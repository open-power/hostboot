# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/mss_pmic.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2019
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

MSS_PMIC_PATH := $(ROOTPATH)/chips/ocmb/common/procedures/hwp/pmic/lib

MSS_PMIC_SOURCE := $(shell find $(MSS_PMIC_PATH) -name '*.C' -exec basename {} \;)

MSS_PMIC_MODULE_OBJS += $(patsubst %.C,%.o,$(MSS_PMIC_SOURCE))

MSS_PMIC_SOURCE_DIRS := $(shell find $(MSS_PMIC_PATH) -type d)

# Define common source and include paths.
define MSS_PMIC_MODULE_INCLUDES
$(foreach dir, $(MSS_PMIC_SOURCE_DIRS), $(call ADD_MODULE_SRCDIR,$(1),$(dir)))
$(call ADD_MODULE_INCDIR,$(1),$(ROOTPATH)/chips/ocmb/common/procedures/hwp/pmic)
$(call ADD_MODULE_INCDIR,$(1),$(ROOTPATH)/chips/ocmb/common/procedures/hwp/pmic/lib)
$(call ADD_MODULE_INCDIR,$(1),$(ROOTPATH)/generic/memory/lib)
$(call ADD_MODULE_INCDIR,$(1),$(FAPI2_PATH)/include)
$(call ADD_MODULE_INCDIR,$(1),$(GENPATH))
$(call ADD_MODULE_INCDIR,$(1),$(FAPI2_PLAT_INCLUDE))
$(call ADD_MODULE_INCDIR,$(1),$(ROOTPATH))
endef
MODULE = mss_pmic
OBJS += $(MSS_PMIC_MODULE_OBJS)

$(eval $(call MSS_PMIC_MODULE_INCLUDES,$(MODULE)))
$(call BUILD_MODULE)
