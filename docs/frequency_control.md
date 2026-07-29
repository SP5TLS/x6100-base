# VFO frequency and LO synthesizer control

## Scope

This document follows the BASE 1.1.9 control registers historically
called `vfoa_freq` and `vfob_freq` by X6100Control through to the
physical clock-generator writes. Historical Linux names are retained
only as protocol labels; no OEM symbol has been renamed.

Firmware SHA-256:

`3fa11293e06951c21c9cfda04ea08adad85eaadda26b77a8e8bbcca8820c53c4`

## Control-register inputs

The I2C3 slave control window begins at `0x2000C4C8`. Its two VFO
records have the same six-word layout:

| VFO | Frequency index | Byte offset | Mode index | Frequency field in selected record |
| --- | ---: | ---: | ---: | ---: |
| A | 1 | `0x0004` | 4 | `+0x04` |
| B | 7 | `0x001C` | 10 | `+0x04` |

`FUN_0802af0c` selects one of the records and reads the 32-bit frequency
at record offset `+0x04`. Thus the BASE 1.1.9 consumers confirm the
historical `vfoa_freq` and `vfob_freq` locations: VERIFIED.

The value is used arithmetically as hertz. The debug message
`Actual_LO_Freq...`, fixed additions of 70,000,000 and 140,000,000,
and direct use as the clock-generator frequency argument establish the
unit: HIGH CONFIDENCE.

## Frequency calculation

Let `Fvfo` be the selected VFO frequency and `Foffset` the active
receive/transmit offset. The normal calculation begins with:

`Ftuned = Fvfo + Foffset`

The offset source depends on receive/transmit state. The historical
control labels place RIT and XIT at indices 42 and 43; the consumer
reads corresponding fields at offsets `0x78` and `0x7C` in its internal
control cache. Their exact cache-to-wire transformation remains to be
documented, so identifying the two internal values specifically as RIT
and XIT is HIGH CONFIDENCE rather than VERIFIED.

For receive-side modes encoded as 4 through 7, the firmware additionally
applies:

| Mode value | Adjustment |
| ---: | --- |
| 4 | subtract configured CW tone |
| 5 | add configured CW tone |
| 6 | subtract 100 Hz |
| 7 | subtract 200 Hz |

The arithmetic and constants are VERIFIED. User-facing mode names have
not yet been assigned because this trace alone does not prove them.

Before committing the synthesizer update, `FUN_0802c840` is called with
the tuned frequency (or a variant-dependent adjusted value). Earlier
peripheral analysis shows that this function controls
frequency-dependent analog/DAC state. The ordering is VERIFIED.

The function independently derives an RF-band index and a DAC2 code.
Recovered RF-band regions are:

| Index | Frequency region |
| ---: | ---: |
| 0 | below 1.5 MHz or above 55 MHz |
| 1 | 1.5–2.2 MHz |
| 2 | >2.2–3.8 MHz |
| 3 | >3.8–5.5 MHz |
| 4 | >5.5–7.5 MHz |
| 5 | >7.5–13.5 MHz |
| 6 | >13.5–21 MHz |
| 7 | >21–33 MHz |
| 8 | >33–50 MHz |
| 9 | >50–55 MHz |

Classification and exact integer boundaries: VERIFIED. The index is
cached at main-state offset `+0x6A`; a change sets pending-action bit
`0x02`. A second sub-band index is cached at `+0x6B` and sets
pending-action bit `0x01`. Those pending actions are applied before the
deferred synthesizer commit: VERIFIED. The secondary index has seven
regions bounded at 2, 4, 8, 15, 22, and 30 MHz: VERIFIED. Physical
relay or switch assignments are not yet known. Output backends and
exact bit patterns are documented in `docs/rf_switching.md`.

DAC2 receives a piecewise-constant 12-bit code:

| Frequency region | DAC2 code |
| ---: | ---: |
| ≤2 MHz | `0x11D` |
| >2–5 MHz | `0x23A` |
| >5–7 MHz | `0x358` |
| >7–10 MHz | `0x475` |
| >10–14 MHz | `0x593` |
| >14–18 MHz | `0x6B0` |
| >18–21 MHz | `0x7CD` |
| >21–24 MHz | `0x8EB` |
| >24–28 MHz | `0xA08` |
| >28–50 MHz | `0xB26` |
| >50 MHz | `0xC43` |

Codes, boundaries, and DAC2 routing to PA5: VERIFIED. At a 3.3 V DAC
reference the codes form the approximately 230 mV-per-step staircase
specified for the external ACC `BAND_V` contact. Identifying this
output as ACC `BAND_V` is therefore HIGH CONFIDENCE. The complete
correlation is documented in `docs/acc.md`; machine-readable boundaries
are in `analysis/frequency_control/frequency_bands.csv`.

## Synthesizer identification

The synthesizer object at `0x2000036C` contains:

