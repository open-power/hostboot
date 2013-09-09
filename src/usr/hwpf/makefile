# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/makefile $
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
ROOTPATH = ../../..
SUBDIRS = fapi.d hwp.d plat.d test.d

#------------------------------------------------------------------------------
# This makefile controls the generation of HWPF files
#------------------------------------------------------------------------------

#------------------------------------------------------------------------------
# Source XML files
#------------------------------------------------------------------------------
HWP_ERROR_XML_FILES = hwp/fapiHwpErrorInfo.xml   \
    hwp/dmi_training/proc_cen_framelock/proc_cen_framelock_errors.xml \
    hwp/bus_training/io_errors.xml \
    hwp/dimm_errors.xml	\
    hwp/dram_training/memory_errors.xml \
    hwp/nest_chiplets/proc_start_clocks_chiplets/proc_start_clocks_chiplets_errors.xml \
    hwp/edi_ei_initialization/proc_fab_iovalid/proc_fab_smp_errors.xml  \
    hwp/mvpd_accessors/mvpd_errors.xml \
    ../pore/fapiporeve/fapiPoreVe_errors.xml \
    hwp/dram_initialization/proc_setup_bars/proc_setup_bars_errors.xml  \
    hwp/nest_chiplets/proc_chiplet_scominit/proc_chiplet_scominit_errors.xml \
    hwp/build_winkle_images/p8_slw_build/p8_slw_build_errors.xml    \
    hwp/build_winkle_images/p8_slw_build/p8_xip_customize_errors.xml    \
    hwp/build_winkle_images/p8_slw_build/p8_pba_bar_config_errors.xml \
    hwp/nest_chiplets/proc_a_x_pci_dmi_pll_setup_errors.xml \
    hwp/core_activate/proc_prep_master_winkle/proc_prep_master_winkle_errors.xml \
    hwp/core_activate/proc_stop_deadman_timer/proc_stop_deadman_timer_errors.xml \
    hwp/activate_powerbus/proc_build_smp/proc_build_smp_errors.xml \
    hwp/activate_powerbus/proc_build_smp/proc_adu_utils_errors.xml \
    hwp/thread_activate/proc_thread_control/proc_thread_control.xml \
    hwp/bus_training/erepair_errors.xml \
    hwp/nest_chiplets/proc_pcie_scominit/proc_pcie_scominit_errors.xml \
    hwp/dram_initialization/proc_pcie_config/proc_pcie_config_errors.xml \
    hwp/build_winkle_images/p8_set_pore_bar/p8_set_pore_bar_errors.xml  \
    hwp/build_winkle_images/p8_set_pore_bar/p8_pmc_deconfig_setup_errors.xml \
    hwp/build_winkle_images/p8_set_pore_bar/p8_pfet_errors.xml \
    hwp/build_winkle_images/p8_set_pore_bar/p8_poreslw_errors.xml   \
    hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_check_slave_sbe_seeprom_complete_errors.xml \
    hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_extract_sbe_rc_errors.xml \
    hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_read_seeprom_errors.xml    \
    hwp/proc_sbe_registers.xml \
    hwp/runtime_errors/p8_ocb_init_errors.xml \
    hwp/runtime_errors/p8_occ_control_errors.xml \
    hwp/runtime_errors/p8_occ_sram_init_errors.xml \
    hwp/runtime_errors/p8_oha_init_errors.xml \
    hwp/runtime_errors/p8_pcbs_init_errors.xml \
    hwp/runtime_errors/p8_pm_prep_for_reset_errors.xml \
    hwp/runtime_errors/p8_force_vsafe_errors.xml \
    hwp/runtime_errors/p8_pmc_errors.xml \
    hwp/runtime_errors/p8_pss_errors.xml \
    hwp/runtime_errors/proc_cpu_special_wakeup_errors.xml \
    hwp/runtime_errors/p8_poregpe_errors.xml \
    hwp/runtime_errors/p8_pba_init_errors.xml \
    hwp/dram_initialization/host_mpipl_service/proc_mpipl_chip_cleanup_errors.xml \
    hwp/build_winkle_images/p8_set_pore_bar/p8_pfet_init_errors.xml \
    hwp/poreve_errors.xml \
    hwp/proc_fab_iovalid_errors.xml \
    hwp/nest_chiplets/proc_chiplet_scominit/proc_abus_scominit_errors.xml \
    hwp/nest_chiplets/proc_chiplet_scominit/proc_xbus_scominit_errors.xml \
    hwp/dmi_training/proc_dmi_scominit_errors.xml \
    hwp/dmi_training/cen_dmi_scominit_errors.xml \
    hwp/sbe_centaur_init/cen_xip_customize_errors.xml \
    hwp/tod_init/proc_tod_utils/proc_tod_utils.xml \
    hwp/mc_config/mss_eff_config/opt_memmap_errors.xml \
    hwp/pstates/pstates/p8_build_pstate_datablock_errors.xml \
    hwp/pstates/pstates/proc_get_voltage_errors.xml \
    hwp/proc_cfam_registers.xml \
    hwp/proc_slw_registers.xml \
    hwp/proc_sbe_select_ex_errors.xml \
    hwp/utility_procedures/memory_mss_maint_cmds.xml \
    hwp/mc_config/mss_volt/memory_mss_volt.xml \
    hwp/mc_config/mss_freq/memory_mss_freq.xml \
    hwp/mc_config/mss_eff_config/memory_mss_eff_grouping.xml \
    hwp/mc_config/mss_eff_config/memory_mss_eff_config_thermal.xml \
    hwp/mc_config/mss_eff_config/memory_mss_bulk_pwr_throttles.xml \
    hwp/dram_training/memory_mss_funcs.xml \
    hwp/dram_training/mss_draminit_training/memory_mss_draminit_training.xml  \
    hwp/dram_training/mss_ddr_phy_reset/memory_mss_ddr_phy_reset.xml \
    hwp/dram_training/memory_mss_termination_control.xml \
    hwp/dram_training/mem_startclocks/memory_cen_stopclocks.xml \
    hwp/dram_training/mss_scominit/memory_mss_scominit.xml \
    hwp/dram_training/mss_draminit_trainadv/memory_mss_mcbist_common.xml \
    hwp/dram_initialization/proc_setup_bars/memory_mss_setup_bars.xml \
    hwp/slave_sbe/proc_cen_ref_clk_enable/proc_cen_ref_clk_enable_errors.xml \
    hwp/dmi_training/mss_getecid/memory_mss_get_cen_ecid.xml \
    hwp/dram_initialization/mss_extent_setup/memory_mss_extent_setup.xml \
    hwp/dram_initialization/mss_thermal_init/memory_mss_thermal_init.xml \
    hwp/dram_training/mss_draminit/memory_mss_draminit.xml \
    hwp/dram_training/mss_draminit_mc/memory_mss_draminit_mc.xml \
    hwp/dram_training/mss_draminit_trainadv/memory_mss_access_delay_reg.xml \
    hwp/dram_training/mss_draminit_trainadv/memory_mss_draminit_training_advanced.xml \
    hwp/dram_training/mss_draminit_trainadv/memory_mss_generic_shmoo.xml \
    hwp/dram_training/mss_draminit_trainadv/memory_mss_mcbist.xml \
    hwp/mc_config/mss_eff_config/memory_mss_eff_config.xml \
    hwp/mc_config/mss_eff_config/memory_mss_eff_config_cke_map.xml \
    hwp/mc_config/mss_eff_config/memory_mss_eff_config_rank_group.xml \
    hwp/mc_config/mss_eff_config/memory_mss_eff_config_termination.xml \
    hwp/build_winkle_images/p8_block_wakeup_intr/p8_block_wakeup_intr_errors.xml

