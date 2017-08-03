/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_setup_evid.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file  p9_setup_evid.C
/// @brief Setup External Voltage IDs
///
// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Prasad Bg Ranganath <prasadbgr@in.ibm.com>
// *Team                : PM
// *Consumed by         : HB
// *Level               : 3
///
/// @verbatim
///
/// Procedure Summary:
///   - Use Attributes to send VDD, VDN and VCS via the AVS bus to VRMs
///
/// @endverbatim

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_setup_evid.H>
#include <p9_avsbus_lib.H>
#include <p9_avsbus_scom.H>
#include <p9_quad_scom_addresses.H>
#include <p9_quad_scom_addresses_fld.H>

enum P9_SETUP_EVID_CONSTANTS
{
// By convention, the Pstate GPE will use bridge 0.  Other entities
// will use bridge 1
    BRIDGE_NUMBER = 1,

// Default voltages if mailbox -> attributes are not setup
    AVSBUS_VOLTAGE_WRITE_RETRY_COUNT = 5

};


//-----------------------------------------------------------------------------
// Procedure
//-----------------------------------------------------------------------------


// Substep indicators
// const uint32_t STEP_SBE_EVID_START              = 0x1;
// const uint32_t STEP_SBE_EVID_CONFIG             = 0x2;
// const uint32_t STEP_SBE_EVID_WRITE_VDN          = 0x3;
// const uint32_t STEP_SBE_EVID_POLL_VDN_STATUS    = 0x4;
// const uint32_t STEP_SBE_EVID_WRITE_VDD          = 0x5;
// const uint32_t STEP_SBE_EVID_POLL_VDD_STATUS    = 0x6;
// const uint32_t STEP_SBE_EVID_WRITE_VCS          = 0x7;
// const uint32_t STEP_SBE_EVID_POLL_VCS_STATUS    = 0x8;
// const uint32_t STEP_SBE_EVID_TIMEOUT            = 0x9;
// const uint32_t STEP_SBE_EVID_BOOT_FREQ          = 0xA;
// const uint32_t STEP_SBE_EVID_COMPLETE           = 0xB;


struct avsbus_attrs_t
{
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
};

