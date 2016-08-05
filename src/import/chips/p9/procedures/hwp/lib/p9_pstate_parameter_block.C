/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_pstate_parameter_block.C $ */
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

///
/// @file  p9_pstate_parameter_block.C
/// @brief Setup Pstate super structure for PGPE/CME HCode
///
/// *HWP HW Owner        : Sudheendra K Srivathsa <sudheendraks@in.ibm.com>
/// *HWP HW Backup Owner : Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner        : Sangeetha T S <sangeet2@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 1
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
//#include <p9_pstates.h>
//#include <pstate_tables.h>
//#include <lab_pstates.h>
//#include <pstates.h>
//#include <p9_pm.H>
#include <p9_pstate_parameter_block.H>

// ssrivath START OF PSTATE PARAMETER BLOCK function

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

    FAPI_INF("Populating magic number in Pstate Parameter block structure");

    // -----------------------------------------------------------
    // Clear the PstateSuperStructure and install the magic number
    // -----------------------------------------------------------
    memset(io_pss, 0, sizeof(PstateSuperStructure));

    //@TODO RTC 157943 - Use revle64 below with the right include files
    //(*io_pss).magic = revle64(PSTATE_PARMSBLOCK_MAGIC);
    (*io_pss).magic = PSTATE_PARMSBLOCK_MAGIC;

#if 0

    //Local variables for Global,local and OCC parameter blocks
    // PGPE content
    GlobalPstateParmBlock l_globalppb;

    // CME content
    LocalPstateParmBlock l_localppb;

    // OCC content
    OCCPstateParmBlock l_occppb;

    // Variable for all attributes data structure
    AttributeList attr;
    //ChipCharacterization* characterization;

    // MVPD #V variables
    uint32_t attr_mvpd_voltage_control[PV_D][PV_W];
    uint8_t present_chiplets = 0;
    uint32_t valid_pdv_points = 0;

    // Bias variables, @todo RTC 157943 - P9 Usage?
    double volt_int_vdd_bias = 1.0;
    double volt_int_vcs_bias = 1.0;

    //Variables for Loadline, Distribution loss and offset
    SysPowerDistParms l_vdd_sysparm;
    SysPowerDistParms l_vcs_sysparm;
    SysPowerDistParms l_vdn_sysparm;

    // Local IDDQ table variable
    IddqTable l_iddqt;

    // Frequency step variable
    uint32_t l_frequency_step_khz;

    //// -----------------------------------------------------------
    //// Clear the PstateSuperStructure and install the magic number
    //// -----------------------------------------------------------
    //memset(io_pss, 0, sizeof(PstateSuperStructure));

    ////@todo RTC 157943 - Use revle64 below with the right include files
    ////(*io_pss).magic = revle64(PSTATE_PARMSBLOCK_MAGIC);
    //(*io_pss).magic = PSTATE_PARMSBLOCK_MAGIC;

    // -------------------------
    // Get all attributes needed
    // -------------------------
    FAPI_INF("Getting Attributes to build Pstate Superstructure");

    FAPI_TRY(proc_get_attributes(i_target, &attr), "Get attributes function failed");


    //ssrivath, START OF P8 CODE SECTION, TODO, Evaluate if PSTATE_NO_INSTALL_LPSA, PSTATE_NO_INSTALL_RESCLK usage
    //// --------------------------------
    //// check chip ec feature attributes
    //// --------------------------------
    //if (attr.attr_proc_ec_core_hang_pulse_bug)
    //{
    //    FAPI_INF("ATTR_PROC_EC_CORE_HANG_PULSE_BUG is set so disable iVRMs - setting PSTATE_NO_INSTALL_LPSA");
    //    (*io_pss).gpst.options.options = revle32(revle32((*io_pss).gpst.options.options) | PSTATE_NO_INSTALL_LPSA);
    //    poundm_valid = 0;
    //    lpst_valid   = 0;
    //}

    //if (! attr.attr_chip_ec_feature_resonant_clk_valid)
    //{
    //    FAPI_INF("ATTR_CHIP_EC_FEATURE_RESONANT_CLK_VALID is not set so disable resonant clocking - setting PSTATE_NO_INSTALL_RESCLK");
    //    (*io_pss).gpst.options.options = revle32(revle32((*io_pss).gpst.options.options) | PSTATE_NO_INSTALL_RESCLK );
    //ssrivath, END OF P8 CODE SECTION, TODO, Evaluate if PSTATE_NO_INSTALL_LPSA, PSTATE_NO_INSTALL_RESCLK usage

    // ----------------
    // get #V data
    // ----------------
    FAPI_IMP("Getting #V Data");

    // clear MVPD array
    memset(attr_mvpd_voltage_control, 0, sizeof(attr_mvpd_voltage_control));

    FAPI_TRY(proc_get_mvpd_data( i_target, &attr, attr_mvpd_voltage_control, &valid_pdv_points, &present_chiplets),
             "Get MVPD #V data failed");

    if (!present_chiplets)
    {
        FAPI_ERR("**** ERROR : There are no cores present");
        //const uint8_t& PRESENT_CHIPLETS = present_chiplets;
        //const Target&  CHIP_TARGET = i_target;
        //FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_NO_CORES_PRESENT_ERROR);
        //break;
    }

    // ---------------------------------------------
    // process external and internal bias attributes
    // ---------------------------------------------
    FAPI_IMP("Apply Biasing to #V");

    FAPI_TRY(proc_get_extint_bias(attr_mvpd_voltage_control, &attr, &volt_int_vdd_bias, &volt_int_vcs_bias),
             "Bias application function failed");

    // -----------------------------------------------
    // populate VpdOperatingPoint with biased MVPD attributes
    // -----------------------------------------------
    VpdOperatingPoint s132a_vpd[VPD_PV_POINTS];

    FAPI_TRY(load_mvpd_operating_point(attr_mvpd_voltage_control, s132a_vpd), "Loading MVPD operating point failed");

    // -----------------------------------------------
    // System power distribution parameters
    // -----------------------------------------------
    // VDD rail
    l_vdd_sysparm.loadline_uohm = attr.attr_proc_r_loadline_vdd_uohm;
    l_vdd_sysparm.distloss_uohm = attr.attr_proc_r_distloss_vdd_uohm;
    l_vdd_sysparm.distoffset_uv = attr.attr_proc_vrm_voffset_vdd_uv;

    // VCS rail
    l_vcs_sysparm.loadline_uohm = attr.attr_proc_r_loadline_vcs_uohm;
    l_vcs_sysparm.distloss_uohm = attr.attr_proc_r_distloss_vcs_uohm;
    l_vcs_sysparm.distoffset_uv = attr.attr_proc_vrm_voffset_vcs_uv;

    // VDN rail
    l_vdn_sysparm.loadline_uohm = attr.attr_proc_r_loadline_vdn_uohm;
    l_vdn_sysparm.distloss_uohm = attr.attr_proc_r_distloss_vdn_uohm;
    l_vdn_sysparm.distoffset_uv = attr.attr_proc_vrm_voffset_vdn_uv;

    // ----------------
    // get IQ (IDDQ) data
    // ----------------
    FAPI_INF("Getting IQ (IDDQ) Data");
    FAPI_TRY(proc_get_mvpd_iddq(i_target, &l_iddqt));

    // -----------------------------------------------
    // Global parameter block
    // -----------------------------------------------

    // Pstate Options

    // @todo RTC 157943 - Corresponds to Pstate 0 .
    // Does this correspond to ATTR_FREQ_CORE_CEILING_MHZ ?
    // reference_frequency_khz

    // frequency_step_khz
    l_frequency_step_khz = (attr.attr_freq_proc_refclock_khz / attr.attr_proc_dpll_divider);
    l_globalppb.frequency_step_khz = l_frequency_step_khz;

    // VPD operating point
    //std::copy(s132a_vpd,s132a_vpd+VPD_PV_POINTS,l_globalppb.operating_points);
    FAPI_TRY(load_mvpd_operating_point(attr_mvpd_voltage_control, l_globalppb.operating_points),
             "Loading MVPD operating point failed");

    // VpdBias
    // ssrivath , proc_get_extint_bias can be easily modified to return the VpdBias structure

    l_globalppb.vdd_sysparm = l_vdd_sysparm;
    l_globalppb.vcs_sysparm = l_vcs_sysparm;
    l_globalppb.vdn_sysparm = l_vdn_sysparm;

    // safe_voltage_mv

    // safe_frequency_khz
    l_globalppb.safe_frequency_khz = attr.attr_pm_safe_frequency_mhz;

    // vrm_stepdelay_range

    // vrm_stepdelay_value

    // VDMParmBlock vdm
    // ssrivath, New function required to read attributes and populate VDM Parm block

    // -----------------------------------------------
    // Local parameter block
    // -----------------------------------------------
    l_localppb.magic = PSTATE_PARMSBLOCK_MAGIC;

    // QuadManagerFlags

    // VPD operating point
    FAPI_TRY(load_mvpd_operating_point(attr_mvpd_voltage_control, l_localppb.operating_points),
             "Loading MVPD operating point failed");

    l_localppb.vdd_sysparm = l_vdd_sysparm;

    // IvrmParmBlock
    // ClockGridMgmtInfo
    // VDMParmBlock

    // -----------------------------------------------
    // OCC parameter block
    // -----------------------------------------------
    l_occppb.magic = PSTATE_PARMSBLOCK_MAGIC;

    // VPD operating point
    FAPI_TRY(load_mvpd_operating_point(attr_mvpd_voltage_control, l_occppb.operating_points),
             "Loading MVPD operating point failed");

    l_occppb.vdd_sysparm = l_vdd_sysparm;
    l_occppb.vcs_sysparm = l_vcs_sysparm;

    // Iddq Table
    l_occppb.iddq = l_iddqt;

    //WOFElements

    // frequency_min_khz - Value from Power save operating point after biases
    l_occppb.frequency_min_khz = (attr_mvpd_voltage_control[POWERSAVE][0] / 1000);

    // frequency_max_khz - Value from Ultra Turbo operating point after biases
    l_occppb.frequency_max_khz = (attr_mvpd_voltage_control[ULTRA][0] / 1000);

    // frequency_step_khz
    l_occppb.frequency_step_khz = l_frequency_step_khz;

    // pstate_min

    // pstate_max

    // -----------------------------------------------
    // Populate Global,local and OCC parameter blocks into Pstate super structure
    // -----------------------------------------------
    (*io_pss).globalppb = l_globalppb;
    (*io_pss).localppb = l_localppb;
    (*io_pss).occppb = l_occppb;


