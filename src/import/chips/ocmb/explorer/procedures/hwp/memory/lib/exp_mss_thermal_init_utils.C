/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/exp_mss_thermal_init_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file exp_mss_thermal_init_utils.C
/// @brief Thermal initialization utility functions
///
// *HWP HWP Owner: Sharath Manjunath <shamanj4@in.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/exp_mss_thermal_init_utils.H>
#include <lib/inband/exp_inband.H>
#include <lib/shared/exp_consts.H>
#include <generic/memory/lib/utils/c_str.H>
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>
#include <exp_data_structs.H>
#include <mss_explorer_attribute_getters.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/exp_attribute_accessors_manual.H>

namespace mss
{
namespace exp
{

///
/// @brief Setup & perform sensor interval read
/// @param[in] i_target OCMB chip
/// @param[in] i_override_sensor value of sensor selection override from procedure wrapper
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode sensor_interval_read(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const thermal::sensor_selection_override i_override_sensor)
{
    for (const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        uint8_t l_configured_thermal_sensors = 0;
        FAPI_TRY(mss::attr::get_module_thermal_sensors(l_port, l_configured_thermal_sensors));

        if (l_configured_thermal_sensors == 0)
        {
            continue;
        }

        {
            // Declare variables
            host_fw_command_struct l_cmd_sensor;
            host_fw_response_struct l_response;
            std::vector<uint8_t> l_rsp_data;

            // Sets up EXP_FW_TEMP_SENSOR_CONFIG_INTERVAL_READ cmd params
            FAPI_TRY(mss::exp::setup_sensor_interval_read_cmd_params(l_port, i_override_sensor, l_cmd_sensor));

            // Enable sensors
            FAPI_TRY( mss::exp::ib::putCMD(i_target, l_cmd_sensor),
                      "Failed putCMD() for  %s", mss::c_str(i_target) );

            FAPI_TRY( mss::exp::ib::getRSP(i_target, mss::exp::omi::EXP_FW_TEMP_SENSOR_CONFIG_INTERVAL_READ, l_response,
                                           l_rsp_data),
                      "Failed getRSP() for  %s", mss::c_str(i_target) );

            FAPI_TRY( mss::exp::check::sensor_response(i_target, l_response, l_cmd_sensor),
                      "Failed sensor_response() for  %s", mss::c_str(i_target) );
        }
    }

fapi_try_exit:

    // If we have a failing sensor response code, then log it as recovered
    // We do not want to exit an IPL or deconfigure a DIMM for a bad temperature sensor
    // Note: we are doing our error logging here rather than in check::sensor_response
    //       to allow check::sensor_response to return the RC for unit testing purposes
    mss::exp::check::log_sensor_cache_errors(fapi2::current_err);

    return fapi2::current_err;
}

///
/// @brief host_fw_command_struct structure setup
/// @param[in] i_port PORT target
/// @param[in] i_override_sensor value of sensor selection override from procedure wrapper
/// @param[out] o_cmd the command parameters to set
/// @return FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode setup_sensor_interval_read_cmd_params(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port,
    const thermal::sensor_selection_override i_override_sensor,
    host_fw_command_struct& o_cmd)
{
    memset(&o_cmd, 0, sizeof(host_fw_command_struct));

    uint32_t l_counter = 0;

    // Sets up EXP_FW_TEMP_SENSOR_CONFIG_INTERVAL_READ cmd params
    // Command is used to configure interval read options for temperature sensors
    o_cmd.cmd_id = mss::exp::omi::EXP_FW_TEMP_SENSOR_CONFIG_INTERVAL_READ;

    // Set up cmd flags field
    FAPI_TRY(thermal::setup_cmd_flags(i_port, o_cmd.cmd_flags));

    // Retrieve a unique sequence id for this transaction
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OCMB_COUNTER, mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_port), l_counter));
    o_cmd.request_identifier = l_counter;

    // Unused/don't care
    o_cmd.cmd_length = 0;

    // Unused, left as 0xFFFFFFFF as per exp fw spec
    o_cmd.cmd_crc = 0xFFFFFFFF;

    // Unused
    o_cmd.host_work_area = 0;
    o_cmd.cmd_work_area = 0;

    // o_cmd.command_argument
    FAPI_TRY(thermal::setup_cmd_args(i_port, i_override_sensor, o_cmd));

    // Print out relevant command information
    FAPI_DBG("%s cmd_id:     0x%02X", mss::c_str(i_port), o_cmd.cmd_id);
    FAPI_DBG("%s cmd_flags:  0x%02X", mss::c_str(i_port), o_cmd.cmd_flags);
    FAPI_DBG("%s req_id:     0x%04X", mss::c_str(i_port), o_cmd.request_identifier);
    FAPI_DBG("%s cmd_crc:    0x%02X", mss::c_str(i_port), o_cmd.cmd_crc);

    for (int i = 0; i < ARGUMENT_SIZE; ++i)
    {
        FAPI_DBG("%s cmd_arg[%u]:   0x%02X", mss::c_str(i_port), i, o_cmd.command_argument[i]);
    }

