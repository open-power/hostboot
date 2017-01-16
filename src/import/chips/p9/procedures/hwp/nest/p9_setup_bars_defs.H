/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_setup_bars_defs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file p9_setup_bars_defs.H
/// @brief Structure/constant definitions for p9_setup_bars (FAPI2)
///

// *HWP HWP Owner: Joe McGill jmcgill@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB

#ifndef _P9_SETUP_BARS_DEFS_H_
#define _P9_SETUP_BARS_DEFS_H_

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <map>
#include <fapi2.H>
#include <p9_fbc_utils.H>
#include <p9_misc_scom_addresses.H>


//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// address range size definition constants
enum p9_setup_bars_bar_size
{
    P9_SETUP_BARS_SIZE_8_TB   = 0x0000080000000000ULL,
    P9_SETUP_BARS_SIZE_4_TB   = 0x0000040000000000ULL,
    P9_SETUP_BARS_SIZE_2_TB   = 0x0000020000000000ULL,
    P9_SETUP_BARS_SIZE_1_TB   = 0x0000010000000000ULL,
    P9_SETUP_BARS_SIZE_512_GB = 0x0000008000000000ULL,
    P9_SETUP_BARS_SIZE_256_GB = 0x0000004000000000ULL,
    P9_SETUP_BARS_SIZE_128_GB = 0x0000002000000000ULL,
    P9_SETUP_BARS_SIZE_64_GB  = 0x0000001000000000ULL,
    P9_SETUP_BARS_SIZE_32_GB  = 0x0000000800000000ULL,
    P9_SETUP_BARS_SIZE_16_GB  = 0x0000000400000000ULL,
    P9_SETUP_BARS_SIZE_8_GB   = 0x0000000200000000ULL,
    P9_SETUP_BARS_SIZE_4_GB   = 0x0000000100000000ULL,
    P9_SETUP_BARS_SIZE_2_GB   = 0x0000000080000000ULL,
    P9_SETUP_BARS_SIZE_1_GB   = 0x0000000040000000ULL,
    P9_SETUP_BARS_SIZE_512_MB = 0x0000000020000000ULL,
    P9_SETUP_BARS_SIZE_256_MB = 0x0000000010000000ULL,
    P9_SETUP_BARS_SIZE_128_MB = 0x0000000008000000ULL,
    P9_SETUP_BARS_SIZE_64_MB  = 0x0000000004000000ULL,
    P9_SETUP_BARS_SIZE_32_MB  = 0x0000000002000000ULL,
    P9_SETUP_BARS_SIZE_16_MB  = 0x0000000001000000ULL,
    P9_SETUP_BARS_SIZE_8_MB   = 0x0000000000800000ULL,
    P9_SETUP_BARS_SIZE_4_MB   = 0x0000000000400000ULL,
    P9_SETUP_BARS_SIZE_2_MB   = 0x0000000000200000ULL,
    P9_SETUP_BARS_SIZE_1_MB   = 0x0000000000100000ULL,
    P9_SETUP_BARS_SIZE_512_KB = 0x0000000000080000ULL,
    P9_SETUP_BARS_SIZE_256_KB = 0x0000000000040000ULL,
    P9_SETUP_BARS_SIZE_128_KB = 0x0000000000020000ULL,
    P9_SETUP_BARS_SIZE_64_KB  = 0x0000000000010000ULL,
    P9_SETUP_BARS_SIZE_32_KB  = 0x0000000000008000ULL,
    P9_SETUP_BARS_SIZE_16_KB  = 0x0000000000004000ULL,
    P9_SETUP_BARS_SIZE_8_KB   = 0x0000000000002000ULL,
    P9_SETUP_BARS_SIZE_4_KB   = 0x0000000000001000ULL
};

