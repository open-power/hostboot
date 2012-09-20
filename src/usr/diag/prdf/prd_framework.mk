# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
# 
# $Source: src/usr/diag/prdf/prd_framework.mk $
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

prd_framework = \
 iipTemplates.o \
 prdfTrace.o \
 prdfMain.o

######## Util ########

prd_util = \
 prdfBitString.o \
 prdfBitKey.o \
 iipdgtb.o \
 iipdigit.o \
 prdfErrlSmartPtr.o \
 prdfFilters.o \
 prdfAssert.o

######## Config ########

prd_config = \
 iipchip.o \
 iipConfigurator.o \
 iipDomain.o \
 iipDomainContainer.o \
 prdfFabricDomain.o \
 prdfRuleChipDomain.o \
 iipSystem.o \
 prdfExtensibleDomain.o \

# prdfParentDomain.o \
# prdfPllDomain.o \

######## Service ########
# FIXME: partially finished....need to add more
prd_service = \
 prdfServiceDataCollector.o \
 prdf_ras_services.o \
 prdfTargetServices.o \
 xspprdsdbug.o

######## Platform Specfic Services ########

prd_env_service = \
 prdfHomRegisterAccess.o \
 prdfPlatServices.o

######## Chip ########
# FIXME: need to add prd_s to prdf/makefile
prd_ss = \
 prdfMemoryMru.o

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

# iipScanCommRegisterCluster.o \ not used


#FIXME: do we need to add this prd_mnfgtools to prdf/makefile?
######## Threshold ########
#prd_mnfgtools = \
# prdfMfgThresholdFile.o \
# prdfMfgThresholdMgr.o \
# prdfMesThresholds.o

#prd_mnfgtools_includes = \
# prdfMfgThresholds.H \
# prdfMesThresholds.H

