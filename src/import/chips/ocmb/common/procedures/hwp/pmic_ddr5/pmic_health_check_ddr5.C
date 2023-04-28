/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/pmic_health_check_ddr5.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
/// @file pmic_health_check_ddr5.C
/// @brief To be run periodically at runtime to determine health of 4U parts
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HBRT
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <pmic_health_check_ddr5.H>
#include <lib/i2c/i2c_pmic.H>
#include <lib/utils/pmic_consts.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>

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
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode reset_breadcrumb(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                                   mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    using DT_REGS  = mss::dt::regs;

    for (auto l_dt_count = 0; l_dt_count < io_target_info.iv_number_of_target_infos_present; l_dt_count++)
    {
        // If the pmic is not overridden to disabled, run the below code
        mss::pmic::ddr5::run_if_present_dt(io_target_info, l_dt_count, [&io_target_info, l_dt_count]
                                           (const fapi2::Target<fapi2::TARGET_TYPE_POWER_IC>& i_dt) -> fapi2::ReturnCode
        {
            // Clear breadcrumb reg
            mss::pmic::ddr5::pmic_reg_write(io_target_info.iv_pmic_dt_map[l_dt_count], DT_REGS::BREADCRUMB, mss::pmic::ddr5::bread_crumb::ALL_GOOD);
            return fapi2::FAPI2_RC_SUCCESS;
        });
    }

    // Resetting the struct bread crumb variable
    io_health_check_info.iv_dt0.iv_breadcrumb = mss::pmic::ddr5::bread_crumb::ALL_GOOD;
    io_health_check_info.iv_dt1.iv_breadcrumb = mss::pmic::ddr5::bread_crumb::ALL_GOOD;
    io_health_check_info.iv_dt2.iv_breadcrumb = mss::pmic::ddr5::bread_crumb::ALL_GOOD;
    io_health_check_info.iv_dt3.iv_breadcrumb = mss::pmic::ddr5::bread_crumb::ALL_GOOD;

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check bread crumbs for a specific DT/PMIC
///
/// @param[in] i_target pmic target
/// @param[in,out] io_dt_health_check struct which contains DT regs info
/// @return FAPI2_RC_SUCCESS iff okay
///
void check_and_advance_breadcrumb_reg(const fapi2::Target<fapi2::TARGET_TYPE_POWER_IC>& i_target,
                                      mss::pmic::ddr5::dt_health_check_telemetry& io_dt_health_check)
{
    using DT_REGS  = mss::dt::regs;

    switch(io_dt_health_check.iv_breadcrumb)
    {
        case mss::pmic::ddr5::bread_crumb::ALL_GOOD:
            {
                // Set breadcrumb to FIRST_ATTEMPT
                io_dt_health_check.iv_breadcrumb = mss::pmic::ddr5::bread_crumb::FIRST_ATTEMPT;
                mss::pmic::i2c::reg_write(i_target, DT_REGS::BREADCRUMB, mss::pmic::ddr5::bread_crumb::FIRST_ATTEMPT);
                break;
            }

        case mss::pmic::ddr5::bread_crumb::FIRST_ATTEMPT:
            {
                // Set breadcrumb to RECOVERY_ATTEMPTED
                io_dt_health_check.iv_breadcrumb = mss::pmic::ddr5::bread_crumb::RECOVERY_ATTEMPTED;
                mss::pmic::i2c::reg_write(i_target, DT_REGS::BREADCRUMB, mss::pmic::ddr5::bread_crumb::RECOVERY_ATTEMPTED);
                // TODO: ZEN:MST-1905 Implement PMIC Health Check tool
                // Call recovery procedure
                break;
            }

        case mss::pmic::ddr5::bread_crumb::RECOVERY_ATTEMPTED:
            {
                // Set breadcrumb to STILL_A_FAIL
                io_dt_health_check.iv_breadcrumb = mss::pmic::ddr5::bread_crumb::STILL_A_FAIL;
                mss::pmic::i2c::reg_write(i_target, DT_REGS::BREADCRUMB, mss::pmic::ddr5::bread_crumb::STILL_A_FAIL);
                break;
            }

        case mss::pmic::ddr5::bread_crumb::STILL_A_FAIL:
            {
                // Do nothing
                // TK need to figure out what to do here exit wise
                // Maybe just send STILL_A_FAIL response
                break;
            }
    }
}

///
/// @brief Update bread crumbs for a specific PMIC/DT pair
///
/// @param[in] i_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @param[in] DT number to be checked for breadcrumbs
/// @return FAPI2_RC_SUCCESS iff okay
///
void update_pmic_breadcrumb(mss::pmic::ddr5::target_info_pmic_dt_pair& i_target_info,
                            mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info,
                            const uint8_t i_dt_number)
{
    switch(i_dt_number)
    {
        case mss::dt::dt_i2c_devices::DT0:
            {
                check_and_advance_breadcrumb_reg(i_target_info.iv_dt, io_health_check_info.iv_dt0);
                break;
            }

        case mss::dt::dt_i2c_devices::DT1:
            {
                check_and_advance_breadcrumb_reg(i_target_info.iv_dt, io_health_check_info.iv_dt1);
                break;
            }

        case mss::dt::dt_i2c_devices::DT2:
            {
                check_and_advance_breadcrumb_reg(i_target_info.iv_dt, io_health_check_info.iv_dt2);
                break;
            }

        case mss::dt::dt_i2c_devices::DT3:
            {
                check_and_advance_breadcrumb_reg(i_target_info.iv_dt, io_health_check_info.iv_dt3);
                break;
            }
    }
}

///
/// @brief Compare 4 phases provided from 4 pmics, update pmic states if needed
///
/// @tparam N size of the phase value data buffer
/// @tparam M size of the number of pmics
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @param[in] array of phase values
/// @param[in] array of pmics to do phase comparison on
/// @return mss::pmic::ddr5::pmic_state Aggregate pmic state, to be updated if needed
///
template <size_t N, size_t M>
fapi2::ReturnCode phase_comparison(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                                   mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info,
                                   const uint32_t (&i_phase_values)[N],
                                   const uint8_t (&i_pmic)[M])
{
    uint8_t l_phase_min_index = 0;
    uint8_t l_phase_max_index = 0;

    l_phase_min_index = check_phase_min(i_phase_values);
    l_phase_max_index = check_phase_max(i_phase_values);

    if (i_phase_values[l_phase_min_index] < mss::pmic::ddr5::PHASE_MIN)
    {
        const auto l_index = i_pmic[l_phase_min_index];
        mss::pmic::ddr5::run_if_present_dt(io_target_info, i_phase_values[l_phase_min_index],
                                           [&io_target_info, l_phase_min_index, l_index, &io_health_check_info]
                                           (const fapi2::Target<fapi2::TARGET_TYPE_POWER_IC>& i_dt) -> fapi2::ReturnCode
        {
            io_target_info.iv_pmic_dt_map[l_index].iv_pmic_state |= mss::pmic::ddr5::pmic_state::PMIC_CURRENT_IMBALANCE;
            update_pmic_breadcrumb(io_target_info.iv_pmic_dt_map[l_index], io_health_check_info, l_index);
            return fapi2::FAPI2_RC_SUCCESS;
        });
    }
    else if (i_phase_values[l_phase_max_index] > mss::pmic::ddr5::PHASE_MAX)
    {
        const auto l_index = i_pmic[l_phase_max_index];
        mss::pmic::ddr5::run_if_present_dt(io_target_info, i_phase_values[l_phase_max_index],
                                           [&io_target_info, l_phase_max_index, l_index, &io_health_check_info]
                                           (const fapi2::Target<fapi2::TARGET_TYPE_POWER_IC>& i_dt) -> fapi2::ReturnCode
        {
            io_target_info.iv_pmic_dt_map[l_index].iv_pmic_state |= mss::pmic::ddr5::pmic_state::PMIC_CURRENT_IMBALANCE;
            update_pmic_breadcrumb(io_target_info.iv_pmic_dt_map[l_index], io_health_check_info, l_index);
            return fapi2::FAPI2_RC_SUCCESS;
        });
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

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
                mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    uint32_t l_phase[4] = {};
    const uint8_t l_pmic[] = {0, 1, 2, 3};

    // IVDDQ is made up of the following phase currents
    // (SWA0 + SWB0)
    // (SWA1 + SWB1)
    // (SWA2 + SWB2)
    // (SWA3 + SWB2)

    l_phase[0] = (io_health_check_info.iv_pmic0.iv_swa_current_mA * mss::pmic::ddr5::CURRENT_MULTIPLIER) +
                 (io_health_check_info.iv_pmic0.iv_swb_current_mA * mss::pmic::ddr5::CURRENT_MULTIPLIER);

    l_phase[1] = (io_health_check_info.iv_pmic1.iv_swa_current_mA * mss::pmic::ddr5::CURRENT_MULTIPLIER) +
                 (io_health_check_info.iv_pmic1.iv_swb_current_mA * mss::pmic::ddr5::CURRENT_MULTIPLIER);

    l_phase[2] = (io_health_check_info.iv_pmic2.iv_swa_current_mA * mss::pmic::ddr5::CURRENT_MULTIPLIER) +
                 (io_health_check_info.iv_pmic2.iv_swb_current_mA * mss::pmic::ddr5::CURRENT_MULTIPLIER);

    l_phase[3] = (io_health_check_info.iv_pmic3.iv_swa_current_mA * mss::pmic::ddr5::CURRENT_MULTIPLIER) +
                 (io_health_check_info.iv_pmic3.iv_swb_current_mA * mss::pmic::ddr5::CURRENT_MULTIPLIER);

    phase_comparison(io_target_info, io_health_check_info, l_phase, l_pmic);
}

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
               mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    uint32_t l_phase[2] = {};
    const uint8_t l_pmic[] = {1, 2};

    // IVIO is made up of SWD1 and SWC2
    l_phase[0] = (io_health_check_info.iv_pmic1.iv_swd_current_mA * mss::pmic::ddr5::CURRENT_MULTIPLIER);
    l_phase[1] = (io_health_check_info.iv_pmic2.iv_swc_current_mA * mss::pmic::ddr5::CURRENT_MULTIPLIER);

    phase_comparison(io_target_info, io_health_check_info, l_phase, l_pmic);
}

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
               mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    uint32_t l_phase[2] = {};
    const uint8_t l_pmic[] = {0, 2};

    // IVPP is made up of SWD0 and SWD2
    l_phase[0] = (io_health_check_info.iv_pmic0.iv_swd_current_mA * mss::pmic::ddr5::CURRENT_MULTIPLIER);
    l_phase[1] = (io_health_check_info.iv_pmic2.iv_swd_current_mA * mss::pmic::ddr5::CURRENT_MULTIPLIER);

    phase_comparison(io_target_info, io_health_check_info, l_phase, l_pmic);
}

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
               mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    uint32_t l_phase[3] = {};
    const uint8_t l_pmic[] = {0, 1, 3};

    // IVDD is made up of SWC0, SWC1 and SWC3
    l_phase[0] = (io_health_check_info.iv_pmic0.iv_swc_current_mA * mss::pmic::ddr5::CURRENT_MULTIPLIER);
    l_phase[1] = (io_health_check_info.iv_pmic1.iv_swc_current_mA * mss::pmic::ddr5::CURRENT_MULTIPLIER);
    l_phase[2] = (io_health_check_info.iv_pmic3.iv_swc_current_mA * mss::pmic::ddr5::CURRENT_MULTIPLIER);

    phase_comparison(io_target_info, io_health_check_info, l_phase, l_pmic);
}

