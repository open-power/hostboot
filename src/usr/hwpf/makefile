# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2011,2016
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
ROOTPATH = ../../..
SUBDIRS = fapi.d hwp.d plat.d test.d

#------------------------------------------------------------------------------
# This makefile controls the generation of HWPF files
#------------------------------------------------------------------------------

#------------------------------------------------------------------------------
# Source XML files
#------------------------------------------------------------------------------

HWP_ERROR_XML_FILES += hwp/fapiHwpErrorInfo.xml
HWP_ERROR_XML_FILES += hwp/dmi_training/proc_cen_framelock/proc_cen_framelock_errors.xml
HWP_ERROR_XML_FILES += hwp/dimm_errors.xml
HWP_ERROR_XML_FILES += hwp/chip_accessors/chip_errors.xml
HWP_ERROR_XML_FILES += hwp/dram_training/memory_errors.xml
HWP_ERROR_XML_FILES += hwp/nest_chiplets/proc_start_clocks_chiplets/proc_start_clocks_chiplets_errors.xml
HWP_ERROR_XML_FILES += hwp/edi_ei_initialization/proc_fab_iovalid/proc_fab_smp_errors.xml
HWP_ERROR_XML_FILES += hwp/mvpd_accessors/mvpd_errors.xml
HWP_ERROR_XML_FILES += hwp/spd_accessors/getSpdAttrAccessorErrors.xml
HWP_ERROR_XML_FILES += hwp/winkle_ring_accessors/proc_l3_delta_data_errors.xml
HWP_ERROR_XML_FILES += hwp/pll_accessors/getPllRingInfoAttrErrors.xml
HWP_ERROR_XML_FILES += hwp/pll_accessors/getPllRingAttrErrors.xml
HWP_ERROR_XML_FILES += ../pore/fapiporeve/fapiPoreVe_errors.xml
HWP_ERROR_XML_FILES += hwp/dram_initialization/proc_setup_bars/proc_setup_bars_errors.xml
HWP_ERROR_XML_FILES += hwp/nest_chiplets/proc_chiplet_scominit/proc_chiplet_scominit_errors.xml
HWP_ERROR_XML_FILES += hwp/build_winkle_images/p8_slw_build/p8_slw_build_errors.xml
HWP_ERROR_XML_FILES += hwp/build_winkle_images/p8_slw_build/p8_xip_customize_errors.xml
HWP_ERROR_XML_FILES += hwp/build_winkle_images/p8_slw_build/p8_pba_bar_config_errors.xml
HWP_ERROR_XML_FILES += hwp/nest_chiplets/proc_a_x_pci_dmi_pll_setup_errors.xml
HWP_ERROR_XML_FILES += hwp/core_activate/proc_prep_master_winkle/proc_prep_master_winkle_errors.xml
HWP_ERROR_XML_FILES += hwp/core_activate/proc_stop_deadman_timer/proc_stop_deadman_timer_errors.xml
HWP_ERROR_XML_FILES += hwp/activate_powerbus/proc_build_smp/proc_build_smp_errors.xml
HWP_ERROR_XML_FILES += hwp/activate_powerbus/proc_build_smp/proc_adu_utils_errors.xml
HWP_ERROR_XML_FILES += hwp/nest_chiplets/proc_pcie_slot_power/proc_pcie_slot_power_errors.xml
HWP_ERROR_XML_FILES += hwp/thread_activate/proc_thread_control/proc_thread_control.xml
HWP_ERROR_XML_FILES += hwp/bus_training/erepair_errors.xml
HWP_ERROR_XML_FILES += hwp/nest_chiplets/proc_pcie_scominit/proc_pcie_scominit_errors.xml
HWP_ERROR_XML_FILES += hwp/dram_initialization/proc_pcie_config/proc_pcie_config_errors.xml
HWP_ERROR_XML_FILES += hwp/build_winkle_images/p8_set_pore_bar/p8_set_pore_bar_errors.xml
HWP_ERROR_XML_FILES += hwp/build_winkle_images/p8_set_pore_bar/p8_pmc_deconfig_setup_errors.xml
HWP_ERROR_XML_FILES += hwp/build_winkle_images/p8_set_pore_bar/p8_pfet_errors.xml
HWP_ERROR_XML_FILES += hwp/build_winkle_images/p8_set_pore_bar/p8_poreslw_errors.xml
HWP_ERROR_XML_FILES += hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_check_slave_sbe_seeprom_complete_errors.xml
HWP_ERROR_XML_FILES += hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_extract_sbe_rc_errors.xml
HWP_ERROR_XML_FILES += hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_read_seeprom_errors.xml
HWP_ERROR_XML_FILES += hwp/proc_sbe_registers.xml
HWP_ERROR_XML_FILES += hwp/runtime_errors/p8_ocb_init_errors.xml
HWP_ERROR_XML_FILES += hwp/runtime_errors/p8_occ_control_errors.xml
HWP_ERROR_XML_FILES += hwp/runtime_errors/p8_occ_sram_init_errors.xml
HWP_ERROR_XML_FILES += hwp/runtime_errors/p8_oha_init_errors.xml
HWP_ERROR_XML_FILES += hwp/runtime_errors/p8_pcbs_init_errors.xml
HWP_ERROR_XML_FILES += hwp/runtime_errors/p8_pm_prep_for_reset_errors.xml
HWP_ERROR_XML_FILES += hwp/runtime_errors/p8_force_vsafe_errors.xml
HWP_ERROR_XML_FILES += hwp/runtime_errors/p8_pmc_errors.xml
HWP_ERROR_XML_FILES += hwp/runtime_errors/p8_pss_errors.xml
HWP_ERROR_XML_FILES += hwp/runtime_errors/proc_cpu_special_wakeup_errors.xml
HWP_ERROR_XML_FILES += hwp/runtime_errors/p8_poregpe_errors.xml
HWP_ERROR_XML_FILES += hwp/runtime_errors/p8_pba_init_errors.xml
HWP_ERROR_XML_FILES += hwp/runtime_errors/proc_ocb_indir_access_errors.xml
HWP_ERROR_XML_FILES += hwp/dram_initialization/host_mpipl_service/proc_mpipl_chip_cleanup_errors.xml
HWP_ERROR_XML_FILES += hwp/build_winkle_images/p8_set_pore_bar/p8_pfet_init_errors.xml
HWP_ERROR_XML_FILES += hwp/poreve_errors.xml
HWP_ERROR_XML_FILES += hwp/proc_fab_iovalid_errors.xml
HWP_ERROR_XML_FILES += hwp/nest_chiplets/proc_chiplet_scominit/proc_abus_scominit_errors.xml
HWP_ERROR_XML_FILES += hwp/nest_chiplets/proc_chiplet_scominit/proc_xbus_scominit_errors.xml
HWP_ERROR_XML_FILES += hwp/dmi_training/proc_dmi_scominit_errors.xml
HWP_ERROR_XML_FILES += hwp/dmi_training/cen_dmi_scominit_errors.xml
HWP_ERROR_XML_FILES += hwp/sbe_centaur_init/cen_xip_customize_errors.xml
HWP_ERROR_XML_FILES += hwp/tod_init/proc_tod_utils/proc_tod_utils.xml
HWP_ERROR_XML_FILES += hwp/mc_config/mss_eff_config/opt_memmap_errors.xml
HWP_ERROR_XML_FILES += hwp/pstates/pstates/p8_build_pstate_datablock_errors.xml
HWP_ERROR_XML_FILES += hwp/pstates/pstates/proc_get_voltage_errors.xml
HWP_ERROR_XML_FILES += hwp/proc_cfam_registers.xml
HWP_ERROR_XML_FILES += hwp/p8_slw_registers.xml
HWP_ERROR_XML_FILES += hwp/utility_procedures/memory_mss_maint_cmds.xml
HWP_ERROR_XML_FILES += hwp/utility_procedures/proc_mpipl_force_winkle_errors.xml

