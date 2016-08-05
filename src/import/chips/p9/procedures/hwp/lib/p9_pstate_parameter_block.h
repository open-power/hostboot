/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_pstate_parameter_block.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file  p9_pstate_parameter_block.h
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
    uint32_t vdd_load_line_uohm;
    uint32_t vcs_load_line_uohm;
    uint32_t vdn_load_line_uohm;
    uint32_t vdd_distribution_uohm;
    uint32_t vcs_distribution_uohm;
    uint32_t vdn_distribution_uohm;
    uint32_t vdd_voffset_uv;
    uint32_t vcs_voffset_uv;
    uint32_t vdn_voffset_uv;
} OperatingPointParameters;


/// A chip characterization

typedef struct
{

    VpdOperatingPoint* vpd;
    VpdOperatingPoint* vpd_unbiased;
    OperatingPoint* ops;
    OperatingPointParameters* parameters;
    uint32_t points;
    uint32_t max_cores;                     // Needed for WOF

} ChipCharacterization;


/// @todo IVRM structures based no an HCode design are not complete
/// The following is the P8 structure for reference.
typedef struct IVRM_PARM_DATA
{
    uint32_t vin_min;                   // Minimum input voltage
    uint32_t vin_max;                   // Maximum input voltage
    uint32_t vin_table_step_size;       // Granularity of Vin table entries
    uint32_t vin_table_setsperrow;      // Vin sets per Vds row
    uint32_t vin_table_pfetstrperset;   // PFET Strength values per Vin set
    uint32_t vout_min;                  // Minimum regulated output voltage
    uint32_t vout_max;                  // Maximum regulated output voltage
    uint32_t vin_entries_per_vds;       // Vin array entries per vds region
    uint32_t vds_min_range_upper_bound; // Starting point for vds regions
    uint32_t vds_step_percent;          // vds region step muliplier
    uint32_t vds_region_entries;        // vds region array entries (in hardware)
    uint32_t pfetstr_default;           // Default PFET Strength with no calibration
    uint32_t positive_guardband;        // Plus side guardband (%)
    uint32_t negative_guardband;        // Negative side guardband (%)
    uint32_t number_of_coefficients;    // Number of coefficents in cal data
    uint32_t force_pfetstr_values;      // 0 - calculated; 1 = forced
    uint32_t forced_pfetstr_value;      // If force_pfetstr_values = 1, use this value
    // 5b value used as it to fill in all entries
} ivrm_parm_data_t;

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
#define IQ_BUFFER_ALLOC     64
// END OF PARMS REQUIRED VPD parsing procedures


