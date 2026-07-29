# Linux to BASE protocol

## Evidence sources

### BASE firmware

Firmware:

`X6100_BBFW_V1.1.9_251127001.bin`

SHA-256:

`3fa11293e06951c21c9cfda04ea08adad85eaadda26b77a8e8bbcca8820c53c4`

Relevant handlers:

- `I2C3_EV_IRQHandler` at `0x08033990`;
- `I2C3_ER_IRQHandler` at `0x08033B88`.

### Linux reference implementation

Local project:

`X6100Control`

Reviewed revision:

`4159e1142783c3c4f2f196b385721fb3975ee13d`

The project implements the Linux side of a protocol recovered from an
older firmware/UI generation. The repository revision is from 2023;
the association with BASE firmware 1.1.6 was supplied by the project
owner. Its names are therefore historical evidence, not automatically
final names for BASE 1.1.9.

A second, version-matched Linux reference is now available:

`x6100_ui_v100`

It comes from Linux firmware 1.2 and is paired with BASE 1.1.9
according to the project owner. The ELF is not stripped and directly
confirms `/dev/i2c-0`, address `0x72`, current control framing,
`/dev/ttyS1`, and the BASE IAP path: VERIFIED binary evidence. See
`docs/linux_hardware_interface.md` and `docs/base_firmware_update.md`.

## Transports

X6100Control uses two transports:

| Purpose | Linux device | Parameters | 1.1.9 status |
| --- | --- | --- | --- |
| Control register file | `/dev/i2c-0` | slave address `0x72` | VERIFIED in both Linux implementations and BASE |
| IQ and telemetry flow | `/dev/ttyS1` in both reviewed Linux implementations | Linux token: 1,152,000; BASE 1.1.9 initializer: 1,500,000 | VERIFIED path/tokens; unresolved physical-rate conflict |

## I2C control framing

### Single register write

X6100Control transmits a packed six-byte message:

| Byte | Meaning |
| ---: | --- |
| 0 | 16-bit byte address, high byte |
| 1 | 16-bit byte address, low byte |
| 2–5 | 32-bit value, little endian |

The byte address is `command_index * 4`.

The BASE event handler independently confirms that the first received
byte becomes the high address byte and the second becomes the low
address byte. Subsequent bytes are stored sequentially into RAM.

Framing and byte order: VERIFIED for BASE 1.1.9.

The current OEM Linux application independently uses the same framing.
Its read path performs an offset-only write and the read as two
separate `I2C_RDWR` ioctls, with a STOP between them: VERIFIED. BASE
must preserve the selected offset across that STOP.

### BASE I2C3 initialization

`FUN_08033d64` initializes I2C3 at `0x40005C00` with:

| Property | Value |
| --- | ---: |
| Clock rate | 400,000 Hz |
| Own-address field | `0x00E4` |
| 7-bit slave address | `0x72` |
| ACK | enabled |
| Addressing mode | 7 bit |

The STM32 peripheral stores the 7-bit own address shifted left by one,
so `0xE4 >> 1` gives `0x72`. The same function configures PA8 and PC9
for I2C3 alternate function and enables the event/error interrupt path.

I2C3 peripheral and Linux-visible slave-address identification:
VERIFIED.

### Bulk control write

X6100Control initializes or refreshes the complete control file using:

- two address bytes, both zero;
- 56 little-endian 32-bit values;
- total transfer length: 226 bytes.

BASE 1.1.9 initializes its normal I2C write target as:

| Property | Value |
| --- | ---: |
| RAM base | `0x2000C4C8` |
| Length | `0xE0` bytes |
| 32-bit entries | 56 |

The independently recovered size is an exact match for
`x6100_last + 1` in X6100Control.

Existence and size of the 56-entry control register file: VERIFIED.

The 1.1.6 names are not all implemented by BASE 1.1.9. Some slots are
active, some fields are decoded or cached without a consumer, and
thirteen slots are not read by the control updater. Indices 1 and 7 are
traced through the LO synthesizer; see `docs/frequency_control.md`.

The complete 56-slot audit is now in
`analysis/protocol/control_register_audit.csv`. Slots
`18, 19, 26, 30...32, 36...40, 52, 54` have no read in the recovered
BASE 1.1.9 control updater: HIGH CONFIDENCE that they are unused in
this image. Register 16 is different: its low two bytes are copied into
internal state, but no downstream reader was recovered. It is therefore
cached-only rather than proven active.

## Historical control register labels

These names come from X6100Control. Offsets and layout are VERIFIED as
the Linux implementation's wire format. Their semantics in BASE 1.1.9
are currently HIGH CONFIDENCE rather than final symbol names.