HWP_ERROR_XML_FILES += hwp/mc_config/mss_volt/memory_mss_volt.xml
HWP_ERROR_XML_FILES += hwp/mc_config/mss_volt/memory_mss_volt_avdd_offset.xml
HWP_ERROR_XML_FILES += hwp/mc_config/mss_volt/memory_mss_volt_vdd_offset.xml
HWP_ERROR_XML_FILES += hwp/mc_config/mss_volt/memory_mss_volt_vcs_offset.xml
HWP_ERROR_XML_FILES += hwp/mc_config/mss_volt/memory_mss_volt_vpp_offset.xml
HWP_ERROR_XML_FILES += hwp/mc_config/mss_volt/memory_mss_volt_vddr_offset.xml
HWP_ERROR_XML_FILES += hwp/mc_config/mss_freq/memory_mss_freq.xml
HWP_ERROR_XML_FILES += hwp/mc_config/mss_eff_config/memory_mss_eff_grouping.xml
HWP_ERROR_XML_FILES += hwp/mc_config/mss_eff_config/memory_mss_eff_config_thermal.xml
HWP_ERROR_XML_FILES += hwp/mc_config/mss_eff_config/memory_mss_bulk_pwr_throttles.xml
HWP_ERROR_XML_FILES += hwp/dram_training/memory_mss_funcs.xml
HWP_ERROR_XML_FILES += hwp/dram_training/mss_draminit_training/memory_mss_draminit_training.xml
HWP_ERROR_XML_FILES += hwp/dram_training/mss_ddr_phy_reset/memory_mss_ddr_phy_reset.xml
HWP_ERROR_XML_FILES += hwp/dram_training/memory_mss_termination_control.xml
HWP_ERROR_XML_FILES += hwp/dram_training/mem_startclocks/memory_cen_stopclocks.xml
HWP_ERROR_XML_FILES += hwp/dram_training/mss_scominit/memory_mss_scominit.xml
HWP_ERROR_XML_FILES += hwp/dram_training/mss_draminit_trainadv/memory_mss_mcbist_common.xml
HWP_ERROR_XML_FILES += hwp/dram_initialization/proc_setup_bars/memory_mss_setup_bars.xml
HWP_ERROR_XML_FILES += hwp/slave_sbe/proc_cen_ref_clk_enable/proc_cen_ref_clk_enable_errors.xml
HWP_ERROR_XML_FILES += hwp/dmi_training/mss_getecid/memory_mss_get_cen_ecid.xml
HWP_ERROR_XML_FILES += hwp/dram_initialization/mss_extent_setup/memory_mss_extent_setup.xml
HWP_ERROR_XML_FILES += hwp/dram_initialization/mss_thermal_init/memory_mss_thermal_init.xml
HWP_ERROR_XML_FILES += hwp/dram_training/mss_draminit/memory_mss_draminit.xml
HWP_ERROR_XML_FILES += hwp/dram_training/mss_draminit_mc/memory_mss_draminit_mc.xml
HWP_ERROR_XML_FILES += hwp/dram_training/mss_draminit_trainadv/memory_mss_access_delay_reg.xml
HWP_ERROR_XML_FILES += hwp/dram_training/mss_draminit_trainadv/memory_mss_draminit_training_advanced.xml
HWP_ERROR_XML_FILES += hwp/dram_training/mss_draminit_trainadv/memory_mss_mss_ddr4_pda_errors.xml
HWP_ERROR_XML_FILES += hwp/dram_training/mss_draminit_trainadv/memory_mss_generic_shmoo.xml
HWP_ERROR_XML_FILES += hwp/dram_training/mss_draminit_trainadv/memory_mss_mcbist.xml
HWP_ERROR_XML_FILES += hwp/mc_config/mss_eff_config/memory_mss_eff_config.xml
HWP_ERROR_XML_FILES += hwp/mc_config/mss_eff_config/memory_mss_eff_config_cke_map.xml
HWP_ERROR_XML_FILES += hwp/mc_config/mss_eff_config/memory_mss_eff_config_rank_group.xml
HWP_ERROR_XML_FILES += hwp/mc_config/mss_eff_config/memory_mss_eff_config_termination.xml
HWP_ERROR_XML_FILES += hwp/build_winkle_images/p8_block_wakeup_intr/p8_block_wakeup_intr_errors.xml
HWP_ERROR_XML_FILES += hwp/build_winkle_images/proc_mailbox_utils/p8_mailbox_utils_errors.xml
HWP_ERROR_XML_FILES += hwp/proc_otprom_registers.xml
HWP_ERROR_XML_FILES += hwp/runtime_errors/p8_gpe_registers.xml
HWP_ERROR_XML_FILES += hwp/runtime_errors/p8_pss_registers.xml
HWP_ERROR_XML_FILES += hwp/proc_hwreconfig/proc_enable_reconfig/proc_enable_reconfig_errors.xml
HWP_ERROR_XML_FILES += hwp/dram_training/mem_startclocks/cen_mem_startclocks_errors.xml
HWP_ERROR_XML_FILES += hwp/dram_training/mem_pll_setup/cen_mem_pll_initf_errors.xml
HWP_ERROR_XML_FILES += hwp/dram_training/mem_pll_setup/cen_mem_pll_setup_errors.xml
HWP_ERROR_XML_FILES += hwp/core_activate/proc_check_slw_done/proc_check_slw_done_errors.xml
HWP_ERROR_XML_FILES += hwp/dram_initialization/proc_throttle_sync/proc_throttle_sync_errors.xml
HWP_ERROR_XML_FILES += hwp/dram_initialization/mss_power_cleanup/memory_mss_power_cleanup.xml
HWP_ERROR_XML_FILES += hwp/runtime_errors/p8_pstate_registers.xml
HWP_ERROR_XML_FILES += hwp/mc_config/mss_eff_mb_interleave/memory_mss_eff_mb_interleave.xml
HWP_ERROR_XML_FILES += hwp/nest_chiplets/proc_a_x_pci_dmi_pll_registers.xml
HWP_ERROR_XML_FILES += hwp/dram_training/mss_lrdimm_funcs/memory_mss_lrdimm_funcs.xml
HWP_ERROR_XML_FILES += hwp/bus_training/gcr_funcs_errors.xml
HWP_ERROR_XML_FILES += hwp/bus_training/io_run_training_errors.xml
HWP_ERROR_XML_FILES += hwp/bus_training/io_funcs_errors.xml
HWP_ERROR_XML_FILES += hwp/bus_training/io_dccal_errors.xml
HWP_ERROR_XML_FILES += hwp/bus_training/io_power_down_lanes_errors.xml
HWP_ERROR_XML_FILES += hwp/bus_training/io_read_erepair_errors.xml
HWP_ERROR_XML_FILES += hwp/bus_training/io_fir_isolation_errors.xml
HWP_ERROR_XML_FILES += hwp/bus_training/io_restore_erepair_errors.xml
HWP_ERROR_XML_FILES += hwp/proc_pibmem_registers.xml
HWP_ERROR_XML_FILES += hwp/proc_clock_control_registers.xml
HWP_ERROR_XML_FILES += hwp/proc_sbe_errors/proc_sbe_check_master_errors.xml
HWP_ERROR_XML_FILES += hwp/proc_sbe_errors/proc_sbe_chiplet_init_errors.xml
HWP_ERROR_XML_FILES += hwp/proc_sbe_errors/proc_sbe_decompress_scan_halt_codes.xml
HWP_ERROR_XML_FILES += hwp/proc_sbe_errors/proc_sbe_ex_dpll_setup_halt_codes.xml
HWP_ERROR_XML_FILES += hwp/proc_sbe_errors/proc_sbe_ex_startclocks_errors.xml
HWP_ERROR_XML_FILES += hwp/proc_sbe_errors/proc_sbe_fabricinit_errors.xml
HWP_ERROR_XML_FILES += hwp/proc_sbe_errors/proc_sbe_instruct_start_errors.xml
HWP_ERROR_XML_FILES += hwp/proc_sbe_errors/proc_sbe_lco_loader_errors.xml
HWP_ERROR_XML_FILES += hwp/proc_sbe_errors/proc_sbe_npll_setup_errors.xml
HWP_ERROR_XML_FILES += hwp/proc_sbe_errors/proc_sbe_pb_startclocks.xml
HWP_ERROR_XML_FILES += hwp/proc_sbe_errors/proc_sbe_pibmem_loader_halt_codes.xml
HWP_ERROR_XML_FILES += hwp/proc_sbe_errors/proc_sbe_scominit_errors.xml
HWP_ERROR_XML_FILES += hwp/proc_sbe_errors/proc_sbe_select_ex_errors.xml
HWP_ERROR_XML_FILES += hwp/proc_sbe_errors/proc_sbe_setup_evid_errors.xml
HWP_ERROR_XML_FILES += hwp/proc_sbe_errors/proc_sbe_tp_switch_gears_errors.xml
HWP_ERROR_XML_FILES += hwp/proc_sbe_errors/proc_sbe_trigger_winkle_errors.xml
HWP_ERROR_XML_FILES += hwp/proc_sbe_errors/proc_slw_base_halt_codes.xml
HWP_ERROR_XML_FILES += hwp/proc_sbe_errors/sbe_common_halt_codes.xml
HWP_ERROR_XML_FILES += hwp/proc_sbe_errors/sbe_load_ring_vec_ex_errors.xml
HWP_ERROR_XML_FILES += hwp/slave_sbe/proc_tp_collect_dbg_data/proc_tp_collect_dbg_data.xml
HWP_ERROR_XML_FILES += hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_extract_pore_engine_state_errors.xml
HWP_ERROR_XML_FILES += hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_extract_pore_base_ffdc.xml
HWP_ERROR_XML_FILES += hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_extract_pore_halt_ffdc.xml
HWP_ERROR_XML_FILES += hwp/proc_pba_utils_registers.xml
HWP_ERROR_XML_FILES += hwp/p8_fir_registers.xml
HWP_ERROR_XML_FILES += hwp/cen_fir_registers.xml
HWP_ERROR_XML_FILES += hwp/tp_dbg_data_accessors/proc_tp_dbg_data_errors.xml
HWP_ERROR_XML_FILES += hwp/secure_boot/proc_sbe_scan_service_errors.xml
HWP_ERROR_XML_FILES += hwp/secure_boot/proc_stop_sbe_scan_service_errors.xml

