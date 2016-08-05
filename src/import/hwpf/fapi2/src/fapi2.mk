# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/hwpf/fapi2/src/fapi2.mk $
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

#
# Makefile to build the FAPI2 libraries.
#


# Add common and generated parts to object list.
FAPI2_MODULE_OBJS += error_info.o
FAPI2_MODULE_OBJS += ffdc.o
FAPI2_MODULE_OBJS += fapi2_attribute_service.o

# Define common source and include paths.
define FAPI2_MODULE_INCLUDES
$(call ADD_MODULE_SRCDIR,$(1),$(GENPATH))
$(call ADD_MODULE_INCDIR,$(1),$(FAPI2_PATH)/include)
$(call ADD_MODULE_INCDIR,$(1),$(FAPI2_PLAT_INCLUDE))
endef

# Build real FAPI2 library that uses Cronus platform.
MODULE = fapi2
OBJS += $(FAPI2_MODULE_OBJS)
$(eval $(call FAPI2_MODULE_INCLUDES,$(MODULE)))
lib$(MODULE)_EXTRALIBS += $(FAPI2_REQUIRED_LIBS)
lib$(MODULE)_LDFLAGS += -ldl
$(call BUILD_MODULE)

# Build test FAPI2 library that uses the reference platform.
# To do this, we just add the extra 'plat' directories to the srcdir / incdir
# before the Cronus platform directories.
MODULE = fapi2_reference
OBJS += $(FAPI2_MODULE_OBJS)
OBJS += plat_utils.o
$(call ADD_MODULE_SRCDIR,fapi2_reference,$(FAPI2_PATH)/src/plat)
$(call ADD_MODULE_INCDIR,fapi2_reference,$(FAPI2_PATH)/include/plat)
$(eval $(call FAPI2_MODULE_INCLUDES,$(MODULE)))
$(call BUILD_MODULE)
