/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/dimmBadDqBitmapFuncs.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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
#ifndef DIMMBADDQBITMAPFUNCS_H_
#define DIMMBADDQBITMAPFUNCS_H_

#include <fapi2.H>
#include <mss_generic_consts.H>

extern "C"
{

/**
 * @brief FW Team Utility function that gets the Bad DQ Bitmap.
 *
 * This utility functon should be called by a HWP needing to get the Bad DQ
 * bitmap for a particular mem port, dimm and rank.
 *
 * This function finds the corresponding DIMM Target, calls
 * dimmBadDqBitmapAccessHwp to get the DQ bitmap and returns the data
 * for the specified rank.
 *
 * @param[in]  i_fapiTrgt Reference to MEM_PORT/OCMB_CHIP Target
 * @param[in]  i_dimm     DIMM number
 * @param[in]  i_rank     DIMM rank number
 * @param[out] o_data     Reference to data where Bad DQ bitmap is copied to
 *
 * @return ReturnCode
 */
fapi2::ReturnCode p10DimmGetBadDqBitmap( const fapi2::Target
    <fapi2::TARGET_TYPE_MEM_PORT|fapi2::TARGET_TYPE_OCMB_CHIP>& i_fapiTrgt,
    uint8_t i_dimm,
    uint8_t i_rank,
    uint8_t (&o_data)[mss::BAD_DQ_BYTE_COUNT]);

/**
 * @brief FW Team Utility function that sets the Bad DQ Bitmap.
 *
 * This utility functon should be called by a HWP needing to set the Bad DQ
 * bitmap for a particular mem port, dimm and rank.
 *
 * This utility function finds the corresponding DIMM Target, calls
 * dimmBadDqBitmapAccessHwp to get the DQ bitmap, fills in the data for the
 * specified rank and calls dimmBadDqBitmapAccessHwp to set the DQ bitmap
 *
 * @param[in] i_fapiTrgt Reference to MEM_PORT/OCMB_CHIP Target
 * @param[in] i_dimm     DIMM number
 * @param[in] i_rank     DIMM rank number
 * @param[in] i_data     Reference to data where Bad DQ bitmap is copied from
 *
 * @return ReturnCode
 */
fapi2::ReturnCode p10DimmSetBadDqBitmap( const fapi2::Target
    <fapi2::TARGET_TYPE_MEM_PORT|fapi2::TARGET_TYPE_OCMB_CHIP>& i_fapiTrgt,
    uint8_t i_dimm,
    uint8_t i_rank,
    const uint8_t (&i_data)[mss::BAD_DQ_BYTE_COUNT]);
}

#endif
