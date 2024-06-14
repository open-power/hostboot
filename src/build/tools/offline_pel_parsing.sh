#!/bin/bash
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/offline_pel_parsing.sh $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2021,2024
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

#    offline_pel_parsing.sh
#
#    Hostboot developers may need to parse binary pels from CI jobs.

function usage()
{
    echo "Hostboot developers sometimes want to parse binary pels"
    echo ""
    echo "offline_pel_parsing.sh"
    echo "    -h --help"
    echo "    -o --offline-venv-name"
    echo "    -v --offline-venv-directory"
    echo "    -b --pel-path"
    echo "    -p --pel-pattern"
    echo "    -w --wheel-path"
    echo "    -x --pel-output-ext"
    echo ""
    return 1
}

function parse_the_pels ()
{
    for i in ${pel_path}/${pel_patterns}; do
        if [ ! -f "${i}" ]; then
            echo "Skipping file i=${i}"
        else
            python3 -m pel.peltool.peltool -f ${i} >${i}.${output_extension}
            echo "Parsed as ${i}.${output_extension}"
        fi
    done
}

function pull_wheel_packages ()
{
    if [[ "$GERRIT_BRANCH" == "release-fw1060" ]]; then
        release_name="opp1060"
        latest_name="latest_ibm-release-fw1060"
    elif [[ "$GERRIT_BRANCH" == "main-p11" ]]; then
        release_name="opp1110"
        latest_name="latest_main-p11"
    else
        echo "ERROR: Support for release-1060 and main-p11 only, need to add additional support if required"
        return 2
    fi
    cp -v /afs/rchland/projects/esw/${release_name}/Builds/${latest_name}/op-build/output/build/hostboot*/dist/Hostboot*.whl ${wheel_path}
    cp -v /afs/rchland/projects/esw/${release_name}/Builds/${latest_name}/op-build/output/build/sbe*/dist/sbe*.whl ${wheel_path}
    cp -v /afs/rchland/projects/esw/${release_name}/Builds/${latest_name}/op-build/output/build/occ*/dist/occ*.whl ${wheel_path}
    cp -v /afs/rchland/projects/esw/${release_name}/Builds/${latest_name}/op-build/output/build/hcode*/dist/hcode*.whl ${wheel_path}
    cp -v /afs/rchland/projects/esw/${release_name}/Builds/${latest_name}/op-build/output/build/sbe-odyssey*/dist/poz*.whl ${wheel_path}
    return $?
}

function offline_venv_cleanup ()
{
    echo "WARNING: If you want to cleanup the virtual environment created you must manually rm -rf ${offline_venv_directory}${offline_venv_name} ..."
    echo "INFO: If re-running multiple times its best to leave the virtual environment setup."
    deactivate
}

