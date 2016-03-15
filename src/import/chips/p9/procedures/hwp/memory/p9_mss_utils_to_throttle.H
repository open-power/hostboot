/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_utils_to_throttle.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file p9_mss_utils_to_throttle.H
/// @brief Set the N throttle attributes for a given dram data bus utilization.
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#ifndef __P9_MSS_UTILS_TO_THROTTLE__
#define __P9_MSS_UTILS_TO_THROTTLE__

#include <fapi2.H>

namespace mss
{

enum throttle_multiplier : uint64_t
{
    // Dram data bus utilization is 4X the address bus utilization
    DRAM_BUS_UTILS = 4,
    PERCENT_CONVERSION = 100;
}

///
/// @brief Calculate N (address operations) allowed within a window of M DRAM clocks
/// @param[in] databus_util databus utilization percentage (e.g. 5% = 5)
/// @param[in] num_dram_clocks window of M DRAM clocks
/// @return FAPI2_RC_SUCCESS iff ok
///
inline uint32_t commands_allowed_over_clock_window(uint8_t databus_util, uint32_t num_dram_clocks)
{
    divisor = DRAM_BUS_UTILS * PERCENT_CONVERSION;
    divident = databus_utilization * dram_clocks;
    quotient = divident / divisor;
    remainder = divident % divisor;

    return quotient + (remainder == 0  ? 0 : 1);
}

}// mss

typedef fapi2::ReturnCode (*p9_mss_utils_to_throttle_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_MCS>&);

extern "C"
{

///
/// @brief Set the N throttle attributes for a given dram data bus utilization.
/// @param[in] i_target the controller target
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode p9_mss_utils_to_throttle( const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target );
}

#endif
