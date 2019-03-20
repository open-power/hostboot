#!/bin/sh
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/citest/cxxtest-start.sh $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2019
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
if [ -z $HOSTBOOT_CI_ENV_SETUP ];
then
    unset $SANDBOXBASE
    unset $SANDBOXNAME
    source "$PROJECT_ROOT/src/build/citest/setup-env"
fi

HOSTBOOT_IMAGE=img/hbicore_test.bin

# do not set this for anything prior to axone
if [ "$MACHINE" != "NIMBUS" ] && [ "$MACHINE" != "CUMULUS" ] && \
   [ "$MACHINE" != "CUMULUS_CDIMM" ] && [ "$MACHINE" != "FSPBUILD" ];
then
    export PATH=$PATH:$SANDBOXBASE/simics/
    export START_SIMICS_CMD="runsim -m $MACHINE hb_script_to_run=$SANDBOXBASE/obj/ppc/simu/scripts/hbfw/startup.simics pnor_img=$SANDBOXBASE/obj/ppc/hbfw/img/axone.pnor sbe_seeprom_img=$SANDBOXBASE/images/ppc/lab/flash/sbe_seeprom_p9a_10.bin.ecc num_procs=1 vpd_proc=vpd/images/99a8c3fe4e5c74798f5bd4212f3d9a2a"
fi

#   Front end to autocitest - script to execute unit tests under simics.
#
##  when jenkins runs it will create a workspace with the built code tree
##  and drop us into it.
autocitest ${BACKING_BUILD} ${HOSTBOOT_IMAGE}

exit $?
