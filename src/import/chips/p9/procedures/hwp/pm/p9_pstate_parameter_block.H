/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pstate_parameter_block.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
// *HWP FW Owner        : Prasad Bg Ranganath <prasadbgr@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 3
// *HWP Consumed by     : PGPE, OCC

#ifndef __P9_PSTATE_PARAMETER_BLOCK_H__
#define __P9_PSTATE_PARAMETER_BLOCK_H__

#include <p9_pm_utils.H>
#include <p9_pstates_common.h>
#include <p9_pstates_pgpe.h>
#include <p9_pstates_cmeqm.h>
#include <p9_pstates_occ.h>
#include "p9_pm_get_poundv_bucket.H"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_ACTIVE_CORES 24

#define HOMER_WOF_TABLE_SIZE 258176

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


typedef struct
{
    bool iv_pstates_enabled;
    bool iv_resclk_enabled;
    bool iv_vdm_enabled;
    bool iv_ivrm_enabled;
    bool iv_wof_enabled;
} PSTATE_attribute_state;

// Safe mode frequency and voltage params

typedef struct
{
    uint32_t safe_op_freq_mhz;
    uint8_t  safe_op_ps;
    uint32_t safe_vdm_jump_value;
    uint32_t safe_mode_freq_mhz;
    uint8_t  safe_mode_ps;
    uint32_t safe_mode_mv;
    uint32_t boot_mode_mv;
} Safe_mode_parameters;


/// Constants required to compute and interpolate operating points
///
/// The nominal frequency and frequency step-size is given in Hz. Load-line
/// and on-chip distribution resistances are given in micro-Ohms.
///

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
#define PSTATE_STEPSIZE    1
#define EVRM_DELAY_NS      100
#define DEAD_ZONE_5MV      20       // 100mV
#define PDV_BUFFER_SIZE    51
#define PDV_BUFFER_ALLOC   512

#define POUND_W_VERSION_2_BUCKET_SIZE 60
#define PDM_BUFFER_SIZE    257      // Value is for version 3 @ 256 + 1 for version number
#define PDM_BUFFER_ALLOC   513      // Value is for version 2 @ 512 + 1 for version number
#define BIAS_PCT_UNIT      0.5
#define BOOST_PCT_UNIT     0.001
#define POUNDM_POINTS      13
#define POUNDM_MEASUREMENTS_PER_POINT   4

// #V 2 dimensional array values (5x5) - 5 operating point and 5 values per operating point
#define PV_D 5
#define PV_W 5

// IQ Keyword Sizes
#define IQ_BUFFER_SIZE      9
#define IQ_BUFFER_ALLOC     255
// END OF PARMS REQUIRED VPD parsing procedures


