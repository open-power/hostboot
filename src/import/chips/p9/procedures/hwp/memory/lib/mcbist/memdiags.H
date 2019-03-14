/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/mcbist/memdiags.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
/// @file memdiags.H
/// @brief API for memory diagnostics
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP
//

#ifndef _MSS_MEMDIAGS_H_
#define _MSS_MEMDIAGS_H_

#include <fapi2.H>
#include <lib/shared/mss_const.H>
#include <lib/ecc/ecc_traits.H>
#include <lib/mcbist/mcbist.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_memdiags.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_DIMM;
using fapi2::TARGET_TYPE_SYSTEM;
using fapi2::FAPI2_RC_SUCCESS;
using fapi2::FAPI2_RC_INVALID_PARAMETER;

namespace mss
{

namespace memdiags
{

///
/// @brief Checks that the starting port/dimm address is in range for broadcast mode - helper for testing
/// @param[in] i_targets a vector of MCA targets
/// @param[in] i_start_addr the starting port_dimm select address
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode broadcast_mode_start_address_check_helper(
    const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCA> >& i_targets,
    const uint64_t i_start_addr);

///
/// @brief Start address port dimm check
/// @param[in] i_target the MCBIST target
/// @param[in] i_start_addr the starting address
/// @param[out] o_dimms DIMM(s) associated with the first valid MCA
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode broadcast_mode_start_address_check(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
        const uint64_t i_start_addr,
        std::vector< fapi2::Target<fapi2::TARGET_TYPE_DIMM> >& o_dimms);

} // ns memdiags

} // ns mss
#endif
