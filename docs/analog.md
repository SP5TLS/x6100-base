# Analog acquisition and DAC control

## Scope and evidence

This document describes direct use of the STM32F427 ADC and DAC
peripherals by BASE firmware 1.1.9. Evidence was exported without
renaming symbols:

- `analysis/analog/adc_common_refs.csv`;
- `analysis/analog/adc3_refs.csv`;
- `analysis/analog/adc_common_only_refs.csv`;
- `analysis/analog/adc_dma_buffer_refs.csv`;
- `analysis/analog/dac_refs.csv`;
- selected disassembly under `analysis/analog/`.

Firmware SHA-256:

`3fa11293e06951c21c9cfda04ea08adad85eaadda26b77a8e8bbcca8820c53c4`

## ADC topology

`FUN_08030950` initializes two independent three-channel scan groups.

| ADC | Regular channels | MCU pins | DMA path | Destination |
| --- | --- | --- | --- | --- |
| ADC1 | 0, 1, 2 | PA0, PA1, PA2 | DMA2 Stream 0, channel 0, 3 halfwords | `0x2000C6B4` |
| ADC2 | 6, 7, 14 | PA6, PA7, PC4 | DMA2 Stream 2, channel 1, 15 halfwords | `0x2000C694` |

Peripheral identities, channel numbers, DMA stream/channel selections,
transfer lengths, and destination addresses: VERIFIED.

The GPIO-to-ADC channel mapping is the standard STM32F427 mapping:
VERIFIED.

ADC3 has no direct register references in the application image:
HIGH CONFIDENCE that it is unused.

Neither ADC DMA stream has an active interrupt vector. The consumers
read the DMA-updated buffers from timer and DSP interrupt contexts:
VERIFIED.

## ADC2 telemetry filter

The 15-halfword ADC2 buffer is five repetitions of the three-channel
regular sequence:

```
ch6, ch7, ch14, ch6, ch7, ch14, ... (five sets)
```

`FUN_0803082c`, called by every TIM2 update, separates the interleaved
samples and updates three floating-point states at `0x2000C688`,
`0x2000C68C`, and `0x2000C690`:

```
y = 0.92 * y + 0.016 * sum(five samples)
  = 0.92 * y + 0.08 * mean(five samples)
```

Buffer layout, filter equation, and TIM2 scheduling: VERIFIED.

`FUN_08030808(index)` converts one of these states to an unsigned
16-bit integer. Valid indices are 0 through 2: VERIFIED.

Observed consumers establish the following partial semantic map:

| Getter index | ADC2 channel | Evidence-backed role | Confidence |
| ---: | ---: | --- | --- |
| 0 | 6 / PA6 | voltage measurement; the battery/power manager multiplies it by `4.835165` | HIGH CONFIDENCE |
| 1 | 7 / PA7 | PA current feedback used while calibrating both drive and final-stage bias | HIGH CONFIDENCE |
| 2 | 14 / PC4 | no direct consumer identified yet | VERIFIED channel, unknown role |

The exact electrical units, divider/gain values, and physical net names
remain unresolved. In particular, `4.835165` is a verified firmware
scale factor but is not sufficient by itself to assign a final unit.

## ADC1 fast measurements

The DMA1 Stream 3 DSP handler reads the three halfwords at
`0x2000C6B4`:

- ADC1 channel 0 is the forward RF-detector path: HIGH CONFIDENCE;
- ADC1 channel 1 is the reflected RF-detector path: HIGH CONFIDENCE;
- ADC1 channel 2 participates in an ALC correction multiplier, but its
  physical net remains unknown: VERIFIED use, unknown identity.

Channels 0 and 1 pass through identical conversions. For raw ADC sample
`adc`, the firmware calculates:

```
x = adc × 0.012165527
P = x × (0.0115375 × x + 0.06)
```

It smooths the channel-0 result and exposes it through
`FUN_0802442c`. `TIM3_IRQHandler` publishes that getter as TX-power
telemetry, while the reviewed X6100Control 1.1.6 interface decodes the
same field as `tx_power` in tenths. Arithmetic and end-to-end telemetry
association: VERIFIED. The forward-power interpretation is therefore
HIGH CONFIDENCE; the absolute unit still requires hardware
calibration.

