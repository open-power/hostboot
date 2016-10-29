/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/ecc/ecc_traits.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file ecc_traits.C
/// @brief Traits class for the MC ECC syndrome registers
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/ecc/ecc_traits.H>

namespace mss
{

// we need these declarations here in order for the linker to see the definitions
// in the eccTraits class
constexpr const uint64_t eccTraits<fapi2::TARGET_TYPE_MCA>::MAINLINE_NCE_REGS[];
constexpr const uint64_t eccTraits<fapi2::TARGET_TYPE_MCA>::MAINLINE_RCE_REGS[];
constexpr const uint64_t eccTraits<fapi2::TARGET_TYPE_MCA>::MAINLINE_MPE_REGS[];
constexpr const uint64_t eccTraits<fapi2::TARGET_TYPE_MCA>::MAINLINE_UE_REGS[];
constexpr const uint64_t eccTraits<fapi2::TARGET_TYPE_MCA>::MAINLINE_AUE_REGS[];
constexpr const uint64_t eccTraits<fapi2::TARGET_TYPE_MCA>::ERROR_VECTOR_REGS[];

constexpr const uint8_t eccTraits<fapi2::TARGET_TYPE_MCA>::symbol2galois[];
constexpr const uint8_t eccTraits<fapi2::TARGET_TYPE_MCA>::symbol2dq[];

// Definition of the symbol error count registers
const std::vector< uint64_t > eccTraits<fapi2::TARGET_TYPE_MCBIST>::SYMBOL_COUNT_REG =
{
    MCBIST_MBSSYMEC0Q,
    MCBIST_MBSSYMEC1Q,
    MCBIST_MBSSYMEC2Q,
    MCBIST_MBSSYMEC3Q,
    MCBIST_MBSSYMEC4Q,
    MCBIST_MBSSYMEC5Q,
    MCBIST_MBSSYMEC6Q,
    MCBIST_MBSSYMEC7Q,
    MCBIST_MBSSYMEC8Q,
};

} // close namespace mss
