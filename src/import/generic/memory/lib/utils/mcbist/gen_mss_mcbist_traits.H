/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mcbist/gen_mss_mcbist_traits.H $ */
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
/// @file gen_mss_mcbist_traits.H
/// @brief Run and manage the MCBIST engine
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _GEN_MSS_MCBIST_TRAITS_H_
#define _GEN_MSS_MCBIST_TRAITS_H_

#include <fapi2.H>

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_address.H>

namespace mss
{

///
/// @class mcbistMCTraits
/// @tparam MC the mc type
/// @brief A MC to MC_TARGET_TYPE mapping
///
template< mss::mc_type MC = DEFAULT_MC_TYPE >
class mcbistMCTraits;

///
/// @class mcbistTraits
/// @tparam MC the mc type of the T
/// @tparam T the fapi2::TargetType - derived
/// @brief a collection of traits associated with the MCBIST engine or hardware
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T = mss::mcbistMCTraits<MC>::MC_TARGET_TYPE>
class mcbistTraits;

}// mss
#endif
