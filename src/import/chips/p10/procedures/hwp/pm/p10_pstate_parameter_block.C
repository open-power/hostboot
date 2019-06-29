/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pstate_parameter_block.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file  p10_pstate_parameter_block.C
/// @brief Setup Pstate super structure for PGPE/CME HCode
///
/// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner        : Prasad Bg Ranganath <prasadbgr@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 2
/// *HWP Consumed by     : HB,PGPE,CME,OCC
///
/// @verbatim
/// Procedure Summary:
///   - Read VPD and attributes to create the Pstate Parameter Block(s) (one each for PGPE,OCC and CMEs).
/// @endverbatim

// *INDENT-OFF*
//
// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p10_pstate_parameter_block.H>
#include <p10_pm_utils.H>

using namespace pm_pstate_parameter_block;

#define IQ_BUFFER_ALLOC            255
#define PSTATE_MAX                 255
#define PSTATE_MIN                 0
#define PROC_PLL_DIVIDER           8
#define CF1_3_PERCENTAGE           0.33
#define CF2_4_PERCENTAGE           0.50

#define POUNDV_POINT_CALC(X,Y,Z)     (( (Y - X) * Z) + X)


#define POUNDV_POINTS_CHECK(i) \
                (iv_attr_mvpd_data[i].frequency_mhz == 0 || \
                 iv_attr_mvpd_data[i].vdd_mv        == 0 || \
                 iv_attr_mvpd_data[i].idd_tdp_ac_10ma == 0 || \
                 iv_attr_mvpd_data[i].idd_tdp_dc_10ma == 0 || \
                 iv_attr_mvpd_data[i].idd_rdp_ac_10ma == 0 || \
                 iv_attr_mvpd_data[i].idd_rdp_dc_10ma == 0 || \
                 iv_attr_mvpd_data[i].vcs_mv          == 0 || \
                 iv_attr_mvpd_data[i].ics_tdp_ac_10ma == 0 || \
                 iv_attr_mvpd_data[i].ics_tdp_dc_10ma == 0 || \
                 iv_attr_mvpd_data[i].frequency_guardband_sort_mhz == 0 || \
                 iv_attr_mvpd_data[i].vdd_vmin == 0 || \
                 iv_attr_mvpd_data[i].idd_power_pattern_10ma == 0 || \
                 iv_attr_mvpd_data[i].core_power_pattern_temp_0p5C == 0)

#define POUNDV_POINTS_PRINT(i,suffix)   \
                  .set_FREQUENCY_##suffix(iv_attr_mvpd_data[i].frequency_mhz)  \
                  .set_VDD_##suffix(iv_attr_mvpd_data[i].vdd_mv) \
                 .set_IDD_TDP_AC_##suffix(iv_attr_mvpd_data[i].idd_tdp_ac_10ma) \
                 .set_IDD_TDP_DC_##suffix(iv_attr_mvpd_data[i].idd_tdp_dc_10ma) \
                 .set_IDD_RDP_AC_##suffix(iv_attr_mvpd_data[i].idd_rdp_ac_10ma) \
                 .set_IDD_RDP_DC_##suffix(iv_attr_mvpd_data[i].idd_rdp_dc_10ma) \
                 .set_VCS_##suffix(iv_attr_mvpd_data[i].vcs_mv) \
                 .set_ICS_TDP_AC_##suffix(iv_attr_mvpd_data[i].ics_tdp_ac_10ma) \
                 .set_ICS_TDP_DC_##suffix(iv_attr_mvpd_data[i].ics_tdp_dc_10ma) \
                 .set_FREQ_GB_SORT_##suffix(iv_attr_mvpd_data[i].frequency_guardband_sort_mhz) \
                 .set_VDD_VMIN_##suffix(iv_attr_mvpd_data[i].vdd_vmin) \
                 .set_IDD_POWR_##suffix(iv_attr_mvpd_data[i].idd_power_pattern_10ma) \
                 .set_CORE_POWR_TEMP_##suffix(iv_attr_mvpd_data[i].core_power_pattern_temp_0p5C)

//w => N_L (w > 7 is invalid)
//x => N_S (x > N_L is invalid)
//y => L_S (y > (N_L - S_N) is invalid)
//z => S_N (z > N_S is invalid
#define VALIDATE_FREQUENCY_DROP_VALUES(w, x, y, z, state) \
    if ((w > 7)         ||      \
        (x > w)         ||      \
        (y > (w - z))   ||      \
        (z > x)         ||      \
        ((w | x | y | z) == 0)) \
    { state = 0; }

#define POUNDV_SLOPE_CHECK(x,y)   x > y ? " is GREATER (ERROR!) than " : " is less than "


#include <fapi2.H>
#include <p10_pstate_parameter_block.H>

using namespace pm_pstate_parameter_block;

///////////////////////////////////////////////////////////
////////     p10_pstate_parameter_block
///////////////////////////////////////////////////////////
fapi2::ReturnCode
p10_pstate_parameter_block( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                           PstateSuperStructure* io_pss,
                           uint8_t* o_buf,
                           uint32_t& io_size)
{
    FAPI_DBG("> p10_pstate_parameter_block");

    //Instantiate pstate object
    PlatPmPPB l_pmPPB(i_target);

    FAPI_ASSERT(l_pmPPB.iv_init_error == false,
                fapi2::PSTATE_PB_ATTRIBUTE_ACCESS_ERROR()
                .set_CHIP_TARGET(i_target),
                "Pstate Parameter Block attribute access error");

fapi_try_exit:
    FAPI_DBG("< p10_pstate_parameter_block");
    return fapi2::current_err;
}
// END OF PSTATE PARAMETER BLOCK function

///////////////////////////////////////////////////////////
////////  attr_init 
///////////////////////////////////////////////////////////
void PlatPmPPB::attr_init( void )
{
    const uint32_t EXT_VRM_TRANSITION_START_NS = 8000;
    const uint32_t EXT_VRM_TRANSITION_RATE_INC_UV_PER_US = 10000;
    const uint32_t EXT_VRM_TRANSITION_RATE_DEC_UV_PER_US = 10000;
    const uint32_t EXT_VRM_STABILIZATION_TIME_NS = 5;
    const uint32_t EXT_VRM_STEPSIZE_MV = 50;

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    // --------------------------
    // attributes not yet defined
    // --------------------------
    iv_attrs.attr_dpll_bias                 = 0;
    iv_attrs.attr_undervolting              = 0;

    // ---------------------------------------------------------------
    // set ATTR_PROC_DPLL_DIVIDER
    // ---------------------------------------------------------------
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_DPLL_DIVIDER, iv_procChip,
                           iv_attrs.attr_proc_dpll_divider), "fapiGetAttribute of ATTR_PROC_DPLL_DIVIDER failed");

    // If value is 0, set a default
    if (!iv_attrs.attr_proc_dpll_divider)
    {
        FAPI_DBG("ATTR_PROC_DPLL_DIVIDER - setting default to 0x%x", iv_attrs.attr_proc_dpll_divider);
        iv_attrs.attr_proc_dpll_divider = PROC_PLL_DIVIDER;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_DPLL_DIVIDER, iv_procChip,
                               iv_attrs.attr_proc_dpll_divider), "fapiSetAttribute of ATTR_PROC_DPLL_DIVIDER failed");
    }

    FAPI_INF("ATTR_PROC_DPLL_DIVIDER - 0x%x", iv_attrs.attr_proc_dpll_divider);

    // ----------------------------
    // attributes currently defined
    // ----------------------------

#define DATABLOCK_GET_ATTR(attr_name, target, attr_assign) \
FAPI_TRY(FAPI_ATTR_GET(fapi2::attr_name, target, iv_attrs.attr_assign),"Attribute read failed"); \
FAPI_INF("%-60s = 0x%08x %d", #attr_name, iv_attrs.attr_assign, iv_attrs.attr_assign);

#define DATABLOCK_GET_ATTR_2(attr_name, target, attr_assign) \
FAPI_TRY(FAPI_ATTR_GET(fapi2::attr_name, target, iv_attrs.attr_assign),"Attribute read failed"); \
FAPI_INF("%-60s[0] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[0], iv_attrs.attr_assign[0]);\
FAPI_INF("%-60s[1] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[1], iv_attrs.attr_assign[1]);

#define DATABLOCK_GET_ATTR_4(attr_name, target, attr_assign) \
FAPI_TRY(FAPI_ATTR_GET(fapi2::attr_name, target, iv_attrs.attr_assign),"Attribute read failed"); \
FAPI_INF("%-60s[0] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[0], iv_attrs.attr_assign[0]);\
FAPI_INF("%-60s[1] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[1], iv_attrs.attr_assign[1]);\
FAPI_INF("%-60s[2] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[2], iv_attrs.attr_assign[2]);\
FAPI_INF("%-60s[3] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[3], iv_attrs.attr_assign[3]);


    // Frequency Bias attributes
    DATABLOCK_GET_ATTR(ATTR_FREQ_BIAS, iv_procChip, attr_freq_bias);

    // Voltage Bias attributes
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_BIAS, iv_procChip, attr_voltage_ext_bias);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VDN_BIAS, iv_procChip, attr_voltage_ext_vdn_bias);
    DATABLOCK_GET_ATTR(ATTR_EXTERNAL_VRM_STEPSIZE, FAPI_SYSTEM, attr_ext_vrm_step_size_mv);
    DATABLOCK_GET_ATTR(ATTR_EXTERNAL_VRM_TRANSITION_RATE_DEC_UV_PER_US, 
                       FAPI_SYSTEM, attr_ext_vrm_transition_rate_dec_uv_per_us);
    DATABLOCK_GET_ATTR(ATTR_EXTERNAL_VRM_TRANSITION_RATE_INC_UV_PER_US, 
                       FAPI_SYSTEM, attr_ext_vrm_transition_rate_inc_uv_per_us);
    DATABLOCK_GET_ATTR(ATTR_EXTERNAL_VRM_TRANSITION_STABILIZATION_TIME_NS, 
                       FAPI_SYSTEM, attr_ext_vrm_stabilization_time_us);
    DATABLOCK_GET_ATTR(ATTR_EXTERNAL_VRM_TRANSITION_START_NS, 
                       FAPI_SYSTEM, attr_ext_vrm_transition_start_ns);

    DATABLOCK_GET_ATTR(ATTR_SAFE_MODE_FREQUENCY_MHZ,iv_procChip, attr_pm_safe_frequency_mhz);
    DATABLOCK_GET_ATTR_2(ATTR_SAFE_MODE_VOLTAGE_MV,   iv_procChip, attr_pm_safe_voltage_mv);
    DATABLOCK_GET_ATTR_2(ATTR_SAVE_MODE_NODDS_UPLIFT_MV,   iv_procChip, attr_save_mode_nodds_uplift_mv);

    // AVSBus ... needed by p10_setup_evid
    DATABLOCK_GET_ATTR_4(ATTR_AVSBUS_BUSNUM, iv_procChip, attr_avs_bus_num);
    DATABLOCK_GET_ATTR_4(ATTR_AVSBUS_RAIL,   iv_procChip, attr_avs_bus_rail_select);
    DATABLOCK_GET_ATTR_4(ATTR_BOOT_VOLTAGE, iv_procChip, attr_boot_voltage_mv);
    DATABLOCK_GET_ATTR(ATTR_AVSBUS_FREQUENCY, iv_procChip, attr_avs_bus_freq);
    DATABLOCK_GET_ATTR_4(ATTR_PROC_R_DISTLOSS_UOHM, iv_procChip, attr_proc_r_distloss_uohm);
    DATABLOCK_GET_ATTR_4(ATTR_PROC_R_LOADLINE_UOHM, iv_procChip, attr_proc_r_loadline_uohm);
    DATABLOCK_GET_ATTR_4(ATTR_PROC_VRM_VOFFSET_UV,  iv_procChip, attr_proc_vrm_voffset_uv);
    DATABLOCK_GET_ATTR(ATTR_BOOT_VOLTAGE_BIAS_0P5PCT,  iv_procChip, attr_boot_voltage_biase_0p5pct);


    // Frequency attributes
    DATABLOCK_GET_ATTR(ATTR_FREQ_PAU_MHZ,            FAPI_SYSTEM, attr_nest_frequency_mhz);
    DATABLOCK_GET_ATTR(ATTR_FREQ_CORE_CEILING_MHZ,  iv_procChip, attr_freq_core_ceiling_mhz);
    DATABLOCK_GET_ATTR(ATTR_FREQ_CORE_FLOOR_MHZ,    iv_procChip, attr_freq_core_floor_mhz);

    // Loadline, Distribution loss and Distribution offset attributes

    // Read IVRM,WOF and DPLL attributes
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_WOF_DISABLE,    FAPI_SYSTEM, attr_system_wof_disable);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_DDS_DISABLE,    FAPI_SYSTEM, attr_system_dds_disable);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_RESCLK_DISABLE, FAPI_SYSTEM, attr_resclk_disable);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_PSTATES_MODE,   FAPI_SYSTEM, attr_pstate_mode);

    //TBD
    //DATABLOCK_GET_ATTR(ATTR_CHIP_EC_FEATURE_WOF_NOT_SUPPORTED, iv_procChip, attr_dd_wof_not_supported);


    //TBD
    //DATABLOCK_GET_ATTR(ATTR_FREQ_PROC_REFCLOCK_KHZ,   FAPI_SYSTEM, freq_proc_refclock_khz);
    DATABLOCK_GET_ATTR(ATTR_PROC_DPLL_DIVIDER,        iv_procChip, proc_dpll_divider);
    // AVSBus ... needed by p10_setup_evid
    //Get WOV attributes
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_WOV_OVERV_DISABLE,        FAPI_SYSTEM,attr_wov_overv_disable);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_WOV_UNDERV_DISABLE,       FAPI_SYSTEM,attr_wov_underv_disable);
    DATABLOCK_GET_ATTR(ATTR_WOV_SAMPLE_125US,               iv_procChip,attr_wov_sample_125us);
    DATABLOCK_GET_ATTR(ATTR_WOV_MAX_DROOP_10THPCT,          iv_procChip,attr_wov_max_droop_pct);
    DATABLOCK_GET_ATTR(ATTR_WOV_UNDERV_PERF_LOSS_THRESH_10THPCT, iv_procChip,attr_wov_underv_perf_loss_thresh_pct);
    DATABLOCK_GET_ATTR(ATTR_WOV_UNDERV_STEP_INCR_10THPCT,   iv_procChip,attr_wov_underv_step_incr_pct);
    DATABLOCK_GET_ATTR(ATTR_WOV_UNDERV_STEP_DECR_10THPCT,   iv_procChip,attr_wov_underv_step_decr_pct);
    DATABLOCK_GET_ATTR(ATTR_WOV_UNDERV_MAX_10THPCT,         iv_procChip,attr_wov_underv_max_pct);
    DATABLOCK_GET_ATTR(ATTR_WOV_UNDERV_VMIN_MV,             iv_procChip,attr_wov_underv_vmin_mv);
    DATABLOCK_GET_ATTR(ATTR_WOV_OVERV_VMAX_SETPOINT_MV,     iv_procChip,attr_wov_overv_vmax_mv);
    DATABLOCK_GET_ATTR(ATTR_WOV_OVERV_STEP_INCR_10THPCT,    iv_procChip,attr_wov_overv_step_incr_pct);
    DATABLOCK_GET_ATTR(ATTR_WOV_OVERV_STEP_DECR_10THPCT,    iv_procChip,attr_wov_overv_step_decr_pct);
    DATABLOCK_GET_ATTR(ATTR_WOV_OVERV_MAX_10THPCT,          iv_procChip,attr_wov_overv_max_pct);



    // Deal with defaults if attributes are not set
