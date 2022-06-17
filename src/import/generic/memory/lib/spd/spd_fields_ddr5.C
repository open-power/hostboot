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
// *HWP Level: 2
// *HWP Consumed by: HB
// EKB-Mirror-To: hostboot

#include <generic/memory/lib/spd/spd_fields_ddr5.H>

namespace mss
{
namespace spd
{

// These "definitions" are needed to generate linkage for the static constexprs declared in the .H because of ODR-used
// fields<DDR5, BASE_CNFG>

// Note: Spacing out bytes a bit to hopefully reduce merge conflicts
//////////////////////////////////////
//// Bytes 0-18: prior to timings
//////////////////////////////////////
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::HYBRID;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::HYBRID_MEDIA;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::BASE_MODULE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::DIE_PER_PACKAGE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::DENSITY_PER_DIE;

//////////////////////////////////////
//// Bytes 19-93: timings
//////////////////////////////////////
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TCK_MIN_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TCK_MIN_MSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TCK_MAX_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TCK_MAX_MSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::CL_FIRST_BYTE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::CL_SECOND_BYTE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::CL_THIRD_BYTE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::CL_FOURTH_BYTE;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::CL_FIFTH_BYTE;

constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TAA_MIN_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TAA_MIN_MSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRCD_MIN_LSB;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::TRCD_MIN_MSB;

//////////////////////////////////////
//// Bytes 230-236: module information
//////////////////////////////////////
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::RANK_MIX;
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, BASE_CNFG>::PACKAGE_RANKS_PER_CHANNEL;

// fields<DDR5, DDIMM_MODULE>
constexpr mss::field_t<mss::endian::LITTLE> fields<DDR5, DDIMM_MODULE>::HI_DDR_SPEED_RATIO;

}// spd
}// mss
