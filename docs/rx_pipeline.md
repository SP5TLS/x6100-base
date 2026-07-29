# RX DSP pipeline

This document describes the receive branch of DMA1 Stream 3 handler
`FUN_08024528`. It records behavior needed for an independent
implementation; names remain descriptive until stronger symbol evidence
exists.

The machine-readable stage and mode summaries are in
`analysis/rx_pipeline/stages.csv` and
`analysis/rx_pipeline/mode_paths.csv`.

## Block and sample-rate model

The handler processes 128 complex input samples per completed SPI3/I2S3
DMA bank. The recovered rate constants are 100,000, 25,000, and 12,500
samples/s. The following mapping is VERIFIED:

| Path | Conversion | Samples per handler call |
|---|---:|---:|
| complex converter input | none | 128 complex |
| SSB/CW | decimate by 8 | 16 real audio |
| AM/NFM | decimate by 4, demodulate, decimate by 2 | 16 real audio |
| common audio output | interpolate by 8 | 128 real |

Identifying SPI3/I2S3 as the converter I/Q stream is documented in
`docs/spi_i2s.md`.

## Input representation

For each complex sample the handler reads two 32-bit DMA words. It swaps
the upper and lower 16-bit halves of each word, interprets both results
as signed integers, and converts them to floating point. This operation
and the interleaved two-channel layout are VERIFIED.

Both components are multiplied by:

```text
input_gain_1 * input_gain_2 * 4.656612e-10
```

`4.656612e-10` is `2^-31`, so the converter representation is normalized
signed Q31. Both runtime gains are initialized to `1.0`. The arithmetic
and initial values are VERIFIED.

The converted block starts at `0x20003990` and contains interleaved
floating-point components. Calling them I and Q is HIGH CONFIDENCE; the
absolute electrical polarity and which word is I versus Q still require
a known-signal capture.

## Adaptive I/Q correction

The handler maintains block accumulators and exponentially retained
energy/correlation estimates in the state range
`0x2000B6EC..0x2000B714`. Every 128 samples it updates two correction
coefficients. Between updates it applies:

```text
component_2' = component_2 + component_1 * cross_coefficient
component_1' = component_1 * amplitude_coefficient
```

The estimate retention is `0.997`; the new contribution is derived from
`0.003 / 128`. Invalid or zero-energy estimates fall back to cross
coefficient `0.0` and amplitude coefficient `1.0`. The arithmetic and
fallback are VERIFIED. Its purpose as adaptive quadrature
cross-coupling/amplitude-imbalance correction is HIGH CONFIDENCE.

The complete complex front end contains no independent input
DC-subtraction stage: VERIFIED absence in the recovered path. The
filters later in the audio path and the NFM post-demodulator recurrence
must not be presented as converter DC removal.

## Optional complex frequency shift

The Linux-visible source is protocol register 35 at byte offset
`0x008C`. This register is not present in the historical X6100Control
enumeration. `FUN_0802AF0C` decodes it as:

```text
bypass = (register >> 24) & 1
n      = sign_extend_24(register & 0x00ffffff)
```

`FUN_08024404` copies `bypass` to `0x2000BF71`, and
`FUN_08024418` copies `n` to `0x2000BF74`. These are their only direct
writers: VERIFIED from memory-reference export.

The update block calls both helpers during its initial full refresh and
whenever live register 35 differs from its cached copy. No mode check
is made at this point: VERIFIED. With a zero-filled control window the
initial decoded state is `bypass=0, n=0`; a later Linux register write
changes it.

The polarity is important: the DMA handler rotates only while
`bypass == 0`. Thus bit 24 clear enables the path and bit 24 set
bypasses it. With `n == 0`, enabling the path still produces zero
shift.

When an enabled `n` changes, the handler caches it and derives:

```text
phase_increment = abs(n) * 2*pi / 100000
direction       = sign(n)
```

For each corrected input sample `(I,Q)`, it applies:

```text
c = cos(phase)
s = sin(phase) * direction
I' = I*c - Q*s
Q' = I*s + Q*c
phase = wrap_2pi(phase + phase_increment)
```

The equations, update trigger, and phase wrapping are VERIFIED. This
is mathematically a signed rotation at `n / 100000` cycles/sample.
Consequently one integer unit is one hertz if the recovered
100-ksample/s domain equals the physical converter rate: HIGH
CONFIDENCE unit. A physical I2S clock measurement remains the final
absolute-rate check.