#define SET_DEFAULT(_attr_name, _attr_default) \
    if (!(iv_attrs._attr_name)) \
    { \
       iv_attrs._attr_name = _attr_default; \
       FAPI_INF("Setting %-44s = 0x%08x %d (internal default)", \
                #_attr_name, iv_attrs._attr_name, iv_attrs._attr_name); \
    }

    SET_DEFAULT(attr_freq_proc_refclock_khz, 133333);
    SET_DEFAULT(freq_proc_refclock_khz,      133333); // Future: collapse this out
    SET_DEFAULT(attr_ext_vrm_transition_start_ns, EXT_VRM_TRANSITION_START_NS)
    SET_DEFAULT(attr_ext_vrm_transition_rate_inc_uv_per_us, EXT_VRM_TRANSITION_RATE_INC_UV_PER_US)
    SET_DEFAULT(attr_ext_vrm_transition_rate_dec_uv_per_us, EXT_VRM_TRANSITION_RATE_DEC_UV_PER_US)
    SET_DEFAULT(attr_ext_vrm_stabilization_time_us, EXT_VRM_STABILIZATION_TIME_NS)
    SET_DEFAULT(attr_ext_vrm_step_size_mv, EXT_VRM_STEPSIZE_MV)


    SET_DEFAULT(attr_wov_sample_125us, 2);
    SET_DEFAULT(attr_wov_max_droop_pct, 125);
    SET_DEFAULT(attr_wov_overv_step_incr_pct, 5);
    SET_DEFAULT(attr_wov_overv_step_decr_pct, 5);
    SET_DEFAULT(attr_wov_overv_max_pct, 0);
    SET_DEFAULT(attr_wov_overv_vmax_mv, 1150);
    SET_DEFAULT(attr_wov_underv_step_incr_pct, 5);
    SET_DEFAULT(attr_wov_underv_step_decr_pct, 5);
    SET_DEFAULT(attr_wov_underv_max_pct, 100);
    SET_DEFAULT(attr_wov_underv_perf_loss_thresh_pct, 5);


    //Ensure that the ranges for WOV attributes are honored
    if (iv_attrs.attr_wov_sample_125us < 2) {
        iv_attrs.attr_wov_sample_125us = 2;
    }

    if(iv_attrs.attr_wov_overv_step_incr_pct > 20) {
        iv_attrs.attr_wov_overv_step_incr_pct = 20;
    }

    if(iv_attrs.attr_wov_overv_step_decr_pct > 20) {
        iv_attrs.attr_wov_overv_step_decr_pct = 20;
    }

    if(iv_attrs.attr_wov_overv_max_pct > 100) {
        iv_attrs.attr_wov_overv_max_pct = 100;
    }

    if(iv_attrs.attr_wov_underv_step_incr_pct > 20) {
        iv_attrs.attr_wov_underv_step_incr_pct = 20;
    }

    if(iv_attrs.attr_wov_underv_step_decr_pct > 20) {
        iv_attrs.attr_wov_underv_step_decr_pct = 20;
    }

    if(iv_attrs.attr_wov_underv_max_pct < 10) {
        iv_attrs.attr_wov_underv_step_decr_pct = 10;
    }

    if (iv_attrs.attr_wov_underv_perf_loss_thresh_pct > 20) {
        iv_attrs.attr_wov_underv_perf_loss_thresh_pct = 20;
    }

    // Deal with critical attributes that are not set and that any defaults chosen
    // could well be very wrong
    FAPI_ASSERT(iv_attrs.attr_nest_frequency_mhz,
                fapi2::PSTATE_PB_NEST_FREQ_EQ_ZERO()
                .set_CHIP_TARGET(iv_procChip),
                "ATTR_FREQ_PAU_MHZ has a zero value");

    // -----------------------------------------------
    // System power distribution parameters
    // -----------------------------------------------
    // VDD rail
    iv_vdd_sysparam.loadline_uohm = revle32(iv_attrs.attr_proc_r_loadline_uohm[0]);
    iv_vdd_sysparam.distloss_uohm = revle32(iv_attrs.attr_proc_r_distloss_uohm[0]);
    iv_vdd_sysparam.distoffset_uv = revle32(iv_attrs.attr_proc_vrm_voffset_uv[0]);

    // VCS rail
    iv_vcs_sysparam.loadline_uohm = revle32(iv_attrs.attr_proc_r_loadline_uohm[1]);
    iv_vcs_sysparam.distloss_uohm = revle32(iv_attrs.attr_proc_r_distloss_uohm[1]);
    iv_vcs_sysparam.distoffset_uv = revle32(iv_attrs.attr_proc_vrm_voffset_uv[1]);

    // VDN rail
    iv_vdn_sysparam.loadline_uohm = revle32(iv_attrs.attr_proc_r_loadline_uohm[2]);
    iv_vdn_sysparam.distloss_uohm = revle32(iv_attrs.attr_proc_r_distloss_uohm[2]);
    iv_vdn_sysparam.distoffset_uv = revle32(iv_attrs.attr_proc_vrm_voffset_uv[2]);

    // VIO rail
    iv_vio_sysparam.loadline_uohm = revle32(iv_attrs.attr_proc_r_loadline_uohm[3]);
    iv_vio_sysparam.distloss_uohm = revle32(iv_attrs.attr_proc_r_distloss_uohm[3]);
    iv_vio_sysparam.distoffset_uv = revle32(iv_attrs.attr_proc_vrm_voffset_uv[3]);

#define SET_ATTR(attr_name, target, attr_assign) \
    FAPI_TRY(FAPI_ATTR_SET(attr_name, target, attr_assign),"Attribute set failed"); \
    FAPI_INF("%-60s = 0x%08x %d", #attr_name, attr_assign, attr_assign);

    //Set default values
    SET_ATTR(fapi2::ATTR_PSTATES_ENABLED, iv_procChip, iv_pstates_enabled);
    SET_ATTR(fapi2::ATTR_RESCLK_ENABLED,  iv_procChip, iv_resclk_enabled);
    SET_ATTR(fapi2::ATTR_DDS_ENABLED,     iv_procChip, iv_dds_enabled);
    SET_ATTR(fapi2::ATTR_WOF_ENABLED,     iv_procChip, iv_wof_enabled);
    //SET_ATTR(fapi2::ATTR_WOV_UNDERV_ENABLED, iv_procChip, iv_wov_underv_enabled);
    //SET_ATTR(fapi2::ATTR_WOV_OVERV_ENABLED, iv_procChip, iv_wov_overv_enabled);

    iv_pstates_enabled = true;
    iv_resclk_enabled  = true;
    iv_dds_enabled     = true;
    iv_wof_enabled     = true;
    //iv_wov_underv_enabled = true;
    //iv_wov_overv_enabled = true;

    //Calculate nest & frequency_step_khz
    iv_frequency_step_khz = (iv_attrs.attr_freq_proc_refclock_khz /
                             iv_attrs.attr_proc_dpll_divider);

    FAPI_INF ("iv_attrs.attr_freq_proc_refclock_khz %08X iv_attrs.attr_proc_dpll_divider %08x",
         iv_attrs.attr_freq_proc_refclock_khz,iv_attrs.attr_proc_dpll_divider);
    FAPI_INF ("iv_frequency_step_khz %08X %08X", iv_frequency_step_khz, revle32(iv_frequency_step_khz));
    iv_frequency_step_khz = 16666;

    iv_nest_freq_mhz      = iv_attrs.attr_nest_frequency_mhz;


fapi_try_exit:
    if (fapi2::current_err)
    {
        iv_init_error = true;
    }
}

///////////////////////////////////////////////////////////
////////    compute_boot_safe
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::compute_boot_safe(
                  const VoltageConfigActions_t i_action)
{
    fapi2::ReturnCode l_rc;

    iv_pstates_enabled = true;
    iv_resclk_enabled  = true;
    iv_dds_enabled     = true;
    iv_ivrm_enabled    = true;
    iv_wof_enabled     = false;

    do
    {

        //We only wish to compute voltage setting defaults if the action
        //inputed to the HWP tells us to
        if(i_action == COMPUTE_VOLTAGE_SETTINGS)
        {

            // query VPD if any of the voltage attributes are zero
            if (!iv_attrs.attr_boot_voltage_mv[VDD]||
                !iv_attrs.attr_boot_voltage_mv[VCS] ||
                !iv_attrs.attr_boot_voltage_mv[VDN] ||
                !iv_attrs.attr_boot_voltage_mv[VIO])
            {
                // ----------------
                // get VPD data (#V,#W)
                // ----------------

                FAPI_TRY(vpd_init(),"vpd_init function failed");

                // Compute the VPD operating points
                compute_vpd_pts();

                FAPI_TRY(safe_mode_init());


                if (iv_attrs.attr_boot_voltage_mv[VDN])
                {
                    FAPI_INF("VDN boot voltage override set");
                }
                else
                {
                    FAPI_INF("VDN boot voltage override not set, using VPD value and correcting for applicable load line setting");
                    uint32_t l_int_vdn_mv = iv_poundV_raw_data.static_rails.SRVdnVltg;
                    uint32_t l_idn_ma = (iv_poundV_raw_data.static_rails.SRIdnTdpAcCurr + 
                                         iv_poundV_raw_data.static_rails.SRIdnTdpDcCurr) * 100;
                    // Returns revle32
                    uint32_t l_ext_vdn_mv = sysparm_uplift(l_int_vdn_mv,
                            l_idn_ma,
                            iv_vdn_sysparam.loadline_uohm,
                            iv_vdn_sysparam.distloss_uohm,
                            iv_vdn_sysparam.distoffset_uv);

                    FAPI_INF("VDN VPD voltage %d mV; Corrected voltage: %d mV; IDN: %d mA; LoadLine: %d uOhm; DistLoss: %d uOhm;  Offst: %d uOhm",
                            l_int_vdn_mv,
                            (l_ext_vdn_mv),
                            l_idn_ma,
                            iv_vdn_sysparam.loadline_uohm,
                            iv_vdn_sysparam.distloss_uohm,
                            iv_vdn_sysparam.distoffset_uv);

                    iv_attrs.attr_boot_voltage_mv[VDN]= (l_ext_vdn_mv);
                }

                if (iv_attrs.attr_boot_voltage_mv[VIO])
                {
                    FAPI_INF("VIO boot voltage override set");
                }
                else
                {
                    FAPI_INF("VIO boot voltage override not set, using VPD value and correcting for applicable load line setting");
                    uint32_t l_int_vio_mv = iv_poundV_raw_data.static_rails.SRVioVltg;
                    uint32_t l_iio_ma = (iv_poundV_raw_data.static_rails.SRIioTdpAcCurr + 
                                         iv_poundV_raw_data.static_rails.SRIioTdpDcCurr) * 100;
                    // Returns revle32
                    uint32_t l_ext_vio_mv = sysparm_uplift(l_int_vio_mv,
                            l_iio_ma,
                            iv_vio_sysparam.loadline_uohm,
                            iv_vio_sysparam.distloss_uohm,
                            iv_vio_sysparam.distoffset_uv);

                    FAPI_INF("VIO VPD voltage %d mV; Corrected voltage: %d mV; IDN: %d mA; LoadLine: %d uOhm; DistLoss: %d uOhm;  Offst: %d uOhm",
                            l_int_vio_mv,
                            (l_ext_vio_mv),
                            l_iio_ma,
                            iv_vio_sysparam.loadline_uohm,
                            iv_vio_sysparam.distloss_uohm,
                            iv_vio_sysparam.distoffset_uv);

                    iv_attrs.attr_boot_voltage_mv[VIO]= (l_ext_vio_mv);
                }
            }
            else
            {
#if 0
                FAPI_INF("Using overrides for all boot voltages (VDD/VCS/VDN/VIO) and core frequency");

                // Set safe frequency to the default BOOT_FREQ_MULT
                fapi2::ATTR_BOOT_FREQ_MULT_Type l_boot_freq_mult;
                FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_BOOT_FREQ_MULT,
                                        iv_procChip,
                                        l_boot_freq_mult));

                uint32_t l_boot_freq_mhz =
                    ((l_boot_freq_mult * iv_attrs.freq_proc_refclock_khz ) /
                     iv_attrs.proc_dpll_divider )
                    / 1000;



                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ,
                                       iv_procChip,
                                       l_boot_freq_mhz));
                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SAFE_MODE_VOLTAGE_MV,
                                       iv_procChip,
                                       (iv_attrs.vdd_voltage_mv)));
                FAPI_INF("Safe mode Frequency = %d MHz (0x%x), Safe mode voltage = %d mV (0x%x)",
                         l_boot_freq_mhz, l_boot_freq_mhz,
                         (iv_attrs.vdd_voltage_mv), (iv_attrs.vdd_voltage_mv));
