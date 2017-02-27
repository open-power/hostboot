/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pstate_parameter_block.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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

///
/// @file  p9_pstate_parameter_block.C
/// @brief Setup Pstate super structure for PGPE/CME HCode
///
/// *HWP HW Owner        : Sudheendra K Srivathsa <sudheendraks@in.ibm.com>
/// *HWP HW Backup Owner : Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner        : Sangeetha T S <sangeet2@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 2
/// *HWP Consumed by     : PGPE,CME
///
/// @verbatim
/// Procedure Summary:
///   - Read VPD and attributes to create the Pstate Parameter Block(s) (one each for PGPE,OCC and CMEs).
/// @endverbatim

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi2.H>
#include <p9_pstate_parameter_block.H>
#include "p9_pm_get_poundv_bucket.H"

// START OF PSTATE PARAMETER BLOCK function

/// -------------------------------------------------------------------
/// @brief Populate Pstate super structure from VPD data
/// @param[in]    i_target          => Chip Target
/// @param[inout] *pss              => pointer to pstate superstructure
/// @return   FAPI2::SUCCESS
/// -------------------------------------------------------------------

fapi2::ReturnCode
p9_pstate_parameter_block( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                           PstateSuperStructure* io_pss)
{
    int rc;
    FAPI_INF("> p9_pstate_parameter_block");


    do
    {
        // -----------------------------------------------------------
        // Clear the PstateSuperStructure and install the magic number
        //----------------------------------------------------------
        memset(io_pss, 0, sizeof(PstateSuperStructure));
        FAPI_INF("Populating magic number in Pstate Parameter block structure");
        (*io_pss).magic = revle64(PSTATE_PARMSBLOCK_MAGIC);

        //Local variables for Global,local and OCC parameter blocks
        // PGPE content
        GlobalPstateParmBlock l_globalppb;

        // CME content
        LocalPstateParmBlock l_localppb;

        // OCC content
        OCCPstateParmBlock l_occppb;

        memset (&l_globalppb, 0, sizeof(GlobalPstateParmBlock));
        memset (&l_localppb, 0, sizeof(LocalPstateParmBlock));
        memset (&l_occppb , 0, sizeof (OCCPstateParmBlock));

        // Struct Variable for all attributes
        AttributeList attr;
        //ChipCharacterization* characterization;

        // MVPD #V variables
        uint32_t attr_mvpd_voltage_control[PV_D][PV_W];
        uint8_t present_chiplets = 0;
        uint32_t valid_pdv_points = 0;

        //Variables for Loadline, Distribution loss and offset
        SysPowerDistParms l_vdd_sysparm;
        SysPowerDistParms l_vcs_sysparm;
        SysPowerDistParms l_vdn_sysparm;

        // Local IDDQ table variable
        IddqTable l_iddqt;

        // Frequency step variable
        double l_frequency_step_khz;

        //VDM Parm block
        VDMParmBlock l_vdmpb;

        //Resonant Clocking setup
        ResonantClockingSetup l_resclk_setup;

        //IVRM Parm block
        IvrmParmBlock l_ivrmpb;

        // VPD voltage and frequency biases
        VpdBias l_vpdbias[VPD_PV_POINTS];

        // Quad Manager Flags
        QuadManagerFlags l_qm_flags;
        fapi2::buffer<uint16_t> l_data16;

        // -------------------------
        // Get all attributes needed
        // -------------------------
        FAPI_INF("Getting Attributes to build Pstate Superstructure");

        FAPI_TRY(proc_get_attributes(i_target, &attr), "Get attributes function failed");

        // ----------------
        // get #V data
        // ----------------
        FAPI_IMP("Getting #V Data");

        // clear MVPD array
        memset(attr_mvpd_voltage_control, 0, sizeof(attr_mvpd_voltage_control));

        FAPI_TRY(proc_get_mvpd_data( i_target, attr_mvpd_voltage_control, &valid_pdv_points, &present_chiplets),
                 "Get MVPD #V data failed");

        if (!present_chiplets)
        {
            FAPI_ERR("**** ERROR : There are no cores present");
            break;
            //const uint8_t& PRESENT_CHIPLETS = present_chiplets;      //const Target&  CHIP_TARGET = i_target;
            //FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_NO_CORES_PRESENT_ERROR);     //break;
        }

        // ---------------------------------------------
        // process external and internal bias attributes
        // ---------------------------------------------
        FAPI_IMP("Apply Biasing to #V");

        FAPI_TRY(proc_get_extint_bias(attr_mvpd_voltage_control, &attr, l_vpdbias),
                 "Bias application function failed");

        // -----------------------------------------------
        // System power distribution parameters
        // -----------------------------------------------
        // VDD rail
        l_vdd_sysparm.loadline_uohm = revle32(attr.attr_proc_r_loadline_vdd_uohm);
        l_vdd_sysparm.distloss_uohm = revle32(attr.attr_proc_r_distloss_vdd_uohm);
        l_vdd_sysparm.distoffset_uv = revle32(attr.attr_proc_vrm_voffset_vdd_uv);

        // VCS rail
        l_vcs_sysparm.loadline_uohm = revle32(attr.attr_proc_r_loadline_vcs_uohm);
        l_vcs_sysparm.distloss_uohm = revle32(attr.attr_proc_r_distloss_vcs_uohm);
        l_vcs_sysparm.distoffset_uv = revle32(attr.attr_proc_vrm_voffset_vcs_uv);

        // VDN rail
        l_vdn_sysparm.loadline_uohm = revle32(attr.attr_proc_r_loadline_vdn_uohm);
        l_vdn_sysparm.distloss_uohm = revle32(attr.attr_proc_r_distloss_vdn_uohm);
        l_vdn_sysparm.distoffset_uv = revle32(attr.attr_proc_vrm_voffset_vdn_uv);

        // ----------------
        // get IQ (IDDQ) data
        // ----------------
        FAPI_INF("Getting IQ (IDDQ) Data");
        FAPI_TRY(proc_get_mvpd_iddq(i_target, &l_iddqt));

        // ----------------
        // get VDM Parameters data
        // ----------------
        FAPI_INF("Getting VDM Parameters Data");
        FAPI_TRY(proc_get_vdm_parms(i_target, &l_vdmpb));

        // ----------------
        // get Resonant clocking attributes
        // ----------------
        FAPI_INF("Getting Resonant Clocking Parameters Data");
        FAPI_TRY(proc_res_clock_setup(i_target, &l_resclk_setup));

        // ----------------
        // get IVRM Parameters data
        // ----------------
        FAPI_INF("Getting IVRM Parameters Data");
        FAPI_TRY(proc_get_ivrm_parms(i_target, &l_ivrmpb));

        l_data16.flush<0>();
        l_data16.insertFromRight<0, 1>(attr.attr_resclk_enable);
        l_data16.insertFromRight<1, 1>(attr.attr_system_ivrms_enabled);
        l_data16.insertFromRight<2, 1>(attr.attr_system_wof_enabled);
        l_data16.insertFromRight<3, 1>(attr.attr_dpll_dynamic_fmax_enable);
        l_data16.insertFromRight<4, 1>(attr.attr_dpll_dynamic_fmin_enable);
        l_data16.insertFromRight<5, 1>(attr.attr_dpll_droop_protect_enable);

        l_qm_flags.value = revle16(l_data16);

        // -----------------------------------------------
        // Global parameter block
        // -----------------------------------------------

        // Needs to be Endianness corrected going into the block

        l_globalppb.magic = revle64(PSTATE_PARMSBLOCK_MAGIC);

        l_globalppb.options.options = 0;   // until options get defined.

        // Pstate Options @todo RTC 161279, Check what needs to be populated here

        // @todo RTC 161279 - Corresponds to Pstate 0 . Setting to ULTRA TURBO frequency point. REVIEW with Greg
        l_globalppb.reference_frequency_khz = revle32((attr_mvpd_voltage_control[ULTRA][0] * 1000));
        FAPI_INF("Pstate Base Frequency %X (%d)",
                 revle32(l_globalppb.reference_frequency_khz),
                 revle32(l_globalppb.reference_frequency_khz));

        // frequency_step_khz
        l_frequency_step_khz = (attr.attr_freq_proc_refclock_khz / attr.attr_proc_dpll_divider);
        l_globalppb.frequency_step_khz = revle32(l_frequency_step_khz);
        l_globalppb.nest_frequency_mhz = revle32(attr.attr_nest_frequency_mhz);

        // External VRM parameters
        l_globalppb.ext_vrm_transition_start_ns = revle32(attr.attr_ext_vrm_transition_start_ns);
        l_globalppb.ext_vrm_transition_rate_inc_uv_per_us = revle32(attr.attr_ext_vrm_transition_rate_inc_uv_per_us);
        l_globalppb.ext_vrm_transition_rate_dec_uv_per_us = revle32(attr.attr_ext_vrm_transition_rate_dec_uv_per_us);
        l_globalppb.ext_vrm_stabilization_time_us = revle32(attr.attr_ext_vrm_stabilization_time_us);
        l_globalppb.ext_vrm_step_size_mv = revle32(attr.attr_ext_vrm_step_size_mv);

        // -----------------------------------------------
        // populate VpdOperatingPoint with biased MVPD attributes
        // -----------------------------------------------

        FAPI_INF("Load VPD");
        // VPD operating point
        FAPI_TRY(load_mvpd_operating_point(attr_mvpd_voltage_control, l_globalppb.operating_points, l_frequency_step_khz),
                 "Loading MVPD operating point failed");

        // VpdBias External and Internal Biases for Global and Local parameter block
        for (uint8_t i = 0; i < VPD_PV_POINTS; i++)
        {
            l_globalppb.ext_biases[i] = l_vpdbias[i];
            l_globalppb.int_biases[i] = l_vpdbias[i];

            l_localppb.ext_biases[i]  = l_vpdbias[i];
            l_localppb.int_biases[i]  = l_vpdbias[i];
        }

        l_globalppb.vdd_sysparm = l_vdd_sysparm;
        l_globalppb.vcs_sysparm = l_vcs_sysparm;
        l_globalppb.vdn_sysparm = l_vdn_sysparm;

        // safe_voltage_mv
        l_globalppb.safe_voltage_mv = revle32(attr.attr_pm_safe_voltage_mv);

        // safe_frequency_khz
        l_globalppb.safe_frequency_khz = revle32(attr.attr_pm_safe_frequency_mhz / 1000);

        // nest_frequency_khz
        l_globalppb.nest_frequency_mhz = revle32(attr.attr_nest_freq_mhz);

        // @todo RTC 161279
        l_globalppb.ext_vrm_transition_start_ns = revle32(8000);
        l_globalppb.ext_vrm_transition_rate_inc_uv_per_us = revle32(10);
        l_globalppb.ext_vrm_transition_rate_dec_uv_per_us = revle32(10);
        l_globalppb.ext_vrm_stabilization_time_us = revle32(5);
        l_globalppb.ext_vrm_step_size_mv = revle32(50);

        // vrm_stepdelay_range -@todo RTC 161279 potential attributes to be defined

        // vrm_stepdelay_value -@todo RTC 161279 potential attributes to be defined

        // VDMParmBlock vdm
        l_globalppb.vdm = l_vdmpb;

        // IvrmParmBlock
        l_globalppb.ivrm = l_ivrmpb;

        // Resonant Clock Grid Management Setup
        l_globalppb.resclk = l_resclk_setup;

        VpdOperatingPoint l_operating_points[NUM_VPD_PTS_SET][VPD_PV_POINTS];
        // Compute VPD points
        p9_pstate_compute_vpd_pts(l_operating_points, &l_globalppb);

        // Calculate pre-calculated slopes
        p9_pstate_compute_PsV_slopes(l_operating_points, &l_globalppb);

        gppb_print(&(l_globalppb));

        // -----------------------------------------------
        // Local parameter block
        // -----------------------------------------------
        l_localppb.magic = revle64(LOCAL_PARMSBLOCK_MAGIC);

        // QuadManagerFlags
        l_localppb.qmflags = l_qm_flags;

        // VPD operating point
        FAPI_TRY(load_mvpd_operating_point(attr_mvpd_voltage_control, l_localppb.operating_points, l_frequency_step_khz),
                 "Loading MVPD operating point failed");

        l_localppb.vdd_sysparm = l_vdd_sysparm;

        // IvrmParmBlock
        l_localppb.ivrm = l_ivrmpb;

        // VDMParmBlock
        l_localppb.vdm = l_vdmpb;

        // Resonant Clock Grid Management Setup
        l_localppb.resclk = l_resclk_setup;

        // -----------------------------------------------
        // OCC parameter block
        // -----------------------------------------------
        l_occppb.magic = revle64(OCC_PARMSBLOCK_MAGIC);

        // VPD operating point
        FAPI_TRY(load_mvpd_operating_point(attr_mvpd_voltage_control, l_occppb.operating_points, l_frequency_step_khz),
                 "Loading MVPD operating point failed");

        l_occppb.vdd_sysparm = l_vdd_sysparm;
        l_occppb.vcs_sysparm = l_vcs_sysparm;
        l_occppb.vdn_sysparm = l_vdn_sysparm;

        // Iddq Table
        l_occppb.iddq = l_iddqt;

        //WOFElements - @todo RTC 161279 (VID Modification table not populated)
        l_occppb.wof.wof_enabled = attr.attr_system_wof_enabled;
        l_occppb.wof.tdp_rdp_factor = revle32(attr.attr_tdp_rdp_current_factor);

        // frequency_min_khz - Value from Power save operating point after biases
        l_occppb.frequency_min_khz = revle32(attr_mvpd_voltage_control[POWERSAVE][0] * 1000);

        // frequency_max_khz - Value from Ultra Turbo operating point after biases
        l_occppb.frequency_max_khz = revle32(attr_mvpd_voltage_control[ULTRA][0] * 1000);

        // frequency_step_khz
        l_occppb.frequency_step_khz = revle32(l_frequency_step_khz);

        // @todo RTC 161279 - Need Pstate 0 definition and freq2pstate function to be coded

        Pstate pstate_min;
        rc = freq2pState(&l_globalppb, revle32(l_occppb.frequency_min_khz), &pstate_min);

        if (!rc)
        {
            FAPI_ERR("A Bad thing happened!");
        }

        l_occppb.pstate_min = pstate_min;

        // pstate_max

        oppb_print(&(l_occppb));

        // -----------------------------------------------
        // Populate Global,local and OCC parameter blocks into Pstate super structure
        // -----------------------------------------------
        (*io_pss).globalppb = l_globalppb;
        (*io_pss).localppb = l_localppb;
        (*io_pss).occppb = l_occppb;

    }
    while(0);

fapi_try_exit:
    FAPI_INF("< p9_pstate_parameter_block");

    return fapi2::current_err;
}
// END OF PSTATE PARAMETER BLOCK function

