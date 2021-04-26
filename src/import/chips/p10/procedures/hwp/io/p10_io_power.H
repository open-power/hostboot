/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_power.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
// EKB-Mirror-To: hostboot
///
/// @file p10_io_power.H
/// @brief Common IO functions and constants
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------

#include <fapi2.H>

#ifndef _P10_IO_POWER__
#define _P10_IO_POWER__

//------------------------------------------------------------------------------
// Consts
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Functions
//------------------------------------------------------------------------------

extern "C"
{
///
/// @brief Set power on/off for targeted lanes.
///
/// @param[in] i_iolink_target Iolink target to work with
/// @param[in] i_on Specified action (true=on, false=off)
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode p10_io_iolink_power(
        const fapi2::Target<fapi2::TARGET_TYPE_IOLINK>& i_iolink_target,
        const bool& i_on);

///
/// @brief Set power on/off for targeted lanes.
///
/// @param[in] i_iohs_target Iohs target to work with
/// @param[in] i_on Specified action (true=on, false=off)
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode p10_io_iohs_power(
        const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
        const bool& i_on);

///
/// @brief Set power on/off for targeted lanes.
///
/// @param[in] i_omic_target Omic target to work with
/// @param[in] i_on Specified action (true=on, false=off)
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode p10_io_omic_power(
        const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_omic_target,
        const bool& i_on);
} // extern "C"
#endif
