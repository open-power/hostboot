# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/prdf_hb_only.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2013,2015
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
prd_vpath += ${PRD_SRC_PATH}/framework/config
prd_vpath += ${PRD_SRC_PATH}/framework/resolution
prd_vpath += ${PRD_SRC_PATH}/framework/service
prd_vpath += ${PRD_SRC_PATH}/framework/register
prd_vpath += ${PRD_SRC_PATH}/mnfgtools
prd_vpath += ${PRD_SRC_PATH}/occ_firdata
prd_vpath += ${PRD_SRC_PATH}/plat
prd_vpath += ${PRD_SRC_PATH}/plat/pegasus

# Internal PRD header paths
prd_incpath += ${PRD_INC_PATH}        # Stored differently in FSP
prd_incpath += ${PRD_INC_PATH}/common # Stored differently in FSP
prd_incpath += ${PRD_SRC_PATH}
prd_incpath += ${PRD_SRC_PATH}/framework/config
prd_incpath += ${PRD_SRC_PATH}/framework/resolution
prd_incpath += ${PRD_SRC_PATH}/framework/register
prd_incpath += ${PRD_SRC_PATH}/framework/service
prd_incpath += ${PRD_SRC_PATH}/mnfgtools
prd_incpath += ${PRD_SRC_PATH}/occ_firdata
prd_incpath += ${PRD_SRC_PATH}/plat/pegasus

# External header paths
prd_incpath += ${ROOTPATH}/src/include/usr/ecmddatabuffer
prd_incpath += ${ROOTPATH}/src/include/usr/errl
prd_incpath += ${ROOTPATH}/src/include/usr/hwpf/fapi
prd_incpath += ${ROOTPATH}/src/include/usr/hwpf/hwp
prd_incpath += ${ROOTPATH}/src/include/usr/hwpf/plat
prd_incpath += ${ROOTPATH}/src/include/usr/ibscom
prd_incpath += ${ROOTPATH}/src/include/usr/util
prd_incpath += ${ROOTPATH}/src/usr/hwpf/hwp/bus_training
prd_incpath += ${ROOTPATH}/src/usr/hwpf/hwp/include
prd_incpath += ${ROOTPATH}/src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete

################################################################################
# Hostboot only object files common to both IPL and runtime
################################################################################

# ./
prd_obj += prdfMain.o

# framework/resolution/
prd_obj += prdfDumpResolution.o

# framework/service/
prd_obj += prdfPlatServices.o
prd_obj += prdfRasServices.o

# framework/register
prd_obj += $(if $(CONFIG_ENABLE_CHECKSTOP_ANALYSIS), prdfFileRegisterAccess.o)

# plat/pegasus/ (non-rule plugin related)
prd_obj += prdfPllUtils.o

# plat/pegasus/ (rule plugin related)
prd_rule_plugin += prdfP8TodPlugins.o
prd_rule_plugin += prdfPlatCenMemUtils.o
prd_rule_plugin += prdfPlatCenPll.o
prd_rule_plugin += prdfPlatP8Ex.o
prd_rule_plugin += prdfPlatP8Proc.o

################################################################################
# Hostboot only object files (IPL only)
################################################################################

ifneq (${HOSTBOOT_RUNTIME},1)

# ./
prd_obj += prdfMain_ipl.o

# framework/config/
prd_obj += prdfMbaDomain.o

# framework/service/
prd_obj += prdfPlatServices_ipl.o

# mnfgtools/
prd_obj += prdfMfgSync.o

# occ_firdata/
prd_obj += $(if $(CONFIG_ENABLE_CHECKSTOP_ANALYSIS), prdfPnorFirDataReader.o)
prd_obj += $(if $(CONFIG_ENABLE_CHECKSTOP_ANALYSIS), prdfReadPnorFirData.o)

# plat/pegasus/ (non-rule plugin related)
prd_obj += prdfCenMbaIplCeStats.o
prd_obj += prdfCenMbaTdCtlr_ipl.o
prd_obj += prdfDramRepairs.o
prd_obj += prdfPlatCalloutUtil.o

# plat/pegasus/ (rule plugin related)
prd_rule_plugin += prdfPlatCenMba_ipl.o

endif

################################################################################
# Hostboot only object files (runtime only)
################################################################################

ifeq (${HOSTBOOT_RUNTIME},1)

# runtime/
prd_obj += prdfPlatServices_rt.o

# common/runtime/
prd_obj += prdfCenMbaDynMemDealloc_rt.o
prd_obj += prdfCenMbaTdCtlr_rt.o
prd_obj += prdfCenMbaTdRankData.o

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
