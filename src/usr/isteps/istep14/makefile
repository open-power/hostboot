# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep14/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2020
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

# FIXME RTC: 210975

PROCEDURE_PATH = ${ROOTPATH}/src/import/chips/p10/procedures
EXPLORER_COMMON_PATH = ${ROOTPATH}/src/import/chips/ocmb/explorer/common
EXPLORER_HWP_PATH = ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory
OBJ_GENFILES = ${ROOTPATH}/obj/genfiles

#Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/plat
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/imageProcs
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/core/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/common/scominfo/
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
#EXTRAINCDIR += ${ROOTPATH}/src/import/
#EXTRAINCDIR += ${PROCEDURE_PATH}/hwp/memory
#EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include/
#EXTRAINCDIR += ${PROCEDURE_PATH}/hwp/memory/lib/eff_config/
#EXTRAINCDIR += ${PROCEDURE_PATH}/hwp/memory/lib/
#EXTRAINCDIR += ${PROCEDURE_PATH}/hwp/memory/lib/mcbist/
#EXTRAINCDIR += ${PROCEDURE_PATH}/hwp/memory/lib/dimm/
#EXTRAINCDIR += ${PROCEDURE_PATH}/hwp/memory/lib/dimm/ddr4/
#EXTRAINCDIR += ${EXP_COMMON_PATH}/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/nest/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/scomt/  # proc_somt.Hd
#EXTRAINCDIR += ${ROOTPATH}/src/import/generic/memory
EXTRAINCDIR += ${ROOTPATH}/src/import/generic/memory/lib/utils/  # gen_mss_unmask.H
EXTRAINCDIR += ${ROOTPATH}/src/import/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/pm/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/memory/   # p10_defaults.H
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/common/utils/    # chipids.H
EXTRAINCDIR += ${PROCEDURE_PATH}/hwp/nest
EXTRAINCDIR += ${EXPLORER_COMMON_PATH}/include/
EXTRAINCDIR += ${EXPLORER_HWP_PATH}/lib/shared/
EXTRAINCDIR += ${EXPLORER_HWP_PATH}/lib/inband/
EXTRAINCDIR += ${ROOTPATH}/src/import/generic/memory/lib/ # mss_generic_attribute_getters.H
EXTRAINCDIR += ${EXPLORER_HWP_PATH}/      # exp_mss_thermal_init_utils.H
EXTRAINCDIR += ${EXPLORER_HWP_PATH}/lib/  # mss_explorer_attribute_getters.H

OBJS += call_mss_memdiag.o
OBJS += call_mss_thermal_init.o
OBJS += call_proc_pcie_config.o
OBJS += call_proc_load_iop_xram.o
#OBJS += call_mss_power_cleanup.o
OBJS += call_proc_setup_mmio_bars.o
OBJS += call_proc_htm_setup.o
OBJS += call_proc_exit_cache_contained.o
#OBJS += call_host_mpipl_service.o

include ${ROOTPATH}/procedure.rules.mk
include ${PROCEDURE_PATH}/hwp/nest/p10_exit_cache_contained.mk
include ${PROCEDURE_PATH}/hwp/nest/p10_l2_flush.mk
include ${PROCEDURE_PATH}/hwp/nest/p10_l3_flush.mk
#include ${PROCEDURE_PATH}/hwp/nest/p10_adu_setup.mk
include ${PROCEDURE_PATH}/hwp/nest/p10_adu_access.mk
include ${PROCEDURE_PATH}/hwp/nest/p10_revert_sbe_mcs_setup.mk

# TODO: RTC 159164: Multiple definition linker errors on HWPs that include the
# same *.o file in their *.mk files
# ---- Workaround: Compile the HWP directly below
OBJS += p10_adu_setup.o
OBJS += p10_setup_mmio_bars.o
OBJS += p10_putmemproc.o
OBJS += p10_getputmemproc_utils.o
OBJS += p10_putsram.o
OBJS += p10_getputsram_utils.o
OBJS += p10_putsram_io_ppe.o
OBJS += p10_io_ppe_utils.o
OBJS += p10_pcie_config.o
OBJS += p10_write_xram.o
OBJS += p10_qme_sram_access.o
OBJS += exp_mss_thermal_init.o
OBJS += p10_throttle_sync.o
#OBJS += p9_htm_start.o
#OBJS += p9_htm_reset.o
#OBJS += p9_htm_adu_ctrl.o
#OBJS += p9_pcie_config.o
#OBJS += p9_fbc_smp_utils.o
#OBJS += p9_mpipl_chip_cleanup.o
#OBJS += p9_mss_thermal_init.o

include ${PROCEDURE_PATH}/hwp/nest/p10_htm_setup.mk
include ${PROCEDURE_PATH}/hwp/nest/p10_load_iop_xram.mk
#include ${PROCEDURE_PATH}/hwp/nest/p9_setup_bars.mk
# ---- End workaround

# include ${PROCEDURE_PATH}/hwp/memory/p9_mss_memdiag.mk
# include ${PROCEDURE_PATH}/hwp/memory/p9_mss_thermal_init.mk
#include ${PROCEDURE_PATH}/hwp/nest/p9_throttle_sync.mk
#include ${PROCEDURE_PATH}/hwp/memory/p9_mss_power_cleanup.mk

OBJS += p10_scominfo.o

VPATH += ${ROOTPATH}/src/import/chips/p10/common/scominfo/
VPATH += ${PROCEDURE_PATH}/hwp/nest/
VPATH += ${PROCEDURE_PATH}/hwp/core/
VPATH += ${PROCEDURE_PATH}/hwp/pm/
VPATH += ${PROCEDURE_PATH}/hwp/memory/
VPATH += ${EXPLORER_HWP_PATH}/
VPATH += ${ROOTPATH}/src/import/chips/common/utils/scomt/

include ${ROOTPATH}/config.mk
#VPATH    += ${PROCEDURE_PATH}/hwp/memory/lib/eff_config/
#VPATH    += ${PROCEDURE_PATH}/hwp/memory/lib/utils/
#VPATH    += ${PROCEDURE_PATH}/hwp/memory/lib/mcbist/
#VPATH    += ${PROCEDURE_PATH}/hwp/memory/lib/dimm/
#VPATH    += ${PROCEDURE_PATH}/hwp/memory/lib/dimm/ddr4/
