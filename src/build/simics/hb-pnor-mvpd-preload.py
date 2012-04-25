#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/simics/hb-pnor-mvpd-preload.py $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2012
#
#  p1
#
#  Object Code Only (OCO) source materials
#  Licensed Internal Code Source Materials
#  IBM HostBoot Licensed Internal Code
#
#  The source code for this program is not published or other-
#  wise divested of its trade secrets, irrespective of what has
#  been deposited with the U.S. Copyright Office.
#
#  Origin: 30
#
#  IBM_PROLOG_END_TAG
import os,sys
import subprocess
import shlex

#------------------------------------------------------------------------------
# Call a perl script to build up the VPD data for PNOR.
#------------------------------------------------------------------------------
toolLoc = os.environ.get("HB_TOOLPATH");
thisSys = os.environ.get("HB_MACHINE").upper();
numProcs = os.environ.get( "GFW_P8_%s_NUM_PROCS" % thisSys );
numCentaurPerProc = os.environ.get( "GFW_P8_%s_CENTAURS_PER_PROC" % thisSys );
cmd = toolLoc + "/hb-pnor-mvpd-preload.pl --numProcs " + numProcs + " --numCentPerProc " + numCentaurPerProc + " --machine " + thisSys + " --dataPath " + toolLoc
print "Generate PNOR VPD for " + numProcs + " processor(s), and " + numCentaurPerProc + " Centaur(s) per Processor.";
args = shlex.split( cmd );
subprocess.call( args );
