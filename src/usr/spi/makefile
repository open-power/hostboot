# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/spi/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2019,2020
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

MODULE = spi

HWP_PATH += ${ROOTPATH}/src/import/chips/p10/procedures

EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${HWP_PATH}/hwp/ffdc
EXTRAINCDIR += ${HWP_PATH}/../common/include/
EXTRAINCDIR += ${HWP_PATH}/hwp/spi/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/scomt/
EXTRAINCDIR += ${ROOTPATH}/src/inlcude/usr/

VPATH += ${HWP_PATH}/hwp/spi/

#include unique objects
OBJS += spi.o
OBJS += spidd.o
OBJS += errlud_spi.o
OBJS += p10_spi_init_pib.o
OBJS += p10_spi_init_fsi.o
OBJS += $(if $(CONFIG_TPMDD),tpmdd.o,)

SUBDIRS += test.d

include ${ROOTPATH}/procedure.rules.mk
include ${HWP_PATH}/hwp/spi/p10_sbe_spi_cmd.mk
include ${ROOTPATH}/config.mk