fapi_try_exit:
    return fapi2::current_err;
}

namespace thermal
{

///
/// @brief Set the up cmd flags field
/// @param[in] i_port MEM_PORT for attribute access
/// @param[out] o_cmd_flags cmd flags field to setup
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode setup_cmd_flags(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> i_port,
    uint8_t& o_cmd_flags)
{
    o_cmd_flags = 0;

    fapi2::buffer<uint8_t> l_cmd_flags;
    uint32_t l_fw_version = 0;

    // This is how we are defining the spd/attributes
    // therm_sensor_0_avail --> dimm0
    // therm_sensor_1_avail --> dimm1
    // therm_sensor_2_avail --> onchip/internal

    uint8_t l_sensor_0_avail = 0;
    uint8_t l_sensor_1_avail = 0;
    uint8_t l_diff_sensor_avail = 0;

    uint8_t l_sensor_0_usage = 0;
    uint8_t l_sensor_1_usage = 0;
    uint8_t l_diff_sensor_usage = 0;

    FAPI_TRY(mss::get_booted_fw_version(mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_port), l_fw_version));

    FAPI_TRY(mss::attr::get_therm_sensor_0_availability(i_port, l_sensor_0_avail));
    FAPI_TRY(mss::attr::get_therm_sensor_1_availability(i_port, l_sensor_1_avail));
    FAPI_TRY(mss::attr::get_therm_sensor_differential_availability(i_port, l_diff_sensor_avail));

    FAPI_TRY(mss::attr::get_therm_sensor_0_usage(i_port, l_sensor_0_usage));
    FAPI_TRY(mss::attr::get_therm_sensor_1_usage(i_port, l_sensor_1_usage));
    FAPI_TRY(mss::attr::get_therm_sensor_differential_usage(i_port, l_diff_sensor_usage));

    // Make sure usage is > DISABLED (0) and also marked as available
    l_cmd_flags.writeBit<DIMM0_SENSOR_PRESENT_BIT>(
        ((l_sensor_0_avail == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_AVAIL_AVAILABLE) &&
         (l_sensor_0_usage != fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_DISABLED)));

    l_cmd_flags.writeBit<DIMM1_SENSOR_PRESENT_BIT>(
        ((l_sensor_1_avail == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_1_AVAIL_AVAILABLE) &&
         (l_sensor_1_usage != fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_1_USAGE_DISABLED)));

    // Also, do not enable on-chip, non-remote sensor if FW doesn't support it
    l_cmd_flags.writeBit<ONCHIP_SENSOR_PRESENT_BIT>(
        (is_dtm_supported(l_fw_version, l_diff_sensor_usage) &&
         (l_diff_sensor_avail == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_DIFF_AVAIL_AVAILABLE) &&
         (l_diff_sensor_usage != fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_DIFF_USAGE_DISABLED)));

    o_cmd_flags = l_cmd_flags;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set the up cmd args for EXP_FW_TEMP_SENSOR_CONFIG_INTERVAL_READ
/// @param[in] i_port MEM_PORT target for attribute access
/// @param[in] i_override_sensor value of sensor selection override from procedure wrapper
/// @param[out] o_cmd host_fw_commmand_struct to setup command args for
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode setup_cmd_args(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> i_port,
    const sensor_selection_override i_override_sensor,
    host_fw_command_struct& o_cmd)
{
    // Sanity memset
    memset(&o_cmd.command_argument[0], 0, sizeof(o_cmd.command_argument));

    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    uint8_t l_sensor_0_type = 0;
    uint8_t l_sensor_1_type = 0;
    uint8_t l_differential_sensor_type = 0;
    uint32_t l_fw_version = 0;
    uint8_t l_airflow_direction = 0;

    FAPI_TRY(mss::attr::get_therm_sensor_0_type(i_port, l_sensor_0_type));
    FAPI_TRY(mss::attr::get_therm_sensor_1_type(i_port, l_sensor_1_type));
    FAPI_TRY(mss::attr::get_therm_sensor_differential_type(i_port, l_differential_sensor_type));
    FAPI_TRY(mss::get_booted_fw_version(mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_port), l_fw_version));
    FAPI_TRY(mss::attr::get_mrw_dimm_slot_airflow(l_airflow_direction));

