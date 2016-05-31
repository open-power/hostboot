# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep06/thread_activate/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2016
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
ROOTPATH = ../../../../..

MODULE = thread_activate

##      support for fapi2
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/isteps/

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
HWP_PATH_1 += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/core
HWP_PATH_2 += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/pm
HWP_PATH += ${HWP_PATH_1}/ ${HWP_PATH_2}/
EXTRAINCDIR += ${HWP_PATH}

##  NOTE: add new object files when you add a new HWP
OBJS += thread_activate.o


##  NOTE: add a new directory onto the vpaths when you add a new HWP
VPATH += ${HWP_PATH}

include ${ROOTPATH}/procedure.rules.mk
# p9_thread_control.o brought in by p9_thread_control.mk
include $(HWP_PATH_1)/p9_thread_control.mk
# p9_cpu_special_wakeup.o brought in by p9_cpu_special_wakeup.mk
include $(HWP_PATH_2)/p9_cpu_special_wakeup.mk
include ${ROOTPATH}/config.mk

