# SPI/I2S sample interfaces

## Architecture

The BASE firmware uses both STM32 full-duplex I2S pairs:

- SPI2/I2S2 with I2S2ext;
- SPI3/I2S3 with I2S3ext.

SPI2 and SPI3 receive sample data. Their extension peripherals transmit
sample data. All four directions are connected to DMA1 double buffers
described in `docs/dma.md`.

Peripheral roles and directions: VERIFIED.

Signal roles recovered from the DMA handler:

| Full-duplex pair | Receive use | Transmit use | Role | Confidence |
| --- | --- | --- | --- | --- |
| SPI2 + I2S2ext | two real channels summed for TX audio | real audio samples | audio | VERIFIED |
| SPI3 + I2S3ext | separate receiver I/Q components | complex Q31 I/Q pairs | I/Q | VERIFIED |

## Pin configuration

`FUN_080320fc` configures these alternate-function pins before enabling
the I2S peripherals:

| GPIO | Pins | Alternate function |
| --- | --- | ---: |
| GPIOA | 15 | AF6 |
| GPIOC | 10 | AF6 |
| GPIOC | 11 | AF5 |
| GPIOC | 12 | AF6 |
| GPIOD | 12–15 | AF5 |

Pin and AF assignments: VERIFIED. Exact board-net names remain to be
correlated with a schematic or direct signal tracing.

## Serial format and clock ownership

The initialization structure passed to SPI2 and SPI3 selects:

- I2S slave receive mode;
- Philips I2S standard;
- 32-bit data in a 32-bit channel;
- low clock polarity;
- no MCU-generated master clock.

The I2S extension blocks are configured for the complementary slave
transmit direction.

Mode, standard, and word length: VERIFIED by the resulting I2SCFGR
fields.

Because these interfaces are slaves, word-select and bit clock are
provided by external hardware. The sample rate must not be calculated
from the MCU PLLI2S divider. Although firmware support code enables
PLLI2S and reads its reset-value configuration, the I2S slave paths do
not use it as their serial-clock source.

External I2S clock ownership: VERIFIED.

TLV320AIC3204 page-0 register `0x1B` receives `0x3C`, selecting 32-bit
I2S and making BCLK and WCLK outputs. The TLV320AIC3204 is therefore
the serial-clock master and the STM32 is the slave: VERIFIED. Whether
the same clocks are distributed to both converter pairs requires
board-net tracing.

## DMA framing

Each DMA bank contains 512 halfwords. A stereo frame with two 32-bit
channels occupies four halfwords, so one bank contains:

```text
512 / 4 = 128 stereo sample frames
```

DMA framing and 128-frame bank size: VERIFIED.

The receive words are reconstructed as signed 32-bit values and
converted to floating point at the beginning of
`DMA1_Stream3_IRQHandler`.

## DSP rate constants

`FUN_08021744`, called immediately before I2S/DMA startup, initializes
four floating-point rate constants:

| RAM address | Value | Observed use | Confidence |
| ---: | ---: | --- | --- |
| `0x2000BA40` | 100,000 | raw-rate-dependent DSP coefficient | HIGH CONFIDENCE: raw I/Q sample rate |
| `0x2000BA44` | 12,500 | primary filter and modulation stages | HIGH CONFIDENCE: primary DSP rate |
| `0x2000BA48` | 12,500 | demodulator/filter design | HIGH CONFIDENCE: audio/baseband rate |
| `0x2000BA4C` | 25,000 | alternate filter and phase stages | HIGH CONFIDENCE: alternate DSP rate |

The values themselves and their addresses are VERIFIED. Their semantic
labels are HIGH CONFIDENCE because they are repeatedly passed as the
sample-rate argument to filter and oscillator initialization routines,
but those routines have not yet received final names.

If the raw external I2S rate is 100,000 stereo frames/s, a 128-frame
DMA bank completes every 1.28 ms. This cadence is HIGH CONFIDENCE and
should be verified by tracing the external word-select signal before it
is treated as a board-level fact.

The ratio between the raw and primary DSP constants is exactly eight,
indicating an 8:1 rate conversion in the receive pipeline: HIGH
CONFIDENCE. The responsible filter/decimator code remains to be
isolated from the large DMA handler.

## Startup sequence

`FUN_080244b4` performs:

1. DSP-state initialization in `FUN_08021744`;
2. GPIO, I2S, and DMA configuration in `FUN_080320fc`;
3. external codec/control initialization;
4. enabling all four DMA streams in `FUN_080322f8`;
5. enabling the I2S receive/transmit blocks.

Ordering and function relationships: VERIFIED.

## External converter variant

One supported converter is a Cirrus Logic CS4272 at I2C2 address
`0x10`: VERIFIED from its complete register map and startup sequence.
Firmware configures it for double-speed, slave, I2S operation.

The combined evidence assigns the converters as follows:

| Device | Reset-related GPIO | I2S pair | Confidence |
| --- | --- | --- | --- |
| TLV320AIC3204 at `0x18` | PE15 toggled immediately before initialization | SPI2/I2S2 audio pair | VERIFIED |
| CS4272 at `0x10` | PG8 released immediately before its probe/configuration | SPI3/I2S3 I/Q pair | VERIFIED |
| unidentified fallback at `0x4C` | same startup branch as CS4272 | SPI3/I2S3 I/Q pair | HIGH CONFIDENCE |

The CS4272 assignment is corroborated by the X6100 service-manual block
diagram, which places it between the zero-IF quadrature mixers and the
STM32. The diagram separately places IC3204 in the MIC/speaker audio
path. Together with the independently verified SPI3 I/Q and SPI2 audio
DMA roles, this also verifies the TLV320AIC3204-to-SPI2 assignment.

If the CS4272 probe fails, startup configures an unidentified device at
I2C2 address `0x4C` instead. The mutually exclusive branch and its
placement in audio startup identify it as an alternate sample-converter
implementation: HIGH CONFIDENCE.

Exact I2C payloads and device evidence are documented in `docs/i2c.md`.

## Independent-implementation guidance

An independent implementation must treat the external sample clock as
authoritative. It must configure the TLV320AIC3204 dividers and
master-I2S direction before relying on BCLK/WCLK, and must keep all four
I2S DMA streams phase-aligned at bank boundaries.

## Reproducible evidence

- `analysis/i2s/rcc_plli2s_refs.csv`;
- `analysis/i2s/sample_rate_refs.csv`;
- `analysis/i2s/i2s_signal_roles.csv`;
- `analysis/i2c/i2c2_aux_startup_sequences.csv`;
- `analysis/dma/audio_dma_callers.csv`;
- `analysis/dma/dma1_stream3_refs.csv`.
