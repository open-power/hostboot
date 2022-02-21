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

# Global variable to hold search directories for the LIDs and in what order to search
LID_SEARCH_DIRS = [ "/usr/local/share/hostfw/running",     # The BMC patch directory
                    "/var/lib/phosphor-software-manager/hostfw/running" # The BMC running directory
                  ]

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
        if os.path.exists(path + '/' + lidFileName):
            lidFileNameWithPath = path + '/' + lidFileName
            break

    return lidFileNameWithPath

