/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/opt_memmap.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
// $Id: opt_memmap.C,v 1.21 2015/01/23 01:54:26 jmcgill Exp $
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
// *!
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Design flow:
//
// opt_memmap() interacts with mss_eff_grouping() to define the assignment
// of non-mirrored/mirrored real address space on each chip in the drawer:
// - mss_eff_grouping() is responsible for the address assignment/layout
//   of regions on a chip basis
// - opt_memmap() determines the final position of each chip's address
//   space within the drawer
// 
// Sequence:
//
// opt_memmap() will be called twice in the IPL flow, once before and once
// after mss_eff_grouping().  
//
// 1) Call opt_memmap() with i_init = true
//
//    opt_memmap() writes ATTR_PROC_[MEM|MIRROR]_BASE attributes to
//    provide a basis for mss_eff_grouping() to stack all on-chip
//    groups.  Initially all chips are set to common values to provide
//    a simple basis for size comparison.
//
//                                          non-mirrored              mirrored
//         mirror       eff. stacking        stacking                 stacking
//         policy       sort criteria         origin                   origin
//        --------      -------------   ---------------------  -----------------------
//         NORMAL            nm                0 TB                    X TB
//         DRAWER            nm           32 TB * drawer       X TB+(32 TB * drawer)/2
//         FLIPPED           m                 X TB                    0 TB
//      FLIPPED_DRAWER       m          X TB+(32 TB * drawer)      32TB * drawer
//    
// 2) mss_eff_grouping() call
//    - The HWP updates each proc's ATTR_PROC_[MEM|MIRROR]_[BASES|SIZES]
//      attributes based on the address regions allocated for installed memory
//      behind each proc
//    - ATTR_PROC_[MEM|MIRROR]_[BASES|SIZES]_ACK are updated to reflect
//      the stackable size of each on chip memory region
//
// 3) Call opt_memmap() with i_init = false
//    - Consume mss_eff_grouping() *_ACK attributes for each proc to determine
//      "effective stackable" size of non-mirrored/mirrored regions
//      on each proc
//    - Stack procs based on their effective size and desired placement
//      policy
//    - Write ATTR_PROC_[MEM|MIRROR]_BASE attributes to their final
//      value
//
// 4) mss_eff_grouping() call
//    - Second run will produce properly aligned output attributes based
//      on final per-chip base address attributes determined in prior step
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------

#include <opt_memmap.H>
#include <algorithm>

//------------------------------------------------------------------------------
//  Constant definitions
//------------------------------------------------------------------------------