The phase accumulator is not reset when `n` changes or when bypass is
asserted. It simply stops advancing while bypassed and resumes from its
previous phase when re-enabled: VERIFIED.

### Separate CW/CWR beat oscillator

CW/CWR modes have another oscillator after factor-8 decimation and
before their channel biquads. Its frequency is not `n`. It comes from
protocol register 33 bits `12...22`, the verified `cwtone` field, and
is stored as a floating-point hertz value at `0x200082E8`.

At the 12.5-ksample/s stage its normalized phase advances by:

```text
cw_phase_cycles += cwtone * 8e-5
```

Since `8e-5 = 1/12500`, `cwtone` is used directly in hertz. The
arithmetic and register source are VERIFIED.

The register-35 bypass flag gates both the 100-ksample/s complex
rotator and this later CW/CWR oscillator. With bit 24 set, neither is
applied. With bit 24 clear, the general shift uses `n`, while CW/CWR
additionally use `cwtone`. This shared gating is VERIFIED; the
user-interface reason for coupling the two stages remains unresolved.

## Mode-dependent channel and demodulator paths

The numeric mode correlation below comes from the existing historical
Linux-facing mode mapping and is HIGH CONFIDENCE:

| Mode | Name | Complex decimation | Demodulation |
|---:|---|---:|---|
| 0 | LSB | 8 | phasing: delayed I plus Hilbert Q |
| 1 | LSB_DIG | 8 | phasing: delayed I plus Hilbert Q |
| 2 | USB | 8 | phasing: delayed I minus Hilbert Q |
| 3 | USB_DIG | 8 | phasing: delayed I minus Hilbert Q |
| 4 | CW | 8 | beat oscillator, filtered I minus filtered Q |
| 5 | CWR | 8 | beat oscillator, filtered I plus filtered Q |
| 6 | AM | 4 then 2 | complex magnitude |
| 7 | NFM | 4 then 2 | phase-difference discriminator |

## Exact rate-conversion FIRs

All RX rate-conversion coefficient arrays and their instance parameters
are now exported. The mapping is VERIFIED:

| Flash coefficients | Factor | Taps | RX instances and use |
|---:|---:|---:|---|
| `0x0803E3E4` | 8 decimation | 64 | `0x2000665C`, `0x200068A8`: SSB/CW I and Q |
| `0x0803E3E4` | 8 interpolation | 64 | `0x20006C30`: common audio output |
| `0x0803E354` | 4 decimation | 36 | `0x200063C4`, `0x20006510`: AM/NFM I and Q |
| `0x0803E2C4` | 2 decimation | 36 | `0x20006AF4`: AM/NFM real demodulator output |

The factor-8 array is shared with the already exported TX
rate-conversion path and is stored in
`analysis/tx_filters/rate_conversion_fir_64.csv`. The two 36-tap arrays
are in `analysis/rx_pipeline/fir_decimate_4x_36.csv` and
`analysis/rx_pipeline/fir_decimate_2x_36.csv`. A machine-readable object
map is in `analysis/rx_pipeline/rate_conversion_filters.csv`.

All three arrays are exactly symmetric linear-phase FIRs: VERIFIED from
the exported values. Independent numerical evaluation gives:

| Array | Coefficient sum | Half-output-rate response |
|---|---:|---:|
| factor-8, 64 taps | `1.057501116` | `-6.020600 dB` at 6.25 kHz in the 100-kHz domain |
| factor-4, 36 taps | `0.942498868` | `-6.020600 dB` at 12.5 kHz in the 100-kHz domain |
| factor-2, 36 taps | `0.942498897` | `-6.020600 dB` at 6.25 kHz in the 25-kHz domain |

The sums and responses are reproducible calculations from the exact
exports, not additional firmware semantics. An independent
implementation may use these arrays directly or use an equivalently
validated anti-alias/interpolation design if bit-for-bit compatibility
is unnecessary.

## Runtime channel-filter selection

Protocol registers 44 through 47 provide four signed frequency edges:

| Register | Address | DSP state |
|---:|---:|---:|
| 44 `filter1_low` | `0x00B0` | `0x2000859C` |
| 45 `filter1_high` | `0x00B4` | `0x200085A0` |
| 46 `filter2_low` | `0x00B8` | `0x200085A4` |
| 47 `filter2_high` | `0x00BC` | `0x200085A8` |

`FUN_080240B4` copies all four values and sets filter-dirty bit 0 when
any changes. Register routing and dirty behavior are VERIFIED.

The firmware uses two families of precomputed five-stage biquads:

