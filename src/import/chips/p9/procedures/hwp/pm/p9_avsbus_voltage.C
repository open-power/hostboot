/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_avsbus_voltage.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file  p9_avsbus_voltage.C
/// @brief Read or Write External Voltage Rail Values
///
/// *HW Owner    : Sudheendra K Srivathsa <sudheendraks@in.ibm.com>
/// *FW Owner    : Sangeetha T S <sangeet2@in.ibm.com>
/// *Team        : PM
/// *Consumed by : FSP
/// *Level       : 2
///
/// @verbatim
///
/// Procedure Summary:
///   - Read or Write voltages VDD, VDN and VCS via the AVS bus to VRMs
///
/// @endverbatim

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_avsbus_voltage.H>
#include <p9_avsbus_lib.H>
#include <p9_avsbus_scom.H>

enum P9_AVSBUS_VOLTAGE_CONSTANTS
{
// By convention, the Pstate GPE will use bridge 0.  Other entities
// will use bridge 1
    BRIDGE_NUMBER = 1,
    AVSBUS_ACCESS_RETRY_COUNT = 5


// Default configuration, Bus Numbers and Rail Selects read through attributes
//    DEFAULT_VDD_BUS_NUMBER = 0,
//    DEFAULT_VDD_RAILSELECT = 0,
//    DEFAULT_VDN_BUS_NUMBER = 1,
//    DEFAULT_VDN_RAILSELECT = 0,
//    DEFAULT_VCS_BUS_NUMBER = 0,
//    DEFAULT_VCS_RAILSELECT = 1,

};
struct p9_avsbus_attrs_t
{
    uint8_t RailBusNum;
    uint8_t RailSelect;
};

// Based on i_voltage_rail selected, read corresponding attributes
fapi2::ReturnCode
p9avsInitAttributes( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                     const p9avslib::avsRails i_voltage_rail,
                     p9_avsbus_attrs_t* attrs
                   )
{
    if (i_voltage_rail == p9avslib::VDD)
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDD_AVSBUS_BUSNUM, i_target,
                               attrs->RailBusNum));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDD_AVSBUS_RAIL,  i_target,
                               attrs->RailSelect));
    }
    else if (i_voltage_rail == p9avslib::VDN)
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDN_AVSBUS_BUSNUM, i_target,
                               attrs->RailBusNum));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDN_AVSBUS_RAIL,  i_target,
                               attrs->RailSelect));
    }
    else if (i_voltage_rail == p9avslib::VCS)
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VCS_AVSBUS_BUSNUM, i_target,
                               attrs->RailBusNum));

        if(attrs->RailBusNum == 0xFF)
        {
            FAPI_ERR("Programming error via AVSBus, VCS rail not connected to AVSBus interface in the system.");
            FAPI_ASSERT(false,
                        fapi2::PM_VCS_RAIL_ERR()
                        .set_TARGET(i_target),
                        "ERROR: Programming error via AVSBus, VCS rail not connected to AVSBus interface in the system.");
        }

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VCS_AVSBUS_RAIL,  i_target,
                               attrs->RailSelect));
    }

fapi_try_exit:
    return fapi2::current_err;
}


