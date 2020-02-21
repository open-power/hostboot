#!/bin/sh
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/citest/cxxtest-start.sh $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2020
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
    SBE_STANDALONE_MEASURE_IMG=${STANDALONE_SIMICS}/sbe_measurement_p10.bin.ecc
    SBE_STANDALONE_OTPROM_IMG=${STANDALONE_SIMICS}/sbe_otprom_p10.bin

    export START_SIMICS_CMD="\
        runsim -m ${MACHINE} \
        hb_script_to_run=${STARTUPSIMICS} \
        pnor_img=${STANDALONE}/pnor/P10.pnor \
        sbe_seeprom_img=${SBE_STANDALONE_IMG} \
        sbe_meas_seeprom_img=${SBE_STANDALONE_MEASURE_IMG} \
        sbe_otprom_img=${SBE_STANDALONE_OTPROM_IMG} \
        enable_lpc_console=TRUE \
        fused_core=TRUE \
        xive_gen=2 \
        bmc_files=/host/genEecache:/usr/local/share/pnor/EECACHE \
        eecacheEcc=1"

fi

#   Front end to autocitest - script to execute unit tests under simics.
#
##  when jenkins runs it will create a workspace with the built code tree
##  and drop us into it.
autocitest ${BACKING_BUILD} ${HOSTBOOT_IMG}

exit $?
