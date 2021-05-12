/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pstate_parameter_block.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file  p10_pstate_parameter_block.H
/// @brief Definitons of paramater information used to process pstates
///
// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Prasad Bg Ranganath <prasadbgr@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : HB,PGPE,CME,OCC

#ifndef __P10_PSTATE_PARAMETER_BLOCK_H__
#define __P10_PSTATE_PARAMETER_BLOCK_H__

#include <fapi2.H>
#include <pstates_occ.H>
#include <pstates_pgpe.H>
#include <pstates_table.H>
#include <p10_pm_utils.H>
#include <p10_pm_get_poundv_bucket.H>
#include <p10_pm_get_poundw_bucket.H>
#include <p10_pm_set_system_freq.H>

#define INVALID_BUS_NUM   0xFF

//VDD Voltage config actions
typedef enum
{
    COMPUTE_VOLTAGE_SETTINGS,
    APPLY_VOLTAGE_SETTINGS
} VoltageConfigActions_t;
typedef enum VPD_TYPE
{
    RAW,
    BIASED,
} vpd_type;
typedef enum VOLTAGE_TYPE
{
    VDD = 0,
    VCS = 1,
    VDN = 2,
    VIO = 3,
    MAX_VRM = 4,
} voltage_type;

enum FREQ2PSTATE_ROUNDING
{
    ROUND_FAST,
    ROUND_SLOW
};

enum PPB_ERROR
{
    PPB_OFF,
    PPB_WARN,
    PPB_INFO,
    PPB_FAIL
};


typedef uint8_t Pstate;
#define PSTATE_LT_PSTATE_MIN 0x00778a03
#define PSTATE_GT_PSTATE_MAX 0x00778a04

//Pstate SuperStructure
typedef struct
{
    /// Magic Number
    uint64_t iv_magic;

    // PGPE content
    GlobalPstateParmBlock_t iv_globalppb;

    //TBD
    // QME content
    //LocalPstateParmBlock iv_localppb;

    // OCC content
    OCCPstateParmBlock_t iv_occppb;

} PstateSuperStructure;

