/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/ccs/exp_bad_dq_bitmap_funcs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/// @file exp_bad_dq_bitmap_funcs.H
/// @brief Functions that access the Bad DQ Bitmap.
///
/// *HWP HWP Owner: Matt Hickman <Matthew.Hickman@ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
/// EKB-Mirror-To: hostboot
///

#ifndef __EXP_BAD_DQ_BITMAP_FUNCS__
#define __EXP_BAD_DQ_BITMAP_FUNCS__

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{
namespace exp
{
///
/// @brief Row Repair Utility function that gets the Bad DQ Bitmap.
/// @param[in] i_rank Rank info to get bitmap
/// @param[out] o_data Reference to data where Bad DQ bitmap is copied to
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode get_bad_dq_bitmap( const mss::rank::info<>& i_rank,
                                     uint8_t o_data[BAD_DQ_BYTE_COUNT]);

///
/// @brief Row Repair Utility function that sets the Bad DQ Bitmap.
/// @param[in] i_rank Rank info to get bitmap
/// @param[in] i_data Reference to data where Bad DQ bitmap is copied to
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode set_bad_dq_bitmap( const mss::rank::info<>& i_rank,
                                     const uint8_t i_data[BAD_DQ_BYTE_COUNT]);
} // namespace exp
} // namespace mss
#endif
