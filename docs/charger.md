# Charger and battery-management contract

## Scope

This document describes the firmware-visible behavior needed for an
independent implementation. It intentionally does not assign an exact
part number to the charger or battery-pack controller.

The two relevant routines are the early service loop
`FUN_08032500` and the runtime controller `FUN_0802d878`. The exact
state machine and GPIO lifecycle are exported in:

- `analysis/charger/charger_runtime_state_machine.csv`;
- `analysis/charger/charger_gpio_lifecycle.csv`;
- `analysis/charger/battery_telemetry_fields.csv`.

## Linux policy control

Linux register 21 bit 4, historically named `chge`, is copied into
state byte `0x2000003E` and bit 0 of persistent word `0x2000E984`.
The update handler itself performs no GPIO write: VERIFIED.

The bit is an enable policy, not an unconditional output level. The
runtime battery manager combines it with external-power detection,
capacity thresholds, and the current charger state before changing the
hardware: HIGH CONFIDENCE semantic role; VERIFIED data flow.

## Battery telemetry transaction

Every 5000 calls the runtime routine alternates between acquiring a
battery block and evaluating charger state. The acquisition is an I2C1
combined write/repeated-start/read:

```
address byte = 0x6C (7-bit address 0x36)
register     = 0x00
destination  = 0x2000BF90
length       = 0x200 bytes
```

Transaction parameters and ordering are VERIFIED. The decoded fields
used by this routine are:

| Offset | Conversion | Firmware use | Confidence |
| ---: | --- | --- | --- |
| `0x0C` | unsigned 16-bit × `0.0039` | capacity compared with 90 and 98 | VERIFIED arithmetic; HIGH CONFIDENCE quantity |
| `0x10` | signed 16-bit ÷ `256` | published telemetry | VERIFIED arithmetic; HYPOTHESIS quantity |
| `0x16` | signed 16-bit × `0.15625` | published telemetry | VERIFIED arithmetic; HYPOTHESIS quantity |
| `0x1B4` | unsigned 16-bit × `1.25` | battery-voltage-like value | VERIFIED arithmetic; HIGH CONFIDENCE quantity |

ADC2 source 0 is separately multiplied by `4.835165` and treated as an
external-supply-voltage-like value: VERIFIED arithmetic; HIGH
CONFIDENCE physical interpretation.

The exact meanings of the two signed telemetry fields remain unknown.
An independent implementation should preserve their signed arithmetic
and scaling without inventing names.

## Runtime charger state machine

The following decisions are VERIFIED:

1. If `chge` is zero, disable charging.
2. If `chge` is one but external power is absent, disable charging.
3. If charging is inactive, external power is present, and capacity is
   below 90, enable charging.
4. Once active, retain charging below 98.
5. At capacity 98 or above, disable charging.

Thus 90/98 form start/stop hysteresis. Between 90 and 98 the previous
charger state is retained: VERIFIED.

External-power state has a separate 500-unit voltage hysteresis. When
the state is absent, `battery < external + 500` sets it present. When
the state is present, `external < battery + 500` clears it. The
comparisons and ordering are VERIFIED; identifying the two scaled
values as battery and external supply is HIGH CONFIDENCE.

The charger decision uses the existing external-power state and updates
that state afterward. A compatible implementation must preserve this
one-evaluation ordering if exact OEM transition timing matters:
VERIFIED.

## Physical actuation

Each enable or disable transition performs these operations:

1. call board-variant callback slot `0x2000C6C8` with the requested
   state;
2. call `FUN_08030140` with the same state;
3. directly set or clear PF12;
4. publish the charging-active flag through `FUN_08033974`.

The callback has two verified backends:

| Backend | Enabled | Disabled | Confidence |
| --- | --- | --- | --- |
| PCA9535-compatible expander bit 1 | low | high | VERIFIED |
| direct PF12 | high | low | VERIFIED |

PF12 and expander bit 1 therefore implement the board-variant charger
enable, with opposite electrical polarity: HIGH CONFIDENCE role;
VERIFIED operations and levels. The unconditional direct PF12 write
means that the expander-backed variant also updates the PF12 output
latch.

`FUN_08030140` is exactly a two-byte `bx lr` stub in BASE 1.1.9. It has
no hardware effect and must not be mistaken for a second charger
device command: VERIFIED. It appears to be a reserved hook:
HYPOTHESIS.

No charger-programming register writes were found in the runtime state
transition. The firmware-visible control contract is a binary enable
line, not a recovered current/voltage programming protocol: VERIFIED
within the analyzed call paths.

## Early boot/service loop

`FUN_08032500` temporarily establishes this charger-related state:

1. configure PF11 and PF12 as outputs, PE13 and PG4 as inputs, and PD3
   and PD4 as outputs;
2. drive PF11 high, PF12 low, and PD4 low;
3. load persistent policy bit 0, defaulting to enabled when the stored
   configuration is invalid;
4. when enabled, initialize the selected board backend, apply the
   policy to PF12 and callback `0x2000C6C8`, and enter the service loop;
5. periodically read an early battery object and report `CHARGING` or
   `FULL`;
6. classify full when the recovered capacity-like value is at least
   `1800.0` or PE13 is low;
7. toggle PD3 on charging samples and force PD3 high in the full state;
8. leave PF11 high on exit.

GPIO configuration, levels, calls, comparisons, and ordering are
VERIFIED. PE13 is an input to the early full decision, not the charger
enable. Its exact electrical source is unresolved.

PF11 is written as an output; it is not read by this loop. Its physical
net remains HYPOTHESIS. PD3 is demonstrably reused during this early
phase even though normal operation drives it as the receive-side member
of the complementary PD3/PD4 pair. Whether the early toggling indicates
charge status, deliberately cycles a receive rail, or reflects an
incomplete board-level interpretation is unresolved: VERIFIED overlap;
HYPOTHESIS alternatives.

PF13 has no charger role. It is consumed by the TIM3 telegraph-key
input path: VERIFIED separation.

## Independent implementation guidance

A compatible implementation needs:

- the register-21 `chge` policy bit and persistent default;
- the I2C1 `0x36` block read and exact field scaling;
- external-power and 90/98 capacity hysteresis;
- the selected active-low expander-bit or active-high PF12 backend;
- charging-active telemetry publication.

Exact part names are unnecessary. PE13, PF11, and the early PD3 reuse
should remain descriptively named until board measurements establish
their nets.
