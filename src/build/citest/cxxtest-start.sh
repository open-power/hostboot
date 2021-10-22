#!/bin/sh
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/citest/cxxtest-start.sh $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2021
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

    SBE_STANDALONE_IMG=${STANDALONE_SIMICS}/import/boot_roms/sbe_seeprom_p10.bin.ecc
    SBE_STANDALONE_MEASURE_IMG=${STANDALONE_SIMICS}/import/boot_roms/sbe_measurement_p10.bin.ecc
    SBE_STANDALONE_OTPROM_IMG=${STANDALONE_SIMICS}/import/boot_roms/sbe_otprom_p10.bin
    SBE_SCRIPTS_PATH=${STANDALONE_SIMICS}/targets/p10_standalone/sbeTest/
    SBE_SCRIPT_TO_RUN=${SBE_SCRIPTS_PATH}/sbe_startup.simics

    export START_SIMICS_CMD=" runsim -m ${MACHINE}"
    START_SIMICS_CMD+=" hb_script_to_run=${STARTUPSIMICS}"
    START_SIMICS_CMD+=" pnor_img=${STANDALONE}/pnor/P10.pnor"
    START_SIMICS_CMD+=" sbe_seeprom_img=${SBE_STANDALONE_IMG}"
    START_SIMICS_CMD+=" sbe_meas_seeprom_img=${SBE_STANDALONE_MEASURE_IMG}"
    START_SIMICS_CMD+=" sbe_otprom_img=${SBE_STANDALONE_OTPROM_IMG}"
    START_SIMICS_CMD+=" sbe_script_to_run=${SBE_SCRIPT_TO_RUN}"
    START_SIMICS_CMD+=" sbe_scripts_path=${SBE_SCRIPTS_PATH}"
    START_SIMICS_CMD+=" enable_lpc_console=TRUE"
    START_SIMICS_CMD+=" dimm_type=4U"
    START_SIMICS_CMD+=" fused_core=TRUE"
    START_SIMICS_CMD+=" xive_gen=2"
    START_SIMICS_CMD+=" bmc_files=/host/genEecache:/usr/local/share/hostfw/running/81e00679.lid"
    START_SIMICS_CMD+=" eecacheEcc=1"
    #@FIXME-RTC:254475-Remove once this works everywhere
    START_SIMICS_CMD+=" hb_ignoresmpfail=0"

    # If CI job is for DD1 then send the proper simics commandline arg.
    # NOTE: Only care that the variable is set in the environment. Doesn't matter if it's an empty string ""
    #       or anything else. Existence of the var implies user wants DD1 simics. To revert back to default DD2
    #       simics user must unset STANDALONE_TEST_DD1 in their environment.
    if [ -n "${STANDALONE_TEST_DD1+set}" ]; then
        START_SIMICS_CMD+=" dd_major_ver=1"
    fi

    if [ "$HOSTBOOT_PROFILE" ] ; then
        export SIMICS_MORECACHE=1
        START_SIMICS_CMD+=" num_cores_per_chip=8"
    fi
fi

#   Front end to autocitest - script to execute unit tests under simics.
#
##  when jenkins runs it will create a workspace with the built code tree
##  and drop us into it.
autocitest ${BACKING_BUILD} ${HOSTBOOT_IMG}

exit $?
