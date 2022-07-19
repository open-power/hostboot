# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_scominit.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2022
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



-include 00ody_common.mk

PROCEDURE=ody_scominit
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(MSS_ODY_INCLUDES))
$(call ADD_MODULE_INCDIR,$(PROCEDURE),$(ROOTPATH)/chips/ocmb/procedures/hwp/initfiles)
$(call BUILD_PROCEDURE)
