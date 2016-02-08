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
ROOTPATH = ../../../../..

MODULE = tod_init

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include

##  NOTE: add the base istep dir here.
##@ EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/@istepname
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/tod_init

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
##@ EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/???
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/tod_init/proc_tod_setup
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/tod_init/proc_tod_save_config
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/tod_init/proc_tod_utils
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/tod_init/proc_tod_init


##  NOTE: add new object files when you add a new HWP
OBJS += tod_init.o
OBJS += TodControls.o
OBJS += TodDrawer.o
OBJS += TodProc.o
OBJS += TodSvc.o
OBJS += TodSvcUtil.o
OBJS += TodHwpIntf.o
OBJS += TodTopologyManager.o
OBJS += proc_tod_setup.o
OBJS += proc_tod_save_config.o
OBJS += proc_tod_init.o
OBJS += proc_tod_utils.o

##  NOTE: add a new directory onto the vpaths when you add a new HWP
##@ VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/???
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/tod_init/proc_tod_setup
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/tod_init/proc_tod_save_config
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/tod_init/proc_tod_utils
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/tod_init/proc_tod_init

include ${ROOTPATH}/config.mk
