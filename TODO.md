# TODO

## High priority

### Startup

-   [x] Recover complete Reset_Handler
-   [x] Identify startup_call_1 (`candidate_SystemInit`, HIGH CONFIDENCE)
-   [x] Identify startup_call_2 (`candidate_libc_init_array`, HIGH CONFIDENCE)
-   [x] Identify startup_call_3 (`candidate_main`, HIGH CONFIDENCE)
-   [x] Confirm SystemInit() (VERIFIED)
-   [x] Confirm \_\_libc_init_array() (VERIFIED)
-   [x] Locate `candidate_main` at `0x08034178` (HIGH CONFIDENCE)

### Interrupts

-   [x] Recover complete vector table
-   [x] Identify all active IRQ handlers
-   [ ] Rename verified handlers

### Memory

-   [ ] Document .text
-   [ ] Document .rodata
-   [x] Document startup-derived `.data` range (HIGH CONFIDENCE)
-   [x] Document startup-derived `.bss` range (HIGH CONFIDENCE)
-   [ ] Document CCMRAM usage

## Hardware

-   [x] RCC / clocks
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

-   [x] I2C3 control transport and framing
-   [x] Verify UART IQ/telemetry flow against BASE 1.1.9
-   [x] Identify UART baud-rate change to 1,500,000
-   [x] Verify ATU tune flag and Linux boot handshake
-   [x] Recover UART flow packet layout and metadata producers
-   [ ] Correlate remaining commands with BASE 1.1.9 consumers
-   [x] Recover I2C read responses and calibration-window framing
-   [ ] Recover telemetry physical-unit calibration and calibration-field semantics

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
-   [x] Export direct function callers
-   [x] Export raw interrupt table
-   [ ] Export globals
-   [ ] Find peripheral register accesses
-   [ ] Generate Markdown documentation

## Documentation

-   [x] startup.md
-   [x] interrupts.md
-   [x] memory_map.md
-   [ ] gpio.md
-   [x] clocks.md
-   [ ] dma.md
-   [x] protocol.md (transport and historical 1.1.6 register map)
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
