#!/bin/sh
#
#   Front end to autosample - script to execute unit tests under simics.
#   2011-06-02  mww Initial (working) checkin
#

##  does gerrit export env vars for workspace???
##  when gerrit runs it will create a workspace with the built code tree
##  and drop us into it.
export  WORKSPACE_DIR=`pwd`
export  AUTOSAMPLE="/gsa/ausgsa/projects/h/hostboot/test/autosample"
CXXTEST_REMOTE_SANDBOX="cxxtest_sb"

if [ "$HOSTNAME" == "" ] ; then
    echo "no HOSTNAME??"
    export  HOSTNAME=`hostname`
fi


##  klog to get access to simics tools
AFSPASSWD="/gsa/ausgsa/projects/h/hostboot/gerrit-server/afspasswd.sh"
$AFSPASSWD | klog -cell austin -pipe
$AFSPASSWD | klog -cell rchland -pipe

##  This will create a sandbox inside the Gerrit workspace and run simics UT
##  usage: autosample [--quiet] <backing-tree-dir> <sandbox-name> <hbicore_test.bin-image-from-make>
## /gsa/ausgsa/projects/h/hostboot/test/autosample /esw/fips740/Builds/b0513a_1121.740 cxxtest_sb  $GERRIT_WS_DIR/img/hbicore_test.bin

##  run autosample to run simics unit tests
##  NOTE:  this assumes that someone has copied hbicore_test.bin and hbicore_test.syms $WORKSPACE_DIR/img directory
##  usage: autosample [--quiet] <backing-tree-dir> <sandbox-name> <hbicore_test.bin-image-from-make>
$AUTOSAMPLE /esw/fips740/Builds/b0513a_1121.740 $CXXTEST_REMOTE_SANDBOX $WORKSPACE_DIR/img/hbicore_test.bin

echo "Done."

