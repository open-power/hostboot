# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/hwpf/fapi2/tools/createIfAttrService.mk $
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

# Makefile to run createIfAttrService script.

GENERATED = createIfAttrService
COMMAND = createIfAttrService.pl

SOURCES += $(FAPI2_ATTR_XML)
SOURCES += $(GENPATH)/empty_attribute.xml

TARGETS += fapi2_attribute_service.C

CLEAN_TARGETS += $(GENPATH)/fapi2_attribute_service.C

define createIfAttrService_RUN
		$(C1) $$< --output-dir=$$($(GENERATED)_PATH) -a $$(filter-out $$<,$$^)
endef

$(call BUILD_GENERATED)
