# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/initservice/build/makefile $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2011,2013
#
# p1
#
# Object Code Only (OCO) source materials
# Licensed Internal Code Source Materials
# IBM HostBoot Licensed Internal Code
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# Origin: 30
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
