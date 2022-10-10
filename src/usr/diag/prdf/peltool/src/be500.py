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


def huidToStr(huid: str) -> str:

    # HUID format (32 bits):
    # 4    4    8        16
    # SSSS NNNN TTTTTTTT iiiiiiiiiiiiiiii
    # S=System
    # N=Node Number
    # T=Target Type (matches TYPE attribute)
    # i=Instance/Sequence number of target, relative to node
    node_inst = int(huid[1:2], 16)
    target_type = int(huid[2:4], 16)
    target_inst = int(huid[4:8], 16)

    chips = {
        0x05: 'proc',  # TYPE_PROC
        0x4b: 'ocmb',  # TYPE_OCMB_CHIP
    }

    if target_type in chips:
        return f'node {node_inst} {chips[target_type]} {target_inst}'

    proc_units = {
        # autopep8: off
        0x07: ('core', 32),  # TYPE_CORE
        0x23: ('eq'  ,  8),  # TYPE_EQ
        0x2d: ('pec' ,  2),  # TYPE_PEC
        0x2e: ('phb' ,  6),  # TYPE_PHB
        0x44: ('mc'  ,  4),  # TYPE_MC
        0x49: ('mcc' ,  8),  # TYPE_MCC
        0x4a: ('omic',  8),  # TYPE_OMIC
        0x4f: ('nmmu',  2),  # TYPE_NMMU
        0x50: ('pau' ,  8),  # TYPE_PAU
        0x51: ('iohs',  8),  # TYPE_IOHS
        0x52: ('pauc',  4),  # TYPE_PAUC
        # autopep8: on
    }

    if target_type in proc_units:
        unit_type, units_per_proc = proc_units[target_type]
        proc_inst = target_inst // units_per_proc
        unit_inst = target_inst % units_per_proc
        return f'node {node_inst} proc {proc_inst} {unit_type} {unit_inst}'

    # Just in case we fail to parse the HUID.
    return f'node {node_inst} type 0x{target_type:02x} inst {target_inst}'


def parseSRCToJson(refcode: str,
                   word2: str, word3: str, word4: str, word5: str,
                   word6: str, word7: str, word8: str, word9: str) -> str:
    """
    SRC parser for Hostboot/HBRT PRD component.
    """

    out = OrderedDict()

    # The HUID is word6.
    out["Target Desc"] = huidToStr(word6)

    # The target type is the second byte of the HUID.
    # The signature is word8.
    out["Signature"] = SignatureData().parseSignature(word6[2:4], word8)

    # The attention type is the last byte of word7.
    out["Attn Type"] = attnTypeToStr(word7[6:8])

    return json.dumps(out)
