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
/// @brief Displays all training information
/// @param[in] i_target the OCMB target
/// @param[in] i_training_info the training information to display
/// @return returns FAPI2_RC_SUCCESS iff the procedure executes successfully
/// @note This is a place holder to help avoid merge conflicts
///
inline fapi2::ReturnCode display_info(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                      const user_response_msdg_t& i_training_info)
{
    return fapi2::FAPI2_RC_SUCCESS;
}


} // ns train
} // ns exp
} // ns mss
#endif