fapi_try_exit:
    return fapi2::current_err;
#endif
    return fapi2::FAPI2_RC_SUCCESS;
}
#if 0

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------
/// \param[in]      i_target           Chip Target
/// \param[in/out]  *io_pss            Reference to PstateSuperStructure

/// \retval FAPI_RC_SUCCESS
/// \retval ERROR defined in xml

ReturnCode
p9_pstate_parameter_block(const Target& i_target,
                          PstateSuperStructure* io_pss)
{
    fapi::ReturnCode l_rc;
    int rc;

    AttributeList attr;
    ChipCharacterization* characterization;
    uint8_t i                        = 0;
    uint8_t present_chiplets         = 0;
    uint8_t functional_chiplets      = 0;
    uint8_t poundm_ver               = 0;
    uint8_t poundm_valid             =
        1;  // assume valid until code determines invalid
    uint8_t lpst_valid               =
        1;  // assume valid until code determines invalid

    uint32_t valid_pdv_points = 0;
    uint8_t attr_pm_ivrms_enabled_wr = 0;
    uint8_t attr_pm_ivrms_enabled_rd = 0;

    double volt_int_vdd_bias = 1.0;
    double volt_int_vcs_bias = 1.0;

    uint32_t frequency_step_khz = 0;
    uint32_t attr_mvpd_voltage_control[PV_D][PV_W];

    ivrm_mvpd_t   ivrm_mvpd;

    FAPI_INF("Executing p9_pstate_parameter_block ....");

    do
    {
        // -----------------------------------------------------------
        // Clear the PstateSuperStructure and install the magic number
        // -----------------------------------------------------------
        memset(io_pss, 0, sizeof(*io_pss));
        (*io_pss).magic = revle64(PSTATE_SUPERSTRUCTURE_MAGIC);

        // -------------------------
        // get all attributes needed
        // -------------------------
        FAPI_IMP("Getting Attributes to build Pstate Superstructure");

        l_rc = proc_get_attributes(i_target ,  &attr );

        if (l_rc)
        {
            break;
        }

        // calculate pstate frequency step in Khz
        frequency_step_khz = (attr.attr_freq_proc_refclock *
                              1000) / attr.attr_proc_dpll_divider;

        // --------------------------------
        // check chip ec feature attributes
        // --------------------------------
        if (attr.attr_proc_ec_core_hang_pulse_bug)
        {
            FAPI_INF("ATTR_PROC_EC_CORE_HANG_PULSE_BUG is set so disable iVRMs - setting PSTATE_NO_INSTALL_LPSA");
            (*io_pss).gpst.options.options = revle32(revle32((*io_pss).gpst.options.options)
                                             |
                                             PSTATE_NO_INSTALL_LPSA);
            poundm_valid = 0;
            lpst_valid   = 0;
        }

        if (! attr.attr_chip_ec_feature_resonant_clk_valid)
        {
            FAPI_INF("ATTR_CHIP_EC_FEATURE_RESONANT_CLK_VALID is not set so disable resonant clocking - setting PSTATE_NO_INSTALL_RESCLK");
            (*io_pss).gpst.options.options = revle32(revle32((*io_pss).gpst.options.options)
                                             |
                                             PSTATE_NO_INSTALL_RESCLK );
        }

        // ----------------
        // get #V & #M data
        // ----------------
        FAPI_IMP("Getting #V & #M Data");

        // clear array
        memset(attr_mvpd_voltage_control, 0, sizeof(attr_mvpd_voltage_control));
        memset(&ivrm_mvpd,                0, sizeof(ivrm_mvpd));

        l_rc = proc_get_mvpd_data(  i_target,
                                    &attr,
                                    attr_mvpd_voltage_control,
                                    &valid_pdv_points,
                                    &ivrm_mvpd,
                                    &present_chiplets,
                                    &functional_chiplets,
                                    &poundm_valid,
                                    &poundm_ver);

        if (l_rc)
        {
            break;
        }
        else if (!present_chiplets)
        {
            FAPI_ERR("**** ERROR : There are no cores present");
            const uint8_t& PRESENT_CHIPLETS = present_chiplets;
            const Target&  CHIP_TARGET = i_target;
            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_NO_CORES_PRESENT_ERROR);
            break;
        }

        if (!functional_chiplets || !poundm_valid)
        {

            if (!functional_chiplets)
            {
                FAPI_IMP("No FUNCTIONAL chiplets found - set PSTATE_NO_INSTALL_LPSA");
            }
            else
            {
                FAPI_IMP("Invalid #M found - set PSTATE_NO_INSTALL_LPSA");
            }

            // indicate no LPST installed in PSS
            (*io_pss).gpst.options.options = revle32(revle32((*io_pss).gpst.options.options)
                                             |
                                             PSTATE_NO_INSTALL_LPSA);
        }

        // ---------------------------------------------
        // process external and internal bias attributes
        // ---------------------------------------------
        FAPI_IMP("Apply Biasing to #V");

        l_rc = proc_get_extint_bias(attr_mvpd_voltage_control,
                                    &attr,
                                    &volt_int_vdd_bias,
                                    &volt_int_vcs_bias);

        if (l_rc)
        {
            break;
        }


        // -----------------------------------------------
        // populate VpdOperatingPoint with biased MVPD attributes
        // -----------------------------------------------
        VpdOperatingPoint s132a_vpd[VPD_PV_POINTS];

        rc = load_mvpd_operating_point (attr_mvpd_voltage_control,
                                        s132a_vpd);

        // -------------------------------------------------------------------
        // Create s132a_points and filled in by chip_characterization_create()
        // -------------------------------------------------------------------
        OperatingPoint s132a_points[VPD_PV_POINTS];

        // -------------------------------------------------
        // populate OperatingPointParameters with attributes
        // -------------------------------------------------

        OperatingPointParameters s132a_parms;
        s132a_parms.pstate0_frequency_khz = ((s132a_vpd[valid_pdv_points - 1].frequency_mhz *
                                              1000) / frequency_step_khz) *
                                            frequency_step_khz;
        // pstate0 is turbo rounded down and forced to be a multiple of freq_step_khz
        s132a_parms.frequency_step_khz    =
            frequency_step_khz;                // ATTR_REFCLK_FREQUENCY/ATTR_DPLL_DIVIDER
        s132a_parms.vdd_load_line_uohm    = attr.attr_proc_r_loadline_vdd;
        s132a_parms.vcs_load_line_uohm    = attr.attr_proc_r_loadline_vcs;
        s132a_parms.vdd_distribution_uohm = attr.attr_proc_r_distloss_vdd;
        s132a_parms.vcs_distribution_uohm = attr.attr_proc_r_distloss_vcs;
        // SW267784
        s132a_parms.vdd_voffset_uv = attr.attr_proc_vrm_voffset_vdd;
        s132a_parms.vcs_voffset_uv = attr.attr_proc_vrm_voffset_vcs;


        // --------------------------------------
        // Create Chip characterization structure
        // --------------------------------------

        ChipCharacterization s132a_characterization;
        s132a_characterization.vpd          = s132a_vpd;
        s132a_characterization.ops          = s132a_points;
        s132a_characterization.parameters   = &s132a_parms;
        s132a_characterization.points       = valid_pdv_points;
        s132a_characterization.max_cores    = present_chiplets;

        // ---------------------------
        // Finish the characterization
        // ---------------------------
        characterization = &s132a_characterization;

        rc = chip_characterization_create(characterization,
                                          characterization->vpd,
                                          characterization->ops,
                                          characterization->parameters,
                                          characterization->points);

        // check for error
        int& CHAR_RETURN_CODE = rc;

        if (rc == -GPST_INVALID_OBJECT)
        {
            FAPI_ERR("**** ERROR : chip_characterization_create was passed null pointer to characterization or characterization->parameters");
            FAPI_SET_HWP_ERROR(l_rc,
                               RC_PROCPM_PSTATE_DATABLOCK_CHARACTERIZATION_OBJECT_ERROR);
            break;
        }
        else if (rc == -GPST_INVALID_ARGUMENT)
        {
            uint32_t& POINTS  = characterization->points;
            FAPI_ERR("**** ERROR : chip_characterization_create was passed null pointer to characterization->vpd or no points");
            FAPI_SET_HWP_ERROR(l_rc,
                               RC_PROCPM_PSTATE_DATABLOCK_CHARACTERIZATION_ARGUMENT_ERROR);
            break;
        }
        else if (rc)
        {
            FAPI_ERR("**** ERROR : chip_characterization_create returned error rc = %d",
                     rc );
            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_CHARACTERIZATION_ERROR);
            break;
        }

        // Load the WOF information as this influences the generation
        // of the Pstate tables
        if (attr.attr_system_wof_enabled)
        {
            // -----------------------------------------------
            // populate WOF structure with the biased VPD information
            // -----------------------------------------------
            l_rc = load_mvpd_operating_point (attr_mvpd_voltage_control,
                                              io_pss->wof.operating_points);

            if (l_rc)
            {
                // No errors to handle at this time
            }

            // ----------------
            // get IQ (IDDQ) data and place into the Pstate SuperStructure
            // ----------------
            FAPI_IMP("Getting IQ (IDDQ) Data");

            l_rc = proc_get_mvpd_iddq(i_target, io_pss);

            if (l_rc)
            {
                // @todo add FFDC

                // Disable WOF and keep going
                FAPI_INF("**** WARNING:  While WOF was enabled via attributes, IDDQ information "
                         "for the present part could not be obtained (either due to access error "
                         "or is not present in the VPD.  WOF is being DISABLED but Pstate table "
                         "generation is continuing");
                attr.attr_system_wof_enabled = 0;

            }
            else
            {
                // -----------------------------------------------
                // populate WOF structure with the biased VPD information
                // -----------------------------------------------
                rc = load_wof_attributes (io_pss, &attr);

                if (l_rc)
                {
                    // No errors to handle at this time
                }
            }
        }


        // ------------------------------
        // Create the Global Pstate table
        // ------------------------------
        FAPI_IMP("Creating Global Pstate Table");

        rc = gpst_create(&((*io_pss).gpst),
                         characterization,
                         &((*io_pss).wof),
                         PSTATE_STEPSIZE,
                         EVRM_DELAY_NS);

        FAPI_INF("GPST vpd pmin = %d  vpd pmax = %d  vpd points = %d",
                 s132a_characterization.ops[0].pstate,
                 s132a_characterization.ops[s132a_characterization.points - 1].pstate,
                 s132a_characterization.points);
        FAPI_INF("GPST pmin = %d  entries = %u", (*io_pss).gpst.pmin,
                 (*io_pss).gpst.entries);
        FAPI_INF("GPST refclock(Mhz) = %d  pstate0_freq(Khz) = %d  frequency_step(Khz) = %d",
                 attr.attr_freq_proc_refclock, s132a_parms.pstate0_frequency_khz,
                 s132a_parms.frequency_step_khz);

        // check for error
        int& GPST_RETURN_CODE = rc;

        if (rc == -GPST_INVALID_OBJECT)
        {
            FAPI_ERR("**** ERROR : gpst_create was passed null pointer to gpst, characterization, or characterization->ops or characterization->points = 0");
            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_GPST_CREATE_OBJECT_ERROR);
            break;
        }
        else if (rc == -GPST_INVALID_ARGUMENT)
        {
            int32_t& OPS_PMIN           = s132a_characterization.ops[0].pstate;
            int32_t& OPS_PMAX           =
                s132a_characterization.ops[s132a_characterization.points - 1].pstate;
            FAPI_ERR("**** ERROR : gpst_create was passed bad argument and resulted in PSTATE limits error or operating point ordering error");
            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_GPST_CREATE_ARGUMENT_ERROR);
            break;
        }
        else if (rc == -GPST_INVALID_ENTRY)
        {
            FAPI_ERR("**** ERROR : gpst_entry_create was passed a voltage that was out of limits of vrm11 vid code or ivid vide code");
            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_GPST_CREATE_ENTRY_ERROR);
            break;
        }
        else if (rc)
        {
            FAPI_ERR("**** ERROR : gpst_create returned error rc = %d", rc );
            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_GPST_CREATE_ERROR);
            break;
        }

        // -----------------------------
        // Boost the Global Pstate table
        // -----------------------------
        FAPI_IMP("Boost Global Pstate Table per CPM Boost Attribute");

        l_rc = proc_boost_gpst (io_pss, attr.attr_cpm_turbo_boost_percent);

        if (l_rc)
        {
            break;
        }

        // --------------------------------------------------------------------
        // Setup psafe_pstate via attr_pm_safe_frequency (added per SW260812)
        // --------------------------------------------------------------------
        FAPI_INF("Setup psafe_pstate via attr_pm_safe_frequency");

        l_rc = proc_upd_psafe_ps (io_pss, &attr);

        if (l_rc)
        {
            break;
        }

        // --------------------------------------------------------------------
        // Setup pmin_clip via attr_freq_core_floor (added per SW260911)
        // --------------------------------------------------------------------
        FAPI_INF("Setup pmin_clip via attr_freq_core_floor");

        l_rc = proc_upd_floor_ps (io_pss, &attr);

        if (l_rc)
        {
            break;
        }

        // -----------------------------
        // Create the Local Pstate table
        // -----------------------------
        uint8_t vid_incr_gt7_nonreg = 0;

        if (! attr.attr_proc_ec_core_hang_pulse_bug)
        {
            FAPI_IMP("Creating Local Pstate Table");

            rc = lpst_create( &((*io_pss).gpst), &((*io_pss).lpsa), DEAD_ZONE_5MV,
                              volt_int_vdd_bias, volt_int_vcs_bias, &vid_incr_gt7_nonreg);

            int& LPST_RETURN_CODE = rc;

            if (rc == -LPST_INVALID_OBJECT)
            {
                FAPI_ERR("**** ERROR : lpst_create was passed null pointer to gpst or lpsa");
                FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_LPST_CREATE_OBJECT_ERROR);
                break;
            }
            else if (rc == -IVID_INVALID_VOLTAGE)
            {
                FAPI_ERR("**** ERROR : lpst_create attempted to convert an invalid voltage value to ivid format (GT 1.39375V or LT 0.6V");
                FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_LPST_CREATE_IVID_ERROR);
                break;
            }
            else if (rc == -LPST_INCR_CLIP_ERROR)
            {
                FAPI_ERR("**** ERROR : lpst_create encountered a vid increment > 7 in regulation");
                FAPI_SET_HWP_ERROR(l_rc,
                                   RC_PROCPM_PSTATE_DATABLOCK_LPST_CREATE_VID_INCR_CLIP_INREG_ERROR);
                break;
            }
            else if (rc == -LPST_GPST_WARNING)
            {
                FAPI_IMP("No Local Pstate Generated  - Global Pstate Table is completely within Deadzone - set PSTATE_NO_INSTALL_LPSA" );

                // indicate no LPST installed in PSS
                (*io_pss).gpst.options.options = revle32(revle32((*io_pss).gpst.options.options)
                                                 |
                                                 PSTATE_NO_INSTALL_LPSA);
                lpst_valid = 0;
            }
            else if (rc)
            {
                FAPI_ERR("**** ERROR : lpst_create returned error rc = %d", rc );
                FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_LPST_CREATE_ERROR);
                break;
            }

            // display warning message if this condition occurs
            if (vid_incr_gt7_nonreg)
            {
                FAPI_IMP("Warning : vid increment field was > 7 in non-regulation - clipped to 7 in lpst");
            }

        }

        // -----------------------
        // Create VDS & VIN tables
        // -----------------------
        FAPI_IMP("Create VDS & VIN Tables");

        ivrm_parm_data_t        ivrm_parms;

        // Set defaults
        ivrm_parms.vin_min                   = 600;        // Minimum input voltage
        ivrm_parms.vin_max                   = 1375;       // Maximum input voltage
        ivrm_parms.vin_table_step_size       = 25;         // Granularity of Vin table entries
        ivrm_parms.vin_table_setsperrow      = 4;          // Vin sets per Vds row
        ivrm_parms.vin_table_pfetstrperset   = 8;          // PFET Strength values per Vin set
        ivrm_parms.vout_min                  = 600;        // Minimum regulated output voltage
        ivrm_parms.vout_max                  = 1200;       // Maximum regulated output voltage
        ivrm_parms.vin_entries_per_vds       = 32;         // Vin array entries per vds region
        ivrm_parms.vds_min_range_upper_bound = 100;        // Starting point for vds regions
        ivrm_parms.vds_step_percent          = 25;         // vds region step muliplier
        ivrm_parms.vds_region_entries        = 16;         // vds region array entries (in hardware)
        ivrm_parms.pfetstr_default           = 0x11;       // Default PFET Strength with no calibration
        ivrm_parms.positive_guardband        = 11;         // Plus side guardband (%)
        ivrm_parms.negative_guardband        = 6;          // Negative side guardband (%)
        ivrm_parms.number_of_coefficients    = 4;          // Number of coefficents in cal data
        ivrm_parms.force_pfetstr_values      = 1;          // 0 - calculated; 1 = forced
        ivrm_parms.forced_pfetstr_value      = 0x03;

        // create vds
        build_vds_region_table(&ivrm_parms, io_pss);

        // loop over chiplets and find ones with valid data
        // break after first valid chiplet since superstructure does not handle separate vin table for each chiplet
        for (i = 0; i < CHIPLETS; i++)
        {

            if (ivrm_mvpd.data.ex[i].point_valid > 0)
            {

                // perform least squares fit to get coefficients & then fill in VIN table
                fit_file(ivrm_parms.number_of_coefficients,
                         ivrm_mvpd.header.version,
                         ivrm_mvpd.data.ex[i].Coef,
                         &(ivrm_mvpd.data.ex[i]) );

                write_HWtab_bin(&ivrm_parms,
                                ivrm_mvpd.data.ex[i].Coef,
                                io_pss);
                break;
            }
        }

        // ---------------------------------------
        // Update CPM Range info in Superstructure
        // ---------------------------------------
        FAPI_IMP("Creating CPM Range Table");

        l_rc = proc_upd_cpmrange (io_pss, &attr);

        if (l_rc)
        {
            break;
        }

        // -----------------------------------------------
        // Update Resonant Clocking info in Superstructure
        // -----------------------------------------------
        if (attr.attr_chip_ec_feature_resonant_clk_valid)
        {
            FAPI_IMP("Creating Resonant Clocking Band Table");

            l_rc = proc_res_clock (io_pss, &attr);

            if (l_rc)
            {
                break;
            }
        }

        // ------------------------
        // Force optional overrides
        // ------------------------
        FAPI_INF(" Set PSTATE_FORCE_INITIAL_PMIN in GPST control options");
        (*io_pss).gpst.options.options = revle32(revle32((*io_pss).gpst.options.options)
                                         | PSTATE_FORCE_INITIAL_PMIN);
        FAPI_INF(" GPST control options mask is now: [%x].",
                 (*io_pss).gpst.options.options);

        //  -------------------
        //  Attributes to write
        //  -------------------
        //  uint32_t ATTR_PM_PSTATE0_FREQUENCY // Binary in Khz
        FAPI_IMP("Writing Attribute Values");

        // check if IVRMs should be enabled
        if (poundm_valid && lpst_valid
            &&                              // IVRMs should be enabled based on VPD findings
            attr.attr_pm_system_ivrms_enabled &&                       // Allowed by system
            (attr.attr_pm_system_ivrm_vpd_min_level != 0)
            &&           // Attribute has a valid value
            (attr.attr_pm_system_ivrm_vpd_min_level >= poundm_ver)
            &&  // Hardware characterized
            attr.attr_chip_ec_feature_ivrm_winkle_bug)                 // Hardware has logic fixes
        {
            attr_pm_ivrms_enabled_wr = 1;
        }
        else
        {
            attr_pm_ivrms_enabled_wr = 0;
            FAPI_INF(" ATTR_PM_IVRMS_ENABLED will be set to 0 - set PSTATE_NO_INSTALL_LPSA");
            // indicate no LPST installed in PSS
            (*io_pss).gpst.options.options = revle32(revle32((*io_pss).gpst.options.options)
                                             |
                                             PSTATE_NO_INSTALL_LPSA);
        }

        // write ATTR_PM_IVRMS_ENABLED
        SETATTR(l_rc, ATTR_PM_IVRMS_ENABLED, "ATTR_PM_IVRMS_ENABLED", &i_target,
                attr_pm_ivrms_enabled_wr);

        // Read back attribute to see if overridden
        GETATTR (l_rc, ATTR_PM_IVRMS_ENABLED, "ATTR_PM_IVRMS_ENABLED", &i_target,
                 attr_pm_ivrms_enabled_rd);

        if (attr_pm_ivrms_enabled_rd && !attr_pm_ivrms_enabled_wr)
        {
            FAPI_INF("WARNING : Attribute ATTR_PM_IVRMS_ENABLED was overridden to 1, but #V or #M data is not valid for IVRMs");
        }
        else if (!attr_pm_ivrms_enabled_rd && attr_pm_ivrms_enabled_wr)
        {
            FAPI_INF("WARNING : ATTR_PM_IVRMS_ENABLED was overriden to 0, but #V or #M data are valid - set PSTATE_NO_INSTALL_LPSA");
            // indicate no LPST installed in PSS
            (*io_pss).gpst.options.options = revle32(revle32((*io_pss).gpst.options.options)
                                             |
                                             PSTATE_NO_INSTALL_LPSA);
        }

    }
    while(0);

    return l_rc;
} // end p9_pstate_parameter_block
#endif
// ssrivath END OF PSTATE PARAMETER BLOCK function

