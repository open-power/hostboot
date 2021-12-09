# Hostboot
Hostboot firmware initializes all processor, bus, and memory within IBM POWER
 based systems. Furthermore, it is responsible for loading the hostboot image
 using hostboot bootloader, prepare hardware to load and run an appropriate
 payload (e.g phyp or skiboot), and provide runtime services while the payload
 is running. Various hostboot features are easily configurable via compile time
 CONFIG flags.

## How to compile hostboot?
- Standalone compile:
    - `cd hostboot`
    - `./hb workon`
    - `make -j32`
        - **NOTE**: You can run `make clobber` when switching between branches
        or releases for a fresh start
    - `hb prime`
- In OpenPOWER context:
    - `op-build <system_name>_defconfig && op-build hostboot-rebuild
        machine-xml-rebuild openpower-pnor-rebuild`
        - **Example**: `op-build witherspoon_defconfig && op-build
        hostboot-rebuild machine-xml-rebuild openpower-pnor-rebuild`
    - **NOTE**: Above command is assuming you have already done a full op-build
        compile already. If not, then run the following `op-build
        <system_name>_defconfig && op-build`

## Various Components
### [Hostboot Bootloader (HBBL)](src/bootloader/README.md)
Hostboot Bootloader image is part of the SEEPROM SBE (Self Boot Engine) image.
In istep 5.1, SBE loads the bootloader in cache. In istep 5.2, SBE starts
instructions on the processor from where the HBBL is loaded. HBBL finds the
hostboot images in pnor, loads them into memory, and starts hostboot.

### [Kernel](src/kernel/README.md)
Hostboot uses a custom kernel that enables execution of user-space hostboot IPL
firmware and services. The kernel provides the general execution environment,
message passing, task control, memory management, interrupt support, and any
other functions to support the initialization activities of the user space. It
is a micro-kernel that pushes as much function as possible to the user space,
which has more safety protections.

### User Space Applications
There are various user space applications, including, device drivers, services
necessary for base enablement, and other interactions with other components.

##### Device Drivers
- Base Device Driver FW (devicefw)
- FSI
- GPIO
- I2C
- SCAN/SCOM/IBSCOM/FSISCOM/XSCOM
- LPC
- MBOX
- PNOR

##### Base Services
- Error Logs
- Targeting
- FAPI2
- HWAS
- Base IPL Service (initservice/isteps)
- Interrupt Service
- Trace
- VFS
- VPD
- Console
- Secureboot

##### Other FW Components
- SBE
- HDAT
- HTMGT
- PRD/DIAGNOSTICS
- HBRT

### Build
This contains all the infrastructure to compile, link, and generate hostboot
binaries (including a full pnor for standalone compile).

### Import
This contains code which does all the hardware accesses required to initialize
the hardware. This lives in the import directory because we directly consume it
from the hardware team and call it hardware procedures.
