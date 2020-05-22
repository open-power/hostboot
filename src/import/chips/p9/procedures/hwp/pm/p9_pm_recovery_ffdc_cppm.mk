# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_recovery_ffdc_cppm.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2017,2020
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
PROCEDURE=p9_pm_recovery_ffdc_cppm
CPPM_FFDC_INC=$(ROOTPATH)/chips/p9/procedures/hwp/pm/
CPPM_FFDC_INC+=$(ROOTPATH)/chips/p9/procedures/hwp/lib
CPPM_FFDC_INC+=$(ROOTPATH)/hwpf/fapi2/include
lib$(PROCEDURE)_DEPLIBS += p9_pm_recovery_ffdc_base
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(CPPM_FFDC_INC))
$(call BUILD_PROCEDURE)
