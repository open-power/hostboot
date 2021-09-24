# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/ebmc/vpdConstants.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2021
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

""" The following values and functions are used in b0c00.py
"""

""" The following values are from src/include/usr/hwas/common/vpdConstants.H
and are used to create the Partial-Good Vector.
Changes to those values should be reflected here.
"""
VPD_CP00_PG_DATA_LENGTH = 192;
VPD_CP00_PG_ENTRY_SIZE = 3;
VPD_CP00_PG_DATA_ENTRIES = VPD_CP00_PG_DATA_LENGTH // VPD_CP00_PG_ENTRY_SIZE;

VPD_CP00_PG_FSI_ALL_GOOD = 0xFFE03FFF
VPD_CP00_PG_PRV_ALL_GOOD = 0xFFE051FF
VPD_CP00_PG_N0_ALL_GOOD = 0xFFE37FFF
VPD_CP00_PG_N1_ALL_GOOD = 0xFFE53FFF
VPD_CP00_PG_RESERVED_GOOD = 0xFFFFFFFF
VPD_CP00_PG_PCI_ALL_GOOD = 0xFFE00C1F
VPD_CP00_PG_MC_ALL_GOOD = 0xFFE21DFF
VPD_CP00_PG_PAUC_SE_NE_ALL_GOOD = 0xFFE39FFF
VPD_CP00_PG_PAUC_SW_NW_ALL_GOOD = 0xFFE19FFF
VPD_CP00_PG_IOHS_ALL_GOOD = 0xFFE3BDFF
VPD_CP00_PG_EQ_ALL_GOOD = 0xFFE0001F

"""
Creates Partial-Good Vector found in src/include/usr/hwas/common/vpdConstants.H
Changes to the vector should be reflected here.

@returns: an array of the partial good vector
"""
def createPGV():
    ag = []
    ag.append(VPD_CP00_PG_FSI_ALL_GOOD)
    ag.append(VPD_CP00_PG_PRV_ALL_GOOD)
    ag.append(VPD_CP00_PG_N0_ALL_GOOD)
    ag.append(VPD_CP00_PG_N1_ALL_GOOD)
    for x in range(4):
        ag.append(VPD_CP00_PG_RESERVED_GOOD)
    for x in range(2):
        ag.append(VPD_CP00_PG_PCI_ALL_GOOD)
    for x in range(2):
        ag.append(VPD_CP00_PG_RESERVED_GOOD)
    for x in range(4):
        ag.append(VPD_CP00_PG_MC_ALL_GOOD)
    for x in range(2):
        ag.append(VPD_CP00_PG_PAUC_SE_NE_ALL_GOOD)
    for x in range(2):
        ag.append(VPD_CP00_PG_PAUC_SW_NW_ALL_GOOD)
    for x in range(4):
        ag.append(VPD_CP00_PG_RESERVED_GOOD)
    for x in range(8):
        ag.append(VPD_CP00_PG_IOHS_ALL_GOOD)
    for x in range(8):
        ag.append(VPD_CP00_PG_EQ_ALL_GOOD)
    for x in range(24):
        ag.append(VPD_CP00_PG_RESERVED_GOOD)

    return ag
