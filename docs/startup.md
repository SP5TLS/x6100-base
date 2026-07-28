# Firmware startup

## Scope

This document records the reset path of
`X6100_BBFW_V1.1.9_251127001.bin`.

Firmware SHA-256:

`3fa11293e06951c21c9cfda04ea08adad85eaadda26b77a8e8bbcca8820c53c4`

The evidence was exported with Ghidra 12.1.2 using
`ghidra_scripts/ExportStartupEvidence.java`. Generated evidence is under
`analysis/startup/`.

## Vector entry

| Property | Value | Confidence |
| --- | --- | --- |
| Vector-table address | `0x08020000` | VERIFIED |
| Initial MSP | `0x20030000` | VERIFIED |
| Reset vector value | `0x08034A19` | VERIFIED |
| Reset code address | `0x08034A18` | VERIFIED |

The low bit of the vector value is the Cortex-M Thumb-state bit. It is
not part of the aligned code address.

## Reset function

Current Ghidra name: `FUN_08034a18`

Proposed name: `candidate_Reset_Handler`

Confidence: HIGH CONFIDENCE

The function performs these operations:

1. Loads `0x20030000` into `SP`.
2. Copies 32-bit words from `0x0807C5D0` to
   `[0x20000000, 0x20003570)`.
3. Clears 32-bit words in `[0x20003570, 0x2000EB00)`.
4. Calls `FUN_0803485c`.
5. Calls `FUN_08037ed0`.
6. Calls `FUN_08034178`.
7. Enters an infinite loop if the third call returns.

The copy, clear, call sequence, and final loop are VERIFIED by direct
disassembly. The interpretation as `.data` and `.bss` initialization is
HIGH CONFIDENCE pending correlation with a recovered linker layout.

## First startup call

Address: `0x0803485C`

Current name: `FUN_0803485c`

Proposed name: `candidate_SystemInit`

Final name justified by evidence: `SystemInit`

Confidence: VERIFIED

Observed behavior:

- enables CP10 and CP11 access through `SCB->CPACR` at `0xE000ED88`;
- writes RCC control/configuration registers in the
  `0x40023800` block;
- writes `0x08020000` to `SCB->VTOR` at `0xE000ED08`;
- returns to the reset function.

The register sequence and reset constants match the STM32F4 CMSIS
`SystemInit` implementation distributed in the official
[STM32CubeF4 package](https://github.com/STMicroelectronics/STM32CubeF4).
The function's position as the first reset-time call independently
supports the identification. The final name is therefore VERIFIED,
although it has not yet been applied to the persistent Ghidra project.

## Second startup call

Address: `0x08037ED0`

Current name: `FUN_08037ed0`

Proposed name: `candidate_libc_init_array`

Final name justified by evidence: `__libc_init_array`

Confidence: VERIFIED

Observed behavior:

- iterates over a first range of function pointers;
- calls `FUN_0803ced8`;
- iterates over a second range of function pointers;
- returns.

The four boundaries loaded by this function are:

| Linker-provided range | Start | End | Entries |
| --- | ---: | ---: | ---: |
| preinit array | `0x0807C5C8` | `0x0807C5C8` | 0 |
| init array | `0x0807C5C8` | `0x0807C5CC` | 1 |

The sole init-array entry is the Thumb address `0x080201D5`, whose code
address is `0x080201D4`.

The control flow is an exact match for newlib's `__libc_init_array`:
iterate the preinit array, call `_init`, then iterate the init array.
This comparison is based on the
[newlib `init.c` implementation](https://sourceware.org/pipermail/newlib/2022/018886.html)
and the recovered array boundaries. The final name is therefore
VERIFIED, although it has not yet been applied to the persistent Ghidra
project.

`FUN_0803ced8` contains only an ABI-compatible prologue, `nop`, and
epilogue. Its role as the `_init` stub is HIGH CONFIDENCE.

The init-array function at `0x080201D4` loads a null weak-function
literal and returns without invoking it. Its identity as a generated
frame-registration helper is MEDIUM CONFIDENCE; its effective no-op
behavior in this image is VERIFIED.

## Third startup call

Address: `0x08034178`

Current name: `FUN_08034178`

Proposed name: `candidate_main`

Confidence: HIGH CONFIDENCE

The function performs extensive application and peripheral
initialization, references the firmware version and build date strings,
performs PA calibration checks, and does not normally return. Its
position after the runtime initializer strongly supports the `main`
hypothesis. No final rename has been performed.

## Remaining work

- Recover the complete call graph rooted at `FUN_08034178`.
- Correlate RAM ranges with linker sections and global references.
- Apply candidate or final names in the persistent Ghidra project only
  after the evidence review.
