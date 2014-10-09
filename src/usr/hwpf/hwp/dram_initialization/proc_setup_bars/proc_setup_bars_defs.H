/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/proc_setup_bars/proc_setup_bars_defs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
// $Id: proc_setup_bars_defs.H,v 1.1 2014/08/05 20:43:46 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_setup_bars_defs.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** ***
// *|
// *! TITLE       : proc_setup_bars_defs.H
// *! DESCRIPTION : Structure/constant definitions for proc_setup_bars HWP (FAPI)
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *!
// *! ADDITIONAL COMMENTS:
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_SETUP_BARS_DEFS_H_
#define _PROC_SETUP_BARS_DEFS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_setup_bars.H"

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// address range size definition constants
const uint64_t PROC_SETUP_BARS_SIZE_1_PB   = 0x0004000000000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_512_TB = 0x0002000000000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_256_TB = 0x0001000000000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_128_TB = 0x0000800000000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_64_TB  = 0x0000400000000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_32_TB  = 0x0000200000000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_16_TB  = 0x0000100000000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_8_TB   = 0x0000080000000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_4_TB   = 0x0000040000000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_2_TB   = 0x0000020000000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_1_TB   = 0x0000010000000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_512_GB = 0x0000008000000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_256_GB = 0x0000004000000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_128_GB = 0x0000002000000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_64_GB  = 0x0000001000000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_32_GB  = 0x0000000800000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_16_GB  = 0x0000000400000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_8_GB   = 0x0000000200000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_4_GB   = 0x0000000100000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_2_GB   = 0x0000000080000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_1_GB   = 0x0000000040000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_512_MB = 0x0000000020000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_256_MB = 0x0000000010000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_128_MB = 0x0000000008000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_64_MB  = 0x0000000004000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_32_MB  = 0x0000000002000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_16_MB  = 0x0000000001000000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_8_MB   = 0x0000000000800000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_4_MB   = 0x0000000000400000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_2_MB   = 0x0000000000200000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_1_MB   = 0x0000000000100000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_512_KB = 0x0000000000080000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_256_KB = 0x0000000000040000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_128_KB = 0x0000000000020000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_64_KB  = 0x0000000000010000ULL;
const uint64_t PROC_SETUP_BARS_SIZE_4_KB   = 0x0000000000001000ULL;

// memory (non-mirrored/mirrored) constants
const uint8_t PROC_SETUP_BARS_NUM_NON_MIRRORED_RANGES = 8;
const uint8_t PROC_SETUP_BARS_NUM_MIRRORED_RANGES = 4;

// PCIe unit contstants
const uint8_t PROC_SETUP_BARS_PCIE_NUM_UNITS = 3;
const uint8_t PROC_SETUP_BARS_PCIE_RANGES_PER_UNIT = 3;


//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// structure to represent range of FBC real address space
struct proc_setup_bars_addr_range
{
    // default constructor (mark range disabled)
    proc_setup_bars_addr_range() :
        enabled(false),
        base_addr(0),
        size(0)
    {
    }

    // constructor
    proc_setup_bars_addr_range(
        const uint64_t& range_base_addr,
        const uint64_t& range_size) :
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
    bool overlaps(const proc_setup_bars_addr_range& range_compare) const
    {
        // if either range is disabled, consider them non-overlapping
        return(enabled &&
               range_compare.enabled &&
               (base_addr <= range_compare.end_addr()) &&
               (end_addr() >= range_compare.base_addr));
    }

    // merge two ranges (span breadth of both ranges)
    void merge(const proc_setup_bars_addr_range& range_new)
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
        return ((base_addr < PROC_FAB_SMP_MAX_ADDRESS) &&
                (end_addr() < PROC_FAB_SMP_MAX_ADDRESS));
    }

    // utility function to display address range information
    void print() const
    {
        FAPI_DBG("proc_setup_bars_print_addr_range: %s :: [ %016llX-%016llX ]",
                 (enabled)?("E"):("D"),
                 base_addr,
                 end_addr());
    }

    bool enabled;
    uint64_t base_addr;
    uint64_t size;
};

// structure to represent fabric connectivty & properites for a single chip
// in the SMP topology
struct proc_setup_bars_smp_chip
{
    // associated HWP input structure
    proc_setup_bars_proc_chip* chip;

    // chip properties/attributes:
    // fabric chip/node ID
    proc_fab_smp_chip_id chip_id;
    proc_fab_smp_node_id node_id;
    // partial good attributes
    bool nx_enabled;
    bool pcie_enabled;
    // select for PCIe/DSMP mux (one per link)
    bool pcie_not_f_link[PROC_FAB_SMP_NUM_F_LINKS];
    // real address ranges covered by resources on this chip
    proc_setup_bars_addr_range non_mirrored_range;
    proc_setup_bars_addr_range mirrored_range;
    proc_setup_bars_addr_range foreign_near_ranges[PROC_FAB_SMP_NUM_F_LINKS];
    proc_setup_bars_addr_range foreign_far_ranges[PROC_FAB_SMP_NUM_F_LINKS];
    proc_setup_bars_addr_range psi_range;
    proc_setup_bars_addr_range fsp_range;
    proc_setup_bars_addr_range fsp_mmio_mask_range;
    proc_setup_bars_addr_range intp_range;
    proc_setup_bars_addr_range nx_mmio_range;
    proc_setup_bars_addr_range as_mmio_range;
    proc_setup_bars_addr_range pcie_ranges[PROC_SETUP_BARS_PCIE_NUM_UNITS][PROC_SETUP_BARS_PCIE_RANGES_PER_UNIT];
};

// structure to represent properties for a single node in the SMP topology
struct proc_setup_bars_smp_node
{
    // chips which reside in this node
    std::map<proc_fab_smp_chip_id, proc_setup_bars_smp_chip> chips;