namespace pm_pstate_parameter_block
{

enum ROUNDING
{
    ROUND_UP,
    ROUND_DOWN
};

#define BIAS_PCT_UNIT              0.5
using namespace fapi2;
// Structure containing all attributes required by Pstate Parameter block
typedef struct
{
    uint32_t attr_freq_core_ceiling_mhz;

    uint32_t attr_freq_proc_refclock_khz;
    uint32_t attr_proc_dpll_divider;
    uint32_t attr_pau_frequency_mhz;

    uint32_t attr_dpll_bias;
    uint32_t attr_undervolting;
    uint32_t attr_pm_safe_frequency_mhz;
    uint32_t attr_pm_safe_voltage_mv[2];

    uint32_t attr_freq_core_floor;
    uint32_t attr_freq_core_floor_mhz;
    uint32_t attr_boot_freq_mhz;
    uint32_t attr_nest_freq_mhz;

    uint8_t attr_resclk_disable;
    uint8_t attr_dpll_vdm_response;
    uint8_t attr_nest_leakage_percent;

    // Control attributes
    uint8_t attr_system_current_read_disable;
    uint8_t attr_system_ocs_disable;
    uint8_t attr_system_wof_disable;
    uint8_t attr_system_rvrm_disable;
    uint8_t attr_system_dds_disable;
    uint8_t attr_dds_cal_pstate_enable;
    uint8_t attr_dds_coarse_thr_enable;
    uint8_t attr_dds_freq_jump_enable;
    uint8_t attr_pmcr_most_recent_enable;
    uint8_t attr_phantom_halt_enable;
    uint8_t attr_pgpe_hcode_function_enable;
    uint8_t attr_system_pitch_enable;
    uint8_t attr_system_wof_disable_dimension[5];
    uint8_t attr_system_wof_throttle_control_loop_disable;
    uint8_t attr_system_wof_throttle_control_loop_mode;
    uint8_t attr_dds_trip_mode;
    uint8_t attr_dds_trip_interpolation_control;
    uint8_t attr_dds_dpll_slew_mode;
    uint8_t attr_dds_bias_enable;
    // RTC: 269546:  remove the FMax Enable mode control
    uint8_t attr_fmax_enable;
    uint8_t attr_war_mode;

    uint8_t attr_dd_wof_not_supported;
    uint8_t attr_dd_dds_not_supported;
    uint8_t attr_pstate_mode;

    int8_t  attr_freq_bias; //for all #V points
    int8_t  attr_voltage_ext_bias[2][8];
    int8_t  attr_voltage_ext_vdn_bias;

    uint16_t attr_system_wof_altitude_temp_adjustment;
    uint16_t attr_system_wof_tdp_altitude_reference;

    // AVSBus attributes
    uint32_t attr_avs_bus_freq;
    uint8_t  attr_avs_bus_num[4]; //VDD,VCS,VDN,VIO
    uint8_t  attr_avs_bus_rail_select[4]; //VDD,VCS,VDN,VIO
    uint32_t attr_boot_voltage_mv[4]; //VDD,VCS,VDN,VIO
    uint32_t attr_proc_r_distloss_uohm[4];
    uint32_t attr_proc_r_loadline_uohm[4];
    uint32_t attr_proc_vrm_voffset_uv[4];
    uint8_t  attr_boot_voltage_biase_0p5pct;

    // External Voltage Timing attributes VDD,VCS,VDN,VIO
    uint32_t attr_ext_vrm_transition_start_ns[4];
    uint32_t attr_ext_vrm_transition_rate_inc_uv_per_us[4];
    uint32_t attr_ext_vrm_transition_rate_dec_uv_per_us[4];
    uint32_t attr_ext_vrm_stabilization_time_us[4];
    uint32_t attr_ext_vrm_step_size_mv[4];
    uint32_t attr_save_mode_nodds_uplift_mv[2]; //VDD,VCS
    uint32_t attr_pstate0_freq_mhz;
    uint32_t attr_nominal_freq_mhz;
    uint32_t attr_pstate0_freq;
    uint8_t  attr_throttle_pstate_number_limit;

    //WOF Attributes
    uint16_t attr_vratio_vdd_10th_pct[NUM_WOF_VRATIO_PCT];
    uint16_t attr_vratio_vcs_10th_pct[NUM_WOF_VRATIO_PCT];

    ///Undervolt and Overvolt Attributes
    uint8_t attr_wov_underv_disable;
    uint8_t attr_wov_overv_disable;
    uint8_t attr_wov_underv_force;
    uint32_t attr_wov_sample_125us;
    uint32_t attr_wov_max_droop_pct;
    uint8_t attr_wov_underv_perf_loss_thresh_pct;
    uint8_t attr_wov_underv_step_incr_pct;
    uint8_t attr_wov_underv_step_decr_pct;
    uint8_t attr_wov_underv_max_pct;
    uint16_t attr_wov_underv_vmin_mv;
    uint16_t attr_wov_overv_vmax_mv;
    uint8_t attr_wov_overv_step_incr_pct;
    uint8_t attr_wov_overv_step_decr_pct;
    uint8_t attr_wov_overv_max_pct;
    uint8_t attr_wov_dirty_uncurrent_ctrl[NUM_WOV_DIRTY_UC_CTRL];
    uint32_t attr_sram_write_assist_mv;
    uint32_t attr_array_write_assist_set;
    uint8_t  attr_rvrm_deadzone_mv;
    uint8_t attr_vcs_vdd_offset_mv;
    uint16_t attr_vcs_floor_mv;

    // Only 3 of the 8 are actually consumed
    uint8_t attr_current_scaling_factor[8];

    uint64_t attr_wof_dccr_value;
    uint64_t attr_wof_flmr_value;
    uint64_t attr_wof_fmmr_value;

} AttributeList;

//PlatPmPPB Object definition
class PlatPmPPB
{
    public:
        //Constructor with Proc target as input
        PlatPmPPB ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> i_target ) :
            iv_init_error(false), iv_procChip (i_target), iv_boot_mode(false),
            iv_pstates_enabled(0), iv_resclk_enabled(0), iv_dds_enabled(0), iv_rvrm_enabled(0),
            iv_wof_enabled(0), iv_safe_voltage(0), iv_safe_frequency(0),
            iv_reference_frequency_mhz(0), iv_reference_frequency_khz(0),
            iv_frequency_step_khz(0), iv_proc_dpll_divider(0), iv_occ_freq_mhz(0),
            iv_wov_underv_enabled(0), iv_wov_overv_enabled(0), iv_ocs_enabled(0),
            iv_wof_throttle_enabled(0), iv_poundV_fmax_enable(true),
            iv_dccr_value(0), iv_flmr_value(0), iv_fmmr_value(0),
            iv_wts_vddPsavFreq(0), iv_wts_vddWofBaseFreq(0), iv_wts_vddUTFreq(0), iv_wts_vddFixedFreq(0)
        {
            attr_init();
        }

