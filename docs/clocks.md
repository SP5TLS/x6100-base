# Clock tree

## Scope

This document records the clock initialization recovered from BASE
firmware `X6100_BBFW_V1.1.9_251127001.bin`.

No symbols were renamed. The relevant functions retain their Ghidra
names:

- `SystemInit` at `0x0803485C`;
- `FUN_08031480` at `0x08031480`;
- `FUN_080348b0` at `0x080348B0`.

## Reset-time state

`SystemInit` resets the main RCC configuration before the C runtime is
entered:

- `RCC_CFGR = 0`;
- `RCC_PLLCFGR = 0x24003010`;
- the HSI remains the system-clock source;
- `SCB_VTOR = 0x08020000`.

Immediately after entering `candidate_main`, `FUN_080348b0` computes
and stores a 16,000,000-Hz core clock from that reset state.

Reset-time use of the 16-MHz HSI: VERIFIED.

## Application clock setup

`FUN_080317b4`, called during application initialization, invokes
`FUN_08031480`. The latter performs the following sequence:

1. enables HSE and waits for `HSERDY`;
2. enables the PWR peripheral clock;
3. enables the two over-drive control bits in `PWR_CR`;
4. programs the AHB/APB prescalers;
5. writes `0x04403C0C` to `RCC_PLLCFGR`;
6. enables the main PLL and waits for `PLLRDY`;
7. writes `0x00000705` to `FLASH_ACR`;
8. selects PLL as SYSCLK and waits until the status field reports PLL;
9. calls `FUN_080348b0` to update the core-clock variable.

Sequence and register constants: VERIFIED.

## PLL decoding

`RCC_PLLCFGR = 0x04403C0C` decodes as:

| Field | Value | Confidence |
| --- | ---: | --- |
| PLL source | HSE | VERIFIED |
| PLLM | 12 | VERIFIED |
| PLLN | 240 | VERIFIED |
| PLLP | 2 | VERIFIED |
| PLLQ | 4 | VERIFIED |

`FUN_080348b0` uses 25,000,000 Hz when HSE or an HSE-sourced PLL is
selected. This is direct evidence that the firmware is compiled for a
25-MHz HSE.

Firmware HSE assumption: VERIFIED.

With that source frequency, the configured tree is:

| Clock | Calculation | Frequency |
| --- | --- | ---: |
| PLL input | 25 MHz / 12 | 2.083333 MHz |
| PLL VCO | PLL input × 240 | 500 MHz |
| SYSCLK | PLL VCO / 2 | 250 MHz |
| HCLK/core | SYSCLK / 1 | 250 MHz |
| PCLK1 | HCLK / 4 | 62.5 MHz |
| APB1 timer clock | PCLK1 × 2 | 125 MHz |
| PCLK2 | HCLK / 2 | 125 MHz |
| APB2 timer clock | PCLK2 × 2 | 250 MHz |
| PLLQ output | PLL VCO / 4 | 125 MHz |

The prescalers follow from `RCC_CFGR` bits set by the firmware:

- HPRE = divide by 1;
- PPRE1 = divide by 4;
- PPRE2 = divide by 2.

After switching to PLL, `FUN_080348b0` stores `250000000` at
`0x200033A4`, the recovered `SystemCoreClock` storage.

The firmware's intended 250-MHz core clock: VERIFIED.

The physical MCU actually operating at 250 MHz: HIGH CONFIDENCE,
conditional on the expected 25-MHz oscillator and successful HSE/PLL
lock. This frequency is an apparent overclock relative to the nominal
STM32F427 maximum and must not be treated as a generally safe
replacement-firmware setting without hardware validation.

## Flash and power settings

`FLASH_ACR = 0x00000705` selects:

- five flash wait states;
- prefetch;
- instruction cache;
- data cache.

The clock setup also enables the STM32F4 over-drive control sequence
before starting the PLL. Register settings: VERIFIED.

## Implementation consequence

Timing constants in the OEM firmware can depend on the non-standard
250-MHz core, 62.5-MHz APB1, and 125-MHz APB2 clocks. An independent
implementation does not need to reproduce the overclock, but it must
recalculate baud rates, timer periods, and DSP scheduling when choosing
a different safe clock tree.

## Reproducible evidence

- `analysis/clocks/rcc_core_refs.csv`;
- `analysis/clocks/clock_setup_callers.csv`;
- `analysis/startup/startup_call_1_0803485c_disassembly.txt`.
