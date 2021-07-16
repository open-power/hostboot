# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/p10/procedures/hwp/pm/p10_core_special_wakeup.mk $
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
PROCEDURE=p10_core_special_wakeup
SPWKUP_UTIL=$(ROOTPATH)/chips/p10/common/include/eq/
SPWKUP_UTIL+=$(ROOTPATH)/chips/p10/common/include/
SPWKUP_UTIL+=$(ROOTPATH)/chips/p10/procedures/hwp/lib/
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(SPWKUP_UTIL)) 
$(call BUILD_PROCEDURE)
