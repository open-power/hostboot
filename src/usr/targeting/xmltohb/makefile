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

GENFILES =                      \
    ${XMLTOHB_HEADER_TARGETS}   \
    ${XMLTOHB_SOURCE_TARGETS}   \
    ${XMLTOHB_BINARY_TARGETS} 

# Delete any generated file on error 
.DELETE_ON_ERROR:

$(addprefix %/,$(GENFILES)) : xmltohb.pl hb.xml
	./$< --hb-xml-file ./hb.xml --fapi-attributes-xml-file=../../hwpf/hwp/fapiHwpAttributeInfo.xml --src-output-dir=$(dir $@) --img-output-dir=$(dir $@) $(filter-out $<,$^) 
	cp -f $(dir $@)/targeting.bin $(IMGDIR) 

include ${ROOTPATH}/config.mk