## these get generated into obj/genfiles/AttributeIds.H
HWP_ATTR_XML_FILES = hwp/memory_attributes.xml \
                     hwp/L2_L3_attributes.xml \
                     hwp/scratch_attributes.xml \
                     hwp/system_attributes.xml \
                     hwp/chip_attributes.xml \
                     hwp/dimm_spd_attributes.xml \
                     hwp/dimm_attributes.xml \
                     hwp/unit_attributes.xml \
                     hwp/freq_attributes.xml \
                     hwp/proc_mvpd_attributes.xml \
                     hwp/ei_bus_attributes.xml \
                     hwp/chip_ec_attributes.xml \
                     hwp/centaur_ec_attributes.xml \
                     hwp/common_attributes.xml \
                     hwp/sync_attributes.xml   \
                     hwp/dram_initialization/proc_setup_bars/proc_setup_bars_memory_attributes.xml \
                     hwp/dram_initialization/proc_setup_bars/proc_setup_bars_l3_attributes.xml \
                     hwp/dram_initialization/proc_setup_bars/proc_setup_bars_mmio_attributes.xml \
                     hwp/activate_powerbus/proc_build_smp/proc_fab_smp_fabric_attributes.xml    \
                     hwp/runtime_attributes/pm_plat_attributes.xml \
                     hwp/runtime_attributes/pm_hwp_attributes.xml \
                     hwp/nest_chiplets/proc_pcie_scominit/proc_pcie_scominit_attributes.xml \
                     hwp/dmi_training/proc_cen_set_inband_addr/proc_cen_set_inband_addr_attributes.xml \
                     hwp/build_winkle_images/p8_slw_build/proc_pll_ring_attributes.xml \
                     hwp/build_winkle_images/p8_slw_build/p8_xip_customize_attributes.xml \
                     hwp/poreve_memory_attributes.xml \
                     hwp/mcbist_attributes.xml \
                     hwp/proc_winkle_scan_override_attributes.xml \
                     hwp/erepair_thresholds.xml \
                     hwp/dram_training/mem_pll_setup/memb_pll_ring_attributes.xml \
                     hwp/proc_chip_ec_feature.xml

