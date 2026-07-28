# Linux to BASE protocol

## Evidence sources

### BASE firmware

Firmware:

`X6100_BBFW_V1.1.9_251127001.bin`

SHA-256:

`3fa11293e06951c21c9cfda04ea08adad85eaadda26b77a8e8bbcca8820c53c4`

Relevant handlers:

- `I2C3_EV_IRQHandler` at `0x08033990`;
- `I2C3_ER_IRQHandler` at `0x08033B88`.

### Linux reference implementation

Local project:

`/home/master/r1cbu/x6100/X6100Control`

Reviewed revision:

`4159e1142783c3c4f2f196b385721fb3975ee13d`

The project implements the Linux side of a protocol recovered from an
older firmware/UI generation. The repository revision is from 2023;
the association with BASE firmware 1.1.6 was supplied by the project
owner. Its names are therefore historical evidence, not automatically
final names for BASE 1.1.9.

## Transports

X6100Control uses two transports:

| Purpose | Linux device | Parameters | 1.1.9 status |
| --- | --- | --- | --- |
| Control register file | `/dev/i2c-0` | slave address `0x72` | VERIFIED |
| IQ and telemetry flow | `/dev/ttyS1` | 1,152,000 baud, raw | MEDIUM CONFIDENCE pending BASE-side framing verification |

## I2C control framing

### Single register write

X6100Control transmits a packed six-byte message:

| Byte | Meaning |
| ---: | --- |
| 0 | 16-bit byte address, high byte |
| 1 | 16-bit byte address, low byte |
| 2–5 | 32-bit value, little endian |

The byte address is `command_index * 4`.

The BASE event handler independently confirms that the first received
byte becomes the high address byte and the second becomes the low
address byte. Subsequent bytes are stored sequentially into RAM.

Framing and byte order: VERIFIED for BASE 1.1.9.

### BASE I2C3 initialization

`FUN_08033d64` initializes I2C3 at `0x40005C00` with:

| Property | Value |
| --- | ---: |
| Clock rate | 400,000 Hz |
| Own-address field | `0x00E4` |
| 7-bit slave address | `0x72` |
| ACK | enabled |
| Addressing mode | 7 bit |

The STM32 peripheral stores the 7-bit own address shifted left by one,
so `0xE4 >> 1` gives `0x72`. The same function configures PA8 and PC9
for I2C3 alternate function and enables the event/error interrupt path.

I2C3 peripheral and Linux-visible slave-address identification:
VERIFIED.

### Bulk control write

X6100Control initializes or refreshes the complete control file using:

- two address bytes, both zero;
- 56 little-endian 32-bit values;
- total transfer length: 226 bytes.

BASE 1.1.9 initializes its normal I2C write target as:

| Property | Value |
| --- | ---: |
| RAM base | `0x2000C4C8` |
| Length | `0xE0` bytes |
| 32-bit entries | 56 |

The independently recovered size is an exact match for
`x6100_last + 1` in X6100Control.

Existence and size of the 56-entry control register file: VERIFIED.

Preservation of every 1.1.6 command meaning in 1.1.9: HIGH CONFIDENCE,
pending correlation with each BASE-side consumer.

## Historical control register labels

These names come from X6100Control. Offsets and layout are VERIFIED as
the Linux implementation's wire format. Their semantics in BASE 1.1.9
are currently HIGH CONFIDENCE rather than final symbol names.

| Index | Byte offset | Historical label |
| ---: | ---: | --- |
| 0 | `0x0000` | `vfoa_ham_band` |
| 1 | `0x0004` | `vfoa_freq` |
| 2 | `0x0008` | `vfoa_att` |
| 3 | `0x000C` | `vfoa_pre` |
| 4 | `0x0010` | `vfoa_mode` |
| 5 | `0x0014` | `vfoa_agc` |
| 6 | `0x0018` | `vfob_ham_band` |
| 7 | `0x001C` | `vfob_freq` |
| 8 | `0x0020` | `vfob_att` |
| 9 | `0x0024` | `vfob_pre` |
| 10 | `0x0028` | `vfob_mode` |
| 11 | `0x002C` | `vfob_agc` |
| 12 | `0x0030` | `sple_atue_trx` |
| 13 | `0x0034` | `vi_vm` |
| 14 | `0x0038` | `rxvol` |
| 15 | `0x003C` | `rfg_txpwr` |
| 17 | `0x0044` | `atu_network` |
| 20 | `0x0050` | `ling_loutg_imicg_hmicg` |
| 21 | `0x0054` | `micsel_pttmode_chge_spmode_auxiqgen_sqlthr` |
| 22 | `0x0058` | `voxg_voxag_voxdly_voxe` |
| 23 | `0x005C` | `nrthr_nbw_nbthr_nre_nbe` |
| 24 | `0x0060` | `dnfcnt_dnfwidth_dnfe` |
| 25 | `0x0064` | `cmplevel_cmpe` |
| 27 | `0x006C` | `agcknee_agcslope_agchang` |
| 28 | `0x0070` | `agctime` |
| 29 | `0x0074` | `monilevel` |
| 33 | `0x0084` | `ks_km_kimb_cwtone_cwvol_cwtrain` |
| 34 | `0x0088` | `qsktime_kr` |
| 41 | `0x00A4` | `biasdrive_biasfinal` |
| 42 | `0x00A8` | `rit` |
| 43 | `0x00AC` | `xit` |
| 44 | `0x00B0` | `filter1_low` |
| 45 | `0x00B4` | `filter1_high` |
| 46 | `0x00B8` | `filter2_low` |
| 47 | `0x00BC` | `filter2_high` |
| 48 | `0x00C0` | `rphscmp` |
| 49 | `0x00C4` | `rmagcmp` |
| 50 | `0x00C8` | `txiofs` |
| 51 | `0x00CC` | `txqofs` |
| 53 | `0x00D4` | `pwrsync` |
| 55 | `0x00DC` | `last` |

