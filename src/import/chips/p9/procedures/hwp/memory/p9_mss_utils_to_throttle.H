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
/// @brief Sets throttles
/// TMGT will call this procedure to set the N address operations (commands)
/// allowed within a window of M DRAM clocks given the minimum dram data bus utilization.
///

// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Andre A. Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef __P9_MSS_UTILS_TO_THROTTLE__
#define __P9_MSS_UTILS_TO_THROTTLE__

#include <fapi2.H>
#include <vector>

typedef fapi2::ReturnCode (*p9_mss_utils_to_throttle_FP_t) (const
        std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCS> >&);

extern "C"
{

    ///
    /// @brief Sets number commands allowed within a given port databus utilization.
    /// @param[in] i_targets vector of MCS to set throttle attributes on
    /// @return FAPI2_RC_SUCCESS iff ok
    /// @note ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT will be set to worst case of all slots passed in
    /// @note output ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT, ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_PORT, and ATTR_MSS_PORT_MAXPOWER
    ///
    fapi2::ReturnCode p9_mss_utils_to_throttle( const std::vector <fapi2::Target<fapi2::TARGET_TYPE_MCS> >& i_targets );
}

#endif