//##############################################################################
//@brief Initialize VDD/VCS/VDN bus num, rail select and voltage values
//@param[in] i_target   Proc Chip target
//@param[in] attrs      VDD/VCS/VDN attributes
//@param[in] i_action   Voltage Config action
//@return fapi::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
//##############################################################################
fapi2::ReturnCode
avsInitAttributes(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                  avsbus_attrs_t* attrs,
                  const VoltageConfigActions_t i_action)
{
    fapi2::ReturnCode l_rc;
    uint32_t attr_mvpd_data[PV_D][PV_W];
    uint32_t valid_pdv_points;
    uint8_t present_chiplets;
    PSTATE_attribute_state l_state;
    l_state.iv_pstates_enabled = true;
    l_state.iv_resclk_enabled  = true;
    l_state.iv_vdm_enabled     = true;
    l_state.iv_ivrm_enabled    = true;
    l_state.iv_wof_enabled     = true;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    uint32_t attr_freq_proc_refclock_khz = 0;
    uint32_t attr_proc_dpll_divider = 0;

#define DATABLOCK_GET_ATTR(_attr_name, _target, _attr_assign) \
    FAPI_TRY(FAPI_ATTR_GET(fapi2::_attr_name, _target, _attr_assign),"Attribute read failed"); \
    FAPI_INF("%-30s = 0x%08x %u", #_attr_name, _attr_assign, _attr_assign);

    DATABLOCK_GET_ATTR(ATTR_VDD_AVSBUS_BUSNUM,        i_target, attrs->vdd_bus_num);
    DATABLOCK_GET_ATTR(ATTR_VDD_AVSBUS_RAIL,          i_target, attrs->vdd_rail_select);
    DATABLOCK_GET_ATTR(ATTR_VDN_AVSBUS_BUSNUM,        i_target, attrs->vdn_bus_num);
    DATABLOCK_GET_ATTR(ATTR_VDN_AVSBUS_RAIL,          i_target, attrs->vdn_rail_select);
    DATABLOCK_GET_ATTR(ATTR_VCS_AVSBUS_BUSNUM,        i_target, attrs->vcs_bus_num);
    DATABLOCK_GET_ATTR(ATTR_VCS_AVSBUS_RAIL,          i_target, attrs->vcs_rail_select);
    DATABLOCK_GET_ATTR(ATTR_VCS_BOOT_VOLTAGE,         i_target, attrs->vcs_voltage_mv);
    DATABLOCK_GET_ATTR(ATTR_VDD_BOOT_VOLTAGE,         i_target, attrs->vdd_voltage_mv);
    DATABLOCK_GET_ATTR(ATTR_VDN_BOOT_VOLTAGE,         i_target, attrs->vdn_voltage_mv);

    DATABLOCK_GET_ATTR(ATTR_PROC_R_LOADLINE_VDD_UOHM, i_target, attrs->r_loadline_vdd_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_DISTLOSS_VDD_UOHM, i_target, attrs->r_distloss_vdd_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_VRM_VOFFSET_VDD_UV,  i_target, attrs->vrm_voffset_vdd_uv );
    DATABLOCK_GET_ATTR(ATTR_PROC_R_LOADLINE_VDN_UOHM, i_target, attrs->r_loadline_vdn_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_DISTLOSS_VDN_UOHM, i_target, attrs->r_distloss_vdn_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_VRM_VOFFSET_VDN_UV,  i_target, attrs->vrm_voffset_vdn_uv );
    DATABLOCK_GET_ATTR(ATTR_PROC_R_LOADLINE_VCS_UOHM, i_target, attrs->r_loadline_vcs_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_DISTLOSS_VCS_UOHM, i_target, attrs->r_distloss_vcs_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_VRM_VOFFSET_VCS_UV,  i_target, attrs->vrm_voffset_vcs_uv);
    DATABLOCK_GET_ATTR(ATTR_FREQ_PROC_REFCLOCK_KHZ, FAPI_SYSTEM, attr_freq_proc_refclock_khz);
    DATABLOCK_GET_ATTR(ATTR_PROC_DPLL_DIVIDER, i_target, attr_proc_dpll_divider);

    do
    {

        //We only wish to compute voltage setting defaults if the action
        //inputed to the HWP tells us to
        if(i_action == COMPUTE_VOLTAGE_SETTINGS)
        {
            uint8_t l_poundv_bucketId = 0;
            fapi2::voltageBucketData_t l_poundv_data;

            // query VPD if any of the voltage attributes are zero
            if (!attrs->vdd_voltage_mv ||
                !attrs->vcs_voltage_mv ||
                !attrs->vdn_voltage_mv)
            {
                // Get #V data from MVPD for VDD/VDN and VCS voltage values
                FAPI_TRY(proc_get_mvpd_data(i_target,
                                            attr_mvpd_data,
                                            &valid_pdv_points,
                                            &present_chiplets,
                                            l_poundv_bucketId,
                                            &l_poundv_data,
                                            &l_state          ));

                if (!present_chiplets)
                {
                    FAPI_IMP("**** WARNING : There are no EQ chiplets present which means there is no valid #V VPD");
                    break;
                }

                // Compute safe mode values
                LP_VDMParmBlock   l_lp_vdmpb;
                PoundW_data l_poundw_data;
                memset (&l_poundw_data, 0, sizeof(PoundW_data));
                LocalPstateParmBlock l_localppb;
                memset(&l_localppb, 0, sizeof(LocalPstateParmBlock));
                Safe_mode_parameters l_safe_mode_values;
                uint8_t l_pstate = 0xFF;
                AttributeList l_attr;
                VpdBias l_vpdbias[NUM_OP_POINTS];
                memset (l_vpdbias, 0, sizeof(VpdBias));

                //set to default value if dpll divider is 0
                if (!attr_proc_dpll_divider)
                {
                    attr_proc_dpll_divider = 8;
                }

                // Read the Biased attribute data
                FAPI_TRY(proc_get_attributes(i_target, &l_attr), "Get attributes function failed");

                // Apply Bias values
                FAPI_TRY(proc_get_extint_bias(attr_mvpd_data,
                                              &l_attr,
                                              l_vpdbias),
                         "Bias application function failed");


                uint32_t l_frequency_step_khz = attr_freq_proc_refclock_khz / attr_proc_dpll_divider;
                uint32_t l_ref_freq_khz = attr_mvpd_data[ULTRA][VPD_PV_CORE_FREQ_MHZ] * 1000;

                l_pstate = ((attr_mvpd_data[ULTRA][VPD_PV_CORE_FREQ_MHZ] -
                             attr_mvpd_data[POWERSAVE][VPD_PV_CORE_FREQ_MHZ]) * 1000) /
                           l_frequency_step_khz;
                l_rc = proc_get_mvpd_poundw(i_target, l_poundv_bucketId, &l_lp_vdmpb, &l_poundw_data, l_poundv_data, &l_state, true);

                if (l_rc)
                {
                    FAPI_ASSERT_NOEXIT(false,
                                       fapi2::PSTATE_PB_POUND_W_ACCESS_FAIL(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                       .set_CHIP_TARGET(i_target)
                                       .set_FAPI_RC(l_rc),
                                       "Pstate Parameter Block proc_get_mvpd_poundw function failed");
                    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                }

                FAPI_INF ("l_frequency_step_khz %08x", l_frequency_step_khz);
                FAPI_INF ("l_ref_freq_khz %08X", l_ref_freq_khz);
                FAPI_INF ("l_pstate %x", l_pstate);

                //Compute safe mode values
                FAPI_TRY(p9_pstate_safe_mode_computation (i_target, attr_mvpd_data,
                         l_ref_freq_khz, l_frequency_step_khz,
                         l_pstate, &l_safe_mode_values,
                         l_poundw_data),
                         "Error from p9_pstate_safe_mode_computation function");

                // Set the DPLL frequency values to safe mode values
                FAPI_TRY (p9_setup_dpll_values(i_target,
                                               l_safe_mode_values,
                                               attrs->vdd_voltage_mv,
                                               attr_freq_proc_refclock_khz,
                                               attr_proc_dpll_divider),
                          "Error from p9_setup_dpll_values function");


                // set VDD voltage to PowerSave Voltage from MVPD data (if no override)
                if (attrs->vdd_voltage_mv)
                {
                    FAPI_INF("VDD boot voltage override set.");
                }
                else
                {
                    FAPI_INF("VDD boot voltage override not set, using VPD value and correcting for applicable load line setting");
                    uint32_t vpd_vdd_voltage_mv = attr_mvpd_data[POWERSAVE][VPD_PV_VDD_MV];
                    attrs->vdd_voltage_mv =
                        ( (vpd_vdd_voltage_mv * 1000) +                                                 // uV
                          ( ( (attr_mvpd_data[POWERSAVE][VPD_PV_IDD_100MA] / 10) *                      // A
                              (attrs->r_loadline_vdd_uohm + attrs->r_distloss_vdd_uohm)) +            // uohm -> A*uohm = uV
                            attrs->vrm_voffset_vdd_uv                                    )) / 1000;  // mV

                    FAPI_INF("VDD VPD voltage %d mV; Corrected voltage: %d mV; IDD: %d mA; LoadLine: %d uOhm; DistLoss: %d uOhm;  Offst: %d uOhm",
                             vpd_vdd_voltage_mv,
                             attrs->vdd_voltage_mv,
                             attr_mvpd_data[POWERSAVE][VPD_PV_IDD_100MA] * 100,
                             attrs->r_loadline_vdd_uohm,
                             attrs->r_distloss_vdd_uohm,
                             attrs->vrm_voffset_vdd_uv);

                    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_VDD_BOOT_VOLTAGE, i_target, attrs->vdd_voltage_mv),
                             "Error from FAPI_ATTR_SET (ATTR_VDD_BOOT_VOLTAGE)");
                }

                // set VCS voltage to UltraTurbo Voltage from MVPD data (if no override)
                if (attrs->vcs_voltage_mv)
                {
                    FAPI_INF("VCS boot voltage override set.");
                }
                else
                {
                    FAPI_INF("VCS boot voltage override not set, using VPD value and correcting for applicable load line setting");
                    uint32_t vpd_vcs_voltage_mv = attr_mvpd_data[POWERSAVE][VPD_PV_VCS_MV];
                    attrs->vcs_voltage_mv =
                        ( (vpd_vcs_voltage_mv * 1000) +                                                 // uV
                          ( ( (attr_mvpd_data[POWERSAVE][VPD_PV_ICS_100MA] / 10) *                      // A
                              (attrs->r_loadline_vcs_uohm + attrs->r_distloss_vcs_uohm)) +            // uohm -> A*uohm = uV
                            attrs->vrm_voffset_vcs_uv                                    )) / 1000;  // mV

                    FAPI_INF("VCS VPD voltage %d mV; Corrected voltage: %d mV; IDD: %d mA; LoadLine: %d uOhm; DistLoss: %d uOhm;  Offst: %d uOhm",
                             vpd_vcs_voltage_mv,
                             attrs->vcs_voltage_mv,
                             attr_mvpd_data[POWERSAVE][VPD_PV_ICS_100MA] * 100,
                             attrs->r_loadline_vcs_uohm,
                             attrs->r_distloss_vcs_uohm,
                             attrs->vrm_voffset_vcs_uv);

                    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_VCS_BOOT_VOLTAGE, i_target, attrs->vcs_voltage_mv),
                             "Error from FAPI_ATTR_SET (ATTR_VCS_BOOT_VOLTAGE)");
                }

                // set VDN voltage to PowerSave Voltage from MVPD data (if no override)
                if (attrs->vdn_voltage_mv)
                {
                    FAPI_INF("VDN boot voltage override set");
                }
                else
                {
                    FAPI_INF("VDN boot voltage override not set, using VPD value and correcting for applicable load line setting");
                    uint32_t vpd_vdn_voltage_mv = attr_mvpd_data[POWERBUS][VPD_PV_VDN_MV];
                    attrs->vdn_voltage_mv =
                        ( (vpd_vdn_voltage_mv * 1000) +                                                 // uV
                          ( ( (attr_mvpd_data[POWERBUS][VPD_PV_IDN_100MA] / 10) *                       // A
                              (attrs->r_loadline_vdn_uohm + attrs->r_distloss_vdn_uohm)) +            // uohm -> A*uohm = uV
                            attrs->vrm_voffset_vdn_uv                                    )) / 1000;  // mV

                    FAPI_INF("VDN VPD voltage %d mV; Corrected voltage: %d mV; IDN: %d mA; LoadLine: %d uOhm; DistLoss: %d uOhm;  Offst: %d uOhm",
                             vpd_vdn_voltage_mv,
                             attrs->vdn_voltage_mv,
                             attr_mvpd_data[POWERBUS][VPD_PV_IDN_100MA] * 100,
                             attrs->r_loadline_vdn_uohm,
                             attrs->r_distloss_vdn_uohm,
                             attrs->vrm_voffset_vdn_uv);

                    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_VDN_BOOT_VOLTAGE, i_target, attrs->vdn_voltage_mv),
                             "Error from FAPI_ATTR_SET (ATTR_VDN_BOOT_VOLTAGE)");
                }
            }
            else
            {
                FAPI_INF("Using override for all boot voltages (VDD/VCS/VDN)");
            }

        }
    }
    while(0);

    // trace values to be used
    FAPI_INF("VDD boot voltage = %d mV (0x%x)",
             attrs->vdd_voltage_mv, attrs->vdd_voltage_mv);
    FAPI_INF("VCS boot voltage = %d mV (0x%x)",
             attrs->vcs_voltage_mv, attrs->vcs_voltage_mv);
    FAPI_INF("VDN boot voltage = %d mV (0x%x)",
             attrs->vdn_voltage_mv, attrs->vdn_voltage_mv);

