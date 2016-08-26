/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pstate_parameter_block.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file  p9_pstate_parameter_block.H
/// @brief Definitons of paramater information used to process pstates
///
// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
// *HWP HW Owner        : Michael Floyd <mfloyd@us.ibm.com>
// *HWP FW Owner        : Martha Broyles <mbroyles@us.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : PGPE, OCC

#ifndef __P9_PSTATE_PARAMETER_BLOCK_H__
#define __P9_PSTATE_PARAMETER_BLOCK_H__

#include <p9_pstates.h>

// ssrivath- See if this is required
#ifdef __cplusplus
extern "C" {
#endif

//ssrivath, Also defined in p9_pstates.h
// can remove from here if below structure is moved to p9_pstates.h
#define MAX_ACTIVE_CORES 24

/// An internal operating point
///
/// Internal operating points include characterization (both the original,
/// unbiased values and biased by external attributes) and load-line corrected
/// voltages for the external VRM.  For the internal VRM, effective e-voltages
/// and maxreg voltages are stored.  All voltages are stored as
/// uV. Characterization currents are in mA. Frequencies are in KHz. The
/// Pstate of the operating point (as a potentially out-of-bounds value) is
/// also stored.

typedef struct
{

    uint32_t vdd_uv;
    uint32_t vcs_uv;
    uint32_t vdd_corrected_uv;
    uint32_t vcs_corrected_uv;
    uint32_t vdd_corrected_wof_uv[MAX_ACTIVE_CORES];
    uint32_t vcs_corrected_wof_uv[MAX_ACTIVE_CORES];
    uint32_t vdd_ivrm_effective_uv;
    uint32_t vcs_ivrm_effective_uv;
    uint32_t vdd_maxreg_uv;
    uint32_t vcs_maxreg_uv;
    uint32_t idd_ma;
    uint32_t ics_ma;
    uint32_t frequency_khz;
    int32_t  pstate;

} OperatingPoint;


/// Constants required to compute and interpolate operating points
///
/// The nominal frequency and frequency step-size is given in Hz. Load-line
/// and on-chip distribution resistances are given in micro-Ohms.
///
/// \todo Confirm that the "eVID V[dd,cs] Eff" correction is modeled as a simple
/// resistance similar to the load line.

typedef struct
{

    uint32_t reference_frequency_khz;
    uint32_t frequency_step_khz;   // This is the reference frequency / DPPL_DIVIDER
    // Load line parameters, This is also called Rloadline
    uint32_t vdd_r_loadline_uohm;
    uint32_t vcs_r_loadline_uohm;
    uint32_t vdn_r_loadline_uohm;
    // Distribution loss parameters, This is also called Rpath
    uint32_t vdd_r_distloss_uohm;
    uint32_t vcs_r_distloss_uohm;
    uint32_t vdn_r_distloss_uohm;
    uint32_t vdd_voffset_uv;
    uint32_t vcs_voffset_uv;
    uint32_t vdn_voffset_uv;
} SystemParameters;


/// A chip characterization

typedef struct
{

    VpdOperatingPoint* vpd;
    VpdOperatingPoint* vpd_unbiased;
    OperatingPoint* ops;
    SystemParameters* parameters;
    uint32_t points;
    uint32_t max_cores;                     // Needed for WOF

} ChipCharacterization;


//Section added back by ssrivath
// START OF PARMS REQUIRED VPD parsing procedures
//#define S132A_POINTS       4 - Replaced by  VPD_PV_POINTS
#define PSTATE_STEPSIZE    1
#define EVRM_DELAY_NS      100
#define DEAD_ZONE_5MV      20       // 100mV
#define PDV_BUFFER_SIZE    51
#define PDV_BUFFER_ALLOC   512

//#define PDM_BUFFER_SIZE    105
#define PDM_BUFFER_SIZE    257      // Value is for version 3 @ 256 + 1 for version number
#define PDM_BUFFER_ALLOC   513      // Value is for version 2 @ 512 + 1 for version number
//#define BIAS_PCT_UNIT      0.005
#define BIAS_PCT_UNIT      0.5
#define BOOST_PCT_UNIT     0.001
#define POUNDM_POINTS      13
#define POUNDM_MEASUREMENTS_PER_POINT   4

// #V 2 dimensional array values (5x5) - 5 operating point and 5 values per operating point
#define PV_D 5
#define PV_W 5

// Replaced by VPD_PV_ORDER_STR
//// order of operating points from slow to fast in #V
//// 1=pwrsave 0=nominal 2=turbo. 3=ultraturbo
//#define PV_OP_ORDER             {1, 0, 2, 3}
//#define PV_OP_ORDER_STR         {"Nominal", "PowerSave", "Turbo", "UltraTurbo"}
//#define PV_OP_ORDER_MIN_VALID   {1, 1, 1, 0}

// IQ Keyword Sizes
#define IQ_BUFFER_SIZE      9
//#define IQ_BUFFER_ALLOC     64
#define IQ_BUFFER_ALLOC     255
// END OF PARMS REQUIRED VPD parsing procedures


// Structure contatining all attributes required by Pstate Parameter block
typedef struct
{

    //uint32_t attr_freq_core_max; - P8 attribute
    uint32_t attr_freq_core_ceiling_mhz;

// Loadline, Distribution loss and Distribution offset attributes
    uint32_t attr_proc_r_loadline_vdd_uohm;
    uint32_t attr_proc_r_distloss_vdd_uohm;
    uint32_t attr_proc_vrm_voffset_vdd_uv;
    uint32_t attr_proc_r_loadline_vdn_uohm;
    uint32_t attr_proc_r_distloss_vdn_uohm;
    uint32_t attr_proc_vrm_voffset_vdn_uv;
    uint32_t attr_proc_r_loadline_vcs_uohm;
    uint32_t attr_proc_r_distloss_vcs_uohm;
    uint32_t attr_proc_vrm_voffset_vcs_uv;

//  uint32_t attr_freq_proc_refclock;
    uint32_t attr_freq_proc_refclock_khz;
    uint32_t attr_proc_dpll_divider;

// Frequency Bias attributes
    int8_t attr_freq_bias_ultraturbo;
    int8_t attr_freq_bias_turbo;
    int8_t attr_freq_bias_nominal;
    int8_t attr_freq_bias_powersave;

// Voltage Bias attributes
    int8_t attr_voltage_ext_vdd_bias_ultraturbo;
    int8_t attr_voltage_ext_vdd_bias_turbo;
    int8_t attr_voltage_ext_vdd_bias_nominal;
    int8_t attr_voltage_ext_vdd_bias_powersave;
    int8_t attr_voltage_ext_vcs_bias;
    int8_t attr_voltage_ext_vdn_bias;

    int8_t attr_voltage_int_vdd_bias_ultraturbo;
    int8_t attr_voltage_int_vdd_bias_turbo;
    int8_t attr_voltage_int_vdd_bias_nominal;
    int8_t attr_voltage_int_vdd_bias_powersave;

    uint32_t attr_dpll_bias;
    uint32_t attr_undervolting;
    uint32_t attr_pm_safe_frequency_mhz;
    uint32_t attr_pm_safe_voltage_mv;

//  uint32_t attr_freq_core_floor;
    uint32_t attr_freq_core_floor_mhz;
    uint32_t attr_boot_freq_mhz;

// Resonant clock frequency attrmbutes
    uint32_t attr_pm_resonant_clock_full_clock_sector_buffer_frequency_khz;
    uint32_t attr_pm_resonant_clock_low_band_lower_frequency_khz;
    uint32_t attr_pm_resonant_clock_low_band_upper_frequency_khz;
    uint32_t attr_pm_resonant_clock_high_band_lower_frequency_khz;
    uint32_t attr_pm_resonant_clock_high_band_upper_frequency_khz;

    uint8_t  attr_system_wof_enabled;
    uint8_t  attr_system_ivrms_enabled;
    uint32_t attr_tdp_rdp_current_factor;

    uint8_t attr_resclk_enable;
    uint8_t attr_dpll_dynamic_fmax_enable;
    uint8_t attr_dpll_dynamic_fmin_enable;
    uint8_t attr_dpll_droop_protect_enable;


} AttributeList;

// Start of function declarations

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------

/// ----------------------------------------------------------------
/// @brief Get #V data and put into array
/// @param[i] i_target            Chip Target
/// @param[o] o_attr_mvpd_data    5x5 array to hold the #V data
/// @param[o] o_valid_pdv_points  No of Valid VPD points
/// @param[o] o_present_chiplets  No of functional chiplets
/// @return   FAPI2::SUCCESS
/// ----------------------------------------------------------------
fapi2::ReturnCode
proc_get_mvpd_data ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                     uint32_t o_attr_mvpd_data[PV_D][PV_W],
                     uint32_t* o_valid_pdv_points,
                     uint8_t* o_present_chiplets );

