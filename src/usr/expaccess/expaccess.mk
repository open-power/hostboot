# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/expaccess/expaccess.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2019,2021
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
EXTRAINCDIR += ${ROOTPATH}/src/import
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/inband/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/ocmb/explorer/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2

VPATH += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/inband/
VPATH += ${ROOTPATH}/src/import/generic/memory/lib/utils/
VPATH += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/i2c
VPATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc/

# Need to build exp_inband to use EKB's getMMIO/putMMIO/getCMD/getRSP
OBJS += exp_inband.o
OBJS += expscom_trace.o
OBJS += expscom_utils.o
OBJS += i2cscomdd.o
OBJS += mmioscomdd.o
OBJS += exp_fw_log.o
OBJS += exp_fw_log_data.o
OBJS += errlud_expscom.o
OBJS += c_str.o
OBJS += exp_i2c.o
OBJS += exp_fw_adapter_properties.o
OBJS += exp_collect_explorer_log.o
