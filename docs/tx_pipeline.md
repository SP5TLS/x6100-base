# Transmit DSP pipeline

## Scope

This document is an incremental reconstruction of the BASE 1.1.9
transmit path. It currently covers RX/TX mode handoff, input conversion,
rate conversion, modulation, ALC, final fixed-point conversion, and
I2S output routing.

## RX/TX mode handoff

`FUN_08023f20` updates byte `0x200085AF` and sets dirty bit `0x08` in
`0x200085B4` when the value changes. `FUN_0802aaf4` calls it with:

| Requested state | Value |
| --- | ---: |
| RX | 0 |
| TX | 1 |

The caller association and mode values are VERIFIED.

At the next DMA1 Stream 3 block, `FUN_08024528` snapshots and clears
dirty bit `0x08`. The bit causes the handler to reset TX/RX processing
state, including filter buffers, ring indices, accumulators, and
mode-dependent state. Mode-change request followed by block-boundary
reset: VERIFIED.

This is separate from the frequency-change reset flag at `0x20008328`.
Both mechanisms clear DSP history, but they are requested by different
control events.

## Input conversion and first TX gain

The DMA handler converts signed samples from the completed SPI2/I2S2
receive bank into two floating-point channel arrays using scale
`4.656612e-10`. When `0x200085AF` is nonzero, it then calculates:

`tx_input[n] = (channel_0[n] + channel_1[n]) × gain`

The sum, multiplication, and use only in nonzero/TX mode are VERIFIED.
The result enters the following decimation and mode-dependent
filter/modulation stages.

The floating-point gain is stored at `0x2000B778` and written by
`FUN_080243f0`. During TX entry, `FUN_0802aaf4` first writes `1.0`; for
one audio-routing branch it later writes `5.0`. Values and branching:
VERIFIED. Interpreting the two branches as particular microphone
connectors is not yet supported, so no source names are assigned.

The gain is therefore a digital TX input gain: HIGH CONFIDENCE. It is
not the external PA bias/drive value, because it is consumed directly
as a floating-point multiplier inside the audio DSP pipeline:
VERIFIED distinction.

Byte `0x2000B739` can force this multiplier to zero, but no firmware
writer to that byte exists in BASE 1.1.9 and startup `.bss`
initialization leaves it zero. The conditional mute path is present but
inactive in this build: HIGH CONFIDENCE.

Direct-reference exports:

- `analysis/rf_switching/tx_gain_refs.csv`;
- `analysis/rf_switching/tx_mode_state_refs.csv`.

## Rate conversion

The raw TX input is accumulated in groups of eight samples and passed
to a 64-tap FIR decimator with factor 8. Its instance is at
`0x20007244`, and its coefficients are copied from `0x0803E3E4` during
startup. Factor, tap count, object, coefficient source, and processing
direction: VERIFIED.

After mode-dependent complex-baseband generation, two independent
64-tap FIR interpolators at `0x20007490` and `0x200075DC` expand the I
and Q components by factor 8. They use the same coefficient array at
`0x0803E3E4`: VERIFIED.

Together with the recovered 100 kHz raw and 12.5 kHz internal rate
constants, these structures establish:

`100 kHz → decimate by 8 → 12.5 kHz modulation → interpolate by 8 → 100 kHz`

Rate-domain topology: VERIFIED.

The 64 coefficients are exactly symmetric. Their exported
single-precision sum is approximately `1.057501116`. Exact IEEE-754
bits and decimal values are in
`analysis/tx_filters/rate_conversion_fir_64.csv`.

Between decimation and modulation, two five-stage direct-form-I biquad
cascades process the audio sequentially. Startup generates their
coefficients for 300 Hz and 3000 Hz using the 12.5 kHz rate. Structure,
stage count, frequencies, rate, and ordering: VERIFIED. Interpretation
as the TX audio band-pass edges is HIGH CONFIDENCE.

The coefficients are selected from two initialized `.data` pointer
tables. For cutoff `F` and sample rate `Fs`, the firmware computes:

`index = trunc(((2 × F / Fs) − 0.002) × 995)`

and clamps the result to `0…995`. Thus:

| Cutoff | Index | Flash entry | Overall gain |
| ---: | ---: | ---: | ---: |
| 300 Hz | 45 | `0x0805B10C` | `0.693388164` |
| 3000 Hz | 475 | `0x0806C334` | `0.0200895444` |

Formula, indices, initialized pointers, and gains: VERIFIED.

Each flash entry contains five six-float groups followed by one overall
gain:

`b0, b1, b2, 1.0, a1, a2`

