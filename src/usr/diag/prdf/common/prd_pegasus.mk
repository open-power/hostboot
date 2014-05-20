# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/prd_pegasus.mk $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2012,2014
#
# p1
#
# Object Code Only (OCO) source materials
# Licensed Internal Code Source Materials
# IBM HostBoot Licensed Internal Code
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# Origin: 30
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