#endif
            }

            FAPI_INF("Setting Boot Voltage attributes: VDD = %dmV; VCS = %dmV; VDN = %dmV",
                     iv_attrs.attr_boot_voltage_mv[VDD], iv_attrs.attr_boot_voltage_mv[VCS],
                     iv_attrs.attr_boot_voltage_mv[VDN], iv_attrs.attr_boot_voltage_mv[VIO]);
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_BOOT_VOLTAGE, iv_procChip, iv_attrs.attr_boot_voltage_mv),
                     "Error from FAPI_ATTR_SET (ATTR_BOOT_VOLTAGE)");
        }  // COMPUTE_VOLTAGE_SETTINGS
    }
    while(0);

    // trace values to be used
    FAPI_INF("VDD boot voltage = %d mV (0x%x)",
             (iv_attrs.attr_boot_voltage_mv[VDD]), (iv_attrs.attr_boot_voltage_mv[VDD]));
    FAPI_INF("VCS boot voltage = %d mV (0x%x)",
             (iv_attrs.attr_boot_voltage_mv[VCS]), (iv_attrs.attr_boot_voltage_mv[VCS]));
    FAPI_INF("VDN boot voltage = %d mV (0x%x)",
             (iv_attrs.attr_boot_voltage_mv[VDN]), (iv_attrs.attr_boot_voltage_mv[VDN]));
    FAPI_INF("VIO boot voltage = %d mV (0x%x)",
             (iv_attrs.attr_boot_voltage_mv[VIO]), (iv_attrs.attr_boot_voltage_mv[VIO]));

fapi_try_exit:
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////  vpd_init 
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::vpd_init( void )
{
    FAPI_INF(">>>>>>>>>> vpd_init");
    fapi2::ReturnCode l_rc;
    do
    {
        memset (&iv_poundW_data, 0, sizeof(iv_poundW_data));
        memset (&iv_iddqt, 0, sizeof(iv_iddqt));
        memset (iv_operating_points,0,sizeof(iv_operating_points));
        memset (&iv_attr_mvpd_poundV_raw, 0, sizeof(iv_attr_mvpd_poundV_raw));
        memset (&iv_attr_mvpd_poundV_biased, 0, sizeof(iv_attr_mvpd_poundV_biased));

        //Read #V data
        FAPI_TRY(get_mvpd_poundV(),
                 "get_mvpd_poundV function failed to retrieve pound V data");

        // Apply biased values if any
        //
        FAPI_IMP("Apply Biasing to #V");
        FAPI_TRY(apply_biased_values(),"apply_biased_values function failed");

        //Read #W data

        // ----------------
        // get VDM Parameters data
        // ----------------
        // Note:  the get_mvpd_poundW has the conditional checking for VDM
        // and WOF enablement as #W has both VDM and WOF content
        l_rc = get_mvpd_poundW();
        if (l_rc)
        {
            FAPI_ASSERT_NOEXIT(false,
                               fapi2::PSTATE_PB_POUND_W_ACCESS_FAIL(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                              .set_CHIP_TARGET(iv_procChip)
                              .set_FAPI_RC(l_rc),
                               "Pstate Parameter Block get_mvpd_poundW function failed");
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        }

        //Read #IQ data

        //if wof is disabled.. don't call IQ function
        if (is_wof_enabled())
        {
            // ----------------
            // get IQ (IDDQ) data
            // ----------------
            FAPI_INF("Getting IQ (IDDQ) Data");
            l_rc = get_mvpd_iddq ();

            if (l_rc)
            {
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::PSTATE_PB_IQ_ACCESS_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                   .set_CHIP_TARGET(iv_procChip)
                                   .set_FAPI_RC(l_rc),
                                   "Pstate Parameter Block get_mvpd_iddq function failed");
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            }
        }
        else
        {
            FAPI_INF("Skipping IQ (IDDQ) Data as WOF is disabled");
            iv_wof_enabled = false;
        }
#if 0

        FAPI_INF("Load RAW VPD");
        load_mvpd_operating_point(RAW);

        FAPI_INF("Load VPD");
        // VPD operating point
        load_mvpd_operating_point(BIASED);
#endif

    }while(0);

    FAPI_INF("<<<<<<<<< vpd_init");

fapi_try_exit:
    return fapi2::current_err;

}
///////////////////////////////////////////////////////////
////////   get_mvpd_poundV 
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::get_mvpd_poundV()
{
    uint8_t    bucket_id        = 0;
    uint8_t*   l_buffer         =  
    reinterpret_cast<uint8_t*>(malloc(sizeof(voltageBucketData_t)) );
    uint8_t*   l_buffer_inc     = nullptr;

    do
    {
        //Read #V data
        FAPI_TRY(p10_pm_get_poundv_bucket(iv_procChip, iv_poundV_raw_data));

        bucket_id = iv_poundV_raw_data.bucketId;
        memset(l_buffer, 0, sizeof(iv_poundV_raw_data));

        // fill chiplet_mvpd_data 2d array with data iN buffer (skip first byte - bucket id)
#define UINT16_GET(__uint8_ptr)   ((uint16_t)( ( (*((const uint8_t *)(__uint8_ptr)) << 8) | *((const uint8_t *)(__uint8_ptr) + 1) ) ))

        //memcpy(iv_attr_mvpd_poundV_raw,&iv_poundV_raw_data.nomFreq,sizeof(iv_attr_mvpd_poundV_raw));
        memcpy(l_buffer, &iv_poundV_raw_data, sizeof(iv_poundV_raw_data));

        FAPI_INF("#V bucket id = %u", bucket_id);

        l_buffer_inc = l_buffer;
        l_buffer_inc++;
        for (int i = 0; i < NUM_PV_POINTS; i++)
        {
            //frequency_mhz
            iv_attr_mvpd_poundV_raw[i].frequency_mhz = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].frequency_mhz,
                    iv_attr_mvpd_poundV_raw[i].frequency_mhz);
            l_buffer_inc += 2;
            //vdd_mv
            iv_attr_mvpd_poundV_raw[i].vdd_mv= (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].vdd_mv,
                    iv_attr_mvpd_poundV_raw[i].vdd_mv);
            l_buffer_inc += 2;
            //idd_tdp_ac_10ma
            iv_attr_mvpd_poundV_raw[i].idd_tdp_ac_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].idd_tdp_ac_10ma,
                    iv_attr_mvpd_poundV_raw[i].idd_tdp_ac_10ma);
            l_buffer_inc += 2;
            //idd_tdp_dc_10ma
            iv_attr_mvpd_poundV_raw[i].idd_tdp_dc_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].idd_tdp_dc_10ma,
                    iv_attr_mvpd_poundV_raw[i].idd_tdp_dc_10ma);
            l_buffer_inc += 2;
            //idd_rdp_ac_10ma
            iv_attr_mvpd_poundV_raw[i].idd_rdp_ac_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].idd_rdp_ac_10ma,
                    iv_attr_mvpd_poundV_raw[i].idd_tdp_ac_10ma);
            l_buffer_inc += 2;
            //idd_rdp_dc_10ma
            iv_attr_mvpd_poundV_raw[i].idd_rdp_dc_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].idd_rdp_dc_10ma,
                    iv_attr_mvpd_poundV_raw[i].idd_rdp_dc_10ma);
            l_buffer_inc += 2;
            //vcs_mv
            iv_attr_mvpd_poundV_raw[i].vcs_mv= (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].vcs_mv,
                    iv_attr_mvpd_poundV_raw[i].vcs_mv);
            l_buffer_inc += 2;
            //ics_tdp_ac_10ma
            iv_attr_mvpd_poundV_raw[i].ics_tdp_ac_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].ics_tdp_ac_10ma,
                    iv_attr_mvpd_poundV_raw[i].ics_tdp_ac_10ma);
            l_buffer_inc += 2;
            //ics_tdp_dc_10ma
            iv_attr_mvpd_poundV_raw[i].ics_tdp_dc_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].ics_tdp_dc_10ma,
                    iv_attr_mvpd_poundV_raw[i].ics_tdp_dc_10ma);
            l_buffer_inc += 2;
            //frequency_guardband_sort_mhz
            iv_attr_mvpd_poundV_raw[i].frequency_guardband_sort_mhz = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].frequency_guardband_sort_mhz,
                    iv_attr_mvpd_poundV_raw[i].frequency_guardband_sort_mhz);
            l_buffer_inc += 2;
            //vdd_vmin
            iv_attr_mvpd_poundV_raw[i].vdd_vmin = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].vdd_vmin,
                    iv_attr_mvpd_poundV_raw[i].vdd_vmin);
            l_buffer_inc += 2;
            //idd_power_pattern_10ma
            iv_attr_mvpd_poundV_raw[i].idd_power_pattern_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].idd_power_pattern_10ma,
                    iv_attr_mvpd_poundV_raw[i].idd_power_pattern_10ma);
            l_buffer_inc += 2;
            //core_power_pattern_temp_0p5C
            iv_attr_mvpd_poundV_raw[i].core_power_pattern_temp_0p5C = (uint32_t) *l_buffer_inc;
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].core_power_pattern_temp_0p5C,
                    iv_attr_mvpd_poundV_raw[i].core_power_pattern_temp_0p5C);

            // //core_power_pattern_temp_0p5C(1byte) + spare (3bytes)
            l_buffer_inc += 4;
        }

        iv_poundV_bucket_id = bucket_id;
        FAPI_TRY(chk_valid_poundv(false));

        update_vpd_pts_value();

    }
    while(0);


fapi_try_exit:

    if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
    {
        iv_pstates_enabled = false;
    }
    free (l_buffer);

    return fapi2::current_err;

}

