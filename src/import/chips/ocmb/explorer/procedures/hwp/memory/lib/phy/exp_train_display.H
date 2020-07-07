/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/phy/exp_train_display.H $ */
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
/// @file exp_train_display.H
/// @brief Procedures used to display the training response information
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _EXP_TRAIN_DISPLAY_H_
#define _EXP_TRAIN_DISPLAY_H_

#include <fapi2.H>
#include <lib/shared/exp_consts.H>
#include <lib/dimm/exp_rank.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/index.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <exp_data_structs.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>


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
                          const uint16_t i_data);

///
/// @brief Displays RCW information for a single 8-bit RCW
/// @param[in] i_target the OCMB target
/// @param[in] i_dimm the dimm number associated w/ the RCW
/// @param[in] i_func_space the function space for the RCW
/// @param[in] i_rcw_number RCW number
/// @param[in] i_data data associated with the RCW
///
inline void display_rcw_8bit(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                             const uint64_t i_dimm,
                             const uint64_t i_func_space,
                             const uint64_t i_rcw_number,
                             const uint8_t i_data)
{
    // Offset by 1 since index 0 is really F*RC1X not F*RC0X
    const uint64_t l_rcw_print_number = i_rcw_number - exp_struct_sizes::RCW_8BIT_CUTOFF + 1;
    FAPI_MFG("%s DIMM%u F%uRC%xX: 0x%02x", mss::c_str(i_target), i_dimm, i_func_space, l_rcw_print_number, i_data);
}

///
/// @brief Displays RCW information for a single 4-bit RCW
/// @param[in] i_target the OCMB target
/// @param[in] i_dimm the dimm number associated w/ the RCW
/// @param[in] i_func_space the function space for the RCW
/// @param[in] i_rcw_number RCW number
/// @param[in] i_data data associated with the RCW
///
inline void display_rcw_4bit(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                             const uint64_t i_dimm,
                             const uint64_t i_func_space,
                             const uint64_t i_rcw_number,
                             const uint8_t i_data)
{
    FAPI_MFG("%s DIMM%u F%uRC%02x: 0x%02x", mss::c_str(i_target), i_dimm, i_func_space, i_rcw_number, i_data);
}


///
/// @brief Displays lane failure information after training
/// @tparam T response struct
/// @param[in] i_target the OCMB target
/// @param[in] i_training_info the training information to display
///
template <typename T>
void display_lane_info(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                       const T& i_training_info)
{
    for(uint8_t l_lane = 0; l_lane < exp_struct_sizes::TRAINING_RESPONSE_NUM_LANES; ++l_lane)
    {
        display_lane_results( i_target, l_lane, i_training_info.err_resp.Failure_Lane[l_lane]);
    }
}

