/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/dimm/ddr4/latch_wr_vref_explorer.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2022                        */
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
/// @file latch_wr_vref_explorer.C
/// @brief Explorer specialized latch WR VREF functions
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <generic/memory/lib/utils/dimm/mss_ddr4_timing.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/dimm/ddr4/latch_wr_vref.H>

namespace mss
{
namespace ddr4
{

///
/// @brief VREF DQ Enter time *in clocks*
/// @tparam T TargetType
/// @return VREF DQ Enter time *in clocks*
/// @note Explorer specialization
///
template<fapi2::TargetType T>
class tvrefdqe<mss::mc_type::EXPLORER, T>
{
    public:
        static uint64_t get(const fapi2::Target<T>& i_target)
        {
            // WR VREF train delay is 150 ns / SMALLEST_CLOCK
            // Our smallest clock is 0.625 at 3200
            return 240;
        }
};

} // ddr4

} // mss
