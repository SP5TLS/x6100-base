# I2C buses and attached devices

## Scope and evidence

BASE 1.1.9 uses all three STM32F427 I2C controllers. Direct peripheral
references are exported under `analysis/i2c/`; transport-specific I2C3
evidence is also described in `docs/protocol.md`.

Firmware SHA-256:

`3fa11293e06951c21c9cfda04ea08adad85eaadda26b77a8e8bbcca8820c53c4`

## Bus overview

| Bus | Pins | Rate | Role | Confidence |
| --- | --- | ---: | --- | --- |
| I2C1 | PB6 SCL, PB7 SDA, AF4 | 100 kHz | master, battery telemetry and LO synthesizer | VERIFIED |
| I2C2 | PB10 SCL, PB11 SDA, AF4 | 100 kHz | master, audio codec and auxiliary devices | VERIFIED |
| I2C3 | PA8 SCL, PC9 SDA, AF4 | 400 kHz | slave, Linux control register file | VERIFIED |

I2C1 and I2C2 use blocking/polling transfers. They have no active I2C
interrupt vectors: VERIFIED.

I2C3 alone uses event and error interrupts. Its register protocol,
memory windows, and Linux correlation are documented in
`docs/protocol.md`.

## Address notation

The master-transfer helper receives the complete address byte expected
by the STM32 peripheral library. Therefore the observed even values
must be shifted right once to obtain the conventional 7-bit address.

| Bus | Address byte in firmware | 7-bit address | Observed use |
| --- | ---: | ---: | --- |
| I2C1 | `0x6C` | `0x36` | battery telemetry block |
| I2C1 | `0xD4` | `0x6A` | five-output LO clock generator |
| I2C2 | `0x40` | `0x20` | 16-bit RF-control GPIO expander |
| I2C2 | `0x20` | `0x10` | CS4272 stereo ADC/DAC |
| I2C2 | `0x30` | `0x18` | TLV320AIC3204 audio codec |
| I2C2 | `0x94` | `0x4A` | auxiliary startup configuration |
| I2C2 | `0x98` | `0x4C` | fallback hardware-variant configuration |

Address bytes and conversion to 7-bit addresses: VERIFIED.

## I2C1 battery telemetry

`FUN_08031fc0` initializes I2C1 and PB6/PB7. `FUN_08031e1c` implements
a combined write/repeated-start/read transaction:

1. address the device for writing;
2. write one register byte;
3. issue a repeated START;
4. address the device for reading;
5. receive the requested byte count with ACK handling;
6. issue STOP.

Transaction behavior: VERIFIED.

The battery manager periodically executes:

```
device address byte = 0x6C
register            = 0x00
destination         = 0x2000BF90
length              = 0x200 bytes
```

It extracts voltage-, capacity-, current-, and status-like fields from
this block and publishes them to the Linux telemetry packet. A
battery-pack controller or pack-side MCU role is HIGH CONFIDENCE. The
device protocol and IC identity are unknown, so no final device name is
assigned.

On transfer failure, `FUN_08031cfc`:

- disables I2C1;
- temporarily configures PB6/PB7 as GPIO;
- clocks PB7 ten times while controlling PB6;
- restores alternate-function mode;
- resets and reinitializes I2C1;
- prints `i2c reseted`.

Bus recovery sequence and ten clock pulses: VERIFIED. This is
consistent with recovery from a slave holding the bus, but the exact
electrical fault is not observable from firmware alone.

## I2C1 LO synthesizer

The object at `0x2000036C` uses address byte `0xD4` (7-bit `0x6A`), a
26 MHz reference, five outputs, and an I2C1 write callback. Its
configuration and divider registers match the Renesas/IDT 5P49V60
VersaClock 6E: HIGH CONFIDENCE.

The VFO frequency path, divider formulas, deferred register commit, and
device evidence are documented in `docs/frequency_control.md`.

## I2C2 TLV320AIC3204

Most I2C2 transactions use address byte `0x30`, or 7-bit address
`0x18`. The register sequence in `FUN_0802f0ec` and
`FUN_0802f9a4` matches the TI TLV320AIC3204:

- register 0 selects a register page;
- registers 4–8 configure the PLL;
- registers 11–14 configure NDAC, MDAC, and DOSR;
- registers 18–20 configure NADC, MADC, and AOSR;
- registers 59/60 and 65/66 are used by channel volume controls;
- page switching is used for analog routing and output configuration.

