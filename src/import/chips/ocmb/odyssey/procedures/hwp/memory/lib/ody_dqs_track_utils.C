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
#include <lib/phy/ody_phy_access.H>
#include <generic/memory/lib/ccs/ccs_ddr5_commands.H>
#include <lib/power_thermal/ody_thermal_init_utils.H>
#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_memdiags.H>
#include <ody_scom_mp_dbyte0_b0.H>
#include <ody_scom_mp_dbyte1_b0.H>
#include <ody_scom_mp_dbyte2_b0.H>
#include <ody_scom_mp_dbyte3_b0.H>
#include <ody_scom_mp_dbyte4_b0.H>
#include <ody_scom_mp_dbyte5_b0.H>
#include <ody_scom_mp_dbyte6_b0.H>
#include <ody_scom_mp_dbyte7_b0.H>
#include <ody_scom_mp_dbyte8_b0.H>
#include <ody_scom_mp_dbyte9_b0.H>
#include <generic/memory/lib/utils/fir/gen_mss_unmask.H>

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
    const auto& l_port_rank = i_rank_info.get_port_rank();
    // Create local mrr instruction for LSB/MSB snoop
    mss::ccs::instruction_t<mss::mc_type::ODYSSEY> l_inst;

    l_inst = mss::ccs::ddr5::mrr_command<mss::mc_type::ODYSSEY>(l_port_rank, uint64_t(i_mr_number),
             ccsTraits<mss::mc_type::ODYSSEY>::MRR_SAFE_IDLE);
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
    // if ATTR_MSS_MRW_OVERRIDE_THERM_SENSOR_USAGE is enabled then DRAM usage is overriden to ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_DRAM_AND_MEM_BUF_EXT
    if ((i_thermal_sensor_usage == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_DRAM
         || i_thermal_sensor_usage == fapi2::ENUM_ATTR_MEM_EFF_THERM_SENSOR_0_USAGE_DRAM_AND_MEM_BUF_EXT) &&
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
/// @param [out] o_chosen_sensor_index index of the sensor chosen for the delta calculation
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode ody_calc_temp_sensors_delta(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        int16_t& o_temp_delta,
        int16_t (&o_current_temp_values)[mss::temp_sensor_traits<mss::mc_type::ODYSSEY>::temp_sensor::NUM_SENSORS],
        uint8_t& o_chosen_sensor_index)
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
        o_chosen_sensor_index = l_sensor_info.iv_dram_index;
    }
    else if (l_sensor_info.iv_pmic_exists &&
             (o_current_temp_values[l_sensor_info.iv_pmic_index] >= 0) &&
             (o_current_temp_values[l_sensor_info.iv_pmic_index] <= 125))
    {
        o_temp_delta = l_temp_delta_values[l_sensor_info.iv_pmic_index];
        o_chosen_sensor_index = l_sensor_info.iv_pmic_index;
    }
    else if (l_sensor_info.iv_mem_buf_ext_exists &&
             (o_current_temp_values[l_sensor_info.iv_mem_buf_ext_index] >= 0) &&
             (o_current_temp_values[l_sensor_info.iv_mem_buf_ext_index] <= 125))
    {
        o_temp_delta = l_temp_delta_values[l_sensor_info.iv_mem_buf_ext_index];
        o_chosen_sensor_index = l_sensor_info.iv_mem_buf_ext_index;
    }
    // if none of the above sensors exist use the differential one
    else if ((o_current_temp_values[mss::ody::sensor_types::DIFFERENTIAL_SENSOR] >= 0) &&
             (o_current_temp_values[mss::ody::sensor_types::DIFFERENTIAL_SENSOR] <= 125))
    {
        o_temp_delta = l_temp_delta_values[mss::ody::sensor_types::DIFFERENTIAL_SENSOR];
        o_chosen_sensor_index = mss::ody::sensor_types::DIFFERENTIAL_SENSOR;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Record DQS offsets or compute offset delta
/// @param [in] i_target MEM_PORT target
/// @param [in] i_compute_deltas FALSE if recording offsets prior to a recal, TRUE if computing delta after a recal
/// @param [in,out] io_offsets the DQS offsets (signed integer)
/// @param [out] o_deltas maximum computed deltas between io_offsets and current offsets (in log format)
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode ody_get_dqs_offsets(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                      const bool i_compute_deltas,
                                      int16_t (&io_offsets)[HW_MAX_RANK_PER_DIMM][ODY_NUM_DRAM_X4],
                                      fapi2::buffer<uint16_t> (&o_deltas)[ATTR_ODY_DQS_TRACKING_LOG_DELTA_COUNT])
{
    // DQS drift registers, organized by [rank][nibble]
    constexpr uint64_t TXTRKSTATES[HW_MAX_RANK_PER_DIMM][ODY_NUM_DRAM_X4] __attribute__ ((__aligned__(8))) =
    {
        {
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_TXTRKSTATES0_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_TXTRKSTATES4_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_TXTRKSTATES0_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_TXTRKSTATES4_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_TXTRKSTATES0_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_TXTRKSTATES4_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_TXTRKSTATES0_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_TXTRKSTATES4_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_TXTRKSTATES0_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_TXTRKSTATES4_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_TXTRKSTATES0_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_TXTRKSTATES4_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_TXTRKSTATES0_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_TXTRKSTATES4_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_TXTRKSTATES0_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_TXTRKSTATES4_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_TXTRKSTATES0_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_TXTRKSTATES4_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_TXTRKSTATES0_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_TXTRKSTATES4_P0
        },
        {
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_TXTRKSTATES1_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_TXTRKSTATES5_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_TXTRKSTATES1_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE1_BASE0_TXTRKSTATES5_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_TXTRKSTATES1_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE2_BASE0_TXTRKSTATES5_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_TXTRKSTATES1_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE3_BASE0_TXTRKSTATES5_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_TXTRKSTATES1_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE4_BASE0_TXTRKSTATES5_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_TXTRKSTATES1_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE5_BASE0_TXTRKSTATES5_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_TXTRKSTATES1_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE6_BASE0_TXTRKSTATES5_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_TXTRKSTATES1_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE7_BASE0_TXTRKSTATES5_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_TXTRKSTATES1_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE8_BASE0_TXTRKSTATES5_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_TXTRKSTATES1_P0,
            scomt::mp::DWC_DDRPHYA_DBYTE9_BASE0_TXTRKSTATES5_P0
        }
    };

    uint8_t l_num_mranks[MAX_DIMM_PER_PORT] = {0};
    uint8_t l_dram_width[MAX_DIMM_PER_PORT] = {0};
    uint8_t l_num_dram = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target, l_num_mranks));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_WIDTH, i_target, l_dram_width));

    l_num_dram = (l_dram_width[0] == fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X4) ? ODY_NUM_DRAM_X4 : ODY_NUM_DRAM_X8;

    FAPI_TRY(mss::ody::phy::configure_phy_scom_access(i_target, mss::states::ON_N));

    for (uint8_t l_mrank = 0; l_mrank < l_num_mranks[0]; l_mrank++)
    {
        for (uint8_t l_dram = 0; l_dram < l_num_dram; l_dram++)
        {
            fapi2::buffer<uint64_t> l_offset_data;
            FAPI_TRY(fapi2::getScom(i_target, TXTRKSTATES[l_mrank][l_dram], l_offset_data));

            if (!i_compute_deltas)
            {
                io_offsets[l_mrank][l_dram] = convert_to_2s_complement(l_offset_data);
            }
            else
            {
                const auto l_delta = convert_to_2s_complement(l_offset_data) - io_offsets[l_mrank][l_dram];
                const uint16_t l_delta_abs = (l_delta < 0) ? static_cast<uint16_t>(l_delta * -1) : static_cast<uint16_t>(l_delta);

                // insert the new delta entry into the array if it's big enough
                insert_delta(l_delta_abs, l_mrank, l_dram, o_deltas);
            }
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check if a steer test is in the MCBIST
/// @param [in] i_target OCMB target
/// @param [out] o_is_steer will be set to true if steer test present, false otherwise
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode check_steer_subtest(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                      bool& o_is_steer)
{
    using TT = mcbistTraits<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>;

    fapi2::buffer<uint64_t> l_mcbmr;
    uint8_t l_operation = 0;

    // Return false by default
    o_is_steer = false;

    // Check in first MCBIST subtest register
    FAPI_TRY(fapi2::getScom(i_target, TT::MCBMR0_REG, l_mcbmr));
    l_mcbmr.extractToRight<TT::OP_TYPE, TT::OP_TYPE_LEN>(l_operation);

    o_is_steer = (l_operation == mss::mcbist::op_type::STEER_RW);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check if MCBIST_PROGRAM_COMPLETE FIR is set
/// @param [in] i_target OCMB target
/// @param [out] o_prog_complete will be set to true if PROGRAM_COMPLETE is set, false otherwise
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode check_mcbist_program_complete(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        bool& o_prog_complete)
{
    using TT = mcbistTraits<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>;

    fapi2::buffer<uint64_t> l_mcbistfir;

    // Return false by default
    o_prog_complete = false;

    FAPI_TRY(fapi2::getScom(i_target, TT::FIRQ_REG, l_mcbistfir));

    o_prog_complete = l_mcbistfir.getBit<TT::MCB_PROGRAM_COMPLETE>();

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Save state of MCBIST test
/// @param [in] i_target OCMB target
/// @param [in,out] io_saved_mcbist_state saved state of MCBIST
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode save_mcbist_state(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    mcbist_state& io_saved_mcbist_state)
{
    using TT = mcbistTraits<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>;

    fapi2::buffer<uint64_t> l_mcbmr;

    // Note MCBPARMQ should be saved before the point where this function gets called because of the
    // adjustment to the command gap

    FAPI_TRY(fapi2::getScom(i_target, TT::THRESHOLD_REG, io_saved_mcbist_state.iv_thresholds));
    FAPI_TRY(fapi2::getScom(i_target, TT::LAST_ADDR_REG, io_saved_mcbist_state.iv_current_addr));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Restore state of MCBIST test
/// @param [in] i_target OCMB target
/// @param [in] i_saved_mcbist_state saved state of MCBIST
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode restore_mcbist_state(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                       const mcbist_state& i_saved_mcbist_state)
{
    using TT = mcbistTraits<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>;

    // Note: current address and subtest programming get set up when the test is restarted
    FAPI_TRY(fapi2::putScom(i_target, TT::MCBPARMQ_REG, i_saved_mcbist_state.iv_mcbparmq));
    FAPI_TRY(fapi2::putScom(i_target, TT::THRESHOLD_REG, i_saved_mcbist_state.iv_thresholds));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Suspend and save the state of a background steer operation
/// @param [in] i_target OCMB target
/// @param [in,out] io_saved_mcbist_state saved state of MCBIST, to be used in later resume_bg_scrub call
/// @param [out] o_cannot_suspend will be set to true if scrub test cannot be suspended, false otherwise
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode suspend_bg_scrub(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                   mcbist_state& io_saved_mcbist_state,
                                   bool& o_cannot_suspend)
{
    using TT = mcbistTraits<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>;

    constexpr uint16_t MAX_CMD_GAP = 0xFFF;

    fapi2::buffer<uint64_t> l_mcbparmq;
    fapi2::buffer<uint64_t> l_last_addr;
    const mss::poll_parameters l_poll_parameters(0, 200, mss::DELAY_1MS, 200, 50);
    bool l_curr_addr_changed = false;
    bool l_prog_complete = false;

    // Default o_cannot_suspend to true in case an error occurs
    o_cannot_suspend = true;

    // Slow down command by putting max value into the command gap
    FAPI_TRY(fapi2::getScom(i_target, TT::MCBPARMQ_REG, l_mcbparmq));
    io_saved_mcbist_state.iv_mcbparmq = l_mcbparmq;
    l_mcbparmq.insertFromRight<TT::MIN_CMD_GAP, TT::MIN_CMD_GAP_LEN>(MAX_CMD_GAP)
    .setBit<TT::MIN_GAP_TIMEBASE>();
    FAPI_TRY(fapi2::putScom(i_target, TT::MCBPARMQ_REG, l_mcbparmq));

    // Poll for current address pointer to change
    // Note: we slowed down the MCBIST test to the maximum min_cmd_gap, which is 10ms.
    // The designers say the max command gap is still around 28ms in this case, so we poll
    // 50 times with a 1ms delay in between to be safe.
    FAPI_TRY(fapi2::getScom(i_target, TT::LAST_ADDR_REG, l_last_addr));
    l_curr_addr_changed = mss::poll(i_target, TT::LAST_ADDR_REG, l_poll_parameters,
                                    [l_last_addr](const size_t poll_remaining,
                                            const fapi2::buffer<uint64_t>& addr_reg) -> bool
    {
        if (addr_reg != l_last_addr)
        {
            return true;
        }
        return false;
    });

    // If the curent address didn't change, assume PRD is doing an analysis, so restore state and exit
    if (!l_curr_addr_changed)
    {
        FAPI_INF_NO_SBE(GENTARGTIDFORMAT " current MCBIST test is paused, so cannot suspend", GENTARGTID(i_target));
        o_cannot_suspend = true;
        FAPI_TRY(fapi2::putScom(i_target, TT::MCBPARMQ_REG, io_saved_mcbist_state.iv_mcbparmq));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // If MCBIST_PROGRAM_COMPLETE FIR is set, test is either at end of address range or stopped on error
    // so restore state and exit
    FAPI_TRY(check_mcbist_program_complete(i_target, l_prog_complete));

    if (l_prog_complete)
    {
        FAPI_INF_NO_SBE(GENTARGTIDFORMAT " current MCBIST test is stopped on error, so cannot suspend", GENTARGTID(i_target));
        o_cannot_suspend = true;
        FAPI_TRY(fapi2::putScom(i_target, TT::MCBPARMQ_REG, io_saved_mcbist_state.iv_mcbparmq));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // If we haven't exited by now, it means we're safe to suspend the MCBIST test

    FAPI_INF_NO_SBE(GENTARGTIDFORMAT " suspending current MCBIST test", GENTARGTID(i_target));

    // Mask MCBIST_PROGRAM_COMPLETE and force MCBIST stop
    FAPI_TRY( mss::memdiags::stop<mss::mc_type::ODYSSEY>(i_target),
              "MCBIST engine failed to stop on "
              GENTARGTIDFORMAT, GENTARGTID(i_target) );

    // Record subtest, stop conditions, and current address, then return
    FAPI_TRY(save_mcbist_state(i_target, io_saved_mcbist_state));
    o_cannot_suspend = false;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Restore the state of a background steer operation and restart it
/// @param [in] i_target OCMB target
/// @param [in] i_saved_mcbist_state saved state of MCBIST, from suspend_bg_scrub
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode resume_bg_scrub(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                  const mcbist_state& i_saved_mcbist_state)
{
    const mss::mcbist::address<mss::mc_type::ODYSSEY> l_address(i_saved_mcbist_state.iv_current_addr);

    FAPI_INF_NO_SBE(GENTARGTIDFORMAT " resuming suspended MCBIST test", GENTARGTID(i_target));

    // Restore speed and stop conditions
    FAPI_TRY(restore_mcbist_state(i_target, i_saved_mcbist_state));

    // Start new steer test from saved address
    FAPI_TRY(mss::memdiags::mss_firmware_background_steer_helper<mss::mc_type::ODYSSEY>(i_target,
             mss::mcbist::stop_conditions<mss::mc_type::ODYSSEY>::DONT_CHANGE,
             mss::mcbist::speed::SAME_SPEED,
             l_address));

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

    // Consts for readability
    constexpr bool RECORD_OFFSETS = false;
    constexpr bool COMPUTE_DELTAS = true;

    std::vector<mss::rank::info<mss::mc_type::ODYSSEY>> l_rank_infos;
    uint8_t l_threshold = 0;
    int16_t l_temp_delta = 0;
    int16_t l_curr_temp_values[TT::temp_sensor::NUM_SENSORS] __attribute__ ((__aligned__(8))) = {0};
    uint16_t l_count = 0;
    uint16_t l_count_threshold = 0;
    bool l_steer = false;
    mcbist_state l_saved_mcbist_state;
    uint8_t l_temp_trigger = 0;
    uint8_t l_chosen_sensor_index = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DQS_TRACKING_TEMP_THRESHOLD, i_target, l_threshold));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DQS_TRACKING_COUNT_SINCE_LAST_RECAL, i_target, l_count));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DQS_TRACKING_COUNT_THRESHOLD, i_target, l_count_threshold));

    // Get the temperature delta and the current temperature values, both in centi-degrees
    if (l_count <= l_count_threshold)
    {
        FAPI_TRY(ody_calc_temp_sensors_delta(i_target, l_temp_delta, l_curr_temp_values, l_chosen_sensor_index));
    }

    // Run DQS tracking only if the temp delta or count is more than the associated threshold
    // Threshold is in degrees-C so needs to be multiplied by 100
    l_temp_trigger = (l_temp_delta > static_cast<int16_t>(l_threshold) * 100) ? 1 : 0;

    if (l_temp_trigger ||
        ((l_count >= l_count_threshold) &&
         (l_count_threshold != fapi2::ENUM_ATTR_ODY_DQS_TRACKING_COUNT_THRESHOLD_DISABLE)))
    {
        uint16_t l_recal_count = 0;
        fapi2::buffer<uint16_t> l_deltas[ATTR_ODY_DQS_TRACKING_LOG_DELTA_COUNT] __attribute__ ((__aligned__(8))) = {0};

        // Check if steer is running
        FAPI_TRY(check_steer_subtest(i_target, l_steer));

        if (l_steer)
        {
            bool l_prog_complete = false;
            bool l_cannot_suspend = false;

            // Check if MCBIST_PROGRAM_COMPLETE is 1, implying PRD is handling an error at this moment
            FAPI_TRY(check_mcbist_program_complete(i_target, l_prog_complete));

            if (l_prog_complete)
            {
                // PRD is handling an error, so we're blocked. Set the counter to the threshold to force
                // a recal at the next opportunity
                FAPI_TRY(FAPI_ATTR_SET_CONST(fapi2::ATTR_ODY_DQS_TRACKING_COUNT_SINCE_LAST_RECAL, i_target,
                                             static_cast<uint16_t>(l_count_threshold + 1)));

                FAPI_INF_NO_SBE(GENTARGTIDFORMAT " MCBIST_PROGRAM_COMPLETE FIR is on for steer test,"
                                " so cannot use MCBIST engine", GENTARGTID(i_target));
                return fapi2::FAPI2_RC_SUCCESS;
            }

            // Check and save the state of the MCBIST engine, and exit if we cannot break in
            FAPI_TRY(suspend_bg_scrub(i_target, l_saved_mcbist_state, l_cannot_suspend));

            if (l_cannot_suspend)
            {
                // Set the counter to the threshold to force a recal at the next opportunity
                FAPI_TRY(FAPI_ATTR_SET_CONST(fapi2::ATTR_ODY_DQS_TRACKING_COUNT_SINCE_LAST_RECAL, i_target,
                                             static_cast<uint16_t>(l_count_threshold + 1)));

                FAPI_INF_NO_SBE(GENTARGTIDFORMAT " could not suspend current MCBIST test", GENTARGTID(i_target));
                return fapi2::FAPI2_RC_SUCCESS;
            }
        }

        // If we made it here, it means the MCBIST engine should be unused at this point
        for(auto& l_port_target : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target) )
        {
            int16_t l_offsets[HW_MAX_RANK_PER_DIMM][ODY_NUM_DRAM_X4] __attribute__ ((__aligned__(8))) = {0};

            // Clear out deltas
            for (uint8_t l_idx = 0; l_idx < ATTR_ODY_DQS_TRACKING_LOG_DELTA_COUNT; l_idx++)
            {
                l_deltas[l_idx] = 0;
            }

            // Record the current DQS offsets
            FAPI_TRY(ody_get_dqs_offsets(l_port_target, RECORD_OFFSETS, l_offsets, l_deltas));

            FAPI_TRY(mss::rank::ranks_on_port<mss::mc_type::ODYSSEY>(l_port_target, l_rank_infos));

            // Run DQS drift tracking
            for(auto l_rank_info : l_rank_infos)
            {
                FAPI_TRY(dqs_recal(l_rank_info));
            }

            // Compute the DQS offset deltas
            FAPI_TRY(ody_get_dqs_offsets(l_port_target, COMPUTE_DELTAS, l_offsets, l_deltas));
        }

        // Log the tracking info
        FAPI_TRY(ody_dqs_track_log(i_target,
                                   l_temp_trigger,
                                   l_count,
                                   l_curr_temp_values[l_chosen_sensor_index],
                                   l_deltas));

        // Update the previous temperature value attrs
        for (uint8_t l_sensor_index = 0; l_sensor_index < TT::temp_sensor::NUM_SENSORS; l_sensor_index++)
        {
            FAPI_TRY(mss::ody::thermal::set_therm_sensor_prev_value[l_sensor_index](i_target, l_curr_temp_values[l_sensor_index]));
        }

        // Reset the "count since last recal" value
        l_count = 0;

        // Update the number of recals performed
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DQS_TRACKING_RECAL_COUNT, i_target, l_recal_count));
        l_recal_count += 1;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ODY_DQS_TRACKING_RECAL_COUNT, i_target, l_recal_count));
    }
    else
    {
        // We didn't recal, so increment the "count since last recal" value
        l_count++;
    }

    // Update the "count since last recal" value
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ODY_DQS_TRACKING_COUNT_SINCE_LAST_RECAL, i_target, l_count));

    if (l_steer)
    {
        // Restore the state of the MCBIST engine and restart the bg steer test from the last address
        FAPI_TRY(resume_bg_scrub(i_target, l_saved_mcbist_state));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // Log original error
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
    // Unmask and set FIRs
    fapi2::ReturnCode l_rc = mss::unmask::dqs_drift_track_error<mss::mc_type::ODYSSEY>(i_target);
    return l_rc;
}

} // end ns ody
} // end ns mss