///////////////////////////////////////////////////////////
////////   chk_valid_poundv 
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::chk_valid_poundv(
                      const bool i_biased_state)
{
    const char*     pv_op_str[NUM_PV_POINTS] = VPD_PV_STR;
    uint8_t         i = 0;
    bool            suspend_ut_check = false;
    uint8_t         l_chiplet_num = iv_procChip.getChipletNumber();
    uint8_t attr_poundv_validate_ec_disable = 0;


    //Biased
    if (i_biased_state)
    {
        memcpy (iv_attr_mvpd_data,iv_attr_mvpd_poundV_biased,sizeof(iv_attr_mvpd_data));
    }
    else
    {
        memcpy (iv_attr_mvpd_data,iv_attr_mvpd_poundV_raw,sizeof(iv_attr_mvpd_data));
    }

    FAPI_DBG(">> chk_valid_poundv for %s values", (i_biased_state) ? "biased" : "non-biased" );

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_SYSTEM_POUNDV_VALIDITY_HALT_DISABLE_Type      attr_poundv_validity_halt_disable;
//    fapi2::ATTR_CHIP_EC_FEATURE_POUNDV_VALIDATE_DISABLE_Type  attr_poundv_validate_ec_disable;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_POUNDV_VALIDITY_HALT_DISABLE,
                FAPI_SYSTEM,
                attr_poundv_validity_halt_disable));

  //  FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_POUNDV_VALIDATE_DISABLE,
    //            iv_procChip,
      //          attr_poundv_validate_ec_disable));

    if (attr_poundv_validate_ec_disable)
    {
        iv_pstates_enabled = false;
        FAPI_INF("**** WARNING : #V zero value checking is not being performed on this chip EC level");
        FAPI_INF("**** WARNING : Pstates are not enabled");
    }
    else
    {
        // check for non-zero freq, voltage, or current in valid operating points
        for (i = 0; i <= NUM_PV_POINTS - 1; i++)
        {
            FAPI_INF("Checking for Zero valued %s data in each #V operating point (%s) " \
                    "f=%u v=%u i=%u i=%u i=%u i=%u v=%u i=%u i=%u f=%u v=%u i=%u t=%u ",
                    (i_biased_state) ? "biased" : "non-biased",
                    pv_op_str[i],
                    iv_attr_mvpd_data[i].frequency_mhz,
                    iv_attr_mvpd_data[i].vdd_mv,
                    iv_attr_mvpd_data[i].idd_tdp_ac_10ma,
                    iv_attr_mvpd_data[i].idd_tdp_dc_10ma,
                    iv_attr_mvpd_data[i].idd_rdp_ac_10ma,
                    iv_attr_mvpd_data[i].idd_rdp_dc_10ma,
                    iv_attr_mvpd_data[i].vcs_mv,
                    iv_attr_mvpd_data[i].ics_tdp_ac_10ma,
                    iv_attr_mvpd_data[i].ics_tdp_dc_10ma,
                    iv_attr_mvpd_data[i].frequency_guardband_sort_mhz,
                    iv_attr_mvpd_data[i].vdd_vmin,
                    iv_attr_mvpd_data[i].idd_power_pattern_10ma,
                    iv_attr_mvpd_data[i].core_power_pattern_temp_0p5C
                    );

            if (is_wof_enabled() && 
                    (strcmp(pv_op_str[i], "UltraTurbo") == 0))
            {
                if (POUNDV_POINTS_CHECK(i))
                {
                    if (!strcmp(pv_op_str[i], "CF1") ||
                       (!strcmp(pv_op_str[i], "CF2")) ||
                       (!strcmp(pv_op_str[i], "CF4")) || 
                       (!strcmp(pv_op_str[i], "CF5")) ||
                       (!strcmp(pv_op_str[i], "Fmax") ))
                    {
                        iv_optional_pdv_pts_value_zero = true;
                        FAPI_INF("Skip logging error for this operating point %s",pv_op_str[i]);
                        continue;
                    }
                    //if we have hit here then,main poundV point itself is
                    //invalid so no need to update the optional points
                    iv_optional_pdv_pts_value_zero  = false;

                    FAPI_INF("**** WARNING: WOF is enabled but zero valued data found in #V (chiplet = %u  bucket id = %u  op point = %s)",
                            l_chiplet_num, iv_poundV_bucket_id, pv_op_str[i]);
                    FAPI_INF("**** WARNING: Disabling WOF and continuing");
                    suspend_ut_check = true;

                    // Set ATTR_WOF_ENABLED so the caller can set header flags
                    iv_wof_enabled = false;

                    // Take out an informational error log and then keep going.
                    if (i_biased_state)
                    {
                        FAPI_ASSERT_NOEXIT(false,
                                fapi2::PSTATE_PB_BIASED_POUNDV_WOF_UT_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                .set_CHIP_TARGET(iv_procChip)
                                .set_CHIPLET_NUMBER(l_chiplet_num)
                                .set_BUCKET(iv_poundV_bucket_id) 
                                POUNDV_POINTS_PRINT(i,A),
                                "Pstate Parameter Block WOF Biased #V UT error being logged");
                    }
                    else
                    {
                        FAPI_ASSERT_NOEXIT(false,
                                fapi2::PSTATE_PB_POUNDV_WOF_UT_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                .set_CHIP_TARGET(iv_procChip)
                                .set_CHIPLET_NUMBER(l_chiplet_num)
                                .set_BUCKET(iv_poundV_bucket_id)
                                POUNDV_POINTS_PRINT(i,A),
                                "Pstate Parameter Block WOF #V UT error being logged");
                    }
                    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                }
            }
            else if ((!is_wof_enabled()) && (strcmp(pv_op_str[i], "UltraTurbo") == 0))
            {
                FAPI_INF("**** NOTE: WOF is disabled so the UltraTurbo VPD is not being checked");
                suspend_ut_check = true;
            }
            else
            {
                if (POUNDV_POINTS_CHECK(i))
                {
                    if (!strcmp(pv_op_str[i], "CF1") ||
                       (!strcmp(pv_op_str[i], "CF2")) ||
                       (!strcmp(pv_op_str[i], "CF4")) || 
                       (!strcmp(pv_op_str[i], "CF5")) ||
                       (!strcmp(pv_op_str[i], "Fmax") ))
                    {
                        iv_optional_pdv_pts_value_zero = true;
                        FAPI_INF("Skip logging error for this operating point %s",pv_op_str[i]);
                        continue;
                    }
                    //if we have hit here then,main poundV point itself is
                    //invalid so no need to update the optional points
                    iv_optional_pdv_pts_value_zero  = false;
                    iv_pstates_enabled = false;

                    if (attr_poundv_validity_halt_disable)
                    {
                        FAPI_IMP("**** WARNING : halt on #V validity checking has been disabled and errors were found");
                        FAPI_IMP("**** WARNING : Zero valued data found in #V (chiplet = %u  bucket id = %u  op point = %s)",
                                l_chiplet_num, iv_poundV_bucket_id, pv_op_str[i]);
                        FAPI_IMP("**** WARNING : Pstates are not enabled but continuing on.");

                        // Log errors based on biased inputs or not
                        if (i_biased_state)
                        {
                            FAPI_ASSERT_NOEXIT(false,
                                    fapi2::PSTATE_PB_BIASED_POUNDV_ZERO_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                    .set_CHIP_TARGET(iv_procChip)
                                    .set_CHIPLET_NUMBER(l_chiplet_num)
                                    .set_BUCKET(iv_poundV_bucket_id)
                                    .set_POINT(i)
                                    POUNDV_POINTS_PRINT(i,A),
                                    "Pstate Parameter Block Biased #V Zero contents error being logged");
                        }
                        else
                        {
                            FAPI_ASSERT_NOEXIT(false,
                                    fapi2::PSTATE_PB_POUNDV_ZERO_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                    .set_CHIP_TARGET(iv_procChip)
                                    .set_CHIPLET_NUMBER(l_chiplet_num)
                                    .set_BUCKET(iv_poundV_bucket_id)
                                    .set_POINT(i)
                                    POUNDV_POINTS_PRINT(i,A),
                                    "Pstate Parameter Block #V Zero contents error being logged");
                        }
                        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                    }
                    else
                    {
                        FAPI_ERR("**** ERROR : Zero valued data found in #V (chiplet = %u  bucket id = %u  op point = %s)",
                                l_chiplet_num, iv_poundV_bucket_id, pv_op_str[i]);

                        // Error out has Pstate and all dependent functions are suspious.
                        if (i_biased_state)
                        {
                            FAPI_ASSERT(false,
                                    fapi2::PSTATE_PB_BIASED_POUNDV_ZERO_ERROR()
                                    .set_CHIP_TARGET(iv_procChip)
                                    .set_CHIPLET_NUMBER(l_chiplet_num)
                                    .set_BUCKET(iv_poundV_bucket_id)
                                    .set_POINT(i)
                                    POUNDV_POINTS_PRINT(i,A),
                                    "Pstate Parameter Block Biased #V Zero contents error being logged");
                        }
                        else
                        {
                            FAPI_ASSERT(false,
                                    fapi2::PSTATE_PB_POUNDV_ZERO_ERROR()
                                    .set_CHIP_TARGET(iv_procChip)
                                    .set_CHIPLET_NUMBER(l_chiplet_num)
                                    .set_BUCKET(iv_poundV_bucket_id)
                                    .set_POINT(i)
                                    POUNDV_POINTS_PRINT(i,A),
                                    "Pstate Parameter Block #V Zero contents error being logged");
                        }
                    }  // Halt disable
                }  // #V point zero check
            }  // WOF and UT conditions
        } // Operating poing loop
    } // validate #V EC

    // Adjust the valid operating point based on UltraTurbo presence
    // and WOF enablement
    iv_valid_pdv_points = NUM_PV_POINTS;

    if (suspend_ut_check)
    {
        iv_valid_pdv_points--;
    }

    FAPI_DBG("iv_valid_pdv_points = %d", iv_valid_pdv_points);

    if (attr_poundv_validate_ec_disable)
    {
        iv_pstates_enabled = false;
        FAPI_INF("**** WARNING : #V relationship checking is not being performed on this chip EC level");
        FAPI_INF("**** WARNING : Pstates are not enabled");
    }
    else
    {
        // check valid operating points' values have this relationship (power save <= nominal <= turbo <= ultraturbo)
        for (i = 1; i <= (iv_valid_pdv_points) - 1; i++)
        {
            FAPI_INF("Checking for relationship between #V operating point (%s <= %s)",
                    pv_op_str[i - 1], pv_op_str[i]);

            // Only skip checkinug for WOF not enabled and UltraTurbo.
            if ( is_wof_enabled()    ||
               (!( !is_wof_enabled() && 
               (strcmp(pv_op_str[i], "UltraTurbo") == 0))))
            {
                if (!strcmp(pv_op_str[i], "CF1") ||
                    (!strcmp(pv_op_str[i], "CF2")) ||
                    (!strcmp(pv_op_str[i], "CF4")) || 
                    (!strcmp(pv_op_str[i], "CF5")) ||
                    (!strcmp(pv_op_str[i], "Fmax") ))
                {
                    FAPI_INF("Skip logging error for this operating point %s",pv_op_str[i]);
                    continue;
                }
                if ((iv_attr_mvpd_data[i - 1].frequency_mhz > 
                     iv_attr_mvpd_data[i].frequency_mhz) ||
                    (iv_attr_mvpd_data[i - 1].vdd_mv >
                     iv_attr_mvpd_data[i].vdd_mv) ||
                    (iv_attr_mvpd_data[i - 1].idd_tdp_ac_10ma > 
                     iv_attr_mvpd_data[i].idd_tdp_ac_10ma) ||
                    (iv_attr_mvpd_data[i - 1].idd_tdp_dc_10ma > 
                    iv_attr_mvpd_data[i].idd_tdp_dc_10ma) ||
                    (iv_attr_mvpd_data[i - 1].idd_rdp_ac_10ma > 
                    iv_attr_mvpd_data[i].idd_rdp_ac_10ma) || 
                    (iv_attr_mvpd_data[i  -1].idd_rdp_dc_10ma >
                    iv_attr_mvpd_data[i].idd_rdp_dc_10ma) || 
                    (iv_attr_mvpd_data[i - 1].vcs_mv > 
                    iv_attr_mvpd_data[i].vcs_mv) || 
                    (iv_attr_mvpd_data[i - 1].ics_tdp_ac_10ma > 
                    iv_attr_mvpd_data[i].ics_tdp_ac_10ma) ||
                    (iv_attr_mvpd_data[i - 1].ics_tdp_dc_10ma > 
                    iv_attr_mvpd_data[i].ics_tdp_dc_10ma) ||
                    (iv_attr_mvpd_data[i - 1].frequency_guardband_sort_mhz > 
                    iv_attr_mvpd_data[i].frequency_guardband_sort_mhz) ||
                    (iv_attr_mvpd_data[i - 1].vdd_vmin > 
                    iv_attr_mvpd_data[i].vdd_vmin) ||
                    (iv_attr_mvpd_data[i - 1].idd_power_pattern_10ma > 
                    iv_attr_mvpd_data[i].idd_power_pattern_10ma) ||
                    (iv_attr_mvpd_data[i - 1].core_power_pattern_temp_0p5C > 
                    iv_attr_mvpd_data[i].core_power_pattern_temp_0p5C))

                {
                    iv_pstates_enabled = false;

                    if (attr_poundv_validity_halt_disable)
                    {
                        FAPI_IMP("**** WARNING : halt on #V validity checking has been " 
                                "disabled and relationship errors were found");
                        FAPI_IMP("**** WARNING : Relationship error between #V operating point "
                                "(%s > %s)(power save <= nominal <= turbo <= ultraturbo) (chiplet = %u  bucket id = %u  op point = %u)",
                                pv_op_str[i - 1], pv_op_str[i], l_chiplet_num, iv_poundV_bucket_id, i);
                        FAPI_IMP("**** WARNING : Pstates are not enabled but continuing on.");
                    }
                    else
                    {
                        FAPI_ERR("**** ERROR : Relation../../xml/attribute_info/pm_plat_attributes.xmlship "
                                "error between #V operating point (%s > %s)(power save <= nominal <= turbo "
                                "<= ultraturbo) (chiplet = %u  bucket id = %u  op point = %u)",
                                pv_op_str[i - 1], pv_op_str[i], l_chiplet_num, iv_poundV_bucket_id,i);
                    }

                    FAPI_INF("%s Frequency value %u is %s %s Frequency value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].frequency_mhz,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].frequency_mhz, 
                                iv_attr_mvpd_data[i].frequency_mhz),pv_op_str[i], iv_attr_mvpd_data[i].frequency_mhz);
                    FAPI_INF("%s VDD voltage value %u is %s %s VDD voltage value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].vdd_mv,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].vdd_mv, 
                                iv_attr_mvpd_data[i].vdd_mv),pv_op_str[i], iv_attr_mvpd_data[i].vdd_mv);
                    FAPI_INF("%s IDD tdp ac value %u is %s %s IDD tdp ac value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].idd_tdp_ac_10ma,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].idd_tdp_ac_10ma, 
                                iv_attr_mvpd_data[i].idd_tdp_ac_10ma),pv_op_str[i], iv_attr_mvpd_data[i].idd_tdp_ac_10ma);
                    FAPI_INF("%s IDD tdp dc value %u is %s %s IDD tdp dc value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].idd_tdp_dc_10ma,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].idd_tdp_dc_10ma, 
                                iv_attr_mvpd_data[i].idd_tdp_dc_10ma),pv_op_str[i], iv_attr_mvpd_data[i].idd_tdp_dc_10ma);
                    FAPI_INF("%s IDD rdp ac value %u is %s %s IDD rdp ac value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].idd_rdp_ac_10ma,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].idd_rdp_ac_10ma, 
                                iv_attr_mvpd_data[i].idd_rdp_ac_10ma),pv_op_str[i], iv_attr_mvpd_data[i].idd_rdp_ac_10ma);
                    FAPI_INF("%s IDD rdp dc value %u is %s %s IDD rdp dc value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].idd_rdp_dc_10ma,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].idd_rdp_dc_10ma, 
                                iv_attr_mvpd_data[i].idd_rdp_dc_10ma),pv_op_str[i], iv_attr_mvpd_data[i].idd_rdp_dc_10ma);
                    FAPI_INF("%s VCS voltage value %u is %s %s VCS voltage value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].vcs_mv,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].vcs_mv, 
                                iv_attr_mvpd_data[i].vcs_mv),pv_op_str[i], iv_attr_mvpd_data[i].vcs_mv);
                    FAPI_INF("%s ICS tdp ac value %u is %s %s ICS tdp ac value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].ics_tdp_ac_10ma,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].ics_tdp_ac_10ma, 
                                iv_attr_mvpd_data[i].ics_tdp_ac_10ma),pv_op_str[i], iv_attr_mvpd_data[i].ics_tdp_ac_10ma);
                    FAPI_INF("%s ICS tdp dc value %u is %s %s ICS tdp dc value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].ics_tdp_dc_10ma,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].ics_tdp_dc_10ma, 
                                iv_attr_mvpd_data[i].ics_tdp_dc_10ma),pv_op_str[i], iv_attr_mvpd_data[i].ics_tdp_dc_10ma);
                    FAPI_INF("%s Frequency GB sort value %u is %s %s Frequency GB sort value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].frequency_guardband_sort_mhz,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].frequency_guardband_sort_mhz, 
                                iv_attr_mvpd_data[i].frequency_guardband_sort_mhz),pv_op_str[i], iv_attr_mvpd_data[i].frequency_guardband_sort_mhz);
                    FAPI_INF("%s VDD vmin voltage value %u is %s %s VDD vmin voltage value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].vdd_vmin,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].vdd_vmin, 
                                iv_attr_mvpd_data[i].vdd_vmin),pv_op_str[i], iv_attr_mvpd_data[i].vdd_vmin);
                    FAPI_INF("%s IDD powr pattern value %u is %s %s IDD powr pattern value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].idd_power_pattern_10ma,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].idd_power_pattern_10ma, 
                                iv_attr_mvpd_data[i].idd_power_pattern_10ma),pv_op_str[i], iv_attr_mvpd_data[i].idd_power_pattern_10ma);
                    FAPI_INF("%s Core powr pattern temp value %u is %s %s Core powr pattern temp value %u",
                            pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].core_power_pattern_temp_0p5C,
                            POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].core_power_pattern_temp_0p5C, 
                                iv_attr_mvpd_data[i].core_power_pattern_temp_0p5C),pv_op_str[i], iv_attr_mvpd_data[i].core_power_pattern_temp_0p5C);
                    if (i_biased_state)
                    {
                        if (attr_poundv_validity_halt_disable)
                        {
                            // Log the error only.
                            FAPI_ASSERT_NOEXIT(false,
                                    fapi2::PSTATE_PB_BIASED_POUNDV_SLOPE_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                    .set_CHIP_TARGET(iv_procChip)
                                    .set_CHIPLET_NUMBER(l_chiplet_num)
                                    .set_BUCKET(iv_poundV_bucket_id)
                                    .set_POINT(i)
                                    POUNDV_POINTS_PRINT(i-1,A)
                                    POUNDV_POINTS_PRINT(i,B),
                                    "Pstate Parameter Block Biased #V disorder contents error being logged");

                            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

                        }
                        else
                        {
                            // Error out has Pstate and all dependent functions are suspicious.
                            FAPI_ASSERT(false,
                                    fapi2::PSTATE_PB_BIASED_POUNDV_SLOPE_ERROR()
                                    .set_CHIP_TARGET(iv_procChip)
                                    .set_CHIPLET_NUMBER(l_chiplet_num)
                                    .set_BUCKET(iv_poundV_bucket_id)
                                    .set_POINT(i)
                                    POUNDV_POINTS_PRINT(i-1,A)
                                    POUNDV_POINTS_PRINT(i,B),
                                    "Pstate Parameter Block Biased #V disorder contents error being logged");
                        }
                    }
                    else
                    {
                        if (attr_poundv_validity_halt_disable)
                        {
                            // Log the error only.
                            FAPI_ASSERT_NOEXIT(false,
                                    fapi2::PSTATE_PB_POUNDV_SLOPE_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                    .set_CHIP_TARGET(iv_procChip)
                                    .set_CHIPLET_NUMBER(l_chiplet_num)
                                    .set_BUCKET(iv_poundV_bucket_id)
                                    .set_POINT(i)
                                    POUNDV_POINTS_PRINT(i-1,A)
                                    POUNDV_POINTS_PRINT(i,B),

                                    "Pstate Parameter Block #V disorder contents error being logged");

                            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                        }
                        else
                        {
                            // Error out has Pstate and all dependent functions are suspicious.
                            FAPI_ASSERT(false,
                                    fapi2::PSTATE_PB_POUNDV_SLOPE_ERROR()
                                    .set_CHIP_TARGET(iv_procChip)
                                    .set_CHIPLET_NUMBER(l_chiplet_num)
                                    .set_BUCKET(iv_poundV_bucket_id)
                                    .set_POINT(i)
                                    POUNDV_POINTS_PRINT(i-1,A)
                                    POUNDV_POINTS_PRINT(i,B),
                                    "Pstate Parameter Block #V disorder contents error being logged");
                        }
                    }
                }  // validity failed
            }  // Skip UT check
        } // point loop
    }  // validity disabled

