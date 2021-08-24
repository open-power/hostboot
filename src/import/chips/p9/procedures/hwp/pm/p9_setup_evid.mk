# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/p9/procedures/hwp/pm/p9_setup_evid.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2017
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
PROCEDURE=p9_setup_evid
$(call ADD_MODULE_SRCDIR,$(PROCEDURE),$(PROJECT_ROOT)/chips/p9/procedures/hwp/lib)
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(PROJECT_ROOT)/chips/p9/procedures/hwp/pm/include/registers)
OBJS+=p9_avsbus_lib.o
OBJS+=p9_pstate_parameter_block.o
OBJS+=p9_pm_get_poundv_bucket.o
OBJS+=p9_pm_get_poundw_bucket.o
lib$(PROCEDURE)_DEPLIBS+=p9_pm_utils
$(call BUILD_PROCEDURE)