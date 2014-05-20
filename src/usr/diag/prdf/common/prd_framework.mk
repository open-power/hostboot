# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/diag/prdf/common/prd_framework.mk $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2005,2014
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

prd_framework += iipTemplates.o
prd_framework += prdfTrace.o
prd_framework += prdfMain_common.o
prd_framework += prdfMain.o

prd_util += prdfBitString.o
prd_util += prdfBitKey.o
prd_util += iipdgtb.o
prd_util += iipdigit.o
prd_util += prdfErrlSmartPtr.o
prd_util += prdfFilters.o
prd_util += prdfAssert.o

prd_config += iipchip.o
prd_config += iipConfigurator.o
prd_config += iipDomain.o
prd_config += iipDomainContainer.o
prd_config += prdfFabricDomain.o
prd_config += prdfParentDomain.o
prd_config += prdfRuleChipDomain.o
prd_config += prdfPllDomain.o
prd_config += iipSystem.o
prd_config += prdfExtensibleDomain.o

prd_service += prdfServiceDataCollector.o
prd_service += prdfRasServices_common.o
prd_service += prdfTargetServices.o
prd_service += xspprdsdbug.o

prd_resolution += iipResolution.o
prd_resolution += iipResolutionFactory.o
prd_resolution += prdfResolutionMap.o
prd_resolution += prdfThresholdResolutions.o
prd_resolution += xspprdFlagResolution.o
prd_resolution += xspprdGardResolution.o
prd_resolution += prdfClockResolution.o
prd_resolution += prdfCaptureResolution.o
prd_resolution += prdfDumpResolution.o

prd_register += iipscr.o
prd_register += prdfErrorRegister.o
prd_register += prdfErrorRegisterMask.o
prd_register += prdfRegisterCache.o
prd_register += prdfResetErrorRegister.o
prd_register += prdfScomRegister.o
prd_register += prdfScomRegisterAccess.o
prd_register += prdfCaptureData.o
prd_register += prdfScanFacility.o

prd_mnfgtools +=  prdfMfgThresholdFile_common.o
prd_mnfgtools += prdfMfgThresholdMgr.o

prd_object_files += ${prd_framework}
prd_object_files += ${prd_util}
prd_object_files += ${prd_config}
prd_object_files += ${prd_service}
prd_object_files += ${prd_resolution}
prd_object_files += ${prd_register}
prd_object_files += ${prd_mnfgtools}

################################################################################
# PRD object files common to Hostboot and FSP, but not to PRD simulator.
################################################################################

prd_object_files_no_sim += prdfHomRegisterAccess.o
prd_object_files_no_sim += prdfPlatServices_common.o
prd_object_files_no_sim += prdfPlatServices.o

