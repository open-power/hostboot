# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_eff_config_thermal.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2021
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

PROCEDURE=p9c_mss_eff_config_thermal
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(CEN_INCLUDES))
lib${PROCEDURE}_DEPLIBS+=p9c_mss_funcs
$(call BUILD_PROCEDURE)
