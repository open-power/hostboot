# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/kernel/forceattn_p8.S $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2015
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


.global p8_force_attn
p8_force_attn:
    li r0, 1
    mfspr r9, HID0
    insrdi r9,r0,1,3 	/* Turn on bit 3 */
    sync
    mtspr HID0,r9	/* Enable attentions */
    mfspr r9, HID0
    mfspr r9, HID0
    mfspr r9, HID0
    mfspr r9, HID0
    mfspr r9, HID0
    mfspr r9, HID0
    isync
    attn
    b 0