    // Sensor 0 / DIMM 0
    {
        uint8_t l_secondary_sensor_avail = 0;
        uint8_t l_primary_sensor_location = 0;
        uint8_t l_secondary_sensor_location = 0;
        uint8_t l_primary_sensor_i2c_addr = 0;
        uint8_t l_secondary_sensor_i2c_addr = 0;
        uint8_t l_selected_i2c_addr = 0;
        thermal::thermal_sensor_settings l_settings;

        FAPI_TRY(mss::attr::get_therm_sensor_0_secondary_availability(i_port, l_secondary_sensor_avail));
        FAPI_TRY(mss::attr::get_therm_sensor_0_location(i_port, l_primary_sensor_location));
        FAPI_TRY(mss::attr::get_therm_sensor_0_secondary_location(i_port, l_secondary_sensor_location));
        FAPI_TRY(mss::attr::get_therm_sensor_0_i2c_addr(i_port, l_primary_sensor_i2c_addr));
        FAPI_TRY(mss::attr::get_therm_sensor_0_secondary_i2c_addr(i_port, l_secondary_sensor_i2c_addr));

        // Select primary or secondary sensor and get i2c address
        l_selected_i2c_addr = select_ext_sensor(i_port,
                                                l_secondary_sensor_avail,
                                                l_primary_sensor_location,
                                                l_secondary_sensor_location,
                                                l_primary_sensor_i2c_addr,
                                                l_secondary_sensor_i2c_addr,
                                                l_airflow_direction,
                                                i_override_sensor);

        // Construct settings object
        FAPI_TRY(thermal::thermal_sensor_settings::get_settings(
                     i_port,
                     static_cast<thermal::thermal_sensor_type>(l_sensor_0_type),
                     l_settings),
                 "Unknown thermal sensor type %u for %s", l_sensor_0_type, mss::c_str(i_port));

        // Insert i2c address
        o_cmd.command_argument[0] = l_selected_i2c_addr;

        // Insert reg offset and r/w length
        o_cmd.command_argument[1] = l_settings.iv_reg_offset;
        o_cmd.command_argument[2] = l_settings.iv_num_bytes_rw;
    }

    // Sensor 1 / DIMM 1
    {
        uint8_t l_secondary_sensor_avail = 0;
        uint8_t l_primary_sensor_location = 0;
        uint8_t l_secondary_sensor_location = 0;
        uint8_t l_primary_sensor_i2c_addr = 0;
        uint8_t l_secondary_sensor_i2c_addr = 0;
        uint8_t l_selected_i2c_addr = 0;
        thermal::thermal_sensor_settings l_settings;

        FAPI_TRY(mss::attr::get_therm_sensor_1_secondary_availability(i_port, l_secondary_sensor_avail));
        FAPI_TRY(mss::attr::get_therm_sensor_1_location(i_port, l_primary_sensor_location));
        FAPI_TRY(mss::attr::get_therm_sensor_1_secondary_location(i_port, l_secondary_sensor_location));
        FAPI_TRY(mss::attr::get_therm_sensor_1_i2c_addr(i_port, l_primary_sensor_i2c_addr));
        FAPI_TRY(mss::attr::get_therm_sensor_1_secondary_i2c_addr(i_port, l_secondary_sensor_i2c_addr));

        // Select primary or secondary sensor and get i2c address
        l_selected_i2c_addr = select_ext_sensor(i_port,
                                                l_secondary_sensor_avail,
                                                l_primary_sensor_location,
                                                l_secondary_sensor_location,
                                                l_primary_sensor_i2c_addr,
                                                l_secondary_sensor_i2c_addr,
                                                l_airflow_direction,
                                                i_override_sensor);

        // Construct settings object
        FAPI_TRY(thermal::thermal_sensor_settings::get_settings(
                     i_port,
                     static_cast<thermal::thermal_sensor_type>(l_sensor_1_type),
                     l_settings),
                 "Unknown thermal sensor type %u for %s", l_sensor_1_type, mss::c_str(i_port));

        // Insert i2c address
        o_cmd.command_argument[3] = l_selected_i2c_addr;

        // Insert reg offset and r/w length
        o_cmd.command_argument[4] = l_settings.iv_reg_offset;
        o_cmd.command_argument[5] = l_settings.iv_num_bytes_rw;
    }