// address range BAR offset mask definition constants
enum p9_setup_bars_bar_offset_mask
{
    P9_SETUP_BARS_OFFSET_MASK_4_TB   = 0xFFFFFFFFFFFFFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_2_TB   = 0xFFFFFDFFFFFFFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_1_TB   = 0xFFFFFCFFFFFFFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_512_GB = 0xFFFFFC7FFFFFFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_256_GB = 0xFFFFFC3FFFFFFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_128_GB = 0xFFFFFC1FFFFFFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_64_GB  = 0xFFFFFC0FFFFFFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_32_GB  = 0xFFFFFC07FFFFFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_16_GB  = 0xFFFFFC03FFFFFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_8_GB   = 0xFFFFFC01FFFFFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_4_GB   = 0xFFFFFC00FFFFFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_2_GB   = 0xFFFFFC007FFFFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_1_GB   = 0xFFFFFC003FFFFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_512_MB = 0xFFFFFC001FFFFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_256_MB = 0xFFFFFC000FFFFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_128_MB = 0xFFFFFC0007FFFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_64_MB  = 0xFFFFFC0003FFFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_32_MB  = 0xFFFFFC0001FFFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_16_MB  = 0xFFFFFC0000FFFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_8_MB   = 0xFFFFFC00007FFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_4_MB   = 0xFFFFFC00003FFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_2_MB   = 0xFFFFFC00001FFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_1_MB   = 0xFFFFFC00000FFFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_512_KB = 0xFFFFFC000007FFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_256_KB = 0xFFFFFC000003FFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_128_KB = 0xFFFFFC000001FFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_64_KB  = 0xFFFFFC000000FFFFULL,
    P9_SETUP_BARS_OFFSET_MASK_32_KB  = 0xFFFFFC0000007FFFULL,
    P9_SETUP_BARS_OFFSET_MASK_16_KB  = 0xFFFFFC0000003FFFULL,
    P9_SETUP_BARS_OFFSET_MASK_8_KB   = 0xFFFFFC0000001FFFULL,
    P9_SETUP_BARS_OFFSET_MASK_4_KB   = 0xFFFFFC0000000FFFULL
};

// define set of valid MCD group sizes/encodings
// MCD group configuration register base address field (33:63) covers RA 8:38
const uint64_t P9_SETUP_BARS_MCD_BASE_ADDR_SHIFT = 25;

// MCD group configuration register size field (13:29) masks RA 22:38
// (max 4 TB / min 32 MB)
struct p9_setup_bars_mcd_grp_size
{
    static std::map<uint64_t, uint64_t> create_map()
    {
        std::map<uint64_t, uint64_t> m;
        m[P9_SETUP_BARS_SIZE_32_MB]  = 0x00000;
        m[P9_SETUP_BARS_SIZE_64_MB]  = 0x00001;
        m[P9_SETUP_BARS_SIZE_128_MB] = 0x00003;
        m[P9_SETUP_BARS_SIZE_256_MB] = 0x00007;
        m[P9_SETUP_BARS_SIZE_512_MB] = 0x0000F;
        m[P9_SETUP_BARS_SIZE_1_GB]   = 0x0001F;
        m[P9_SETUP_BARS_SIZE_2_GB]   = 0x0003F;
        m[P9_SETUP_BARS_SIZE_4_GB]   = 0x0007F;
        m[P9_SETUP_BARS_SIZE_8_GB]   = 0x000FF;
        m[P9_SETUP_BARS_SIZE_16_GB]  = 0x001FF;
        m[P9_SETUP_BARS_SIZE_32_GB]  = 0x003FF;
        m[P9_SETUP_BARS_SIZE_64_GB]  = 0x007FF;
        m[P9_SETUP_BARS_SIZE_128_GB] = 0x00FFF;
        m[P9_SETUP_BARS_SIZE_256_GB] = 0x01FFF;
        m[P9_SETUP_BARS_SIZE_512_GB] = 0x03FFF;
        m[P9_SETUP_BARS_SIZE_1_TB]   = 0x07FFF;
        m[P9_SETUP_BARS_SIZE_2_TB]   = 0x0FFFF;
        m[P9_SETUP_BARS_SIZE_4_TB]   = 0x1FFFF;
        return m;
    }
    static const std::map<uint64_t, uint64_t> xlate_map;
};

