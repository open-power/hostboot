# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/00pmic_common.mk $
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

MSS_PMIC_INCLUDES := $(GENPATH)
MSS_PMIC_INCLUDES += $(ROOTPATH)
MSS_PMIC_INCLUDES += $(ROOTPATH)/chips/ocmb/common/include
MSS_PMIC_INCLUDES += $(ROOTPATH)/chips/ocmb/common/procedures/hwp/pmic/lib
MSS_PMIC_INCLUDES += $(ROOTPATH)/chips/ocmb/common/procedures/hwp/pmic

# For generic attribute accessors
MSS_PMIC_INCLUDES += $(ROOTPATH)/generic/memory/lib

CATCH_UNIT_TESTS_INCLUDES := $(ROOTPATH)/hwpf/fapi2/test

# ADD_PMIC_MEMORY_INCDIRS
#     This macro will add additional include paths for all memory modules
ADD_PMIC_MEMORY_INCDIRS = $(call __ADD_MODULE_INCDIR,$(1),$(MSS_PMIC_INCLUDES))