extern "C" {

using namespace fapi;


//------------------------------------------------------------------------------
//  Function definitions
//------------------------------------------------------------------------------


// class to represent memory region
class MemRegion
{
public:
    // region type (mirrored/non-mirrored)
    enum type { nm = 0, m = 1 };

    // constructors
    MemRegion(MemRegion::type type) :
        iv_group_type(type), iv_base(0), iv_size(0) {}

    MemRegion(MemRegion::type type, uint64_t base, uint64_t size) :
        iv_group_type(type), iv_base(base), iv_size(size) {}

    // comparison operators for sorting
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

    bool operator == (MemRegion rhs) const
    {
        return((iv_base == rhs.iv_base) &&
               (iv_size == rhs.iv_size));
    }

    bool operator > (MemRegion rhs) const
    {
        return (!(*this == rhs) && !(*this < rhs));
    }

    uint64_t getBase() const { return iv_base; }
    uint64_t getSize() const { return iv_size; }
    void setBase(uint64_t base) { iv_base = base; }
    void setSize(uint64_t size) { iv_size = size; }

    // determine if region size is power of 2 aligned
    bool isPowerOf2() const
    {
        return ((iv_size != 0) && !(iv_size & (iv_size - 1)));
    }

    // round region size to next largest power of 2
    void roundNextPowerOf2()
    {
        iv_size = iv_size - 1;
        iv_size = iv_size | (iv_size >> 1);
        iv_size = iv_size | (iv_size >> 2);
        iv_size = iv_size | (iv_size >> 4);
        iv_size = iv_size | (iv_size >> 8);
        iv_size = iv_size | (iv_size >> 16);
        iv_size = iv_size | (iv_size >> 32);
        iv_size = iv_size + 1;
    }

    // debug function
    void dump() const
    {
        FAPI_DBG("Region [ %s ]", (iv_group_type == nm)?("nm"):("m"));
        FAPI_DBG("  Base: 0x%016llX", iv_base);
        FAPI_DBG("  Size: 0x%016llX", iv_size);
    }

private:
    // region type
    type iv_group_type;

    // region parameters
    uint64_t iv_base;
    uint64_t iv_size;

};


// class to represent memory map (non-mirrored/mirrored regions) on one processor chip
class ProcChipMemmap
{
public:
    // constructor
    ProcChipMemmap(Target* t, MemRegion::type sort, bool chip_as_group) :
        iv_target(t), iv_sort(sort), iv_chip_as_group(chip_as_group), iv_node_id(0), iv_chip_id(0), iv_nm(MemRegion::nm), iv_m(MemRegion::m) {}

    // comparison operator for sort
    // sort in increasing effective size, and decreasing proc position
    // e.g. proc0 and proc2 have same size, then the order will be
    // proc2 then proc0
    bool operator < (ProcChipMemmap rhs) const
    {
        uint8_t l_pos = ((4*iv_node_id)+iv_chip_id);
        uint8_t r_pos = ((4*rhs.iv_node_id)+rhs.iv_chip_id);

        bool l_lt = true;
        // perform sort comparison
        MemRegion l = ((iv_sort == MemRegion::nm)?(iv_nm):(iv_m));
        MemRegion r = ((iv_sort == MemRegion::nm)?(rhs.iv_nm):(rhs.iv_m));
        if ((l > r) ||
            ((l == r) && (l_pos < r_pos)))
        {
            l_lt = false;
        }
        return l_lt;
    }

    // process chip data from attributes
    ReturnCode processAttributes()
    {
        ReturnCode rc;
        uint64_t l_nm_base;
        uint64_t l_m_base;
        uint64_t l_nm_bases[OPT_MEMMAP_MAX_NM_REGIONS] = { 0 };
        uint64_t l_nm_sizes[OPT_MEMMAP_MAX_NM_REGIONS] = { 0 };
        uint64_t l_m_bases[OPT_MEMMAP_MAX_M_REGIONS] = { 0 };
        uint64_t l_m_sizes[OPT_MEMMAP_MAX_M_REGIONS] = { 0 };
        std::vector<MemRegion> l_nm_regions;
        std::vector<MemRegion> l_m_regions;

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

            // retrieve base address attributes (computed by prior opt_memmap call)
            rc = FAPI_ATTR_GET(ATTR_PROC_MEM_BASE,
                               iv_target,
                               l_nm_base);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_PROC_MEM_BASE)");
                break;
            }
            iv_nm.setBase(l_nm_base);

            rc = FAPI_ATTR_GET(ATTR_PROC_MIRROR_BASE,
                               iv_target,
                               l_m_base);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_PROC_MIRROR_BASE)");
                break;
            }
            iv_m.setBase(l_m_base);

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
            FAPI_INF("Process Chip n%d:p%d: Begin", iv_node_id, iv_chip_id);
            for (uint8_t i = 0; i < OPT_MEMMAP_MAX_NM_REGIONS; i++)
            {
                if (l_nm_sizes[i] != 0)
                {
                    FAPI_INF("  nm_bases[%d] = 0x%016llX", i, l_nm_bases[i]);
                    FAPI_INF("  nm_sizes[%d] = 0x%016llX", i, l_nm_sizes[i]);
                    MemRegion r(MemRegion::nm, l_nm_bases[i], l_nm_sizes[i]);
                    l_nm_regions.push_back(r);
                }
            }

            // populate mirrored regions
            for (uint8_t i = 0; i < OPT_MEMMAP_MAX_M_REGIONS; i++)
            {
                if (l_m_sizes[i] != 0)
                {
                    // align to common origin
                    FAPI_INF("   m_bases[%d] = 0x%016llX", i, l_m_bases[i]);
                    FAPI_INF("   m_sizes[%d] = 0x%016llX", i, l_m_sizes[i]);
                    MemRegion r(MemRegion::m, l_m_bases[i], l_m_sizes[i]);
                    l_m_regions.push_back(r);
                }
            }

            // sort regions for effective size calculations
            std::sort(l_nm_regions.begin(), l_nm_regions.end());
            std::sort(l_m_regions.begin(), l_m_regions.end());

            // compute effective size of chip address space associated with
            // each stack (rounded up to a power of 2)
            if (l_nm_regions.size() != 0)
            {
//                if (iv_nm.getBase() != l_nm_regions[0].getBase())
//                {
//                    const uint64_t& ADDR = iv_nm.getBase();
//                    FAPI_ERR("Unexpected value returned for ATTR_PROC_MEM_BASE (='0x%016llX')",
//                             iv_nm.getBase());
//                    FAPI_SET_HWP_ERROR(rc, RC_OPT_MEMMAP_MEM_BASE_ERR);
//                    break;
//                }

                iv_nm.setSize(l_nm_regions[l_nm_regions.size()-1].getBase() -
                              l_nm_regions[0].getBase() +
                              l_nm_regions[l_nm_regions.size()-1].getSize());
                if (!iv_nm.isPowerOf2())
                {
                    iv_nm.roundNextPowerOf2();
                }
            }
            else
            {
                iv_nm.setSize(0);
            }
            FAPI_INF("  nm_eff_size = 0x%016llX", iv_nm.getSize());

            if (l_m_regions.size() != 0)
            {
//                if (iv_m.getBase() != l_m_regions[0].getBase())
//                {
//                    const uint64_t& ADDR = iv_m.getBase();
//                    FAPI_ERR("Unexpected value returned for ATTR_PROC_MIRROR_BASE (='0x%016llX')",
//                             iv_m.getBase());
//                    FAPI_SET_HWP_ERROR(rc, RC_OPT_MEMMAP_MIRROR_BASE_ERR);
//                    break;
//                }

                iv_m.setSize(l_m_regions[l_m_regions.size()-1].getBase() -
                             l_m_regions[0].getBase() +
                             l_m_regions[l_m_regions.size()-1].getSize());
                if (!iv_m.isPowerOf2())
                {
                    iv_m.roundNextPowerOf2();
                }
            }
            else
            {
                iv_m.setSize(0);
            }
            FAPI_INF("   m_eff_size = 0x%016llX", iv_m.getSize());
            FAPI_INF("Process Chip: End");

        } while(0);

        return rc;
    }

    // return group ID
    uint8_t getGroupID() const
    {
        uint8_t pos = ((4*iv_node_id)+iv_chip_id);
        return((iv_chip_as_group)?(pos):(iv_node_id));
    }

    // return specified region size
    uint64_t getSize(const MemRegion::type type) const
    {
        return((type == MemRegion::nm)?(iv_nm.getSize()):(iv_m.getSize()));
    }

    // establish new base address for this chip
    void setBase(const MemRegion::type type, const uint64_t& base)
    {
        if (type == MemRegion::nm)
        {
            iv_nm.setBase(base);
        }
        else
        {
            iv_m.setBase(base);
        }
    }

    // flush state back to attributes
    ReturnCode flushAttributes()
    {
        ReturnCode rc;
        uint64_t nm_base = iv_nm.getBase();
        uint64_t m_base = iv_m.getBase();

        FAPI_INF("Stack Chip n%d:p%d: Begin", iv_node_id, iv_chip_id);
        FAPI_INF("  nm_base: 0x%016llX", nm_base);
        FAPI_INF("   m_base: 0x%016llX", m_base);
        do
        {
            // set base addresses
            rc = FAPI_ATTR_SET(ATTR_PROC_MEM_BASE,
                               iv_target,
                               nm_base);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_SET (ATTR_PROC_MEM_BASE)");
                break;
            }

            rc = FAPI_ATTR_SET(ATTR_PROC_MIRROR_BASE,
                               iv_target,
                               m_base);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_SET (ATTR_PROC_MIRROR_BASE)");
                break;
            }

        } while(0);
        FAPI_INF("Stack Chip: End");
        return rc;
    }