// Structure contatining all attributes required by Pstate Parameter block
typedef struct
{

    uint32_t attr_freq_core_ceiling_mhz;

// Loadline, Distribution loss and Distribution offset attVpdOpributes
    uint32_t attr_proc_r_loadline_vdd_uohm;
    uint32_t attr_proc_r_distloss_vdd_uohm;
    uint32_t attr_proc_vrm_voffset_vdd_uv;
    uint32_t attr_proc_r_loadline_vdn_uohm;
    uint32_t attr_proc_r_distloss_vdn_uohm;
    uint32_t attr_proc_vrm_voffset_vdn_uv;
    uint32_t attr_proc_r_loadline_vcs_uohm;
    uint32_t attr_proc_r_distloss_vcs_uohm;
    uint32_t attr_proc_vrm_voffset_vcs_uv;

    uint32_t attr_freq_proc_refclock_khz;
    uint32_t attr_proc_dpll_divider;
    uint32_t attr_nest_frequency_mhz;

// Frequency Bias attributes
    int8_t attr_freq_bias_ultraturbo;
    int8_t attr_freq_bias_turbo;
    int8_t attr_freq_bias_nominal;
    int8_t attr_freq_bias_powersave;

// External Voltage Timing attributes
    uint32_t attr_ext_vrm_transition_start_ns;
    uint32_t attr_ext_vrm_transition_rate_inc_uv_per_us;
    uint32_t attr_ext_vrm_transition_rate_dec_uv_per_us;
    uint32_t attr_ext_vrm_stabilization_time_us;
    uint32_t attr_ext_vrm_step_size_mv;

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

    uint32_t attr_freq_core_floor;
    uint32_t attr_freq_core_floor_mhz;
    uint32_t attr_boot_freq_mhz;
    uint32_t attr_nest_freq_mhz;

// Resonant clock frequency attributes
    uint32_t attr_pm_resonant_clock_full_clock_sector_buffer_frequency_khz;
    uint32_t attr_pm_resonant_clock_low_band_lower_frequency_khz;
    uint32_t attr_pm_resonant_clock_low_band_upper_frequency_khz;
    uint32_t attr_pm_resonant_clock_high_band_lower_frequency_khz;
    uint32_t attr_pm_resonant_clock_high_band_upper_frequency_khz;

    uint32_t attr_tdp_rdp_current_factor;

    uint8_t attr_resclk_disable;
    uint8_t attr_dpll_vdm_response;
    uint8_t attr_nest_leakage_percent;

// Control attributes
    uint8_t attr_system_ivrm_disable;
    uint8_t attr_systemp_resclk_disable;
    uint8_t attr_system_wof_disable;
    uint8_t attr_system_vdm_disable;

    uint8_t attr_dd_wof_not_supported;
    uint8_t attr_dd_vdm_not_supported;
    uint8_t attr_pstate_mode;

// AVSBus attributes
    uint8_t vdd_bus_num;
    uint8_t vdd_rail_select;
    uint8_t vdn_bus_num;
    uint8_t vdn_rail_select;
    uint8_t vcs_bus_num;
    uint8_t vcs_rail_select;
    uint32_t vcs_voltage_mv;
    uint32_t vdd_voltage_mv;
    uint32_t vdn_voltage_mv;
    uint32_t r_loadline_vdd_uohm;
    uint32_t r_distloss_vdd_uohm;
    uint32_t vrm_voffset_vdd_uv;
    uint32_t r_loadline_vdn_uohm;
    uint32_t r_distloss_vdn_uohm;
    uint32_t vrm_voffset_vdn_uv;
    uint32_t r_loadline_vcs_uohm;
    uint32_t r_distloss_vcs_uohm;
    uint32_t vrm_voffset_vcs_uv;
    uint32_t freq_proc_refclock_khz;
    uint32_t proc_dpll_divider;

} AttributeList;

/// The layout of the various Pstate Parameter Blocks (PPBs) passed a single
/// structure for data movement.
///
/// This structure is only used for passing Pstate data from
/// p9_pstate_parameter_block to it caller for placement into HOMER for
/// consumption by into OCC, the Pstate PGPE and CME. Therefore there is no
/// alignment requirement.

typedef struct
{

    /// Magic Number
    uint64_t magic;

    // PGPE content
    GlobalPstateParmBlock globalppb;

    // CME content
    LocalPstateParmBlock localppb;

    // OCC content
    OCCPstateParmBlock occppb;

} PstateSuperStructure;

// Start of function declarations

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------

/// ----------------------------------------------------------------
/// @brief Get #V data and put into array
/// @param[i] i_target            Proc Target
/// @param[o] o_attr_mvpd_data    5x5 array to hold the #V data
/// @param[o] o_valid_pdv_points  No of Valid VPD points
/// @param[o] o_present_chiplets  No of functional chiplets
/// @param[o] o_bucketId          bucket id that got selected
/// @param[o] o_poundv_data       PoundV data
/// @paran[o] o_state             pstate attribute state
/// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// ----------------------------------------------------------------
fapi2::ReturnCode
proc_get_mvpd_data ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                     uint32_t o_attr_mvpd_data[PV_D][PV_W],
                     uint32_t* o_valid_pdv_points,
                     uint8_t* o_present_chiplets,
                     uint8_t&      o_bucketId,
                     fapi2::voltageBucketData_t* o_poundv_data,
                     PSTATE_attribute_state* o_state);