    // node properties/attributes:
    // fabric node ID
    proc_fab_smp_node_id node_id;
    // real address ranges covered for mirrored & non-mirrored regions
    // (considering all chips in node)
    proc_setup_bars_addr_range non_mirrored_range;
    proc_setup_bars_addr_range mirrored_range;
};

// structure to represent collection of nodes in SMP topology
struct proc_setup_bars_smp_system
{
    // nodes which reside in this SMP
    std::map<proc_fab_smp_node_id, proc_setup_bars_smp_node> nodes;
};

// define set of shared design non-foreign BAR sizes
struct proc_setup_bars_nf_bar_size
{
    static std::map<uint64_t, uint64_t> create_map()
    {
        std::map<uint64_t, uint64_t> m;
        m[PROC_SETUP_BARS_SIZE_64_TB]  = 0x3FFFULL;
        m[PROC_SETUP_BARS_SIZE_32_TB]  = 0x1FFFULL;
        m[PROC_SETUP_BARS_SIZE_16_TB]  = 0x0FFFULL;
        m[PROC_SETUP_BARS_SIZE_8_TB]   = 0x07FFULL;
        m[PROC_SETUP_BARS_SIZE_4_TB]   = 0x03FFULL;
        m[PROC_SETUP_BARS_SIZE_2_TB]   = 0x01FFULL;
        m[PROC_SETUP_BARS_SIZE_1_TB]   = 0x00FFULL;
        m[PROC_SETUP_BARS_SIZE_512_GB] = 0x007FULL;
        m[PROC_SETUP_BARS_SIZE_256_GB] = 0x003FULL;
        m[PROC_SETUP_BARS_SIZE_128_GB] = 0x001FULL;
        m[PROC_SETUP_BARS_SIZE_64_GB]  = 0x000FULL;
        m[PROC_SETUP_BARS_SIZE_32_GB]  = 0x0007ULL;
        m[PROC_SETUP_BARS_SIZE_16_GB]  = 0x0003ULL;
        m[PROC_SETUP_BARS_SIZE_8_GB]   = 0x0001ULL;
        m[PROC_SETUP_BARS_SIZE_4_GB]   = 0x0000ULL;
        return m;
    }
    static const std::map<uint64_t, uint64_t> xlate_map;
};

// define set of shared design foreign BAR sizes
struct proc_setup_bars_f_bar_size
{
    static std::map<uint64_t, uint64_t> create_map()
    {
        std::map<uint64_t, uint64_t> m;
        m[PROC_SETUP_BARS_SIZE_8_TB]   = 0x7FFFFULL;
        m[PROC_SETUP_BARS_SIZE_4_TB]   = 0x3FFFFULL;
        m[PROC_SETUP_BARS_SIZE_2_TB]   = 0x1FFFFULL;
        m[PROC_SETUP_BARS_SIZE_1_TB]   = 0x0FFFFULL;
        m[PROC_SETUP_BARS_SIZE_512_GB] = 0x07FFFULL;
        m[PROC_SETUP_BARS_SIZE_256_GB] = 0x03FFFULL;
        m[PROC_SETUP_BARS_SIZE_128_GB] = 0x01FFFULL;
        m[PROC_SETUP_BARS_SIZE_64_GB]  = 0x00FFFULL;
        m[PROC_SETUP_BARS_SIZE_32_GB]  = 0x007FFULL;
        m[PROC_SETUP_BARS_SIZE_16_GB]  = 0x003FFULL;
        m[PROC_SETUP_BARS_SIZE_8_GB]   = 0x001FFULL;
        m[PROC_SETUP_BARS_SIZE_4_GB]   = 0x000FFULL;
        m[PROC_SETUP_BARS_SIZE_2_GB]   = 0x0007FULL;
        m[PROC_SETUP_BARS_SIZE_1_GB]   = 0x0003FULL;
        m[PROC_SETUP_BARS_SIZE_512_MB] = 0x0001FULL;
        m[PROC_SETUP_BARS_SIZE_256_MB] = 0x0000FULL;
        m[PROC_SETUP_BARS_SIZE_128_MB] = 0x00007ULL;
        m[PROC_SETUP_BARS_SIZE_64_MB]  = 0x00003ULL;
        m[PROC_SETUP_BARS_SIZE_32_MB]  = 0x00001ULL;
        m[PROC_SETUP_BARS_SIZE_16_MB]  = 0x00000ULL;
        return m;
    }
    static const std::map<uint64_t, uint64_t> xlate_map;
};

// define set of FSP BAR sizes
struct proc_setup_bars_fsp_bar_size
{
    static std::map<uint64_t, uint64_t> create_map()
    {
        std::map<uint64_t, uint64_t> m;
        m[PROC_SETUP_BARS_SIZE_4_GB]   = 0x000ULL;
        m[PROC_SETUP_BARS_SIZE_2_GB]   = 0x800ULL;
        m[PROC_SETUP_BARS_SIZE_1_GB]   = 0xC00ULL;
        m[PROC_SETUP_BARS_SIZE_512_MB] = 0xE00ULL;
        m[PROC_SETUP_BARS_SIZE_256_MB] = 0xF00ULL;
        m[PROC_SETUP_BARS_SIZE_128_MB] = 0xF80ULL;
        m[PROC_SETUP_BARS_SIZE_64_MB]  = 0xFC0ULL;
        m[PROC_SETUP_BARS_SIZE_32_MB]  = 0xFE0ULL;
        m[PROC_SETUP_BARS_SIZE_16_MB]  = 0xFF0ULL;
        m[PROC_SETUP_BARS_SIZE_8_MB]   = 0xFF8ULL;
        m[PROC_SETUP_BARS_SIZE_4_MB]   = 0xFFCULL;
        m[PROC_SETUP_BARS_SIZE_2_MB]   = 0xFFEULL;
        m[PROC_SETUP_BARS_SIZE_1_MB]   = 0xFFFULL;
        return m;
    }
    static const std::map<uint64_t, uint64_t> xlate_map;
};