private:
    // pointer to processor chip target
    Target *iv_target;
    // sort criteria
    MemRegion::type iv_sort;
    // chip position information
    bool iv_chip_as_group;
    uint8_t iv_node_id;
    uint8_t iv_chip_id;
    // chip effective non-mirrored region
    MemRegion iv_nm;
    // chip effective mirrored region
    MemRegion iv_m;
};


// class to represent group in drawer memory map
class ProcGroupMemmap
{
public:
    // constructor
    ProcGroupMemmap(uint8_t group_id, uint8_t mirror_policy, MemRegion::type sort) :
        iv_group_id(group_id), iv_mirror_policy(mirror_policy), iv_sort(sort), iv_nm(MemRegion::nm), iv_m(MemRegion::m) {}

    // comparison operator for sort
    // sort in increasing size, and decreasing node ID
    // e.g. group2 and group0 have same size, then the order will be
    // group2 then group0
    bool operator < (const ProcGroupMemmap & rhs) const
    {
        bool l_lt = true;
        // perform sort comparison
        MemRegion l = ((iv_sort == MemRegion::nm)?(iv_nm):(iv_m));
        MemRegion r = ((iv_sort == MemRegion::nm)?(rhs.iv_nm):(rhs.iv_m));
        if ((l > r) ||
            ((l == r) && (iv_group_id < rhs.iv_group_id)))
        {
            l_lt = false;
        }
        return l_lt;
    }