        ///-----------------------------------------------------------------------
        /// @brief Initialize pstate attributes
        /// @return void
        //-----------------------------------------------------------------------
        void attr_init();

        /// -----------------------------------------------------------------------
        /// @brief Initialize VPD data
        // @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode vpd_init();

        /// -----------------------------------------------------------------------
        /// @brief Compute safe mode values
        /// @param[in]    i_action  voltage config action (Compute/set)
        /// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode compute_boot_safe(
            const VoltageConfigActions_t i_action);

        /// -----------------------------------------------------------------------
        /// @brief Initialize resclk
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        void resclk_init();

        /// -----------------------------------------------------------------------
        /// @brief Initialize WOF data
        /// @param[out]    o_buf points to WOF data
        /// @param[inout]  io_size size of the wof  table
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode wof_init(
            uint8_t* o_buf,
            uint32_t& io_size);

        /// -----------------------------------------------------------------------
        /// @brief Convert the WOF Tables from System version to the HOMER version
        /// @param[in]     l_wof_table_data points to WOF data tables
        /// @param[out]    o_buf points to WOF data in the output memory buffer
        /// @param[inout]  io_size size of the wof  table
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode wof_convert_tables(
            fapi2::ATTR_WOF_TABLE_DATA_Type* l_wof_table_data,
            uint8_t* o_buf,
            uint32_t& io_size);

        /// -----------------------------------------------------------------------
        /// @brief VRT data initialization from WOF data
        /// @param[in]     i_pBuffer WOF data buffer
        /// @param[inout]  o_vrt_data  vrt data
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode update_vrt(
            uint8_t* i_pBuffer,
            VRT_t* o_vrt_data);

        /// -----------------------------------------------------------------------
        /// @brief Set the WOF override flags in the class. Used for marking output
        ///         traces with indicators.
        /// @param[in]     pound V data
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode set_wof_override_flags(voltageBucketData_t* i_poundV_data);

        /// -----------------------------------------------------------------------
        /// @brief Initialize global pstate parameter block
        /// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode gppb_init( GlobalPstateParmBlock_t* i_globalppb);

        /// -----------------------------------------------------------------------
        /// @brief This will set the pstate feature attrbutes(DDS,RESCLK,VRM,WOF)
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode set_global_feature_attributes();

        /// -----------------------------------------------------------------------
        /// @brief Initialize occ pstate parameter block
        /// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode oppb_init(OCCPstateParmBlock_t* i_occppb);

        /// -----------------------------------------------------------------------
        /// @brief This fills up the DDS slopes in GlobalParmBlock
        /// @param[out]     o_gppb  global PPB data
        /// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        void compute_dds_slopes(GlobalPstateParmBlock_t* o_gppb);

        /// -----------------------------------------------------------------------
        /// @brief This fills up the PStateVSlopes and VPStatesSlopes in
        ///         GlobalParmBlock
        /// @param[out]     o_gppb  global PPB data
        /// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        void compute_PStateV_I_slope(GlobalPstateParmBlock_t* o_gppb);

        /// -----------------------------------------------------------------------
        /// @brief set pstate0 attribute/floor/ceil freq based on Fmax/UT/PSav value
        /// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode pm_set_frequency();

        /// -----------------------------------------------------------------------
        /// @brief Read #V data from module vpd
        /// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode get_mvpd_poundV();

        /// -----------------------------------------------------------------------
        /// @brief Read AW data from module vpd
        /// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode get_mvpd_poundAW();

        /// -----------------------------------------------------------------------
        /// @brief Read #W data from module vpd
        /// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode get_mvpd_poundW();

        /// -----------------------------------------------------------------------
        /// @brief Validate #V data
        /// @param[in]     i_biased_state present/nonpresent
        /// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode chk_valid_poundv(
            const bool i_biased_state);

        /// -----------------------------------------------------------------------
        /// @brief Update pound V optional curve points if values are zero
        /// @return none
        /// -----------------------------------------------------------------------
        void update_vpd_pts_value();

        /// -----------------------------------------------------------------------
        /// @brief Compute safe mode values
        /// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode safe_mode_computation();

        /// -----------------------------------------------------------------------
        /// @brief Compute the retention VID value
        /// @attr[out]      ATTR_RVRM_RVID
        /// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode compute_retention_vid();

        /// -----------------------------------------------------------------------
        /// @brief Compute the retention VID value
        /// @attr[out]      ATTR_RVRM_RVID
        /// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode rvrm_enablement();

        /// -----------------------------------------------------------------------
        /// @brief Convert pstate to voltage from biased points
        /// @param[in]     i_pstate     pstate value that needs to be converted
        /// @param[in]     i_type       voltage type (VDD, VCS)
        /// @param[in]     i_point_set  point set (VPD_PT_SET_BIASED, VPD_PT_SET_BIASED_SYSP)
        /// @return  voltage value.
        /// -----------------------------------------------------------------------
        uint32_t ps2v_mv(const Pstate i_pstate,
                         const voltage_type i_type,
                         const uint32_t i_point_set);

        /// -----------------------------------------------------------------------
        /// @brief Converts frequency value to pstate number
        /// @param[in]     i_freq_khz input frequency
        /// @param[out]    o_pstate pstate output for a given inut frequency
        /// @return        fapi::ReturnCode
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode  freq2pState (const uint32_t freq_khz,
                                        Pstate* o_pstate,
                                        const FREQ2PSTATE_ROUNDING i_round = ROUND_SLOW,
                                        const PPB_ERROR i_error_mode = PPB_WARN);

        /// -----------------------------------------------------------------------
        /// @brief Converts a pstate number to a frequency
        /// @param[in]     i_pstate pstate output for a given inut frequency
        /// @param[out]    o_freq_khz input frequency
        /// -----------------------------------------------------------------------
        void pState2freq (const Pstate i_pstate,
                          uint32_t* o_freq_khz);

        /// -----------------------------------------------------------------------
        /// @brief Safe mode frequency and voltage init
        /// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode safe_mode_init( void );

        /// -----------------------------------------------------------------------
        /// @brief Determine the region number of a frequency within
        ///        iv_attr_mvpd_poundV_raw_orig
        /// @param[in]     freq_mhz     Frequency in MHz
        /// @return                     Number of regions
        /// -----------------------------------------------------------------------
        uint32_t find_freq_region(const uint32_t freq_mhz);

        /// -----------------------------------------------------------------------
        /// @brief Determine the number if frequency steps in a
        ///        iv_attr_mvpd_poundV_raw_orig region
        /// @param[in]     region       region number
        /// @return                     Number of steps
        /// -----------------------------------------------------------------------
        uint32_t region_steps(const uint32_t region);

        ///////////////////////////////////////////////////////////
        ////////   interpolate_freq_point
        ///////////////////////////////////////////////////////////
        void interpolate_freq_pt(const uint32_t  freq,
                                 PoundVOpPoint_t* ip);

        /// -----------------------------------------------------------------------
        /// @brief Interpolate #W points
        /// @param[in]     freq     Frequency to interpolate
        /// @param[in]     region   region number
        /// @param[in]     d_region #W Delay region
        /// @param[in]     ip       #W Entry Pointer
        /// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        void interpolate_pw_pt(const uint32_t  freq,
                               const uint32_t  region,
                               const uint32_t  d_region,
                               PoundWEntry_t*  ip);

        /// -----------------------------------------------------------------------
        /// @brief Compute VPD points of different regions
        /// @return none
        /// -----------------------------------------------------------------------
        void compute_vpd_pts();

        /// -----------------------------------------------------------------------
        /// @brief Read IQ vpd data
        /// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode get_mvpd_iddq( void );

        /// -----------------------------------------------------------------------
        /// @brief Disable Pstates and any dependent functions
        /// -----------------------------------------------------------------------
        void disable_pstates();

        /// -----------------------------------------------------------------------
        /// @brief Disable Rssonant Clocking and any dependent functions
        /// -----------------------------------------------------------------------
        void disable_resclk();

        /// -----------------------------------------------------------------------
        /// @brief Disable WOF and any dependent functions
        /// -----------------------------------------------------------------------
        void disable_wof();

        /// -----------------------------------------------------------------------
        /// @brief Disable RVRM and any dependent functions
        /// -----------------------------------------------------------------------
        void disable_rvrm();

        /// -----------------------------------------------------------------------
        /// @brief Disable DDS and any dependent functions
        /// -----------------------------------------------------------------------
        void disable_dds();

        /// -----------------------------------------------------------------------
        /// @brief Disable OCS and any dependent functions
        /// -----------------------------------------------------------------------
        void disable_ocs();

        /// -----------------------------------------------------------------------
        /// @brief Disable Undervolting and any dependent functions
        /// -----------------------------------------------------------------------
        void disable_underv();

        /// -----------------------------------------------------------------------
        /// @brief Disable Overrvolting and any dependent functions
        /// -----------------------------------------------------------------------
        void disable_overv();

        /// -----------------------------------------------------------------------
        /// @brief Disable WOF Throttling and any dependent functions
        /// -----------------------------------------------------------------------
        void disable_wof_throttle();

        /// -----------------------------------------------------------------------
        /// @brief State of Pstate enablement
        /// @return enabled(true)/disabled (false)
        /// -----------------------------------------------------------------------
        bool is_pstates_enabled();

        /// -----------------------------------------------------------------------
        /// @brief State of Resonant Clock enablement
        /// @return enabled(true)/disabled (false)
        /// -----------------------------------------------------------------------
        bool is_resclk_enabled();

        /// -----------------------------------------------------------------------
        /// @brief State of WOF enablement
        /// @return enabled(true)/disabled (false)
        /// -----------------------------------------------------------------------
        bool is_wof_enabled();

        /// -----------------------------------------------------------------------
        /// @brief State of RVRM enablement
        /// @return enabled(true)/disabled (false)
        /// -----------------------------------------------------------------------
        bool is_rvrm_enabled();

        /// -----------------------------------------------------------------------
        /// @brief State of DDS enablement
        /// @return enabled(true)/disabled (false)
        /// -----------------------------------------------------------------------
        bool is_dds_enabled();

        /// -----------------------------------------------------------------------
        /// @brief State of OCS enablement
        /// @return enabled(true)/disabled (false)
        /// -----------------------------------------------------------------------
        bool is_ocs_enabled();

        /// -----------------------------------------------------------------------
        /// @brief State of Undervolt enablement
        /// @return enabled(true)/disabled (false)
        /// -----------------------------------------------------------------------
        bool is_wov_underv_enabled();

        /// -----------------------------------------------------------------------
        /// @brief State of Overvolt enablement
        /// @return enabled(true)/disabled (false)
        /// -----------------------------------------------------------------------
        bool is_wov_overv_enabled();

        /// @brief State of WOF Throttle
        /// @return enabled(true)/disabled (false)
        /// -----------------------------------------------------------------------
        bool is_wof_throttle_enabled();

        /// -----------------------------------------------------------------------
        /// @brief Get pstate attribute data
        /// @param[out]    o_attr  populate attribute list data
        /// @return        none
        /// -----------------------------------------------------------------------
        void get_pstate_attrs(AttributeList& o_attr);

        /// -----------------------------------------------------------------------
        /// @brief Compute and apply biased values
        /// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode apply_extint_bias();

        /// -----------------------------------------------------------------------
        /// @brief Update the Pstates withing the biased structure
        /// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode update_biased_pstates();

        /// -----------------------------------------------------------------------
        /// @brief apply biased values for #V data
        /// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode apply_biased_values();

        /// -----------------------------------------------------------------------
        /// @brief Get the raw #W data
        /// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        void get_poundV_data_raw(PoundVOpPoint_t* o_data)
        {
            memcpy(o_data, iv_attr_mvpd_poundV_raw, sizeof(iv_attr_mvpd_poundV_raw));
        }

        /// -----------------------------------------------------------------------
        /// @brief Get the biased #W data
        /// @return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        void get_poundV_data_biased(PoundVOpPoint_t* o_data)
        {
            memcpy(o_data, iv_attr_mvpd_poundV_biased, sizeof(iv_attr_mvpd_poundV_biased));
        }

        /// -----------------------------------------------------------------------
        /// @brief Compute slope values for fixed point of shift 4.12
        /// @param[in]     y1
        /// @param[in]     y0
        /// @param[in]     x1
        /// @param[in]     x0
        /// @return computed slope (y1-y0)/(x1-x0) * (1 << VID_SLOPE_FP_SHIFT_12)
        /// -----------------------------------------------------------------------
        int16_t compute_slope_4_12(uint32_t y1, uint32_t y0, uint32_t x1, uint32_t x0)
        {
            return (int16_t)
                   (
                       // Perform division using floats for maximum precision
                       // Store resulting slope in 4.12 Fixed-Pt format
                       ((float)(y1 - y0) / (float)(x1 - x0)) * (1 << VID_SLOPE_FP_SHIFT_12)
                   );

        }
        /// -----------------------------------------------------------------------
        /// @brief Compute slope values for fixed point of shift 2.6
        /// @param[in]     y1
        /// @param[in]     y0
        /// @param[in]     x1
        /// @param[in]     x0
        /// @return computed slope (y1-y0)/(x1-x0) * (1 << 6)
        /// -----------------------------------------------------------------------
        int16_t compute_slope_2_6(uint32_t y1, uint32_t y0, uint32_t x1, uint32_t x0)
        {
            return (int8_t)
                   (
                       // Perform division using floats for maximum precision
                       // Store resulting slope in 2.6 Fixed-Pt format
                       ((float)(y1 - y0) / (float)(x1 - x0)) * (1 << 6)
                   );

        }
        /// -----------------------------------------------------------------------
        /// @brief Compute slope values for fixed point of shift 4.9
        /// @param[in]     y1
        /// @param[in]     y0
        /// @param[in]     x1
        /// @param[in]     x0
        /// @return computed slope (y1-y0)/(x1-x0) * (1 << I_SLOPE_FP_SHIFT_9)
        /// -----------------------------------------------------------------------
        int16_t compute_slope_4_9(uint32_t y1, uint32_t y0, uint32_t x1, uint32_t x0)
        {
            return (int16_t)
                   (
                       // Perform division using floats for maximum precision
                       // Store resulting slope in 4.9 Fixed-Pt format
                       ((float)(y1 - y0) / (float)(x1 - x0)) * (1 << I_SLOPE_FP_SHIFT_9)
                   );

        }

        /// -----------------------------------------------------------------------
        /// @brief Compute VDD/VCS/VDN voltage for given system parameters
        /// @param[in]     i_vpd_mv voltage value in milli volts
        /// @param[in]     i_vpd_ma Cuurent value in milli amps
        /// @param[in]     i_loadline_uohm   loadline value
        /// @param[in]     i_distloss_uohm   dist loss value
        /// @param[in]     i_distoffset_uohm dist offset value
        /// @return uplift value
        /// -----------------------------------------------------------------------
        uint32_t sysparm_uplift(const uint32_t i_vpd_mv,
                                const uint32_t i_vpd_ma,
                                const uint32_t i_loadline_uohm,
                                const uint32_t i_distloss_uohm,
                                const uint32_t i_distoffset_uohm)
        {
            double l_mv = (static_cast<double>(i_vpd_mv) +  // mV
                           (
                               // mA*uOhm/1000 -> uV
                               (static_cast<double>(i_vpd_ma * (i_loadline_uohm + i_distloss_uohm)) / 1000 +
                                // uv
                                static_cast<double>(i_distoffset_uohm))
                           ) / 1000);  // uV -> mV
            uint32_t l_result = static_cast<uint32_t>(l_mv);
            FAPI_DBG("  system_uplift_mv: i_vpd_mv=%d; i_vpd_ma=%d; i_loadline_uohm=%d "
                     "i_distloss_uohm = %d i_distoffset_uohm = %d l_mv = %5.3f l_result = %d" ,
                     i_vpd_mv,
                     i_vpd_ma,
                     i_loadline_uohm,
                     i_distloss_uohm,
                     i_distoffset_uohm,
                     l_mv,
                     l_result);

            return  (l_result);
        }
        /// -----------------------------------------------------------------------
        /// @brief Pstate attribute ATTR_SYSTEM_PSTATES_MODE status
        /// @return true/false
        /// -----------------------------------------------------------------------
        bool isPstateModeEnabled()
        {
            return((iv_attrs.attr_pstate_mode != fapi2::ENUM_ATTR_SYSTEM_PSTATES_MODE_OFF) ?
                   true : false);
        } //end of isPstateModeEnabled

        /// -----------------------------------------------------------------------
        /// @brief Get the DCCR value that might have overrides
        /// @return DCCR value to use
        /// -----------------------------------------------------------------------
        uint64_t dccr_value();

        /// -----------------------------------------------------------------------
        /// @brief Get the FLMR value that might have overrides
        /// @return DCCR value to use
        /// -----------------------------------------------------------------------
        uint64_t flmr_value();

        /// -----------------------------------------------------------------------
        /// @brief Get the FMMR value that might have overrides
        /// @return DCCR value to use
        /// -----------------------------------------------------------------------
        uint64_t fmmr_value();

        /// -----------------------------------------------------------------------
        /// @brief Test function to poison #V
        /// @return DCCR value to use
        /// -----------------------------------------------------------------------
        void poison_mvpd_poundV();



    public:
        bool                      iv_init_error;

    private:
        fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > iv_procChip;  // processor chip target
        AttributeList             iv_attrs;
        bool                      iv_boot_mode;
        uint8_t                   iv_pstates_enabled;
        uint8_t                   iv_resclk_enabled;
        uint8_t                   iv_dds_enabled;
        uint8_t                   iv_rvrm_enabled;
        uint8_t                   iv_wof_enabled;
        uint8_t                   iv_wof_disable_vdd;
        uint8_t                   iv_wof_disable_vcs;
        uint8_t                   iv_wof_disable_io;
        uint8_t                   iv_wof_disable_amb;
        uint8_t                   iv_wof_disable_vratio;
        uint32_t                  iv_safe_voltage;    // System safe voltage
        uint32_t                  iv_safe_frequency;  // System safe frequency
        uint32_t                  iv_reference_frequency_mhz;  //System reference frequency
        uint32_t                  iv_reference_frequency_khz;  //System reference frequency
        uint32_t                  iv_frequency_step_khz;  // System step frequency
        uint32_t                  iv_proc_dpll_divider;   // proc dpll divider value
        uint32_t                  iv_occ_freq_mhz;        // OCC frequency
        uint8_t                   iv_wov_underv_enabled;
        uint8_t                   iv_wov_overv_enabled;
        uint8_t                   iv_ocs_enabled;
        uint8_t                   iv_wof_throttle_enabled;
        bool                      iv_optional_pdv_pts_value_zero;
        bool                      iv_poundV_fmax_enable;
        uint16_t                  iv_array_vdn_mv;
        uint16_t                  iv_array_vdd_mv;
        uint8_t                   iv_pdv_model_data;

        PoundVOpPoint_t           iv_operating_points[NUM_VPD_PTS_SET][NUM_PV_POINTS];
        PoundVOpPoint_t           iv_attr_mvpd_poundV_raw[NUM_PV_POINTS];
        PoundVOpPoint_t           iv_attr_mvpd_poundV_biased[NUM_PV_POINTS];
        PoundVOpPoint_t           iv_attr_mvpd_poundV_raw_orig[NUM_PV_POINTS];
        PoundVOpPoint_t           iv_attr_mvpd_data[NUM_PV_POINTS];
        uint8_t                   iv_poundV_bucket_id;

        PoundVBias_t              iv_bias;
        voltageBucketData_t       iv_poundV_raw_data;
        PoundVStaticRails_t       iv_attr_mvpd_poundV_static_rails;
        PoundVOtherInfo_t         iv_attr_mvpd_poundV_other_info;
        PoundW_t                  iv_poundW_data;
        IddqTable_t               iv_iddqt;

        SysPowerDistParms_t       iv_vdd_sysparam;
        SysPowerDistParms_t       iv_vcs_sysparam;
        SysPowerDistParms_t       iv_vdn_sysparam;
        SysPowerDistParms_t       iv_vio_sysparam;

        uint32_t                  iv_vddFmaxFreq;
        uint32_t                  iv_vddPsavFreq;
        uint32_t                  iv_vddWofBaseFreq;
        uint32_t                  iv_vddUTFreq;

        uint64_t                  iv_dccr_value;
        uint64_t                  iv_flmr_value;
        uint64_t                  iv_fmmr_value;

        uint32_t                  iv_vddFixedFreq;
        uint32_t                  iv_sortPower;

        uint32_t                  iv_wts_vddPsavFreq;
        uint32_t                  iv_wts_vddWofBaseFreq;
        uint32_t                  iv_wts_vddUTFreq;
        uint32_t                  iv_wts_vddFixedFreq;
        uint32_t                  iv_wts_sortPower;

        bool                      iv_wts_vddPsavFreqOverride;
        bool                      iv_wts_vddWofBaseFreqOverride;
        bool                      iv_wts_vddUTFreqOverride;
        bool                      iv_wts_vddFixedFreqOverride;
        bool                      iv_wts_sortPowerOverride;
        bool                      iv_wts_sortRdpCurrent;
};

}

