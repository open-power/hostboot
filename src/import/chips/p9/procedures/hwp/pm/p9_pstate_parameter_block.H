/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pstate_parameter_block.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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

#include <fapi2.H>
#include <p9_pm_utils.H>
#include <p9_pstates_common.h>
#include <p9_pstates_pgpe.h>
#include <p9_pstates_cmeqm.h>
#include <p9_pstates_occ.h>
#include "p9_pm_get_poundv_bucket.H"
#include "p9_pm_get_poundw_bucket.H"
#include <p9_hcd_memmap_base.H>

//Pstate SuperStructure
typedef struct
{
    /// Magic Number
    uint64_t magic;

    // PGPE content
    GlobalPstateParmBlock globalppb;

    // CME content
    LocalPstateParmBlock localppb[MAX_QUADS_PER_CHIP];

    // OCC content
    OCCPstateParmBlock occppb;

} PstateSuperStructure;

//VDD Voltage config actions
typedef enum
{
    COMPUTE_VOLTAGE_SETTINGS,
    APPLY_VOLTAGE_SETTINGS
} VoltageConfigActions_t;


namespace pm_pstate_parameter_block
{



using namespace fapi2;
//VPD types
typedef enum VPD_TYPE
{
    RAW,
    BIASED,
} vpd_type;

//Frequency actions
enum FREQ2PSTATE_ROUNDING
{
    ROUND_FAST,
    ROUND_SLOW
};

#define BIAS_PCT_UNIT              0.5

//Safe mode parameters
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

    uint32_t attr_freq_dpll_refclock_khz;
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

} AttributeList;