///
/// @brief Convert raw current values to readble hex values
///
/// @param[in,out] io_health_check_info health check struct for raw phase readings
/// @return void
/// @note This function should be called only once to convert the raw values else we will keep multiplying
/// the values with 125 and get a wrong conversion.
///
void convert_raw_current_readable_values(mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    // Overflow is not possible here as CURRENT_BITMAP_MULTIPLIER of 125 results in a max of
    // 125 * 0xFF = 0x7C83 which is within the uint16_t bounds
    // SWA
    io_health_check_info.iv_pmic0.iv_swa_current_mA = io_health_check_info.iv_pmic0.iv_swa_current_mA *
            mss::pmic::ddr5::CURRENT_MULTIPLIER;
    io_health_check_info.iv_pmic1.iv_swa_current_mA = io_health_check_info.iv_pmic1.iv_swa_current_mA *
            mss::pmic::ddr5::CURRENT_MULTIPLIER;
    io_health_check_info.iv_pmic2.iv_swa_current_mA = io_health_check_info.iv_pmic2.iv_swa_current_mA *
            mss::pmic::ddr5::CURRENT_MULTIPLIER;
    io_health_check_info.iv_pmic3.iv_swa_current_mA = io_health_check_info.iv_pmic3.iv_swa_current_mA *
            mss::pmic::ddr5::CURRENT_MULTIPLIER;

    // SWB
    io_health_check_info.iv_pmic0.iv_swb_current_mA = io_health_check_info.iv_pmic0.iv_swb_current_mA *
            mss::pmic::ddr5::CURRENT_MULTIPLIER;
    io_health_check_info.iv_pmic1.iv_swb_current_mA = io_health_check_info.iv_pmic1.iv_swb_current_mA *
            mss::pmic::ddr5::CURRENT_MULTIPLIER;
    io_health_check_info.iv_pmic2.iv_swb_current_mA = io_health_check_info.iv_pmic2.iv_swb_current_mA *
            mss::pmic::ddr5::CURRENT_MULTIPLIER;
    io_health_check_info.iv_pmic3.iv_swb_current_mA = io_health_check_info.iv_pmic3.iv_swb_current_mA *
            mss::pmic::ddr5::CURRENT_MULTIPLIER;

    // SWC
    io_health_check_info.iv_pmic0.iv_swc_current_mA = io_health_check_info.iv_pmic0.iv_swc_current_mA *
            mss::pmic::ddr5::CURRENT_MULTIPLIER;
    io_health_check_info.iv_pmic1.iv_swc_current_mA = io_health_check_info.iv_pmic1.iv_swc_current_mA *
            mss::pmic::ddr5::CURRENT_MULTIPLIER;
    io_health_check_info.iv_pmic2.iv_swc_current_mA = io_health_check_info.iv_pmic2.iv_swc_current_mA *
            mss::pmic::ddr5::CURRENT_MULTIPLIER;
    io_health_check_info.iv_pmic3.iv_swc_current_mA = io_health_check_info.iv_pmic3.iv_swc_current_mA *
            mss::pmic::ddr5::CURRENT_MULTIPLIER;

    // SWD
    io_health_check_info.iv_pmic0.iv_swd_current_mA = io_health_check_info.iv_pmic0.iv_swd_current_mA *
            mss::pmic::ddr5::CURRENT_MULTIPLIER;
    io_health_check_info.iv_pmic1.iv_swd_current_mA = io_health_check_info.iv_pmic1.iv_swd_current_mA *
            mss::pmic::ddr5::CURRENT_MULTIPLIER;
    io_health_check_info.iv_pmic2.iv_swd_current_mA = io_health_check_info.iv_pmic2.iv_swd_current_mA *
            mss::pmic::ddr5::CURRENT_MULTIPLIER;
    io_health_check_info.iv_pmic3.iv_swd_current_mA = io_health_check_info.iv_pmic3.iv_swd_current_mA *
            mss::pmic::ddr5::CURRENT_MULTIPLIER;

}

