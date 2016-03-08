# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/plat/pegasus/prdf_plat_p8.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016
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

prd_vpath += ${PRD_SRC_PATH}/common/plat/pegasus

prd_incpath += ${PRD_SRC_PATH}/common/plat/pegasus

################################################################################
# Object files common to both FSP and Hostboot
################################################################################

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
prd_obj += prdfFabricDomain.o
prd_obj += prdfFsiCapUtil.o
prd_obj += prdfLaneRepair.o
prd_obj += prdfLineDelete.o
prd_obj += prdfMemoryMru.o
prd_obj += prdfPciOscSwitchDomain.o
prd_obj += prdfPegasusConfigurator.o
prd_obj += prdfPllDomain.o
prd_obj += prdfPhbUtils.o
prd_obj += prdfPlatUtil.o

# common/plat/pegasus/ (rule plugin related)
prd_rule_plugin += prdfCenMba.o
prd_rule_plugin += prdfCenMembuf.o
prd_rule_plugin += prdfCenPll.o
prd_rule_plugin += prdfP8Ex.o
prd_rule_plugin += prdfP8Mcs.o
prd_rule_plugin += prdfP8Pll.o
prd_rule_plugin += prdfP8PllPcie.o
prd_rule_plugin += prdfP8Proc.o
prd_rule_plugin += prdfPllUtils.o

