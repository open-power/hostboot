# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/p10/procedures/ppe/fw_tools/srcparsers/b2f00/b2f00.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2023
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

"""Automatically generated by XGPE ./genErrlSrcInfo.py	"""
srcInfo = { 

    "2F05-0003-0000": { "devdesc":  " XGPE had a SCOM failure",
                "moduleid":   "XGPE_HCODE_SCOM",
                    "reasoncode": "XGPE_SCOM_MACHINE_CHECK_ERROR",
                    "userdata1":  "EDR",
                    "userdata2":  "SRR0",
                    "userdata3":  "SPRG0",
                    "userdata4":  "0x0000",
            },

    "2F06-0004-0000": { "devdesc":  " Critical Error Detected from PGPE",
                "moduleid":   "XGPE_MODID_HANDLE_PGPE_ERRL",
                    "reasoncode": "XGPE_RC_PGPE_CRITICAL_ERR",
                    "userdata1":  "SRR0",
                    "userdata2":  "LR",
                    "userdata3":  "CTR",
                    "userdata4":  "0x0000",
            },

    "2F03-0001-0000": { "devdesc":  " XGPE detected a failure downloading QME error log",
                "moduleid":   "XGPE_MODID_HANDLE_QME_ERRL",
                    "reasoncode": "XGPE_RC_QME_ERR_DOWNLOAD",
                    "userdata1":  "QME Quad Id",
                    "userdata2":  "QME Error Code",
                    "userdata3":  "Failure Status",
                    "userdata4":  "0x0000",
            },

    "2F02-0001-0000": { "devdesc":  " XGPE detected a QME fault error log",
                "moduleid":   "XGPE_MODID_HANDLE_QME_ERRL",
                    "reasoncode": "XGPE_RC_QME_CRITICAL_ERR",
                    "userdata1":  "QME Quad Id",
                    "userdata2":  "QME Error Code",
                    "userdata3":  "Failed Cores",
                    "userdata4":  "0x0000",
            },

    "2F04-0002-0000": { "devdesc":  " XGPE detected an user error injection",
                "moduleid":   "XGPE_MODID_FIT_HANDLER",
                    "reasoncode": "XGPE_RC_HCODE_ERR_INJECT",
                    "userdata1":  "OCC Flag 3",
                    "userdata2":  "Error Pattern",
                    "userdata3":  "Error Pattern",
                    "userdata4":  "0x0000",
            },

} 


import importlib
import json

def parseSRCToJson(refcode: str,

            word2: str, word3: str, word4: str, word5: str,
            word6: str, word7: str, word8: str, word9: str) -> str:
        """
        SRC parser for XGPE generated PELs.

        This returns a string containing formatted JSON data. The data is simply
        appended to the end of the "Primary SRC" section of the PEL and will not
        impact any other fields in that section.        """
        #refcode is in the form: Bsxxccrr
        #where cc = Component ID
        #rr = Reason Code
        #word9 (userdata4) is in the form: mmmmeeee
        #where mmmm = XGPE Module ID
        #eeee = XGPE Extended Reason Code
        #Search dictionary for corresponding key: ccrr-mmmm-eeee
        d = srcInfo.get(refcode[4:8] + '-' + word9[0:4] + '-' + word9[4:8])
        out = json.dumps(d, indent = 2)
        return out


if  __name__ == "__main__":
        word2 = "000000E0"
        word3 = "00000200"
        word4 = "00000000"
        word5 = "00200000"
        word6 = "02000000"
        word7 = "DEADBEEF"
        word8 = "DEADBEEF"
        word9 = "00020000"

        out = parseSRCToJson( "BC102F04",
                    word2,
                    word3,
                    word4,
                    word5,
                    word6,
                    word7,
                    word8,
                    word9 )
        print(out)