fapi_try_exit:
    return fapi2::current_err;
} // avsInitAttributes


fapi2::ReturnCode
p9_setup_evid(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target, const VoltageConfigActions_t i_action)
{

    // AVSBus configuration variables
    avsbus_attrs_t attrs;

    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint8_t> l_data8;
    uint8_t l_count = 0;
    uint8_t l_goodResponse = 0;
    uint8_t l_throwAssert = 0;

    // Read attribute -
    FAPI_TRY(avsInitAttributes(i_target, &attrs, i_action));

    //We only wish to apply settings if i_action says to
    if(i_action == APPLY_VOLTAGE_SETTINGS)
    {
        // Initialize the buses
        FAPI_TRY(avsInitExtVoltageControl(i_target,
                                          attrs.vdd_bus_num, BRIDGE_NUMBER),
                 "Initializing avsBus VDD, bridge %d", BRIDGE_NUMBER);
        FAPI_TRY(avsInitExtVoltageControl(i_target,
                                          attrs.vdn_bus_num, BRIDGE_NUMBER),
                 "Initializing avsBus VDN, bridge %d", BRIDGE_NUMBER);

        l_count = 0;

        do
        {
            FAPI_INF("Sending an Idle frame before Voltage writes");

            // Drive AVS Bus with a frame value 0xFFFFFFFF (idle frame) to
            // initialize the AVS slave on VDD bus
            FAPI_TRY(avsIdleFrame(i_target, attrs.vdd_bus_num, BRIDGE_NUMBER));

            if (!attrs.vdd_voltage_mv)
            {
                FAPI_IMP("VDD voltage value is zero,so we can't set boot voltage");
                break;
            }

            // Set Boot VDD Voltage
            FAPI_TRY(avsVoltageWrite(i_target,
                                     attrs.vdd_bus_num,
                                     BRIDGE_NUMBER,
                                     attrs.vdd_rail_select,
                                     attrs.vdd_voltage_mv),
                     "Setting VDD voltage via AVSBus %d, Bridge %d",
                     attrs.vdd_bus_num,
                     BRIDGE_NUMBER);

            // Throw an assertion if we don't get a good response.
            l_throwAssert =  l_count >= AVSBUS_VOLTAGE_WRITE_RETRY_COUNT;
            FAPI_TRY(avsValidateResponse(i_target,  attrs.vdd_bus_num, BRIDGE_NUMBER, l_throwAssert, l_goodResponse));

            l_count++;
        }
        while (l_goodResponse == 0);




        l_count = 0;

        do
        {

            // VDN bus
            FAPI_TRY(avsIdleFrame(i_target, attrs.vdn_bus_num, BRIDGE_NUMBER));

            if (!attrs.vdn_voltage_mv)
            {
                FAPI_IMP("VDN voltage value is zero,so we can't set boot voltage");
                break;
            }

            // Set Boot VDN Voltage
            FAPI_TRY(avsVoltageWrite(i_target,
                                     attrs.vdn_bus_num,
                                     BRIDGE_NUMBER,
                                     attrs.vdn_rail_select,
                                     attrs.vdn_voltage_mv),
                     "Setting VDN voltage via AVSBus %d, Bridge %d",
                     attrs.vdn_bus_num,
                     BRIDGE_NUMBER);


            // Throw an assertion if we don't get a good response.
            l_throwAssert =  l_count >= AVSBUS_VOLTAGE_WRITE_RETRY_COUNT;
            FAPI_TRY(avsValidateResponse(i_target,  attrs.vdn_bus_num, BRIDGE_NUMBER, l_throwAssert, l_goodResponse));
            l_count++;
        }
        while (l_goodResponse == 0);


        // Set Boot VCS Voltage
        if(attrs.vcs_bus_num == 0xFF)
        {

            FAPI_INF("VCS rail is not connected to AVSBus. Skipping VCS programming");

        }
        else
        {

            l_count = 0;

            do
            {
                // VCS bus
                FAPI_TRY(avsIdleFrame(i_target, attrs.vcs_bus_num, BRIDGE_NUMBER));

                if (!attrs.vcs_voltage_mv)
                {
                    FAPI_IMP("VCS voltage value is zero,so we can't set boot voltage");
                    break;
                }

                // Set Boot VCS voltage
                FAPI_TRY(avsVoltageWrite(i_target,
                                         attrs.vcs_bus_num,
                                         BRIDGE_NUMBER,
                                         attrs.vcs_rail_select,
                                         attrs.vcs_voltage_mv),
                         "Setting VCS voltage via AVSBus %d, Bridge %d",
                         attrs.vcs_bus_num,
                         BRIDGE_NUMBER);

                // Throw an assertion if we don't get a good response.
                l_throwAssert =  l_count >= AVSBUS_VOLTAGE_WRITE_RETRY_COUNT;
                FAPI_TRY(avsValidateResponse(i_target,  attrs.vcs_bus_num, BRIDGE_NUMBER, l_throwAssert, l_goodResponse));

                l_count++;
            }
            while (l_goodResponse == 0);

        }
    }

fapi_try_exit:
    return fapi2::current_err;
} // Procedure

