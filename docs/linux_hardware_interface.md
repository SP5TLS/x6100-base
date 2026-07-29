# Linux application hardware interface

## Scope and source

This document covers only direct hardware access recovered from:

`x6100_ui_v100`

The ELF is ARM EABI5, dynamically linked, and not stripped. It contains
a full static symbol table but no DWARF sections. Its MD5 is
`9017e6c2175dccb432b0ba3d84f480db`.
Its SHA-256 is
`f0f154b754b2d68a448a5e06dde4a040e57fd2b1c1d305d64b470e4aaf98d427`.

The application came from Linux firmware 1.2 and is paired with BASE
1.1.9 according to the project owner. This provenance is user-supplied;
the function addresses, device paths, constants, and call sequences
below are independently VERIFIED from the ELF.

The audit deliberately excludes GUI, DSP, networking, database, and
audio APIs. Machine-readable results are in:

- `analysis/linux_app/hardware_interfaces.csv`;
- `analysis/linux_app/base_update_sequence.csv`;
- `analysis/linux_app/xmodem_1k_contract.csv`.

## Hardware summary

| Purpose | Linux interface | Recovered parameters | Confidence |
| --- | --- | --- | --- |
| BASE control register file | `/dev/i2c-0` | 7-bit address `0x72`; `I2C_RDWR` | VERIFIED |
| BASE IQ/telemetry flow and IAP | `/dev/ttyS1` | raw 8-bit serial; termios speed token `0x1009` | VERIFIED |
| Software CW and IAP strap | `gpiochip0`, line 203 | active-low output | VERIFIED |
| BASE IAP reset pulse | sysfs GPIO 204 | high, then low | HIGH CONFIDENCE reset role; VERIFIED sequence |

No other direct GPIO, I2C, or UART interface belongs to the BASE
hardware layer in this application. `/dev/ttyS2` is referenced by a
separate UART client and is not passed to `xradio_create`: VERIFIED.

## I2C control transport

`MainWidget` calls `xradio_create("/dev/i2c-0", 0x72)` at
`0x000649E0`: VERIFIED. This directly confirms the BASE 1.1.9 I2C3
slave address already recovered from STM32 `OAR1 = 0x00E4`.

The Linux object stores the device path, file descriptor, and 7-bit
address. `ui2c_write` at `0x00072414` constructs one Linux
`i2c_msg` and issues `ioctl(fd, 0x0707, ...)`, the `I2C_RDWR`
request. Its byte stream is:

1. 16-bit byte offset, high byte first;
2. zero or more payload bytes without byte-order conversion.

For example, a normal 32-bit control register write sends a two-byte
big-endian offset followed by the four little-endian bytes already
present in host memory: VERIFIED.

`ui2c_read` at `0x0007269C` is not a combined repeated-start
transaction. It first invokes `ui2c_write(offset, NULL, 0)`, producing
an offset-only two-byte write in one `I2C_RDWR` ioctl, then performs a
second one-message read ioctl: VERIFIED. A compatible BASE slave must
retain the selected offset across the STOP between these transactions.

The normal control publisher (`thread_remote_admin`, `0x0008F9D0`):

- compares one of 55 cached 32-bit words per iteration;
- writes a changed word at offset `index * 4`;
- advances the index modulo `0x37`;
- refreshes the complete `0xE0`-byte, 56-word window at offset zero
  every 1000 active iterations;
- sleeps 1 ms between active iterations.

This behavior and transfer sizes are VERIFIED. The 55-word
change-scanner versus 56-word bulk refresh is an observed asymmetry,
not a documentation error.

The public helpers also expose:

- an `0x80`-byte read at offset zero;
- arbitrary offset/length reads and writes;
- command payload writes at special offset `0xFFFE`.

These operations exactly match the BASE-side windows documented in
`docs/protocol.md`: VERIFIED.

## UART transport

`xradio_create` passes `/dev/ttyS1` and termios token `0x1009` to
`uart_create`: VERIFIED. The UART is configured with input/output speed
`0x1009`, eight data bits, raw input/output/local modes, no parity, and
no hardware flow control: VERIFIED constants; HIGH CONFIDENCE 8-N-1
interpretation.

Under Linux UAPI termios definitions, token `0x1009` is `B1152000`.
The application therefore requests 1,152,000 baud: HIGH CONFIDENCE,
because the numeric token is VERIFIED but the target libc headers are
not present in the ELF.

This conflicts with the explicit 1,500,000-baud initializer recovered
from BASE 1.1.9. Both observations are retained. It is not yet safe to
claim either that the shipped pair uses different physical baud rates
or that one side's clock/constant has been interpreted incorrectly.
The actual line rate must be measured or checked against the exact
target Linux headers/clock configuration: unresolved.

The UART worker reopens the stored path and reads the `0x1028`-byte
BASE flow packets used for IQ and telemetry. The same file descriptor
is temporarily suspended and reused by the IAP/XMODEM updater:
VERIFIED.

## GPIO 203: CW and IAP strap

`MorseSender::slot_worker` opens `gpiochip0`, requests line offset
`0xCB` (203) as an output initially high, and generates active-low
Morse pulses:

- dot: low for one element;
- dash: low for three elements;
- intra-element high gap: one element;
- character gap: three additional elements;
- word gap: seven elements.

Line number, active level, and timing sequence: VERIFIED. The default
element duration in the constructor is 30 ms: VERIFIED.

The IAP entry routine independently exports legacy sysfs GPIO 203 and
holds it low across a reset pulse. The exact shared use establishes
that line 203 is both the Linux software-CW output and the BASE
boot-mode strap at reset: HIGH CONFIDENCE functional interpretation;
VERIFIED shared line and levels.

This is consistent with a single inter-board signal reaching a normal
BASE key input during runtime and being sampled as a boot condition
during reset. The exact schematic net name remains unknown.

## GPIO 204: IAP reset pulse

The update routine exports GPIO 204, configures it as output, drives it
high, waits 100 ms, drives it low, and unexports it. BASE then emits
its IAP greeting over the UART. GPIO 204 is therefore the BASE reset
control with HIGH CONFIDENCE; exact levels and ordering are VERIFIED.

No ordinary runtime GPIO-204 consumer was found in the audited
hardware layer.

## Reimplementation implications

- Use I2C address `0x72`, not the BASE-side master-device addresses
  `0x10`, `0x4A`, or `0x4C`.
- Preserve the STOP-separated offset-write/read transaction.
- Serialize I2C access; the OEM application protects every public
  operation with one mutex.
- Treat GPIO 203 as a shared CW/IAP resource and leave it high when
  idle.
- Do not fix the Linux/BASE UART baud conflict by assumption; measure
  the shipped hardware first.
- Use `docs/base_firmware_update.md` for the complete IAP protocol.