| Index | Byte offset | Historical label |
| ---: | ---: | --- |
| 0 | `0x0000` | `vfoa_ham_band` |
| 1 | `0x0004` | `vfoa_freq` |
| 2 | `0x0008` | `vfoa_att` |
| 3 | `0x000C` | `vfoa_pre` |
| 4 | `0x0010` | `vfoa_mode` |
| 5 | `0x0014` | `vfoa_agc` |
| 6 | `0x0018` | `vfob_ham_band` |
| 7 | `0x001C` | `vfob_freq` |
| 8 | `0x0020` | `vfob_att` |
| 9 | `0x0024` | `vfob_pre` |
| 10 | `0x0028` | `vfob_mode` |
| 11 | `0x002C` | `vfob_agc` |
| 12 | `0x0030` | `sple_atue_trx` |
| 13 | `0x0034` | `vi_vm` |
| 14 | `0x0038` | `rxvol` |
| 15 | `0x003C` | `rfg_txpwr` |
| 17 | `0x0044` | `atu_network` |
| 20 | `0x0050` | `ling_loutg_imicg_hmicg` |
| 21 | `0x0054` | `micsel_pttmode_chge_spmode_auxiqgen_sqlthr` |
| 22 | `0x0058` | `voxg_voxag_voxdly_voxe` |
| 23 | `0x005C` | `nrthr_nbw_nbthr_nre_nbe` |
| 24 | `0x0060` | `dnfcnt_dnfwidth_dnfe` |
| 25 | `0x0064` | `cmplevel_cmpe` |
| 27 | `0x006C` | `agcknee_agcslope_agchang` |
| 28 | `0x0070` | `agctime` |
| 29 | `0x0074` | `monilevel` |
| 33 | `0x0084` | `ks_km_kimb_cwtone_cwvol_cwtrain` |
| 34 | `0x0088` | `qsktime_kr` |
| 35 | `0x008C` | unknown historical label; RX complex-shift control |
| 41 | `0x00A4` | `biasdrive_biasfinal` |
| 42 | `0x00A8` | `rit` |
| 43 | `0x00AC` | `xit` |
| 44 | `0x00B0` | `filter1_low` |
| 45 | `0x00B4` | `filter1_high` |
| 46 | `0x00B8` | `filter2_low` |
| 47 | `0x00BC` | `filter2_high` |
| 48 | `0x00C0` | `rphscmp` |
| 49 | `0x00C4` | `rmagcmp` |
| 50 | `0x00C8` | `txiofs` |
| 51 | `0x00CC` | `txqofs` |
| 53 | `0x00D4` | `pwrsync` |
| 55 | `0x00DC` | `last` |

Unlisted entries remain unnamed. They must not be assumed unused
without checking BASE 1.1.9.

### Audio-control fields verified in BASE 1.1.9

The historical names for registers 14, 20, and 21 now correlate with
direct TLV320AIC3204 writes in the current firmware:

| Register | Bits | 1.1.6 name | BASE 1.1.9 effect | Confidence |
| ---: | ---: | --- | --- | --- |
| 14 | 7:0 | `rxvol` | combined HPR analog gain and digital receive-audio scalar | HIGH CONFIDENCE role; VERIFIED thresholds/raw calls |
| 20 | 7:0 | `ling` | right MICPGA gain for IN2R | HIGH CONFIDENCE line input |
| 20 | 15:8 | `loutg` | LOL/LOR gain after subtracting 7 dB | HIGH CONFIDENCE line output |
| 20 | 23:16 | `imicg` | doubled gain code for left MICPGA/IN1L with MICBIAS | HIGH CONFIDENCE built-in microphone |
| 20 | 31:24 | `hmicg` | left MICPGA gain for IN2L without MICBIAS | HIGH CONFIDENCE hand microphone |
| 21 | 1:0 | `micsel` | 0=IN1L/MICBIAS, 1=IN2L, 2=automatic choice | HIGH CONFIDENCE source names; VERIFIED routing |
| 21 | 5 | `spmode` | combine with PF15 jack state; apply 0.05 receive-audio gain when both conditions select it | HIGH CONFIDENCE S/P role; VERIFIED gain path |
| 29 | 7:0 | `monilevel` | convert to `value * 0.01` and use as the TX input-monitor gain in the final audio mixer | HIGH CONFIDENCE role; VERIFIED arithmetic/path |
| 12 | 14 | `modem_trx` | construct operating flag `0x40`, enter TX, and route MAIN/Linux-board audio from IN3R | HIGH CONFIDENCE board source; VERIFIED flag/routing |

The exact register-to-hardware mapping is in
`analysis/i2c/audio_control_register_mapping.csv`. This correlation
supports using the historical field names in an independent Linux
implementation, but does not justify final Ghidra symbol names.

The `spmode` bit does not directly select a TLV320 output or toggle an
output GPIO in BASE 1.1.9. It participates in a debounced condition
with PF15 and changes the receive-audio scalar by a factor of `0.05`.
The detailed path is exported in
`analysis/i2c/audio_spmode_path.csv`.

The remaining register-21 fields have now been audited:

| Bits | Historical label | BASE 1.1.9 behavior |
| ---: | --- | --- |
| `2...3` | `pttmode` | cached as a two-bit value; no reader recovered |
| 4 | `chge` | set/clear bit 0 of persistent word `0x2000E984` |
| 6 | `auxiqgen` | on either edge, call a variant output with constant 1 |
| `8...15` | `sqlthr` | unsigned squelch threshold converted directly to float |

Extraction and the listed operations are VERIFIED. The `pttmode`
effective role remains HYPOTHESIS because the cached byte has no
recovered downstream reader.

