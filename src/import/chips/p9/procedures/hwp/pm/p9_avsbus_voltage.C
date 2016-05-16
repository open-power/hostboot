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
    BRIDGE_NUMBER = 1

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

    p9avslib::avsBusNum l_avs_bus_num = p9avslib::AVSBUSVDD;

    avsbus_data_t voltage_read_data;

    //@TODO RTC 156536 - Remove code once p9_avsbus_lib function is updated to read bus num directly from attributes
    if (i_voltage_rail == p9avslib::VDD)
    {
        l_avs_bus_num = p9avslib::AVSBUSVDD;
    }
    else if (i_voltage_rail == p9avslib::VDN)
    {
        l_avs_bus_num = p9avslib::AVSBUSVDN;
    }
    else if (i_voltage_rail == p9avslib::VCS)
    {
        l_avs_bus_num = p9avslib::AVSBUSVCS;
    }

    // Read attribute -
    FAPI_INF("Reading AVSBus attributes for the selected voltage rail");
    FAPI_TRY(p9avsInitAttributes(i_target, i_voltage_rail, &attrs));

    //@TODO RTC 156536 - Replace with attrs.RailBusNum once  p9_avsbus_lib function is updated to read bus num directly from attributes
    // Initialize the buses
    FAPI_INF("Initializing AVSBus interface");
    FAPI_TRY(avsInitExtVoltageControl(i_target,
                                      l_avs_bus_num, BRIDGE_NUMBER),
             "Initializing avsBus Num %d, bridge %d", l_avs_bus_num, BRIDGE_NUMBER);

    FAPI_INF("Reading the specified voltage rail value");
    FAPI_TRY(avsVoltageRead(i_target, attrs.RailBusNum, BRIDGE_NUMBER,
                            attrs.RailSelect, &voltage_read_data.o_voltage),
             "AVS Voltage read transaction failed");

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

    p9avslib::avsBusNum l_avs_bus_num = p9avslib::AVSBUSVDD;

    //@TODO RTC 156536- Remove code once p9_avsbus_lib function is updated to read bus num directly from attributes
    if (i_voltage_rail == p9avslib::VDD)
    {
        l_avs_bus_num = p9avslib::AVSBUSVDD;
    }
    else if (i_voltage_rail == p9avslib::VDN)
    {
        l_avs_bus_num = p9avslib::AVSBUSVDN;
    }
    else if (i_voltage_rail == p9avslib::VCS)
    {
        l_avs_bus_num = p9avslib::AVSBUSVCS;
    }

    // Read attribute -
    FAPI_INF("Reading AVSBus attributes for the selected voltage rail");
    FAPI_TRY(p9avsInitAttributes(i_target, i_voltage_rail, &attrs));

    //@TODO RTC 156536 - Replace with attrs.RailBusNum once  p9_avsbus_lib function is updated to read bus num directly from attributes
    // Initialize the buses
    FAPI_INF("Initializing AVSBus interface");
    FAPI_TRY(avsInitExtVoltageControl(i_target,
                                      l_avs_bus_num, BRIDGE_NUMBER),
             "Initializing avsBus Num %d, bridge %d", l_avs_bus_num, BRIDGE_NUMBER);

    // Set the required voltage
    FAPI_INF("Setting the specified voltage rail value");
    FAPI_TRY(avsVoltageWrite(i_target, attrs.RailBusNum, BRIDGE_NUMBER,
                             attrs.RailSelect, i_Voltage),
             "Setting voltage via AVSBus %d, Bridge %d",
             attrs.RailBusNum,
             BRIDGE_NUMBER);

fapi_try_exit:
    return fapi2::current_err;
} // Procedure
