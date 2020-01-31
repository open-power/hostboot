/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_sram_access_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/// @file  p10_pm_sram_access_utils.H
/// @brief SRAM access utility functions for QME and OCC.
///
// *HWP HWP Owner       : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Amit Tendolkar <amit.tendolkar@in.ibm.com>
// *HWP Team            : PM
// *HWP Consumed by     : HS:CRO:SBE
///

#ifndef _P10_PM_SRAM_ACCESS_UTILS_H_
#define _P10_PM_SRAM_ACCESS_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
extern "C" {

/// @brief Load a double word into a buffer.
///
/// @param [in]  i_useByteBuf    Buffer is byte wide
/// @param [in]  i_data          Double word data
/// @param [out] o_dataPtr       64-bit buffer pointer
///
    void loadDataToBuffer(const bool i_useByteBuf,
                          const uint64_t i_data,
                          uint64_t* o_dataPtr);

/// @brief Get a double word from a buffer.
///
/// @param [in]  i_useByteBuf    Buffer is byte wide
/// @param [in]  i_dataPtr       64-bit buffer pointer
/// @param [out] o_data          Double word data
///
    void getDataFromBuffer(const bool i_useByteBuf,
                           uint64_t* i_dataPtr,
                           uint64_t& o_data);

} // extern "C"

#endif // _P10_PM_SRAM_ACCESS_UTILS_H_