//PlatPmPPB Object definition
class PlatPmPPB
{
    public:
        //Constructor with Proc target as input
        PlatPmPPB ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> i_target ) :
            iv_procChip (i_target), iv_pstates_enabled(0), iv_resclk_enabled(0),
            iv_vdm_enabled(0), iv_ivrm_enabled(0), iv_wof_enabled(0), iv_safe_voltage (0),
            iv_safe_frequency(0), iv_reference_frequency_mhz(0), iv_reference_frequency_khz(0),
            iv_frequency_step_khz(0), iv_proc_dpll_divider(0), iv_nest_freq_mhz(0),
            iv_wov_underv_enabled(0), iv_wov_overv_enabled(0)

        {
            attr_init();
        }

        /// -----------------------------------------------------------------------
        /// @brief Initialize pstate attributes
        /// @return none
        /// -----------------------------------------------------------------------
        void attr_init();

        /// -----------------------------------------------------------------------
        /// @brief Initialize VPD data
        //  @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode vpd_init();

        /// -----------------------------------------------------------------------
        /// @brief Initialize resclk data
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode resclk_init();

        /// -----------------------------------------------------------------------
        /// @brief Initialize WOF data
        /// @param[out]     o_buf points to WOF data
        /// @param[inout]   io_size size of the wof  table
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode wof_init(
            uint8_t* o_buf,
            uint32_t& io_size);

        /// -----------------------------------------------------------------------
        /// @brief Initialize global pstate parameter block
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode gppb_init( GlobalPstateParmBlock* i_globalppb);

        /// -----------------------------------------------------------------------
        /// @brief Initialize local pstate parameter block
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode lppb_init(LocalPstateParmBlock* i_localppb);

        /// -----------------------------------------------------------------------
        /// @brief Initialize occ pstate parameter block
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode oppb_init(OCCPstateParmBlock* i_occppb);

        /// -----------------------------------------------------------------------
        /// @brief VDM initializtion based on #W data
        /// @return none
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode vdm_init( void );

        /// -----------------------------------------------------------------------
        /// @brief Safe mode frquency and voltage init
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode safe_mode_init( void );

        /// -----------------------------------------------------------------------
        /// @brief VFRT data initialization from WOF data
        /// @param[in]     i_pBuffer WOF data buffer
        /// @param[inout]  o_vfrt_data  vfrt data
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode update_vfrt(
            uint8_t* i_pBuffer,
            HomerVFRTLayout_t* o_vfrt_data);

        /// -----------------------------------------------------------------------
        /// @brief Compute and apply biased values
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode get_extint_bias();

        /// -----------------------------------------------------------------------
        /// @brief apply biased values for #V data
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode apply_biased_values();

        /// -----------------------------------------------------------------------
        /// @brief Read IQ vpd data
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode get_mvpd_iddq( void );

        /// -----------------------------------------------------------------------
        /// @brief Read #W(VDM) vpd data
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode get_mvpd_poundW (void);

        /// -----------------------------------------------------------------------
        /// @brief Read IVRM data from attributes
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode get_ivrm_parms ();

        /// -----------------------------------------------------------------------
        /// @brief Set resclk attribute values
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode set_resclk_table_attrs();

        /// -----------------------------------------------------------------------
        /// @brief Compute and setup resclk values
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode res_clock_setup (void);

        /// -----------------------------------------------------------------------
        /// @brief Compute VDM freq drop values
        /// @return none
        /// -----------------------------------------------------------------------
        void large_jump_defaults();

        /// -----------------------------------------------------------------------
        /// @brief Compute safe mode values
        /// @param[in]    i_action  voltage config action (Compute/set)
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode compute_boot_safe(
            const VoltageConfigActions_t i_action);

        /// -----------------------------------------------------------------------
        /// @brief This fills up the PStateVSlopes and VPStatesSlopes in
        ///         GlobalParmBlock
        /// @param[out]     o_gppb  global PPB data
        /// @return none
        /// -----------------------------------------------------------------------
        void compute_PStateV_slope(GlobalPstateParmBlock* o_gppb);

        /// -----------------------------------------------------------------------
        /// @brief This will set the pstate feature attrbutes(VDM,RESCLK,VRM,WOF)
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode set_global_feature_attributes();

        /// -----------------------------------------------------------------------
        /// @brief State of WOF Undervolt
        /// @return enabled(true)/disabled (false)
        /// -----------------------------------------------------------------------
        bool is_wov_underv_enabled();

        /// -----------------------------------------------------------------------
        /// @brief State of WOF Overvolt
        /// @return enabled(true)/disabled (false)
        /// -----------------------------------------------------------------------
        bool is_wov_overv_enabled();

        /// -----------------------------------------------------------------------
        /// @brief State of WOF feature
        /// @return enabled(true)/disabled (false)
        /// -----------------------------------------------------------------------
        bool is_wof_enabled();

        /// -----------------------------------------------------------------------
        /// @brief State of VDM feature
        /// @return enabled(true)/disabled (false)
        /// -----------------------------------------------------------------------
        bool is_vdm_enabled();

        /// -----------------------------------------------------------------------
        /// @brief Initialize #v vpd points for both raw/biased
        /// @param[in]     i_state RAW/BIASED
        /// @return none
        /// -----------------------------------------------------------------------
        void load_mvpd_operating_point (vpd_type i_state);

        /// -----------------------------------------------------------------------
        /// @brief Read #V data form module vpd
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode get_mvpd_poundV();

        /// -----------------------------------------------------------------------
        /// @brief Validate #V data
        /// @param[in]     i_biased_state present/nonpresent
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode chk_valid_poundv(
            const bool i_biased_state);

        /// -----------------------------------------------------------------------
        /// @brief Compute VPD points of different regions
        /// @return none
        /// -----------------------------------------------------------------------
        void compute_vpd_pts();

        /// -----------------------------------------------------------------------
        /// @brief Converts frequency value to pstate number
        /// @param[in]     i_freq_khz input frequency
        /// @param[out]    pstate pstate output for a given inut frequency
        /// @param[in]     i_round p-state rounding strategy
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        int freq2pState (const uint32_t freq_khz,
                         Pstate* pstate,
                         const FREQ2PSTATE_ROUNDING i_round = ROUND_SLOW);

        /// -----------------------------------------------------------------------
        /// @brief Compute safe mode values
        /// @param[in]     i_ps_state  pstate value
        /// @param[out]    o_safe_mode_values safe mode freq/voltage values
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode safe_mode_computation(
            const Pstate i_ps_pstate,
            Safe_mode_parameters* o_safe_mode_values);

        /// -----------------------------------------------------------------------
        /// @brief Convert pstate to voltage
        /// @param[in]     i_pstate  pstate value that needs to be converted
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        uint32_t ps2v_mv(const Pstate i_pstate);

        /// -----------------------------------------------------------------------
        /// @brief Compute VDM jump values for a given pstate
        /// @param[in]     i_pstate  pstate value
        /// @return none
        /// -----------------------------------------------------------------------
        void compute_PsVDMJumpSlopes(
            uint8_t* i_pstate);

        /// -----------------------------------------------------------------------
        /// @brief Compute VDM threshold values for a given pstate
        /// @param[in]     i_pstate  pstate value
        /// @return none
        /// -----------------------------------------------------------------------
        void compute_PsVDMThreshSlopes(
            uint8_t* i_pstate);

        /// -----------------------------------------------------------------------
        /// @brief Compute VID compare slope values for a given pstate
        /// @param[in]     i_pstate  pstate value
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode compute_PsVIDCompSlopes_slopes(
            uint8_t* i_pstate);

        /// -----------------------------------------------------------------------
        /// @brief Compute VDM threshold points for different regions
        /// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
        /// -----------------------------------------------------------------------
        fapi2::ReturnCode compute_vdm_threshold_pts();

        /// -----------------------------------------------------------------------
        /// @brief Compute bias value for pre-defined percentage unit
        /// @param[in]     i_value Biased value
        /// @return bias value
        /// -----------------------------------------------------------------------
        double calc_bias(const int8_t i_value)
        {
            double temp = 1.0 + ((BIAS_PCT_UNIT / 100) * (double)i_value);
            FAPI_DBG("    calc_bias: input bias (in 1/2 percent) = %d; percent = %4.1f%% biased multiplier = %6.3f",
                     i_value, (i_value * BIAS_PCT_UNIT), temp);
            return temp;
        }

        /// -----------------------------------------------------------------------
        /// @brief Compute smallest value for a given input
        /// @param[in]     x value
        /// @return smallest value
        /// -----------------------------------------------------------------------
        double internal_ceil(double x)
        {
            if ((x - (int)(x)) > 0)
            {
                return (int)x + 1;
            }

            return ((int)x);
        }

        /// -----------------------------------------------------------------------
        /// @brief Compute largest value for a given input
        /// @param[in]     x value
        /// @return largest value
        /// -----------------------------------------------------------------------
        double internal_floor(double x)
        {
            if(x >= 0)
            {
                return (int)x;
            }

            return (int)(x - 0.9999999999999999);
        }

        /// -----------------------------------------------------------------------
        /// @brief Adjust bias value for given vdd/vcs voltage
        /// @param[in]     i_value vdd/vcs value
        /// @param[in]     i_bias_0p5pct  bias value
        /// @return computed biase value
        /// -----------------------------------------------------------------------
        uint32_t bias_adjust_mv(const uint32_t i_value,
                                const int32_t i_bias_0p5pct)
        {
            double l_mult = calc_bias(i_bias_0p5pct);
            double l_biased_value = (double)i_value * l_mult;
            double l_ceiling = internal_ceil(l_biased_value);
            uint32_t l_result = (uint32_t)l_ceiling;
            FAPI_DBG("  bias_adjust_mv:  i_value=%d; mult=%5.3f; biased value=%3.0f ceiling = %3.0f result = %d",
                     i_value,
                     l_mult,
                     l_biased_value,
                     l_ceiling,
                     l_result);
            return (l_result);
        }

        /// -----------------------------------------------------------------------
        /// @brief Adjust bias value for given frequency value
        /// @param[in]     i_value  frequency value
        /// @param[in]     i_bias_0p5pct  bias value
        /// @return computed biase value
        /// -----------------------------------------------------------------------
        uint32_t bias_adjust_mhz(const uint32_t i_value,
                                 const int32_t i_bias_0p5pct)
        {
            double l_mult = calc_bias(i_bias_0p5pct);
            double l_biased_value = (double)i_value * l_mult;
            FAPI_DBG("  bias_adjust_mhz: i_value=%d; mult=%5.3f; biased value=%3.0f",
                     i_value,
                     l_mult,
                     l_biased_value);
            return ((uint32_t)internal_floor(l_biased_value));
        }

        /// -----------------------------------------------------------------------
        /// @brief Compute slope threshold points
        /// @param[in]     y1    jump/threshold value of nominal
        /// @param[in]     y0    jump/threshold value of powersave
        /// @param[in]     x1    pstate value of powersave
        /// @param[in]     x0    pstate value of nominal
        /// @return computed slope threshold value
        /// -----------------------------------------------------------------------
        int16_t compute_slope_thresh(int32_t y1, int32_t y0, int32_t x1, int32_t x0)
        {
            return (int16_t)
                   (
                       // Perform division using double for maximum precision
                       // Store resulting slope in 4.12 Fixed-Pt format
                       ((double)(y1 - y0) / (double)(x1 - x0)) * (1 << THRESH_SLOPE_FP_SHIFT)
                   );
        }

        /// -----------------------------------------------------------------------
        /// @brief Compute slope values for fixed point of shift 4.12
        /// @param[in]     y1    pstate value of powersave
        /// @param[in]     y0    pstate value of nominal
        /// @param[in]     x1    VDD value of nominal
        /// @param[in]     x0    VDD value of powersave
        /// @return computed slope threshold value
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
            double l_mv = ((double)i_vpd_mv +  // mV
                           (
                               // mA*uOhm/1000 -> uV
                               ((double)(i_vpd_ma * (i_loadline_uohm + i_distloss_uohm)) / 1000 +
                                // uv
                                (double)i_distoffset_uohm)
                           ) / 1000);  // uV -> mV
            uint32_t l_result = (uint32_t)l_mv;
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
        bool isPstateModeEnabled();

        /// -----------------------------------------------------------------------
        /// @brief EQ chiplet state
        /// @return true/false
        /// -----------------------------------------------------------------------
        bool isEqChipletPresent ();

        /// -----------------------------------------------------------------------
        /// @brief Compute jump interpolate
        /// @param[in]     i_pstate  Safe mode pstate
        /// @param[in]     i_ps_pstate power save pstate
        /// @return vdm jump value
        /// -----------------------------------------------------------------------
        uint32_t large_jump_interpolate(const Pstate i_pstate,
                                        const Pstate i_ps_pstate);

        /// -----------------------------------------------------------------------
        /// @brief Get pstate attribute data
        /// @param[out]    o_attr  populate attribute list data
        /// @return none
        /// -----------------------------------------------------------------------
        void get_pstate_attrs(AttributeList* o_attr);