// ssrivath START OF GET ATTRIBUTES function


fapi2::ReturnCode
proc_get_attributes ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                      AttributeList* io_attr)
{
    do
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

#if 0
        // @todo RTC 157943 - Check if below macro code is required in P9 and if so check implementation- ssrivath
        // This macro is in place to to deal with the movement of attribute placement
        // from SYSTEM to PROC_CHIP per SW298278 while allowing for this procedure
        // to still operate in system that continue store attributes at the SYSTEM level.
        // This is done by trying the passed target first; if it doesn't succeed, the
        // SYSTEM level is attempted.  Failure of both will cause a break.

        // @todo RTC 157943 - Below is P8 implementation, Check need in P9
#define DATABLOCK_GET_ATTR_CHECK_PROC(attr_name, target, attr_assign) \
    l_rc = FAPI_ATTR_GET(attr_name, target, io_attr->attr_assign); \
    if (!l_rc) { \
        FAPI_INF("%-60s = 0x%08x %u from PROC_CHIP target", #attr_name, io_attr->attr_assign, io_attr->attr_assign); \
    } \
    else { \
        FAPI_INF("Accessing %s as the passed target did not succeed.  Trying from the SYSTEM target", #attr_name); \
        l_rc = FAPI_ATTR_GET(attr_name, NULL, io_attr->attr_assign); \
        if (!l_rc) { \
            FAPI_INF("%-60s = 0x%08x %u from SYSTEM target", #attr_name, io_attr->attr_assign, io_attr->attr_assign); \
        } \
        else { \
            FAPI_ERR("%-60s access failed after trying both PROC_CHIP and SYSTEM targets", #attr_name ); \
            break; \
        } \
    }
#endif

#define DATABLOCK_GET_ATTR_CHECK_PROC(attr_name, target, attr_assign) \
    FAPI_TRY(FAPI_ATTR_GET(fapi2::attr_name, target, io_attr->attr_assign),"Attribute read failed"); \
    FAPI_INF("%-60s = 0x%08x %u from PROC_CHIP target", #attr_name, io_attr->attr_assign, io_attr->attr_assign); \


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
    DATABLOCK_GET_ATTR(ATTR_FREQ_CORE_CEILING_MHZ, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), attr_freq_core_ceiling_mhz);
    DATABLOCK_GET_ATTR(ATTR_PM_SAFE_FREQUENCY_MHZ, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), attr_pm_safe_frequency_mhz);
    DATABLOCK_GET_ATTR(ATTR_FREQ_CORE_FLOOR_MHZ, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), attr_freq_core_floor_mhz);
    DATABLOCK_GET_ATTR(ATTR_BOOT_FREQ_MHZ, i_target, attr_boot_freq_mhz);

// Loadline, Distribution loss and Distribution offset attributes
    DATABLOCK_GET_ATTR_CHECK_PROC(ATTR_PROC_R_LOADLINE_VDD_UOHM, i_target, attr_proc_r_loadline_vdd_uohm);
    DATABLOCK_GET_ATTR_CHECK_PROC(ATTR_PROC_R_DISTLOSS_VDD_UOHM, i_target, attr_proc_r_distloss_vdd_uohm);
    DATABLOCK_GET_ATTR_CHECK_PROC(ATTR_PROC_VRM_VOFFSET_VDD_UV, i_target, attr_proc_vrm_voffset_vdd_uv);
    DATABLOCK_GET_ATTR_CHECK_PROC(ATTR_PROC_R_LOADLINE_VDN_UOHM, i_target, attr_proc_r_loadline_vdn_uohm);
    DATABLOCK_GET_ATTR_CHECK_PROC(ATTR_PROC_R_DISTLOSS_VDN_UOHM, i_target, attr_proc_r_distloss_vdn_uohm);
    DATABLOCK_GET_ATTR_CHECK_PROC(ATTR_PROC_VRM_VOFFSET_VDN_UV, i_target, attr_proc_vrm_voffset_vdn_uv);
    DATABLOCK_GET_ATTR_CHECK_PROC(ATTR_PROC_R_LOADLINE_VCS_UOHM, i_target, attr_proc_r_loadline_vcs_uohm);
    DATABLOCK_GET_ATTR_CHECK_PROC(ATTR_PROC_R_DISTLOSS_VCS_UOHM, i_target, attr_proc_r_distloss_vcs_uohm);
    DATABLOCK_GET_ATTR_CHECK_PROC(ATTR_PROC_VRM_VOFFSET_VCS_UV, i_target, attr_proc_vrm_voffset_vcs_uv);


// ssrivath, P9 resclk attributes to be defined
//Resonant clocking attributes
//    DATABLOCK_GET_ATTR(ATTR_PM_RESONANT_CLOCK_FULL_CLOCK_SECTOR_BUFFER_FREQUENCY_KHZ,
//                       fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), attr_pm_resonant_clock_full_clock_sector_buffer_frequency_khz);
//    DATABLOCK_GET_ATTR(ATTR_PM_RESONANT_CLOCK_LOW_BAND_LOWER_FREQUENCY_KHZ,
//                       fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), attr_pm_resonant_clock_low_band_lower_frequency_khz);
//    DATABLOCK_GET_ATTR(ATTR_PM_RESONANT_CLOCK_LOW_BAND_UPPER_FREQUENCY_KHZ,
//                       fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), attr_pm_resonant_clock_low_band_upper_frequency_khz);
//    DATABLOCK_GET_ATTR(ATTR_PM_RESONANT_CLOCK_HIGH_BAND_LOWER_FREQUENCY_KHZ,
//                       fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), attr_pm_resonant_clock_high_band_lower_frequency_khz);
//    DATABLOCK_GET_ATTR(ATTR_PM_RESONANT_CLOCK_HIGH_BAND_UPPER_FREQUENCY_KHZ,
//                       fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), attr_pm_resonant_clock_high_band_upper_frequency_khz);

    // Read IVRM attributes
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_IVRMS_ENABLED, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                       attr_system_ivrms_enabled);
    // Read WOF attributes
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_WOF_ENABLED, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                       attr_system_wof_enabled);

    DATABLOCK_GET_ATTR(ATTR_TDP_RDP_CURRENT_FACTOR, i_target,
                       attr_tdp_rdp_current_factor);

    // --------------------------------------------------------------
    // do basic attribute value checking and generate error if needed
    // --------------------------------------------------------------

    //check that dpll_divider is not 0
    if (io_attr->attr_proc_dpll_divider == 0)
    {
        FAPI_ERR("**** ERROR : Attribute ATTR_PROC_DPLL_DIVIDER = 0");
        //@TODO - L3, FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_ATTR_DPLL_DIV_ERROR);
        break;
    }


// Biasing checks either not required or need to be different in P9
#if 0

    // ----------------------------------------------------
    // Check Valid Frequency and Voltage Biasing Attributes
    //  - cannot have both up and down bias set
    // ----------------------------------------------------
    if (io_attr->attr_freq_ext_bias_up > 0 && io_attr->attr_freq_ext_bias_down > 0)
    {
        FAPI_ERR("**** ERROR : Frequency bias up and down both defined");
        FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_FREQ_BIAS_ERROR);
        break;
    }

    if (io_attr->attr_voltage_ext_vdd_bias_up > 0
        && io_attr->attr_voltage_ext_vdd_bias_down > 0)
    {
        FAPI_ERR("**** ERROR : External voltage bias up and down both defined");
        FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_EXT_VDD_VOLTAGE_BIAS_ERROR);
        break;
    }

    if (io_attr->attr_voltage_ext_vcs_bias_up > 0
        && io_attr->attr_voltage_ext_vcs_bias_down > 0)
    {
        FAPI_ERR("**** ERROR : External voltage bias up and down both defined");
        FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_EXT_VCS_VOLTAGE_BIAS_ERROR);
        break;
    }

    if (io_attr->attr_voltage_int_vdd_bias_up > 0
        && io_attr->attr_voltage_int_vdd_bias_down > 0)
    {
        FAPI_ERR("**** ERROR : Internal voltage bias up and down both defined");
        FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_INT_VDD_VOLTAGE_BIAS_ERROR);
        break;
    }

    if (io_attr->attr_voltage_int_vcs_bias_up > 0
        && io_attr->attr_voltage_int_vcs_bias_down > 0)
    {
        FAPI_ERR("**** ERROR : Internal voltage bias up and down both defined");
        FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_INT_VCS_VOLTAGE_BIAS_ERROR);
        break;
    }

    // print debug message if double biasing is enabled
    if ( (io_attr->attr_voltage_ext_vdd_bias_up + io_attr->attr_voltage_ext_vdd_bias_down
          > 0) &&
         (io_attr->attr_voltage_int_vdd_bias_up + io_attr->attr_voltage_int_vdd_bias_down >
          0) )
    {
        FAPI_INF("Double Biasing enabled on external and internal VDD");
    }

    if ( (io_attr->attr_voltage_ext_vcs_bias_up + io_attr->attr_voltage_ext_vcs_bias_down
          > 0) &&
         (io_attr->attr_voltage_int_vcs_bias_up + io_attr->attr_voltage_int_vcs_bias_down >
          0) )
    {
        FAPI_INF("Double Biasing enabled on external and internal VCS");
    }

