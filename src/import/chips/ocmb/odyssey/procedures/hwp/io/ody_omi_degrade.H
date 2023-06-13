/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_omi_degrade.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
#include <fapi2.H>
///------------------------------------------------------------------------------
/// @file ody_omi_degrade.H
/// @brief Attempt degrade recovery on degraded lanes
///
/// *HWP HW Maintainer : Josh Chica <josh.chica@ibm.com>
/// *HWP FW Maintainer :
/// *HWP Consumed by: SBE
///------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
typedef fapi2::ReturnCode (*ody_omi_degrade_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
    const uint32_t,
    const uint8_t,
    const uint8_t);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

    ///
    /// @brief Attempt degrade recovery on degraded lanes
    ///
    /// @param[in] i_target         Chip target to start
    /// @param[in] i_link_mask      Which links are being recovered
    /// @param[in] i_step           What step is currently being run
    ///                                 0 - Power On Tx/Rx, Allow Undegrade
    ///                                 1 - Start Initialize PHY Lanes (dccal/tx_zcal/etc) only on degraded lanes
    ///                                 2 - Poll PHY Initialization
    ///                                 3 - Force SW Retrain
    ///                                 4 - Confirm Width
    /// @param[in] i_loops_to_poll  How many loops to poll for
    ///
    /// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode ody_omi_degrade(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint32_t i_link_mask,
        const uint8_t i_step,
        const uint8_t i_loops_to_poll);

} // extern "C"
