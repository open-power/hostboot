# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/fapi2/test/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2020
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
# @file src/usr/fapi2/test/makefile
#
# @brief Makefile for fapi2 test case directory
#
ROOTPATH = ../../../..
MODULE = testfapi2

include fapi2Test.mk

ifdef TRACE_MB_VPD_ATTR_UNIT_TEST
CXXFLAGS+=-DTRACE_MB_VPD_ATTR_UNIT_TEST
endif

include ${ROOTPATH}/config.mk

vpath %.C ${GENDIR}

