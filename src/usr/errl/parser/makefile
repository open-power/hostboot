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


# makefile for errlparser,
# a 32-bit x86 linux binary suitable for running on GFW pool machines.


ROOTPATH=../../../..

GENDIR = ${ROOTPATH}/obj/genfiles
IMGDIR = ${ROOTPATH}/img

OBJDIR = ${ROOTPATH}/obj/modules/errlparser

SRCPARSE_HEADER_TARGET = \
	${GENDIR}/hostBootSrcParse.H

CC=i686-mcp6-g++ -m32
CFLAGS:=-g -O0   -I $(ROOTPATH)/src/include/usr  -D PARSER


all: gen_pass code_pass

gen_pass:

code_pass: makeobjdir ${IMGDIR}/errlparser ${SRCPARSE_HEADER_TARGET}

clean:
	rm -fr ${SRCPARSE_HEADER_TARGET}
	rm -fr ${OBJDIR}/errlparser.o
	rm -fr ${GENDIR}/errlparser
	rm -fr ${GENDIR}/comps.C

beam:


makeobjdir:
	mkdir -p ${OBJDIR}

${GENDIR}/comps.C: $(ROOTPATH)/src/include/usr/hbotcompid.H
	grep "const compId_t [A-Z0-9]*_COMP_ID" $^ | \
	grep -v MY_COMP_ID | \
	sed 's/const compId_t \([A-Z0-9]*\)_COMP_ID[ =\t]*\(0[xX][0-9a-fA-F]*\).*/{ "\1", \2 },/' \
	> $@

${OBJDIR}/errlparser.o: errlparser.C $(ROOTPATH)/src/include/usr/errl/errltypes.H ${GENDIR}/comps.C \
	${SRCPARSE_HEADER_TARGET}
	$(CC) -c  $(CFLAGS) -I${ROOTPATH}/obj/genfiles -o $@  $<

${IMGDIR}/errlparser: ${OBJDIR}/errlparser.o
	$(CC) -o  $@ $<


${SRCPARSE_HEADER_TARGET} :
	./scanforsrcs.pl -b ${ROOTPATH} -o ${GENDIR}


