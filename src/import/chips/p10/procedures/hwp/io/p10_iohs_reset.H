/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_iohs_reset.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file p10_iohs_reset.H
/// @brief Reset the iohs phy
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  :
///-----------------------------------------------------------------------------

#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
typedef fapi2::ReturnCode (*p10_iohs_reset_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>&, const uint8_t);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Reset the IOHS Half phy
///
/// @param[in] i_target IOHS target to reset
/// @param[in] i_half odd/even/both
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode p10_iohs_reset(
        const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target, const uint8_t i_half);

///
/// @brief Reset the IOHS Half phy
///
/// @param[in] i_target IOHS target to reset
/// @param[in] i_half odd/even/both
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode p10_iohs_init(
        const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target, const uint8_t i_half);

///
/// @brief Reset the IOLINK phy -- keeps the iolink in reset
///
/// @param[in] i_target Iolink target to reset
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode p10_iolink_reset(
        const fapi2::Target<fapi2::TARGET_TYPE_IOLINK>& i_iolink);

} // extern "C"
