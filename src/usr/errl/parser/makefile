# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/errl/parser/makefile $
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

# makefile for errlparser a 32-bit x86 linux binary
# to extract the PEL of an error log and 
# put it in a temporary file so that the 
# FipS errl tool can format and display it.
# "Pretty printing" of those error logs is the
# function of FipS 'errl' and its plugins, not this program.
#
# This makefile runs 'genErrlParsers' which generates 
# the Hostboot SRC parsers and the makefile to build the
# Hostboot SRC and User Detail Data parsers

ROOTPATH=../../../..

GENDIR = ${ROOTPATH}/obj/genfiles
IMGDIR = ${ROOTPATH}/img
OBJDIR = ${ROOTPATH}/obj/modules/errl/parser


ERRLPARSE_TARGETS = \
	${GENDIR}/plugins/hbfwUdIds.H \
    ${GENDIR}/plugins/makefile

CC=i686-mcp6-g++ -m32
CFLAGS:=-g -O0   -I $(ROOTPATH)/src/include/usr -I ${GENDIR}

all: GEN_PASS CODE_PASS

GEN_PASS:  mkdirs  ${GENDIR}/comps.C ${ERRLPARSE_TARGETS}

ifeq ($(MAKECMDGOALS),all)
CODE_PASS: GEN_PASS
endif
ifeq ($(MAKECMDGOALS),)
CODE_PASS: GEN_PASS
endif

CODE_PASS: ${IMGDIR}/errlparser

.PHONY: mkdirs
mkdirs:
	mkdir -p ${OBJDIR}
	mkdir -p ${GENDIR}/plugins

# Generate error log parser code
${ERRLPARSE_TARGETS} : gen_errl_parsers

.PHONY: gen_errl_parsers
gen_errl_parsers: mkdirs
	./genErrlParsers.pl -b ${ROOTPATH} -o ${GENDIR}/plugins

${GENDIR}/comps.C: ${ROOTPATH}/src/include/usr/hbotcompid.H mkdirs
	grep "const compId_t [A-Z0-9]*_COMP_ID" $< | \
	grep -v MY_COMP_ID | \
	sed 's/const compId_t \([A-Z0-9]*\)_COMP_ID[ =\t]*\(0[xX][0-9a-fA-F]*\).*/{ "\1", \2 },/' \
	> $@

${OBJDIR}/errlparser.o: errlparser.C ${ROOTPATH}/src/include/usr/errl/hberrltypes.H ${GENDIR}/comps.C
	$(CC) -c  $(CFLAGS)  -o $@  $<


${IMGDIR}/errlparser: ${OBJDIR}/errlparser.o
	$(CC) -o  $@ $<

clean:
	rm -f ${ERRLPARSE_TARGETS}
	rm -f ${GENDIR}/plugins/hbfwSrcParse*.C
	rm -f ${GENDIR}/comps.C
	rm -f ${IMGDIR}/errlparser
	rm -fr ${OBJDIR}

debug:
	ls -l 	${GENDIR}
	ls -l	${OBJDIR} 
	ls -l	${IMGDIR}
	
BEAM_PASS:
IMAGE_PASS:
CLEAN_PASS: clean
