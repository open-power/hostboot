# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/p10/procedures/hwp/pm/p10_hcode_image_build.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2021
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
PROCEDURE=p10_hcode_image_build
HCODE_UTIL=$(ROOTPATH)/chips/p10/procedures/utils/stopreg/
HCODE_UTIL+=$(ROOTPATH)/chips/p10/utils/imageProcs/
HCODE_UTIL+=$(ROOTPATH)/chips/p10/procedures/hwp/lib/
HCODE_UTIL+=$(ROOTPATH)/chips/p10/procedures/hwp/pm/
HCODE_UTIL+=$(ROOTPATH)/chips/p10/procedures/hwp/nest/
HCODE_UTIL+=$(ROOTPATH)/chips/p10/common/include/
HCODE_UTIL+=$(ROOTPATH)/chips/p10/procedures/hwp/customize/
HCODE_UTIL+=$(ROOTPATH)/chips/p10/procedures/hwp/accessors/
HCODE_UTIL+=$(ROOTPATH)/chips/p10/procedures/utils/stopreg/
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(HCODE_UTIL))
lib$(PROCEDURE)_DEPLIBS += p10_ddco
lib$(PROCEDURE)_DEPLIBS += p10_stop_util
lib$(PROCEDURE)_DEPLIBS += p10_stop_api
lib$(PROCEDURE)_DEPLIBS += p10_ipl_image
lib$(PROCEDURE)_DEPLIBS += p10_scan_ring_util
lib$(PROCEDURE)_DEPLIBS += p10_ipl_customize
lib$(PROCEDURE)_DEPLIBS += p10_get_mvpd_ring
lib$(PROCEDURE)_DEPLIBS += p10_mvpd_ring_funcs
lib$(PROCEDURE)_DEPLIBS += p10_pstate_parameter_block
lib$(PROCEDURE)_DEPLIBS += p10_pm_utils
lib$(PROCEDURE)_DEPLIBS += p10_pm_get_poundw_bucket
lib$(PROCEDURE)_DEPLIBS += p10_pm_get_poundv_bucket
lib$(PROCEDURE)_DEPLIBS += p10_qme_customize
lib$(PROCEDURE)_DEPLIBS += p10_qme_build_attributes
lib$(PROCEDURE)_DEPLIBS	+= p10_scan_compression
lib$(PROCEDURE)_DEPLIBS	+= p10_tor
lib$(PROCEDURE)_DEPLIBS += common_ringId
lib$(PROCEDURE)_DEPLIBS += p10_ringId
lib$(PROCEDURE)_DEPLIBS += p10_fbc_core_topo
lib$(PROCEDURE)_DEPLIBS += p10_fbc_utils
lib$(PROCEDURE)_COMMONFLAGS += -DP10_RS4_CONTANER_SIZE_TRACING
$(call BUILD_PROCEDURE)
