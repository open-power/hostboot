#!/bin/sh
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/copyright-check.sh $
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

#
#   Front end to addCopyright.pl - script to check for copyright block during
#   Gerrit checkin.  
#

export WORKSPACE_DIR=`pwd`
export ADDCOPYRIGHT=${WORKSPACE_DIR}/src/build/tools/addCopyright.pl

##  run git show to get a list of checked in files
CHECKINFILES=`git show --pretty=format: --name-only -n1 | tr '\n' ' '`
##  use git log to determine the year of the commit.
##     Since commits have their copyright updated at the time they are
##     committed, a commit might have a copyright date in its prolog of
##     last year.  Set the DATE_OVERRIDE variable to the 'validate' to allow
##     slightly-old prologs (ie. ones corresponding to the date in the msg).
export DATE_OVERRIDE=`git log -n1 --date=short | grep "Date" | sed "s/Date: *//" | sed "s/-.*//"`

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