// START OF GET ATTRIBUTES function

fapi2::ReturnCode
proc_get_attributes ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                      AttributeList* io_attr)
{
    // --------------------------
    // attributes not yet defined
    // --------------------------
    io_attr->attr_dpll_bias                 = 0;
    io_attr->attr_undervolting              = 0;

    // ---------------------------------------------------------------
    // set ATTR_PROC_DPLL_DIVIDER
    // ---------------------------------------------------------------

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_DPLL_DIVIDER, i_target,
                           io_attr->attr_proc_dpll_divider), "fapiGetAttribute of ATTR_PROC_DPLL_DIVIDER failed");
    FAPI_DBG("ATTR_PROC_DPLL_DIVIDER - get to %x", io_attr->attr_proc_dpll_divider);

    // If value is 0, set a default
    if (!io_attr->attr_proc_dpll_divider)
    {
        FAPI_DBG("ATTR_PROC_DPLL_DIVIDER - setting default to %x", io_attr->attr_proc_dpll_divider);
        io_attr->attr_proc_dpll_divider = 8;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_DPLL_DIVIDER, i_target,
                               io_attr->attr_proc_dpll_divider), "fapiSetAttribute of ATTR_PROC_DPLL_DIVIDER failed");
    }

    FAPI_INF("ATTR_PROC_DPLL_DIVIDER - %x", io_attr->attr_proc_dpll_divider);

    // ----------------------------
    // attributes currently defined
    // ----------------------------
#define DATABLOCK_GET_ATTR(attr_name, target, attr_assign) \
    FAPI_TRY(FAPI_ATTR_GET(fapi2::attr_name, target, io_attr->attr_assign),"Attribute read failed"); \
    FAPI_INF("%-60s = 0x%08x %u", #attr_name, io_attr->attr_assign, io_attr->attr_assign);

    // Frequency Bias attributes
    DATABLOCK_GET_ATTR(ATTR_FREQ_BIAS_ULTRATURBO, i_target, attr_freq_bias_ultraturbo);
    DATABLOCK_GET_ATTR(ATTR_FREQ_BIAS_TURBO, i_target, attr_freq_bias_turbo);
    DATABLOCK_GET_ATTR(ATTR_FREQ_BIAS_NOMINAL, i_target, attr_freq_bias_nominal);
    DATABLOCK_GET_ATTR(ATTR_FREQ_BIAS_POWERSAVE, i_target, attr_freq_bias_powersave);

    // Voltage Bias attributes
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VDD_BIAS_ULTRATURBO, i_target, attr_voltage_ext_vdd_bias_ultraturbo);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VDD_BIAS_TURBO, i_target, attr_voltage_ext_vdd_bias_turbo);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VDD_BIAS_NOMINAL, i_target, attr_voltage_ext_vdd_bias_nominal);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VDD_BIAS_POWERSAVE, i_target, attr_voltage_ext_vdd_bias_powersave);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VCS_BIAS, i_target, attr_voltage_ext_vcs_bias);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VDN_BIAS, i_target, attr_voltage_ext_vdn_bias);

    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_INT_VDD_BIAS_ULTRATURBO, i_target, attr_voltage_int_vdd_bias_ultraturbo);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_INT_VDD_BIAS_TURBO, i_target, attr_voltage_int_vdd_bias_turbo);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_INT_VDD_BIAS_NOMINAL, i_target, attr_voltage_int_vdd_bias_nominal);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_INT_VDD_BIAS_POWERSAVE, i_target, attr_voltage_int_vdd_bias_powersave);

    // Frequency attributes
    DATABLOCK_GET_ATTR(ATTR_FREQ_PROC_REFCLOCK_KHZ, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                       attr_freq_proc_refclock_khz);
    DATABLOCK_GET_ATTR(ATTR_FREQ_PB_MHZ, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                       attr_nest_frequency_mhz);
    DATABLOCK_GET_ATTR(ATTR_FREQ_CORE_CEILING_MHZ, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), attr_freq_core_ceiling_mhz);
    // @todo RTC 169768 Safe mode and use of boot mode
//    DATABLOCK_GET_ATTR(ATTR_PM_SAFE_FREQUENCY_MHZ, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), attr_pm_safe_frequency_mhz);
//    DATABLOCK_GET_ATTR(ATTR_PM_SAFE_VOLTAGE_MV, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), attr_pm_safe_voltage_mv);
    DATABLOCK_GET_ATTR(ATTR_FREQ_CORE_FLOOR_MHZ, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), attr_freq_core_floor_mhz);

    // Loadline, Distribution loss and Distribution offset attributes
    DATABLOCK_GET_ATTR(ATTR_PROC_R_LOADLINE_VDD_UOHM, i_target, attr_proc_r_loadline_vdd_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_DISTLOSS_VDD_UOHM, i_target, attr_proc_r_distloss_vdd_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_VRM_VOFFSET_VDD_UV, i_target, attr_proc_vrm_voffset_vdd_uv);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_LOADLINE_VDN_UOHM, i_target, attr_proc_r_loadline_vdn_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_DISTLOSS_VDN_UOHM, i_target, attr_proc_r_distloss_vdn_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_VRM_VOFFSET_VDN_UV, i_target, attr_proc_vrm_voffset_vdn_uv);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_LOADLINE_VCS_UOHM, i_target, attr_proc_r_loadline_vcs_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_DISTLOSS_VCS_UOHM, i_target, attr_proc_r_distloss_vcs_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_VRM_VOFFSET_VCS_UV, i_target, attr_proc_vrm_voffset_vcs_uv);

    // Read IVRM,WOF and DPLL attributes
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_IVRMS_ENABLED, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), attr_system_ivrms_enabled);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_WOF_ENABLED, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), attr_system_wof_enabled);
    DATABLOCK_GET_ATTR(ATTR_DPLL_DYNAMIC_FMAX_ENABLE, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                       attr_dpll_dynamic_fmax_enable);
    DATABLOCK_GET_ATTR(ATTR_DPLL_DYNAMIC_FMIN_ENABLE, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                       attr_dpll_dynamic_fmin_enable);
    DATABLOCK_GET_ATTR(ATTR_DPLL_DROOP_PROTECT_ENABLE, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                       attr_dpll_droop_protect_enable);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_RESCLK_ENABLE, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                       attr_resclk_enable);

    DATABLOCK_GET_ATTR(ATTR_TDP_RDP_CURRENT_FACTOR, i_target, attr_tdp_rdp_current_factor);

    // @todo RTC 169768   Safe mode and use of boot mode

    // Setting Safe Mode to the core floor frequency as this is the minimum
    // allowed for this system.
    io_attr->attr_pm_safe_frequency_mhz = io_attr->attr_freq_core_floor_mhz;

    // Hardcode for now... @todo RTC 169800
    io_attr->attr_ext_vrm_transition_start_ns = 8000;
    io_attr->attr_ext_vrm_transition_rate_inc_uv_per_us = 10000;  // 10mV/us
    io_attr->attr_ext_vrm_transition_rate_dec_uv_per_us = 10000;  // 10mV/us
    io_attr->attr_ext_vrm_stabilization_time_us = 5;
    io_attr->attr_ext_vrm_step_size_mv = 50;

fapi_try_exit:
    return fapi2::current_err;

}
///  END OF GET ATTRIBUTES function

///  START OF MVPD DATA FUNCTION

fapi2::ReturnCode
proc_get_mvpd_data(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                   uint32_t      o_attr_mvpd_data[PV_D][PV_W],
                   uint32_t*     o_valid_pdv_points,
                   uint8_t*      o_present_chiplets
                  )
{

    std::vector<fapi2::Target<fapi2::TARGET_TYPE_EQ>> l_eqChiplets;
    fapi2::voltageBucketData_t l_poundv_data;
    uint8_t*   l_buffer         =  reinterpret_cast<uint8_t*>(malloc(sizeof(l_poundv_data)) );
    uint8_t*   l_buffer_inc;
    uint32_t   chiplet_mvpd_data[PV_D][PV_W];
    uint8_t    j                = 0;
    uint8_t    i                = 0;
    uint8_t    ii               = 0;
    uint8_t    first_chplt      = 1;
    uint8_t    bucket_id        = 0;

    do
    {
        // initialize
        *o_present_chiplets    = 0;

        // -----------------------------------------------------------------
        // get list of quad chiplets and loop over each and get #V data from each
        // -----------------------------------------------------------------
        // check that frequency is the same per chiplet
        // for voltage, get the max for use for the chip

        l_eqChiplets = i_target.getChildren<fapi2::TARGET_TYPE_EQ>(fapi2::TARGET_STATE_FUNCTIONAL);


        *o_present_chiplets = l_eqChiplets.size();
        FAPI_INF("Number of EQ chiplets present => %u", *o_present_chiplets);

        for (j = 0; j < l_eqChiplets.size(); j++)
        {

            uint8_t l_chipNum = 0xFF;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_eqChiplets[j], l_chipNum));

            FAPI_INF("Chip Number => %u", l_chipNum);

            // clear out buffer to known value before calling fapiGetMvpdField
            memset(l_buffer, 0, sizeof(l_poundv_data));

            FAPI_TRY(p9_pm_get_poundv_bucket(l_eqChiplets[j], l_poundv_data));

            memcpy(l_buffer, &l_poundv_data, sizeof(l_poundv_data));

            // clear array
            memset(chiplet_mvpd_data, 0, sizeof(chiplet_mvpd_data));

            // fill chiplet_mvpd_data 2d array with data iN buffer (skip first byte - bucket id)
#define UINT16_GET(__uint8_ptr)   ((uint16_t)( ( (*((const uint8_t *)(__uint8_ptr)) << 8) | *((const uint8_t *)(__uint8_ptr) + 1) ) ))

            l_buffer_inc = l_buffer;

            bucket_id = *l_buffer_inc;
            l_buffer_inc++;

            FAPI_INF("#V chiplet = %u bucket id = %u", l_chipNum, bucket_id);

            for (i = 0; i <= 4; i++)
            {

                for (ii = 0; ii <= 4; ii++)
                {
                    chiplet_mvpd_data[i][ii] = (uint32_t) UINT16_GET(l_buffer_inc);
                    FAPI_INF("#V data = 0x%04X  %-6d", chiplet_mvpd_data[i][ii],
                             chiplet_mvpd_data[i][ii]);
                    // increment to next MVPD value in buffer
                    l_buffer_inc += 2;
                }
            }

            FAPI_TRY(proc_chk_valid_poundv( i_target,
                                            chiplet_mvpd_data,
                                            o_valid_pdv_points,
                                            l_chipNum,
                                            bucket_id));

            //@todo-L3 - Error handling from check routine
            // if (l_rc == RC_PROCPM_PSTATE_DATABLOCK_PDV_ZERO_DATA_UT_ERROR)
            // {
            //     // Disable WOF
            //     i_attr->attr_system_wof_enabled = 0;
            // }
            // else if (l_rc)
            // {
            //     break;
            // }

            // on first chiplet put each bucket's data into attr_mvpd_voltage_control
            if (first_chplt)
            {
                for (i = 0; i <= 4; i++)
                {
                    for (ii = 0; ii <= 4; ii++)
                    {
                        o_attr_mvpd_data[i][ii] = chiplet_mvpd_data[i][ii];
                    }
                }

                first_chplt = 0;
            }
            else
            {
                // on subsequent chiplets, check that frequencies are same for each operating point for each chiplet
                if ( (o_attr_mvpd_data[0][0] != chiplet_mvpd_data[0][0]) ||
                     (o_attr_mvpd_data[1][0] != chiplet_mvpd_data[1][0]) ||
                     (o_attr_mvpd_data[2][0] != chiplet_mvpd_data[2][0]) ||
                     (o_attr_mvpd_data[3][0] != chiplet_mvpd_data[3][0]) ||
                     (o_attr_mvpd_data[4][0] != chiplet_mvpd_data[4][0]) )
                {
                    //@todo-L3
                    //const uint32_t &ATTR_MVPD_DATA_0 = o_attr_mvpd_data[0][0];
                    //const uint32_t &ATTR_MVPD_DATA_1 = o_attr_mvpd_data[1][0];
                    //const uint32_t &ATTR_MVPD_DATA_2 = o_attr_mvpd_data[2][0];
                    //const uint32_t &ATTR_MVPD_DATA_3 = o_attr_mvpd_data[3][0];
                    //const uint32_t &ATTR_MVPD_DATA_4 = o_attr_mvpd_data[4][0];
                    FAPI_ERR("**** ERROR : frequencies are not the same for each operating point for each chiplet");
                    //const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& CHIP_TARGET= i_target;
                    //FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_MVPD_CHIPLET_VOLTAGE_NOT_EQUAL);
                    break;
                }
            }

            // check each bucket for max voltage and if max, put bucket's data into attr_mvpd_voltage_control
            for (i = 0; i <= 4; i++)
            {
                if (o_attr_mvpd_data[i][1] < chiplet_mvpd_data[i][1])
                {
                    o_attr_mvpd_data[i][0] = chiplet_mvpd_data[i][0];
                    o_attr_mvpd_data[i][1] = chiplet_mvpd_data[i][1];
                    o_attr_mvpd_data[i][2] = chiplet_mvpd_data[i][2];
                    o_attr_mvpd_data[i][3] = chiplet_mvpd_data[i][3];
                    o_attr_mvpd_data[i][4] = chiplet_mvpd_data[i][4];
                }
            }
        } // end for loop
    }
    while(0);

    free (l_buffer);

