# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/common/utils/scomt/proc_scomt.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2019
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

PROC_SCOMT_PATH := $(ROOTPATH)/scomt
PROC_SCOMT_SOURCE := proc_scomt.C
PROC_SCOMT_MODULE_OBJS := $(patsubst %.C,%.o,$(PROC_SCOMT_SOURCE))
PROC_SCOMT_SOURCE_DIRS := $(PROC_SCOMT_PATH)

define PROC_SCOMT_INCLUDES
$(foreach dir, $(PROC_SCOMT_SOURCE_DIRS), $(call ADD_MODULE_SRCDIR,$(1),$(dir)))
$(call ADD_MODULE_INCDIR,$(1),$(FAPI2_PATH)/include)
$(call ADD_MODULE_INCDIR,$(1),$(GENPATH))
$(call ADD_MODULE_INCDIR,$(1),$(FAPI2_PLAT_INCLUDE))
$(call ADD_MODULE_INCDIR,$(1),$(ROOTPATH))
endef

MODULE=proc_scomt
OBJS += $(PROC_SCOMT_MODULE_OBJS)

#COMMONFLAGS+=-DSCOM_CHECKING=1

$(eval $(call PROC_SCOMT_INCLUDES,$(MODULE)))
$(call BUILD_MODULE)