// define set of FSP MMIO mask sizes
struct proc_setup_bars_fsp_mmio_mask_size
{
    static std::map<uint64_t, uint64_t> create_map()
    {
        std::map<uint64_t, uint64_t> m;
        m[PROC_SETUP_BARS_SIZE_4_GB]   = 0xF;
        m[PROC_SETUP_BARS_SIZE_2_GB]   = 0x7;
        m[PROC_SETUP_BARS_SIZE_1_GB]   = 0x3;
        m[PROC_SETUP_BARS_SIZE_512_MB] = 0x1;
        m[PROC_SETUP_BARS_SIZE_256_MB] = 0x0;
        return m;
    }
    static const std::map<uint64_t, uint64_t> xlate_map;
};

// define set of NX MMIO mask sizes
struct proc_setup_bars_nx_mmio_bar_size
{
    static std::map<uint64_t, uint64_t> create_map()
    {
        std::map<uint64_t, uint64_t> m;
        m[PROC_SETUP_BARS_SIZE_16_GB] = 0x2;
        m[PROC_SETUP_BARS_SIZE_16_MB] = 0x4;
        m[PROC_SETUP_BARS_SIZE_1_MB]  = 0x3;
        m[PROC_SETUP_BARS_SIZE_64_KB] = 0x1;
        m[PROC_SETUP_BARS_SIZE_4_KB]  = 0x0;
        return m;
    }
    static const std::map<uint64_t, uint64_t> xlate_map;
};

// define set of AS MMIO mask sizes
struct proc_setup_bars_as_mmio_bar_size
{
    static std::map<uint64_t, uint64_t> create_map()
    {
        std::map<uint64_t, uint64_t> m;
        m[PROC_SETUP_BARS_SIZE_2_MB]   = 0x3;
        m[PROC_SETUP_BARS_SIZE_1_MB]   = 0x2;
        m[PROC_SETUP_BARS_SIZE_512_KB] = 0x1;
        m[PROC_SETUP_BARS_SIZE_256_KB] = 0x0;
        return m;
    }
    static const std::map<uint64_t, uint64_t> xlate_map;
};

// define set of HCA BAR sizes
struct proc_setup_bars_hca_nm_bar_size
{
    static std::map<uint64_t, uint64_t> create_map()
    {
        std::map<uint64_t, uint64_t> m;
        m[PROC_SETUP_BARS_SIZE_1_TB]   = 0xFFULL;
        m[PROC_SETUP_BARS_SIZE_512_GB] = 0x7FULL;
        m[PROC_SETUP_BARS_SIZE_256_GB] = 0x3FULL;
        m[PROC_SETUP_BARS_SIZE_128_GB] = 0x1FULL;
        m[PROC_SETUP_BARS_SIZE_64_GB]  = 0x0FULL;
        m[PROC_SETUP_BARS_SIZE_32_GB]  = 0x07ULL;
        m[PROC_SETUP_BARS_SIZE_16_GB]  = 0x03ULL;
        m[PROC_SETUP_BARS_SIZE_8_GB]   = 0x01ULL;
        m[PROC_SETUP_BARS_SIZE_4_GB]   = 0x00ULL;
        return m;
    }
    static const std::map<uint64_t, uint64_t> xlate_map;
};

// define set of MCD BAR sizes
struct proc_setup_bars_mcd_bar_size
{
    static std::map<uint64_t, uint64_t> create_map()
    {
        std::map<uint64_t, uint64_t> m;
        m[PROC_SETUP_BARS_SIZE_32_TB]  = 0x1FFFFFULL;
        m[PROC_SETUP_BARS_SIZE_16_TB]  = 0x0FFFFFULL;
        m[PROC_SETUP_BARS_SIZE_8_TB]   = 0x07FFFFULL;
        m[PROC_SETUP_BARS_SIZE_4_TB]   = 0x03FFFFULL;
        m[PROC_SETUP_BARS_SIZE_2_TB]   = 0x01FFFFULL;
        m[PROC_SETUP_BARS_SIZE_1_TB]   = 0x00FFFFULL;
        m[PROC_SETUP_BARS_SIZE_512_GB] = 0x007FFFULL;
        m[PROC_SETUP_BARS_SIZE_256_GB] = 0x003FFFULL;
        m[PROC_SETUP_BARS_SIZE_128_GB] = 0x001FFFULL;
        m[PROC_SETUP_BARS_SIZE_64_GB]  = 0x000FFFULL;
        m[PROC_SETUP_BARS_SIZE_32_GB]  = 0x0007FFULL;
        m[PROC_SETUP_BARS_SIZE_16_GB]  = 0x0003FFULL;
        m[PROC_SETUP_BARS_SIZE_8_GB]   = 0x0001FFULL;
        m[PROC_SETUP_BARS_SIZE_4_GB]   = 0x0000FFULL;
        m[PROC_SETUP_BARS_SIZE_2_GB]   = 0x00007FULL;
        m[PROC_SETUP_BARS_SIZE_1_GB]   = 0x00003FULL;
        m[PROC_SETUP_BARS_SIZE_512_MB] = 0x00001FULL;
        m[PROC_SETUP_BARS_SIZE_256_MB] = 0x00000FULL;
        m[PROC_SETUP_BARS_SIZE_128_MB] = 0x000007ULL;
        m[PROC_SETUP_BARS_SIZE_64_MB]  = 0x000003ULL;
        m[PROC_SETUP_BARS_SIZE_32_MB]  = 0x000001ULL;
        m[PROC_SETUP_BARS_SIZE_16_MB]  = 0x000000ULL;
        return m;
    }
    static const std::map<uint64_t, uint64_t> xlate_map;
};

