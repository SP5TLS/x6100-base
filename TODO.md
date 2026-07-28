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

-   [x] Document recovered executable region
-   [x] Bound combined read-only data/runtime-table region
-   [x] Document startup-derived `.data` range (HIGH CONFIDENCE)
-   [x] Document startup-derived `.bss` range (HIGH CONFIDENCE)
-   [x] Confirm no application CCMRAM accesses (HIGH CONFIDENCE)

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
-   [x] Confirm no application IWDG/WWDG use and document software reset

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
-   [x] Trace `vfoa_freq`/`vfob_freq` through LO synthesizer programming
-   [x] Resolve the BASE 1.1.9 frequency-path selector (constant 1)
-   [x] Recover output-4 harmonic-avoidance algorithm (`PSYNC`, HIGH CONFIDENCE)
-   [x] Recover RF-band indices and frequency-dependent DAC2 table
-   [x] Map primary RF index to PCA9535 and direct-GPIO backends
-   [x] Map secondary RF index to SPI6 output-image bits
-   [x] Recover exact secondary RF-index frequency boundaries
-   [x] Recover frequency-change DSP reset and four-block countdown
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

-   [x] Recover mode-dependent modulation topology
-   [x] Export TX rate-conversion and quadrature-filter coefficients
-   [x] Recover runtime TX biquad selection and exact coefficients
-   [x] Verify combined TX audio-filter frequency response independently
-   [x] Correlate BASE mode numbers with historical Linux-facing names
-   [x] Recover CW RF/monitor envelope timing and tone/level fields
-   [x] Recover CW software key-state generator and register-33 fields
-   [x] Recover QSK hold units and audit key-ratio application
-   [x] Map CW input flags to STM32 GPIO pins
-   [x] Map PF13/PF14 to KEY tip/ring contacts
-   [ ] Map PA11/PD0 to remaining PTT sources
-   [ ] Compare disconnected key-ratio control with other BASE versions
-   [x] RX/TX block-boundary handoff and first digital input gain
-   [x] Recover TX ALC topology, limits, and final complex scaling
-   [x] Correlate ADC1 directional-detector inputs with TX-power/VSWR telemetry
-   [ ] Recover absolute RF-power units and identify ADC1 channel 2
-   [ ] PA control
-   [x] Trace VSWR measurement into the antenna-tuner search
-   [x] Recover ATU state packing, relay-bit permutation, and search phases
-   [x] Recover ATU result publication and register-17 reapplication path
-   [ ] Assign ATU banks to L/C and recover component values
-   [ ] Locate Linux-side per-frequency ATU persistence
-   [x] Audit direct VSWR consumers for a firmware hard-trip path
-   [ ] Identify any hardware or external-controller SWR protection

## Tooling

-   [x] Export complete function ranges from Ghidra
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
-   [x] frequency_control.md
-   [x] rf_switching.md
-   [x] watchdog.md
-   [ ] dma.md
-   [x] protocol.md (transport and historical 1.1.6 register map)
-   [x] rtos.md
-   [ ] rx_pipeline.md
-   [x] tx_pipeline.md (initial mode handoff and input-gain stages)

## Milestone 1

Recover complete firmware startup.

Completion criteria:

-   Reset_Handler understood
-   SystemInit identified
-   Runtime identified
-   main() identified
-   Startup documented
-   Ghidra project updated
