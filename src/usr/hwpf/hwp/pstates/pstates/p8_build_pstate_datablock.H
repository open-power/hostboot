/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pstates/pstates/p8_build_pstate_datablock.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
// $Id: p8_build_pstate_datablock.H,v 1.9 2013/09/17 16:43:44 jimyac Exp $
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

// #V 2 dimensional array values (5x5) - 5 operating point and 5 values per operating point
#define PV_D 5
#define PV_W 5

// order of operating points from slow to fast in #V 
// 1=pwrsave 0=nominal 2=turbo
const uint8_t pv_op_order[S132A_POINTS] = {1, 0, 2}; 
#define PV_OP_ORDER {1, 0, 2}

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
  
  uint32_t attr_proc_r_loadline;                                        // = 0;          // Impedance (binary in microOhms)
  uint32_t attr_proc_r_distloss;                                        // = 0;          // Impedance (binary in microOhms)
  uint32_t attr_proc_vrm_voffset;                                       // = 0;          // Offset voltage (binary in microvolts)

  uint32_t attr_freq_proc_refclock;                                     // = 133333 ;    //  Khz
  uint32_t attr_proc_dpll_divider;                                      // = 4;
  uint32_t attr_cpm_turbo_boost_percent;                                                 // binary in 0.1 percent steps
  uint32_t attr_cpm_inflection_points[16];  
  uint32_t attr_freq_ext_bias_up;                                       // = 0;
  uint32_t attr_freq_ext_bias_down;                                     // = 0;
  uint32_t attr_voltage_ext_bias_up;                                    // = 0;
  uint32_t attr_voltage_ext_bias_down;                                  // = 0;
  uint32_t attr_voltage_int_bias_up;                                    // = 0;
  uint32_t attr_voltage_int_bias_down;                                  // = 0;

  uint32_t attr_dpll_bias;
  uint32_t attr_undervolting;
  uint8_t  attr_pm_safe_frequency;                                         
  uint32_t attr_boot_freq_mhz;
    
  uint32_t attr_pm_resonant_clock_full_clock_sector_buffer_frequency;   // = 0; // Mhz
  uint32_t attr_pm_resonant_clock_low_band_lower_frequency;             // = 0; // Mhz
  uint32_t attr_pm_resonant_clock_low_band_upper_frequency;             // = 0; // Mhz
  uint32_t attr_pm_resonant_clock_high_band_lower_frequency;            // = 0; // Mhz
  uint32_t attr_pm_resonant_clock_high_band_upper_frequency;            // = 0; // Mhz

} AttributeList;

#endif
