# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/i2c/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2024
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
ROOTPATH = ../../..
MODULE = i2c

EXTRAINCDIR += $(ROOTPATH)/src/include/

EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc/
EXTRAINCDIR += ${ROOTPATH}/src/import/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/include/
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/chips/ocmb/common/procedures/hwp/pmic/lib/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic/lib/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic/lib/i2c
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/lib/utils

#include common objects between hb and runtime
include i2c.mk

#include unique objects
OBJS += i2c.o
OBJS += fapi_i2c_dd.o
OBJS += i2cTargetPres.o

SUBDIRS += test.d
SUBDIRS += runtime.d

include ${ROOTPATH}/config.mk
