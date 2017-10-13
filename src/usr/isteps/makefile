# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2017
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
ROOTPATH=../../..
MODULE = isteps

SUBDIRS+=istep06.d
SUBDIRS+=istep07.d
SUBDIRS+=istep08.d
SUBDIRS+=istep09.d
SUBDIRS+=istep10.d
SUBDIRS+=istep11.d
SUBDIRS+=istep12.d
SUBDIRS+=istep13.d
SUBDIRS+=istep14.d
SUBDIRS+=istep15.d
SUBDIRS+=istep16.d
SUBDIRS+=istep18.d
SUBDIRS+=istep20.d
SUBDIRS+=istep21.d
SUBDIRS+=pm.d
SUBDIRS+=p9_stop_util.d
SUBDIRS+=mss.d
SUBDIRS+=cen.d
SUBDIRS+=cpuWkup.d
SUBDIRS+=p9_phbPerst.d

OBJS += hwpisteperror.o
OBJS += hwpistepud.o
OBJS += istepHelperFuncs.o
OBJS += pbusLinkSvc.o

#TODO: RTC 176018
EXTRAINCDIR += ${ROOTPATH}/src/import/

OBJS += $(if $(CONFIG_OPENPOWER_VOLTMSG),openpower_vddr.o,hbToHwsvVoltageMsg.o)

EXTRAINCDIR += ${ROOTPATH}/src/usr/initservice/istepdispatcher
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/ffdc/

include ${ROOTPATH}/config.mk
