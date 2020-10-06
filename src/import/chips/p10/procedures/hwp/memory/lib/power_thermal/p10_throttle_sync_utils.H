/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/power_thermal/p10_throttle_sync_utils.H $ */
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
/// @file p10_throttle_sync_utils.H
/// @brief throttle_sync function definitions for P10
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _P10_MSS_THROTTLE_SYNC_UTILS_H_
#define _P10_MSS_THROTTLE_SYNC_UTILS_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{

///
/// @brief Configure sync operations on the ocmb's for a given MI
/// @param[in] i_target the target to be programmed
/// @param[in] i_enable ON if enabled, OFF to disable
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode configure_ocmb_sync_operations(const fapi2::Target<fapi2::TARGET_TYPE_MI>& i_target,
        const mss::states i_enable);

///
/// @brief Configure sync operations on the MI
/// @param[in] i_target the target to be programmed
/// @param[in] i_enable ON if enabled, OFF to disable
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode configure_sync_operations(const fapi2::Target<fapi2::TARGET_TYPE_MI>& i_target,
        const mss::states i_enable);

///
/// @brief Setting up sync mode in the MI
/// @param[in] i_target the target to be programmed
/// @param[in] i_primary true if this is the primary MI to program, otherwise false
/// @return FAPI2_RC_SUCCESS iff okay
/// @note Writes SCOMFIR_MCSYNC reg to set the input MI with configuration for primary vs secondary MI
///
fapi2::ReturnCode setup_sync(const fapi2::Target<fapi2::TARGET_TYPE_MI>& i_target, const bool i_primary);

///
/// @brief Programming the MI to issue the sync
/// @param[in] i_target the target to be programmed - the primary MI
/// @return FAPI2_RC_SUCCESS iff okay
/// @note Writes SCOMFIR_MCSYNC reg to issue the sync commands
///
fapi2::ReturnCode issue_sync(const fapi2::Target<fapi2::TARGET_TYPE_MI>& i_target);

}// mss

#endif