///
/// @brief Perform current imbalance to check PMIC faults
///
/// @param[in,out] io_target_info  PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct for raw phase readings
/// @return none
///
void check_current_imbalance(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                             mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    // VDDQ
    FAPI_INF("Checking voltage domain VDDQ");
    read_ivddq(io_target_info, io_health_check_info);

    // VIO
    FAPI_INF("Checking voltage domain VIO");
    read_ivio(io_target_info, io_health_check_info);

    // VPP
    FAPI_INF("Checking voltage domain VPP");
    read_ivpp(io_target_info, io_health_check_info);

    // VDD
    FAPI_INF("Checking voltage domain VDD");
    read_ivdd(io_target_info, io_health_check_info);

    convert_raw_current_readable_values(io_health_check_info);
}

///
/// @brief Check PMIC faults for all given PMICs
///
/// @param[in,out] io_target_info  PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @return mss::pmic::ddr5::pmic_state aggregrate state of all PMICs
/// @note As per the document provided by the Power team "Redundant PoD5 - Functional Specification
///      dated 20230412 version 0.07", the only data needed from the PMICs for health determination
///      are the rail currents to detect current imbalances (other status faults are summed up into
///      the DT IC “GPI_1” bit)
///
mss::pmic::ddr5::pmic_state check_pmic_faults(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
        mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    using CONSTS  = mss::pmic::id;

    check_current_imbalance(io_target_info, io_health_check_info);

    return static_cast<mss::pmic::ddr5::pmic_state>(std::max({io_target_info.iv_pmic_dt_map[CONSTS::PMIC0].iv_pmic_state,
            io_target_info.iv_pmic_dt_map[CONSTS::PMIC1].iv_pmic_state,
            io_target_info.iv_pmic_dt_map[CONSTS::PMIC2].iv_pmic_state,
            io_target_info.iv_pmic_dt_map[CONSTS::PMIC3].iv_pmic_state
                                                             }));
}

