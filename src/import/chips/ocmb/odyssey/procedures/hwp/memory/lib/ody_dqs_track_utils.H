/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ody_dqs_track_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
// *HWP Level: 2
// *HWP Consumed by: Memory Lab

#ifndef _ODY_DQS_TRACK_UTILS_H_
#define _ODY_DQS_TRACK_UTILS_H_

#include <fapi2.H>
#include <lib/dimm/ody_rank.H>
#include <lib/ccs/ody_ccs.H>

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
/// @brief Ody DQS track procedure
/// @param [in] i_target OCMB target
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode ody_dqs_track(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);


} // namespace ody
} // namespace mss
#endif