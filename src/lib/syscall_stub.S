# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/lib/syscall_stub.S $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2010,2014
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