Bit 4 does not directly toggle a charger GPIO in this update path. It
modifies the persisted control bit that startup also reads while
initializing the board and battery-management subsystem: VERIFIED.
The runtime manager consumes the cached bit as an enable policy and
drives the selected board backend through active-low PCA9535 bit 1
and/or active-high PF12, subject to external-power and 90/98 capacity
hysteresis: HIGH CONFIDENCE role; VERIFIED data flow, levels, and
thresholds. The ordered contract is documented in `docs/charger.md`.

Bit 6 does not forward the requested zero/one state. Whenever its
value differs from the cached value, firmware calls the selected board
callback with the constant argument 1. One backend sets PCA9535 bit 15;
the other sets PD15: VERIFIED. Startup initially calls the same
callback with 0 and later with 1. The historical `auxiqgen` name is
therefore only a HYPOTHESIS for the physical net.

The squelch helper stores the byte as an unscaled floating-point
threshold and separately records whether it is positive. Zero disables
the recovered detector; positive values enable comparison with
hysteresis in the DMA audio path: VERIFIED.

Bits 7 and `16...31` have no observed effect in the update block:
HIGH CONFIDENCE. Exact field behavior is exported in
`analysis/protocol/register21_audio_misc.csv`.

IN3R is identified as the MAIN/Linux-board playback path with HIGH
CONFIDENCE by correlation with `x6100_base_patch` commit `4413870` and
the `x6100_gui` platform-sound playback path. This is an endpoint
assignment, not a VERIFIED schematic-net name.

## Semantics verified in BASE 1.1.9

### Registers 1 and 7: VFO frequencies

Addresses: `0x0004` and `0x001C`

`FUN_0802af0c` selects the A or B six-word VFO record and consumes the
32-bit field at record offset `+0x04` as a frequency in hertz. It
applies operating offsets and passes the result into the LO frequency
path. Register locations and selection behavior: VERIFIED. Hertz unit:
HIGH CONFIDENCE.

The main LO device is on I2C1 at 7-bit address `0x6A`, not among the
I2C2 devices at `0x10`, `0x4A`, or `0x4C`. The complete trace is in
`docs/frequency_control.md`.

### Registers 4 and 10: VFO modes

Addresses: `0x0010` and `0x0028`

The historical X6100Control enum maps values 0...7 to `LSB, LSB_DIG,
USB, USB_DIG, CW, CWR, AM, NFM`. All four mode families independently
match the recovered BASE 1.1.9 transmit algorithms. Preservation of
this numeric enumeration is HIGH CONFIDENCE. See
`docs/tx_pipeline.md`.

### Register 15: RF gain and TX-power target

Address: `0x003C`

The historical `rfg_txpwr` label is confirmed field by field in BASE
1.1.9.

The low byte is an RF-gain command. In the active hardware path
(`FUN_0803147c` returns the constant 1), the firmware implements this
piecewise transfer:

| `rfg` input | Six-bit serial output | DSP scalar |
| ---: | ---: | ---: |
| `0...36` | `0x3F` | `10^((0.5*rfg - 18)*0.05)` |
| `37...100` | `100-rfg` | `1.0` |
| `101...255` | `0x00` | `1.0` |

The six-bit value is shifted through PC5/PB0 and latched with PB1 by
`FUN_0802cf88`: VERIFIED. The serial bits therefore control an
external stepped RF gain/attenuation network: HIGH CONFIDENCE. Exact
gain contribution of each physical bit remains unknown. The scalar is
applied in the DSP path through `FUN_08023dd8`: VERIFIED.

Bits `8...15` are converted to floating point, multiplied by `0.1`,
and supplied to `FUN_08024010`. That function resets and configures the
closed-loop TX output controller described in `docs/tx_pipeline.md`.
Packing, scale, and controller routing are VERIFIED; the historical
`txpwr` label is HIGH CONFIDENCE because absolute RF-power calibration
is not yet recovered.

Bits `16...19` are passed to `FUN_08023db8`. Inputs `0...3` produce the
one-hot byte `1 << value`; inputs `4...15` are clamped to index 4 and
produce `0x10`. The byte is stored at `0x200089DE`: VERIFIED. Its
downstream DSP or hardware meaning is not yet resolved, so the field
must not be given a final name. Bits `20...31` have no observed effect
in the register-15 update block: HIGH CONFIDENCE.

The exact transfer is exported in
`analysis/protocol/register15_rfg_txpwr.csv`.

### Register 13: active VFO and calibration band

Address: `0x0034`

Bit 0 selects the normal active VFO record: zero selects VFO A and one
selects VFO B. The firmware then derives active and inactive record
pointers from this bit; register 12 split control may exchange them
during an ordinary TX: VERIFIED selection, HIGH CONFIDENCE A/B labels.
Bits `1...7` are ignored by this consumer: HIGH CONFIDENCE.

Bits `8...15` select a frequency-dependent calibration entry. When the
index changes, BASE loads:

- two signed calibration values, multiplies each by `5000`, and stores
  them as the I and Q integer offsets added immediately before the
  final SPI3/I2S3 sample packing;
- one signed value scaled by `0.0001`, then converted to a multiplicative
  correction by adding `1.0`;
