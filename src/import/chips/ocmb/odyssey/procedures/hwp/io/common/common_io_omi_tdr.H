/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/common/common_io_omi_tdr.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
/// @file common_io_omi_tdr.H
/// @brief OMI TDR procedure
///
/// *HWP HW Maintainer: Josh Chica <Josh.Chica@ibm.com>
/// *HWP FW Maintainer:
/// *HWP Consumed by: SBE
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#pragma once
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*common_io_omi_tdr_FP_t)(
    const fapi2::Target < fapi2::TARGET_TYPE_OCMB_CHIP | fapi2::TARGET_TYPE_OMI > &,
    const uint32_t,
    const uint64_t);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

    ///
    /// @brief OMI TDR procedure
    ///
    /// @param[in] i_target       Reference to compound target
    /// @param[in] i_freq         OMI link frequency
    /// @param[in] i_base_addr    Base address relative to i_target
    /// @return fapi::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
    ///
    fapi2::ReturnCode common_io_omi_tdr(const fapi2::Target < fapi2::TARGET_TYPE_OCMB_CHIP | fapi2::TARGET_TYPE_OMI > &
                                        i_target,
                                        const uint32_t i_freq,
                                        const uint64_t i_base_addr);

} // extern "C"
