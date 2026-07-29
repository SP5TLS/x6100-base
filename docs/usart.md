# USART interfaces

## Overview

BASE 1.1.9 initializes USART1 and USART6. Both use DMA2, but their
roles and rates differ.

| Interface | Pins | Baud rate | Recovered role | Confidence |
| --- | --- | ---: | --- | --- |
| USART1 | PA9 TX, PA10 RX, AF7 | 115,200 | diagnostic/stdio channel | HIGH CONFIDENCE |
| USART6 | PC6 TX, PC7 RX, AF8 | 1,500,000 | Linux IQ/telemetry flow | VERIFIED |

Peripheral addresses, pins, alternate functions, and baud-rate
constants: VERIFIED.

## Common serial format

The initialization structures select:

- eight data bits;
- no parity;
- one stop bit;
- transmitter and receiver enabled;
- no hardware flow control.

Interpretation as 8-N-1: HIGH CONFIDENCE, based on the recovered
library initialization fields and control-register state.

Both peripherals are driven from the recovered 125-MHz APB2 peripheral
clock.

## USART1

USART1 is initialized at 115,200 baud during the preliminary boot loop
and reinitialized with the complete peripheral set after Linux raises
the I2C boot-ready flag.

### DMA assignments

| Operation | DMA resource | Channel | RAM | Mode |
| --- | --- | ---: | ---: | --- |
| receive | DMA2 Stream 5 | 4 | `0x2000E718` | 100-byte circular buffer |
| transmit | DMA2 Stream 7 | 4 | caller-provided | memory-to-peripheral |

The USART1 transmit wrapper `FUN_08033e24` is reached through
`FUN_08037c92`, part of the firmware's formatted-output path.
Diagnostic/stdio purpose: HIGH CONFIDENCE. It has not been assigned a
final symbol name.

## USART6 Linux flow

USART6 uses PC6/PC7 at 1,500,000 baud. Both the historical
X6100Control project and the current OEM `x6100_ui_v100` application
open Linux `/dev/ttyS1` for the matching IQ/telemetry stream: VERIFIED.
The packet construction and format are documented in
`docs/protocol.md`.

### DMA assignments

| Operation | DMA resource | Channel | RAM | Mode |
| --- | --- | ---: | ---: | --- |
| receive | DMA2 Stream 1 | 5 | `0x2000E77C` | 100-byte peripheral-to-memory transfer |
| flow transmit | DMA2 Stream 6 | 5 | `0x200003F8` | 4136-byte memory-to-peripheral transfer |

`FUN_08032fc8` programs Stream 6 for each flow packet:

- peripheral address `0x40011404`, USART6 data register;
- incrementing memory address;
- memory-to-peripheral direction;
- caller-supplied memory address and length.

The observed caller always supplies packet base `0x200003F8` and length
`0x1028`.

USART6/DMA2 Stream 6 flow transport: VERIFIED.

The purpose and framing of the 100-byte USART6 receive transfer remain
unknown. No Linux-side writer was found in the reviewed historical
X6100Control revision, so it must not yet be described as a command
channel.

## Linux baud-rate conflict

The historical X6100Control code uses 1,152,000 baud. More
significantly, `x6100_ui_v100`, supplied as the Linux firmware 1.2
application paired with BASE 1.1.9, passes termios token `0x1009` to
`cfsetispeed` and `cfsetospeed`. Under Linux UAPI definitions that token
is `B1152000`: VERIFIED numeric token; HIGH CONFIDENCE decoded rate.

BASE 1.1.9 nevertheless writes the explicit value 1,500,000 to its
USART6 initialization structure: VERIFIED. These two observations are
in conflict and neither has been discarded. The actual wire rate, exact
target termios definition, and clock-dependent BASE divisor must be
checked on hardware before an independent implementation selects a
rate.

## Reproducible evidence

- `analysis/usart/usart1_refs.csv`;
- `analysis/usart/usart6_refs.csv`;
- `analysis/usart/usart_dma_callers.csv`;
- `analysis/usart/usart1_send_callers.csv`.
- `analysis/linux_app/hardware_interfaces.csv`.
