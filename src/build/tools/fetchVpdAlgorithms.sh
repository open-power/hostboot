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

echo "Fetching and applying the VPD ECC algorithm files:"

while :
do
    # Get the absolute path to the HB repo
    REPO_ABSOLUTE_PATH=$(git rev-parse --show-toplevel)
    RET_VAL=$?

    # If an issue getting the absolute path to the project, then exit while loop
    if [[ $RET_VAL -ne 0 ]]; then
        break
    fi

    # Confirm existence of the VPD directory within the project via an absolute path
    VPD_ABSOLUTE_PATH="${PROJECT_ROOT}/src/usr/vpd"
    if [[ ! -d  "$VPD_ABSOLUTE_PATH" ]]; then
        echo "VPD directory '$VPD_ABSOLUTE_PATH' does not exist"

        # OS error code 2 `perror 2`: No such file or directory
        RET_VAL=2
        break
    fi

    ## Attempt to apply files
    #  Fetch the changes
    `git fetch ssh://hostboot.gerrit/hostboot refs/changes/54/112054/1`
    RET_VAL=$?
    # If an error occurred while fetching the commit, then exit while loop
    if [[ $RET_VAL -ne 0 ]]; then
        break
    fi

    # Create a patch from the FETCH_HEAD reference and apply the patch
    `git format-patch -1 --stdout FETCH_HEAD -p | git apply --verbose`
    RET_VAL=$?
    # If an error occurred while applying the patch, then exit while loop
    if [[ $RET_VAL -ne 0 ]]; then
        break
    fi

    # If made it this far, then files have been patched
    RET_VAL=0
    break;
done

if [[ $RET_VAL -ne  0 ]]; then
    echo "Unexpected error retrieving the VPD ECC algorithm files:"
    echo "     vpdecc.c, vpdecc.h, vpdecc_support.c and vpdecc_support.h"
fi

exit $RET_VAL
