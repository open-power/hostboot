# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/runtime/rt_start.S $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2022
# [+] International Business Machines Corp.
# [+] Joel Stanley
#
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing
# permissions and limitations under the License.
#
# IBM_PROLOG_END_TAG
.include "kernel/ppcconsts.S"

#define __HOSTBOOT_RUNTIME_INTERFACE_VERSION_ONLY 1
#include <runtime/interface.h>

.section .text.intvects

.org 0x0;
hbrt_desired_interface_version:
    .quad 0x4842525456455253  # 'HBRTVERS' eyecatch.
    .quad HOSTBOOT_RUNTIME_INTERFACE_VERSION

.org 0x100;
_init:
    mflr r10                  # Save LR
    bl 1f                     # Get current address by branch-with-link.
1:
    mflr r4                   # Extract current address.
    mtlr r10                  # Restore LR.
    clrrdi r4, r4, 12         # Align address to 4k.

    addi r10, r4, 0x2000      # Find VFS_LAST_ADDRESS symbol.
    ld r10, 0(r10)            # Read start of relocation table.
    add r10, r10, r4

    ld r8, 0(r10)             # Get count of relocations.

    cmpwi cr0, r8, 0          # Perform relocations (if any).
    beq 2f

    # TLS workaround
    # Load ASCII 'T','L','S' + 0x00 into bits 32:63 of r6, which will be used
    # to compare against bits 0-31 of each relocation entry.  A match signifies
    # that this and the next relocation entry are the TLS module and offset
    # relocations respectively.  Skip both relocations before continuing the
    # processing.  These first two directives create the reference pattern to
    # compare against.  Also skip a relocation entry if its value is 0.
    rldicl r6,r6,0,63         # Clear r6 to zero
    addis r6, 0, 0x544C       # Load ASCII "TL" into bits 32:47 of r6
    ori r6, r6, 0x5300        # Load ASCII "S" + 0x00 into bits 48:63 of r6

    mtctr r8
1:
    ldu r8, 8(r10)            # Get relocation destination
    add r8, r8, r4
    ld r7, 0(r8)              # Get relocation address


    # TLS workaround (continued for next 8 instructions)
    rldicl r5,r5,0,63         # Clear r5 to zero
    cmp cr0, 0, r5, r7        # Compare the relocation address (r7) to zero (r5)
    beq cr0, 3f               # If the relocation address is zero, do
                              # not adjust it and instead jump to the loop
                              # decrement/branch instruction

    rldicl r5,r7,32,32        # Rotate bits 0-31 of the relocation address
                              # into 32-63 and clear bits 0-31, saving result
                              # to r5, to set up the next comparison
    cmp cr0, 0, r6, r5        # Compare bits 32-63, which should both contain
                              # ASCII TLS+0x00 if this is a TLS module
    bne cr0, 4f               # If not a TLS module relocation, keep going;
    ldu r8, 8(r10)            # otherwise, skip the TLS module relocation
    bdnz 3f                   # and decrement the loop counter to match. Jump
                              # to a 2nd skip/decrement pair to effectively skip
                              # the next TLS module relocation as well
4:
    add r7, r7, r4
    std r7, 0(r8)             # Update relocation address.
3:
    bdnz 1b                   # Decrement CTR and continue loop.
2:
    addi r10, r4, 0x2008      # Find pointer to main TOC.
    ld r10, 0(r10)            # Dereference pointer to get TOC entry.
    ld r2, 8(r10)
    ld r10, 0(r10)
    mtctr r10
    bctr

.section .text.kernelasm # @2000
.global VFS_LAST_ADDRESS
VFS_LAST_ADDRESS:
    .space 8
main_toc_ptr:
    .quad _main


.section .data

.global hbi_ImageId
hbi_ImageId:
    .space 128
.global hbi_FWId_long
hbi_FWId_long:
    .space 128
.global hbi_FWId_short
hbi_FWId_short:
    .space 16
