# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/scom/test/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2019
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
ROOTPATH = ../../../..

MODULE = testscom
TESTS = *.H

OBJS+=retryWorkaroundTestData.o

#To enable tracing of SCOM Unit Tests
# TRACE_SCOM_UNIT_TEST=1 make -j32
ifdef TRACE_SCOM_UNIT_TEST
CXXFLAGS+=-DTRACE_SCOM_UNIT_TEST
$(info Tracing Enabled For SCOM Unit Tests)
endif

include ${ROOTPATH}/config.mk
