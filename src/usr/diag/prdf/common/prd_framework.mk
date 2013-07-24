# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/prd_framework.mk $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2005,2013
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

################################################################################
# PRD object files (common Hostboot and FSP).
################################################################################

prd_framework = \
 iipTemplates.o \
 prdfTrace.o \
 prdfMain_common.o prdfMain.o

prd_util = \
 prdfBitString.o \
 prdfBitKey.o \
 iipdgtb.o \
 iipdigit.o \
 prdfErrlSmartPtr.o \
 prdfFilters.o \
 prdfAssert.o

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

prd_service = \
 prdfServiceDataCollector.o \
 prdfRasServices_common.o \
 prdfTargetServices.o \
 xspprdsdbug.o

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

prd_register = \
 iipscr.o \
 prdfErrorRegister.o \
 prdfErrorRegisterMask.o \
 prdfRegisterCache.o \
 prdfResetErrorRegister.o \
 prdfScomRegister.o \
 prdfScomRegisterAccess.o \
 prdfCaptureData.o \
 prdfScanFacility.o

prd_mnfgtools = \
 prdfMfgThresholdMgr.o

prd_object_files = \
 ${prd_framework} \
 ${prd_util} \
 ${prd_config} \
 ${prd_service} \
 ${prd_resolution} \
 ${prd_register} \
 ${prd_mnfgtools} \

################################################################################
# PRD object files common to Hostboot and FSP, but not to PRD simulator.
################################################################################

prd_object_files_no_sim = \
 prdfHomRegisterAccess.o \
 prdfPlatServices_common.o prdfPlatServices.o

