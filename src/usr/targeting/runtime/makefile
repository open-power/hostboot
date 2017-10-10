# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/runtime/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2017
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
MODULE = targeting_rt

SUBDIRS += test.d

TARGETING_REL_PATH = ..
include ${TARGETING_REL_PATH}/hostboot_common.mk
ROOTPATH = ../../../..

vpath %.C ${TARGETING_REL_PATH}

HOSTBOOT_RUNTIME_SPECIFIC_OBJS += attrrp_rt.o
HOSTBOOT_RUNTIME_SPECIFIC_OBJS += start_rt.o
HOSTBOOT_RUNTIME_SPECIFIC_OBJS += targplatutil.o
HOSTBOOT_RUNTIME_SPECIFIC_OBJS += rt_targeting.o
HOSTBOOT_RUNTIME_SPECIFIC_OBJS += attrPlatOverride_rt.o
HOSTBOOT_RUNTIME_SPECIFIC_OBJS += errludattribute.o
HOSTBOOT_RUNTIME_SPECIFIC_OBJS += attributestrings.o

OBJS += ${COMMON_TARGETING_OBJS}
OBJS += ${HOSTBOOT_RT_IPL_COMMON_OBJS}
OBJS += ${HOSTBOOT_RUNTIME_SPECIFIC_OBJS}
OBJS += persistrwattrcheck.o


include $(ROOTPATH)/config.mk


# To find errludattribute.[CH], etc.  They are generated
# by src/usr/targeting/common/xmltohb/xmltohb.pl
vpath %.C ${GENDIR}
