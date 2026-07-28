# AGENTS.md

# Instructions for AI agents working on this repository

## Mission

This repository is a reverse engineering project, not a decompilation
project.

The objective is to understand the X6100 BASE firmware well enough to
build an independent implementation.

The primary deliverable is documentation and verified knowledge.

------------------------------------------------------------------------

# General principles

1.  Never invent information.
2.  Never rename symbols without evidence.
3.  Prefer automation over manual work.
4.  Every completed task must update documentation.
5.  Preserve reproducibility.

------------------------------------------------------------------------

# Function naming

Use three stages:

    FUN_08024510

↓

    candidate_uart_irq

↓

    USART1_IRQHandler

Final names require convincing evidence.

------------------------------------------------------------------------

# Confidence levels

Every important conclusion should include one of:

-   VERIFIED
-   HIGH CONFIDENCE
-   MEDIUM CONFIDENCE
-   HYPOTHESIS

Never present hypotheses as facts.

------------------------------------------------------------------------

# Preferred workflow

1.  Automate repetitive work.
2.  Export data from Ghidra.
3.  Analyze call graphs.
4.  Document discoveries.
5.  Only then rename symbols.

------------------------------------------------------------------------

# Preferred tooling

-   Ghidra
-   Headless Ghidra scripts
-   Python
-   Git
-   Markdown

------------------------------------------------------------------------

# Documentation rules

Whenever new information is confirmed:

-   update the appropriate document in docs/
-   update TODO.md
-   commit both code and documentation

------------------------------------------------------------------------

# Coding rules

Do NOT copy decompiled OEM code into the new firmware.

Instead:

-   describe behavior
-   identify algorithms
-   implement an independent equivalent

------------------------------------------------------------------------

# Ghidra scripts

Prefer writing reusable scripts.

Useful scripts include:

-   export_functions
-   export_vectors
-   export_globals
-   export_strings
-   export_callgraph
-   export_peripherals
-   rename_from_csv

------------------------------------------------------------------------

# Commit style

Small logical commits.

Examples:

    startup: identify Reset_Handler

    docs: document vector table

    ghidra: rename verified DMA handlers

------------------------------------------------------------------------

# Success criteria

The project succeeds when a developer unfamiliar with the original
firmware can understand the complete architecture from the documentation
alone and implement a compatible firmware without consulting the OEM
binary.
