# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/ebmc/miscUtils.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020,2022
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
@file miscUtils.py

@brief A plugin for miscellaneous utilities/functions such as
       finding a lid file which can be used by the other
       tracing plugins.
"""


import os.path   # Used in getLid function
import os
import site

# Global variable to hold search directories for the LIDs and in what order to search
# Listed in order of priority, i.e. HOSTBOOT_TRACE_DIR takes highest priority if found, etc.
LID_SEARCH_DIRS = [ os.getenv('HOSTBOOT_TRACE_DIR'),                    # ENV VAR OVERRIDE HOSTBOOT
                    os.getenv('SBE_TRACE_DIR'),                         # ENV VAR OVERRIDE SBE
                    os.path.join(site.USER_BASE, 'hostboot_data'),      # data_files exported from Hostboot
                    os.path.join(site.USER_BASE, 'sbe_data'),           # data_files exported from SBE
                    "/usr/local/share/hostfw/running",                  # The BMC patch directory
                    "/var/lib/phosphor-software-manager/hostfw/running" # The BMC running directory
                  ]

# lid_dict is used to allow either lid names or raw file names to be found
# Users using HOSTBOOT_TRACE_DIR may opt for just copying from development builds, etc.
lid_dict = {
    "81e00685.lid" : "hbotStringFile",
    "81e00686.lid" : "hbicore.syms",
    "81e0068a.lid" : "sbeStringFile",
}

""" Searches the directories in the list 'LID_SEARCH_DIRS' for the given
    input LID file name, lidFileName.
    If found will return the path to the file plus filename back to caller.
    If not found will return back to caller an empty string ("").

@param[in] lidFileName: string - name of the LID file to search for
@returns: If LID file found, then a string containing the path to file plus filename
          is returned.
          If LID file *not* found, then an empty string ("") is returned
"""
def getLid(lidFileName):
    # Default the return value to an empty string ("") until file has been found
    lidFileNameWithPath = ""

    # Retrieve the LID from the search path, if found
    for path in LID_SEARCH_DIRS:

        if path: # if ENV VAR does not exist we get None, so need to validate first
            primary_lid = os.path.join(path, lidFileName)
            try:
                alternate_file = os.path.join(path, lid_dict[lidFileName])
            except Exception as e:
                # this can happen if someone calls this routine with an
                # unsupported lidFileName (a name not in the lid_dict)
                # this will eventually fail in isfile below
                alternate_file = ""
            if os.path.isfile(primary_lid):
                lidFileNameWithPath = primary_lid
                break
            else:
                if os.path.isfile(alternate_file):
                    lidFileNameWithPath = alternate_file
                    break

    return lidFileNameWithPath

