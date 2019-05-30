/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/exp_mss_thermal_init_utils.C $ */
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
/// @file exp_mss_thermal_init_utils.C
/// @brief Thermal initialization utility functions
///
// *HWP HWP Owner: Sharath Manjunath <shamanj4@in.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/exp_mss_thermal_init_utils.H>
#include <exp_inband.H>
#include <lib/shared/exp_consts.H>
#include <generic/memory/lib/utils/c_str.H>
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>

namespace mss
{
namespace exp
{

///
/// @brief host_fw_command_struct structure setup
/// @param[out] o_cmd the command parameters to set
///
void setup_sensor_interval_read_cmd_params(host_fw_command_struct& o_cmd)
{
    // Sets up EXP_FW_TEMP_SENSOR_CONFIG_INTERVAL_READ cmd params
    // Command is used to configure interval read options for temperature sensors
    o_cmd.cmd_id = mss::exp::omi::EXP_FW_TEMP_SENSOR_CONFIG_INTERVAL_READ;
    o_cmd.cmd_flags = 0;
    o_cmd.request_identifier = 0;
    o_cmd.cmd_length = 0;
    o_cmd.cmd_crc = 0xFFFFFFFF;
    o_cmd.host_work_area = 0;
    o_cmd.cmd_work_area = 0;
    memset(o_cmd.padding, 0, sizeof(o_cmd.padding));
    memset(o_cmd.command_argument, 0, sizeof(o_cmd.command_argument));
    o_cmd.command_argument[0] = 0x30;  // i2c address of first sensor 0x30
    o_cmd.command_argument[1] = 0x14;  // i2c address register offset 0x05, and size b00 (1 byte)
    o_cmd.command_argument[2] = 0x00;  // 2 and 3 together defines the interval
    o_cmd.command_argument[3] = 0x1E;  // interval in ms 30ms for first sensor
    o_cmd.command_argument[4] = 0x32;  // i2c address of second sensor 0x32
    o_cmd.command_argument[5] = 0x14;  // i2c address register offset 0x05, and size b00 (1 byte)
    o_cmd.command_argument[6] = 0x00;  // 6 and 7 together defines the interval
    o_cmd.command_argument[7] = 0x1E;  // interval in ms 30ms for second sensor
    o_cmd.command_argument[8] = 0x00;  // 8 and 9 together defines the interval
    o_cmd.command_argument[9] = 0x1E;  // interval in ms 30ms for Onchip sensor
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
    uint32_t l_n_safemode_throttle_value = 0;
    uint32_t l_m_throttle_value = 0;
    uint16_t l_nslot_safe = 0;
    uint16_t l_nport_safe = 0;

    // Get the required values from the mrw attributes
    FAPI_TRY(mss::attr::get_mrw_safemode_dram_databus_util(l_n_safemode_throttle_value),
             "Error in setup_emergency_throttles" );
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
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode sensor_response(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                  const host_fw_response_struct& i_rsp)
{
    // Check if cmd was successful
    FAPI_ASSERT(i_rsp.response_argument[0] == mss::exp::omi::response_arg::SUCCESS,
                fapi2::MSS_EXP_SENSOR_CACHE_ENABLE_FAILED().
                set_TARGET(i_target).
                set_RSP_ID(i_rsp.response_id).
                set_ERROR_CODE(i_rsp.response_argument[1]),
                "Failed to enable sensor cache for %s", mss::c_str(i_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

} // ns check

} // ns exp

} // ns mss
