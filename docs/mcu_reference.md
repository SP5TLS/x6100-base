# MCU reference: pins and internals

A single-page summary of the STM32F427 pin and peripheral facts recovered
from BASE firmware 1.1.9
(`3fa11293e06951c21c9cfda04ea08adad85eaadda26b77a8e8bbcca8820c53c4`).
It adds no new findings. The evidence and full detail are in the linked
subsystem documents.

Confidence column: **V** = VERIFIED, **HC** = HIGH CONFIDENCE,
**MC** = MEDIUM CONFIDENCE, **H** = HYPOTHESIS. Where the firmware
behaviour is verified but the board role is not, both are given
(e.g. "V levels / HC role").

## Core

| Item | Value | Conf. |
| --- | --- | --- |
| MCU | STM32F427, Cortex-M4F, Thumb-2, little-endian | V |
| FPU | CP10/CP11 enabled by `SystemInit` (`SCB_CPACR`) | V |
| Vector table | `0x08020000`, 108 words (16 core + 92 external); `SCB_VTOR = 0x08020000` | V |
| Initial MSP | `0x20030000` | V |
| Reset handler | `0x08034A18` (vector `0x08034A19`) | V |
| Execution model | bare-metal superloop + 6 IRQs; SVC/PendSV/SysTick vectors = default handler | V superloop / HC no RTOS |
| NVIC grouping | `AIRCR = 0x05FA0500` (PRIGROUP 5) via `FUN_0802ded4(0x500)` | V |
| Watchdogs | IWDG and WWDG never touched; `RCC_CSR` never read | HC |
| Software reset | `AIRCR` `SYSRESETREQ` at the end of shutdown | V |
| CCMRAM | not used | HC |
| ADC3 | not used | HC |

## Clocks

| Item | Value | Conf. |
| --- | --- | --- |
| Hand-off from bootloader | SYSCLK on bootloader PLL (~180 MHz); `SystemInit` returns to HSI (`RCC_CFGR = 0`, HSEON/PLLON cleared, `RCC_PLLCFGR = 0x24003010`) | V (rs on radio) |
| HSE | 25 MHz (firmware assumption) | V |
| `RCC_PLLCFGR` | `0x04403C0C`: HSE source, M = 12, N = 240, P = 2, Q = 4 | V |
| SYSCLK / HCLK | 250 MHz (over nominal 180 MHz max) | V config / HC physical |
| PCLK1 / APB1 timers | 62.5 MHz / 125 MHz (PPRE1 = /4) | V |
| PCLK2 / APB2 timers | 125 MHz / 250 MHz (PPRE2 = /2) | V |
| PLLQ output | 125 MHz | V |
| `FLASH_ACR` | `0x705`: 5 wait states, prefetch, I-cache, D-cache | V |
| `PWR_CR` | over-drive bits set before PLL start (open: may be VOS scale 1 `0xC000`, see below) | V write |
| `SystemCoreClock` | stored at `0x200033A4` (16 000 000, then 250 000 000) | V |
| PLLI2S | enabled but unused; I2S runs as slave on external clocks | V |
| SysTick | polling delay only, no interrupt; `delay(n)` = (n − 1) × 0.704 ms | V (rs hwsim) |

`delay(n)` examples: `delay(1)` = 0, `delay(10)` = 6.34 ms,
`delay(100)` = 69.7 ms, `delay(3000)` = 2.11 s, `delay(5000)` = 3.52 s.


## Memory

