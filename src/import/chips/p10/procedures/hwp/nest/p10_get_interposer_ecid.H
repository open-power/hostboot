/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_get_interposer_ecid.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
/// @file p10_get_interposer_ecid.H
/// @brief Check the if interposer is present and it's revision level
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------
// EKB-Mirror-To: hostboot

#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
typedef fapi2::ReturnCode (*p10_get_interposer_ecid_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    fapi2::variable_buffer&);

enum P10_GET_INTERPOSER_ECID_Public_Constants
{
    p10_get_interposer_ecid_fuseString_len = 64,       // fuse string length
};

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Wait for dccal done and power-up all configured links/lanes
///
/// @param[in] i_target Chip target to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode p10_get_interposer_ecid(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        fapi2::variable_buffer& o_ecid);

} // extern "C"
