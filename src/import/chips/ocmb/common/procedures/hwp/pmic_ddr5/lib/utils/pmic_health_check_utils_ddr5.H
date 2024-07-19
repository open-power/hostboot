/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/lib/utils/pmic_health_check_utils_ddr5.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
/// @file pmic_health_check_utils_ddr5.H
/// @brief To be run periodically at runtime to determine n-mode states of 4U parts
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HBRT
// EKB-Mirror-To: hostboot

#ifndef __PMIC_HEALTH_CHECK_UTILS_DDR5_H__
#define __PMIC_HEALTH_CHECK_UTILS_DDR5_H__

#include <fapi2.H>
#include <lib/utils/pmic_common_utils_ddr5.H>
#include <hwp_data_stream.H>

static constexpr uint8_t NUMBER_ADDITIONAL_DT_REGS_READ = 2;
static constexpr uint8_t NUMBER_DT_REGS_READ = 2;
static constexpr uint8_t NUMBER_PMIC_REGS_READ = 12;
static constexpr uint8_t SIZEOF_AGGREGATE_STATE = 1;
static constexpr uint8_t SIZEOF_GI2C_FAIL_DATA = 11;
static constexpr uint8_t GI2C_FAIL_MAX_COUNT   = 3;

typedef fapi2::ReturnCode (*pmic_health_check_ddr5_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
    fapi2::hwp_data_ostream&);

///
/// @brief Check minimum phase value from the given array
///
/// @tparam N size of the phase value data buffer
/// @param[in] array of phase values
/// @return index of minimum phase value from the array
///
template <size_t N>
uint8_t check_phase_min(const uint32_t (&i_phase)[N])
{
    uint8_t l_min = 0;

    for ( uint8_t l_count = 0; l_count < N; l_count++ )
    {
        if (i_phase[l_count] < i_phase[l_min])
        {
            l_min = l_count;
        }
    }

    return l_min;
}

///
/// @brief Check maximum phase value from the given array
///
/// @tparam N size of the phase value data buffer
/// @param[in] array of phase values
/// @return index of maximum phase value from the array
///
template <size_t N>
uint8_t check_phase_max(const uint32_t (&i_phase)[N])
{
    uint8_t l_max = 0;

    for ( uint8_t l_count = 0; l_count < N; l_count++ )
    {
        if (i_phase[l_count] > i_phase[l_max])
        {
            l_max = l_count;
        }
    }

    return l_max;
}

