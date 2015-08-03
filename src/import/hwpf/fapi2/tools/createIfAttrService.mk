# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: hwpf/fapi2/tools/createIfAttrService.mk $
#
# IBM CONFIDENTIAL
#
# EKB Project
#
# COPYRIGHT 2015
# [+] International Business Machines Corp.
#
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# IBM_PROLOG_END_TAG

# Makefile to run createIfAttrService script.

GENERATED = createIfAttrService
COMMAND = createIfAttrService.pl

SOURCES += $(FAPI2_ATTR_XML)
SOURCES += $(GENPATH)/empty_attribute.xml

TARGETS += fapi2_attribute_service.C

define createIfAttrService_RUN
		$(C1) $$< --output-dir=$$($(GENERATED)_PATH) -a $$(filter-out $$<,$$^)
endef

$(call BUILD_GENERATED)
