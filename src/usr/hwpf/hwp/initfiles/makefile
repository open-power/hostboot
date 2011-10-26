#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/hwpf/hwp/initfiles/makefile $
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
ROOTPATH = ../../../../../

INITFILES_INPUT = sample.initfile
INITFILES_OUTPUT = sample.if

INITCOMPILER = ${ROOTPATH}/src/build/ifcompiler/bin/initCompiler
ATTR_HEADER = ${ROOTPATH}/obj/genfiles/fapiAttributeIds.H

EXTRA_PARTS = $(addprefix ${IMGDIR}/, ${INITFILES_OUTPUT})

include ${ROOTPATH}/config.mk

${EXTRA_PARTS}: ${IMGDIR}/% : ${GENDIR}/%
	cp -f $^ $@

${GENDIR}/%.if: ${INITCOMPILER} ${ATTR_HEADER} %.initfile
	${INITCOMPILER} -init ${INITFILES_INPUT} -outdir ${GENDIR} -attr ${ATTR_HEADER}





