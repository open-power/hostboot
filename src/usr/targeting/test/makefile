# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/test/makefile $
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
#  @file src/usr/targeting/test/makefile
#
#  @brief Makefile for building Hostboot's targeting test dir
#
################################################################################

ROOTPATH = ../../../..

# Determine relative paths to common targeting makefile

COMMON_TARGETING_REL_PATH = ../common
COMMON_MAKEFILE = ${COMMON_TARGETING_REL_PATH}/test/common.mk

# Suck in the common targeting makefile, verbatim

include ${COMMON_MAKEFILE}

# Defines from the common makefile included above:
# - COMMON_TESTCASES (name of common testcase .H's)
# - HWPF_INC_DIRS    (subdirs of HWPF to look for includes)

# Point "make" to find sources and includes in the common and platform
# specific trees

VPATH += ${COMMON_TARGETING_REL_PATH}/test

HWPF_REL_PATH = ${ROOTPATH}/src/include/usr/hwpf

EXTRAINCDIR +=                                       \
    $(addprefix ${HWPF_REL_PATH}/, ${HWPF_INC_DIRS}) \
    ${ROOTPATH}/src/include/usr/ecmddatabuffer       \
    ../                                              \
    ${ROOTPATH}/obj/genfiles/                        \
    ${ROOTPATH}/src/import/hwpf/fapi2/include/       \
    ${ROOTPATH}/src/include/usr/fapi2/

# Generate the test suite

MODULE = testtargeting

COMMON_TESTCASE_REL_PATHS = \
    $(addprefix ${COMMON_TARGETING_REL_PATH}/test/,${COMMON_TESTCASES})

TESTS += testtargeting.H
TESTS += testattrsync.H
TESTS += testattrtank.H
TESTS += testAttribute.H
TESTS += testTargetUtil.H
TESTS += ${COMMON_TESTCASE_REL_PATHS}
TESTS += testattrrules.H
TESTS += testTargPlatUtil.H

OBJS += attributestrings.o

#debug :
#	@echo EXTRAINCDIR = ${EXTRAINCDIR}
#	@echo COMMON_TARGETING_REL_PATH = ${COMMON_TARGETING_REL_PATH}
#	@echo COMMON_MAKEFILE = ${COMMON_MAKEFILE}
#	@echo VPATH = ${VPATH}
#	@echo INCLUDES = ${INCLUDES}
#	@echo COMMON_TESTCASE_REL_PATHS = ${COMMON_TESTCASE_REL_PATHS}
#	@echo COMMON_TESTCASES = ${COMMON_TESTCASES}
#	@echo HWPF_INC_DIRS = ${HWPF_INC_DIRS}
#	@echo TESTS = ${TESTS}

include ${ROOTPATH}/config.mk

vpath %.C ${GENDIR}