| Field | Value |
| --- | ---: |
| I2C address byte | `0xD4` |
| Conventional 7-bit address | `0x6A` |
| Output count | 5 |
| Reference frequency | 26,000,000 Hz |
| Write callback | `FUN_08030f24` |
| Enable/reset callback | `FUN_0803124c` |

The constants are exported in
`analysis/frequency_control/synth_object.csv`: VERIFIED.

`FUN_08030f24` writes through I2C1 and invokes the existing I2C1 bus
recovery path on failure. `FUN_0803124c` controls GPIOE pin 7.
Bus and callback behavior: VERIFIED. The electrical meaning of GPIOE7
as reset, output enable, or combined board-level gating remains a
HYPOTHESIS.

The address, five-output topology, 26 MHz reference use, initialization
registers, and fractional-divider register writes match the
Renesas/IDT 5P49V60 VersaClock 6E programmable clock generator:
HIGH CONFIDENCE. The relevant primary references are the
[5P49V60 product page](https://www.renesas.com/en/products/5p49v60),
[datasheet](https://www.renesas.com/en/document/dst/5p49v60b-datasheet),
and [VersaClock 6E programming guide](https://www.renesas.com/en/document/mat/versaclock-6e-family-register-descriptions-and-programming-guide).

This evidence excludes the I2C2 devices at 7-bit addresses `0x10`,
`0x4A`, and `0x4C` as the main VFO/LO synthesizer: VERIFIED for BASE
1.1.9. Their identities remain unknown.

## Programming sequence

Startup function `FUN_08033580`:

1. toggles the GPIO callback with two 100 ms delays;
2. writes a 107-byte initialization table;
3. derives the internal VCO setting from the 26 MHz reference, clamped
   to the range 2.5–3.0 GHz;
4. initializes output-divider state.

Startup behavior: VERIFIED.

`FUN_08033428` computes and caches the integer and fractional divider
fields for a requested output frequency. With its final argument zero,
it does not immediately write those fields. In the normal VFO path,
`FUN_0802af0c` then updates frequency-dependent analog state and calls
`FUN_08033514`, which emits the cached three-byte and five-byte register
groups for output 1. Deferred calculation followed by an explicit
commit: VERIFIED.

Two paths are selected by `FUN_0803147c`:

| Selector result | Output programming |
| --- | --- |
| `< 2` | output 1 receives `4 × Ftuned`, then is committed |
| `>= 2` | output 1 receives `Ftuned + 70 MHz`; output 4 receives 140 MHz |

The formulas and output numbers are VERIFIED. In the reviewed BASE
1.1.9 binary, `FUN_0803147c` consists only of `movs r0,#1; bx lr`.
It therefore always selects the `< 2` path: VERIFIED. The alternative
path is present but unreachable in this build.

`FUN_0802a428` also programs output 4 to a value in approximately the
1–2.2 MHz range while avoiding harmonic relationships within 100 kHz
of the tuned frequency. More precisely, it starts at 2 MHz and moves
the clock to `2 MHz ± 100 kHz / N` when a tuned-frequency harmonic
would fall closer than 100 kHz. It then clamps the programmed result
to 1–2.2 MHz. The arithmetic and limits are VERIFIED.

The X6100 maintenance material identifies a board signal named `PSYNC`
as the power-supply synchronization square wave. A tunable clock near
2 MHz that is moved to prevent receiver harmonics is consistent with
that purpose. Identifying synthesizer output 4 as the source of
`PSYNC` is therefore HIGH CONFIDENCE, not VERIFIED, because no recovered
schematic or firmware-visible net directly connects the output to the
named test point. The reviewed
[X6100 maintenance manual](https://www.manualslib.com/guide/3740642/xiegu-x6100-hf-transceiver-series-manual.html)
also identifies the 26 MHz reference and tuned-frequency LO test
points.

Historical control index 53 is labelled `pwrsync`. BASE 1.1.9 copies
that register into its internal cache but no direct use of the cached
value has yet been found. Its presence supports the interpretation but
does not prove that output 4 is the same physical signal: MEDIUM
CONFIDENCE.

## Reimplementation implications

- Treat Linux VFO values as hertz and preserve signed offset arithmetic.
- Preserve the mode-dependent offsets before LO conversion.
- On the `< 2` hardware path, calculate the output-1 divider first,
  update the frequency-dependent analog path, and only then commit the
  cached synthesizer registers.
- BASE 1.1.9 can implement the reachable `4 × Ftuned` path. Preserve
  the alternative formula in the architecture only if compatibility
  with another BASE build or board family is required.
- Generate the approximately 2 MHz output-4 clock with the recovered
  harmonic-avoidance algorithm; its `PSYNC` role is HIGH CONFIDENCE.
- Implement the clock-generator driver from the public 5P49V60 register
  specification; do not copy the OEM initialization/decompiler output.
- Retain I2C1 recovery for failed synthesizer writes.

## Remaining work

- Locate another firmware build in which `FUN_0803147c` returns a value
  other than 1, or establish that the alternative path is dead legacy
  code.
- Correlate internal receive/transmit offset storage with the complete
  wire-register update path.
