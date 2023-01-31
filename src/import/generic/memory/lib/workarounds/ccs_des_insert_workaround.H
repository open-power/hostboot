/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/workarounds/ccs_des_insert_workaround.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
/// @file ccs_des_insert_workaround.H
/// @brief Generic template for CCS des command insert
///
// *HWP HWP Owner: David Jude Chung <dj.chung@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_CCS_DES_WORKAROUND_H_
#define _MSS_CCS_DES_WORKAROUND_H_

#include <fapi2.H>
#include <generic/memory/lib/ccs/ccs_instruction.H>

namespace mss
{
namespace ccs
{
namespace workarounds
{

///
/// @brief Workaround for DES command insertion
/// @tparam MC the memory controller type running CCS
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in] i_port the port target to effect
/// @param[in,out] io_inst_count the inst count for the ccs instructions
/// @param[in] i_current_cke the CKE for this instruction
/// @param[in] i_rank_config rank configs relative to memport pos
/// @return FAPI2_RC_SUCCESS iff ok
///
template <mss::mc_type MC, fapi2::TargetType T, fapi2::TargetType P>
fapi2::ReturnCode insert_des(const fapi2::Target<T>& i_target,
                             const fapi2::Target<P>& i_port,
                             size_t& io_inst_count,
                             const uint8_t i_current_cke,
                             const mss::ccs::rank_configuration i_rank_config);

} // namespace workaround
} // namespace ccs
} // namespace mss

#endif