fapi_try_exit:
    return fapi2::current_err;

} // end proc_get_mvpd_data
///  END OF MVPD DATA FUNCTION

///  START OF IDDQ READ FUNCTION

fapi2::ReturnCode
proc_get_mvpd_iddq( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                    IddqTable* io_iddqt)
{

    uint8_t*        l_buffer_iq_c =  reinterpret_cast<uint8_t*>(malloc(IQ_BUFFER_ALLOC));
    uint32_t        l_record = 0;
    uint8_t*        l_buffer_iq_inc;
    uint32_t        l_bufferSize_iq  = IQ_BUFFER_ALLOC;
    uint8_t         i, j;
    uint8_t         l_buffer_data;
    iddq_entry_t    l_iddq_data;
    avgtemp_entry_t l_avgtemp_data;
    const char*     idd_meas_str[IDDQ_MEASUREMENTS] = IDDQ_ARRAY_VOLTAGES_STR;
    char            l_buffer_str[128];   // Temporary formatting string buffer
    char            l_line_str[128];     // Formatted output line string

// --------------------------------------------
// Process IQ Keyword (IDDQ) Data
// --------------------------------------------

    do
    {
        // clear out buffer to known value before calling fapiGetMvpdField
        memset(l_buffer_iq_c, 0, IQ_BUFFER_ALLOC);

        // set l_record to appropriate cprx record
        l_record = (uint32_t)fapi2::MVPD_RECORD_CRP0;
        l_bufferSize_iq = IQ_BUFFER_ALLOC;

        FAPI_DBG("getMvpdField(record %X, keyword %X, iq %p, size %d)", l_record,
                 (uint32_t)fapi2::MVPD_KEYWORD_IQ,
                 l_buffer_iq_c,
                 l_bufferSize_iq);

        // Get Chip IQ MVPD data from the CRPx records
        FAPI_TRY(getMvpdField((fapi2::MvpdRecord)l_record,
                              fapi2::MVPD_KEYWORD_IQ,
                              i_target,
                              l_buffer_iq_c,
                              l_bufferSize_iq));

        // check buffer size, ssrivath, @TODO L3
        if (l_bufferSize_iq < IQ_BUFFER_SIZE)
        {
            FAPI_ERR("**** ERROR : Wrong size buffer returned from getMvpdField for IQ => %d", l_bufferSize_iq );
            //const uint32_t& BUFFER_SIZE = l_bufferSize_iq;
            //const Target&  CHIP_TARGET = i_target;
            //FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_IQ_BUFFER_SIZE_ERROR);
            break;
        }

        // use copy of allocated buffer pointer to increment through buffer
        l_buffer_iq_inc = l_buffer_iq_c;

        // get IQ version and advance pointer 1-byte
        uint8_t l_iddq_version = *l_buffer_iq_inc;
        io_iddqt->iddq_version = l_iddq_version ;
        FAPI_INF("  IDDQ Version Number = %u", l_iddq_version);
        l_buffer_iq_inc++;

        // get number of good quads per sort
        uint8_t l_good_quads_per_sort = *l_buffer_iq_inc;
        io_iddqt->good_quads_per_sort = l_good_quads_per_sort ;
        l_buffer_iq_inc++;

        // get number of normal cores per sort
        uint8_t l_good_normal_cores_per_sort = *l_buffer_iq_inc;
        io_iddqt->good_normal_cores_per_sort = l_good_normal_cores_per_sort ;
        l_buffer_iq_inc++;

        // get number of good caches per sort
        uint8_t l_good_caches_per_sort = *l_buffer_iq_inc;
        io_iddqt->good_caches_per_sort = l_good_caches_per_sort ;
        l_buffer_iq_inc++;
        FAPI_INF("  Sort Info:         Good Quads = %02d Good Caches = %02d Good Cores = %02d",
                 l_good_quads_per_sort,
                 l_good_caches_per_sort,
                 l_good_normal_cores_per_sort);

        // get number of good normal cores in each quad
        strcpy(l_line_str, "  Good normal cores:");
        strcpy(l_buffer_str, "");

        for (i = 0; i < MAXIMUM_QUADS; i++)
        {
            l_buffer_data = *l_buffer_iq_inc;
            io_iddqt->good_normal_cores[i] = l_buffer_data;
            sprintf(l_buffer_str, " Quad %d = %u ", i, l_buffer_data);
            strcat(l_line_str, l_buffer_str);
            l_buffer_iq_inc++;
        }

        FAPI_INF("%s", l_line_str);


        // get number of good caches in each quad
        strcpy(l_line_str, "  Good caches:      ");
        strcpy(l_buffer_str, "");

        for (i = 0; i < MAXIMUM_QUADS; i++)
        {
            l_buffer_data = *l_buffer_iq_inc;
            io_iddqt->good_caches[i] = l_buffer_data;
            sprintf(l_buffer_str, " Quad %d = %u ", i, l_buffer_data);
            strcat(l_line_str, l_buffer_str);
            l_buffer_iq_inc++;
        }

        FAPI_INF("%s", l_line_str);

        // get RDP TO TDP scalling factor
        uint16_t l_rdp_to_tdp_scale_factor = *(reinterpret_cast<uint16_t*>(l_buffer_iq_inc));
        io_iddqt->rdp_to_tdp_scale_factor = revle16(l_rdp_to_tdp_scale_factor);
        FAPI_INF("  RDP TO TDP scalling factor = %u", l_rdp_to_tdp_scale_factor );
        l_buffer_iq_inc += 2;

        // get WOF IDDQ margin factor
        uint16_t l_wof_iddq_margin_factor = *(reinterpret_cast<uint16_t*>(l_buffer_iq_inc));
        io_iddqt->wof_iddq_margin_factor = revle16(l_wof_iddq_margin_factor);
        FAPI_INF("  WOF IDDQ margin factor     = %u", l_wof_iddq_margin_factor);
        l_buffer_iq_inc += 2;

        // get Temperature scaling factor
        uint16_t l_temperature_scale_factor = *(reinterpret_cast<uint16_t*>(l_buffer_iq_inc));
        io_iddqt->temperature_scale_factor = revle16(l_temperature_scale_factor);
        FAPI_INF("  Temperature scaling factor = %u", l_temperature_scale_factor);
        l_buffer_iq_inc += 2;

        // get spare data - 10B
        for (i = 0; i < 9; i++)
        {
            l_buffer_data = *l_buffer_iq_inc;
            io_iddqt->spare[i] = l_buffer_data;
            l_buffer_iq_inc++;
        }

        // Put out the measurement voltages to the trace.
        strcpy(l_line_str, "  Measurment voltages:                           ");
        strcpy(l_buffer_str, "");

        for (i = 0; i < IDDQ_MEASUREMENTS; i++)
        {
            sprintf(l_buffer_str, "  %sV", idd_meas_str[i]);
            strcat(l_line_str, l_buffer_str);
        }

        FAPI_INF("%s", l_line_str);

        // get IVDDQ measurements with all good cores ON
        strcpy(l_line_str, "  IDDQ all good cores ON:                        ");
        strcpy(l_buffer_str, "");

        for (i = 0; i < IDDQ_MEASUREMENTS; i++)
        {
            l_iddq_data = *(reinterpret_cast<iddq_entry_t*>(l_buffer_iq_inc));
            io_iddqt->ivdd_all_good_cores_on_caches_on[i] = revle16(l_iddq_data);
            l_buffer_iq_inc += sizeof(iddq_entry_t);
            sprintf(l_buffer_str, "  %04u ", revle16(l_iddq_data));
            strcat(l_line_str, l_buffer_str);
        }

        FAPI_INF("%s", l_line_str);

        // get IVDDQ measurements with all cores and caches OFF
        strcpy(l_line_str, "  IVDDQ all cores and caches OFF:                ");
        strcpy(l_buffer_str, "");

        for (i = 0; i < IDDQ_MEASUREMENTS; i++)
        {
            l_iddq_data = *(reinterpret_cast<iddq_entry_t*>(l_buffer_iq_inc));
            io_iddqt->ivdd_all_cores_off_caches_off[i] = revle16(l_iddq_data);
            l_buffer_iq_inc += sizeof(iddq_entry_t);
            sprintf(l_buffer_str, "  %04u ", revle16(l_iddq_data));
            strcat(l_line_str, l_buffer_str);
        }

        FAPI_INF("%s", l_line_str);;

        // get IVDDQ measurements with all good cores OFF and caches ON
        strcpy(l_line_str, "  IVDDQ all good cores OFF and caches ON:        ");
        strcpy(l_buffer_str, "");

        for (i = 0; i < IDDQ_MEASUREMENTS; i++)
        {
            l_iddq_data = *(reinterpret_cast<iddq_entry_t*>(l_buffer_iq_inc));
            io_iddqt->ivdd_all_good_cores_off_good_caches_on[i] = revle16(l_iddq_data);
            l_buffer_iq_inc += sizeof(iddq_entry_t);
            sprintf(l_buffer_str, "  %04u ", revle16(l_iddq_data));
            strcat(l_line_str, l_buffer_str);
        }

        FAPI_INF("%s", l_line_str);

        // get IVDDQ measurements with all good cores in each quad
        for (i = 0; i < MAXIMUM_QUADS; i++)
        {
            strcpy(l_line_str, "  IVDDQ all good cores OFF and caches ON: ");
            strcpy(l_buffer_str, "");
            sprintf(l_buffer_str, "Quad %d:", i);
            strcat(l_line_str, l_buffer_str);

            for (j = 0; j < IDDQ_MEASUREMENTS; j++)
            {
                l_iddq_data = *(reinterpret_cast<iddq_entry_t*>(l_buffer_iq_inc));
                io_iddqt->ivdd_quad_good_cores_on_good_caches_on[i][j] = revle16(l_iddq_data);
                l_buffer_iq_inc += sizeof(iddq_entry_t);
                sprintf(l_buffer_str, "  %04u ", revle16(l_iddq_data));
                strcat(l_line_str, l_buffer_str);
            }

            FAPI_INF("%s", l_line_str);
        }

        // get IVDN data
        strcpy(l_line_str, "  IVDN                                           ");
        strcpy(l_buffer_str, "");

        for (i = 0; i < IDDQ_MEASUREMENTS; i++)
        {
            l_iddq_data = *(reinterpret_cast<iddq_entry_t*>(l_buffer_iq_inc));
            io_iddqt->ivdn[i] = revle16(l_iddq_data);
            l_buffer_iq_inc += sizeof(iddq_entry_t);
            sprintf(l_buffer_str, "  %04u ", revle16(l_iddq_data));
            strcat(l_line_str, l_buffer_str);
        }

        FAPI_INF("%s", l_line_str);



        // get average temperature measurements with all good cores ON
        strcpy(l_line_str, "  Measurment voltages:                           ");
        strcpy(l_line_str, "  Average temp all good cores ON:                ");
        strcpy(l_buffer_str, "");

        for (i = 0; i < IDDQ_MEASUREMENTS; i++)
        {
            l_avgtemp_data = *(reinterpret_cast<avgtemp_entry_t*>(l_buffer_iq_inc));
            io_iddqt->avgtemp_all_good_cores_on[i] = l_avgtemp_data;
            sprintf(l_buffer_str, "   %02u  ", l_avgtemp_data);
            strcat(l_line_str, l_buffer_str);
            l_buffer_iq_inc += sizeof(l_avgtemp_data);
        }

        FAPI_INF("%s", l_line_str);

        // get average temperature measurements with all cores and caches OFF
        strcpy(l_line_str, "  Average temp all cores OFF, caches OFF:        ");
        strcpy(l_buffer_str, "");

        for (i = 0; i < IDDQ_MEASUREMENTS; i++)
        {
            l_avgtemp_data = *(reinterpret_cast<avgtemp_entry_t*>(l_buffer_iq_inc));
            io_iddqt->avgtemp_all_cores_off_caches_off[i] = l_avgtemp_data;
            l_buffer_iq_inc += sizeof(l_avgtemp_data);
            sprintf(l_buffer_str, "   %02u  ", l_avgtemp_data);
            strcat(l_line_str, l_buffer_str);
        }

        FAPI_INF("%s", l_line_str);

        // get average temperature measurements with all good cores OFF and caches ON
        strcpy(l_line_str, "  Average temp all good cores OFF, caches ON:    ");
        strcpy(l_buffer_str, "");

        for (i = 0; i < IDDQ_MEASUREMENTS; i++)
        {
            l_avgtemp_data = *(reinterpret_cast<avgtemp_entry_t*>(l_buffer_iq_inc));
            io_iddqt->avgtemp_all_good_cores_off[i] = l_avgtemp_data;
            l_buffer_iq_inc += sizeof(l_avgtemp_data);
            sprintf(l_buffer_str, "   %02u  ", l_avgtemp_data);
            strcat(l_line_str, l_buffer_str);
        }

        FAPI_INF("%s", l_line_str);

        // get average temperature measurements with all good cores in each quad
        for (i = 0; i < MAXIMUM_QUADS; i++)
        {
            strcpy(l_line_str, "  Average temp all good cores ON: ");
            strcpy(l_buffer_str, "");
            sprintf(l_buffer_str, "Quad %d:        ", i);
            strcat(l_line_str, l_buffer_str);

            for (j = 0; j < IDDQ_MEASUREMENTS; j++)
            {
                l_avgtemp_data = *(reinterpret_cast<avgtemp_entry_t*>(l_buffer_iq_inc));
                io_iddqt->avgtemp_quad_good_cores_on[i][j] = l_avgtemp_data;
                l_buffer_iq_inc += sizeof(l_avgtemp_data);
                sprintf(l_buffer_str, "   %02u  ", l_avgtemp_data);
                strcat(l_line_str, l_buffer_str);
            }

            FAPI_INF("%s", l_line_str);
        }

        // get average nest temperature nest
        strcpy(l_line_str, "  Average temp Nest:                             ");
        strcpy(l_buffer_str, "");

        for (i = 0; i < IDDQ_MEASUREMENTS; i++)
        {
            l_avgtemp_data = *(reinterpret_cast<avgtemp_entry_t*>(l_buffer_iq_inc));
            io_iddqt->avgtemp_vdn = revle16(l_avgtemp_data);
            l_buffer_iq_inc += sizeof(l_avgtemp_data);
            sprintf(l_buffer_str, "   %02u  ", l_avgtemp_data);
            strcat(l_line_str, l_buffer_str);
        }

        FAPI_INF("%s", l_line_str);

    }
    while(0);

    // Free up memory buffer
    free(l_buffer_iq_c);

fapi_try_exit:
    return fapi2::current_err;
} // proc_get_mvdp_iddq