    // Sensor 2 / Differential Buffer Thermal Sensor / Onchip / Internal Sensor
    {
        thermal::thermal_sensor_settings l_settings;

        // Construct settings object
        FAPI_TRY(thermal::thermal_sensor_settings::get_settings(
                     i_port,
                     static_cast<thermal::thermal_sensor_type>(l_differential_sensor_type),
                     l_settings),
                 "Unknown thermal sensor type %u for %s", l_differential_sensor_type, mss::c_str(i_port));

        // Command arg 6 is laid out as such:
        //
        // Bit 3-4: Onchip register read length
        // Bit 2: Onchip register offset setting (1: 16 bit reg size, 0: 8 bit reg size)
        // Bit 1: Number of reg read operations (1: 2 register read ops, 0: 1 register read op)
        // Bit 0: (1: FW managed onchip sensor, 0: I2C onchip sensor)

        // cmd_arg_6_fields
        // note: these are left aligned (buffer-perspective fields)
        enum cmd_arg_6_flds
        {
            ONCHIP_REG_READ_LENGTH_START    = 3,
            ONCHIP_REG_READ_LENGTH_LEN      = 2,
            ONCHIP_REG_OFFSET_SETTING       = 5,
            NUM_REG_READ_OPS                = 6,
            FW_MANAGED_ONCHIP_SENSOR        = 7,
        };

        fapi2::buffer<uint8_t> l_arg_6;
        uint8_t l_differential_usage = 0;
        FAPI_TRY(mss::attr::get_therm_sensor_differential_usage(i_port, l_differential_usage));

        // Skip on-chip sensor arguments if Explorer FW doesn't support sensor type
        if (is_dtm_supported(l_fw_version, l_differential_usage))
        {
            // Insert at bits 3-4 (right aligned)
            l_arg_6.insertFromRight<ONCHIP_REG_READ_LENGTH_START, ONCHIP_REG_READ_LENGTH_LEN>(l_settings.iv_num_bytes_rw);

            // Insert at bit 2 (right aligned)
            l_arg_6.writeBit<ONCHIP_REG_OFFSET_SETTING>(l_settings.iv_onchip_reg_offset_setting);

            // Insert at bit 1 (right aligned)
            l_arg_6.writeBit<NUM_REG_READ_OPS>(l_settings.iv_onchip_onchip_register_read_ops);

            // Insert at bit 0 (right aligned)

            // INTERNAL_DTM implies bit 0 high (FW managed on-chip sensor)
            // INTERNAL_DTM_REM implies bit 0 low (I2C on-chip sensor)
            l_arg_6.writeBit<FW_MANAGED_ONCHIP_SENSOR>(
                l_differential_usage == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_DIFF_USAGE_MB_INT_DTM);

            o_cmd.command_argument[6] = l_arg_6;

            // Direct mapping
            FAPI_TRY(mss::attr::get_therm_sensor_differential_i2c_addr(i_port, o_cmd.command_argument[7]));

            // cmd_argument[8-9 & 10-11]: register offset
            o_cmd.command_argument[8] = l_settings.iv_cmd_arg_8_onchip_reg_offset_0;
            o_cmd.command_argument[9] = l_settings.iv_cmd_arg_9_onchip_reg_offset_0;
            o_cmd.command_argument[10] = l_settings.iv_cmd_arg_10_onchip_reg_offset_1;
            o_cmd.command_argument[11] = l_settings.iv_cmd_arg_11_onchip_reg_offset_1;
        }
    }

