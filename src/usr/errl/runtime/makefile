# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/errl/runtime/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2022
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
ROOTPATH = ../../../..
MODULE = errl_rt

# include common ojects between hostboot and runtime hostboot
include ../errl.mk

# needed to compile hwasPlatDeconfigGard in runtime context
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/

EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/pm
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include

# support for pm_common
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps

# need find the source for this hwp in runtime env
VPATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/pm

VPATH += ${ROOTPATH}/src/usr/hwas/common
VPATH += ${ROOTPATH}/src/usr/hwas

OBJS += rt_errlmanager.o
OBJS += rt_vfs.o
OBJS += hwasCallout.o
OBJS += deconfigGard.o
OBJS += hwasPlatDeconfigGard.o
OBJS += hwas.o
OBJS += pgLogic.o

SUBDIRS += test.d

VPATH += ..
include $(ROOTPATH)/config.mk

# to find errludattribute.[CH] and errludtarget.[CH] - they are generated
#  by src/usr/targeting/common/xmltohb/xmltohb.pl
vpath %.C ${GENDIR}
