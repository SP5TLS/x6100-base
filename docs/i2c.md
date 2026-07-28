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
| I2C2 | `0x20` | `0x10` | hardware-variant device |
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

Other codec helpers select pages and update paired left/right fields,
power/mute state, serial-interface configuration, and page-dependent
analog routing: VERIFIED at the transaction level. The exact
user-facing meaning of every helper remains to be correlated with the
codec register guide and Linux control fields before final names are
assigned.

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

`FUN_08030754` sends a fixed startup sequence to address byte `0x94`
(7-bit `0x4A`). The writes include register/value pairs and one
five-byte block. The device is initialized alongside the audio path,
but its identity and physical role are unknown: VERIFIED transactions,
unknown semantics.

`FUN_0803022c` probes address byte `0x20` (7-bit `0x10`) by writing
register/value pairs for registers 0 through 7. If the first transfer
succeeds, startup returns without performing the later `0x98`
configuration. If it fails, four two-byte writes are sent to address
byte `0x98` (7-bit `0x4C`).

Mutually exclusive `0x10`/`0x4C` startup branches: VERIFIED.

Interpretation as support for two board or peripheral variants is HIGH
CONFIDENCE. Interpreting either device as a specific codec, amplifier,
clock generator, or power IC would currently be a HYPOTHESIS and is
not used for naming.

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
- Detect the `0x10`/`0x4C` hardware variant rather than configuring both
  devices unconditionally.
- Keep I2C3 in slave mode at address `0x72`; it is not part of the
  master peripheral bus.

## Remaining work

- Recover the I2C1 battery block layout and checksum/version fields.
- Identify the I2C2 devices at 7-bit addresses `0x10`, `0x4A`, and
  `0x4C`.
- Map every TLV320AIC3204 helper to its codec register semantics.
- Verify whether the hardware-variant branch is selected by board
  revision, device presence, or another condition.
