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
-   [x] GPIO modes, peripheral pins, shift chains, and shutdown sequence
-   [x] DMA
-   [x] ADC topology, DMA acquisition, and ADC2 filtering
-   [x] DAC initialization and frequency-dependent DAC2 control
-   [x] SPI / full-duplex I2S
-   [x] I2C1/I2C2 masters, codec, variants, and I2C3 slave
-   [x] USART
-   [x] Timers
-   [ ] Watchdog

## RTOS

-   [x] Identify bare-metal superloop; no RTOS scheduler (HIGH CONFIDENCE)
-   [x] Confirm no RTOS task objects are present
-   [x] Confirm no RTOS queues/semaphores are present
-   [x] Confirm timers are hardware-driven rather than RTOS timers

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
-   [x] Export call graph
-   [x] Export direct function callers
-   [x] Export raw interrupt table
-   [ ] Export globals
-   [ ] Find peripheral register accesses
-   [ ] Generate Markdown documentation

## Documentation

-   [x] startup.md
-   [x] interrupts.md
-   [x] memory_map.md
-   [x] gpio.md
-   [x] clocks.md
-   [x] timers.md
-   [x] usart.md
-   [x] dma.md
-   [x] spi_i2s.md
-   [x] dsp_primitives.md
-   [x] analog.md
-   [x] i2c.md
-   [ ] dma.md
-   [x] protocol.md (transport and historical 1.1.6 register map)
-   [x] rtos.md
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
