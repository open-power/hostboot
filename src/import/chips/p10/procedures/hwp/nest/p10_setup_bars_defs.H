/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_setup_bars_defs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
/// @file p10_setup_bars_defs.H
/// @brief Structure/constant definitions for nest BAR initialization (FAPI2)
///

//
// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by  : HB
//

#ifndef _P10_SETUP_BARS_DEFS_H_
#define _P10_SETUP_BARS_DEFS_H_

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <map>
#include <p10_fbc_utils.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// address range size definition constants
enum p10_setup_bars_bar_size
{
    P10_SETUP_BARS_SIZE_16_TB  = 0x0000100000000000ULL,
    P10_SETUP_BARS_SIZE_8_TB   = 0x0000080000000000ULL,
    P10_SETUP_BARS_SIZE_4_TB   = 0x0000040000000000ULL,
    P10_SETUP_BARS_SIZE_2_TB   = 0x0000020000000000ULL,
    P10_SETUP_BARS_SIZE_1_TB   = 0x0000010000000000ULL,
    P10_SETUP_BARS_SIZE_512_GB = 0x0000008000000000ULL,
    P10_SETUP_BARS_SIZE_256_GB = 0x0000004000000000ULL,
    P10_SETUP_BARS_SIZE_128_GB = 0x0000002000000000ULL,
    P10_SETUP_BARS_SIZE_64_GB  = 0x0000001000000000ULL,
    P10_SETUP_BARS_SIZE_32_GB  = 0x0000000800000000ULL,
    P10_SETUP_BARS_SIZE_16_GB  = 0x0000000400000000ULL,
    P10_SETUP_BARS_SIZE_8_GB   = 0x0000000200000000ULL,
    P10_SETUP_BARS_SIZE_4_GB   = 0x0000000100000000ULL,
    P10_SETUP_BARS_SIZE_2_GB   = 0x0000000080000000ULL,
    P10_SETUP_BARS_SIZE_1_GB   = 0x0000000040000000ULL,
    P10_SETUP_BARS_SIZE_512_MB = 0x0000000020000000ULL,
    P10_SETUP_BARS_SIZE_256_MB = 0x0000000010000000ULL,
    P10_SETUP_BARS_SIZE_128_MB = 0x0000000008000000ULL,
    P10_SETUP_BARS_SIZE_64_MB  = 0x0000000004000000ULL,
    P10_SETUP_BARS_SIZE_32_MB  = 0x0000000002000000ULL,
    P10_SETUP_BARS_SIZE_16_MB  = 0x0000000001000000ULL,
    P10_SETUP_BARS_SIZE_8_MB   = 0x0000000000800000ULL,
    P10_SETUP_BARS_SIZE_4_MB   = 0x0000000000400000ULL,
    P10_SETUP_BARS_SIZE_2_MB   = 0x0000000000200000ULL,
    P10_SETUP_BARS_SIZE_1_MB   = 0x0000000000100000ULL,
    P10_SETUP_BARS_SIZE_512_KB = 0x0000000000080000ULL,
    P10_SETUP_BARS_SIZE_256_KB = 0x0000000000040000ULL,
    P10_SETUP_BARS_SIZE_128_KB = 0x0000000000020000ULL,
    P10_SETUP_BARS_SIZE_64_KB  = 0x0000000000010000ULL,
    P10_SETUP_BARS_SIZE_32_KB  = 0x0000000000008000ULL,
    P10_SETUP_BARS_SIZE_16_KB  = 0x0000000000004000ULL,
    P10_SETUP_BARS_SIZE_8_KB   = 0x0000000000002000ULL,
    P10_SETUP_BARS_SIZE_4_KB   = 0x0000000000001000ULL
};

static const p10_setup_bars_bar_size p10_setup_bars_bar_sizes[] =
{
    P10_SETUP_BARS_SIZE_16_TB,
    P10_SETUP_BARS_SIZE_8_TB,
    P10_SETUP_BARS_SIZE_4_TB,
    P10_SETUP_BARS_SIZE_2_TB,
    P10_SETUP_BARS_SIZE_1_TB,
    P10_SETUP_BARS_SIZE_512_GB,
    P10_SETUP_BARS_SIZE_256_GB,
    P10_SETUP_BARS_SIZE_128_GB,
    P10_SETUP_BARS_SIZE_64_GB,
    P10_SETUP_BARS_SIZE_32_GB,
    P10_SETUP_BARS_SIZE_16_GB,
    P10_SETUP_BARS_SIZE_8_GB,
    P10_SETUP_BARS_SIZE_4_GB,
    P10_SETUP_BARS_SIZE_2_GB,
    P10_SETUP_BARS_SIZE_1_GB,
    P10_SETUP_BARS_SIZE_512_MB,
    P10_SETUP_BARS_SIZE_256_MB,
    P10_SETUP_BARS_SIZE_128_MB,
    P10_SETUP_BARS_SIZE_64_MB,
    P10_SETUP_BARS_SIZE_32_MB,
    P10_SETUP_BARS_SIZE_16_MB,
    P10_SETUP_BARS_SIZE_8_MB,
    P10_SETUP_BARS_SIZE_4_MB,
    P10_SETUP_BARS_SIZE_2_MB,
    P10_SETUP_BARS_SIZE_1_MB,
    P10_SETUP_BARS_SIZE_512_KB,
    P10_SETUP_BARS_SIZE_256_KB,
    P10_SETUP_BARS_SIZE_128_KB,
    P10_SETUP_BARS_SIZE_64_KB,
    P10_SETUP_BARS_SIZE_32_KB,
    P10_SETUP_BARS_SIZE_16_KB,
    P10_SETUP_BARS_SIZE_8_KB,
    P10_SETUP_BARS_SIZE_4_KB
};