#endif


    // ssrivath, @todo RTC 157943 - Resclk checks need definition in P9
    // check resonant clocking attribute values relative to each other
    //if (io_attr->attr_chip_ec_feature_resonant_clk_valid)
    //{
    //if ( (io_attr->attr_pm_resonant_clock_low_band_lower_frequency_khz  >
    //      io_attr->attr_pm_resonant_clock_low_band_upper_frequency_khz) ||
    //     (io_attr->attr_pm_resonant_clock_low_band_upper_frequency_khz  >
    //      io_attr->attr_pm_resonant_clock_high_band_lower_frequency_khz) ||
    //     (io_attr->attr_pm_resonant_clock_high_band_lower_frequency_khz >
    //      io_attr->attr_pm_resonant_clock_high_band_upper_frequency_khz) )
    //{
    //    //@TODO - L3 const uint32_t &PM_RES_CLOCK_LOW_BAND_LOWER_FREQ =
    //    //@TODO - L3     io_attr->attr_pm_resonant_clock_low_band_lower_frequency;
    //    //@TODO - L3 const uint32_t &PM_RES_CLOCK_LOW_BAND_UPPER_FREQ =
    //    //@TODO - L3     io_attr->attr_pm_resonant_clock_low_band_upper_frequency;
    //    //@TODO - L3 const uint32_t &PM_RES_CLOCK_HIGH_BAND_LOWER_FREQ =
    //    //@TODO - L3     io_attr->attr_pm_resonant_clock_high_band_lower_frequency;
    //    //@TODO - L3 const uint32_t &PM_RES_CLOCK_HIGH_BAND_UPPER_FREQ =
    //    //@TODO - L3     io_attr->attr_pm_resonant_clock_high_band_upper_frequency;
    //    FAPI_ERR("**** ERROR : Resonant clocking band attribute values are not in ascending order from low to high");
    //    //@TODO - L3 FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_RESCLK_BAND_ERROR);
    //    break;
    //}

    //}
    //

    // ------------------------------------------------------
    // do attribute default value setting if the are set to 0
    // ------------------------------------------------------
    if (io_attr->attr_freq_proc_refclock_khz == 0)
    {
        io_attr->attr_freq_proc_refclock_khz = 133;
        FAPI_INF("Attribute value was 0 - setting to default value ATTR_FREQ_PROC_REFCLOCK_KHZ = 133");
    }

    if (io_attr->attr_proc_dpll_divider == 0)
    {
        io_attr->attr_proc_dpll_divider = 8;
        FAPI_INF("Attribute value was 0 - setting to default value ATTR_PROC_DPLL_DIVIDER = 8");
    }

    if (io_attr->attr_pm_safe_frequency_mhz  == 0)
    {
        io_attr->attr_pm_safe_frequency_mhz = io_attr->attr_boot_freq_mhz;
        FAPI_INF("Attribute value was 0 - setting to default value ATTR_PM_SAFE_FREQUENCY_MHZ = ATTR_BOOT_FREQ_MHZ");
    }

    // @todo RTC 157943 - Loadline/Distloss defaults values need to be defined for P9
    if (io_attr->attr_proc_r_loadline_vdd_uohm == 0)
    {
        io_attr->attr_proc_r_loadline_vdd_uohm = 570;
        FAPI_INF("Attribute value was 0 - setting to default value ATTR_PROC_R_LOADLINE_VDD_UOHM = 570");
    }

    if (io_attr->attr_proc_r_loadline_vcs_uohm == 0)
    {
        io_attr->attr_proc_r_loadline_vcs_uohm = 570;
        FAPI_INF("Attribute value was 0 - setting to default value ATTR_PROC_R_LOADLINE_VCS_UOHM = 570");
    }

    if (io_attr->attr_proc_r_distloss_vdd_uohm == 0)
    {
        io_attr->attr_proc_r_distloss_vdd_uohm = 390;
        FAPI_INF("Attribute value was 0 - setting to default value ATTR_PROC_R_DISTLOSS_VDD_UOHM = 390");
    }

    if (io_attr->attr_proc_r_distloss_vcs_uohm == 0)
    {
        io_attr->attr_proc_r_distloss_vcs_uohm = 3500;
        FAPI_INF("Attribute value was 0 - setting to default value ATTR_PROC_R_DISTLOSS_VCS_UOHM = 3500");
    }

}
while(0);

