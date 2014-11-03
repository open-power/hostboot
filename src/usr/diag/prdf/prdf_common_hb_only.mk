# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/prdf_common_hb_only.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2014
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

# NOTE: ROOTPATH must be defined before including this file and PRD_SRC_PATH
#       must be defined in this file.

PRD_SRC_PATH = ${ROOTPATH}/src/usr/diag/prdf
PRD_INC_PATH = ${ROOTPATH}/src/include/usr/diag/prdf

################################################################################
# Paths common to both IPL and runtime
################################################################################

prd_vpath += ${PRD_SRC_PATH}
prd_vpath += ${PRD_SRC_PATH}/framework/config
prd_vpath += ${PRD_SRC_PATH}/framework/resolution
prd_vpath += ${PRD_SRC_PATH}/framework/service
prd_vpath += ${PRD_SRC_PATH}/mnfgtools
prd_vpath += ${PRD_SRC_PATH}/plat
prd_vpath += ${PRD_SRC_PATH}/plat/pegasus

################################################################################
# Hostboot only object files common to both IPL and runtime
################################################################################

# ./
prd_obj += prdfMain.o

# framework/config/
prd_obj += prdfMbaDomain.o

# framework/resolution/
prd_obj += prdfDumpResolution.o

# framework/service/
prd_obj_no_sim += prdfPlatServices.o
prd_obj += prdfRasServices.o

# mnfgtools/
prd_obj += prdfMfgSync.o
prd_obj += prdfMfgThresholdFile.o

# plat/pegasus/ (non-rule plugin related)
prd_obj += prdfCenMbaIplCeStats.o
prd_obj += prdfCenMbaTdCtlr.o
prd_obj += prdfDramRepairs.o
prd_obj += prdfPlatCalloutUtil.o
prd_obj += prdfPllUtils.o

# plat/pegasus/ (rule plugin related)
prd_rule_plugin += prdfP8TodPlugins.o
prd_rule_plugin += prdfPlatCenMba.o
prd_rule_plugin += prdfPlatCenMemUtils.o
prd_rule_plugin += prdfPlatCenPll.o
prd_rule_plugin += prdfPlatP8Ex.o
prd_rule_plugin += prdfPlatP8Proc.o