// address range BAR offset mask definition constants
enum p10_setup_bars_bar_offset_mask
{
    P10_SETUP_BARS_OFFSET_MASK_16_TB  = 0xFFFFFFFFFFFFFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_8_TB   = 0xFFFFF7FFFFFFFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_4_TB   = 0xFFFFF3FFFFFFFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_2_TB   = 0xFFFFF1FFFFFFFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_1_TB   = 0xFFFFF0FFFFFFFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_512_GB = 0xFFFFF07FFFFFFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_256_GB = 0xFFFFF03FFFFFFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_128_GB = 0xFFFFF01FFFFFFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_64_GB  = 0xFFFFF00FFFFFFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_32_GB  = 0xFFFFF007FFFFFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_16_GB  = 0xFFFFF003FFFFFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_8_GB   = 0xFFFFF001FFFFFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_4_GB   = 0xFFFFF000FFFFFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_2_GB   = 0xFFFFF0007FFFFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_1_GB   = 0xFFFFF0003FFFFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_512_MB = 0xFFFFF0001FFFFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_256_MB = 0xFFFFF0000FFFFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_128_MB = 0xFFFFF00007FFFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_64_MB  = 0xFFFFF00003FFFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_32_MB  = 0xFFFFF00001FFFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_16_MB  = 0xFFFFF00000FFFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_8_MB   = 0xFFFFF000007FFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_4_MB   = 0xFFFFF000003FFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_2_MB   = 0xFFFFF000001FFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_1_MB   = 0xFFFFF000000FFFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_512_KB = 0xFFFFF0000007FFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_256_KB = 0xFFFFF0000003FFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_128_KB = 0xFFFFF0000001FFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_64_KB  = 0xFFFFF0000000FFFFULL,
    P10_SETUP_BARS_OFFSET_MASK_32_KB  = 0xFFFFF00000007FFFULL,
    P10_SETUP_BARS_OFFSET_MASK_16_KB  = 0xFFFFF00000003FFFULL,
    P10_SETUP_BARS_OFFSET_MASK_8_KB   = 0xFFFFF00000001FFFULL,
    P10_SETUP_BARS_OFFSET_MASK_4_KB   = 0xFFFFF00000000FFFULL
};

static const p10_setup_bars_bar_offset_mask p10_setup_bars_bar_offset_masks[] =
{
    P10_SETUP_BARS_OFFSET_MASK_16_TB,
    P10_SETUP_BARS_OFFSET_MASK_8_TB,
    P10_SETUP_BARS_OFFSET_MASK_4_TB,
    P10_SETUP_BARS_OFFSET_MASK_2_TB,
    P10_SETUP_BARS_OFFSET_MASK_1_TB,
    P10_SETUP_BARS_OFFSET_MASK_512_GB,
    P10_SETUP_BARS_OFFSET_MASK_256_GB,
    P10_SETUP_BARS_OFFSET_MASK_128_GB,
    P10_SETUP_BARS_OFFSET_MASK_64_GB,
    P10_SETUP_BARS_OFFSET_MASK_32_GB,
    P10_SETUP_BARS_OFFSET_MASK_16_GB,
    P10_SETUP_BARS_OFFSET_MASK_8_GB,
    P10_SETUP_BARS_OFFSET_MASK_4_GB,
    P10_SETUP_BARS_OFFSET_MASK_2_GB,
    P10_SETUP_BARS_OFFSET_MASK_1_GB,
    P10_SETUP_BARS_OFFSET_MASK_512_MB,
    P10_SETUP_BARS_OFFSET_MASK_256_MB,
    P10_SETUP_BARS_OFFSET_MASK_128_MB,
    P10_SETUP_BARS_OFFSET_MASK_64_MB,
    P10_SETUP_BARS_OFFSET_MASK_32_MB,
    P10_SETUP_BARS_OFFSET_MASK_16_MB,
    P10_SETUP_BARS_OFFSET_MASK_8_MB,
    P10_SETUP_BARS_OFFSET_MASK_4_MB,
    P10_SETUP_BARS_OFFSET_MASK_2_MB,
    P10_SETUP_BARS_OFFSET_MASK_1_MB,
    P10_SETUP_BARS_OFFSET_MASK_512_KB,
    P10_SETUP_BARS_OFFSET_MASK_256_KB,
    P10_SETUP_BARS_OFFSET_MASK_128_KB,
    P10_SETUP_BARS_OFFSET_MASK_64_KB,
    P10_SETUP_BARS_OFFSET_MASK_32_KB,
    P10_SETUP_BARS_OFFSET_MASK_16_KB,
    P10_SETUP_BARS_OFFSET_MASK_8_KB,
    P10_SETUP_BARS_OFFSET_MASK_4_KB
};

