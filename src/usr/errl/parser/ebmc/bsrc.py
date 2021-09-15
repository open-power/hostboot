# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/errl/parser/ebmc/bsrc.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020,2021
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
import importlib
import json

from srcparsers.bsrc.srcdisplaydata import srcInfo

def parseSRCToJson(refcode: str,
                   word2: str, word3: str, word4: str, word5: str,
                   word6: str, word7: str, word8: str, word9: str) -> str:
    """
    SRC parser for Hostboot/HBRT generated PELs.

    This returns a string containing formatted JSON data. The data is simply
    appended to the end of the "Primary SRC" section of the PEL and will not
    impact any other fields in that section.

    IMPORTANT:
    Components can define parser modules just like those defined for user data
    sections. If a parser module is not defined in this fashion, the default SRC
    parser will be used.

    To define a parser module for a component, create an SRC parser module with
    a path in the following format:

        srcparsers/<subsystem><component>/<subsystem><component>.py

    Where the <subsystem> is 'b' for Hostboot/HBRT and <component> is the four
    character component ID in the format `xx00`, where `xx` is the component ID
    in lower case (example: e500). Then add this same function definition to
    the new module.
    """

    # Search for an SRC parser module for this component. The component ID can
    # be pulled from the third byte of the reference code.
    subsystem = 'b'
    component = subsystem + refcode[4:6].lower() + '00'
    module_name = '.'.join(['srcparsers', component, component])

    try:
        # Grab the module if it exists. If not, it will throw an exception.
        module = importlib.import_module(module_name)

    except ModuleNotFoundError:
        # A module for this component does not exist. Use the default parser.

        #refcode is in the form: Bsxxyyyy
        #where yyyy = Comp ID + Reasoncode

        #word3 is in the form: ssssmmrr
        #where mm = Module ID

        #Get dictionary for corresponding Comp ID + Reasoncode + Mod ID
        d = srcInfo.get(int(refcode[4:8] + word3[4:6], 16))

        out = json.dumps(d, indent = 2)

    else:
        # The module was found. Call the component parser in that module.
        out = module.parseSRCToJson(refcode,
                                    word2, word3, word4, word5,
                                    word6, word7, word8, word9)

    return out


