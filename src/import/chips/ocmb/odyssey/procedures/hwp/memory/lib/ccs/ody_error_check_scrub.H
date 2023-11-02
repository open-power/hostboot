/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ccs/ody_error_check_scrub.H $ */
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

///
/// @file ody_error_check_scrub.H
/// @brief Odyssey error check scrub functionality
///
// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#ifndef _ODY_ERROR_CHECK_SCRUB_H_
#define _ODY_ERROR_CHECK_SCRUB_H_

#include <fapi2.H>

#include <lib/dimm/ody_rank.H>
#include <generic/memory/lib/ccs/ccs_traits.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <lib/ccs/ody_ccs_traits.H>

namespace mss
{
namespace ccs
{
namespace ody
{

const uint8_t MR14_ECC_CONFIG = 14;
const uint8_t MR15_ECC_THRESHOLD = 15;
const uint64_t MR16_ERROR_COUNT = 16;
const uint64_t MR17_ERROR_COUNT = 17;
const uint64_t MR18_ERROR_COUNT = 18;
const uint64_t MR19_ERROR_COUNT = 19;
const uint64_t MR20_ERROR_COUNT = 20;
const uint64_t NA_DRAM_INDEX = 0;
constexpr mss::states NTTM_MODE_OFF = mss::states::OFF;
constexpr mss::states NESTED_LOOP_ON = mss::states::ON;


///
/// @brief Setup the CCS instructions for performing ECS test
/// @param[in] i_rank_info Rank info of the target
/// @param[in] i_srank chipid/srank that needs to be run
/// @param[in,out] io_program object of program class that has the vector of CCS instructions
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode  setup_arrays_with_ecs_instructions(const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
        const uint8_t i_srank,
        mss::ccs::program<mss::mc_type::ODYSSEY>& io_program );

///
/// @brief Setup the CCS instructions for performing ECS test
/// @param[in] i_rank_info Rank info of the target
/// @param[in] i_srank the srank that needs to be executed
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode setup_to_execute_ecs(const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
                                       const uint8_t i_srank);


///
/// @brief Resets the error counters and initialize
/// @param[in] i_rank_info Rank info of the target
/// @param[in] i_srank the srank that needs to be executed
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode reset_error_counters(const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
                                       const uint8_t i_srank);



///
/// @brief Disables the ecc mode
/// @param[in] i_target OCMB target
/// @param[out] o_ecc_reg buffer to return the original value of ecc reg
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode disable_ecc_mode(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                   fapi2::buffer<uint64_t>& o_ecc_reg);


///
/// @brief Disables the periodic calibration
/// @param[in] i_target OCMB target
/// @param[out] o_periodic_calib buffer to return the original value of FARB9Q reg
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode disable_periodic_cal(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                       fapi2::buffer<uint64_t>& o_periodic_calib);


///
/// @brief Enables the needed modes after running ecs test
/// @param[in] i_target OCMB target
/// @param[in] i_ecc_reg value to set the ecc reg
/// @param[in] i_periodic_calib value to set the FARB9Q_REG
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode enable_periodic_cal_ecc_modes(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const fapi2::buffer<uint64_t>& i_ecc_reg,
        const fapi2::buffer<uint64_t>& i_periodic_calib);

///
/// @brief Initialize the memory on a specific srank with a specific data pattern
/// @param[in] i_target OCMB Chip
/// @param[in] i_srank the srank to initialize
/// @param[in] i_pattern mcbist pattern
/// @return FAPI2_RC_SUCCESS iff successful
///

fapi2::ReturnCode memory_init_via_memdiags(const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
        const uint8_t i_srank,
        const uint64_t i_pattern);


///
/// @brief Initialize the memory
/// @param[in] i_target OCMB Chip
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode memory_init_via_memdiags(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Reads the MR registers
/// @param[in] i_rank_info rank info
/// @param[in] i_mrs the specific MRS
/// @param[out] o_data array of mr values per dram
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode read_mr_error_regs(const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
                                     const uint64_t i_mrs,
                                     uint8_t (&o_data)[mss::ody::ODY_NUM_DRAM_X4]);

///
/// @brief Run the ecs test
/// @param[in] i_rank_info rank info
/// @param[in] i_pattern data pattern to test
/// @param[out] o_mr20_arr array to keep the mr20 data
/// @param[out] o_mr16_19_arr array to keep the mr16-19 data
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode run_ecs_helper(const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
                                 const uint64_t i_pattern,
                                 uint8_t (&o_mr20_arr)[mss::ody::MAX_SRANKS][mss::ody::ODY_NUM_DRAM_X4],
                                 uint32_t (&o_mr16_19_arr)[mss::ody::MAX_SRANKS][mss::ody::ODY_NUM_DRAM_X4]);


///
/// @brief Run the ecs test
/// @param[in] i_vec_ranks vector of ranks
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode run_ecs(const std::vector<mss::rank::info<mss::mc_type::ODYSSEY>>& i_vec_ranks);

} // ns ody
} // ns ccs
} // ns mss
#endif
