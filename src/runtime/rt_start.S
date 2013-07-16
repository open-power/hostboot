# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/runtime/rt_start.S $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2013
#
# p1
#
# Object Code Only (OCO) source materials
# Licensed Internal Code Source Materials
# IBM HostBoot Licensed Internal Code
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# Origin: 30
#
# IBM_PROLOG_END_TAG
.include "kernel/ppcconsts.S"

.section .text.intvects

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