/// END OF IDDQ READ FUNCTION

/// START OF BIAS APPLICATION FUNCTION

fapi2::ReturnCode
proc_get_extint_bias( uint32_t io_attr_mvpd_data[PV_D][PV_W],
                      const AttributeList* i_attr,
                      VpdBias o_vpdbias[VPD_PV_POINTS]
                    )
{

    //int    i                 = 0;
    //double freq_bias         = 1.0;
    //double volt_ext_vdd_bias = 1.0;
    //double volt_ext_vcs_bias = 1.0;

    double freq_bias_ultraturbo;
    double freq_bias_turbo;
    double freq_bias_nominal;
    double freq_bias_powersave;

    double voltage_ext_vdd_bias_ultraturbo;
    double voltage_ext_vdd_bias_turbo;
    double voltage_ext_vdd_bias_nominal;
    double voltage_ext_vdd_bias_powersave;

    //double voltage_int_vdd_bias_ultraturbo;
    //double voltage_int_vdd_bias_turbo;
    //double voltage_int_vdd_bias_nominal;
    //double voltage_int_vdd_bias_powersave;

    double voltage_ext_vcs_bias;
    double voltage_ext_vdn_bias;

    freq_bias_ultraturbo = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_freq_bias_ultraturbo);
    freq_bias_turbo = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_freq_bias_turbo);
    freq_bias_nominal = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_freq_bias_nominal);
    freq_bias_powersave = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_freq_bias_powersave);

    voltage_ext_vdd_bias_ultraturbo = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_voltage_ext_vdd_bias_ultraturbo);
    voltage_ext_vdd_bias_turbo = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_voltage_ext_vdd_bias_turbo);
    voltage_ext_vdd_bias_nominal = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_voltage_ext_vdd_bias_nominal);
    voltage_ext_vdd_bias_powersave = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_voltage_ext_vdd_bias_powersave);

    // @todo RTC 161279 - Where should we apply int_vdd bias ?, Read in attributes for all VPD points. REVIEW with Greg
    //voltage_int_vdd_bias_ultraturbo = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_voltage_int_vdd_bias_ultraturbo);
    //voltage_int_vdd_bias_turbo = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_voltage_int_vdd_bias_turbo);
    //voltage_int_vdd_bias_nominal = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_voltage_int_vdd_bias_nominal);
    //voltage_int_vdd_bias_powersave = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_voltage_int_vdd_bias_powersave);

    // @todo RTC 161279 - Should VCS bias be applied to all operating points ? Currently applied to all. REVIEW with Greg
    voltage_ext_vcs_bias = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_voltage_ext_vcs_bias);

    // @todo RTC 161279 - VDN bias corresponds to Power Bus operating point ? Currently applied to power bus point. REVIEW with Greg
    voltage_ext_vdn_bias = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_voltage_ext_vdn_bias);


    // Nominal frequency operating point
    io_attr_mvpd_data[NOMINAL][0] = (uint32_t) ((( (double)io_attr_mvpd_data[NOMINAL][0]) * freq_bias_nominal));
    io_attr_mvpd_data[NOMINAL][1] = (uint32_t) ((( (double)io_attr_mvpd_data[NOMINAL][1]) * voltage_ext_vdd_bias_nominal));
    io_attr_mvpd_data[NOMINAL][3] = (uint32_t) ((( (double)io_attr_mvpd_data[NOMINAL][3]) * voltage_ext_vcs_bias));

    // Power Save frequency operating point
    io_attr_mvpd_data[POWERSAVE][0] = (uint32_t) ((( (double)io_attr_mvpd_data[POWERSAVE][0]) * freq_bias_powersave));
    io_attr_mvpd_data[POWERSAVE][1] = (uint32_t) ((( (double)io_attr_mvpd_data[POWERSAVE][1]) *
                                      voltage_ext_vdd_bias_powersave));
    io_attr_mvpd_data[POWERSAVE][3] = (uint32_t) ((( (double)io_attr_mvpd_data[POWERSAVE][3]) * voltage_ext_vcs_bias));

    // Turbo frequency operating point
    io_attr_mvpd_data[TURBO][0] = (uint32_t) ((( (double)io_attr_mvpd_data[TURBO][0]) * freq_bias_turbo));
    io_attr_mvpd_data[TURBO][1] = (uint32_t) ((( (double)io_attr_mvpd_data[TURBO][1]) * voltage_ext_vdd_bias_turbo));
    io_attr_mvpd_data[TURBO][3] = (uint32_t) ((( (double)io_attr_mvpd_data[TURBO][3]) * voltage_ext_vcs_bias));

    // Ultraturbo frequency operating point
    io_attr_mvpd_data[ULTRA][0] = (uint32_t) ((( (double)io_attr_mvpd_data[ULTRA][0]) * freq_bias_ultraturbo));
    io_attr_mvpd_data[ULTRA][1] = (uint32_t) ((( (double)io_attr_mvpd_data[ULTRA][1]) * voltage_ext_vdd_bias_ultraturbo));
    io_attr_mvpd_data[ULTRA][3] = (uint32_t) ((( (double)io_attr_mvpd_data[ULTRA][3]) * voltage_ext_vcs_bias));

    // Power bus operating point
    io_attr_mvpd_data[4][1] = (uint32_t) ((( (double)io_attr_mvpd_data[4][1]) * voltage_ext_vdn_bias));

    //VPD Biases per operating point
    // Nominal
    o_vpdbias[NOMINAL].vdd_ext_hp = i_attr->attr_voltage_ext_vdd_bias_nominal;
    o_vpdbias[NOMINAL].vdd_int_hp = i_attr->attr_voltage_int_vdd_bias_nominal;
    o_vpdbias[NOMINAL].vdn_ext_hp = i_attr->attr_voltage_ext_vdn_bias;
    o_vpdbias[NOMINAL].vcs_ext_hp = i_attr->attr_voltage_ext_vcs_bias;
    o_vpdbias[NOMINAL].frequency_hp = i_attr->attr_freq_bias_nominal;

    // PowerSave
    o_vpdbias[POWERSAVE].vdd_ext_hp = i_attr->attr_voltage_ext_vdd_bias_powersave;
    o_vpdbias[POWERSAVE].vdd_int_hp = i_attr->attr_voltage_int_vdd_bias_powersave;
    o_vpdbias[POWERSAVE].vdn_ext_hp = i_attr->attr_voltage_ext_vdn_bias;
    o_vpdbias[POWERSAVE].vcs_ext_hp = i_attr->attr_voltage_ext_vcs_bias;
    o_vpdbias[POWERSAVE].frequency_hp = i_attr->attr_freq_bias_powersave;

    // Turbo
    o_vpdbias[TURBO].vdd_ext_hp = i_attr->attr_voltage_ext_vdd_bias_turbo;
    o_vpdbias[TURBO].vdd_int_hp = i_attr->attr_voltage_int_vdd_bias_turbo;
    o_vpdbias[TURBO].vdn_ext_hp = i_attr->attr_voltage_ext_vdn_bias;
    o_vpdbias[TURBO].vcs_ext_hp = i_attr->attr_voltage_ext_vcs_bias;
    o_vpdbias[TURBO].frequency_hp = i_attr->attr_freq_bias_turbo;

    // UltraTurbo
    o_vpdbias[ULTRA].vdd_ext_hp = i_attr->attr_voltage_ext_vdd_bias_ultraturbo;
    o_vpdbias[ULTRA].vdd_int_hp = i_attr->attr_voltage_int_vdd_bias_ultraturbo;
    o_vpdbias[ULTRA].vdn_ext_hp = i_attr->attr_voltage_ext_vdn_bias;
    o_vpdbias[ULTRA].vcs_ext_hp = i_attr->attr_voltage_ext_vcs_bias;
    o_vpdbias[ULTRA].frequency_hp = i_attr->attr_freq_bias_ultraturbo;

    return fapi2::FAPI2_RC_SUCCESS;

} // end proc_get_extint_bias

/// ssrivath END OF BIAS APPLICATION FUNCTION


