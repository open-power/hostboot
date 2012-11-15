# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/prd_framework.mk $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2005,2012
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

# Object files for prd shared library

######## Framework ########

prd_framework = \
 iipTemplates.o \
 prdfTrace.o \
 prdfMain.o

prd_framework_includes = \
 prdfMain.H \
 prdf_service_codes.H

######## Util ########

prd_util = \
 prdfBitString.o \
 prdfBitKey.o \
 iipdgtb.o \
 iipdigit.o \
 prdfErrlSmartPtr.o \
 prdfFilters.o \
 prdfAssert.o

prd_util_includes = \
 prdfCompressBuffer.H

######## Config ########

prd_config = \
 iipchip.o \
 iipConfigurator.o \
 iipDomain.o \
 iipDomainContainer.o \
 prdfFabricDomain.o \
 prdfParentDomain.o \
 prdfRuleChipDomain.o \
 prdfPllDomain.o \
 iipSystem.o \
 prdfExtensibleDomain.o \

prd_config_FSP = \
 prdfChipPersist.o \
 prdfSystemData.o

prd_config_includes = \

######## Service ########

prd_service = \
 prdfServiceDataCollector.o \
 prdf_ras_services.o \
 prdfTargetServices.o \
 xspprdsdbug.o

prd_service_FSP = \
 prdfSdcFileControl.o

prd_service_includes = \

######## Platform Specfic Services ########

prd_env_service = \
 prdfHomRegisterAccess.o \
 prdfPlatServices.o

prd_env_service_includes = \

######## Chip ########

prd_ss = \
 prdfMemoryMru.o

prd_ss_includes = \
 prdfMemoryMru.H \
 prdfRepairHealth.H

######## Resolution ########

prd_resolution = \
 iipResolution.o \
 iipResolutionFactory.o \
 prdfResolutionMap.o \
 prdfThresholdResolutions.o \
 xspprdDumpResolution.o \
 xspprdFlagResolution.o \
 xspprdGardResolution.o \
 prdfClockResolution.o \
 prdfCaptureResolution.o

prd_resolution_includes = \

######## Register ########

prd_register = \
 iipscr.o \
 prdfErrorRegister.o \
 prdfErrorRegisterMask.o \
 iipMopRegisterAccess.o \
 prdfResetErrorRegister.o \
 iipScanCommRegisterAccess.o \
 iipScanCommRegisterChip.o \
 prdfCaptureData.o \
 prdfScanFacility.o

prd_register_includes = \

######## Threshold ########

prd_mnfgtools = \
 prdfMfgThresholdFile.o \
 prdfMfgThresholdMgr.o \
 prdfMesThresholds.o

prd_mnfgtools_includes = \
 prdfMfgThresholds.H \
 prdfMesThresholds.H
