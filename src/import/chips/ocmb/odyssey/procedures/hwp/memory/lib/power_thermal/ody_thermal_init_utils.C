/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/power_thermal/ody_thermal_init_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
/// @file ody_thermal_init_utils.C
/// @brief Odyssey's thermal init utility functions
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Sneha Kadam <Sneha.Kadam1@ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB, FSP, SBE
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <i2c_access.H>
#include <vector>

#include <lib/power_thermal/ody_thermal_init_utils.H>
#include <lib/shared/ody_consts.H>
#include <ody_scom_ody_odc.H>
#include <ody_scom_ody_t.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/pos.H>
#include <mss_generic_system_attribute_getters.H>
#include <ody_dts_read.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/power_thermal/gen_throttle.H>

namespace mss
{
namespace ody
{
namespace thermal
{
namespace i2c
{

///
/// @brief Helper function setup i2c reads to the DIMM thermal sensors
/// @param[in] i_reg the register to read
/// @param[in,out] io_vector the vector of i2c data
///
void read_dts_helper(const uint8_t i_reg, std::vector<uint8_t>& io_vector)
{
    // The host should take care of the sensor ID and routing
    // The register is taken care of by passing it in here

    io_vector.clear();
    io_vector.push_back(i_reg);
}

///
/// @brief Helper function setup i2c reads from the DIMM thermal sensors
/// @param[in] i_target the i2c responder target
/// @param[in] i_reg the register to write to
/// @param[out] o_data the data
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode read_dts(const fapi2::Target<fapi2::TARGET_TYPE_TEMP_SENSOR>& i_target,
                           const uint8_t i_reg,
                           fapi2::buffer<uint16_t>& o_data)
{
    constexpr uint8_t DATA_SIZE_IN_BYTES = 2;
    std::vector<uint8_t> l_command;
    std::vector<uint8_t> l_data;
    read_dts_helper(i_reg, l_command);

    FAPI_TRY(fapi2::getI2c(i_target, DATA_SIZE_IN_BYTES, l_command, l_data));

    o_data.insertFromRight<            0, BITS_PER_BYTE>(l_data[0]);
    o_data.insertFromRight<BITS_PER_BYTE, BITS_PER_BYTE>(l_data[1]);

fapi_try_exit:
    return fapi2::current_err;
}

} // ns i2c

///
/// @brief Function that reads and processes the thermal information
/// @param[in] i_ocmb the OCMB target
/// @param[in] i_i2c the i2c responder target
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode thermal_sensor::read(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb,
                                       const fapi2::Target<fapi2::TARGET_TYPE_TEMP_SENSOR>& i_i2c) const
{
    fapi2::buffer<uint64_t> l_data;

    // Mark the sensor as present
    // Note: the cache registers use the same API, using D0THERM for the enumerated bits
    l_data.setBit<scomt::ody::ODC_MMIO_SNSC_D0THERM_PRESENTBIT>();

    fapi2::buffer<uint16_t> l_i2c_data;

    // Read the data
    FAPI_TRY(i2c_read_helper(i_i2c, l_i2c_data));

    // Assemble the data
    // Note: the cache registers use the same API, using D0THERM for the enumerated bits
    l_data.setBit<scomt::ody::ODC_MMIO_SNSC_D0THERM_VALIDBIT>()
    .insertFromRight<scomt::ody::ODC_MMIO_SNSC_D0THERM_THERMALDATA, scomt::ody::ODC_MMIO_SNSC_D0THERM_THERMALDATA_LEN>
    (l_i2c_data);

fapi_try_exit:
    return process_results(i_ocmb, iv_reg_addr, l_data);
}

///
/// @brief Helper function to conduct the i2c reads
/// @param[in] i_i2c the i2c responder target
/// @param[out] o_i2c_data the data read from the i2c register
/// @return FAPI2_RC_SUCCESS iff okay
/// @note allows for a shim to be made for unit testing
///
fapi2::ReturnCode thermal_sensor::i2c_read_helper(const fapi2::Target<fapi2::TARGET_TYPE_TEMP_SENSOR>& i_i2c,
        fapi2::buffer<uint16_t>& o_i2c_data) const
{
    // The register to read is taken from the thermal sensor specification
    constexpr uint8_t SENSOR_DATA_REG = 0x05;
    return i2c::read_dts(i_i2c, SENSOR_DATA_REG, o_i2c_data);
}

///
/// @brief Reset I2C controller
/// @param[in] i_ocmb the OCMB target
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode reset_i2cc(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb)
{
    fapi2::ATTR_FREQ_OMI_MHZ_Type l_freq_omi_mhz;
    fapi2::ATTR_IS_SIMICS_Type l_is_simics;
    uint64_t l_brd = 0;
    fapi2::buffer<uint64_t> l_i2cc_imm_reset_data = 0;
    fapi2::buffer<uint64_t> l_i2cc_mode_data = 0;
    fapi2::buffer<uint64_t> l_i2cc_cmd_data = 0;
    fapi2::buffer<uint64_t> l_i2cc_status_data_exp = 0;
    fapi2::buffer<uint64_t> l_i2cc_status_data_act = 0;

    FAPI_TRY(mss::attr::get_is_simics(l_is_simics));

    if (l_is_simics)
    {
        // skip in Simics
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // reset i2cc logic
    FAPI_TRY(fapi2::putScom(i_ocmb, scomt::ody::T_TPCHIP_PIB_I2CC_IMM_RESET_I2C_B, l_i2cc_imm_reset_data));

    // configure i2c mode register
    // BRD field:
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_OMI_MHZ, i_ocmb, l_freq_omi_mhz));
    l_brd = ((((l_freq_omi_mhz / 128) * 1000) / 400) - 1) / 4;
    l_i2cc_mode_data.insertFromRight<scomt::ody::T_TPCHIP_PIB_I2CC_MODE_REGISTER_B_BIT_RATE_DIVISOR_000,
                                     scomt::ody::T_TPCHIP_PIB_I2CC_MODE_REGISTER_B_BIT_RATE_DIVISOR_000_LEN>(l_brd & 0xFFFFULL);
    l_i2cc_mode_data.setBit<scomt::ody::T_TPCHIP_PIB_I2CC_MODE_REGISTER_B_FGAT_MODE_000>();
    FAPI_TRY(fapi2::putScom(i_ocmb, scomt::ody::T_TPCHIP_PIB_I2CC_MODE_REGISTER_B, l_i2cc_mode_data));

