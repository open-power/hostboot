# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_recovery_ffdc_cme.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2017,2021
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
PROCEDURE=p9_pm_recovery_ffdc_cme
CME_FFDC_INC=$(ROOTPATH)/chips/p9/procedures/hwp/pm/
CME_FFDC_INC+=$(ROOTPATH)/chips/p9/procedures/hwp/lib
CME_FFDC_INC+=$(ROOTPATH)/chips/p9/common/pmlib/include/registers
lib$(PROCEDURE)_DEPLIBS+=p9_pm_recovery_ffdc_base
lib$(PROCEDURE)_DEPLIBS+=p9_pm_ocb_indir_setup_linear
lib$(PROCEDURE)_DEPLIBS+=p9_cme_sram_access
lib$(PROCEDURE)_DEPLIBS+=p9_ppe_state
lib$(PROCEDURE)_DEPLIBS+=p9_ppe_utils
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(CME_FFDC_INC))
$(call BUILD_PROCEDURE)
