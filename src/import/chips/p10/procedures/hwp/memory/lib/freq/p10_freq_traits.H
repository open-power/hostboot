/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/freq/p10_freq_traits.H $ */
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
/// @file p10_freq_traits.H
/// @brief Contains frequency traits information for P10
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: CI

#ifndef _P10_FREQ_TRAITS_H_
#define _P10_FREQ_TRAITS_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/freq/gen_mss_freq_traits.H>
#include <vpd_access.H>

namespace mss
{

///
/// @class Traits and policy class for frequency and synchronous code - specialization for the P10 processor type
///
template<>
class frequency_traits<mss::proc_type::PROC_P10>
{
    public:
        //////////////////////////////////////////////////////////////
        // Target types
        //////////////////////////////////////////////////////////////
        static constexpr fapi2::TargetType PORT_TARGET_TYPE = fapi2::TARGET_TYPE_MEM_PORT;
        static constexpr fapi2::TargetType FREQ_TARGET_TYPE = fapi2::TARGET_TYPE_MEM_PORT;
        static constexpr fapi2::TargetType FREQ_DOMAIN_TARGET_TYPE = fapi2::TARGET_TYPE_PROC_CHIP;
        static constexpr fapi2::TargetType VPD_TARGET_TYPE = fapi2::TARGET_TYPE_OCMB_CHIP;

        //////////////////////////////////////////////////////////////
        // Traits values
        //////////////////////////////////////////////////////////////
        static const std::vector<uint64_t> SUPPORTED_FREQS;
        // PROC_CHIP is our frequency domain
        static constexpr uint64_t PORTS_PER_FREQ_DOMAIN = 16;
        // Max DIMM's per port
        static constexpr uint64_t MAX_DIMM_PER_PORT = 2;
        // Maxium number of primary ranks on a DIMM
        static constexpr uint64_t MAX_PRIMARY_RANK_PER_DIMM = 4;
        // MC type for P10 is constant - EXPLORER
        static constexpr mss::mc_type MC = mss::mc_type::EXPLORER;
        static constexpr const char* PROC_STR = "P10";

        // VPD traits values
        // TK Resolve these when we know what they are for P10
        static constexpr uint64_t VPD_KEYWORD_MAX = 255;
        static constexpr const char* VPD_BLOB_NAME = "EFD";
        static constexpr auto VPD_BLOB = fapi2::MemVpdData::EFD;
        static constexpr auto LRDIMM_TYPE = fapi2::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM;

        // Coding minion, why have these explicitly defined frequency values?
        // Isn't the supported frequency vector used for this purpose?
        // Well, we need to callout the specific frequency values that are allowed on a given system
        // As we can't callout a vector in error callouts and each traits might have a different number of allowable traits,
        // the below values are hardcoded specifically for the error callouts
        static constexpr uint64_t SUPPORTED_FREQ0 = DIMM_SPEED_2666;
        static constexpr uint64_t SUPPORTED_FREQ1 = DIMM_SPEED_2933;
        static constexpr uint64_t SUPPORTED_FREQ2 = DIMM_SPEED_3200;
};


} // ns mss
#endif
