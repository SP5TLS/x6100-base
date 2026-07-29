# Memory map

## Firmware image

| Region | Start | End (exclusive) | Size | Confidence |
| --- | ---: | ---: | ---: | --- |
| Raw application image | `0x08020000` | `0x0807FB70` | `392048` bytes | VERIFIED |
| Vector table | `0x08020000` | `0x080201B0` | `432` bytes | VERIFIED |
| Recovered executable region | `0x080201B0` | `0x0803CEF0` | `118080` bytes | HIGH CONFIDENCE |
| Read-only data and runtime tables | `0x0803CEF0` | `0x0807C5C8` | `259800` bytes | HIGH CONFIDENCE combined region |
| Runtime arrays | `0x0807C5C8` | `0x0807C5D0` | `8` bytes | VERIFIED |
| `.data` load image | `0x0807C5D0` | `0x0807FB40` | `13680` bytes | VERIFIED |
| Unloaded image trailer | `0x0807FB40` | `0x0807FB70` | `48` bytes | VERIFIED extent |

The image extent is derived from the load address plus the exact binary
size.

The file contains no bytes for `0x08000000`–`0x0801FFFF`: VERIFIED.
That omitted 128 KiB range includes separately accessed persistent
blocks at `0x08004000` and `0x08008000`, and with HIGH CONFIDENCE also
contains the boot-resident IAP path that selects the application at
`0x08020000`. Its internal code/data subdivision and the IAP
post-transfer jump/reset mechanism cannot be recovered from this
application-only image.

The vector table contains 108 words: 16 Cortex-M core entries followed
by 92 STM32F427 external interrupt entries. Code begins immediately at
`0x080201B0`: VERIFIED.

`analysis/memory/function_ranges.csv` contains 456 recovered functions.
The last two are twelve-byte ARM floating-point helpers at
`0x0803CED8` and `0x0803CEE4`; their final instruction ends at
`0x0803CEF0`. Printable diagnostic text starts at `0x0803CEF8`.
The executable-region end is therefore HIGH CONFIDENCE.

The large following region contains strings, constants, DSP coefficient
tables, lookup tables, and compiler runtime metadata. Its combined
extent is HIGH CONFIDENCE, but it must not yet be described as a single
pure `.rodata` section.

The runtime-array words are:

| Address | Value | Meaning | Confidence |
| ---: | ---: | --- | --- |
| `0x0807C5C8` | `0x080201D5` | sole `.init_array` function | VERIFIED |
| `0x0807C5CC` | `0x080201B1` | following runtime/startup pointer | VERIFIED value, exact section role unresolved |

The startup routine copies exactly through `0x0807FB40`. The remaining
48 bytes are present in the file but are not copied to SRAM. They are
mostly zero, include the ASCII marker `ASCII`, and end with eight
`0xFF` bytes. Their producer-specific meaning is unknown.

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

## Heap and unused SRAM

`FUN_08034820` is a minimal `_sbrk`-style allocator backend:

- the initial program break is `0x2000EB00`;
- the current break is stored at `0x2000E9B0`;
- positive requests advance the break without alignment or a fixed
  upper bound;
- each request is rejected if its new break would pass the current
  stack pointer;
- rejection sets `errno` to 12 and returns `-1`.

Behavior and addresses: VERIFIED.

The initial distance from heap start to initial MSP is:

```text
0x20030000 - 0x2000EB00 = 0x21500 = 136448 bytes
```

This is shared dynamically by heap and descending stack. There is no
fixed guard region in this application: HIGH CONFIDENCE.

No statically addressed object was found between `0x2000EB00` and
`0x20030000`, apart from constants that only resemble SRAM addresses
when interpreted out of context. Static application state therefore
ends at the recovered `.bss` boundary: HIGH CONFIDENCE.

## CCMRAM

The complete `0x10000000`–`0x1000FFFF` CCMRAM range was searched.
The apparent hits at `0x10000000`, `0x10000040`, `0x10000100`,
`0x10000200`, `0x10000400`, and `0x10000800` are instruction
immediates used as RCC or DMA status masks, not memory operands.

No actual CCMRAM load, store, initialization copy, or clear was found:
HIGH CONFIDENCE that BASE 1.1.9 does not use CCMRAM.

This distinction matters for an independent implementation: CCMRAM is
CPU-only and cannot host DMA buffers, but remains available for
CPU-local DSP state if the new implementation deliberately chooses to
use it.

## Flash-resident calibration

The application accesses persistent data outside the raw application
image. The calibration block has copies at `0x08004000` and
`0x080E0000`; another configuration path reads at `0x08008000`.
These are not part of `.text`, `.rodata`, or the application `.data`
load image. Calibration framing is documented in `docs/protocol.md`.

## Unknowns

- exact internal subdivision of the combined read-only flash region;
- exact role of the second runtime-array word at `0x0807C5CC`;
- meaning of the final 48-byte image trailer;
- executable and persistent-data subdivision below `0x08020000`;
- exact boot-resident IAP post-transfer validation and application
  entry mechanism;
- retained or backup-memory use by the bootloader;
- worst-case stack and dynamic-allocation high-water marks.

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

## Reproducible function-range export

`ghidra_scripts/ExportFunctionRanges.java` exports each recovered
function as:

```text
entry,body_min,body_max_exclusive,body_bytes,name
```

Run it with:

```sh
./tools/run_headless_function_ranges.sh analysis/memory/function_ranges.csv
```

Body ranges may overlap when Ghidra models shared chunks or thunks.
They are evidence for recovered executable coverage, not a linker map.
