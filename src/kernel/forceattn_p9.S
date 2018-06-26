# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/kernel/forceattn_p9.S $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2018
# [+] International Business Machines Corp.
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


.global p9_force_attn
p9_force_attn:
# Update HID0 to enable attentions
    li r0, 3
    mfspr r9, HID0
    rldimi r9,r0,60,2 /* Turn on bits 2 (flush icache) + 3 (enable attn) */
    sync
    mtspr HID0,r9 /* Enable attentions */
    mfspr r9, HID0
    mfspr r9, HID0
    mfspr r9, HID0
    mfspr r9, HID0
    mfspr r9, HID0
    mfspr r9, HID0
    isync
# Invoke attention instruction
    sync
    isync
    rlwimi 31,31,0,4,22   /* MAGIC_SIMICS_SHUTDOWN */
    attn
    b 0
