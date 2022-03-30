# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/prdf_hb_only.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2022
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
prd_vpath += ${PRD_SRC_PATH}/plat

# Internal PRD header paths
prd_incpath += ${PRD_INC_PATH}        # Stored differently in FSP
prd_incpath += ${PRD_INC_PATH}/common # Stored differently in FSP
prd_incpath += ${PRD_SRC_PATH}
prd_incpath += ${PRD_SRC_PATH}/framework
prd_incpath += ${PRD_SRC_PATH}/mnfgtools
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
prd_incpath += ${ROOTPATH}/src/import/chips/p10/common/include/
prd_incpath += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/ffdc/
prd_incpath += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/memory/
prd_incpath += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/memory/lib/mcbist/
prd_incpath += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/memory/utils/
prd_incpath += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/io/
prd_incpath += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/corecache/
prd_incpath += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/perv/
prd_incpath += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/nest/
prd_incpath += ${ROOTPATH}/src/import/chips/p10/procedures/utils/stopreg/
prd_incpath += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/pm/
prd_incpath += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/lib/
prd_incpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/
prd_incpath += ${ROOTPATH}/src/import/generic/memory/lib/utils/shared/
prd_incpath += ${ROOTPATH}/src/import/generic/memory/lib/utils/
prd_incpath += ${ROOTPATH}/src/import/generic/memory/
prd_incpath += ${ROOTPATH}/src/import/chips/p10/utils/imageProcs/
prd_incpath += ${ROOTPATH}/src/import/chips/common/utils/
prd_incpath += ${ROOTPATH}/src/import/chips/common/utils/imageProcs/
prd_incpath += ${ROOTPATH}/src/import/chips/common/utils/scomt/
prd_incpath += ${ROOTPATH}/src/import/hwpf/fapi2/include
prd_incpath += ${ROOTPATH}/src/import/
prd_incpath += ${ROOTPATH}/src/import/generic/memory/lib/utils/mcbist/
prd_incpath += ${ROOTPATH}/src/usr/isteps/nvdimm

# For including hwp_wrappers.H
prd_incpath += ${ROOTPATH}/src/import/generic/memory/lib/prd/
prd_incpath += ${ROOTPATH}/src/import/generic/memory/lib/utils/mcbist/
prd_incpath += ${ROOTPATH}/src/import/generic/memory/lib/utils/dimm/
prd_incpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/common/include/
prd_incpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/
prd_incpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/phy/
prd_incpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/fir/
prd_incpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/ecc/
prd_incpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mc/
prd_incpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mcbist/
prd_incpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/dimm/
prd_incpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/shared/
prd_incpath += ${ROOTPATH}/obj/genfiles/chips/ocmb/explorer/procedures/hwp/memory/lib/
prd_incpath += ${ROOTPATH}/obj/genfiles/chips/ocmb/explorer/procedures/hwp/memory/lib/fir/
prd_incpath += ${ROOTPATH}/obj/genfiles/generic/memory/lib/

################################################################################
# Hostboot only object files common to both IPL and runtime
################################################################################

# ./
prd_obj += prdfMain.o

# framework
prd_obj += prdfDumpResolution.o

# plat/
prd_obj += prdfPlatServices.o
prd_obj += prdfRasServices.o

################################################################################
# Hostboot only object files (IPL only)
################################################################################

ifneq (${HOSTBOOT_RUNTIME},1)

# ./
prd_obj += prdfMain_ipl.o

# mnfgtools/
prd_obj += prdfMfgSync.o

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

prd_vpath += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/io/
prd_vpath += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/nest/
prd_vpath += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/perv/
prd_obj_no_sim += p10_io_lib.o
prd_obj_no_sim += p10_io_ppe_lib.o
prd_obj_no_sim += p10_io_ppe_regs.o
prd_obj_no_sim += p10_io_quiesce_lane.o
prd_obj_no_sim += p10_proc_gettracearray.o
prd_obj_no_sim += p10_sbe_tracearray.o

prd_obj_no_sim += p10_fbc_tdm_inject.o
prd_obj_no_sim += p10_fbc_tdm_utils.o
prd_obj_no_sim += p10_io_iohs_poll_recal.o
prd_obj_no_sim += p10_iohs_reset.o
prd_obj_no_sim += p10_smp_link_firs.o
prd_obj_no_sim += p10_omi_degrade_dl_reconfig.o

prd_vpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/
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
prd_vpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/dimm/ddr4/
prd_vpath += ${ROOTPATH}/src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/
prd_vpath += ${ROOTPATH}/src/import/generic/memory/lib/spd/
prd_vpath += ${ROOTPATH}/src/import/generic/memory/lib/spd/rdimm/ddr4/
prd_vpath += ${ROOTPATH}/src/import/generic/memory/lib/spd/lrdimm/ddr4/
prd_obj_no_sim += hwp_wrappers_exp.o
prd_obj_no_sim += explorer_pos.o
prd_obj_no_sim += exp_mcbist.o
prd_obj_no_sim += exp_memdiags.o
prd_obj_no_sim += explorer_memory_size.o
prd_obj_no_sim += exp_train_handler.o
prd_obj_no_sim += exp_unmask.o
prd_obj_no_sim += ecc_traits_explorer.o
prd_obj_no_sim += exp_port.o
prd_obj_no_sim += exp_kind.o
prd_obj_no_sim += exp_fir_workarounds.o
prd_obj_no_sim += exp_phy_utils.o
prd_obj_no_sim += exp_maint_cmds.o

# Needed for the exp_deploy_row_repairs procedure
prd_obj_no_sim += exp_deploy_row_repairs.o
prd_obj_no_sim += exp_row_repair.o
prd_obj_no_sim += ccs_explorer.o
prd_obj_no_sim += exp_mrs04.o
prd_obj_no_sim += exp_fir.o
prd_obj_no_sim += mrs_load_ddr4_explorer.o
prd_obj_no_sim += p10_rcs_transient_check.o
prd_obj_no_sim += p10_perv_sbe_cmn.o   # required by p10_rcs_transient_check
prd_obj_no_sim += p10_clock_test_cmn.o # required by p10_rcs_transient_check

################################################################################
# The following are hardware procedure utilities that we are pulling into the
# PRD library (only needed here for HBRT). This code is already compiled in
# istep14 for Hostboot
################################################################################

ifeq (${HOSTBOOT_RUNTIME},1)
prd_vpath += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/corecache/
prd_vpath += ${ROOTPATH}/src/import/chips/p10/procedures/hwp/pm/
prd_obj_no_sim += p10_l2err_linedelete.o
prd_obj_no_sim += p10_l2err_extract.o
prd_obj_no_sim += p10_l3err_linedelete.o
prd_obj_no_sim += p10_l3err_extract.o
prd_obj_no_sim += p10_l2_flush.o
prd_obj_no_sim += p10_pm_callout.o

#prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/dimm/
#prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/eff_config/
#prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/mcbist/
#prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/utils/
#prd_vpath += ${ROOTPATH}/src/import/generic/memory/lib/utils/
#prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/workarounds/
#prd_vpath += ${ROOTPATH}/src/import/chips/p9/procedures/hwp/memory/lib/workarounds/


endif