// Structure contatining all attributes required by Pstate Parameter block
typedef struct
{
    uint32_t attr_freq_core_ceiling_mhz;

// Loadline, Distribution loss and Distribution offset attributes
//  uint32_t attr_proc_r_loadline_vdd;
//  uint32_t attr_proc_r_loadline_vcs;
//  uint32_t attr_proc_r_distloss_vdd;
//  uint32_t attr_proc_r_distloss_vcs;
//  uint32_t attr_proc_vrm_voffset_vdd;
//  uint32_t attr_proc_vrm_voffset_vcs;

    uint32_t attr_proc_r_loadline_vdd_uohm;
    uint32_t attr_proc_r_distloss_vdd_uohm;
    uint32_t attr_proc_vrm_voffset_vdd_uohm;
    uint32_t attr_proc_r_loadline_vdn_uohm;
    uint32_t attr_proc_r_distloss_vdn_uohm;
    uint32_t attr_proc_vrm_voffset_vdn_uohm;
    uint32_t attr_proc_r_loadline_vcs_uohm;
    uint32_t attr_proc_r_distloss_vcs_uohm;
    uint32_t attr_proc_vrm_voffset_vcs_uohm;

// Voltage Bias attributes
//  uint32_t attr_voltage_ext_vdd_bias_up;
//  uint32_t attr_voltage_ext_vcs_bias_up;
//  uint32_t attr_voltage_ext_vdd_bias_down;
//  uint32_t attr_voltage_ext_vcs_bias_down;
//  uint32_t attr_voltage_int_vdd_bias_up;
//  uint32_t attr_voltage_int_vcs_bias_up;
//  uint32_t attr_voltage_int_vdd_bias_down;
//  uint32_t attr_voltage_int_vcs_bias_down ;

//  uint32_t attr_freq_proc_refclock;
    uint32_t attr_freq_proc_refclock_khz;
    uint32_t attr_proc_dpll_divider;
    uint32_t attr_cpm_turbo_boost_percent;
    uint32_t attr_cpm_inflection_points[16];

// Frequency Bias attributes
//  uint32_t attr_freq_ext_bias_up;
//  uint32_t attr_freq_ext_bias_down;

    int32_t attr_freq_ext_bias_ultraturbo;
    int32_t attr_freq_ext_bias_turbo;
    int32_t attr_freq_ext_bias_nominal;
    int32_t attr_freq_ext_bias_powersave;

// Voltage Bias attributes
//  uint32_t attr_voltage_ext_bias_up;
//  uint32_t attr_voltage_ext_bias_down;
//  uint32_t attr_voltage_int_bias_up;
//  uint32_t attr_voltage_int_bias_down;

    int32_t attr_voltage_vdd_bias_ultraturbo;
    int32_t attr_voltage_vdd_bias_turbo;
    int32_t attr_voltage_vdd_bias_nominal;
    int32_t attr_voltage_vdd_bias_powersave;
    int32_t attr_voltage_vcs_bias;
    int32_t attr_voltage_vdn_bias;
    int32_t attr_voltage_int_vdd_bias;

    uint32_t attr_dpll_bias;
    uint32_t attr_undervolting;
    uint32_t attr_pm_safe_frequency_mhz;

//  uint32_t attr_freq_core_floor;
    uint32_t attr_freq_core_floor_mhz;
    uint32_t attr_boot_freq_mhz;

// Resonant clock frequency attrmbutes
//  uint32_t attr_pm_resonant_clock_full_clock_sector_buffer_frequency;
//  uint32_t attr_pm_resonant_clock_low_band_lower_frequency;
//  uint32_t attr_pm_resonant_clock_low_band_upper_frequency;
//  uint32_t attr_pm_resonant_clock_high_band_lower_frequency;
//  uint32_t attr_pm_resonant_clock_high_band_upper_frequency;

    uint32_t attr_pm_resonant_clock_full_clock_sector_buffer_frequency_khz;
    uint32_t attr_pm_resonant_clock_low_band_lower_frequency_khz;
    uint32_t attr_pm_resonant_clock_low_band_upper_frequency_khz;
    uint32_t attr_pm_resonant_clock_high_band_lower_frequency_khz;
    uint32_t attr_pm_resonant_clock_high_band_upper_frequency_khz;

    uint8_t  attr_system_wof_enabled;
    uint8_t  attr_system_ivrms_enabled;
    uint32_t attr_tdp_rdp_current_factor;

// P8 attributes not needed in P9
//  uint8_t  attr_chip_ec_feature_resonant_clk_valid;
//  uint8_t  attr_proc_ec_core_hang_pulse_bug;
//  uint8_t  attr_chip_ec_feature_ivrm_winkle_bug;
//  uint8_t  attr_pm_system_ivrm_vpd_min_level;

} AttributeList;

//ssrivath, Start of function declarations

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------

/// ----------------------------------------------------------------
/// @brief Get #V data and put into array
/// @param[i] i_target          Chip Target
/// @param[i] attr_mvpd_data    6x5 array to hold the #V data
/// @return   FAPI2::SUCCESS
/// ----------------------------------------------------------------
fapi2::ReturnCode
proc_get_mvpd_data ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                     AttributeList* attr,
                     uint32_t attr_mvpd_data[PV_D][PV_W],
                     uint32_t* valid_pdv_points,
                     uint8_t* present_chiplets );

/// -------------------------------------------------------------------
/// @brief Perform data validity check on #V data
/// @param[i] poundv_data       pointer to array of #V data
/// @return   FAPI2::SUCCESS
/// -------------------------------------------------------------------

fapi2::ReturnCode
proc_chk_valid_poundv ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                        AttributeList* attr,
                        const uint32_t chiplet_mvpd_data[PV_D][PV_W],
                        uint32_t* valid_pdv_points,
                        uint8_t chiplet_num,
                        uint8_t bucket_id);


/// ----------------------------------------------------------------
/// @brief Get IQ (IDDQ) data and put into array
/// @param[in]    i_target          => Chip Target
/// @param[inout] attr_mvpd_iddq    => 24 x 16 array to hold the IQ data
/// @return   FAPI2::SUCCESS
/// ----------------------------------------------------------------

fapi2::ReturnCode
proc_get_mvpd_iddq ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                     PstateSuperStructure* pss);

/// -----------------------------------------------------------------------
/// @brief Get needed attributes
/// @param[in]    i_target          => Chip Target
/// @param[inout] attr              => pointer to attribute list structure
/// @return   FAPI2::SUCCESS
/// -----------------------------------------------------------------------

fapi2::ReturnCode
proc_get_attributes ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                      AttributeList* i_attr);