// define set of PCIe MMIO BAR (BAR0/1 only) sizes
struct proc_setup_bars_pcie_bar_size
{
    static std::map<uint64_t, uint64_t> create_map()
    {
        std::map<uint64_t, uint64_t> m;
        m[PROC_SETUP_BARS_SIZE_1_PB]   = 0x000000000ULL;
        m[PROC_SETUP_BARS_SIZE_512_TB] = 0x200000000ULL;
        m[PROC_SETUP_BARS_SIZE_256_TB] = 0x300000000ULL;
        m[PROC_SETUP_BARS_SIZE_128_TB] = 0x380000000ULL;
        m[PROC_SETUP_BARS_SIZE_64_TB]  = 0x3C0000000ULL;
        m[PROC_SETUP_BARS_SIZE_32_TB]  = 0x3E0000000ULL;
        m[PROC_SETUP_BARS_SIZE_16_TB]  = 0x3F0000000ULL;
        m[PROC_SETUP_BARS_SIZE_8_TB]   = 0x3F8000000ULL;
        m[PROC_SETUP_BARS_SIZE_4_TB]   = 0x3FC000000ULL;
        m[PROC_SETUP_BARS_SIZE_2_TB]   = 0x3FE000000ULL;
        m[PROC_SETUP_BARS_SIZE_1_TB]   = 0x3FF000000ULL;
        m[PROC_SETUP_BARS_SIZE_512_GB] = 0x3FF800000ULL;
        m[PROC_SETUP_BARS_SIZE_256_GB] = 0x3FFC00000ULL;
        m[PROC_SETUP_BARS_SIZE_128_GB] = 0x3FFE00000ULL;
        m[PROC_SETUP_BARS_SIZE_64_GB]  = 0x3FFF00000ULL;
        m[PROC_SETUP_BARS_SIZE_32_GB]  = 0x3FFF80000ULL;
        m[PROC_SETUP_BARS_SIZE_16_GB]  = 0x3FFFC0000ULL;
        m[PROC_SETUP_BARS_SIZE_8_GB]   = 0x3FFFE0000ULL;
        m[PROC_SETUP_BARS_SIZE_4_GB]   = 0x3FFFF0000ULL;
        m[PROC_SETUP_BARS_SIZE_2_GB]   = 0x3FFFF8000ULL;
        m[PROC_SETUP_BARS_SIZE_1_GB]   = 0x3FFFFC000ULL;
        m[PROC_SETUP_BARS_SIZE_512_MB] = 0x3FFFFE000ULL;
        m[PROC_SETUP_BARS_SIZE_256_MB] = 0x3FFFFF000ULL;
        m[PROC_SETUP_BARS_SIZE_128_MB] = 0x3FFFFF800ULL;
        m[PROC_SETUP_BARS_SIZE_64_MB]  = 0x3FFFFFC00ULL;
        m[PROC_SETUP_BARS_SIZE_32_MB]  = 0x3FFFFFE00ULL;
        m[PROC_SETUP_BARS_SIZE_16_MB]  = 0x3FFFFFF00ULL;
        m[PROC_SETUP_BARS_SIZE_8_MB]   = 0x3FFFFFF80ULL;
        m[PROC_SETUP_BARS_SIZE_4_MB]   = 0x3FFFFFFC0ULL;
        m[PROC_SETUP_BARS_SIZE_2_MB]   = 0x3FFFFFFE0ULL;
        m[PROC_SETUP_BARS_SIZE_1_MB]   = 0x3FFFFFFF0ULL;
        m[PROC_SETUP_BARS_SIZE_512_KB] = 0x3FFFFFFF8ULL;
        m[PROC_SETUP_BARS_SIZE_256_KB] = 0x3FFFFFFFCULL;
        m[PROC_SETUP_BARS_SIZE_128_KB] = 0x3FFFFFFFEULL;
        m[PROC_SETUP_BARS_SIZE_64_KB]  = 0x3FFFFFFFFULL;
        return m;
    }
    static const std::map<uint64_t, uint64_t> xlate_map;
};

// structure to represent logical HW BAR properties
struct proc_setup_bars_bar_def
{
    // mask for implemented base address bits (1 for all non implemented bits)
    uint64_t base_addr_mask;
    // minimum/maximum supported size values
    uint64_t size_min;
    uint64_t size_max;
    // check that base address/size are aligned?
    bool check_aligned;
};

// define set of supported shift operations for aligning logical
// BAR base address to physical position in HW register
enum proc_setup_bars_shift_base
{
    PROC_SETUP_BARS_SHIFT_LEFT,
    PROC_SETUP_BARS_SHIFT_RIGHT,
    PROC_SETUP_BARS_SHIFT_NONE
};

// set of BAR/range attribute identifiers
enum proc_setup_bars_attr_id
{
    PROC_SETUP_BARS_ATTR_ID_NM = 0,
    PROC_SETUP_BARS_ATTR_ID_M = 1,
    PROC_SETUP_BARS_ATTR_ID_FN = 2,
    PROC_SETUP_BARS_ATTR_ID_FF = 3,
    PROC_SETUP_BARS_ATTR_ID_PSI = 4,
    PROC_SETUP_BARS_ATTR_ID_FSP = 5,
    PROC_SETUP_BARS_ATTR_ID_FSP_MMIO = 6,
    PROC_SETUP_BARS_ATTR_ID_INTP = 7,
    PROC_SETUP_BARS_ATTR_ID_NX = 8,
    PROC_SETUP_BARS_ATTR_ID_AS = 9,
    PROC_SETUP_BARS_ATTR_ID_PCIE = 10
};

// encoding for RC_PROC_SETUP_BARS_ATTR_LOOKUP_ERR types
enum proc_setup_bars_attr_lookup_err_type
{
    PROC_SETUP_BARS_BASE_ADDR_ATTR_LOOKUP_ERR = 0,
    PROC_SETUP_BARS_ENABLE_ATTR_LOOKUP_ERR = 1,
    PROC_SETUP_BARS_SIZE_ATTR_LOOKUP_ERR = 2
};