## these get generated into obj/genfiles/AttributeIds.H
HWP_ATTR_XML_FILES += hwp/memory_attributes.xml
HWP_ATTR_XML_FILES += hwp/L2_L3_attributes.xml
HWP_ATTR_XML_FILES += hwp/scratch_attributes.xml
HWP_ATTR_XML_FILES += hwp/system_attributes.xml
HWP_ATTR_XML_FILES += hwp/chip_attributes.xml
HWP_ATTR_XML_FILES += $(if $(CONFIG_VPD_GETMACRO_USE_EFF_ATTR), hwp/lab_dimm_spd_attributes.xml, hwp/dimm_spd_attributes.xml)
HWP_ATTR_XML_FILES += $(if $(CONFIG_VPD_GETMACRO_USE_EFF_ATTR), hwp/lab_dimm_attributes.xml, hwp/dimm_attributes.xml)
HWP_ATTR_XML_FILES += hwp/unit_attributes.xml
HWP_ATTR_XML_FILES += hwp/freq_attributes.xml
HWP_ATTR_XML_FILES += hwp/ei_bus_attributes.xml
HWP_ATTR_XML_FILES += hwp/chip_ec_attributes.xml
HWP_ATTR_XML_FILES += hwp/centaur_ec_attributes.xml
HWP_ATTR_XML_FILES += hwp/common_attributes.xml
HWP_ATTR_XML_FILES += hwp/sync_attributes.xml
HWP_ATTR_XML_FILES += hwp/dram_initialization/proc_setup_bars/proc_setup_bars_memory_attributes.xml
HWP_ATTR_XML_FILES += hwp/dram_initialization/proc_setup_bars/proc_setup_bars_l3_attributes.xml
HWP_ATTR_XML_FILES += hwp/dram_initialization/proc_setup_bars/proc_setup_bars_mmio_attributes.xml
HWP_ATTR_XML_FILES += hwp/activate_powerbus/proc_build_smp/proc_fab_smp_fabric_attributes.xml
HWP_ATTR_XML_FILES += hwp/runtime_attributes/pm_plat_attributes.xml
HWP_ATTR_XML_FILES += hwp/runtime_attributes/pm_hwp_attributes.xml
HWP_ATTR_XML_FILES += hwp/nest_chiplets/proc_pcie_scominit/proc_pcie_scominit_attributes.xml
HWP_ATTR_XML_FILES += hwp/dmi_training/proc_cen_set_inband_addr/proc_cen_set_inband_addr_attributes.xml
HWP_ATTR_XML_FILES += hwp/build_winkle_images/p8_slw_build/proc_pll_ring_attributes.xml
HWP_ATTR_XML_FILES += hwp/build_winkle_images/p8_slw_build/p8_xip_customize_attributes.xml
HWP_ATTR_XML_FILES += hwp/poreve_memory_attributes.xml
HWP_ATTR_XML_FILES += hwp/mcbist_attributes.xml
HWP_ATTR_XML_FILES += hwp/proc_winkle_scan_override_attributes.xml
HWP_ATTR_XML_FILES += hwp/erepair_thresholds.xml
HWP_ATTR_XML_FILES += hwp/dram_training/mem_pll_setup/memb_pll_ring_attributes.xml
HWP_ATTR_XML_FILES += hwp/proc_chip_ec_feature.xml
HWP_ATTR_XML_FILES += hwp/proc_abus_dmi_xbus_scominit_attributes.xml
HWP_ATTR_XML_FILES += hwp/runtime_attributes/memory_occ_attributes.xml
HWP_ATTR_XML_FILES += hwp/pstate_attributes.xml
HWP_ATTR_XML_FILES += hwp/slave_sbe/proc_tp_collect_dbg_data/proc_tp_collect_dbg_data_attributes.xml

