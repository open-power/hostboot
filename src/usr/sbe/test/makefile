# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/sbe/test/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2020
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
ROOTPATH = ../../../..

MODULE = testsbe
TESTS = *.H

# needed for sbe_update.H p10_infrastruct_help.H
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
# needed for fapi2.H pulled by p10_infrastruct_help.H
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
# needed for target.H pulled by fapi2.H
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
# needed for multicast_group_defs.H pulled by plat_target.H
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
# needed for common_ringId.H pulled by plat_hw_access.H
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
# needed for ffdc_includes.H pulled by hwp_ffdc_classes.H
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc/

include ${ROOTPATH}/config.mk