/// -------------------------------------------------------------------
/// @brief Perform data validity check on #V data
/// @param[i] i_chiplet_mvpd_data Pointer to array of #V data
/// @param[o] o_valid_pdv_points  No of Valid VPD points
/// @param[o] i_chiplet_num       Chiplet number
/// @param[o] i_bucket_id     Bucket ID
/// @return   FAPI2::SUCCESS
/// -------------------------------------------------------------------

fapi2::ReturnCode
proc_chk_valid_poundv ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                        const uint32_t i_chiplet_mvpd_data[PV_D][PV_W],
                        uint32_t* o_valid_pdv_points,
                        const uint8_t i_chiplet_num,
                        const uint8_t i_bucket_id);


/// ----------------------------------------------------------------
/// @brief Get IQ (IDDQ) data and put into array
/// @param[in]    i_target          => Chip Target
/// @param[inout] iddqt             => IDDQ table to hold MVPD IDDQ data
/// @return   FAPI2::SUCCESS
/// ----------------------------------------------------------------

fapi2::ReturnCode
proc_get_mvpd_iddq ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                     IddqTable* io_iddqt);

/// -----------------------------------------------------------------------
/// @brief Get needed attributes
/// @param[in]    i_target          => Chip Target
/// @param[inout] io_attr           => pointer to attribute list structure
/// @return   FAPI2::SUCCESS
/// -----------------------------------------------------------------------

