# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: hwpf/fapi2/tools/parseAttributeInfo.mk $
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

# Makefile to run parseAttributeInfo script.

GENERATED = parseAttributeInfo
COMMAND = parseAttributeInfo.pl

SOURCES += $(FAPI2_ATTR_XML)
SOURCES += $(GENPATH)/empty_attribute.xml

TARGETS += attribute_ids.H
TARGETS += fapi2_chip_ec_feature.C
TARGETS += attribute_plat_check.H
TARGETS += attributesSupported.html
TARGETS += attrInfo.csv
TARGETS += attrEnumInfo.csv
TARGETS += fapi2AttrOverrideData.H
TARGETS += fapi2AttrOverrideEnums.H


define parseAttributeInfo_RUN
		$(C1) $$< --output-dir=$$($(GENERATED)_PATH) $$(filter-out $$<,$$^)
endef

$(call BUILD_GENERATED)

# Generate an empty attribute XML file so that the scripts pass if the
# environment hasn't defined any of its own.
GENERATED = empty_attribute_xml
TARGETS += empty_attribute.xml

define empty_attribute_xml_RUN
		$(C1) echo "<attributes/>" > $$($(GENERATED)_PATH)/empty_attribute.xml
endef

$(call BUILD_GENERATED)
