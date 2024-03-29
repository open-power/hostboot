# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/p10/procedures/hwp/nest/p10_htm_setup.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2019
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
PROCEDURE=p10_htm_setup
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(ROOTPATH))
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(ROOTPATH)/generic/memory/lib/utils/)
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(ROOTPATH)/chips/ocmb/explorer/procedures/hwp/memory/)
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(ROOTPATH)/chips/ocmb/explorer/procedures/hwp/memory/lib/shared/)
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(ROOTPATH)/chips/ocmb/explorer/procedures/hwp/memory/lib/inband/)
OBJS+=p10_mss_eff_grouping.o
OBJS+=p10_htm_start.o
OBJS+=p10_htm_reset.o
OBJS+=p10_htm_adu_ctrl.o
$(call BUILD_PROCEDURE)