// structure to represent physical HW BAR register programming
struct proc_setup_bars_bar_reg_def
{
    // base address programming information
    bool has_base;
    proc_setup_bars_shift_base base_shift;
    uint8_t base_shift_amount;
    uint8_t base_start_bit;
    uint8_t base_end_bit;
    // enable programming information
    bool has_enable;
    uint8_t enable_bit;
    // size programming information
    bool has_size;
    uint8_t size_start_bit;
    uint8_t size_end_bit;
    // translate logical size to register programming
    const std::map<uint64_t, uint64_t>* xlate_map;
    // static value/mask to be written along with BAR content
    uint64_t static_data;
    uint64_t static_data_mask;
};

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// non-mirrored range constants
const proc_setup_bars_bar_def non_mirrored_range_def =
{
    0xFFFC0000FFFFFFFFULL,         // base: RA 14:63
    PROC_SETUP_BARS_SIZE_4_GB,     // size (min): 4 GB
    PROC_SETUP_BARS_SIZE_4_TB,     // size (max): 4 TB
    false
};

// mirrored range constants
const proc_setup_bars_bar_def mirrored_range_def =
{
    0xFFFC0000FFFFFFFFULL,         // base: RA 14:63
    PROC_SETUP_BARS_SIZE_2_GB,     // size (min): 2 GB
    PROC_SETUP_BARS_SIZE_2_TB,     // size (max): 2 TB
    false
};

// shared non-foreign BAR design (mirrored/non-mirrored regions) constants
const proc_setup_bars_bar_def common_nf_scope_bar_def =
{
    0xFFFC0000FFFFFFFFULL,         // base: RA 14:31
    PROC_SETUP_BARS_SIZE_4_GB,     // size (min): 4 GB
    PROC_SETUP_BARS_SIZE_64_TB,    // size (min): 64 TB
    true
};

const proc_setup_bars_bar_reg_def common_nf_scope_bar_reg_def =
{
    true,                          // base: bits 15:32
    PROC_SETUP_BARS_SHIFT_RIGHT,
    1,
    15,
    32,
    true,                          // enable: bit 0
    0,
    true,                          // size: bits 1:14
    1,
    14,
    &proc_setup_bars_nf_bar_size::xlate_map,
    0x0ULL,
    0x0ULL
};

// shared foreign BAR design (near/far regions) constants
const fapi::AttributeId f_near_range_base_addr_attr = fapi::ATTR_PROC_FOREIGN_NEAR_BASE;
const fapi::AttributeId f_near_range_size_attr = fapi::ATTR_PROC_FOREIGN_NEAR_SIZE;

const fapi::AttributeId f_far_range_base_addr_attr = fapi::ATTR_PROC_FOREIGN_FAR_BASE;
const fapi::AttributeId f_far_range_size_attr = fapi::ATTR_PROC_FOREIGN_FAR_SIZE;

const proc_setup_bars_bar_def common_f_scope_bar_def =
{
    0xFFFC000000FFFFFFULL,         // base: RA 14:39
    PROC_SETUP_BARS_SIZE_16_MB,    // size (min): 16 MB
    PROC_SETUP_BARS_SIZE_8_TB,     // size (min): 8 TB
    true
};

const proc_setup_bars_bar_reg_def common_f_scope_bar_reg_def =
{
    true,                          // base: bits 20:45
    PROC_SETUP_BARS_SHIFT_RIGHT,
    6,
    20,
    45,
    true,                          // enable: bit 0
    0,
    true,                          // size: bits 1:19
    1,
    19,
    &proc_setup_bars_f_bar_size::xlate_map,
    0x0ULL,
    0x0ULL
};

// PSI BAR constants
const fapi::AttributeId psi_bridge_bar_base_addr_attr = fapi::ATTR_PROC_PSI_BRIDGE_BAR_BASE_ADDR;
const fapi::AttributeId psi_bridge_bar_en_attr = fapi::ATTR_PROC_PSI_BRIDGE_BAR_ENABLE;

const proc_setup_bars_bar_def psi_bridge_bar_def =
{
    0xFFFC0000000FFFFFULL,         // base: RA 14:43
    PROC_SETUP_BARS_SIZE_1_MB,     // size (min): 1 MB
    PROC_SETUP_BARS_SIZE_1_MB,     // size (max): 1 MB
    true
};

const proc_setup_bars_bar_reg_def psi_bridge_bar_reg_def =
{
    true,                          // base: bits 14:43
    PROC_SETUP_BARS_SHIFT_NONE,
    0,
    14,
    43,
    true,                          // enable: bit 63
    63,
    false,                         // size: implied
    0,
    0,
    NULL,
    0x0ULL,
    0x0ULL
};

// FSP BAR constants
const fapi::AttributeId fsp_bar_base_addr_attr = fapi::ATTR_PROC_FSP_BAR_BASE_ADDR;
const fapi::AttributeId fsp_bar_en_attr = fapi::ATTR_PROC_FSP_BAR_ENABLE;
const fapi::AttributeId fsp_bar_size_attr = fapi::ATTR_PROC_FSP_BAR_SIZE;

const proc_setup_bars_bar_def fsp_bar_def =
{
    0xFFFC0000000FFFFFULL,         // base: RA 14:43
    PROC_SETUP_BARS_SIZE_1_MB,     // size (min): 1 MB
    PROC_SETUP_BARS_SIZE_4_GB,     // size (max): 4 GB
    true
};

const proc_setup_bars_bar_reg_def fsp_bar_reg_def =
{
    true,                          // base: bits 14:43
    PROC_SETUP_BARS_SHIFT_NONE,
    0,
    14,
    43,
    false,                         // enable: other reg
    0,
    false,                         // size: other reg
    0,
    0,
    NULL,
    0x0ULL,
    0x0ULL
};

const proc_setup_bars_bar_reg_def fsp_bar_mask_reg_def =
{
    false,                         // base: other reg
    PROC_SETUP_BARS_SHIFT_NONE,
    0,
    0,
    0,
    false,                         // enable: other reg
    0,
    true,                          // size: 32:43
    32,
    43,
    &proc_setup_bars_fsp_bar_size::xlate_map,
    0x0ULL,
    0x0ULL
};

