/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/opt_memmap.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// $Id: opt_memmap.C,v 1.19 2014/06/20 20:23:44 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/opt_memmap.C,v $


//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : opt_memmap.C
// *! DESCRIPTION : Layout non-mirrored/mirrored address map (FAPI)
// *!
// *! OWNER NAME  : Joe McGill    Email: jmcgill@us.ibm.com
// *! BACKUP NAME : ???           Email: ???@us.ibm.com
// *!
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.18   | jmcgill  | 06/20/14| Add logic for flipped drawer enum
//  1.17   | dcrowell | 06/19/14| Switch from #define to attr for mirror origin
//  1.16   | jmcgill  | 10/28/13| Offset drawers by 32TB rather than 1TB
//  1.15   | jmcgill  | 09/17/13| Add logic to offset memory map based on
//         |          |         | drawer number (required for multi-drawer
//         |          |         | Brazos)
//  1.14   | thi      | 08/29/13| Init variable to avoid HB compiler error.
//  1.13   | jmcgill  | 08/29/13| Remove use of reverse iter (HB doesn't support)
//  1.12   | jmcgill  | 07/10/13| Update to match new attributes, selective
//         |          |         | aligment policy changes
//  1.11   | jmcgill  | 06/11/13| Update for alternate BAR support (mirrored)
//  1.10   | jmcgill  | 05/24/13| Updates for alternate BAR support
//  1.9    | jmcgill  | 05/23/13| Address FW review issues
//  1.8    | jmcgill  | 04/28/13| Add HTM/OCC memory allocation, fix namespace
//  1.7    | jmcgill  | 04/20/13| Rewrite to add additional sorting capabilities
//         |          |         | desired for exercisor mirroring testing
//  1.6    | vanlee   | 02/22/13| Update sort logic of ProcBase class
//  1.5    | vanlee   | 02/20/13| Add init paramter
//  1.4    | vanlee   | 01/04/13| Added version string
//  1.1    | vanlee   | 12/01/12| First drop
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Design flow:
//
// opt_memmap() interacts with mss_eff_grouping() to define the assignment
// of non-mirrored/mirrored real address space on each chip in the drawer
//
// opt_memmap() will be called twice in the IPL flow, once before and once
// after mss_eff_grouping()
//
// 1) Call opt_memmap() with i_init = true
//    - Each proc's ATTR_PROC_MEM_BASE attribute is set to 0 (512TB for flipped
//      alignment)
//    - Each proc's ATTR_PROC_MIRROR_BASE attribute is set to 512TB (0 for
//      flipped alignment, 8TB for selective alignment)
//
//    This provides a basis for mss_eff_grouping() to stack all on-chip
//    groups.
//    
//    NOTE: offset/mirrored origin (512TB above/below) is controlled by
//          value of ATTR_MIRROR_BASE_ADDRESS
//
// 2) mss_eff_grouping() call
//    - The HWP updates each proc's ATTR_PROC_[MEM|MIRROR]_[BASES|SIZES]
//      attributes based on the address regions allocated for installed memory
//      behind each proc
//    - ATTR_PROC_[MEM|MIRROR]_[BASES|SIZES]_ACK are updated to reflect
//      the stackable size of each on chip memory region
//
// 3) Call opt_memmap() with i_init = false
//    - Consume mss_eff_grouping() attributes for each proc to determine
//      "effective stackable" size of non-mirrored/mirrored regions
//      on each proc
//    - Stack procs based on their effective size and desired placement
//      policy
//                                         non-mirrored    mirrored
//         mirror       eff. stacking       stacking       stacking
//         policy       sort criteria        origin         origin
//        --------      -------------      ------------    --------
//         NORMAL            nm                0TB           512TB
//         DRAWER            nm            32TB*drawer     512TB+(32TB*drawer)/2
//         FLIPPED           m                512TB           0TB
//      FLIPPED_DRAWER       m         512TB+(32TB*drawer) 32TB*drawer
//        SELECTIVE         nm+m               0TB            8TB
//
//    - Write ATTR_PROC_[MEM|MIRROR]_BASE attributes to their final
//      value
//
// 4) mss_eff_grouping() call
//    - Second run will produce properly aligned output attributes based
//      on final per-chip base address attributes determine in prior step
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------

