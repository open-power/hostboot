#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/targeting/makefile $
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

ROOTPATH = ../../../..

XMLTOHB_HEADER_TARGETS =    \
    attributeenums.H        \
    attributestrings.H      \
    attributetraits.H       \
    attributestructs.H      \
    pnortargeting.H         \
    fapiplatattrmacros.H

XMLTOHB_SOURCE_TARGETS =    \
    attributestrings.C  

XMLTOHB_BINARY_TARGETS =    \
    targeting.bin

XMLTOHB_TARGETS = \
    ${XMLTOHB_HEADER_TARGETS} \
    ${XMLTOHB_SOURCE_TARGETS} \
    ${XMLTOHB_BINARY_TARGETS}

XMLTOHB_HBXML_SOURCES = \
    hb.xml

XMLTOHB_FAPIATTR_SOURCES = \
    ${ROOTPATH}/src/usr/hwpf/hwp/fapiHwpAttributeInfo.xml

GENFILES = ${XMLTOHB_TARGETS}

EXTRA_PARTS = $(addprefix $(IMGDIR)/, $(XMLTOHB_BINARY_TARGETS))

include ${ROOTPATH}/config.mk

# Delete any generated file on error 
.DELETE_ON_ERROR:

${EXTRA_PARTS}: ${IMGDIR}/% : ${GENDIR}/%
	cp -f $^ $@

$(call GENTARGET,$(XMLTOHB_TARGETS)) : \
		xmltohb.pl ${XMLTOHB_HBXML_SOURCES} ${XMLTOHB_FAPIATTR_SOURCES}
	./$< $(addprefix --hb-xml-file=,${XMLTOHB_HBXML_SOURCES}) \
	     $(addprefix --fapi-attributes-xml-file=,\
			 ${XMLTOHB_FAPIATTR_SOURCES}) \
	     --src-output-dir=$(dir $@) --img-output-dir=$(dir $@)

