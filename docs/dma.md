# DMA architecture

## Overview

The recovered firmware uses:

- DMA1 for two full-duplex I2S data paths;
- DMA2 for USART1 and USART6.

Only DMA1 Stream 3 has an active vector-table handler. The other audio
streams run synchronously in double-buffer mode and are coordinated
from that handler.

## DMA1 audio/IQ paths

`FUN_080320fc` configures four DMA1 streams around the SPI2/I2S2 and
SPI3/I2S3 peripheral pairs.

| Stream | Channel | Peripheral | Direction | M0 buffer | M1 buffer | Count |
| ---: | ---: | --- | --- | ---: | ---: | ---: |
| 0 | 0 | SPI3/I2S3 DR `0x40003C0C` | peripheral to memory | `0x2000D2F4` | `0x2000CEF4` | 512 |
| 3 | 0 | SPI2/I2S2 DR `0x4000380C` | peripheral to memory | `0x2000E2F4` | `0x2000DEF4` | 512 |
| 4 | 2 | I2S2ext DR `0x4000340C` | memory to peripheral | `0x2000DAF4` | `0x2000D6F4` | 512 |
| 5 | 2 | I2S3ext DR `0x4000400C` | memory to peripheral | `0x2000CAF4` | `0x2000C6F4` | 512 |

All four streams use:

- 16-bit peripheral transfers;
- 16-bit memory transfers;
- incrementing memory addresses;
- circular mode;
- double-buffer mode.

Configuration, addresses, directions, widths, and counts: VERIFIED.

Each memory bank is 512 halfwords, or `0x400` bytes. The recovered
addresses are spaced by exactly that size.

## DMA1 Stream 3 interrupt

Vector:

| Property | Value |
| --- | --- |
| IRQ | DMA1 Stream 3 |
| Handler | `FUN_08024528` |
| Address | `0x08024528` |
| Final name | not assigned |

The handler checks and clears the Stream 3 transfer-complete condition.
It then reads the current-target state of Stream 3 to select the
completed banks for both synchronized receive streams. The
current-target state of Stream 4 similarly selects the banks for both
synchronized transmit streams.

The selected buffer pointers are published through:

| RAM location | Role | Confidence |
| ---: | --- | --- |
| `0x200003CC` | completed SPI2/I2S2 receive bank | VERIFIED |
| `0x200003D4` | completed SPI3/I2S3 receive bank | VERIFIED |
| `0x200003C8` | selected I2S2ext transmit bank | VERIFIED |
| `0x200003D0` | selected I2S3ext transmit bank | VERIFIED |

After selecting the banks, the handler converts interleaved signed
samples to floating point and executes the firmware's RX/TX signal
processing. This very large interrupt routine is therefore the primary
audio/IQ DSP block callback: HIGH CONFIDENCE.

The handler also consumes a frequency-transition reset flag at
`0x20008328`, clearing numerous DSP histories at the next block
boundary. It decrements a separate transition counter at `0x2000832A`
once per completed block. Exact behavior is documented in
`docs/rf_switching.md`.

The exact sample rate still requires recovery of the I2S clock
configuration. Buffer size and double-buffer scheduling alone are
VERIFIED.

## DMA2 serial paths

| Stream | Channel | Peripheral | Direction | Buffer/use |
| ---: | ---: | --- | --- | --- |
| 1 | 5 | USART6 DR | peripheral to memory | `0x2000E77C`, 100 bytes |
| 5 | 4 | USART1 DR | peripheral to memory | `0x2000E718`, 100-byte circular buffer |
| 6 | 5 | USART6 DR | memory to peripheral | 4136-byte Linux flow packet |
| 7 | 4 | USART1 DR | memory to peripheral | diagnostic output |

DMA2 assignments and directions: VERIFIED. See `docs/usart.md` and
`docs/protocol.md` for the serial framing.

USART6 Stream 6 is programmed on demand by `FUN_08032fc8`. USART1
Stream 7 is programmed on demand by `FUN_08032f4c`.

## Independent-implementation guidance

The OEM interrupt contains extensive DSP work directly inside the
DMA1 Stream 3 handler. A compatible implementation needs to preserve
the completed-buffer ownership and I2S synchronization, but does not
need to reproduce that software structure. A short ISR that queues the
completed bank for deterministic processing is an acceptable
independent design if it meets the sample deadline.

## Reproducible evidence

- `analysis/dma/dma1_stream3_refs.csv`;
- `analysis/dma/audio_dma_callers.csv`;
- `analysis/interrupts/irq_14_DMA1_Stream3_08024528_disassembly.txt`;
- startup `.data` source at firmware address `0x0807C994`.