/// -------------------------------------------------------------------
/// @brief Perform data validity check on #V data
/// @param[i] i_target            Proc Target
/// @param[i] i_chiplet_mvpd_data Pointer to array of #V data
/// @param[o] o_valid_pdv_points  No of Valid VPD points
/// @param[i] i_chiplet_num       Chiplet number
/// @param[i] i_bucket_id         Bucket ID
/// @param[o] o_state             pstate attribute state
/// @param[i] i_biased_state      biased validity check state
/// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// -------------------------------------------------------------------

fapi2::ReturnCode
proc_chk_valid_poundv ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                        const uint32_t i_chiplet_mvpd_data[PV_D][PV_W],
                        uint32_t* o_valid_pdv_points,
                        const uint8_t i_chiplet_num,
                        const uint8_t i_bucket_id,
                        PSTATE_attribute_state* o_state,
                        const bool i_biased_state = false);


/// ----------------------------------------------------------------
/// @brief Get IQ (IDDQ) data and put into array
/// @param[in]    i_target          => Proc Target
/// @param[inout] iddqt             => IDDQ table to hold MVPD IDDQ data
/// @param[out]   o_state           => pstate attribute state
/// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// ----------------------------------------------------------------

fapi2::ReturnCode
proc_get_mvpd_iddq ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                     IddqTable* io_iddqt,
                     PSTATE_attribute_state* o_state);
/// ----------------------------------------------------------------
/// @brief Get #W data and put into array
/// @param[in]    i_target          => Proc Target
/// @param[in]    i_poundv_bucketId => #V bucket id
/// @param[out]   o_vdmpb           => Vdmparamblock data
/// @param[out]   o_poundw_data     => #W data
/// @paramg[in]   i_poundv_data     => #V data
/// @param[o]     o_state           => pstate attribute state
/// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// ----------------------------------------------------------------
fapi2::ReturnCode
proc_get_mvpd_poundw(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                     uint8_t       i_poundv_bucketId,
                     LP_VDMParmBlock* o_vdmpb,
                     PoundW_data* o_poundw_data,
                     fapi2::voltageBucketData_t i_poundv_data,
                     PSTATE_attribute_state* o_state
                    );
/// -----------------------------------------------------------------------
/// @brief Get needed attributes
/// @param[in]     i_target          => Proc Target
/// @param[in/out] io_attr           => pointer to attribute list structure
/// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// -----------------------------------------------------------------------
fapi2::ReturnCode
proc_get_attributes ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                      AttributeList* io_attr);


/// -----------------------------------------------------------------------
/// @brief Load attribute content into the Global Parameter Block
/// @param[in] i_attr               => Reference to attribute list structure
/// @param[out] o_globalppb         => Pointer to Global Parameter Block
/// -----------------------------------------------------------------------
void
load_gppb_attrs(const AttributeList*   i_attr,
                GlobalPstateParmBlock* o_globalppb);

//
/// -----------------------------------------------------------------------
/// @brief Apply system parameters to a VPD value
/// @param[in] i_vpd_mv             => Reference to attribute list structure
/// @param[in] i_vpd_ma             = Reference to attribute list structure
/// @param[in] i_loadline_uohm      => Reference to attribute list structure
/// @param[in] i_distloss_uohm      => Reference to attribute list structure
/// @param[in] i_distoffset_uohm    => Reference to attribute list structure
/// @return[out] uplifted voltage with system parameters added
/// -----------------------------------------------------------------------
uint32_t
sysparm_uplift(const uint32_t i_vpd_mv,
               const uint32_t i_vpd_ma,
               const uint32_t i_loadline_uohm,
               const uint32_t i_distloss_uohm,
               const uint32_t i_distoffset_uohm);