#include <opt_memmap.H>


//------------------------------------------------------------------------------
//  Constant definitions
//------------------------------------------------------------------------------

extern "C" {

using namespace fapi;


//------------------------------------------------------------------------------
//  Function definitions
//------------------------------------------------------------------------------


// round to next largest power of 2
inline uint64_t PowerOf2Roundedup(uint64_t i_number)
{
    if (i_number)
    {
        --i_number;
        i_number |= i_number >> 1;
        i_number |= i_number >> 2;
        i_number |= i_number >> 4;
        i_number |= i_number >> 8;
        i_number |= i_number >> 16;
        i_number |= i_number >> 32;
        ++i_number;
    }
    return i_number;
}


// class to represent memory region
// filled by attribute data from mss_eff_grouping procedure
class MemRegion
{

public:

    // region type (mirrored/non-mirrored)
    enum group_type { nm = 0, m = 1 };

    // region type
    group_type iv_group_type;

    // region parameters
    uint64_t iv_base;
    uint64_t iv_size;

    // comparison operator for sort
    bool operator < (MemRegion rhs) const
    {
        bool l_lt = true;
        if (iv_base > rhs.iv_base ||
            ((iv_base == rhs.iv_base) && (iv_size > rhs.iv_size)))
        {
            l_lt = false;
        }
        return l_lt;
    }

    // constructor
    MemRegion(MemRegion::group_type type, uint64_t base, uint64_t size) :
        iv_group_type(type), iv_base(base), iv_size(size) {}

    // debug function
    void dump()
    {
        FAPI_DBG("Region [ %s ]", (iv_group_type == nm)?("nm"):("m"));
        FAPI_DBG("  Base: %016llX", iv_base);
        FAPI_DBG("  Size: %016llX", iv_size);
    }
};


// class to represent memory map (non-mirrored/mirrored) on one processor chip
class ProcChipMemmap
{

public:
    // pointer to processor chip target
    Target *iv_target;
    // mirroring policy
    uint8_t iv_mirror_policy;

    // chip location information
    uint8_t iv_pos;
    uint8_t iv_node_id;
    uint8_t iv_chip_id;

    // chip non-mirrored base, effective size, and member regions
    uint64_t iv_nm_base;
    uint64_t iv_nm_eff_size;
    std::vector<MemRegion> iv_nm_regions;

    // chip mirrored base, effective size, and member regions
    uint64_t iv_m_base;
    uint64_t iv_m_eff_size;
    std::vector<MemRegion> iv_m_regions;

    // comparison operator for sort
    // sort in increasing size, and decreasing proc position
    // e.g. proc0 and proc2 have same size, then the order will be
    // proc2 then proc0
    bool operator < (ProcChipMemmap rhs) const
    {
        bool l_lt = true;
        uint64_t l_this_eff_size = 0;
        uint64_t l_rhs_eff_size = 0;

        // compute effective size based on mirror policy
        // sort by non-mirrored size
        if (((iv_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL) &&
             (rhs.iv_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL)) ||
            ((iv_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_DRAWER) &&
             (rhs.iv_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_DRAWER)) ||
            ((iv_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_SELECTIVE) &&
             (rhs.iv_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_SELECTIVE)))
        {
            l_this_eff_size = iv_nm_eff_size;
            l_rhs_eff_size  = rhs.iv_nm_eff_size;
        }
        // sort by mirrored size
        else if (((iv_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED) &&
                  (rhs.iv_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED)) ||
                 ((iv_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED_DRAWER) &&
                  (rhs.iv_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED_DRAWER)))
        {
            l_this_eff_size = iv_m_eff_size;
            l_rhs_eff_size  = rhs.iv_m_eff_size;
        }
        // perform sort comparison
        if (l_this_eff_size > l_rhs_eff_size ||
            (l_this_eff_size == l_rhs_eff_size && iv_pos < rhs.iv_pos))
        {
            l_lt = false;
        }
        return l_lt;
    }

    // constructor
    ProcChipMemmap(Target* t, uint8_t mirror_policy) :
        iv_target(t), iv_mirror_policy(mirror_policy) {}

    // process chip data from attributes
    ReturnCode processAttributes()
    {
        ReturnCode rc;
        uint64_t l_nm_bases[OPT_MEMMAP_MAX_NM_REGIONS];
        uint64_t l_nm_sizes[OPT_MEMMAP_MAX_NM_REGIONS];
        uint64_t l_m_bases[OPT_MEMMAP_MAX_M_REGIONS];
        uint64_t l_m_sizes[OPT_MEMMAP_MAX_M_REGIONS];

        do
        {
            // obtain node/chip ID
            rc = FAPI_ATTR_GET(ATTR_FABRIC_NODE_ID,
                               iv_target,
                               iv_node_id);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_FABRIC_NODE)");
                break;
            }

            rc = FAPI_ATTR_GET(ATTR_FABRIC_CHIP_ID,
                               iv_target,
                               iv_chip_id);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_FABRIC_CHIP)");
                break;
            }
            iv_pos = ((4*iv_node_id)+iv_chip_id);

            // retrieve base address for each chip
            rc = FAPI_ATTR_GET(ATTR_PROC_MEM_BASE,
                               iv_target,
                               iv_nm_base);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_PROC_MEM_BASE)");
                break;
            }

            rc = FAPI_ATTR_GET(ATTR_PROC_MIRROR_BASE,
                               iv_target,
                               iv_m_base);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_PROC_MIRROR_BASE)");
                break;
            }

            // retrieve regions (bases and sizes) computed by mss_eff_grouping
            rc = FAPI_ATTR_GET(ATTR_PROC_MEM_BASES_ACK,
                               iv_target,
                               l_nm_bases);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_PROC_MEM_BASES_ACK)");
                break;
            }

            rc = FAPI_ATTR_GET(ATTR_PROC_MEM_SIZES_ACK,
                               iv_target,
                               l_nm_sizes);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_PROC_MEM_SIZES_ACK)");
                break;
            }
            rc = FAPI_ATTR_GET(ATTR_PROC_MIRROR_BASES_ACK,
                               iv_target,
                               l_m_bases);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_PROC_MIRROR_BASES_ACK)");
                break;
            }

            rc = FAPI_ATTR_GET(ATTR_PROC_MIRROR_SIZES_ACK,
                               iv_target,
                               l_m_sizes);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_PROC_MIRROR_SIZES_ACK)");
                break;
            }

            // populate non-mirrored regions
            FAPI_INF("Chip n%d:p%d", iv_node_id, iv_chip_id);
            for (uint8_t i = 0; i < OPT_MEMMAP_MAX_NM_REGIONS; i++)
            {
                if (l_nm_sizes[i] != 0)
                {
                    FAPI_INF("  l_nm_bases[%d] = %016llX", i, l_nm_bases[i]);
                    FAPI_INF("  l_nm_sizes[%d] = %016llX", i, l_nm_sizes[i]);
                    MemRegion r(MemRegion::nm, l_nm_bases[i], l_nm_sizes[i]);
                    iv_nm_regions.push_back(r);
                }
            }

            // populate mirrored regions
            for (uint8_t i = 0; i < OPT_MEMMAP_MAX_M_REGIONS; i++)
            {
                if (l_m_sizes[i] != 0)
                {
                    // align to common origin
                    FAPI_INF("  l_m_bases[%d] = %016llX", i, l_m_bases[i]);
                    FAPI_INF("  l_m_sizes[%d] = %016llX", i, l_m_sizes[i]);
                    MemRegion r(MemRegion::m, l_m_bases[i], l_m_sizes[i]);
                    iv_m_regions.push_back(r);
                }
            }

            // sort regions for effective size calculations
            std::sort(iv_nm_regions.begin(), iv_nm_regions.end());
            std::sort(iv_m_regions.begin(), iv_m_regions.end());

            // compute effective size of chip address space
            // this is simply the end address of the last region in
            // each stack (rounded up to a power of 2)
            if (iv_nm_regions.size() != 0)
            {
                if (iv_nm_base != iv_nm_regions[0].iv_base)
                {
                    const uint64_t& ADDR = iv_nm_base;
                    FAPI_ERR("Unexpected value returned for ATTR_PROC_MEM_BASE (=%016llX)",
                             iv_nm_base);
                    FAPI_SET_HWP_ERROR(rc, RC_OPT_MEMMAP_MEM_BASE_ERR);
                    break;
                }

                iv_nm_eff_size = iv_nm_regions[iv_nm_regions.size()-1].iv_base -
                    iv_nm_regions[0].iv_base;
                iv_nm_eff_size += iv_nm_regions[iv_nm_regions.size()-1].iv_size;
                iv_nm_eff_size = PowerOf2Roundedup(iv_nm_eff_size);
            }
            else
            {
                iv_nm_eff_size = 0;
            }
            FAPI_INF("  nm_eff_size = %016llX", iv_nm_eff_size);

            if (iv_m_regions.size() != 0)
            {
                if (iv_m_base != iv_m_regions[0].iv_base)
                {
                    const uint64_t& ADDR = iv_m_base;
                    FAPI_ERR("Unexpected value returned for ATTR_PROC_MIRROR_BASE (=%016llX)",
                             iv_m_base);
                    FAPI_SET_HWP_ERROR(rc, RC_OPT_MEMMAP_MIRROR_BASE_ERR);
                    break;
                }

                iv_m_eff_size = iv_m_regions[iv_m_regions.size()-1].iv_base -
                    iv_m_regions[0].iv_base;
                iv_m_eff_size += iv_m_regions[iv_m_regions.size()-1].iv_size;
                iv_m_eff_size = PowerOf2Roundedup(iv_m_eff_size);
            }
            else
            {
                iv_m_eff_size = 0;
            }
            FAPI_INF("  m_eff_size = %016llX", iv_m_eff_size);

        } while(0);

        return rc;
    }

    // establish new non-mirrored base address for this chip
    void setNMBase(const uint64_t& base)
    {
        iv_nm_base = base;
    }

    // establish new mirrored base address for this chip
    void setMBase(const uint64_t& base)
    {
        iv_m_base = base;
    }

    // flush state back to attributes
    ReturnCode flushAttributes()
    {
        ReturnCode rc;

        do
        {
            // set base addresses
            rc = FAPI_ATTR_SET(ATTR_PROC_MEM_BASE,
                               iv_target,
                               iv_nm_base);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_SET (ATTR_PROC_MEM_BASE)");
                break;
            }

            rc = FAPI_ATTR_SET(ATTR_PROC_MIRROR_BASE,
                               iv_target,
                               iv_m_base);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_SET (ATTR_PROC_MIRROR_BASE)");
                break;
            }

        } while(0);
        return rc;
    }
};


