#!/bin/sh
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/setupgithooks.sh $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2023
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

# Each developer runs this from the git_repo base dir, where it will copy the
# needed scripts into .git/hooks/ directory and make them executable.

if [ -d $HOOKSDIR ]
then

    # Get hooks from Gerrit, if needed.
    if [ ! -f $HOOKSDIR/commit-msg ]
    then
        echo "Copying Gerrit hooks..."
        # gerrit needs -O flag as sftp is not enabled
        # get version major number
        # OpenSSH_9.0p1, OpenSSL 1.1.1f  31 Mar 2020
        version=($(ssh -V |& awk -F'[_.]' '{ print $2 }'))
        use_legacy=$(echo "$version >= 9" | bc -l)
        if (( $use_legacy ))
        then
            scp -O -p -q $GERRIT_SRV:hooks/commit-msg $HOOKSDIR
        else
            scp -p -q $GERRIT_SRV:hooks/commit-msg $HOOKSDIR
        fi
    fi

    # Copy custom pre/post commit hooks from tools directory.
    if [ -f "$TOOLSDIR/pre-commit" -a \
         -f "$TOOLSDIR/post-commit" ]
    then
        echo "Copying pre/post commit hooks..."

        cp $TOOLSDIR/pre-commit  $HOOKSDIR/
        cp $TOOLSDIR/pre-commit  $HOOKSDIR/pre-applypatch
        cp $TOOLSDIR/post-commit $HOOKSDIR/

        chmod u+x $HOOKSDIR/pre-commit
        chmod u+x $HOOKSDIR/pre-applypatch
        chmod u+x $HOOKSDIR/post-commit

    else
        echo "Cannot find or access pre or post commit scripts"
        exit 1
    fi

else
    echo "Cannot find or access .git/hooks directory"
    exit 1
fi

exit 0
