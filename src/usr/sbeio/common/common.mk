# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/sbeio/common/common.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2018
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

#Common .mk files to include
include ${ROOTPATH}/procedure.rules.mk
include ${PROCEDURES_PATH}/hwp/sbe/p9_get_sbe_msg_register.mk
include ${PROCEDURES_PATH}/hwp/perv/p9_start_cbs.mk
include ${PROCEDURES_PATH}/hwp/perv/p9_sbe_hreset.mk

#Common Include Paths
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/ffdc
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/perv
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/lib
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/sbe
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs

#Common Objects
OBJS += p9_extract_sbe_rc.o
OBJS += p9_ppe_common.o
OBJS += sbe_attn.o
OBJS += sbe_retry_handler.o

#Common VPATHs
VPATH += ${ROOTPATH}/src/usr/sbeio/common
VPATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/sbe/
VPATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/lib/
VPATH += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/perv/