# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/simics/hb-pnor-vpd-preload.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2017
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
import os,sys
import subprocess
import shlex

#------------------------------------------------------------------------------
# Call a perl script to build up the VPD data for PNOR.
#------------------------------------------------------------------------------
toolLoc = os.environ.get("HB_TOOLPATH");
thisSys = os.environ.get("HB_MACHINE").upper();
numProcs = os.environ.get( "NUM_PROCS");
dimmsPerProc = os.environ.get( "DIMMS_PER_PROC");
numCentaurPerProcParm = "";
numCentaurPerProc = "0";
if (thisSys == "CUMULUS"):
    numCentaurPerProc=str(int(dimmsPerProc)/2);
    numCentaurPerProcParm=" --numCentPerProc " + numCentaurPerProc;
pass
procChipTypeParm = "";
if os.environ.has_key('HB_PROC_CHIP_TYPE'):
    procChipType = os.environ.get('HB_PROC_CHIP_TYPE');
    procChipTypeParm=" --procChipType " + procChipType;
pass
cmd = toolLoc + "/hb-pnor-vpd-preload.pl --numProcs " + numProcs + numCentaurPerProcParm + procChipTypeParm + " --machine " + thisSys + " --dataPath " + toolLoc
print "Generate PNOR VPD for " + numProcs + " processor(s), and " + numCentaurPerProc + " Centaur(s) per Processor.";
args = shlex.split( cmd );
subprocess.call( args );