fapi2::ReturnCode
proc_chk_valid_poundv(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                      const uint32_t i_chiplet_mvpd_data[PV_D][PV_W],
                      uint32_t*      o_valid_pdv_points,
                      const uint8_t  i_chiplet_num,
                      const uint8_t  i_bucket_id)
{

    const uint8_t pv_op_order[VPD_PV_POINTS] = VPD_PV_ORDER;
    const char*    pv_op_str[VPD_PV_POINTS] = VPD_PV_ORDER_STR;
    uint8_t       i = 0;
    bool          suspend_ut_check = false;
    uint8_t  l_attr_system_wof_enabled;

    do
    {

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_WOF_ENABLED, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_attr_system_wof_enabled));

        // check for non-zero freq, voltage, or current in valid operating points
        for (i = 0; i <= VPD_PV_POINTS - 1; i++)
        {
            FAPI_INF("Checking for Zero valued data in each #V operating point (%s) f=%u v=%u i=%u v=%u i=%u",
                     pv_op_str[pv_op_order[i]],
                     i_chiplet_mvpd_data[pv_op_order[i]][0],
                     i_chiplet_mvpd_data[pv_op_order[i]][1],
                     i_chiplet_mvpd_data[pv_op_order[i]][2],
                     i_chiplet_mvpd_data[pv_op_order[i]][3],
                     i_chiplet_mvpd_data[pv_op_order[i]][4]);

            if (l_attr_system_wof_enabled && (strcmp(pv_op_str[pv_op_order[i]], "UltraTurbo") == 0))
            {

                if (i_chiplet_mvpd_data[pv_op_order[i]][0] == 0 ||
                    i_chiplet_mvpd_data[pv_op_order[i]][1] == 0 ||
                    i_chiplet_mvpd_data[pv_op_order[i]][2] == 0 ||
                    i_chiplet_mvpd_data[pv_op_order[i]][3] == 0 ||
                    i_chiplet_mvpd_data[pv_op_order[i]][4] == 0   )
                {

                    FAPI_INF("**** WARNING: WOF is enabled but zero valued data found in #V (chiplet = %u  bucket id = %u  op point = %s)",
                             i_chiplet_num, i_bucket_id, pv_op_str[pv_op_order[i]]);
                    FAPI_INF("**** WARNING: Disabling WOF and continuing");
                    //@todo-L3
                    //const uint8_t& OP_POINT    = pv_op_order[i];
                    //const uint8_t& CHIPLET_NUM = i_chiplet_num;
                    //const uint8_t& BUCKET_ID   = i_bucket_id;
                    //const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& CHIP_TARGET= i_target;
                    //FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_PDV_ZERO_DATA_UT_ERROR);
                    suspend_ut_check = true;
                }
            }
            else if ((!l_attr_system_wof_enabled) && (strcmp(pv_op_str[pv_op_order[i]], "UltraTurbo") == 0))
            {
                FAPI_INF("**** NOTE: WOF is disabled so the UltraTurbo VPD is not being checked");
                suspend_ut_check = true;
            }
            else
            {

                if (i_chiplet_mvpd_data[pv_op_order[i]][0] == 0 ||
                    i_chiplet_mvpd_data[pv_op_order[i]][1] == 0 ||
                    i_chiplet_mvpd_data[pv_op_order[i]][2] == 0 ||
                    i_chiplet_mvpd_data[pv_op_order[i]][3] == 0 ||
                    i_chiplet_mvpd_data[pv_op_order[i]][4] == 0   )
                {

                    FAPI_ERR("**** ERROR : Zero valued data found in #V (chiplet = %u  bucket id = %u  op point = %s)",
                             i_chiplet_num, i_bucket_id, pv_op_str[pv_op_order[i]]);
                    //@todo-L3
                    //const uint8_t& OP_POINT    = pv_op_order[i];
                    //const uint8_t& CHIPLET_NUM = i_chiplet_num;
                    //const uint8_t& BUCKET_ID   = i_bucket_id;
                    //const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& CHIP_TARGET= i_target;
                    //FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_PDV_ZERO_DATA_ERROR);
                    break;
                }
            }
        }

        //@todo - L3
        // if (l_rc)
        // {
        //     // If an error was found where suspension was flagged, keep going.
        //     // If not, break to exit point.
        //     if (!suspend_ut_check)
        //         break;
        // }


        // Adjust the valid operating point based on UltraTurbo presence
        // and WOF enablement
        *o_valid_pdv_points = VPD_PV_POINTS;

        if (suspend_ut_check)
        {
            (*o_valid_pdv_points)--;
        }

        FAPI_DBG("o_valid_pdv_points = %d", *o_valid_pdv_points);

        // check valid operating points' values have this relationship (power save <= nominal <= turbo <= ultraturbo)
        for (i = 1; i <= (*o_valid_pdv_points) - 1; i++)
        {

            FAPI_INF("Checking for relationship between #V operating point (%s <= %s)",
                     pv_op_str[pv_op_order[i - 1]], pv_op_str[pv_op_order[i]]);
            FAPI_INF("   f=%u <= f=%u",               i_chiplet_mvpd_data[pv_op_order[i - 1]][0],
                     i_chiplet_mvpd_data[pv_op_order[i]][0]);
            FAPI_INF("   v=%u <= v=%u  i=%u <= i=%u", i_chiplet_mvpd_data[pv_op_order[i - 1]][1],
                     i_chiplet_mvpd_data[pv_op_order[i]][1], i_chiplet_mvpd_data[pv_op_order[i - 1]][2],
                     i_chiplet_mvpd_data[pv_op_order[i]][2]);
            FAPI_INF("   v=%u <= v=%u  i=%u <= i=%u", i_chiplet_mvpd_data[pv_op_order[i - 1]][3],
                     i_chiplet_mvpd_data[pv_op_order[i]][3], i_chiplet_mvpd_data[pv_op_order[i - 1]][4],
                     i_chiplet_mvpd_data[pv_op_order[i]][4]);

            if (l_attr_system_wof_enabled && strcmp(pv_op_str[pv_op_order[i]], "UltraTurbo") && !suspend_ut_check )
            {
                if (i_chiplet_mvpd_data[pv_op_order[i - 1]][0] > i_chiplet_mvpd_data[pv_op_order[i]][0]  ||
                    i_chiplet_mvpd_data[pv_op_order[i - 1]][1] > i_chiplet_mvpd_data[pv_op_order[i]][1]  ||
                    i_chiplet_mvpd_data[pv_op_order[i - 1]][2] > i_chiplet_mvpd_data[pv_op_order[i]][2]  ||
                    i_chiplet_mvpd_data[pv_op_order[i - 1]][3] > i_chiplet_mvpd_data[pv_op_order[i]][3]  ||
                    i_chiplet_mvpd_data[pv_op_order[i - 1]][4] > i_chiplet_mvpd_data[pv_op_order[i]][4]    )
                {

                    FAPI_ERR("**** ERROR : Relationship error between #V operating point (%s <= %s)(power save <= nominal <= turbo <= ultraturbo) (chiplet = %u  bucket id = %u  op point = %u)",
                             pv_op_str[pv_op_order[i - 1]], pv_op_str[pv_op_order[i]], i_chiplet_num, i_bucket_id,
                             pv_op_order[i]);
                    //@todo-L3
                    //const uint8_t& OP_POINT    = pv_op_order[i];
                    //const uint8_t& CHIPLET_NUM = i_chiplet_num;
                    //const uint8_t& BUCKET_ID   = i_bucket_id;
                    //const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& CHIP_TARGET= i_target;
                    //FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_PDV_OPPOINT_ORDER_ERROR);
                    break;
                }
            }
        }

    }
    while(0);

fapi_try_exit:
    return fapi2::current_err;
}

/// ------------------------------------------------------------
/// \brief Copy VPD operating point into destination in assending order
/// \param[in]  &src[VPD_PV_POINTS]   => reference to source VPD structure (array)
/// \param[out] *dest[VPD_PV_POINTS]  => pointer to destination VpdOperatingPoint structure
//  \param[in]  i_frequency_step_khz  => Base frequency value for pstate calculation
/// ------------------------------------------------------------
/// \note:  this routine reads the keyword information in "VPD order" (eg Nominal,
///         PowerSave, Turbo, UltraTurbo) into the data structures in "Natural Order"
///         (eg (eg PowerSave, Nominal, Turbo, UltraTurbo)
///
fapi2::ReturnCode
load_mvpd_operating_point ( const uint32_t i_src[PV_D][PV_W],
                            VpdOperatingPoint* o_dest,
                            uint32_t i_frequency_step_khz)
{
    FAPI_INF(">> load_mvpd_operating_point");
    const uint8_t pv_op_order[VPD_PV_POINTS] = VPD_PV_ORDER;

    for (uint32_t i = 0; i < VPD_PV_POINTS; i++)
    {
        o_dest[i].frequency_mhz  = revle32(i_src[pv_op_order[i]][0]);
        o_dest[i].vdd_mv        = revle32(i_src[pv_op_order[i]][1]);
        o_dest[i].idd_100ma      = revle32(i_src[pv_op_order[i]][2]);
        o_dest[i].vcs_mv        = revle32(i_src[pv_op_order[i]][3]);
        o_dest[i].ics_100ma      = revle32(i_src[pv_op_order[i]][4]);
        o_dest[i].pstate = (i_src[ULTRA][0] - i_src[pv_op_order[i]][0]) * 1000 / i_frequency_step_khz;
    }

    FAPI_INF("<< load_mvpd_operating_point");
    return fapi2::FAPI2_RC_SUCCESS;
} // end load_mvpd_operating_point


fapi2::ReturnCode
proc_get_vdm_parms ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                     VDMParmBlock* o_vdmpb)
{
    uint8_t l_droop_small_override[VPD_PV_POINTS + 1];
    uint8_t l_droop_large_override[VPD_PV_POINTS + 1];
    uint8_t l_droop_extreme_override[VPD_PV_POINTS + 1];
    uint8_t l_overvolt_override[VPD_PV_POINTS + 1];
    uint16_t l_fmin_override_khz[VPD_PV_POINTS + 1];
    uint16_t l_fmax_override_khz[VPD_PV_POINTS + 1];
    uint8_t l_vid_compare_override_mv[VPD_PV_POINTS + 1];
    uint8_t l_vdm_response;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDM_DROOP_SMALL_OVERRIDE, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_droop_small_override));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDM_DROOP_LARGE_OVERRIDE, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_droop_large_override));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDM_DROOP_EXTREME_OVERRIDE, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_droop_extreme_override));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDM_OVERVOLT_OVERRIDE, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_overvolt_override));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDM_FMIN_OVERRIDE_KHZ, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_fmin_override_khz));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDM_FMAX_OVERRIDE_KHZ, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_fmax_override_khz));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDM_VID_COMPARE_OVERRIDE_MV, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_vid_compare_override_mv));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_DPLL_VDM_RESPONSE, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_vdm_response));

    o_vdmpb->droop_small_override_enable = l_droop_small_override[VPD_PV_POINTS];
    o_vdmpb->droop_large_override_enable = l_droop_large_override[VPD_PV_POINTS];
    o_vdmpb->droop_extreme_override_enable = l_droop_extreme_override[VPD_PV_POINTS];
    o_vdmpb->overvolt_override_enable = l_overvolt_override[VPD_PV_POINTS];
    o_vdmpb->fmin_override_khz_enable = l_fmin_override_khz[VPD_PV_POINTS];
    o_vdmpb->fmax_override_khz_enable = l_fmax_override_khz[VPD_PV_POINTS];
    o_vdmpb->vid_compare_override_mv_enable = l_vid_compare_override_mv[VPD_PV_POINTS];

    o_vdmpb->vdm_response = l_vdm_response;

    for (uint8_t i = 0; i < VPD_PV_POINTS; i++)
    {
        o_vdmpb->droop_small_override[i] = l_droop_small_override[i];
        o_vdmpb->droop_large_override[i] = l_droop_large_override[i];
        o_vdmpb->droop_extreme_override[i] = l_droop_extreme_override[i];
        o_vdmpb->overvolt_override[i] = l_overvolt_override[i];
        o_vdmpb->fmin_override_khz[i] = l_fmin_override_khz[i];
        o_vdmpb->fmax_override_khz[i] = l_fmax_override_khz[i];
        o_vdmpb->vid_compare_override_mv[i] = l_vid_compare_override_mv[i];
    }

fapi_try_exit:
    return fapi2::current_err;

}

