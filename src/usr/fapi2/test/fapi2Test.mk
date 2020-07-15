# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/fapi2/test/fapi2Test.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2020
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
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/pm/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/accessors/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/targeting/common/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/
EXTRAINCDIR += ${ROOTPATH}/src/usr/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwp/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc/
EXTRAINCDIR += ${ROOTPATH}/src/usr/diag/attn/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/diag/

# TODO RTC: 210905 Uncomment the procedures below
# Procedures
OBJS += p10_sample_procedure.o
OBJS += p10_hwtests.o
OBJS += rcSupport.o
OBJS += fapi2TestUtils.o
OBJS += fapi2DdimmGetEfdTest.o
# FIXME RTC:257497-Update to new target and vpd types
#OBJS += getVpdTest.o
OBJS += p10_pm_get_poundv_bucket.o
OBJS += fapi2PlatGetVpdOcmbChipTest.o

ifeq (${HOSTBOOT_RUNTIME},1)
## Remove non-runtime tests (grep -v testname.H)
TESTS += ${shell ls ${ROOTPATH}/src/usr/fapi2/test/*Test.H | \
         grep -v fapi2PlatGetVpdOcmbChipTest.H | \
         grep -v fapi2I2cAccessTest.H | \
         grep -v fapi2MmioAccessTest.H | \
         sort | xargs}
else
## All hostboot IPL time tests
TESTS += ${shell ls ${ROOTPATH}/src/usr/fapi2/test/*Test.H | \
         sort | xargs}
EXTRAINCDIR += ${ROOTPATH}/src/usr/expaccess/

OBJS += p10_i2ctests.o
OBJS += p10_mmiotests.o
endif

TESTS += ${shell ls ${ROOTPATH}/src/usr/fapi2/test/*TestCxx.H | sort | xargs}

# FIXME RTC:257497
# Remove the following "filter-out" command after RTC is fixed.
# Info: Can't include fapi2ChipEcTest.H in TESTS objects because it requires
# attributes from src/import/chips/p9/procedures/xml/attribute_info/
# chip_ec_attributes.xml. There is a p10 equivalent src/import/chips/p10/
# procedures/xml/attribute_info/p10_chip_ec_attributes.xml which is being parsed
# out to a gen file, but it doesn't have all the required attributes.
TESTS := $(filter-out ${ROOTPATH}/src/usr/fapi2/test/fapi2ChipEcTest.H,$(TESTS))

# FIXME RTC:257497
# PROC_EXAMPLE_ERROR RC_PROC_EXAMPLE_ERROR_BUFFER required, which for p9 came
# from: src/import/chips/p9/procedures/xml/error_info/proc_example_errors.xml
# For p10 this file is not in the ekb-p10 branch yet:
# http://habcap11p1.aus.stglabs.ibm.com:8080/source/xref/ekb-p10/chips/p10/procedures/xml/error_info/
TESTS := $(filter-out ${ROOTPATH}/src/usr/fapi2/test/fapi2HwpErrorBufferTest.H,$(TESTS))

# FIXME RTC:257497
# Uses getVpdTest which has been commented out above
TESTS := $(filter-out ${ROOTPATH}/src/usr/fapi2/test/fapi2GetVpdTest.H,$(TESTS))

# FIXME RTC:257497
# Something seems to be resetting the data, getting different values compared to the boot
TESTS := $(filter-out %/fapi2DdimmGetEfdTest.H,$(TESTS))

# Will delete after enabling TESTS objects
VPATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/pm/
