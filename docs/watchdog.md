# Watchdogs and software reset

## Scope and evidence

Direct references were exported for:

- IWDG at `0x40003000`;
- WWDG at `0x40002C00`;
- RCC_CSR at `0x40023874`;
- SCB_AIRCR at `0xE000ED0C`.

The reproducible results are under `analysis/watchdog/`.

Firmware SHA-256:

`3fa11293e06951c21c9cfda04ea08adad85eaadda26b77a8e8bbcca8820c53c4`

## Independent watchdog

No direct reference to any IWDG register was found in the application
image:

- no write-unlock key;
- no start key;
- no reload key;
- no prescaler or reload configuration;
- no status polling.

Absence of application IWDG initialization and refresh: HIGH
CONFIDENCE.

The firmware image does not contain the STM32 option bytes. Therefore
it cannot independently prove whether hardware-start watchdog mode is
disabled in the programmed device. However, this application could not
run normally for long if IWDG were started before entry and never
refreshed. An inactive IWDG in the deployed configuration is therefore
HIGH CONFIDENCE, not VERIFIED from this image alone.

## Window watchdog

No direct reference to WWDG registers was found:

- WWDG is not enabled;
- its counter and window are not configured;
- no early-wakeup interrupt is enabled;
- no refresh write is present.

Absence of application WWDG use: HIGH CONFIDENCE.

The WWDG interrupt vector also points to the default handler rather
than an application handler: VERIFIED.

## Reset-cause handling

No direct access to RCC_CSR was found. The application does not inspect
or clear the POR, pin-reset, software-reset, IWDG-reset, WWDG-reset, or
brownout-reset flags itself: HIGH CONFIDENCE.

Reset-cause processing could still occur in an earlier bootloader,
which is outside the analyzed BASE application image. No conclusion is
made about bootloader behavior.

## SCB AIRCR uses

There are two distinct AIRCR use cases.

### NVIC priority grouping

`FUN_08032400` calls `FUN_0802ded4(0x500)`. The helper writes the
required `0x5FA` key plus the supplied priority-grouping bits to
SCB_AIRCR. It then enables the six active external IRQs through
`FUN_0802dee8`.

Priority-group configuration, rather than reset request: VERIFIED.

The same helper is not a general watchdog or reset-service routine and
should not be named as one.

### Intentional system reset

At the end of `FUN_08034178`, after the ordered GPIO shutdown sequence,
the firmware:

1. disables interrupts through PRIMASK;
2. waits for GPIOG input pin 4 to become high;
3. clears GPIOE output pin 11;
4. waits 100 timer units;
5. executes a data synchronization barrier;
6. preserves AIRCR priority-group bits;
7. writes the `0x5FA` key with `SYSRESETREQ`;
8. executes another barrier;
9. waits forever for reset.

AIRCR value construction and `SYSRESETREQ` use: VERIFIED.

Interpretation as the final stage of a controlled shutdown/restart path
is HIGH CONFIDENCE. Whether external power actually remains present
long enough for the MCU reset to complete depends on the unidentified
GPIO-controlled rails.

## Fault-containment implications

BASE 1.1.9 has no application-level hardware watchdog supervision:
HIGH CONFIDENCE.

Consequently:

- a deadlock in the superloop is not recovered by IWDG/WWDG;
- a hung high-priority interrupt is not recovered by IWDG/WWDG;
- I2C1 has explicit local bus recovery, but this is not a system
  watchdog;
- the final shutdown path uses an explicit Cortex-M system reset rather
  than waiting for a watchdog timeout.

An independent implementation may add watchdog supervision, but doing
so is a deliberate reliability change rather than behavior recovered
from OEM firmware. It must account for long startup calibration,
five-second and three-second shutdown delays, flash operations, and
blocking I2C timeouts before selecting a deadline.

## Remaining work

- Read option bytes from a physical unit to verify IWDG hardware/software
  start configuration.
- Determine whether the bootloader records or consumes RCC reset flags.
- Identify the GPIOG4 condition that gates the final software reset.
- Measure the units used by the final 100-unit delay.