/// ---------------------------------------------------------------------------
/// @brief Check and process #V bias attributes for external and internal
/// @param[in/out]  io_attr_mvpd_data       => 5x5 array to hold the #V data
/// @param[in]      i_attr                  => pointer to attribute list structure
/// @param[out]     o_vpdbias               => Voltage/Frequency bias values
/// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// ---------------------------------------------------------------------------

fapi2::ReturnCode
proc_get_extint_bias ( uint32_t io_attr_mvpd_data[PV_D][PV_W],
                       const AttributeList* i_attr,
                       VpdBias o_vpdbias[NUM_OP_POINTS] );

/// -------------------------------------------------------------------
/// @brief Boost max frequency in pstate table based on boost attribute
/// @param[in/out] io_pss               => pointer to pstate superstructure
/// @param[in]    i_attr_boost_percent  => Boost percentage attribute
/// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// -------------------------------------------------------------------

fapi2::ReturnCode
proc_boost_gpst ( PstateSuperStructure* io_pss,
                  uint32_t i_attr_boost_percent);

/// ------------------------------------------------------------
/// @brief Update Psafe_pstate
/// @param[in/out] *io_pss   => pointer to pstate superstructure
/// @param[in]     *i_attr  => pointer to attribute list structure
/// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// ------------------------------------------------------------

fapi2::ReturnCode
proc_upd_psafe_ps ( PstateSuperStructure* io_pss,
                    const AttributeList* i_attr);

/// ------------------------------------------------------------
/// @brief Update Floor_pstate
/// @param[inout] *io_pss   => pointer to pstate superstructure
/// @param[in]    *i_attr  => pointer to attribute list structure
/// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// ------------------------------------------------------------

fapi2::ReturnCode
proc_upd_floor_ps ( PstateSuperStructure* io_pss,
                    const AttributeList* i_attr);

/// -------------------------------------------------------------------
/// @brief Convert Resonant Clocking attributes to pstate values and update superstructure with those values
/// @param[inout] *io_pss   => pointer to pstate superstructure
/// @param[in]    *i_attr  => pointer to attribute list structure
/// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// -------------------------------------------------------------------

fapi2::ReturnCode
proc_res_clock    ( PstateSuperStructure* io_pss,
                    AttributeList* i_attr);

/// ------------------------------------------------------------
/// @brief Populate a subset of the WOFElements structure from Attributes
/// @param[inout] *io_pss   => pointer to pstate superstructure
/// @param[in]    *i_attr  => pointer to attribute list structure
/// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// ------------------------------------------------------------

fapi2::ReturnCode
load_wof_attributes ( PstateSuperStructure* io_pss,
                      const AttributeList* i_attr);

/// ------------------------------------------------------------
/// @brief Copy VPD operating point into destination in assending order
/// @param[in]    i_src[NUM_OP_POINTS]   => Source VPD structure (array)
/// @param[out] * o_dest[NUM_OP_POINTS]  => pointer to destination VpdOperatingPoint structure
/// @param[in]    i_frequency_step_khz   => frequency step size
/// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// ------------------------------------------------------------

fapi2::ReturnCode
load_mvpd_operating_point ( const uint32_t i_src[PV_D][PV_W],
                            VpdOperatingPoint* o_dest,
                            uint32_t i_frequency_step_khz);

/// ------------------------------------------------------------
/// @brief Copy out of operating point set into a destination operating point
/// @param[in]  &i_op_pt_set          => reference to array of VpdOperatingPoint sets
/// @param[out] *dest[NUM_OP_POINTS]  => pointer to destination VpdOperatingPoint structure
/// @param[in]  i_frequency_step_khz  => Base frequency value for pstate calculation
/// ------------------------------------------------------------
fapi2::ReturnCode
get_operating_point ( const VpdOperatingPoint  i_op_pt_set[NUM_VPD_PTS_SET][NUM_OP_POINTS],
                      uint32_t                 i_set,
                      VpdOperatingPoint*       o_op_pt);