#------------------------------------------------------------------------------
# Initfiles
#------------------------------------------------------------------------------
HWP_INITFILES = hwp/initfiles/sample.initfile \
                hwp/initfiles/cen.dmi.scom.initfile \
                hwp/initfiles/p8.dmi.scom.initfile \
                hwp/initfiles/mbs_def.initfile \
                hwp/initfiles/mba_def.initfile \
                hwp/initfiles/cen_ddrphy.initfile \
                hwp/initfiles/p8.fbc.scom.initfile \
                hwp/initfiles/p8.pe.phase1.scom.initfile \
                hwp/initfiles/p8.pe.phase2.scom.initfile \
                hwp/initfiles/p8.abus.scom.initfile \
                hwp/initfiles/p8.xbus.scom.initfile \
                hwp/initfiles/p8.mcs.scom.initfile \
                hwp/initfiles/p8.as.scom.initfile \
                hwp/initfiles/p8.nx.scom.initfile \
                hwp/initfiles/p8.dmi.custom.scom.initfile \
                hwp/initfiles/cen.dmi.custom.scom.initfile \
                hwp/initfiles/p8.abus.custom.scom.initfile \
                hwp/initfiles/p8.xbus.custom.scom.initfile \
                hwp/initfiles/p8.psi.scom.initfile \
                hwp/initfiles/p8.tpbridge.scom.initfile \
                hwp/initfiles/p8.cxa.scom.initfile \
                hwp/initfiles/p8.a_x_pci_dmi_fir.scom.initfile

HWP_IF_DEFINE_DIR = hwp/initfiles

#------------------------------------------------------------------------------
# Generated files
#------------------------------------------------------------------------------

# Initfile compiler files
IF_CMP_SUBDIR = hwp_ifcompiler

IF_CMP_YACC_C_TARGET = $(IF_CMP_SUBDIR)/ifcompiler.y.tab.c
IF_CMP_YACC_H_TARGET = $(IF_CMP_SUBDIR)/ifcompiler.y.tab.h
IF_CMP_FLEX_TARGET = $(IF_CMP_SUBDIR)/ifcompiler.lex.yy.c
IF_CMP_COMPILER_TARGET = ifcompiler

IF_COMPILER_C_FILES = ifcompiler/initCompiler.C \
                      ifcompiler/initRpn.C \
                      ifcompiler/initScom.C \
                      ifcompiler/initSymbols.C

IF_COMPILER_H_FILES = ifcompiler/initCompiler.H \
                      ifcompiler/initRpn.H \
                      ifcompiler/initScom.H \
                      ifcompiler/initSymbols.H

IF_COMPILER_O_FILES = $(addprefix $(GENDIR)/$(IF_CMP_SUBDIR)/, \
			    $(call notdir, $(IF_COMPILER_C_FILES:.C=.host.o)) \
			    $(call notdir, $(IF_CMP_YACC_C_TARGET:.c=.host.o)) \
			    $(call notdir, $(IF_CMP_FLEX_TARGET:.c=.host.o)) \
		      )

