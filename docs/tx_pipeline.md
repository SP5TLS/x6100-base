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
| 0, 1 | audio history/delay plus FIR-derived quadrature component; identical DSP orientation for both values | LSB / LSB_DIG, HIGH CONFIDENCE |
| 2, 3 | same construction with I/Q roles exchanged relative to 0/1; identical orientation within the pair | USB / USB_DIG, HIGH CONFIDENCE |
| 4, 5 | internally generated/keyed waveform; final complex orientation is exchanged between values | CW / CWR, HIGH CONFIDENCE |
| 6 | `carrier_offset + audio × depth`; identical values feed both initial components | AM, HIGH CONFIDENCE |
| 7 | audio is clipped, scaled into phase deviation, then converted to a `sin/cos` complex pair | NFM, HIGH CONFIDENCE; angle-modulation algorithm VERIFIED |
| other | both components are zero | VERIFIED |

The numeric mode selection and signal-processing behavior are VERIFIED.
The user-facing names are correlated with the X6100Control 1.1.6 enum.
That historical enum assigns exactly `LSB, LSB_DIG, USB, USB_DIG, CW,
CWR, AM, NFM` to values 0...7. Its two sideband pairs, keyed pair, AM,
and NFM all independently agree with the BASE 1.1.9 algorithms:
HIGH CONFIDENCE that the enumeration is unchanged.

This cross-version correlation is not used to rename Ghidra symbols.
The evidence table is exported in
`analysis/tx_filters/mode_mapping.csv`.

For modes 0–3, the firmware uses a 100-sample circular history and a
101-tap quadrature FIR helper. One component is delayed by 50 samples
while the other is filtered, then both are multiplied by eight. The
coefficient array at `0x0803E130` is exactly antisymmetric with a zero
center tap and zero sum to exported precision, matching a Hilbert
transformer. Delay, history length, FIR use, coefficient properties,
orientation swaps, and scaling: VERIFIED. Exact values are in
`analysis/tx_filters/quadrature_fir_101.csv`.

Modes 4 and 5 consume the internal waveform/ramp state also used by the
CW transition logic. The waveform is multiplied by eight. A later
mode-specific path exchanges sine/cosine placement between values 4
and 5, consistent with the historical CW/CWR pair: HIGH CONFIDENCE.

Startup generates a 120-element half-cosine ramp:

`ramp[i] = (1 - cos(pi × i / 119)) / 2`, for `i = 0...119`

Formula, length, endpoints, and monotonic direction: VERIFIED. The RF
keyed-waveform branch advances or reverses one table position per
12.5 kHz modulation sample. The ramp contains 120 sample values; its
two endpoints are 119 sample intervals apart, or `9.52 ms`: VERIFIED.

A separate index applies the same ramp to the CW monitor oscillator in
the 100 kHz output loop. That monitor rise/fall spans 120 samples, or
119 intervals between endpoints, or `1.19 ms`: VERIFIED. The unequal
RF and monitor timings follow directly from their different processing
rates; they are not inferred from a single shared counter.

The monitor phase increment is:

`phase_step = tone_hz × 2 pi / 100000`

Register 33 bits `12...22` supply `tone_hz`. Its startup default is
800 Hz, producing phase step `0.0502654836` radians/sample. Register 33
bits `23...28` supply monitor level, converted to linear gain by
`value × 0.003125` (`value / 320`). Field extraction, setters, formula,
and defaults: VERIFIED. The historical X6100Control field labels
`cwtone` and `cwvol` agree with these consumers: HIGH CONFIDENCE.

Exact recovered parameters are summarized in
`analysis/tx_filters/cw_envelope_parameters.csv`; direct state
references are in `analysis/tx_filters/cw_envelope_refs.csv`.

### CW key-state generator

The DMA handler invokes `FUN_0802145C` once per completed 128-frame
block. Its input callback `FUN_080312F4` returns the three-bit state at
`0x2000C6D8`. `FUN_08031300(mask, state)` is the only writer and
atomically sets or clears selected bits: VERIFIED.

The three input bits have these algorithmic roles:

| Bit | Recovered use | Interpretation |
| ---: | --- | --- |
| 0 | first paddle input | dot/dash identity depends on key mode |
| 1 | second paddle input | dot/dash identity depends on key mode |
| 2 | immediately asserts the key without element generation | straight/manual key, HIGH CONFIDENCE |

`FUN_0802A8A4` constructs these bits only while the active mode is 4 or
5. Bits 0 and 1 come from two control-state flags. Bit 2 is synthesized
from additional control and transition flags. Thus the CW processor
consumes a software-aggregated key state, not a GPIO register directly:
VERIFIED.

TIM3 supplies the upstream flags from active-low GPIO descriptors:

| CW role | Stable flag | MCU pin | Debounce |
| --- | ---: | --- | ---: |
| paddle input 0 | `0x200001AA` | PF14 | 1 TIM3 tick |
| paddle input 1 | `0x200001BE` | PF13 | 1 TIM3 tick |
| latched immediate-key source | `0x200001D2` | PA11 | 1 TIM3 tick |
| immediate-key source | `0x200001FA` | PD0 | 1 TIM3 tick |