- one signed value scaled by `0.001`, clamped to `-60...+60`, converted
  to radians, and expanded into sine/cosine correction state;
- the raw band index into the DSP control state.

Table addressing, constants, final I/Q offset additions, and
trigonometric conversion are VERIFIED. Interpreting the latter two
values as magnitude and phase correction is HIGH CONFIDENCE.

The historical Linux implementation computes indices `0...22` from
frequency, covering out-of-band gaps and amateur bands through
54 MHz. BASE performs no range check before indexing its calibration
arrays: VERIFIED. A compatible controller must restrict this byte to
`0...22`; larger values can read beyond the intended entries.

Bits `16...31` have no observed effect in the register-13 update block:
HIGH CONFIDENCE. The mapping is exported in
`analysis/protocol/register13_vi_vm.csv`.

### Register 17: ATU network

Address: `0x0044`

Bits `0...6` and `8...14` hold two seven-bit matching-network banks;
bit 16 selects one of two network topologies. Packing is VERIFIED.
Electrical assignment of the banks to inductors and capacitors remains
unresolved; see `docs/atu.md`.

### Register 23: noise reduction and noise blanker

Address: `0x005C`

The noise-reduction fields consumed by BASE 1.1.9 are:

| Bits | Historical label | Effect |
|---:|---|---|
| `0...7` | `nrthr` | unsigned threshold, capped to 100 |
| `24` | `nre` | enable the 256-point overlapped spectral processor |

Field extraction, clamp, and enable routing are VERIFIED. The recovered
FFT framing, estimator, spectral gain, passband-bin selection, and
output ring are documented in `docs/rx_pipeline.md`.

The remaining historical noise-blanker fields are decoded separately
from `FUN_08022C30`; they must not be conflated with the spectral
noise-reduction path.

The full consumer audit found no later reader for the decoded
noise-blanker width, threshold, or enable fields. Only `nrthr` and
`nre` have an effective path in BASE 1.1.9: HIGH CONFIDENCE that the
noise-blanker controls are not implemented in this image.

### Register 22: VOX controls

Address: `0x0058`

The updater decodes:

| Bits | Historical label | BASE action |
| ---: | --- | --- |
| `0...6` | `voxg` | copy to internal state |
| `7...13` | `voxag` | copy to internal state |
| `14...25` | `voxdly` | sign-extend the 12-bit field into internal state |
| 26 | `voxe` | copy to internal state |

No downstream reader of those decoded fields was recovered. The
complete call graph also contains no call that sets TX-source mask
`0x20`, historically associated with VOX. Field extraction is
VERIFIED; VOX having no runtime effect in BASE 1.1.9 is HIGH
CONFIDENCE.

### Register 24: digital notch filter

Address: `0x0060`

| Bits | Historical label | BASE action |
| ---: | --- | --- |
| `0...11` | `dnfcnt` | unsigned notch center frequency |
| `12...23` | `dnfwidth` | unsigned width/Q control, clamped to `1...100` |
| 24 | `dnfe` | enable the resulting RX biquad |

`FUN_0802415C` designs the biquad at the common RX audio sample rate.
It constrains the center value to between 1% and 40% of that rate,
applies the width clamp, and writes five coefficients. The DMA RX
handler conditionally executes this biquad after demodulation and
common filtering. Extraction, coefficient path, enable, and placement
are VERIFIED; interpreting the center value in hertz and the
historical DNF labels are HIGH CONFIDENCE.

### Register 25: compressor controls

Address: `0x0064`

The low nibble is copied as historical `cmplevel`; bit 4 is copied as
historical `cmpe`. Neither decoded field has a recovered downstream
reader, and no compressor enable/gain transfer from this state appears
in the DMA handler. Extraction is VERIFIED; no runtime compressor
effect in BASE 1.1.9 is HIGH CONFIDENCE.

### Registers 27 and 28: AGC controls

Register 27 at `0x006C` decodes the signed low byte (`agcknee`), the
next byte (`agcslope` storage), and bit 12 (`agchang`). The first two
values are passed to functions that immediately return without writing
state: VERIFIED no-op behavior. Bit 12 is stored and controls whether
the RX AGC waits through its hang counter before increasing gain:
VERIFIED.

Register 28 at `0x0070` packs three time values:

| Bits | Use |
| ---: | --- |
| `0...9` | time constant used for AGC mode 1 |
| `10...19` | decoded middle time constant; no active selection branch |
| `20...31` | time constant used for AGC mode 2 |

`FUN_08023F50` selects the applicable value according to AGC mode and
derives the gain-recovery coefficient. Other AGC modes use fixed
mode-dependent constants. Packing, selection, and coefficient path are
VERIFIED.

### Register 33: CW controls

Address: `0x0084`

Bits `12...22` are a tone frequency in hertz. Bits `23...28` are the CW
monitor-level field, converted to linear gain by division by 320. These
uses confirm the historical `cwtone` and `cwvol` labels: VERIFIED
fields and arithmetic, HIGH CONFIDENCE labels. The fixed RF and monitor
envelopes are documented in `docs/tx_pipeline.md`.

