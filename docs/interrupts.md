# Interrupt vector table

## Scope and evidence

The raw table was read from `0x08020000` by
`ghidra_scripts/ExportInterruptEvidence.java`. The complete export is in
`analysis/startup/vectors.csv`; the non-default external entries are in
`analysis/interrupts/active_irqs.csv`.

The external IRQ numbers and standard names are correlated against the
official STMicroelectronics
[`stm32f427xx.h`](https://github.com/STMicroelectronics/cmsis-device-f4/blob/master/Include/stm32f427xx.h)
CMSIS device header and RM0090.

Firmware SHA-256:

`3fa11293e06951c21c9cfda04ea08adad85eaadda26b77a8e8bbcca8820c53c4`

## Default handler

Vector value: `0x08034A69`

Code address: `0x08034A68`

Current Ghidra name: `FUN_08034a68`

Proposed name: `Default_Handler`

Confidence: VERIFIED

All external vector entries other than the six listed below point to
this address. The function is a non-returning branch to itself.

## Active external interrupts

| IRQ | Standard vector name | Handler | Proposed final name | Confidence |
| ---: | --- | ---: | --- | --- |
| 14 | DMA1 Stream 3 | `0x08024528` | `DMA1_Stream3_IRQHandler` | VERIFIED |
| 28 | TIM2 | `0x08034950` | `TIM2_IRQHandler` | VERIFIED |
| 29 | TIM3 | `0x0802DB2C` | `TIM3_IRQHandler` | VERIFIED |
| 30 | TIM4 | `0x08034988` | `TIM4_IRQHandler` | VERIFIED |
| 72 | I2C3 event | `0x08033990` | `I2C3_EV_IRQHandler` | VERIFIED |
| 73 | I2C3 error | `0x08033B88` | `I2C3_ER_IRQHandler` | VERIFIED |

The final handler names are justified by their exact vector positions,
not inferred solely from handler behavior. They have not yet been
applied to the persistent Ghidra project.

## DMA1 Stream 3

Current name: `FUN_08024528`

The handler:

- tests and clears a DMA1 Stream 3 interrupt condition through the
  stream register block at `0x40026058`;
- checks the current-target state of DMA1 Stream 3 and another DMA
  stream at `0x40026070`;
- selects pairs of ping-pong buffer pointers;
- executes a large floating-point signal-processing path;
- updates extensive DSP state in SRAM.

Peripheral identity and interrupt dispatch: VERIFIED.

Use as a DMA-driven DSP processing engine: HIGH CONFIDENCE.

The exact RX/TX sub-pipelines and buffer formats remain unresolved. No
behavioral name beyond the standard IRQ handler name is assigned.

## TIM2

Current name: `FUN_08034950`

The handler tests and clears the TIM2 update interrupt at
`0x40000000`, then invokes four processing routines. Its final path
samples GPIOG input bit 15 through `GPIOG_IDR` at `0x40021810` and
maintains a nine-tick debounce state.

One of the called routines, `FUN_080337fc`, builds and schedules the
4136-byte USART6 IQ/telemetry packet through DMA2 Stream 6.

Peripheral identity and update-event handling: VERIFIED.

GPIOG pin 15 debounce behavior: HIGH CONFIDENCE.

Periodic UART flow service role: VERIFIED.

The physical signal connected to GPIOG pin 15 is unknown.

## TIM3

Current name: `FUN_0802db2c`

The handler tests and clears the TIM3 update interrupt at
`0x40000400`. It debounces multiple GPIO-backed inputs, updates a shared
bitfield, samples three converted telemetry values, and maintains an
additional GPIO-based counter.

Peripheral identity and update-event handling: VERIFIED.

Periodic input/telemetry service role: HIGH CONFIDENCE.

The GPIO-to-front-panel or RF-control signal mapping remains unknown.

## TIM4

Current name: `FUN_08034988`

The handler tests and clears TIM4 interrupt source `0x0002`, reads
`TIM4_CCR1` and `TIM4_CCR2` at offsets `0x34` and `0x38`, and passes
both capture values to `FUN_08030334` with state at `0x2000C670`.

Peripheral identity and capture-register reads: VERIFIED.

Input-capture measurement role: HIGH CONFIDENCE.

The external signal being measured is unknown.

## I2C3 event

Current name: `FUN_08033990`

The initialized pointer at `0x20001464` is `0x40005C00`, the I2C3
register base. The event handler reads I2C status registers, implements
a multi-byte address state machine, and transfers data between the I2C
data register and several RAM-backed regions or circular buffers.

`FUN_08033d64` initializes the same peripheral for 400 kHz operation
with 7-bit own address `0x72`.

Peripheral identity and event-driven slave state machine: VERIFIED.

Interpretation as the Linux control register service: VERIFIED by
correlation with X6100Control and the exact 224-byte register-window
size.

The address map includes special ranges around `0xF000`; their
destinations are documented in `docs/protocol.md`, but their external
meaning is not yet established.

## I2C3 error

Current name: `FUN_08033b88`

The handler reads I2C3 status, tests a sequence of error conditions,
clears the first active condition, sets the peripheral ACK bit, and
resets saved status state.

Peripheral identity and error-clearing role: VERIFIED.

The exact mapping of helper masks to I2C error flags still needs to be
recorded.

## Remaining work

- Apply the six VERIFIED names and `Default_Handler` to the persistent
  Ghidra project.
- Recover direct call graphs for the DMA and timer handlers.
- Identify DMA1 Stream 3 and companion-stream buffer layouts.
- Map TIM2/TIM3 GPIO inputs to schematic signals.
- Document the I2C3 address-space protocol and buffer ownership.
