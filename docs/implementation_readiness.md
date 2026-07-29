# Independent firmware implementation readiness

## Conclusion

The recovered hardware contracts are sufficient to begin controlled
bench bring-up with the PA held disabled: HIGH CONFIDENCE.

They are not yet sufficient for an unattended, antenna-connected
transmitter. The two principal remaining work areas are:

1. complete the receive DSP path;
2. establish PA bias, absolute RF-power calibration, and fast protection
   before enabling normal TX.

Exact names for the `0x4A`/`0x4C` devices, ATU L/C assignment, and
several GPIO nets are not implementation blockers because their
firmware-visible transactions and active behavior are already known.

Machine-readable inventories:

- `analysis/implementation/driver_inventory.csv`;
- `analysis/implementation/readiness_gaps.csv`.

## Safety baseline

First code execution on hardware should meet all of these conditions:

- PA-bias channels remain zero;
- the PA enable tuple remains in its recovered RX/disabled state;
- PE12 remains high;
- PD4 remains low;
- charger output remains disabled until PA6 voltage acquisition is
  validated;
- unknown debounced inputs cannot request TX;
- RF output is connected to a dummy load before any transmit test;
- an external current-limited supply and independent RF-power/SWR
  measurement are used.

The exact RX-disabled tuple and transition order are in
`docs/pa_control.md`. This safety baseline is derived from verified OEM
safe states, but its board-level protection effectiveness is HIGH
CONFIDENCE until physical measurements confirm every net.

## Minimum driver set

### Foundation

| Driver | Minimum contract | Status |
| --- | --- | --- |
| clock/platform | stable MCU clock and recalculated APB/timer rates | contract known; clock choice required |
| GPIO | known alternate functions plus conservative output-safe state | mostly known |
| timebase | short delays and periodic TIM2/TIM3-equivalent services | known |
| diagnostic USART | USART1 115200 8-N-1 | known |

The OEM 250-MHz clock is not a compatibility requirement. A safe clock
is preferable if all baud, timer, I2S/DMA deadline, and DSP scheduling
assumptions are recalculated.

### Board discovery and low-risk services

| Driver | Minimum contract | Status |
| --- | --- | --- |
| I2C1 master | blocking transfer and ten-clock bus recovery | recovered |
| I2C2 master | raw writes and returned probe status | recovered |
| board variant | PCA9535 probe and inactive callback defaults | recovered alternatives |
| MAX17205 | selected registers and recovery writes | recovered |
| charger | policy and hysteresis; initially forced off | recovered |
| ADC/DAC | both scan groups, ADC2 filter, DAC2 staircase | recovered |

### Sample and RF receive path

| Driver | Minimum contract | Status |
| --- | --- | --- |
| TLV320AIC3204 | hardware reset, exact startup, routing and gain | recovered |
| I/Q converter | CS4272 sequence or `0x4C` fallback | recovered |
| auxiliary `0x4A` | exact six-write timeline | recovered |
| four-stream I2S DMA | synchronized double buffers | recovered |
| LO generator | divider calculation and ordered commit | recovered |
| RF switching | variant primary index and shared SPI6 image | recovered |
| RX DSP | input, I/Q correction, frequency shift, all mode demodulators, AGC, and rate graph recovered; coefficients, optional noise reduction, and final mixer incomplete | partial |

The principal RX topology is documented in `docs/rx_pipeline.md`.
Exact RX coefficient exports, any distinct converter-DC removal, the
optional noise-reduction transform, and the final audio mixer remain
functional blockers to a faithful receiver. Hardware acquisition can
still be validated by capturing raw I/Q banks and comparing spectrum,
phase, polarity, gain, and sample cadence off-target.

### Linux integration

| Driver | Minimum contract | Status |
| --- | --- | --- |
| I2C3 slave | register windows, framing, boot handshake | recovered on BASE and current OEM Linux |
| USART6 flow | 4136-byte packet and CRC | recovered; physical baud conflict must be measured |
| BASE IAP | GPIO boot/reset, commands, 1K XMODEM | Linux side recovered; BASE post-transfer exit unresolved |
| control dispatcher | apply only documented register consumers | partially complete |

Linux integration is not required for the first electrical bring-up.
A diagnostic firmware can validate hardware locally, then add the
wire-compatible control service.

### Transmit and optional services

| Driver | Minimum contract | Status |
| --- | --- | --- |
| PTT/key arbitration | verified sources only | physical mapping incomplete |
| PA-bias controller | protocol plus measured transfer function | protocol only |
| TX hardware sequence | exact bias/GPIO ordering | recovered |
| TX DSP/ALC | recovered topology plus calibrated output units | topology recovered |
| RF protection | trustworthy forward/reflected limits | incomplete |
| ATU | fresh VSWR, search, shared SPI6 output | recovered after safe TX exists |

Normal TX must remain compile-time or runtime locked until the PA bias
and RF-protection gates below pass.

## Bring-up sequence

### Phase 0: MCU-only foundation