fapi2::ReturnCode
proc_res_clock_setup ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                       ResonantClockingSetup* o_resclk_setup)
{
    FAPI_INF(">> proc_res_clock_setup");
    uint16_t l_steparray[RESCLK_STEPS];

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_STEP_DELAY, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           o_resclk_setup->step_delay_ns));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_FREQ_REGIONS, i_target,
                           o_resclk_setup->resclk_freq));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_FREQ_REGION_INDEX, i_target,
                           o_resclk_setup->resclk_index));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_L3_VALUE, i_target,
                           o_resclk_setup->l3_steparray));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_L3_VOLTAGE_THRESHOLD_MV, i_target,
                           o_resclk_setup->l3_threshold_mv));

    // Resonant Clocking Step array
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_VALUE, i_target,
                           l_steparray));

    for (uint8_t i = 0; i < RESCLK_STEPS; i++)
    {
        o_resclk_setup->steparray[i].value = l_steparray[i];
    }

fapi_try_exit:
    FAPI_INF("<< proc_res_clock_setup");
    return fapi2::current_err;
}

fapi2::ReturnCode
proc_get_ivrm_parms ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                      IvrmParmBlock* o_ivrmpb)
{
    FAPI_INF(">> proc_get_ivrm_parms");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IVRM_STRENGTH_LOOKUP, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           o_ivrmpb->strength_lookup));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IVRM_VIN_MULTIPLIER, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           o_ivrmpb->vin_multiplier));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IVRM_VIN_MAX_MV, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           o_ivrmpb->vin_max_mv));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IVRM_STEP_DELAY_NS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           o_ivrmpb->step_delay_ns));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IVRM_STABILIZATION_DELAY_NS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           o_ivrmpb->stablization_delay_ns));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IVRM_DEADZONE_MV, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           o_ivrmpb->deadzone_mv));

fapi_try_exit:
    FAPI_INF("<< proc_get_ivrm_parms");
    return fapi2::current_err;

}

//
//p9_pstate_compute_vpd_pts
//
void p9_pstate_compute_vpd_pts(VpdOperatingPoint (*o_operating_points)[VPD_PV_POINTS],
                               GlobalPstateParmBlock* i_gppb)
{
    int p = 0;

    const uint8_t pv_op_order[VPD_PV_POINTS] = VPD_PV_ORDER;

    //RAW POINTS. We just copy them as is
    for (p = 0; p < VPD_PV_POINTS; p++)
    {
        o_operating_points[VPD_PT_SET_RAW][pv_op_order[p]].vdd_mv = revle32(i_gppb->operating_points[p].vdd_mv) ;
        o_operating_points[VPD_PT_SET_RAW][pv_op_order[p]].vcs_mv = revle32(i_gppb->operating_points[p].vcs_mv);
        o_operating_points[VPD_PT_SET_RAW][pv_op_order[p]].idd_100ma = revle32(i_gppb->operating_points[p].idd_100ma);
        o_operating_points[VPD_PT_SET_RAW][pv_op_order[p]].ics_100ma = revle32(i_gppb->operating_points[p].ics_100ma);
        o_operating_points[VPD_PT_SET_RAW][pv_op_order[p]].frequency_mhz = revle32(i_gppb->operating_points[p].frequency_mhz);
        o_operating_points[VPD_PT_SET_RAW][pv_op_order[p]].pstate = i_gppb->operating_points[p].pstate;
        FAPI_INF("Raw o_operating_points[%d][pv_op_order[%d]].pstate %u",
                 VPD_PT_SET_RAW, p,
                 o_operating_points[VPD_PT_SET_RAW][pv_op_order[p]].pstate);
    }

    //SYSTEM PARAMS APPLIED POINTS
    //We first calculate everything in uV, and then divide by 1000. Doing this ensures
    //that integer division doesn't result in 0 for intermediate terms
    for (p = 0; p < VPD_PV_POINTS; p++)
    {
        o_operating_points[VPD_PT_SET_SYSP][pv_op_order[p]].vdd_mv =
            revle32((i_gppb->operating_points[p].vdd_mv * 1000 +
                     ((i_gppb->operating_points[p].idd_100ma * 100) * (i_gppb->vdd_sysparm.loadline_uohm +
                             i_gppb->vdd_sysparm.distloss_uohm)) +
                     (i_gppb->vdd_sysparm.distoffset_uv)) / 1000) ;
        o_operating_points[VPD_PT_SET_SYSP][pv_op_order[p]].vcs_mv =
            revle32( (i_gppb->operating_points[p].vcs_mv * 1000 +
                      ((i_gppb->operating_points[p].ics_100ma * 100) * (i_gppb->vcs_sysparm.loadline_uohm +
                              i_gppb->vcs_sysparm.distloss_uohm)) +
                      (i_gppb->vcs_sysparm.distoffset_uv)) / 1000) ;
        o_operating_points[VPD_PT_SET_SYSP][pv_op_order[p]].idd_100ma = revle32(i_gppb->operating_points[p].idd_100ma);
        o_operating_points[VPD_PT_SET_SYSP][pv_op_order[p]].ics_100ma = revle32(i_gppb->operating_points[p].ics_100ma);
        o_operating_points[VPD_PT_SET_SYSP][pv_op_order[p]].frequency_mhz = revle32(i_gppb->operating_points[p].frequency_mhz);
        o_operating_points[VPD_PT_SET_SYSP][pv_op_order[p]].pstate = i_gppb->operating_points[p].pstate;

        FAPI_INF(" sys o_operating_points[%d][pv_op_order[%d]].pstate %u",
                 VPD_PT_SET_SYSP, p,
                 o_operating_points[VPD_PT_SET_SYSP][pv_op_order[p]].pstate);
    }

    //BIASED POINTS
    for (p = 0; p < VPD_PV_POINTS; p++)
    {
        o_operating_points[VPD_PT_SET_BIASED][pv_op_order[p]].vdd_mv = ((revle32(i_gppb->operating_points[p].vdd_mv) *
                (200 + i_gppb->ext_biases[p].vdd_ext_hp)) / 200);
        o_operating_points[VPD_PT_SET_BIASED][pv_op_order[p]].vcs_mv = ((revle32(i_gppb->operating_points[p].vcs_mv) *
                (200 + i_gppb->ext_biases[p].vcs_ext_hp)) / 200);
        o_operating_points[VPD_PT_SET_BIASED][pv_op_order[p]].idd_100ma = revle32(i_gppb->operating_points[p].idd_100ma);
        o_operating_points[VPD_PT_SET_BIASED][pv_op_order[p]].ics_100ma = revle32(i_gppb->operating_points[p].ics_100ma);
        o_operating_points[VPD_PT_SET_BIASED][pv_op_order[p]].frequency_mhz = ((revle32(
                    i_gppb->operating_points[p].frequency_mhz) *
                (200 + i_gppb->ext_biases[p].frequency_hp)) / 200);
    }

    for (p = 0; p < VPD_PV_POINTS; p++)
    {
        o_operating_points[VPD_PT_SET_BIASED][pv_op_order[p]].pstate =
            (((o_operating_points[VPD_PT_SET_BIASED][ULTRA].frequency_mhz -
               o_operating_points[VPD_PT_SET_BIASED][pv_op_order[p]].frequency_mhz) * 1000) /
             revle32(i_gppb->frequency_step_khz));

    }

    //BIASED POINTS and SYSTEM PARMS APPLIED POINTS
    //We first calculate everything in uV, and then divide by 1000. Doing this ensures
    //that integer division doesn't result in 0 for intermediate terms
    for (p = 0; p < VPD_PV_POINTS; p++)
    {
        o_operating_points[VPD_PT_SET_BIASED_SYSP][pv_op_order[p]].vdd_mv =
            (((o_operating_points[VPD_PT_SET_BIASED][pv_op_order[p]].vdd_mv * 1000) +
              ((o_operating_points[VPD_PT_SET_BIASED][pv_op_order[p]].idd_100ma * 100) *
               revle32((i_gppb->vdd_sysparm.loadline_uohm + i_gppb->vdd_sysparm.distloss_uohm))) +
              revle32((i_gppb->vdd_sysparm.distoffset_uv))) / 1000 );
        o_operating_points[VPD_PT_SET_BIASED_SYSP][pv_op_order[p]].vcs_mv =
            (((o_operating_points[VPD_PT_SET_BIASED][pv_op_order[p]].vcs_mv * 1000) +
              ((o_operating_points[VPD_PT_SET_BIASED][pv_op_order[p]].ics_100ma * 100) *
               revle32((i_gppb->vcs_sysparm.loadline_uohm + i_gppb->vcs_sysparm.distloss_uohm))) +
              revle32((i_gppb->vcs_sysparm.distoffset_uv))) / 1000 );
        o_operating_points[VPD_PT_SET_BIASED_SYSP][pv_op_order[p]].idd_100ma =
            (o_operating_points[VPD_PT_SET_BIASED][pv_op_order[p]].idd_100ma);
        o_operating_points[VPD_PT_SET_BIASED_SYSP][pv_op_order[p]].ics_100ma =
            (o_operating_points[VPD_PT_SET_BIASED][pv_op_order[p]].ics_100ma);
        o_operating_points[VPD_PT_SET_BIASED_SYSP][pv_op_order[p]].frequency_mhz =
            (o_operating_points[VPD_PT_SET_BIASED][pv_op_order[p]].frequency_mhz);
        o_operating_points[VPD_PT_SET_BIASED_SYSP][pv_op_order[p]].pstate =
            o_operating_points[VPD_PT_SET_BIASED][pv_op_order[p]].pstate;

    }
}


