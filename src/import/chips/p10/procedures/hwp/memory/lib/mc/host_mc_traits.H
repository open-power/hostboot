/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/mc/host_mc_traits.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file host_mc_traits.H
/// @brief P10 host memory controller traits
///

// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB

#ifndef _HOST_MC_TRAITS_H_
#define _HOST_MC_TRAITS_H_

#include <fapi2.H>
#include <p10_scom_mcc_4.H>
#include <p10_scom_mcc_d.H>

namespace mss
{

///
/// @class mccTraits
/// @tparam PT the proc type
/// @brief A collection of register traits for the Host MCC
///
template<mss::proc_type PT>
class mccTraits;

///
/// @class mccTraits
/// @brief A collection of register traits for the Host MCC, P10 specialization
///
template<>
class mccTraits<mss::proc_type::PROC_P10>
{
    public:
        // P10 MCC registers - must be 64 bits
        static constexpr uint64_t USTL_FAILMASK = scomt::mcc::USTL_USTLFAILMASK;
        static constexpr uint64_t DSTL_CFG      = scomt::mcc::DSTL_DSTLCFG;
        static constexpr uint64_t DSTL_CFG2     = scomt::mcc::DSTL_DSTLCFG2;
};

} // end mss ns
#endif
