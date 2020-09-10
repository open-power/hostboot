# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/centaur/procedures/hwp/memory/01common.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2021
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
CEN_INCLUDES := $(GENPATH)
CEN_INCLUDES += $(ROOTPATH)
CEN_INCLUDES += $(ROOTPATH)/chips/centaur/common/include
CEN_INCLUDES += $(ROOTPATH)/chips/centaur/procedures/hwp/memory
CEN_INCLUDES += $(ROOTPATH)/chips/centaur/procedures/hwp/memory/lib
CEN_INCLUDES += $(ROOTPATH)/chips/centaur/procedures/hwp/memory/lib/shared
CEN_INCLUDES += $(ROOTPATH)/chips/centaur/procedures/hwp/initfiles/
export CEN_INCLUDES := $(CEN_INCLUDES)

CEN_MSS_LAB_PATH := $(ROOTPATH)/chips/centaur/procedures/hwp/memory/lab

CEN_CATCH_UNIT_TESTS_INCLUDES := $(ROOTPATH)/hwpf/fapi2/test

# ADD_MEMORY_INCDIRS
#     This macro will add additional include paths for all memory modules
ADD_MEMORY_INCDIRS = $(call __ADD_MODULE_INCDIR,$(1),$(CEN_INCLUDES))
ADD_MEMORY_SRCDIRS = $(call __ADD_MODULE_SRCDIR,$(1),$(ROOTPATH)/chips/centaur/procedures/hwp/memory)

# Include main MSS Lab makefile
-include $(CEN_MSS_LAB_PATH)/01mss_lab.mk