#------------------------------------------------------------------------------
# PLL Ring Data files
#------------------------------------------------------------------------------
HWP_PLL_FILES += hwp/pll_attributes/s1_10_pll_ring.attributes
HWP_PLL_FILES += hwp/pll_attributes/s1_13_pll_ring.attributes
HWP_PLL_FILES += hwp/pll_attributes/s1_20_pll_ring.attributes
HWP_PLL_FILES += hwp/pll_attributes/s1_21_pll_ring.attributes
HWP_PLL_FILES += hwp/pll_attributes/p8_10_pll_ring.attributes
HWP_PLL_FILES += hwp/pll_attributes/p8_20_pll_ring.attributes
HWP_PLL_FILES += hwp/pll_attributes/n1_10_pll_ring.attributes
HWP_PLL_FILES += hwp/pll_attributes/centaur_10_pll_ring.attributes
HWP_PLL_FILES += hwp/pll_attributes/centaur_20_pll_ring.attributes
HWP_PLL_FILES += hwp/pll_attributes/centaur_21_pll_ring.attributes

#------------------------------------------------------------------------------
# Winkle Ring data files
#------------------------------------------------------------------------------
HWP_WINKLE_RING_FILES += hwp/winkle_ring_accessors/s1_10_winkle_ring.attributes
HWP_WINKLE_RING_FILES += hwp/winkle_ring_accessors/s1_13_winkle_ring.attributes
HWP_WINKLE_RING_FILES += hwp/winkle_ring_accessors/s1_20_winkle_ring.attributes
HWP_WINKLE_RING_FILES += hwp/winkle_ring_accessors/s1_21_winkle_ring.attributes
HWP_WINKLE_RING_FILES += hwp/winkle_ring_accessors/p8_10_winkle_ring.attributes
HWP_WINKLE_RING_FILES += hwp/winkle_ring_accessors/p8_20_winkle_ring.attributes
HWP_WINKLE_RING_FILES += hwp/winkle_ring_accessors/n1_10_winkle_ring.attributes

