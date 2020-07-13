# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/prdf_hb_only.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2020
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

# NOTE: ROOTPATH must be defined before including this file and both
#       PRD_SRC_PATH and PRD_INC_PATH must be defined in this file.

PRD_SRC_PATH = ${ROOTPATH}/src/usr/diag/prdf
PRD_INC_PATH = ${ROOTPATH}/src/include/usr/diag/prdf

################################################################################
# Paths common to both IPL and runtime
################################################################################

prd_vpath += ${PRD_SRC_PATH}
prd_vpath += ${PRD_SRC_PATH}/framework
prd_vpath += ${PRD_SRC_PATH}/mnfgtools
prd_vpath += ${PRD_SRC_PATH}/occ_firdata
prd_vpath += ${PRD_SRC_PATH}/plat

# Internal PRD header paths
prd_incpath += ${PRD_INC_PATH}        # Stored differently in FSP
prd_incpath += ${PRD_INC_PATH}/common # Stored differently in FSP
prd_incpath += ${PRD_SRC_PATH}
prd_incpath += ${PRD_SRC_PATH}/framework
prd_incpath += ${PRD_SRC_PATH}/mnfgtools
prd_incpath += ${PRD_SRC_PATH}/occ_firdata
prd_incpath += ${PRD_SRC_PATH}/plat
prd_incpath += ${PRD_SRC_PATH}/plat/mem

# External header paths
prd_incpath += ${ROOTPATH}/src/include/usr/ecmddatabuffer
prd_incpath += ${ROOTPATH}/src/include/usr/errl
prd_incpath += ${ROOTPATH}/src/include/usr/fapi2
prd_incpath += ${ROOTPATH}/src/include/usr/ibscom
prd_incpath += ${ROOTPATH}/src/include/usr/util
prd_incpath += ${ROOTPATH}/src/include/usr/isteps/pm/
prd_incpath += ${ROOTPATH}/src/include/usr/isteps/tod/
prd_incpath += ${ROOTPATH}/src/include/usr/isteps/tod/runtime/
prd_incpath += ${ROOTPATH}/src/import/chips/centaur/common/include
prd_incpath += ${ROOTPATH}/src/import/chips/centaur/procedures/hwp/memory
prd_incpath += ${ROOTPATH}/src/import/chips/centaur/procedures/hwp/memory/lib/shared
prd_incpath += ${ROOTPATH}/src/import/chips/p9/common/include/
prd_incpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/ffdc/
prd_incpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/
prd_incpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib
prd_incpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/mcbist/
prd_incpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/utils/
prd_incpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/io/
prd_incpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/cache/
prd_incpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/perv/
prd_incpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/nest/
prd_incpath += ${ROOTPATH}/src/import/chips/p9/procedures/utils/stopreg/
prd_incpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/pm/
prd_incpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/lib/
prd_incpath += ${ROOTPATH}/src/import/generic/memory/lib/utils/
prd_incpath += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
prd_incpath += ${ROOTPATH}/src/import/chips/common/utils/
prd_incpath += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
prd_incpath += ${ROOTPATH}/src/import/hwpf/fapi2/include
prd_incpath += ${ROOTPATH}/src/import/
prd_incpath += ${ROOTPATH}/src/import/chips/centaur/procedures/hwp/io/
prd_incpath += ${ROOTPATH}/src/usr/isteps/nvdimm

# For including hwp_wrappers.H
prd_incpath += ${ROOTPATH}/src/import/generic/memory/lib/prd/
prd_incpath += ${ROOTPATH}/src/import/generic/memory/lib/ccs/
prd_incpath += ${ROOTPATH}/src/import/generic/memory/lib/spd/
prd_incpath += ${ROOTPATH}/src/import/generic/memory/lib/spd/rdimm/ddr4/
prd_incpath += ${ROOTPATH}/src/import/generic/memory/lib/spd/lrdimm/ddr4/
prd_incpath += ${ROOTPATH}/src/import/generic/memory/lib/dimm/ddr4/
prd_incpath += ${ROOTPATH}/src/import/generic/memory/lib/utils/
prd_incpath += ${ROOTPATH}/src/import/generic/memory/lib/utils/mcbist/
prd_incpath += ${ROOTPATH}/src/import/generic/memory/lib/utils/freq/
prd_incpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/common/include/
prd_incpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/
prd_incpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/
prd_incpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mc/
prd_incpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/phy/
prd_incpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/ecc/
prd_incpath += ${ROOTPATH}/obj/genfiles/chips/ocmb/explorer/procedures/hwp/memory/lib/
prd_incpath += ${ROOTPATH}/obj/genfiles/generic/memory/lib/
prd_incpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/phy/
prd_incpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/dimm/
prd_incpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/
prd_incpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/spd/
prd_incpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/ecc/
prd_incpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/mc/

