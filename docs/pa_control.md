# PA bias and RX/TX hardware control

## Scope and evidence

This document describes the hardware-facing PA control recovered from
BASE firmware 1.1.9. It deliberately does not attempt to reproduce the
OEM control policy.

Primary evidence:

- `analysis/pa/pa_control_decompilation.txt`;
- `analysis/pa/bias_device_init_decompilation.txt`;
- `analysis/pa/pre_main_bias_init_decompilation.txt`;
- `analysis/pa/bias_device_object_refs.csv`;
- `analysis/pa/bias_device_object.csv`;
- disassembly and decompilation under `analysis/pa/callbacks/`.

Firmware SHA-256:

`3fa11293e06951c21c9cfda04ea08adad85eaadda26b77a8e8bbcca8820c53c4`

## External two-channel bias-control device

The object at `0x20000334` has the following initialized layout:

| Offset | Value | Meaning | Confidence |
| ---: | ---: | --- | --- |
| `+0x00` | `0xC6` | I2C address byte; conventional 7-bit address `0x63` | VERIFIED |
| `+0x04` | `2` | accepted channel count | VERIFIED |
| `+0x08` | `5000` | object constant, also used as write timeout | VERIFIED value |
| `+0x0C` | `0x0400` initially | overwritten by startup readback | VERIFIED |
| `+0x10`, `+0x14` | `0` | cached values for channels 0 and 1 | VERIFIED |
| `+0x20` | `0x08030F25` | Thumb I2C1 write callback | VERIFIED |
| `+0x24` | `0x08030FE5` | Thumb I2C1 read callback | VERIFIED |
| `+0x28` | `0x08030FC5` | Thumb PE10 pulse/delay callback | VERIFIED |

`FUN_0803062c(object, channel, value)` ignores channels greater than
or equal to two. If the requested value differs from the cached value,
it sends exactly three bytes:

```
byte 0 = channel << 3
byte 1 = value >> 8
byte 2 = value
```

It then invokes the PE10 callback with argument `10`. The callback
drives PE10 low, calls the firmware delay function, and drives PE10
high. Transaction bytes, cache behavior, bus, address, and GPIO pulse:
VERIFIED. PE10 being the device's update/latch signal is HIGH
CONFIDENCE; the schematic net name remains unknown.

The I2C callbacks serialize access to I2C1 (`0x40005400`). Writes use a
timeout of 5000 and reads use 2500; either failure invokes the common
I2C1 recovery path: VERIFIED.

### Startup transaction sequence

`FUN_080305ac` clears all four cached slots in the generic object and
sends these three-byte frames to address `0xC6`:

```
00 00 00
40 00 00
48 00 00
50 00 00
```

It pulses PE10 low/high, then performs a two-byte read associated with
command/register `0x10` and stores the result at object offset `+0x0C`:
VERIFIED.

The exact IC is unresolved. An MCP4728 identification is specifically
not supported: that device is four-channel and its documented command
framing does not match this two-channel object and runtime
channel-select byte. Device identity: unknown.

## Channel roles

The firmware uses only channels 0 and 1:

| Channel | Firmware use | Confidence |
| ---: | --- | --- |
| 0 | drive-stage quiescent-current control | HIGH CONFIDENCE |
| 1 | final-stage quiescent-current control | HIGH CONFIDENCE |

The association comes from diagnostic strings
`PA_drive_stage_current` and `PA_final_stage_current`, their calibration
order, and the use of ADC2 channel 7 / PA7 as current feedback. The
electrical DAC transfer function and the final current units are not
yet known.

Protocol register 41 supplies the normal operating codes. Its low
16-bit half is sent to channel 0 and its high 16-bit half to channel 1:
VERIFIED for BASE 1.1.9.

## RX/TX hardware sequence

`FUN_0802aaf4` is the central hardware transition. The table records
the order visible in the function; all GPIO levels are direct ODR
levels.

### Enter RX / disable TX

1. PE12 high.
2. Board-variant callback at `0x2000C6CC` called with `0`.
3. Bias channel 0 set to zero.
4. Bias channel 1 set to zero.
5. PE9 high.
6. PE8 low.
7. PG11 low.
8. PE2 low.
9. `FUN_08023f20(0)`.
10. PD3 high.
11. PD4 low.
12. `FUN_08033974(2, 0)`.

### Enter TX / enable PA

After the mode-dependent audio/DSP preparation:

1. Bias channel 0 receives the cached drive-stage code.
2. Bias channel 1 receives the cached final-stage code.
3. Board-variant callback at `0x2000C6CC` called with `1`.
4. PE9 low.
5. PE8 high.
6. PG11 high.
7. PE2 high.
8. PD3 low.
9. PD4 high.
10. `FUN_08033974(2, 1)`.

The order, levels, and bias-channel writes are VERIFIED. Treating the
group as PA/RF enable and routing controls is HIGH CONFIDENCE, but
assigning individual relay, gate-bias, or supply-enable net names is
still a HYPOTHESIS without schematic or measurements. The indirect
callback also has hardware-variant implementations, so it must not be
replaced by a guessed fixed GPIO.

The startup safe state in `FUN_0802a5d0` agrees with the RX sequence:
both bias values are zero, PE12/PE9/PD3 are high, and
PE8/PG11/PD4 are low. PE2 is additionally driven low by the explicit
RX transition. This correspondence is VERIFIED.

## Independent implementation requirements

- Initialize I2C1 and the external bias device before any PA enable.
- Preserve the three-byte channel-write framing and PE10 low/high
  update pulse.
- Keep both bias channels at zero in startup and RX safe states.
- Apply the stored channel-0 and channel-1 codes before asserting the
  remaining TX GPIO group, matching the recovered order.
- On return to RX, disable the board-level path before zeroing both
  bias channels, matching the recovered order.
- Keep all unknown GPIOs and the variant callback under provisional
  names until board-level evidence identifies their nets.

## Remaining hardware work

- Identify the external two-channel device from PCB markings or bus
  capture and recover its electrical transfer function.
- Resolve PE2, PE8, PE9, PE12, PG11, PD3, and PD4 to schematic nets.
- Resolve both implementations of the `0x2000C6CC` board-variant
  callback.
- Measure the required settling time represented by the PE10 callback
  argument `10`.
