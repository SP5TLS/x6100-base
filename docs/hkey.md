# External hardware-key input

## Recovered hardware path

The UART-flow `hkey` field is produced by a dedicated timer-capture
path, not by GPIO polling or an ADC resistor ladder:

```text
external encoded waveform
  -> PD12 / AF2
  -> TIM4_CH1 PWM-input capture
  -> TIM4 CCR1 and CCR2
  -> FUN_08030334 frame decoder
  -> FUN_08033968
  -> UART flow word at 0x1020
```

PD12, AF2, TIM4 configuration, both capture registers, decoder, setter,
and packet destination are VERIFIED. The historical field name `hkey`
and its use for keys on the external hand microphone/headset make that
external role HIGH CONFIDENCE. Board continuity from PD12 to the
connector remains to be measured before assigning a final net name.

An earlier resource map incorrectly listed the I2S pins as PD12...PD15.
The I2S initializer actually passes GPIO base `0x40020400`, which is
GPIOB, so those pins are PB12...PB15. PD12 is not reconfigured and
remains available to TIM4: VERIFIED correction.

## Timer acquisition

TIM4 is configured as a PWM-input measurement on channel 1:

| Property | Value |
| --- | ---: |
| Input pin | PD12, AF2 |
| Prescaler register | 8 |
| Counter tick | approximately 72 ns |
| Auto-reload | `0xFFFF` |
| Digital input filter | `0x0F` |
| Interrupt | capture/compare flag `0x0002` |

The interrupt reads `CCR1` and `CCR2` after each completed measurement.
The decoder uses only their ratio:

```text
r = CCR1 / CCR2
```

Absolute pulse duration is not checked except that neither capture may
be zero. The timer's paired PWM-input configuration means the captures
represent period and active interval: HIGH CONFIDENCE. The ratio-based
decoder itself is VERIFIED.

## Frame encoding

Three ratio classes are recognized:

| Symbol | Accepted ratio | Use |
| ---: | ---: | --- |
| 0 | `1.7...2.3` | preamble or payload bit 0 |
| 1 | `2.5500002...3.4499998` | payload bit 1 |
| 2 | `4.25...5.75` | frame delimiter |

A frame is:

```text
7 × symbol 0
1 × symbol 2
39 payload symbols, each symbol 0 or 1
```

Payload bits are accumulated least-significant bit first. The first
20 bits enter one word and the remaining 19 bits a second word. After
the 39th bit, the decoder compares masked bits `12...19` of the two
accumulators. On success it publishes:

```text
hkey = ((first_word >> 6) & 0xF0)
     | ((first_word & 0x7FFFF) >> 15)
```

Framing, thresholds, bit order, comparison, and extraction are
VERIFIED. The semantic assignment of individual resulting key codes
is not recovered in BASE because it forwards the code to Linux without
interpreting it.

## Release/timeout behavior

Every capture reloads a counter to 200. `TIM2_IRQHandler` services the
decoder approximately every `672.17 us`; when the counter expires it
clears the decoder state and publishes `hkey = 0`.

The nominal release timeout is therefore:

```text
200 * 672.17 us = 134.4 ms
```

Counter behavior is VERIFIED; the wall-clock value is HIGH CONFIDENCE
from the recovered timer clock.

## Independent implementation

An independent BASE implementation must:

- keep PD12 in AF2 and configure TIM4 channel 1 for paired PWM input;
- handle the capture interrupt and classify `CCR1/CCR2`;
- reproduce the preamble, delimiter, 39-bit payload, validation, and
  key extraction;
- publish zero after the 200-service-tick timeout;
- keep key-code meanings in the Linux/UI layer unless external
  measurements establish a stable hardware mapping.

Evidence:

- `analysis/hkey/hkey_decode_decompile.txt`;
- `analysis/hkey/hkey_frame_decode.csv`;
- `analysis/interrupts/irq_30_TIM4_08034988_disassembly.txt`.
