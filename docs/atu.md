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
- Do not invent an OEM hard-trip threshold; none is supported by the
  recovered ratio consumers.

## Remaining work

- Recover the tuner relay bit mapping.
- Reconstruct the complete search and acceptance algorithm.
- Identify whether protection exists in hardware or another firmware
  component.