ReturnCode opt_memmap(std::vector<fapi::Target> & i_procs, bool i_init)
{
    ReturnCode rc;
    std::vector<ProcChipMemmap> l_drawer_memmap;
    uint8_t l_mirror_policy;

    do
    {
        // retrieve mirroring placement policy attribute
        rc = FAPI_ATTR_GET(ATTR_MEM_MIRROR_PLACEMENT_POLICY,
                           NULL,
                           l_mirror_policy);
        if (!rc.ok())
        {
            FAPI_ERR("Error querying ATTR_MEM_MIRROR_PLACEMENT_POLICY");
            break;
        }

        uint64_t l_mirror_origin = 0;
        rc = FAPI_ATTR_GET(ATTR_MIRROR_BASE_ADDRESS,
                           NULL,
                           l_mirror_origin);
        if (!rc.ok())
        {
            FAPI_ERR("Error querying ATTR_MIRROR_BASE_ADDRESS");
            break;
        }

        FAPI_INF("opt_memmap called with i_init: %d, mirror_policy: %d, mirror_origin: %016llX",
                 (i_init)?(1):(0), l_mirror_policy, l_mirror_origin);

        // first pass of execution
        if (i_init)
        {
            uint64_t mem_base;
            uint64_t mirror_base;

            if (l_mirror_policy ==
                ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL)
            {
                mem_base = OPT_MEMMAP_BASE_ORIGIN;
                mirror_base = l_mirror_origin;
            }
            else if (l_mirror_policy ==
                     ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED)
            {
                mem_base = l_mirror_origin;
                mirror_base = OPT_MEMMAP_BASE_ORIGIN;
            }
            else if (l_mirror_policy ==
                     ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_SELECTIVE)
            {
                mem_base = OPT_MEMMAP_BASE_ORIGIN;
                mirror_base = OPT_MEMMAP_SELECTIVE_ORIGIN;
            }

            // loop across all chips in drawer, set common
            // base for non-mirrored/mirrored memory on each chip in preparation
            // for mss_eff_grouping call
            for (std::vector<fapi::Target>::iterator l_iter = i_procs.begin();
                 l_iter != i_procs.end();
                 ++l_iter)
            {
                if ((l_iter == i_procs.begin()) &&
                    ((l_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_DRAWER) ||
                     (l_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED_DRAWER)))
                {
                    uint8_t drawer_id;
                    rc = FAPI_ATTR_GET(ATTR_FABRIC_NODE_ID,
                                       &(*l_iter),
                                       drawer_id);
                    if (!rc.ok())
                    {
                        FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_FABRIC_NODE_ID)");
                        break;
                    }

                    if (l_mirror_policy ==  ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_DRAWER)
                    {
                        mem_base = drawer_id * 32 * OPT_MEMMAP_TB;
                        mirror_base = l_mirror_origin + (mem_base / 2);
                    }
                    else
                    {
                        mirror_base = drawer_id * 32 * OPT_MEMMAP_TB;
                        mem_base = l_mirror_origin + mirror_base;
                    }
                }

                rc = FAPI_ATTR_SET(ATTR_PROC_MEM_BASE,
                                   &(*l_iter),
                                   mem_base);
                if (!rc.ok())
                {
                    FAPI_ERR("Error from FAPI_ATTR_SET (ATTR_PROC_MEM_BASE)!");
                    break;
                }

                rc = FAPI_ATTR_SET(ATTR_PROC_MIRROR_BASE,
                                   &(*l_iter),
                                   mirror_base);
                if (!rc.ok())
                {
                    FAPI_ERR("Error from FAPI_ATTR_SET (ATTR_PROC_MIRROR_BASE)!");
                    break;
                }
            }
            if (!rc.ok())
            {
                break;
            }
        }
        // second pass of execution
        // reorder chips based on their effective stackable size
        else
        {
            // base for alignment of mirrored/non-mirrored regions
            uint64_t l_m_base_curr = 0;
            uint64_t l_nm_base_curr = 0;

            if (l_mirror_policy ==
                ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL)
            {
                // non-mirrored at zero, mirrored at offset
                l_nm_base_curr = OPT_MEMMAP_BASE_ORIGIN;
                l_m_base_curr  = l_mirror_origin;
            }
            else if (l_mirror_policy ==
                     ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED)
            {
                // mirrored at zero, non-mirrored at offset
                l_nm_base_curr = l_mirror_origin;
                l_m_base_curr  = OPT_MEMMAP_BASE_ORIGIN;
            }
            else if (l_mirror_policy ==
                     ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_SELECTIVE)
            {
                l_nm_base_curr = OPT_MEMMAP_BASE_ORIGIN;
                l_m_base_curr  = OPT_MEMMAP_SELECTIVE_ORIGIN;
            }

            // loop across all chips in drawer, consume results of
            // mss_eff_grouping call
            for (std::vector<fapi::Target>::iterator l_iter = i_procs.begin();
                 l_iter != i_procs.end();
                 ++l_iter)
            {
                if ((l_iter == i_procs.begin()) &&
                    ((l_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_DRAWER) ||
                     (l_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED_DRAWER)))
                {
                    uint8_t drawer_id;
                    rc = FAPI_ATTR_GET(ATTR_FABRIC_NODE_ID,
                                       &(*l_iter),
                                       drawer_id);
                    if (!rc.ok())
                    {
                        FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_FABRIC_NODE_ID)");
                        break;
                    }

                    if (l_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_DRAWER)
                    {
                        l_nm_base_curr = drawer_id * 32 * OPT_MEMMAP_TB;
                        l_m_base_curr = l_mirror_origin + (l_nm_base_curr / 2);
                    }
                    else
                    {
                        l_m_base_curr = drawer_id * 32 * OPT_MEMMAP_TB;
                        l_nm_base_curr = l_mirror_origin + l_m_base_curr;
                    }
                }

                ProcChipMemmap p(&(*l_iter), l_mirror_policy);
                rc = p.processAttributes();
                if (!rc.ok())
                {
                    FAPI_ERR("Error from processAttributes");
                    break;
                }
                l_drawer_memmap.push_back(p);
            }
            if (!rc.ok())
            {
                break;
            }

            // sort chips based on their effective stackable size
            std::sort(l_drawer_memmap.begin(), l_drawer_memmap.end());

            // walk through chips, from largest->smallest effective size &
            // assign base addresses for each group
            for (uint8_t i = l_drawer_memmap.size();
                 i != 0;
                 --i)
            {
                FAPI_DBG("Stacking chip n%d:p%d (eff nm size = %lld GB, eff m size = %lld GB)...",
                         l_drawer_memmap[i-1].iv_node_id,
                         l_drawer_memmap[i-1].iv_chip_id,
                         l_drawer_memmap[i-1].iv_nm_eff_size / OPT_MEMMAP_GB,
                         l_drawer_memmap[i-1].iv_m_eff_size / OPT_MEMMAP_GB);

                if (l_mirror_policy ==
                    ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_SELECTIVE)
                {
                    l_m_base_curr += l_drawer_memmap[i-1].iv_nm_eff_size;
                }

                // establish base addresses for this chip & realign
                // all groups on this chip to reflect this
                l_drawer_memmap[i-1].setNMBase(l_nm_base_curr);
                l_drawer_memmap[i-1].setMBase(l_m_base_curr);
                FAPI_DBG("nm base: %016llX", l_nm_base_curr);
                FAPI_DBG("m base: %016llX", l_m_base_curr);
                if ((l_mirror_policy ==
                     ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL) ||
                    (l_mirror_policy ==
                     ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_DRAWER))
                {
                    l_nm_base_curr += l_drawer_memmap[i-1].iv_nm_eff_size;
                    l_m_base_curr += l_drawer_memmap[i-1].iv_nm_eff_size / 2;
                }
                else if ((l_mirror_policy ==
                          ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED) ||
                         (l_mirror_policy ==
                          ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED_DRAWER))
                {
                    l_nm_base_curr += l_drawer_memmap[i-1].iv_nm_eff_size;
                    l_m_base_curr += l_drawer_memmap[i-1].iv_m_eff_size;
                }
                else if (l_mirror_policy ==
                         ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_SELECTIVE)
                {
                    l_nm_base_curr += l_drawer_memmap[i-1].iv_nm_eff_size;
                    l_m_base_curr += l_drawer_memmap[i-1].iv_nm_eff_size / 2;
                }

                // flush attributes for this chip
                rc = l_drawer_memmap[i-1].flushAttributes();
                if (!rc.ok())
                {
                    FAPI_ERR("Error from flushAttributes");
                    break;
                }
            }
            if (!rc.ok())
            {
                break;
            }
        }
    } while(0);

    return rc;
}


} //end extern C