Bits `0...7` set keyer element timing; bits `8...9` select manual or
automatic paddle handling, including a swapped-paddle mode; bits
`10...11` select iambic behavior. Bit 29 is training mode and suppresses
RF keying while retaining the monitor. Algorithms are VERIFIED;
historical `ks`, `km`, `kimb`, and `cwtrain` labels are HIGH CONFIDENCE.

### Register 34: QSK hold and key ratio

Address: `0x0088`

The low 16 bits are the raw RF-key hold count, consumed once per
128-frame DMA block. At the recovered 100 kHz rate, one count is
`1.28 ms`: VERIFIED arithmetic and scheduling; historical `qsktime`
label HIGH CONFIDENCE.

The upper 16 bits are decoded as `value × 0.1`, consistent with the
historical key-ratio field, but BASE 1.1.9 does not apply the decoded
value to its keyer. The active ratio remains fixed at startup value
`3.0`: HIGH CONFIDENCE. See `docs/tx_pipeline.md`.

### Register 35: RX complex-shift control

Address: `0x008C`

This register was absent from the historical X6100Control enumeration,
so no historical field name is assigned.

`FUN_0802AF0C` decodes it as:

| Bits | BASE use | Confidence |
|---:|---|---|
| `0...23` | sign-extended signed shift value `n` | VERIFIED |
| `24` | complex-shift bypass flag | VERIFIED |
| `25...31` | no consumer in this update block | HIGH CONFIDENCE |

The decoded fields are forwarded through two single-assignment helpers:

- `FUN_08024404(bit24)` writes byte `0x2000BF71`;
- `FUN_08024418(sign_extend(raw & 0x00FFFFFF))` writes signed word
  `0x2000BF74`.

The DMA RX handler executes the rotator only when bit 24 is zero.
Therefore the verified polarity is:

| Bit 24 | Effect |
|---:|---|
| `0` | rotator path enabled |
| `1` | rotator bypassed |

`n=0` produces no frequency shift even when the path is enabled.
For nonzero `n`, the handler uses one signed-hertz step per integer at
the recovered 100-ksample/s processing rate: HIGH CONFIDENCE physical
unit, VERIFIED arithmetic. See `docs/rx_pipeline.md` for the equations
and the separate CW oscillator.

### Register 41: PA bias codes

Address: `0x00A4`

The low 16 bits are copied to external bias-control channel 0 and the
high 16 bits to channel 1. Channel 0 is associated with the PA drive
stage and channel 1 with the final stage: VERIFIED packing and channel
routing; HIGH CONFIDENCE stage identities.

The device is on I2C1 at address byte `0xC6` (7-bit address `0x63`).
The transaction framing and the complete ordered RX/TX hardware
sequence are documented in `docs/pa_control.md`.

### Registers 44...47: RX filter edges

Addresses:

| Register | Address | Historical label |
|---:|---:|---|
| 44 | `0x00B0` | `filter1_low` |
| 45 | `0x00B4` | `filter1_high` |
| 46 | `0x00B8` | `filter2_low` |
| 47 | `0x00BC` | `filter2_high` |

All four values are copied as signed 32-bit frequency edges.
`FUN_080240B4` sets an RX filter-dirty flag whenever any value changes:
VERIFIED.

SSB/CW use the two low values for cascaded postdemodulation high-pass
sections and the two high values for cascaded low-pass sections. AM
instead derives its two predemodulation component low-pass cutoffs as
the maximum absolute low edge and minimum absolute high edge. NFM
does not use the four values in its recovered filter selection.
Branches, signed/absolute operations, and routing are VERIFIED. See
`docs/rx_pipeline.md` for objects, rates, and table-index calculation.

### Registers 48...51: live DSP corrections

These registers override the corresponding band-selected calibration
values:

| Register | Historical label | Conversion and destination |
| ---: | --- | --- |
| 48 | `rphscmp` | signed value × `0.001`, RX phase correction |
| 49 | `rmagcmp` | signed value × `0.0001`, RX magnitude correction |
| 50 | `txiofs` | signed value × `5000`, TX I Q31 offset |
| 51 | `txqofs` | signed value × `5000`, TX Q Q31 offset |

Indexing, signed conversions, setters, and final DSP consumers are
VERIFIED. Historical semantic labels are HIGH CONFIDENCE.

### Register 53: power-synchronization setting

Address: `0x00D4`

X6100Control historical label: `pwrsync`

BASE 1.1.9 detects changes and copies the complete 32-bit value into
its internal control cache. No subsequent reader of that cached field
has yet been recovered: VERIFIED copy behavior, unknown effective
semantics.

The synthesizer independently adjusts output 4 around 2 MHz to avoid
tuned-frequency harmonics. Correlation of that clock with the board
`PSYNC` signal is HIGH CONFIDENCE, but correlation of register 53 with
the clock remains MEDIUM CONFIDENCE. See `docs/frequency_control.md`.

### Register 12: operation flags

Address: `0x0030`

X6100Control historical label: `sple_atue_trx`

`FUN_0802adf4` reads bit `0x00002000` from this register while running
an ATU-related sequence and waits for the bit to clear before returning.
X6100Control assigns the same bit to `x6100_atu_tune`.

