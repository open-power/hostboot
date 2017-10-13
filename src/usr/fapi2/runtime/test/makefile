# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/fapi2/runtime/test/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2017
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
# @file src/usr/fapi2/runtime/test/makefile
#
# @brief Makefile for fapi2 runtime test directory
#
HOSTBOOT_RUNTIME = 1
ROOTPATH = ../../../../..
MODULE = testfapi2_rt

include ../../test/fapi2Test.mk

#Use temp variables to remove the tests we do not want to run in runtime
TMPVAR1 := ${TESTS}
#RTC: 181003 need to determine why fapi2HwpErrorBufferTest.H is getting data storage exception in RT
TESTS = $(filter-out ${ROOTPATH}/src/usr/fapi2/test/getVpdTest.H ${ROOTPATH}/src/usr/fapi2/test/fapi2GetVpdTest.H ${ROOTPATH}/src/usr/fapi2/test/fapi2HwpErrorBufferTest.H ${ROOTPATH}/src/usr/fapi2/test/fapi2SubroutineExecutorTest.H  ,  ${TMPVAR1})
TMPVAR2 := ${OBJS}
OBJS = $(filter-out getVpdTest.o, ${TMPVAR2})
include ${ROOTPATH}/config.mk
VPATH += ../../test/

