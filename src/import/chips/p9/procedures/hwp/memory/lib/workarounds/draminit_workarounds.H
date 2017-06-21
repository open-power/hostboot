/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/draminit_workarounds.H $ */
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
/// @file workarounds/draminit_workarounds.H
/// @brief Workarounds for the draminit code
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <mss.H>
#include <lib/dimm/rcd_load_ddr4.H>
#include <lib/dimm/ddr4/control_word_ddr4.H>

namespace mss
{

namespace workarounds
{

///
/// @brief Runs the DRAM reset workaround to fix training bugs
/// @param[in] i_target - the target on which to operate
/// @param[in,out] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode rcw_reset_dram( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                  std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst);

} // namespace workarounds

} // namespace mss