    // retreive group ID
    uint8_t getGroupID() const { return iv_group_id; }

    // add chip to group
    void addChip(const ProcChipMemmap & chip)
    {
        iv_nm.setSize(iv_nm.getSize() + chip.getSize(MemRegion::nm));
        iv_m.setSize(iv_m.getSize() + chip.getSize(MemRegion::m));
        iv_chips.push_back(chip);
    }
    
    // finalize effective group size
    void processGroup()
    {
        FAPI_INF("Process Group %d: Begin", iv_group_id);
        // sort member chips based on their effective stackable sizes
        // individual chip sizes should already be power-of-2 aligned
        std::sort(iv_chips.begin(), iv_chips.end());

        // ensure size is rounded to power-of-2
        if (!iv_nm.isPowerOf2())
        {
            iv_nm.roundNextPowerOf2();
        }
        if (!iv_m.isPowerOf2())
        {
            iv_m.roundNextPowerOf2();
        }
        FAPI_INF("  nm_eff_size = 0x%016llX", iv_nm.getSize());
        FAPI_INF("   m_eff_size = 0x%016llX", iv_m.getSize());
        FAPI_INF("Process Group: End");
    }

    // return specified region size
    uint64_t getSize(const MemRegion::type type) const
    {
        return((type == MemRegion::nm)?(iv_nm.getSize()):(iv_m.getSize()));
    }

    // walk through member chips, from largest->smallest effective size
    // assign base addresses for each
    ReturnCode stackChips(uint64_t nm_base, uint64_t m_base)
    {
        ReturnCode rc;
        uint64_t l_nm_base_curr = nm_base;
        uint64_t l_m_base_curr = m_base;

        iv_nm.setBase(nm_base);
        iv_m.setBase(m_base);

        FAPI_INF("Stack Group %d: Begin", iv_group_id);
        for (uint8_t i = iv_chips.size();
             i != 0;
             --i)
        {
            // establish base addresses for each chip & realign
            // all groups on this chip to reflect this
            iv_chips[i-1].setBase(MemRegion::nm, l_nm_base_curr);
            iv_chips[i-1].setBase(MemRegion::m, l_m_base_curr);
            l_nm_base_curr += iv_chips[i-1].getSize(MemRegion::nm);

            if ((iv_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL) ||
                (iv_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_DRAWER))
            {
                l_m_base_curr += iv_chips[i-1].getSize(MemRegion::nm) / 2;
            }
            else
            {
                l_m_base_curr += iv_chips[i-1].getSize(MemRegion::m);
            }

            // flush attributes for this chip
            rc = iv_chips[i-1].flushAttributes();
            if (!rc.ok())
            {
                FAPI_ERR("Error from flushAttributes");
                break;
            }
        }

        FAPI_INF("Stack Group: End");
        return rc;
    }

private:
    // collection of member chips
    std::vector<ProcChipMemmap> iv_chips;
    // group ID
    uint8_t iv_group_id;
    // mirroring policy/sort criteria
    uint8_t iv_mirror_policy;
    MemRegion::type iv_sort;
    // effective sizes
    MemRegion iv_nm;
    MemRegion iv_m;

};