CLEAN_TARGETS += $(IF_COMPILER_O_FILES)

# The FAPI files generated from Error XML files
FAPI_ERROR_TARGETS = fapiHwpReturnCodes.H fapiHwpErrorInfo.H \
                     fapiCollectRegFfdc.C fapiSetSbeError.H

# The PLAT HWP Error Parser file generated from Error XML files
PLAT_HWP_ERR_PARSER = fapiPlatHwpErrParser.H

# The FAPI attribute id file generated from Attribute XML files
FAPI_ATTR_ID_TARGET = fapiAttributeIds.H

# The FAPI files generated from Attribute XML files
FAPI_ATTR_TARGETS = fapiChipEcFeature.C fapiAttributePlatCheck.H \
                    fapiAttributesSupported.html fapiAttrInfo.csv \
                    fapiAttrEnumInfo.csv

# The binary, list and attr files generated from Initfiles
# Generation depends on ifcompiler and fapiAttributeIds.H
HWP_IF_NAMES = $(notdir ${HWP_INITFILES})
HWP_IF_BASENAMES = $(basename ${HWP_IF_NAMES})
HWP_IF_BIN_TARGETS = $(addsuffix .if, ${HWP_IF_BASENAMES})
HWP_IF_LST_TARGETS = $(addsuffix .if.list.bz2, ${HWP_IF_BASENAMES})
HWP_IF_ATT_TARGETS = $(addsuffix .if.attr, ${HWP_IF_BASENAMES})
HWP_IF_ALL_TARGETS = ${HWP_IF_BIN_TARGETS} ${HWP_IF_LST_TARGETS} \
                     ${HWP_IF_ATT_TARGETS}

# The FAPI Initfile attribute service
# Generation depends on the Initfile <name>.if.attr files
FAPI_ATTR_IF_TARGET = fapiAttributeService.C

GENFILES = ${IF_CMP_YACC_C_TARGET} \
           ${IF_CMP_YACC_H_TARGET} \
           ${IF_CMP_FLEX_TARGET} \
           ${IF_CMP_COMPILER_TARGET} \
           ${FAPI_ERROR_TARGETS} \
           ${FAPI_ATTR_ID_TARGET} \
           ${FAPI_ATTR_TARGETS} \
           ${HWP_IF_ALL_TARGETS} \
           ${FAPI_ATTR_IF_TARGET}

GENFILES_PLUGINS = ${PLAT_HWP_ERR_PARSER}

EXTRA_PARTS = $(addprefix ${ROOTPATH}/img/,${HWP_IF_BIN_TARGETS})
GEN_PASS_PRE += make_ifcompiler_dir

include ${ROOTPATH}/config.mk

#------------------------------------------------------------------------------
# The Initfile compiler
#------------------------------------------------------------------------------
make_ifcompiler_dir:
	@mkdir -p $(GENDIR)/$(IF_CMP_SUBDIR)

$(call GENTARGET, ${IF_CMP_YACC_C_TARGET} ${IF_CMP_YACC_H_TARGET}) : \
        ifcompiler/initCompiler.y
	$(C2) "    YACC       $(notdir $<)"
	$(C1)yacc -d -o ${GENDIR}/${IF_CMP_YACC_C_TARGET} $^

$(call GENTARGET, ${IF_CMP_FLEX_TARGET}) : \
        ifcompiler/initCompiler.lex
	$(C2) "    FLEX       $(notdir $<)"
	$(C1)flex -o$@ $^

$(GENDIR)/$(IF_CMP_SUBDIR)/%.host.o: ifcompiler/%.C $(IF_COMPILER_H_FILES)
	$(C2) "    CXX        $(notdir $<)"
	$(C1)$(CCACHE) $(HOST_PREFIX)g++ -O3 $< -I ifcompiler -I $(GENDIR) \
			-I $(GENDIR)/$(IF_CMP_SUBDIR) \
			-I $(ROOTPATH)/src/include/usr/hwpf/hwp -c -o $@

$(GENDIR)/$(IF_CMP_YACC_C_TARGET:.c=.host.o): \
    $(GENDIR)/$(IF_CMP_YACC_C_TARGET) $(IF_COMPILER_H_FILES)
	$(C2) "    CXX        $(notdir $<)"
	$(C1)$(CCACHE) $(HOST_PREFIX)g++ -O3 $< -I ifcompiler -I $(GENDIR) \
			-I $(GENDIR)/$(IF_CMP_SUBDIR) \
			-I $(ROOTPATH)/src/include/usr/hwpf/hwp -c -o $@