fapi2::ReturnCode
p9_setup_dpll_values (const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                      const Safe_mode_parameters i_safe_mode_values,
                      uint32_t& o_vddm_mv,
                      const uint32_t  i_freq_proc_refclock_khz,
                      const uint32_t i_proc_dpll_divider)

{
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_EQ>> l_eqChiplets;
    fapi2::Target<fapi2::TARGET_TYPE_EQ> l_firstEqChiplet;
    l_eqChiplets = i_target.getChildren<fapi2::TARGET_TYPE_EQ>(fapi2::TARGET_STATE_FUNCTIONAL);
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_fmult;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    uint8_t l_chipNum = 0xFF;


    for ( auto l_itr = l_eqChiplets.begin(); l_itr != l_eqChiplets.end(); ++l_itr)
    {
        l_fmult.flush<0>();
        FAPI_TRY(fapi2::getScom(*l_itr, EQ_QPPM_DPLL_FREQ , l_data64),
                 "ERROR: Failed to read EQ_QPPM_DPLL_FREQ");

        l_data64.extractToRight<EQ_QPPM_DPLL_FREQ_FMULT,
                                EQ_QPPM_DPLL_FREQ_FMULT_LEN>(l_fmult);

        // Convert back to the complete frequency value
        l_fmult =  ((l_fmult * i_freq_proc_refclock_khz ) / i_proc_dpll_divider ) / 1000;

        // Convert frequency value to a format that needs to be written to the
        // register
        uint32_t l_safe_mode_freq = ((i_safe_mode_values.safe_mode_freq_mhz * 1000) * i_proc_dpll_divider) /
                                    i_freq_proc_refclock_khz;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, *l_itr, l_chipNum));
        FAPI_INF("For EQ number %u, l_fmult %08X l_safe_mode_freq %08X",
                 l_chipNum, l_fmult, l_safe_mode_freq);

        if (l_fmult > i_safe_mode_values.safe_mode_freq_mhz)
        {
            FAPI_INF("DPLL setting: Lowering the dpll frequency");
        }
        else if (l_fmult < i_safe_mode_values.safe_mode_freq_mhz)
        {
            FAPI_INF("DPLL setting: Raising the dpll frequency");
        }
        else
        {
            FAPI_INF("DPLL setting: Leaving the dpll frequency as it is");
        }

        //FMax
        l_data64.insertFromRight<EQ_QPPM_DPLL_FREQ_FMAX,
                                 EQ_QPPM_DPLL_FREQ_FMAX_LEN>(l_safe_mode_freq);
        //FMin
        l_data64.insertFromRight<EQ_QPPM_DPLL_FREQ_FMIN,
                                 EQ_QPPM_DPLL_FREQ_FMIN_LEN>(l_safe_mode_freq);
        //FMult
        l_data64.insertFromRight<EQ_QPPM_DPLL_FREQ_FMULT,
                                 EQ_QPPM_DPLL_FREQ_FMULT_LEN>(l_safe_mode_freq);

        FAPI_TRY(fapi2::putScom(*l_itr, EQ_QPPM_DPLL_FREQ, l_data64),
                 "ERROR: Failed to write for EQ_QPPM_DPLL_FREQ");

        //Update external voltage to boot mode value
        o_vddm_mv = i_safe_mode_values.boot_mode_mv;


        //Update VDM VID compare to safe mode value
        const uint16_t VDM_VOLTAGE_IN_MV = 512;
        const uint16_t VDM_GRANULARITY = 4;

        //Convert same mode value to a format that needs to be written to
        //the register
        uint32_t l_vdm_vid_value = (i_safe_mode_values.safe_mode_mv - VDM_VOLTAGE_IN_MV) / VDM_GRANULARITY;

        FAPI_INF ("l_vdm_vid_value %x, i_safe_mode_values.safe_mode_mv %x", l_vdm_vid_value, i_safe_mode_values.safe_mode_mv);

        FAPI_TRY(fapi2::getScom(*l_itr, EQ_QPPM_VDMCFGR, l_data64),
                 "ERROR: Failed to read EQ_QPPM_VDMCFGR");

        l_data64.insertFromRight<0, 8>(l_vdm_vid_value);

        FAPI_TRY(fapi2::putScom(*l_itr, EQ_QPPM_VDMCFGR, l_data64),
                 "ERROR: Failed to write for EQ_QPPM_VDMCFGR");
    } //end of eq list

fapi_try_exit:
    return fapi2::current_err;
}