//
// p9_pstate_compute_PsV_slopes
//
//Computes slope of voltage-PState curve and PState-voltage
//
//PState(Frequency) on y-axis, Voltage is on x-axis for VF curve
//Interpolation formula: (y-y0)/(x-x0) = (y1-y0)/(x1-x0)
//m   = (x1-x0)/(y1-y0), then use this to calculate voltage, x = (y-y0)*m + x0
//1/m = (y1-y0)/(x1-x0) here, then use this to calculate pstate(frequency), y = (x-x0)*m + y0
//Region 0 is b/w POWERSAVE and NOMINAL
//Region 1 is b/w NOMINAL and TURBO
//Region 2 is between TURBO and ULTRA_TURBO
//
//Inflection Point 3 is ULTRA_TURBO
//Inflection Point 2 is TURBO
//Inflection Point 1 is NOMINAL
//Inflection Point 0 is POWERSAVE
//
void p9_pstate_compute_PsV_slopes(VpdOperatingPoint i_operating_points[][4],
                                  GlobalPstateParmBlock* o_gppb)
{
    uint32_t tmp;
    uint32_t eVidFP[VPD_PV_POINTS];

    do
    {
        //
        //RAW VPD PTS SLOPES
        //
        //convert to a fixed-point number
        eVidFP[POWERSAVE] = i_operating_points[VPD_PT_SET_RAW][POWERSAVE].vdd_mv << EVID_SLOPE_FP_SHIFT;
        eVidFP[NOMINAL] = i_operating_points[VPD_PT_SET_RAW][NOMINAL].vdd_mv << EVID_SLOPE_FP_SHIFT;
        eVidFP[TURBO] = i_operating_points[VPD_PT_SET_RAW][TURBO].vdd_mv << EVID_SLOPE_FP_SHIFT;
        eVidFP[ULTRA] = i_operating_points[VPD_PT_SET_RAW][ULTRA].vdd_mv << EVID_SLOPE_FP_SHIFT;

        FAPI_INF("eVidFP[POWERSAVE] %u %04x", eVidFP[POWERSAVE], i_operating_points[VPD_PT_SET_RAW][POWERSAVE].vdd_mv);
        FAPI_INF("eVidFP[NOMINAL] %u %04x", eVidFP[NOMINAL], i_operating_points[VPD_PT_SET_RAW][NOMINAL].vdd_mv);
        FAPI_INF("eVidFP[TURBO] %u %04x", eVidFP[TURBO], i_operating_points[VPD_PT_SET_RAW][TURBO].vdd_mv);
        FAPI_INF("eVidFP[ULTRA] %u %04x", eVidFP[ULTRA], i_operating_points[VPD_PT_SET_RAW][ULTRA].vdd_mv);

        // ULTRA TURBO pstate check is not required..because it's pstate will be
        // 0
        if (!(i_operating_points[VPD_PT_SET_RAW][POWERSAVE].pstate) ||
            !(i_operating_points[VPD_PT_SET_RAW][NOMINAL].pstate) ||
            !(i_operating_points[VPD_PT_SET_RAW][TURBO].pstate))
        {
            FAPI_ERR("PSTATE value shouldn't be zero for VPD_PT_SET_RAW");
            break;
        }

        //Calculate slopes
        tmp = (uint32_t)(eVidFP[NOMINAL] - eVidFP[POWERSAVE]) /
              (uint32_t)(-i_operating_points[VPD_PT_SET_RAW][NOMINAL].pstate + i_operating_points[VPD_PT_SET_RAW][POWERSAVE].pstate);
        o_gppb->PsVSlopes[VPD_SLOPES_RAW][REGION_POWERSAVE_NOMINAL] = revle16((uint16_t)tmp);
        FAPI_INF("PsVSlopes[VPD_SLOPES_RAW][REGION_POWERSAVE_NOMINAL] %X tmp %X",
                 (revle16(o_gppb->PsVSlopes[VPD_SLOPES_RAW][REGION_POWERSAVE_NOMINAL])), (tmp));

        tmp = (uint32_t)(eVidFP[TURBO] - eVidFP[NOMINAL]) /
              (uint32_t)(-i_operating_points[VPD_PT_SET_RAW][TURBO].pstate + i_operating_points[VPD_PT_SET_RAW][NOMINAL].pstate);
        o_gppb->PsVSlopes[VPD_SLOPES_RAW][REGION_NOMINAL_TURBO] = revle16((uint16_t)tmp);
        FAPI_INF("PsVSlopes[VPD_SLOPES_RAW][REGION_NOMINAL_TURBO] %X tmp %X",
                 (revle16(o_gppb->PsVSlopes[VPD_SLOPES_RAW][REGION_NOMINAL_TURBO])), (tmp));

        tmp = (uint32_t)(eVidFP[ULTRA] - eVidFP[TURBO]) /
              (uint32_t)(-i_operating_points[VPD_PT_SET_RAW][ULTRA].pstate + i_operating_points[VPD_PT_SET_RAW][TURBO].pstate);
        o_gppb->PsVSlopes[VPD_SLOPES_RAW][REGION_TURBO_ULTRA] = revle16((uint16_t)tmp);
        FAPI_INF("PsVSlopes[VPD_SLOPES_RAW][REGION_TURBO_ULTRA] %X tmp %X",
                 (revle16(o_gppb->PsVSlopes[VPD_SLOPES_RAW][REGION_TURBO_ULTRA])), (tmp));

        //Calculate inverted slopes
        tmp =  (uint32_t)((-i_operating_points[VPD_PT_SET_RAW][NOMINAL].pstate +
                           i_operating_points[VPD_PT_SET_RAW][POWERSAVE].pstate) << EVID_SLOPE_FP_SHIFT)
               / (uint32_t) (i_operating_points[VPD_PT_SET_RAW][NOMINAL].vdd_mv -
                             i_operating_points[VPD_PT_SET_RAW][POWERSAVE].vdd_mv);
        o_gppb->VPsSlopes[VPD_SLOPES_RAW][REGION_POWERSAVE_NOMINAL] = revle16((uint16_t)tmp);
        FAPI_INF("VPsSlopes[VPD_SLOPES_RAW][REGION_POWERSAVE_NOMINAL] %X tmp %X",
                 (revle16(o_gppb->VPsSlopes[VPD_SLOPES_RAW][REGION_POWERSAVE_NOMINAL])), (tmp));

        tmp =  (uint32_t)((-i_operating_points[VPD_PT_SET_RAW][TURBO].pstate +
                           i_operating_points[VPD_PT_SET_RAW][NOMINAL].pstate) << EVID_SLOPE_FP_SHIFT)
               / (uint32_t) (i_operating_points[VPD_PT_SET_RAW][TURBO].vdd_mv -
                             i_operating_points[VPD_PT_SET_RAW][NOMINAL].vdd_mv);
        o_gppb->VPsSlopes[VPD_SLOPES_RAW][REGION_NOMINAL_TURBO] = revle16((uint16_t)tmp);
        FAPI_INF("VPsSlopes[VPD_SLOPES_RAW][REGION_NOMINAL_TURBO] %X tmp %X",
                 (revle16(o_gppb->VPsSlopes[VPD_SLOPES_RAW][REGION_NOMINAL_TURBO])), (tmp));

        tmp =  (uint32_t)((-i_operating_points[VPD_PT_SET_RAW][ULTRA].pstate +
                           i_operating_points[VPD_PT_SET_RAW][TURBO].pstate) << EVID_SLOPE_FP_SHIFT)
               / (uint32_t) (i_operating_points[VPD_PT_SET_RAW][ULTRA].vdd_mv -
                             i_operating_points[VPD_PT_SET_RAW][TURBO].vdd_mv);
        o_gppb->VPsSlopes[VPD_SLOPES_RAW][REGION_TURBO_ULTRA] = revle16((uint16_t)tmp);
        FAPI_INF("VPsSlopes[VPD_SLOPES_RAW][REGION_TURBO_ULTRA] %X tmp %X",
                 (revle16(o_gppb->VPsSlopes[VPD_SLOPES_RAW][REGION_TURBO_ULTRA])), (tmp));

        //
        //BIASED VPD PTS SLOPES
        //
        //convert to fixed-point number
        eVidFP[POWERSAVE] = i_operating_points[VPD_PT_SET_BIASED][POWERSAVE].vdd_mv << EVID_SLOPE_FP_SHIFT;
        eVidFP[NOMINAL] = i_operating_points[VPD_PT_SET_BIASED][NOMINAL].vdd_mv << EVID_SLOPE_FP_SHIFT;
        eVidFP[TURBO] = i_operating_points[VPD_PT_SET_BIASED][TURBO].vdd_mv << EVID_SLOPE_FP_SHIFT;
        eVidFP[ULTRA] = i_operating_points[VPD_PT_SET_BIASED][ULTRA].vdd_mv << EVID_SLOPE_FP_SHIFT;

        FAPI_INF("eVidFP[POWERSAVE] Biased %u", eVidFP[POWERSAVE]);
        FAPI_INF("eVidFP[NOMINAL] Biased %u", eVidFP[NOMINAL]);
        FAPI_INF("eVidFP[TURBO] Biased %u", eVidFP[TURBO]);
        FAPI_INF("eVidFP[ULTRA] Biased %u", eVidFP[ULTRA]);

        // ULTRA TURBO pstate check is not required..because it's pstate will be
        // 0
        if (!(i_operating_points[VPD_PT_SET_BIASED][POWERSAVE].pstate) ||
            !(i_operating_points[VPD_PT_SET_BIASED][NOMINAL].pstate) ||
            !(i_operating_points[VPD_PT_SET_BIASED][TURBO].pstate))
        {
            FAPI_ERR("PSTATE value shouldn't be zero for VPD_PT_SET_BIASED");
            break;
        }

        //Calculate slopes
        FAPI_INF(" num %u denom %u %u %u",
                 (uint32_t)(eVidFP[NOMINAL] - eVidFP[POWERSAVE]),
                 (uint32_t)(-i_operating_points[VPD_PT_SET_BIASED][NOMINAL].pstate +
                            i_operating_points[VPD_PT_SET_BIASED][POWERSAVE].pstate),
                 (uint32_t)(-i_operating_points[VPD_PT_SET_BIASED][NOMINAL].pstate),
                 (uint32_t)i_operating_points[VPD_PT_SET_BIASED][POWERSAVE].pstate);
        tmp = (uint32_t)(eVidFP[NOMINAL] - eVidFP[POWERSAVE]) /
              (uint32_t)(-i_operating_points[VPD_PT_SET_BIASED][NOMINAL].pstate +
                         i_operating_points[VPD_PT_SET_BIASED][POWERSAVE].pstate);
        o_gppb->PsVSlopes[VPD_SLOPES_BIASED][REGION_POWERSAVE_NOMINAL] = revle16((uint16_t)tmp);
        FAPI_INF("PsVSlopes[VPD_SLOPES_BIASED][REGION_POWERSAVE_NOMINAL] %X tmp %X",
                 (revle16(o_gppb->PsVSlopes[VPD_SLOPES_BIASED][REGION_POWERSAVE_NOMINAL])), (tmp));

        tmp = (uint32_t)(eVidFP[TURBO] - eVidFP[NOMINAL]) /
              (uint32_t)(-i_operating_points[VPD_PT_SET_BIASED][TURBO].pstate +
                         i_operating_points[VPD_PT_SET_BIASED][NOMINAL].pstate);
        o_gppb->PsVSlopes[VPD_SLOPES_BIASED][REGION_NOMINAL_TURBO] = revle16((uint16_t)tmp);
        FAPI_INF("PsVSlopes[VPD_SLOPES_BIASED][REGION_NOMINAL_TURBO] %X tmp %X",
                 (revle16(o_gppb->PsVSlopes[VPD_SLOPES_BIASED][REGION_NOMINAL_TURBO])), (tmp));

        tmp = (uint32_t)(eVidFP[ULTRA] - eVidFP[TURBO]) /
              (uint32_t)(-i_operating_points[VPD_PT_SET_BIASED][ULTRA].pstate + i_operating_points[VPD_PT_SET_BIASED][TURBO].pstate);
        o_gppb->PsVSlopes[VPD_SLOPES_BIASED][REGION_TURBO_ULTRA] = revle16((uint16_t)tmp);
        FAPI_INF("PsVSlopes[VPD_SLOPES_BIASED][REGION_TURBO_ULTRA] %X tmp %X",
                 (revle16(o_gppb->PsVSlopes[VPD_SLOPES_BIASED][REGION_TURBO_ULTRA])), (tmp));

        //Calculate inverted slopes
        tmp =  (uint32_t)((-i_operating_points[VPD_PT_SET_BIASED][NOMINAL].pstate +
                           i_operating_points[VPD_PT_SET_BIASED][POWERSAVE].pstate) << EVID_SLOPE_FP_SHIFT)
               / (uint32_t) (i_operating_points[VPD_PT_SET_BIASED][NOMINAL].vdd_mv -
                             i_operating_points[VPD_PT_SET_BIASED][POWERSAVE].vdd_mv);
        o_gppb->VPsSlopes[VPD_SLOPES_BIASED][REGION_POWERSAVE_NOMINAL] = revle16((uint16_t)tmp);
        FAPI_INF ("VPsSlopes[VPD_SLOPES_BIASED][REGION_POWERSAVE_NOMINAL] %X tmp %X",
                  (revle16(o_gppb->VPsSlopes[VPD_SLOPES_BIASED][REGION_POWERSAVE_NOMINAL])), (tmp));

        tmp =  (uint32_t)((-i_operating_points[VPD_PT_SET_BIASED][TURBO].pstate +
                           i_operating_points[VPD_PT_SET_BIASED][NOMINAL].pstate) << EVID_SLOPE_FP_SHIFT)
               / (uint32_t) (i_operating_points[VPD_PT_SET_BIASED][TURBO].vdd_mv -
                             i_operating_points[VPD_PT_SET_BIASED][NOMINAL].vdd_mv);
        o_gppb->VPsSlopes[VPD_SLOPES_BIASED][REGION_NOMINAL_TURBO] = revle16((uint16_t)tmp);
        FAPI_INF("VPsSlopes[VPD_SLOPES_BIASED][REGION_NOMINAL_TURBO] %X tmp %X",
                 (revle16(o_gppb->VPsSlopes[VPD_SLOPES_BIASED][REGION_NOMINAL_TURBO])), (tmp));

        tmp =  (uint32_t)((-i_operating_points[VPD_PT_SET_BIASED][ULTRA].pstate +
                           i_operating_points[VPD_PT_SET_BIASED][TURBO].pstate) << EVID_SLOPE_FP_SHIFT)
               / (uint32_t) (i_operating_points[VPD_PT_SET_BIASED][ULTRA].vdd_mv -
                             i_operating_points[VPD_PT_SET_BIASED][TURBO].vdd_mv);
        o_gppb->VPsSlopes[VPD_SLOPES_BIASED][REGION_TURBO_ULTRA] = revle16((uint16_t)tmp);
        FAPI_INF("VPsSlopes[VPD_SLOPES_BIASED][REGION_TURBO_ULTRA] %X tmp %X",
                 (revle16(o_gppb->VPsSlopes[VPD_SLOPES_BIASED][REGION_TURBO_ULTRA])), (tmp));
    }
    while(0);
}

/// Print a GlobalPstateParameterBlock structure on a given stream
///
/// \param gppb The Global Pstate Parameter Block print

