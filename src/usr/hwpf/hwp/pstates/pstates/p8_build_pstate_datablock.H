/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pstates/pstates/p8_build_pstate_datablock.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: p8_build_pstate_datablock.H,v 1.14 2014/05/27 15:33:49 daviddu Exp $
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

fapi::ReturnCode p8_build_pstate_datablock(const fapi::Target& i_target, PstateSuperStructure *io_pss);

} // extern "C"

#define S132A_POINTS       3
#define PSTATE_STEPSIZE    1
#define EVRM_DELAY_NS      100
#define DEAD_ZONE_5MV      20
#define PDV_BUFFER_SIZE    51
#define PDM_BUFFER_SIZE    105
#define BIAS_PCT_UNIT      0.005
#define BOOST_PCT_UNIT     0.001
#define POUNDM_POINTS      13

// #V 2 dimensional array values (5x5) - 5 operating point and 5 values per operating point
#define PV_D 5
#define PV_W 5

// order of operating points from slow to fast in #V
// 1=pwrsave 0=nominal 2=turbo
#define PV_OP_ORDER     {1, 0, 2}
#define PV_OP_ORDER_STR {"nominal", "powersave", "turbo"}

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

} AttributeList;

#endif