function offline_venv_setup ()
{
    # If desired can set these locally or export to environment, they are required
    #ARTIFACTORY_TOKEN="abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl"
    #ARTIFACTORY_EMAIL="xyz@us.ibm.com"
    if [ ! -d "${offline_venv_directory}/${offline_venv_name}" ]; then
        echo "INFO: offline_venv_path=${offline_venv_directory}${offline_venv_name} does NOT exist, setting up..."
        python3 -m venv ${offline_venv_directory}/${offline_venv_name}
        rc=$?
        if [ ${rc} -ne 0 ]; then
            echo "ERROR: Problem rc=${rc} setting up venv, exiting..."
            return 1
        fi

        . ${offline_venv_directory}/${offline_venv_name}/bin/activate
        pip3 install --upgrade pip
        if [ ${rc} -ne 0 ]; then
            echo "ERROR: Problem rc=${rc} upgrading pip, exiting..."
            return 1
        fi
        # config set must be done after the pip3 install is setup
        # The setting of the TOKEN and EMAIL is not dynamically set in the global config
        # to prevent the writing of the token and email credentials to the conf file.
        #pip3 config set --site global.extra-index-url https://${ARTIFACTORY_EMAIL}:${ARTIFACTORY_TOKEN}@eu.artifactory.swg-devops.com/artifactory/api/pypi/sys-pwr-aoa-team-bin-pytools-pypi-local/simple
        pip3 config set --site global.index-url https://pypi.org/simple
        pip3 config set --site global.format columns
        pip3 install peltool-wrapper -i https://${ARTIFACTORY_EMAIL}:${ARTIFACTORY_TOKEN}@eu.artifactory.swg-devops.com/artifactory/api/pypi/sys-pwr-aoa-team-bin-pytools-pypi-local/simple
        if [ ${rc} -ne 0 ]; then
            echo "ERROR: Problem rc=${rc} installing peltool-wrapper, exiting..."
            return 1
        fi
    else
        . ${offline_venv_directory}${offline_venv_name}/bin/activate
    fi

    cleanup_wheels=false
    do_wheel_update=true
    if [ ! -d "${wheel_path}" ]; then
        echo "WARNING: wheel_path=${wheel_path} does NOT exist, will attempt to pull wheel packages."
        mkdir -p ${wheel_path}
        cleanup_wheels=true
        # attempt to pull the latest available official wheel packages
        pull_wheel_packages
        rc=$?
        if [ ${rc} -ne 0 ]; then
            if [[ $rc == "2" ]]; then
                echo "ERROR: Problem rc=${rc} Undefined release specified, only release-fw1060 and main-p11 supported."
                exit
            fi
            echo "WARNING: Problem rc=${rc} could not copy the wheel packages, do you have tokens ? SKIPPING adding latest wheel packages"
            do_wheel_update=false
        fi
    fi
    if [ "$do_wheel_update" == true ]; then
        # user supplied set of wheels to test or override the pre-built wheels
        # should always have either the pre-built or custom to install
        echo "INFO: wheel_path=${wheel_path} adding custom wheel packages."
        pip3 install --upgrade --force-reinstall ${wheel_path}/*.whl
        rc=$?
        if [ ${rc} -ne 0 ]; then
            echo "WARNING: Problem rc=${rc} something happened when attempting to add custom wheel packages, verify your desired outcome..."
        fi
    fi
    if [ "$cleanup_wheels" == true ]; then
        rm -rf ${wheel_path}
    fi
}

function main ()
{
    # Change the long args to short args
    for arg in "$@"; do
        shift
        case "$arg" in
            "--help") set -- "$@" "-h" ;;
            "--offline-venv-name") set -- "$@" "-o" ;;
            "--offline-venv-directory") set -- "$@" "-v" ;;
            "--pel-binaries") set -- "$@" "-b" ;;
            "--pel-pattern") set -- "$@" "-p" ;;
            "--wheel-path") set -- "$@" "-w" ;;
            "--pel-output-ext") set -- "$@" "-x" ;;
            "--"*)  echo "ERROR: Invalid argument ${arg}"; usage; return 1;;
            *) set -- "$@" "$arg"
        esac
    done

    # If going to use in CI set default to path desired
    default_offline_venv_name="offline_parser_venv_sandbox"
    offline_venv_name=""
    # if not specified in options use WORKSPACE
    offline_venv_directory=""
    # pel path are the source binary pels
    pel_path=""
    pel_patterns=""
    default_pel_patterns=("pel*.bin")
    output_extension=""
    default_output_extension="parsed"
    output_extension=""
    wheel_path=""
    #flag to warn the user to cleanup

    # Parse through the optional args
    OPTIND=1
    while getopts "hv:o:b:p:w:x:" option
    do
        case "${option}" in
            h)
                usage
                return 0
                ;;
            v)
                offline_venv_directory="$OPTARG"
                ;;
            o)
                offline_venv_name="$OPTARG"
                ;;
            b)
                pel_path="$OPTARG"
                ;;
            p)
                pel_patterns="$OPTARG"
                ;;
            w)
                wheel_path="$OPTARG"
                ;;
            x)
                output_extension="$OPTARG"
                ;;

            ?)
                usage
                return 1
                ;;
            *)
                usage
                return 1
                ;;
        esac
    done
    shift $((OPTIND-1))

if [[ "$ARTIFACTORY_TOKEN" == "" ]]; then
    echo "ERROR: It is required that ARTIFACTORY_TOKEN has a valid token to setup and install the virtual environment"
    return 1
fi
if [[ "$ARTIFACTORY_EMAIL" == "" ]]; then
    echo "ERROR: It is required that ARTIFACTORY_EMAIL has a valid email to setup and install the virtual environment"
    return 1
fi

if [ -z "${wheel_path}" ]
then
    wheel_path="$WORKSPACE/dist/"
fi

if [ -z "${offline_venv_name}" ]
then
    offline_venv_name="${default_offline_venv_name}"
fi

if [ -z "${offline_venv_directory}" ]
then
    offline_venv_directory="${WORKSPACE}/"
fi

if [ -z "${output_extension}" ]
then
    output_extension="${default_output_extension}"
fi

if [ -z "${pel_patterns}" ]
then
    pel_patterns="${default_pel_patterns}"
fi

if [ -z "${pel_path}" ]
then
    if [[ "$PEL_PATH" == "" ]]; then
        pel_path="${WORKSPACE}/standalone/simics/"
    else
        # pick up from Jenkins
        pel_path="$PEL_PATH/"
    fi
fi

if [ ! -d "${pel_path}" ]; then
    echo "ERROR: pel_path=${pel_path} does NOT exist, a valid directory of binary pel files must be available."
    return 1
fi

echo "INFO: Starting the Virtual Environment Setup ..."
offline_venv_setup
echo "INFO: Completed the Virtual Environment Setup ..."

echo "INFO: Starting the PEL Parsing ..."
parse_the_pels
echo "INFO: Completed the PEL Parsing ..."

offline_venv_cleanup

}

# WORKSPACE is used to define the working context
# Needs to determine relative to workon, Jenkins or somewhere else
if [[ "$WORKSPACE" == "" ]]; then
    if [[ ! "$PROJECT_ROOT" ]] ; then
        export WORKSPACE="$PWD/"
    else
        export WORKSPACE="$PROJECT_ROOT/"
    fi
    # Jenkins uses for cloning purposes
    export GERRIT_BRANCH=release-fw1060
    #export GERRIT_BRANCH=main-p11
fi
    main $@

# we really do not want to cleanup the location of the binary pels

# Cleanup the script variables, mainly for standalone use, non-Jenkins
unset WORKSPACE
unset GERRIT_BRANCH

