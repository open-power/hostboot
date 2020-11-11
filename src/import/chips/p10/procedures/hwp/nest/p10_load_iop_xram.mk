# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/p10/procedures/hwp/nest/p10_load_iop_xram.mk $
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
PROCEDURE=p10_load_iop_xram
OBJS+=p10_iop_xram_utils.o
OBJS+=p10_pcie_scominit.o
OBJS+=p10_phb_hv_access.o
OBJS+=p10_phb_hv_utils.o
OBJS+=p10_pcie_utils.o
lib$(PROCEDURE)_DEPLIBS+=p10_ipl_image
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(ROOTPATH)/chips/p10/utils/imageProcs)
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(ROOTPATH)/chips/common/utils/imageProcs)
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(ROOTPATH)/chips/p10/procedures/hwp/pm)
$(call BUILD_PROCEDURE)
