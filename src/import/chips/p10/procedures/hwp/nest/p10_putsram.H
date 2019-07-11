/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_putsram.H $      */
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
/// @file p10_putsram.H
/// @brief Write data to SRAM of PPEs (IO, QME, PCI, or OCC)
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB, Cronus, SBE
///

#ifndef _P10_PUTSRAM_H_
#define _P10_PUTSRAM_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode(*p10_putsram_FP_t) (
    const fapi2::Target < fapi2::TARGET_TYPE_PROC_CHIP>&,
    const uint32_t,
    const bool,
    const uint8_t,
    const uint64_t,
    const uint32_t,
    uint8_t*);

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
extern "C" {

///
///
/// @brief Write data to SRAM of different types of PPEs:
///        IO, QME, PCI, or OCC.
///
/// @param[in]  i_target        Reference to proc chip target
/// @param[in]  i_pervChipletId Target perv chiplet ID, only relevant for unitcast.
///                             For multicast, first functional chiplet will be used.
/// @param[in]  i_multicast     True: Muticast access; False: Unicast access
/// @param[in]  i_mode          For OCC use only:
///                               0x1   Normal
///                               0x2   Debug
///                               0x3   Circular
/// @param[in]  i_offset        SRAM address offset to write to
/// @param[in]  i_bytes         Size of data to write in bytes
/// @param[in]  i_data          Pointer to write data
///
/// @return FAPI_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode p10_putsram(const fapi2::Target < fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                  const uint32_t i_pervChipletId,
                                  const bool i_multicast,
                                  const uint8_t i_mode,
                                  const uint64_t i_offset,
                                  const uint32_t i_bytes,
                                  uint8_t* i_data);

} //extern "C"

#endif //_P10_PUTSRAM_H_
