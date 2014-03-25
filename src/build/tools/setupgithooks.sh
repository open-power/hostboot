#!/bin/sh
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/setupgithooks.sh $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2011,2014
#
# p1
#
# Object Code Only (OCO) source materials
# Licensed Internal Code Source Materials
# IBM HostBoot Licensed Internal Code
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# Origin: 30
#
# IBM_PROLOG_END_TAG

# Each developer runs this from the git_repo base dir, where it will copy the
# needed scripts into .git/hooks/ directory and make them executable.

# Setup some global variables
HOOKSDIR=$HOSTBOOTROOT/.git/hooks
TOOLSDIR=$HOSTBOOTROOT/src/build/tools
HB_SRV=hostboot.gerrit

if [ -d $HOOKSDIR ]
then

    # Get hooks from Gerrit, if needed.
    if [ ! -f $HOOKSDIR/commit-msg ]
    then
        echo "Copying Gerrit hooks..."
        scp -p -q $HB_SRV:hooks/commit-msg $HOOKSDIR
    fi

    # Copy custom pre/post commit hooks from tools directory.
    if [ -f "$TOOLSDIR/pre-commit" -a -f "$TOOLSDIR/post-commit" ]
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
