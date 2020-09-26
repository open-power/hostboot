# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/framework/prdf_framework.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2020
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

prd_vpath += ${PRD_SRC_PATH}/common/framework/config
prd_vpath += ${PRD_SRC_PATH}/common/framework/register
prd_vpath += ${PRD_SRC_PATH}/common/framework/resolution
prd_vpath += ${PRD_SRC_PATH}/common/framework/service

prd_incpath += ${PRD_SRC_PATH}/common/framework/config
prd_incpath += ${PRD_SRC_PATH}/common/framework/register
prd_incpath += ${PRD_SRC_PATH}/common/framework/resolution
prd_incpath += ${PRD_SRC_PATH}/common/framework/service

################################################################################
# Object files common to both FSP and Hostboot
################################################################################

# common/framework/config/
prd_obj += iipchip.o
prd_obj += iipConfigurator.o
prd_obj += iipDomain.o
prd_obj += iipDomainContainer.o
prd_obj += iipSystem.o
prd_obj += prdfExtensibleDomain.o
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
prd_obj += prdfResolutionMap.o
prd_obj += prdfThresholdResolutions.o
prd_obj += xspprdFlagResolution.o

# common/framework/service/
prd_obj += prdfServiceDataCollector.o
prd_obj += xspprdsdbug.o

