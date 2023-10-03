/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ody_dqs_track_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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

// EKB-Mirror-To: hostboot

///
/// @file ody_dqs_track_utils.C
/// @brief DQS tracking utils
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: David J Chung <dj.chung@ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <vector>

#include <ody_dqs_track_utils.H>
#include <lib/dimm/ody_rank.H>
#include <ody_scom_ody_odc.H>
#include <lib/shared/ody_consts.H>
#include <lib/ccs/ody_ccs_traits.H>
#include <lib/mc/ody_port_traits.H>
#include <lib/mcbist/ody_mcbist_traits.H>
#include <lib/ccs/ody_ccs.H>
#include <generic/memory/lib/ccs/ccs_ddr5_commands.H>
#include <lib/power_thermal/ody_thermal_init_utils.H>

namespace mss
{
namespace ody
{

///
/// @brief Maps DQS interval timer value to MR value encoding
/// @param [in] i_timer_val timer value in clocks from attribute
/// @return encoded MR value representing i_timer_val
///
uint8_t map_dqs_timer_val(const uint16_t i_timer_val)
{
    // Values taken from Jedec DDR5 spec JESD79-5B_v1.20 MR45 table
    // All values up to 1008 are just value/16
    if (i_timer_val <= 1008)
    {
        return i_timer_val / 16;
    }

    // Set all values between 1009 and 2048 clocks to the 2048 value
    if (i_timer_val <= 2048)
    {
        return 0x40;
    }

    // Set all values between 2049 and 4096 clocks to the 4096 value
    if (i_timer_val <= 4096)
    {
        return 0x80;
    }

    // Set all higher values to the 8192 value
    return 0xC0;
}

///
/// @brief Asserts snoop on MSB or LSB for DQS->DQ tracking
/// @param [in] i_target OCMB to assert snoop on
/// @param [in] i_mr_number mr to asset snoop on, should only be 46 or 47
/// @return fapi2::FAPI2_RC_SUCCESS iff successful, fapi2 error code otherwise
///
fapi2::ReturnCode assert_mr_snoop (
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const drift_track_mr i_mr_number)
{
    fapi2::buffer<uint64_t> l_farb2q_data;
    FAPI_TRY(getScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB2Q, l_farb2q_data));

    // Clear both bits first
    l_farb2q_data.clearBit<scomt::ody::ODC_SRQ_MBA_FARB2Q_CFG_CCS_SNOOP_EN_LSB>();
    l_farb2q_data.clearBit<scomt::ody::ODC_SRQ_MBA_FARB2Q_CFG_CCS_SNOOP_EN_MSB>();

    if (i_mr_number == drift_track_mr::LSB_MR)
    {
        l_farb2q_data.setBit<scomt::ody::ODC_SRQ_MBA_FARB2Q_CFG_CCS_SNOOP_EN_LSB>();
    }
    else
    {
        l_farb2q_data.setBit<scomt::ody::ODC_SRQ_MBA_FARB2Q_CFG_CCS_SNOOP_EN_MSB>();
    }

