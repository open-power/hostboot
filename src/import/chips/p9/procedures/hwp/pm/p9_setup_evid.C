/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_setup_evid.C $       */
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
/// @todo (to be considered in L2/L3 development) AVSBus timing parameters
///  as attributes or not.  They were hardcoded in P8.

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

// Default configuration settings
    DEFAULT_VDD_BUS_NUMBER = 0,
    DEFAULT_VDD_RAILSELECT = 0,
    DEFAULT_VDN_BUS_NUMBER = 1,
    DEFAULT_VDN_RAILSELECT = 0,
    DEFAULT_VCS_BUS_NUMBER = 0,
    DEFAULT_VCS_RAILSELECT = 1,

// Default voltages if mailbox -> attributes are not setup
    DEFAULT_BOOT_VDD_VOLTAGE_MV = 1000,
    DEFAULT_BOOT_VCS_VOLTAGE_MV = 1050,
    DEFAULT_BOOT_VDN_VOLTAGE_MV = 900
};

//##############################################################################
// Function to initiate an eVRM voltage change.
//##############################################################################
// @todo - RTC item to track how AVS Voltage write is called through function below
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
        //@todo L3 - This need to have a FAPI_ASSERT block with appropriate
        //error codes used from this procedure's error xml file
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
                            l_RailSelect, &l_CmdDataRead),
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

    attrs->vdd_bus_num = DEFAULT_VDD_BUS_NUMBER;
    attrs->vdd_rail_select = DEFAULT_VDD_RAILSELECT;
    attrs->vdn_bus_num = DEFAULT_VDN_BUS_NUMBER;
    attrs->vdn_rail_select = DEFAULT_VDN_RAILSELECT;
    attrs->vcs_bus_num = DEFAULT_VCS_BUS_NUMBER;
    attrs->vcs_rail_select = DEFAULT_VCS_RAILSELECT;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDD_AVSBUS_BUSNUM, i_target,
                           attrs->vdd_bus_num));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDD_AVSBUS_RAIL,  i_target,
                           attrs->vdd_rail_select));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDN_AVSBUS_BUSNUM, i_target,
                           attrs->vdn_bus_num));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDN_AVSBUS_RAIL,  i_target,
                           attrs->vdn_rail_select));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VCS_AVSBUS_BUSNUM, i_target,
                           attrs->vcs_bus_num));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VCS_AVSBUS_RAIL,  i_target,
                           attrs->vcs_rail_select));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VCS_BOOT_VOLTAGE, i_target,
                           attrs->vcs_voltage_mv));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDD_BOOT_VOLTAGE, i_target,
                           attrs->vdd_voltage_mv));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDN_BOOT_VOLTAGE, i_target,
                           attrs->vdn_voltage_mv));


    //We only wish to compute voltage setting defaults if the action
    //inputed to the HWP tells us to
    if(i_action == COMPUTE_VOLTAGE_SETTINGS)
    {
        // If attribute values are zero, use the default values (hardcoded)
        // check VDD VID
        if (attrs->vdd_voltage_mv == 0)
        {
            // Default voltage if mailbox value is not set

            // @todo L3 - Eventually, this should replaced with an error point
            // to indicate that the mailbox -> attributes haven't been setup

            attrs->vdd_voltage_mv  = DEFAULT_BOOT_VDD_VOLTAGE_MV;
            FAPI_INF("VDD boot voltage not set in attributes. Setting to default of %d mV (%x)",
                     attrs->vdd_voltage_mv, attrs->vdd_voltage_mv);
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_VDD_BOOT_VOLTAGE, i_target,
                                   attrs->vdd_voltage_mv));
        }
        else
        {
            FAPI_INF("VDD boot voltage = %d mV (%x)",
                     attrs->vdd_voltage_mv, attrs->vdd_voltage_mv);
        }

        // check VCS VID
        if (attrs->vcs_voltage_mv == 0)
        {
            // Default voltage if mailbox value is not set

            // @todo L3 - Eventually, this should replaced with an error point
            // to indicate that the mailbox -> attributes haven't been setup

            attrs->vcs_voltage_mv  = DEFAULT_BOOT_VCS_VOLTAGE_MV;
            FAPI_INF("VCS boot voltage not set in attributes. Setting to default of %d mV (%x)",
                     attrs->vcs_voltage_mv, attrs->vcs_voltage_mv);
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_VCS_BOOT_VOLTAGE, i_target,
                                   attrs->vcs_voltage_mv));
        }
        else
        {
            FAPI_INF("VCS boot voltage = %d mV (%x)",
                     attrs->vcs_voltage_mv, attrs->vcs_voltage_mv);
        }

        // check VDN VID
        if (attrs->vdn_voltage_mv == 0)
        {
            // Default voltage if mailbox value is not set

            // @todo -L3  Eventually, this should replaced with an error point
            // to indicate that the mailbox -> attributes haven't been setup

            attrs->vdn_voltage_mv  = DEFAULT_BOOT_VDN_VOLTAGE_MV;
            FAPI_INF("VDN boot voltage not set in attributes. Setting to default of %d mV (%x)",
                     attrs->vdn_voltage_mv, attrs->vdn_voltage_mv);
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_VDN_BOOT_VOLTAGE, i_target,
                                   attrs->vdn_voltage_mv));
        }
        else
        {
            FAPI_INF("VDN boot voltage = %d mV (%x)",
                     attrs->vdn_voltage_mv, attrs->vdn_voltage_mv);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
} // avsInitAttributes