Device identification as TLV320AIC3204: VERIFIED by address and
register-map correlation.

`FUN_0802f0ec` calculates codec clock dividers from an input frequency
and a 55.296 MHz constant, validates the resulting internal clock
ranges, and writes the PLL and converter-divider registers.
Clock-programming algorithm and register writes: VERIFIED.

The startup path requests a 100,000-Hz converter rate. This matches the
raw DSP rate constant recovered in `docs/spi_i2s.md`: HIGH CONFIDENCE.

### Operational audio-codec controls

The small helpers following the clock-programming routine have now
been correlated with the official codec register guide. Their complete
machine-readable contract is in
`analysis/i2c/tlv320aic3204_control_helpers.csv`.

| Firmware function | Hardware operation | Encoding |
| --- | --- | --- |
| `FUN_0802f4bc` | left/right analog MICPGA gain | `0x00`–`0x5F` = 0–47.5 dB in 0.5-dB steps; larger values clamp to `0x5F` |
| `FUN_0802f568` | LOL/LOR line-driver gain and mute | below -6 dB means mute; -6 through +29 dB use the codec's signed 6-bit gain code |
| `FUN_0802f628` | HPL/HPR headphone-driver gain and mute | below -6 dB means mute; -6 through +29 dB use the codec's signed 6-bit gain code |
| `FUN_0802f6e8` | left/right DAC mute | page 0 register `0x40`, bits 3 and 2 |
| `FUN_0802f758` | left/right ADC mute | page 0 register `0x52`, bits 7 and 3; fine gain remains 0 dB |
| `FUN_0802f7c8` | analog input routing to left/right MICPGA | argument bits 0/1/2 select IN1/IN2/IN3 respectively |
| `FUN_0802f8d0` | MICBIAS power | page 1 register `0x33`: `0x20` off, `0x60` on |
| `FUN_0802f924` | codec LDO control | page 1 register `0x02 = 0x01` |
| `FUN_0802f964` | codec software reset | page 0 register `0x01 = 0x01` |

Function/register mappings and encodings in this table are VERIFIED.
The names remain descriptive documentation, not final Ghidra symbol
renames.

`FUN_0802f7c8` makes the physical analog-input behavior particularly
clear. For each selected channel, argument bit 0 connects IN1, bit 1
connects IN2, and bit 2 connects IN3 to the positive MICPGA input
through 10 kOhm. It also writes a fixed common-mode connection to the
negative input (`0x40` for the left MICPGA and `0x80` for the right).
An argument of zero disconnects all three positive inputs while
retaining that negative common-mode connection: VERIFIED.

The DAC and ADC mute helpers overwrite their complete target register.
Their channel mask constructs `0x08`/`0x04` for DAC mute and
`0x80`/`0x08` for ADC mute; it does not read-modify-write or preserve
an independently muted unselected channel. This behavior must be
preserved by a compatible implementation: VERIFIED.

`FUN_0802f8d0` keeps MICBIAS voltage-selection bits at binary `10` and
only changes power bit D6. The exact voltage is conditional on the
codec common-mode selection, so this documentation intentionally does
not infer one board voltage from the register alone.

### Physical audio-source correlation

The current 1.1.9 control-update path was correlated with the historical
X6100Control 1.1.6 field names. The cross-version names alone are not
treated as proof; confidence also uses the current codec routing,
MICBIAS behavior, gain destinations, and mode-selection logic. The
result is exported in
`analysis/i2c/audio_control_register_mapping.csv`, while the relevant
current-firmware functions are reproducibly exported in
`analysis/i2c/audio_route_callers_decompile.txt`.

| Physical role | Control field | Current 1.1.9 hardware action | Confidence |
| --- | --- | --- | --- |
| built-in microphone | register 20 bits 23:16, historical `imicg` | value is doubled, applied to left MICPGA, and IN1L is selected; MICBIAS is enabled | HIGH CONFIDENCE |
| hand microphone | register 20 bits 31:24, historical `hmicg` | value is applied to left MICPGA and IN2L is selected; MICBIAS is not enabled | HIGH CONFIDENCE |
| line input | register 20 bits 7:0, historical `ling` | value is applied to right MICPGA and IN2R is selected | HIGH CONFIDENCE |
| line output | register 20 bits 15:8, historical `loutg` | value minus 7 dB is applied to both LOL and LOR drivers | HIGH CONFIDENCE |

