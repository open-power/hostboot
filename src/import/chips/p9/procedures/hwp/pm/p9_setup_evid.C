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
// *HW Owner    : Sudheendra K Srivathsa <sudheendraks@in.ibm.com>
// *FW Owner    : Sangeetha T S <sangeet2@in.ibm.com>
// *Team        : PM
// *Consumed by : HB
// *Level       : 2
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
#include <p9_pstate_parameter_block.H>

enum P9_SETUP_EVID_CONSTANTS
{
// By convention, the Pstate GPE will use bridge 0.  Other entities
// will use bridge 1
    BRIDGE_NUMBER = 1,

// Default voltages if mailbox -> attributes are not setup
    AVSBUS_VOLTAGE_WRITE_RETRY_COUNT = 5

};


//##############################################################################
// Function to initiate an eVRM voltage change.
//##############################################################################
// Voltage write and Status Check performed in main procedure
fapi2::ReturnCode
driveVoltageChange(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&
                   i_target,
                   const p9avslib::avsRails i_Rail,
                   const uint32_t i_Voltage )
{

    uint32_t l_CmdDataRead = 0;
    uint32_t l_avsBusNum = 0, l_RailSelect = 0;
    uint32_t l_o2sBridgeNum = BRIDGE_NUMBER;

    // Hardcoded for now
    if (i_Rail == p9avslib::VDD)
    {
        l_avsBusNum = 0;
        l_RailSelect = 0;
    }
    else if (i_Rail == p9avslib::VDN)
    {
        l_avsBusNum = 1;
        l_RailSelect = 0;
    }
    else
    {
        FAPI_ERR("Invalid AVSBus Rail: i_Rail = %u", i_Rail);
        //return fapi2::current_err;

    }

    // Drive AVS transaction with a frame value 0xFFFFFFFF (idle frame) to
    // initialize the AVS slave
    FAPI_TRY(avsIdleFrame(i_target, l_avsBusNum, l_o2sBridgeNum),
             "AVS Idle frame transaction failed");

    // Drive write transaction with a target voltage on a particular rail
    // and wait on o2s_ongoing=0
    FAPI_TRY(avsVoltageWrite(i_target, l_avsBusNum, l_o2sBridgeNum,
                             l_RailSelect, i_Voltage),
             "AVS Voltage write transaction failed");


    // *** The following is used for procedure validation testing an will be removed
    // *** from the final code as will be replaced with a checkStatus() routine.

    // Drive read transaction to return the voltage on the same rail
    // and wait on o2s_ongoing=0
    FAPI_TRY(avsVoltageRead(i_target, l_avsBusNum, l_o2sBridgeNum,
                            l_RailSelect, l_CmdDataRead),
             "AVS Voltage read transaction failed");

    // Compare write voltage value with read voltage value
    if (i_Voltage == l_CmdDataRead)
    {
        //PASS
    }
    else
    {
        //@todo L3 - Update once RTC item for drive Voltage change and
        // check status routine is completed and L3 FFDC // FAIL
    }

fapi_try_exit:
    return fapi2::current_err;
}

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

