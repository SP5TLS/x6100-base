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
-   [x] Identify I2C2 address `0x10` as CS4272 and decode its startup
-   [x] Recover complete startup-only control contract for `0x4A`/`0x4C`
-   [ ] Trace board-level electrical functions of `0x4A` and `0x4C`
-   [x] Identify TLV320AIC3204 as 32-bit I2S BCLK/WCLK master
-   [x] Recover PE15 TLV320AIC3204 reset lifecycle (HIGH CONFIDENCE role)
-   [x] Export complete ordered TLV320AIC3204 startup contract and
    decode its power, routing, mute, and gain phases
-   [x] Map TLV320AIC3204 control helpers to analog routing, gain,
    MICBIAS, and ADC/DAC mute semantics
-   [x] Correlate codec IN1L/IN2L/IN2R and gain controls with built-in
    microphone, hand microphone, and line input (HIGH CONFIDENCE)
-   [x] Trace speaker/phone mode through PF15 to the DMA audio-gain
    selector (HIGH CONFIDENCE jack-detect role)
-   [x] Assign IN3R/HPL to the MAIN/Linux-board audio path and
    IN2R/LOL/LOR to the C-Media/USB-card path (HIGH CONFIDENCE)
-   [x] Recover SPI2 audio and SPI3 I/Q signal roles from DMA processing
-   [x] Verify CS4272 as zero-IF I/Q converter and assign SPI3/I2S3
-   [x] Assign `0x4C` fallback to the same I/Q interface (HIGH CONFIDENCE)
-   [x] Audit PG8 around converter startup; it remains an input and is
    not a verified reset line
-   [x] USART
-   [x] Timers
-   [x] Confirm no application IWDG/WWDG use and document software reset
-   [x] Recover firmware-visible charger control, I2C telemetry,
    hysteresis, and ordered PF12/PCA9535 actuation; exclude PF13
-   [x] Recover early MAX17205 capacity/voltage reads and ordered
    reset/hibernate/pack-configuration recovery writes
-   [x] Map the runtime `0x36`/512-byte MAX17205 snapshot, its four
    consumed registers, failure behavior, cadence, and Linux fields
-   [ ] Identify the physical PE13 and PF11 nets and reconcile early
    PD3 charge-loop reuse with its normal `+5R` role

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
    - [x] Recover register 15 RF-gain serial output, DSP gain split,
      and TX-power target scaling
    - [x] Recover every consumed register 12 operation bit and the
      ATU-tune request/clear handshake
    - [x] Recover register 13 active-VFO selection, calibration-band
      table effects, and required index bound
    - [x] Audit all register 21 fields, including persistent charger
      control, variant output behavior, and squelch threshold
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
-   [x] Recover TX-request arbitration and hardware-PTT GPIO
-   [ ] Map PB9/PA11/PD0 to physical TX controls
-   [x] RX/TX block-boundary handoff and first digital input gain
-   [x] Recover TX ALC topology, limits, and final complex scaling
-   [x] Correlate ADC1 directional-detector inputs with TX-power/VSWR telemetry
-   [ ] Recover absolute RF-power units
-   [x] Identify ADC1 channel 2 / PA2 as the ACC ALC input
-   [x] Recover PA bias-device protocol and ordered RX/TX hardware controls
-   [x] Resolve hardware-variant PA callback to PCA9535 bit 0 / PD14
-   [x] Export the complete PCA9535/direct-GPIO variant callback table
-   [x] Audit the PA enable GPIO tuple across startup, RX/TX, calibration, and shutdown
-   [x] Separate PA calibration-enable subset and recover PE12 CW output
-   [x] Correlate PD3/PD4 with service-manual +5R/+5T rails
-   [x] Recover ACC TRX, BAND_V, and ALC_V MCU mappings
-   [ ] Identify PA-control IC and resolve individual enable/routing GPIO nets
-   [x] Trace VSWR measurement into the antenna-tuner search
-   [x] Recover ATU state packing, relay-bit permutation, and search phases
-   [x] Recover ATU result publication and register-17 reapplication path
-   [x] Recover physical ATU output through SPI6 and PG12 latch
-   [ ] Optionally assign ATU banks to L/C and recover component values
    - Non-blocking for implementation: OEM tuning treats both banks as
      opaque controls and minimizes measured VSWR.
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
