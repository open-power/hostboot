# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/targeting/common/xmltohb/common.mk $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2011,2014
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

XMLTOHB_HEADER_TARGETS += attributeenums.H
XMLTOHB_HEADER_TARGETS += attributestrings.H
XMLTOHB_HEADER_TARGETS += attributetraits.H
XMLTOHB_HEADER_TARGETS += attributestructs.H
XMLTOHB_HEADER_TARGETS += pnortargeting.H
XMLTOHB_HEADER_TARGETS += fapiplatattrmacros.H
XMLTOHB_HEADER_TARGETS += test_ep.H
XMLTOHB_HEADER_TARGETS += mapattrmetadata.H
XMLTOHB_HEADER_TARGETS += mapsystemattrsize.H

XMLTOHB_SOURCE_TARGETS += attributestrings.C
XMLTOHB_SOURCE_TARGETS += attributedump.C
XMLTOHB_SOURCE_TARGETS += errludattribute.C
XMLTOHB_SOURCE_TARGETS += errludtarget.C
XMLTOHB_SOURCE_TARGETS += mapattrmetadata.C
XMLTOHB_SOURCE_TARGETS += mapsystemattrsize.C

XMLTOHB_SYSTEM_BINARIES += vbu_VENICE_targeting.bin
XMLTOHB_SYSTEM_BINARIES += vbu_MURANO_targeting.bin
XMLTOHB_SYSTEM_BINARIES += simics_VENICE_targeting.bin
XMLTOHB_SYSTEM_BINARIES += simics_MURANO_targeting.bin

XMLTOHB_TARGETS += ${XMLTOHB_HEADER_TARGETS}
XMLTOHB_TARGETS += ${XMLTOHB_SOURCE_TARGETS}

FAPI_ATTR_SOURCES += memory_attributes.xml
FAPI_ATTR_SOURCES += L2_L3_attributes.xml
FAPI_ATTR_SOURCES += scratch_attributes.xml
FAPI_ATTR_SOURCES += system_attributes.xml
FAPI_ATTR_SOURCES += chip_attributes.xml
FAPI_ATTR_SOURCES += dimm_spd_attributes.xml
FAPI_ATTR_SOURCES += dimm_attributes.xml
FAPI_ATTR_SOURCES += unit_attributes.xml
FAPI_ATTR_SOURCES += freq_attributes.xml
FAPI_ATTR_SOURCES += ei_bus_attributes.xml
FAPI_ATTR_SOURCES += dram_initialization/proc_setup_bars/proc_setup_bars_memory_attributes.xml
FAPI_ATTR_SOURCES += dram_initialization/proc_setup_bars/proc_setup_bars_l3_attributes.xml
FAPI_ATTR_SOURCES += dram_initialization/proc_setup_bars/proc_setup_bars_mmio_attributes.xml
FAPI_ATTR_SOURCES += activate_powerbus/proc_build_smp/proc_fab_smp_fabric_attributes.xml
FAPI_ATTR_SOURCES += runtime_attributes/pm_hwp_attributes.xml
FAPI_ATTR_SOURCES += runtime_attributes/pm_plat_attributes.xml
FAPI_ATTR_SOURCES += nest_chiplets/proc_pcie_scominit/proc_pcie_scominit_attributes.xml
FAPI_ATTR_SOURCES += dmi_training/proc_cen_set_inband_addr/proc_cen_set_inband_addr_attributes.xml
FAPI_ATTR_SOURCES += common_attributes.xml
FAPI_ATTR_SOURCES += build_winkle_images/p8_slw_build/proc_pll_ring_attributes.xml
FAPI_ATTR_SOURCES += build_winkle_images/p8_slw_build/p8_xip_customize_attributes.xml
FAPI_ATTR_SOURCES += sync_attributes.xml
FAPI_ATTR_SOURCES += poreve_memory_attributes.xml
FAPI_ATTR_SOURCES += mcbist_attributes.xml
FAPI_ATTR_SOURCES += proc_winkle_scan_override_attributes.xml
FAPI_ATTR_SOURCES += erepair_thresholds.xml
FAPI_ATTR_SOURCES += dram_training/mem_pll_setup/memb_pll_ring_attributes.xml
FAPI_ATTR_SOURCES += runtime_attributes/memory_occ_attributes.xml
FAPI_ATTR_SOURCES += proc_abus_dmi_xbus_scominit_attributes.xml

XMLTOHB_GENERIC_XML     += generic.xml
XMLTOHB_FAPI_XML        += fapiattrs.xml
XMLTOHB_MERGE_SCRIPT    += mergexml.sh
XMLTOHB_COMPILER_SCRIPT += xmltohb.pl
VMM_CONSTS_FILE         += vmmconst.h

GENERATED_CODE = ${XMLTOHB_TARGETS}