///
/// @brief Displays MR information
/// @tparam T response struct
/// @param[in] i_target the OCMB target
/// @param[in] i_training_info the training information to display
///
template <typename T>
fapi2::ReturnCode display_mrs_info(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                   const T& i_training_info)
{
    // Loop through all ports
    for (const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        // Rank info object for
        std::vector<mss::rank::info<>> l_rank_info_vect;
        uint8_t l_dram_width[mss::exp::sizes::MAX_DIMM_PER_PORT] = {};
        FAPI_TRY(mss::rank::ranks_on_port<>(l_port, l_rank_info_vect));
        FAPI_TRY(mss::attr::get_dram_width(l_port, l_dram_width));

        // Loops through all of the ranks
        for (const auto& l_rank_info : l_rank_info_vect)
        {
            const uint8_t l_phy_rank = l_rank_info.get_phy_rank();
            const uint8_t l_port_rank = l_rank_info.get_port_rank();
            const uint8_t l_dram_width_for_dimm = l_dram_width[mss::index(l_rank_info.get_dimm_target())];
            // MR0->5 are easy, just display the value
            FAPI_MFG("%s rank%u MR%u 0x%04x", mss::c_str(i_target), l_port_rank, 0, i_training_info.mrs_resp.MR0);
            FAPI_MFG("%s rank%u MR%u 0x%04x", mss::c_str(i_target), l_port_rank, 1, i_training_info.mrs_resp.MR1[l_phy_rank]);
            FAPI_MFG("%s rank%u MR%u 0x%04x", mss::c_str(i_target), l_port_rank, 2, i_training_info.mrs_resp.MR2[l_phy_rank]);
            FAPI_MFG("%s rank%u MR%u 0x%04x", mss::c_str(i_target), l_port_rank, 3, i_training_info.mrs_resp.MR3);
            FAPI_MFG("%s rank%u MR%u 0x%04x", mss::c_str(i_target), l_port_rank, 4, i_training_info.mrs_resp.MR4);
            FAPI_MFG("%s rank%u MR%u 0x%04x", mss::c_str(i_target), l_port_rank, 5, i_training_info.mrs_resp.MR5[l_phy_rank]);

            // The number of the DRAM's and the position to access each DRAM changes based upon x4 vs x8
            const auto l_num_dram = l_dram_width_for_dimm == fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X4 ?
                                    mss::exp::generic_consts::EXP_NUM_DRAM_X4 : mss::exp::generic_consts::EXP_NUM_DRAM_X8;
            // The correction factor is used to determine the correct DRAM position, as x8 DRAM's take up two entries
            const auto l_correction_factor = l_dram_width_for_dimm == fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X4 ? 1 : 2;

            for (uint64_t l_dram = 0; l_dram < l_num_dram; ++l_dram)
            {
                const auto l_dram_pos = l_correction_factor * l_dram;
                FAPI_MFG("%s rank%u MR6 dram%u 0x%04x", mss::c_str(i_target), l_port_rank, l_dram,
                         i_training_info.mrs_resp.MR6[l_phy_rank][l_dram_pos]);
            }
        }
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Displays all RCW information
/// @tparam T response struct
/// @param[in] i_target the OCMB target
/// @param[in] i_training_info the training information to display
///
template <typename T>
void display_rcw_info(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                      const T& i_training_info)
{
    constexpr uint64_t FUNC_SPACE0 = 0;
    constexpr uint64_t FUNC_SPACE1 = 1;

    // Only display the DIMM's that exist
    const auto& l_dimms = mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target);

    // Display DIMM0
    if(l_dimms.size() >= 1)
    {
        // Display all of function space 0
        // Display all 4-bit numbers
        for(uint8_t l_rcw = 0; l_rcw < exp_struct_sizes::RCW_8BIT_CUTOFF; ++l_rcw)
        {
            display_rcw_4bit( i_target, 0, FUNC_SPACE0, l_rcw, i_training_info.rc_resp.F0RC_D0[l_rcw]);
        }

        // Display all 8-bit numbers
        for(uint8_t l_rcw = exp_struct_sizes::RCW_8BIT_CUTOFF; l_rcw < exp_struct_sizes::TRAINING_RESPONSE_NUM_RC; ++l_rcw)
        {
            display_rcw_8bit( i_target, 0, FUNC_SPACE0, l_rcw, i_training_info.rc_resp.F0RC_D0[l_rcw]);
        }

        // Display all of function space 1
        // Display all 4-bit numbers
        for(uint8_t l_rcw = 0; l_rcw < exp_struct_sizes::RCW_8BIT_CUTOFF; ++l_rcw)
        {
            display_rcw_4bit( i_target, 0, FUNC_SPACE1, l_rcw, i_training_info.rc_resp.F1RC_D0[l_rcw]);
        }

        // Display all 8-bit numbers
        for(uint8_t l_rcw = exp_struct_sizes::RCW_8BIT_CUTOFF; l_rcw < exp_struct_sizes::TRAINING_RESPONSE_NUM_RC; ++l_rcw)
        {
            display_rcw_8bit( i_target, 0, FUNC_SPACE1, l_rcw, i_training_info.rc_resp.F1RC_D0[l_rcw]);
        }
    }

    // Display DIMM1
    if(l_dimms.size() == 2)
    {
        // Display all of function space 0
        // Display all 4-bit numbers
        for(uint8_t l_rcw = 0; l_rcw < exp_struct_sizes::RCW_8BIT_CUTOFF; ++l_rcw)
        {
            display_rcw_4bit( i_target, 1, FUNC_SPACE0, l_rcw, i_training_info.rc_resp.F0RC_D1[l_rcw]);
        }

        // Display all 8-bit numbers
        for(uint8_t l_rcw = exp_struct_sizes::RCW_8BIT_CUTOFF; l_rcw < exp_struct_sizes::TRAINING_RESPONSE_NUM_RC; ++l_rcw)
        {
            display_rcw_8bit( i_target, 1, FUNC_SPACE0, l_rcw, i_training_info.rc_resp.F0RC_D1[l_rcw]);
        }

        // Display all of function space 1
        // Display all 4-bit numbers
        for(uint8_t l_rcw = 0; l_rcw < exp_struct_sizes::RCW_8BIT_CUTOFF; ++l_rcw)
        {
            display_rcw_4bit( i_target, 1, FUNC_SPACE1, l_rcw, i_training_info.rc_resp.F1RC_D1[l_rcw]);
        }

        // Display all 8-bit numbers
        for(uint8_t l_rcw = exp_struct_sizes::RCW_8BIT_CUTOFF; l_rcw < exp_struct_sizes::TRAINING_RESPONSE_NUM_RC; ++l_rcw)
        {
            display_rcw_8bit( i_target, 1, FUNC_SPACE1, l_rcw, i_training_info.rc_resp.F1RC_D1[l_rcw]);
        }
    }
}

///
/// @brief Displays command to command response timing
/// @tparam T response struct
/// @param[in] i_target the OCMB target
/// @param[in] i_training_info the training information to display
/// @return returns FAPI2_RC_SUCCESS iff the procedure executes successfully
///
template <typename T>
inline fapi2::ReturnCode display_response_timing(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const T& i_training_info)
{
    // Loop through all ports
    for (const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        // Rank info object for
        std::vector<mss::rank::info<>> l_rank_info_vect;
        FAPI_TRY(mss::rank::ranks_on_port<>(l_port, l_rank_info_vect));

        // DFIMRL_DDRCLK_trained training result
        FAPI_MFG("%s DFIMRL_DDRCLK_trained: %u", mss::c_str(i_target), i_training_info.tm_resp.DFIMRL_DDRCLK_trained);

        // RD to RD
        FAPI_MFG("%s RD-to-RD      :  0  1  2  3", mss::c_str(i_target));

        for(const auto& l_rank : l_rank_info_vect)
        {
            const auto l_phy_rank = l_rank.get_phy_rank();
            const auto l_port_rank = l_rank.get_port_rank();
            FAPI_MFG("%s RD-to-RD rank%u: %2i %2i %2i %2i", mss::c_str(i_target), l_port_rank,
                     i_training_info.tm_resp.CDD_RR[l_phy_rank][0], i_training_info.tm_resp.CDD_RR[l_phy_rank][1],
                     i_training_info.tm_resp.CDD_RR[l_phy_rank][2], i_training_info.tm_resp.CDD_RR[l_phy_rank][3]);
        }

        // WR to WR
        FAPI_MFG("%s WR-to-WR      :  0  1  2  3", mss::c_str(i_target));

        for(const auto& l_rank : l_rank_info_vect)
        {
            const auto l_phy_rank = l_rank.get_phy_rank();
            const auto l_port_rank = l_rank.get_port_rank();
            FAPI_MFG("%s WR-to-WR rank%u: %2i %2i %2i %2i", mss::c_str(i_target), l_port_rank,
                     i_training_info.tm_resp.CDD_WW[l_phy_rank][0], i_training_info.tm_resp.CDD_WW[l_phy_rank][1],
                     i_training_info.tm_resp.CDD_WW[l_phy_rank][2], i_training_info.tm_resp.CDD_WW[l_phy_rank][3]);
        }

        // WR to RD
        FAPI_MFG("%s WR-to-RD      :  0  1  2  3", mss::c_str(i_target));

        for(const auto& l_rank : l_rank_info_vect)
        {
            const auto l_phy_rank = l_rank.get_phy_rank();
            const auto l_port_rank = l_rank.get_port_rank();
            FAPI_MFG("%s WR-to-RD rank%u: %2i %2i %2i %2i", mss::c_str(i_target), l_port_rank,
                     i_training_info.tm_resp.CDD_WR[l_phy_rank][0], i_training_info.tm_resp.CDD_WR[l_phy_rank][1],
                     i_training_info.tm_resp.CDD_WR[l_phy_rank][2], i_training_info.tm_resp.CDD_WR[l_phy_rank][3]);
        }

        // RD to WR
        FAPI_MFG("%s RD-to-WR      :  0  1  2  3", mss::c_str(i_target));

        for(const auto& l_rank : l_rank_info_vect)
        {
            const auto l_phy_rank = l_rank.get_phy_rank();
            const auto l_port_rank = l_rank.get_port_rank();
            FAPI_MFG("%s RD-to-WR rank%u: %2i %2i %2i %2i", mss::c_str(i_target), l_port_rank,
                     i_training_info.tm_resp.CDD_RW[l_phy_rank][0], i_training_info.tm_resp.CDD_RW[l_phy_rank][1],
                     i_training_info.tm_resp.CDD_RW[l_phy_rank][2], i_training_info.tm_resp.CDD_RW[l_phy_rank][3]);
        }
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Display train_2d_read_eye_msdg_t response struct
///
/// @param[in] i_target OCMB target
/// @param[in] i_training_info training info struct
///
void display_train_2d_read_eye(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                               const user_2d_eye_response_1_msdg_t& i_training_info);

///
/// @brief Display train_2d_write_eye_msdg_t response struct
///
/// @param[in] i_target OCMB target
/// @param[in] i_training_info training info struct
///
void display_train_2d_write_eye(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                const user_2d_eye_response_2_msdg_t& i_training_info);

///
/// @brief Displays all training information common to all response structs
/// @tparam T response struct
/// @param[in] i_target the OCMB target
/// @param[in] i_training_info the training information to display
/// @return returns FAPI2_RC_SUCCESS iff the procedure executes successfully
///
template <typename T>
inline fapi2::ReturnCode display_normal_info(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const T& i_training_info)
{
    // Target trace & FAPI_INF moved to the caller(s) such that we can call this from the eye capture functions
    display_rcw_info(i_target, i_training_info);
    FAPI_TRY(display_mrs_info(i_target, i_training_info));
    display_lane_info(i_target, i_training_info);
    FAPI_TRY(display_response_timing(i_target, i_training_info));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Displays all training information
/// @tparam T response struct
/// @param[in] i_target the OCMB target
/// @param[in] i_training_info the training information to display
/// @return fapi2::FAPI2_RC_SUCCESS iff success
///
template <typename T>
fapi2::ReturnCode display_user_2d_eye_info(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const T& i_training_info);

///
/// @brief Displays all training information for eye response 1
/// @param[in] i_target the OCMB target
/// @param[in] i_training_info the training information to display
/// @return fapi2::FAPI2_RC_SUCCESS iff success
///
template <>
fapi2::ReturnCode display_user_2d_eye_info<user_2d_eye_response_1_msdg_t>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const user_2d_eye_response_1_msdg_t& i_training_info);

///
/// @brief Displays all training information for eye response 2
/// @param[in] i_target the OCMB target
/// @param[in] i_training_info the training information to display
/// @return fapi2::FAPI2_RC_SUCCESS iff success
///
template <>
fapi2::ReturnCode display_user_2d_eye_info<user_2d_eye_response_2_msdg_t>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const user_2d_eye_response_2_msdg_t& i_training_info);

} // ns train
} // ns exp
} // ns mss
#endif
