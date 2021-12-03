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

# 0x7dce is the DCE state set ID from the Hostboot PDR creation code.
EFFECTER_ID=$(busctl call xyz.openbmc_project.PLDM /xyz/openbmc_project/pldm xyz.openbmc_project.PLDM.PDR FindStateEffecterPDR yqq 2 45 0x7dce | awk '{print int(256 * $17 + $16)}')

pldmtool platform SetStateEffecterStates -m 9 -i $EFFECTER_ID -c 1 -d 00 00