// structure to represent chip configuration information
struct p9_setup_bars_chip_info
{
    uint8_t fbc_group_id;
    uint8_t fbc_chip_id;
    uint64_t base_address_nm[2];
    uint64_t base_address_m;
    uint64_t base_address_mmio;
};

// structure to represent range of FBC real address space
struct p9_setup_bars_addr_range
{
    // default constructor (mark range disabled)
    p9_setup_bars_addr_range() :
        enabled(false),
        base_addr(0),
        size(0)
    {
    }

    // constructor
    p9_setup_bars_addr_range(
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

    // check for overlapping ranges
    bool overlaps(const p9_setup_bars_addr_range& range_compare) const
    {
        // if either range is disabled, consider them non-overlapping
        return(enabled &&
               range_compare.enabled &&
               (base_addr <= range_compare.end_addr()) &&
               (end_addr() >= range_compare.base_addr));
    }

    // merge two ranges (span breadth of both ranges)
    void merge(const p9_setup_bars_addr_range& range_new)
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
        return ((base_addr < P9_FBC_UTILS_FBC_MAX_ADDRESS) &&
                (end_addr() < P9_FBC_UTILS_FBC_MAX_ADDRESS));
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


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//
// MCD
//

const uint32_t MCD_RECOVERY_PACE_RATE = 0x5;
const uint32_t MCD_RECOVERY_RTY_COUNT = 0xF;
const uint32_t MCD_RECOVERY_VG_COUNT = 0x7FFF;
const uint32_t MCD_VGC_AVAIL_GROUPS = 0xFFFF;

const uint64_t MCD_FIR_ACTION0 = 0x0000000000000000ULL;
const uint64_t MCD_FIR_ACTION1 = 0x8000000000000000ULL;
const uint64_t MCD_FIR_MASK    = 0x4C70000000000000ULL;


//
// NPU
//

// NPU BAR address constants
const uint8_t NPU_NUM_BAR_SHADOWS = 4;
const uint64_t NPU_BAR_BASE_ADDR_MASK = 0x0001FFFFFFFFFFFFULL;
const uint64_t NPU_BAR_ADDR_SHIFT = 12;

const uint64_t NPU_PHY0_BAR_REGS[NPU_NUM_BAR_SHADOWS] =
{
    PU_NPU0_SM0_PHY_BAR,
    PU_NPU0_SM1_PHY_BAR,
    PU_NPU0_SM2_PHY_BAR,
    PU_NPU0_SM3_PHY_BAR
};

const uint64_t NPU_PHY0_BAR_REGS_DD2[NPU_NUM_BAR_SHADOWS] =
{
    0x05011006,
    0x05011036,
    0x05011066,
    0x05011096
};

const uint64_t NPU_PHY1_BAR_REGS[NPU_NUM_BAR_SHADOWS] =
{
    PU_NPU1_SM0_PHY_BAR,
    PU_NPU1_SM1_PHY_BAR,
    PU_NPU1_SM2_PHY_BAR,
    PU_NPU1_SM3_PHY_BAR
};

const uint64_t NPU_PHY1_BAR_REGS_DD2[NPU_NUM_BAR_SHADOWS] =
{
    0x05011206,
    0x05011236,
    0x05011266,
    0x05011296
};

const uint64_t NPU_MMIO_BAR_REGS[NPU_NUM_BAR_SHADOWS] =
{
    PU_NPU2_SM0_PHY_BAR,
    PU_NPU2_SM1_PHY_BAR,
    PU_NPU2_SM2_PHY_BAR,
    PU_NPU2_SM3_PHY_BAR
};

const uint64_t NPU_MMIO_BAR_REGS_DD2[NPU_NUM_BAR_SHADOWS] =
{
    0x05011406,
    0x05011436,
    0x05011466,
    0x05011496
};

#endif //_P9_SETUP_BARS_DEFS_H_
