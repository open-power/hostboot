# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/nvdimm/nvdimm.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2018,2020
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
# nvdimmm.mk should only be called when CONFIG_NVDIMM is set
# Called by src/makefile with the condition that CONFIG_NVDIMM is defined

# FIXME RTC:249244

#PROCEDURE_PATH = ${ROOTPATH}/src/import/chips/p9/procedures

#Add all the extra include paths

EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/
#EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
#EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2
#EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
#EXTRAINCDIR += ${ROOTPATH}/src/import/
#EXTRAINCDIR += ${PROCEDURE_PATH}/hwp/memory
#EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include/
#EXTRAINCDIR += ${PROCEDURE_PATH}/hwp/memory/lib/eff_config/
#EXTRAINCDIR += ${PROCEDURE_PATH}/hwp/memory/lib/
#EXTRAINCDIR += ${PROCEDURE_PATH}/hwp/memory/lib/mcbist/
#EXTRAINCDIR += ${PROCEDURE_PATH}/hwp/memory/lib/dimm/
#EXTRAINCDIR += ${PROCEDURE_PATH}/hwp/memory/lib/dimm/ddr4/
#EXTRAINCDIR += ${PROCEDURE_PATH}/hwp/memory/
#EXTRAINCDIR += ${PROCEDURE_PATH}/hwp/ffdc/

OBJS += nvdimm.o
OBJS += nvdimmdd.o
OBJS += errlud_nvdimm.o

ifneq (${HOSTBOOT_RUNTIME},1)

# code update path for NVDIMMs (not at RUNTIME)
OBJS += nvdimm_update.o

endif

#VPATH    += ${PROCEDURE_PATH}/hwp/memory/lib/dimm/ddr4/
