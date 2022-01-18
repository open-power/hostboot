/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_fields_ddr5.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
/// @file spd_fields_ddr5.C
/// @brief DDR5 SPD data fields forward declarations
///

// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB
// EKB-Mirror-To: hostboot

#include <generic/memory/lib/spd/spd_fields_ddr5.H>

namespace mss
{
namespace spd
{

// These "definitions" are needed to generate linkage for the static constexprs declared in the .H because of ODR-used

// fields<DDR5, BASE_CNFG>
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::HYBRID;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::HYBRID_MEDIA;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::BASE_MODULE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::DIE_PER_PACKAGE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::DENSITY_PER_DIE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::RANK_MIX;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::PACKAGE_RANKS_PER_CHANNEL;

}// spd
}// mss
