/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mcbist/gen_mss_mcbist_patterns.H $ */
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
/// @file gen_mss_mcbist_patterns.H
/// @brief Static definition of MCBIST patterns
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_GEN_MCBIST_PATTERNS_
#define _MSS_GEN_MCBIST_PATTERNS_

#include <vector>

namespace mss
{
namespace mcbist
{

/// Memory diagnostic Pattern indexes.
// Why not an enum? I want to do math on them to generate a proper index in to a vector of
// patterns and enums really don't like that.
// Couple of extra symbols in here to keep things easy if desired
constexpr uint64_t PATTERN_ZEROS = 0;
constexpr uint64_t PATTERN_0 = PATTERN_ZEROS;
constexpr uint64_t PATTERN_ONES = 1;
constexpr uint64_t PATTERN_1 = PATTERN_ONES;
constexpr uint64_t PATTERN_2 = 2;
constexpr uint64_t PATTERN_3 = 3;
constexpr uint64_t PATTERN_4 = 4;
constexpr uint64_t PATTERN_5 = 5;
constexpr uint64_t PATTERN_6 = 6;
constexpr uint64_t PATTERN_7 = 7;
constexpr uint64_t PATTERN_8 = 8;
constexpr uint64_t PATTERN_9 = 9;
constexpr uint64_t PATTERN_10 = 10;
constexpr uint64_t PATTERN_RANDOM = PATTERN_8;
constexpr uint64_t LAST_PATTERN = PATTERN_10;

// Don't mess with the patterns
constexpr uint64_t NO_PATTERN = LAST_PATTERN + 1;

//Pattern references for the 24b random data pattern seeds
constexpr uint64_t MAX_NUM_RANDOM24_SEEDS = 3;
constexpr uint64_t RANDOM24_SEEDS_0 = 0;
constexpr uint64_t RANDOM24_SEEDS_1 = 1;
constexpr uint64_t RANDOM24_SEEDS_2 = 2;
constexpr uint64_t RANDOM24_SEEDS_3 = 3;
constexpr uint64_t LAST_RANDOM24_SEEDS = RANDOM24_SEEDS_3;
constexpr uint64_t NO_RANDOM24_SEEDS = LAST_RANDOM24_SEEDS + 1;

//Pattern references for the 24b random data pattern seeds
constexpr uint64_t MAX_NUM_RANDOM24_MAPS = 9;
constexpr uint64_t RANDOM24_SEED_MAP_0 = 0;
constexpr uint64_t RANDOM24_SEED_MAP_1 = 1;
constexpr uint64_t LAST_RANDOM24_SEED_MAP = RANDOM24_SEED_MAP_1;
constexpr uint64_t NO_RANDOM24_SEED_MAP = LAST_RANDOM24_SEED_MAP + 1;
constexpr uint64_t RANDOM24_SEED_MAP_FIELD_LEN = 4;


/// Vector of cache lines, separated in to two 64B chunks
using cache_line = std::pair<uint64_t, uint64_t> ;
using pattern = std::vector< cache_line > ;
extern const std::vector< pattern > patterns;

// Vector of 24b random data seeds
using random24_data_seed = std::vector< uint64_t > ;
extern const std::vector< random24_data_seed > random24_data_seeds;

// Vector of 24b random data seed maps
using random24_seed_map = std::vector< uint64_t >;
extern const std::vector< random24_seed_map > random24_seed_maps;

}// mcbist

}// mss
#endif
