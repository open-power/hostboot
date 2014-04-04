#!/bin/sh
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/citest/cxxtest-start.sh $
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
export WORKSPACE_DIR=`pwd`
export COPYRIGHT_CHECK=${WORKSPACE_DIR}/src/build/tools/copyright-check.sh
export AUTOCITEST=${WORKSPACE_DIR}/src/build/citest/autocitest
export BACKING_BUILD=`cat ${WORKSPACE_DIR}/src/build/citest/etc/bbuild`
HOSTBOOT_IMAGE=img/hbicore_test.bin

if [ -z $JOB_NAME -o -z $BUILD_NUMBER ];
then
    CXXTEST_REMOTE_SANDBOX="cxxtest_sb"
else
    CXXTEST_REMOTE_SANDBOX=`echo $JOB_NAME $BUILD_NUMBER | md5sum | head -c10`
fi

#
#   Validate Copyright blocks
if [ -f $COPYRIGHT_CHECK ]; then
    $COPYRIGHT_CHECK
    if [ $? -ne 0 ]; then
        exit 1
    fi
fi

#
#   Front end to autocitest - script to execute unit tests under simics.
#
##  when jenkins runs it will create a workspace with the built code tree
##  and drop us into it.



##  klog to get access to simics tools
AFSPASSWD="/gsa/ausgsa/projects/h/hostboot/gerrit-server/afspasswd.sh"
$AFSPASSWD | klog -cell austin -pipe
$AFSPASSWD | klog -cell rchland -pipe

$AUTOCITEST ${BACKING_BUILD} ${CXXTEST_REMOTE_SANDBOX} ${HOSTBOOT_IMAGE}

exit $?
