#!/bin/bash
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/trace/tracelite/traceLite.sh $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2019,2020
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

#####################################################################
# This script will run trace_lite parsing on a specified BMC
#
#####################################################################

SCRIPT=`basename ${BASH_SOURCE[0]}`

# Set fonts
NORM=`tput sgr0`
BOLD=`tput bold`

function usage() {
  echo "Usage: $0 [-s BMC_system] (-t hbotStringFile) (-o output_raw_file) (-w weave_tool) (-p bmc_port_num) (-b base_hb_op_dir) (-h)" 1>&2;
  exit 1
}

function HELP {
  echo -e \\n"Help documentation for ${BOLD}${SCRIPT}${NORM}"\\n
  echo "Basic usage:"
  echo -e "$0 -s BMC_system${NORM} (-t hbotStringFile) (-o output_raw_file) (-w weave_tool) (-p bmc_port_num) (-b base_hb_op_dir) (-h)"\\n
  echo "Required:"
  echo -e "${BOLD}-s${NORM} BMC_system   -- BMC server name"\\n
  echo "Optional:"
  echo "${BOLD}-b${NORM} base_hb_op_dir   -- hostboot output directory where hbotString and tools will be located if not specified"
  echo "${BOLD}-o${NORM} output_raw_file   -- Save unparsed raw output of SOL console to file (use weave tool to parse offline)"
  echo "${BOLD}-t${NORM} hbotStringFile   -- full path to hbotStringFile (defaulted to look for in current directory)"
  echo "        - Location in OP build: [base hostboot op dir]/img/hbotStringFile"
  echo "${BOLD}-w${NORM} weave_tool    -- full path to weave tool (defaults to just call weave without path)"
  echo "        - Location in OP build: [base hostboot op dir]/obj/genfiles/weave"
  echo "${BOLD}-p${NORM} bmc_port_num   -- BMC port number for HB console"
  echo "${BOLD}-h${NORM}   -- Displays this help message. No further functions are performed."
  echo -e \\n"Example: $SCRIPT -s wsbmc021 -t ../hbotStringFile -o raw_SOL_output -w ../weave"
  echo -e "Example: $SCRIPT -s wsbmc021 -b /tmp/op_sb/output/build/hostboot-b28407123f5e5e834d658f994432ea77f8ba01d9 -o raw_SOL_output"\\n
  exit 1
}

while getopts ":b:s:t:o:w:p:h" o; do
  case "${o}" in
    b)
        baseOp=${OPTARG}
        ;;
    s)
        server=${OPTARG}
        ;;
    t)
        stringFile=${OPTARG}
        ;;
    o)
        rawOutFile=${OPTARG}
        ;;
    w)
        weaveTool=${OPTARG}
        ;;
    p)
        portNum=${OPTARG}
        ;;
    h)
        HELP
        ;;
    *)
        usage
        exit 2;
        ;;
  esac
done
shift $((OPTIND-1))

## First check for required parameter
if [ "$server" = "" ]; then
  echo "Need to specify the BMC with -s option"
  usage
  exit 1
fi

## Check validity of baseOp
if [ "$baseOp" != "" ]; then
  if [ ! -d $baseOp ]; then
    echo "ERROR: -b specified directory, $baseOp, does not exist!"
    exit 1
  else
    # remove trailing / if present
    if [ ${baseOp: -1} = "/" ]; then
      baseOp=${baseOp%?}
    fi
  fi
fi

## Fill in undefined parameters with defaults
if [ "$stringFile" = "" ]; then
  stringFile="hbotStringFile"
  if [ "$baseOp" != "" ]; then
    stringFile="$baseOp/img/hbotStringFile"
  fi
fi

if [ "$rawOutFile" = "" ]; then
  teeCmd="tee"
else
  teeCmd="tee -a $rawOutFile"
fi

if [ "$weaveTool" = "" ]; then
  weaveTool="weave"
  if [ "$baseOp" != "" ]; then
      weaveTool="$baseOp/obj/genfiles/weave"
  fi
fi

if [ "$portNum" = "" ]; then
  portNum="2200"
fi



## Check that the hbotStringFile exists
if [ ! -f $stringFile ]; then
    echo "ERROR: $stringFile is not found. Use -t to specify" >&2
    usage
    exit 1
fi

## Check that all the necessary scripts exist
if ! [ -x "$(command -v $weaveTool)" ]; then
  echo "Error: $weaveTool is not found. Use -w to specify or update your \$PATH" >&2
  exit 1
fi


login_bmc="./login_bmc"
if ! [ -x "$(command -v $login_bmc)" ]; then
  if [ "$baseOp" != "" ]; then
  {
      login_bmc="$baseOp/src/build/trace/tracelite/login_bmc"
  }
  else
  {
      echo "Error:  login_bmc script not found.  Update base OP or your \$PATH" >&2
      exit 1
  }
  fi
fi


## Use the expect script to log into bmc's SOL console and then use weave to parse
echo "NOTE: Use ${BOLD}~${NORM} followed by ${BOLD}.${NORM} to exit"
echo "ssh -p 2200 root@$server | $teeCmd | $weaveTool $stringFile $weaveDebugFile"
#echo "login_bmc 0penBmc $server root | $teeCmd | $weaveTool $stringFile $weaveDebugFile"
$login_bmc 0penBmc $server $portNum root | $teeCmd | $weaveTool $stringFile $weaveDebugFile
