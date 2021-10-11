# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/sbeio/common/common.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2018,2021
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

#Common Include Paths
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/ffdc
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/perv
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/lib
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/sbe
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/scomt

#Common Objects
OBJS += sbe_attn.o
OBJS += sbe_retry_handler.o
OBJS += p10_sbe_hreset.o
OBJS += p10_start_cbs.o
OBJS += p10_get_sbe_msg_register.o
OBJS += sbe_psudd_common.o
OBJS += sbe_ffdc_parser.o
OBJS += sbe_ffdc_package_parser.o
OBJS += sbe_getCapabilities.o
OBJS += sbe_psuGetHwReg.o
OBJS += sbe_utils.o

#Common VPATHs
VPATH += ${ROOTPATH}/src/usr/sbeio/common
VPATH += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs
VPATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/perv/
VPATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/sbe/
VPATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/lib/