fapi_try_exit:

    FAPI_DBG("<< chk_valid_poundv");
    return fapi2::current_err;
}
void PlatPmPPB::update_vpd_pts_value()
{
    uint8_t i = 0;
    uint8_t l_ps_cf3_idx = 0;
    uint8_t l_cf3_ut_idx = 0;
    const char*     pv_op_str[NUM_PV_POINTS] = VPD_PV_STR;
    //PSAV 0, CF1 1, CF2 2, CF3 3, CF4 4, CF5 5,UT 6
    for (i = 0; i < NUM_PV_POINTS - 1; ++i)
    {
        if (iv_optional_pdv_pts_value_zero)
        {
            if ((strcmp(pv_op_str[i], "CF1") == 0) ||
                    (strcmp(pv_op_str[i], "CF4") == 0))
            {
                l_ps_cf3_idx = i - 1;
                l_cf3_ut_idx = i + 2;
            }
            else if (((strcmp(pv_op_str[i], "CF2") == 0) ||
                        (strcmp(pv_op_str[i], "CF5") == 0)))
            {
                l_ps_cf3_idx = i - 2;
                l_cf3_ut_idx = i + 1;
            }
            else
            {
                continue;
            }
            iv_attr_mvpd_poundV_raw[i].frequency_mhz = 
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].frequency_mhz,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].frequency_mhz,
                        CF1_3_PERCENTAGE);
            iv_attr_mvpd_poundV_raw[i].vdd_mv = 
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].vdd_mv,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].vdd_mv,
                        CF1_3_PERCENTAGE);
            iv_attr_mvpd_poundV_raw[i].idd_tdp_ac_10ma = 
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].idd_tdp_ac_10ma,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].idd_tdp_ac_10ma,
                        CF1_3_PERCENTAGE);
            iv_attr_mvpd_poundV_raw[i].idd_tdp_dc_10ma = 
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].idd_tdp_dc_10ma,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].idd_tdp_dc_10ma,
                        CF1_3_PERCENTAGE);
            iv_attr_mvpd_poundV_raw[i].idd_rdp_ac_10ma = 
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].idd_rdp_ac_10ma,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].idd_rdp_ac_10ma,
                        CF1_3_PERCENTAGE);
            iv_attr_mvpd_poundV_raw[i].idd_rdp_dc_10ma = 
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].idd_rdp_dc_10ma,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].idd_rdp_dc_10ma,
                        CF1_3_PERCENTAGE);
            iv_attr_mvpd_poundV_raw[i].vcs_mv = 
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].vcs_mv,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].vcs_mv,
                        CF1_3_PERCENTAGE);
            iv_attr_mvpd_poundV_raw[i].ics_tdp_ac_10ma = 
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].ics_tdp_ac_10ma,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].ics_tdp_ac_10ma,
                        CF1_3_PERCENTAGE);
            iv_attr_mvpd_poundV_raw[i].ics_tdp_dc_10ma = 
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].ics_tdp_dc_10ma,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].ics_tdp_dc_10ma,
                        CF1_3_PERCENTAGE);

            iv_attr_mvpd_poundV_raw[i].frequency_guardband_sort_mhz = 
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].frequency_guardband_sort_mhz,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].frequency_guardband_sort_mhz,
                        CF1_3_PERCENTAGE);

            iv_attr_mvpd_poundV_raw[i].vdd_vmin = 
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].vdd_vmin,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].vdd_vmin,
                        CF1_3_PERCENTAGE);

            iv_attr_mvpd_poundV_raw[i].idd_power_pattern_10ma = 
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].idd_power_pattern_10ma,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].idd_power_pattern_10ma,
                        CF1_3_PERCENTAGE);

            iv_attr_mvpd_poundV_raw[i].core_power_pattern_temp_0p5C = 
                POUNDV_POINT_CALC (iv_attr_mvpd_poundV_raw[l_ps_cf3_idx].core_power_pattern_temp_0p5C,
                        iv_attr_mvpd_poundV_raw[l_cf3_ut_idx].core_power_pattern_temp_0p5C,
                        CF1_3_PERCENTAGE);

        } //end of if
    }//end of for
}
///////////////////////////////////////////////////////////
////////   is_ddsc_enabled
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_ddsc_enabled()
{
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
//    uint8_t attr_dd_ddsc_not_supported;
    fapi2::ATTR_SYSTEM_DDS_DISABLE_Type attr_system_dds_disable;

    FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_DDS_DISABLE, FAPI_SYSTEM, attr_system_dds_disable);
//    FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_DDSC_NOT_SUPPORTED, iv_procChip, attr_dd_ddsc_not_supported);

    return
        (!(attr_system_dds_disable) &&
 //        !(attr_dd_vdm_not_supported) &&
         iv_dds_enabled)
         ? true : false;
} // end of is_ddsc_enabled

///////////////////////////////////////////////////////////
////////  is_wof_enabled
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_wof_enabled()
{
//    uint8_t attr_dd_wof_not_supported;
    uint8_t attr_system_wof_disable;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_WOF_DISABLE, FAPI_SYSTEM, attr_system_wof_disable);
//    FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_WOF_NOT_SUPPORTED, iv_procChip, attr_dd_wof_not_supported);

    return
        (!(attr_system_wof_disable) &&
 //        !(attr_dd_wof_not_supported) &&
         iv_wof_enabled)
        ? true : false;
} //end of is_wof_enabled

///////////////////////////////////////////////////////////
////////   apply_biased_values
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::apply_biased_values ()
{
    FAPI_INF(">>>>>>>>>>>>> apply_biased_values");
    const char*     pv_op_str[NUM_PV_POINTS] = VPD_PV_STR;

    do
    {
        // ---------------------------------------------
        // process external and internal bias attributes
        // ---------------------------------------------
        FAPI_IMP("Apply Biasing to #V");

        // Copy to Bias array
        memcpy(iv_attr_mvpd_poundV_biased,iv_attr_mvpd_poundV_raw,sizeof(iv_attr_mvpd_poundV_raw));

        for (int i = 0; i <= NUM_PV_POINTS - 1; i++)
        {
            FAPI_DBG("BIASED #V operating point (%s) f=%u v=%u i=%u v=%u i=%u",
                    pv_op_str[i],
                    iv_attr_mvpd_poundV_biased[i].frequency_mhz,
                    iv_attr_mvpd_poundV_biased[i].vdd_mv,
                    iv_attr_mvpd_poundV_biased[i].idd_tdp_dc_10ma,
                    iv_attr_mvpd_poundV_biased[i].vcs_mv,
                    iv_attr_mvpd_poundV_biased[i].ics_tdp_dc_10ma);
        }

        FAPI_TRY(apply_extint_bias(),
                 "Bias application function failed");

        //Validating Bias values
        FAPI_INF("Validate Biasd Voltage and Frequency values");

        FAPI_TRY(chk_valid_poundv(BIASED));

        FAPI_DBG("Pstate Base Frequency - after bias %X (%d)",
                 iv_attr_mvpd_poundV_biased[VPD_PV_UT].frequency_mhz * 1000,
                 iv_attr_mvpd_poundV_biased[VPD_PV_UT].frequency_mhz * 1000);
    }while(0);

fapi_try_exit:
    FAPI_INF("<<<<<<<<<<<< apply_biased_values");
    return fapi2::current_err;

}

