#!/bin/sh
#
#   Front end to autocitest - script to execute unit tests under simics.
#

##  when jenkins runs it will create a workspace with the built code tree
##  and drop us into it.

export WORKSPACE_DIR=`pwd`
export AUTOCITEST=${WORKSPACE_DIR}/src/build/citest/autocitest
export BACKING_BUILD=`cat ${WORKSPACE_DIR}/src/build/citest/etc/bbuild`
CXXTEST_REMOTE_SANDBOX="cxxtest_sb"
HOSTBOOT_IMAGE=img/hbicore_test.bin

##  klog to get access to simics tools
AFSPASSWD="/gsa/ausgsa/projects/h/hostboot/gerrit-server/afspasswd.sh"
$AFSPASSWD | klog -cell austin -pipe
$AFSPASSWD | klog -cell rchland -pipe

$AUTOCITEST ${BACKING_BUILD} ${CXXTEST_REMOTE_SANDBOX} ${HOSTBOOT_IMAGE}

exit $?