///
/// @brief Check for DT faults in regs of a specific DT
///
/// @param[in] dt_health_check_telemetry struct which contains DT regs data
/// @return mss::pmic::ddr5::dt_state fault state of current DT
///
mss::pmic::ddr5::dt_state get_dt_state(const mss::pmic::ddr5::dt_health_check_telemetry& i_dt_health_check)
{
    using DT_FIELDS  = mss::dt::fields;
    mss::pmic::ddr5::dt_state l_state = mss::pmic::ddr5::dt_state::DT_ALL_GOOD;

    fapi2::buffer<uint16_t> l_reg0 = i_dt_health_check.iv_ro_inputs_0;
    fapi2::buffer<uint16_t> l_reg1 = i_dt_health_check.iv_ro_inputs_1;

    if(l_reg1.getBit<DT_FIELDS::GPI_1>())
    {
        l_state = mss::pmic::ddr5::dt_state::DT_GPI_1;
    }
    else if (l_reg0.getBit<DT_FIELDS::SWIN_FAULT_A>())
    {
        l_state = mss::pmic::ddr5::dt_state::DT_SWIN_FAULT_A;
    }
    else if (l_reg0.getBit<DT_FIELDS::SWIN_FAULT_B>())
    {
        l_state = mss::pmic::ddr5::dt_state::DT_SWIN_FAULT_B;
    }
    else if (l_reg0.getBit<DT_FIELDS::SWIN_FAULT_C>())
    {
        l_state = mss::pmic::ddr5::dt_state::DT_SWIN_FAULT_C;
    }
    else if (l_reg0.getBit<DT_FIELDS::SWIN_FAULT_D>())
    {
        l_state = mss::pmic::ddr5::dt_state::DT_SWIN_FAULT_D;
    }

    return l_state;
}

