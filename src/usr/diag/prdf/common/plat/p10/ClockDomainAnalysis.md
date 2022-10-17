# P10 Clock Domain Error Analysis for PRD

## Registers

The following is a summary of the registers that are referenced in this document
with links to the P10 SCOM def. Note that all of these register will be captured
in the PRD error logs referenced in this document.

### `TP_LOCAL_FIR` [01040100][]: TP chiplet local FIR

All attentions referenced in this document will be routed through this register.
**Reminder:** PRD must have an active FIR attention in order to react to a
hardware event.

### `FSI_STATUS` [1007][]: FSI status register

This requires a CFAM operation to access and is **not** accessible by PRD in
HBRT nor during Hostboot on the master processor. Therefore, while it contains
good information regarding RCS and PLL errors, it is not a reliable source for
PRD isolation. Fortunately, the information that PRD needs is available in
other registers. PRD will capture this register for FFDC when possible.

### `xx_PCBSLV_ERROR` [xx0f001f][]: PCB slave error registers

These registers contain information regarding active PCB slave parity errors and
PLL unlock errors, which feed directly into `TP_LOCAL_FIR[28]`. There is one
instance of these registers in each P10 chiplet (TP, N0, N1, PCI 0-1, MC 0-4,
PAU 0-4, IOHS 0-7, and EQ 0-7).

Any bit set in `xx_PCBSLV_ERROR[24:31]` will indicate an active PLL unlock on
the associated chiplet. The bit definition of this range can vary per chiplet.
Note that `xx_PCBSLV_ERROR[24:31]` for the TP chiplet is mirrored into
`FSI_STATUS[20:27]`.

These are "write-to-clear" registers, which mean writing a `1` to any bit will
tell the hardware to clear that bit.

### `BC_OR_PCBSLV_ERROR` 470f001f: Broadcast OR of the PCB slave error registers

This is a virtual register that does not exist in the SCOM def. Reading this
virtual register returns a bitwise OR of all the `xx_PCBSLV_ERROR` registers.
This is a quick way to determine if **any** chiplet is reporting a specific
error type. Subsequently, writing this register will write the same value to all
`xx_PCBSLV_ERROR` registers, which provides a quick way to clear a specific
error type in all chiplets.

### `xx_PCBSLV_CONFIG` [xx0f001e][]: PCB slave config registers

These registers configure errors reported in the `xx_PCBSLV_ERROR` registers,
such as masking certain error types. Just like the `xx_PCBSLV_ERROR` registers,
there is one instance of these registers in each P10 chiplet. Unlike the
`xx_PCBSLV_ERROR` registers, there is **not** an associated virtual broadcast
register. Therefore, PRD must iterate each chiplet if it needs to mask a
specific error type.

### `RCS_SENSE_1` [0005001D][]: RCS Sense 1 register

RCS clock error attentions and RCS unlock detect attentions are reported via
`RCS_SENSE_1[0:3]`, which are also mirrored to `TP_LOCAL_FIR[42:45]` and
`FSI_STATUS[12:15]`. `RCS_SENSE_1[12:13]` will indicate which of the two clocks
is currently the primary. `RCS_SENSE_1[16]` indicates if a clock has switched
over to another.

This register is **read-only**. To clear clock errors, PRD must toggle (set
high, then set low) the corresponding bits in `ROOT_CTRL5[6:7]`. Note that this
will clear the corresponding bits in `RCS_SENSE_1[0:3]` and `RCS_SENSE_1[16]`.

### `ROOT_CTRL3` [00050013][]: Root Control 3 register

When transient error recovery fails, PRD will use this register to enable the
alternate ref clock mode. See details below.

### `ROOT_CTRL5` [00050015][]: Root Control 5 register

As referenced above, this is used to clear errors in the `RCS_SENSE_1` register.

[01040100]: https://eclipz.pok.ibm.com/sys/ras/scom/p10/ec_10.dd10_split_fure.v17/tp.html#0000000001040100
[1007]: https://eclipz.pok.ibm.com/sys/ras/scom/p10/ec_10.dd10_split_fure.v17/tp.html#0000000000001007
[xx0f001f]: https://eclipz.pok.ibm.com/sys/ras/scom/p10/ec_10.dd10_split_fure.v17/tp_pcb_slave.html#00000000010F001F
[xx0f001e]: https://eclipz.pok.ibm.com/sys/ras/scom/p10/ec_10.dd10_split_fure.v17/tp_pcb_slave.html#00000000010F001E
[0005001D]: https://eclipz.pok.ibm.com/sys/ras/scom/p10/ec_10.dd10_split_fure.v17/tp.html#000000000005001D
[00050013]: https://eclipz.pok.ibm.com/sys/ras/scom/p10/ec_10.dd10_split_fure.v17/tp.html#0000000000050013
[00050015]: https://eclipz.pok.ibm.com/sys/ras/scom/p10/ec_10.dd10_split_fure.v17/tp.html#0000000000050015

