# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/p10/procedures/hwp/memory/p10_omi_ddr4_edpl.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2019,2024
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

# Include the macros and things for MSS procedures
-include 00p10_common.mk

PROCEDURE=p10_omi_ddr4_edpl
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(MSS_P10_INCLUDES))
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(ROOTPATH)/chips/ocmb/explorer/procedures/hwp/memory)
$(call BUILD_PROCEDURE)