| Region | Range | Conf. |
| --- | --- | --- |
| Not in image (bootloader + persistent blocks) | `0x08000000`–`0x0801FFFF` | V |
| Calibration block, primary copy | `0x08004000` (204 words, magic `0xAA5555AA`, CRC32 word 203) | V |
| Configuration read path | `0x08008000` | V |
| Calibration block, legacy/migration copy | `0x080E0000` | V |
| Application image | `0x08020000`–`0x0807FB70` (392 048 B) | V |
| Code | `0x080201B0`–`0x0803CEF0` | HC |
| Read-only data | `0x0803CEF0`–`0x0807C5C8` | HC |
| init arrays | `0x0807C5C8`–`0x0807C5D0` | V |
| `.data` load image | `0x0807C5D0`–`0x0807FB40` → `0x20000000`–`0x20003570` | V |
| Image trailer (not copied) | `0x0807FB40`–`0x0807FB70` | V |
| `.bss` | `0x20003570`–`0x2000EB00` | V range / HC name |
| Heap (`_sbrk`, break at `0x2000E9B0`) | from `0x2000EB00`, grows to SP | V |
| Stack | down from `0x20030000`; heap + stack share 136 448 B | V |


## Active interrupts

All other external vectors → `Default_Handler` `0x08034A68` (infinite loop).

| IRQ | Vector | Handler | Job | Conf. |
| ---: | --- | ---: | --- | --- |
| 14 | DMA1_Stream3 | `0x08024528` | I2S bank completion + all RX/TX DSP; PB2 marker | V |
| 28 | TIM2 | `0x08034950` | UART-flow state machine, ADC2 filter, PG15 debounce | V |
| 29 | TIM3 | `0x0802DB2C` | input debounce, TX power/VSWR/ALC telemetry, PG4 hold counter | V |
| 30 | TIM4 | `0x08034988` | PD12 PWM-input capture → hkey decoder | V |
| 72 | I2C3_EV | `0x08033990` | Linux control-register slave | V |
| 73 | I2C3_ER | `0x08033B88` | I2C3 error clear | V |

## Timers

| Timer | PSC | ARR | Rate | Use | Conf. |
| --- | ---: | ---: | --- | --- | --- |
| TIM2 | 20 | 4000 | 1487.72 Hz (672.17 µs) | update IRQ: flow scheduler, ADC2 filter, PG15 debounce | V |
| TIM3 | 61 | 5000 | 403.15 Hz (2.4805 ms) | update IRQ: debounce, telemetry | V (rs hwsim) |
| TIM4 | 8 | `0xFFFF` | 13.889 MHz tick (72 ns), 4.719 ms span | PWM input on CH1 (PD12), CCR1 + CCR2, IRQ on CC1 | V |

TIM3's PSC is computed from PCLK1 (62.5 MHz), but the timer counts at
125 MHz.

## DMA

| Controller / stream | Ch. | Peripheral | Dir. | Buffers | Mode | Conf. |
| --- | ---: | --- | --- | --- | --- | --- |
| DMA1 S0 | 0 | SPI3/I2S3 DR `0x40003C0C` | P→M | M0 `0x2000D2F4`, M1 `0x2000CEF4`, 512 HW | 16/16-bit, circular, double-buffer | V |
| DMA1 S3 | 0 | SPI2/I2S2 DR `0x4000380C` | P→M | M0 `0x2000E2F4`, M1 `0x2000DEF4`, 512 HW | same; TC IRQ | V |
| DMA1 S4 | 2 | I2S2ext DR `0x4000340C` | M→P | M0 `0x2000DAF4`, M1 `0x2000D6F4`, 512 HW | same | V |
| DMA1 S5 | 2 | I2S3ext DR `0x4000400C` | M→P | M0 `0x2000CAF4`, M1 `0x2000C6F4`, 512 HW | same | V |
| DMA2 S0 | 0 | ADC1 | P→M | `0x2000C6B4`, 3 HW | circular scan | V |
| DMA2 S2 | 1 | ADC2 | P→M | `0x2000C694`, 15 HW | circular scan | V (open: may be S3) |
| DMA2 S1 | 5 | USART6 RX | P→M | `0x2000E77C`, 100 B | — | V |
| DMA2 S5 | 4 | USART1 RX | P→M | `0x2000E718`, 100 B | circular | V |
| DMA2 S6 | 5 | USART6 TX (`0x40011404`) | M→P | `0x200003F8`, 4136 B per packet | on demand | V |
| DMA2 S7 | 4 | USART1 TX | M→P | caller buffer | on demand | V |

