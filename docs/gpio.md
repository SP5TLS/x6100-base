# GPIO topology and control paths

## Scope and evidence

The central GPIO initializer is `FUN_0803158c`. Direct register
references were exported to `analysis/gpio/gpio_refs.csv`; selected
functions were also exported under `analysis/gpio/`.

Firmware SHA-256:

`3fa11293e06951c21c9cfda04ea08adad85eaadda26b77a8e8bbcca8820c53c4`

All seven ports GPIOA through GPIOG are clocked by the application:
VERIFIED.

## Central pin configuration

The compact initialization structure used by the firmware contains a
pin mask followed by byte-sized mode, speed, output-type, and pull
fields. Decoding its mode field gives the following groups.

| Mode | GPIO pins | Confidence |
| --- | --- | --- |
| output | PD2, PD3, PD4 | VERIFIED |
| output | PE2, PE7, PE8, PE9, PE11, PE12, PE14, PE15 | VERIFIED |
| output | PG12 | VERIFIED |
| input | PG0, PG1, PG6, PG8, PG11 | VERIFIED |
| output, high speed | PB0, PB1 | VERIFIED |
| output, high speed | PC5 | VERIFIED |
| output | PE10 | VERIFIED |
| output | PG6, PG12 | VERIFIED |
| output | PA3 | VERIFIED |
| input | PA11, PA12 | VERIFIED |
| input | PB8, PB9 | VERIFIED |
| input | PE3, PE13 | VERIFIED |
| input | PF13, PF14, PF15 | VERIFIED |
| input | PG4 | VERIFIED |
| input | PD0 | VERIFIED |
| analog | PA0, PA1, PA2, PA6, PA7 | VERIFIED |
| analog | PC4 | VERIFIED |
| analog | PA4, PA5 | VERIFIED |
| alternate function 2 | PD12 | VERIFIED |

PG0 and PG8 are configured with pull-downs; PG1 and PG11 with pull-ups:
VERIFIED. Other pull and output-type details should be checked pin by
pin before being copied into an independent implementation.

Some pins appear in more than one group because the initializer
deliberately reconfigures them during its sequence. PG6 and PG12 are
first included in an input/output setup and later explicitly configured
as outputs.

## Peripheral alternate functions

Additional subsystem initializers establish these mappings:

| Peripheral | Pins | Alternate function | Confidence |
| --- | --- | ---: | --- |
| I2C3 | PA8, PC9 | AF4 | VERIFIED |
| USART1 | PA9, PA10 | AF7 | VERIFIED |
| USART6 | PC6, PC7 | AF8 | VERIFIED |
| TIM4 channel input | PD12 | AF2 | VERIFIED |
| Full-duplex I2S sample interfaces | PA15, PC10–PC12, PD12–PD15 | AF5/AF6 | VERIFIED |

PD12 is initially configured for TIM4 AF2 and later reconfigured for
the active I2S setup at AF5. Exact I2S direction and clock roles are
documented in `docs/spi_i2s.md`.

The analog assignments are:

| Function | Pins | Confidence |
| --- | --- | --- |
| ADC1 channels 0, 1, 2 | PA0, PA1, PA2 | VERIFIED |
| ADC2 channels 6, 7, 14 | PA6, PA7, PC4 | VERIFIED |
| DAC channels 1, 2 | PA4, PA5 | VERIFIED |

See `docs/analog.md` for acquisition and filtering behavior.

## Serial GPIO shift chains

Three output pins implement software-clocked serial control:

- PC5 is serial data;
- PB0 is the serial clock;
- PB1 or PG6 is asserted around a completed transfer, depending on the
  selected chain.

`FUN_0802cf88` shifts six bits through PC5/PB0 and pulses PB1.
`FUN_0802d310` shifts two eight-bit arguments, most-significant bit
first, through PC5/PB0 while PG6 is low, then raises PG6.
`FUN_0802d15c` sends a fixed startup pattern through the same
PC5/PB0/PG6 path.

Pin roles, bit counts, order, and latch behavior: VERIFIED.

These routines are called by frequency/band configuration code.
Interpretation as two RF relay/filter control shift chains is HIGH
CONFIDENCE. The mapping from individual shifted bits to physical
relays, filters, or attenuators remains unknown.

## Direct runtime controls

The following direct operations are established, but most physical net
names are not yet known:

| Pin or group | Observed use | Confidence |
| --- | --- | --- |
| PB2 | toggled at entry/exit of the fast DMA1 DSP handler | VERIFIED |
| PG15 | sampled and debounced by TIM2 | VERIFIED |
| PG4 | sampled during normal operation and awaited during final shutdown | VERIFIED |
| PE8, PE9, PE11, PE14, PE15 | changed during startup, PA calibration, DSP operation, or shutdown | VERIFIED |
| PE10 | low-delay-high pulse after external PA-bias device writes | VERIFIED |
| PE2, PE8, PE9, PE12, PG11, PD3, PD4 | ordered RX/TX hardware transition group | VERIFIED |
| PD2, PD3, PD4 | sequenced low during shutdown | VERIFIED |
| PF11 | read by the charger/battery startup loop | VERIFIED |
| PF13 | controlled by the charger/battery startup loop | VERIFIED |
| PG8, PG11, PG12 | changed by startup, peripheral-reset, PA, or power-management paths | VERIFIED |

PB2 is a timing/debug marker candidate because it brackets the complete
DSP interrupt body: HIGH CONFIDENCE. Its electrical destination is
unknown.

The precise RX/TX levels and ordering of the PA-related group, and the
I2C1 bias-control device associated with PE10, are documented in
`docs/pa_control.md`. Individual physical net names remain unresolved.
The hardware-variant PA callback is now resolved to PCA9535 output bit
1 on one variant and PD14 on the other: VERIFIED.

The main routine clears PD4, waits five seconds, clears PD3, waits three
seconds, then clears PD2 before its final shutdown wait. Interpretation
as an ordered power-rail shutdown sequence is HIGH CONFIDENCE; the
individual rails are unknown.

GPIO-backed callbacks selected by `FUN_0803131c` provide two hardware
variants for several power and RF-control operations. The callback
addresses and affected pins are VERIFIED, but final semantic names
should not be assigned until the hardware variant and nets are
identified.

The primary RF-band callback has now been resolved. One implementation
uses a PCA9535-compatible I2C2 expander; the other writes the index as
a binary value on PG9, PG10, PG11, and PG13. A secondary one-hot RF
index is transmitted through SPI6, with PG12 used by its completion
path. Exact mappings are documented in `docs/rf_switching.md`.

## Inputs serviced by TIM3

TIM3 debounces seven active-low GPIO-backed input descriptors:

| Pin | Mask | Debounce reload | Stable flag |
| --- | ---: | ---: | ---: |
| PB9 | `0x0200` | 10 | `0x20000182` |
| PE3 | `0x0008` | 10 | `0x20000196` |
| PF14 | `0x4000` | 1 | `0x200001AA` |
| PF13 | `0x2000` | 1 | `0x200001BE` |
| PA11 | `0x0800` | 1 | `0x200001D2` |
| PA12 | `0x1000` | 1 | `0x200001E6` |
| PD0 | `0x0001` | 1 | `0x200001FA` |

Descriptor values, active level, debounce state machine, and stable
destinations: VERIFIED.

PB9 directly controls TX-source bit `0x2`; its historical `HPTT`
interpretation is HIGH CONFIDENCE. PF14 and PF13 feed the two CW paddle
inputs. Correlation with the
published KEY-plug diagram and keyer element lengths maps PF14 to
tip/`DI`/dot and PF13 to ring/`DA`/dash: HIGH CONFIDENCE. PA11 and PD0
feed the aggregated immediate-CW-key path only in CW/CWR modes:
VERIFIED software routing. Their exact external or internal sources,
and PB9's exact physical PTT control, remain unresolved. See
`docs/tx_pipeline.md`.

## Reimplementation implications

- Reproduce the output-safe states before enabling RF or peripheral
  subsystems.
- Preserve the MSB-first PC5/PB0 shift timing and the distinct
  PB1/PG6 latch signals.
- Keep the PD4 → PD3 → PD2 shutdown delays until the controlled rails
  are identified.
- Do not assign semantic GPIO names from port masks alone.

## Remaining work

- Assign final physical roles and connector contacts to PA11, PA12,
  PD0, PB9, and PE3.
- Correlate shifted RF-control bits with frequency ranges and hardware
  filters.
- Identify power, PA-enable, charger, and reset nets from the board
  schematic or controlled measurements.
- Document initial and shutdown levels for every output pin.