    // send stop command to reset downstream thermal sensor devices
    l_i2cc_cmd_data.setBit<scomt::ody::T_TPCHIP_PIB_I2CC_COMMAND_REGISTER_B_WITH_STOP_000>();
    FAPI_TRY(fapi2::putScom(i_ocmb, scomt::ody::T_TPCHIP_PIB_I2CC_COMMAND_REGISTER_B, l_i2cc_cmd_data));
    FAPI_TRY(fapi2::delay(10000000, 10000000));

    // confirm clean status
    l_i2cc_status_data_exp.setBit<scomt::ody::T_TPCHIP_PIB_I2CC_STATUS_REGISTER_ENGINE_B_CMD_COMPLETE_000>()
    .setBit<scomt::ody::T_TPCHIP_PIB_I2CC_STATUS_REGISTER_ENGINE_B_SCL_SYN_000>()
    .setBit<scomt::ody::T_TPCHIP_PIB_I2CC_STATUS_REGISTER_ENGINE_B_SDA_SYN_000>()
    .insertFromRight<scomt::ody::T_TPCHIP_PIB_I2CC_STATUS_REGISTER_ENGINE_B_PEEK_DATA1_000, scomt::ody::T_TPCHIP_PIB_I2CC_STATUS_REGISTER_ENGINE_B_PEEK_DATA1_000_LEN>
    (0x1);

