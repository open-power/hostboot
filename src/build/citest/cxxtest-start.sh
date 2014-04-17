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
if [ -z $HOSTBOOT_CI_ENV_SETUP ];
then
    source "$HOSTBOOTROOT/src/build/citest/setup-env"
fi

HOSTBOOT_IMAGE=img/hbicore_test.bin

#   Front end to autocitest - script to execute unit tests under simics.
#
##  when jenkins runs it will create a workspace with the built code tree
##  and drop us into it.
autocitest ${BACKING_BUILD} ${HOSTBOOT_IMAGE}

exit $?
