#!/bin/sh
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/fetchVpdAlgorithms.sh $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2021
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

#
# This script will fetch the VPD ECC algorithm files vpdecc.h/.c and
# vpdecc_support.h/.c and place the files into directory src/usr/vpd.  This is
# not a patch, whereas a patch will create a git log of the tracked files.  This
# script will only get the files and place them in said directory.  When used
# in conjunction with a .gitignore file, these files will not be tracked or seen
# by the command 'git status'.
#

# Assume any commnds that run, passed (0)
RET_VAL=0

# Set this to 1 for verbose tracing
DEBUG_INFO=0

echo "Fetching and applying the VPD ECC algorithm files:"

while :
do
    # Get the absolute path to the repo
    REPO_HOME=$(git rev-parse --show-toplevel 2>&1)
    RET_VAL=$?

    # If could not get absolute path to repo, then exit while loop
    if [[ $RET_VAL -ne 0 ]]; then
        if [[ $DEBUG_INFO -ne 0 ]]; then
            echo "Command 'git rev-parse --show-toplevel' failed:"
            echo "$REPO_HOME"
        fi

        break
    fi

    # Confirm existence of the VPD directory
    VPD_DIR="${REPO_HOME}/src/usr/vpd"
    if [[ ! -d  "$VPD_DIR" ]]; then
        if [[ $DEBUG_INFO -ne 0 ]]; then
            echo "Destination directory '$VPD_DIR' does not exist"
        fi

        # OS error code 2 `perror 2`: No such file or directory
        RET_VAL=2
        break
    fi

    # If any of the files exist, the 'git apply' command below will error out.
    # This is not necessarily an issue, it is just erroring out because the files exist.
    # Considering that there is no force option on the 'git apply' command, will
    # issue a warning to caller because an error message may be misleading.
    if [[  -f "${VPD_DIR}/vpdecc.c"         || -f "${VPD_DIR}/vpdecc.h"  ||
           -f "${VPD_DIR}/vpdecc_support.c" || -f "${VPD_DIR}/vpdecc_support.h" ]]; then
        echo -e "Warning: One, if not all, of these files vpdecc.c, vpdecc.h, vpdecc_support.c\n" \
                "and/or vpdecc_support.h exists in directory ${VPD_DIR}\n"                       \
                "Cannot patch any of these files if any one exists.\n"                           \
                "If patch must be applied then try 'make clean', 'make clobber' or remove files by hand."

        # Exit loop and do not continue
        RET_VAL=0
        break
    fi

    ## Attempt to apply files
    #  Fetch the changes
    RESULTS=$(git fetch ssh://hostboot.gerrit/hostboot refs/changes/54/112054/1 2>&1)
    RET_VAL=$?
    # If an error occurred while fetching the commit, then exit while loop
    if [[ $RET_VAL -ne 0 ]]; then
        if [[ $DEBUG_INFO -ne 0 ]]; then
            echo "Command 'git fetch ssh://hostboot.gerrit/hostboot refs/changes/54/112054/1' failed:"
            echo "$RESULTS"
        fi

        # No valid OS error code, will use generic code 1 `perror 1`: Operation not permitted
        RET_VAL=1
        break
    fi

    # Create a patch from the FETCH_HEAD reference and apply the patch
    RESULTS=$(git format-patch -1 --stdout FETCH_HEAD -p | git apply 2>&1)
    RET_VAL=$?
    # If an error occurred while applying the patch, then exit while loop
    if [[ $RET_VAL -ne 0 ]]; then
        if [[ $DEBUG_INFO -ne 0 ]]; then
            echo "Command 'git format-patch -1 --stdout FETCH_HEAD -p | git apply ' failed:"
            echo "$RESULTS"
        fi

        # No valid OS error code, will use generic code 1 `perror 1`: Operation not permitted
        RET_VAL=1
        break
    fi

    # If made it this far, then files have been patched
    RET_VAL=0
    break;
done

if [[ $RET_VAL -eq  0 ]]; then
    echo "Patched VPD ECC algorithm files:"
    echo "    ${VPD_DIR}/vpdecc.c"
    echo "    ${VPD_DIR}/vpdecc.h"
    echo "    ${VPD_DIR}/vpdecc_support.c"
    echo "    ${VPD_DIR}/vpdecc_support.h"
else
    echo "Unexpected error retrieving the VPD ECC algorithm files:"
    echo "     vpdecc.c, vpdecc.h, vpdecc_support.c and vpdecc_support.h"
fi

exit 0
