# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/expaccess/test/test.mk $
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
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/shared
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/inband/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/explorer/common/include
EXTRAINCDIR += ${ROOTPATH}/src/import
EXTRAINCDIR += ${ROOTPATH}/src/usr/expaccess
EXTRAINCDIR += ${ROOTPATH}/src/usr/expaccess/test
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/

VPATH += ${ROOTPATH}/src/usr/expaccess/test/
VPATH += ${ROOTPATH}/src/usr/expaccess/
VPATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc/

OBJS += exptest_utils.o
OBJS += exp_collect_explorer_log.o
OBJS += exp_collect_explorer_active_log.o
OBJS += exp_collect_explorer_saved_A_log.o
OBJS += exp_collect_explorer_saved_B_log.o
OBJS += rcExpLog.o

include ${ROOTPATH}/config.mk