fapi_try_exit:
return fapi2::current_err;

}


// ssrivath END OF GET ATTRIBUTES function

/// ssrivath START OF MVPD DATA FUNCTION

fapi2::ReturnCode
proc_get_mvpd_data(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                   const AttributeList* i_attr,
                   uint32_t      o_attr_mvpd_data[PV_D][PV_W],
                   uint32_t*     o_valid_pdv_points,
                   uint8_t*      o_present_chiplets
                  )
{

std::vector<fapi2::Target<fapi2::TARGET_TYPE_EQ>> l_eqChiplets;
uint8_t*   l_buffer         =  reinterpret_cast<uint8_t*>(malloc(PDV_BUFFER_ALLOC) );
uint8_t*   l_buffer_inc;
uint32_t   l_bufferSize     = 512;
uint32_t   l_record         = 0;
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

        l_bufferSize      = 512;
        uint8_t l_chipNum = 0xFF;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_eqChiplets[j], l_chipNum));

        FAPI_INF("Chip Number => %u", l_chipNum);

        // set l_record to appropriate lprx record (add quad number to lrp0)
        l_record = (uint32_t)fapi2::MVPD_RECORD_LRP0 + l_chipNum;

        FAPI_INF("Record Number => %u", l_record);
        // clear out buffer to known value before calling fapiGetMvpdField
        memset(l_buffer, 0, 512);

        // Get Chiplet MVPD data and put in chiplet_mvpd_data using accessor function
        FAPI_TRY(getMvpdField((fapi2::MvpdRecord)l_record,
                              fapi2::MVPD_KEYWORD_PDV,
                              i_target,
                              l_buffer,
                              l_bufferSize));

        // check buffer size
        if (l_bufferSize < PDV_BUFFER_SIZE)
        {
            FAPI_ERR("**** ERROR : Wrong size buffer returned from fapiGetMvpdField for #V => %d",
                     l_bufferSize );
            // @todo-L3
            //const uint32_t &BUFFER_SIZE = l_bufferSize;
            //const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& CHIP_TARGET= i_target;
            //FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_PDV_BUFFER_SIZE_ERROR);
            break;
        }

        // clear array
        memset(chiplet_mvpd_data, 0, sizeof(chiplet_mvpd_data));

        // fill chiplet_mvpd_data 2d array with data iN buffer (skip first byte - bucket id)
