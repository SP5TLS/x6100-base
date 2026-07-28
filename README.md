# X6100 BASE Reverse Engineering

## Project goal

The goal of this project is **not** to patch the original Xiegu
firmware.

The goal is to fully understand the architecture and behavior of the
STM32 BASE firmware of the Xiegu X6100 well enough to implement an
independent, open-source replacement.

The original firmware is used only as a reference for observable
behavior and hardware interaction.

------------------------------------------------------------------------

# Current status

## Hardware

Device: **Xiegu X6100**

BASE MCU: **STM32F427**

## Firmware

Current firmware version:

`X6100_BBFW_V1.1.9_251127001`

Original encrypted firmware (.xgf) has been successfully decrypted.

Current working image:

`X6100_BBFW_V1.1.9_251127001.bin`

## Ghidra

Version:

`12.1.2`

Architecture:

-   ARM Cortex-M4
-   Thumb-2
-   Little Endian

Firmware base address:

`0x08020000`

Confirmed by:

-   Linker script (`FLASH ORIGIN = 0x08020000`)
-   Vector table:
    -   Initial MSP = `0x20030000`
    -   Reset_Handler = `0x08034A19`

# Confirmed information

## Memory layout

-   Flash application base: `0x08020000`
-   Initial stack: `0x20030000`
-   Reset_Handler: `0x08034A18`
-   Default_Handler: `0x08034A68`

## Startup

Current understanding:

    Reset_Handler
        ↓
    copy .data
        ↓
    clear .bss
        ↓
    candidate_SystemInit (HIGH CONFIDENCE)
        ↓
    __libc_init_array (VERIFIED)
        ↓
    candidate_main (HIGH CONFIDENCE)
        ↓
    application

Only `__libc_init_array()` has sufficient evidence for a final name.
The other two functions retain candidate names until verified.

# Project philosophy

-   Never rename functions based on guesses.
-   Every conclusion must have evidence.
-   Documentation comes before implementation.
-   The objective is a complete behavioral specification, not a
    line-by-line decompilation.

# Suggested repository layout

    analysis/
    docs/
    ghidra/
    tools/
    firmware/
    firmware_new/

# Reverse engineering roadmap

1.  Startup
2.  Interrupts
3.  Hardware initialization
4.  RTOS / scheduler
5.  Linux ↔ BASE protocol
6.  RX DSP pipeline
7.  TX DSP pipeline
8.  Independent firmware implementation

# Long-term objective

Produce a maintainable, fully documented and independently implemented
replacement firmware for the Xiegu X6100 BASE controller.