/// ---------------------------------------------------------------------------
/// @brief Check and process #V bias attributes for external and internal
/// @param[in]    attr_mvpd_data         => 5x5 array to hold the #V data
/// @param[in]    *attr                  => pointer to attribute list structure
/// @param[inout] * volt_int_vdd_bias    => pointer to internal vdd bias
/// @param[inout] * volt_int_vcs_bias    => pointer to internal vcs bias
/// @return   FAPI2::SUCCESS
/// ---------------------------------------------------------------------------

fapi2::ReturnCode
proc_get_extint_bias ( uint32_t attr_mvpd_data[PV_D][PV_W],
                       const AttributeList* attr,
                       double* volt_int_vdd_bias,
                       double* volt_int_vcs_bias);

/// -------------------------------------------------------------------
/// @brief Boost max frequency in pstate table based on boost attribute
/// @param[inout] *pss   => pointer to pstate superstructure
/// @param[in]    *attr  => pointer to attribute list structure
/// @return   FAPI2::SUCCESS
/// -------------------------------------------------------------------

fapi2::ReturnCode
proc_boost_gpst ( PstateSuperStructure* pss,
                  uint32_t attr_boost_percent);

/// ------------------------------------------------------------
/// @brief Update Psafe_pstate
/// @param[inout] *pss   => pointer to pstate superstructure
/// @param[in]    *attr  => pointer to attribute list structure
/// @return   FAPI2::SUCCESS
/// ------------------------------------------------------------

fapi2::ReturnCode
proc_upd_psafe_ps ( PstateSuperStructure* pss,
                    const AttributeList* attr);

/// ------------------------------------------------------------
/// @brief Update Floor_pstate
/// @param[inout] *pss   => pointer to pstate superstructure
/// @param[in]    *attr  => pointer to attribute list structure
/// @return   FAPI2::SUCCESS
/// ------------------------------------------------------------

fapi2::ReturnCode
proc_upd_floor_ps ( PstateSuperStructure* pss,
                    const AttributeList* attr);

/// -------------------------------------------------------------------
/// @brief Convert Resonant Clocking attributes to pstate values and update superstructure with those values
/// @param[inout] *pss   => pointer to pstate superstructure
/// @param[in]    *attr  => pointer to attribute list structure
/// @return   FAPI2::SUCCESS
/// -------------------------------------------------------------------

fapi2::ReturnCode
proc_res_clock    ( PstateSuperStructure* pss,
                    AttributeList* attr_list);

/// ------------------------------------------------------------
/// @brief Populate a subset of the WOFElements structure from Attributes
/// @param[inout] *pss   => pointer to pstate superstructure
/// @param[in]    *attr  => pointer to attribute list structure
/// @return   FAPI2::SUCCESS
/// ------------------------------------------------------------

fapi2::ReturnCode
load_wof_attributes ( PstateSuperStructure* pss,
                      const AttributeList* attr);

/// ------------------------------------------------------------
/// @brief Copy VPD operating point into destination in assending order
/// @param[in]  &src[VPD_PV_POINTS]   => reference to source VPD structure (array)
/// @param[out] *dest[VPD_PV_POINTS]  => pointer to destination VpdOperatingPoint structure
/// @return   FAPI2::SUCCESS
/// ------------------------------------------------------------

fapi2::ReturnCode
load_mvpd_operating_point ( const uint32_t src[PV_D][PV_W],
                            VpdOperatingPoint* dest);

/// ------------------------------------------------------------
/// @brief Update CPM Range table
/// @param[inout] *pss   => pointer to pstate superstructure
/// @param[in]    *attr  => pointer to attribute list structure
/// @return   FAPI2::SUCCESS
/// ------------------------------------------------------------

//fapi2::ReturnCode
//proc_upd_cpmrange ( PstateSuperStructure *pss,
//                    const AttributeList *attr);


/// @typedef p9_pstate_parameter_block_FP_t
/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pstate_parameter_block_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

extern "C"
{

/// -------------------------------------------------------------------
/// @brief Populate Pstate super structure from VPD data
/// @param[in]    i_target          => Chip Target
/// @param[inout] *pss              => pointer to pstate superstructure
/// @return   FAPI2::SUCCESS
/// -------------------------------------------------------------------
    fapi2::ReturnCode
    p9_pstate_parameter_block( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                               PstateSuperStructure* io_pss);

} // extern C


//ssrivath, End of function declarations

// ssrivath- See if this is required

#ifdef __cplusplus
} // end extern C
#endif

#endif  // __P9_PSTATE_PARAMETER_BLOCK_H__
