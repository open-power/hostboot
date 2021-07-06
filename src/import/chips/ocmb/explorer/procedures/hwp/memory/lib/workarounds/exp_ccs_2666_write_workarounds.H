/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/exp_ccs_2666_write_workarounds.H $ */
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
/// @file exp_ccs_2666_workarounds.H
/// @brief Workarounds for explorer CCS write issue at 2666
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup:  Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#ifndef _EXP_CCS_2666_WRITE_WORKAROUNDS_H_
#define _EXP_CCS_2666_WRITE_WORKAROUNDS_H_

#include <fapi2.H>
#include <lib/ccs/ccs_explorer.H>

namespace mss
{
namespace exp
{
namespace workarounds
{

///
/// @brief Determine if the CCS 2666 write workaround is needed
/// @param[in] i_target port target on which to operate
/// @param[out] o_is_needed true if the workaround needs to be run
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode is_ccs_2666_write_needed(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        bool& o_is_needed);

///
/// @brief Updates CAS write latency if the workaround is needed
/// @param[in] i_target port target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note This is the first part of the CCS 2666 write workaround
/// The CWL needs to be increased to 18 for 2666 (non RDIMM)
/// This will put a non-zero value in the WRDATA_DLY, allowing for good CCS writes
///
fapi2::ReturnCode update_cwl(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

} // workarounds
} // exp
} // mss

#endif
