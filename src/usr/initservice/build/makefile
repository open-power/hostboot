#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/initservice/build/makefile $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2011
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
#  IBM_PROLOG_END
#
# makefile for initialization service build tasks.
#    1.  create isteplist.csv file for spless
#


ROOTPATH=../../../..

## pull in IMGDIR, etc.
include ${ROOTPATH}/src/usr/parser.mk

OBJFILES=

all: gen_pass code_pass

gen_pass:

code_pass: ${IMGDIR}/isteplist.csv

${IMGDIR}/isteplist.csv : ${ROOTPATH}/src/include/usr/isteps/*.H
	./scanistepnames.pl -b $(ROOTPATH)/src/include/usr/isteps -d -o $@

clean:
	rm -fr ${IMGDIR}/isteplist.csv
	rm -fr *.o

debug:
	ls -l ${GENDIR}
	ls -l ${OBJDIR} 
	ls -l ${IMGDIR}
