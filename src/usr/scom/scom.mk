# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/scom/scom.mk $
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


VPATH += ${ROOTPATH}/src/import/chips/p10/common/scominfo/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/scominfo/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/


EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/pm/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/scomt/

# Local Objects
OBJS += scom.o
OBJS += scomtrans.o
OBJS += errlud_pib.o
OBJS += preopchecks.o
OBJS += postopchecks.o
OBJS += DmiScomWorkaround.o
OBJS += ibscom_retry.o
OBJS += handleSpecialWakeup.o
OBJS += ibscom.o

# Objects From Import Directory
OBJS += p10_scominfo.o
OBJS += p10_scom_addr.o
