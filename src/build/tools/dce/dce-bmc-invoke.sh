#!/bin/bash
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/dce/dce-bmc-invoke.sh $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2021,2022
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

# Usage: dce-bmc-invoke.sh
#
# This script makes a PLDM request to Hostboot to request the DCE LID
# from the BMC and execute it.

SECURE_ACCESS_BIT_MASK=0x08000000
CFAM=$(getcfam -quiet pu 2801 | awk '{print $(NF)}')
SECURE_MODE=$((CFAM & SECURE_ACCESS_BIT_MASK))

if [[ $((SECURE_MODE)) -ne 0 ]] ; then
    echo 'Error: Secure mode must be disabled to use DCE.'
    echo 'Set the DISABLE_SECURITY attribute to 1 with the following command and re-IPL to run DCE scripts:'
    echo
    echo '  attributes write k0 ATTR_DISABLE_SECURITY 1'
    echo
    exit 1
fi

# 2 is the terminus ID that created the effecter PDR we're looking for (2 is hostboot's TID).
# 45 is the type of the "System" target.
# 0x7dce is the DCE state set ID from the Hostboot PDR creation code.
EFFECTER_ID=$(busctl call xyz.openbmc_project.PLDM /xyz/openbmc_project/pldm xyz.openbmc_project.PLDM.PDR FindStateEffecterPDR yqq 2 45 0x7dce | awk '{print int(256 * $17 + $16)}')

pldmtool platform SetStateEffecterStates -m 9 -i $EFFECTER_ID -c 1 -d 00 00