/// ----------------------------------------------------------------
/// @brief Get VDM parameters from attributes
/// @param[in]    i_target          => Proc Target
/// @param[in]   *i_attr            => pointer to attribute list structure
/// @param[out]   o_vdmpb           => VDM parameter block
/// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// ----------------------------------------------------------------

fapi2::ReturnCode
proc_get_vdm_parms ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                     const AttributeList* i_attr,
                     GP_VDMParmBlock* o_vdmpb);

/// ----------------------------------------------------------------
/// @brief Get resonant clocking parameters from attributes
/// @param[in]    i_target          => Proc Target
/// @param[out]   o_resclk_setup    => Resonant clocking setup
/// @param[in]    i_gppb            => The Global Pstate Parameter Block
/// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// ----------------------------------------------------------------

fapi2::ReturnCode
proc_res_clock_setup ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                       ResonantClockingSetup* o_resclk_setup,
                       const GlobalPstateParmBlock* i_gppb);

/// ----------------------------------------------------------------
/// @brief Get IVRM parameters from attributes
/// @param[in]     i_target          => Proc Target
/// @param[in]    *i_attr            => pointer to attribute list structure
/// @param[out]    o_ivrmpb          => IVRM parameter block
/// @param[o]      o_state           => pstate attribute state
/// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// ----------------------------------------------------------------

fapi2::ReturnCode
proc_get_ivrm_parms ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                      const AttributeList* i_attr,
                      IvrmParmBlock* o_ivrmpb,
                      PSTATE_attribute_state* o_state);

/// -------------------------------------------------------------------
/// @brief Set Resonant Clocking "array"/"table" attributes using p9_resclk_defines.h
/// @param[in]    i_target          => Proc Target
/// @param[in]    o_state           => resclck attribute state
/// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// -------------------------------------------------------------------
fapi2::ReturnCode
proc_set_resclk_table_attrs(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                            PSTATE_attribute_state* o_state);

/// -------------------------------------------------------------------
/// @brief  Compute VPD points for different regions
/// @param[out]    o_operating_points =>  VPD operating points
/// @param[in]    i_gppb             => Global pstate structure
/// @param[in]    i_raw_vpd_pts      => Raw vpd operating points data
/// @return void
/// -------------------------------------------------------------------
void p9_pstate_compute_vpd_pts(VpdOperatingPoint (*o_operating_points)[NUM_OP_POINTS],
                               GlobalPstateParmBlock* i_gppb,
                               VpdOperatingPoint* i_raw_vpd_pts);
//
// p9_pstate_compute_PsV_slopes
//
// Computes slope of voltage-PState curve and PState-voltage
//
// PState(Frequency) on y-axis, Voltage is on x-axis for VF curve
// Interpolation formula: (y-y0)/(x-x0) = (y1-y0)/(x1-x0)
// m   = (x1-x0)/(y1-y0), then use this to calculate voltage, x = (y-y0)*m + x0
// 1/m = (y1-y0)/(x1-x0) here, then use this to calculate pstate(frequency), y = (x-x0)*m + y0
// Region 0 is b/w POWERSAVE and NOMINAL
// Region 1 is b/w NOMINAL and TURBO
// Region 2 is between TURBO and ULTRA_TURBO
//
// Inflection Point 3 is ULTRA_TURBO
// Inflection Point 2 is TURBO
// Inflection Point 1 is NOMINAL
// Inflection Point 0 is POWERSAVE
//
/// -------------------------------------------------------------------
/// @brief  Compute Pstate slope values for different frequencies and pstates
/// @param[in]    i_operating_points =>  VPD operating points
/// @param[out]   o_gppb             => Global pstate structure
/// @return void
/// -------------------------------------------------------------------
void p9_pstate_compute_PsV_slopes(VpdOperatingPoint i_operating_points[][4],
                                  GlobalPstateParmBlock* o_gppb);