$(GENDIR)/$(IF_CMP_FLEX_TARGET:.c=.host.o): \
    $(GENDIR)/$(IF_CMP_FLEX_TARGET) $(IF_COMPILER_H_FILES)
	$(C2) "    CXX        $(notdir $<)"
	$(C1)$(CCACHE) $(HOST_PREFIX)g++ -O3 $< -I ifcompiler -I $(GENDIR) \
			-I $(GENDIR)/$(IF_CMP_SUBDIR) \
			-I $(ROOTPATH)/src/include/usr/hwpf/hwp -c -o $@

$(call GENTARGET, ${IF_CMP_COMPILER_TARGET}) : $(IF_COMPILER_O_FILES)
	$(C2) "    CXX        $(notdir $<)"
	$(C1)$(HOST_PREFIX)g++ -O3 $^ -o $@

#------------------------------------------------------------------------------
# The FAPI return code and error info files generated from Error XML files
#------------------------------------------------------------------------------
$(call GENTARGET, ${FAPI_ERROR_TARGETS}) : \
        fapi/fapiParseErrorInfo.pl ${HWP_ERROR_XML_FILES}
	$< $(dir $@) ${HWP_ERROR_XML_FILES}

#------------------------------------------------------------------------------
# The PLAT HWP RC and FFDC parser file generated from Error XML files
#------------------------------------------------------------------------------
$(call GENPLUGINTARGET, ${PLAT_HWP_ERR_PARSER}) : \
        plat/fapiPlatCreateHwpErrParser.pl ${HWP_ERROR_XML_FILES}
	$< $(dir $@) ${HWP_ERROR_XML_FILES}

#------------------------------------------------------------------------------
# The FAPI attribute id file, the FAPI attribute platform check file and the
# FAPI attributes supported file generated from Attribute XML files
#------------------------------------------------------------------------------
$(call GENTARGET, ${FAPI_ATTR_ID_TARGET} ${FAPI_ATTR_TARGETS}) : \
        fapi/fapiParseAttributeInfo.pl ${HWP_ATTR_XML_FILES}
	$< $(dir $@) ${HWP_ATTR_XML_FILES}

#------------------------------------------------------------------------------
# The binary, list and attr files generated from Initfiles
#------------------------------------------------------------------------------
define HWP_IF_RECIPE
$${GENDIR}/$(basename $(notdir $1)).if :\
	$${GENDIR}/$${IF_CMP_COMPILER_TARGET} \
	$${GENDIR}/$${FAPI_ATTR_ID_TARGET} \
	$${HWP_IF_DEFINE_DIR} $1
	    $$(HOST_PREFIX)jail \
	        $$< -init $1 -outdir $$(dir $$@) \
                    -attr $${GENDIR}/$${FAPI_ATTR_ID_TARGET} \
                    -I $${HWP_IF_DEFINE_DIR}
	@rm -f $${GENDIR}/$(basename $(notdir $1)).if.list.bz2
	@bzip2 $${GENDIR}/$(basename $(notdir $1)).if.list

$${GENDIR}/$(basename $(notdir $1)).if.list.bz2: \
    $${GENDIR}/$(basename $(notdir $1)).if
$${GENDIR}/$(basename $(notdir $1)).if.attr: \
    $${GENDIR}/$(basename $(notdir $1)).if
endef
$(foreach initfile,${HWP_INITFILES}, \
	$(eval $(call HWP_IF_RECIPE,$(initfile))))

${EXTRA_PARTS}: ${IMGDIR}/% : ${GENDIR}/%
	cp -f $< $@

#------------------------------------------------------------------------------
# The FAPI Initfile attribute service
#------------------------------------------------------------------------------
$(call GENTARGET, ${FAPI_ATTR_IF_TARGET}) : \
        fapi/fapiCreateIfAttrService.pl ${HWP_ATTR_XML_FILES} \
        $(addprefix ${GENDIR}/, $(HWP_IF_ATT_TARGETS))
	$< $(dir $@) $(addprefix ${GENDIR}/, $(HWP_IF_ATT_TARGETS)) -a ${HWP_ATTR_XML_FILES}

