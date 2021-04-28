# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwplibs/runtime/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2021
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
HOSTBOOT_RUNTIME = 1

MODULE = hwplibs_rt

ROOTPATH = ../../../..

P9_PROCEDURE_PATH = ${ROOTPATH}/src/import/chips/p9/procedures/
HWP_NEST_MEM_UTILS_PATH := ${ROOTPATH}/src/import/chips/p9/procedures/hwp/nest/
EXP_COMMON_PATH = ${ROOTPATH}/src/import/chips/ocmb/explorer/common
AXONE_PROCEDURE_PATH = ${ROOTPATH}/src/import/chips/p9a/procedures

EXTRAINCDIR += ${HWP_NEST_MEM_UTILS_PATH}
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs
EXTRAINCDIR += ${EXP_COMMON_PATH}/include/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/
EXTRAINCDIR += ${ROOTPATH}/src/import/
EXTRAINCDIR += ${AXONE_PROCEDURE_PATH}/hwp/memory/
EXTRAINCDIR += ${P9_PROCEDURE_PATH}/hwp/memory

VPATH += ${HWP_NEST_MEM_UTILS_PATH}

include ${ROOTPATH}/procedure.rules.mk

include ${HWP_NEST_MEM_UTILS_PATH}/p9_putmemproc.mk
OBJS += $(if $(CONFIG_AXONE),p9a_throttle_sync.o,p9_throttle_sync.o)
OBJS += p9_fbc_tl_disable_gathering.o

OBJS += concurrent_inits.o

include ${ROOTPATH}/config.mk
