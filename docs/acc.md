# ACC connector hardware mapping

## External connector

The published X6100 user manual defines the four-contact 3.5 mm TRRS
ACC connector as:

| Contact | Published signal |
| --- | --- |
| tip | `TRX` |
| first ring | `BAND_V` |
| second ring | `ALC_V` |
| sleeve | GND |

Connector order and published names: VERIFIED from the
[X6100 user manual](https://xiegu.ru/attachments/get/47/xiegu_x6100_user_manual_20211123.pdf).

## BASE-side mapping

| ACC signal | STM32 resource | Firmware behavior | Confidence |
| --- | --- | --- | --- |
| `TRX` | PE2 through the external ACC interface circuitry | low in RX, high in TX | HIGH CONFIDENCE |
| `BAND_V` | DAC channel 2 / PA5 | frequency-dependent 12-bit staircase | HIGH CONFIDENCE |
| `ALC_V` | ADC1 channel 2 / PA2 | fast ALC correction input | HIGH CONFIDENCE |
| GND | board ground | connector common | VERIFIED externally |

The service manual tells the technician to check the MCU wiring and
the `TR` switching level at ACC test point A1. PE2 is the only
remaining direct GPIO in the central RX/TX transition with exactly
RX=`0`, TX=`1`: VERIFIED firmware behavior and HIGH CONFIDENCE
physical correlation.

## Band-voltage generation

`FUN_0802c840` writes these codes to the STM32 internal DAC channel 2:

| Step | Frequency region | Code | Approximate output at 3.3 V |
| ---: | --- | ---: | ---: |
| 1 | ≤2 MHz | `0x11D` | 0.230 V |
| 2 | >2–5 MHz | `0x23A` | 0.459 V |
| 3 | >5–7 MHz | `0x358` | 0.690 V |
| 4 | >7–10 MHz | `0x475` | 0.920 V |
| 5 | >10–14 MHz | `0x593` | 1.150 V |
| 6 | >14–18 MHz | `0x6B0` | 1.380 V |
| 7 | >18–21 MHz | `0x7CD` | 1.610 V |
| 8 | >21–24 MHz | `0x8EB` | 1.840 V |
| 9 | >24–28 MHz | `0xA08` | 2.070 V |
| 10 | >28–50 MHz | `0xB26` | 2.300 V |
| 11 | >50 MHz | `0xC43` | 2.530 V |

The codes form an eleven-step staircase at approximately 230 mV per
step:

`Vout = code × 3.3 / 4095`

The X6100 extended documentation independently describes ACC band
control in 230 mV steps. The code table and PA5 DAC routing are
VERIFIED; identifying PA5 as the ACC `BAND_V` source is HIGH
CONFIDENCE.

## ALC input

ADC1 channel 2 on PA2 produces:

`correction = clamp(1 + 0.005 × (4000 - adc), 1, 20)`

The multiplier enters the fast TX ALC path. Its direction, timing, and
arithmetic are VERIFIED. Correlation with the published ACC `ALC_V`
contact is HIGH CONFIDENCE.

## Independent implementation requirements

- Configure PA5 as STM32 DAC channel 2 and reproduce the exact
  frequency/code boundaries.
- Configure PA2 as ADC1 channel 2 in the existing three-channel
  scan/DMA sequence.
- Drive PE2 low in RX and high in TX; verify actual connector polarity
  through the external interface circuit before direct connection to
  third-party equipment.
- Preserve the connector contact order. Do not treat the four-contact
  ACC jack as an ordinary three-contact stereo connector.

## Remaining work

- Confirm PE2 continuity to the ACC `TRX` interface circuit.
- Measure the unloaded and loaded `BAND_V` staircase at the connector.
- Recover the external scaling/protection network between `ALC_V` and
  PA2.
