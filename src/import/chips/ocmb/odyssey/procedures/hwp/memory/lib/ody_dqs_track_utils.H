/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ody_dqs_track_utils.H $ */
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
/// @file ody_dqs_track_utils.H
/// @brief  Tool to track and recal DQS
///
// *HWP HWP Owner: David J. Chung <dj.chung@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory Lab

#ifndef _ODY_DQS_TRACK_UTILS_H_
#define _ODY_DQS_TRACK_UTILS_H_

#include <fapi2.H>
#include <lib/dimm/ody_rank.H>
#include <lib/power_thermal/ody_temp_sensor_traits.H>
#include <lib/ccs/ody_ccs.H>
#include <ody_scom_mp_dbyte0_b0.H>

namespace mss
{
namespace ody
{

///
/// @brief Enum to keep track of the drift tracking mode register to be used
///
enum class drift_track_mr
{
    LSB_MR = 46,
    MSB_MR = 47,
};

///
/// @brief Enum to keep track of starting and stopping oscilators
///
enum class mpc_command
{
    OSCILLATOR_START = 0x7,
    OSCILLATOR_STOP  = 0x6,
};

///
/// @brief Enum to keep track of the thype of sensors
///
enum sensor_types
{
    THERMAL_SENSOR0 = 0,
    THERMAL_SENSOR1 = 1,
    THERMAL_SENSOR2 = 2,
    THERMAL_SENSOR3 = 3,
    DIFFERENTIAL_SENSOR = 4,
};

///
/// @brief Structure for exists and index vars of sensors
///
struct sensor_info_vars
{
    bool iv_dram_exists = false;
    bool iv_pmic_exists = false;
    bool iv_mem_buf_ext_exists = false;
    uint8_t iv_dram_index = 0;
    uint8_t iv_pmic_index = 0;
    uint8_t iv_mem_buf_ext_index = 0;
    uint16_t iv_pad = 0;
} __attribute__ ((__aligned__(8)));

///
/// @brief Structure to hold the saved MCBIST state during DQS drift tracking
/// @note The purpose of this struct is to save/restore BG memory diagnostics
///       while DQS drift tracking runs.
///
struct mcbist_state
{
    // iv_mcbparmq saves the min_cmd_gap and timebase
    fapi2::buffer<uint64_t> iv_mcbparmq;

    // iv_thresholds saves the stop conditions
    fapi2::buffer<uint64_t> iv_thresholds;

    // iv_current_addr saves the last address completed by the test, and thus the
    // starting address for when we resume the test
    fapi2::buffer<uint64_t> iv_current_addr;
} __attribute__ ((__aligned__(8)));

///
/// @brief Constants related to ATTR_ODY_DQS_TRACKING_LOG
///
enum logging_consts
{
    // Number of log entries in ATTR_ODY_DQS_TRACKING_LOG
    ATTR_ODY_DQS_TRACKING_LOG_ENTRIES = 24,
    // Number of DQS drift delta entries in a ATTR_ODY_DQS_TRACKING_LOG entry
    ATTR_ODY_DQS_TRACKING_LOG_DELTA_COUNT = 3,
};

///
/// @brief Maps DQS interval timer value to MR value encoding
/// @param [in] i_timer_val timer value in clocks from attribute
/// @return encoded MR value representing i_timer_val
///
uint8_t map_dqs_timer_val(const uint16_t i_timer_val);

///
/// @brief Asserts snoop on MSB or LSB for DQS->DQ tracking
/// @param [in] i_target OCMB to assert snoop on
/// @param [in] i_mr_number mr to asset snoop on, should only be 46 or 47
/// @return fapi2::FAPI2_RC_SUCCESS iff successful, fapi2 error code otherwise
///
fapi2::ReturnCode assert_mr_snoop (
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const drift_track_mr i_mr_number);

///
/// @brief Disables snoop on MSB or LSB for DQS->DQ tracking
/// @param [in] i_target OCMB to assert snoop on
/// @return fapi2::FAPI2_RC_SUCCESS iff successful, fapi2 error code otherwise
///
fapi2::ReturnCode disable_mr_snoop(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

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
    mss::ccs::program<mss::mc_type::ODYSSEY>& io_program);

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
    mss::ccs::program<mss::mc_type::ODYSSEY>& io_program);

///
/// @brief Sets mr 45 to ATTR_ODY_DQS_OSC_RUNTIME_SEL value
/// @param [in] i_rank_info rank info
/// @param [in, out] io_program the ccs program
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode set_dqs_timer_val(
    const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
    mss::ccs::program<mss::mc_type::ODYSSEY>& io_program);

///
/// @brief Execute CCS program in concurrent mode
/// @param [in] i_rank_info rank info
/// @param [in,out] io_program the ccs program
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode execute_concurrent_ccs(
    const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
    mss::ccs::program<mss::mc_type::ODYSSEY>& io_program);

///
/// @brief Tracks dqs and recalibrates to ATTR_ODY_DQS_OSC_RUNTIME_SEL
/// @param [in] i_rank_info rank info
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode dqs_recal(const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info);

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
        int16_t& o_current_temp_value);