The loader copies `b0…b2`, omits the per-stage `1.0`, negates `a1/a2`
to match the feedback-sign convention of `FUN_08036000`, and stores
five floats per runtime stage. After the two cascades, the DSP path
multiplies the sample by both entries' overall gains. Layout,
sign conversion, and gain application: VERIFIED.

Exact source entries are exported in:

- `analysis/tx_filters/biquad_300hz_table_entry.csv`;
- `analysis/tx_filters/biquad_3000hz_table_entry.csv`;
- `analysis/tx_filters/biquad_selection.csv`.

`tools/verify_tx_biquads.py` independently evaluates the exported
sections using:

`H(z) = gain × Π (b0 + b1 z⁻¹ + b2 z⁻²) / (1 + a1 z⁻¹ + a2 z⁻²)`

It does not execute OEM code. Representative combined magnitudes are:

| Frequency | Magnitude |
| ---: | ---: |
| 300 Hz | `0.959888` |
| 1 kHz | `0.998126` |
| 2 kHz | `0.975860` |
| 3 kHz | `0.438530` |
| 4 kHz | `0.000358` |

The cascade passes the expected voice-frequency region and strongly
attenuates frequencies outside it. This independently verifies the
coefficient layout, feedback signs, and overall-gain interpretation:
HIGH CONFIDENCE.

## Mode-dependent modulation

The mode byte at `0x200085AD` selects the initial complex-baseband
generator:

| Mode values | Recovered behavior | Interpretation |
| --- | --- | --- |
| 0, 1 | audio history/delay plus FIR-derived quadrature component; opposite I/Q orientation between modes | opposite-sideband pair, HIGH CONFIDENCE |
| 2, 3 | same delay/FIR quadrature construction with the alternate orientation pairing | second opposite-sideband pair, HIGH CONFIDENCE |
| 4, 5 | internally generated/keyed waveform is copied to both components; GPIOE12 follows its sign/state | CW-like keyed pair, HIGH CONFIDENCE |
| 6 | `carrier_offset + audio × depth`; identical values feed both initial components | AM-like modulation, HIGH CONFIDENCE |
| 7 | audio is clipped, scaled into phase deviation, then converted to a `sin/cos` complex pair | angle/FM modulation, VERIFIED algorithm; FM mode HIGH CONFIDENCE |
| other | both components are zero | VERIFIED |

The numeric mode selection and signal-processing behavior are VERIFIED.
Final user-facing mode names are not assigned because the BASE binary
does not itself prove the Linux enumeration labels.

For modes 0–3, the firmware uses a 100-sample circular history and a
101-tap quadrature FIR helper. One component is delayed by 50 samples
while the other is filtered, then both are multiplied by eight. The
coefficient array at `0x0803E130` is exactly antisymmetric with a zero
center tap and zero sum to exported precision, matching a Hilbert
transformer. Delay, history length, FIR use, coefficient properties,
orientation swaps, and scaling: VERIFIED. Exact values are in
`analysis/tx_filters/quadrature_fir_101.csv`.

Modes 4 and 5 consume the internal waveform/ramp state also used by the
CW transition logic. The waveform is multiplied by eight. Identifying
the pair as opposite CW sidebands is HIGH CONFIDENCE, but the exact
keying-envelope timing remains to be recovered.

Mode 6 computes an affine audio value using two initialized parameters
and sends the same initial value into both component paths. Its
AM/carrier interpretation is HIGH CONFIDENCE.

Mode 7:

1. multiplies audio by a deviation parameter;
2. clamps it symmetrically;
3. converts it to a phase increment;
4. evaluates sine and cosine;
5. scales both components by eight.

This is a directly observed angle-modulation algorithm: VERIFIED.

After every branch, two separate FIR objects process the initial
components and produce eight output samples per 12.5 kHz modulation
sample, returning the stream to the 100 kHz domain: HIGH CONFIDENCE.
The resulting 128 complex samples occupy interleaved floating-point
buffer `0x20004190...0x2000458F`: VERIFIED.

## Automatic level control

The handler calculates the magnitude of every complex sample in
`0x20004190`, selects a block peak, and smooths it into state
`0x2000B7CC`. When the new peak is larger, the update is:

`envelope = 0.01 × old + 0.99 × peak`

When it is smaller:

`envelope = 0.995 × old + 0.005 × peak`

Magnitude calculation, peak selection, asymmetric attack/release, and
constants: VERIFIED.

