# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep18/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016
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

MODULE = istep18
PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/p9/procedures

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/tod_init
EXTRAINCDIR += ${PROCEDURES_PATH}
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/isteps


## pointer to common HWP files

#@TODO-RTC:149253-Add TOD support
OBJS += tod_init.o
#OBJS += TodControls.o
#OBJS += TodDrawer.o
#OBJS += TodProc.o
#OBJS += TodSvc.o
#OBJS += TodSvcUtil.o
#OBJS += TodHwpIntf.o
#OBJS += TodTopologyManager.o

#OBJS += proc_tod_setup.o
#OBJS += proc_tod_save_config.o
#OBJS += proc_tod_init.o
#OBJS += proc_tod_utils.o
#OBJS += call_tod_setup.o
#OBJS += call_tod_init.o

include ${ROOTPATH}/procedure.rules.mk
include ${ROOTPATH}/config.mk
