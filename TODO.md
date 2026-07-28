# TODO

## High priority

### Startup

-   [x] Recover complete Reset_Handler
-   [x] Identify startup_call_1 (`candidate_SystemInit`, HIGH CONFIDENCE)
-   [x] Identify startup_call_2 (`candidate_libc_init_array`, HIGH CONFIDENCE)
-   [x] Identify startup_call_3 (`candidate_main`, HIGH CONFIDENCE)
-   [ ] Confirm SystemInit()
-   [ ] Confirm \_\_libc_init_array()
-   [x] Locate `candidate_main` at `0x08034178` (HIGH CONFIDENCE)

### Interrupts

-   [ ] Recover complete vector table
-   [ ] Identify all IRQ handlers
-   [ ] Rename verified handlers

### Memory

-   [ ] Document .text
-   [ ] Document .rodata
-   [x] Document startup-derived `.data` range (HIGH CONFIDENCE)
-   [x] Document startup-derived `.bss` range (HIGH CONFIDENCE)
-   [ ] Document CCMRAM usage

## Hardware

-   [ ] RCC / clocks
-   [ ] GPIO
-   [ ] DMA
-   [ ] ADC
-   [ ] DAC
-   [ ] SPI
-   [ ] I2C
-   [ ] USART
-   [ ] Timers
-   [ ] Watchdog

## RTOS

-   [ ] Detect RTOS
-   [ ] Recover tasks
-   [ ] Recover queues
-   [ ] Recover timers

## Linux ↔ BASE protocol

-   [ ] Transport
-   [ ] Commands
-   [ ] Responses
-   [ ] Telemetry

## DSP

### RX

-   [ ] IQ buffers
-   [ ] DC removal
-   [ ] IQ correction
-   [ ] Frequency shift
-   [ ] FIR filters
-   [ ] AGC
-   [ ] Demodulation

### TX

-   [ ] Modulation
-   [ ] ALC
-   [ ] PA control
-   [ ] SWR protection

## Tooling

-   [ ] Export functions from Ghidra
-   [ ] Export call graph
-   [x] Export raw interrupt table
-   [ ] Export globals
-   [ ] Find peripheral register accesses
-   [ ] Generate Markdown documentation

## Documentation

-   [ ] startup.md
-   [ ] interrupts.md
-   [ ] memory_map.md
-   [ ] gpio.md
-   [ ] clocks.md
-   [ ] dma.md
-   [ ] protocol.md
-   [ ] rtos.md
-   [ ] rx_pipeline.md
-   [ ] tx_pipeline.md

## Milestone 1

Recover complete firmware startup.

Completion criteria:

-   Reset_Handler understood
-   SystemInit identified
-   Runtime identified
-   main() identified
-   Startup documented
-   Ghidra project updated
