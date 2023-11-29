# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/mmio/runtime/test/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2023
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

HOSTBOOT_RUNTIME = 1
ROOTPATH = ../../../../..
MODULE = testmmio_rt

EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/explorer/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/odyssey/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/odyssey/procedures/hwp/sppe/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/

EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/sbe/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/perv/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/

EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/usr/
EXTRAINCDIR += ${ROOTPATH}/src/usr/mmio
EXTRAINCDIR += ${ROOTPATH}/src/usr/expaccess/

EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/attr/

VPATH += ${ROOTPATH}/src/usr/sbeio

OBJS += sbe_getCodeLevels.o

TESTS = *.H

include ${ROOTPATH}/config.mk
