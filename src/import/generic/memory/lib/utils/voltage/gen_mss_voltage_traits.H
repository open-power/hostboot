/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/voltage/gen_mss_voltage_traits.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2022                        */
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
/// @file gen_mss_voltage_traits.H
/// @brief Contains voltage traits information
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: CI

#ifndef _GEN_MSS_VOLTAGE_TRAITS_H_
#define _GEN_MSS_VOLTAGE_TRAITS_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{

///
/// @class Traits and policy class for voltage code
/// @tparam P mss::proc_type processor type
/// @tparam D mss::spd::device_type DRAM device type (generation)
///
template< mss::mc_type P, mss::spd::device_type D >
class voltage_traits;

///
/// @class Traits and policy class for voltage code - specialization for the P10 processor type, DDR4 device type
///
template<>
class voltage_traits<mss::mc_type::EXPLORER, mss::spd::device_type::DDR4>
{
    public:
        //////////////////////////////////////////////////////////////
        // Target types
        //////////////////////////////////////////////////////////////
        static constexpr fapi2::TargetType VOLTAGE_TARGET_TYPE = fapi2::TARGET_TYPE_OCMB_CHIP;
        static constexpr fapi2::TargetType SPD_TARGET_TYPE = fapi2::TARGET_TYPE_DIMM;

        //////////////////////////////////////////////////////////////
        // Traits values
        //////////////////////////////////////////////////////////////
        // List of attribute setter functions for setting voltage rail values
        static const std::vector<fapi2::ReturnCode (*)(const fapi2::Target<VOLTAGE_TARGET_TYPE>&, uint32_t)> voltage_setters;

        // Static consts for DDR4 voltages used in p9_mss_volt
        static const uint64_t DDR4_NOMINAL_VOLTAGE = 1200;
        static const uint64_t DDR4_VPP_VOLTAGE = 2500;
};

///
/// @class Traits and policy class for voltage code - specialization for the P10 processor type, DDR5 device type
///
template<>
class voltage_traits<mss::mc_type::ODYSSEY, mss::spd::device_type::DDR5>
{
    public:
        //////////////////////////////////////////////////////////////
        // Target types
        //////////////////////////////////////////////////////////////
        static constexpr fapi2::TargetType VOLTAGE_TARGET_TYPE = fapi2::TARGET_TYPE_OCMB_CHIP;
        static constexpr fapi2::TargetType SPD_TARGET_TYPE = fapi2::TARGET_TYPE_DIMM;

        //////////////////////////////////////////////////////////////
        // Traits values
        //////////////////////////////////////////////////////////////
        // List of attribute setter functions for setting voltage rail values
        static const std::vector<fapi2::ReturnCode (*)(const fapi2::Target<VOLTAGE_TARGET_TYPE>&, uint32_t)> voltage_setters;

        // Static consts for DDR5 voltages
        static const uint64_t DDR5_VDD_VOLTAGE = 1100;
        static const uint64_t DDR5_VDDQ_VOLTAGE = 1100;
        static const uint64_t DDR5_VPP_VOLTAGE = 1800;
};

} // ns mss
#endif
