/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mcbist/exp_mcbist.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file exp_mcbist.H
/// @brief Run and manage the MCBIST engine
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_EXP_MCBIST_H_
#define _MSS_EXP_MCBIST_H_

#include <fapi2.H>

#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>

#include <lib/shared/exp_consts.H>
#include <lib/ecc/ecc_traits_explorer.H>
#include <lib/mcbist/exp_mcbist_traits.H>
#include <lib/mc/exp_port.H>
#include <lib/utils/mss_exp_conversions.H>
#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/memory_size.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_patterns.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_settings.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist.H>

namespace mss
{

namespace mcbist
{

///
/// @brief Load MCBIST ECC (and?) spare data pattern given a pattern - explorer specialization
/// @param[in] i_target the target to effect
/// @param[in] i_pattern an mcbist::patterns
/// @param[in] i_invert whether to invert the pattern or not
/// @return FAPI2_RC_SUCCSS iff ok
///
template< >
inline fapi2::ReturnCode load_eccspare_pattern<mss::mc_type::EXPLORER>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const pattern& i_pattern,
    const bool i_invert )
{
    // First up assemble the pattern
    const auto l_pattern = generate_eccspare_pattern(i_pattern, i_invert);

    FAPI_TRY(fapi2::putScom(i_target, EXPLR_MCBIST_MCBFDQ, l_pattern));
    FAPI_TRY(fapi2::putScom(i_target, EXPLR_MCBIST_MCBFDSPQ, l_pattern));

fapi_try_exit:
    return fapi2::current_err;
}

} // ns mss

} // ns mcbist
#endif
