# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/errl/runtime/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2015
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

#include common ojects between hostboot and runtime hostboot
include ../errl.mk

VPATH += ${ROOTPATH}/src/usr/hwas/common

OBJS += rt_errlmanager.o
OBJS += rt_vfs.o
OBJS += hwasCallout.o

SUBDIRS += test.d

VPATH += ..
include $(ROOTPATH)/config.mk

# to find errludattribute.[CH] and errludtarget.[CH] - they are generated
#  by src/usr/targeting/common/xmltohb/xmltohb.pl
vpath %.C ${GENDIR}