    FAPI_TRY(fapi2::getScom(i_ocmb, scomt::ody::T_TPCHIP_PIB_I2CC_STATUS_REGISTER_ENGINE_B, l_i2cc_status_data_act));
    FAPI_ASSERT(l_i2cc_status_data_exp == l_i2cc_status_data_act,
                fapi2::ODYSSEY_I2CC_RESET_ERROR()
                .set_OCMB_TARGET(i_ocmb)
                .set_STATUS_DATA(l_i2cc_status_data_act),
                "Unexpected state after i2cc reset (a: 0x%08X%08X, e: 0x%08X%08X)",
                l_i2cc_status_data_act >> 32, l_i2cc_status_data_act & 0xFFFFFFFF,
                l_i2cc_status_data_exp >> 32, l_i2cc_status_data_exp & 0xFFFFFFFF);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Processes the results for this thermal sensor and writes them into the sensor cache register
/// @param[in] i_ocmb the OCMB target
/// @param[in] i_reg_addr the register address upon which to operate
/// @param[in] i_data register data to write. Note: this is not a pass-by-reference as it could be updated internally
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode process_results(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb,
                                  const uint64_t i_reg_addr,
                                  fapi2::buffer<uint64_t> i_data)
{
    // If the current error is not successful, mark it as recovered
    if(fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
    {
        // Note: this code does discard the current error
        // Normally, this would go against common design principles
        // However, this code will be called within an asynchronous thread running on the SPPE
        // As such, fapi asserts and log errors will not work
        // The SPPE and hostboot teams agreed that discarding the error is the correct approach
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

        // Note: the cache registers use the same API, using D0THERM for the enumerated bits
        i_data.setBit<scomt::ody::ODC_MMIO_SNSC_D0THERM_ERRORBIT>();
    }

    // Write out the data to the storage address
    return fapi2::putScom(i_ocmb, i_reg_addr, i_data);
}

///
/// @brief Processes the results for the On-Chip (OC) thermal sensor
/// @param[in] i_ocmb the OCMB target
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode read_oc_results(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb)
{
    fapi2::buffer<uint64_t> l_data;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    // Mark the sensor as present
    // Note: the cache registers use the same API, using D0THERM for the enumerated bits
    l_data.setBit<scomt::ody::ODC_MMIO_SNSC_D0THERM_PRESENTBIT>();

    int16_t l_oc_temp;

    // Read the data
    FAPI_EXEC_HWP(l_rc, ody_dts_read, i_ocmb, l_oc_temp);
    FAPI_TRY(l_rc);

    // Assemble the data
    // Note: the cache registers use the same API, using D0THERM for the enumerated bits
    l_data.setBit<scomt::ody::ODC_MMIO_SNSC_D0THERM_VALIDBIT>()
    .insertFromRight<scomt::ody::ODC_MMIO_SNSC_D0THERM_THERMALDATA, scomt::ody::ODC_MMIO_SNSC_D0THERM_THERMALDATA_LEN>
    (static_cast<uint16_t>(l_oc_temp));

fapi_try_exit:
    return process_results(i_ocmb, scomt::ody::ODC_MMIO_SNSC_OCTHERM, l_data);
}

///
/// @brief Function that reads and processes all thermal sensors
/// @param[in] i_ocmb the OCMB target
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode read_dts_sensors(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb)
{
    static constexpr thermal_sensor thermal_sensor_info[NUM_DTS] =
    {
        thermal_sensor(scomt::ody::ODC_MMIO_SNSC_D0THERM),
        thermal_sensor(scomt::ody::ODC_MMIO_SNSC_D1THERM),
        thermal_sensor(scomt::ody::ODC_MMIO_SNSC_D2THERM),
        thermal_sensor(scomt::ody::ODC_MMIO_SNSC_D3THERM),
    };

    // Loops over and reads out all thermal sensor information
    for(const auto& l_sensor : mss::find_targets<fapi2::TARGET_TYPE_TEMP_SENSOR>(i_ocmb))
    {
        // Should be 0-3, but using a modulo operation for safety's sake
        const auto l_sensor_pos = mss::relative_pos<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>
                                  (l_sensor) % NUM_DTS;

        // Read and cache the sensor value
        FAPI_TRY(thermal_sensor_info[l_sensor_pos].read(i_ocmb, l_sensor));
    }

    FAPI_TRY(read_oc_results(i_ocmb));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Function that initializes runtime SPPE polling attr
/// @param[in] i_ocmb the OCMB target
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode init_sppe_polling_attr(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb)
{

    uint32_t l_temp_polling_period_ms;
    uint8_t l_temp_dqs_tracking_period;

    // Get Init values from init attrs
    FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_ODY_SENSOR_POLLING_PERIOD_MS_INIT,
                             i_ocmb,
                             l_temp_polling_period_ms) );
    FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_ODY_DQS_TRACKING_PERIOD_INIT,
                             i_ocmb,
                             l_temp_dqs_tracking_period));