#------------------------------------------------------------------------------
# Tp_dbg Spy data files
#------------------------------------------------------------------------------
HWP_TP_DBG_SPY_FILES += hwp/tp_dbg_attributes/s1_10_tp_dbg_data.attributes
HWP_TP_DBG_SPY_FILES += hwp/tp_dbg_attributes/s1_13_tp_dbg_data.attributes
HWP_TP_DBG_SPY_FILES += hwp/tp_dbg_attributes/s1_20_tp_dbg_data.attributes
HWP_TP_DBG_SPY_FILES += hwp/tp_dbg_attributes/s1_21_tp_dbg_data.attributes
HWP_TP_DBG_SPY_FILES += hwp/tp_dbg_attributes/p8_10_tp_dbg_data.attributes
HWP_TP_DBG_SPY_FILES += hwp/tp_dbg_attributes/n1_10_tp_dbg_data.attributes

#------------------------------------------------------------------------------
# Initfiles
#------------------------------------------------------------------------------
HWP_INITFILES += hwp/initfiles/sample.initfile
HWP_INITFILES += hwp/initfiles/cen.dmi.scom.initfile
HWP_INITFILES += hwp/initfiles/p8.dmi.scom.initfile
HWP_INITFILES += hwp/initfiles/mbs_def.initfile
HWP_INITFILES += hwp/initfiles/mba_def.initfile
HWP_INITFILES += hwp/initfiles/cen_ddrphy.initfile
HWP_INITFILES += hwp/initfiles/p8.fbc.scom.initfile
HWP_INITFILES += hwp/initfiles/p8.pe.phase1.scom.initfile
HWP_INITFILES += hwp/initfiles/p8.pe.phase2.scom.initfile
HWP_INITFILES += hwp/initfiles/p8.abus.scom.initfile
HWP_INITFILES += hwp/initfiles/p8.xbus.scom.initfile
HWP_INITFILES += hwp/initfiles/p8.mcs.scom.initfile
HWP_INITFILES += hwp/initfiles/p8.as.scom.initfile
HWP_INITFILES += hwp/initfiles/p8.nx.scom.initfile
HWP_INITFILES += hwp/initfiles/p8.dmi.custom.scom.initfile
HWP_INITFILES += hwp/initfiles/cen.dmi.custom.scom.initfile
HWP_INITFILES += hwp/initfiles/p8.abus.custom.scom.initfile
HWP_INITFILES += hwp/initfiles/p8.xbus.custom.scom.initfile
HWP_INITFILES += hwp/initfiles/p8.psi.scom.initfile
HWP_INITFILES += hwp/initfiles/p8.tpbridge.scom.initfile
HWP_INITFILES += hwp/initfiles/p8.cxa.scom.initfile
HWP_INITFILES += hwp/initfiles/p8.a_x_pci_dmi_fir.scom.initfile
HWP_INITFILES += hwp/initfiles/p8.npu.scom.initfile
HWP_INITFILES += hwp/initfiles/p8.nvbus.scom.initfile

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

