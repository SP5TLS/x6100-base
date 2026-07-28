# Memory map

## Firmware image

| Region | Start | End (exclusive) | Size | Confidence |
| --- | ---: | ---: | ---: | --- |
| Raw application image | `0x08020000` | `0x0807FB70` | `392048` bytes | VERIFIED |
| Vector table | `0x08020000` | not yet bounded | unknown | VERIFIED start |

The image extent is derived from the load address plus the exact binary
size. It does not imply that every byte belongs to executable `.text`.

## Startup-derived RAM regions

| Proposed section | Start | End (exclusive) | Size | Load address | Confidence |
| --- | ---: | ---: | ---: | ---: | --- |
| `.data` | `0x20000000` | `0x20003570` | `13680` bytes | `0x0807C5D0` | HIGH CONFIDENCE |
| `.bss` | `0x20003570` | `0x2000EB00` | `46480` bytes | — | HIGH CONFIDENCE |

The address ranges and startup operations are VERIFIED from
`FUN_08034a18`. The section names remain HIGH CONFIDENCE until they are
correlated with the rest of the image and a linker layout.

## Stack

| Property | Value | Confidence |
| --- | --- | --- |
| Initial MSP | `0x20030000` | VERIFIED |

The vector entry and the explicit load into `SP` in the reset function
independently agree.

## Unknowns

- boundary between `.text`, `.rodata`, and Flash initialization data;
- whether all SRAM below the initial MSP is used;
- CCMRAM allocation and initialization;
- heap and runtime stack boundaries;
- any retained or backup-memory regions.

## Headless analysis model

`ghidra_scripts/MapSTM32F427Memory.java` adds uninitialized analysis
blocks for:

| Block | Start | End (exclusive) | Permissions |
| --- | ---: | ---: | --- |
| CCMRAM | `0x10000000` | `0x10010000` | read/write |
| SRAM | `0x20000000` | `0x20030000` | read/write |

These blocks contain no invented initialization data. They allow Ghidra
to create references to addresses used by the firmware while the actual
initial values continue to come only from the recovered `.data` copy.
