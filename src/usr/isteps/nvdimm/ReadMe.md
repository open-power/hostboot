# Battery Power Module (BPM) Updates Overview
To support different firmware versions released by SMART, the bpm_update.C and
bpm_update.H files were created to facilitate upgrades and downgrades of the
firmware version on a BPM attached to an NVDIMM. There are two kinds of BPM, one
that supports 16GB type NVDIMMs and one that supports 32GB type NVDIMMs.
Although they have separate image files, the update is functionally the same for
each. This overview will not go into fine-grain detail on every process of the
update. For more information see the comments in bpm_update.H, bpm_update.C and
in the various supporting files.

Supporting Files:
* Two image files, e.g., SRCA8062IBMH012B_FULL_FW_Rev1.03_02282019.txt or
SRCA8062IBMH011B_FULL_FW_Rev1.04_05172019.txt
    * The image file names are important in that they contain information that
    is not found anywhere else in the files. For example, After SRCA8062IBMH01
    but right before the B is a number. That signifies which kind of BPM type
    that image is for. A 1 means 32gb type, a 2 means 16gb type. Also, note that
    the version Rev1.0x is in the file name. There is no other place where this
    occurs within the image file. So, to differentiate the updates from each
    other the file names must be left intact.
* src/build/buildpnor/buildBpmFlashImages.pl
    * This perl script is responsible for packaging the image files listed above
    into binaries that can then be associated with LIDs for use during the BPM
    update.
* src/build/buildpnor/bpm-utils/imageCrc.c and
src/build/buildpnor/bpm-utils/insertBpmFwCrc.py
    * These are provided by SMART and utilized by buildBpmFlashImages.pl to
    generate the correct CRC for the firmware image during the fsp build.
* src/build/mkrules/dist.targets.mk
    * This file puts src/build/buildpnor/buildBpmFlashImages.pl,
    src/build/buildpnor/bpm-utils/imageCrc.c,
    and src/build/buildpnor/bpm-utils/insertBpmFwCrc.py into the fsp.tar which
    can then be primed over to an FSP sandbox.
* <fsp_sandbox>/src/engd/nvdimm/makefile
    * This makefile compiles the src/build/buildpnor/bpm-utils/imageCrc.c and
    calls src/build/buildpnor/buildBpmFlashImages.pl to do all the necessary
    work to bring the flash image binaries up-to-date.
* In <fsp_sandbox>/obj/ppc/engd/nvdimm/bpm/ are 16GB-NVDIMM-BPM-CONFIG.bin,
16GB-NVDIMM-BPM-FW.bin, 32GB-NVDIMM-BPM-CONFIG.bin, and 32GB-NVDIMM-BPM-FW.bin
    * These are the output binaries which will be associated to LIDs for
    hostboot use.

### BPM Update Flow Overview
The update procedure for the BPM is fairly rigid. There are many steps that must
occur in a precise order otherwise the update will fail. We aren't able to
communicate directly to the BPM for these updates. Instead, we send commands to
the NVDIMM which in-turn passes those along to the BPM. There are a couple
"modes" that must be enabled to begin the update process and be able to
communicate with the BPM. These are:

##### Update Mode
This is a mode for the NVDIMM. To enter this mode a command is sent to the
NVDIMM so that the NVDIMM can do some house-keeping work to prepare for the BPM
update. Since the NVDIMM is always doing background scans of the BPM, this mode
will quiet those scans so that we are able to communicate with the BPM.
Otherwise, the communication would be too chaotic to perform the update.

##### Boot Strap Loader (BSL) Mode (Currently, only BSL 1.4 is supported)
This is the mode that the BPM enters in order to perform the update.In order to
execute many of the commands necessary to perform the update, the BPM **must**
be in BSL mode. There are varying versions of BSL mode and these versions are
not coupled with the firmware version at all. In order for the BSL version to be
updated on a BPM, the device must be shipped back to SMART because it requires a
specific hardware programmer device to be updated.

The update procedure does vary between BSL versions, so to ensure a successful
update the code will first read the BSL version on the BPM. If the BSL version
is not 1.4 (the supported version) then the update process will not occur as it
is known that BSL versions prior to 1.4 are different enough that the update
would fail if attempted and it is unknown if future BSL versions will be
backward compatible with the BSL 1.4 procedure.

If something happens to the firmware during an update such that the firmware on
the device is missing or invalid, the BPM is designed to always fall back to
this mode so that valid firmware can be loaded onto the BPM and the device can
be recovered. However, if the firmware is corrupted by any means outside of an
update then it is highly likely that the BPM will not be recoverable and it may
need to be sent back to SMART for recovery.

#### An update in two parts
The BPM update cannot be done in one single pass. This is because there are two
sections of data on the BPM that must be modified to successfully update the
BPM. These are refered to as the Firmware portion of the update and the
Configuration Data Segment portion of the update.

##### The Firmware Portion
This is the actual firmware update. Although, when someone says the BPM Firmware
Update they are often implicitly referring to both parts of the update. In order
for the full update to be a success, the firmware portion of the update is
reliant upon another part to have access to all of the features in a given
update. That is the Configuration Segment Data. It is safe, and advisable, to
update the firmware part first and then the configuration part second.

##### The Configuration Data Portion
The Configuration Data Segment portion is commonly referred to as the segment
update, config update, or any other variation of the name. The config segment
portion **requires** working firmware on the BPM to succeed. This is because we
must read out some of the segment data on the BPM and merge it with parts from
the image. Without working firmware, it will not work and the update will
_never_ succeed.

The configuration data on the BPM is broken into four segments, A, B, C, and D.
These are in reverse order in memory such that D has the lowest address offset.
For our purposes, we only care about Segment D and B. A and C contain logging
information and are not necessary to touch. Segment D will be completely
replaced by the data in the image file. Segment B is the critical segment,
however, because we must splice data from the image into it. Segment B contains
statistical information and other valuable information that should never be lost
during an update. If this segment becomes corrupted then it is very likely the
BPM will be stuck in a bad state.

##### Bpm::runUpdate Flow
1. Read the current firmware version on the BPM to determine if updates are
necessary. If this cannot be done, that is to say that an error occurs during
this process, then updates will not be attempted due to a probable
communication issue with the BPM.
2. Read the current BSL mode version to determine if the BSL version on the BPM
is compatible with the versions we support. If this cannot be done due to some
kind of error, then the updates will not be attempted since we cannot be sure
that the BPM has a compatible BSL version.
3. Perform the firmware portion of the update. If an error occurs during this
part of the update then the segment portion of the updates will not be attempt
as per the given requirement above.
4. Perform the segment portion of the update.

##### Common Operating Processes between functions
Reading the BSL version, and performing the firmware and segment updates all
follow a common operating process to do their work successfully. The steps laid
out in those functions must be followed in the given order otherwise the
functions will not execute successfully and the BPM may go into a bad state.
These steps are:
1. Enter Update Mode
2. Verify the NVDIMM is in Update Mode
3. Command the BPM to enter BSL mode
4. Unlock the BPM so that writing can be performed.
5. Do function's work.
6. Reset the BPM, which is the way that BSL mode is exited.
7. Exit Update Mode

By following these steps, the BPM is able to some background work to verify its
state. If firmware and config updates are attempted at the same time this will
introduce unpredicatable behavior. Meaning if only one set of steps 1-4 have
executed then step 5a and 5b are to perform firmware and config updates, and
then 6-7 are done that will produce unpredicable behavior. It is best run
through the whole process for each. Reading the BSL version does not have this
limitation. As long as steps 1-4 have been executed, the BSL version can be read
at any time.