IF_COMPILER_C_FILES += ifcompiler/initCompiler.C
IF_COMPILER_C_FILES += ifcompiler/initRpn.C
IF_COMPILER_C_FILES += ifcompiler/initScom.C
IF_COMPILER_C_FILES += ifcompiler/initSymbols.C

IF_COMPILER_H_FILES += ifcompiler/initCompiler.H
IF_COMPILER_H_FILES += ifcompiler/initRpn.H
IF_COMPILER_H_FILES += ifcompiler/initScom.H
IF_COMPILER_H_FILES += ifcompiler/initSymbols.H

IF_COMPILER_O_FILES = $(addprefix $(GENDIR)/$(IF_CMP_SUBDIR)/, \
			    $(call notdir, $(IF_COMPILER_C_FILES:.C=.host.o)) \
			    $(call notdir, $(IF_CMP_YACC_C_TARGET:.c=.host.o)) \
			    $(call notdir, $(IF_CMP_FLEX_TARGET:.c=.host.o)) \
		      )

CLEAN_TARGETS += $(IF_COMPILER_O_FILES)

# The FAPI files generated from Error XML files
FAPI_ERROR_TARGETS += fapiHwpReturnCodes.H
FAPI_ERROR_TARGETS += fapiHwpErrorInfo.H
FAPI_ERROR_TARGETS += fapiCollectRegFfdc.C
FAPI_ERROR_TARGETS += fapiSetSbeError.H

