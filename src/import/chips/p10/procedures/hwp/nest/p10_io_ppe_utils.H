/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_io_ppe_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/// @file p10_io_ppe_utils.H
///
/// @brief Common code to support p10_get/putsram_io_ppe HWPs.
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: N/A
/// *HWP Consumed by: HB, Cronus, SBE
///
#ifndef _P10_IO_PPE_UTILS_H_
#define _P10_IO_PPE_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
//

extern "C" {

///
/// @brief Enable/Disable Auto Increment for IO PPE SRAM access
///
/// @param[in]  i_target    Reference PAUC or MULTICAST target
/// @param[in]  i_enable    true=Enable; false=Disable
///
/// @return FAPI_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode enableDisableIoPpeAutoInc(
        const fapi2::Target < fapi2::TARGET_TYPE_PAUC | fapi2::TARGET_TYPE_MULTICAST > & i_target,
        bool i_enable);

} //extern "C"

#endif //_P10_IO_PPE_UTILS_H_