// class to represent memory map at drawer scope
class ProcDrawerMemmap
{

public:
    // constructor
    ProcDrawerMemmap(uint8_t mirror_policy, uint8_t group_policy, uint64_t alt_origin, uint8_t drawer_id) :
        iv_mirror_policy(mirror_policy), iv_group_policy(group_policy), iv_alt_origin(alt_origin), iv_drawer_id(drawer_id)
    {
        // establish base address values based on memory map policy
        if ((iv_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL) ||
            (iv_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_DRAWER))
        {
            iv_sort_policy = MemRegion::nm;
            iv_nm_base = OPT_MEMMAP_BASE_ORIGIN + (iv_drawer_id * 32 * OPT_MEMMAP_TB);
            iv_m_base = iv_alt_origin + (iv_nm_base / 2);
        }
        else if ((iv_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED) ||
                 (iv_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED_DRAWER))
        {
            iv_sort_policy = MemRegion::m;
            iv_m_base = OPT_MEMMAP_BASE_ORIGIN + (iv_drawer_id * 32 * OPT_MEMMAP_TB);
            iv_nm_base = iv_alt_origin + iv_m_base;

        }
    }

    // return drawer sort/ordering policies
    MemRegion::type getSortPolicy() const { return iv_sort_policy; }
    bool getGroupPolicy() const { return (iv_group_policy == ENUM_ATTR_OPT_MEMMAP_GROUP_POLICY_CHIP_AS_GROUP); }

    uint64_t getBase(MemRegion::type type)
    {
        if (type == MemRegion::nm) { return iv_nm_base; }
        else { return iv_m_base; }
    }

    // chip processing function
    ReturnCode insertChip(ProcChipMemmap chip)
    {
        ReturnCode rc;

        // search for matching group
        uint8_t group_match_count = 0;
        for (std::vector<ProcGroupMemmap>::iterator g = iv_groups.begin();
             g != iv_groups.end();
             g++)
        {
            // add to existing group
            if (chip.getGroupID() == g->getGroupID())
            {
                g->addChip(chip);
                group_match_count++;
            }
        }
        // create group if no matches found
        if (group_match_count == 0)
        {
            ProcGroupMemmap new_group(chip.getGroupID(), iv_mirror_policy, iv_sort_policy);
            new_group.addChip(chip);
            iv_groups.push_back(new_group);
        }
        // multiple group matches were found, error
        else if (group_match_count != 1)
        {
            const uint8_t& GROUP_ID = chip.getGroupID();
            const uint8_t& MATCH_COUNT = group_match_count;
            FAPI_ERR("Internal error, chip matched multiple group IDs (=%d)",
                     chip.getGroupID());
            FAPI_SET_HWP_ERROR(rc, RC_OPT_MEMMAP_GROUP_ERR);
        }
        return rc;
    }

    // drawer processing function
    ReturnCode processDrawer()
    {
        ReturnCode rc;
        FAPI_INF("Process Drawer: Begin");

        // determine effective size of each group
        for (std::vector<ProcGroupMemmap>::iterator g = iv_groups.begin();
             g != iv_groups.end();
             g++)
        {
            g->processGroup();
        }

        // order groups by effective size
        std::sort(iv_groups.begin(), iv_groups.end());

        FAPI_INF("Stack Drawer: Begin");
        // walk through groups, from largest->smallest effective size
        for (uint8_t i = iv_groups.size();
             i != 0;
             --i)
        {
            // establish base addresses for group
            rc = iv_groups[i-1].stackChips(iv_nm_base, iv_m_base);
            if (!rc.ok())
            {
                break;
            }

            // establish base addresses for next group
            iv_nm_base += iv_groups[i-1].getSize(MemRegion::nm);
            if ((iv_mirror_policy ==
                 ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL) ||
                (iv_mirror_policy ==
                 ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_DRAWER))
            {
                iv_m_base += iv_groups[i-1].getSize(MemRegion::nm) / 2;
            }
            else
            {
                iv_m_base += iv_groups[i-1].getSize(MemRegion::m);
            }
        }

        FAPI_INF("Stack Drawer: End");
        FAPI_INF("Process Drawer: End");
        return rc;
    }

private:
    // collection of member groups
    std::vector<ProcGroupMemmap> iv_groups;