Register 12 bit `0x00002000` means ATU tune active/requested: VERIFIED.

Register 12 bit `0x00040000` is copied through
`FUN_0802D7CC(0x1, state)` into TX-source bit 0. That source requests
transmit in `FUN_0802A8A4`: VERIFIED. X6100Control calls the register
bit `iptt`; internal/software PTT is therefore HIGH CONFIDENCE.

The complete set of bits consumed by the BASE 1.1.9 update block is:

| Bit | Historical label | Recovered BASE effect |
| ---: | --- | --- |
| 1 | `sple` | select the other VFO record during ordinary TX |
| 3 | `voice_rec` | suppress TX and switch the audio/DSP routing |
| 4 | `swrscan_trx` | set TX-source mask `0x200` |
| 12 | `atue` | select ATU-network application or bypass |
| 13 | `atu_tune` | execute the blocking ATU tune transaction |
| 14 | `modem_trx` | set TX-source mask `0x40` and route IN3R |
| 15 | `calibration_trx` | set TX-source mask `0x100` |
| 16 | `power_off` | request the ordered GPIO shutdown path |
| 18 | `iptt` | set TX-source mask `0x01` |

Bit extraction and the listed control-flow effects are VERIFIED.
Historical labels are HIGH CONFIDENCE except `atu_tune`, whose
Linux/BASE handshake is VERIFIED. No other bit has a direct consumer
in this update block: HIGH CONFIDENCE.

Bit 16 makes `FUN_0802AF0C` return true and terminates the main control
loop in `FUN_08034178`; it is not a direct write to one GPIO. The
bit-to-control-flow edge is VERIFIED. The subsequent ordered GPIO,
rail-delay, PG4-feedback, and system-reset contract is documented in
`docs/shutdown.md`.

The split bit selects the inactive VFO only during an ordinary
transmission. ATU (`0x10`) and calibration (`0x100`) TX sources retain
the normal active VFO: VERIFIED.

The tune bit has command-like behavior. Firmware clears bit 13 in its
internal mirror before calling `FUN_0802adf4`; that function performs
the ATU operation and finally waits until Linux clears bit 13 in the
live control register: VERIFIED. A compatible Linux controller must
therefore deassert the request; it must not leave `atu_tune` set.

The machine-readable mapping is
`analysis/protocol/register12_operation_bits.csv`.

### Register 55: Linux boot handshake

Address: `0x00DC`

X6100Control historical label: `last`

`FUN_0802d7e8` returns register 55. During early boot,
`FUN_08032500` repeatedly checks bit `0x00100000`; when it becomes set,
the preliminary service loop exits, I2C3 is temporarily shut down, and
the main initialization path continues. X6100Control initializes
register 55 to `0x00100001`.

Register 55 bit `0x00100000` is a Linux-to-BASE boot-ready/continue
handshake: VERIFIED.

The meaning of register 55 bit 0 remains unknown.

## I2C direction-dependent address spaces

The same 16-bit address selects different RAM windows depending on
transfer direction.

### Linux writes to BASE

| Address range | BASE destination | Size/wrapping | Confidence |
| --- | --- | --- | --- |
| normal addresses | `0x2000C4C8` | `0xE0` bytes, circular | VERIFIED |
| `0xF000–0xFFFD` | `0x2000C190` | `0x330` bytes, circular | VERIFIED |
| `0xFFFE–0xFFFF` | `0x2000E7E4` | `0x100` bytes, circular | VERIFIED |

The exact accepted normal-address bounds still need a simplified
control-flow proof; the table records the destinations selected by the
observed branches.

### Linux reads from BASE

| Address range | BASE source | Behavior | Confidence |
| --- | --- | --- | --- |
| `0x0000–0x007F` | `0x2000E8E4` | 128-byte circular window | VERIFIED |
| `0x0080–0x00FF` | — | returns zero | HIGH CONFIDENCE |
| `0x0100–0x0FFF` | `0x2000C190` | `0x330`-byte circular window | VERIFIED |
| `0xF000–0xFFFD` | `0x2000C190` | aliased circular window | VERIFIED |
| `0xFFFE–0xFFFF` | — | returns constant `0x61` | HIGH CONFIDENCE |

### Firmware-identification response

The `0x0000–0x007F` read window is a 128-byte circular
firmware-identification buffer at `0x2000E8E4`.

During startup, `candidate_main`:

1. copies seven bytes of `V1.1.9` to offsets `0x00–0x06`;
2. formats the build date and time as `%s,%s`;
3. copies the 32-byte formatting buffer to offsets `0x07–0x26`.

For the analyzed image the meaningful response bytes therefore begin:

```text
V1.1.9Nov 27 2025,10:31:57\0
```

The destination is zero-initialized before those copies, and I2C reads
wrap modulo 128. Buffer purpose, construction, and BASE 1.1.9 contents:
VERIFIED.

### Calibration-data window

The shared `0x2000C190` window contains the BASE calibration block, not
ordinary runtime telemetry. Both I2C read ranges `0x0100–0x0FFF` and
`0xF000–0xFFFD` address it modulo `0x330`; Linux writes through the
`0xF000–0xFFFD` range.

