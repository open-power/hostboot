/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_power_cleanup.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file p9c_mss_power_cleanup.H
/// @brief Procedure to deconfig centaurs and mbas
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Steve Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

#ifndef mss_power_cleanup_H_
#define mss_power_cleanup_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

typedef fapi2::ReturnCode (*p9c_mss_power_cleanup_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&
        i_target_centaur,
        const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba0,
        const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba1);

typedef fapi2::ReturnCode (*p9c_mss_power_cleanup_mba_FP_t)( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba);

extern "C" {
    ///
    /// @brief mss_power_cleanup(): Clean up a centaur and also MBAs, also calls the mba cleanup under the covers
    /// @param[in] i_target_centaur: the centaur
    /// @param[in] i_target_mba0: the mba0
    /// @param[in] i_target_mba1: the mba1
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode p9c_mss_power_cleanup(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target_centaur,
                                            const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba0,
                                            const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba1);
    ///
    /// @brief mss_power_cleanup_mba(): Clean up a centaur and also MBAs
    /// @param[in] i_target_mba0: the mba0
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_power_cleanup_mba(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba);  // clean up an mba

    ///
    /// @brief mss_power_cleanup_centaur(): Clean up a centaur
    /// @param[in] i_target_centaur: the centaur
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_power_cleanup_centaur(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target_centaur);

    ///
    /// @brief mss_power_cleanup_part1(): Clean up an MBA
    /// @param[in] i_target_centaur: the centaur
    /// @param[in] i_target_mba: the mba
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_power_cleanup_mba_part1(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target_centaur,
            const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba);

    ///
    /// @brief mss_power_cleanup_mba_fence(): enable_partial_good_dc memn_fence_dc mems_fence_dc
    /// @param[in] i_target_centaur: the centaur
    /// @param[in] i_target_mba0: the mba0
    /// @param[in] i_target_mba1: the mba1
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_power_cleanup_mba_fence(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target_centaur,
            const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba0,
            const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba1 );

} // extern "C"

#endif // mss_power_cleanup_H

