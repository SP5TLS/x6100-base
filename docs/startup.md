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

Confidence: HIGH CONFIDENCE

Observed behavior:

- enables CP10 and CP11 access through `SCB->CPACR` at `0xE000ED88`;
- writes RCC control/configuration registers in the
  `0x40023800` block;
- writes `0x08020000` to `SCB->VTOR` at `0xE000ED08`;
- returns to the reset function.

This is structurally consistent with a CMSIS `SystemInit` function.
The final name has not been assigned because source or symbol-level
identity has not yet been established.

## Second startup call

Address: `0x08037ED0`

Current name: `FUN_08037ed0`

Proposed name: `candidate_libc_init_array`

Confidence: HIGH CONFIDENCE

Observed behavior:

- iterates over a first range of function pointers;
- calls `FUN_0803ced8`;
- iterates over a second range of function pointers;
- returns.

This matches the characteristic pre-initializer, runtime initializer,
and initializer-array sequence of `__libc_init_array`. The array
boundaries and the identity of `FUN_0803ced8` still need to be recorded
before assigning a final name.

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

- Identify the two initializer-array ranges used by `FUN_08037ed0`.
- Identify `FUN_0803ced8`.
- Recover the complete call graph rooted at `FUN_08034178`.
- Correlate RAM ranges with linker sections and global references.
- Apply candidate or final names in the persistent Ghidra project only
  after the evidence review.