///
/// @brief Helper function calculate the temperature delta of the DDIMM sensor
/// @param [in] i_thermal_sensor_prev_attr attribute value of previous value for diff sensor
/// @param [in] i_snsc_thermal_scom_data scom data of the sensor cache on-chip register
/// @param [out] o_temp_delta delta of the previous value and the current value of the available sensor
/// @return int16_t current temperature value
///
int16_t calc_thermal_sensor_temp_delta_helper(const int16_t i_thermal_sensor_prev_attr,
        const fapi2::buffer<uint64_t>& i_snsc_thermal_scom_data,
        int16_t& o_temp_delta_value);

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
                                       mss::ody::sensor_info_vars& o_sensor_info);

///
/// @brief Calculate the temperature delta of the sensor
/// @param [in] i_target OCMB target
/// @param [out] o_temp_delta delta of the previous value and the current value of the available sensor
/// @param [out] o_current_temp_values vector of current temperature of all the sensors
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode ody_calc_temp_sensors_delta(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        int16_t& o_temp_delta,
        int16_t (&o_current_temp_values)[mss::temp_sensor_traits<mss::mc_type::ODYSSEY>::temp_sensor::NUM_SENSORS],
        uint8_t& o_chosen_sensor_index);

///
/// @brief Check if a steer test is in the MCBIST
/// @param [in] i_target OCMB target
/// @param [out] o_is_steer will be set to true if steer test present, false otherwise
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode check_steer_subtest(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                      bool& o_is_steer);

///
/// @brief Check if MCBIST_PROGRAM_COMPLETE FIR is set
/// @param [in] i_target OCMB target
/// @param [out] o_prog_complete will be set to true if PROGRAM_COMPLETE is set, false otherwise
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode check_mcbist_program_complete(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        bool& o_prog_complete);

///
/// @brief Save state of MCBIST test
/// @param [in] i_target OCMB target
/// @param [in,out] io_saved_mcbist_state saved state of MCBIST
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode save_mcbist_state(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    mcbist_state& io_saved_mcbist_state);

///
/// @brief Restore state of MCBIST test
/// @param [in] i_target OCMB target
/// @param [in] i_saved_mcbist_state saved state of MCBIST
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode restore_mcbist_state(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                       const mcbist_state& i_saved_mcbist_state);

///
/// @brief Suspend and save the state of a background steer operation
/// @param [in] i_target OCMB target
/// @param [in,out] io_saved_mcbist_state saved state of MCBIST, to be used in later resume_bg_scrub call
/// @param [out] o_cannot_suspend will be set to true if steer test cannot be suspended, false otherwise
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode suspend_bg_scrub(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                   mcbist_state& io_saved_mcbist_state,
                                   bool& o_cannot_suspend);

///
/// @brief Restore the state of a background steer operation and restart it
/// @param [in] i_target OCMB target
/// @param [in] i_saved_mcbist_state saved state of MCBIST, from suspend_bg_scrub
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode resume_bg_scrub(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                  const mcbist_state& i_saved_mcbist_state);

///
/// @brief Convert DQS offset from 10-bit 2's complement to int16
/// @param [in] i_value input value that needs to be converted
/// @return 2's complement value in dec
/// @note modifies i_value in the process of conversion to save code space
///
inline int16_t convert_to_2s_complement(fapi2::buffer<uint64_t>& i_value)
{
    // Get the sign bit and write it to bits [0...53]
    i_value.writeBit<0, scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_TXTRKSTATES0_P0_TXTRKSTATES0_P0>(
        i_value.getBit<scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_TXTRKSTATES0_P0_TXTRKSTATES0_P0>());

    // Converting to 2's complement
    return static_cast<int16_t>(i_value);
}

///
/// @brief Insert a new DQS delta entry into the list of the biggest deltas
/// @param [in] i_delta input delta (absolute value)
/// @param [in] i_mrank input delta's mrank
/// @param [in] i_dram input delta's DRAM index
/// @param [in,out] io_deltas maximum computed deltas (in log format)
///
inline void insert_delta(const uint16_t i_delta,
                         const uint8_t i_mrank,
                         const uint8_t i_dram,
                         fapi2::buffer<uint16_t> (&io_deltas)[ATTR_ODY_DQS_TRACKING_LOG_DELTA_COUNT])
{
    // Bit indexes within a drift delta entry
    constexpr uint8_t DELTA_VAL = 6;
    constexpr uint8_t DELTA_VAL_LEN = 4;
    constexpr uint8_t RANK = 10;
    constexpr uint8_t DRAM = 11;
    constexpr uint8_t DRAM_LEN = 5;

    for (uint8_t l_idx = 0; l_idx < ATTR_ODY_DQS_TRACKING_LOG_DELTA_COUNT; l_idx++)
    {
        int16_t l_compare_delta = 0;
        io_deltas[l_idx].extractToRight<DELTA_VAL, DELTA_VAL_LEN>(l_compare_delta);

        if (i_delta > l_compare_delta)
        {
            // build a new delta entry
            fapi2::buffer<uint16_t> l_entry;
            l_entry.writeBit<RANK>(i_mrank)
            .insertFromRight<DRAM, DRAM_LEN>(i_dram)
            .insertFromRight<DELTA_VAL, DELTA_VAL_LEN>(i_delta);

            // shift the other delta entries later in the array, since they are smaller
            for (uint8_t l_shift_idx = ATTR_ODY_DQS_TRACKING_LOG_DELTA_COUNT - 1; l_shift_idx > l_idx; l_shift_idx--)
            {
                io_deltas[l_shift_idx] = io_deltas[l_shift_idx - 1];
            }

            // insert the new delta entry into the array
            io_deltas[l_idx] = l_entry;
            return;
        }
    }
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
                                      fapi2::buffer<uint16_t> (&o_deltas)[ATTR_ODY_DQS_TRACKING_LOG_DELTA_COUNT]);

