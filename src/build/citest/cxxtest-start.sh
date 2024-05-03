#!/bin/sh
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/citest/cxxtest-start.sh $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2024
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

    PPE_SUBREPO_TOP_COMMIT=$(git submodule status src/build/tools/extern/ppe | awk '{print $1}' | sed 's/^-//')
    PPE_CACHE_DIR=${HOSTBOOT_ENVIRONMENT}/prime/ppe/release-fw1060/${PPE_SUBREPO_TOP_COMMIT}
    if [[ "$HB_FAST_PRIME" ]] && [[ -d ${PPE_CACHE_DIR} ]]; then
        # Pick up pre-built SBE images
        SBE_STANDALONE_IMG=${PPE_CACHE_DIR}/sbe_seeprom_p10.bin.ecc
        SBE_STANDALONE_MEASURE_IMG=${PPE_CACHE_DIR}/sbe_measurement_p10.bin.ecc
        SBE_STANDALONE_OTPROM_IMG=${PPE_CACHE_DIR}/sbe_otprom_p10.bin
        SBE_SCRIPT_TO_RUN=${PPE_CACHE_DIR}/sbeTest/sbe_startup.simics
        SBE_SCRIPTS_PATH=${PPE_CACHE_DIR}/sbeTest/
    else
        SBE_STANDALONE_IMG=${STANDALONE_SIMICS}/import/boot_roms/sbe_seeprom_p10.bin.ecc
        SBE_STANDALONE_MEASURE_IMG=${STANDALONE_SIMICS}/import/boot_roms/sbe_measurement_p10.bin.ecc
        SBE_STANDALONE_OTPROM_IMG=${STANDALONE_SIMICS}/import/boot_roms/sbe_otprom_p10.bin
        SBE_SCRIPTS_PATH=${STANDALONE_SIMICS}/targets/p10_standalone/sbeTest/
        SBE_SCRIPT_TO_RUN=${SBE_SCRIPTS_PATH}/sbe_startup.simics
    fi

    SBE_DIR=${PROJECT_ROOT}/src/build/tools/extern/sbe
 
    ODY_SBE_DEBUG_DIR=${STANDALONE_SIMICS}/odysseylab_debug_files_tools/
    if [[ "${HB_FAST_PRIME}" ]]
    then
        # Pick up pre-built images
        export SBE_SUBREPO_TOP_COMMIT=$(git submodule status $SBE_DIR | awk '{print $1}' | sed 's/^-//')
        export ODYSSEY_SBE_IMAGES=${HOSTBOOT_ENVIRONMENT}/prime/sbe/release-fw1060/$SBE_SUBREPO_TOP_COMMIT/
        # Check if the cached images exist; rebuild the SBE submodule if they don't
        if [ -d ${ODYSSEY_SBE_IMAGES} ]; then
            echo "\n***Using default pre-built SBE Odyssey images from ${ODYSSEY_SBE_IMAGES}\n"
            ODY_SBE_DEBUG_DIR=${ODYSSEY_SBE_IMAGES}/odysseylab_debug_files_tools/
        else
            unset ODYSSEY_SBE_IMAGES
        fi
    fi

    # Temporary hack to get CI to pass until we have the correct images cached
    if [ ! -d ${ODY_SBE_DEBUG_DIR} ]; then
        echo "No odysseylab found, using non-lab"
        ODY_SBE_DEBUG_DIR=${ODYSSEY_SBE_IMAGES}/odyssey_debug_files_tools/
        if [ ! -d ${ODY_SBE_DEBUG_DIR} ]; then
            ODY_SBE_DEBUG_DIR=${STANDALONE_SIMICS}/odyssey_debug_files_tools/
            if [ ! -d ${ODY_SBE_DEBUG_DIR} ]; then
                ODY_SBE_DEBUG_DIR=${HOSTBOOT_ENVIRONMENT}/prime/sbe/release-fw1060/latest/odyssey_debug_files_tools/
            fi
        fi
    fi

    # Use default paths for Odyssey images if no custom ones are specified
    if [ -z $ODYSSEY_SBE_IMAGES ]; then
        ODYSSEY_SROM_IMG=${SBE_DIR}/simics/sbe/odyssey_standalone/images/odyssey_srom_DD1.bin
        ODYSSEY_OTPROM_IMG=${SBE_DIR}/images/odyssey/onetime/otprom/odyssey_otprom_DD1.bin
        ODYSSEY_PNOR_IMG=${SBE_DIR}/simics/sbe/odyssey_standalone/images/odyssey_nor_DD1.img.ecc
    else
        ODYSSEY_SROM_IMG=${ODYSSEY_SBE_IMAGES}/odyssey_srom_DD1.bin
        ODYSSEY_OTPROM_IMG=${ODYSSEY_SBE_IMAGES}/odyssey_otprom_DD1.bin
        ODYSSEY_PNOR_IMG=${ODYSSEY_SBE_IMAGES}/odyssey_nor_DD1.img.ecc
    fi

    # Get python user site path that SBE simics scripts require
    PYTHON_USER_PACKAGE_PATH=$(python3 -m site --user-site)

    export START_SIMICS_CMD=" runsim -m ${MACHINE}"
    START_SIMICS_CMD+=" hb_script_to_run=${STARTUPSIMICS}"
    START_SIMICS_CMD+=" pnor_img=${STANDALONE}/pnor/P10.pnor"
    START_SIMICS_CMD+=" sbe_seeprom_img=${SBE_STANDALONE_IMG}"
    START_SIMICS_CMD+=" sbe_meas_seeprom_img=${SBE_STANDALONE_MEASURE_IMG}"
    START_SIMICS_CMD+=" sbe_otprom_img=${SBE_STANDALONE_OTPROM_IMG}"
    START_SIMICS_CMD+=" sbe_script_to_run=${SBE_SCRIPT_TO_RUN}"
    START_SIMICS_CMD+=" sbe_scripts_path=${SBE_SCRIPTS_PATH}"
    START_SIMICS_CMD+=" enable_lpc_console=TRUE"
    START_SIMICS_CMD+=" dimm_height=4U"
    if [ -z "${HB_USE_ODYSSEY}" ]; then
        echo "Using DDR4/Explorer DDIMMs"
    else
        echo "Using DDR5/Odyssey DDIMMs"
        START_SIMICS_CMD+=" dimm_type=ody"
        # Odyssey params
        START_SIMICS_CMD+=" sbe_project_type=odyssey"
        START_SIMICS_CMD+=" sbe_image_type=pnor"
        START_SIMICS_CMD+=" paths_to_add=$ODY_SBE_DEBUG_DIR,$ODY_SBE_DEBUG_DIR/simics,$PYTHON_USER_PACKAGE_PATH"
        START_SIMICS_CMD+=" odyssey_srom_img=${ODYSSEY_SROM_IMG}"
        START_SIMICS_CMD+=" odyssey_otprom_img=${ODYSSEY_OTPROM_IMG}"
        START_SIMICS_CMD+=" odyssey_pnor_img=${ODYSSEY_PNOR_IMG}"
        START_SIMICS_CMD+=" run_till_boot=FALSE"
        START_SIMICS_CMD+=" min_dimm=TRUE"
    fi
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
    else
        # Use more cache by default until we sort out our boot performance
        START_SIMICS_CMD+=" num_cores_per_chip=8"
    fi
fi

#   Front end to autocitest - script to execute unit tests under simics.
#
##  when jenkins runs it will create a workspace with the built code tree
##  and drop us into it.
autocitest ${BACKING_BUILD} ${HOSTBOOT_IMG}

exit $?
