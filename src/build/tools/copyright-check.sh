#!/bin/sh
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/copyright-check.sh $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2020
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
#   Front end to addCopyright - script to check for copyright block during
#   Gerrit checkin.
#

if git log -n1 | grep -c git-subtree-dir; then
    echo "Skipping copyright check on commits with git-subtree-dir tag"
    exit 0
fi

export WORKSPACE_DIR=`pwd`
export ADDCOPYRIGHT=${WORKSPACE_DIR}/src/build/tools/addCopyright

##  run git show to get a list of checked in files
CHECKINFILES=`git show --pretty=format: --name-only -n1 | tr '\n' ' '`

echo "========================================================================"

echo "  Checking Copyright blocks for checked-in files (with $ADDCOPYRIGHT):"
echo "  $CHECKINFILES"
echo
echo $ADDCOPYRIGHT validate  $CHECKINFILES --copyright-check
$ADDCOPYRIGHT validate  $CHECKINFILES --copyright-check

if [ $? -eq 0 ]; then
    echo "Copyright Check passed OK, $?"
    exit 0
else
    echo "ERROR: $?"
    exit 1
fi
