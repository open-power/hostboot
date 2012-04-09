#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/errl/parser/makefile $
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

# makefile for errlparser a 32-bit x86 linux binary
# to extract the PEL of an error log and 
# put it in a temporary file so that the 
# FipS errl tool can format and display it.
# "Pretty printing" of those error logs is the
# function of FipS 'errl' and its plugins, not this program.
#
# This makefile runs 'scanforsrc.pl' which generates 
# hostBootSrcParse.H, a file that hostboot plugins will include.



ROOTPATH=../../../..

GENDIR = ${ROOTPATH}/obj/genfiles
IMGDIR = ${ROOTPATH}/img
OBJDIR = ${ROOTPATH}/obj/modules/errl/parser


SRCPARSE_HEADER_TARGET = \
	${GENDIR}/hostBootSrcParse.H


CC=i686-mcp6-g++ -m32
CFLAGS:=-g -O0   -I $(ROOTPATH)/src/include/usr -I ${GENDIR}

all: gen_pass code_pass

gen_pass:  mkdirs  ${GENDIR}/comps.C

code_pass: ${SRCPARSE_HEADER_TARGET} ${IMGDIR}/errlparser

# errlparserbase and errlusrparser are plugins stuff, not errlparser. 
# OBJFILES = ${OBJDIR}/errlparserbase.o	${OBJDIR}/errlusrparser.o
# %.o : %.C
# 	$(CC) -c  $(CFLAGS) -o $@  $<

mkdirs:
	mkdir -p ${OBJDIR}
	mkdir -p ${GENDIR}

# Parse for error log tags in the Hostboot code, and generate hostBootSrcParse.H
${SRCPARSE_HEADER_TARGET} ::
	./scanforsrcs.pl -b ${ROOTPATH} -o ${GENDIR}

${GENDIR}/comps.C: ${ROOTPATH}/src/include/usr/hbotcompid.H
	grep "const compId_t [A-Z0-9]*_COMP_ID" $^ | \
	grep -v MY_COMP_ID | \
	sed 's/const compId_t \([A-Z0-9]*\)_COMP_ID[ =\t]*\(0[xX][0-9a-fA-F]*\).*/{ "\1", \2 },/' \
	> $@

${OBJDIR}/errlparser.o: errlparser.C ${ROOTPATH}/src/include/usr/errl/hberrltypes.H ${GENDIR}/comps.C ${SRCPARSE_HEADER_TARGET}
	$(CC) -c  $(CFLAGS)  -o $@  $<


${IMGDIR}/errlparser: ${OBJDIR}/errlparser.o
	$(CC) -o  $@ $<

clean:
	rm -f ${SRCPARSE_HEADER_TARGET}
	rm -f ${GENDIR}/comps.C
	rm -f ${IMGDIR}/errlparser
	rm -fr ${OBJDIR}

debug:
	ls -l 	${GENDIR}
	ls -l	${OBJDIR} 
	ls -l	${IMGDIR}
	
beam:
	# dummy