///////////////////////////////////////////////////////////
////////   apply_extint_bias
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::apply_extint_bias( )
{
    double freq_bias[NUM_PV_POINTS];
    double voltage_ext_vdd_bias[NUM_PV_POINTS];
    double voltage_ext_vcs_bias[NUM_PV_POINTS];
  //  double voltage_ext_vdn_bias;
    uint8_t VDD = 0;
    uint8_t VCS = 1;
   // uint8_t VDN = 2;
  //  uint8_t VIO = 3;

    // Calculate the frequency multiplers and load the biases into the exported
    // structure
    for (auto p = 0; p < NUM_PV_POINTS; p++)
    {
        iv_bias.frequency_0p5pct  = iv_attrs.attr_freq_bias;
        iv_bias.vdd_ext_0p5pct[p] = iv_attrs.attr_voltage_ext_bias[VDD][p];
        iv_bias.vcs_ext_0p5pct[p] = iv_attrs.attr_voltage_ext_bias[VCS][p];


        freq_bias[p]              = calc_bias(iv_bias.frequency_0p5pct);
        voltage_ext_vdd_bias[p]   = calc_bias(iv_bias.vdd_ext_0p5pct[p]);
        voltage_ext_vcs_bias[p]   = calc_bias(iv_bias.vcs_ext_0p5pct[p]);

        FAPI_DBG("    Biases[%d](bias): Freq=%f (%f%%); VDD=%f (%f%%) VCS=%f (%f%%)",
                p,
                freq_bias[p],            iv_bias.frequency_0p5pct/2,
                voltage_ext_vdd_bias[p], iv_bias.vdd_ext_0p5pct[p]/2,
                voltage_ext_vcs_bias[p], iv_bias.vcs_ext_0p5pct[p]/2);
    }


    // VDN bias applied to all operating points
//    voltage_ext_vdn_bias = calc_bias(iv_attrs.attr_voltage_ext_vdn_bias);

    // Change the VPD frequency, VDD and VCS values with the bias multiplers
    for (auto p = 0; p < NUM_PV_POINTS; p++)
    {
        FAPI_DBG("    Orig values[%d](bias): Freq=%d (%f); VDD=%d (%f), VCS=%d (%f)",
                    p,
                    iv_attr_mvpd_poundV_biased[p].frequency_mhz, freq_bias[p],
                    iv_attr_mvpd_poundV_biased[p].vdd_mv, voltage_ext_vdd_bias[p],
                    iv_attr_mvpd_poundV_biased[p].vcs_mv, voltage_ext_vcs_bias[p]);

        double freq_mhz =
            (( (double)iv_attr_mvpd_poundV_biased[p].frequency_mhz) * freq_bias[p]);
        double vdd_mv =
            (( (double)iv_attr_mvpd_poundV_biased[p].vdd_mv) * voltage_ext_vdd_bias[p]);
        double vcs_mv =
            (( (double)iv_attr_mvpd_poundV_biased[p].vcs_mv) * voltage_ext_vcs_bias[p]);

        iv_attr_mvpd_poundV_biased[p].frequency_mhz = (uint16_t)internal_floor(freq_mhz);
        iv_attr_mvpd_poundV_biased[p].vdd_mv        = (uint16_t)internal_ceil(vdd_mv);
        iv_attr_mvpd_poundV_biased[p].vcs_mv        = (uint16_t)internal_ceil(vcs_mv);

        FAPI_DBG("    Biased values[%d]: Freq=%f %d; VDD=%f %d, VCS=%f %d ",
                    p,
                    freq_mhz, iv_attr_mvpd_poundV_biased[p].frequency_mhz,
                    vdd_mv, iv_attr_mvpd_poundV_biased[p].vdd_mv,
                    vcs_mv, iv_attr_mvpd_poundV_biased[p].vcs_mv);
    }

    //TBD for VDN and VIO computation

    return fapi2::FAPI2_RC_SUCCESS;
}

///////////////////////////////////////////////////////////
////////  get_mvpd_poundW 
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::get_mvpd_poundW (void)
{
    fapi2::ddscData_t l_ddscBuf;
    uint8_t    bucket_id        = 0;
    uint8_t    version_id       = 0;

    FAPI_DBG(">> get_mvpd_poundW");

    do
    {
        FAPI_DBG("get_mvpd_poundW: VDM enable = %d, WOF enable %d",
                is_ddsc_enabled(), is_wof_enabled());

        // Exit if both VDM and WOF is disabled
        if ((!is_ddsc_enabled() && !is_wof_enabled()))
        {
            FAPI_INF("   get_mvpd_poundW: BOTH VDM and WOF are disabled.  Skipping remaining checks");
            iv_dds_enabled = false;
            iv_wof_enabled = false;
            iv_wov_underv_enabled = false;
            iv_wov_overv_enabled = false;
            break;
        }

        // clear out buffer to known value before calling fapiGetMvpdField
        memset(&l_ddscBuf, 0, sizeof(l_ddscBuf));

        FAPI_TRY(p10_pm_get_poundw_bucket(iv_procChip, l_ddscBuf));

        bucket_id = l_ddscBuf.bucketId;
        version_id = l_ddscBuf.version;

        FAPI_INF("#W bucket_id  = %u version_id = %u", bucket_id, version_id);


        uint8_t l_poundw_static_data = 0;
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POUND_W_STATIC_DATA_ENABLE,
                    FAPI_SYSTEM,
                    l_poundw_static_data),
                "Error from FAPI_ATTR_GET for attribute ATTR_POUND_W_STATIC_DATA_ENABLE");

        if (l_poundw_static_data)
        {
            FAPI_INF("attribute ATTR_POUND_W_STATIC_DATA_ENABLE is set");
            // copy the data to the pound w structure from a hardcoded table
            //            memcpy (&iv_poundW_data, &g_vpdData, sizeof (g_vpdData));
        }
        else
        {
            FAPI_INF("attribute ATTR_POUND_W_STATIC_DATA_ENABLE is NOT set");
            // copy the data to the pound w structure from the actual VPD image
            memcpy (&iv_poundW_data, l_ddscBuf.ddscData, sizeof (l_ddscBuf.ddscData));
        }

        // validate vid values
        bool l_frequency_value_state = 1;
        VALIDATE_FREQUENCY_DROP_VALUES(iv_poundW_data.other.dpll_settings.fields.N_S_drop_3p125pct,
                iv_poundW_data.other.dpll_settings.fields.N_L_drop_3p125pct,
                iv_poundW_data.other.dpll_settings.fields.L_S_return_3p125pct,
                iv_poundW_data.other.dpll_settings.fields.S_N_return_3p125pct,
                l_frequency_value_state);


        if (!l_frequency_value_state)
        {
            iv_dds_enabled = false;
            break;
        }

        //If we have reached this point, that means VDM is ok to be enabled. Only then we try to
        //enable wov undervolting
        if  (((iv_attrs.attr_wov_underv_force == 1))  && 
                is_wov_underv_enabled() == 1) {
            iv_wov_underv_enabled = true;
            FAPI_INF("UNDERV_TESTED or UNDERV_FORCE set to 1");
        } else{
            iv_wov_underv_enabled = false;
            FAPI_INF("UNDERV_TESTED and UNDERV_FORCE set to 0");
        }
    }
    while(0);

fapi_try_exit:
    return fapi2::FAPI2_RC_SUCCESS;
}

///////////////////////////////////////////////////////////
////////  is_wov_underv_enabled 
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_wov_underv_enabled()
{
    return(!(iv_attrs.attr_wov_underv_disable) &&
         iv_wov_underv_enabled)
         ? true : false;
}

///--------------------------------------
///////////////////////////////////////////////////////////
//////// is_wov_overv_enabled 
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_wov_overv_enabled()
{
    return (!(iv_attrs.attr_wov_overv_disable) &&
         iv_wov_overv_enabled)
         ? true : false;
}