################################################################################
# Hostboot only object files common to both IPL and runtime
################################################################################

# ./
prd_obj += prdfMain.o

# framework
prd_obj += prdfDumpResolution.o

# occ_firdata/
prd_obj += $(if $(CONFIG_ENABLE_CHECKSTOP_ANALYSIS), prdfWriteHomerFirData.o)

# plat/
prd_obj += prdfPlatServices.o
prd_obj += prdfRasServices.o

################################################################################
# Hostboot only object files (IPL only)
################################################################################

ifneq (${HOSTBOOT_RUNTIME},1)

# ./
prd_obj += prdfMain_ipl.o

# framework
prd_obj += $(if $(CONFIG_ENABLE_CHECKSTOP_ANALYSIS), prdfFileRegisterAccess.o)

# mnfgtools/
prd_obj += prdfMfgSync.o

# occ_firdata/
prd_obj += $(if $(CONFIG_ENABLE_CHECKSTOP_ANALYSIS), prdfPnorFirDataReader.o)
prd_obj += $(if $(CONFIG_ENABLE_CHECKSTOP_ANALYSIS), prdfReadPnorFirData.o)

# plat/
prd_obj += prdfPlatServices_ipl.o

endif

################################################################################
# Hostboot only object files (runtime only)
################################################################################

ifeq (${HOSTBOOT_RUNTIME},1)

# plat/
prd_obj += prdfPlatServices_rt.o

endif

################################################################################
# Conditional compile flag to enable profiling of flyweight register and
# resolution object
################################################################################

ifeq ($(PRD_PROFILER),1)
CUSTOMFLAGS += -DFLYWEIGHT_PROFILING
endif

################################################################################
# Rule for generated MNFG threshold header file
################################################################################

MFG_THRES       = prdfMfgThresholdAttrs
MFG_THRES_H     = ${MFG_THRES}.H
MFG_THRES_PL    = ${PRD_SRC_PATH}/common/mnfgtools/${MFG_THRES}.pl
MFG_THRES_ATTR_H  = ${ROOTPATH}/obj/genfiles/attributeenums.H
MFG_THRES_PATH  = ${ROOTPATH}/obj/genfiles/${MFG_THRES_H}

CODE_PASS_PRE += ${MFG_THRES_PATH}

${MFG_THRES_PATH} : ${MFG_THRES_ATTR_H}
	${MFG_THRES_PL} $^ > $@
EXTRA_CLEAN += ${MFG_THRES_PATH}
CLEAN_TARGETS += ${MFG_THRES_PATH}

################################################################################
# Hardware procedure files needed for both IPL and RT
################################################################################
prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/io/
prd_obj_no_sim += p9_io_erepairAccessorHwpFuncs.o
prd_obj_no_sim += p9_io_xbus_read_erepair.o
prd_obj_no_sim += p9_io_dmi_read_erepair.o
prd_obj_no_sim += p9_io_dmi_pdwn_lanes.o
prd_obj_no_sim += p9_io_dmi_clear_firs.o

prd_vpath += ${ROOTPATH}/src/import/chips/centaur/procedures/hwp/io/
prd_obj_no_sim += p9_io_cen_read_erepair.o
prd_obj_no_sim += p9_io_cen_pdwn_lanes.o

prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/perv/
prd_obj_no_sim += p9_proc_gettracearray.o
prd_obj_no_sim += p9_sbe_tracearray.o
prd_obj_no_sim += p9_io_xbus_clear_firs.o
prd_obj_no_sim += p9_io_xbus_pdwn_lanes.o

prd_vpath += ${ROOTPATH}/src/import/chips/centaur/procedures/hwp/memory
prd_obj_no_sim += p9c_mss_maint_cmds.o
prd_obj_no_sim += p9c_dimmBadDqBitmapFuncs.o
prd_obj_no_sim += p9c_query_channel_failure.o
prd_obj_no_sim += p9c_mss_rowRepairFuncs.o

