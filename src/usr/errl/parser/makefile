# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/errl/parser/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2022
# [+] Google Inc.
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

ifndef OPENPOWER_BUILD
ifndef RH8_BUILD
    ERRL_LINK_STATIC = -m32 -static
endif
endif

CC=$(HOST_PREFIX)g++ $(ERRL_LINK_STATIC)
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
	> $@.tmp
	cmp -s $@.tmp $@ || mv $@.tmp $@
	rm -f $@.tmp

${OBJDIR}/errlparser.o: errlparser.C ${ROOTPATH}/src/include/usr/errl/hberrltypes.H ${GENDIR}/comps.C
	$(CC) -c  $(CFLAGS)  -o $@  $<


${IMGDIR}/errlparser: ${OBJDIR}/errlparser.o
	$(CC) -o  $@ $<

clean:
	rm -f ${ERRLPARSE_TARGETS}
	rm -f ${GENDIR}/plugins/hbfwSrcParse*.C
	rm -f ${GENDIR}/plugins/errludattribute.H
	rm -f ${GENDIR}/plugins/errludtarget.H
	rm -f ${GENDIR}/comps.C
	rm -f ${IMGDIR}/errlparser
	rm -fr ${OBJDIR}
	rm -f ${GENDIR}/errldisplaydata.C
	rm -f ${GENDIR}/srcListing
	rm -f ${GENDIR}/hbfw_term_rc.H

debug:
	ls -l 	${GENDIR}
	ls -l	${OBJDIR}
	ls -l	${IMGDIR}

BEAM_PASS:
IMAGE_PASS:
CLEAN_PASS: clean
