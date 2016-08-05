# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/hwpf/fapi2/tools/parseAttributeInfo.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2016
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

# Makefile to run parseAttributeInfo script.

GENERATED = parseAttributeInfo
COMMAND = parseAttributeInfo.pl

SOURCES += $(FAPI2_ATTR_XML)
SOURCES += $(GENPATH)/empty_attribute.xml

TARGETS += attribute_ids.H
TARGETS += fapi2_chip_ec_feature.H
TARGETS += attribute_plat_check.H
TARGETS += attributesSupported.html
TARGETS += attrInfo.csv
TARGETS += attrEnumInfo.csv
TARGETS += fapi2AttrOverrideData.H
TARGETS += fapi2AttrOverrideEnums.H

CLEAN_TARGETS += $(GENPATH)/attribute_ids.H
CLEAN_TARGETS += $(GENPATH)/fapi2_chip_ec_feature.C
CLEAN_TARGETS += $(GENPATH)/attribute_plat_check.H
CLEAN_TARGETS += $(GENPATH)/attributesSupported.html
CLEAN_TARGETS += $(GENPATH)/attrInfo.csv
CLEAN_TARGETS += $(GENPATH)/attrEnumInfo.csv
CLEAN_TARGETS += $(GENPATH)/fapi2AttrOverrideData.H
CLEAN_TARGETS += $(GENPATH)/fapi2AttrOverrideEnums.H

define parseAttributeInfo_RUN
		$(C1) $$< --output-dir=$$($(GENERATED)_PATH) $$(filter-out $$<,$$^)
endef

$(call BUILD_GENERATED)

# Generate an empty attribute XML file so that the scripts pass if the
# environment hasn't defined any of its own.
GENERATED = empty_attribute_xml
TARGETS += empty_attribute.xml
CLEAN_TARGETS += $(GENPATH)/empty_attribute.xml

define empty_attribute_xml_RUN
		$(C1) echo "<attributes/>" > $$($(GENERATED)_PATH)/empty_attribute.xml
endef

$(call BUILD_GENERATED)