GPIO ports, masks, active-low polarity, debounce counts, stable flags,
and their CW consumers: VERIFIED. `FUN_0802A8A4` copies PF14/PF13
directly to key-state bits 0/1. It forms bit 2 from PD0 or a latched PA11
transition after both paddles are released: VERIFIED.

PF14 and PF13 are therefore the two paddle inputs: HIGH CONFIDENCE.
PD0 and PA11 participate in the immediate-key/PTT path, but assigning
either one a final connector label such as straight key, microphone
PTT, or accessory PTT requires schematic or connector measurements.
Those physical labels remain HYPOTHESIS.

The keyer structure begins at `0x200082EC`. Its byte at `+9`
(`0x200082F5`) drives the monitor envelope, while byte `+10`
(`0x200082F6`) drives the RF envelope. In normal operation the RF state
can remain asserted for a programmable hold interval after the monitor
key releases. Separate monitor/RF outputs and hold behavior: VERIFIED.

Register 33 fields control the generator:

| Bits | Recovered behavior | Historical label correlation |
| --- | --- | --- |
| `0...7` | element timing input clamped to `5...100` | key speed / WPM, HIGH CONFIDENCE |
| `8...9` | value 0 passes inputs manually; automatic modes generate elements; value 2 swaps paddle bits | manual / auto-left / auto-right, HIGH CONFIDENCE |
| `10...11` | changes behavior when both paddles are held and elements alternate | iambic A/B, HIGH CONFIDENCE |
| `29` | forces RF-key output low while leaving monitor-key generation active | CW training, VERIFIED behavior; label HIGH CONFIDENCE |

For the speed field `w`, `FUN_08024318` calculates the element counter:

`count = clamp(380000 / (clamp(w, 5, 100) × 390.625), 1, 1000)`

Formula and constants: VERIFIED. The historical WPM interpretation is
HIGH CONFIDENCE. Assigning exact wall-clock element duration also
depends on the keyer invocation schedule; the observed DMA-block call
is VERIFIED.

Automatic mode alternates the two element types, retains paddle memory,
and applies a separate length multiplier to one type. This is an
iambic keyer algorithm: HIGH CONFIDENCE. Runtime mode value 1 enables
an additional remembered opposite element after a squeeze transition,
consistent with historical iambic B; value 0 omits that behavior,
consistent with iambic A: HIGH CONFIDENCE.

### QSK hold and element ratio

Register 34 low 16 bits are sign-extended and written to
`0x20008308`. While the monitor key is active, the keyer reloads its RF
hold counter from this value. After monitor release it decrements the
counter once per DMA block before clearing the RF-key state: VERIFIED.

At 100 kHz and 128 frames per completed block, one count corresponds to
`1.28 ms`. Therefore the nominal additional RF hold is:

`hold_ms = max(raw_signed_16, 0) × 1.28`

Count handling is VERIFIED; the time follows from the VERIFIED block
size and sample rate. The historical `qsktime` label is HIGH
CONFIDENCE. Values above `32767` become negative in BASE because of
the sign extension and do not produce a long hold: VERIFIED edge case.

The upper 16 bits are converted to floating point and multiplied by
`0.1`, matching X6100Control's historical key-ratio representation.
However, the result remains only in the main control structure.
No writer transfers it to the keyer ratio at `0x20008314`: HIGH
CONFIDENCE from the complete direct-reference set.

The active keyer ratio is initialized to `3.0` and is then only read
indirectly by `FUN_0802145C`. Consequently BASE 1.1.9 generates the
second element at three times the first-element duration regardless of
register 34's upper half: HIGH CONFIDENCE. This appears to be an
unimplemented or disconnected control field, not permission to remove
the field from a compatible protocol.

Field and state evidence:

- `analysis/tx_filters/cw_keyer_fields.csv`;
- `analysis/tx_filters/cw_key_input_refs.csv`;
- `analysis/tx_filters/cw_control_loop_callers.csv`;
- `analysis/tx_filters/cw_gpio_mapping.csv`;
- `analysis/tx_filters/cw_gpio_descriptor_data.csv`;
- `analysis/tx_filters/cw_gpio_descriptor_refs.csv`;
- `analysis/tx_filters/cw_upstream_flag_refs.csv`;
- `analysis/tx_filters/cw_upstream_extended_refs.csv`;
- `analysis/tx_filters/cw_qsk_ratio_refs.csv`.

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

ADC1 channels 0 and 1 feed identically calibrated directional-detector
paths. Channel 0 supplies the published TX-power value; channels 0 and
1 form the published VSWR ratio `(F+R)/(F-R)`. Their interpretation as
forward and reflected RF detectors is HIGH CONFIDENCE, with the
arithmetic and telemetry routing VERIFIED. ADC1 channel 2 supplies a
clamped `1...20` correction multiplier to the ALC feedback calculation;
its physical identity remains unknown. Exact formulas and qualification
logic are documented in `docs/analog.md`.

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
- Correlate PF13/PF14/PA11/PD0 with external connector contacts and
  distinguish straight key from PTT sources.
- Compare the disconnected key-ratio field with other BASE versions.
- Recover the absolute RF-power calibration unit and identify the
  physical role of ADC1 channel 2.
- Determine the source and exact purpose of common Q31 correction
  `0x2000BA58`.
- Determine whether the inactive zero-gain override is used by another
  firmware version.