fapi2::ReturnCode
p9_avsbus_voltage_read( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                        const avsbus_units_t& i_rail_output_mode,
                        const p9avslib::avsRails i_voltage_rail,
                        avsbus_data_t& o_voltage_data)
{

    p9_avsbus_attrs_t attrs;

    avsbus_data_t voltage_read_data;

    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint8_t> l_data8;
    uint8_t l_count = 0;

    // Read attribute -
    FAPI_INF("Reading AVSBus attributes for the selected voltage rail");
    FAPI_TRY(p9avsInitAttributes(i_target, i_voltage_rail, &attrs));

    // Initialize the buses
    FAPI_INF("Initializing AVSBus interface");
    FAPI_TRY(avsInitExtVoltageControl(i_target,
                                      attrs.RailBusNum, BRIDGE_NUMBER),
             "Initializing avsBus Num %d, bridge %d", attrs.RailBusNum, BRIDGE_NUMBER);


    l_count = 0;

    while (l_count < AVSBUS_ACCESS_RETRY_COUNT)
    {

        FAPI_INF("Sending an Idle frame before Voltage reads");
        FAPI_TRY(avsIdleFrame(i_target, attrs.RailBusNum, BRIDGE_NUMBER));

        FAPI_INF("Reading the specified voltage rail value");
        FAPI_TRY(avsVoltageRead(i_target, attrs.RailBusNum, BRIDGE_NUMBER,
                                attrs.RailSelect, voltage_read_data.o_voltage),
                 "AVS Voltage read transaction failed");


        l_data64.flush<0>();
        l_data8.flush<0>();

        FAPI_TRY(getScom(i_target,
                         p9avslib::OCB_O2SRD[attrs.RailBusNum][BRIDGE_NUMBER], l_data64));

        l_data64.extract(l_data8, 0, 1);

        if (l_data8 == 0)
        {
            break;
        }

        l_count++;
    }

    if (l_count >= AVSBUS_ACCESS_RETRY_COUNT)
    {

        FAPI_ASSERT(false, fapi2::PM_AVSBUS_READVOLTAGE_TIMEOUT().set_TARGET(i_target),
                    "ERROR; Voltage read to selected rail failed due to bad CRC,unknown command or unavailable resource");
    }

    o_voltage_data.o_voltage = voltage_read_data.o_voltage;

fapi_try_exit:
    return fapi2::current_err;
} // Procedure

fapi2::ReturnCode
p9_avsbus_voltage_write( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                         const avsbus_units_t& i_rail_output_mode,
                         const p9avslib::avsRails i_voltage_rail,
                         const uint32_t i_Voltage)
{

    p9_avsbus_attrs_t attrs;
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint8_t> l_data8;
    uint8_t l_count = 0;

    // Read attribute -
    FAPI_INF("Reading AVSBus attributes for the selected voltage rail");
    FAPI_TRY(p9avsInitAttributes(i_target, i_voltage_rail, &attrs));

    // Initialize the buses
    FAPI_INF("Initializing AVSBus interface");
    FAPI_TRY(avsInitExtVoltageControl(i_target,
                                      attrs.RailBusNum, BRIDGE_NUMBER),
             "Initializing avsBus Num %d, bridge %d", attrs.RailBusNum, BRIDGE_NUMBER);


    l_count = 0;

    while (l_count < AVSBUS_ACCESS_RETRY_COUNT)
    {

        FAPI_INF("Sending an Idle frame before Voltage writes");
        FAPI_TRY(avsIdleFrame(i_target, attrs.RailBusNum, BRIDGE_NUMBER));

        // Set the required voltage
        FAPI_INF("Setting the specified voltage rail value");
        FAPI_TRY(avsVoltageWrite(i_target, attrs.RailBusNum, BRIDGE_NUMBER,
                                 attrs.RailSelect, i_Voltage),
                 "Setting voltage via AVSBus %d, Bridge %d failed",
                 attrs.RailBusNum,
                 BRIDGE_NUMBER);

        l_data64.flush<0>();
        l_data8.flush<0>();

        FAPI_TRY(getScom(i_target,
                         p9avslib::OCB_O2SRD[attrs.RailBusNum][BRIDGE_NUMBER], l_data64));

        l_data64.extract(l_data8, 0, 1);

        if (l_data8 == 0)
        {
            break;
        }

        l_count++;
    }

    if (l_count >= AVSBUS_ACCESS_RETRY_COUNT)
    {
        FAPI_ASSERT(false, fapi2::PM_AVSBUS_WRITEVOLTAGE_TIMEOUT().set_TARGET(i_target),
                    "ERROR; Voltage write to selected rail failed due to bad CRC,unknown command or unavailable resource");

    }

fapi_try_exit:
    return fapi2::current_err;
} // Procedure
