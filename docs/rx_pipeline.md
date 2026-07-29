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

No independent complex-input DC-subtraction stage has yet been
identified. The filters later in the audio path and the NFM
post-demodulator recurrence must not be presented as proof of converter
DC removal. This remains an open item.

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

An optional block processor `FUN_08022C30` consumes accumulated
128-sample audio blocks and publishes processed blocks through a
512-sample ring. Its detailed transform remains unresolved; identifying
it as the user-visible noise-reduction facility is MEDIUM CONFIDENCE.

With that facility disabled, the 16 common-path samples at `0x20005FC4`
are sent directly to the factor-8 FIR interpolator at `0x20006C30`.
With it enabled, samples from the processed ring feed the same
interpolator. The resulting 128-sample block starts at `0x200061C4`.
The interpolation topology is VERIFIED.

The interpolated RX signal is subsequently combined with monitor and
other audio sources and converted back to a signed fixed-point DMA
output. Exact source names, mixer gains, saturation behavior, and the
final SPI2 DMA-bank layout remain work items; no semantic source names
are assigned here without evidence.

## Independent implementation requirements

- Accept 128 interleaved complex Q31 samples per converter DMA block.
- Preserve the halfword swap before signed conversion.
- Provide the recovered adaptive I/Q correction with its safe fallback.
- Implement the optional 100 ksample/s complex rotator.
- Reproduce the two mode-dependent decimation trees and demodulators.
- Run common audio processing at 12.5 ksample/s and return 128 samples
  through the factor-8 interpolator.
- Keep converter I/Q polarity configurable until verified on hardware.
- Do not claim converter DC removal until a distinct stage or measured
  equivalent is established.

## Remaining evidence work

- Export and independently validate all RX FIR and runtime biquad
  coefficient sets.
- Determine whether converter DC removal exists elsewhere or is wholly
  provided by later channel filtering.
- Resolve every common audio filter to its control field and response.
- Recover `FUN_08022C30` sufficiently to implement the optional
  noise-reduction path.
- Assign the final audio-mixer sources and fixed-point output contract.
- Verify I/Q polarity, sideband polarity, gain, and sample rates with
  known RF and audio captures.