| Property | Value | Confidence |
| --- | ---: | --- |
| RAM base | `0x2000C190` | VERIFIED |
| Size | `0x330` bytes | VERIFIED |
| Word count | 204 | VERIFIED |
| Word 0 | magic `0xAA5555AA` | VERIFIED |
| Words 1–202 | calibration payload | VERIFIED layout |
| Word 203 | CRC of words 0–202 | VERIFIED |
| CRC initial value | `0xFFFFFFFF` | VERIFIED |
| CRC processing | non-reflected, table-driven, four steps per word | VERIFIED |
| CRC polynomial | `0x04C11DB7` | HIGH CONFIDENCE |
| Primary flash copy | `0x08004000` | VERIFIED |
| Legacy/migration copy | `0x080E0000` | VERIFIED |

`FUN_08033ef4` validates the primary flash copy, falls back to the
legacy address and migrates it when valid, or creates a zeroed default
block when neither copy passes magic and CRC validation. Two early
payload values are clamped to `0xAF0` and `0xCE4`.

The runtime consumers recover the following used layout. Here `b` is
the register-13 calibration-band index `0...22`:

| Words | Count | Conversion | Role | Confidence |
| ---: | ---: | --- | --- | --- |
| 1 | 1 | raw 16-bit code | drive-stage PA bias control | HIGH CONFIDENCE role; VERIFIED use |
| 2 | 1 | raw 16-bit code | final-stage PA bias control | HIGH CONFIDENCE role; VERIFIED use |
| `3 + 2b` | 23 | signed × `0.0001` | RX magnitude correction | HIGH CONFIDENCE role; VERIFIED indexing/scale |
| `4 + 2b` | 23 | signed × `0.001` | RX phase correction | HIGH CONFIDENCE role; VERIFIED indexing/scale |
| `103 + 2b` | 23 | signed × `5000` | TX I integer offset correction | HIGH CONFIDENCE role; VERIFIED indexing/scale |
| `104 + 2b` | 23 | signed × `5000` | TX Q integer offset correction | HIGH CONFIDENCE role; VERIFIED indexing/scale |

The electrical current transfer functions of words 1 and 2 remain
unknown. Words 49...102 and 149...202 have no recovered runtime
consumer in BASE 1.1.9; they remain reserved/unknown and must be
preserved.

The exact word/byte layout is exported in
`analysis/protocol/calibration_field_layout.csv`; dynamic-index
evidence is in
`analysis/protocol/calibration_consumers_decompile.txt`.

## UART flow evidence from X6100Control

The historical Linux implementation expects packets containing:

- magic `0xAA5555AA`;
- 512 `_Complex float` IQ samples;
- TX/charger/external-power flags;
- TX power, VSWR, ALC, voltage, battery, ATU, and key telemetry;
- CRC32 using polynomial `0x04C11DB7`;
- typical packet interval near 35 ms.

This is VERIFIED behavior of the reviewed X6100Control revision.

## UART flow in BASE 1.1.9

`FUN_080337fc`, called by `TIM2_IRQHandler`, builds and schedules the
flow packet. `FUN_08032fc8` configures DMA2 Stream 6 to transmit it
through the USART6 data register at `0x40011404`.

| Property | BASE 1.1.9 evidence |
| --- | --- |
| Packet base | `0x200003F8` |
| Magic offset | `0x0000` |
| Magic value | `0xAA5555AA` |
| IQ sample area | offset `0x0004`, length `0x1000` |
| IQ sample count | 512 complex 32-bit-float pairs |
| Metadata/telemetry | follows the IQ area |
| CRC input length | `0x409` words = 4132 bytes |
| CRC offset | `0x1024` |
| Total DMA length | `0x1028` = 4136 bytes |
| CRC engine | STM32 hardware CRC at `0x40023000` |
| CRC configuration | reset through `CRC_CR = 1`, then 32-bit words written in order |
| Peripheral | USART6 |
| DMA | DMA2 Stream 6 |

The total size, magic, sample count, metadata placement, and CRC
placement exactly match `x6100_flow_t` in X6100Control.

### Packet layout

The following byte layout is independently present in BASE 1.1.9.
Historical field names are retained where the producer behavior agrees
with X6100Control; no firmware symbols have been renamed from these
labels.

