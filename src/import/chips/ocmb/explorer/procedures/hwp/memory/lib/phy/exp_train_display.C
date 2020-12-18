/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/phy/exp_train_display.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file exp_train_display.C
/// @brief Procedures used to display the training response information
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/shared/exp_defaults.H>
#include <lib/shared/exp_consts.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/index.H>
#include <generic/memory/lib/utils/c_str.H>
#include <exp_data_structs.H>
#include <lib/phy/exp_train_display.H>

namespace mss
{
namespace exp
{
namespace train
{

///
/// @brief Displays training information
/// @param[in] i_target the OCMB target
/// @param[in] i_lane the lane for the training information
/// @param[in] i_data the training data for this lane
///
void display_lane_results(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                          const uint64_t i_lane,
                          const uint16_t i_data)
{
    // Extracts the per-rank information
    fapi2::buffer<uint16_t> l_data(i_data);
    uint8_t l_rank0 = 0;
    uint8_t l_rank1 = 0;
    uint8_t l_rank2 = 0;
    uint8_t l_rank3 = 0;

    l_data.extractToRight<0, BITS_PER_NIBBLE>(l_rank3)
    .extractToRight<BITS_PER_NIBBLE, BITS_PER_NIBBLE>(l_rank2)
    .extractToRight<BITS_PER_NIBBLE * 2, BITS_PER_NIBBLE>(l_rank1)
    .extractToRight<BITS_PER_NIBBLE * 3, BITS_PER_NIBBLE>(l_rank0);

    constexpr uint16_t CLEAN = 0;

    // If we passed, display the information as only as MFG - we don't want to clutter the screen with too much information
    if(CLEAN == i_data)
    {
        FAPI_MFG("%s lane: %u PASSING R0:%u R1:%u R2:%u R3:%u",
                 mss::c_str(i_target), i_lane,
                 l_rank0, l_rank1, l_rank2, l_rank3);
    }

    // If we failed, display the information as INF
    else
    {
        FAPI_INF("%s lane: %u FAILING R0:%u R1:%u R2:%u R3:%u",
                 mss::c_str(i_target), i_lane,
                 l_rank0, l_rank1, l_rank2, l_rank3);
    }
}

///
/// @brief Display train_2d_read_eye_msdg_t response struct
///
/// @param[in] i_target OCMB target
/// @param[in] i_training_info training info struct
///
void display_train_2d_read_eye(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                               const user_2d_eye_response_1_msdg_t& i_training_info)
{
    FAPI_MFG("%s %s (EYE MIN/MAX):", mss::c_str(i_target), "VrefDAC0");
    FAPI_MFG("%s Ranks for the 2D RD eye are in the PHY perspectives", mss::c_str(i_target));

    for (uint8_t l_rank = 0; l_rank < TRAINING_RESPONSE_NUM_RANKS; ++l_rank)
    {
        for (uint8_t l_dbyte = 0; l_dbyte < DBYTE_N_SIZE; ++l_dbyte)
        {
            for (uint8_t l_bit = 0; l_bit < BIT_N_SIZE; ++l_bit)
            {
                for (uint8_t l_eye_index = 0; l_eye_index < EYE_MIN_MAX_SIZE; ++l_eye_index)
                {
                    const auto l_eye_min = i_training_info.read_2d_eye_resp.VrefDAC0[l_rank][l_dbyte][l_bit].eye_min[l_eye_index];
                    const auto l_eye_max = i_training_info.read_2d_eye_resp.VrefDAC0[l_rank][l_dbyte][l_bit].eye_max[l_eye_index];

                    FAPI_MFG("%s %s RANK %u, DBYTE %u BIT %u EYE INDEX %u -- MIN: %u MAX: %u",
                             mss::c_str(i_target), "VrefDAC0", l_rank, l_dbyte, l_bit, l_eye_index, l_eye_min, l_eye_max);
                }
            }
        }
    }

    FAPI_MFG("%s %s_Center:", mss::c_str(i_target), "VrefDAC0");

    for (uint8_t l_dbyte = 0; l_dbyte < DBYTE_N_SIZE; ++l_dbyte)
    {
        for (uint8_t l_bit = 0; l_bit < BIT_N_SIZE; ++l_bit)
        {
            const auto l_vref_dac0_center = i_training_info.read_2d_eye_resp.VrefDAC0_Center[l_dbyte][l_bit];
            FAPI_MFG("%s %s DBYTE %u, BIT %u: %u", mss::c_str(i_target), "VrefDAC0_Center", l_dbyte, l_bit, l_vref_dac0_center);
        }
    }

    FAPI_MFG("%s %s_Center:", mss::c_str(i_target), "RxClkDly");

    for (uint8_t l_rank = 0; l_rank < TRAINING_RESPONSE_NUM_RANKS; ++l_rank)
    {
        for (uint8_t l_nibble = 0; l_nibble < NIBBLE_N_SIZE; ++l_nibble)
        {
            const auto l_rxclkdly_center = i_training_info.read_2d_eye_resp.RxClkDly_Center[l_rank][l_nibble];
            FAPI_MFG("%s %s RANK %u, NIBBLE %u: %u", mss::c_str(i_target), "RxClkDly_Center", l_rank, l_nibble, l_rxclkdly_center);
        }
    }
}

///
/// @brief Display train_2d_write_eye_msdg_t response struct
///
/// @param[in] i_target OCMB target
/// @param[in] i_training_info training info struct
///
void display_train_2d_write_eye(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                const user_2d_eye_response_2_msdg_t& i_training_info)
{
    FAPI_MFG("%s %s (EYE MIN/MAX):", mss::c_str(i_target), "VrefDQ");
    FAPI_MFG("%s Ranks for the 2D WR eye are in the PHY perspectives", mss::c_str(i_target));

    for (uint8_t l_rank = 0; l_rank < TRAINING_RESPONSE_NUM_RANKS; ++l_rank)
    {
        for (uint8_t l_dbyte = 0; l_dbyte < DBYTE_N_SIZE; ++l_dbyte)
        {
            for (uint8_t l_bit = 0; l_bit < BIT_N_SIZE; ++l_bit)
            {
                for (uint8_t l_eye_index = 0; l_eye_index < EYE_MIN_MAX_SIZE; ++l_eye_index)
                {
                    const auto l_eye_min = i_training_info.write_2d_eye_resp.VrefDQ[l_rank][l_dbyte][l_bit].eye_min[l_eye_index];
                    const auto l_eye_max = i_training_info.write_2d_eye_resp.VrefDQ[l_rank][l_dbyte][l_bit].eye_max[l_eye_index];

                    FAPI_MFG("%s %s RANK %u, DBYTE %u BIT %u EYE INDEX %u -- MIN: %u MAX: %u",
                             mss::c_str(i_target), "VrefDQ", l_rank, l_dbyte, l_bit, l_eye_index, l_eye_min, l_eye_max);
                }
            }
        }
    }

    FAPI_MFG("%s %s_Center:", mss::c_str(i_target), "VrefDQ");

    for (uint8_t l_rank = 0; l_rank < TRAINING_RESPONSE_NUM_RANKS; ++l_rank)
    {
        for (uint8_t l_nibble = 0; l_nibble < NIBBLE_N_SIZE; ++l_nibble)
        {
            const auto l_vrefdq_center = i_training_info.write_2d_eye_resp.VrefDQ_Center[l_rank][l_nibble];
            FAPI_MFG("%s %s RANK %u, NIBBLE %u: %u", mss::c_str(i_target), "VrefDQ_Center", l_rank, l_nibble, l_vrefdq_center);
        }
    }

    FAPI_MFG("%s %s_Center:", mss::c_str(i_target), "TxDqDly");

    for (uint8_t l_rank = 0; l_rank < TRAINING_RESPONSE_NUM_RANKS; ++l_rank)
    {
        for (uint8_t l_dbyte = 0; l_dbyte < DBYTE_N_SIZE; ++l_dbyte)
        {
            for (uint8_t l_bit = 0; l_bit < BIT_N_SIZE; ++l_bit)
            {
                const auto l_txdqdly_center = i_training_info.write_2d_eye_resp.TxDqDly_Center[l_rank][l_dbyte][l_bit];
                FAPI_MFG("%s %s RANK %u, DBYTE %u BIT %u: %u", mss::c_str(i_target), "TxDqDly_Center", l_rank, l_dbyte, l_bit,
                         l_txdqdly_center);
            }
        }
    }
}

///
/// @brief Displays all training information
/// @param[in] i_target the OCMB target
/// @param[in] i_training_info the training information to display
/// @return fapi2::FAPI2_RC_SUCCESS iff success
///
template <>
fapi2::ReturnCode display_user_2d_eye_info<user_2d_eye_response_1_msdg_t>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const user_2d_eye_response_1_msdg_t& i_training_info)
{
    FAPI_INF("%s displaying user 2d eye response 1 data version %u", mss::c_str(i_target), i_training_info.version_number)
    display_train_2d_read_eye(i_target, i_training_info);
    FAPI_TRY(display_normal_info(i_target, i_training_info));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Displays all training information
/// @param[in] i_target the OCMB target
/// @param[in] i_training_info the training information to display
/// @return fapi2::FAPI2_RC_SUCCESS iff success
///
template <>
fapi2::ReturnCode display_user_2d_eye_info<user_2d_eye_response_2_msdg_t>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const user_2d_eye_response_2_msdg_t& i_training_info)
{
    FAPI_INF("%s displaying user 2d eye response 2 data version %u", mss::c_str(i_target), i_training_info.version_number)
    display_train_2d_write_eye(i_target, i_training_info);
    FAPI_TRY(display_normal_info(i_target, i_training_info));

fapi_try_exit:
    return fapi2::current_err;
}

} // ns train
} // ns exp
} // ns mss
