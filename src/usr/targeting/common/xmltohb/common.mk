# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/common/xmltohb/common.mk $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2011,2013
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
#
#  @file targeting/common/xmltohb/common.mk
#
#  @brief Common attribute compiler makefile to be included in
#      targeting/xmltohb/makefile
#
################################################################################

XMLTOHB_HEADER_TARGETS =        \
    attributeenums.H            \
    attributestrings.H          \
    attributetraits.H           \
    attributestructs.H          \
    pnortargeting.H             \
    fapiplatattrmacros.H        \
    test_ep.H                   \
    mapattrmetadata.H

XMLTOHB_SOURCE_TARGETS = \
    attributestrings.C   \
    attributedump.C      \
    errludattribute.C    \
    errludtarget.C       \
    mapattrmetadata.C

XMLTOHB_SYSTEM_BINARIES =       \
   vbu_VENICE_targeting.bin     \
   vbu_MURANO_targeting.bin     \
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
    proc_mvpd_attributes.xml \
    ei_bus_attributes.xml    \
    dram_initialization/proc_setup_bars/proc_setup_bars_memory_attributes.xml \
    dram_initialization/proc_setup_bars/proc_setup_bars_l3_attributes.xml \
    dram_initialization/proc_setup_bars/proc_setup_bars_mmio_attributes.xml \
    activate_powerbus/proc_build_smp/proc_fab_smp_fabric_attributes.xml \
    runtime_attributes/pm_hwp_attributes.xml \
    runtime_attributes/pm_plat_attributes.xml \
    nest_chiplets/proc_pcie_scominit/proc_pcie_scominit_attributes.xml \
    dmi_training/proc_cen_set_inband_addr/proc_cen_set_inband_addr_attributes.xml \
    common_attributes.xml \
    build_winkle_images/p8_slw_build/proc_pll_ring_attributes.xml \
    build_winkle_images/p8_slw_build/p8_xip_customize_attributes.xml \
    sync_attributes.xml   \
    poreve_memory_attributes.xml \
    mcbist_attributes.xml \
    proc_winkle_scan_override_attributes.xml \
    erepair_thresholds.xml \
    dram_training/mem_pll_setup/memb_pll_ring_attributes.xml

XMLTOHB_GENERIC_XML     = generic.xml
XMLTOHB_FAPI_XML        = fapiattrs.xml
XMLTOHB_MERGE_SCRIPT    = mergexml.sh
XMLTOHB_COMPILER_SCRIPT = xmltohb.pl
VMM_CONSTS_FILE         = vmmconst.h

GENERATED_CODE = ${XMLTOHB_TARGETS}