Register 21 bits 1:0 select the microphone source. Value 0 selects the
IN1L/MICBIAS path, value 1 selects IN2L, and value 2 automatically
chooses between them from operating-state bit 1: VERIFIED behavior.
Calling these built-in, hand, and automatic microphone selection is
HIGH CONFIDENCE from the independent 1.1.6 labels and the 1.1.9
electrical behavior.

One additional transmit branch disables left MICPGA input routing and
selects IN3R on the right MICPGA with a separate cached gain. Its
internal operating flag `0x40` is constructed by `FUN_0802d7cc` from
control register 12 bit 14, historically named `modem_trx`: VERIFIED.
IN3R is therefore the modem-mode analog transmit source with HIGH
CONFIDENCE.

Cross-checking two independent companion projects resolves the
board-side distinction without requiring an exact IC name.
`x6100_base_patch` commit `4413870` identifies IN3R as the MAIN-to-BASE
audio stream and deliberately enables it for Linux-side playback and
recording. The `x6100_gui` audio layer uses PulseAudio's
`alsa_output.platform-sound` and `alsa_input.platform-sound` devices.
Together with the verified 1.1.9 modem route, this identifies IN3R as
MAIN/Linux-board playback into the BASE ADC: HIGH CONFIDENCE. A
schematic or continuity measurement would still be required for
VERIFIED board-net status.

The same cross-check completes the converter's external audio
topology:

| TLV320 node | Board-level role | Confidence |
| --- | --- | --- |
| IN1L | built-in microphone into BASE | HIGH CONFIDENCE |
| IN2L | hand microphone into BASE | HIGH CONFIDENCE |
| IN2R | C-Media/USB-card playback into BASE | HIGH CONFIDENCE |
| IN3R | MAIN/Linux-board playback into BASE | HIGH CONFIDENCE |
| HPL | BASE output to MAIN/Linux-board capture | HIGH CONFIDENCE |
| HPR | headphone/external-speaker receive output | HIGH CONFIDENCE |
| LOL/LOR | BASE output to C-Media/USB-card capture | HIGH CONFIDENCE |

Current 1.1.9 register actions remain the primary evidence. The older
projects only resolve external endpoint names, and therefore do not
raise these board assignments to VERIFIED. Evidence is summarized in
`analysis/i2c/audio_board_topology_evidence.csv`.

Receive-volume register 14 drives only HPR in the recovered codec
helper. Value 0 mutes HPR. Values 1 through 29 leave HPR at 0 dB and
call `FUN_0803b5d8(10.0, (value - 30) * 0.05)` for the digital scalar;
values 30 and above use unity digital gain and set HPR analog gain to
`value - 30` dB. The raw arguments, thresholds, and physical HPR
destination are VERIFIED. `FUN_0803b5d8` has the behavior and error
handling of `powf`, making the exponential interpretation and the full
receive-audio-output role HIGH CONFIDENCE. S/P selection operates on
this same receive-audio path rather than assigning another codec
output.

The speaker/phone qualifier is now traced outside the codec register
API. Register 21 bit 5 is stored at `0x2000003F`. The routine beginning
at `0x0802D7FC` compares it with GPIOF input PF15, reloads a countdown
of 9 whenever either state changes, and after stability writes a
combined selector to `0x20008368`. The DMA audio handler reads this
selector and multiplies the receive-volume scalar by `0.05` when it is
nonzero: VERIFIED.

The selector is nonzero only when the requested S/P mode is 1 and PF15
is low. No codec routing register or output GPIO is changed. The
published operation manual describes this setting as headphone-port
selection between headphones and an external loudspeaker. Combining
that description with the recovered behavior identifies PF15 as the
S/P jack-detect input and the operation as a 20:1 digital level change
on the same HPR path: HIGH CONFIDENCE. The exact state machine is in
`analysis/i2c/audio_spmode_path.csv`.

Manual reference:
<https://xiegu.eu/wp-content/uploads/sites/4/2022/01/X6100-Operation-Manual.pdf>

Startup writes page-0 register `0x1B = 0x3C`. This selects 32-bit I2S
format and makes both BCLK and WCLK outputs: VERIFIED against the
TLV320AIC3204 register map. The codec is therefore the serial-clock
master while both STM32 I2S peripherals are slaves.

PE15 is driven low early in `FUN_08034178`, driven low again immediately
before codec startup, held for at least the explicit 1-ms delay, and
then driven high immediately before the TLV320AIC3204 software-reset
write and register sequence: VERIFIED. No later PE15 writes were found,
including in the recovered shutdown path: VERIFIED. Interpreting PE15
as the codec's active-low hardware reset is HIGH CONFIDENCE. The exact
lifecycle is exported in
`analysis/i2c/audio_reset_gpio_lifecycle.csv`.

