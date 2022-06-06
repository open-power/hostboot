# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/hostboot_common.mk $
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

ROOTPATH=../../..

COMMON_TARGETING_REL_PATH = ${TARGETING_REL_PATH}/common
COMMON_TARGETING_MAKEFILE = ${COMMON_TARGETING_REL_PATH}/common.mk

include ${COMMON_TARGETING_MAKEFILE}

VPATH += ${TARGETING_REL_PATH}/adapters
VPATH += ${COMMON_TARGETING_REL_PATH}
VPATH += ${addprefix ${COMMON_TARGETING_REL_PATH}/, ${COMMON_TARGETING_SUBDIRS}}

# Next includes required for attribute override support
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/include/util/

HOSTBOOT_RT_IPL_COMMON_OBJS += attrPlatOverride.o
HOSTBOOT_RT_IPL_COMMON_OBJS += translateTarget.o