#define UINT16_GET(__uint8_ptr)   ((uint16_t)( ( (*((const uint8_t *)(__uint8_ptr)) << 8) | *((const uint8_t *)(__uint8_ptr) + 1) ) ))

        // use copy of allocated buffer pointer to increment through buffer
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

        //@todo-L3 perform data validity checks on this #V data before proceeding to use it
        //l_rc = proc_chk_valid_poundv(   i_target,
        //                                i_attr,
        //                                chiplet_mvpd_data,
        //                                o_valid_pdv_points,
        //                                l_chipNum,
        //                                bucket_id);

        FAPI_TRY(proc_chk_valid_poundv( i_target,
                                        i_attr,
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
/// ssrivath END OF MVPD DATA FUNCTION

/// ssrivath START OF IDDQ READ FUNCTION

fapi2::ReturnCode
proc_get_mvpd_iddq( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                    IddqTable* io_iddqt)
{

uint8_t* l_buffer_iq_c =  reinterpret_cast<uint8_t*>(malloc(IQ_BUFFER_ALLOC));
uint32_t l_record         = 0;
uint8_t* l_buffer_iq_inc;
uint32_t l_bufferSize_iq  = IQ_BUFFER_ALLOC;
uint8_t  i, j;
uint8_t  l_buffer_data;
iddq_entry_t l_iddq_data;
avgtemp_entry_t l_avgtemp_data;

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
    FAPI_INF("  IDDQ Version Number = %u", l_good_quads_per_sort);
    l_buffer_iq_inc++;

    // get number of normal cores per sort
    uint8_t l_good_normal_cores_per_sort = *l_buffer_iq_inc;
    io_iddqt->good_normal_cores_per_sort = l_good_normal_cores_per_sort ;
    FAPI_INF("  IDDQ Version Number = %u", l_good_normal_cores_per_sort);
    l_buffer_iq_inc++;

    // get number of good caches per sort
    uint8_t l_good_caches_per_sort = *l_buffer_iq_inc;
    io_iddqt->good_caches_per_sort = l_good_caches_per_sort ;
    FAPI_INF("  IDDQ Version Number = %u", l_good_caches_per_sort);
    l_buffer_iq_inc++;

    // get number of good normal cores in each quad
    for (i = 0; i < MAX_QUADS; i++)
    {
        l_buffer_data = *l_buffer_iq_inc;
        io_iddqt->good_normal_cores[i] = l_buffer_data;
        FAPI_INF("Num of good normal cores in quad %d = %u", i, l_buffer_data);
        l_buffer_iq_inc++;
    }

    // get number of good caches in each quad
    for (i = 0; i < MAX_QUADS; i++)
    {
        l_buffer_data = *l_buffer_iq_inc;
        io_iddqt->good_caches[i] = l_buffer_data;
        FAPI_INF("Num of good caches in quad %d = %u", i, l_buffer_data);
        l_buffer_iq_inc++;
    }

    // get RDP TO TDP scalling factor
    uint16_t l_rdp_to_tdp_scale_factor = *(reinterpret_cast<uint16_t*>(l_buffer_iq_inc));
    io_iddqt->rdp_to_tdp_scale_factor = l_rdp_to_tdp_scale_factor;
    FAPI_INF("RDP TO TDP scalling factor = %u", l_rdp_to_tdp_scale_factor );
    l_buffer_iq_inc += 2;

    // get WOF IDDQ margin factor
    uint16_t l_wof_iddq_margin_factor = *(reinterpret_cast<uint16_t*>(l_buffer_iq_inc));
    io_iddqt->wof_iddq_margin_factor = l_wof_iddq_margin_factor;
    FAPI_INF(" WOF IDDQ margin factor = %u", l_wof_iddq_margin_factor);
    l_buffer_iq_inc += 2;

    // get Temperature scaling factor
    uint16_t l_temperature_scale_factor = *(reinterpret_cast<uint16_t*>(l_buffer_iq_inc));
    io_iddqt->temperature_scale_factor = l_temperature_scale_factor;
    FAPI_INF("Temperature scaling factor %u", l_temperature_scale_factor);
    l_buffer_iq_inc += 2;

    // get spare data
    FAPI_INF("10 bytes of spare data");

    for (i = 0; i < 9; i++)
    {
        l_buffer_data = *l_buffer_iq_inc;
        io_iddqt->spare[i] = l_buffer_data;
        l_buffer_iq_inc++;
    }

    // get IVDDQ measurements with all good cores ON
    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        l_iddq_data = *(reinterpret_cast<iddq_entry_t*>(l_buffer_iq_inc));
        io_iddqt->ivdd_all_good_cores_on[i] = l_iddq_data;
        FAPI_INF(" IVDDQ with all good cores ON, Measurement %d = %u", i, l_iddq_data);
        l_buffer_iq_inc += sizeof(iddq_entry_t);
    }

    // get IVDDQ measurements with all cores and caches OFF
    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        l_iddq_data = *(reinterpret_cast<iddq_entry_t*>(l_buffer_iq_inc));
        io_iddqt->ivdd_all_cores_off[i] = l_iddq_data;
        FAPI_INF("IVDDQ with all cores and caches OFF, Measurement %d = %u", i, l_iddq_data);
        l_buffer_iq_inc += sizeof(iddq_entry_t);
    }

    // get IVDDQ measurements with all good cores OFF and caches ON
    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        l_iddq_data = *(reinterpret_cast<iddq_entry_t*>(l_buffer_iq_inc));
        io_iddqt->ivdd_all_good_cores_off[i] = l_iddq_data;
        FAPI_INF("IVDDQ with all good cores OFF and caches ON, Measurement %d = %u", i, l_iddq_data);
        l_buffer_iq_inc += sizeof(iddq_entry_t);
    }

    // get IVDDQ measurements with all good cores in each quad
    for (i = 0; i < MAX_QUADS; i++)
    {
        for (j = 0; j < IDDQ_MEASUREMENTS; j++)
        {
            l_iddq_data = *(reinterpret_cast<iddq_entry_t*>(l_buffer_iq_inc));
            io_iddqt->ivdd_quad_good_cores_on[i][j] = l_iddq_data;
            FAPI_INF(" IVDDQ will all good cores ON , Quad %d, Measurement %d = %u", i, j, l_iddq_data);
            l_buffer_iq_inc += sizeof(iddq_entry_t);
        }
    }

    // get IVDN data
    l_iddq_data = *(reinterpret_cast<iddq_entry_t*>(l_buffer_iq_inc));
    io_iddqt->ivdn = l_iddq_data;
    FAPI_INF("IVDN data = %u", l_iddq_data);
    l_buffer_iq_inc += sizeof(iddq_entry_t);

    // get average temperature measurements with all good cores ON
    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        l_avgtemp_data = *(reinterpret_cast<avgtemp_entry_t*>(l_buffer_iq_inc));
        io_iddqt->avgtemp_all_good_cores_on[i] = l_avgtemp_data;
        FAPI_INF("Average temperature with all good cores ON, Measurement %d = %u", i, l_avgtemp_data);
        l_buffer_iq_inc += sizeof(avgtemp_entry_t);
    }

    // get average temperature measurements with all cores and caches OFF
    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        l_avgtemp_data = *(reinterpret_cast<avgtemp_entry_t*>(l_buffer_iq_inc));
        io_iddqt->avgtemp_all_cores_off_caches_off[i] = l_avgtemp_data;
        FAPI_INF("Average temperature with all cores and caches OFF, Measurement %d = %u", i, l_avgtemp_data);
        l_buffer_iq_inc += sizeof(avgtemp_entry_t);
    }

    // get average temperature measurements with all good cores OFF and caches ON
    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        l_avgtemp_data = *(reinterpret_cast<avgtemp_entry_t*>(l_buffer_iq_inc));
        io_iddqt->avgtemp_all_good_cores_off[i] = l_avgtemp_data;
        FAPI_INF("Average temperature with all good cores OFF and caches ON, Measurement %d = %u", i, l_avgtemp_data);
        l_buffer_iq_inc += sizeof(avgtemp_entry_t);
    }

    // get average temperature measurements with all good cores in each quad
    for (i = 0; i < MAX_QUADS; i++)
    {
        for (j = 0; j < IDDQ_MEASUREMENTS; j++)
        {
            l_avgtemp_data = *(reinterpret_cast<avgtemp_entry_t*>(l_buffer_iq_inc));
            io_iddqt->avgtemp_quad_good_cores_on[i][j] = l_avgtemp_data;
            FAPI_INF(" Average temperature will all good cores ON , Quad %d, Measurement %d = %u", i, j, l_avgtemp_data);
            l_buffer_iq_inc += sizeof(avgtemp_entry_t);
        }
    }

    // get average temperature VDN data
    l_avgtemp_data = *(reinterpret_cast<avgtemp_entry_t*>(l_buffer_iq_inc));
    io_iddqt->avgtemp_vdn = l_avgtemp_data;
    FAPI_INF(" Average temperature VDN data = %u", l_avgtemp_data);
}
while(0);

// Free up memory buffer
free(l_buffer_iq_c);

fapi_try_exit:
return fapi2::current_err;
} // proc_get_mvdp_iddq

/// ssrivath END OF IDDQ READ FUNCTION
//
/// ssrivath START OF BIAS APPLICATION FUNCTION

fapi2::ReturnCode
proc_get_extint_bias( uint32_t io_attr_mvpd_data[PV_D][PV_W],
                      const AttributeList* i_attr,
                      double* io_volt_int_vdd_bias,
                      double* io_volt_int_vcs_bias)
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
double voltage_ext_vcs_bias;
double voltage_ext_vdn_bias;
//double voltage_ext_int_vdd_bias;


freq_bias_ultraturbo = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_freq_bias_ultraturbo);
freq_bias_turbo = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_freq_bias_turbo);
freq_bias_nominal = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_freq_bias_nominal);
freq_bias_powersave = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_freq_bias_powersave);
voltage_ext_vdd_bias_ultraturbo = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_voltage_ext_vdd_bias_ultraturbo);
voltage_ext_vdd_bias_turbo = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_voltage_ext_vdd_bias_turbo);
voltage_ext_vdd_bias_nominal = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_voltage_ext_vdd_bias_nominal);
voltage_ext_vdd_bias_powersave = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_voltage_ext_vdd_bias_powersave);

// @todo RTC 157943 - Should VCS bias be applied to all operating points ?
voltage_ext_vcs_bias = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_voltage_ext_vcs_bias);

// @todo RTC 157943 - VDN bias corresponds to Power Bus operating point ?
voltage_ext_vdn_bias = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_voltage_ext_vdn_bias);

// @todo RTC 157943 - Where should we apply int_vdd bias ?
//voltage_int_vdd_bias = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_voltage_int_vdd_bias);

// Nominal frequency operating point
io_attr_mvpd_data[0][0] = (uint32_t) ((( (double)io_attr_mvpd_data[0][0]) * freq_bias_nominal));
io_attr_mvpd_data[0][1] = (uint32_t) ((( (double)io_attr_mvpd_data[0][1]) * voltage_ext_vdd_bias_nominal));
io_attr_mvpd_data[0][3] = (uint32_t) ((( (double)io_attr_mvpd_data[0][3]) * voltage_ext_vcs_bias));

// Power Save frequency operating point
io_attr_mvpd_data[1][0] = (uint32_t) ((( (double)io_attr_mvpd_data[1][0]) * freq_bias_powersave));
io_attr_mvpd_data[1][1] = (uint32_t) ((( (double)io_attr_mvpd_data[1][1]) * voltage_ext_vdd_bias_powersave));
io_attr_mvpd_data[1][3] = (uint32_t) ((( (double)io_attr_mvpd_data[1][3]) * voltage_ext_vcs_bias));

// Turbo frequency operating point
io_attr_mvpd_data[2][0] = (uint32_t) ((( (double)io_attr_mvpd_data[2][0]) * freq_bias_turbo));
io_attr_mvpd_data[2][1] = (uint32_t) ((( (double)io_attr_mvpd_data[2][1]) * voltage_ext_vdd_bias_turbo));
io_attr_mvpd_data[2][3] = (uint32_t) ((( (double)io_attr_mvpd_data[2][3]) * voltage_ext_vcs_bias));

// Ultraturbo frequency operating point
io_attr_mvpd_data[3][0] = (uint32_t) ((( (double)io_attr_mvpd_data[3][0]) * freq_bias_ultraturbo));
io_attr_mvpd_data[3][1] = (uint32_t) ((( (double)io_attr_mvpd_data[3][1]) * voltage_ext_vdd_bias_ultraturbo));
io_attr_mvpd_data[3][3] = (uint32_t) ((( (double)io_attr_mvpd_data[3][3]) * voltage_ext_vcs_bias));

