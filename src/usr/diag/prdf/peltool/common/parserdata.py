# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/peltool/common/parserdata.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2021,2023
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
import glob
import json
import os
import re
from collections import OrderedDict

import pel.prd.regdata
import pel.prd.sigdata


class SignatureData:
    """
    The human readable output for signature descriptions are stored in JSON data
    files. This class is simply a wrapper to access the data files and provide
    functions for data needed by Hostboot/HBRT PRD.
    """

    def __init__(self):
        """
        Reads and stores all the JSON data files from `pel.prd.sigdata`.
        """
        self._data = {}

        data_path = os.path.dirname(pel.prd.sigdata.__file__)

        for data_file in glob.glob(os.path.join(data_path, "*.json")):
            with open(data_file, "r") as fp:
                data = json.load(fp)

            self._data[data["target_type"]] = data

    def parseSignature(self, chipId: str, chipSig: str) -> str:
        # convert the input chipId to int and back to a hex string to prevent
        # possible issues with preceding 0s in the string
        intId = int(chipId, 16)
        hexId = hex(intId)

        # The input chip signature will be a hex string but without
        # the preceding '0x' so add that here. Also, we will ensure we have
        # lower case hex strings
        chipType = hexId.lower()
        hexSig = "0x" + chipSig.lower()

        signature = "Undefined error code " + hexSig

        # Check for any special error codes that can be associated with any
        # FIR bit. These only take into account the last 16 bits (4 characters).
        errCodeMap = {
            "dd00": "Assert failed in PRD",
            "dd01": "Invalid attention type passed to PRD",
            "dd02": "No active error bits found",
            "dd03": "Chip connection lookup failure",
            "dd05": "Internal PRD code",
            "dd09": "Fail to access attention data from registry",
            "dd11": "SRC Access failure",
            "dd12": "HWSV Access failure",
            "dd20": "Config error - no domains in system",
            "dd21": "No active attentions found",
            "dd23": "Unknown chip raised attention",
            "dd24": "PRD Model is not built",
            "dd28": "PrdStartScrub failure",
            "dd29": "PrdResoreRbs failure",
            "dd81": "Multiple bits on in Error Register",
            "dd90": "Scan comm access from Error Register failed",
            "dd91": "SCOM access failed due to Power Fault",
            "ddff": "Do not reset or mask FIR bits",
        }
        last4 = hexSig[-4:]

        if last4 in errCodeMap:
            signature = errCodeMap[last4]
        elif chipType in self._data:
            if hexSig in self._data[chipType]["signatures"]:
                signature = self._data[chipType]["signatures"][hexSig]

        return signature


class RegisterData:
    """
    The human readable output for signature descriptions are stored in JSON data
    files. This class is simply a wrapper to access the data files and provide
    functions for data needed by Hostboot/HBRT PRD.
    """

    def __init__(self):
        """
        Reads and stores all the JSON data files from `pel.prd.regdata`.
        """
        self._data = {}

        data_path = os.path.dirname(pel.prd.regdata.__file__)

        for data_file in glob.glob(os.path.join(data_path, "*.json")):
            with open(data_file, "r") as fp:
                data = json.load(fp)

            self._data[data["target_type"]] = data

    def parseRegister(self, chipId: str, regId: str) -> dict:
        # convert the input chipId to int and back to a hex string to prevent
        # possible issues with preceding 0s in the string
        intId = int(chipId, 16)
        hexId = hex(intId)

        # The input register ID will be a hex string but without
        # the preceding '0x' so add that here. Also, we will ensure we have
        # lower case hex strings
        chipType = hexId.lower()
        hashReg = "0x" + regId.lower()

        register = {"name": "Undefined Register Hash", "address": hashReg}

        if chipType in self._data:
            if hashReg in self._data[chipType]:
                register = self._data[chipType][hashReg]

        return register