The I2S banks are 512 halfwords each, i.e. 128 stereo 32-bit frames. At
a 100 kHz frame rate a bank completes every 1.28 ms (HC). The DSP
handler publishes the completed bank pointers at `0x200003CC` (I2S2 RX),
`0x200003D4` (I2S3 RX), `0x200003C8` (I2S2ext TX) and `0x200003D0`
(I2S3ext TX).

## Serial peripherals

| Peripheral | Pins / AF | Config | Attached | Conf. |
| --- | --- | --- | --- | --- |
| I2C1 | PB6 SCL, PB7 SDA, AF4 | master, 100 kHz, polling | MAX17205 `0x36`; 5P49V60 LO `0x6A` (HC); PA-bias DAC `0x63` (IC unknown); PCA9535 `0x20` (HC family); BQ24715 `0x09` | V |
| I2C2 | PB10 SCL, PB11 SDA, AF4 | master, 100 kHz, polling | CS4272 `0x10`; TLV320AIC3204 `0x18`; unknown `0x4A`; unknown `0x4C` (CS4272 fallback) | V |
| I2C3 | PA8 SCL, PC9 SDA, AF4 | slave, own address `0x72`, 400 kHz, EV + ER IRQ | Linux `/dev/i2c-0` | V |
| USART1 | PA9 TX, PA10 RX, AF7 | 115 200 8-N-1 | debug/stdio | V pins / HC role |
| USART6 | PC6 TX, PC7 RX, AF8 | 1 500 000 8-N-1 (BRR `0x53` → 1.506 Mbaud) | Linux `/dev/ttyS1` flow + IAP | V (rs on radio) |
| SPI2 + I2S2ext | PB12–PB15 | I2S slave, Philips, 32-bit, CPOL low, no MCLK; SPI2 RX, ext TX | TLV320AIC3204 audio | V |
| SPI3 + I2S3ext | PA15, PC10–PC12 | same; SPI3 RX, ext TX | CS4272 I/Q | V |
| SPI6 | PG13 SCK, PG14 MOSI, AF5; PG12 GPIO latch | TX only, 3 bytes MSB first | 24-bit ATU + secondary RF relay image | V |
| CRC | `0x40023000` | `CRC_CR = 1`, then 0x409 words | UART flow packet CRC at offset `0x1024` | V |

The TLV320AIC3204 is the I2S clock master: page 0 register `0x1B` is
written with `0x3C`. I2C address bytes in the firmware are shifted left
by one; the table gives 7-bit addresses. On a transfer failure, I2C1
recovery reconfigures PB6/PB7 as GPIO, clocks PB7 ten times, and
re-initialises the peripheral. 

## Analog

| Resource | Pin | Use | Conf. |
| --- | --- | --- | --- |
| ADC1 ch0 | PA0 | forward RF detector; `x = adc × 0.012165527`, `P = x(0.0115375x + 0.06)` W | V math / HC role |
| ADC1 ch1 | PA1 | reflected RF detector, same polynomial; VSWR | V math / HC role |
| ADC1 ch2 | PA2 | ALC correction `clamp(1 + 0.005(4000 − adc), 1, 20)`; ACC `ALC_V` | V math / HC role |
| ADC2 ch6 | PA6 | external supply: filtered × 4.835165 (mV) | V path / HC role |
| ADC2 ch7 | PA7 | PA current feedback for bias calibration | HC |
| ADC2 ch14 | PC4 | sampled and filtered, no consumer found | V |
| DAC ch1 | PA4 | initialised to 0, never written again | HC |
| DAC ch2 | PA5 | ACC `BAND_V` staircase `0x11D`…`0xC43` (~230 mV/step) | V codes / HC role |

The ADC2 buffer holds 5 × (ch6, ch7, ch14). On every TIM2 tick each
channel is filtered as `y = 0.92y + 0.016·Σ5`.

## Pin map

The "Config" column is the configuration set by firmware. "—" means no
known role. Every STM32 pin not listed here has no recovered access.

