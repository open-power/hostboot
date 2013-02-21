#!/bin/sh
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/setupgithooks.sh $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2011,2013
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

#   each developer runs this from the git_repo base dir.  
#   will copy the scripts into .git/hooks/ dir and make them runnable

ROOTDIR=.
TOOLSDIR=$ROOTDIR/src/build/tools
preCommitScript=pre-commit-prologs
addCopyrightScript=addCopyright.pl

if [ -f "$TOOLSDIR/$preCommitScript" ]
then
    if [ -d ".git/hooks" ]
    then
        echo "copy files into .git/hooks dir..."
        cp -v $ROOTDIR/src/build/tools/pre-commit          $ROOTDIR/.git/hooks/.
        cp -v $ROOTDIR/src/build/tools/pre-commit          $ROOTDIR/.git/hooks/pre-applypatch
        cp -v $ROOTDIR/src/build/tools/$preCommitScript    $ROOTDIR/.git/hooks/.
        cp -v $ROOTDIR/src/build/tools/$addCopyrightScript $ROOTDIR/.git/hooks/.
        
        chmod u+x $ROOTDIR/.git/hooks/pre-commit
        chmod u+x $ROOTDIR/.git/hooks/pre-applypatch
        chmod u+x $ROOTDIR/.git/hooks/$preCommitScript
        chmod u+x $ROOTDIR/.git/hooks/addCopyright.pl
        
    else
        echo "Does not appear that the current working directory is the root of a git repository\n"
        exit 1
    fi
else
    echo "Cannot find or access $preCommitScript\n"
    exit 1
fi

exit 0
