# Recovered DSP primitives

## Scope

The large DMA1 Stream 3 handler calls a small set of optimized
floating-point primitives. Their algorithms and state layouts allow
candidate CMSIS-DSP identities to be assigned without yet renaming
symbols.

All names in this document are candidates unless explicitly marked
otherwise.

## Direct calls from the DMA handler

The complete call graph contains 26 unique direct callees from
`FUN_08024528`. Many are runtime arithmetic, memory, or DMA helpers.
The following functions implement reusable signal-processing kernels.

| Address | Current symbol | Candidate identity | Evidence | Confidence |
| ---: | --- | --- | --- | --- |
| `0x08035364` | `FUN_08035364` | `candidate_arm_fir_interpolate_f32` | polyphase FIR, interpolation factor in instance, produces multiple outputs per input | HIGH CONFIDENCE |
| `0x080357C0` | `FUN_080357c0` | `candidate_arm_fir_f32` | FIR instance with tap count, coefficient pointer, state pointer, block processing | HIGH CONFIDENCE |
| `0x08035C88` | `FUN_08035c88` | `candidate_arm_fir_decimate_f32` | block size divided by instance factor; one output per factor-sized input group | HIGH CONFIDENCE |
| `0x08036000` | `FUN_08036000` | `candidate_arm_biquad_cascade_df1_f32` | stages use five coefficients and four state floats | HIGH CONFIDENCE |
| `0x080361A0` | `FUN_080361a0` | `candidate_arm_cmplx_mag_f32` | computes `sqrt(real² + imag²)` for interleaved complex input | HIGH CONFIDENCE |
| `0x08036478` | `FUN_08036478` | `candidate_arm_scale_f32` | multiplies each source float by one scalar | HIGH CONFIDENCE |

The mathematical behavior in the final column is VERIFIED from the
instructions. Exact library symbol identity remains HIGH CONFIDENCE
until matched against a specific CMSIS-DSP build or signature database.

## Rate-conversion evidence

The DMA handler calls both the candidate decimator and interpolator.
Firmware initialization also establishes rate constants of 100 kHz,
12.5 kHz, and 25 kHz.

Together these establish that the signal path contains explicit
multi-rate FIR processing: VERIFIED.

The RX call sites are now separated. SSB/CW use a direct factor-8
complex decimator. AM/NFM use factor 4 before demodulation and factor 2
after it. All modes therefore produce 16 audio samples at the
12.5-kHz-domain rate from each 128-sample input block, and a factor-8
interpolator returns 128 samples to the output domain. The call topology
and integer factors are VERIFIED; interpreting the initialization
constants as physical sample rates still requires a hardware clock
measurement. See `docs/rx_pipeline.md`.

All RX rate-conversion FIR coefficient sets are exported and
independently checked for symmetry and representative response. Runtime
RX biquad table selection remains to be completed. See
`docs/rx_pipeline.md`.

## Biquad processing

`FUN_08036000` iterates over a stage count. Each stage consumes:

- five coefficients;
- four persistent state values;
- a caller-provided float block.

The output of each stage becomes the input to the next stage. This is a
direct-form-I floating-point biquad cascade: VERIFIED.

Multiple state objects are passed to this primitive from different
branches of the DMA handler, so one final semantic name cannot yet be
assigned to every filter instance.

## TX filter instances

| Object | Primitive | Parameters | Confidence |
| ---: | --- | --- | --- |
| `0x20007244` | FIR decimator | factor 8, 64 taps | VERIFIED |
| `0x20007728` | biquad cascade | 5 stages, generated for 300 Hz at 12.5 kHz | VERIFIED parameters |
| `0x200077F4` | biquad cascade | 5 stages, generated for 3000 Hz at 12.5 kHz | VERIFIED parameters |
| `0x200078D8` | FIR | 101-tap antisymmetric quadrature coefficients | VERIFIED structure |
| `0x20007490` | FIR interpolator | factor 8, 64 taps | VERIFIED |
| `0x200075DC` | FIR interpolator | factor 8, 64 taps | VERIFIED |

The decimator and both interpolators share the flash coefficient array
at `0x0803E3E4`. The quadrature FIR uses `0x0803E130`. Both arrays are
exported under `analysis/tx_filters/`. Its exact antisymmetry, zero
center tap, and use with a 50-sample delay establish a Hilbert role:
HIGH CONFIDENCE.

The 300/3000 Hz biquad entries have also been exported. Each contains
five six-float source sections plus an overall gain. The runtime loader
converts each section into the five-float CMSIS-style DF1 layout and
applies the two overall gains after cascading both objects: VERIFIED.
See `docs/tx_pipeline.md` for the selection formula and addresses.

## Complex magnitude

`FUN_080361a0` consumes interleaved real/imaginary float pairs and emits
one magnitude per pair:

```text
magnitude = sqrt(real * real + imag * imag)
```

Algorithm: VERIFIED. Its DMA-handler call site is a candidate signal
level/envelope stage; the downstream consumer must be traced before
that semantic label is finalized.

## Call-graph tooling

`ghidra_scripts/ExportCallGraph.java` exports every direct call as:

```text
caller_address,caller,call_site,callee_address,callee
```

Run it with:

```text
./tools/run_headless_callgraph.sh analysis/callgraph.csv
```

The export is deterministic for the current analyzed Ghidra project and
does not rename or modify the program.

## Reproducible evidence

- `analysis/callgraph.csv`;
- `analysis/interrupts/irq_14_DMA1_Stream3_08024528_disassembly.txt`;
- `ghidra_scripts/ExportCallGraph.java`.
