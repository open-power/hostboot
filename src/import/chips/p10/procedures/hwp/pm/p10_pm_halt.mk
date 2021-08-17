# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_halt.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2019,2021
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
PROCEDURE=p10_pm_halt
lib$(PROCEDURE)_EXTRALIBS+=p10_pm_xgpe_init
lib$(PROCEDURE)_EXTRALIBS+=p10_pm_pgpe_init
lib$(PROCEDURE)_EXTRALIBS+=p10_pm_qme_init
lib$(PROCEDURE)_EXTRALIBS+=p10_pm_pba_init
lib$(PROCEDURE)_EXTRALIBS+=p10_pm_pss_init
lib$(PROCEDURE)_EXTRALIBS+=p10_pm_firinit
lib$(PROCEDURE)_EXTRALIBS+=p10_pm_ocb_init
lib$(PROCEDURE)_EXTRALIBS+=p10_pm_occ_firinit
lib$(PROCEDURE)_EXTRALIBS+=p10_pm_occ_control
lib$(PROCEDURE)_EXTRALIBS+=p10_core_special_wakeup
lib$(PROCEDURE)_EXTRALIBS+=p10_setup_evid
lib$(PROCEDURE)_EXTRALIBS+=p10_avsbus_lib
lib$(PROCEDURE)_EXTRALIBS+=p10_pstate_parameter_block
$(call ADD_MODULE_SRCDIR,$(PROCEDURE),$(ROOTPATH)/chips/p10/procedures/hwp/lib)
$(call ADD_MODULE_SRCDIR,$(PROCEDURE),$(ROOTPATH)/chips/p10/common/pmlib/include/registers)
$(call BUILD_PROCEDURE)
