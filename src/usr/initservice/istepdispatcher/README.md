# Booting, Rebooting and Shutting Down


### Common Terms / Acronyms
- IPL = Initial Program Load, a legacy IBM term that refers to booting the server hardware
- Istep = IPL Step, refers to the named/numbered portions of the boot sequence, e.g. istep 6.6 is host_discover_targets
- MPIPL = Memory Preserving re-IPL, a type of reboot from runtime where the mainstore memory and all pervasive nest/io are left configured, but the core-related logic is reconfigured.  These are usually done to collect mainstore dump information due to runtime failures, but can also be used just as a fast reboot.
- Reconfig Loop = A special kind of mini-reboot that Hostboot triggers to rerun a portion of the isteps in order to reconfigure some part of the hardware due to a condition that was encountered. A reconfig loop does not increment any kind of system-level reboot counter and does not necessarily indicate a system problem.
- SBE = Self-Boot Engine, hw/fw component on the processor that does the initial configuration of the hardware before Hostboot starts
- SP = Service Processor, this refers to either the FSP or BMC
- TI = Terminate Immediate, triggered by executing the ATTN instruction which leads to a special attention seen by the SP


## Typical Boot flow
A standard IPL is triggered by the service processor (SP) and runs to completion without user intervention.
1. SP powers on the system hardware
2. SP starts the SBE on a single primary boot processor
3. SBE initializes the boot processor enough to have valid L3 cache and core logic  
   - At minimum Hostboot needs 8MB of cache memory to start in, but we can use up to 64MB if it is available 
4. SBE loads HB Bootloader (HBBL) code from the SBE SEEPROM into L3 cache
5. SBE starts instructions on a single thread to run HBBL
6. HBBL loads Hostboot Base (HBB) code from the PNOR via the LPC bus into (cache) memory
7. HBBL verifies HBB signature and branches to the start of HBB execution (src/kernel/start.S)
8. Kernel initializes, userspace initializes (base initservice, extended initservice)
    - Encompasses isteps host_setup..host_set_ipl_parms
