# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/prdf_common_fsp_and_hb.mk $
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

# NOTE: PRD_SRC_PATH must be defined before including this file.

################################################################################
# Paths common to both FSP and Hostboot
################################################################################

prd_vpath += ${PRD_SRC_PATH}/common
prd_vpath += ${PRD_SRC_PATH}/common/include
prd_vpath += ${PRD_SRC_PATH}/common/framework/config
prd_vpath += ${PRD_SRC_PATH}/common/framework/register
prd_vpath += ${PRD_SRC_PATH}/common/framework/resolution
prd_vpath += ${PRD_SRC_PATH}/common/framework/rule
prd_vpath += ${PRD_SRC_PATH}/common/framework/service
prd_vpath += ${PRD_SRC_PATH}/common/mnfgtools
prd_vpath += ${PRD_SRC_PATH}/common/plat
prd_vpath += ${PRD_SRC_PATH}/common/plat/pegasus
prd_vpath += ${PRD_SRC_PATH}/common/plugins
prd_vpath += ${PRD_SRC_PATH}/common/runtime
prd_vpath += ${PRD_SRC_PATH}/common/util

prd_incpath += ${PRD_SRC_PATH}/common
prd_incpath += ${PRD_SRC_PATH}/common/framework/config
prd_incpath += ${PRD_SRC_PATH}/common/framework/register
prd_incpath += ${PRD_SRC_PATH}/common/framework/resolution
prd_incpath += ${PRD_SRC_PATH}/common/framework/rule
prd_incpath += ${PRD_SRC_PATH}/common/framework/service
prd_incpath += ${PRD_SRC_PATH}/common/mnfgtools
prd_incpath += ${PRD_SRC_PATH}/common/plat
prd_incpath += ${PRD_SRC_PATH}/common/plat/pegasus
prd_incpath += ${PRD_SRC_PATH}/common/plugins
prd_incpath += ${PRD_SRC_PATH}/common/runtime
prd_incpath += ${PRD_SRC_PATH}/common/util

################################################################################
# Object files common to both FSP and Hostboot
################################################################################

# common/
prd_obj += prdfMain_common.o
prd_obj += prdfTrace.o

# common/framework/config/
prd_obj += iipchip.o
prd_obj += iipConfigurator.o
prd_obj += iipDomain.o
prd_obj += iipDomainContainer.o
prd_obj += iipSystem.o
prd_obj += prdfExtensibleDomain.o
prd_obj += prdfFabricDomain.o
prd_obj += prdfParentDomain.o
prd_obj += prdfPllDomain.o
prd_obj += prdfRuleChipDomain.o

# common/framework/register/
prd_obj += iipscr.o
prd_obj += prdfCaptureData.o
prd_obj += prdfErrorRegister.o
prd_obj += prdfErrorRegisterMask.o
prd_obj_no_sim += prdfHomRegisterAccess.o
prd_obj += prdfRegisterCache.o
prd_obj += prdfResetErrorRegister.o
prd_obj += prdfScanFacility.o
prd_obj += prdfScomRegisterAccess.o
prd_obj += prdfScomRegister.o

# common/framework/resolution/
prd_obj += iipResolution.o
prd_obj += iipResolutionFactory.o
prd_obj += prdfCaptureResolution.o
prd_obj += prdfClockResolution.o
prd_obj += prdfResolutionMap.o
prd_obj += prdfThresholdResolutions.o
prd_obj += xspprdFlagResolution.o

# common/framework/rule/
prd_obj += iipTemplates.o
prd_obj += prdfGroup.o
prd_obj += prdfPluginMap.o
prd_obj += prdfRuleChip.o
prd_obj += prdfRuleFiles.o
prd_obj += prdfRuleMetaData.o
prd_obj += prdrLoadChip.o
prd_obj += prdrLoadChipCache.o

# common/framework/service/
prd_obj_no_sim += prdfPlatServices_common.o
prd_obj += prdfRasServices_common.o
prd_obj += prdfServiceDataCollector.o
prd_obj += prdfTargetServices.o
prd_obj += xspprdsdbug.o

# common/mnfgtools/
prd_obj += prdfMfgThresholdFile_common.o
prd_obj += prdfMfgThresholdMgr.o

# common/plat/
prd_obj += prdfLineDelete.o

# common/plat/pegasus/ (non-rule plugin related)
prd_obj += prdfCalloutUtil.o
prd_obj += prdfCenAddress.o
prd_obj += prdfCenDqBitmap.o
prd_obj += prdfCenMbaCaptureData.o
prd_obj += prdfCenMbaCeTable.o
prd_obj += prdfCenMbaRceTable.o
prd_obj += prdfCenMbaTdCtlr_common.o
prd_obj += prdfCenMbaThresholds_common.o
prd_obj += prdfCenMbaUeTable.o
prd_obj += prdfCenMemUtils.o
prd_obj += prdfCenSymbol.o
prd_obj += prdfFsiCapUtil.o
prd_obj += prdfLaneRepair.o
prd_obj += prdfMemoryMru.o
prd_obj += prdfPegasusConfigurator.o
prd_obj += prdfPhbUtils.o

# common/plat/pegasus/ (rule plugin related)
prd_rule_plugin += prdfCenMba.o
prd_rule_plugin += prdfCenMembuf.o
prd_rule_plugin += prdfCenPll.o
prd_rule_plugin += prdfP8Ex.o
prd_rule_plugin += prdfP8Mcs.o
prd_rule_plugin += prdfP8Pll.o
prd_rule_plugin += prdfP8PllPcie.o
prd_rule_plugin += prdfP8Proc.o

# common/plugins/ (errl plugin related)
prd_obj += prdfParserUtils.o

# common/util/
prd_obj += iipdgtb.o
prd_obj += iipdigit.o
prd_obj += prdfAssert.o
prd_obj += prdfBitKey.o
prd_obj += prdfBitString.o
prd_obj += prdfErrlSmartPtr.o
prd_obj += prdfFilters.o
prd_obj += prdfRegisterData.o
prd_obj += prdfThresholdUtils.o