    // Polling period
    {
        uint16_t l_polling_period = 0;

        FAPI_TRY(mss::attr::get_mrw_thermal_sensor_polling_period(l_polling_period));

        // command_argument[12] is the lower byte
        o_cmd.command_argument[12] = l_polling_period & 0xFF;

        // command_argument[13] is the upper byte
        o_cmd.command_argument[13] = (l_polling_period >> BITS_PER_BYTE) & 0xFF;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Select external sensor and return its I2C address
/// @param[in] i_target MEM_PORT target
/// @param[in] i_secondary_sensor_avail value of ATTR_MEM_EFF_THERM_SENSOR_X_SECOND_AVAIL
/// @param[in] i_primary_sensor_location value of ATTR_MEM_EFF_THERM_SENSOR_X_LOCATION
/// @param[in] i_secondary_sensor_location value of ATTR_MEM_EFF_THERM_SENSOR_X_SECOND_LOCATION
/// @param[in] i_primary_sensor_i2c_addr value of ATTR_MEM_EFF_THERM_SENSOR_X_I2C_ADDR
/// @param[in] i_secondary_sensor_i2c_addr value of ATTR_MEM_EFF_THERM_SENSOR_X_SECOND_I2C_ADDR
/// @param[in] i_airflow_direction value of ATTR_MSS_MRW_DIMM_SLOT_AIRFLOW
/// @param[in] i_override_sensor value of sensor selection override from procedure wrapper
/// @return I2C address of selected sensor
///
uint8_t select_ext_sensor(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                          const uint8_t i_secondary_sensor_avail,
                          const uint8_t i_primary_sensor_location,
                          const uint8_t i_secondary_sensor_location,
                          const uint8_t i_primary_sensor_i2c_addr,
                          const uint8_t i_secondary_sensor_i2c_addr,
                          const uint8_t i_airflow_direction,
                          const sensor_selection_override i_override_sensor)
{
    if (i_secondary_sensor_avail == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_SECOND_AVAIL_NOT_AVAILABLE)
    {
        FAPI_DBG("%s Selecting primary sensor at address 0x%02X since no secondary sensor available",
                 mss::c_str(i_target), i_primary_sensor_i2c_addr);
        return i_primary_sensor_i2c_addr;
    }

    // Check override first
    if (i_override_sensor != sensor_selection_override::NO_OVERRIDE)
    {
        return (i_override_sensor == sensor_selection_override::USE_PRIMARY_SENSOR) ?
               i_primary_sensor_i2c_addr : i_secondary_sensor_i2c_addr;
    }

    // Note: Sensor location enums are encoded as follows so the math works out:
    // ATTR_MSS_MRW_DIMM_SLOT_AIRFLOW: RIGHT_TO_LEFT = 0x00, LEFT_TO_RIGHT = 0x01
    // ATTR_MEM_EFF_THERM_SENSOR_X_LOCATION: LOWER_LEFT = 0, UPPER_LEFT = 1, LOWER_RIGHT = 2, UPPER_RIGHT = 3
    if (i_primary_sensor_location / 2 == i_airflow_direction)
    {
        FAPI_DBG("%s Selecting primary sensor at address 0x%02X since it's downstream",
                 mss::c_str(i_target), i_primary_sensor_i2c_addr);
        return i_primary_sensor_i2c_addr;
    }
    else if (i_secondary_sensor_location / 2 == i_airflow_direction)
    {
        FAPI_DBG("%s Selecting secondary sensor at address 0x%02X since it's downstream",
                 mss::c_str(i_target), i_secondary_sensor_i2c_addr);
        return i_secondary_sensor_i2c_addr;
    }

    FAPI_DBG("%s Selecting primary sensor at address 0x%02X since neither is downstream",
             mss::c_str(i_target), i_primary_sensor_i2c_addr);
    return i_primary_sensor_i2c_addr;
}

} // ns thermal

namespace mc
{

///
/// @brief set the N/M throttle register to safemode values
/// @param[in] i_target the ocmb target
/// @return fapi2::fapi2_rc_success if ok
/// @Will be overwritten by OCC/cronus later in IPL
///
fapi2::ReturnCode setup_emergency_throttles(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::buffer<uint64_t> l_data;
    uint32_t l_n_safemode_throttle_value = 0;
    uint32_t l_m_throttle_value = 0;
    uint16_t l_nslot_safe = 0;
    uint16_t l_nport_safe = 0;

    // Get the required values from the attributes
    for(const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        FAPI_TRY(mss::attr::get_safemode_dram_databus_util(l_port, l_n_safemode_throttle_value),
                 "Error in setup_emergency_throttles" );

        break;
    }

    FAPI_TRY(mss::attr::get_mrw_mem_m_dram_clocks(l_m_throttle_value), "Error in setup_emergency_throttles" );

    // Get the register to be programmed using getScom
    FAPI_TRY(fapi2::getScom(i_target, EXPLR_SRQ_MBA_FARB3Q, l_data), "Error in setup_emergency_throttles" );

    // Calculate Nslot and Nport throttles and set l_data
    // TK to use throttled_cmds function from commit 72525
    l_nslot_safe = (( l_n_safemode_throttle_value * l_m_throttle_value / 100 ) / 100 ) / 4;
    l_nport_safe = l_nslot_safe;
    l_data.insertFromRight<EXPLR_SRQ_MBA_FARB3Q_CFG_NM_N_PER_SLOT, EXPLR_SRQ_MBA_FARB3Q_CFG_NM_N_PER_SLOT_LEN>
    (l_nslot_safe);
    l_data.insertFromRight<EXPLR_SRQ_MBA_FARB3Q_CFG_NM_N_PER_PORT, EXPLR_SRQ_MBA_FARB3Q_CFG_NM_N_PER_PORT_LEN>
    (l_nport_safe);

    // Write it back using putScom
    FAPI_TRY(fapi2::putScom(i_target, EXPLR_SRQ_MBA_FARB3Q, l_data), "Error in setup_emergency_throttles" );
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR("Error setting safemode throttles for target %s", mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief disable emergency mode throttle for thermal_init
/// @param[in] i_target the ocmb target
/// @return fapi2::fapi2_rc_success if ok
/// @note clears MB_SIM.SRQ.MBA_FARB7Q bit
///
fapi2::ReturnCode disable_safe_mode_throttles (const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::buffer<uint64_t> l_data;

    // Get the register to be cleared
    FAPI_TRY(fapi2::getScom(i_target, EXPLR_SRQ_MBA_FARB7Q, l_data));

    // Clear the register and write it back to the address
    l_data.clearBit<EXPLR_SRQ_MBA_FARB7Q_EMER_THROTTLE_IP>();
    FAPI_TRY(fapi2::putScom(i_target, EXPLR_SRQ_MBA_FARB7Q, l_data));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

} // ns mc

namespace check
{

///
/// @brief Checks explorer response argument for a successful command
/// @param[in] i_target OCMB target
/// @param[in] i_rsp response command
/// @param[in] i_cmd command response
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode sensor_response(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                  const host_fw_response_struct& i_rsp,
                                  const host_fw_command_struct& i_cmd)
{
    uint32_t l_partition_id = 0;
    uint32_t l_fw_version_a = 0;
    uint32_t l_fw_version_b = 0;

    FAPI_TRY(mss::attr::get_exp_fw_partition_id(i_target, l_partition_id));
    FAPI_TRY(mss::attr::get_exp_fw_version_a(i_target, l_fw_version_a));
    FAPI_TRY(mss::attr::get_exp_fw_version_b(i_target, l_fw_version_b));

    // Check if cmd was successful.
    // EXP_FW_TEMP_SENSOR_CONFIG_INTERVAL_READ has 2 error bytes
    // in response_argument[1] and [2], record and print both.
    FAPI_ASSERT(i_rsp.response_argument[0] == mss::exp::omi::response_arg::RESPONSE_SUCCESS &&
                i_rsp.request_identifier == i_cmd.request_identifier &&
                i_rsp.response_id == i_cmd.cmd_id,
                fapi2::MSS_EXP_SENSOR_CACHE_ENABLE_FAILED().
                set_OCMB_TARGET(i_target).
                set_RSP_ID(i_rsp.response_id).
                set_CMD_ID(i_cmd.cmd_id).
                set_RSP_REQUEST_ID(i_rsp.request_identifier).
                set_CMD_REQUEST_ID(i_cmd.request_identifier).
                set_ERROR_CODE_1(i_rsp.response_argument[1]).
                set_ERROR_CODE_2(i_rsp.response_argument[2]).
                set_FW_PARTITION_ID(l_partition_id).
                set_FW_VERSION_A(l_fw_version_a).
                set_FW_VERSION_B(l_fw_version_b),
                "Failed to enable sensor cache for %s . Error codes: "
                "response_argument[1] = 0x%02X response_argument[2] = 0x%02X",
                mss::c_str(i_target), i_rsp.response_argument[1], i_rsp.response_argument[2]);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Logs a return code as recovered if it is a temperature sensor RC
/// @param[in,out] io_rc the RC
/// @note Only logs RC_MSS_EXP_SENSOR_CACHE_ENABLE_FAILED
///
void log_sensor_cache_errors(fapi2::ReturnCode& io_rc)
{
    if(uint64_t(fapi2::RC_MSS_EXP_SENSOR_CACHE_ENABLE_FAILED) == uint64_t(io_rc))
    {
        fapi2::logError(io_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);
        io_rc = fapi2::FAPI2_RC_SUCCESS;
    }
}

} // ns check

} // ns exp

} // ns mss