Primary device references:

- TI TLV320AIC3204 product page:
  <https://www.ti.com/product/TLV320AIC3204>
- TI TLV320AIC3204 application reference guide:
  <https://www.ti.com/lit/ml/slaa557/slaa557.pdf>

## Other I2C2 devices and hardware variants

The object at `0x20000360` uses address byte `0x40` (7-bit `0x20`).
It accesses the eight-register layout and 16-bit output state of an NXP
PCA9535-compatible GPIO expander. Device-family identification:
HIGH CONFIDENCE. It provides one of two primary RF-band output
implementations; see `docs/rf_switching.md`.

### CS4272 at `0x10`

`FUN_0803022c` writes this sequence to address byte `0x20` (7-bit
`0x10`):

| Register | Value | CS4272 register |
| ---: | ---: | --- |
| `0x07` | `0x03` | Mode Control 2 |
| `0x01` | `0x81` | Mode Control 1 |
| `0x02` | `0x00` | DAC Control |
| `0x03` | `0x49` | DAC Volume and Mixing Control |
| `0x04` | `0x00` | DAC Channel A Volume |
| `0x05` | `0x00` | DAC Channel B Volume |
| `0x06` | `0x10` | ADC Control |
| `0x07` | `0x02` | Mode Control 2 |

The address, complete contiguous register map, and register meanings
match the Cirrus Logic CS4272. Device identification: VERIFIED.

The first write enables the control port while keeping the converter
powered down. Register `0x01 = 0x81` selects double-speed, slave, I2S
DAC operation; register `0x06 = 0x10` selects I2S ADC data; and the
last write clears the power-down bit while retaining control-port
operation. These field interpretations are VERIFIED against the
CS4272 data sheet.

Double-speed mode covers 50–100 kHz, so this configuration independently
supports the recovered 100,000-Hz raw DSP rate. The CS4272 is the
external stereo converter in the zero-IF I/Q path: VERIFIED. The
service-manual block diagram places it directly between the receive/
transmit quadrature mixers and the STM32. Combined with the verified DMA
signal roles, this assigns it to SPI3/I2S3: VERIFIED.

Primary device reference:

- Cirrus Logic CS4272 data sheet:
  <https://statics.cirrus.com/pubs/proDatasheet/CS4272_F2.pdf>
- X6100 service-manual middle-plate block diagram:
  <https://www.manualslib.com/guide/3740642/xiegu-x6100-hf-transceiver-series-manual.html>

### Devices at `0x4A` and `0x4C`

`FUN_08030754` always sends the following payloads to address byte
`0x94` (7-bit `0x4A`) during audio startup:

```text
00 00
20 01
00 00 80 3F 00
0B 00
delay 1 ms
0D 01
delay 1 ms
0E 01
delay 1 ms
```

The five-byte block is copied directly from firmware address
`0x0803E0BC`; it is not an inferred register/value pair. Exact payloads
and ordering: VERIFIED. The device is independent of the converter
variant selection and is initialized before I2S DMA is enabled:
VERIFIED.

Firmware-level role of `0x4A`: an unconditional startup-configuration
companion of the audio/IQ subsystem: VERIFIED. BASE 1.1.9 contains no
reads, later writes, gain changes, frequency changes, or mode-dependent
accesses to this address: VERIFIED. Firmware alone cannot distinguish
whether its autonomous hardware function is routing, conditioning,
conversion, or board-specific control.

The service-manual signal-flow diagram contains no separate block
corresponding to this address. It explicitly shows CS4272 as the I/Q
converter and IC3204 as the MIC/speaker audio codec. Therefore `0x4A`
is not required to explain either principal conversion path. Treating
it as a subordinate support/control function is MEDIUM CONFIDENCE;
assigning a more specific electrical function without board-net tracing
would be a HYPOTHESIS.

If the initial CS4272 write is not acknowledged, `FUN_080244b4` instead
sends this sequence to address byte `0x98` (7-bit `0x4C`):

```text
10 00
delay 10 ms
10 C2
11 80
14 00
```

Exact fallback sequence: VERIFIED. Because this branch is mutually
exclusive with successful CS4272 initialization and occurs in the same
audio startup path, `0x4C` is an alternate backend for the zero-IF I/Q
converter interface: HIGH CONFIDENCE. It may be the converter itself or
a closely coupled controller; this distinction is not visible to
firmware.

