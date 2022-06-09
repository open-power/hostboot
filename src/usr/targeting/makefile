# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2022
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
################################################################################
#
#  @file src/usr/targeting/makefile
#
#  @brief Makefile for building Hostboot's targeting implementation
#
################################################################################

ROOTPATH = ../../..
MODULE = targeting

TARGETING_REL_PATH = .

EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/plat

include ${TARGETING_REL_PATH}/hostboot_common.mk

EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/sbe
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include

ATTR_RP_OBJS += attrrp.o
ATTR_RP_OBJS += attrsync.o
ATTR_RP_OBJS += targplatutil.o

ENTRY_POINT_OBJS += targetservicestart.o

DEBUG_OBJS += attributestrings.o

HOSTBOOT_SPECIFIC_OBJS += ${ENTRY_POINT_OBJS}
HOSTBOOT_SPECIFIC_OBJS += ${ATTR_RP_OBJS}
HOSTBOOT_SPECIFIC_OBJS += ${DEBUG_OBJS}
HOSTBOOT_SPECIFIC_OBJS += ${HOSTBOOT_RT_IPL_COMMON_OBJS}
HOSTBOOT_SPECIFIC_OBJS += namedtarget.o
HOSTBOOT_SPECIFIC_OBJS += attrcheck_errl.o
OBJS += persistrwattrcheck.o


# Indicates that targutilbase.o will be excluded from targeting and put in
# the base image for hostboot builds only. See common/common.mk and grep
# for TARGUTILBASE for the exclusion logic.
TARGUTILBASE=

#debug :
#	@echo COMMON_TARGETING_REL_PATH = ${COMMON_TARGETING_REL_PATH}
#	@echo COMMON_TARGETING_MAKEFILE = ${COMMON_TARGETING_MAKEFILE}
#	@echo COMMON_TARGETING_SUBDIRS = ${COMMON_TARGETING_SUBDIRS}
#	@echo VPATH = ${VPATH}
#	@echo COMMON_TARGETING_OBJS = ${COMMON_TARGETING_OBJS}

OBJS += ${COMMON_TARGETING_OBJS}
OBJS += ${HOSTBOOT_SPECIFIC_OBJS}

SUBDIRS += test.d
SUBDIRS += xmltohb.d
SUBDIRS += runtime.d
SUBDIRS += attroverride.d

include ${ROOTPATH}/config.mk

# To find errludattribute.[CH], etc.  They are generated
# by src/usr/targeting/common/xmltohb/xmltohb.pl
vpath %.C ${GENDIR}
