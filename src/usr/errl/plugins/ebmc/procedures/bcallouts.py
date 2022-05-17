# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/errl/plugins/ebmc/procedures/bcallouts.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2022
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
"""
@file bcallouts.py

@brief This plugin will decode the hostboot procedures.
       Descriptions come from eBMC Isolation Procedures document
"""
import json

procedures = {
    "HB00001": [
        "A part that is vital to the system function is unconfigured and ",
        "is causing secondary errors to occur.  Review the system error logs ",
        "for errors that include parts in their failing item list that are ",
        "relevant to each reasoncode."
    ],

    "HB00004": [
        "A problem has been detected in the eBMC firmware."
    ],

    "HB00005": [
        "The eBMC has detected a problem in the platform firmware."
    ],

    "HB00008": [
        "A problem was detected with a system processor module, ",
        "but it cannot be isolated to a specific system processor module."
    ],

    "HB00009": [
        "A problem was detected with a memory DIMM, but it cannot be isolated "
        "to a specific memory DIMM."
    ],

    "HB0000A": [
        "A part that is required for system operation is not valid or is missing."
    ],

    "HB00010": [
        "Save any dump data and contact your next level of support for assistance."
    ],

    "HB00011": [
        "A system uncorrectable error has occurred."
    ],

    "HB00022": [
        "Memory modules are plugged in a configuration that is not valid."
    ],

    "HB0002D": [
        "The system detected an error with a firmware peripheral interface bus."
    ],

    "HB00037": [
        "A problem was detected on the bus between two parts."
    ],

    "HB0003F": [
        "The system has experienced a power error.  ",
        "Please review previous error logs for power-related issues."
    ],

    "HB0004F": [
        "Look for uncorrectable memory errors in the serviceable event view ",
        "that were logged at about the same time as this error and resolve them.  ",
        "If there are no uncorrectable memory errors logged, replace the system ",
        "processor module."
    ],

    "HB00055": [
        "A problem was detected during the early boot process."
    ],

    "HB00056": [
        "A diagnostic function detected a problem with the time of day or ",
        "clock function."
    ],

    "HB0005C": [
        "The eBMC detected an over temperature condition."
    ],

    "HB0005D": [
        "The signature of a system firmware module could not be verified."
    ],

    "HB00062": [
        "A problem was detected in the system processor module firmware."
    ]
}

def getMaintProcDesc(procedure: str) -> str:
    if procedure in procedures:
        return json.dumps(procedures[procedure])
    return ''
