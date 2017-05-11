# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/p9/procedures/hwp/pm/p9_hcode_image_build.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2017
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
PROCEDURE = p9_hcode_image_build
HCODE_UTIL=$(ROOTPATH)/chips/p9/procedures/utils/stopreg/
HCODE_UTIL+=$(ROOTPATH)/chips/p9/procedures/hwp/customize/
HCODE_UTIL+=$(ROOTPATH)/chips/p9/xip/
HCODE_UTIL+=$(ROOTPATH)/chips/p9/procedures/hwp/lib/
HCODE_UTIL+=$(ROOTPATH)/tools/imageProcs/
HCODE_UTIL+=$(ROOTPATH)/chips/p9/procedures/hwp/customize/
HCODE_UTIL+=$(ROOTPATH)/chips/p9/common/include/
HCODE_UTIL+=$(ROOTPATH)/chips/p9/procedures/utils/stopreg/
HCODE_UTIL+=$(ROOTPATH)/chips/p9/procedures/hwp/nest

lib$(PROCEDURE)_DEPLIBS += p9_scan_ring_util
lib$(PROCEDURE)_DEPLIBS += p9_xip_image
lib$(PROCEDURE)_DEPLIBS += p9_pstate_parameter_block
lib$(PROCEDURE)_DEPLIBS += p9_tor
lib$(PROCEDURE)_DEPLIBS += p9_ringId
lib$(PROCEDURE)_DEPLIBS += p9_stop_util
lib$(PROCEDURE)_DEPLIBS += p9_stop_api
lib$(PROCEDURE)_DEPLIBS += p9_fbc_utils
lib$(PROCEDURE)_DEPLIBS += p9_dd_container

$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(HCODE_UTIL))
$(call BUILD_PROCEDURE)
