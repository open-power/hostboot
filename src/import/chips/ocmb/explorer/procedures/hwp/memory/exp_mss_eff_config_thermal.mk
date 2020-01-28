# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_mss_eff_config_thermal.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2019,2020
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

-include 00exp_common.mk

PROCEDURE=exp_mss_eff_config_thermal
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(MSS_EXP_INCLUDES))
lib$(PROCEDURE)_DEPLIBS+=exp_bulk_pwr_throttles
$(call BUILD_PROCEDURE)