/// @typedef p10_pstate_parameter_block_FP_t
/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_pstate_parameter_block_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    PstateSuperStructure*, uint8_t*, uint32_t&);


extern "C"
{
    /// -------------------------------------------------------------------
    /// @brief  Print a GlobalPstateParameterBlock structure on a given stream
    /// @param[in]  i_gppb    pointer to Global Pstate Parameter Block
    /// @return void
    /// -------------------------------------------------------------------
    void
    gppb_print(GlobalPstateParmBlock_t* i_gppb);

    /// -------------------------------------------------------------------
    /// @brief  Print a OCCPstateParameterBlock structure on a given stream
    /// @param[in]  i_oppb    pointer to OCC Pstate Parameter Block
    /// @return void
    /// -------------------------------------------------------------------
    void
    oppb_print(OCCPstateParmBlock_t* i_oppb);

    /// -------------------------------------------------------------------
    /// @brief  Print offsets of PstateSuperStructure contents
    /// @return void
    /// -------------------------------------------------------------------
    void
    print_offsets();

    /// -------------------------------------------------------------------
    /// @brief  Print an iddq_print structure on a given stream
    /// @param[in]  i_iddqt pointer to Iddq structure
    /// @return void
    /// -------------------------------------------------------------------
    void
    iddq_print(IddqTable_t* i_iddqt);

    /// -------------------------------------------------------------------
    /// @brief  Print the WOF Table Header
    /// @param[in]  i_iwfth pointer to wfth structure to output
    /// @return void
    /// -------------------------------------------------------------------
    void
    wfth_print(WofTablesHeader_t* i_wfth);

    /// -------------------------------------------------------------------
    /// @brief Populate Pstate super structure from VPD data
    /// @param[in]    i_target          => Chip Target
    /// @param[inout] *io_pss           => pointer to pstate superstructure
    /// @param[out]   *o_buf            => wof table data
    /// @param[inout] &io_size          => wof table data size
    /// @return   FAPI2::SUCCESS
    /// -------------------------------------------------------------------
    fapi2::ReturnCode
    p10_pstate_parameter_block( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                PstateSuperStructure* io_pss, uint8_t* o_buf, uint32_t& io_size);

} // extern C


#endif  // __P10_PSTATE_PARAMETER_BLOCK_H__