// Power bus operating point
io_attr_mvpd_data[4][1] = (uint32_t) ((( (double)io_attr_mvpd_data[4][1]) * voltage_ext_vdn_bias));

// --------------------------------------------------------------------------
// Apply specified Frequency and Voltage Biasing to i_attr_mvpd_voltage_control
//   - at least one bias value is guaranteed to be 0
//   - convert freq/voltage to double
//   - compute biased freq/voltage and round
//   - convert back to integer
// --------------------------------------------------------------------------
//

// ssrivath - Start of P8 Code
//freq_bias          = 1.0 + (BIAS_PCT_UNIT * (double)i_attr->attr_freq_ext_bias_up)
//                     - (BIAS_PCT_UNIT * (double)i_attr->attr_freq_ext_bias_down);
//volt_ext_vdd_bias  = 1.0 + (BIAS_PCT_UNIT * (double)
//                            i_attr->attr_voltage_ext_vdd_bias_up) - (BIAS_PCT_UNIT * (double)
//                                    i_attr->attr_voltage_ext_vdd_bias_down);
//volt_ext_vcs_bias  = 1.0 + (BIAS_PCT_UNIT * (double)
//                            i_attr->attr_voltage_ext_vcs_bias_up) - (BIAS_PCT_UNIT * (double)
//                                    i_attr->attr_voltage_ext_vcs_bias_down);
//*io_volt_int_vdd_bias = 1.0 + (BIAS_PCT_UNIT * (double)
//                            i_attr->attr_voltage_int_vdd_bias_up) - (BIAS_PCT_UNIT * (double)
//                                    i_attr->attr_voltage_int_vdd_bias_down);
//*io_volt_int_vcs_bias = 1.0 + (BIAS_PCT_UNIT * (double)
//                            i_attr->attr_voltage_int_vcs_bias_up) - (BIAS_PCT_UNIT * (double)
//                                    i_attr->attr_voltage_int_vcs_bias_down);

//// loop over each operating point
//for (i=0; i <= 4; i++)
//{
//    io_attr_mvpd_data[i][0] = (uint32_t) ((( (double)io_attr_mvpd_data[i][0]) * freq_bias)
//                                       + 0.5);
//    io_attr_mvpd_data[i][1] = (uint32_t) ((( (double)io_attr_mvpd_data[i][1]) *
//                                        volt_ext_vdd_bias) + 0.5);
//    io_attr_mvpd_data[i][3] = (uint32_t) ((( (double)io_attr_mvpd_data[i][3]) *
//                                        volt_ext_vcs_bias) + 0.5);
//}

//FAPI_INF("BIAS freq    = %f", freq_bias);
//FAPI_INF("BIAS vdd ext = %f  vcs ext = %f", volt_ext_vdd_bias,
//         volt_ext_vcs_bias);
//FAPI_INF("BIAS vdd int = %f  vcs int = %f", *io_volt_int_vdd_bias,
//         *io_volt_int_vcs_bias);

// ssrivath - End of P8 Code
//
//
return fapi2::FAPI2_RC_SUCCESS;

} // end proc_get_extint_bias

/// ssrivath END OF BIAS APPLICATION FUNCTION

#if 0
/// -------------------------------------------------------------------
/// \brief Boost max frequency in pstate table based on boost attribute
/// \param[inout] *pss   => pointer to pstate superstructure
/// \param[in]    *attr  => pointer to attribute list structure
/// -------------------------------------------------------------------

ReturnCode proc_boost_gpst (PstateSuperStructure* pss,
                            uint32_t attr_boost_percent)
{
ReturnCode l_rc;
uint8_t    i;
uint8_t    idx;
double    boosted_pct;
uint32_t   boosted_freq_khz;
uint32_t   pstate0_frequency_khz;
uint32_t   frequency_step_khz;
uint32_t   pstate_diff;
gpst_entry_t entry;
uint8_t    gpsi_max;

const uint32_t MAXIMUM_BOOST_PERCENT_SUPPORTED = 20;
const uint32_t MAXIMUM_PSTATE_RANGE = 255;  // maximum represented by uint8_t

do
{

    if (attr_boost_percent == 0)
    {
        FAPI_INF("CPM Turbo Boost Attribute = 0 -- no boosting will be done");
        break;
    }

    // check that percentage is rational.  Note: attribute information is .1 percent units
    if (attr_boost_percent > MAXIMUM_BOOST_PERCENT_SUPPORTED * 10)
    {
        FAPI_ERR("Boost percentage is greater than maximum supported.  Max: %u; Value: %u",
                 MAXIMUM_BOOST_PERCENT_SUPPORTED, attr_boost_percent);
        const uint32_t& MAXBOOSTPERCENT  = MAXIMUM_BOOST_PERCENT_SUPPORTED;
        const uint32_t& ATTRBOOSTPERCENT = attr_boost_percent;
        FAPI_SET_HWP_ERROR(l_rc,
                           RC_PROCPM_PSTATE_DATABLOCK_INVALID_BOOST_PERCENTAGE_ERROR);
        break;
    }

    // calculate percent to boost
    boosted_pct = 1.0 + (BOOST_PCT_UNIT * (double)attr_boost_percent);

    // get turbo frequency (pstate0 frequency)
    pstate0_frequency_khz = revle32(pss->gpst.pstate0_frequency_khz);

    // get pstate frequency step
    frequency_step_khz    = revle32(pss->gpst.frequency_step_khz);

    // calculate boosted frequency
    boosted_freq_khz = (uint32_t) ( (double)pstate0_frequency_khz * boosted_pct);

    // if boosted frequency is <= turbo frequency, then no boost is to be done
    if (boosted_freq_khz <= pstate0_frequency_khz)
    {
        FAPI_INF("CPM Turbo Boost Attribute resulted in no increase in pstates - boost_pct = %f turbo_freq_khz = %u boosted_freq_khz = %u",
                 boosted_pct,  pstate0_frequency_khz, boosted_freq_khz);
        break;
    }

    // calculate # pstates that boosted frequency is above turbo
    pstate_diff = (boosted_freq_khz / frequency_step_khz) -
                  (pstate0_frequency_khz / frequency_step_khz);

    // pstate difference is 0 then no boost is to be done, else update global pstate table
    if (pstate_diff == 0)
    {
        FAPI_INF("CPM Turbo Boost Attribute resulted in no increase in pstates - boost_pct = %f turbo_freq_khz = %u boosted_freq_khz = %u",
                 boosted_pct,  pstate0_frequency_khz, boosted_freq_khz);
        break;
    }
    else if (pstate_diff > MAXIMUM_PSTATE_RANGE)
    {
        FAPI_ERR("Percentage boost calculation overrun produced invalid Pstate Difference: %u",
                 pstate_diff);
        const uint32_t& PSTATEDIFF = pstate_diff;
        const uint32_t& BOOSTEDFREQKHZ = boosted_freq_khz;
        const uint32_t& PSTATE0FREQKHZ = pstate0_frequency_khz;
        const uint32_t& FREQSTEPKHZ = frequency_step_khz;
        const uint32_t& ATTRBOOSTPERCENT = attr_boost_percent;
        const double& BOOSTEDPCT = boosted_pct;
        FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_PSTATE_DIFF_ERROR);
        break;
    }
    else
    {
        gpsi_max    = pss->gpst.entries - 1;
        entry.value = revle64(pss->gpst.pstate[gpsi_max].value);

        FAPI_INF("Boosting Pstate Table : percent = %f num pstates added = %d",
                 boosted_pct, pstate_diff);

        for (i = 1; i <= pstate_diff; i++)
        {
            idx = gpsi_max + i;
            pss->gpst.pstate[idx].value = revle64(entry.value);
        }

        pss->gpst.entries += pstate_diff;

    }

}
while(0);

return l_rc;
} // end proc_boost_gpst

#endif

