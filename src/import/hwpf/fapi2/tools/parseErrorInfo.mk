# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: hwpf/fapi2/tools/parseErrorInfo.mk $
#
# IBM CONFIDENTIAL
#
# EKB Project
#
# COPYRIGHT 2015,2016
# [+] International Business Machines Corp.
#
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# IBM_PROLOG_END_TAG

# Makefile to run the parseErrorInfo script.

GENERATED = parseErrorInfo
COMMAND = parseErrorInfo.pl

SOURCES += $(FAPI2_ERROR_XML)
SOURCES += $(GENPATH)/empty_error.xml

TARGETS += hwp_return_codes.H
TARGETS += hwp_error_info.H
TARGETS += hwp_ffdc_classes.H
TARGETS += collect_reg_ffdc.H
TARGETS += set_sbe_error.H

define parseErrorInfo_RUN
		$(C1) $$< --output-dir=$$($(GENERATED)_PATH) $$(filter-out $$<,$$^)
endef

$(call BUILD_GENERATED)

# Generate an empty error XML file so that the scripts pass if the
# environment hasn't defined any of its own.
GENERATED = empty_error_xml
TARGETS += empty_error.xml

define empty_error_xml_RUN
		$(C1) echo "<hwpErrors/>" > $$($(GENERATED)_PATH)/empty_error.xml
endef

$(call BUILD_GENERATED)