1. Boot with PA and charger disabled.
2. Assert the recovered PA-off, charger-off, and relay-safe GPIO states
   before initializing nonessential peripherals.
3. Establish a safe clock tree and diagnostic USART.
4. Verify timer rates and delay units against an oscilloscope GPIO.

Exit criteria:

- stable reset and diagnostic output;
- measured timer periods match calculations;
- no unexpected PA, charger, or relay activation.

### Phase 1: bus discovery

1. Probe only documented addresses with their known non-mutating
   transaction; do not use an indiscriminate I2C scan.
2. Read MAX17205 identity/status for diagnostics, even though OEM runtime
   does not validate them.
3. Probe PCA9535 and select the callback backend.
4. Keep every output image at its recovered inactive state.
5. Verify I2C1 stuck-bus recovery without enabling RF hardware.

Exit criteria:

- expected acknowledgements and repeatable register reads;
- ambiguous variant detection fails safe;
- no I2C failure can leave PA or charger enabled.

### Phase 2: analog and sample transport

1. Start ADC DMA and validate PA6 external-voltage scaling.
2. Verify MAX17205 `Batt`, `RepSOC`, `Temp`, and `AvgCurrent`.
3. Initialize TLV320AIC3204 and the CS4272/`0x4C` branch.
4. Measure BCLK/WCLK and confirm both I2S pairs lock.
5. Run the four DMA streams with pass-through or zero-filled output.

Exit criteria:

- stable 128-frame bank cadence with no overrun;
- correct channel ordering and signed 32-bit reconstruction;
- external and battery voltage agree with instruments;
- transmit banks remain electrically inactive.

### Phase 3: receive-only radio

1. Program the LO with TX inhibited.
2. Apply primary and secondary RF indices while preserving shared bits.
3. Capture known RF signals and finish the RX DSP stages.
4. Validate frequency, sideband orientation, gain, and demodulation.

Exit criteria:

- receiver works across every RF switching boundary;
- frequency changes reset DSP histories without stale transients;
- no RX action can assert the TX tuple.

### Phase 4: Linux compatibility

1. Expose the I2C3 control window with strict bounds.
2. Implement the boot-ready handshake.
3. Emit UART flow packets and verify CRC/layout against Linux.
4. Enable control words incrementally, beginning with VFO and receive
   audio controls.

Exit criteria:

- malformed writes cannot escape documented windows;
- packet cadence and metadata match the companion software;
- unknown control fields are preserved or rejected deliberately.

### Phase 5: guarded transmit

1. Establish the PA-bias controller transfer function with the RF chain
   disabled.
2. Calibrate PA0/PA1 forward/reflected measurements against instruments.
3. Implement independent power, current, timeout, and SWR trips.
4. Enable the PA tuple only into a dummy load at minimum power.
5. Validate RX/TX ordering, ALC, every mode, and emergency shutdown.

Exit criteria:

- measured quiescent currents are bounded;
- commanded and measured power are correlated;
- open/high-SWR/load-loss tests remove drive safely;
- no unresolved GPIO input can request TX.

### Phase 6: ATU and productization

1. Enable low-power tune sessions and fresh VSWR handshakes.
2. Validate all ATU bits without needing L/C names.
3. Add independent per-frequency tuner persistence if desired.
4. Verify shutdown GPIO ordering, watchdog option bytes, and reset
   behavior.

## Blocking gaps

### Functional blocker

The receive pipeline still lacks end-to-end documentation for DC
removal, IQ correction, frequency shift, FIR stages, AGC, and
demodulation. Until recovered or independently redesigned, it blocks a
compatible receiver.

### Transmit safety blockers

- PA-bias code-to-current transfer function;
- absolute forward/reflected RF calibration;
- confirmed fast power/SWR protection;
- physical validation of the PA enable tuple and unresolved TX inputs.

These do not block receive-only development. They block normal TX.

### Productization gates

- watchdog option-byte state;
- exact PG4 shutdown condition;
- final safe-state audit for every output;
- validation on each supported board variant.

## Nonblocking unknowns

The following can remain unresolved during initial implementation:

- exact `0x4A` and `0x4C` part identities;
- assignment of ATU banks to inductors or capacitors;
- ATU component values;
- exact names of individual RF relay outputs;
- PF11/PE13 names and early PD3 UI behavior if the OEM pre-Linux
  charging screen is not reproduced;
- the OEM foreground-versus-ISR software organization;
- CW key ratio behavior not implemented by OEM firmware.

Omitting an OEM convenience is acceptable when the hardware remains
safe and the Linux-facing behavior is deliberate and documented.

## Definition of implementation-ready

The repository is ready to begin coding when:

- the hardware map is accepted as the initial board contract;
- PA-off and charger-off startup states are encoded as invariants;
- the selected clock and sample-processing architecture can meet the
  measured DMA deadline;
- receive DSP work is either recovered or explicitly scoped as an
  independent design;
- TX remains gated behind the listed calibration and protection tests.

It is ready for normal radio use only after all Phase 5 exit criteria
pass on physical hardware.