#if 0
        void print_raw_poundV_points()
        {
            for (int i = 0; i <= NUM_OP_POINTS - 1; i++)
            {
                FAPI_DBG("Raw #V operating point (%s) f=%u v=%u i=%u v=%u i=%u",
                         pv_op_str[pv_op_order[i]],
                         iv_attr_mvpd_poundV_raw[pv_op_order[i]].frequency_mhz,
                         iv_attr_mvpd_poundV_raw[pv_op_order[i]].vdd_mv,
                         iv_attr_mvpd_poundV_raw[pv_op_order[i]].idd_100ma,
                         iv_attr_mvpd_poundV_raw[pv_op_order[i]].vcs_mv,
                         iv_attr_mvpd_poundV_raw[pv_op_order[i]].ics_100ma);
            }
        }
#endif

    private: //function
        fapi2::ReturnCode validate_quad_spec_data( );

    private: //data
        fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > iv_procChip;  // processor chip target
        AttributeList             iv_attrs;           // Pstate attributes list
        VpdOperatingPoint         iv_raw_vpd_pts[NUM_OP_POINTS];  // Raw vpd operating points
        VpdOperatingPoint         iv_biased_vpd_pts[NUM_OP_POINTS]; // Biased vpd operating points
        VpdOperatingPoint         iv_operating_points[NUM_VPD_PTS_SET][NUM_OP_POINTS];
        SysPowerDistParms         iv_vdd_sysparam; //VDD,VDN,VCS
        SysPowerDistParms         iv_vdn_sysparam; //VDD,VDN,VCS
        SysPowerDistParms         iv_vcs_sysparam; //VDD,VDN,VCS
        VpdBias                   iv_bias[NUM_OP_POINTS];
        Safe_mode_parameters      iv_safe_mode_values;
        uint8_t                   iv_pstates_enabled;
        uint8_t                   iv_resclk_enabled;
        uint8_t                   iv_vdm_enabled;
        uint8_t                   iv_ivrm_enabled;
        uint8_t                   iv_wof_enabled;
        uint32_t                  iv_safe_voltage;    // System safe voltage
        uint32_t                  iv_safe_frequency;  // System safe frequency
        uint32_t                  iv_reference_frequency_mhz;  //System reference frequency
        uint32_t                  iv_reference_frequency_khz;  //System reference frequency
        uint32_t                  iv_frequency_step_khz;   // System step frequency
        uint32_t                  iv_proc_dpll_divider;   // proc dpll divider value
        uint32_t                  iv_nest_freq_mhz;       //Nest frequency
        uint8_t                   iv_poundV_bucket_id;
        uint8_t                   iv_eq_chiplet_state;
        uint8_t                   iv_valid_pdv_points;

        voltageBucketData_t       iv_poundV_raw_data;
        voltageBucketData_t       iv_poundV_biased_data;
        VpdPoint                  iv_attr_mvpd_poundV_raw[5];
        VpdPoint                  iv_attr_mvpd_poundV_biased[5];

        PoundW_data_per_quad      iv_poundW_data;
        IddqTable                 iv_iddqt;
        GP_VDMParmBlock           iv_vdmpb;
        IvrmParmBlock             iv_ivrmpb;
        ResonantClockingSetup     iv_resclk_setup;
        CompareVIDPoints          iv_vid_point_set[MAX_QUADS_PER_CHIP][NUM_OP_POINTS];
        uint8_t                   iv_threshold_set[NUM_OP_POINTS][NUM_THRESHOLD_POINTS];
        int16_t                   iv_PsVIDCompSlopes[MAX_QUADS_PER_CHIP][VPD_NUM_SLOPES_REGION];
        int16_t                   iv_PsVDMThreshSlopes[VPD_NUM_SLOPES_REGION][NUM_THRESHOLD_POINTS];
        uint8_t                   iv_jump_value_set[NUM_OP_POINTS][NUM_JUMP_VALUES];
        int16_t                   iv_PsVDMJumpSlopes[VPD_NUM_SLOPES_REGION][NUM_JUMP_VALUES];
        uint8_t                   iv_wov_underv_enabled;
        uint8_t                   iv_wov_overv_enabled;
};

}

/// @typedef p9_pstate_parameter_block_FP_t
/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pstate_parameter_block_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    PstateSuperStructure*, uint8_t*, uint32_t&);


extern "C"
{
/// -------------------------------------------------------------------
/// @brief  Print a GlobalPstateParameterBlock structure on a given stream
/// @param[in]  i_gppb    The Global Pstate Parameter Block to print
/// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// -------------------------------------------------------------------
    fapi2::ReturnCode gppb_print(GlobalPstateParmBlock* i_gppb,
                                 const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target );


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




/// -------------------------------------------------------------------
/// @brief Populate Pstate super structure from VPD data
/// @param[in]    i_target          => Chip Target
/// @param[inout] *io_pss           => pointer to pstate superstructure
/// @param[out]   *o_buf            => wof table data
/// @param[inout] &io_size          => wof table data size
/// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// -------------------------------------------------------------------
    fapi2::ReturnCode
    p9_pstate_parameter_block( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                               PstateSuperStructure* io_pss, uint8_t* o_buf, uint32_t& io_size);

} // extern C


#endif  // __P9_PSTATE_PARAMETER_BLOCK_H__

