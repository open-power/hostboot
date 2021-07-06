/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/exp_mr_workarounds.H $ */
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

///
/// @file exp_mr_workarounds.H
/// @brief MR related workarounds for explorer
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup:  Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#ifndef _EXP_MR_WORKAROUNDS_H_
#define _EXP_MR_WORKAROUNDS_H_

#include <fapi2.H>
#include <lib/ccs/ccs_explorer.H>

namespace mss
{
namespace exp
{
namespace workarounds
{

///
/// @brief Updates LPASR setting depending on MRW refresh rate attribute
/// @param[in] i_target port target on which to operate
/// @param[out] o_update_needed set to true if MR2 needs to be updated
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note Unit test helper
///
fapi2::ReturnCode update_lpasr(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                               bool& o_update_needed);


///
/// @brief Helper that adds the MR2 commands
/// @param[in] i_target port target on which to operate
/// @param[out] o_instructions CCS instructions
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note Unit test helper
///
fapi2::ReturnCode updates_mode_registers_helper(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        std::vector<ccs::instruction_t>& o_instructions);

///
/// @brief Updates MR2 to have the proper CWL value if the workaround is needed
/// @param[in] i_target port target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note This is the second part of the CCS 2666 write workaround
/// The CWL needs to be programmed into MR2
/// This cannot be done with the Microchip FW as we do not have a parameter for CWL
///
fapi2::ReturnCode updates_mode_registers(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);


} // workarounds
} // exp
} // mss

#endif
