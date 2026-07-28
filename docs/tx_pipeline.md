# Transmit DSP pipeline

## Scope

This document is an incremental reconstruction of the BASE 1.1.9
transmit path. It currently covers RX/TX mode handoff, input conversion,
the first digital gain, and transition-state clearing. Modulation, ALC,
and final output scaling remain under investigation.

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
as the TX audio band-pass edges is HIGH CONFIDENCE. These coefficients
are generated in RAM rather than copied from a fixed flash array.

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
The resulting complex samples continue into level control, correction,
and output stages not yet documented here.

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

## Remaining work

- Associate the `1.0` and `5.0` branches with physical audio inputs.
- Reproduce and verify the runtime-generated 300/3000 Hz biquad
  coefficients independently.
- Correlate numeric modes 0–7 with Linux-facing mode names.
- Recover the CW keying-envelope timing for modes 4/5.
- Recover ALC and final TX output scaling.
- Determine whether the inactive zero-gain override is used by another
  firmware version.
