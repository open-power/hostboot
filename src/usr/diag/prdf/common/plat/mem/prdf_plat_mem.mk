# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/plat/mem/prdf_plat_mem.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2021
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

prd_vpath += ${PRD_SRC_PATH}/common/plat/mem

prd_incpath += ${PRD_SRC_PATH}/common/plat/mem

################################################################################
# Object files common to both FSP and Hostboot
################################################################################

# non-rule plugin related
prd_obj += prdfMemAddress.o
prd_obj += prdfMemCaptureData.o
prd_obj += prdfMemCeTable.o
prd_obj += prdfMemDqBitmap.o
prd_obj += prdfMemEccAnalysis.o
prd_obj += prdfMemMark.o
prd_obj += prdfMemRowRepair.o
prd_obj += prdfMemSymbol.o
prd_obj += prdfMemoryMru.o
prd_obj += prdfMemUeTable.o
prd_obj += prdfMemUtils.o
prd_obj += prdfMemThresholds.o
prd_obj += prdfOcmbChipDomain.o
prd_obj += prdfOcmbAddrConfig.o