/// -------------------------------------------------------------------
/// @brief  Compute Pstate slope values for different frequencies and pstates
/// @param[in]    i_operating_points =>  VPD operating points
/// @param[out]   o_gppb             => Global pstate structure
/// @return void
/// -------------------------------------------------------------------
void p9_pstate_compute_PStateV_slope(VpdOperatingPoint i_operating_points[][4],
                                     GlobalPstateParmBlock* o_gppb);


/// -------------------------------------------------------------------
/// @brief  Print a GlobalPstateParameterBlock structure on a given stream
/// @param[in]  i_gppb    The Global Pstate Parameter Block to print
/// @return void
/// -------------------------------------------------------------------
void
gppb_print(GlobalPstateParmBlock* i_gppb);


/// -------------------------------------------------------------------
/// @brief  Print a OCCPstateParameterBlock structure on a given stream
/// @param[in]  i_oppb The OCC Pstate Parameter Block to print
/// @return void
/// -------------------------------------------------------------------
void
oppb_print(OCCPstateParmBlock* i_oppb);

/// -------------------------------------------------------------------
/// @brief  Print an iddq_print structure on a given stream
/// @param[in]  i_iddqt pointer to Iddq structure to output
/// @return void
/// -------------------------------------------------------------------
void
iddq_print(IddqTable* i_iddqt);



enum FREQ2PSTATE_ROUNDING
{
    ROUND_FAST,
    ROUND_SLOW
};


/// -------------------------------------------------------------------
/// @brief Convert frequency to Pstate number
/// @param[in]     i_gppb     The Global Pstate Parameter Block
/// @param[in]     i_freq_khz Input frequency to convert
/// @param[out]    o_pstate   Computed Pstate
/// @param[out]    i_round    Pstate rounding (ROUND_FAST, ROUND_SLOW)
// @return  pstate state value whether it's lesser than min or greater than max
/// -------------------------------------------------------------------

int freq2pState (const GlobalPstateParmBlock* i_gppb,
                 const uint32_t             i_freq_khz,
                 Pstate*                    o_pstate,
                 const FREQ2PSTATE_ROUNDING i_round = ROUND_SLOW);

/// -------------------------------------------------------------------
/// @brief Convert Pstate number to frequency
/// @param[in]     i_gppb     The Global Pstate Parameter Block
/// @param[in]     i_pstate   Computed Pstate to convert
/// @param[out]    o_freq_khz Computed frequency
/// -------------------------------------------------------------------
int pState2freq (const GlobalPstateParmBlock* gppb,
                 const Pstate i_pstate,
                 uint32_t*    o_freq_khz);

/// -------------------------------------------------------------------
/// @brief Pstate VFRT initialization
/// @param[in] i_target     proc chip target
/// @param[in] i_gppb       The Global Pstate Parameter Block
/// @param[in] i_pBuffer    VFRT data coming from HB
/// @param[out] o_vfrt_data Homer VFRT version
/// @param[in] i_reference_freq  Ultra frequency  @todo get this from the gppb
/// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// -------------------------------------------------------------------
fapi2::ReturnCode
p9_pstate_update_vfrt(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const GlobalPstateParmBlock*  i_gppb,
    uint8_t* i_pBuffer,
    HomerVFRTLayout_t* o_vfrt_data,
    uint32_t i_reference_freq);

/**
*
* Description: Generic function to perform the effective capacitance
*              calculations.
*              C_eff = I / (V^1.3 * F)
*
*              I is the AC component of Idd in 0.01 Amps (or10 mA)
*              V is the silicon voltage in 100 uV
*              F is the frequency in MHz
*
*              Note: Caller must ensure they check for a 0 return value
*                    and disable wof if that is the case
*
/// -------------------------------------------------------------------
/// @brief calculate_effective_capacitance
/// @param[in]: i_iAC - the AC component
/// @param[in]: i_voltage - the voltage component in 100uV
/// @param[in]: i_frequency - the frequency component
/// @return: The calculated effective capacitance
/// -------------------------------------------------------------------
*/
uint16_t pstate_calculate_effective_capacitance( uint16_t i_iAC,
        uint16_t i_voltage,
        uint16_t i_frequency );


