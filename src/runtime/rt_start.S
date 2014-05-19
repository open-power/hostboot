# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/runtime/rt_start.S $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2013,2014
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

    cmpi cr0, r8, 0           # Perform relocations (if any).
    beq 2f
    mtctr r8
1:
    ldu r8, 8(r10)            # Get relocation destination
    add r8, r8, r4
    ld r7, 0(r8)              # Get relocation address
    add r7, r7, r4
    std r7, 0(r8)             # Update relocation address.
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