### GPIOA

| Pin | Config | Function | Conf. |
| --- | --- | --- | --- |
| PA0 | analog | ADC1_IN0, forward RF | V / HC role |
| PA1 | analog | ADC1_IN1, reflected RF | V / HC role |
| PA2 | analog | ADC1_IN2, ALC / ACC `ALC_V` | V / HC role |
| PA3 | output | — | V |
| PA4 | analog | DAC_OUT1, held at 0 | V |
| PA5 | analog | DAC_OUT2, ACC `BAND_V` | V / HC role |
| PA6 | analog | ADC2_IN6, external supply voltage | V / HC role |
| PA7 | analog | ADC2_IN7, PA current | V / HC role |
| PA8 | AF4 | I2C3_SCL (Linux control) | V |
| PA9 | AF7 | USART1_TX | V |
| PA10 | AF7 | USART1_RX | V |
| PA11 | input | TIM3 debounce (reload 1, flag `0x200001D2`), active-low; feeds CW key in CW/CWR | V; source unknown |
| PA12 | input | TIM3 debounce (reload 1, flag `0x200001E6`), active-low | V; source unknown |
| PA13, PA14 | debug | SWD (configured first by the GPIO initialiser) | V |
| PA15 | AF6 | I2S3 pair (datasheet AF6: SPI3_NSS/I2S3_WS) | V AF |

### GPIOB

| Pin | Config | Function | Conf. |
| --- | --- | --- | --- |
| PB0 | output, high speed | clock for the software shift chains (data PC5) | V |
| PB1 | output, high speed | latch for the 6-bit RF-gain chain | V / HC role |
| PB2 | output | toggled at entry and exit of the DMA1_S3 DSP handler (timing marker) | V / HC role |
| PB6 | AF4 | I2C1_SCL | V |
| PB7 | AF4 | I2C1_SDA | V |
| PB8 | input | — | V |
| PB9 | input | PTT, active-low, debounce reload 10 (24.8 ms), sets TX source bit `0x2` | V / HC role |
| PB10 | AF4 | I2C2_SCL | V |
| PB11 | AF4 | I2C2_SDA | V |
| PB12 | AF5 | I2S2 pair (datasheet: SPI2_NSS/I2S2_WS) | V AF |
| PB13 | AF5 | I2S2 pair (datasheet: SPI2_SCK/I2S2_CK) | V AF |
| PB14 | AF6 | I2S2 pair (datasheet: I2S2ext_SD) | V AF |
| PB15 | AF5 | I2S2 pair (datasheet: SPI2_MOSI/I2S2_SD) | V AF |

### GPIOC

| Pin | Config | Function | Conf. |
| --- | --- | --- | --- |
| PC4 | analog | ADC2_IN14, unknown | V |
| PC5 | output, high speed | data for the software shift chains (MSB first) | V |
| PC6 | AF8 | USART6_TX | V |
| PC7 | AF8 | USART6_RX | V |
| PC9 | AF4 | I2C3_SDA | V |
| PC10 | AF6 | I2S3 pair (datasheet: SPI3_SCK/I2S3_CK) | V AF |
| PC11 | AF5 | I2S3 pair (datasheet: I2S3ext_SD) | V AF |
| PC12 | AF6 | I2S3 pair (datasheet: SPI3_MOSI/I2S3_SD) | V AF |

### GPIOD

| Pin | Config | Function | Conf. |
| --- | --- | --- | --- |
| PD0 | input | TIM3 debounce (reload 1, flag `0x200001FA`), active-low; feeds CW key in CW/CWR | V; source unknown |
| PD2 | output | high at startup, cleared last in shutdown; power hold | V / HC role |
| PD3 | output | `+5R`: RX = 1, TX = 0; toggled in the early charge loop | V / HC role |
| PD4 | output | `+5T`: RX = 0, TX = 1; low at early boot | V / HC role |
| PD9, PD10, PD11, PD13 | output (direct variant) | primary RF band index, binary weights 1/2/4/8 | V |
| PD12 | AF2 | TIM4_CH1, hand-mic/headset key PWM input | V / HC role |
| PD14 | output (direct variant) | PA-control callback (= PCA9535 bit 0) | V |
| PD15 | output (direct variant) | variant callback (= PCA9535 bit 15), set by register bit 6 change | V; role H |

