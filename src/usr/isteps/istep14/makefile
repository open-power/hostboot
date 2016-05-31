# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep14/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2016
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
MODULE = istep14

PROCEDURE_PATH = ${ROOTPATH}/src/import/chips/p9/procedures

#Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/obj/genfiles/
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs
EXTRAINCDIR += ${PROCEDURE_PATH}/hwp/nest
EXTRAINCDIR += ${PROCEDURE_PATH}/hwp/memory
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include/
EXTRAINCDIR += ${PROCEDURE_PATH}/xml/error_info/
EXTRAINCDIR += ${PROCEDURE_PATH}/hwp/memory/lib/eff_config/
EXTRAINCDIR += ${PROCEDURE_PATH}/hwp/memory/lib/

OBJS += call_mss_memdiag.o
OBJS += call_mss_thermal_init.o
OBJS += call_proc_pcie_config.o
OBJS += call_mss_power_cleanup.o
OBJS += call_proc_setup_bars.o
OBJS += call_proc_htm_setup.o
OBJS += call_proc_exit_cache_contained.o
OBJS += call_host_mpipl_service.o

#Object files from lib directories
OBJS += memory_size.o
OBJS += c_str.o

include ${ROOTPATH}/procedure.rules.mk
include ${PROCEDURE_PATH}/hwp/nest/p9_htm_setup.mk
include ${PROCEDURE_PATH}/hwp/nest/p9_pcie_config.mk
include ${PROCEDURE_PATH}/hwp/nest/p9_exit_cache_contained.mk
include ${PROCEDURE_PATH}/hwp/nest/p9_setup_bars.mk
include ${PROCEDURE_PATH}/hwp/nest/p9_mss_setup_bars.mk
# include ${PROCEDURE_PATH}/hwp/memory/p9_mss_memdiag.mk
# include ${PROCEDURE_PATH}/hwp/memory/p9_mss_thermal_init.mk
include ${PROCEDURE_PATH}/hwp/memory/p9_mss_power_cleanup.mk
include ${ROOTPATH}/config.mk


VPATH    += ${PROCEDURE_PATH}/hwp/nest/ ${PROCEDURE_PATH}/hwp/memory/
VPATH    += ${PROCEDURE_PATH}/hwp/memory/lib/eff_config/
VPATH    += ${PROCEDURE_PATH}/hwp/memory/lib/utils/
