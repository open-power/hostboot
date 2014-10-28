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
prd_obj += xspprdGardResolution.o

# common/framework/rule/
prd_obj += iipTemplates.o

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
# common/plat/pegasus/ (non-rule plugin related)
# common/plat/pegasus/ (rule plugin related)
# common/plugins/ (errl plugin related)

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