void
gppb_print(GlobalPstateParmBlock* i_gppb)
{

    static const uint32_t   BUFFSIZE = 256;
    char                    l_buffer[BUFFSIZE];
    char                    l_temp_buffer[BUFFSIZE];

    // Put out the endian-corrected scalars
    FAPI_INF("---------------------------------------------------------------------------------------");
    FAPI_INF("Global Pstate Parameter Block @ %p", i_gppb);
    FAPI_INF("---------------------------------------------------------------------------------------");

//    sprintf(l_buffer, "Magic:               %llu", revle64(i_gppb->magic));
    FAPI_INF("Options:             %X", revle32(i_gppb->options.options));
    FAPI_INF("Reference Frequency: %X (%d)",
             revle32(i_gppb->reference_frequency_khz), revle32(i_gppb->reference_frequency_khz));
    FAPI_INF("Frequency Step Size: %X (%d)",
             revle32(i_gppb->frequency_step_khz), revle32(i_gppb->frequency_step_khz));

    FAPI_INF("Operating Points:     Frequency     VDD(mV)    IDD(100mA)     VCS(mV)    ICS(100mA)");

    for (uint32_t i = 0; i < VPD_PV_POINTS; i++)
    {
        sprintf(l_buffer, "                 ");
        sprintf(l_temp_buffer, " %04X (%4d) ",
                revle32(i_gppb->operating_points[i].frequency_mhz),
                revle32(i_gppb->operating_points[i].frequency_mhz));
        strcat(l_buffer, l_temp_buffer);

        sprintf(l_temp_buffer, " %04X (%4d) ",
                revle32(i_gppb->operating_points[i].vdd_mv),
                revle32(i_gppb->operating_points[i].vdd_mv));
        strcat(l_buffer, l_temp_buffer);

        sprintf(l_temp_buffer, " %04X (%4d) ",
                revle32(i_gppb->operating_points[i].idd_100ma),
                revle32(i_gppb->operating_points[i].idd_100ma));
        strcat(l_buffer, l_temp_buffer);

        sprintf(l_temp_buffer, " %04X (%4d) ",
                revle32(i_gppb->operating_points[i].vcs_mv),
                revle32(i_gppb->operating_points[i].vcs_mv));
        strcat(l_buffer, l_temp_buffer);

        sprintf(l_temp_buffer, " %04X (%3d) ",
                revle32(i_gppb->operating_points[i].ics_100ma),
                revle32(i_gppb->operating_points[i].ics_100ma));
        strcat(l_buffer, l_temp_buffer);
        FAPI_INF("%s", l_buffer);
    }

    FAPI_INF("System Parameters:            VDD        VCS        VDN");
    sprintf(l_buffer, "   Load line (uOhm)        ");
    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_gppb->vdd_sysparm.loadline_uohm),
            revle32(i_gppb->vdd_sysparm.loadline_uohm));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_gppb->vcs_sysparm.loadline_uohm),
            revle32(i_gppb->vcs_sysparm.loadline_uohm));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_gppb->vdn_sysparm.loadline_uohm),
            revle32(i_gppb->vdn_sysparm.loadline_uohm));
    strcat(l_buffer, l_temp_buffer);
    FAPI_INF("%s", l_buffer);

    sprintf(l_buffer, "   Distribution Loss (uOhm)");
    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_gppb->vdd_sysparm.distloss_uohm),
            revle32(i_gppb->vdd_sysparm.distloss_uohm));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_gppb->vcs_sysparm.distloss_uohm),
            revle32(i_gppb->vcs_sysparm.distloss_uohm));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_gppb->vdn_sysparm.distloss_uohm),
            revle32(i_gppb->vdn_sysparm.distloss_uohm));
    strcat(l_buffer, l_temp_buffer);
    FAPI_INF("%s", l_buffer);

    sprintf(l_buffer, "   Offset (uV)             ");
    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_gppb->vdd_sysparm.distoffset_uv),
            revle32(i_gppb->vdd_sysparm.distoffset_uv));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_gppb->vcs_sysparm.distoffset_uv),
            revle32(i_gppb->vcs_sysparm.distoffset_uv));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_gppb->vdn_sysparm.distoffset_uv),
            revle32(i_gppb->vdn_sysparm.distoffset_uv));
    strcat(l_buffer, l_temp_buffer);
    FAPI_INF("%s", l_buffer);

    FAPI_INF("Safe Parameters:");
    FAPI_INF("   Frequency  %04X (%3d) ",
             revle32(i_gppb->safe_frequency_khz),
             revle32(i_gppb->safe_frequency_khz));
    FAPI_INF("   Voltage    %04X (%3d)",
             revle32(i_gppb->safe_voltage_mv),
             revle32(i_gppb->safe_voltage_mv));

    FAPI_INF("Pstate Stepping Parameters:");
    FAPI_INF("   Delay range exponent %04X (%3d) ",
             revle32(i_gppb->vrm_stepdelay_range),
             revle32(i_gppb->vrm_stepdelay_range));
    FAPI_INF("   Significand  %04X (%3d)",
             revle32(i_gppb->vrm_stepdelay_value),
             revle32(i_gppb->vrm_stepdelay_value));

    FAPI_INF("External VRM Parameters:");
    FAPI_INF("   VRM Transition Start %04X (%3d)",
             revle32(i_gppb->ext_vrm_transition_start_ns),
             revle32(i_gppb->ext_vrm_transition_start_ns));
    FAPI_INF("   VRM Transition Rate - Rising %04X (%3d) (uv/us)",
             revle32(i_gppb->ext_vrm_transition_rate_inc_uv_per_us),
             revle32(i_gppb->ext_vrm_transition_rate_inc_uv_per_us));
    FAPI_INF("   VRM Transition Rate - Falling (uv/us) %04X (%3d)",
             revle32(i_gppb->ext_vrm_transition_rate_dec_uv_per_us),
             revle32(i_gppb->ext_vrm_transition_rate_dec_uv_per_us));
    FAPI_INF("   VRM Settling Time (us) %04X (%3d)",
             revle32(i_gppb->ext_vrm_transition_rate_dec_uv_per_us),
             revle32(i_gppb->ext_vrm_transition_rate_dec_uv_per_us));
    FAPI_INF("   VRM Transition Step Size (mV) %04X (%3d)",
             revle32(i_gppb->ext_vrm_step_size_mv),
             revle32(i_gppb->ext_vrm_step_size_mv));

    FAPI_INF("Nest Frequency: %04X (%3d)",
             revle32(i_gppb->nest_frequency_mhz),
             revle32(i_gppb->nest_frequency_mhz));

    FAPI_INF("PsVSlopes: ");

    strcpy(l_buffer, " Regions ");

    for (uint32_t j = 0; j <  VPD_NUM_SLOPES_REGION; ++j)
    {
        sprintf(l_temp_buffer, "   %d   ", j);
        strcat(l_buffer, l_temp_buffer);
    }

    FAPI_INF("%s", l_buffer);

    for (uint32_t i = 0; i < VPD_NUM_SLOPES_SET; ++i)
    {
        sprintf(l_buffer, " Set %d : ", i);

        for (uint32_t j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
        {
            sprintf(l_temp_buffer, " %04X  ",
                    revle16(i_gppb->PsVSlopes[i][j]));
            strcat(l_buffer, l_temp_buffer);
        }

        FAPI_INF("%s", l_buffer);
    }

    FAPI_INF("VPsSlopes: ");
    strcpy(l_buffer, " Regions ");

    for (uint32_t j = 0; j <  VPD_NUM_SLOPES_REGION; ++j)
    {
        sprintf(l_temp_buffer, "   %d   ", j);
        strcat(l_buffer, l_temp_buffer);
    }

    FAPI_INF("%s", l_buffer);

    for (uint32_t i = 0; i < VPD_NUM_SLOPES_SET; ++i)
    {
        sprintf(l_buffer, " Set %d : ", i);

        for (uint32_t j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
        {
            sprintf(l_temp_buffer, " %04X  ",
                    revle16(i_gppb->VPsSlopes[i][j]));
            strcat(l_buffer, l_temp_buffer);
        }

        FAPI_INF("%s", l_buffer);
    }


    FAPI_INF("---------------------------------------------------------------------------------------");
}

/// Print an OCCPstateParameterBlock structure on a given stream
///
/// \param oppb The OCC Pstate Parameter Block print

void
oppb_print(OCCPstateParmBlock* i_oppb)
{
    static const uint32_t   BUFFSIZE = 256;
    char                    l_buffer[BUFFSIZE];
    char                    l_temp_buffer[BUFFSIZE];

    // Put out the endian-corrected scalars

    FAPI_INF("---------------------------------------------------------------------------------------");
    FAPI_INF("OCC Pstate Parameter Block @ %p", i_oppb);
    FAPI_INF("---------------------------------------------------------------------------------------");

//    fprintf(stream, "Magic:               %llu\n", revle64(i_oppb->magic));
    FAPI_INF("Operating Points:     Frequency     VDD(mV)    IDD(100mA)     VCS(mV)    ICS(100mA)");

    for (uint32_t i = 0; i < VPD_PV_POINTS; i++)
    {
        sprintf(l_buffer, "                 ");
        sprintf(l_temp_buffer, " %04X (%4d) ",
                revle32(i_oppb->operating_points[i].frequency_mhz),
                revle32(i_oppb->operating_points[i].frequency_mhz));
        strcat(l_buffer, l_temp_buffer);

        sprintf(l_temp_buffer, " %04X (%4d) ",
                revle32(i_oppb->operating_points[i].vdd_mv),
                revle32(i_oppb->operating_points[i].vdd_mv));
        strcat(l_buffer, l_temp_buffer);

        sprintf(l_temp_buffer, " %04X (%4d) ",
                revle32(i_oppb->operating_points[i].idd_100ma),
                revle32(i_oppb->operating_points[i].idd_100ma));
        strcat(l_buffer, l_temp_buffer);

        sprintf(l_temp_buffer, " %04X (%4d) ",
                revle32(i_oppb->operating_points[i].vcs_mv),
                revle32(i_oppb->operating_points[i].vcs_mv));
        strcat(l_buffer, l_temp_buffer);

        sprintf(l_temp_buffer, " %04X (%3d) ",
                revle32(i_oppb->operating_points[i].ics_100ma),
                revle32(i_oppb->operating_points[i].ics_100ma));
        strcat(l_buffer, l_temp_buffer);
        FAPI_INF("%s", l_buffer);
    }

    FAPI_INF("System Parameters:            VDD        VCS        VDN");
    sprintf(l_buffer, "   Load line (uOhm)        ");
    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vdd_sysparm.loadline_uohm),
            revle32(i_oppb->vdd_sysparm.loadline_uohm));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vcs_sysparm.loadline_uohm),
            revle32(i_oppb->vcs_sysparm.loadline_uohm));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vdn_sysparm.loadline_uohm),
            revle32(i_oppb->vdn_sysparm.loadline_uohm));
    strcat(l_buffer, l_temp_buffer);
    FAPI_INF("%s", l_buffer);

    sprintf(l_buffer, "   Distribution Loss (uOhm)");
    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vdd_sysparm.distloss_uohm),
            revle32(i_oppb->vdd_sysparm.distloss_uohm));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vcs_sysparm.distloss_uohm),
            revle32(i_oppb->vcs_sysparm.distloss_uohm));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vdn_sysparm.distloss_uohm),
            revle32(i_oppb->vdn_sysparm.distloss_uohm));
    strcat(l_buffer, l_temp_buffer);
    FAPI_INF("%s", l_buffer);

    sprintf(l_buffer, "   Offset (uV)             ");
    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vdd_sysparm.distoffset_uv),
            revle32(i_oppb->vdd_sysparm.distoffset_uv));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vcs_sysparm.distoffset_uv),
            revle32(i_oppb->vcs_sysparm.distoffset_uv));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vdn_sysparm.distoffset_uv),
            revle32(i_oppb->vdn_sysparm.distoffset_uv));
    strcat(l_buffer, l_temp_buffer);
    FAPI_INF("%s", l_buffer);

    FAPI_INF("Frequency Minumum (kHz):      %04X (%3d)",
             revle32(i_oppb->frequency_min_khz),
             revle32(i_oppb->frequency_min_khz));

    FAPI_INF("Frequency Maximum (kHz):     %04X (%3d)",
             revle32(i_oppb->frequency_max_khz),
             revle32(i_oppb->frequency_max_khz));

    FAPI_INF("Frequency Step (kHz):        %04X (%3d)",
             revle32(i_oppb->frequency_step_khz),
             revle32(i_oppb->frequency_step_khz));

    FAPI_INF("Pstate of Minimum Frequency: %02X (%3d)",
             i_oppb->pstate_min,
             i_oppb->pstate_min);

    FAPI_INF("---------------------------------------------------------------------------------------");
}



// Convert frequency to Pstate number
///
/// \param stream The output stream

int freq2pState (const GlobalPstateParmBlock* gppb,
                 const uint32_t freq_khz,
                 Pstate* pstate)
{
    int rc = 0;
    float pstate32 = 0;

    // ----------------------------------
    // compute pstate for given frequency
    // ----------------------------------
    pstate32 = ((float)(revle32(gppb->reference_frequency_khz) - freq_khz)) / (float)revle32(gppb->frequency_step_khz);
    *pstate    = (Pstate)pstate32;

    // ------------------------------
    // perform pstate bounds checking
    // ------------------------------
    if (pstate32 > PSTATE_MIN)
    {
        rc = -PSTATE_LT_PSTATE_MIN;
    }

    if (pstate32 < PSTATE_MAX)
    {
        rc = -PSTATE_GT_PSTATE_MAX;
    }

    return rc;
}
