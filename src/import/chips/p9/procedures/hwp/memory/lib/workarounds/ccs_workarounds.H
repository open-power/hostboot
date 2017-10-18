/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/ccs_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file ccs_workarounds.H
/// @brief Contains CCS workarounds
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB Memory Lab

#ifndef _CCS_WORKAROUNDS_H
#define _CCS_WORKAROUNDS_H

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>

#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/ccs/ccs.H>

namespace mss
{

namespace ccs
{

namespace workarounds
{

///
/// @brief Issues the PDA exit command
/// @param[in] i_target - the DIMM target on which to operate
/// @param[in] i_rank - the rank on which to operate
/// @param[in,out] io_program - the CCS program
/// @return fapi2::ReturnCode - SUCCESS iff everything executes successfully
/// @note The PHY traps both the a-side and b-side MRS's into the same shadow register
/// After the a-side MRS exits PDA, the b-side MRS will not be taken out of PDA mode
/// To workaround this problem, a-side MRS is issued, then the shadow register is modified to have PDA mode enabled
/// Then the b-side MRS is issued
///
fapi2::ReturnCode exit( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const uint64_t i_rank,
                        ccs::program<fapi2::TARGET_TYPE_MCBIST>& io_program );

///
/// @brief Re-enables PDA mode on a given rank in the shadow registers
/// @param[in] i_target - the MCA target on which to operate
/// @param[in] i_rank - the rank on which to operate
/// @return fapi2::ReturnCode - SUCCESS iff everything executes successfully
///
fapi2::ReturnCode enable_pda_shadow_reg( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rank );

} // ns workarounds

} // ns ccs

} // ns mss

#endif
