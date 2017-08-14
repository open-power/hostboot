# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/runtime/test/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2017
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

MODULE = testruntime
#@TODO RTC 132750
#TESTS += hdatservicetest.H
#@TODO RTC:178802
#TESTS += test_customize_attrs_for_payload.H

# The testcase depends on the following file, but it is typically only compiled
# into the runtime code.  Pull it into just the test module so we can exercise
# it
#@TODO RTC:178802
#OBJS += rt_targeting.o

# Use a vpath to give access to the rt_targeting.C code
#@TODO RTC:178802
#vpath %.C ../../targeting/runtime

#@TODO RTC:132750
#TESTS += runtimeattrtest.H

#@TODO RTC:178802
#EXTRAINCDIR += ${ROOTPATH}/src/include/usr/runtime/

include ${ROOTPATH}/config.mk
