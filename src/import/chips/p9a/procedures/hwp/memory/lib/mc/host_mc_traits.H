/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/lib/mc/host_mc_traits.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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

#ifndef _HOST_MC_TRAITS_H_
#define _HOST_MC_TRAITS_H_

#include <fapi2.H>
#include <p9a_mc_scom_addresses.H>
#include <p9a_mc_scom_addresses_fld.H>
#include <p9a_mc_scom_addresses_fixes.H>
#include <p9a_mc_scom_addresses_fld_fixes.H>

namespace mss
{

///
/// @class mcTraits
/// @tparam PT the proc type
/// @brief A collection of register traits for the Host MC
///
template<mss::proc_type PT>
class mcTraits;

///
/// @class mcTraits
/// @brief A collection of register traits for the Host MC, Axone specialization
///
template<>
class mcTraits<mss::proc_type::AXONE>
{
    public:
        // p9a MC registers - must be 64 bits
        static constexpr uint64_t REG0_DL0_ERROR_MASK = P9A_MC_REG0_DL0_ERROR_MASK;
        static constexpr uint64_t REG0_DL1_ERROR_MASK = P9A_MC_REG0_DL1_ERROR_MASK;
        static constexpr uint64_t REG0_DL2_ERROR_MASK = P9A_MC_REG0_DL2_ERROR_MASK;
        static constexpr uint64_t REG1_DL0_ERROR_MASK = P9A_MC_REG1_DL0_ERROR_MASK;
        static constexpr uint64_t REG1_DL1_ERROR_MASK = P9A_MC_REG1_DL1_ERROR_MASK;
        static constexpr uint64_t REG1_DL2_ERROR_MASK = P9A_MC_REG1_DL2_ERROR_MASK;
        static constexpr uint64_t REG2_DL0_ERROR_MASK = P9A_MC_REG2_DL0_ERROR_MASK;
        static constexpr uint64_t REG2_DL1_ERROR_MASK = P9A_MC_REG2_DL1_ERROR_MASK;
        static constexpr uint64_t REG2_DL2_ERROR_MASK = P9A_MC_REG2_DL2_ERROR_MASK;
};

///
/// @class mccTraits
/// @tparam PT the proc type
/// @brief A collection of register traits for the Host MCC
///
template<mss::proc_type PT>
class mccTraits;

///
/// @class mccTraits
/// @brief A collection of register traits for the Host MCC, Axone specialization
///
template<>
class mccTraits<mss::proc_type::AXONE>
{
    public:
        // p9a MCC registers - must be 64 bits
        static constexpr uint64_t USTL_FAILMASK = P9A_MCC_USTLFAILMASK;
        static constexpr uint64_t DSTL_CFG      = P9A_MCC_DSTLCFG;
        static constexpr uint64_t DSTL_CFG2     = P9A_MCC_DSTLCFG2;
};

} // end mss ns
#endif
