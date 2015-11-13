# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2015
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
include ${TARGETING_REL_PATH}/hostboot_common.mk

ATTR_RP_OBJS += attrrp.o
ATTR_RP_OBJS += attrsync.o
ATTR_RP_OBJS += targplatutil.o
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi

ENTRY_POINT_OBJS += targetservicestart.o

DEBUG_OBJS += attributestrings.o

HOSTBOOT_SPECIFIC_OBJS += ${ENTRY_POINT_OBJS}
HOSTBOOT_SPECIFIC_OBJS += ${ATTR_RP_OBJS}
HOSTBOOT_SPECIFIC_OBJS += ${DEBUG_OBJS}
HOSTBOOT_SPECIFIC_OBJS += ${HOSTBOOT_RT_IPL_COMMON_OBJS}
HOSTBOOT_SPECIFIC_OBJS += namedtarget.o


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
#@TODO RTC:128106
#SUBDIRS += attroverride.d

include ${ROOTPATH}/config.mk

vpath %.C ${GENDIR}