| Offset | Size | Field | BASE evidence | Confidence |
| ---: | ---: | --- | --- | --- |
| `0x0000` | 4 | magic | constant `0xAA5555AA` | VERIFIED |
| `0x0004` | `0x1000` | 512 complex-float IQ samples | copied by `FUN_08023c88` | VERIFIED |
| `0x1004` | 4 | flags | snapshot of accumulator at `0x20001420` | VERIFIED |
| `0x1008` | 1 | reserved | retained by packet builder | VERIFIED |
| `0x1009` | 1 | TX power, `0.1 W` | `TIM3_IRQHandler` saturates `FUN_0802442c() * 10` to 8 bits | HIGH CONFIDENCE unit; VERIFIED packing |
| `0x100A` | 1 | VSWR, tenths | `TIM3_IRQHandler` saturates `FUN_08024454() * 10` to 8 bits | HIGH CONFIDENCE |
| `0x100B` | 1 | dimensionless ALC indicator | controller linear gain mapped to approximately 1...100; X6100Control displays × 0.1 | HIGH CONFIDENCE meaning; VERIFIED arithmetic/packing |
| `0x100C` | 1 | external voltage | ADC2-derived internal value × `0.01`; tenths of a volt | VERIFIED path; HIGH CONFIDENCE unit |
| `0x100D` | 1 | battery voltage | MAX17205 `Batt` millivolts × `0.01`; tenths of a volt | VERIFIED |
| `0x100E` | 1 | battery capacity | integer conversion of MAX17205 `RepSOC` | VERIFIED |
| `0x100F` | 1 | reserved | copied with the preceding three bytes | VERIFIED layout |
| `0x1010` | 4 | ATU parameters | topology and two seven-bit bank values supplied by the ATU sequence; high byte retained | VERIFIED |
| `0x1014` | 12 | reserved | no packet-builder writes observed | HIGH CONFIDENCE |
| `0x1020` | 4 | hardware key code | decoded from the PD12/TIM4 PWM-input frame and cleared after timeout | VERIFIED path/format; HIGH CONFIDENCE headset role |
| `0x1024` | 4 | CRC32 | CRC over the preceding `0x409` words | VERIFIED |

Immediately before building the CRC, `FUN_080337fc` calls
`FUN_0802e0bc`, which writes `1` to `CRC_CR` at `0x40023008`.
`FUN_0802e0cc` then writes exactly `0x409` consecutive 32-bit packet
words to `CRC_DR` at `0x40023000` and returns the final `CRC_DR` value:
VERIFIED. Thus the flow CRC uses the STM32 hardware engine with its
reset/default polynomial behavior; the presence of a software
`0x04C11DB7` table elsewhere in the image is not evidence for this
packet path.

X6100Control interprets the voltage bytes in tenths of a volt and TX
power in tenths of a watt. `FUN_08024010` independently establishes
watts by converting the control target to dBm as
`10*log10(target*1000)`: HIGH CONFIDENCE physical unit; VERIFIED
conversion. VSWR is a dimensionless ratio in tenths. The ALC byte is a
dimensionless indication of the controller's linear gain, displayed by
the historical client with an additional factor of `0.1`.

External voltage at `0x100C` originates specifically from PA6:
ADC2 channel 6 → filtered ADC2 getter index 0 → multiplication by
`4.835165` → internal state `0x200000F0` → multiplication by `0.01` →
flow byte. Every software step and address in this path is VERIFIED;
the external-supply interpretation and tenths-of-a-volt unit are HIGH
CONFIDENCE. See `docs/analog.md`.

The three low bytes of `atu_params` are the tune result in order:
topology, direct-bank value, permuted-bank value. The reverse control
path is register 17. BASE publishes a result but does not persist it in
the analyzed image; see `docs/atu.md`.

### Flow flags

`FUN_08033974(mask, state)` is the sole observed modifier of the
32-bit flag accumulator. Its callers establish:

| Mask | Historical label | BASE 1.1.9 behavior | Confidence |
| ---: | --- | --- | --- |
| `0x00000001` | resync | no setter call observed | HYPOTHESIS: unused |
| `0x00000002` | TX | set and cleared by the RX/TX hardware-switching path | VERIFIED |
| `0x00000004` | charger enabled | cleared around ATU operation, then restored | HIGH CONFIDENCE |
| `0x00000008` | external power present | follows the same state that supplies external/battery voltage telemetry | HIGH CONFIDENCE |
| `0x00000010` | charging active | controlled by battery-management thresholds and charger GPIO state | HIGH CONFIDENCE |

Mask `0x10` is present in BASE 1.1.9 but absent from the historical
four-bit X6100Control declaration. Linux implementations should preserve
and expose the complete 32-bit flags word rather than assuming that only
bits 0–3 can be set.

Reusable evidence exports:

- `analysis/flow/packet_tail_refs.csv`;
- `analysis/flow/metadata_source_refs.csv`;
- `analysis/flow/metadata_setter_callers.csv`;
- `analysis/flow/hkey_setter_callers.csv`.

UART flow packet compatibility between the reviewed historical
implementation and BASE 1.1.9: VERIFIED.

### Baud-rate conflict

Both X6100Control and the current OEM `x6100_ui_v100` configure
`/dev/ttyS1` with the Linux termios value for 1,152,000 baud:
VERIFIED historical source and VERIFIED current numeric token.

In BASE 1.1.9, `FUN_08033210` initializes:

- USART1 at 115,200 baud;
- USART6 at 1,500,000 baud.

The flow producer uses USART6. The BASE initializer and both Linux
clients therefore disagree even though the current OEM application is
paired with BASE 1.1.9. This is an unresolved physical-rate conflict,
not a verified version difference. Measure the shipped UART and verify
the exact target termios and BASE clock/divisor behavior before choosing
a compatibility rate.

## Remaining work

- Correlate the remaining control words with BASE-side consumers.
- Determine the meanings of the read and special I2C windows.
- Recover the exact meaning and scaling of every UART metadata field.
- Compare command additions or changed bitfields between 1.1.6 and 1.1.9.
