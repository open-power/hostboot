/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_dimmBadDqBitmapAccessHwp.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file p9c_dimmBadDqBitmapAccessHwp.H
/// @brief FW Team HWP that accesses the Bad DQ Bitmap.
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB
////
//
#ifndef DIMMBADDQBITMAPACCESSHWP_H_
#define DIMMBADDQBITMAPACCESSHWP_H_

#include <fapi2.H>
#include <dimmConsts.H>

typedef fapi2::ReturnCode (*p9c_dimmBadDqBitmapAccessHwp_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_MBA>&,
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&,
        const uint8_t (&)[MAX_RANKS_PER_DIMM][DIMM_DQ_RANK_BITMAP_SIZE],
        const bool);

extern "C"
{

    ///
    /// @brief FW Team HWP that accesses the Bad DQ Bitmap.
    ///        It accesses the raw data from DIMM SPD and does
    ///        any necessary processing to turn it into a
    ///        bitmap from a Centaur DQ point of view. If the data in SPD is not
    ///        valid then it has never been written and all zeroes are returned (no
    ///        bad DQs).
    ///
    /// This HWP should be called by HWP/PLAT code to access the BAD DQ Bitmap
    ///
    /// @param[in] i_mba   Reference to MBA Target
    /// @param[in] i_dimm  Reference to DIMM Target
    /// @param[in,out] io_data Reference to bad DQ bitmap data for the DIMM.
    /// @param[in] i_get   True if getting DQ Bitmap data. False if setting data.
    /// @return FAPI2_RC_SUCCESS iff okay
    /// @note that the MSB of each byte corresponds to the lowest DQ.
    /// if (data[1][0] == 0x80) then rank 1, Centaur DQ0 is bad
    /// if (data[1][0] == 0x40) then rank 1, Centaur DQ1 is bad
    /// if (data[1][1] == 0x20) then rank 1, Centaur DQ10 is bad
    ///
    fapi2::ReturnCode dimmBadDqBitmapAccessHwp(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mba,
            const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
            uint8_t (&io_data)[MAX_RANKS_PER_DIMM][DIMM_DQ_RANK_BITMAP_SIZE],
            const bool i_get);

}

#endif
