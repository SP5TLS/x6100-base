# Execution architecture

## Conclusion

BASE 1.1.9 uses a bare-metal foreground loop with interrupt-driven
peripheral and DSP processing.

Bare-metal superloop architecture: VERIFIED.

Absence of a linked RTOS scheduler: HIGH CONFIDENCE.

## Foreground control flow

After initialization and PA calibration, `candidate_main` repeatedly
executes:

```text
while (FUN_0802af0c(state, control_window) == 0) {
    FUN_080349e4(1);
}
```

`FUN_0802af0c`:

- polls and applies the Linux I2C control register file;
- updates RF and audio hardware settings;
- runs battery-management service;
- starts ATU operations;
- handles calibration save/reload requests;
- returns a termination condition to `candidate_main`.

This function is the foreground service step, not an RTOS task:
VERIFIED.

When it returns nonzero, `candidate_main` disables peripherals, stores
configuration, sequences GPIO shutdown signals, and eventually enters a
non-returning wait path.

## Interrupt-driven work

Concurrent activity is supplied directly by six external interrupt
handlers:

| Handler | Role |
| --- | --- |
| DMA1 Stream 3 | synchronized I2S buffer completion and primary DSP |
| TIM2 | UART-flow state machine and fast service/debounce |
| TIM3 | input debounce and measurement telemetry |
| TIM4 | hardware-key input capture |
| I2C3 event | Linux control/read protocol |
| I2C3 error | I2C fault recovery |

There is no intermediate scheduler dispatch in these handlers.

## Core exception evidence

The vector table does not provide RTOS exception handlers:

| Core exception | Vector state |
| --- | --- |
| SVC | default handler |
| PendSV | default handler |
| SysTick | default handler |

SVC, PendSV, and SysTick are the normal scheduling hooks for common
Cortex-M RTOS ports. Their absence is strong evidence against an RTOS
kernel in this image.

Vector contents: VERIFIED. Interpretation as evidence against an RTOS:
HIGH CONFIDENCE.

## Delay implementation

`FUN_080349e4` is a polling delay:

1. programs SysTick LOAD and VAL;
2. enables the counter without its interrupt;
3. polls the SysTick status/count flag;
4. repeats for the requested count.

It does not block on or yield to a scheduler. Polling behavior:
VERIFIED.

The function is a candidate millisecond-style delay, but its exact time
unit should not receive a final name until the SysTick clock-source
selection and the unusual 250-MHz system clock are reconciled.

## Negative evidence

The firmware and exported call graph contain no recovered:

- task creation or context-switch path;
- scheduler start function;
- queue or semaphore API;
- per-task stacks;
- RTOS-identifying strings;
- SVC/PendSV context handlers.

Negative evidence alone is not proof, so the global “no RTOS linked”
conclusion remains HIGH CONFIDENCE. The directly observed superloop
execution model is VERIFIED.

## Independent-implementation guidance

Compatibility does not require reproducing the OEM foreground/ISR
structure. An independent firmware may use an RTOS, provided it
preserves protocol timing, I2S buffer deadlines, and hardware state
ordering.

## Reproducible evidence

- `analysis/startup/startup_call_3_08034178_decompile.c`;
- `analysis/startup/vectors.csv`;
- `analysis/callgraph.csv`;
- `analysis/rtos/FUN_080349e4_080349e4_disassembly.txt` (locally
  reproducible and intentionally ignored).
