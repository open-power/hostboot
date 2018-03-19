# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/p9/procedures/hwp/perv/p9_cen_framelock.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2017,2018
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
CEN_MSS_INCLUDES := $(GENPATH)
CEN_MSS_INCLUDES += $(ROOTPATH)
CEN_MSS_INCLUDES += $(ROOTPATH)/chips/centaur/common/include
CEN_MSS_INCLUDES += $(ROOTPATH)/chips/centaur/procedures/hwp/memory
CEN_MSS_INCLUDES += $(ROOTPATH)/chips/centaur/procedures/hwp/memory/lib
CEN_MSS_INCLUDES += $(ROOTPATH)/chips/centaur/procedures/hwp/memory/lib/shared
CEN_MSS_INCLUDES += $(ROOTPATH)/chips/centaur/procedures/hwp/initfiles/

PROCEDURE=p9_cen_framelock
lib${PROCEDURE}_DEPLIBS=p9c_mss_unmask_errors
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(ROOTPATH)/chips/centaur/common/include)
$(eval $(call __ADD_MODULE_INCDIR,$(PROCEDURE),$(CEN_MSS_INCLUDES)))
$(call BUILD_PROCEDURE)