## Clock Domains

A clock domain contains all chips that could report attentions for a single
clock or clock pair. For P10, there is one clock, or clock pair, per node.
Therefore, a P10 clock domain will contain all processor chips within a node.

Because of the downstream effects of clock errors, PRD will always analyze all
clock domains before initiating normal PRD FIR analysis.

## Clock Error Types

PRD will be looking for the following attentions on each chip in a clock domain:
- `TP_LOCAL_FIR[28]` => PLL unlock (see below regarding PCB slave parity errors)
- `TP_LOCAL_FIR[42]` => RCS OSC error on clock 0
- `TP_LOCAL_FIR[43]` => RCS OSC error on clock 1
- `TP_LOCAL_FIR[44]` => RCS unlock detect on clock 0
- `TP_LOCAL_FIR[45]` => RCS unlock detect on clock 1

Additionally, when `TP_LOCAL_FIR[28]` is asserted:
- A non-zero value from `BC_OR_PCBSLV_ERROR[24:31]` indicates a there is a PLL
  unlock attention. These will be handled during clock domain analysis.
- A non-zero value from `BC_OR_PCBSLV_ERROR[0,4:17,19:23,32:35]` indicates a
  there is a PCB slave parity error. These will not be handled by clock domain
  analysis and will instead be handled during normal PRD FIR analysis. See
  section regarding this attention type during normal PRD FIR analysis for
  details.

Also, RCS unlock detect attentions are only valid if found on the non-primary
clock. PRD will have to check `RCS_SENSE_1[12:13]` to determine which clock is
primary.

### Important notes regarding RCS unlock detect attentions in hardware

- In P10 DD1.0, it is possible on to see an RCS unlock detect attention on the
  primary clock, which should be ignored. The hardware team is working on a
  possible fix for P10 DD2.0 to only report on non-primary clocks.

- In P10 DD1.0, there is a bug in hardware that will report false RCS unlock
  detect attentions. Therefore, the hardware team has recommended to mask these
  attentions for P10 DD1.0.

- In P10 DD2.0, the hardware team was unable to resolve the P10 DD1.0 issues
  above, among other issues, and have determined that the RCS unlock detect
  functionality will be **disabled for all P10 processors** and the attentions
  will be masked.

## Clock Domain Error Analysis Priority and Justifications

RCS OSC error attentions have the potential of generating PLL unlock attentions,
but it is also possible the PLL unlock attentions could have asserted on their
own. Unfortunately, there may have been one or more clock failovers due to the
RCS OSC error attentions. Therefore, it would be impossible to tell which clock
was the primary at the time of the PLL unlock attention. So, if any RCS OSC
error attentions are present on a chip, PRD must ignore any PLL unlock
attentions on that chip.

Similarly, RCS unlock detect attentions only have meaning if found on the
non-primary clock. Again, due to potential clock failovers, it would be
impossible to tell which clock was the primary at the time of the the RCS unlock
detect attention. Therefore, if any RCS OSC error attentions are present on a
chip, PRD must ignore any RCS unlock detect attentions on that chip.

Certain PLL unlock attentions have the potential of causing RCS unlock detect
attentions, but it is also possible the two error types could have asserted on
their own. Regardless, the callouts will be accurate, assuming there are no RCS
OSC error attentions. So, the decision is to treat PLL unlock attentions and RCS
unlock detect attentions as individual events to simplify PRD analysis.

Slow frequency drifts will not be detected by the RCS checkers. However, they
can cause cause PLL unlock attentions if the frequency deviates beyond the
specified PLL frequency band. Jitter can cause PLL unlock attentions, but will
most likely be caught by the RCS checkers. In addition, PLL unlock attentions
may indicate there is a problem within the processor that reported the error.
Therefore, PRD must call out both the primary clock and the processor.

If more than one processor in the clock domain is reporting PLL unlock
attentions, then the primary clock is more likely at fault than the processors.

Conversely, if all PLL unlock attentions are scoped to a single processor in
the clock domain, we cannot definitively determine that a part is more at fault
than the other, especially if a system only has one configured processor.
Therefore, we will call out both the primary clock and the processor at medium
priority. In addition, the clock will be the first in the list as it is the
easiest part to repair.

In all the cases referenced above, the clock is either more likely the root
cause or it is indeterminate which of the two parts is at fault. Guarding the
processor has the potential (based on resources) to prevent the system from
IPLing, which would be undesirable when there could be a perfectly good
redundant clock available. Therefore, we will not guard the processor on any of
these errors.

