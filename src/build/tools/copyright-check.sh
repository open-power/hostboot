#!/bin/sh
#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/tools/copyright-check.sh $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2011
#
#  p1
#
#  Object Code Only (OCO) source materials
#  Licensed Internal Code Source Materials
#  IBM HostBoot Licensed Internal Code
#
#  The source code for this program is not published or other-
#  wise divested of its trade secrets, irrespective of what has
#  been deposited with the U.S. Copyright Office.
#
#  Origin: 30
#
#  IBM_PROLOG_END

#
#   Front end to addCopyright.pl - script to check for copyright block during
#   Gerrit checkin.  
#

export WORKSPACE_DIR=`pwd`
export ADDCOPYRIGHT=${WORKSPACE_DIR}/src/build/tools/addCopyright.pl

##  run git show to get a list of checked in files
CHECKINFILES=`git show --pretty=format: --name-only -n1 | tr '\n' ' '`

echo "========================================================================"

echo "  Checking Copyright blocks for checked-in files:"
echo "  $CHECKINFILES"
echo
$ADDCOPYRIGHT validate  $CHECKINFILES

if [ $? -eq 0 ]; then
    echo "Copyright Check passed OK, $?"
    exit 0
else       
    echo "ERROR: $?" 
    exit 1
fi
