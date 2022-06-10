# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/peltool/src/be500.py $
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
import os
import sys
import json
import glob
from collections import OrderedDict

from pel.prd.parserdata import SignatureData

# ###################################################
# Used to convert attention types to readable string
# ###################################################


def attnTypeToStr(i_type: str) -> str:

    attnTypes = {"01": "SYSTEM_CS",
                 "02": "UNIT_CS",
                 "03": "RECOVERABLE",
                 "04": "SPECIAL",
                 "05": "HOST_ATTN"}

    attnTypeStr = "Unknown " + i_type

    if i_type in attnTypes:
        attnTypeStr = attnTypes[i_type]

    return attnTypeStr

# ###################################################
# Used to convert target types to readable string
# ###################################################


def targetTypeToStr(i_type: str) -> str:

    targetTypes = {"00": "TYPE_NA",
                   "01": "TYPE_SYS",
                   "02": "TYPE_NODE",
                   "03": "TYPE_DIMM",
                   "04": "TYPE_MEMBUF",
                   "05": "TYPE_PROC",
                   "06": "TYPE_EX",
                   "07": "TYPE_CORE",
                   "08": "TYPE_L2",
                   "09": "TYPE_L3",
                   "0a": "TYPE_L4",
                   "0b": "TYPE_MCS",
                   "0d": "TYPE_MBA",
                   "0e": "TYPE_XBUS",
                   "0f": "TYPE_ABUS",
                   "10": "TYPE_PCI",
                   "11": "TYPE_DPSS",
                   "12": "TYPE_APSS",
                   "13": "TYPE_OCC",
                   "14": "TYPE_PSI",
                   "15": "TYPE_FSP",
                   "16": "TYPE_PNOR",
                   "17": "TYPE_OSC",
                   "18": "TYPE_TODCLK",
                   "19": "TYPE_CONTROL_NODE",
                   "1a": "TYPE_OSCREFCLK",
                   "1b": "TYPE_OSCPCICLK",
                   "1c": "TYPE_REFCLKENDPT",
                   "1d": "TYPE_PCICLKENDPT",
                   "1e": "TYPE_NX",
                   "1f": "TYPE_PORE",
                   "20": "TYPE_PCIESWITCH",
                   "21": "TYPE_CAPP",
                   "22": "TYPE_FSI",
                   "23": "TYPE_EQ",
                   "24": "TYPE_MCA",
                   "25": "TYPE_MCBIST",
                   "26": "TYPE_MI",
                   "27": "TYPE_DMI",
                   "28": "TYPE_OBUS",
                   "2a": "TYPE_SBE",
                   "2b": "TYPE_PPE",
                   "2c": "TYPE_PERV",
                   "2d": "TYPE_PEC",
                   "2e": "TYPE_PHB",
                   "2f": "TYPE_SYSREFCLKENDPT",
                   "30": "TYPE_MFREFCLKENDPT",
                   "31": "TYPE_TPM",
                   "32": "TYPE_SP",
                   "33": "TYPE_UART",
                   "34": "TYPE_PS",
                   "35": "TYPE_FAN",
                   "36": "TYPE_VRM",
                   "37": "TYPE_USB",
                   "38": "TYPE_ETH",
                   "39": "TYPE_PANEL",
                   "3a": "TYPE_BMC",
                   "3b": "TYPE_FLASH",
                   "3c": "TYPE_SEEPROM",
                   "3d": "TYPE_TMP",
                   "3e": "TYPE_GPIO_EXPANDER",
                   "3f": "TYPE_POWER_SEQUENCER",
                   "40": "TYPE_RTC",
                   "41": "TYPE_FANCTLR",
                   "42": "TYPE_OBUS_BRICK",
                   "43": "TYPE_NPU",
                   "44": "TYPE_MC",
                   "45": "TYPE_TEST_FAIL",
                   "46": "TYPE_MFREFCLK",
                   "47": "TYPE_SMPGROUP",
                   "48": "TYPE_OMI",
                   "49": "TYPE_MCC",
                   "4a": "TYPE_OMIC",
                   "4b": "TYPE_OCMB_CHIP",
                   "4c": "TYPE_MEM_PORT",
                   "4d": "TYPE_I2C_MUX",
                   "4e": "TYPE_PMIC",
                   "4f": "TYPE_NMMU",
                   "50": "TYPE_PAU",
                   "51": "TYPE_IOHS",
                   "52": "TYPE_PAUC",
                   "53": "TYPE_FC",
                   "54": "TYPE_LPCREFCLKENDPT",
                   "55": "TYPE_GENERIC_I2C_DEVICE",
                   "56": "TYPE_MDS_CTLR",
                   "57": "TYPE_LAST_IN_RANGE"}

    targetTypeStr = "Unknown Type " + i_type

    if i_type.lower() in targetTypes:
        targetTypeStr = targetTypes[i_type.lower()]

    return targetTypeStr


def parseSRCToJson(refcode: str,
                   word2: str, word3: str, word4: str, word5: str,
                   word6: str, word7: str, word8: str, word9: str) -> str:
    """
    SRC parser for Hostboot/HBRT PRD component.
    """

    out = OrderedDict()

    # word6 contains the huid.
    # HUID format (32 bits):
    # 4    4    8        16
    # SSSS NNNN TTTTTTTT iiiiiiiiiiiiiiii
    # S=System
    # N=Node Number
    # T=Target Type (matches TYPE attribute)
    # i=Instance/Sequence number of target, relative to node
    nodeNum = word6[1:2]
    targetType = word6[2:4].lower()
    targetInst = word6[4:8]

    # The signature is word8
    signatureData = SignatureData()
    description = signatureData.parseSignature(targetType, word8.lower())

    # Attention type is the last nibble of word7
    attnType = word7[6:8]

    out["Attention Type"] = attnTypeToStr(attnType)
    out["Node"] = int(nodeNum, 16)
    out["Target Type"] = targetTypeToStr(targetType)
    out["Target Instance"] = int(targetInst, 16)
    out["Signature"] = description

    return json.dumps(out)