    FAPI_TRY(putScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB2Q, l_farb2q_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Disables snoop on MSB or LSB for DQS->DQ tracking
/// @param [in] i_target OCMB to assert snoop on
/// @return fapi2::FAPI2_RC_SUCCESS iff successful, fapi2 error code otherwise
///
fapi2::ReturnCode disable_mr_snoop(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::buffer<uint64_t> l_farb2q_data;
    FAPI_TRY(getScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB2Q, l_farb2q_data));

    l_farb2q_data.clearBit<scomt::ody::ODC_SRQ_MBA_FARB2Q_CFG_CCS_SNOOP_EN_LSB>();
    l_farb2q_data.clearBit<scomt::ody::ODC_SRQ_MBA_FARB2Q_CFG_CCS_SNOOP_EN_MSB>();

    FAPI_TRY(putScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB2Q, l_farb2q_data));

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Prepares mrr ccs instructions for given mr
/// @param [in] i_rank_info rank info
/// @param [in] i_mr_number mr to to be read
/// @param[in,out] io_program the ccs program
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode prepare_mrr_ccs(
    const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
    const drift_track_mr i_mr_number,
    mss::ccs::program<mss::mc_type::ODYSSEY>& io_program)
{
    // Idling until the data is returned by the DRAM to ensure it's logged by the PHY
    constexpr uint64_t IDLES = 128;
    const auto& l_port_rank = i_rank_info.get_port_rank();
    // Create local mrr instruction for LSB/MSB snoop
    mss::ccs::instruction_t<mss::mc_type::ODYSSEY> l_inst;

    l_inst = mss::ccs::ddr5::mrr_command<mss::mc_type::ODYSSEY>(l_port_rank, uint64_t(i_mr_number), IDLES);
    io_program.iv_instructions.push_back(l_inst);

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Prepares mrw ccs instructions for given mr
/// @param [in] i_rank_info rank info
/// @param [in,out] io_program the ccs program
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode set_dqs_timer_val(
    const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
    mss::ccs::program<mss::mc_type::ODYSSEY>& io_program)
{
    constexpr uint64_t DQS_INTERVAL_MR = 45;
    constexpr uint16_t TMRD = 34;

    mss::ccs::instruction_t<mss::mc_type::ODYSSEY> l_inst;
    uint16_t l_dqs_interval = 0;
    uint8_t l_encoded = 0;
    const auto& l_port_rank = i_rank_info.get_port_rank();
    const auto& l_port_target = i_rank_info.get_port_target();

    // Grab dqs value from attr
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DQS_OSC_RUNTIME_SEL, l_port_target, l_dqs_interval));
    l_encoded = map_dqs_timer_val(l_dqs_interval);

    FAPI_DBG(GENTARGTIDFORMAT " DQS interval: 0x%04X (encoded to: 0x%02X)",
             GENTARGTID(l_port_target), l_dqs_interval, l_encoded);

    l_inst = mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>(l_port_rank, DQS_INTERVAL_MR, l_encoded, TMRD);
    io_program.iv_instructions.push_back(l_inst);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Prepares oscillator start mpc command for ccs inst
/// @param [in] i_rank_info rank info
/// @param [in] i_op the operator for this MPC command OP[7:0]
/// @param [in,out] io_program the ccs program
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode prepare_oscillator_mpc(
    const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
    const mpc_command i_op,
    mss::ccs::program<mss::mc_type::ODYSSEY>& io_program)
{
    mss::ccs::instruction_t<mss::mc_type::ODYSSEY> l_inst;
    uint16_t l_dqs_interval = 0;
    const auto& l_port_rank = i_rank_info.get_port_rank();
    const auto& l_port_target = i_rank_info.get_port_target();

    if (i_op == mpc_command::OSCILLATOR_START)
    {
        // Oscillator time delay is tMRD + the DQS interval
        // using the maximum tMRD (34 clocks at 4800)
        constexpr uint64_t tMRD = 34;

        // Grab dqs value to delay to cover timer setting programmed into mr45
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DQS_OSC_RUNTIME_SEL, l_port_target, l_dqs_interval));

        // Start Oscillator
        l_inst = mss::ccs::ddr5::mpc_command<mss::mc_type::ODYSSEY>(l_port_rank, uint64_t(i_op), l_dqs_interval + tMRD);
    }
    else
    {
        // Stop oscillator (no delay needed)
        l_inst = mss::ccs::ddr5::mpc_command<mss::mc_type::ODYSSEY>(l_port_rank, uint64_t(i_op));
    }

    io_program.iv_instructions.push_back(l_inst);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Execute CCS program in concurrent mode
/// @param [in] i_rank_info rank info
/// @param [in,out] io_program the ccs program
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode execute_concurrent_ccs(
    const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
    mss::ccs::program<mss::mc_type::ODYSSEY>& io_program)
{
    fapi2::buffer<uint64_t> l_modeq_reg;
    fapi2::buffer<uint64_t> l_farb0q;

    const auto& l_port = i_rank_info.get_port_target();
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port);

    FAPI_TRY(mss::ccs::stop_ccs_and_mcbist<mss::mc_type::ODYSSEY>(l_ocmb));

    FAPI_DBG(GENTARGTIDFORMAT " Executing DQS drift track and recal via concurrent CCS", GENTARGTID(l_ocmb));

    // Configure CCS regs for execution
    FAPI_TRY( mss::ccs::config_ccs_regs_for_concurrent<mss::mc_type::ODYSSEY>(l_ocmb, l_modeq_reg, mss::states::OFF ) );