Unlisted entries remain unnamed. They must not be assumed unused
without checking BASE 1.1.9.

## Semantics verified in BASE 1.1.9

### Register 12: operation flags

Address: `0x0030`

X6100Control historical label: `sple_atue_trx`

`FUN_0802adf4` reads bit `0x00002000` from this register while running
an ATU-related sequence and waits for the bit to clear before returning.
X6100Control assigns the same bit to `x6100_atu_tune`.

Register 12 bit `0x00002000` means ATU tune active/requested: VERIFIED.

Other register 12 bits retain HIGH CONFIDENCE historical meanings until
their individual consumers are checked.

### Register 55: Linux boot handshake

Address: `0x00DC`

X6100Control historical label: `last`

`FUN_0802d7e8` returns register 55. During early boot,
`FUN_08032500` repeatedly checks bit `0x00100000`; when it becomes set,
the preliminary service loop exits, I2C3 is temporarily shut down, and
the main initialization path continues. X6100Control initializes
register 55 to `0x00100001`.

Register 55 bit `0x00100000` is a Linux-to-BASE boot-ready/continue
handshake: VERIFIED.

The meaning of register 55 bit 0 remains unknown.

## I2C direction-dependent address spaces

The same 16-bit address selects different RAM windows depending on
transfer direction.

### Linux writes to BASE

| Address range | BASE destination | Size/wrapping | Confidence |
| --- | --- | --- | --- |
| normal addresses | `0x2000C4C8` | `0xE0` bytes, circular | VERIFIED |
| `0xF000–0xFFFD` | `0x2000C190` | `0x330` bytes, circular | VERIFIED |
| `0xFFFE–0xFFFF` | `0x2000E7E4` | `0x100` bytes, circular | VERIFIED |

The exact accepted normal-address bounds still need a simplified
control-flow proof; the table records the destinations selected by the
observed branches.

### Linux reads from BASE

| Address range | BASE source | Behavior | Confidence |
| --- | --- | --- | --- |
| `0x0000–0x007F` | `0x2000E8E4` | 128-byte circular window | VERIFIED |
| `0x0080–0x00FF` | — | returns zero | HIGH CONFIDENCE |
| `0x0100–0x0FFF` | `0x2000C190` | `0x330`-byte circular window | VERIFIED |
| `0xF000–0xFFFD` | `0x2000C190` | aliased circular window | VERIFIED |
| `0xFFFE–0xFFFF` | — | returns constant `0x61` | HIGH CONFIDENCE |

The semantic purpose of the telemetry and special windows remains
unknown.

## UART flow evidence from X6100Control

The historical Linux implementation expects packets containing:

- magic `0xAA5555AA`;
- 512 `_Complex float` IQ samples;
- TX/charger/external-power flags;
- TX power, VSWR, ALC, voltage, battery, ATU, and key telemetry;
- CRC32 using polynomial `0x04C11DB7`;
- typical packet interval near 35 ms.

This is VERIFIED behavior of the reviewed X6100Control revision.
Compatibility with BASE 1.1.9 is a HYPOTHESIS until the corresponding
USART/DMA producer is recovered.

## Remaining work

- Correlate the remaining control words with BASE-side consumers.
- Determine the meanings of the read and special I2C windows.
- Locate the UART packet builder and verify its 1.1.9 structure.
- Compare command additions or changed bitfields between 1.1.6 and
  1.1.9.