9. IStepDispatcher begins executing isteps based on src/include/usr/isteps/*.H
10. Hardware is initialized
11. Hostboot loads a payload into mainstore memory and branches to it
    - This is istep host_start_payload
    - After this point, Hostboot is no longer executing on the system.
12. Payload (PHYP/OPAL) executes
13. Hostboot Runtime (HBRT) application is started
    - Details on environment vary by payload.
    - This is a hosted application, there is no kernel/os-level control by Hostboot.

## Memory Preserving IPL (MPIPL)
A MPIPL operates more or less the same as a normal IPL except a large majority of the isteps are not run.  Most isteps that are related to initializing non-core hardware are NOOPs.


## Istep Mode
For lab debug, Hostboot can be booted in istep mode.  In this mode, Hostboot executes a single istep and then stops.  The IPL is driven by some external entity, usually the SP or some other tool.


## Reconfig Loop
The purpose of a reconfig loop is to reinitialize some aspect of the hardware or firmware stack without triggering a customer-visible reboot.


There are two types of reconfig loops that Hostboot can trigger:
- Shallow loop where Hostboot itself will rerun certain isteps without shutting down.  The main use case for this is istep7 where we can handle deconfigurations more efficiently.
- Deep loop where Hostboot shuts down and the IPL restarts at the beginning (SBE start).


There are several reasons that Hostboot will request a reconfig loop, listed below.  Note that if a reconfig loop is triggered in istep mode, the istep will fail and no restart will be triggered.  This is because by definition isteps are bounded by the specific request that was made and will not rerun previous steps.


### A target was deconfigured during an istep
Since the CEC hardware initialization is inherently a serial process, it isn't possible to just continue the boot when the configuration changes due to a deconfiguration.  All deconfigurations are preserved across reconfig loops (unlike a regular reboot) so the subsequent IPL will be done with a configuration that is more likely to succeed, since the problematic hardware won't be used.  Once Hostboot has booted past the host_gard istep, any error log that deconfigures a target will automatically result in a reconfig loop being initiated at the end of the istep.  This is enforced by the HWAS logic setting ATTR_RECONFIGURE_LOOP for all deconfigs.


### After a SBE firmware update
We always want to be running off the level of SBE firmware that is part of the current image.  This means that whenever we find a mismatch we need to restart the SBEs to run on the new code after we update them.  This must be a deep reconfig loop for two reasons.  First, any reboot of the primary boot processor's SBE must be done by the SP.  Second, the update of the secondary processors is done after we have the SMP fabric connected, a restart of any of the SBEs in that fabric will reset the processor and checkstop the system.
 
### To reconcile SBE boot properties with the SP
The SP uses its own system data as input to the SBE start on the boot processor.  It is possible for some of those initial values from the SP to differ from what Hostboot wants the values to be.  This is typically caused when the values are dynamically computed based on system configuration.  For example, the frequency of the memory PLL is based on the type of DIMMs that are installed.  This cross-check is run in istep 7.5 mss_attr_update.  Hostboot will sync its version of the data down to the SP and then trigger a reconfig loop.  This will cause the SP to use that data on subsequent restarts of the SBE.


### To recover from a known intermittent hardware failure
Occasionally there are hardware operations with a non-zero failure rate that we simply want to retry.  One example is when we find a bad bit on the memory but we have spares to repair it with.  We have to reboot the hardware to apply the spare before we can continue on to runtime.


### After a OCMB Firmware update
We always want to be running off the level of OCMB firmware that is part of the current image.  This means that whenever we find a mismatch we need to restart the OCMBs to run on the new code after we update them.  This must be a deep reconfig loop because it will affect the way the OMI bus is trained and how the DRAM was initialized.


## Service Processor Differences for Reconfig Loops
The method by which we trigger a reconfig loop varies based on the service processor being used on this machine.


### FSP
On FSP boxes, Hostboot will shutdown and TI with a unique reasoncode (RC) indicating we would like a reconfig loop.  The FSP code will interpret that and act accordingly.


### BMC
On BMC systems, Hostboot will request a graceful reboot to trigger a deep reconfig loop.  The BMC's bootcount (counts down to zero) will be explicitly incremented before this is requested to ensure we don't trigger the reboot limit.

## Graceful shutdown

There are several situations where Hostboot needs to completely shut down that do not have their origins in an error or fault in the system. These are:

1. For a Secure Boot Key Transition (shutdown happens after an SBE update)
2. For Physical Presence Detection (system shuts down and waits for a manual power-on)
3. When the SP/BMC requests a shutdown while the host is IPLing (can happen because of user input or other reasons)

The shutdown in the first two scenarios is initiated by Hostboot itself. Hostboot invokes the requestSoftPowerOff function which quiesces the host. (The host is said to be "quiesced" when Hostboot has reached a state where power to the host can safely be cut; HB will terminate certain tasks, flush dirty pages to backing storage, stop making or accepting requests for certain resources, etc. in preparation for the poweroff.)

The third scenario is initiated by the service processor (SP) using either an FSI mailbox message or a PLDM message, depending on whether the system is managed by an FSP or an eBMC.

### eBMC systems

On eBMC systems, a graceful shutdown can be triggered by sending Hostboot a PLDM SetStateEffecterStates request directed at the host's Graceful Shutdown effecter. Hostboot will respond to the message immediately and begin the shutdown sequence.

At the end of a graceful shutdown when the host is quiesced (no matter who requests it), Hostboot will send a PLDM event to the BMC to notify it that the host shutdown is complete and power to the chassis can safely be turned off. This only works after the PDR exchange has completed; attempting to perform a graceful shutdown before this point will cause an error to be logged, and the shutdown status will be set to "error."

### Shutdown path restrictions

The further the host progresses down the shutdown path, the fewer resources are available. For example, once dirty PNOR pages have been flushed to backing storage, no more PNOR requests should be made by the system. Code in the final shutdown path has to be written to take these restrictions into account. Here is an incomplete list of things that code in the shutdown path should take care to avoid:

1. Do not execute code that resides in the HB Extended Image (HBI), because this could cause PNOR pages to be fetched. Only HB Base (HBB) code can be safely executed, because this code is never paged out.
2. Do not access attributes. Even accessing volatile attributes could cause parts of the attribute data structures to be paged in via PNOR (if the HBD section is built as pageable).
3. Do not commit error logs. They will not be sent to the SP because PNOR pages will have already been flushed and the error log manager service will already have been shut down.
4. Do not do anything that requires interrupts.

Documentation on the stages of shutdown can be found at src/usr/initservice/README.md.
