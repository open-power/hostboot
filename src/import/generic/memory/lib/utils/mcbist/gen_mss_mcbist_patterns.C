/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mcbist/gen_mss_mcbist_patterns.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file gen_mss_mcbist_patterns.C
/// @brief Static definition of MCBIST patterns
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <vector>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_patterns.H>

namespace mss
{

namespace mcbist
{

/// Vector of cache lines, seaprated in to two 64B chunks
// TK Real patterns from Marc representing the proper bits for ECC checking
const std::vector< pattern > patterns =
{
    // Pattern index 0 (Pattern 1 is this inverted)
    {
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
    },

    // Pattern index 2 (Pattern 3 is this inverted)
    {
        {0x5555555555555555, 0x5555555555555555},
        {0xAAAAAAAAAAAAAAAA, 0xAAAAAAAAAAAAAAAA},
        {0x5555555555555555, 0x5555555555555555},
        {0xAAAAAAAAAAAAAAAA, 0xAAAAAAAAAAAAAAAA},
        {0x5555555555555555, 0x5555555555555555},
        {0xAAAAAAAAAAAAAAAA, 0xAAAAAAAAAAAAAAAA},
        {0x5555555555555555, 0x5555555555555555},
        {0xAAAAAAAAAAAAAAAA, 0xAAAAAAAAAAAAAAAA},
    },

    // Pattern index 4 (Pattern 5 is this inverted)
    {
        {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF},
        {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF},
        {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
    },

    // Pattern index 6 (Pattern 7 is this inverted)
    {
        {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF},
        {0x0000000000000000, 0x0000000000000000},
        {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF},
        {0x0000000000000000, 0x0000000000000000},
        {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF},
        {0x0000000000000000, 0x0000000000000000},
        {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF},
        {0x0000000000000000, 0x0000000000000000},
    },

    // Pattern index 8 Random Seed
    {
        {0x1234567887654321, 0x8765432112345678},
        {0x1234567887654321, 0x8765432112345678},
        {0x1234567887654321, 0x8765432112345678},
        {0x1234567887654321, 0x8765432112345678},
        {0x1234567887654321, 0x8765432112345678},
        {0x1234567887654321, 0x8765432112345678},
        {0x1234567887654321, 0x8765432112345678},
        {0x1234567887654321, 0x8765432112345678},
    },

    // Pattern index 10 (Pattern 11 is this inverted), MPR pattern
    {
        {0x0000000000000000, 0xFFFFFFFFFFFFFFFF},
        {0x0000000000000000, 0xFFFFFFFFFFFFFFFF},
        {0x0000000000000000, 0xFFFFFFFFFFFFFFFF},
        {0x0000000000000000, 0xFFFFFFFFFFFFFFFF},
        {0x0000000000000000, 0xFFFFFFFFFFFFFFFF},
        {0x0000000000000000, 0xFFFFFFFFFFFFFFFF},
        {0x0000000000000000, 0xFFFFFFFFFFFFFFFF},
        {0x0000000000000000, 0xFFFFFFFFFFFFFFFF},
    },
};

// TK Want a new RC for random 24
/// Vector of 24b random data seeds
const std::vector< random24_data_seed > random24_data_seeds =
{
    // 24 Bit Pattern index 0 Matches user input defaults
    {   {0x010203},
        {0x040506},
        {0x070809},
    },

    // 24 Bit Pattern index 2 (Pattern 3 is this inverted)
    {   {0x112233},
        {0x445566},
        {0x778899},
    },

};


/// Vector of 24b random data seed mappings
//  Not sure how many mapping we will want, for now it should be sufficient to
//  have all bytes point to a different LFSR or all bytes point to the same LFSR
const std::vector< random24_seed_map > random24_seed_maps =
{
    // 8 Bit Pattern index 0
    // This selection maps every data byte to a different random LFSR
    {   {0x0},
        {0x1},
        {0x2},
        {0x3},
        {0x4},
        {0x5},
        {0x6},
        {0x7},
        {0x8},
    },

    // 8 Bit Pattern index 1
    // This selection maps every data byte to random LFSR 0
    {   {0x0},
        {0x0},
        {0x0},
        {0x0},
        {0x0},
        {0x0},
        {0x0},
        {0x0},
        {0x0},
    },

};

} //namespace mcbist
} //namespace mss