    // Backup FARB0Q value before running Concurrent CCS
    FAPI_TRY( mss::ccs::pre_execute_via_mcbist<mss::mc_type::ODYSSEY>(l_ocmb, l_farb0q) );

    // Run CCS via MCBIST for Concurrent CCS
    FAPI_TRY( mss::ccs::execute_via_mcbist<mss::mc_type::ODYSSEY>(l_ocmb, io_program, l_port) );

    // Restore FARB0Q value after running Concurrent CCS
    FAPI_TRY( mss::ccs::post_execute_via_mcbist<mss::mc_type::ODYSSEY>(l_ocmb, l_farb0q) );

    // Revert CCS regs after execution
    FAPI_TRY( mss::ccs::revert_config_regs<mss::mc_type::ODYSSEY>(l_ocmb, l_modeq_reg) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Tracks dqs and recalibrates to ATTR_ODY_DQS_OSC_RUNTIME_SEL
/// @param [in] i_rank_info rank info
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode dqs_recal(const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info)
{
    const auto& l_port_target = i_rank_info.get_port_target();
    const auto& l_ocmb_target = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port_target);

    mss::ccs::program<mss::mc_type::ODYSSEY> l_program;

    // Assert LSB snoop on MRR
    FAPI_TRY(assert_mr_snoop(l_ocmb_target, drift_track_mr::LSB_MR));

    // We need two CCS programs since we can only snoop LSB or MSB individually
    // First CCS program: run the oscillator, then read/snoop MR46
    {
        // Prepares mpc command to start oscillator
        FAPI_TRY(prepare_oscillator_mpc(i_rank_info, mpc_command::OSCILLATOR_START, l_program));

        // MRR for the LSB
        FAPI_TRY(prepare_mrr_ccs(i_rank_info, drift_track_mr::LSB_MR, l_program));

        // Executes the CCS program in concurrent mode
        FAPI_TRY(execute_concurrent_ccs(i_rank_info, l_program));
    }

    // Assert MSB snoop on MRR
    FAPI_TRY(assert_mr_snoop(l_ocmb_target, drift_track_mr::MSB_MR));

    l_program.iv_instructions.clear();

    // Second CCS program: read/snoop MR47
    {
        // MRR for the LSB
        FAPI_TRY(prepare_mrr_ccs(i_rank_info, drift_track_mr::MSB_MR, l_program));

        // Executes the CCS program in concurrent mode
        FAPI_TRY(execute_concurrent_ccs(i_rank_info, l_program));
    }

    // Clear the snoop bit
    FAPI_TRY(disable_mr_snoop(l_ocmb_target));

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Helper function to calculate the temperature delta of the ocmb sensor
/// @param [in] i_target OCMB target
/// @param [in] i_thermal_sensor_prev_attr attribute value of previous value for diff sensor
/// @param [in] i_snsc_thermal_scom_data scom data of the sensor cache on-chip register
/// @param [out] o_temp_delta delta of the previous value and the current value of the available sensor
/// @param [out] o_current_temp_values vector of current temperature of all the sensors
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode calc_ocmb_sensor_temp_delta_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const int16_t i_thermal_sensor_prev_attr,
        const fapi2::buffer<uint64_t>& i_snsc_thermal_scom_data,
        int16_t& o_temp_delta_value,
        int16_t& o_current_temp_value
                                                    )
{
    using TT = mss::temp_sensor_traits<mss::mc_type::ODYSSEY>;

    uint8_t l_thermal_present = 0;
    uint8_t l_thermal_error = 0;

    // Get the present bit and the error bit for OCMB temp sensor
    l_thermal_present = i_snsc_thermal_scom_data.getBit<TT::SENSOR_PRESENT_BIT>();
    l_thermal_error = i_snsc_thermal_scom_data.getBit<TT::SENSOR_ERROR_BIT>();

    // Get the decoding for OCMB temp sensor in centigrade
    if(l_thermal_present && !(l_thermal_error))
    {
        FAPI_TRY(mss::get_sensor_data_for_ocmb_x100<mss::mc_type::ODYSSEY>(i_target,
                 i_snsc_thermal_scom_data,
                 l_thermal_present,
                 l_thermal_error,
                 o_current_temp_value));

        // Put the difference of the previous attr and the register value in the array
        // Using the if condition instead of abs(), since hostboot is failing with abs()
        o_temp_delta_value =  i_thermal_sensor_prev_attr - o_current_temp_value;

        if(o_temp_delta_value < 0)
        {
            o_temp_delta_value *= -1;
        }
    }
    else  // If the sensor is not present or if the sensor has an error bit then delta is 0
    {
        // No update in the temperature value and the delta value is 0
        o_current_temp_value = i_thermal_sensor_prev_attr;
        o_temp_delta_value = 0;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function calculate the temperature delta of the DDIMM sensor
/// @param [in] i_thermal_sensor_prev_attr attribute value of previous value for diff sensor
/// @param [in] i_snsc_thermal_scom_data scom data of the sensor cache on-chip register
/// @param [out] o_temp_delta delta of the previous value and the current value of the available sensor
/// @return int16_t current temperature value
///
int16_t calc_thermal_sensor_temp_delta_helper(const int16_t i_thermal_sensor_prev_attr,
        const fapi2::buffer<uint64_t>& i_snsc_thermal_scom_data,
        int16_t& o_temp_delta_value
                                             )
{
    using TT = mss::temp_sensor_traits<mss::mc_type::ODYSSEY>;

    uint8_t l_thermal_present = 0;
    uint8_t l_thermal_error = 0;
    int16_t l_current_temp_value = 0;

    // Get the present bit and the error bit for OCMB temp sensor
    l_thermal_present = i_snsc_thermal_scom_data.getBit<TT::SENSOR_PRESENT_BIT>();
    l_thermal_error = i_snsc_thermal_scom_data.getBit<TT::SENSOR_ERROR_BIT>();

    // Get the decoding for OCMB temp sensor in centigrade
    if(l_thermal_present && !(l_thermal_error))
    {
        l_current_temp_value = mss::get_sensor_data_for_ddimm_x100<mss::mc_type::ODYSSEY>(i_snsc_thermal_scom_data,
                               l_thermal_present,
                               l_thermal_error);

        // Put the difference of the previous attr and the register value in the array
        // Using the if condition instead of abs(), since hostboot is failing with abs()
        o_temp_delta_value =  i_thermal_sensor_prev_attr - l_current_temp_value;

        if(o_temp_delta_value < 0)
        {
            o_temp_delta_value *= -1;
        }
    }
    else  // If the sensor is not present or if the sensor has an error bit then delta is 0
    {
        // No update in the temperature value and the delta value is 0
        l_current_temp_value = i_thermal_sensor_prev_attr;
        o_temp_delta_value = 0;
    }

    return l_current_temp_value;
}


///
/// @brief Check if sensor exists and get the index number of that sensor
/// @param [in] i_thermal_sensor_usage attr for thermal sensor usage
/// @param [in] i_thermal_sensor_avail attr for thermal sensor avail
/// @param [in] i_sensor_index index of the sensor that is being checked
/// @param [out] o_sensor_info structure of the sensor info
/// @return none
///
void check_sensor_exists_and_get_index(const uint8_t i_thermal_sensor_usage,
                                       const uint8_t i_thermal_sensor_avail,
                                       const uint8_t i_sensor_index,
                                       mss::ody::sensor_info_vars& o_sensor_info)
{
    // Checking against sensor0 enums since the enum values for all sensors are the same.
    // DRAM
    if (i_thermal_sensor_usage == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_DRAM &&
        i_thermal_sensor_avail == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_AVAIL_AVAILABLE)
    {
        o_sensor_info.iv_dram_exists = true;
        o_sensor_info.iv_dram_index = i_sensor_index;
    }

    // PMIC
    if(i_thermal_sensor_usage == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_PMIC &&
       i_thermal_sensor_avail == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_AVAIL_AVAILABLE)
    {
        o_sensor_info.iv_pmic_exists = true;
        o_sensor_info.iv_pmic_index = i_sensor_index;
    }

    // MEM_BUF_EXT
    if (i_thermal_sensor_usage == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_MEM_BUF_EXT &&
        i_thermal_sensor_avail == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_AVAIL_AVAILABLE)
    {
        o_sensor_info.iv_mem_buf_ext_exists = true;
        o_sensor_info.iv_mem_buf_ext_index = i_sensor_index;
    }

    return;
}

///
/// @brief Calculate the temperature delta of the sensor
/// @param [in] i_target OCMB target
/// @param [out] o_temp_delta delta of the previous value and the current value of the available sensor
/// @param [out] o_current_temp_values vector of current temperature of all the sensors
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode ody_calc_temp_sensors_delta(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        int16_t& o_temp_delta,
        int16_t (&o_current_temp_values)[mss::temp_sensor_traits<mss::mc_type::ODYSSEY>::temp_sensor::NUM_SENSORS])
{
    using TT = mss::temp_sensor_traits<mss::mc_type::ODYSSEY>;

    // Various arrays to store the usage, availability, previous, reg scom data
    uint8_t l_thermal_sensor_usage[TT::temp_sensor::NUM_SENSORS] = {0};
    uint8_t l_thermal_sensor_avail[TT::temp_sensor::NUM_SENSORS] = {0};
    int16_t l_thermal_sensor_prev_attr[TT::temp_sensor::NUM_SENSORS] __attribute__ ((__aligned__(8))) = {0};
    const uint64_t l_thermal_sensors_scom_regs[TT::temp_sensor::NUM_SENSORS] = {scomt::ody::ODC_MMIO_SNSC_D0THERM,
                                                                                scomt::ody::ODC_MMIO_SNSC_D1THERM,
                                                                                scomt::ody::ODC_MMIO_SNSC_D2THERM,
                                                                                scomt::ody::ODC_MMIO_SNSC_D3THERM,
                                                                                scomt::ody::ODC_MMIO_SNSC_OCTHERM
                                                                               };
    fapi2::buffer<uint64_t> l_snsc_therm_data[TT::temp_sensor::NUM_SENSORS] = {0};
    int16_t l_temp_delta_values[TT::temp_sensor::NUM_SENSORS] __attribute__ ((__aligned__(8))) = {0};

    // Index values for the sensors
    mss::ody::sensor_info_vars l_sensor_info;

    // Get all the temperature deltas for DDIMM temperature sensors
    for(uint8_t l_sensor_index = 0; l_sensor_index < TT::temp_sensor::NUM_SENSORS; l_sensor_index++)
    {
        if(l_sensor_index != mss::ody::sensor_types::DIFFERENTIAL_SENSOR)
        {
            FAPI_TRY(mss::ody::thermal::get_therm_sensor_usage[l_sensor_index](i_target,
                     l_thermal_sensor_usage[l_sensor_index]));
            FAPI_TRY(mss::ody::thermal::get_therm_sensor_availability[l_sensor_index](i_target,
                     l_thermal_sensor_avail[l_sensor_index]));
        }
        // Have to fill up the differential sensor values into the array
        // which are not part of the setter and getter pointer arrays
        else
        {
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_DIFF_USAGE, i_target,
                                    l_thermal_sensor_usage[l_sensor_index]) );
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_THERM_SENSOR_DIFF_AVAIL, i_target,
                                    l_thermal_sensor_avail[l_sensor_index]) );
        }

