# Antenna-tuner measurement path

## Scope

This document records the recovered use of the fast VSWR measurement
by the automatic antenna-tuner code in BASE 1.1.9. Relay-search
algorithms and persistent tuner memories remain to be reconstructed.

## Immediate VSWR getter

`FUN_08024468(timeout)` waits for the DSP handler to publish a fresh
measurement flag at `0x2000B73A`, clears the flag, and returns the
current ratio at `0x2000B760`. If the timeout expires, it returns the
latest ratio anyway. Wait/clear/return behavior: VERIFIED.

This differs from telemetry getter `FUN_08024454`, which returns the
qualified display value at `0x2000B768`. Both originate in the same
directional-detector calculation, but the tuner deliberately consumes
the immediate value: VERIFIED.

All direct callers of `FUN_08024468` belong to the function cluster
under `FUN_0802A1B8`. They repeatedly change bit fields sent through
the board-control callback, wait, obtain fresh ratios, and compare the
new result with the preceding/best result. This is a relay-search
optimizer for an antenna matching network: HIGH CONFIDENCE.

Caller evidence is exported in
`analysis/atu/vswr_measurement_callers.csv`.

## Tune-session wrapper

`FUN_0802ADF4` wraps the search in a complete transmit session:

1. saves/changes operating controls;
2. sets the TX-power target to `5.0`;
3. enables control bit `0x10`;
4. requests TX through the normal RX/TX handoff;
5. waits 100 ticks and runs `FUN_0802A1B8`;
6. waits 500 ticks;
7. restores the previous power target and control state;
8. requests RX and publishes the resulting tuner state.

Sequence and constants: VERIFIED. X6100Control 1.1.6 names bit `0x10`
of the corresponding Linux control register `swrscan_trx`. That is
supporting historical evidence for the measurement-session
interpretation, not proof that every 1.1.9 register label is unchanged.

## Network representation

The best candidate is stored at `0x2000BF88` in this layout:

| Offset | Width | Meaning |
| ---: | ---: | --- |
| `+0` | 32 bits | best measured VSWR multiplied by 10 |
| `+4` | 8 bits | first seven-bit relay bank |
| `+5` | 8 bits | second seven-bit relay bank |
| `+6` | 8 bits | binary network-topology selection |

Offsets and value domains: VERIFIED. Calling the two bytes relay banks
is HIGH CONFIDENCE from their one-bit-at-a-time board-output mapping
and use by the matching search. Assigning either bank the final label
`L` or `C` is not yet justified.

Linux register 17, historically named `atu_network` by X6100Control
1.1.6, packs the same state as:

- bits `0...6`: direct relay bank;
- bits `8...14`: permuted relay bank;
- bit `16`: topology selection.

The direct bank maps logical bits 0...6 to board-control bits 0...6.
The other bank maps its logical bits to board-control bits
`21,16,15,14,17,18,19`. Topology maps to board-control bit 20.
Packing and output-bit permutation: VERIFIED. The exact relay coils
and component values need board evidence.

The complete mapping is exported in
`analysis/atu/relay_bit_mapping.csv`.

## Search algorithm

`FUN_08028E48` performs the initial search. It clears the network and
tests both topology values. For each topology it evaluates both
seven-bit banks using the nine coarse patterns:

`0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x30, 0x40`

The table contents, nested search, topology iteration, and retention of
the lowest result are VERIFIED. Exact initialized table words are
exported in `analysis/atu/coarse_scan_patterns.csv`.

Measurements are converted to integer tenths. Candidate validation
waits for repeated fresh readings, takes three readings for an average,
and can retry the average up to five times when it differs too far from
the preceding result. Sampling structure and retry counts: VERIFIED.
This is a noise/stability guard: HIGH CONFIDENCE.

If the best coarse result is still at least `2.0`, `FUN_0802993C`
performs a local multi-step search around the selected candidate. Its
signed step table is:

`1, -1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10`

It retains only candidates that improve the best validated measurement
and limits each bank to `0...127`: VERIFIED. The table is exported in
`analysis/atu/search_tables_words.csv`.

`FUN_080290E0` then performs a final directional sweep around the
candidate, independently refining the two banks. It explores up to ten
positions in either direction, respects the `0...127` limits, and can
stop early once the measured VSWR reaches `1.5` or better. Search
radius, bounds, ordering, and threshold: VERIFIED.

After applying the winning network, the tune result state is `1` when
the best VSWR is at most `3.0`, otherwise `3`. Numeric states and
threshold: VERIFIED; final user-facing names for states 1 and 3 remain
unassigned.

## Application and persistence

Control bit `0x1000`, historically `atue` in X6100Control, selects
whether the configured network is active. When it is clear,
`FUN_0802A168` clears both seven-bit relay banks. When it is set,
`FUN_0802A014` expands register 17 into both banks plus the topology
bit and sends the resulting board-control word through the output
callback. Enable/bypass behavior and register application: VERIFIED.

At the end of a tune session, `FUN_0802ADF4` reads the winning topology
and two bank bytes from `0x2000BF8E`, `0x2000BF8D`, and `0x2000BF8C`.
It passes the three bytes to `FUN_0803394C`, which stores them at
`0x2000142D...0x2000142F`. The flow-packet builder publishes those
bytes in the 32-bit `atu_params` field: VERIFIED.

The complete direct-reference set for `0x2000BF88...0x2000BF8F`
contains only the tuner search, its three getters, and the tune-session
publisher. No BASE function copies the result into flash, a
frequency-indexed table, or control register 17. Absence of internal
persistence in the analyzed BASE 1.1.9 image: HIGH CONFIDENCE.

The winning relays remain physically applied after the search, while
the three-byte logical result is reported to Linux. Persistent
per-frequency storage, if supported by the complete radio, is therefore
the responsibility of Linux-side software or another component:
HIGH CONFIDENCE.

Direct-reference evidence is exported in
`analysis/atu/tune_result_refs.csv`.

## SWR protection status

The complete direct-reference set for the current ratio
`0x2000B760` contains:

- writes and reads inside the DSP handler;
- reads by `FUN_08024468`;
- startup initialization.

No direct consumer compares the ratio and then disables TX or a PA
control. The DSP does use the directional-detector results in its ALC
feedback, so load mismatch can affect output regulation. A separate
hard SWR trip based on this ratio was not found: HIGH CONFIDENCE for
the analyzed BASE 1.1.9 image.

This is not evidence that the complete radio lacks protection:
hardware protection, another controller, or a threshold derived from a
different signal remain possible. Therefore no final `SWR protection`
symbol is assigned.

## Reimplementation implications

- Give the tuner a fresh-measurement handshake rather than sampling the
  displayed VSWR field asynchronously.
- Preserve the dedicated low-power TX session and restore the previous
  user power after tuning.
- Preserve the two seven-bit banks and topology bit as separate logical
  fields; do not expose the permuted board-output word as the public
  network representation.
- Treat `atu_params` as the result-notification path and register 17 as
  the path for reapplying a stored network.
- Reproduce coarse selection, validated measurements, local refinement,
  and final directional sweep as distinct phases.
- Do not invent an OEM hard-trip threshold; none is supported by the
  recovered ratio consumers.

## Remaining work

- Assign the two banks to inductors/capacitors and recover component
  values from schematic or measurement.
- Name tune result states 1 and 3 from an independent consumer.
- Locate the Linux-side owner of any per-frequency tuner memory.
- Identify whether protection exists in hardware or another firmware
  component.
