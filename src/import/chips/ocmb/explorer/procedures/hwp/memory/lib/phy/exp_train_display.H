/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/phy/exp_train_display.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/index.H>
#include <generic/memory/lib/utils/c_str.H>
#include <exp_data_structs.H>

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
/// @brief Displays lane failure information after training
/// @param[in] i_target the OCMB target
/// @param[in] i_training_info the training information to display
///
void display_lane_info(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                       const user_response_msdg_t& i_training_info);

///
/// @brief Displays MRS information
/// @param[in] i_target the OCMB target
/// @param[in] i_training_info the training information to display
/// @return returns FAPI2_RC_SUCCESS iff the procedure executes successfully
///
fapi2::ReturnCode display_mrs_info(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                   const user_response_msdg_t& i_training_info);

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
    const uint64_t l_rcw_print_number = i_rcw_number - exp_struct_sizes::RCW_8BIT_CUTOFF;
    FAPI_DBG("%s DIMM%u F%uRC%xX: 0x%02x", mss::c_str(i_target), i_dimm, i_func_space, l_rcw_print_number, i_data);
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
    FAPI_DBG("%s DIMM%u F%uRC%02x: 0x%02x", mss::c_str(i_target), i_dimm, i_func_space, i_rcw_number, i_data);
}

///
/// @brief Displays all RCW information
/// @param[in] i_target the OCMB target
/// @param[in] i_training_info the training information to display
///
void display_rcw_info(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                      const user_response_msdg_t& i_training_info);

///
/// @brief Displays command to command response timing
/// @param[in] i_target the OCMB target
/// @param[in] i_training_info the training information to display
/// @return returns FAPI2_RC_SUCCESS iff the procedure executes successfully
///
fapi2::ReturnCode display_response_timing(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const user_response_msdg_t& i_training_info);

///
/// @brief Displays all training information
/// @param[in] i_target the OCMB target
/// @param[in] i_training_info the training information to display
/// @return returns FAPI2_RC_SUCCESS iff the procedure executes successfully
///
fapi2::ReturnCode display_info(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                               const user_response_msdg_t& i_training_info);

} // ns train
} // ns exp
} // ns mss
#endif