        FAPI_TRY(mss::ody::thermal::get_therm_sensor_prev_value[l_sensor_index](i_target,
                 l_thermal_sensor_prev_attr[l_sensor_index]));
        FAPI_TRY(fapi2::getScom(i_target,
                                l_thermal_sensors_scom_regs[l_sensor_index],
                                l_snsc_therm_data[l_sensor_index]));

        if(l_sensor_index == mss::ody::sensor_types::DIFFERENTIAL_SENSOR)
        {
            // Get the temperature delta and the current value for OCMB sensor
            FAPI_TRY(calc_ocmb_sensor_temp_delta_helper(i_target,
                     l_thermal_sensor_prev_attr[l_sensor_index],
                     l_snsc_therm_data[l_sensor_index],
                     l_temp_delta_values[l_sensor_index],
                     o_current_temp_values[l_sensor_index]));
        }
        else // For all other thermal sensors
        {
            o_current_temp_values[l_sensor_index] = calc_thermal_sensor_temp_delta_helper(
                    l_thermal_sensor_prev_attr[l_sensor_index],
                    l_snsc_therm_data[l_sensor_index],
                    l_temp_delta_values[l_sensor_index]);
        }

    }

    // Check which sensor is available and mark the index
    for (uint8_t l_sensor_index = 0; l_sensor_index < TT::temp_sensor::NUM_SENSORS - 1; l_sensor_index++)
    {
        check_sensor_exists_and_get_index(l_thermal_sensor_usage[l_sensor_index],
                                          l_thermal_sensor_avail[l_sensor_index],
                                          l_sensor_index,
                                          l_sensor_info);
    }

    // Now check which index exists and choose that temp delta
    // but only if temperature is within reasonable range (0-125C)
    o_temp_delta = 0;

    if (l_sensor_info.iv_dram_exists &&
        (o_current_temp_values[l_sensor_info.iv_dram_index] >= 0) &&
        (o_current_temp_values[l_sensor_info.iv_dram_index] <= 125))
    {
        o_temp_delta = l_temp_delta_values[l_sensor_info.iv_dram_index];
    }
    else if (l_sensor_info.iv_pmic_exists &&
             (o_current_temp_values[l_sensor_info.iv_pmic_index] >= 0) &&
             (o_current_temp_values[l_sensor_info.iv_pmic_index] <= 125))
    {
        o_temp_delta = l_temp_delta_values[l_sensor_info.iv_pmic_index];
    }
    else if (l_sensor_info.iv_mem_buf_ext_exists &&
             (o_current_temp_values[l_sensor_info.iv_mem_buf_ext_index] >= 0) &&
             (o_current_temp_values[l_sensor_info.iv_mem_buf_ext_index] <= 125))
    {
        o_temp_delta = l_temp_delta_values[l_sensor_info.iv_mem_buf_ext_index];
    }
    // if none of the above sensors exist use the differential one
    else if ((o_current_temp_values[mss::ody::sensor_types::DIFFERENTIAL_SENSOR] >= 0) &&
             (o_current_temp_values[mss::ody::sensor_types::DIFFERENTIAL_SENSOR] <= 125))
    {
        o_temp_delta = l_temp_delta_values[mss::ody::sensor_types::DIFFERENTIAL_SENSOR];
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Ody DQS track procedure
/// @param [in] i_target OCMB target
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode ody_dqs_track(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    using TT = mss::temp_sensor_traits<mss::mc_type::ODYSSEY>;
    std::vector<mss::rank::info<mss::mc_type::ODYSSEY>> l_rank_infos;

    uint8_t l_threshold = 0;
    int16_t l_temp_delta = 0;
    int16_t l_curr_temp_values[TT::temp_sensor::NUM_SENSORS] __attribute__ ((__aligned__(8))) = {0};
    uint16_t l_count = 0;
    uint16_t l_count_threshold = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DQS_TRACKING_TEMP_THRESHOLD, i_target, l_threshold));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DQS_TRACKING_COUNT_SINCE_LAST_RECAL, i_target, l_count));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DQS_TRACKING_COUNT_THRESHOLD, i_target, l_count_threshold));

    // Get the temperature delta and the current temperature values, both in centi-degrees
    if (l_count <= l_count_threshold)
    {
        FAPI_TRY(ody_calc_temp_sensors_delta(i_target, l_temp_delta, l_curr_temp_values));
    }

    // Run DQS tracking only if the temp delta or count is more than the associated threshold
    // Threshold is in degrees-C so needs to be multiplied by 100
    if ((l_temp_delta > static_cast<int16_t>(l_threshold) * 100) ||
        (l_count > l_count_threshold))
    {
        for(auto& l_port_target : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target) )
        {
            FAPI_TRY(mss::rank::ranks_on_port<mss::mc_type::ODYSSEY>(l_port_target, l_rank_infos));

            for(auto l_rank_info : l_rank_infos)
            {
                FAPI_TRY(dqs_recal(l_rank_info));
            }
        }

        // Update the attr temp sensors with the delta values
        for (uint8_t l_sensor_index = 0; l_sensor_index < TT::temp_sensor::NUM_SENSORS; l_sensor_index++)
        {
            FAPI_TRY(mss::ody::thermal::set_therm_sensor_prev_value[l_sensor_index](i_target, l_curr_temp_values[l_sensor_index]));
        }

        // Reset the "count since last recal" value
        l_count = 0;
    }
    else
    {
        // We didn't recal, so increment the "count since last recal" value
        l_count++;
    }

    // Update the "count since last recal" value
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ODY_DQS_TRACKING_COUNT_SINCE_LAST_RECAL, i_target, l_count));

fapi_try_exit:
    return fapi2::current_err;
}

} // end ns ody
} // end ns mss