fapi2::ReturnCode
p9_setup_evid(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target, const VoltageConfigActions_t i_action)
{

    // AVSBus configuration variables
    avsbus_attrs_t attrs;
    AttributeList mvpd_attrs;
    uint32_t attr_mvpd_data[PV_D][PV_W];
    uint32_t valid_pdv_points;
    uint8_t present_chiplets;

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

        // Get #V data from MVPD to program VDD/VDN and VCS voltage values
        FAPI_TRY(proc_get_mvpd_data(i_target, &mvpd_attrs, attr_mvpd_data, &valid_pdv_points, &present_chiplets));

        // Set Boot VDD Voltage - PowerSave Voltage from the MVPD data
        FAPI_TRY(avsVoltageWrite(i_target,
                                 attrs.vdd_bus_num,
                                 BRIDGE_NUMBER,
                                 attrs.vdd_rail_select,
                                 attr_mvpd_data[POWERSAVE][1]),
                 "Setting VDD voltage via AVSBus %d, Bridge %d",
                 attrs.vdd_bus_num,
                 BRIDGE_NUMBER);

        // Set Boot VDN Voltage - PowerBus Voltage from the MVPD data
        FAPI_TRY(avsVoltageWrite(i_target,
                                 attrs.vdn_bus_num,
                                 BRIDGE_NUMBER,
                                 attrs.vdn_rail_select,
                                 attr_mvpd_data[POWERBUS][1]),
                 "Setting VDN voltage via AVSBus %d, Bridge %d",
                 attrs.vdn_bus_num,
                 BRIDGE_NUMBER);

        // Set Boot VCS Voltage - UltraTurbo Voltage from the MVPD data
        if(attrs.vcs_bus_num == 0xFF)
        {

            FAPI_INF("VCS rail is not connected to AVSBus. Skipping VCS programming");

        }
        else
        {

            FAPI_TRY(avsVoltageWrite(i_target,
                                     attrs.vcs_bus_num,
                                     BRIDGE_NUMBER,
                                     attrs.vcs_rail_select,
                                     attr_mvpd_data[ULTRA][1]),
                     "Setting VCS voltage via AVSBus %d, Bridge %d",
                     attrs.vcs_bus_num,
                     BRIDGE_NUMBER);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
} // Procedure