fapi2::ReturnCode
proc_get_attributes ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                      AttributeList* io_attr);

/// ---------------------------------------------------------------------------
/// @brief Check and process #V bias attributes for external and internal
/// @param[inout]    io_attr_mvpd_data       => 5x5 array to hold the #V data
/// @param[in]    *  i_attr                  => pointer to attribute list structure
/// @param[out]   *  o_vpdbias               => Voltage/Frequency bias values
/// @return   FAPI2::SUCCESS
/// ---------------------------------------------------------------------------

fapi2::ReturnCode
proc_get_extint_bias ( uint32_t io_attr_mvpd_data[PV_D][PV_W],
                       const AttributeList* i_attr,
                       VpdBias o_vpdbias[VPD_PV_POINTS] );

/// -------------------------------------------------------------------
/// @brief Boost max frequency in pstate table based on boost attribute
/// @param[inout] *io_pss   => pointer to pstate superstructure
/// @param[in]    i_attr_boost_percent  => Boost percentage attribute
/// @return   FAPI2::SUCCESS
/// -------------------------------------------------------------------

fapi2::ReturnCode
proc_boost_gpst ( PstateSuperStructure* io_pss,
                  uint32_t i_attr_boost_percent);

/// ------------------------------------------------------------
/// @brief Update Psafe_pstate
/// @param[inout] *io_pss   => pointer to pstate superstructure
/// @param[in]    *i_attr  => pointer to attribute list structure
/// @return   FAPI2::SUCCESS
/// ------------------------------------------------------------