// structure to represent range of FBC real address space
struct p10_setup_bars_addr_range
{
    // default constructor (mark range disabled)
    p10_setup_bars_addr_range() :
        enabled(false),
        base_addr(0),
        size(0)
    {
    }

    // constructor
    p10_setup_bars_addr_range(
        const uint64_t range_base_addr,
        const uint64_t range_size) :
        enabled(range_size != 0),
        base_addr(range_base_addr),
        size(range_size)
    {
    }

    // determine if region size is power of 2 aligned
    bool is_power_of_2() const
    {
        return ((size != 0) && !(size & (size - 1)));
    }

    // round region size to next largest power of 2
    void round_next_power_of_2()
    {
        size = size - 1;
        size = size | (size >> 1);
        size = size | (size >> 2);
        size = size | (size >> 4);
        size = size | (size >> 8);
        size = size | (size >> 16);
        size = size | (size >> 32);
        size = size + 1;
    }

    // return ending address of range
    uint64_t end_addr() const
    {
        return(base_addr + size - 1);
    }

    // overload operator for set usage
    bool operator<(const p10_setup_bars_addr_range& rhs) const
    {
        // both valid/invalid
        if (enabled == rhs.enabled)
        {
            return (base_addr < rhs.base_addr);
        }

        return rhs.enabled;
    }

    // check for adjacent/abutting ranges
    bool abuts(const p10_setup_bars_addr_range& range_compare) const
    {
        // if either range is disabled, return false
        return(enabled &&
               range_compare.enabled &&
               !(this->overlaps(range_compare)) &&
               ((base_addr == (range_compare.end_addr() + 1)) ||
                ((end_addr() + 1) == range_compare.base_addr)));
    }

    // check for overlapping ranges
    bool overlaps(const p10_setup_bars_addr_range& range_compare) const
    {
        // if either range is disabled, consider them non-overlapping
        return(enabled &&
               range_compare.enabled &&
               (base_addr <= range_compare.end_addr()) &&
               (end_addr() >= range_compare.base_addr));
    }

    // merge two ranges (span breadth of both ranges)
    void merge(const p10_setup_bars_addr_range& range_new)
    {
        // if range is disabled, set values to track those of new
        // range (which may also be disabled)
        if (!enabled)
        {
            enabled = range_new.enabled;
            base_addr = range_new.base_addr;
            size = range_new.size;
        }
        // if new range is disabled, leave as-is
        // otherwise merge two valid ranges
        else if (range_new.enabled)
        {
            uint64_t new_start_addr;
            uint64_t new_end_addr;

            // calculate new base address (smaller of the two start addresses)
            if (base_addr < range_new.base_addr)
            {
                new_start_addr = base_addr;
            }
            else
            {
                new_start_addr = range_new.base_addr;
            }

            // calculate new end address (larger of the two end addresses)
            if (end_addr() > range_new.end_addr())
            {
                new_end_addr = end_addr();
            }
            else
            {
                new_end_addr = range_new.end_addr();
            }

            // set new range values
            base_addr = new_start_addr;
            size = (new_end_addr - new_start_addr + 1);
        }
    }

    // check that if region size aligns exactly to base address range
    // (i.e., no overlap between BAR and size)
    bool is_aligned() const
    {
        return ((base_addr & (size - 1)) == 0x0ULL);
    }

    // does range lie completely within FBC address range?
    bool is_in_fbc_range() const
    {
        return ((base_addr  < P10_FBC_UTILS_FBC_MAX_ADDRESS) &&
                (end_addr() < P10_FBC_UTILS_FBC_MAX_ADDRESS));
    }

    // utility function to display address range information
    void print() const
    {
        FAPI_DBG("%s :: [ %016llX-%016llX ]",
                 (enabled) ? ("E") : ("D"),
                 base_addr,
                 end_addr());
    }

    bool enabled;
    uint64_t base_addr;
    uint64_t size;
};


#endif //_P10_SETUP_BARS_DEFS_H_