///
/// @brief Insert a new DQS track log entry into the attribute array
/// @param [in] i_new_log_entry log entry to insert into the array
/// @param [in,out] io_log log array from ATTR_ODY_DQS_TRACKING_LOG
///
inline void insert_log_entry(const fapi2::buffer<uint64_t> i_new_log_entry,
                             uint64_t (&io_log)[ATTR_ODY_DQS_TRACKING_LOG_ENTRIES])
{
    constexpr uint64_t LAST_VALID_MASK  = 0x8000000000000000;
    constexpr uint64_t LAST_VALID_CLEAR = 0x7FFFFFFFFFFFFFFF;

    bool l_found_last_valid = false;

    // ATTR_ODY_DQS_TRACKING_LOG is a circular buffer with bit0 as its "last valid" bit
    // so we have to store the new entry in the slot after the one with "last valid" set
    // and clear the previous entry's "last valid" bit
    for (uint8_t l_idx = 0; l_idx < ATTR_ODY_DQS_TRACKING_LOG_ENTRIES; l_idx++)
    {
        if ((io_log[l_idx] & LAST_VALID_MASK) != 0)
        {
            io_log[l_idx] &= LAST_VALID_CLEAR;
            io_log[(l_idx + 1) % ATTR_ODY_DQS_TRACKING_LOG_ENTRIES] = i_new_log_entry;
            l_found_last_valid = true;
            break;
        }
    }

    // If we didn't find a "last valid" entry, just add the new entry in slot 0
    if (!l_found_last_valid)
    {
        io_log[0] = i_new_log_entry;
    }
}

///
/// @brief Log data from a DQS recalibration into attributes
/// @param [in] i_target OCMB_CHIP target
/// @param [in] i_trigger true if recal was triggered by temperature delta, false for any other reason
/// @param [in] i_counter value of ATTR_ODY_DQS_TRACKING_COUNT_SINCE_LAST_RECAL at time of recal
/// @param [in] i_temperature value of temperature used for recal trigger at time of recal
/// @param [in] i_deltas maximum computed DQS offset deltas (in log format)
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
inline fapi2::ReturnCode ody_dqs_track_log(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const bool i_trigger,
        const uint16_t i_counter,
        const int16_t i_temperature,
        fapi2::buffer<uint16_t> (&i_deltas)[ATTR_ODY_DQS_TRACKING_LOG_DELTA_COUNT])
{
    // Bit indexes within ATTR_ODY_DQS_TRACKING_LOG
    constexpr uint8_t LAST_VALID = 0;
    constexpr uint8_t TRIGGER_REASON = 1;
    constexpr uint8_t COUNTER = 2;
    constexpr uint8_t COUNTER_LEN = 16;
    constexpr uint8_t TEMPERATURE = 18;
    constexpr uint8_t TEMPERATURE_LEN = 7;
    constexpr uint8_t DELTA0 = 25;
    constexpr uint8_t DELTA1 = 35;
    constexpr uint8_t DELTA2 = 45;
    constexpr uint8_t DELTA_LEN = 10;

    uint64_t l_log[ATTR_ODY_DQS_TRACKING_LOG_ENTRIES] __attribute__ ((__aligned__(8))) = {0};
    fapi2::buffer<uint64_t> l_new_log_entry;

    // Read the log attribute
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DQS_TRACKING_LOG, i_target, l_log));

    // Store all info into l_new_log_entry
    l_new_log_entry.setBit<LAST_VALID>()
    .writeBit<TRIGGER_REASON>(i_trigger)
    .insertFromRight<COUNTER, COUNTER_LEN>(i_counter)
    .insertFromRight<TEMPERATURE, TEMPERATURE_LEN>(i_temperature)
    .insertFromRight<DELTA0, DELTA_LEN>(i_deltas[0])
    .insertFromRight<DELTA1, DELTA_LEN>(i_deltas[1])
    .insertFromRight<DELTA2, DELTA_LEN>(i_deltas[2]);

    // Store the new log entry in l_log's circular buffer
    insert_log_entry(l_new_log_entry, l_log);

    // Write the log attribute
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ODY_DQS_TRACKING_LOG, i_target, l_log));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Ody DQS track procedure
/// @param [in] i_target OCMB target
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode ody_dqs_track(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);


} // namespace ody
} // namespace mss
#endif
