# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/secureboot/base/rom_entry.S $
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

.section .text

.global call_rom_verify
.global call_rom_SHA512

call_rom_verify:
call_rom_SHA512:

call_rom_entry:
    std r2, 40(r1)
    mflr r0
    std r0, 16(r1)
    stdu r1, -128(r1)
    li r2, 0
    mtctr r3
    mr r3, r4
    mr r4, r5
    mr r5, r6
    mr r6, r7
    mr r7, r8
    bctrl
    addi r1, r1, 128
    ld r2, 40(r1)
    ld r0, 16(r1)
    mtlr r0
    blr

