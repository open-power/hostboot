/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/count_dimm.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
/// @file count_dimm.H
/// @brief Count the DIMM attached to a target
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_COUNT_DIMM_H_
#define _MSS_COUNT_DIMM_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/c_str.H>

namespace mss
{
///
/// @brief Return the count of the number of DIMM attached to a target
/// @tparam T the fapi2::TargetType
/// @param[in] i_target a target
/// @return size_t the count of DIMM attached
///
template< fapi2::TargetType T >
inline size_t count_dimm(const fapi2::Target<T>& i_target)
{
    // Sanity check that we have DIMM. Be sure to ask the platform, not eff_config, as
    // in the case of an over-ride and there are no DIMM in the config, we want to let
    // people know. Which is how we found we needed to add this code ...
    size_t l_dimm_count = find_targets<fapi2::TARGET_TYPE_DIMM>(i_target).size();
    return l_dimm_count;
}

///
/// @brief Return the count of the number of DIMM attached to a target - DIMM speicalization
/// @param[in] i_target a target
/// @return size_t the count of DIMM attached
///
template< >
inline size_t count_dimm(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    // You can only ever have one DIMM on a DIMM target
    return 1;
}

///
/// @brief Return the count of the number of DIMM attached to a vector of targets
/// @tparam T the fapi2::TargetType
/// @param[in] i_target a vector of targets
/// @return size_t the count of DIMM attached
///
template< fapi2::TargetType T >
inline size_t count_dimm(const std::vector<fapi2::Target<T>>& i_targets)
{
    size_t l_dimm_count = 0;

    for (const auto& l_target : i_targets)
    {
        l_dimm_count += count_dimm(l_target);
    }

    return l_dimm_count;
}

}
#endif
