/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/ecc/ecc_traits.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file ecc_traits.H
/// @brief Traits class for the MC ECC syndrome registers
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_ECC_TRAITS_H_
#define _MSS_ECC_TRAITS_H_

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{

///
/// @class eccMCTraits
/// @brief a collection of traits associated with the MC ECC interface
/// @tparam T fapi2::TargetType representing the memory controller
///
template< mss::mc_type MC >
class eccMCTraits;

///
/// @class eccTraits
/// @brief a collection of traits associated with the MC/Target ECC interface
/// @tparam T fapi2::TargetType representing the memory controller
///
template< mss::mc_type MC, fapi2::TargetType T >
class eccTraits;

} // close namespace mss

#endif
