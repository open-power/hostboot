# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/p10/procedures/hwp/pm/p10_update_ec_state.mk $
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
PROCEDURE=p10_update_ec_state
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(PROJECT_ROOT)/chips/p10/procedures/hwp/corecache/)
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(PROJECT_ROOT)/chips/p10/procedures/hwp/lib/)
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(PROJECT_ROOT)/chips/p10/common/include)
OBJ+=p10_hcd_core_stopclocks.o
OBJ+=p10_hcd_cache_poweroff.o
OBJ+=p10_hcd_cache_stopclocks.o
OBJ+=p10_hcd_l3_purge.o
OBJ+=p10_hcd_ncu_purge.o
OBJ+=p10_hcd_powerbus_purge.o
OBJ+=p10_hcd_l2_purge.o
OBJ+=p10_hcd_core_shadows_disable.o
OBJ+=p10_hcd_l2_tlbie_quiesce.o
OBJ+=p10_hcd_core_stopgrid.o
OBJ+=p10_hcd_chtm_purge.o
$(call BUILD_PROCEDURE)