//@brief Initialize VDD/VCS/VDN bus num, rail select and voltage values
//@param[i] i_target       Chip target
//@param[i] attrs    VDD/VCS/VDN attributes
//@return   Return code void
fapi2::ReturnCode
avsInitAttributes(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                  avsbus_attrs_t* attrs,
                  const VoltageConfigActions_t i_action)
{
    uint32_t attr_mvpd_data[PV_D][PV_W];
    uint32_t valid_pdv_points;
    uint8_t present_chiplets;

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

    //We only wish to compute voltage setting defaults if the action
    //inputed to the HWP tells us to
    if(i_action == COMPUTE_VOLTAGE_SETTINGS)
    {
        // query VPD if any of the voltage attributes are zero
        if (!attrs->vdd_voltage_mv ||
            !attrs->vcs_voltage_mv ||
            !attrs->vdn_voltage_mv)
        {
            // Get #V data from MVPD for VDD/VDN and VCS voltage values
            FAPI_TRY(proc_get_mvpd_data(i_target, attr_mvpd_data, &valid_pdv_points, &present_chiplets));

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

        while (l_count < AVSBUS_VOLTAGE_WRITE_RETRY_COUNT)
        {

            FAPI_INF("Sending an Idle frame before Voltage writes");

            // Drive AVS Bus with a frame value 0xFFFFFFFF (idle frame) to
            // initialize the AVS slave on VDD bus
            FAPI_TRY(avsIdleFrame(i_target, attrs.vdd_bus_num, BRIDGE_NUMBER));

            // Set Boot VDD Voltage
            FAPI_TRY(avsVoltageWrite(i_target,
                                     attrs.vdd_bus_num,
                                     BRIDGE_NUMBER,
                                     attrs.vdd_rail_select,
                                     attrs.vdd_voltage_mv),
                     "Setting VDD voltage via AVSBus %d, Bridge %d",
                     attrs.vdd_bus_num,
                     BRIDGE_NUMBER);

            l_data64.flush<0>();
            l_data8.flush<0>();

            FAPI_TRY(getScom(i_target,
                             p9avslib::OCB_O2SRD[attrs.vdd_bus_num][BRIDGE_NUMBER], l_data64));

            l_data64.extract(l_data8, 0, 1);

            if (l_data8 == 0)
            {
                break;
            }

            l_count++;
        }

        if (l_count >= AVSBUS_VOLTAGE_WRITE_RETRY_COUNT)
        {
            FAPI_ASSERT(false, fapi2::PM_VDD_EVID_WRITEVOLTAGE_TIMEOUT().set_TARGET(i_target),
                        "ERROR; Voltage write to VDD rail failed due to bad CRC,unknown command or unavailable resource");
        }

        l_count = 0;

        while (l_count < AVSBUS_VOLTAGE_WRITE_RETRY_COUNT)
        {

            // VDN bus
            FAPI_TRY(avsIdleFrame(i_target, attrs.vdn_bus_num, BRIDGE_NUMBER));

            // Set Boot VDN Voltage
            FAPI_TRY(avsVoltageWrite(i_target,
                                     attrs.vdn_bus_num,
                                     BRIDGE_NUMBER,
                                     attrs.vdn_rail_select,
                                     attrs.vdn_voltage_mv),
                     "Setting VDN voltage via AVSBus %d, Bridge %d",
                     attrs.vdn_bus_num,
                     BRIDGE_NUMBER);

            l_data64.flush<0>();
            l_data8.flush<0>();

            FAPI_TRY(getScom(i_target,
                             p9avslib::OCB_O2SRD[attrs.vdn_bus_num][BRIDGE_NUMBER], l_data64));

            l_data64.extract(l_data8, 0, 1);

            if (l_data8 == 0)
            {
                break;
            }

            l_count++;
        }

        if (l_count >= AVSBUS_VOLTAGE_WRITE_RETRY_COUNT)
        {
            FAPI_ASSERT(false, fapi2::PM_VDN_EVID_WRITEVOLTAGE_TIMEOUT().set_TARGET(i_target),
                        "ERROR; Voltage write to VDN rail failed due to bad CRC,unknown command or unavailable resource");
        }

        // Set Boot VCS Voltage
        if(attrs.vcs_bus_num == 0xFF)
        {

            FAPI_INF("VCS rail is not connected to AVSBus. Skipping VCS programming");

        }
        else
        {

            l_count = 0;

            while (l_count < AVSBUS_VOLTAGE_WRITE_RETRY_COUNT)
            {

                FAPI_TRY(avsIdleFrame(i_target, attrs.vcs_bus_num, BRIDGE_NUMBER));

                FAPI_TRY(avsVoltageWrite(i_target,
                                         attrs.vcs_bus_num,
                                         BRIDGE_NUMBER,
                                         attrs.vcs_rail_select,
                                         attrs.vcs_voltage_mv),
                         "Setting VCS voltage via AVSBus %d, Bridge %d",
                         attrs.vcs_bus_num,
                         BRIDGE_NUMBER);

                l_data64.flush<0>();
                l_data8.flush<0>();

                FAPI_TRY(getScom(i_target,
                                 p9avslib::OCB_O2SRD[attrs.vcs_bus_num][BRIDGE_NUMBER], l_data64));

                l_data64.extract(l_data8, 0, 1);

                if (l_data8 == 0)
                {
                    break;
                }

                l_count++;
            }

            if (l_count >= AVSBUS_VOLTAGE_WRITE_RETRY_COUNT)
            {
                FAPI_ASSERT(false, fapi2::PM_VCS_EVID_WRITEVOLTAGE_TIMEOUT().set_TARGET(i_target),
                            "ERROR; Voltage write to VCS rail failed due to bad CRC/unknown command or unavailable resource");
            }
        }
    }

fapi_try_exit:
    return fapi2::current_err;
} // Procedure
