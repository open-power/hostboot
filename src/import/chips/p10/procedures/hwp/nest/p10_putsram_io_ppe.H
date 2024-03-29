/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_putsram_io_ppe.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p10_putsram_io_ppe.H
/// @brief Write data to IO PPE SRAM
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB, Cronus, SBE
///

#ifndef _P10_PUTSRAM_IO_PPE_H_
#define _P10_PUTSRAM_IO_PPE_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode(*p10_putsram_io_ppe_FP_t) (
    const fapi2::Target < fapi2::TARGET_TYPE_PAUC |
    fapi2::TARGET_TYPE_MULTICAST > &,
    const uint64_t,
    const uint32_t,
    uint8_t*);

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
extern "C" {

///
///
/// @brief Write data to IO PPE SRAM
///
/// @param[in]  i_target    Reference target, can be a Multicast target
/// @param[in]  i_offset    SRAM address offset to write to
/// @param[in]  i_bytes     Size of data in bytes
/// @param[in]  i_data      Pointer to write data
///
/// @return FAPI_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode p10_putsram_io_ppe(
        const fapi2::Target < fapi2::TARGET_TYPE_PAUC |
        fapi2::TARGET_TYPE_MULTICAST > & i_target,
        const uint64_t i_offset,
        const uint32_t i_bytes,
        uint8_t* i_data);

} //extern "C"

#endif //_P10_PUTSRAM_IO_PPE_H_