///////////////////////////////////////////////////////////
////////  get_mvpd_iddq
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::get_mvpd_iddq( void )
{

    uint8_t*        l_buffer_iq_c =  nullptr;
    uint32_t        l_record = 0;
    uint32_t        l_bufferSize_iq  = IQ_BUFFER_ALLOC;


    // --------------------------------------------
    // Process IQ Keyword (IDDQ) Data
    // --------------------------------------------

    // set l_record to appropriate cprx record
    l_record = (uint32_t)fapi2::MVPD_RECORD_CRP0;

    //First read is to get size of vpd record, note the o_buffer is nullptr
    FAPI_TRY( getMvpdField((fapi2::MvpdRecord)l_record,
                           fapi2::MVPD_KEYWORD_IQ,
                           iv_procChip,
                           nullptr,
                           l_bufferSize_iq) );

    //Allocate memory for vpd data
    l_buffer_iq_c = reinterpret_cast<uint8_t*>(malloc(l_bufferSize_iq));

    // Get Chip IQ MVPD data from the CRPx records
    FAPI_TRY(getMvpdField((fapi2::MvpdRecord)l_record,
                          fapi2::MVPD_KEYWORD_IQ,
                          iv_procChip,
                          l_buffer_iq_c,
                          l_bufferSize_iq));

    //copy VPD data to IQ structure table
    memcpy(&iv_iddqt, l_buffer_iq_c, l_bufferSize_iq);

    //Verify Payload header data.
    if ( !(iv_iddqt.iddq_version) ||
         !(iv_iddqt.good_normal_cores_per_sort))
    {
        iv_wof_enabled = false;
        FAPI_ASSERT_NOEXIT(false,
                           fapi2::PSTATE_PB_IQ_VPD_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                           .set_CHIP_TARGET(iv_procChip)
                           .set_VERSION(iv_iddqt.iddq_version)
                           .set_GOOD_NORMAL_CORES_PER_SORT(iv_iddqt.good_normal_cores_per_sort),
                           "Pstate Parameter Block IQ Payload data error being logged");
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }

    //Verify ivdd_all_cores_off_caches_off has MSB bit is set
    //if yes then initialized to 0
    for (int i = 0; i < IDDQ_MEASUREMENTS; ++i)
    {
       if ( iv_iddqt.iddq_all_good_cores_off_good_caches_off_5ma[i] & 0x8000)
       {
           iv_iddqt.iddq_all_good_cores_off_good_caches_off_5ma[i] = 0;
       }
    }
    // Put out the structure to the trace
    iddq_print(&iv_iddqt);

fapi_try_exit:

    // Free up memory buffer
    free(l_buffer_iq_c);

    if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
    {
        iv_wof_enabled = false;
    }

    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
//////// iddq_print 
///////////////////////////////////////////////////////////
void iddq_print(IddqTable_t* i_iddqt)
{
    uint32_t        i, j;
    const char*     idd_meas_str[IDDQ_MEASUREMENTS] = IDDQ_ARRAY_VOLTAGES_STR;
    char            l_buffer_str[1024];   // Temporary formatting string buffer
    char            l_line_str[1024];     // Formatted output line string

    static const uint32_t IDDQ_DESC_SIZE = 56;
    static const uint32_t IDDQ_QUAD_SIZE = IDDQ_DESC_SIZE -
                                            strlen("Quad X:");

    FAPI_INF("IDDQ");

    // Put out the endian-corrected scalars

    // get IQ version and advance pointer 1-byte
    FAPI_INF("  IDDQ Version Number = %u", i_iddqt->iddq_version);
    FAPI_INF("  Sort Info:          Good Cores = %02d Good cores per Cache01 = %02d " 
             " Good cores per Cache23 = %02d Good cores per Cache45 = %02d " 
             "Good cores per Cache67 = %02d ",
             i_iddqt->good_normal_cores_per_sort,
             i_iddqt->good_normal_cores_per_EQs[0],
             i_iddqt->good_normal_cores_per_EQs[1],
             i_iddqt->good_normal_cores_per_EQs[2],
             i_iddqt->good_normal_cores_per_EQs[3]);

    FAPI_INF("MMA state %d",i_iddqt->mma_not_active);

    FAPI_INF("MMA leakage percent %d",i_iddqt->mma_off_leakage_pct);

    // All IQ IDDQ measurements are at 5mA resolution. The OCC wants to
    // consume these at 1mA values.  thus, all values are multiplied by
    // 5 upon installation into the paramater block.
    static const uint32_t CONST_5MA_1MA = 5;
    FAPI_INF("  IDDQ data is converted 5mA units to 1mA units");

    // Put out the measurement voltages to the trace.
    strcpy(l_line_str, "  Measurement voltages:");
    sprintf(l_buffer_str, "%-*s ", IDDQ_DESC_SIZE, l_line_str);
    strcpy(l_line_str, l_buffer_str);
    strcpy(l_buffer_str, "");

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        sprintf(l_buffer_str, "  %*sV  ", 5, idd_meas_str[i]);
        strcat(l_line_str, l_buffer_str);
    }

    FAPI_INF("%s", l_line_str);

#define IDDQ_CURRENT_EXTRACT(_member) \
        { \
        uint16_t _temp = revle16(i_iddqt->_member) * CONST_5MA_1MA;     \
        sprintf(l_buffer_str, "  %6.3f ", (double)_temp/1000);          \
        strcat(l_line_str, l_buffer_str); \
        }

// Temps are all 1B quantities.  Not endianess issues.
#define IDDQ_TEMP_EXTRACT(_member) \
        sprintf(l_buffer_str, "   %4.1f  ", ((double)i_iddqt->_member)/2); \
        strcat(l_line_str, l_buffer_str);

#define IDDQ_TRACE(string, size) \
        strcpy(l_line_str, string); \
        sprintf(l_buffer_str, "%-*s", size, l_line_str);\
        strcpy(l_line_str, l_buffer_str); \
        strcpy(l_buffer_str, "");

    // get IVDDQ measurements with all good cores ON
    IDDQ_TRACE ("  IDDQ all good cores ON:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_CURRENT_EXTRACT(iddq_all_good_cores_on_caches_on_5ma[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get IVDDQ measurements with all cores and caches OFF
    IDDQ_TRACE ("  IVDDQ all cores and caches OFF:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
       IDDQ_CURRENT_EXTRACT(iddq_all_good_cores_off_good_caches_off_5ma[i]);
    }

    FAPI_INF("%s", l_line_str);;

    // get IVDDQ measurements with all good cores OFF and caches ON
    IDDQ_TRACE ("  IVDDQ all good cores OFF and caches ON:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_CURRENT_EXTRACT(iddq_all_good_cores_off_good_caches_on_5ma[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get IVDDQ measurements with all good cores in each quad
    for (i = 0; i < MAXIMUM_EQ_SETS; i++)
    {
        IDDQ_TRACE ("  IVDDQ all good cores ON and caches ON ", IDDQ_QUAD_SIZE);
        sprintf(l_buffer_str, "Quad %d:", i);
        strcat(l_line_str, l_buffer_str);

        for (j = 0; j < IDDQ_MEASUREMENTS; j++)
        {
            IDDQ_CURRENT_EXTRACT(iddq_eqs_good_cores_on_good_caches_on_5ma[i][j]);
        }

        FAPI_INF("%s", l_line_str);
    }

    // get ICSQ measurements with all good cores ON
    IDDQ_TRACE ("  ICSQ all good cores ON:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_CURRENT_EXTRACT(icsq_all_good_cores_on_caches_on_5ma[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get ICSQ measurements with all cores and caches OFF
    IDDQ_TRACE ("  ICSQ all cores and caches OFF:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
       IDDQ_CURRENT_EXTRACT(icsq_all_good_cores_off_good_caches_off_5ma[i]);
    }

    FAPI_INF("%s", l_line_str);;

    // get ICSQ measurements with all good cores OFF and caches ON
    IDDQ_TRACE ("  ICSQ all good cores OFF and caches ON:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_CURRENT_EXTRACT(icsq_all_good_cores_off_good_caches_on_5ma[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get ICSQ measurements with all good cores in each quad
    for (i = 0; i < MAXIMUM_EQ_SETS; i++)
    {
        IDDQ_TRACE ("  ICSQ all good cores ON and caches ON ", IDDQ_QUAD_SIZE);
        sprintf(l_buffer_str, "Quad %d:", i);
        strcat(l_line_str, l_buffer_str);

        for (j = 0; j < IDDQ_MEASUREMENTS; j++)
        {
            IDDQ_CURRENT_EXTRACT(icsq_eqs_good_cores_on_good_caches_on_5ma[i][j]);
        }

        FAPI_INF("%s", l_line_str);
    }

    // get average temperature measurements with all good cores ON
    IDDQ_TRACE ("  Average temp all good cores ON:",IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
         IDDQ_TEMP_EXTRACT(avgtemp_all_cores_on_good_caches_on_p5c[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get average temperature measurements with all cores and caches OFF
    IDDQ_TRACE ("  Average temp all cores OFF, caches OFF:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_TEMP_EXTRACT(avgtemp_all_cores_off_caches_off_p5c[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get average temperature measurements with all good cores OFF and caches ON
    IDDQ_TRACE ("  Average temp all good cores OFF, caches ON:",IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_TEMP_EXTRACT(avgtemp_all_good_cores_off_good_caches_on_p5c[i]);
    }

    FAPI_INF("%s", l_line_str);
}

///////////////////////////////////////////////////////////
////////   compute_vpd_pts
///////////////////////////////////////////////////////////
void PlatPmPPB::compute_vpd_pts()
{
    int p = 0;

    uint32_t l_vdd_loadline_uohm    = revle32(iv_vdd_sysparam.loadline_uohm);
    uint32_t l_vdd_distloss_uohm    = revle32(iv_vdd_sysparam.distloss_uohm);
    uint32_t l_vdd_distoffset_uv    = revle32(iv_vdd_sysparam.distoffset_uv);
    uint32_t l_vcs_loadline_uohm    = revle32(iv_vcs_sysparam.loadline_uohm);
    uint32_t l_vcs_distloss_uohm    = revle32(iv_vcs_sysparam.distloss_uohm);
    uint32_t l_vcs_distoffset_uv    = revle32(iv_vcs_sysparam.distoffset_uv);


    //RAW POINTS. We just copy them as is
    memcpy (iv_operating_points[VPD_PT_SET_RAW], iv_attr_mvpd_poundV_raw, sizeof(iv_attr_mvpd_poundV_raw));
    for (p = 0; p < NUM_PV_POINTS; p++)
    {
        FAPI_DBG("GP: OpPoint=[%d][%d], PS=%3d, Freq=%3X (%4d), Vdd=%3X (%4d)",
                VPD_PT_SET_RAW, p,
                iv_operating_points[VPD_PT_SET_RAW][p].pstate,
                (iv_operating_points[VPD_PT_SET_RAW][p].frequency_mhz),
                (iv_operating_points[VPD_PT_SET_RAW][p].frequency_mhz),
                (iv_operating_points[VPD_PT_SET_RAW][p].vdd_mv),
                (iv_operating_points[VPD_PT_SET_RAW][p].vdd_mv));

        //BIASED POINTS
        uint32_t l_frequency_mhz = (iv_attr_mvpd_poundV_biased[p].frequency_mhz);
        uint32_t l_vdd_mv = (iv_attr_mvpd_poundV_biased[p].vdd_mv);
        uint32_t l_vcs_mv = (iv_attr_mvpd_poundV_biased[p].vcs_mv);

        iv_operating_points[VPD_PT_SET_BIASED][p].vdd_mv =
            bias_adjust_mv(l_vdd_mv, iv_bias.vdd_ext_0p5pct[p]);

        iv_operating_points[VPD_PT_SET_BIASED][p].vcs_mv =
            bias_adjust_mv(l_vcs_mv, iv_bias.vcs_ext_0p5pct[p]);

        iv_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz =
            bias_adjust_mhz(l_frequency_mhz, iv_bias.frequency_0p5pct);

        iv_operating_points[VPD_PT_SET_BIASED][p].idd_tdp_ac_10ma=
            iv_attr_mvpd_poundV_biased[p].idd_tdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].idd_tdp_dc_10ma=
            iv_attr_mvpd_poundV_biased[p].idd_tdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].idd_rdp_ac_10ma=
            iv_attr_mvpd_poundV_biased[p].idd_rdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].idd_rdp_dc_10ma=
            iv_attr_mvpd_poundV_biased[p].idd_rdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].frequency_guardband_sort_mhz =
            iv_attr_mvpd_poundV_biased[p].frequency_guardband_sort_mhz;
        iv_operating_points[VPD_PT_SET_BIASED][p].vdd_vmin =
            iv_attr_mvpd_poundV_biased[p].vdd_vmin;
        iv_operating_points[VPD_PT_SET_BIASED][p].idd_power_pattern_10ma =
            iv_attr_mvpd_poundV_biased[p].idd_power_pattern_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].core_power_pattern_temp_0p5C =
            iv_attr_mvpd_poundV_biased[p].core_power_pattern_temp_0p5C;
        iv_operating_points[VPD_PT_SET_BIASED][p].pstate =
            iv_attr_mvpd_poundV_biased[p].pstate;
    }

    // As this is memory to memory, Endianess correction is not necessary.
    iv_reference_frequency_khz =
        (iv_operating_points[VPD_PT_SET_BIASED][VPD_PV_UT].frequency_mhz) * 1000;

    FAPI_DBG("Reference into GPPB: LE local Freq=%X (%d);  Freq=%X (%d)",
                iv_reference_frequency_khz,
                iv_reference_frequency_khz,
                (iv_reference_frequency_khz),
                (iv_reference_frequency_khz));

    // Now that the VPD_PV_UT frequency is known, Pstates can be calculated
    for (p = 0; p < NUM_PV_POINTS; p++)
    {
        iv_operating_points[VPD_PT_SET_BIASED][p].pstate =
            ((((iv_operating_points[VPD_PT_SET_BIASED][VPD_PV_UT].frequency_mhz) -
               (iv_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz)) * 1000) /
             (iv_frequency_step_khz));

        FAPI_DBG("Bi: OpPoint=[%d][%d], PS=%3d, Freq=%3X (%4d), Vdd=%3X (%4d), UT Freq=%3X (%4d) Step Freq=%5d",
                    VPD_PT_SET_BIASED, p,
                    iv_operating_points[VPD_PT_SET_BIASED][p].pstate,
                    (iv_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz),
                    (iv_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz),
                    (iv_operating_points[VPD_PT_SET_BIASED][p].vdd_mv),
                    (iv_operating_points[VPD_PT_SET_BIASED][p].vdd_mv),
                    (iv_operating_points[VPD_PT_SET_BIASED][VPD_PV_UT].frequency_mhz),
                    (iv_operating_points[VPD_PT_SET_BIASED][VPD_PV_UT].frequency_mhz),
                    (iv_frequency_step_khz));

    }

    //BIASED POINTS and SYSTEM PARMS APPLIED POINTS
    for (p = 0; p < NUM_PV_POINTS; p++)
    {
        uint32_t l_vdd_mv = (iv_operating_points[VPD_PT_SET_BIASED][p].vdd_mv);
        uint32_t l_idd_ma = (iv_operating_points[VPD_PT_SET_BIASED][p].idd_tdp_dc_10ma) * 100 +
                             (iv_operating_points[VPD_PT_SET_BIASED][p].idd_tdp_ac_10ma) * 100;
        uint32_t l_vcs_mv = (iv_operating_points[VPD_PT_SET_BIASED][p].vcs_mv);
        uint32_t l_ics_ma = (iv_operating_points[VPD_PT_SET_BIASED][p].ics_tdp_dc_10ma) * 100 + 
                             (iv_operating_points[VPD_PT_SET_BIASED][p].ics_tdp_ac_10ma) * 100;

        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].vdd_mv =
                    sysparm_uplift(l_vdd_mv,
                                   l_idd_ma,
                                   l_vdd_loadline_uohm,
                                   l_vdd_distloss_uohm,
                                   l_vdd_distoffset_uv);


        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].vcs_mv =
                    sysparm_uplift(l_vcs_mv,
                                   l_ics_ma,
                                   l_vcs_loadline_uohm,
                                   l_vcs_distloss_uohm,
                                   l_vcs_distoffset_uv);

        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].idd_tdp_ac_10ma=
                   iv_attr_mvpd_poundV_biased[p].idd_tdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].idd_tdp_dc_10ma=
                   iv_attr_mvpd_poundV_biased[p].idd_tdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].idd_rdp_ac_10ma=
                   iv_attr_mvpd_poundV_biased[p].idd_rdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].idd_rdp_dc_10ma=
                   iv_attr_mvpd_poundV_biased[p].idd_rdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].frequency_guardband_sort_mhz =
                   iv_attr_mvpd_poundV_biased[p].frequency_guardband_sort_mhz;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].vdd_vmin =
                   iv_attr_mvpd_poundV_biased[p].vdd_vmin;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].idd_power_pattern_10ma =
                   iv_attr_mvpd_poundV_biased[p].idd_power_pattern_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].core_power_pattern_temp_0p5C =
                   iv_attr_mvpd_poundV_biased[p].core_power_pattern_temp_0p5C;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].pstate =
                   iv_attr_mvpd_poundV_biased[p].pstate;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].frequency_mhz =
               iv_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz;
    }
}


///////////////////////////////////////////////////////////
////////  safe_mode_init 
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::safe_mode_init( void )
{
    FAPI_INF(">>>>>>>>>> safe_mode_init");
    uint8_t l_ps_pstate = 0;
    uint32_t l_ps_freq_khz = 
    iv_operating_points[VPD_PT_SET_BIASED][VPD_PV_PSAV].frequency_mhz * 1000;

    do
    {
        if (!iv_attrs.attr_pm_safe_voltage_mv[VDD] &&
             !iv_attrs.attr_pm_safe_voltage_mv[VCS] &&
                !iv_attrs.attr_pm_safe_frequency_mhz)
        {
            freq2pState( l_ps_freq_khz, &l_ps_pstate);

            //Compute safe mode values
            FAPI_TRY(safe_mode_computation (
                        l_ps_pstate),
                    "Error from safe_mode_computation function");

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ,
                        iv_procChip,iv_attrs.attr_pm_safe_frequency_mhz ));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAFE_MODE_VOLTAGE_MV,
                        iv_procChip, iv_attrs.attr_pm_safe_voltage_mv));

        }
    }while(0);

