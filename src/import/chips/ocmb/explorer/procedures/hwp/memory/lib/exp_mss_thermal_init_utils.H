/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/exp_mss_thermal_init_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file exp_mss_thermal_init_utils.H
/// @brief Thermal initialization utility functions
///
// *HWP HWP Owner: Sharath Manjunath <shamanj4@in.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _EXP_MSS_THERMAL_INIT_UTILS_H_
#define _EXP_MSS_THERMAL_INIT_UTILS_H_

#include <fapi2.H>
#include <mss_generic_attribute_getters.H>
#include <mss_explorer_attribute_getters.H>
#include <exp_data_structs.H>
#include <mss_generic_system_attribute_getters.H>
#include <lib/shared/exp_consts.H>

namespace mss
{
namespace exp
{

///
/// @brief Setup & perform sensor interval read
/// @param[in] i_target OCMB chip
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode sensor_interval_read(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief host_fw_command_struct structure setup
/// @param[in] i_port PORT target
/// @param[out] o_cmd the command parameters to set
///
fapi2::ReturnCode setup_sensor_interval_read_cmd_params(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port,
    host_fw_command_struct& o_cmd);

///
/// @brief Helper to check supported FW version
/// @param[in] i_fw_version FW version
/// @param[in] i_usage DTM usage
///
inline bool is_dtm_supported(const uint32_t i_fw_version,
                             const uint8_t i_usage)
{
    if (i_usage != fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_DIFF_USAGE_MB_INT_DTM)
    {
        return true;
    }

    return ( (i_fw_version >= fw_version::FW_DTM_SUPPORTED) || (i_fw_version == fw_version::FW_VER_BOOTLEG) );
}

namespace thermal
{

///
/// @brief Thermal Sensor Type
/// @note This is made to mirror the SPD-defined & attribute sensor enums (same for sensors 0, 1, differential)
///
enum thermal_sensor_type : uint8_t
{
    NO_SENSOR = fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_TYPE_NO_SENSOR,
    JC42 = fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_TYPE_JC42,
    EMC1412 = fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_TYPE_EMC1412,
};

///
/// @brief register read length
///
enum register_read_length
{
    ONE_BYTE = 0b00,
    TWO_BYTES = 0b01,
};

///
/// @brief on-chip register offset setting (command_argument[6] Bit 2)
///
enum onchip_register_offset_setting
{
    REG_SIZE_8_BIT = 0,
    REG_SIZE_16_BIT = 1,
};

///
/// @brief on-chip register offset values
///
enum onchip_register_offset
{
    EMC1412_LOW_BYTE = 0x10,
    EMC1412_HIGH_BYTE = 0x01,
};

///
/// @brief register read operations (command_argument[6] bit 1)
///
enum onchip_register_read_ops
{
    ONE_READ_OP = 0,
    TWO_READ_OPS = 1,
};

///
/// @brief Thermal sensor field settings class
///
class thermal_sensor_settings
{
    public:

        ///
        /// @brief Construct a new default thermal sensor fields object
        /// @note Default constructor sets default values to 0. This won't hurt the command, the command just won't do anything.
        ///
        thermal_sensor_settings() = default;

        ///
        /// @brief Get the settings for the provided thermal_sensor_type
        ///
        /// @param[in] i_port PORT target
        /// @param[in] i_type thermal sensor type
        /// @param[out] o_settings settings object
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else RC_MSS_EXP_UNKNOWN_THERMAL_SENSOR if unknown sensor type
        ///
        static fapi2::ReturnCode get_settings(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port,
                                              const thermal_sensor_type i_type,
                                              thermal_sensor_settings& o_settings)
        {
            o_settings = thermal_sensor_settings();

            switch (i_type)
            {
                case thermal_sensor_type::JC42:
                    {
                        o_settings.iv_num_bytes_rw = register_read_length::TWO_BYTES;
                        o_settings.iv_reg_offset = 0x05;

                        // Internal fields N/A for external sensor type

                        break;
                    }

                case thermal_sensor_type::EMC1412:
                    {
                        // Generic sensor fields
                        o_settings.iv_num_bytes_rw = register_read_length::ONE_BYTE;

                        // External sensor N/A for internal sensor

                        // On-chip/internal sensor fields
                        // As defined by Jira EDBC-560 for EMC1412
                        o_settings.iv_onchip_reg_offset_setting = onchip_register_offset_setting::REG_SIZE_8_BIT;
                        o_settings.iv_onchip_onchip_register_read_ops = onchip_register_read_ops::TWO_READ_OPS;
                        o_settings.iv_cmd_arg_8_onchip_reg_offset_0 = onchip_register_offset::EMC1412_LOW_BYTE;
                        // cmd_arg_9 0 because 8 bit register size
                        o_settings.iv_cmd_arg_10_onchip_reg_offset_1 = onchip_register_offset::EMC1412_HIGH_BYTE;
                        // cmd_arg_11 0 because 8 bit register size

                        break;
                    }

                case thermal_sensor_type::NO_SENSOR:
                    {
                        // Can use default 0 values. It won't hurt the command, just won't do anything.
                        break;
                    }

                default:
                    // Unsupported thermal sensor, assert out
                    FAPI_ASSERT(false,
                                fapi2::MSS_EXP_UNKNOWN_THERMAL_SENSOR()
                                .set_PORT_TARGET(i_port)
                                .set_VALUE(i_type),
                                "Value %u provided as a thermal sensor type for %s does not have an associated set of trait values",
                                i_type, mss::c_str(i_port));
            }

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Destroy the thermal sensor fields object
        ///
        ~thermal_sensor_settings() = default;

        // Generic sensor fields
        uint8_t iv_num_bytes_rw;

        // External sensor fields
        uint8_t iv_reg_offset;

        // On-chip/internal sensor fields
        uint8_t iv_onchip_reg_offset_setting;
        uint8_t iv_onchip_onchip_register_read_ops;
        uint8_t iv_cmd_arg_8_onchip_reg_offset_0;
        uint8_t iv_cmd_arg_9_onchip_reg_offset_0;
        uint8_t iv_cmd_arg_10_onchip_reg_offset_1;
        uint8_t iv_cmd_arg_11_onchip_reg_offset_1;
};

/// @brief cmd_flags bitmappings
/// @note these are buffer perspective (left) aligned
enum cmd_flags
{
    // cmd_flags mapped as follows:
    //
    // Bit 3: Onchip sensor is present
    // Bit 2: DIMM1 temperature sensor is present
    // Bit 1: DIMM0 temperature sensor is present
    // Bit 0: Additional data in 64k extended data space (unused here)
    DIMM0_SENSOR_PRESENT_BIT = 6,
    DIMM1_SENSOR_PRESENT_BIT = 5,
    ONCHIP_SENSOR_PRESENT_BIT = 4,
};

///
/// @brief Set the up cmd flags field
/// @param[in] i_port MEM_PORT for attribute access
/// @param[out] o_cmd_flags cmd flags field to setup
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode setup_cmd_flags(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> i_port,
    uint8_t& o_cmd_flags);

///
/// @brief Set the up cmd args for EXP_FW_TEMP_SENSOR_CONFIG_INTERVAL_READ
/// @param[in] i_port MEM_PORT target for attribute access
/// @param[out] o_cmd host_fw_commmand_struct to setup command args for
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode setup_cmd_args(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> i_port,
    host_fw_command_struct& o_cmd);

///
/// @brief Select external sensor and return its I2C address
/// @param[in] i_target MEM_PORT target
/// @param[in] i_secondary_sensor_avail value of ATTR_MEM_EFF_THERM_SENSOR_X_SECOND_AVAIL
/// @param[in] i_primary_sensor_location value of ATTR_MEM_EFF_THERM_SENSOR_X_LOCATION
/// @param[in] i_secondary_sensor_location value of ATTR_MEM_EFF_THERM_SENSOR_X_SECOND_LOCATION
/// @param[in] i_primary_sensor_i2c_addr value of ATTR_MEM_EFF_THERM_SENSOR_X_I2C_ADDR
/// @param[in] i_secondary_sensor_i2c_addr value of ATTR_MEM_EFF_THERM_SENSOR_X_SECOND_I2C_ADDR
/// @param[in] i_airflow_direction value of ATTR_MSS_MRW_DIMM_SLOT_AIRFLOW
/// @return I2C address of selected sensor
///
uint8_t select_ext_sensor(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                          const uint8_t i_secondary_sensor_avail,
                          const uint8_t i_primary_sensor_location,
                          const uint8_t i_secondary_sensor_location,
                          const uint8_t i_primary_sensor_i2c_addr,
                          const uint8_t i_secondary_sensor_i2c_addr,
                          const uint8_t i_airflow_direction);

} // ns thermal

namespace mc
{

///
/// @brief set the N/M throttle register to safemode values
/// @param[in] i_target the ocmb target
/// @return fapi2::fapi2_rc_success if ok
/// @Will be overwritten by OCC/cronus later in IPL
///
fapi2::ReturnCode setup_emergency_throttles(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief disable emergency mode throttle for thermal_init
/// @param[in] i_target the ocmb target
/// @return fapi2::fapi2_rc_success if ok
/// @note clears MB_SIM.SRQ.MBA_FARB7Q bit
///
fapi2::ReturnCode disable_safe_mode_throttles (const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

} // ns mc

namespace check
{

///
/// @brief Checks explorer response argument for a successful command
/// @param[in] i_target OCMB target
/// @param[in] i_rsp response command
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode sensor_response(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                  const host_fw_response_struct& i_rsp);

} // ns check

} // ns exp

} // ns mss

#endif