fapi2::ReturnCode
proc_upd_psafe_ps ( PstateSuperStructure* io_pss,
                    const AttributeList* i_attr);

/// ------------------------------------------------------------
/// @brief Update Floor_pstate
/// @param[inout] *io_pss   => pointer to pstate superstructure
/// @param[in]    *i_attr  => pointer to attribute list structure
/// @return   FAPI2::SUCCESS
/// ------------------------------------------------------------

fapi2::ReturnCode
proc_upd_floor_ps ( PstateSuperStructure* io_pss,
                    const AttributeList* i_attr);

/// -------------------------------------------------------------------
/// @brief Convert Resonant Clocking attributes to pstate values and update superstructure with those values
/// @param[inout] *io_pss   => pointer to pstate superstructure
/// @param[in]    *i_attr  => pointer to attribute list structure
/// @return   FAPI2::SUCCESS
/// -------------------------------------------------------------------

fapi2::ReturnCode
proc_res_clock    ( PstateSuperStructure* io_pss,
                    AttributeList* i_attr);

/// ------------------------------------------------------------
/// @brief Populate a subset of the WOFElements structure from Attributes
/// @param[inout] *io_pss   => pointer to pstate superstructure
/// @param[in]    *i_attr  => pointer to attribute list structure
/// @return   FAPI2::SUCCESS
/// ------------------------------------------------------------

fapi2::ReturnCode
load_wof_attributes ( PstateSuperStructure* io_pss,
                      const AttributeList* i_attr);

/// ------------------------------------------------------------
/// @brief Copy VPD operating point into destination in assending order
/// @param[in]    i_src[VPD_PV_POINTS]   => Source VPD structure (array)
/// @param[out] * o_dest[VPD_PV_POINTS]  => pointer to destination VpdOperatingPoint structure
/// @return   FAPI2::SUCCESS
/// ------------------------------------------------------------

fapi2::ReturnCode
load_mvpd_operating_point ( const uint32_t i_src[PV_D][PV_W],
                            VpdOperatingPoint* o_dest);

/// ----------------------------------------------------------------
/// @brief Get VDM parameters from attributes
/// @param[in]    i_target          => Chip Target
/// @param[out]   o_vdmpb           => VDM parameter block
/// @return   FAPI2::SUCCESS
/// ----------------------------------------------------------------

fapi2::ReturnCode
proc_get_vdm_parms ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                     VDMParmBlock* o_vdmpb);

/// ----------------------------------------------------------------
/// @brief Get resonant clocking parameters from attributes
/// @param[in]    i_target          => Chip Target
/// @param[out]   o_resclk_setup    => Resonant clocking setup
/// @return   FAPI2::SUCCESS
/// ----------------------------------------------------------------

fapi2::ReturnCode
proc_res_clock_setup ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                       ResonantClockingSetup* o_resclk_setup);

/// ----------------------------------------------------------------
/// @brief Get IVRM parameters from attributes
/// @param[in]    i_target          => Chip Target
/// @param[out]   o_ivrmpb          => IVRM parameter block
/// @return   FAPI2::SUCCESS
/// ----------------------------------------------------------------

fapi2::ReturnCode
proc_get_ivrm_parms ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                      IvrmParmBlock* o_ivrmpb);

/// @typedef p9_pstate_parameter_block_FP_t
/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pstate_parameter_block_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    PstateSuperStructure*);

extern "C"
{

/// -------------------------------------------------------------------
/// @brief Populate Pstate super structure from VPD data
/// @param[in]    i_target          => Chip Target
/// @param[inout] *io_pss           => pointer to pstate superstructure
/// @return   FAPI2::SUCCESS
/// -------------------------------------------------------------------
    fapi2::ReturnCode
    p9_pstate_parameter_block( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                               PstateSuperStructure* io_pss);

} // extern C


// End of function declarations

// ssrivath- See if this is required
#ifdef __cplusplus
} // end extern C
#endif

#endif  // __P9_PSTATE_PARAMETER_BLOCK_H__
