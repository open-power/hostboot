# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/peltool/common/parserdata.py $
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
from collections import OrderedDict
import glob
import json
import os
import re

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

        data_path = os.path.dirname(pel.pel.sigdata.__file__)

        for data_file in glob.glob(os.path.join(data_path, '*.json')):
            with open(data_file, 'r') as fp:
                data = json.load(fp)

            self._data[data["target_type"]] = data


    # TODO: add parser function