Every ten DSP blocks, the firmware forms a ratio from accumulated raw
channel-0 and channel-1 samples:

`ratio = (forward + reflected) / (forward - reflected)`

It forces the result to at least `1.0`, suppresses it at low detector
level, and requires three qualifying updates before exposing it through
`FUN_08024454`. `TIM3_IRQHandler` publishes that getter in the VSWR
telemetry field, decoded as `vswr` by X6100Control. Formula and
telemetry association: VERIFIED. Identifying channel 1 as the reflected
detector is HIGH CONFIDENCE.

The antenna-tuner path uses a separate fresh-sample getter for the same
ratio. Its handshake and tune-session behavior are documented in
`docs/atu.md`.

Channel 2 produces:

`correction = clamp(1 + 0.005 × (4000 - adc), 1, 20)`

This multiplier enters the TX ALC feedback calculation. Formula and use
are VERIFIED. It is not safe to infer a final physical net name from
the arithmetic alone.

Direct references for the derived RF measurement state are exported in
`analysis/analog/adc1_rf_measurement_refs.csv`.

## PA bias device versus STM32 DAC

`FUN_0803062c` is not an STM32 DAC writer. It updates a cached
multi-channel value and emits a three-byte transaction through function
pointers:

```
byte 0 = channel << 3
byte 1 = value >> 8
byte 2 = value
```

The transaction format and use by PA calibration are VERIFIED. The
object accepts two channels, uses I2C1 address byte `0xC6` (7-bit
address `0x63`), and pulses PE10 after a changed write: VERIFIED. The
external device identity is unknown; describing it as an external
two-channel bias-control device is HIGH CONFIDENCE.

The calibration path changes two cached channels and samples ADC2
getter index 1. Diagnostic strings identify the two calibrated
quantities as `PA_drive_stage_current` and `PA_final_stage_current`.
Those associations are HIGH CONFIDENCE, while the external IC and
physical voltage/current transfer functions remain unknown.

The complete object layout, startup command sequence, channel roles,
and ordered RX/TX GPIO transitions are documented in
`docs/pa_control.md`.

## Internal DAC

`FUN_08030aa0` enables the STM32 DAC clock, initializes both DAC
channels, writes zero to both 12-bit right-aligned holding registers,
and enables both channels: VERIFIED.

`FUN_0802c840`, a frequency-dependent band-selection routine, writes
different 12-bit constants to DAC channel 2 through `FUN_0802e1b4`.
Observed constants include:

`0x11D`, `0x23A`, `0x6B0`, `0x7CD`, `0x8EB`, `0xA08`, `0xB26`,
and `0xC43`.

Frequency-dependent DAC2 control: VERIFIED.

The complete piecewise table has now been recovered, from `0x11D` at
frequencies up to 2 MHz through `0xC43` above 50 MHz. Exact integer
boundaries and the parallel RF-band classification are documented in
`docs/frequency_control.md` and
`analysis/frequency_control/frequency_bands.csv`.

Its physical purpose is unknown. Band-dependent RF bias or tuning
control is HIGH CONFIDENCE because the code increases monotonically
across frequency regions and is updated immediately before the LO
commit. DAC channel 1 is initialized to zero, but no later application
write has been identified: HIGH CONFIDENCE.

## Reimplementation implications

- Preserve the ADC2 scan order and five-set interleaving before
  reproducing the telemetry filter.
- Treat the three filtered ADC2 values as raw calibrated-domain values
  until their electrical transfer functions are verified.
- Keep ADC1 acquisition synchronized with the fast DSP path; polling it
  from the main loop would not reproduce the observed timing.
- Preserve the common nonlinear calibration for both directional
  detector channels and calculate VSWR only after the recovered
  low-level and settling guards.
- Do not substitute the internal DAC for the separate PA bias-control
  transaction path.

## Remaining work

- Confirm the PA0/PA1 directional-detector assignment against the board
  schematic or injected-signal measurements.
- Identify the physical role of the PA2 ALC correction input.
- Correlate PA6/PA7 and PC4 with the board schematic.
- Recover the physical units for ADC2 indices 0 and 1.
- Identify the ADC2 channel 14 consumer or external role.
- Identify the external PA bias-control device and its transfer
  function from board or bus evidence.
