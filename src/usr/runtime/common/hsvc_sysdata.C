/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/common/hsvc_sysdata.C $                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// Generated on Thu Apr 24 11:24:01 CDT 2014 by cswenson from
//  ./create_hsvc_data.pl -w ../../xml/attribute_info/chip_attributes.xml ../../xml/attribute_info/common_attributes.xml ../../xml/attribute_info/freq_attributes.xml ../../xml/attribute_info/L2_L3_attributes.xml ../../xml/attribute_info/p8_xip_customize_attributes.xml ../../xml/attribute_info/pm_hwp_attributes.xml ../../xml/attribute_info/pm_plat_attributes.xml ../../xml/attribute_info/poreve_memory_attributes.xml ../../xml/attribute_info/proc_chip_ec_feature.xml ../../xml/attribute_info/proc_fab_smp_fabric_attributes.xml ../../xml/attribute_info/proc_pll_ring_attributes.xml ../../xml/attribute_info/proc_setup_bars_l3_attributes.xml ../../xml/attribute_info/proc_winkle_scan_override_attributes.xml ../../xml/attribute_info/scratch_attributes.xml ../../xml/attribute_info/system_attributes.xml ../../xml/attribute_info/unit_attributes.xml

// -- Input: ../../xml/attribute_info/chip_attributes.xml --
// No attributes found
// -- Input: ../../xml/attribute_info/common_attributes.xml --
// No attributes found
// -- Input: ../../xml/attribute_info/freq_attributes.xml --
HSVC_LOAD_ATTR( ATTR_FREQ_A );
HSVC_LOAD_ATTR( ATTR_FREQ_CORE_FLOOR );
HSVC_LOAD_ATTR( ATTR_FREQ_CORE_NOMINAL );
HSVC_LOAD_ATTR( ATTR_FREQ_MEM_REFCLOCK );
HSVC_LOAD_ATTR( ATTR_FREQ_PB );
HSVC_LOAD_ATTR( ATTR_FREQ_PCIE );
HSVC_LOAD_ATTR( ATTR_FREQ_PROC_REFCLOCK );
HSVC_LOAD_ATTR( ATTR_FREQ_PROC_REFCLOCK_KHZ );
HSVC_LOAD_ATTR( ATTR_FREQ_X );
// -- Input: ../../xml/attribute_info/L2_L3_attributes.xml --
HSVC_LOAD_ATTR( ATTR_L2_FORCE_R_T2_EPS );
HSVC_LOAD_ATTR( ATTR_L2_R_T0_EPS );
HSVC_LOAD_ATTR( ATTR_L2_R_T1_EPS );
HSVC_LOAD_ATTR( ATTR_L2_R_T2_EPS );
HSVC_LOAD_ATTR( ATTR_L2_W_EPS );
HSVC_LOAD_ATTR( ATTR_L3_FORCE_R_T2_EPS );
HSVC_LOAD_ATTR( ATTR_L3_R_T0_EPS );
HSVC_LOAD_ATTR( ATTR_L3_R_T1_EPS );
HSVC_LOAD_ATTR( ATTR_L3_R_T2_EPS );
HSVC_LOAD_ATTR( ATTR_L3_W_EPS );
// -- Input: ../../xml/attribute_info/p8_xip_customize_attributes.xml --
HSVC_LOAD_ATTR( ATTR_SBE_IMAGE_MINIMUM_VALID_EXS );
// -- Input: ../../xml/attribute_info/pm_hwp_attributes.xml --
HSVC_LOAD_ATTR( ATTR_PM_GLOBAL_FIR_TRACE_EN );
HSVC_LOAD_ATTR( ATTR_PM_PCBS_FSM_TRACE_EN );
HSVC_LOAD_ATTR( ATTR_PM_SLW_CONTROL_VECTOR_OFFSET );
HSVC_LOAD_ATTR( ATTR_PM_SLW_DEEP_SLEEP_EXIT_GOOD_HALT_ADDR );
HSVC_LOAD_ATTR( ATTR_PM_SLW_DEEP_WINKLE_EXIT_GOOD_HALT_ADDR );
// -- Input: ../../xml/attribute_info/pm_plat_attributes.xml --
HSVC_LOAD_ATTR( ATTR_CPM_TURBO_BOOST_PERCENT );
HSVC_LOAD_ATTR( ATTR_FREQ_CORE_MAX );
HSVC_LOAD_ATTR( ATTR_PM_EXTERNAL_VRM_STEPDELAY );
HSVC_LOAD_ATTR( ATTR_PM_EXTERNAL_VRM_STEPSIZE );
HSVC_LOAD_ATTR( ATTR_PM_RESONANT_CLOCK_FULL_CLOCK_SECTOR_BUFFER_FREQUENCY );
HSVC_LOAD_ATTR( ATTR_PM_RESONANT_CLOCK_HIGH_BAND_LOWER_FREQUENCY );
HSVC_LOAD_ATTR( ATTR_PM_RESONANT_CLOCK_HIGH_BAND_UPPER_FREQUENCY );
HSVC_LOAD_ATTR( ATTR_PM_RESONANT_CLOCK_LOW_BAND_LOWER_FREQUENCY );
HSVC_LOAD_ATTR( ATTR_PM_RESONANT_CLOCK_LOW_BAND_UPPER_FREQUENCY );
HSVC_LOAD_ATTR( ATTR_PM_SAFE_FREQUENCY );
HSVC_LOAD_ATTR( ATTR_PM_SPIPSS_FREQUENCY );
HSVC_LOAD_ATTR( ATTR_PM_SPIVID_FREQUENCY );
HSVC_LOAD_ATTR( ATTR_PM_SYSTEM_IVRMS_ENABLED );
HSVC_LOAD_ATTR( ATTR_PM_SYSTEM_IVRM_VPD_MIN_LEVEL );
HSVC_LOAD_ATTR( ATTR_PROC_R_DISTLOSS_VCS );
HSVC_LOAD_ATTR( ATTR_PROC_R_DISTLOSS_VDD );
HSVC_LOAD_ATTR( ATTR_PROC_R_LOADLINE_VCS );
HSVC_LOAD_ATTR( ATTR_PROC_R_LOADLINE_VDD );
HSVC_LOAD_ATTR( ATTR_PROC_VRM_VOFFSET_VCS );
HSVC_LOAD_ATTR( ATTR_PROC_VRM_VOFFSET_VDD );
// -- Input: ../../xml/attribute_info/poreve_memory_attributes.xml --
// No attributes found
// -- Input: ../../xml/attribute_info/proc_chip_ec_feature.xml --
// No attributes found
// -- Input: ../../xml/attribute_info/proc_fab_smp_fabric_attributes.xml --
HSVC_LOAD_ATTR( ATTR_FREQ_CORE );
HSVC_LOAD_ATTR( ATTR_PROC_EPS_GB_DIRECTION );
HSVC_LOAD_ATTR( ATTR_PROC_EPS_GB_PERCENTAGE );
HSVC_LOAD_ATTR( ATTR_PROC_FABRIC_ASYNC_SAFE_MODE );
// -- Input: ../../xml/attribute_info/proc_pll_ring_attributes.xml --
// No attributes found
// -- Input: ../../xml/attribute_info/proc_setup_bars_l3_attributes.xml --
// No attributes found
// -- Input: ../../xml/attribute_info/proc_winkle_scan_override_attributes.xml --
HSVC_LOAD_ATTR( ATTR_PROC_PBIEX_ASYNC_SEL );
// -- Input: ../../xml/attribute_info/scratch_attributes.xml --
HSVC_LOAD_ATTR( ATTR_DUMMY_SCRATCH_PLAT_INIT_UINT8 );
HSVC_LOAD_ATTR( ATTR_SCRATCH_UINT32_1 );
HSVC_LOAD_ATTR( ATTR_SCRATCH_UINT32_2 );
HSVC_LOAD_ATTR( ATTR_SCRATCH_UINT32_ARRAY_1 );
HSVC_LOAD_ATTR( ATTR_SCRATCH_UINT32_ARRAY_2 );
HSVC_LOAD_ATTR( ATTR_SCRATCH_UINT64_1 );
HSVC_LOAD_ATTR( ATTR_SCRATCH_UINT64_2 );
HSVC_LOAD_ATTR( ATTR_SCRATCH_UINT64_ARRAY_1 );
HSVC_LOAD_ATTR( ATTR_SCRATCH_UINT64_ARRAY_2 );
HSVC_LOAD_ATTR( ATTR_SCRATCH_UINT8_1 );
HSVC_LOAD_ATTR( ATTR_SCRATCH_UINT8_2 );
HSVC_LOAD_ATTR( ATTR_SCRATCH_UINT8_ARRAY_1 );
HSVC_LOAD_ATTR( ATTR_SCRATCH_UINT8_ARRAY_2 );
// -- Input: ../../xml/attribute_info/system_attributes.xml --
HSVC_LOAD_ATTR( ATTR_ALL_MCS_IN_INTERLEAVING_GROUP );
HSVC_LOAD_ATTR( ATTR_BOOT_FREQ_MHZ );
HSVC_LOAD_ATTR( ATTR_BOOT_VOLTAGE );
HSVC_LOAD_ATTR( ATTR_DISABLE_I2C_ACCESS );
HSVC_LOAD_ATTR( ATTR_EXECUTION_PLATFORM );
HSVC_LOAD_ATTR( ATTR_EX_GARD_BITS );
HSVC_LOAD_ATTR( ATTR_IS_MPIPL );
HSVC_LOAD_ATTR( ATTR_IS_SIMULATION );
HSVC_LOAD_ATTR( ATTR_MEM_FILTER_PLL_SOURCE );
HSVC_LOAD_ATTR( ATTR_MNFG_FLAGS );
HSVC_LOAD_ATTR( ATTR_MULTI_SCOM_BUFFER_MAX_SIZE );
HSVC_LOAD_ATTR( ATTR_NEST_FREQ_MHZ );
HSVC_LOAD_ATTR( ATTR_PCI_REFCLOCK_RCVR_TERM );
HSVC_LOAD_ATTR( ATTR_PIB_I2C_NEST_PLL );
HSVC_LOAD_ATTR( ATTR_PIB_I2C_REFCLOCK );
HSVC_LOAD_ATTR( ATTR_PM_HWP_ATTR_VERSION );
HSVC_LOAD_ATTR( ATTR_PROC_EPS_TABLE_TYPE );
HSVC_LOAD_ATTR( ATTR_PROC_FABRIC_PUMP_MODE );
HSVC_LOAD_ATTR( ATTR_PROC_REFCLOCK_RCVR_TERM );
HSVC_LOAD_ATTR( ATTR_PROC_X_BUS_WIDTH );
HSVC_LOAD_ATTR( ATTR_RECONFIGURE_LOOP );
HSVC_LOAD_ATTR( ATTR_RISK_LEVEL );
HSVC_LOAD_ATTR( ATTR_SBE_IMAGE_OFFSET );
// -- Input: ../../xml/attribute_info/unit_attributes.xml --
// No attributes found