prd_vpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/
prd_vpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mc/
prd_vpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/phy/
prd_vpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/eff_config/
prd_vpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mcbist/
prd_vpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/utils
prd_vpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/ccs/
prd_vpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/fir/
prd_vpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/ecc/
prd_vpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/dimm/
prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/utils/
prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/phy/
prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/spd/
prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/ccs/
prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/dimm/
prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/
prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/workarounds/
prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/fir/
prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/freq/
prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/ecc/
prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/mc/
prd_vpath += ${ROOTPATH}/src/import/generic/memory/lib/spd/
prd_vpath += ${ROOTPATH}/src/import/generic/memory/lib/spd/rdimm/ddr4/
prd_vpath += ${ROOTPATH}/src/import/generic/memory/lib/spd/lrdimm/ddr4/
prd_obj_no_sim += hwp_wrappers_nim.o
prd_obj_no_sim += hwp_wrappers_exp.o
prd_obj_no_sim += nimbus_pos.o
prd_obj_no_sim += explorer_pos.o
prd_obj_no_sim += exp_mcbist.o
prd_obj_no_sim += exp_memdiags.o
prd_obj_no_sim += explorer_memory_size.o
prd_obj_no_sim += exp_train_handler.o
prd_obj_no_sim += mss_training.o
prd_obj_no_sim += ddr_phy.o
prd_obj_no_sim += dp16.o
prd_obj_no_sim += ccs_explorer.o
prd_obj_no_sim += ccs_nimbus.o
prd_obj_no_sim += mrs_load_ddr4_nimbus.o
prd_obj_no_sim += dp16_workarounds.o
prd_obj_no_sim += phy_cntrl.o
prd_obj_no_sim += adr.o
prd_obj_no_sim += pda_nimbus.o
prd_obj_no_sim += latch_wr_vref.o
prd_obj_no_sim += ccs_workarounds.o
prd_obj_no_sim += eff_dimm.o
prd_obj_no_sim += eff_config_workarounds.o
prd_obj_no_sim += spd_utils.o
prd_obj_no_sim += seq_workarounds.o
prd_obj_no_sim += spd_factory.o
prd_obj_no_sim += exp_fir.o
prd_obj_no_sim += check.o
prd_obj_no_sim += seq.o
prd_obj_no_sim += dll_workarounds.o
prd_obj_no_sim += dqs_align_workarounds.o
prd_obj_no_sim += mss_lrdimm_training.o
prd_obj_no_sim += wr_vref_workarounds.o
prd_obj_no_sim += mrs03_nimbus.o
prd_obj_no_sim += mrs01_nimbus.o
prd_obj_no_sim += mrs02_nimbus.o
prd_obj_no_sim += mrs00_nimbus.o
prd_obj_no_sim += mrs06_nimbus.o
prd_obj_no_sim += mrs05_nimbus.o
prd_obj_no_sim += mrs04_nimbus.o
prd_obj_no_sim += nimbus_mss_freq.o
prd_obj_no_sim += freq_workarounds.o
prd_obj_no_sim += ecc_traits_explorer.o
prd_obj_no_sim += ecc_traits_nimbus.o
prd_obj_no_sim += adr32s.o
prd_obj_no_sim += adr32s_workarounds.o
prd_obj_no_sim += dcd.o
prd_obj_no_sim += rdimm_raw_cards.o
prd_obj_no_sim += lrdimm_raw_cards.o
prd_obj_no_sim += exp_unmask.o
prd_obj_no_sim += exp_port.o
prd_obj_no_sim += port.o
prd_obj_no_sim += exp_kind.o
prd_obj_no_sim += nimbus_kind.o

################################################################################
# The following are hardware procedure utilities that we are pulling into the
# PRD library (only needed here for HBRT). This code is already compiled in
# istep14 for Hostboot
################################################################################

ifeq (${HOSTBOOT_RUNTIME},1)
prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/cache/
prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/nest/
prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/pm/
# This is really the only file we need, but all of the other files below are
# required because of dependencies.
prd_obj_no_sim += memdiags.o
prd_obj_no_sim += p9_l2err_linedelete.o
prd_obj_no_sim += p9_l2err_extract.o
prd_obj_no_sim += p9_l3err_linedelete.o
prd_obj_no_sim += p9_l3err_extract.o
prd_obj_no_sim += p9_l2_flush.o
prd_obj_no_sim += p9_pm_callout.o

prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/dimm/
prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/eff_config/
prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/mcbist/
prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/utils/
prd_vpath += ${ROOTPATH}/src/import/generic/memory/lib/utils/
prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/workarounds/
prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/workarounds/


endif
