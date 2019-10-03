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

if [ -z $HOSTBOOT_CI_ENV_SETUP ];then
    unset $SANDBOXBASE
    unset $SANDBOXNAME
    source "$PROJECT_ROOT/src/build/citest/setup-env"
fi

HOSTBOOT_IMG=/img/hbicore_test.bin

echo "autocitest setup"

if [[ $SETUP_FOR_STANDALONE -eq 1 ]];then

    echo "autocitest setup for P10 STANDALONE"

    # Env. vars. for startup.simics and hb-tools scripts
    export HBBLPATH=${STANDALONE}/pnor/hbbl.bin
    export HBICORE_EXTENDED_PATH=${STANDALONE}/staging/hbicore_extended.bin
    export STARTUPSIMICS=${STANDALONE_SIMICS}/hbfw/startup.simics

    export PATH=${STANDALONE_SIMICS}:${PATH}

    SBE_STANDALONE_IMG=${STANDALONE_SIMICS}/sbe_seeprom_p10.bin.ecc

    export START_SIMICS_CMD="\
        runsim -m ${MACHINE} \
        hb_script_to_run=${STARTUPSIMICS} \
        pnor_img=${STANDALONE}/pnor/P10.pnor \
        sbe_seeprom_img=${SBE_STANDALONE_IMG} \
        sbe_boot_mem=seeprom \
        enable_lpc_console=TRUE \
        fused_core=TRUE \
        xive_gen=2"

else
    # do not set this for FSP build
    if [ "$MACHINE" != "FSPBUILD" ];then

        echo "autocitest setup for non-FSP and non-P10 Standalone"

        # Env. vars. for startup.simics and hb-tools scripts
        export HBBLPATH=${SANDBOXBASE}/obj/ppc/hbfw/img/hbbl.bin
        export HBICORE_EXTENDED_PATH=${SANDBOXBASE}/src/hbfw/img/hostboot_extended.bin
        export STARTUPSIMICS=$SANDBOXBASE/obj/ppc/simu/scripts/hbfw/startup.simics
        export PATH=$PATH:$SANDBOXBASE/simics/
        SBE_SEEPROM_IMG=/gsa/ausgsa/projects/h/hostboot/simbuild/SBE_19b2530_HB_c391a8a_sbe_seeprom_p10.bin.ecc

        export START_SIMICS_CMD="\
            runsim -m $MACHINE \
            hb_script_to_run=${STARTUPSIMICS} \
            pnor_img=$SANDBOXBASE/obj/ppc/hbfw/img/p10.pnor \
            sbe_seeprom_img=${SBE_SEEPROM_IMG} \
            sbe_boot_mem=seeprom \
            enable_lpc_console=TRUE \
            fused_core=TRUE \
            xive_gen=2"
    fi
fi

#   Front end to autocitest - script to execute unit tests under simics.
#
##  when jenkins runs it will create a workspace with the built code tree
##  and drop us into it.
autocitest ${BACKING_BUILD} ${HOSTBOOT_IMG}

exit $?
