/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/workarounds/ody_dfi_complete_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
/// @file ody_dfi_complete_workarounds.H
/// @brief Workarounds for DFI initialization
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_ODY_DFI_COMPLETE_WORKAROUNDS_H_
#define _MSS_ODY_DFI_COMPLETE_WORKAROUNDS_H_

#include <fapi2.H>


namespace mss
{
namespace ody
{
namespace workarounds
{

///
/// @brief Checks the DFI init completion
/// @param[in] i_target the target to check for DFI interface completion
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode check_dfi_init( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target );

///
/// @brief Checks the DFI init completion - helper for unit testing
/// @param[in] i_target the target to check for DFI interface completion
/// @param[in] i_is_simulation true if this is a simulation environment
/// @param[in] i_is_simics holds the simulation/simics environment type
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode check_dfi_init_helper( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint8_t i_is_simulation, const uint8_t i_is_simics );

///
/// @brief Completes the DFI initialization for simulation
/// @param[in] i_target the target on which to operate
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode complete_dfi_init_for_sim( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target );

///
/// @brief Checks the DFI init workaround is needed
/// @param[in] i_target the target to check for DFI interface completion
/// @param[in] i_is_simulation true if this is a simulation environment
/// @param[in] i_is_simics holds the simulation/simics environment type
/// @return FAPI2_RC_SUCCSS iff ok
///
bool is_simulation_dfi_init_workaround_needed( const uint8_t i_is_simulation, const uint8_t i_is_simics );

///
/// @brief Deasserts the reset_n pin if needed
/// @param[in] i_target the target on which to operate
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode deassert_resetn( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target );

///
/// @brief Deasserts the reset_n pin if needed
/// @param[in] i_target the target on which to operate
/// @param[in] i_is_simulation true if this is a simulation environment
/// @param[in] i_is_simics holds the simulation/simics environment type
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode deassert_resetn_helper( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint8_t i_is_simulation,
        const uint8_t i_is_simics );

} // ns workarounds
} // ns ody
} // ns mss

#endif
