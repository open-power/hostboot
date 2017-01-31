# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/fapi2/test/fapi2Test.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2017
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
#
# @file src/usr/fapi2/test/fapi2Test.mk
#
# @brief Common makefile for fapi2 and runtime test directory
#

EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/usr/fapi2/test/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/pm/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/accessors/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/targeting/common/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/ffdc/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/

# Procedures
OBJS += p9_sample_procedure.o
OBJS += p9_hwtests.o
OBJS += rcSupport.o
OBJS += fapi2TestUtils.o
OBJS += getVpdTest.o
OBJS += p9_pm_get_poundv_bucket.o

TESTS += ${shell find ${ROOTPATH}/src/usr/fapi2/test/ | sort | grep -e "Test.H" -e "TestCxx.H" | xargs}

VPATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/pm/