fapi_try_exit:
    FAPI_INF("<<<<<<<<<< safe_mode_init");
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////   safe_mode_computation
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::safe_mode_computation(
                                const Pstate i_ps_pstate)
{
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ_Type l_safe_mode_freq_mhz;
    fapi2::ATTR_SAFE_MODE_VOLTAGE_MV_Type    l_safe_mode_mv;
    uint32_t                                 l_safe_mode_op_ps2freq_mhz;
    uint32_t                                 l_safe_op_freq_mhz;
    uint32_t                                 l_safe_vdm_jump_value;
    uint8_t                                  l_safe_op_ps;;
    uint32_t                                 l_core_floor_mhz;
    uint32_t                                 l_op_pt;
    Pstate                                   l_safe_mode_ps;


    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_CORE_FLOOR_MHZ,
                           iv_procChip,
                           l_core_floor_mhz));

    // Core floor frequency should be less than ultra turbo freq..
    // if not log an error
    if ((l_core_floor_mhz*1000) > iv_reference_frequency_khz)
    {
        FAPI_ERR("Core floor frequency %08x is greater than UltraTurbo frequency %08x",
                  (l_core_floor_mhz*1000), iv_reference_frequency_khz);
        FAPI_ASSERT(false,
                    fapi2::PSTATE_PB_CORE_FLOOR_FREQ_GT_UT_FREQ()
                    .set_CHIP_TARGET(iv_procChip)
                    .set_CORE_FLOOR_FREQ(l_core_floor_mhz*1000)
                    .set_UT_FREQ(iv_reference_frequency_khz),
                    "Core floor freqency is greater than UltraTurbo frequency");
    }


    FAPI_INF ("core_floor_mhz 0%08x (%d)",
                l_core_floor_mhz,
                l_core_floor_mhz);
    FAPI_INF("operating_point[VPD_PV_PSAV].frequency_mhz 0%08x (%d)",
                (iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_PSAV].frequency_mhz),
                (iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_PSAV].frequency_mhz));
    FAPI_INF ("reference_freq 0%08x (%d)",
                iv_reference_frequency_khz, iv_reference_frequency_khz);
    FAPI_INF ("step_frequency 0%08x (%d)",
                iv_frequency_step_khz, iv_frequency_step_khz);

    //#V PS frequency
    l_op_pt = (iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_PSAV].frequency_mhz);

    // Safe operational frequency is the MAX(core floor, VPD Powersave).
    // PowerSave is the lowest operational frequency that the part was tested at
    if ((iv_attrs.attr_system_dds_disable) &&
        (l_core_floor_mhz > l_op_pt))
    {
        FAPI_INF("Core floor greater that VPD_PV_PSAV");
        l_safe_op_freq_mhz = l_core_floor_mhz;
    }
    else
    {
        FAPI_INF("Core floor less than or equal to VPD_PV_PSAV");
        l_safe_op_freq_mhz = l_op_pt;
    }

    FAPI_INF ("safe_mode_values.safe_op_freq_mhz 0%08x (%d)",
                 l_safe_op_freq_mhz,
                 l_safe_op_freq_mhz);

    // Calculate safe operational pstate.  This must be rounded down to create
    // a faster Pstate than the floor
    l_safe_op_ps = ((float)(iv_reference_frequency_khz) -
                    (float)(l_safe_op_freq_mhz * 1000)) /
                    (float)iv_frequency_step_khz;

    l_safe_mode_op_ps2freq_mhz    = (iv_reference_frequency_khz - 
                                    (l_safe_op_ps * iv_frequency_step_khz)) / 1000;

    while (l_safe_mode_op_ps2freq_mhz < l_safe_op_freq_mhz)
    {
        l_safe_op_ps--;

        l_safe_mode_op_ps2freq_mhz =
            (iv_reference_frequency_khz - (l_safe_op_ps * iv_frequency_step_khz)) / 1000;
    }
    if (iv_attrs.attr_system_dds_disable)
    {
        // Calculate safe jump value for large frequency
        l_safe_vdm_jump_value = 
            iv_poundW_data.other.dpll_settings.fields.N_L_drop_3p125pct;

        FAPI_INF ("l_safe_vdm_jump_value 0x%x -> %5.2f %%",
                l_safe_vdm_jump_value,
                ((float)l_safe_vdm_jump_value/32)*100);

        // Calculate safe mode frequency - Round up to nearest MHz
        // The uplifted frequency is based on the fact that the DPLL percentage is a
        // "down" value. Hence:
        //     X (uplifted safe) = Y (safe operating) / (1 - droop percentage)
        l_safe_mode_freq_mhz = (uint32_t)
            (((float)l_safe_mode_op_ps2freq_mhz * 1000 /
              (1 - (float)l_safe_vdm_jump_value/32) + 500) / 1000);
    }
    else
    {
        l_safe_mode_freq_mhz = l_safe_mode_op_ps2freq_mhz;
    }

    FAPI_INF("Setting safe mode frequency to %d MHz (0x%x) 0x%x",
              l_safe_mode_freq_mhz,
              l_safe_mode_freq_mhz, iv_reference_frequency_khz);

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ, iv_procChip, l_safe_mode_freq_mhz));

    FAPI_INF ("l_safe_mode_freq_mhz 0x%0x (%d)",
                l_safe_mode_freq_mhz,
                l_safe_mode_freq_mhz);

    // Safe frequency must be less than ultra turbo freq.
    // if not log an error
    if ((l_safe_mode_freq_mhz*1000) > iv_reference_frequency_khz)
    {
        FAPI_ERR("Safe mode frequency %08x is greater than UltraTurbo frequency %08x",
                  (l_safe_mode_freq_mhz*1000), iv_reference_frequency_khz);
        FAPI_ASSERT(false,
                    fapi2::PSTATE_PB_SAFE_FREQ_GT_UT_FREQ()
                    .set_CHIP_TARGET(iv_procChip)
                    .set_SAFE_FREQ(l_safe_mode_freq_mhz*1000)
                    .set_UT_FREQ(iv_reference_frequency_khz),
                    "Safe mode freqency is greater than UltraTurbo frequency");
    }

    l_safe_mode_ps = ((float)(iv_reference_frequency_khz) -
                     (float)(l_safe_mode_freq_mhz * 1000)) /
                     (float)iv_frequency_step_khz;

    FAPI_INF ("l_safe_mode_ps 0x%x (%d)",l_safe_mode_ps, l_safe_mode_ps);

    // Calculate safe mode voltage
    // Use the biased with system parms operating points

    if (!iv_attrs.attr_system_dds_disable)
    {
        l_safe_mode_mv[VDD] = ps2v_mv(l_safe_mode_ps, VDD);
        l_safe_mode_mv[VCS] = ps2v_mv(l_safe_mode_ps, VCS);
        FAPI_INF("DDS not enabled Setting safe mode VDD voltage to %d mv (0x%x)",
                l_safe_mode_mv[VDD],
                l_safe_mode_mv[VDD]);
        FAPI_INF("DDS not enabled Setting safe mode VCS voltage to %d mv (0x%x)",
                l_safe_mode_mv[VCS],
                l_safe_mode_mv[VCS]);
    }
    else
    {
        l_safe_mode_mv[VDD] = ps2v_mv(l_safe_mode_ps, VDD) + iv_attrs.attr_save_mode_nodds_uplift_mv[VDD];
        l_safe_mode_mv[VCS] = ps2v_mv(l_safe_mode_ps, VCS) + iv_attrs.attr_save_mode_nodds_uplift_mv[VCS];

        FAPI_INF("DDS enabled Setting safe mode VDD voltage to %d mv (0x%x) with uplift %d mv (0x%x)",
                l_safe_mode_mv[VDD],
                l_safe_mode_mv[VDD],
                iv_attrs.attr_save_mode_nodds_uplift_mv[VDD],
                iv_attrs.attr_save_mode_nodds_uplift_mv[VDD]);
        FAPI_INF("DDS enabled Setting safe mode VCS voltage to %d mv (0x%x) with uplift %d mv (0x%x)",
                l_safe_mode_mv[VCS],
                l_safe_mode_mv[VCS],
                iv_attrs.attr_save_mode_nodds_uplift_mv[VCS],
                iv_attrs.attr_save_mode_nodds_uplift_mv[VCS]);
    }


    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SAFE_MODE_VOLTAGE_MV,
                               iv_procChip,
                               l_safe_mode_mv));


    // Calculate boot mode voltage
    iv_attrs.attr_boot_voltage_mv[VDD] = bias_adjust_mv(iv_attr_mvpd_poundV_biased[VPD_PV_PSAV].vdd_mv,
                                                     iv_attrs.attr_boot_voltage_biase_0p5pct);


    iv_attrs.attr_boot_voltage_mv[VCS] = bias_adjust_mv(iv_attr_mvpd_poundV_biased[VPD_PV_PSAV].vcs_mv,
                                              iv_attrs.attr_boot_voltage_biase_0p5pct);


    FAPI_INF("VDD boot_mode_mv 0x%x (%d)",
        iv_attrs.attr_boot_voltage_mv[VDD],
        iv_attrs.attr_boot_voltage_mv[VDD]);

    FAPI_INF("VCS boot_mode_mv 0x%x (%d)",
        iv_attrs.attr_boot_voltage_mv[VCS],
        iv_attrs.attr_boot_voltage_mv[VCS]);


fapi_try_exit:
    return fapi2::current_err;
}



///////////////////////////////////////////////////////////
////////  ps2v_mv 
///////////////////////////////////////////////////////////
uint32_t PlatPmPPB::ps2v_mv(const Pstate i_pstate,
                            const boot_voltage_type i_type)
{

    uint8_t l_SlopeValue =1;
    uint32_t l_boot_voltage = 0;

    FAPI_DBG("i_pstate = 0x%x, (%d)", i_pstate, i_pstate);

    if (i_type == VDD)
    {

        FAPI_INF("l_operating_points[POWERSAVE].vdd_mv 0x%-3x (%d)",
                (iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_PSAV].vdd_mv),
                (iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_PSAV].vdd_mv));
        FAPI_INF("l_operating_points[POWERSAVE].pstate 0x%-3x (%d)",
                iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_PSAV].pstate,
                iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_PSAV].pstate);



        uint32_t x = (l_SlopeValue * (-i_pstate + iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_PSAV].pstate));
        uint32_t y = x >> VID_SLOPE_FP_SHIFT_12;

        uint32_t l_vdd =
            (((l_SlopeValue * (-i_pstate + iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_PSAV].pstate)) >> VID_SLOPE_FP_SHIFT_12)
             + (iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_PSAV].vdd_mv));

        // Round up
        l_vdd = (l_vdd << 1) + 1;
        l_vdd = l_vdd >> 1;

        FAPI_DBG("i_pstate = %d "
                "i_operating_points[VPD_PV_PSAV].pstate) = %d "
                "i_operating_points[VPD_PV_PSAV].vdd_mv  = %d "
                "VID_SLOPE_FP_SHIFT_12 = %X "
                "x = 0x%x  (%d) y = 0x%x (%d)",
                i_pstate,
                iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_PSAV].pstate,
                (iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_PSAV].vdd_mv),
                VID_SLOPE_FP_SHIFT_12,
                x, x,
                y, y);
        l_boot_voltage = l_vdd;

        FAPI_INF ("l_vdd 0x%x (%d)", l_vdd, l_vdd);
    }
    if (i_type == VCS)
    {

        FAPI_INF("l_operating_points[VPD_PV_PSAV].vcs_mv 0x%-3x (%d)",
                (iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_PSAV].vcs_mv),
                (iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_PSAV].vcs_mv));
        FAPI_INF("l_operating_points[VPD_PV_PSAV].pstate 0x%-3x (%d)",
                iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_PSAV].pstate,
                iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_PSAV].pstate);



        uint32_t x = (l_SlopeValue * (-i_pstate + iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_PSAV].pstate));
        uint32_t y = x >> VID_SLOPE_FP_SHIFT_12;

        uint32_t l_vcs =
            (((l_SlopeValue * (-i_pstate + iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_PSAV].pstate)) >> VID_SLOPE_FP_SHIFT_12)
             + (iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_PSAV].vcs_mv));

        // Round up
        l_vcs = (l_vcs << 1) + 1;
        l_vcs = l_vcs >> 1;

        FAPI_DBG("i_pstate = %d "
                "i_operating_points[VPD_PV_PSAV].pstate = %d "
                "i_operating_points[VPD_PV_PSAV].vcs_mv  = %d "
                "VID_SLOPE_FP_SHIFT_12 = %X "
                "x = 0x%x  (%d) y = 0x%x (%d)",
                i_pstate,
                iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_PSAV].pstate,
                (iv_operating_points[VPD_PT_SET_BIASED_SYSP][VPD_PV_PSAV].vcs_mv),
                VID_SLOPE_FP_SHIFT_12,
                x, x,
                y, y);
        l_boot_voltage = l_vcs;

        FAPI_INF ("l_vcs 0x%x (%d)", l_vcs, l_vcs);
    }


    return l_boot_voltage;
}

///////////////////////////////////////////////////////////
////////    freq2pState 
///////////////////////////////////////////////////////////
int PlatPmPPB::freq2pState (const uint32_t i_freq_khz,
                            Pstate* o_pstate,
                            const FREQ2PSTATE_ROUNDING i_round)
{
    int rc = 0;
    float pstate32 = 0;

    // ----------------------------------
    // compute pstate for given frequency
    // ----------------------------------
    pstate32 = ((float)((iv_reference_frequency_khz) - (float)i_freq_khz)) /
                (float) (iv_frequency_step_khz);
    // @todo Bug fix from Characterization team to deal with VPD not being
    // exactly in step increments
    //       - not yet included to separate changes
    // As higher Pstate numbers represent lower frequencies, the pstate must be
    // snapped to the nearest *higher* integer value for safety.  (e.g. slower
    // frequencies are safer).
    if ((i_round ==  ROUND_SLOW) && (i_freq_khz))
    {
        *o_pstate  = (Pstate)internal_ceil(pstate32);
        FAPI_DBG("freq2pState: ROUND SLOW");
    }
    else
    {
        *o_pstate  = (Pstate)pstate32;
         FAPI_DBG("freq2pState: ROUND FAST");
    }

    FAPI_DBG("freq2pState: i_freq_khz = %u (0x%X); pstate32 = %f; o_pstate = %u (0x%X)",
                i_freq_khz, i_freq_khz, pstate32, *o_pstate, *o_pstate);
    FAPI_DBG("freq2pState: ref_freq_khz = %u (0x%X); step_freq_khz= %u (0x%X)",
                (iv_reference_frequency_khz),
                (iv_reference_frequency_khz),
                (iv_frequency_step_khz),
                (iv_frequency_step_khz));

    // ------------------------------
    // perform pstate bounds checking
    // ------------------------------
    if (pstate32 < PSTATE_MIN)
    {
        rc = -PSTATE_LT_PSTATE_MIN;
        *o_pstate = PSTATE_MIN;
    }

    if (pstate32 > PSTATE_MAX)
    {
        rc = -PSTATE_GT_PSTATE_MAX;
        *o_pstate = PSTATE_MAX;
    }

    return rc;
}


///////////////////////////////////////////////////////////
////////   get_pstate_attrs
///////////////////////////////////////////////////////////
void PlatPmPPB::get_pstate_attrs(AttributeList &o_attr)
{
    memcpy(&o_attr,&iv_attrs, sizeof(iv_attrs));
} // end of get_pstate_attrs

// *INDENT-ON*