A closed-loop controller maintains a dB-domain attenuation state at
`0x2000B7A8`. Its normal range is clamped to `-40...0 dB`. The firmware
combines that state with another dB correction, converts the result to
a linear multiplier, and applies the same multiplier to I and Q for all
128 samples. Controller topology, limits, conversion, and complex
scaling: VERIFIED. Calling this loop TX ALC is HIGH CONFIDENCE.

`FUN_08024010` supplies the controller target. Its caller logs
`txpower updated`, converts the Linux-facing power byte to floating
point in steps of `0.1`, and passes that value to the function. A target
change resets the attenuation state to `-40 dB`, clears the envelope
and controller error state, and therefore restarts acquisition:
VERIFIED. The exact physical units and calibration of the power target
still need correlation with RF measurements.

Several ADC-derived quantities also enter the controller calculation.
Their arithmetic participation is VERIFIED, but assigning them final
forward-power, reflected-power, or supply-sensor names would require
additional analog-path evidence. Those interpretations remain
HYPOTHESIS.

Direct-reference evidence is exported in
`analysis/tx_filters/tx_output_control_refs.csv`.

## Final I/Q output

After ALC, each interleaved float is independently converted to signed
32-bit fixed point with 31 fractional bits. Before packing, the firmware
adds:

- I-specific integer correction `0x2000B784`;
- Q-specific integer correction `0x2000B788`;
- common integer correction `0x2000BA58` to both components.

The first two values have dedicated one-argument setters and are loaded
from calibration-dependent tables by the main control update:
VERIFIED. Their interpretation as converter DC-offset corrections is
HIGH CONFIDENCE. `0x2000BA58` has no runtime writer outside startup in
this image, so its exact purpose remains HYPOTHESIS.

Each 32-bit result has its two 16-bit halves exchanged before storage.
The 128 packed I/Q pairs are written to the selected I2S3ext transmit
bank through pointer `0x200003D0`. I2S3ext is DMA1 Stream 5 and is
configured for 16-bit DMA transfers, so the halfword exchange preserves
the required serial order for each 32-bit sample. Conversion, additions,
packing, destination, and pair count: VERIFIED.

The selected I2S2ext transmit bank at `0x200003C8` is populated in the
same final loop from a separate audio path. It does not receive the
complex buffer. Thus the final routing is:

| Output | DMA stream | Recovered payload |
| --- | ---: | --- |
| I2S2ext | DMA1 Stream 4 | two related audio-level samples |
| I2S3ext | DMA1 Stream 5 | interleaved 32-bit TX I/Q |

Routing and packing are VERIFIED. The physical devices connected to
the two serial outputs are not named here without board-level evidence.

Additional direct-reference evidence:

- `analysis/tx_filters/tx_iq_output_refs.csv`;
- `analysis/tx_filters/tx_iq_offset_refs.csv`.

## Relationship to RF frequency changes

A frequency/RF-path update requests the separate DSP-history reset
described in `docs/rf_switching.md`. It does not change the TX input
gain at `0x2000B778`. RX/TX transition handling and frequency switching
must therefore remain separate events in an independent
implementation: VERIFIED.

## Reimplementation implications

- Apply RX/TX mode changes at a DSP block boundary.
- Clear mode-dependent histories when dirty bit `0x08` is consumed.
- Sum the two recovered input channels before applying the first TX
  gain.
- Preserve the observed `1.0` and `5.0` routing-dependent gains until
  their physical input sources and codec gains are fully correlated.
- Do not reuse this gain as PA power control or bias.
- Implement the mode switch as complex-baseband generators with
  explicit orientation, not merely as audio routing.
- Preserve the 8:1 rate conversion on both sides of the modulation-rate
  processing.
- Use the exact exported IEEE-754 FIR coefficients when compatibility
  is required; decimal columns are provided for inspection.
- Apply one ALC multiplier equally to I and Q; independent component
  gains would rotate or distort the recovered complex signal.
- Convert final I/Q to signed Q31, add the recovered integer
  calibration corrections, exchange 16-bit halves, and send the result
  through the I2S3ext DMA path.

## Remaining work

- Associate the `1.0` and `5.0` branches with physical audio inputs.
- Determine why the table's nominal 3 kHz selection produces roughly
  `-7.16 dB` at exactly 3 kHz rather than a conventional `-3 dB`
  corner.
- Correlate numeric modes 0–7 with Linux-facing mode names.
- Recover the CW keying-envelope timing for modes 4/5.
- Correlate the ALC ADC inputs and power target with physical RF units.
- Determine the source and exact purpose of common Q31 correction
  `0x2000BA58`.
- Determine whether the inactive zero-gain override is used by another
  firmware version.
