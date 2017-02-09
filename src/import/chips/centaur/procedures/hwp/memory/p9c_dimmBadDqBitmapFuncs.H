/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_dimmBadDqBitmapFuncs.H $ */
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
/// @file p9c_dimmBadDqBitmapFuncs.H
/// @brief FW Team Utility functions that accesses the Bad DQ Bitmap.
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
////
//
#ifndef DIMMBADDQBITMAPFUNCS_H_
#define DIMMBADDQBITMAPFUNCS_H_

#include <fapi2.H>
#include <dimmConsts.H>

extern "C"
{

    ///
    /// @brief FW Team Utility function that gets the Bad DQ Bitmap.
    ///
    /// This utility functon should be called by a HWP needing to get the Bad DQ
    /// bitmap for a particular mba, port, dimm and rank.
    ///
    /// This function finds the corresponding DIMM fapi2::Target<fapi2::TARGET_TYPE_MBA>, calls
    /// p9c_dimmBadDqBitmapAccessHwp to get the DQ bitmap and returns the data
    /// for the specified rank.
    ///
    /// @param[in]  i_mba  Reference to MBA Chiplet
    /// @param[in]  i_port MBA port number (0-(MAX_PORTS_PER_MBA - 1))
    /// @param[in]  i_dimm MBA port DIMM number (0-(MAX_DIMM_PER_PORT - 1))
    /// @param[in]  i_rank DIMM rank number (0-(MAX_RANKS_PER_DIMM -1))
    /// @param[out] o_data Reference to data where Bad DQ bitmap is copied to
    /// @return ReturnCode
    ///
    fapi2::ReturnCode dimmGetBadDqBitmap(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mba,
                                         const uint8_t i_port,
                                         const uint8_t i_dimm,
                                         const uint8_t i_rank,
                                         uint8_t (&o_data)[DIMM_DQ_RANK_BITMAP_SIZE]);

    ///
    /// @brief FW Team Utility function that sets the Bad DQ Bitmap.
    ///
    /// This utility functon should be called by a HWP needing to set the Bad DQ
    /// bitmap for a particular mba, port, dimm and rank.
    ///
    /// This utility function finds the corresponding DIMM fapi2::Target<fapi2::TARGET_TYPE_MBA>, calls
    /// dimmBadDqBitmapAccessHwp to get the DQ bitmap, fills in the data for the
    /// specified rank and calls dimmBadDqBitmapAccessHwp to set the DQ bitmap
    ///
    /// @param[in] i_mba  Reference to MBA Chiplet
    /// @param[in] i_port MBA port number (0-(MAX_PORTS_PER_MBA - 1))
    /// @param[in] i_dimm MBA port DIMM number (0-(MAX_DIMM_PER_PORT - 1))
    /// @param[in] i_rank DIMM rank number (0-(MAX_RANKS_PER_DIMM -1))
    /// @param[in] i_data Reference to data where Bad DQ bitmap is copied from
    /// @return ReturnCode
    ///
    fapi2::ReturnCode dimmSetBadDqBitmap(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mba,
                                         const uint8_t i_port,
                                         const uint8_t i_dimm,
                                         const uint8_t i_rank,
                                         const uint8_t (&i_data)[DIMM_DQ_RANK_BITMAP_SIZE]);
}

#endif
