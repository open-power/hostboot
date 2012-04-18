#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/targeting/makefile $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2011
#
#  p1
#
#  Object Code Only (OCO) source materials
#  Licensed Internal Code Source Materials
#  IBM HostBoot Licensed Internal Code
#
#  The source code for this program is not published or other-
#  wise divested of its trade secrets, irrespective of what has
#  been deposited with the U.S. Copyright Office.
#
#  Origin: 30
#
#  IBM_PROLOG_END

################################################################################
#
#  @file targeting/common/xmltohb/common.mk
#
#  @brief Common attribute compiler makefile to be included in 
#      targeting/xmltohb/makefile 
#
################################################################################

XMLTOHB_HEADER_TARGETS = \
    attributeenums.H     \
    attributestrings.H   \
    attributetraits.H    \
    attributestructs.H   \
    pnortargeting.H      \
    fapiplatattrmacros.H

XMLTOHB_SOURCE_TARGETS = \
    attributestrings.C   \
    attributedump.C     

XMLTOHB_SYSTEM_BINARIES =       \
   vbu_targeting.bin            \
   simics_VENICE_targeting.bin  \
   simics_MURANO_targeting.bin  

XMLTOHB_TARGETS =             \
    ${XMLTOHB_HEADER_TARGETS} \
    ${XMLTOHB_SOURCE_TARGETS} 

XMLTOHB_GENERIC_SOURCES = \
    attribute_types.xml   \
    target_types.xml

FAPI_ATTR_SOURCES =          \
    memory_attributes.xml    \
    L2_L3_attributes.xml     \
    scratch_attributes.xml   \
    system_attributes.xml    \
    chip_attributes.xml      \
    dimm_spd_attributes.xml  \
    dimm_attributes.xml      \
    unit_attributes.xml      \
    freq_attributes.xml      \
    proc_mvpd_attributes.xml
    
XMLTOHB_GENERIC_XML     = generic.xml
XMLTOHB_FAPI_XML        = fapiattrs.xml
XMLTOHB_MERGE_SCRIPT    = mergexml.sh
XMLTOHB_COMPILER_SCRIPT = xmltohb.pl
VMM_CONSTS_FILE         = vmmconst.h   

GENERATED_CODE = ${XMLTOHB_TARGETS} 
