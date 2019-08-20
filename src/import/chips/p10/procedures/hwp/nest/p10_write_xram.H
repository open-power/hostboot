/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_write_xram.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p10_write_xram.H
/// @brief Write data to IOP XRAM
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB, Cronus
///

#ifndef _P10_WRITE_XRAM_H_
#define _P10_WRITE_XRAM_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_iop_xram_utils.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode(*p10_write_xram_FP_t) (
    const fapi2::Target < fapi2::TARGET_TYPE_PEC |
    fapi2::TARGET_TYPE_MULTICAST > &,
    const uint32_t,
    const uint32_t,
    const xramIopTopNum_t,
    const xramPhyNum_t,
    uint8_t*);

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
extern "C" {

///
///
/// @brief Write data to specified XRAM.
///
/// @param[in]  i_target    Reference PEC or PEC multicast target
/// @param[in]  i_offset    XRAM address offset to write to
/// @param[in]  i_bytes     Num of bytes to write
/// @param[in]  i_top       iop_top to write data to
/// @param[in]  i_phy       PHY XRAM to write data to
/// @param[in]  i_data      Pointer to data
///
/// @return FAPI_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode p10_write_xram(
        const fapi2::Target < fapi2::TARGET_TYPE_PEC |
        fapi2::TARGET_TYPE_MULTICAST > & i_target,
        const uint32_t i_offset,
        const uint32_t i_bytes,
        const xramIopTopNum_t i_top,
        const xramPhyNum_t i_phy,
        uint8_t* i_data);

} //extern "C"

#endif //_P10_WRITE_XRAM_H_