- the pointer table at `0x20001484` supplies high-pass sections;
- the pointer table at `0x20002414` supplies low-pass sections.

Each selected source entry contains five six-float sections plus a
final gain. The loader negates the two feedback terms in each section
for the runtime direct-form-I representation. Structure, table
selection, and conversion are VERIFIED.

For requested cutoff `f` and processing rate `Fs`, the table index is:

```text
index = trunc((2*f/Fs - 0.002) * 995)
index = clamp(index, 0, 995)
```

The arithmetic and bounds are VERIFIED. An independent implementation
does not need the complete OEM table: an equivalent stable five-stage
high-pass or low-pass design at the requested edge can implement the
functional contract. Exact OEM entries matter only for sample-level
matching.

### Predemodulation component filters

Objects `0x20006D7C` and `0x20006E48` filter the two decimated complex
components before mode demodulation:

| Modes | Rate | Object 1 cutoff | Object 2 cutoff |
|---|---:|---:|---:|
| LSB/LSB_DIG/USB/USB_DIG | 12.5 ksample/s | 6600 Hz, clamped to highest low-pass entry | same |
| CW/CWR | 12.5 ksample/s | 3000 Hz low-pass | same |
| AM | 25 ksample/s | `max(abs(filter1_low), abs(filter2_low))` | `min(abs(filter1_high), abs(filter2_high))` |
| NFM | 25 ksample/s | 7500 Hz low-pass | same |

Calls, constants, absolute-value operations, min/max decisions, and
rates are VERIFIED. The 6600-Hz request lies above the 12.5-ksample/s
Nyquist limit and selects the clamped table endpoint; functionally it
leaves the SSB component bandwidth to the later audio filters.

### Postdemodulation SSB/CW filters

Modes 0 through 5 apply all four user edges at 12.5 ksample/s:

| Object | Position relative to AGC | Type | Edge |
|---:|---|---|---:|
| `0x20006FE0` | before | low-pass | `filter1_high` |
| `0x20007178` | before | low-pass | `filter2_high` |
| `0x20006F14` | after | high-pass | `filter1_low` |
| `0x200070AC` | after | high-pass | `filter2_low` |

This produces two cascaded upper-edge sections before AGC and two
lower-edge sections after AGC. Object ordering and edge routing are
VERIFIED. The purpose of the duplicated filter1/filter2 pairs as two
independently configured skirts is HIGH CONFIDENCE.

AM and NFM instead load cutoff 0 into both high-pass objects and
12,000 Hz into both low-pass objects at the 12.5-ksample/s rate. Both
requests clamp to table endpoints and functionally bypass the
user-configured postdemodulation bandpass: HIGH CONFIDENCE functional
effect, VERIFIED requests and table bounds.

The complete mapping is also available in
`analysis/rx_pipeline/channel_filter_paths.csv`.

## DC-removal conclusion

No dedicated complex-input DC estimator or subtractor exists between
Q31 conversion and demodulation in `FUN_08024528`: HIGH CONFIDENCE
after complete inspection of that branch. The adaptive I/Q stage
corrects cross-correlation and amplitude imbalance but does not track
or subtract a mean: VERIFIED equations.

For SSB/CW, nonzero `filter1_low` and `filter2_low` values suppress DC
later in the real audio path through the two high-pass biquads. NFM has
the explicit postdemodulation recurrence
`y[n]=x[n]-x[n-1]+0.9*y[n-1]`. AM has no separately identified
converter-DC cancellation stage. An independent implementation may add
complex DC blocking as a deliberate improvement, but it is not part of
the recovered OEM front-end contract.

### SSB and digital SSB

Each complex component passes through its own factor-8 FIR decimator and
runtime-configurable biquad channel filter. One filtered component enters
a 100-sample delay. The other enters a 101-tap FIR Hilbert transformer.
The delayed and quadrature outputs are added for modes 0/1 and
subtracted for modes 2/3. The topology and branch conditions are
VERIFIED; its purpose as a phasing SSB detector is HIGH CONFIDENCE.

### CW and CWR

Modes 4/5 use the same factor-8 front end. When the frequency-shift
facility is enabled, a separate beat oscillator multiplies the two
decimated components before the channel biquads. Mode 4 subtracts the
filtered components and mode 5 adds them. The operations are VERIFIED;
their CW/CWR interpretation follows the HIGH CONFIDENCE mode mapping.

### AM

Mode 6 first decimates both complex components by four, applies the
channel biquads, and calculates:

```text
sqrt(I*I + Q*Q)
```

It then decimates the real result by two. The arithmetic is VERIFIED and
is an envelope AM detector.

### NFM

Mode 7 uses the same factor-4 complex front end and calls
`FUN_080210C4`. That helper multiplies the current complex sample by the
conjugate of the previous sample, normalizes the result, derives its
phase, and filters the phase result. This arithmetic is VERIFIED; its
role as a phase-difference FM discriminator is HIGH CONFIDENCE. Its real
output is then decimated by two.

## Common audio processing

The 16 demodulated samples begin at `0x20005DC4`. Each sample traverses
two runtime-configurable biquad pairs and additional post-demodulation
filters. AM receives a fixed factor of five late in this chain. A
first-order recurrence after the last common biquad is:

```text
y[n] = x[n] - x[n-1] + 0.9*y[n-1]
```

The topology and arithmetic are VERIFIED. Exact user-facing names and
cutoff settings for every runtime biquad remain to be correlated with
control-register fields.

An optional detector around `0x200080C4..0x200080E0` measures a filtered
audio-derived changing quantity with asymmetric smoothing, hysteresis,
and a 50-update hold counter. Its use as a squelch/noise detector is
HIGH CONFIDENCE; the exact physical threshold units remain unresolved.

## AGC

Modes other than NFM optionally pass through a feed-forward AGC:

1. input is multiplied by 50 and written to a 120-sample circular delay;
2. absolute level is tracked with asymmetric behavior, including a
   `0.75` coefficient on one transition direction;
3. `20*log10(level + 2.3283e-10)` is compared with the configured
   target and current gain;
4. separate attack and release coefficients update gain, with optional
   hang time;
5. gain is limited to `-100..+10` dB and converted to linear amplitude;
6. the sample delayed by 60 positions is multiplied by the gain and a
   factor of 10.

The operations, delay lengths, and gain bounds are VERIFIED. Calling it
a feed-forward AGC with 60-sample look-ahead is HIGH CONFIDENCE. When
the AGC enable byte is clear, the non-NFM path instead applies a fixed
factor of 50. NFM bypasses this entire gain branch.

## Noise reduction and interpolation

Protocol register 23 controls the optional processor `FUN_08022C30`:

| Field | Meaning | Confidence |
|---:|---|---|
| bits `0...7` | noise-reduction threshold, capped to 100 | VERIFIED |
| bit `24` | noise-reduction enable | VERIFIED |

The existing historical names are `nrthr` and `nre`. `FUN_0802411C`
writes the enable byte at `0x20008FBD`; `FUN_0802412C` converts the
threshold to float after clamping. Writers and field routing are
VERIFIED.

### Frame construction

The normal 12.5-ksample/s audio path accumulates 128 samples before
calling `FUN_08022C30`. The function constructs a 256-sample frame from
the previous and current 128-sample blocks, giving 50-percent overlap.
It applies a 256-point square-root Hann window exported from
`0x0803D818`, creates a complex buffer with zero imaginary inputs, and
calls the same 256-point transform helper in forward and inverse
directions.

Frame size, overlap, real-to-complex layout, transform calls, and
window values are VERIFIED. Identification of the transform as a
complex FFT/IFFT is HIGH CONFIDENCE from its call contract and
surrounding spectral operations.

After inverse transformation, the same square-root Hann window is
applied and the first 128 samples are overlap-added with the saved
second half from the preceding frame. The exact window is in
`analysis/rx_pipeline/noise_reduction_window_256.csv`.

### Spectral estimator and gain

The processor calculates squared magnitude for 128 positive-frequency
bins. On enable or reset it initializes per-bin state, then spends 41
frames accumulating the initial noise-power estimate with a `0.025`
coefficient. It subsequently maintains:

- instantaneous signal/noise power ratios, limited to
  `0.001...1000`;
- a nonnegative excess-SNR estimate with `0.98/0.02` smoothing;
- adaptive per-bin noise estimates bounded by threshold-dependent
  tests;
- a nonlinear spectral gain with a floor of `0.001`.

The state machine, constants, bounds, and per-bin updates are VERIFIED.
Its functional identity as adaptive spectral noise reduction is HIGH
CONFIDENCE. Reproducing every OEM estimator coefficient is optional
for an independent receiver; a conventional Wiener/spectral-subtraction
implementation with equivalent enable, threshold, passband, framing,
and latency is compatible at the functional level.

Processing is limited to bins derived from the active RX band:

```text
low_bin  = clamp(int(low_edge  / 12500 * 256) - 2, 1, 126)
high_bin = clamp(int(high_edge / 12500 * 256) + 2,
                 low_bin + 1, 127)
```

The conversion, margins, and bounds are VERIFIED. The selected edges
are the maximum of the two low edges and minimum of the two high edges.

Processed 128-sample blocks are multiplied by `1.414` and published
through a 512-sample ring. The consumer substitutes samples from this
ring for the normal post-filter audio before factor-8 interpolation.
Buffer sizes, gain, substitution, and underrun-to-zero behavior are
VERIFIED.

With that facility disabled, the 16 common-path samples at `0x20005FC4`
are sent directly to the factor-8 FIR interpolator at `0x20006C30`.
With it enabled, samples from the processed ring feed the same
interpolator. The resulting 128-sample block starts at `0x200061C4`.
The interpolation topology is VERIFIED.

## Final audio mixer and I2S2ext output

The final 128-frame loop combines three sources:

```text
input_monitor = (spi2_input_left + spi2_input_right) * monitor_gain
rx             = interpolated_rx * rx_gate
mix            = input_monitor + rx + cw_monitor

I2S2ext left  = Q31(mix)
I2S2ext right = Q31(mix * receive_volume * sp_attenuation)
```

The buffer sources, arithmetic, and destination are VERIFIED:

| Term | Source/control | Behavior |
| --- | --- | --- |
| `spi2_input_left/right` | float buffers at `0x20004990` and `0x20004B90` | two real TLV320 ADC channels already used as TX audio |
| `monitor_gain` | register 29 `monilevel`, converted by `value * 0.01` | selected during normal TX; other route states select fixed `0`, `0.5`, or the same configured gain |
| `interpolated_rx` | 128-sample buffer at `0x200061C4` | output of the factor-8 RX interpolator |
| `rx_gate` | transition ramp at `0x20008378` | forced to zero during TX or while squelch is closed |
| `cw_monitor` | local CW oscillator and 120-sample envelope | nonzero only in modes 4 and 5 |
| `receive_volume` | register 14 digital scalar | `0`, exponential below setting 30, unity at and above 30 |
| `sp_attenuation` | register 21 bit 5 combined with PF15 | `0.05` when selected, otherwise `1.0` |

The historical `monilevel` label and its exact scaling are HIGH
CONFIDENCE/VERIFIED respectively. Calling the first term an input
monitor is HIGH CONFIDENCE: it is the sum of the codec ADC channels
used by the TX chain and it is admitted at the configured monitor
level during TX.

Each float is converted with the ARM signed fixed-point conversion
used by the firmware (`32` total bits, `31` fractional bits). The two
16-bit halves of each Q31 word are exchanged before storage. The
selected I2S2ext DMA bank therefore contains 128 interleaved frames:

| Word in frame | Payload | Codec destination |
| ---: | --- | --- |
| 0 | unscaled full mix | left DAC/HPL, MAIN/Linux-board capture |
| 1 | receive-volume/S-P-scaled full mix | right DAC/HPR, headphone or speaker |

Word order and TLV320 left/right routing are VERIFIED. The external
endpoint names are HIGH CONFIDENCE from the Linux-side cross-check.
No explicit clamp is visible around the float-to-Q31 instruction;
behavior for an out-of-range mixer value remains unverified and should
be established by an instruction-level test or hardware capture.

Evidence:

- `analysis/rx_pipeline/final_audio_state_refs.csv`;
- `analysis/rx_pipeline/final_audio_control_decompile.txt`;
- `analysis/i2c/audio_board_topology_evidence.csv`.

## Independent implementation requirements

- Accept 128 interleaved complex Q31 samples per converter DMA block.
- Preserve the halfword swap before signed conversion.
- Provide the recovered adaptive I/Q correction with its safe fallback.
- Implement the optional 100 ksample/s complex rotator.
- Reproduce the two mode-dependent decimation trees and demodulators.
- Run common audio processing at 12.5 ksample/s and return 128 samples
  through the factor-8 interpolator.
- Build 128 I2S2ext stereo frames using the recovered monitor/RX/CW
  mix, apply receive volume only to the right/HPR word, and exchange
  the two 16-bit halves of every Q31 word.
- Keep converter I/Q polarity configurable until verified on hardware.
- Do not add a dedicated converter-DC stage merely to mirror the OEM
  path; make it an independently justified optional improvement.

## Remaining evidence work

- Establish out-of-range float-to-Q31 behavior.