///
/// @brief Reset bread crumbs for all PMICs
///
/// @param[in,out] i_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @return none
///
void reset_breadcrumb(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                      mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Attempt recovery for a specific DT/PMIC pair
///
/// @param[in,out] io_pmic_dt_target_info PMIC and DT target info struct
/// @return None
///
void attempt_recovery(mss::pmic::ddr5::target_info_pmic_dt_pair& io_pmic_dt_target_info);

///
/// @brief Check bread crumbs for a specific DT/PMIC
///
/// @param[in,out] io_pmic_dt_target_info PMIC and DT target info struct
/// @param[in,out] io_dt_health_check struct which contains DT regs info
/// None
///
void check_and_advance_breadcrumb_reg(mss::pmic::ddr5::target_info_pmic_dt_pair& io_pmic_dt_target_info,
                                      mss::pmic::ddr5::dt_health_check_telemetry& io_dt_health_check);

///
/// @brief Compare 4 phases provided from 4 pmics, update pmic states if needed
///
/// @tparam N size of the phase value data buffer
/// @tparam M size of the number of pmics
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @param[in] array of phase values
/// @param[in] array of pmics to do phase comparison on
/// @return none
///
template <size_t N, size_t M>
void phase_comparison(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                      mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info,
                      const uint32_t (&i_phase_values)[N],
                      const uint8_t (&i_pmic)[M]);

///
/// @brief Calculate VDDQ current and determine if any current imbalance
///
/// @param[in,out] io_target_info  PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct for raw phase readings
/// @return None
/// @note The domain current calculations has been taken from the document provided by the Power team
///      "Redundant PoD5 - Functional Specification dated 20230421 version 0.08".
///
void read_ivddq(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Calculate VIO current and determine if any current imbalance
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct for raw phase readings
/// @return None
/// @note The domain current calculations has been taken from the document provided by the Power team
///      "Redundant PoD5 - Functional Specification dated 20230421 version 0.08".
///
void read_ivio(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
               mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Calculate VPP current and determine if any current imbalance
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct for raw phase readings
/// @return None
/// @note The domain current calculations has been taken from the document provided by the Power team
///      "Redundant PoD5 - Functional Specification dated 20230421 version 0.08".
///
void read_ivpp(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
               mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Calculate VDD current and determine if any current imbalance
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct for raw phase readings
/// @return None
/// @note The domain current calculations has been taken from the document provided by the Power team
///      "Redundant PoD5 - Functional Specification dated 20230421 version 0.08".
///
void read_ivdd(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
               mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Check PMIC faults for all given PMICs
///
/// @param[in,out] io_target_info  PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @return None
///
inline void set_pmic_states(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                            mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    for (auto l_index = 0; l_index < io_target_info.iv_number_of_target_infos_present; l_index++)
    {
        // Update breadcrumb if PMIC state is VIN_OK_Z or CURRENT_IMBALANCE or both
        if (((io_target_info.iv_pmic_dt_map[l_index].iv_pmic_state & mss::pmic::ddr5::pmic_state::PMIC_VIN_OK_Z) != 0) ||
            ((io_target_info.iv_pmic_dt_map[l_index].iv_pmic_state & mss::pmic::ddr5::pmic_state::PMIC_CURRENT_IMBALANCE) !=
             0))
        {
            mss::pmic::ddr5::run_if_present_dt(io_target_info, l_index,
                                               [&io_target_info, l_index, &io_health_check_info]
                                               (const fapi2::Target<fapi2::TARGET_TYPE_POWER_IC>& i_dt) -> fapi2::ReturnCode
            {
                check_and_advance_breadcrumb_reg(io_target_info.iv_pmic_dt_map[l_index], io_health_check_info.iv_dt[l_index]);
                return fapi2::FAPI2_RC_SUCCESS;
            });
        }
    }
}

///
/// @brief Check PMIC faults for all given PMICs
///
/// @param[in,out] io_target_info  PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @return None
/// @note As per the document provided by the Power team "Redundant PoD5 - Functional Specification
///      dated 20230412 version 0.07", the only data needed from the PMICs for health determination
///      are the rail currents to detect current imbalances (other status faults are summed up into
///      the DT IC “GPI_1” bit)
///
void check_pmic_faults(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                       mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Check for DT faults in regs of a specific DT
///
/// @param[in,out] io_target_info  PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @return none
///
void get_dt_state(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                  mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Reverse the DT regs. When performing bit operations on DT regs,
///        we have to flip the buffer from PMIC style[7:0], to fapi2-style [0:7].
///        After the operations have been performed, we would like to revert
///        the style so as to print the data in PMIC style.
///
/// @param[in] i_number_of_target_infos_present number of DT targets to reverse regs
/// @param[in,out] io_health_check_info struct to be filled in
/// @return None
///
void reverse_dt_regs(const uint8_t i_number_of_target_infos_present,
                     mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Check DT faults for all given DTs
///
/// @param[in,out] io_target_info  PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @return mss::pmic::ddr5::dt_state aggregrate state of all DTs
///
mss::pmic::ddr5::dt_state check_dt_faults(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
        mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Store the read regs into struct
///
/// @param[in] i_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @return none
///
void read_pmic_regs(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                    mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Read all DT regs and store in the array of structs
///
/// @param[in] i_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @return None
///
void read_dt_regs(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                  mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Check if n mode is detected from the states of the individual PMIC/DT pair
///
/// @param[in,out] io_health_check_info health check struct
/// @return aggregate state of the DIMM
///
mss::pmic::ddr5::aggregate_state check_n_mode(mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Collect additional ADC data in case of N_MODE detected
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_additional_info additional health check data
/// @return None
///
void collect_additional_adc_data(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                                 mss::pmic::ddr5::additional_n_mode_telemetry_data& io_additional_info);

///
/// @brief Collect additional PMIC data in case of N_MODE detected
///
/// @param[in] i_target_info PMIC and DT target info struct
/// @param[in,out] io_additional_info additional health check data
/// @return None
///
void collect_additional_pmic_data(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                                  mss::pmic::ddr5::additional_n_mode_telemetry_data& io_additional_info);

///
/// @brief Collect additional DT data in case of N_MODE detected
///
/// @param[in] i_target_info PMIC and DT target info struct
/// @param[in,out] io_additional_info additional health check data
/// @return None
///
void collect_additional_dt_data(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                                mss::pmic::ddr5::additional_n_mode_telemetry_data& io_additional_info);

///
/// @brief Collect additional data in case of N_MODE detected
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_additional_info additional health check data
/// @return None
///
void collect_additional_n_mode_data(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                                    mss::pmic::ddr5::additional_n_mode_telemetry_data& io_additional_info);

///
/// @brief Send the consolidated_health_check_data struct in case of n-mode
///
/// @param[in] i_info consolidated_health_check_data struct
/// @param[in] i_gi2c_fail_state_data data struct
/// @oaram[in] i_length_of_data number of bytes to be trasmitted
/// @param[out] o_data hwp_data_ostream data stream
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode send_struct(mss::pmic::ddr5::consolidated_health_check_data& i_info,
                              mss::pmic::ddr5::gi2c_fail_state_data& i_gi2c_fail_state_data,
                              const uint16_t i_length_of_data,
                              fapi2::hwp_data_ostream& o_data);

///
/// @brief Generate and send the io_consolidated_data struct
///
/// @param[in] i_target_info PMIC and DT target info struct
/// @param[in] i_health_check_info health check struct
/// @param[in] i_additional_info additional data collected struct in case of n-mode detected
/// @param[in] i_periodic_tele_info periodic telemetry data collected struct in case of n-mode detected
/// @param[in,out] io_consolidated_data consolidate data of all the structs to be sent
/// @param[in] i_number_bytes_to_send number of bytes to send as response to this HWP
/// @param[out] o_data hwp_data_ostream of struct information
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode generate_and_send_response(const mss::pmic::ddr5::target_info_redundancy_ddr5& i_target_info,
        const mss::pmic::ddr5::health_check_telemetry_data& i_health_check_info,
        const mss::pmic::ddr5::additional_n_mode_telemetry_data& i_additional_info,
        const mss::pmic::ddr5::periodic_telemetry_data& i_periodic_tele_info,
        mss::pmic::ddr5::consolidated_health_check_data& io_consolidated_data,
        const uint8_t i_number_bytes_to_send,
        fapi2::hwp_data_ostream& o_data);

///
/// @brief Check if at least one PMIC has issues and collect additional data in case of issues
///
/// @param[in] i_failed_pmics n-mode states of the 4 PMICs
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_additional_info additional health check data
/// @param[in,out] io_failed_pmic_number the failed PMIC/DT number for FFDC collection
/// @return true/false at least one pmic is bad
///
bool mnfg_mode_check_failed_pmics (const mss::pmic::n_mode i_failed_pmics[mss::dt::dt_i2c_devices::NUM_TOTAL_DEVICES],
                                   mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                                   mss::pmic::ddr5::additional_n_mode_telemetry_data& io_additional_info,
                                   uint8_t& io_failed_pmic_number);

///
/// @brief Resets breadcrumb for PMIC/DT pair if both PMIC and DT states are ALL_GOOD
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @param[in] i_mnfg_thresholds mnfg attribute flag
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode check_and_reset_breadcrumb(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
        mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info,
        const bool i_mnfg_thresholds);

///
/// @brief Check all the breadcrumbs and return aggregate state as N_MODE if any PMIC/DT
///         pair has breadcrumb set to STILL_A_FAIL
///
/// @param[in,out] io_health_check_info health check struct
/// @return Aggregate state
///
inline mss::pmic::ddr5::aggregate_state check_breadcrumbs_subsequent_n_modes(const
        mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    using CONSTS = mss::dt::dt_i2c_devices;

    if ((io_health_check_info.iv_dt[CONSTS::DT0].iv_breadcrumb == mss::pmic::ddr5::bread_crumb::STILL_A_FAIL) ||
        (io_health_check_info.iv_dt[CONSTS::DT1].iv_breadcrumb == mss::pmic::ddr5::bread_crumb::STILL_A_FAIL) ||
        (io_health_check_info.iv_dt[CONSTS::DT2].iv_breadcrumb == mss::pmic::ddr5::bread_crumb::STILL_A_FAIL) ||
        (io_health_check_info.iv_dt[CONSTS::DT3].iv_breadcrumb == mss::pmic::ddr5::bread_crumb::STILL_A_FAIL))
    {
        return mss::pmic::ddr5::aggregate_state::N_MODE;
    }

    return mss::pmic::ddr5::aggregate_state::N_PLUS_1;
}

///
/// @brief Check if any of the ADC/PMI/DT show I2C error
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @return None
///
void check_gi2c_fail_state(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                           mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info);

///
/// @brief Set/clear the GI2C fail count based on the aggregate state.
///        For P systems, data needs to be sent only the first 3 times, after that just
///        the 1 byte of aggregate state. For Z systems, data can be sent everytime GI2C
///        fail is encountered as Z is not restricted by the number of logs generated
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @param[in,out] io_number_bytes_to_send number of bytes to send as log
/// @return None
///
void set_gi2c_fail_count(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                         mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info,
                         uint8_t& io_number_bytes_to_send);

///
/// @brief Runs the actual health check for 4U parts
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @param[in,out] io_additional_info additional health check data
/// @param[in,out] io_periodic_tele_info periodic telemetry data
/// @param[in,out] io_number_bytes_to_send number of bytes to send as response to this HWP
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode health_check_ddr5(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                                    mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info,
                                    mss::pmic::ddr5::additional_n_mode_telemetry_data& io_additional_info,
                                    mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info,
                                    uint8_t& io_number_bytes_to_send);

///
/// @brief Runtime Health check helper for 4U parts
///
/// @param[in] i_ocmb_target ocmb target
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @param[in,out] io_additional_info additional health check data
/// @param[in,out] io_periodic_tele_info periodic telemetry data
/// @param[in,out] io_consolidated_data consolidate data of all the structs to be sent
/// @param[in,out] io_number_bytes_to_send number of bytes to send as response to this HWP
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode pmic_health_check_ddr5_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
        mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
        mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info,
        mss::pmic::ddr5::additional_n_mode_telemetry_data& io_additional_info,
        mss::pmic::ddr5::periodic_telemetry_data& io_periodic_tele_info,
        mss::pmic::ddr5::consolidated_health_check_data& io_consolidated_health_check_data,
        uint8_t& io_number_bytes_to_send);

#endif
