/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ecc/ecc_traits_odyssey.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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
/// @file ecc_traits_odyssey.C
/// @brief Traits class for the MC ECC syndrome registers
///
// *HWP HWP Owner:  Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <ody_scom_ody_odc.H>
#include <lib/ecc/ecc_traits_odyssey.H>


namespace mss
{

// we need these declarations here in order for the linker to see the definitions
// in the eccTraits class
constexpr const uint64_t eccTraits<mc_type::ODYSSEY, fapi2::TARGET_TYPE_MEM_PORT>::MAINLINE_NCE_REGS[];
constexpr const uint64_t eccTraits<mc_type::ODYSSEY, fapi2::TARGET_TYPE_MEM_PORT>::MAINLINE_RCE_REGS[];
constexpr const uint64_t eccTraits<mc_type::ODYSSEY, fapi2::TARGET_TYPE_MEM_PORT>::MAINLINE_MPE_REGS[];
constexpr const uint64_t eccTraits<mc_type::ODYSSEY, fapi2::TARGET_TYPE_MEM_PORT>::MAINLINE_UE_REGS[];
constexpr const uint64_t eccTraits<mc_type::ODYSSEY, fapi2::TARGET_TYPE_MEM_PORT>::MAINLINE_AUE_REGS[];
constexpr const uint64_t eccTraits<mc_type::ODYSSEY, fapi2::TARGET_TYPE_MEM_PORT>::ERROR_VECTOR_REGS[];
constexpr const uint8_t eccTraits<mc_type::ODYSSEY, fapi2::TARGET_TYPE_MEM_PORT>::symbol2galois[];
constexpr const uint8_t eccTraits<mc_type::ODYSSEY, fapi2::TARGET_TYPE_MEM_PORT>::symbol2dq[];
constexpr const uint8_t eccTraits<mc_type::ODYSSEY, fapi2::TARGET_TYPE_MEM_PORT>::symbol2dq_x8[];

// Definition of the symbol error count registers for Odyssey
const std::vector< uint64_t > eccTraits<mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>::SYMBOL_COUNT_REG =
{
    scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC0Q,
    scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC1Q,
    scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC2Q,
    scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC3Q,
    scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC4Q,
    scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC5Q,
    scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC6Q,
    scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC7Q,
    scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC8Q,
    scomt::ody::ODC_MCBIST_SCOM_MBSSYMEC9Q,
};

} // close namespace mss