Note that any time a clock is called out, HWSV will add the planar (priority
LOW) and procedure FSPSP96 to the callout list.

The following is a summary for clock domain analysis based on the detailed
description above (note that service will only be requested when a threshold
has been reached):

```
for ( each chip in the domain )
{
    if ( RCS OSC error from either clock )
    {
        call out the associated clock(s), HIGH
        call out the processor, LOW, NO GUARD
    }
    else
    {
        if ( RCS unlock detect on non-primary clock )
        {
            call out the associated clock, HIGH
            call out the processor, LOW, NO GUARD
        }

        if ( PLL unlock from primary clock on more than one chip in domain )
        {
            call out the associated clock, HIGH
            call out the processor, MEDIUM, NO GUARD
        }
        else if ( PLL unlock from primary clock on only one chip in the domain )
        {
            call out the associated clock, MEDIUM
            call out the processor, MEDIUM, NO GUARD
        }
    }
}
```

### Important note regarding integrated spare clock configurations

Unlike Denali, which has redundant clock cards, Everest has two clocks soldered
on the backplane. Our service strategy is to only replace the backplane when
both clocks are bad or if a clock is the root cause of a system checkstop
attention.

Note that even though you would expect the system to checkstop when both clocks
go bad, there is a window early in the IPL, before the SMP buses are trained,
where the PLLs can generate a psuedo clock from its VCO. In which case, Hostboot
PRD will have to explicitly check if both clocks are bad.

## RCS Transient Error Recovery

Some failover events could be caused by transient soft errors. When PRD detects
an RCS OSC error, it will call the `p10_rcs_transient_check` HWP which will
initiate recovery. On the event of a hard failure (unsuccessful recovery), PRD
will enable the alternate ref clock mode on the processor reporting the error
by setting `ROOT_CTRL3[3]` (OSC 0) or `ROOT_CTRL3[7]` (OSC 1). In addition, PRD
will make an immediate predictive callout, following the rules above, regardless
of the current threshold counts.

## Thresholding RCS OSC error and RCS unlock detect attentions

PRD will maintain the following threshold counters per chip in the clock
domain:
- RCS OSC error and RCS unlock detect attentions on clock 0.
- RCS OSC error and RCS unlock detect attentions on clock 1.

Note that this is different from PLL unlock attentions were we only threshold
per clock. This is because on threshold of RCS transient errors must switch the
chip over to alt ref clock mode. We only want to do this on failing chips and we
don't want to force any potentially good chips to this mode.

The threshold for each counter will be 2 per 5 minutes in the field or on first
occurrence in manufacturing.

Once a threshold has been reached, all associated attention types will be masked
using the rules stated below. For example, if there is an RCS threshold on
clock 0, the following will be masked per the rules below:
- RCS OSC error on clock 0 on this chip.
- RCS unlock detect on clock 0 on this chip.
- RCS unlock detect on clock 1 on this chip.
- PLL unlock on all chips in the domain.

## Thresholding PLL unlock attentions

PRD will maintain a threshold counter, per clock, for PLL unlock attentions from
any chip in the domain.

During analysis of a clock domain, the threshold counter is increased by 1 if at
least one chip in the clock domain reported a PLL unlock attention.

The threshold for each counter will be 2 per 5 minutes in the field or on first
occurrence in manufacturing.

Once a threshold has been reached, PLL unlock attentions will be masked on **all
processors** in the domain using the rules stated below.

## Clearing Attentions

When clearing any PLL unlock attention in the domain, PRD must clear all PLL
attentions on **all chips in the domain**. For each chip:

- Clear all chiplet PLL unlock attentions by setting `BC_OR_PCBSLV_ERROR[24:31]`
  to all 1's.

- Clear `TP_LOCAL_FIR[28]`.

When clearing an RCS unlock detect attention on a chip, PRD must:

- Clear the underlying attentions in `RCS_SENSE_1` by toggling `ROOT_CTRL5[6]`
  (OSC 0) or `ROOT_CTRL5[7]` (OSC 1) on, then off. Note that this will clear
  both RCS unlock detect and RCS OSC error attentions and there is no way in
  hardware to separate this.

- Clear `TP_LOCAL_FIR[44]` (OSC 0) or `TP_LOCAL_FIR[45]` (OSC 1).

When clearing an RCS OSC error attentions on a chip, PRD must:

- Clear all PLL unlock attentions, as described above, on **all chips in the
  domain**. This must be done to avoid reporting possible side-effect attentions
  later on. See the Analysis Priority above for justification.

- Clear all RCS unlock detect attentions (both clocks), as described above, on
  **this chip**. This must be done to avoid reporting possible side-effect
  attentions later on. See the Analysis Priority above for justification.