    // mirror policy
    uint8_t iv_mirror_policy;
    uint8_t iv_group_policy;
    MemRegion::type iv_sort_policy;
    uint64_t iv_alt_origin;
    uint8_t iv_drawer_id;

    // current base address values
    uint64_t iv_nm_base;
    uint64_t iv_m_base;

};


// HWP entry point
ReturnCode opt_memmap(std::vector<fapi::Target> & i_procs, bool i_init)
{
    ReturnCode rc;
    uint8_t l_mirror_policy;
    uint8_t l_group_policy;
    uint64_t l_alt_origin;
    uint8_t l_drawer_id = 0;

    do
    {
        // retrieve mirroring policy/placement attributes
        rc = FAPI_ATTR_GET(ATTR_MEM_MIRROR_PLACEMENT_POLICY,
                           NULL,
                           l_mirror_policy);
        if (!rc.ok())
        {
            FAPI_ERR("Error querying ATTR_MEM_MIRROR_PLACEMENT_POLICY");
            break;
        }

        rc = FAPI_ATTR_GET(ATTR_OPT_MEMMAP_GROUP_POLICY,
                           NULL,
                           l_group_policy);
        if (!rc.ok())
        {
            FAPI_ERR("Error querying ATTR_OPT_MEMMAP_GROUP_POLICY");
            break;
        }

        rc = FAPI_ATTR_GET(ATTR_MIRROR_BASE_ADDRESS,
                           NULL,
                           l_alt_origin);
        if (!rc.ok())
        {
            FAPI_ERR("Error querying ATTR_MIRROR_BASE_ADDRESS");
            break;
        }

        // all chips in input vector must lie in same drawer
        // if required by placement policy, determine drawer number
        // (equivalent to the fabric node ID)
        if ((l_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_DRAWER) ||
            (l_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED_DRAWER))
        {
            rc = FAPI_ATTR_GET(ATTR_FABRIC_NODE_ID,
                               &(*(i_procs.begin())),
                               l_drawer_id);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_FABRIC_NODE_ID)");
                break;
            }
        }

        FAPI_INF("opt_memmap called with i_init: %d, mirror_policy: %d, group_policy: %d, alternate_origin: 0x%016llX",
                 (i_init)?(1):(0), l_mirror_policy, l_group_policy, l_alt_origin);

        // construct drawer memory map object
        ProcDrawerMemmap l_drawer(l_mirror_policy, l_group_policy, l_alt_origin, l_drawer_id);

        // process all chips in scope of drawer
        for (std::vector<fapi::Target>::iterator l_iter = i_procs.begin();
             l_iter != i_procs.end();
             l_iter++)
        {
            ProcChipMemmap l_chip(&(*l_iter), l_drawer.getSortPolicy(), l_drawer.getGroupPolicy());

            if (i_init)
            {
                l_chip.setBase(MemRegion::nm, l_drawer.getBase(MemRegion::nm));
                l_chip.setBase(MemRegion::m, l_drawer.getBase(MemRegion::m));
                rc = l_chip.flushAttributes();
                if (!rc.ok())
                {
                    FAPI_ERR("Error from flushAttributes");
                    break;
                }
            }
            else
            {
                rc = l_chip.processAttributes();
                if (!rc.ok())
                {
                    FAPI_ERR("Error from processAttributes");
                    break;
                }
                rc = l_drawer.insertChip(l_chip);
                if (!rc.ok())
                {
                    FAPI_ERR("Error from insertChip");
                    break;
                }
            }
        }
        if (!rc.ok())
        {
            break;
        }

        // process drawer to align each group & its member chips
        if (!i_init)
        {
            rc = l_drawer.processDrawer();
            if (!rc.ok())
            {
                FAPI_ERR("Error from processDrawer");
                break;
            }
        }
    } while(0);

    return rc;
}


} //end extern C