BASE 1.1.9 contains no reads or runtime writes to `0x4C`: VERIFIED.
It is managed only as a fixed startup backend. Firmware ignores the
return value of all four fallback transfers, so their failure does not
abort startup.

The TI TLV320AIC3109-Q1 was checked as a candidate because it can appear
at address `0x4C`. It is excluded: VERIFIED. With no preceding page
selection, the candidate would be on page 0, where register `0x11` is
reserved and must be written as `0xFF`, while register `0x14` is
read-only with reset value `0x78`. The firmware instead writes
`0x11 = 0x80` and `0x14 = 0x00`. Address coincidence alone is therefore
not valid identification evidence.

Primary exclusion reference:

- TI TLV320AIC3109-Q1 data sheet:
  <https://www.ti.com/lit/ds/symlink/tlv320aic3109-q1.pdf>

The machine-readable transaction record is
`analysis/i2c/i2c2_aux_startup_sequences.csv`; audited device candidates
are recorded in `analysis/i2c/i2c2_device_candidate_audit.csv`, and the
complete ordered policy is in
`analysis/i2c/i2c2_audio_startup_policy.csv`.

### Required startup transaction contract

The complete firmware-visible control policy is:

1. clear GPIOG ODR bit 8; PG8 remains an input, so this is an output
   latch update rather than a verified physical reset assertion;
2. initialize both STM32 I2S pairs and their DMA streams;
3. reassert PE15 low, wait 1 ms, then drive it high; PE15 was already
   driven low earlier in main startup;
4. initialize TLV320AIC3204 at `0x18`, including 100-kHz dividers and
   32-bit master-I2S operation;
5. wait 100 ms;
6. send the fixed six-transfer sequence to `0x4A`, ignoring results;
7. enable the DMA/I2S sample machinery, then set GPIOG ODR bit 8; PG8
   still remains an input;
8. probe `0x10` using payload `07 03`;
9. on success, send the remaining seven CS4272 writes;
10. on failure, wait 10 ms and send the four fixed writes to `0x4C`.

Order, branch, delays, payload lengths, and absence of reads: VERIFIED.
For `0x4A` and `0x4C`, reproducing these bytes and timing is the complete
control interface currently observable from firmware.

The PG8 ODR writes must not be described as converter reset control.
Central GPIO initialization configures PG8 as a pulled-down input, and
no later mode change to output was found: VERIFIED. On STM32F4, changing
ODR while the pin is in input mode does not drive the pad. The purpose
of these otherwise ineffective latch writes is unknown.

`FUN_08031890` performs a raw transaction: START, address byte, supplied
payload bytes, STOP, then an internal post-transfer delay. It does not
insert an implicit register address: VERIFIED.

## I2C3 Linux control slave

I2C3 exposes 7-bit address `0x72`. The STM32 own-address register
contains `0xE4`, which is the shifted representation. Event and error
handlers implement the Linux-visible register file.

Peripheral role, address, and interrupt-driven slave operation:
VERIFIED.

See `docs/protocol.md` for:

- the 56-entry control window;
- bulk and single-register write framing;
- read-response and calibration windows;
- the Linux boot-ready handshake;
- correlation with X6100Control 1.1.6.

## Reimplementation implications

- Keep I2C1 recovery available; a failed pack transaction currently
  resets and clocks the physical bus before retrying later.
- Treat the I2C1 512-byte block as an external protocol, not as a C
  structure to copy blindly.
- Program the I2C1 clock generator from the public 5P49V60
  specification and preserve the firmware's ordered LO update.
- Preserve TLV320AIC3204 page selection and clock-divider ordering.
- Probe and configure the CS4272 at `0x10`; select the still-unidentified
  `0x4C` backend only when the CS4272 probe fails.
- Treat `0x4A` and `0x4C` as fixed startup protocols; no OEM runtime
  controls exist for them.
- Keep I2C3 in slave mode at address `0x72`; it is not part of the
  master peripheral bus.

## Remaining work

- Recover the I2C1 battery block layout and checksum/version fields.
- Determine the board-level electrical functions of `0x4A` and the
  `0x4C` fallback by tracing signals; their MCU control is recovered.
- Trace the subordinate `0x4A` support function and determine whether
  the `0x4C` fallback is a converter or a converter-side controller.
- Verify whether the hardware-variant branch is selected by board
  revision, device presence, or another condition.