/// -------------------------------------------------------------------
/// @brief   Get IAC VDN value
/// @param[in]: i_vdd_value VDD value from #V
/// @param[in]: i_iddq      IQ vpd data
/// @param[in]: nest_leakage_percent   leakage in 60C
/// @param[in]: i_vdn_vpd_value VPD value from power bus #V data
/// @return iaac vdn value
/// -------------------------------------------------------------------
uint16_t get_iac_vdn_value (uint16_t i_vdd_value,
                            IddqTable i_iddq,
                            uint8_t nest_leakage_percent,
                            uint16_t i_vdn_vpd_value);

/// -------------------------------------------------------------------
/// @brief  round up the floating point value
/// @param[in]: i_vdd_value VDD value from #V
/// @return nearest value
/// -------------------------------------------------------------------
uint16_t roundUp(float i_value);


///Compute VID points
/// -------------------------------------------------------------------
/// @brief  Compute VDM threshold points based on pound W data
/// @param[in]       i_data   => Pound W data
/// @param[in/out]   io_lppb  => local pstate structure data
/// @return void
/// -------------------------------------------------------------------
void p9_pstate_compute_vdm_threshold_pts(PoundW_data i_data,
        LocalPstateParmBlock* io_lppb);

///Biased slope calculation
/// -------------------------------------------------------------------
/// @brief  Compute VID compare slope values
/// @param[in]       i_data   => Pound W data
/// @param[in/out]   io_lppb  => local pstate structure data
/// @param[in]       i_pstate => pstate values
/// @return void
/// -------------------------------------------------------------------
void p9_pstate_compute_PsVIDCompSlopes_slopes(PoundW_data i_data,
        LocalPstateParmBlock* io_lppb,
        uint8_t* i_pstate);

// p9_pstate_compute_PsVDMThreshSlopes
//
/// -------------------------------------------------------------------
/// @brief  Compute VDM threshold slope values
/// @param[in/out]   io_lppb  => local pstate structure data
/// @param[in]       i_pstate => pstate values
/// @return void
/// -------------------------------------------------------------------
void p9_pstate_compute_PsVDMThreshSlopes(LocalPstateParmBlock* io_lppb,
        uint8_t* i_pstate);

// p9_pstate_compute_PsVDMJumpSlopes
//
/// -------------------------------------------------------------------
/// @brief  Compute VDM jump slope values
/// @param[in/out]   io_lppb  => local pstate structure data
/// @param[in]       i_pstate => pstate values
/// @return void
/// -------------------------------------------------------------------
void p9_pstate_compute_PsVDMJumpSlopes(
    LocalPstateParmBlock* io_lppb,
    uint8_t* i_pstate);


// p9_pstate_wof_initialization
/// -------------------------------------------------------------------
/// @brief  WOF table initialization
/// @param[in]     i_target               => proc chip target
/// @param[in]     i_gppb                 => pointer to GPPB strucure
/// @param[out]    o_buf                  => wof data
/// @param[in/out] io_size                => total wof data size
/// @param[out]    o_state                => pstate attribute values
/// @param[in]     i_base_state_frequency => base frequency value
/// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// -------------------------------------------------------------------
fapi2::ReturnCode
p9_pstate_wof_initialization(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const GlobalPstateParmBlock* i_gppb,
    uint8_t* o_buf,
    uint32_t& io_size,
    PSTATE_attribute_state* o_state,
    const uint32_t i_base_state_frequency);