# The PLAT HWP Error Parser file generated from Error XML files
PLAT_HWP_ERR_PARSER = fapiPlatHwpErrParser.H

# The FAPI attribute id file generated from Attribute XML files
FAPI_ATTR_ID_TARGET = fapiAttributeIds.H

# The FAPI PLL attribute header file generated from data files
FAPI_PLL_TARGET = fapiPllRingAttr.H

# The FAPI Winkle Ring attribute header file generated from data files
FAPI_WINKLE_RING_TARGET = fapiL3DeltaDataAttr.H

# The FAPI tp_dbg spy attribute header file generated from data files
FAPI_TP_DBG_SPY_TARGET = fapiTpDbgDataAttr.H

# The FAPI files generated from Attribute XML files
FAPI_ATTR_TARGETS += fapiChipEcFeature.C
FAPI_ATTR_TARGETS += fapiAttributePlatCheck.H
FAPI_ATTR_TARGETS += fapiAttributesSupported.html
FAPI_ATTR_TARGETS += fapiAttrInfo.csv
FAPI_ATTR_TARGETS += fapiAttrEnumInfo.csv

# The binary, list and attr files generated from Initfiles
# Generation depends on ifcompiler and fapiAttributeIds.H
HWP_IF_NAMES = $(notdir ${HWP_INITFILES})
HWP_IF_BASENAMES = $(basename ${HWP_IF_NAMES})
HWP_IF_BIN_TARGETS = $(addsuffix .if, ${HWP_IF_BASENAMES})
HWP_IF_LST_TARGETS = $(addsuffix .if.list.bz2, ${HWP_IF_BASENAMES})
HWP_IF_ATT_TARGETS = $(addsuffix .if.attr, ${HWP_IF_BASENAMES})
HWP_IF_ALL_TARGETS += ${HWP_IF_BIN_TARGETS}
HWP_IF_ALL_TARGETS += ${HWP_IF_LST_TARGETS}
HWP_IF_ALL_TARGETS += ${HWP_IF_ATT_TARGETS}

# The FAPI Initfile attribute service
# Generation depends on the Initfile <name>.if.attr files
FAPI_ATTR_IF_TARGET = fapiAttributeService.C

GENFILES += ${IF_CMP_YACC_C_TARGET}
GENFILES += ${IF_CMP_YACC_H_TARGET}
GENFILES += ${IF_CMP_FLEX_TARGET}
GENFILES += ${IF_CMP_COMPILER_TARGET}
GENFILES += ${FAPI_ERROR_TARGETS}
GENFILES += ${FAPI_ATTR_ID_TARGET}
GENFILES += ${FAPI_ATTR_TARGETS}
GENFILES += ${HWP_IF_ALL_TARGETS}
GENFILES += ${FAPI_ATTR_IF_TARGET}
GENFILES += ${FAPI_PLL_TARGET}
GENFILES += ${FAPI_WINKLE_RING_TARGET}
GENFILES += ${FAPI_TP_DBG_SPY_TARGET}

GENFILES_PLUGINS = ${PLAT_HWP_ERR_PARSER}

EXTRA_PARTS = $(addprefix ${ROOTPATH}/img/,${HWP_IF_BIN_TARGETS})
GEN_PASS_PRE += make_ifcompiler_dir

include ${ROOTPATH}/config.mk