### GPIOE

| Pin | Config | Function | Conf. |
| --- | --- | --- | --- |
| PE2 | output | ACC `TRX`: RX = 0, TX = 1 | V / HC role |
| PE3 | input | TIM3 debounce (reload 10, 24.8 ms, flag `0x20000196`), active-low | V; source unknown |
| PE7 | output | cleared at shutdown | V; role unknown |
| PE8 | output | PA tuple: enabled = 1 | V |
| PE9 | output | PA tuple: enabled = 0, disabled = 1; low at shutdown | V |
| PE10 | output | PA-bias DAC commit: low → delay → high after a changed write | V / HC role |
| PE11 | output | high during run; cleared with PD2 and again after the PG4 wait | V |
| PE12 | output | TX/key, active-low: low for the whole non-CW TX, follows the envelope in CW, high in RX | V (rs hwsim + radio) |
| PE13 | input | early charge loop "full" condition (low = full) | V; net unknown |
| PE14 | output | cleared at shutdown | V; role unknown |
| PE15 | output | TLV320AIC3204 reset, active-low; released once before codec programming | V / HC role |

### GPIOF

| Pin | Config | Function | Conf. |
| --- | --- | --- | --- |
| PF11 | output | high in the early loop, low after board init, high at shutdown | V; net H |
| PF12 | output | charger enable, active-high (= PCA9535 bit 1, active-low) | V / HC role |
| PF13 | input | KEY ring / `DA` / dash, active-low, TIM3 reload 1 | V / HC role |
| PF14 | input | KEY tip / `DI` / dot, active-low, TIM3 reload 1 | V / HC role |
| PF15 | input | S/P jack detect: stable low with `spmode` = 1 → RX audio × 0.05 | V / HC role |

### GPIOG

| Pin | Config | Function | Conf. |
| --- | --- | --- | --- |
| PG0 | output PP, pull-up | high at startup, cleared at shutdown | V; role unknown |
| PG1 | output PP, pull-up | low at init, high at startup, cleared at shutdown | V; role unknown |
| PG2 | output OD (direct variant) | callback slot `0x2000C6BC` (= PCA9535 bit 2, active-low); polarity from a board flag | V |
| PG3 | output OD (direct variant) | callback slot `0x2000C6C0` (= PCA9535 bit 10) | V |
| PG4 | input | power button, active-low: hold ≥ 2000 TIM3 ticks (4.96 s) → shutdown; awaited high before final reset | V / HC role |
| PG5 | output (direct variant) | callback slot `0x2000C6C4` (= PCA9535 bit 14) | V |
| PG6 | output PP, pull-up | latch for the 16-bit PC5/PB0 RF chain (low during shift, then high) | V |
| PG8 | output PP, pull-up | CS4272 reset, active-low: low before I2S setup, high before probe | V levels / HC role |
| PG11 | output PP, pull-up | PA tuple: enabled = 1 | V |
| PG12 | output | SPI6 latch: high, 3 bytes, low | V |
| PG13 | AF5 | SPI6_SCK | V |
| PG14 | AF5 | SPI6_MOSI | V |
| PG15 | input | debounced by TIM2 (9 ticks) | V; role unknown |

## Ordered GPIO sequences

**Early boot (`FUN_08032500`).** Configure PF11/PF12/PD3/PD4 as outputs
and PE13/PG4 as inputs. Drive PF11 = 1, PF12 = 0, PD4 = 0. During the
charge loop, PD3 toggles; it is held at 1 when full. (V)

**After board init (`FUN_08034178`).** PE15 = 0 and PG8 = 0 → timers →
PG0 = PG1 = 1 → variant callback(1) → PD2 = 1, PF11 = 0 → bias = 0 → PA
tuple asserted for bias calibration → bias = 0 → RX-safe state. (V)

