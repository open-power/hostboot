#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/hwpf/makefile $
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
ROOTPATH = ../../..
MODULE = hwpf

FAPI_ERROR_TARGETS = fapiHwpReturnCodes.H fapiHwpErrorInfo.H
FAPI_ATTR_TARGETS = fapiAttributeIds.H fapiAttributeService.C
GENFILES = ${FAPI_ERROR_TARGETS} ${FAPI_ATTR_TARGETS}

SUBDIRS = fapi.d hwp.d plat.d test.d

include ${ROOTPATH}/config.mk

# fapiParseErrorInfo.pl produces multiple output files: FAPI_ERROR_TARGETS
$(call GENTARGET, $(FAPI_ERROR_TARGETS)) : \
	    fapi/fapiParseErrorInfo.pl hwp/fapiHwpErrorInfo.xml
	$< $(dir $@) $(filter-out $<,$^)

# fapiParseAttributeInfo.pl produces multiple output files: FAPI_ATTR_TARGETS
$(call GENTARGET, $(FAPI_ATTR_TARGETS)) : \
	    fapi/fapiParseAttributeInfo.pl hwp/fapiHwpAttributeInfo.xml 
	$< $(dir $@) $(filter-out $<,$^)
