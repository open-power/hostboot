/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_util_to_throttle.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
/// @file p9c_mss_util_to_throttle.H
/// @brief determine the minimum N throttle settings for N/M throttling for a given dram data bus util value
///
/// *HWP HWP Owner: Andre Marin <aamaring@us.ibm.com>
/// *HWP HWP Backup: Michael Pardeik <pardeik@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

#ifndef MSS_UTIL_TO_THROTTLE_H_
#define MSS_UTIL_TO_THROTTLE_H_

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

typedef fapi2::ReturnCode (*p9c_mss_util_to_throttle_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_MBA>&);

extern "C"
{

    ///
    /// @brief This function will determine N/M throttles and channel pair power for a given dram data bus util value from attribute ATTR_CEN_MSS_DATABUS_UTIL_PER_MBA
    /// @param[in] i_target_mba:  MBA Target
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode p9c_mss_util_to_throttle(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba);

    ///
    /// @brief This function will determine the safemode dram utilization
    ///    for the MRW safemode throttle values
    /// @param[in]  i_target_mba:  MBA Target
    /// @param[out]  o_safemode_util:  safemode utilization value from MRW attributes
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode p9c_mss_util_to_throttle_safemode(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
            uint8_t& o_safemode_util);

} // extern "C"

#endif // MSS_UTIL_TO_THROTTLE_H_