    // Set runtime attrs
    FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_ODY_SENSOR_POLLING_PERIOD_MS,
                             i_ocmb,
                             l_temp_polling_period_ms) );
    FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_ODY_DQS_TRACKING_PERIOD,
                             i_ocmb,
                             l_temp_dqs_tracking_period));

fapi_try_exit:
    return fapi2::current_err;
}

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
    uint32_t l_safemode_util_value = 0;
    uint32_t l_m_throttle_value = 0;
    uint16_t l_nslot_safe = 0;
    uint16_t l_nport_safe = 0;
    uint16_t l_n_safemode_throttle_value = 0;

    //  Since emergency mode throttles only use one N for both slot and port that is essentially
    //  optimized so let's optimize the throttles in this funtion to align with that
    bool l_optimize_nslot = true;

    const auto l_port_count = mss::count_mem_port(i_target);

    // Get the required values from the attributes
    for(const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        FAPI_TRY(mss::attr::get_safemode_dram_databus_util(l_port, l_safemode_util_value),
                 "Error in setup_emergency_throttles" );

        break;
    }

    FAPI_TRY(mss::attr::get_mrw_mem_m_dram_clocks(l_m_throttle_value), "Error in setup_emergency_throttles" );

    // Get the register to be programmed using getScom
    FAPI_TRY(fapi2::getScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB3Q, l_data), "Error in setup_emergency_throttles" );

    // Calculate Nslot and Nport throttles and set l_data
    // TODO: Zen:MST-1818 Will need to call MC-specific version of this once BL16 is supported
    l_n_safemode_throttle_value = mss::power_thermal::calc_n_from_dram_util(l_safemode_util_value, l_m_throttle_value);
    l_nslot_safe = (l_optimize_nslot) ? l_n_safemode_throttle_value * l_port_count : l_n_safemode_throttle_value;
    l_nport_safe = l_n_safemode_throttle_value * l_port_count;
    l_data.insertFromRight<scomt::ody::ODC_SRQ_MBA_FARB3Q_CFG_NM_N_PER_SLOT, scomt::ody::ODC_SRQ_MBA_FARB3Q_CFG_NM_N_PER_SLOT_LEN>
    (l_nslot_safe);
    l_data.insertFromRight<scomt::ody::ODC_SRQ_MBA_FARB3Q_CFG_NM_N_PER_PORT, scomt::ody::ODC_SRQ_MBA_FARB3Q_CFG_NM_N_PER_PORT_LEN>
    (l_nport_safe);

    // Write it back using putScom
    FAPI_TRY(fapi2::putScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB3Q, l_data), "Error in setup_emergency_throttles" );

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR("Error setting safemode throttles for target " TARGTIDFORMAT, TARGTID);
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
    FAPI_TRY(fapi2::getScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB7Q, l_data));

    // Clear the register and write it back to the address
    l_data.clearBit<scomt::ody::ODC_SRQ_MBA_FARB7Q_MBA_FARB7Q_EMER_THROTTLE_IP>();
    FAPI_TRY(fapi2::putScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB7Q, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

} // ns mc

} // ns thermal
} // ns ody
} // ns mss