///
/// @brief Check DT faults for all given DTs
///
/// @param[in,out] io_target_info  PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @return mss::pmic::ddr5::dt_state aggregrate state of all DTs
///
mss::pmic::ddr5::dt_state check_dt_faults(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
        mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    using CONSTS = mss::dt::dt_i2c_devices;

    io_target_info.iv_pmic_dt_map[CONSTS::DT0].iv_dt_state = get_dt_state(io_health_check_info.iv_dt0);
    io_target_info.iv_pmic_dt_map[CONSTS::DT1].iv_dt_state = get_dt_state(io_health_check_info.iv_dt1);
    io_target_info.iv_pmic_dt_map[CONSTS::DT2].iv_dt_state = get_dt_state(io_health_check_info.iv_dt2);
    io_target_info.iv_pmic_dt_map[CONSTS::DT3].iv_dt_state = get_dt_state(io_health_check_info.iv_dt3);

    if (io_target_info.iv_pmic_dt_map[CONSTS::DT0].iv_dt_state)
    {
        check_and_advance_breadcrumb_reg(io_target_info.iv_pmic_dt_map[CONSTS::DT0].iv_dt, io_health_check_info.iv_dt0);
    }

    if (io_target_info.iv_pmic_dt_map[CONSTS::DT1].iv_dt_state)
    {
        check_and_advance_breadcrumb_reg(io_target_info.iv_pmic_dt_map[CONSTS::DT1].iv_dt, io_health_check_info.iv_dt1);
    }

    if (io_target_info.iv_pmic_dt_map[CONSTS::DT2].iv_dt_state)
    {
        check_and_advance_breadcrumb_reg(io_target_info.iv_pmic_dt_map[CONSTS::DT2].iv_dt, io_health_check_info.iv_dt2);
    }

    if (io_target_info.iv_pmic_dt_map[CONSTS::DT3].iv_dt_state)
    {
        check_and_advance_breadcrumb_reg(io_target_info.iv_pmic_dt_map[CONSTS::DT3].iv_dt, io_health_check_info.iv_dt3);
    }

    return static_cast<mss::pmic::ddr5::dt_state>(std::max({io_target_info.iv_pmic_dt_map[CONSTS::DT0].iv_dt_state,
            io_target_info.iv_pmic_dt_map[CONSTS::DT1].iv_dt_state,
            io_target_info.iv_pmic_dt_map[CONSTS::DT2].iv_dt_state,
            io_target_info.iv_pmic_dt_map[CONSTS::DT3].iv_dt_state
                                                           }));
}

