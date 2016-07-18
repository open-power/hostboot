/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/power_thermal/throttle.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @brief throttle API
///

// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_THROTTLE_
#define _MSS_THROTTLE_


namespace mss
{

enum throttle_const : size_t
{
    // Dram data bus utilization is 4X the address bus utilization
    DRAM_BUS_UTILS = 4,
    PERCENT_CONVERSION = 100,
};

///
/// @brief Calculate N (address operations) allowed within a window of M DRAM clocks
/// @param[in] i_databus_util databus utilization percentage (e.g. 5% = 5)
/// @param[in] i_num_dram_clocks window of M DRAM clocks
/// @return number of throttled commands allowed
/// @note Uses N/M Throttling.
/// Equation:  (DRAM data bus utilization Percent / 100 ) = ((N * 4) / M )
/// Dram data bus utilization is 4X the address bus utilization
///
inline uint32_t throttled_cmds(const uint8_t i_databus_util, const uint32_t i_num_dram_clocks)
{
    constexpr uint64_t l_divisor = DRAM_BUS_UTILS * PERCENT_CONVERSION;
    const uint64_t l_dividend = i_databus_util * i_num_dram_clocks;
    const uint64_t l_quotient = l_dividend / l_divisor;
    const uint64_t l_remainder = l_dividend % l_divisor;

    return l_quotient + (l_remainder == 0  ? 0 : 1);
}

}// mss

#endif
