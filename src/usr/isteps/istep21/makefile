# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep21/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2021
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
MODULE = istep21

#TODO RTC:214285
#PROCEDURES_PATH = ${ROOTPATH}/src/import/chips/p9/procedures

EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/pm/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/initfiles/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/lib/
#EXTRAINCDIR += ${PROCEDURES_PATH}/utils/stopreg/

EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
EXTRAINCDIR += ${ROOTPATH}/src/usr/runtime/

OBJS += call_host_runtime_setup.o
OBJS += freqAttrData.o
OBJS += call_host_verify_hdat.o
OBJS += call_host_start_payload.o
OBJS += p10_get_freq_compat_settings.o
OBJS += p10_check_freq_compat.o
OBJS += $(if $(CONFIG_UCD_FLASH_UPDATES),call_update_ucd_flash.o,)

OBJS += $(if $(CONFIG_NVDIMM),call_nvdimm_update.o,)

VPATH += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/pm/

include ${ROOTPATH}/config.mk
