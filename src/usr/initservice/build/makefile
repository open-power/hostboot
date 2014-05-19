# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/initservice/build/makefile $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2011,2014
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
# makefile for initialization service build tasks.
#    1.  create isteplist.csv file for spless
#


ROOTPATH=../../../..

## pull in IMGDIR, etc.
include ${ROOTPATH}/src/usr/parser.mk

OBJFILES=

all: GEN_PASS CODE_PASS

GEN_PASS:

CODE_PASS: GEN_PASS ${IMGDIR}/isteplist.csv

## find all the ISTEPNAME( #,#,name ) macros in the istep lists and generate 
##	the isteplist.csv file for hb-istep 
## 	
${IMGDIR}/isteplist.csv : ${ROOTPATH}/src/include/usr/isteps/*.H
	grep -rh "ISTEPNAME(\ *[0-9]"  $^ | sed -e 's/^.*ISTEPNAME(//; s/).*//; s/"//g;s/ //g' | sort --numeric > $@
	 
	

clean:
	rm -fr ${IMGDIR}/isteplist.csv
	rm -fr *.o

debug:
	ls -l ${GENDIR}
	ls -l ${OBJDIR} 
	ls -l ${IMGDIR}
	
BEAM_PASS:
IMAGE_PASS:
CLEAN_PASS: clean
