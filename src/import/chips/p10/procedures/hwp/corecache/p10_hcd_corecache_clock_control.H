/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_hcd_corecache_clock_control.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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


#ifndef _P10_HCD_CORECACHE_CLOCK_CONTROL_H_
#define _P10_HCD_CORECACHE_CLOCK_CONTROL_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_hcd_corecache_clock_control_FP_t) (
    const fapi2::Target < fapi2::TARGET_TYPE_EQ |
    fapi2::TARGET_TYPE_MULTICAST,
    fapi2::MULTICAST_AND > &,
    uint32_t, uint32_t);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Initialize fabric (in single chip 'island mode' configuration) by mastering
/// an init command (ttype=pbop.init_all) from the Alter Display Unit (ADU)
///
/// @param[in] i_target       Reference to processor chip target
/// @param[in] i_command      bit0:stop, bit1:start, bit2:slave, bit3:master
/// @return fapi::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_hcd_corecache_clock_control(
        const fapi2::Target < fapi2::TARGET_TYPE_EQ |
        fapi2::TARGET_TYPE_MULTICAST,
        fapi2::MULTICAST_AND > & i_target,
        uint32_t i_regions,
        uint32_t i_command);

} // extern "C"

#endif // _P10_HCD_CORECACHE_CLOCK_CONTROL_H_