const proc_setup_bars_bar_reg_def fsp_bar_en_reg_def =
{
    false,                         // base: other reg
    PROC_SETUP_BARS_SHIFT_NONE,
    0,
    0,
    0,
    true,                          // enable: bit 1
    1,
    false,                         // size: other reg
    0,
    0,
    NULL,
    0x0ULL,
    0x0ULL
};

// FSP MMIO mask constants
const fapi::AttributeId fsp_mmio_mask_size_attr = fapi::ATTR_PROC_FSP_MMIO_MASK_SIZE;

const proc_setup_bars_bar_def fsp_mmio_mask_def =
{
    0xFFFFFFFFFFFFFFFFULL,         // base: unused
    PROC_SETUP_BARS_SIZE_256_MB,   // size (min): 256 MB
    PROC_SETUP_BARS_SIZE_4_GB,     // size (max): 4 GB
    true
};

const proc_setup_bars_bar_reg_def fsp_mmio_mask_reg_def =
{
    false,                         // base: unused
    PROC_SETUP_BARS_SHIFT_NONE,
    0,
    0,
    0,
    false,                         // enable: unused
    0,
    true,                          // size: bits 8:11
    8,
    11,
    &proc_setup_bars_fsp_mmio_mask_size::xlate_map,
    0x0ULL,
    0x0ULL
};

// INTP BAR constants
const fapi::AttributeId intp_bar_base_addr_attr = fapi::ATTR_PROC_INTP_BAR_BASE_ADDR;
const fapi::AttributeId intp_bar_en_attr = fapi::ATTR_PROC_INTP_BAR_ENABLE;

const proc_setup_bars_bar_def intp_bar_def =
{
    0xFFFC0000000FFFFFULL,         // base: RA 14:43
    PROC_SETUP_BARS_SIZE_1_MB,     // size (min): 1 MB
    PROC_SETUP_BARS_SIZE_1_MB,     // size (max): 1 MB
    true
};

const proc_setup_bars_bar_reg_def intp_bar_reg_def =
{
    true,                          // base: bits 0:29
    PROC_SETUP_BARS_SHIFT_LEFT,
    14,
    0,
    29,
    true,                          // enable: bit 30
    30,
    false,                         // size: implied
    0,
    0,
    NULL,
    0x0ULL,
    0x0ULL
};

// L3 BAR constants
const uint32_t L3_BAR12_BASE_ADDR_LEFT_SHIFT_AMOUNT = 14;
const uint32_t L3_BAR12_SIZE_END_BIT = 34;
const uint32_t L3_BAR2_ENABLE_BIT = 35;

const uint32_t L3_BAR_GROUP_MASK_RA_DIFF_START_BIT = 18;
const uint32_t L3_BAR_GROUP_MASK_RA_DIFF_END_BIT = 31;

const uint32_t L3_BAR_GROUP_MASK_NON_MIRROR_MASK_START_BIT = 3;
const uint32_t L3_BAR_GROUP_MASK_NON_MIRROR_MASK_END_BIT = 16;

const uint32_t L3_BAR_GROUP_MASK_MIRROR_MASK_START_BIT = 20;
const uint32_t L3_BAR_GROUP_MASK_MIRROR_MASK_END_BIT = 33;
const uint32_t L3_BAR_GROUP_MASK_MIRROR_ENABLE_BIT = 34;

// NX MMIO BAR constants
const fapi::AttributeId nx_mmio_bar_base_addr_attr = fapi::ATTR_PROC_NX_MMIO_BAR_BASE_ADDR;
const fapi::AttributeId nx_mmio_bar_en_attr = fapi::ATTR_PROC_NX_MMIO_BAR_ENABLE;
const fapi::AttributeId nx_mmio_bar_size_attr = fapi::ATTR_PROC_NX_MMIO_BAR_SIZE;

const proc_setup_bars_bar_def nx_mmio_bar_def =
{
    0xFFFC000000000FFFULL,         // base: RA 14:51
    PROC_SETUP_BARS_SIZE_4_KB,     // size (min): 4 KB
    PROC_SETUP_BARS_SIZE_16_GB,    // size (max): 16 GB
    true
};

const proc_setup_bars_bar_reg_def nx_mmio_bar_reg_def =
{
    true,                          // base: bits 14:51
    PROC_SETUP_BARS_SHIFT_NONE,
    0,
    14,
    51,
    true,                          // enable: bit 52
    52,
    true,                          // size: bits 53:55
    53,
    55,
    &proc_setup_bars_nx_mmio_bar_size::xlate_map,
    0x0ULL,
    0x0ULL
};

// AS MMIO BAR constants
const fapi::AttributeId as_mmio_bar_base_addr_attr = fapi::ATTR_PROC_AS_MMIO_BAR_BASE_ADDR;
const fapi::AttributeId as_mmio_bar_en_attr = fapi::ATTR_PROC_AS_MMIO_BAR_ENABLE;
const fapi::AttributeId as_mmio_bar_size_attr = fapi::ATTR_PROC_AS_MMIO_BAR_SIZE;

const proc_setup_bars_bar_def as_mmio_bar_def =
{
    0xFFFC000000000FFFULL,         // base: RA 14:51
    PROC_SETUP_BARS_SIZE_4_KB,     // size (min): 4 KB
    PROC_SETUP_BARS_SIZE_16_GB,    // size (max): 16 GB
    true
};

const proc_setup_bars_bar_reg_def as_mmio_bar_reg_def =
{
    true,                          // base: bits 14:51
    PROC_SETUP_BARS_SHIFT_NONE,
    0,
    14,
    51,
    true,                          // enable: bit 52
    52,
    true,                          // size: bits 53:55
    53,
    55,
    &proc_setup_bars_as_mmio_bar_size::xlate_map,
    0x0ULL,
    0x0ULL
};