/// -------------------------------------------------------------------
/// @brief This function computes the safe mode frequency and voltage value
/// @param[in] i_target  proc chip target
/// @param[in] i_attr_mvpd_data #V vpd data
/// @param[in] i_reference_freq proc reference freq
/// @param[in] i_step_frequency Step frequency
/// @param[in] i_ps_pstate power save pstate
/// @param[out] o_safe_mode_values safe mode values
/// @param[in] i_poundw_data  Pound W vpd data
/// @return FAPI2::SUCCESS
fapi2::ReturnCode
p9_pstate_safe_mode_computation(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                const VpdOperatingPoint i_operating_points[NUM_VPD_PTS_SET][NUM_OP_POINTS],
                                const uint32_t i_reference_freq,
                                const uint32_t i_step_frequency,
                                const Pstate i_ps_pstate,
                                Safe_mode_parameters* o_safe_mode_values,
                                const PoundW_data i_poundw_data);


/// -------------------------------------------------------------------
/// @brief This function provides ncessary #W data in the event of access failures
/// @paramgin] o_poundw_data  Pound W vpd data
/// @return None
void
large_jump_defaults(PoundW_data* o_poundw_data);


/// -------------------------------------------------------------------
/// @brief For a given pstate.. gets the vdd voltge value
/// @param[in] i_pstate  safe mode pstate
/// @param[in] i_attr_mvpd_data #V vpd data
/// @param[in] i_step_frequency Step frequency
/// @return uint32_t vdd voltage value
uint32_t pstate2voltage(const Pstate i_pstate,
                        const uint32_t i_attr_mvpd_data[PV_D][PV_W],
                        const uint32_t i_step_frequency);

/// -------------------------------------------------------------------
/// @brief This function calculates large jump value.. for the given pstate
//         values and jump values read from the pound w vpd.
/// @param[in] i_pstate  safe mode pstate
/// @param[in] i_attr_mvpd_data #V vpd data
/// @param[in] i_step_frequency Step frequency
/// @param[in] i_ps_pstate power save pstate
/// @paramgin] i_data  Pound W vpd data
/// @return uint32_t jump value
uint32_t large_jump_interpolate(const Pstate i_pstate,
                                const VpdOperatingPoint i_operating_points[NUM_OP_POINTS],
                                const uint32_t i_step_frequency,
                                Pstate i_ps_pstate,
                                const PoundW_data i_data);

/// -------------------------------------------------------------------
/// @brief Interpolate the currents based on frequency
/// @param[in]      i_biased_vpd - Data to interpolate
/// @param[in]      i_freq_mhz   - Index grequency
/// @param[out]     o_current_ma - Interpolated Current
/// @return true or false
///
void
interpolate_current( const uint32_t i_biased_vpd[PV_D][PV_W],
                     const uint32_t i_freq_mhz,
                     uint32_t*      o_current_ma);

// p9_pstate_set_global_feature_attributes
/// -------------------------------------------------------------------
/// @brief  Set the global pstate attributes
/// @param[in]    i_target   => Proc target
/// @param[in]    i_state    => pstate attribute states
/// @param[out]   o_qm_flags => Quad manager flags
/// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// -------------------------------------------------------------------
fapi2::ReturnCode
p9_pstate_set_global_feature_attributes(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    PSTATE_attribute_state i_state,
    QuadManagerFlags* o_qm_flags);

/// @typedef p9_pstate_parameter_block_FP_t
/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pstate_parameter_block_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    PstateSuperStructure*, uint8_t*, uint32_t&);

extern "C"
{

/// -------------------------------------------------------------------
/// @brief Populate Pstate super structure from VPD data
/// @param[in]    i_target          => Chip Target
/// @param[inout] *io_pss           => pointer to pstate superstructure
/// @param[out]   *o_buf            => wof table data
/// @param[inout] &io_size          => wof table data size
/// @return   FAPI2::SUCCESS
/// -------------------------------------------------------------------
    fapi2::ReturnCode
    p9_pstate_parameter_block( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                               PstateSuperStructure* io_pss, uint8_t* o_buf, uint32_t& io_size);

} // extern C


// End of function declarations

#ifdef __cplusplus
} // end extern C
#endif

#endif  // __P9_PSTATE_PARAMETER_BLOCK_H__

