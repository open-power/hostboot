# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/cpuWkup/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2019
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
MODULE = p9_cpuWkup
# FIXME RTC: 210975
#PROCEDURES_PATH    = ${ROOTPATH}/src/import/chips/p9/procedures

#EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/pm/
#EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/
#EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
#EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/lib/
#EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include/
#EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/

#include ${ROOTPATH}/procedure.rules.mk
#include $(PROCEDURES_PATH)/hwp/pm/p9_cpu_special_wakeup_eq.mk
#include $(PROCEDURES_PATH)/hwp/pm/p9_cpu_special_wakeup_ex.mk
#include $(PROCEDURES_PATH)/hwp/pm/p9_cpu_special_wakeup_core.mk
#include $(PROCEDURES_PATH)/hwp/pm/p9_cpu_special_wakeup_lib.mk
#include $(PROCEDURES_PATH)/hwp/pm/p9_block_wakeup_intr.mk
include ${ROOTPATH}/config.mk

#VPATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/pm/
