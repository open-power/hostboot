# Initialization Service
The Initialization Service is responsible for booting Hostboot userspace.  It
 drives the loading of the modules that are part of the base and extended
 images.  It also controls istep execution
 (See [Istep Dispatcher](src/usr/initservice/istepdispatcher/README.md)) and
 shutting hostboot down.

## Base Init Service
The modules here are part of the base image.  The key distinction here is that
 these modules are not pageable, meaning they will always exist in physical
 memory.  See [initsvctasks.H](baseinitsvc/initsvctasks.H) for the list of
 modules and the order in which they are loaded.

## Extended Init Service
The modules here are part of the extended image.  These modules are always
 loaded and accessible to be called, however they may be paged out of physical
 memory as needed.  All of the resource/service providers, the device drivers,
 FAPI2 infrastructure, and other similar universal utilities are loaded here.
 See [extinitsvctasks.H](extinitsvc/extinitsvctasks.H) for the list of modules
 and the order in which they are loaded.

## Shutdown
A controlled shutdown can be triggered for a variety of reasons:
- Successful completion of the boot and transitioning to PHYP/OPAL
- IPL failure
- External request (FSP or BMC)

In all cases, the various services have a chance to clean themselves up before
 Hostboot terminates.  The services register (registerShutdownEvent) for a
 message call-back  using a specific priority to maintain the ordering
 requirements.  Code can also register for virtual memory to be flushed
 (registerBlock).


### Current list of shutdown messages with reasons and limitations:
(See [initserviceif.H](../../include/usr/initservice/initserviceif.H) for the
 most up to date list of priority values.)

* __HIGHEST_PRIORITY (0)__
  * _Trace Daemon_ --
     Pushes everything out to the mailbox to be synched down to the FSP for
     continuous tracing
* __NO_PRIORITY (16)__ --
    Must be before MBOX_PRIORITY as these services likely send messages as
    part of their work.
  * _TPM Daemon_ --
     Flushes out any pending messages (e.g. PCR Extends) and terminates
  * _Error Log Manager_ --
     Ensures that any previously committed error logs get pushed to the mailbox
     and into PNOR
  * _Attribute Resource Provider_ --
     Sync all attributes down to the FSP
* __MBOX_PRIORITY (18)__ --
    Must be before INTR_PRIORITY since interrupts are being used.
  * _Mailbox Daemon_ --
     Flushes out any pending messages and stops accepting new ones, returns
     after all messages have been sent and acked.
* __INTR_PRIORITY (19)__ --
    Must be after any interrupt user
  * _Interrupt Resource Provider_ --
     Tells all registered interrupt processors that Hostboot is shutting down,
     masks all interrupt sources, resets the interrupt logic, etc.
* __PRESHUTDOWN_INIT_PRIORITY (20)__ --
    Must be after interrupt is shut down because the behavior of the interrupt
    presenter is changing.
  * _Interrupt Hardware Config_ --
     Reinitialize the interrupt logic to get it into a known state for
     PHYP/OPAL.
* __LOWEST_PRIORITY (127) == CONSOLE_PRIORITY (127)__
  * _Trace Daemon_ --
     Only useful for non-FSP environments since the mailbox is already shut
     down.
  * _Console Daemon_ --
     Ensures any pending messages are pushed out to the serial console.
* __LAST_PRE_MEM_FLUSH_PRIORITY (127)__ --
    Everything above this runs with full VMM, after this virtual memory is
    flushed out based on the registerBlock calls, see
    [BlockPriority](../../usr/vmmconst.h).
  * _Attribute Resource Provider_ --
     Flushes the Read-Write section(s).
  * _Secure PNOR Resource Provider_ --
     Flushes out any write-tracked memory.
  * _PNOR Resource Provider_ --
     Flushes out entire virtual address space.
* __HIGHEST_POST_MEM_FLUSH_PRIORITY (128)__ --
    Anything that needs to be notified after the VMM is flushed out.
* __PNOR_RP_PRIORITY (128)__
    Must be last to ensure all writes have made it out to flash.
  * _PNOR Resource Provider_ --
     Disables any future writes but does *not* disable reads since code pages
     may still end up getting paged in.
* __POST_MEM_FLUSH_NOTIFY_LAST (255)__ --
    Absolute last message sent


