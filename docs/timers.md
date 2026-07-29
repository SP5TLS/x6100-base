# Timers

## Clock basis

TIM2, TIM3, and TIM4 are APB1 timers. The recovered application clock
tree supplies:

- PCLK1 = 62.5 MHz;
- APB1 timer clock = 125 MHz because the APB1 prescaler is not 1.

See `docs/clocks.md`.

## Initialization

`FUN_08032dec` enables and configures all three timers. The active
interrupt handlers are:

| Timer | Handler | Address |
| --- | --- | ---: |
| TIM2 | `TIM2_IRQHandler` | `0x08034950` |
| TIM3 | `TIM3_IRQHandler` | `0x0802DB2C` |
| TIM4 | `TIM4_IRQHandler` | `0x08034988` |

Peripheral-to-handler mapping: VERIFIED.

## TIM2: service and UART-flow scheduler

Configuration:

| Property | Value |
| --- | ---: |
| Input clock | 125 MHz |
| Prescaler register | 20 |
| Auto-reload register | 4000 |
| Update frequency | approximately 1487.72 Hz |
| Update period | approximately 672.17 µs |
| Interrupt source | update |

The period follows the STM32 timer formula:

```text
125000000 / ((20 + 1) × (4000 + 1))
```

Configuration and calculated period: VERIFIED.

On every accepted update interrupt, `TIM2_IRQHandler`:

1. calls `FUN_080337fc`, the UART-flow packet state machine;
2. calls `FUN_0803082c`;
3. calls `FUN_0803031c`;
4. updates a debounced GPIO-derived state.

The latter calls remain unnamed pending recovery of their consumers.

### UART packet cadence

A 4136-byte packet transmitted as 8-N-1 data at 1,500,000 baud occupies
approximately 27.57 ms on the wire. After DMA completion,
`FUN_080337fc` waits ten TIM2 service ticks before returning to its idle
state. This gives a minimum cycle near:

```text
27.57 ms + 10 × 0.672 ms = 34.29 ms
```

This explains the historical X6100Control observation of a packet about
every 35 ms. The state-machine relationship is VERIFIED; the 34–35 ms
wall-clock cadence is HIGH CONFIDENCE because DMA completion and timer
phase add bounded scheduling variation.

## TIM3: measurement and input service

`FUN_08032dec` derives the TIM3 prescaler from the recovered 125-MHz
APB1 timer clock:

```text
PSC = timer_clock × 1e-6 - 1 = 124
```

Configuration:

| Property | Value |
| --- | ---: |
| Prescaler register | 124 |
| Auto-reload register | 5000 |
| Update frequency | approximately 199.96 Hz |
| Update period | approximately 5.001 ms |
| Interrupt source | update |

Prescaler derivation and period: VERIFIED.

`TIM3_IRQHandler` performs software debouncing for several GPIO inputs,
updates a packed input-state word, and produces the UART telemetry bytes
for TX power, VSWR, and ALC. These consumers independently establish
TIM3 as the roughly 5-ms measurement/input service timer: HIGH
CONFIDENCE.

## TIM4: external hardware-key PWM input

Recovered base configuration:

| Property | Value |
| --- | ---: |
| Input clock | 125 MHz |
| Prescaler register | 8 |
| Auto-reload register | `0xFFFF` |
| Counter tick | approximately 13.889 MHz |
| Tick period | 72 ns |
| Full 16-bit span | approximately 4.719 ms |
| Interrupt source checked by handler | capture/compare 1 (`0x0002`) |

PD12 is configured as AF2/TIM4_CH1. The timer uses paired PWM-input
capture rather than a periodic update. On a valid interrupt,
`TIM4_IRQHandler` reads `TIM4_CCR1` and `TIM4_CCR2` and passes both
captures to `FUN_08030334`.

The decoder classifies their ratio near 2, 3, or 5; recognizes seven
preamble symbols, a delimiter, and 39 payload bits; validates a
repeated field; and publishes the extracted key through
`FUN_08033968`. After 200 TIM2 service ticks without refresh it
publishes zero. Acquisition and decoding are VERIFIED; connection to
external hand-microphone/headset keys is HIGH CONFIDENCE. See
`docs/hkey.md`.

## Reproducible evidence

- `analysis/timers/tim2_refs.csv`;
- `analysis/timers/tim3_refs.csv`;
- `analysis/timers/tim4_refs.csv`;
- `analysis/interrupts/active_irqs.csv`.