#------------------------------------------------------------------------------
# The Initfile compiler
#------------------------------------------------------------------------------
make_ifcompiler_dir:
	@mkdir -p $(GENDIR)/$(IF_CMP_SUBDIR)

$(call GENTARGET, ${IF_CMP_YACC_C_TARGET}) : \
        ifcompiler/initCompiler.y
	$(C2) "    YACC       $(notdir $<)"
	$(C1)yacc -d -o ${GENDIR}/${IF_CMP_YACC_C_TARGET} $^

$(call GENTARGET, ${IF_CMP_YACC_H_TARGET}) : \
    $(call GENTARGET, ${IF_CMP_YACC_C_TARGET}) ifcompiler/initCompiler.y

$(call GENTARGET, ${IF_CMP_FLEX_TARGET}) : \
        ifcompiler/initCompiler.lex
	$(C2) "    FLEX       $(notdir $<)"
	$(C1)flex -o$@ $^

try = $(shell set -e; if ($(1)) >/dev/null 2>&1; \
        then echo "$(2)"; \
        else echo "$(3)"; fi )

try-cflag = $(call try,$(1) $(2) -x c -c /dev/null -o /dev/null,$(2))
HOSTCFLAGS:=-O3
HOSTCFLAGS+=$(call try-cflag,$(HOST_PREFIX)g++,-std=gnu++03)

$(GENDIR)/$(IF_CMP_SUBDIR)/%.host.o: \
	    ifcompiler/%.C $(IF_COMPILER_H_FILES) \
	    $(GENDIR)/$(IF_CMP_YACC_H_TARGET)
	$(C2) "    CXX        $(notdir $<)"
	$(C1)$(CCACHE) $(HOST_PREFIX)g++ $(HOSTCFLAGS) $< -I ifcompiler -I $(GENDIR) \
			-I $(GENDIR)/$(IF_CMP_SUBDIR) \
			-I $(ROOTPATH)/src/include/usr/hwpf/hwp -c -o $@

$(GENDIR)/$(IF_CMP_YACC_C_TARGET:.c=.host.o): \
    $(GENDIR)/$(IF_CMP_YACC_C_TARGET) $(IF_COMPILER_H_FILES)
	$(C2) "    CXX        $(notdir $<)"
	$(C1)$(CCACHE) $(HOST_PREFIX)g++ $(HOSTCFLAGS) $< -I ifcompiler -I $(GENDIR) \
			-I $(GENDIR)/$(IF_CMP_SUBDIR) \
			-I $(ROOTPATH)/src/include/usr/hwpf/hwp -c -o $@

$(GENDIR)/$(IF_CMP_FLEX_TARGET:.c=.host.o): \
    $(GENDIR)/$(IF_CMP_FLEX_TARGET) $(IF_COMPILER_H_FILES) \
    $(GENDIR)/$(IF_CMP_YACC_H_TARGET)
	$(C2) "    CXX        $(notdir $<)"
	$(C1)$(CCACHE) $(HOST_PREFIX)g++ $(HOSTCFLAGS) -DHOSTBOOT_COMPILE $< -I ifcompiler -I $(GENDIR) \
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
# The PLL attribute file
#------------------------------------------------------------------------------
$(call GENTARGET, ${FAPI_PLL_TARGET}) : \
        fapi/fapiCreatePllRingAttrVals.pl ${HWP_PLL_FILES}
	$< $(dir $@) ${HWP_PLL_FILES}

#------------------------------------------------------------------------------
# The Winkle Ring attribute file
#------------------------------------------------------------------------------
$(call GENTARGET, ${FAPI_WINKLE_RING_TARGET}) : \
        fapi/fapiCreateL3DeltaVals.pl ${HWP_WINKLE_RING_FILES}
	$< $(dir $@) ${HWP_WINKLE_RING_FILES}

#------------------------------------------------------------------------------
# The tp_dbg spy attribute file
#------------------------------------------------------------------------------
$(call GENTARGET, ${FAPI_TP_DBG_SPY_TARGET}) : \
	fapi/fapiCreateTpDbgAttrVals.pl ${HWP_TP_DBG_SPY_FILES}
	$< $(dir $@) ${HWP_TP_DBG_SPY_FILES}

#------------------------------------------------------------------------------
# The binary, list and attr files generated from Initfiles
#------------------------------------------------------------------------------
define HWP_IF_RECIPE
$${GENDIR}/$(basename $(notdir $1)).if :\
	$${GENDIR}/$${IF_CMP_COMPILER_TARGET} \
	$${GENDIR}/$${FAPI_ATTR_ID_TARGET} \
	$${HWP_IF_DEFINE_DIR} $1
	    $$(JAILCMD) \
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