///
/// @brief Store the read regs into struct
///
/// @param[in] i_data PMIC data to be filled into the health_check struct
/// @param[in,out] io_pmic_health_check struct to be filled in
/// @return None
///
void fill_pmic_struct(const fapi2::buffer<uint8_t> (&i_data)[NUMBER_PMIC_REGS_READ],
                      mss::pmic::ddr5::pmic_health_check_telemetry& io_pmic_health_check)
{
    io_pmic_health_check.iv_r04 = i_data[data_position::DATA_0];
    io_pmic_health_check.iv_r05 = i_data[data_position::DATA_1];
    io_pmic_health_check.iv_r06 = i_data[data_position::DATA_2];
    io_pmic_health_check.iv_r07 = i_data[data_position::DATA_3];
    io_pmic_health_check.iv_r08 = i_data[data_position::DATA_4];
    io_pmic_health_check.iv_r09 = i_data[data_position::DATA_5];
    io_pmic_health_check.iv_r0a = i_data[data_position::DATA_6];
    io_pmic_health_check.iv_r0b = i_data[data_position::DATA_7];
    io_pmic_health_check.iv_swa_current_mA = i_data[data_position::DATA_8];
    io_pmic_health_check.iv_swb_current_mA = i_data[data_position::DATA_9];
    io_pmic_health_check.iv_swc_current_mA = i_data[data_position::DATA_10];
    io_pmic_health_check.iv_swd_current_mA = i_data[data_position::DATA_11];
}