// HCA BAR and Range register constants
const proc_setup_bars_bar_reg_def hca_nm_bar_reg_def =
{
    true,                          // base: bits 14:31
    PROC_SETUP_BARS_SHIFT_NONE,
    0,
    14,
    31,
    false,                         // enable: bit 63 (off for SW258328)
    63,
    true,                          // size: bits 33:40
    33,
    40,
    &proc_setup_bars_hca_nm_bar_size::xlate_map,
    0x0ULL,
    0x0ULL
};

// HCA Mirror BAR and Range register constants
const proc_setup_bars_bar_reg_def hca_m_bar_reg_def =
{
    true,                          // base: bits 14:32
    PROC_SETUP_BARS_SHIFT_NONE,
    0,
    14,
    32,
    false,                         // enable: bit 63 (off for SW258328)
    63,
    false,                         // size: other reg
    0,
    0,
    NULL,
    0x0ULL,
    0x0ULL
};

// MCD Configuration Register constants
const proc_setup_bars_bar_reg_def mcd_nf_bar_reg_def =
{
    true,                          // base: bits 30:55
    PROC_SETUP_BARS_SHIFT_RIGHT,
    16,
    30,
    55,
    true,                          // enable: bit 0
    0,
    true,                          // size: bits 9:29
    9,
    29,
    &proc_setup_bars_mcd_bar_size::xlate_map,
    0x4000000000000000ULL,         // 1 config/group, system scope
    0x780000000000001CULL
};

const proc_setup_bars_bar_reg_def mcd_f0_bar_reg_def =
{
    true,                          // base: bits 30:55
    PROC_SETUP_BARS_SHIFT_RIGHT,
    16,
    30,
    55,
    true,                          // enable: bit 0
    0,
    true,                          // size: bits 9:29
    9,
    29,
    &proc_setup_bars_mcd_bar_size::xlate_map,
    0x4000000000000010ULL,         // 1 config/group, foreign scope, f0 link
    0x780000000000001CULL
};

const proc_setup_bars_bar_reg_def mcd_f1_bar_reg_def =
{
    true,                          // base: bits 30:55
    PROC_SETUP_BARS_SHIFT_RIGHT,
    16,
    30,
    55,
    true,                          // enable: bit 0
    0,
    true,                          // size: bits 9:29
    9,
    29,
    &proc_setup_bars_mcd_bar_size::xlate_map,
    0x4000000000000014ULL,         // 1 config/group, foreign scope, f1 link
    0x780000000000001CULL
};

// MCD FIR Register constants
const uint64_t MCD_FIR_MASK_RUNTIME_VAL = 0x2FC0000000000000ULL;

// MCD Evn/Odd Recovery Control Register field/bit definitions
const uint8_t PROC_SETUP_BARS_NUM_MCD_CFG = 4;

const uint64_t MCD_RECOVERY_ENABLE_BIT = 0;
const uint64_t MCD_RECOVERY_CFG_EN_BIT[PROC_SETUP_BARS_NUM_MCD_CFG] = {40,41,42,43};

// PCIe BAR constants
const uint32_t PROC_SETUP_BARS_PCIE_CHIP_NON_MIRRORED_BAR[PROC_SETUP_BARS_PCIE_NUM_UNITS] =
{
    PCIE0_NODAL_BAR0_0x02012010,
    PCIE1_NODAL_BAR0_0x02012410,
    PCIE2_NODAL_BAR0_0x02012810
};

const uint32_t PROC_SETUP_BARS_PCIE_CHIP_MIRRORED_BAR[PROC_SETUP_BARS_PCIE_NUM_UNITS] =
{
    PCIE0_NODAL_BAR1_0x02012011,
    PCIE1_NODAL_BAR1_0x02012411,
    PCIE2_NODAL_BAR1_0x02012811
};

const uint32_t PROC_SETUP_BARS_PCIE_NODE_NON_MIRRORED_BAR[PROC_SETUP_BARS_PCIE_NUM_UNITS] =
{
    PCIE0_GROUP_BAR0_0x02012012,
    PCIE1_GROUP_BAR0_0x02012412,
    PCIE2_GROUP_BAR0_0x02012812
};

const uint32_t PROC_SETUP_BARS_PCIE_NODE_MIRRORED_BAR[PROC_SETUP_BARS_PCIE_NUM_UNITS] =
{
    PCIE0_GROUP_BAR1_0x02012013,
    PCIE1_GROUP_BAR1_0x02012413,
    PCIE2_GROUP_BAR1_0x02012813
};

const uint32_t PROC_SETUP_BARS_PCIE_FOREIGN_NEAR_BAR[PROC_SETUP_BARS_PCIE_NUM_UNITS][PROC_FAB_SMP_NUM_F_LINKS] =
{
    {
        PCIE0_NEAR_BAR_F0_0x02012014,
        PCIE0_NEAR_BAR_F1_0x02012016
    },
    {
        PCIE1_NEAR_BAR_F0_0x02012414,
        PCIE1_NEAR_BAR_F1_0x02012416
    },
    {
        PCIE2_NEAR_BAR_F0_0x02012814,
        PCIE2_NEAR_BAR_F1_0x02012816
    }
};

const uint32_t PROC_SETUP_BARS_PCIE_FOREIGN_FAR_BAR[PROC_SETUP_BARS_PCIE_NUM_UNITS][PROC_FAB_SMP_NUM_F_LINKS] =
{
    {
        PCIE0_FAR_BAR_F0_0x02012015,
        PCIE0_FAR_BAR_F1_0x02012017
    },
    {
        PCIE1_FAR_BAR_F0_0x02012415,
        PCIE1_FAR_BAR_F1_0x02012417
    },
    {
        PCIE2_FAR_BAR_F0_0x02012815,
        PCIE2_FAR_BAR_F1_0x02012817
    }
};