fapi2::ReturnCode
proc_chk_valid_poundv(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                      const AttributeList* i_attr,
                      const uint32_t i_chiplet_mvpd_data[PV_D][PV_W],
                      uint32_t*      o_valid_pdv_points,
                      const uint8_t  i_chiplet_num,
                      const uint8_t  i_bucket_id)
{

const uint8_t pv_op_order[VPD_PV_POINTS] = VPD_PV_ORDER;
const char*    pv_op_str[VPD_PV_POINTS] = VPD_PV_ORDER_STR;
uint8_t       i = 0;
bool          suspend_ut_check = false;

do
{

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

        if (i_attr->attr_system_wof_enabled && (strcmp(pv_op_str[pv_op_order[i]], "UltraTurbo") == 0))
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
        else if ((!i_attr->attr_system_wof_enabled) && (strcmp(pv_op_str[pv_op_order[i]], "UltraTurbo") == 0))
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

        if (i_attr->attr_system_wof_enabled && strcmp(pv_op_str[pv_op_order[i]], "UltraTurbo") && !suspend_ut_check )
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

return fapi2::FAPI2_RC_SUCCESS;
}

#if 0
/// -------------------------------------------------------------------
/// \brief Convert Resonant Clocking attributes to pstate values and update superstructure with those values
/// \param[inout] *pss   => pointer to pstate superstructure
/// \param[in]    *attr  => pointer to attribute list structure
/// -------------------------------------------------------------------
ReturnCode proc_res_clock (PstateSuperStructure* pss,
                           AttributeList* attr_list)
{
ReturnCode l_rc;
int        rc       = 0;
uint32_t   freq_khz = 0;
Pstate     pstate   = 0;

do
{
    // ----------------------------------------------------------------------------
    // convert resonant clock frequencies to pstate value and set in superstructure
    // ----------------------------------------------------------------------------
#define DATABLOCK_RESCLK(attr_name, ps_name) \
    freq_khz = attr_list->attr_name; \
    FAPI_INF("Converting %s (%u khz) to Pstate", #attr_name, freq_khz); \
    rc = freq2pState(&(pss->gpst), freq_khz, &pstate); \
    if ((rc) && (rc != -PSTATE_LT_PSTATE_MIN)) break; \
    rc = pstate_minmax_chk(&(pss->gpst), &pstate); \
    if (rc == -GPST_PSTATE_GT_GPST_PMAX) { \
        pstate = gpst_pmax(&(pss->gpst)); \
        FAPI_INF("%s pstate is greater than gpst_max(%d) - clipping to gpst_max", #attr_name, pstate); \
    } \
    pss->resclk.ps_name = pstate;

    DATABLOCK_RESCLK(attr_pm_resonant_clock_full_clock_sector_buffer_frequency,
                     full_csb_ps);
    DATABLOCK_RESCLK(attr_pm_resonant_clock_low_band_lower_frequency,
                     res_low_lower_ps);
    DATABLOCK_RESCLK(attr_pm_resonant_clock_low_band_upper_frequency,
                     res_low_upper_ps);
    DATABLOCK_RESCLK(attr_pm_resonant_clock_high_band_lower_frequency,
                     res_high_lower_ps);
    DATABLOCK_RESCLK(attr_pm_resonant_clock_high_band_upper_frequency,
                     res_high_upper_ps);

}
while(0);

// ---------------------------------
// check error code from freq2pState
// ---------------------------------
if (rc && rc != -GPST_PSTATE_GT_GPST_PMAX)
{
    int&       RETURN_CODE = rc;
    int8_t&    PSTATE      = pstate;
    uint32_t& FREQ_KHZ    = freq_khz;

    if (rc == -PSTATE_LT_PSTATE_MIN || rc == -PSTATE_GT_PSTATE_MAX)
    {
        FAPI_ERR("**** ERROR : Computed pstate for freq (%d khz) out of bounds of MAX/MIN possible rc = %d",
                 freq_khz, rc);
        FAPI_SET_HWP_ERROR(l_rc,
                           RC_PROCPM_PSTATE_DATABLOCK_FREQ2PSTATE_PSTATE_MINMAX_BOUNDS_ERROR);
    }
    else
    {
        FAPI_ERR("**** ERROR : Bad Return code rc = %d", rc );
        FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_FREQ2PSTATE_ERROR);
    }
}

return l_rc;
}


/// ------------------------------------------------------------
/// \brief Update Psafe_pstate
/// \param[inout] *pss   => pointer to pstate superstructure
/// \param[in]    *attr  => pointer to attribute list structure
/// ------------------------------------------------------------

ReturnCode proc_upd_psafe_ps (PstateSuperStructure* pss,
                              const AttributeList* attr)
{
ReturnCode l_rc;
int        rc           = 0;
Pstate     pstate;
uint32_t   freq_khz;

do
{

    freq_khz = attr->attr_pm_safe_frequency * 1000;
    FAPI_INF("Converting attr_pm_safe_frequency in %u khz to Pstate", freq_khz);
    rc = freq2pState(&(pss->gpst), freq_khz, &pstate);

    if(rc)
    {
        break;
    }

    FAPI_INF("Producing Pstate = %d for attr_pm_safe_frequency = %u khz", pstate,
             freq_khz);
    rc = pstate_minmax_chk(&(pss->gpst), &pstate);

    if(rc)
    {
        break;
    }

    FAPI_IMP("Setting Psafe in Global Pstate Table to be Pstate of attr_pm_safe_frequency");
    pss->gpst.psafe = pstate;

}
while (0);

// ------------------------------------------------------
// check error code from freq2pState or pstate_minmax_chk
// ------------------------------------------------------
if (rc)
{
    int&       RETURN_CODE = rc;
    int8_t&    PSTATE      = pstate;
    uint32_t& FREQ_KHZ    = freq_khz;

    if (rc == -PSTATE_LT_PSTATE_MIN || rc == -PSTATE_GT_PSTATE_MAX)
    {
        FAPI_ERR("**** ERROR : Computed pstate for freq (%d khz) out of bounds of MAX/MIN possible rc = %d",
                 freq_khz, rc);
        FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_PSAFE_MINMAX_BOUNDS_ERROR);
    }
    else if (rc == -GPST_PSTATE_GT_GPST_PMAX)
    {
        FAPI_ERR("**** ERROR : Computed pstate is greater than max pstate in gpst (computed pstate = %d  max pstate = %d  rc = %d",
                 pstate, gpst_pmax(&(pss->gpst)), rc );
        FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_PSAFE_GT_GPSTPMAX_ERROR);
    }
    else
    {
        FAPI_ERR("**** ERROR : Bad Return code rc = %d", rc );
        FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_PSAFE_ERROR);
    }
}

return l_rc;
} // end proc_upd_psafe_ps


/// ------------------------------------------------------------
/// \brief Update Floor_pstate
/// \param[inout] *pss   => pointer to pstate superstructure
/// \param[in]    *attr  => pointer to attribute list structure
/// ------------------------------------------------------------

ReturnCode proc_upd_floor_ps (PstateSuperStructure* pss,
                              const AttributeList* attr)
{
ReturnCode l_rc;
int        rc           = 0;
Pstate     pstate;
uint32_t   freq_khz;

do
{

    freq_khz = attr->attr_freq_core_floor * 1000;
    FAPI_INF("Converting attr_freq_core_floor in %u khz to Pstate", freq_khz);
    rc = freq2pState(&(pss->gpst), freq_khz, &pstate);

    if(rc)
    {
        break;
    }

    FAPI_INF("Producing Pstate = %d for attr_freq_core_floor = %u khz", pstate,
             freq_khz);
    rc = pstate_minmax_chk(&(pss->gpst), &pstate);

    if(rc)
    {
        break;
    }

    FAPI_IMP("Setting Pfloor in Global Pstate Table to be Pstate of attr_freq_core_floor");
    pss->gpst.pfloor = pstate;

}
while (0);

// ------------------------------------------------------
// check error code from freq2pState or pstate_minmax_chk
// ------------------------------------------------------
if (rc)
{
    int&       RETURN_CODE = rc;
    int8_t&    PSTATE      = pstate;
    uint32_t& FREQ_KHZ    = freq_khz;

    if (rc == -PSTATE_LT_PSTATE_MIN || rc == -PSTATE_GT_PSTATE_MAX)
    {
        FAPI_ERR("**** ERROR : Computed pstate for freq (%d khz) out of bounds of MAX/MIN possible rc = %d",
                 freq_khz, rc);
        FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_PFLOOR_MINMAX_BOUNDS_ERROR);
    }
    else if (rc == -GPST_PSTATE_GT_GPST_PMAX)
    {
        FAPI_ERR("**** ERROR : Computed pstate is greater than max pstate in gpst (computed pstate = %d  max pstate = %d  rc = %d",
                 pstate, gpst_pmax(&(pss->gpst)), rc );
        FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_PFLOOR_GT_GPSTPMAX_ERROR);
    }
    else
    {
        FAPI_ERR("**** ERROR : Bad Return code rc = %d", rc );
        FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PSTATE_DATABLOCK_PFLOOR_ERROR);
    }
}

return l_rc;
} // end proc_upd_floor_ps

/// ------------------------------------------------------------
/// \brief Populate a subset of the WOFElements structure from Attributes
/// \param[inout] *pss   => pointer to pstate superstructure
/// \param[in]    *attr  => pointer to attribute list structure
/// ------------------------------------------------------------

ReturnCode load_wof_attributes (PstateSuperStructure* pss,
                                const AttributeList* attr)
{


// -----------------------------------------------
// ATTR_WOF_ENABLED setting
// -----------------------------------------------
pss->wof.wof_enabled = attr->attr_system_wof_enabled;

// -----------------------------------------------
// ATTR_TDP_RDP_CURRENT_FACTOR value
// -----------------------------------------------
pss->wof.tdp_rdp_factor = attr->attr_tdp_rdp_current_factor;

// -----------------------------------------------
// System Power Distribution value
// -----------------------------------------------

pss->wof.vdd_sysparm.loadline_uohm = attr->attr_proc_r_loadline_vdd;
pss->wof.vcs_sysparm.loadline_uohm = attr->attr_proc_r_loadline_vcs;
pss->wof.vdd_sysparm.distloss_uohm = attr->attr_proc_r_distloss_vdd;
pss->wof.vcs_sysparm.distloss_uohm = attr->attr_proc_r_distloss_vcs;
pss->wof.vdd_sysparm.distoffset_uv = attr->attr_proc_vrm_voffset_vdd;
pss->wof.vcs_sysparm.distoffset_uv = attr->attr_proc_vrm_voffset_vcs;

return FAPI_RC_SUCCESS;

} // end load_wof_attributes

#endif

/// ------------------------------------------------------------
/// \brief Copy VPD operating point into destination in assending order
/// \param[in]  &src[VPD_PV_POINTS]   => reference to source VPD structure (array)
/// \param[out] *dest[VPD_PV_POINTS]  => pointer to destination VpdOperatingPoint structure
/// ------------------------------------------------------------

fapi2::ReturnCode
load_mvpd_operating_point ( const uint32_t i_src[PV_D][PV_W],
                            VpdOperatingPoint* o_dest)
{

const uint8_t pv_op_order[VPD_PV_POINTS] = VPD_PV_ORDER;

for (uint32_t i = 0; i < VPD_PV_POINTS; i++)
{
    o_dest[i].frequency_mhz  = i_src[pv_op_order[i]][0];
    o_dest[i].vdd_mv        = i_src[pv_op_order[i]][1];
    o_dest[i].idd_100ma      = i_src[pv_op_order[i]][2];
    //o_dest[i].vdd_maxreg_5mv = i_src[pv_op_order[i]][1] - DEAD_ZONE_5MV;
    o_dest[i].vcs_mv        = i_src[pv_op_order[i]][3];
    o_dest[i].ics_100ma      = i_src[pv_op_order[i]][4];
    //o_dest[i].vcs_maxreg_5mv = i_src[pv_op_order[i]][3] - DEAD_ZONE_5MV;
}

return fapi2::FAPI2_RC_SUCCESS;
} // end attr2wof


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

//return fapi2::FAPI2_RC_SUCCESS;
}