- Clear the underlying attentions in `RCS_SENSE_1` by toggling `ROOT_CTRL5[6]`
  (OSC 0) or `ROOT_CTRL5[7]` (OSC 1) on, then off. Note that this will clear
  both RCS unlock detect and RCS OSC error attentions and there is no way in
  hardware to separate this.

- Clear `TP_LOCAL_FIR[42]` (OSC 0) or `TP_LOCAL_FIR[43]` (OSC 1).

## Masking Attentions (on threshold)

When masking any PLL unlock attention in the domain, PRD must mask all PLL
attentions on **all chips in the domain**. For each chip:

- Set `xx_PCBSLV_CONFIG[12:19]` on all chiplets in the processor.

- PRD will **not** mask `TP_LOCAL_FIR[28]` so that PCB slave parity error
  attentions can continue to be reported.

When masking an RCS unlock detect attention on a chip, PRD must:

- Mask `TP_LOCAL_FIR[44]` (OSC 0) or `TP_LOCAL_FIR[45]` (OSC 1).

When masking an RCS OSC error attentions on a chip, PRD must:

- Mask all PLL unlock attentions, as described above, on **all chips in the
  domain**. This must be done to avoid reporting possible side-effect attentions
  later on. See the Analysis Priority above for justification.

- Mask all RCS unlock detect attentions (both clocks), as described above, on
  **this chip**. This must be done to avoid reporting possible side-effect
  attentions later on. See the Analysis Priority above for justification.

- Mask `TP_LOCAL_FIR[42]` (OSC 0) or `TP_LOCAL_FIR[43]` (OSC 1).

## Additional Handling in Normal PRD FIR Analysis

At the end of the clock domain analysis, all related attentions will be masked
(on threshold) and cleared before entering normal PRD FIR analysis. This section
describes what PRD will do if any of these attentions are seen during normal PRD
FIR analysis.

### `TP_LOCAL_FIR[28]` PCB slave error

At this point, any PLL unlock attentions that existed should have been cleared.
So, PRD will assume this attention is due to a PCB slave parity error. PRD will
capture all of the registers that would be captured during clock domain analysis
just in case there may be a problem with isolation.

RAS actions:
- Call out the processor chip, HIGH.
- Threshold at 2 per 5 minutes.

When clearing the attention::
- PRD will set all bits in `BC_OR_PCBSLV_ERROR` except for bits 24-31, just in
  case a PLL unlock cropped up during analysis.
- PRD will clear `TP_LOCAL_FIR[28]`.

When masking the attention (at threshold):
- PRD will set `xx_PCBSLV_CONFIG[8:11]` on all chiplets in the processor to
  mask off all parity error attentions reported to `TP_LOCAL_FIR[28]`.
- PRD will **not** mask `TP_LOCAL_FIR[28]` so that PLL unlock attentions can
  continue to be reported.

### `TP_LOCAL_FIR[42:43]` RCS OSC error

At this point, all analysis for these bits should have been done in the clock
domain analysis. Therefore, if there are any active attentions in these bits
during normal PRD FIR analysis, they will be considered bugs in the clock domain
analysis code.

RAS actions:
- Call out level 2 support, HIGH.
- Threshold on first occurence.

When clearing either attention:
- PRD will clear the associated `TP_LOCAL_FIR` bit at attention. Note that this
  doesn't really matter because the bit will be masked. This is simply noting
  the PRD framework will clear the bit regardless.

When masking either attention (at threshold):
- PRD will mask the associated `TP_LOCAL_FIR` bit at attention.

### `TP_LOCAL_FIR[44:45]` RCS unlock detect

In P10 DD1.0, it is possible that an RCS unlock detect attention was reported
from the primary clock. This attention is ignored by the clock domain analysis
code because only RCS unlock detect attentions from the non-primary clocks are
valid. The hardware team plans to fix P10 DD2.0 such that RCS unlock detect
attentions should only be reported from the non-primary clock. Fortunately due
to other issues in the P10 DD1.0 RCS checkers, these attentions should be
masked. Therefore, if there are any active attentions in these bits during
normal PRD FIR analysis, they will be considered bugs in the FIR inits (DD1.0)
or the clock domain analysis code (DD2.0).

RAS actions:
- Call out level 2 support, HIGH.
- Threshold on first occurence.

When clearing either attention:
- PRD will clear the associated `TP_LOCAL_FIR` bit at attention. Note that this
  doesn't really matter because the bit will be masked. This is simply noting
  the PRD framework will clear the bit regardless.

When masking either attention (at threshold):
- PRD will mask the associated `TP_LOCAL_FIR` bit at attention.

