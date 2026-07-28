# REVERSE_ENGINEERING_GUIDE.md

# X6100 BASE Reverse Engineering Guide

This document defines the recommended workflow for analyzing the X6100
BASE firmware.

The objective is to produce a complete behavioral specification and,
eventually, an independent firmware implementation.

------------------------------------------------------------------------

# General workflow

For every subsystem:

1.  Identify entry points.
2.  Follow the call graph.
3.  Identify data structures.
4.  Identify hardware interaction.
5.  Document findings.
6.  Estimate confidence.
7.  Verify hypotheses.
8.  Rename symbols only after verification.

Never skip documentation.

------------------------------------------------------------------------

# Phase 1 -- Startup

Goal:

Recover the complete execution path from reset to the application.

Tasks:

-   Verify vector table.
-   Analyze Reset_Handler.
-   Recover .data initialization.
-   Recover .bss initialization.
-   Identify SystemInit().
-   Identify C runtime.
-   Locate main().
-   Determine whether RTOS is started.

Deliverables:

-   docs/startup.md
-   docs/memory_map.md

Completion criteria:

-   Startup chain fully understood.
-   All startup functions renamed.

------------------------------------------------------------------------

# Phase 2 -- Interrupts

Goal:

Recover every interrupt source.

Tasks:

-   Name IRQ handlers.
-   Locate Default_Handler.
-   Map IRQ → peripheral.
-   Identify DMA callbacks.

Deliverables:

-   docs/interrupts.md

Completion criteria:

-   All active IRQs identified.

------------------------------------------------------------------------

# Phase 3 -- Hardware initialization

Recover configuration of:

-   RCC
-   GPIO
-   DMA
-   ADC
-   DAC
-   SPI
-   I2C
-   USART
-   TIM
-   Watchdog

Deliverables:

-   docs/gpio.md
-   docs/clocks.md
-   docs/dma.md
-   docs/peripherals.md

------------------------------------------------------------------------

# Phase 4 -- Scheduler

Determine:

-   bare-metal or RTOS
-   task creation
-   queues
-   semaphores
-   timers

Deliverable:

-   docs/rtos.md

------------------------------------------------------------------------

# Phase 5 -- Linux ↔ BASE protocol

Recover:

-   transport
-   framing
-   command IDs
-   telemetry
-   error handling

Deliverable:

-   docs/protocol.md

------------------------------------------------------------------------

# Phase 6 -- DSP RX

Recover processing pipeline:

DMA → IQ buffers → DC removal → IQ correction → Frequency shift →
Filters → AGC → Demodulator → Audio output

Deliverable:

-   docs/rx_pipeline.md

------------------------------------------------------------------------

# Phase 7 -- DSP TX

Recover:

-   modulation
-   compressor
-   ALC
-   PA control
-   SWR protection
-   telemetry

Deliverable:

-   docs/tx_pipeline.md

------------------------------------------------------------------------

# Phase 8 -- Hardware control

Recover:

-   RF switching
-   synthesizers
-   band filters
-   ATU
-   PA
-   sensors
-   battery

Deliverable:

-   docs/hardware.md

------------------------------------------------------------------------

# Automation

Whenever practical, create Ghidra scripts instead of performing
repetitive work manually.

Preferred scripts:

-   export_functions.py
-   export_vectors.py
-   export_globals.py
-   export_strings.py
-   export_callgraph.py
-   export_peripherals.py
-   rename_from_csv.py

------------------------------------------------------------------------

# Documentation template

Each recovered function should include:

-   Address
-   Current name
-   Proposed name
-   Purpose
-   Inputs
-   Outputs
-   Global state
-   Hardware interaction
-   Callers
-   Callees
-   Confidence level
-   Verification method

------------------------------------------------------------------------

# Evidence levels

VERIFIED

Confirmed by code and behavior.

HIGH CONFIDENCE

Supported by multiple observations.

MEDIUM CONFIDENCE

Likely but not fully verified.

HYPOTHESIS

Needs confirmation.

------------------------------------------------------------------------

# Definition of done

A subsystem is complete only if:

-   implementation understood
-   documentation updated
-   Ghidra names updated
-   TODO updated
-   evidence recorded
-   remaining unknowns listed

Only after most subsystems reach this state should work begin on the
standalone firmware.
