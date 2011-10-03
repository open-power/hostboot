#   IBM_PROLOG_BEGIN_TAG
#   This is an automatically generated prolog.
#
#   $Source: src/lib/syscall_stub.S $
#
#   IBM CONFIDENTIAL
#
#   COPYRIGHT International Business Machines Corp. 2010 - 2011
#
#   p1
#
#   Object Code Only (OCO) source materials
#   Licensed Internal Code Source Materials
#   IBM HostBoot Licensed Internal Code
#
#   The source code for this program is not published or other-
#   wise divested of its trade secrets, irrespective of what has
#   been deposited with the U.S. Copyright Office.
#
#   Origin: 30
#
#   IBM_PROLOG_END
.section .text

.global _syscall0
.global _syscall1
.global _syscall2
.global _syscall3
.global _syscall4
.global _syscall5
.global _syscall6
.global _syscall7

_syscall0:
_syscall1:
_syscall2:
_syscall3:
_syscall4:
_syscall5:
_syscall6:
_syscall7:
    sc
    blr

.global _syscall0_nr
.global _syscall1_nr
.global _syscall2_nr
.global _syscall3_nr
.global _syscall4_nr
.global _syscall5_nr
.global _syscall6_nr
.global _syscall7_nr

_syscall0_nr:
_syscall1_nr:
_syscall2_nr:
_syscall3_nr:
_syscall4_nr:
_syscall5_nr:
_syscall6_nr:
_syscall7_nr:
    sc
1:
    b 1b
