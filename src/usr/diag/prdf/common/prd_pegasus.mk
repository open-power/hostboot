# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/prd_pegasus.mk $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2014
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

# Object files for prdf rule plugins for pegasus
PRDF_RULE_PLUGINS_PEGASUS += prdfP8Proc.o
PRDF_RULE_PLUGINS_PEGASUS += prdfPlatP8Ex.o
PRDF_RULE_PLUGINS_PEGASUS += prdfP8Ex.o
PRDF_RULE_PLUGINS_PEGASUS += prdfP8Mcs.o
PRDF_RULE_PLUGINS_PEGASUS += prdfP8Pll.o
PRDF_RULE_PLUGINS_PEGASUS += prdfCenMba.o
PRDF_RULE_PLUGINS_PEGASUS += prdfPlatCenMba.o
PRDF_RULE_PLUGINS_PEGASUS += prdfCenMembuf.o
PRDF_RULE_PLUGINS_PEGASUS += prdfP8TodPlugins.o
PRDF_RULE_PLUGINS_PEGASUS += prdfCenPll.o
PRDF_RULE_PLUGINS_PEGASUS += prdfPlatP8Proc.o
PRDF_RULE_PLUGINS_PEGASUS += prdfPlatCenMemUtils.o

# Object files for PRDF rule plugins, but include sim extensions.
PRDF_RULE_PLUGINS_PEGASUS_WSIM += prdfP8SystemSpecific.o

# PEGASUS specific objects, not rule related.
prd_pegasus_specific += prdfCalloutUtil.o
prd_pegasus_specific += prdfPhbUtils.o
prd_pegasus_specific += prdfCenAddress.o
prd_pegasus_specific += prdfCenDqBitmap.o
prd_pegasus_specific += prdfCenMbaCaptureData.o
prd_pegasus_specific += prdfCenMbaCeTable.o
prd_pegasus_specific += prdfCenMbaRceTable.o
prd_pegasus_specific += prdfCenMbaTdCtlr.o
prd_pegasus_specific += prdfCenMbaTdCtlr_common.o
prd_pegasus_specific += prdfCenMbaThresholds_common.o
prd_pegasus_specific += prdfCenMbaUeTable.o
prd_pegasus_specific += prdfCenMemUtils.o
prd_pegasus_specific += prdfCenSymbol.o
prd_pegasus_specific += prdfLaneRepair.o
prd_pegasus_specific += prdfLineDelete.o
prd_pegasus_specific += prdfMemoryMru.o
prd_pegasus_specific += prdfPegasusConfigurator.o
prd_pegasus_specific += prdfRegisterData.o
prd_pegasus_specific += prdfParserUtils.o