**Audio start.** PG8 = 0 → PE15 = 0, then 1 → program TLV320 → `0x4A`
→ enable DMA/I2S → PG8 = 1 → probe CS4272 (fallback `0x4C`). (V)

**Enter RX.** PE12 = 1 → callback(0) → bias ch0 = 0 → bias ch1 = 0 →
PE9 = 1 → PE8 = 0 → PG11 = 0 → PE2 = 0 → DSP state → PD3 = 1 →
PD4 = 0. (V)

**Enter TX.** bias ch0 = drive code → bias ch1 = final code →
callback(1) → PE9 = 0 → PE8 = 1 → PG11 = 1 → PE2 = 1 → PD3 = 0 →
PD4 = 1. PE12 is driven low by the DSP handler. (V)

**PA tuple.** Disabled = {PE8 = 0, PE9 = 1, PG11 = 0, callback = 0}.
Enabled = {1, 0, 1, 1}. At shutdown, all are 0. (V)

**Shutdown** (register `0x0030` bit 16, or a 4.96 s PG4 hold). Quiesce
→ PG0/PG1/PG11 = 0 → PE7/PE8/PE9/PE14 = 0 → PD4 = 0 → PF11 = 1 →
3.52 s → PD3 = 0 → 2.11 s → PD2 = 0, PE11 = 0 → PRIMASK → wait PG4 = 1
→ PE11 = 0 → 69.7 ms → DSB → `SYSRESETREQ`. (V)


## Software shift chains

| Chain | Data / clock | Latch | Width | Use | Conf. |
| --- | --- | --- | --- | --- | --- |
| `FUN_0802cf88` | PC5 / PB0 | PB1 pulse | 6 bits | RF gain/attenuator: `rfg` 0–36 → `0x3F`, 37–100 → `100 − rfg`, > 100 → 0 | V / HC role |
| `FUN_0802d310` | PC5 / PB0 | PG6 low during shift, then high | 2 × 8 bits, MSB first | RF relay chain | V / HC role |
| `FUN_0802d15c` | PC5 / PB0 | PG6 | fixed startup pattern | same chain | V |

## Board-variant callback table

`FUN_0803131C` installs one of two backends.

| Slot | PCA9535 (`0x20`, I2C1) | Direct GPIO |
| --- | --- | --- |
| `0x2000C6BC` | bit 2, active-low | PG2 |
| `0x2000C6C0` | bit 10 | PG3 |
| `0x2000C6C4` | bit 14 | PG5 |
| `0x2000C6C8` (charger) | bit 1, active-low | PF12 |
| `0x2000C6CC` (PA) | bit 0 | PD14 |
| `0x2000C6D0` | bit 15 | PD15 |
| `0x2000C6D4` (RF band) | one-hot mask | PD9/PD10/PD11/PD13 binary |

The mapping is VERIFIED. The board revision that uses each backend is
unknown. See `analysis/pa/variant_callback_map.csv`.

## Open contradictions (not yet resolved)


- `PWR_CR |= 0xC000` may be VOS scale 1, not over-drive.
- Jack detect may be PF15 rather than PG15 (this affects the TIM2
  debounce entry).
- The I2C3 error handler may set CR1.PE, not ACK.
- I2C1 may run at about 390 kHz after the clock switch.
- ADC2 may use DMA2 Stream 3, not Stream 2.

## Unknowns

- Board nets: PA3, PB8, PC4, PE7, PE11, PE13, PE14, PF11, PG0, PG1,
  PG15, and PA11/PA12/PD0/PE3.
- Which board revision uses the PCA9535 backend and which uses direct
  GPIO.
- The identities of the PA-bias IC (`0x63`) and of the `0x4A` and `0x4C`
  devices.
- The physical I2S frame rate (to be measured on WS).
- Bootloader contents in `0x08000000`–`0x0801FFFF`.
