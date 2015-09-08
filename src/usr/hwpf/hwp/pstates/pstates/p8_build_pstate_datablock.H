/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pstates/pstates/p8_build_pstate_datablock.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: p8_build_pstate_datablock.H,v 1.15 2015/05/13 03:12:36 stillgs Exp $
#ifndef _P8_BUILD_PSTATE_DATABLOCK_H_
#define _P8_BUILD_PSTATE_DATABLOCK_H_

#include <fapi.H>

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_build_pstate_datablock_FP_t) (const fapi::Target&, PstateSuperStructure*);

extern "C" {

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
/// \brief Build Pstate Tables
/// \param[in]     i_target            Chip Target
/// \param[in/out] *io_pss             Reference to PstateSuperStructure

fapi::ReturnCode 
p8_build_pstate_datablock(const fapi::Target& i_target, PstateSuperStructure *io_pss);

} // extern "C"

#define S132A_POINTS       4
#define PSTATE_STEPSIZE    1
#define EVRM_DELAY_NS      100
#define DEAD_ZONE_5MV      20       // 100mV
#define PDV_BUFFER_SIZE    51
#define PDV_BUFFER_ALLOC   512

//#define PDM_BUFFER_SIZE    105
#define PDM_BUFFER_SIZE    257      // Value is for version 3 @ 256 + 1 for version number
#define PDM_BUFFER_ALLOC   513      // Value is for version 2 @ 512 + 1 for version number
#define BIAS_PCT_UNIT      0.005
#define BOOST_PCT_UNIT     0.001
#define POUNDM_POINTS      13
#define POUNDM_MEASUREMENTS_PER_POINT   4

// #V 2 dimensional array values (5x5) - 5 operating point and 5 values per operating point
#define PV_D 5
#define PV_W 5

// order of operating points from slow to fast in #V
// 1=pwrsave 0=nominal 2=turbo. 3=ultraturbo
#define PV_OP_ORDER             {1, 0, 2, 3}
#define PV_OP_ORDER_STR         {"Nominal", "PowerSave", "Turbo", "UltraTurbo"}
#define PV_OP_ORDER_MIN_VALID   {1, 1, 1, 0}

// IQ Keyword Sizes
#define IQ_BUFFER_SIZE      9
#define IQ_BUFFER_ALLOC     64 
 
typedef struct {
  uint32_t attr_freq_core_max;
  uint32_t attr_proc_r_loadline_vdd;
  uint32_t attr_proc_r_loadline_vcs;
  uint32_t attr_proc_r_distloss_vdd;
  uint32_t attr_proc_r_distloss_vcs;
  uint32_t attr_proc_vrm_voffset_vdd;
  uint32_t attr_proc_vrm_voffset_vcs;
  uint32_t attr_voltage_ext_vdd_bias_up;
  uint32_t attr_voltage_ext_vcs_bias_up;
  uint32_t attr_voltage_ext_vdd_bias_down;
  uint32_t attr_voltage_ext_vcs_bias_down;
  uint32_t attr_voltage_int_vdd_bias_up;
  uint32_t attr_voltage_int_vcs_bias_up;
  uint32_t attr_voltage_int_vdd_bias_down;
  uint32_t attr_voltage_int_vcs_bias_down ;

  uint32_t attr_freq_proc_refclock;
  uint32_t attr_proc_dpll_divider;
  uint32_t attr_cpm_turbo_boost_percent;
  uint32_t attr_cpm_inflection_points[16];
  uint32_t attr_freq_ext_bias_up;
  uint32_t attr_freq_ext_bias_down;
  uint32_t attr_voltage_ext_bias_up;
  uint32_t attr_voltage_ext_bias_down;
  uint32_t attr_voltage_int_bias_up;
  uint32_t attr_voltage_int_bias_down;

  uint32_t attr_dpll_bias;
  uint32_t attr_undervolting;
  uint32_t attr_pm_safe_frequency;
  uint32_t attr_freq_core_floor;
  uint32_t attr_boot_freq_mhz;

  uint32_t attr_pm_resonant_clock_full_clock_sector_buffer_frequency;
  uint32_t attr_pm_resonant_clock_low_band_lower_frequency;
  uint32_t attr_pm_resonant_clock_low_band_upper_frequency;
  uint32_t attr_pm_resonant_clock_high_band_lower_frequency;
  uint32_t attr_pm_resonant_clock_high_band_upper_frequency;

  uint8_t  attr_chip_ec_feature_resonant_clk_valid;
  uint8_t  attr_proc_ec_core_hang_pulse_bug;
  uint8_t  attr_chip_ec_feature_ivrm_winkle_bug;
  uint8_t  attr_pm_system_ivrms_enabled;
  uint8_t  attr_pm_system_ivrm_vpd_min_level;  
  
  uint8_t  attr_wof_enabled; 
  uint32_t attr_tdp_rdp_current_factor; 

} AttributeList;

#endif
