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

# Create some aliases for path
SRC_IMPORT_PATH      = ${ROOTPATH}/src/import
P10_PROCEDURE_PATH   = ${SRC_IMPORT_PATH}/chips/p10/procedures/hwp
EXPLORER_HWP_PATH    = ${SRC_IMPORT_PATH}/chips/ocmb/explorer/procedures/hwp/memory
EXPLORER_COMMON_PATH = ${SRC_IMPORT_PATH}/chips/ocmb/explorer/common

# Add all the extra include paths
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
EXTRAINCDIR += ${SRC_IMPORT_PATH}/
EXTRAINCDIR += ${SRC_IMPORT_PATH}/chips/common/utils/
EXTRAINCDIR += ${SRC_IMPORT_PATH}/chips/common/utils/imageProcs
EXTRAINCDIR += ${SRC_IMPORT_PATH}/chips/common/utils/scomt/
EXTRAINCDIR += ${SRC_IMPORT_PATH}/chips/p10/common/scominfo/
EXTRAINCDIR += ${SRC_IMPORT_PATH}/chips/p10/utils/imageProcs/
EXTRAINCDIR += ${SRC_IMPORT_PATH}/generic/memory/lib/
EXTRAINCDIR += ${SRC_IMPORT_PATH}/generic/memory/lib/utils/
EXTRAINCDIR += ${SRC_IMPORT_PATH}/hwpf/fapi2/include
EXTRAINCDIR += ${P10_PROCEDURE_PATH}/memory/
EXTRAINCDIR += ${P10_PROCEDURE_PATH}/nest
EXTRAINCDIR += ${P10_PROCEDURE_PATH}/pm/
EXTRAINCDIR += ${P10_PROCEDURE_PATH}/core/
EXTRAINCDIR += ${EXPLORER_HWP_PATH}/
EXTRAINCDIR += ${EXPLORER_HWP_PATH}/lib/
EXTRAINCDIR += ${EXPLORER_HWP_PATH}/lib/inband/
EXTRAINCDIR += ${EXPLORER_HWP_PATH}/lib/shared/
EXTRAINCDIR += ${EXPLORER_COMMON_PATH}/include/
EXTRAINCDIR += ${P10_PROCEDURE_PATH}/initfiles/

# Add the sub step object files
OBJS += call_mss_memdiag.o
OBJS += call_mss_thermal_init.o
OBJS += call_proc_pcie_config.o
OBJS += call_proc_load_iop_xram.o
OBJS += call_proc_setup_mmio_bars.o
OBJS += call_proc_exit_cache_contained.o
OBJS += call_proc_htm_setup.o
OBJS += call_host_mpipl_service.o

# Include the makefiles to compile the HWPs needed by the sub steps
include ${ROOTPATH}/procedure.rules.mk
include ${P10_PROCEDURE_PATH}/nest/p10_adu_access.mk
include ${P10_PROCEDURE_PATH}/nest/p10_htm_setup.mk
include ${P10_PROCEDURE_PATH}/nest/p10_exit_cache_contained.mk
include ${P10_PROCEDURE_PATH}/nest/p10_load_iop_xram.mk

# Compile the HWP directly because of linking issues with HWPs that
# include the same object file in their *.mk files.
OBJS += exp_mss_thermal_init.o
OBJS += p10_adu_setup.o
OBJS += p10_getputmemproc_utils.o
OBJS += p10_getputsram_utils.o
OBJS += p10_io_ppe_utils.o
OBJS += p10_pcie_config.o
OBJS += p10_putmemproc.o
OBJS += p10_putsram.o
OBJS += p10_putsram_io_ppe.o
OBJS += p10_qme_sram_access.o
OBJS += p10_scominfo.o
OBJS += p10_setup_mmio_bars.o
OBJS += p10_throttle_sync.o
OBJS += p10_write_xram.o
OBJS += p10_sbe_exit_cache_contained.o
OBJS += p10_sbe_apply_xscom_inits.o
OBJS += p10_sbe_purge_hb.o
OBJS += p10_revert_sbe_mcs_setup.o
OBJS += p10_sbe_instruct_start.o
OBJS += p10_l3_flush.o
OBJS += p10_l2_flush.o
OBJS += p10_sbe_stop_hb.o
OBJS += p10_pcie_scom.o

#TODO-RTC:257623--Consolidate this into 3rd-party module to avoid duplication with istep10
# needed by p10_exit_cache_contained
OBJS+=p10_mcc_omi_scom.o
OBJS+=p10_mi_omi_scom.o


# Add the path where HWPs object files are located
VPATH += ${SRC_IMPORT_PATH}/chips/p10/common/scominfo/
VPATH += ${P10_PROCEDURE_PATH}/memory/
VPATH += ${P10_PROCEDURE_PATH}/nest/
VPATH += ${P10_PROCEDURE_PATH}/pm/
VPATH += ${P10_PROCEDURE_PATH}/core/
VPATH += ${EXPLORER_HWP_PATH}/
VPATH += ${P10_PROCEDURE_PATH}/initfiles/

include ${ROOTPATH}/config.mk
