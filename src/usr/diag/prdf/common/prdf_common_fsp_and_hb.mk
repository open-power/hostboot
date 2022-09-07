# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/prdf_common_fsp_and_hb.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2014,2022
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

# NOTE: PRD_SRC_PATH must be defined before including this file.

################################################################################
# Paths common to both FSP and Hostboot
################################################################################

prd_vpath += ${PRD_SRC_PATH}/common
prd_vpath += ${PRD_SRC_PATH}/common/include
prd_vpath += ${PRD_SRC_PATH}/common/mnfgtools
prd_vpath += ${PRD_SRC_PATH}/common/plat
prd_vpath += ${PRD_SRC_PATH}/common/plugins
prd_vpath += ${PRD_SRC_PATH}/common/rule
prd_vpath += ${PRD_SRC_PATH}/common/util

prd_incpath += ${PRD_SRC_PATH}/common
prd_incpath += ${PRD_SRC_PATH}/common/mnfgtools
prd_incpath += ${PRD_SRC_PATH}/common/plat
prd_incpath += ${PRD_SRC_PATH}/common/plugins
prd_incpath += ${PRD_SRC_PATH}/common/rule
prd_incpath += ${PRD_SRC_PATH}/common/util

################################################################################
# Object files common to both FSP and Hostboot
################################################################################

# common/
prd_obj += prdfMain_common.o
prd_obj += prdfTrace.o

# common/mnfgtools/
prd_obj += prdfMfgThreshold.o
prd_obj += prdfMfgThresholdMgr.o

# common/plat/
prd_obj_no_sim += prdfPlatServices_common.o
prd_obj += prdfRasServices_common.o
prd_obj += prdfTargetServices.o

# common/plugins/ (errl plugin related)
prd_obj += prdfParserUtils.o

# common/rule/
prd_obj += iipTemplates.o
prd_obj += prdfGroup.o
prd_obj += prdfPluginMap.o
prd_obj += prdfRuleChip.o
prd_obj += prdfRuleFiles.o
prd_obj += prdfRuleMetaData.o
prd_obj += prdrLoadChip.o
prd_obj += prdrLoadChipCache.o

# common/util/
prd_obj += iipdgtb.o
prd_obj += iipdigit.o
prd_obj += prdfAssert.o
prd_obj += prdfBitKey.o
prd_obj += prdfBitString.o
prd_obj += prdfErrlSmartPtr.o
prd_obj += prdfErrorSignature.o
prd_obj += prdfFilters.o
prd_obj += prdfRegisterData.o
prd_obj += prdfThresholdUtils.o