///
/// @brief Store the read regs into struct
///
/// @param[in] i_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode read_pmic_regs(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                                 mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    using CONSTS  = mss::pmic::id;
    fapi2::buffer<uint8_t> l_data_buffer[NUMBER_PMIC_REGS_READ];
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    for (auto l_pmic_count = 0; l_pmic_count < io_target_info.iv_number_of_target_infos_present; l_pmic_count++)
    {
        // If the pmic is not overridden to disabled, run the below code
        mss::pmic::ddr5::run_if_present(io_target_info, l_pmic_count, [&io_target_info, l_pmic_count, &l_data_buffer]
                                        (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic) -> fapi2::ReturnCode
        {
            using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;

            mss::pmic::ddr5::pmic_reg_read_contiguous(io_target_info.iv_pmic_dt_map[l_pmic_count], REGS::R04, l_data_buffer);
            return fapi2::FAPI2_RC_SUCCESS;
        });

        switch(l_pmic_count)
        {
            case CONSTS::PMIC0:
                fill_pmic_struct(l_data_buffer, io_health_check_info.iv_pmic0);
                break;

            case CONSTS::PMIC1:
                fill_pmic_struct(l_data_buffer, io_health_check_info.iv_pmic1);
                break;

            case CONSTS::PMIC2:
                fill_pmic_struct(l_data_buffer, io_health_check_info.iv_pmic2);
                break;

            case CONSTS::PMIC3:
                fill_pmic_struct(l_data_buffer, io_health_check_info.iv_pmic3);
                break;
        }
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Store the read regs into struct
///
/// @param[in] i_data DT data to be filled into the health_check struct
/// @param[in,out] io_dt_health_check struct to be filled in
/// @return None
///
void fill_dt_struct(const fapi2::buffer<uint8_t> (&i_data)[NUMBER_DT_REGS_READ],
                    mss::pmic::ddr5::dt_health_check_telemetry& io_dt_health_check)
{
    static constexpr uint8_t NUMBER_OF_BITS = 8;

    io_dt_health_check.iv_ro_inputs_1 = i_data[data_position::DATA_0];
    io_dt_health_check.iv_ro_inputs_1 <<= NUMBER_OF_BITS;
    io_dt_health_check.iv_ro_inputs_1 |= i_data[data_position::DATA_1];

    io_dt_health_check.iv_ro_inputs_0 = i_data[data_position::DATA_2];
    io_dt_health_check.iv_ro_inputs_0 <<= NUMBER_OF_BITS;
    io_dt_health_check.iv_ro_inputs_0 |= i_data[data_position::DATA_3];
}

///
/// @brief Read all DT regs and store in the array of structs
///
/// @param[in] i_target_info PMIC and DT target info struct
/// @param[in,out] io_health_check_info health check struct
/// @return None
///
void read_dt_regs(mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
                  mss::pmic::ddr5::health_check_telemetry_data& io_health_check_info)
{
    using CONSTS  = mss::dt::dt_i2c_devices;

    fapi2::buffer<uint8_t> l_data_buffer[NUMBER_DT_REGS_READ];

    for (auto l_dt_count = 0; l_dt_count < io_target_info.iv_number_of_target_infos_present; l_dt_count++)
    {
        // If the pmic is not overridden to disabled, run the below code
        mss::pmic::ddr5::run_if_present_dt(io_target_info, l_dt_count, [&io_target_info, l_dt_count, &l_data_buffer]
                                           (const fapi2::Target<fapi2::TARGET_TYPE_POWER_IC>& i_pmic) -> fapi2::ReturnCode
        {
            using DT_REGS  = mss::dt::regs;

            mss::pmic::ddr5::dt_reg_read_contiguous(io_target_info.iv_pmic_dt_map[l_dt_count], DT_REGS::RO_INPUTS_1, l_data_buffer);
            return fapi2::FAPI2_RC_SUCCESS;
        });

        switch(l_dt_count)
        {
            case CONSTS::DT0:
                fill_dt_struct(l_data_buffer, io_health_check_info.iv_dt0);
                break;

            case CONSTS::DT1:
                fill_dt_struct(l_data_buffer, io_health_check_info.iv_dt1);
                break;

            case CONSTS::DT2:
                fill_dt_struct(l_data_buffer, io_health_check_info.iv_dt2);
                break;

            case CONSTS::DT3:
                fill_dt_struct(l_data_buffer, io_health_check_info.iv_dt3);
                break;
        }
    }
}

///
/// @brief Runtime Health check for 4U parts
///
/// @param[in] i_ocmb_target ocmb target
/// @param[out] o_data hwp_data_ostream of struct information
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode pmic_health_check_ddr5(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
        fapi2::hwp_data_ostream& o_data)
{
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

    FAPI_INF(GENTARGTIDFORMAT " Running pmic_health_check HWP", GENTARGTID(i_ocmb_target));
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    mss::pmic::ddr5::health_check_telemetry_data l_info;
    l_info.iv_aggregate_state = mss::pmic::ddr5::aggregate_state::N_PLUS_1;

    mss::pmic::ddr5::dt_state l_dt_state = mss::pmic::ddr5::dt_state::DT_ALL_GOOD;
    mss::pmic::ddr5::pmic_state l_pmic_state = mss::pmic::ddr5::pmic_state::PMIC_ALL_GOOD;

    // Grab the targets as a struct, if they exist
    mss::pmic::ddr5::target_info_redundancy_ddr5 l_target_info(i_ocmb_target, l_rc);
    FAPI_TRY(mss::pmic::ddr5::set_pmic_dt_states(l_target_info));

    // Check if we have recevied any PMIC/DT pairs. Else declare LOST
    if (!l_target_info.iv_number_of_target_infos_present)
    {
        l_info.iv_aggregate_state = mss::pmic::ddr5::aggregate_state::LOST;
        FAPI_ERR(GENTARGTIDFORMAT " No PMICs or DTs present", GENTARGTID(i_ocmb_target));
        // TODO: ZEN:MST-1905 Implement PMIC Health Check tool
        // Need to talk to HB, power and Z team to come to an agreement on the number of bytes to be passed
        //FAPI_TRY(send_struct(l_info.iv_aggregate_state, o_data));
        return fapi2::FAPI2_RC_FALSE;
    }

    // Platform has asserted we will receive at least 3 DT targets iff 4U
    // Do a check to see if we are 4U by checking for minimum 3 DT targets
    if (!mss::pmic::ddr5::is_4u(i_ocmb_target))
    {
        l_info.iv_aggregate_state = mss::pmic::ddr5::aggregate_state::DIMM_NOT_4U;
        FAPI_ERR(GENTARGTIDFORMAT " DIMM is not 4U", GENTARGTID(i_ocmb_target));
        //FAPI_TRY(send_struct(l_info.iv_aggregate_state, o_data));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    if(l_target_info.iv_number_of_target_infos_present <= CONSTS::NUM_PRIMARY_PMICS_DDR5)
    {
        l_info.iv_aggregate_state = mss::pmic::ddr5::aggregate_state::N_MODE;
        FAPI_ERR(GENTARGTIDFORMAT " Declaring N-mode dure to not enough functional PMICs/DTs provided",
                 GENTARGTID(i_ocmb_target));
        //FAPI_TRY(send_struct(l_info.iv_aggregate_state, o_data));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Read and store DT regs for fault calculations
    read_dt_regs(l_target_info, l_info);

    // Read and store DT regs for fault calculations
    FAPI_TRY(read_pmic_regs(l_target_info, l_info));

    // Check DT faults and set aggregate state
    l_dt_state = check_dt_faults(l_target_info, l_info);

    // If not faults on DT, then check for PMIC faults
    if (!l_dt_state)
    {
        l_pmic_state = check_pmic_faults(l_target_info, l_info);
    }

    // If no pmic faults then reset the breadcrumb regs
    if (!l_pmic_state)
    {
        FAPI_TRY(reset_breadcrumb(l_target_info, l_info));
    }

    // TODO: ZEN:MST-1905 Implement PMIC Health Check tool
    // TK: in next commit
    // set_pmic_n_mode(l_target_info, l_info);
    // generate_response(l_info, o_data);

fapi_try_exit:
    return fapi2::current_err;
}