const uint8_t PROC_SETUP_BARS_PCIE_RANGES_PER_UNIT_MMIO = 2;
const uint8_t PROC_SETUP_BARS_PCIE_RANGES_PER_UNIT_PHB  = 1;
const uint8_t PROC_SETUP_BARS_PCIE_REGS_PER_PHB_RANGE   = 2;

const uint8_t PROC_SETUP_BARS_PCIE_RANGE_TYPE_MMIO[PROC_SETUP_BARS_PCIE_RANGES_PER_UNIT] =
{
    true,   // BAR 0 = MMIO (primary)
    true,   // BAR 1 = MMIO (backup/failover)
    false,  // BAR 2 = PHB
};

const fapi::AttributeId pcie_mmio_bar_base_addr_attr = fapi::ATTR_PROC_PCIE_BAR_BASE_ADDR;
const fapi::AttributeId pcie_mmio_bar_en_attr = fapi::ATTR_PROC_PCIE_BAR_ENABLE;
const fapi::AttributeId pcie_mmio_bar_size_attr = fapi::ATTR_PROC_PCIE_BAR_SIZE;

const proc_setup_bars_bar_def pcie_mmio_bar_def =
{
    0xFFFC00000000FFFFULL,         // base: RA 14:47
    PROC_SETUP_BARS_SIZE_64_KB,    // size (min): 64 KB
    PROC_SETUP_BARS_SIZE_1_PB,     // size (min): 1 PB
    true
};

const proc_setup_bars_bar_reg_def pcie_mmio_bar_reg_def =
{
    true,                          // base: bits 0:33
    PROC_SETUP_BARS_SHIFT_LEFT,
    14,
    0,
    33,
    false,                         // enable: other reg
    0,
    false,                         // size: other reg
    0,
    0,
    NULL,
    0x0ULL,
    0x0ULL
};

const uint32_t PROC_SETUP_BARS_PCIE_BAR_REGS_MMIO[PROC_SETUP_BARS_PCIE_NUM_UNITS][PROC_SETUP_BARS_PCIE_RANGES_PER_UNIT_MMIO] =
{
    {
        PCIE0_IO_BAR0_0x02012040,
        PCIE0_IO_BAR1_0x02012041
    },
    {
        PCIE1_IO_BAR0_0x02012440,
        PCIE1_IO_BAR1_0x02012441
    },
    {
        PCIE2_IO_BAR0_0x02012840,
        PCIE2_IO_BAR1_0x02012841
    }
};

const proc_setup_bars_bar_reg_def pcie_mmio_bar_mask_reg_def =
{
    false,                         // base: other reg
    PROC_SETUP_BARS_SHIFT_NONE,
    0,
    0,
    0,
    false,                         // enable: other reg
    0,
    true,                          // size: bits 0:33
    0,
    33,
    &proc_setup_bars_pcie_bar_size::xlate_map,
    0x0ULL,
    0x0ULL,
};

const uint32_t PROC_SETUP_BARS_PCIE_BAR_MASK_REGS_MMIO[PROC_SETUP_BARS_PCIE_NUM_UNITS][PROC_SETUP_BARS_PCIE_RANGES_PER_UNIT_MMIO] =
{
    {
        PCIE0_IO_MASK0_0x02012043,
        PCIE0_IO_MASK1_0x02012044
    },
    {
        PCIE1_IO_MASK0_0x02012443,
        PCIE1_IO_MASK1_0x02012444
    },
    {
        PCIE2_IO_MASK0_0x02012843,
        PCIE2_IO_MASK1_0x02012844
    }
};

const proc_setup_bars_bar_def pcie_phb_bar_def =
{
    0xFFFC000000000FFFULL,         // base: RA 14:51
    PROC_SETUP_BARS_SIZE_4_KB,     // size (min): 4 KB
    PROC_SETUP_BARS_SIZE_4_KB,     // size (min): 4 KB
    true
};

const proc_setup_bars_bar_reg_def pcie_phb_bar_reg_def =
{
    true,                          // base: bits 0:37
    PROC_SETUP_BARS_SHIFT_LEFT,
    14,
    0,
    37,
    false,                         // enable: other reg
    0,
    false,                         // size: implied
    0,
    33,
    NULL,
    0x0ULL,
    0x0ULL
};

const uint32_t PROC_SETUP_BARS_PCIE_BAR_REGS_PHB[PROC_SETUP_BARS_PCIE_NUM_UNITS][PROC_SETUP_BARS_PCIE_REGS_PER_PHB_RANGE] =
{
    {
        PCIE0_IO_BAR2_0x02012042,
        PCIE0_ASB_BAR_0x0901200B
    },
    {
        PCIE1_IO_BAR2_0x02012442,
        PCIE1_ASB_BAR_0x0901240B
    },
    {
        PCIE2_IO_BAR2_0x02012842,
        PCIE2_ASB_BAR_0x0901280B
    }
};

const uint32_t PROC_SETUP_BARS_PCIE_BAR_EN_BIT[PROC_SETUP_BARS_PCIE_NUM_UNITS] =
{
    0x0,
    0x1,
    0x2
};

const uint32_t PROC_SETUP_BARS_PCIE_BAR_EN_REGS[PROC_SETUP_BARS_PCIE_NUM_UNITS] =
{
    PCIE0_IO_BAR_EN_0x02012045,
    PCIE1_IO_BAR_EN_0x02012445,
    PCIE2_IO_BAR_EN_0x02012845
};

// ETU Reset register field/bit definitions
const uint32_t PROC_SETUP_BARS_PCIE_ETU_RESET_REGS[PROC_SETUP_BARS_PCIE_NUM_UNITS] =
{
    PCIE0_ETU_RESET_0x0901200A,
    PCIE1_ETU_RESET_0x0901240A,
    PCIE2_ETU_RESET_0x0901280A
};


#endif // _PROC_SETUP_BARS_DEFS_H_
