/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/opt_memmap.C $      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: opt_memmap.C,v 1.8 2013/05/06 15:15:36 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/opt_memmap.C,v $


//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
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
// of non-mirrored/mirrored real address space on each chip in the system
//
// opt_memmap() will be called twice in the IPL flow, once before and once
// after mss_eff_grouping()
//
// 1) Call opt_memmap() with i_init = true
//    - Each proc's ATTR_PROC_MEM_BASE attribute is set to 0
//    - Each proc's ATTR_PROC_MIRROR_BASE attribute is set to 512TB
//
//    This provides a basis for mss_eff_grouping() to stack all on-chip
//    groups.
//
// 2) mss_eff_grouping() call
//    - The HWP updates each proc's ATTR_PROC_MEM_BASES and ATTR_PROC_MEM_SIZES
//      attributes based on the address regions allocated for installed memory
//      behind each proc
//    - ATTR_MSS_MCS_GROUP_32 encapsulates the properties of each group formed.
//
// 3) Call opt_memmap() with i_init = false
//    - Consume mss_eff_grouping() attributes for each proc
//    - Align the per-chip non-mirrored and mirrored stacks on each proc to
//      a common origin (0)
//    - Associate non-mirrored and mirrored partner groups
//    - Resize groups & re-stack if producing selective mirrored config
//    - Get "effective stackable" size of non-mirrored/mirrored regions
//      on each proc
//    - Stack procs based on their effective size and desired placement
//      policy
//                                         non-mirrored    mirrored
//         mirror       eff. stacking       stacking       stacking
//         policy       sort criteria        origin         origin
//        --------      -------------      ------------    --------
//         NORMAL            nm                0TB           512TB
//         FLIPPED           m                512TB           0TB
//        SELECTIVE         nm+m               0TB            0TB
//
//    - Rewrite all attributes produced by mss_eff_grouping to reflect
//      chip placement
//    - Satisfy requests for HTM/OCC memory reservations on each chip
//      (HTM requests will alter ATTR_PROC_MEM_SIZES/ATTR_PROC_MIRROR_SIZES,
//       as these must reflect the true usable memory allocated for PHYP)
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


// class to represent group of memory controllers
// shadows attribute data from mss_eff_grouping procedure
class MemGroup
{

public:

    // group type (mirrored/non-mirrored)
    enum group_type { nm = 0, m = 8 };

    // group type
    group_type iv_group_type;
    // group ID, 1st dimension index to MSS_MCS_GROUP_32[]
    uint8_t iv_group_id;
    // group ID of partner group
    uint8_t iv_partner_group_id;

    // group parameters
    uint64_t iv_size_per_mcs;
    uint8_t  iv_group_size;
    uint64_t iv_size;
    uint64_t iv_base;
    uint8_t  iv_mcs_member_ids[OPT_MEMMAP_MAX_NM_REGIONS];
    bool     iv_use_alt;
    uint64_t iv_size_alt;
    uint64_t iv_base_alt;
    uint64_t iv_biggest_mba;

    // memory allocation state
    // portion of size which will be exposed to exerciser/PHYP
    uint64_t iv_size_exposed;

    // comparison operator for sort
    bool operator < (MemGroup rhs) const
    {
        bool l_lt = true;
        if (iv_base > rhs.iv_base ||
            ((iv_base == rhs.iv_base) && (iv_size > rhs.iv_size)))
        {
            l_lt = false;
        }
        return l_lt;
    }

    // adjust base address of group (by negative offset)
    void decBase(const uint64_t& offset)
    {
        iv_base -= offset;
        if (iv_use_alt)
        {
            iv_base_alt -= offset;
        }
    }

    // adjust base address of group (positive offset)
    void incBase(const uint64_t& offset)
    {
        iv_base += offset;
        if (iv_use_alt)
        {
            iv_base_alt += offset;
        }
    }

    // halve size of group
    // assumes no allocations have been made
    void halveSize()
    {
        iv_size /= 2;
        iv_size_per_mcs /= 2;
        iv_size_exposed /= 2;

        if (iv_use_alt)
        {
            iv_size_alt /= 2;
        }

        iv_biggest_mba /= 2;
    }

    // construct from attribute data array
    MemGroup(group_type group_type, uint8_t group_id, uint32_t (*group_data)[OPT_MEMMAP_GROUP_32_DIM2])
    {
        iv_group_type = group_type;
        iv_group_id = group_id;
        iv_partner_group_id = 0xFF;

        // consume data from attributes
        iv_size_per_mcs = (uint64_t) (group_data[iv_group_type+iv_group_id][OPT_MEMMAP_GROUP_32_MCS_SIZE_INDEX]) * OPT_MEMMAP_GB;
        iv_group_size = (uint8_t)  (group_data[iv_group_type+iv_group_id][OPT_MEMMAP_GROUP_32_MCS_IN_GROUP_INDEX]);
        iv_size = (uint64_t) (group_data[iv_group_type+iv_group_id][OPT_MEMMAP_GROUP_32_SIZE_INDEX]) * OPT_MEMMAP_GB;
        iv_base = (uint64_t) (group_data[iv_group_type+iv_group_id][OPT_MEMMAP_GROUP_32_BASE_INDEX]) * OPT_MEMMAP_GB;
        for (uint8_t i = OPT_MEMMAP_GROUP_32_MEMBERS_START_INDEX;
             i <= OPT_MEMMAP_GROUP_32_MEMBERS_END_INDEX;
             i++)
        {
            if (i < (OPT_MEMMAP_GROUP_32_MEMBERS_START_INDEX + iv_group_size))
            {
                iv_mcs_member_ids[i-OPT_MEMMAP_GROUP_32_MEMBERS_START_INDEX] = (uint8_t) (group_data[iv_group_type+iv_group_id][i]);
            }
            else
            {
                iv_mcs_member_ids[i-OPT_MEMMAP_GROUP_32_MEMBERS_START_INDEX] = 0xFF;
            }
        }

        iv_use_alt  = group_data[iv_group_type+iv_group_id][OPT_MEMMAP_GROUP_32_ALT_VALID_INDEX]?(true):(false);
        iv_size_alt = (uint64_t) (group_data[iv_group_type+iv_group_id][OPT_MEMMAP_GROUP_32_ALT_SIZE_INDEX]) * OPT_MEMMAP_GB;
        iv_base_alt = (uint64_t) (group_data[iv_group_type+iv_group_id][OPT_MEMMAP_GROUP_32_ALT_BASE_INDEX]) * OPT_MEMMAP_GB;
        iv_biggest_mba = (uint64_t) (group_data[iv_group_type+iv_group_id][OPT_MEMMAP_GROUP_32_LARGEST_MBA_INDEX]) * OPT_MEMMAP_GB;

        // mark all size as exposed
        iv_size_exposed = iv_size;
    }

    // debug function
    void dumpGroup()
    {
        FAPI_DBG("Group %d [ %s ]", iv_group_id, (iv_group_type == nm)?("nm"):("m"));
        FAPI_DBG("  Base: %016llX", iv_base);
        FAPI_DBG("  Size: %016llX", iv_size);
        FAPI_DBG("   MCs: %d [ %016llX ]", iv_group_size, iv_size_per_mcs);
        for (uint8_t i = 0; i < iv_group_size; i++)
        {
            FAPI_DBG("      : %d", iv_mcs_member_ids[i]);
        }
        FAPI_DBG("     Alt: %s", (iv_use_alt)?("true"):("false"));
        FAPI_DBG("   ABase: %016llX", iv_base_alt);
        FAPI_DBG("   ASize: %016llX", iv_size_alt);
        FAPI_DBG(" Big MBA: %016llX", iv_biggest_mba);
    }

    // flush back to attribute data array
    void flushAttributes(uint64_t chip_bases[], uint64_t chip_sizes[], uint32_t (*group_data)[OPT_MEMMAP_GROUP_32_DIM2])
    {
        // chip size/range attribute arrays expect addresses in B
        chip_bases[iv_group_id] = iv_base;
        chip_sizes[iv_group_id] = iv_size_exposed;

        // group attribute arrays expect addresses in GB
        group_data[iv_group_type+iv_group_id][OPT_MEMMAP_GROUP_32_MCS_SIZE_INDEX] = (uint32_t) ((iv_size_per_mcs) / OPT_MEMMAP_GB);
        group_data[iv_group_type+iv_group_id][OPT_MEMMAP_GROUP_32_MCS_IN_GROUP_INDEX] = iv_group_size;
        group_data[iv_group_type+iv_group_id][OPT_MEMMAP_GROUP_32_SIZE_INDEX] = (uint32_t) ((iv_size) / OPT_MEMMAP_GB);
        group_data[iv_group_type+iv_group_id][OPT_MEMMAP_GROUP_32_BASE_INDEX] = (uint32_t) ((iv_base) / OPT_MEMMAP_GB);

        for (uint8_t i = OPT_MEMMAP_GROUP_32_MEMBERS_START_INDEX;
             i <= OPT_MEMMAP_GROUP_32_MEMBERS_END_INDEX;
             i++)
        {
            group_data[iv_group_type+iv_group_id][i] = iv_mcs_member_ids[i-OPT_MEMMAP_GROUP_32_MEMBERS_START_INDEX];

        }

        group_data[iv_group_type+iv_group_id][OPT_MEMMAP_GROUP_32_ALT_VALID_INDEX] = (iv_use_alt)?(1):(0);
        group_data[iv_group_type+iv_group_id][OPT_MEMMAP_GROUP_32_ALT_SIZE_INDEX] = (uint32_t) ((iv_size_alt) / OPT_MEMMAP_GB);
        group_data[iv_group_type+iv_group_id][OPT_MEMMAP_GROUP_32_ALT_BASE_INDEX] = (uint32_t) ((iv_base_alt) / OPT_MEMMAP_GB);
        group_data[iv_group_type+iv_group_id][OPT_MEMMAP_GROUP_32_LARGEST_MBA_INDEX] = (uint32_t) ((iv_biggest_mba) / OPT_MEMMAP_GB);
    }

    // memory allocation function
    // returns true if request can be wholly satisfied by this group,
    // false otherwise
    bool allocate(uint64_t size_req)
    {
        if (size_req <= iv_size_exposed)
        {
            iv_size_exposed -= size_req;
            return true;
        }
        else
        {
            iv_size_exposed = 0;
            return false;
        }
    }
};


// class to represent memory map (non-mirrored/mirrored) on one processor chip
class ProcChipMemmap
{

public:
    static const uint8_t PROC_CHIP_MEMMAP_NUM_ALLOCATIONS = 2;
    static const uint8_t PROC_CHIP_MEMMAP_HTM_ALLOC_INDEX = 0;
    static const uint8_t PROC_CHIP_MEMMAP_OCC_ALLOC_INDEX = 1;

    // pointer to processor chip target
    Target *iv_target;
    // mirroring policy
    uint8_t iv_mirror_policy;

    // chip location information
    uint8_t iv_pos;
    uint8_t iv_node_id;
    uint8_t iv_chip_id;

    // chip non-mirrored base, effective size, and member groups
    uint64_t iv_nm_base;
    uint64_t iv_nm_eff_size;
    std::vector<MemGroup> iv_nm_groups;

    // chip mirrored base, effective size, and member groups
    uint64_t iv_m_base;
    uint64_t iv_m_eff_size;
    std::vector<MemGroup> iv_m_groups;

    // base/size for allocated memory areas
    uint64_t iv_alloc_size[PROC_CHIP_MEMMAP_NUM_ALLOCATIONS];
    uint64_t iv_alloc_base[PROC_CHIP_MEMMAP_NUM_ALLOCATIONS];

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
        if ((iv_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL) &&
            (rhs.iv_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL))
        {
            l_this_eff_size = iv_nm_eff_size;
            l_rhs_eff_size  = rhs.iv_nm_eff_size;
        }
        // sort by mirrored size
        else if ((iv_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED) &&
                 (rhs.iv_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED))
        {
            l_this_eff_size = iv_m_eff_size;
            l_rhs_eff_size  = rhs.iv_m_eff_size;
        }
        // sort by sum of non-mirrored/mirrored sizes
        else if ((iv_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_SELECTIVE) &&
                 (rhs.iv_mirror_policy == ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_SELECTIVE))
        {
            l_this_eff_size = PowerOf2Roundedup(iv_nm_eff_size  + iv_m_eff_size);
            l_rhs_eff_size  = PowerOf2Roundedup(rhs.iv_nm_eff_size + rhs.iv_m_eff_size);
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
        uint32_t l_mss_mcs_group_32[OPT_MEMMAP_GROUP_32_DIM1][OPT_MEMMAP_GROUP_32_DIM2];

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

            // retrieve base address for each chip, align to common origin
            rc = FAPI_ATTR_GET(ATTR_PROC_MEM_BASE,
                               iv_target,
                               iv_nm_base);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_PROC_MEM_BASE)");
                break;
            }
            if (iv_nm_base != OPT_MEMMAP_BASE_ORIGIN)
            {
                const uint64_t& ADDR = iv_nm_base;
                FAPI_ERR("Unexpected value returned for ATTR_PROC_MEM_BASE (=%016llX)",
                         iv_nm_base);
                FAPI_SET_HWP_ERROR(rc, RC_OPT_MEMMAP_MEM_BASE_ERR);
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
            if (iv_m_base != OPT_MEMMAP_OFFSET_ORIGIN)
            {
                const uint64_t& ADDR = iv_m_base;
                FAPI_ERR("Unexpected value returned for ATTR_PROC_MIRROR_BASE (=%016llX)",
                         iv_m_base);
                FAPI_SET_HWP_ERROR(rc, RC_OPT_MEMMAP_MIRROR_BASE_ERR);
                break;
            }
            iv_m_base -= OPT_MEMMAP_OFFSET_ORIGIN;

            // retrieve regions (bases and sizes) computed by mss_eff_grouping
            rc = FAPI_ATTR_GET(ATTR_PROC_MEM_BASES,
                               iv_target,
                               l_nm_bases);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_PROC_MEM_BASES)");
                break;
            }

            rc = FAPI_ATTR_GET(ATTR_PROC_MEM_SIZES,
                               iv_target,
                               l_nm_sizes);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_PROC_MEM_SIZES)");
                break;
            }
            rc = FAPI_ATTR_GET(ATTR_PROC_MIRROR_BASES,
                               iv_target,
                               l_m_bases);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_PROC_MIRROR_BASES)");
                break;
            }

            rc = FAPI_ATTR_GET(ATTR_PROC_MIRROR_SIZES,
                               iv_target,
                               l_m_sizes);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_PROC_MIRROR_SIZES)");
                break;
            }

            // retrieve data structure describing groups formed by mss_eff_grouping
            rc = FAPI_ATTR_GET(ATTR_MSS_MCS_GROUP_32,
                               iv_target,
                               l_mss_mcs_group_32);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_MSS_MCS_GROUP_32)");
                break;
            }

            // populate non-mirrored groups
            FAPI_INF("Chip n%d:p%d", iv_node_id, iv_chip_id);
            for (uint8_t i = 0; i < OPT_MEMMAP_MAX_NM_REGIONS; i++)
            {
                if (l_nm_sizes[i] != 0)
                {
                    FAPI_INF("  l_nm_bases[%d] = %016llX", i, l_nm_bases[i]);
                    FAPI_INF("  l_nm_sizes[%d] = %016llX", i, l_nm_sizes[i]);
                    MemGroup g(MemGroup::nm, i, l_mss_mcs_group_32);
                    if ((l_nm_bases[i] != g.iv_base) ||
                        (l_nm_sizes[i] != g.iv_size))
                    {
                        const uint8_t& GROUP = i;
                        const uint64_t& MEM_BASES = l_nm_bases[i];
                        const uint64_t& MEM_SIZES = l_nm_sizes[i];
                        const uint64_t& GROUP_BASE = g.iv_base;
                        const uint64_t& GROUP_SIZE = g.iv_size;
                        FAPI_ERR("Inconsistent non-mirrored group content");
                        FAPI_SET_HWP_ERROR(rc,
                                           RC_OPT_MEMMAP_NON_MIRROR_GROUP_ERR);
                        break;
                    }
                    iv_nm_groups.push_back(g);
                }
            }
            if (!rc.ok())
            {
                break;
            }

            // populate mirrored groups
            for (uint8_t i = 0; i < OPT_MEMMAP_MAX_M_REGIONS; i++)
            {
                if (l_m_sizes[i] != 0)
                {
                    // align to common origin
                    l_m_bases[i] -= OPT_MEMMAP_OFFSET_ORIGIN;
                    FAPI_INF("  l_m_bases[%d] = %016llX", i, l_m_bases[i]);
                    FAPI_INF("  l_m_sizes[%d] = %016llX", i, l_m_sizes[i]);
                    MemGroup g(MemGroup::m, i, l_mss_mcs_group_32);
                    // align to common origin
                    g.decBase(OPT_MEMMAP_OFFSET_ORIGIN);
                    if ((l_m_bases[i] != g.iv_base) ||
                        (l_m_sizes[i] != g.iv_size))
                    {
                        const uint8_t& GROUP = i;
                        const uint64_t& MIRROR_BASES = l_m_bases[i];
                        const uint64_t& MIRROR_SIZES = l_m_sizes[i];
                        const uint64_t& GROUP_BASE = g.iv_base;
                        const uint64_t& GROUP_SIZE = g.iv_size;
                        FAPI_ERR("Inconsistent mirrored group content");
                        FAPI_SET_HWP_ERROR(rc,
                                           RC_OPT_MEMMAP_MIRROR_GROUP_ERR);
                        break;
                    }
                    iv_m_groups.push_back(g);
                }
            }
            if (!rc.ok())
            {
                break;
            }

            // dump configuration for non-mirrored groups
            for (uint8_t i = 0; i < iv_nm_groups.size(); i++)
            {
                iv_nm_groups[i].dumpGroup();
            }
            // link mirrored group with their non-mirrored partner
            for (uint8_t i = 0; i < iv_m_groups.size(); i++)
            {
                // loop through all non-mirrored groups
                // until a match is found
                bool match = false;
                for (uint8_t j = 0; (j < iv_nm_groups.size()) && (!match); j++)
                {
                    // sizes match?
                    match = ((iv_m_groups[i].iv_group_id ==
                              iv_nm_groups[j].iv_group_id) &&
                             (iv_m_groups[i].iv_size ==
                              (iv_nm_groups[j].iv_size / 2)));
                    if (match)
                    {
                        // set MCS unit parameters for mirrored group
                        for (uint8_t k = 0; k < OPT_MEMMAP_MAX_NM_REGIONS; k++)
                        {
                            iv_m_groups[i].iv_mcs_member_ids[k] =
                                iv_nm_groups[j].iv_mcs_member_ids[k];
                        }
                        iv_m_groups[i].iv_group_size =
                            iv_nm_groups[j].iv_group_size;
                        iv_m_groups[i].iv_size_per_mcs =
                            iv_m_groups[i].iv_size /
                            iv_m_groups[i].iv_group_size;

                        // link groups
                        iv_m_groups[i].iv_partner_group_id = iv_nm_groups[j].iv_group_id;
                        iv_nm_groups[j].iv_partner_group_id = iv_m_groups[i].iv_group_id;
                    }
                }
                // valid mirrored group, but couldn't find non-mirrored partner
                if (!match)
                {
                    const uint8_t& GROUP = i;
                    FAPI_ERR("Unable to find non-mirrored group partner for mirrored group!");
                    FAPI_SET_HWP_ERROR(rc, RC_OPT_MEMMAP_GROUP_PARTNER_ERR);
                    break;
                }
                // dump configuration for mirrored group
                iv_m_groups[i].dumpGroup();
            }
            if (!rc.ok())
            {
                break;
            }

            // compress/re-stack groups for the selective mirror configuration
            if (iv_mirror_policy ==
                ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_SELECTIVE)
            {
                for (uint8_t i = 0; i < iv_nm_groups.size(); i++)
                {
                    // only multi-member groups (with a mirrrored partner) will
                    // change in size
                    if ((iv_nm_groups[i].iv_group_size != 1) &&
                        (iv_nm_groups[i].iv_partner_group_id != 0xFF))
                    {
                        iv_nm_groups[i].halveSize();
                        for (uint8_t j = 0; j < iv_m_groups.size(); j++)
                        {
                            if (iv_nm_groups[i].iv_partner_group_id ==
                                iv_m_groups[j].iv_group_id)
                            {
                                iv_m_groups[j].halveSize();
                            }
                        }
                    }
                }

                // realign each group to origin
                for (uint8_t i = 0; i < iv_nm_groups.size(); i++)
                {
                    iv_nm_groups[i].decBase(iv_nm_groups[i].iv_base);
                }
                for (uint8_t i = 0; i < iv_m_groups.size(); i++)
                {
                    iv_m_groups[i].decBase(iv_m_groups[i].iv_base);
                }

                // re-stack set of groups, largest->smallest
                uint64_t l_nm_group_base = OPT_MEMMAP_BASE_ORIGIN;
                std::sort(iv_nm_groups.begin(), iv_nm_groups.end());
                for (uint8_t i = iv_nm_groups.size(); i != 0; --i)
                {
                    iv_nm_groups[i-1].incBase(l_nm_group_base);
                    l_nm_group_base += iv_nm_groups[i-1].iv_size;
                }

                uint64_t l_m_group_base = OPT_MEMMAP_BASE_ORIGIN;
                std::sort(iv_m_groups.begin(), iv_m_groups.end());
                for (uint8_t i = iv_m_groups.size(); i != 0; --i)
                {
                    iv_m_groups[i-1].incBase(l_m_group_base);
                    l_m_group_base += iv_m_groups[i-1].iv_size;
                }
            }

            // sort regions for effective size calculations
            std::sort(iv_nm_groups.begin(), iv_nm_groups.end());
            std::sort(iv_m_groups.begin(), iv_m_groups.end());

            // compute effective size of chip address space
            // this is simply the end address of the last region in
            // each stack (rounded up to a power of 2)
            if (iv_nm_groups.size() != 0)
            {
                iv_nm_eff_size = iv_nm_groups[iv_nm_groups.size()-1].iv_base;
                iv_nm_eff_size += iv_nm_groups[iv_nm_groups.size()-1].iv_size;
                iv_nm_eff_size = PowerOf2Roundedup(iv_nm_eff_size);
            }
            else
            {
                iv_nm_eff_size = 0;
            }
            FAPI_INF("  nm_eff_size = %016llX", iv_nm_eff_size);

            if (iv_m_groups.size() != 0)
            {
                iv_m_eff_size = iv_m_groups[iv_m_groups.size()-1].iv_base;
                iv_m_eff_size += iv_m_groups[iv_m_groups.size()-1].iv_size;
                iv_m_eff_size = PowerOf2Roundedup(iv_m_eff_size);
            }
            else
            {
                iv_m_eff_size = 0;
            }
            FAPI_INF("  m_eff_size = %016llX", iv_m_eff_size);

            // retrieve request for HTM/OCC address space
            rc = FAPI_ATTR_GET(ATTR_PROC_HTM_BAR_SIZE,
                               iv_target,
                               iv_alloc_size[PROC_CHIP_MEMMAP_HTM_ALLOC_INDEX]);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_PROC_HTM_BAR_SIZE)");
                break;
            }

            rc = FAPI_ATTR_GET(ATTR_PROC_OCC_SANDBOX_SIZE,
                               iv_target,
                               iv_alloc_size[PROC_CHIP_MEMMAP_OCC_ALLOC_INDEX]);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_GET (ATTR_PROC_OCC_SANDBOX_SIZE)");
                break;
            }
        } while(0);

        return rc;
    }

    // establish new non-mirrored base address for this chip
    // and adjust all groups to track
    void setNMBase(const uint64_t& base)
    {
        iv_nm_base = base;
        for (uint8_t i = 0; i < iv_nm_groups.size(); ++i)
        {
            iv_nm_groups[i].incBase(base);
        }
    }

    // establish new mirrored base address for this chip
    // and adjust all groups to track
    void setMBase(const uint64_t& base)
    {
        iv_m_base = base;
        for (uint8_t i = 0; i < iv_m_groups.size(); ++i)
        {
            iv_m_groups[i].incBase(base);
        }
    }

    // allocate HTM/OCC memory requests for this chip
    ReturnCode allocate()
    {
        ReturnCode rc;

        // groups have already been sorted for stacking
        // build ordered list of groups to consider in service of
        // allocation requests, based on mirroring mode
        std::vector<MemGroup*> alloc_groups;

        do
        {
            if (iv_mirror_policy ==
                ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_SELECTIVE)
            {
                // mirrored groups occupy highest address space,
                // then non-mirrored, all are independent
                alloc_groups.resize(iv_m_groups.size()+
                                    iv_nm_groups.size());
                for (uint8_t i = 0; i < iv_m_groups.size(); i++)
                {
                    alloc_groups[iv_m_groups.size()-1-i] = &(iv_m_groups[i]);
                }
                for (uint8_t i = 0; i < iv_nm_groups.size(); i++)
                {
                    alloc_groups[iv_m_groups.size()+iv_nm_groups.size()-1-i] = &(iv_nm_groups[i]);
                }
            }
            else if (iv_mirror_policy ==
                     ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED)
            {
                // perform allocation in mirrored space,
                // adjust non-mirrored partner group
                alloc_groups.resize(iv_m_groups.size());
                for (uint8_t i = 0; i < iv_m_groups.size(); i++)
                {
                    alloc_groups[iv_m_groups.size()-1-i] = &(iv_m_groups[i]);
                }
            }
            else
            {
                // perform allocation in non-mirrored space,
                // adjust mirrored partner group
                alloc_groups.resize(iv_nm_groups.size());
                for (uint8_t i = 0; i < iv_nm_groups.size(); i++)
                {
                    alloc_groups[iv_nm_groups.size()-1-i] = &(iv_nm_groups[i]);
                }
            }

            // perform allocations
            for (uint8_t r = 0;
                 (r < PROC_CHIP_MEMMAP_NUM_ALLOCATIONS) && rc.ok();
                 r++)
            {
                uint64_t alloc_size_req = iv_alloc_size[r];
                iv_alloc_base[r] = 0;

                if (alloc_size_req != 0)
                {
                    bool alloc_done = false;
                    for (uint8_t i = 0;
                         (i < alloc_groups.size()) && !alloc_done;
                         i++)
                    {
                        FAPI_DBG("Searching group %d for allocation %d (remaining size: %016llX)",
                                 i, r, alloc_size_req);
                        // allocate from primary group
                        alloc_done = alloc_groups[i]->allocate(alloc_size_req);
                        // take allocation from partner group as well
                        if (iv_mirror_policy ==
                            ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED)
                        {
                            FAPI_DBG("Registering allocation with partner non-mirrored group");
                            for (uint8_t j = 0; j < iv_nm_groups.size(); j++)
                            {
                                if (alloc_groups[i]->iv_partner_group_id ==
                                    iv_nm_groups[j].iv_group_id)
                                {
                                   (void) iv_nm_groups[j].allocate(
                                        alloc_size_req * 2);
                                }
                            }
                        }
                        else if (iv_mirror_policy ==
                                 ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL)
                        {
                            if (alloc_groups[i]->iv_partner_group_id != 0xFF)
                            {
                                FAPI_DBG("Registering allocation with partner mirrored group");
                                for (uint8_t j = 0; j < iv_m_groups.size(); j++)
                                {
                                    if (alloc_groups[i]->iv_partner_group_id ==
                                        iv_m_groups[j].iv_group_id)
                                    {
                                        (void) iv_m_groups[j].allocate(
                                            alloc_size_req / 2);
                                    }
                                }
                            }
                        }
                        // if allocation is not completely satisfied, compute
                        // size request for next iteration
                        if (!alloc_done)
                        {
                            alloc_size_req -= alloc_groups[i]->iv_size_exposed;
                        }
                        else
                        {
                            iv_alloc_base[r] = alloc_groups[i]->iv_base +
                                               alloc_groups[i]->iv_size_exposed;
                        }
                    }
                    if (!alloc_done)
                    {
                        const uint8_t& ALLOC_INDEX = r;
                        FAPI_ERR("Unable to satisfy %s memory request, size requested exceeds available memory!",
                                 (r == 0)?("HTM"):("OCC"));
                        FAPI_SET_HWP_ERROR(rc, RC_OPT_MEMMAP_ALLOC_ERR);
                        break;
                    }
                }
            }
        } while(0);

        return rc;
    }

    // flush group state back to attributes
    ReturnCode flushAttributes()
    {
        ReturnCode rc;
        uint64_t l_mem_bases[OPT_MEMMAP_MAX_NM_REGIONS];
        uint64_t l_mem_sizes[OPT_MEMMAP_MAX_NM_REGIONS];
        uint64_t l_mirror_bases[OPT_MEMMAP_MAX_M_REGIONS];
        uint64_t l_mirror_sizes[OPT_MEMMAP_MAX_M_REGIONS];
        uint32_t l_mss_mcs_group_32[OPT_MEMMAP_GROUP_32_DIM1][OPT_MEMMAP_GROUP_32_DIM2];

        do
        {
            // init attribute arrays
            for (uint8_t i = 0; i < OPT_MEMMAP_MAX_NM_REGIONS; i++)
            {
                l_mem_bases[i] = 0;
                l_mem_sizes[i] = 0;
            }
            for (uint8_t i = 0; i < OPT_MEMMAP_MAX_M_REGIONS ; i++)
            {
                l_mirror_bases[i] = 0;
                l_mirror_sizes[i] = 0;
            }
            for (uint8_t i = 0; i < OPT_MEMMAP_GROUP_32_DIM1; i++)
            {

                for (uint8_t j = OPT_MEMMAP_GROUP_32_MCS_SIZE_INDEX;
                     j <= OPT_MEMMAP_GROUP_32_BASE_INDEX;
                     j++)
                {
                    l_mss_mcs_group_32[i][j] = 0;
                }
                for (uint8_t j = OPT_MEMMAP_GROUP_32_MEMBERS_START_INDEX;
                     j <= OPT_MEMMAP_GROUP_32_MEMBERS_END_INDEX;
                     j++)
                {
                    l_mss_mcs_group_32[i][j] = 0xFF;
                }
                for (uint8_t j = OPT_MEMMAP_GROUP_32_ALT_VALID_INDEX;
                     j <= OPT_MEMMAP_GROUP_32_LARGEST_MBA_INDEX;
                     j++)
                {
                    l_mss_mcs_group_32[i][j] = 0;
                }
            }

            // flush attribute data for each group
            for (uint8_t i = 0; i < iv_nm_groups.size(); i++)
            {
                iv_nm_groups[i].flushAttributes(l_mem_bases,
                                                l_mem_sizes,
                                                l_mss_mcs_group_32);
            }
            for (uint8_t i = 0; i < iv_m_groups.size(); i++)
            {
                iv_m_groups[i].flushAttributes(l_mirror_bases,
                                               l_mirror_sizes,
                                               l_mss_mcs_group_32);
            }

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

            // set non-mirrored region attributes
            rc = FAPI_ATTR_SET(ATTR_PROC_MEM_BASES,
                               iv_target,
                               l_mem_bases);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_SET (ATTR_PROC_MEM_BASES)");
                break;
            }

            rc = FAPI_ATTR_SET(ATTR_PROC_MEM_SIZES,
                               iv_target,
                               l_mem_sizes);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_SET (ATTR_PROC_MEM_BASES)");
                break;
            }

            // set mirrored region attributes
            rc = FAPI_ATTR_SET(ATTR_PROC_MIRROR_BASES,
                               iv_target,
                               l_mirror_bases);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_SET (ATTR_PROC_MIRROR_BASES)");
                break;
            }

            rc = FAPI_ATTR_SET(ATTR_PROC_MIRROR_SIZES,
                               iv_target,
                               l_mirror_sizes);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_SET (ATTR_PROC_MIRROR_BASES)");
                break;
            }

            // set group definition attributes
            rc = FAPI_ATTR_SET(ATTR_MSS_MCS_GROUP_32,
                               iv_target,
                               l_mss_mcs_group_32);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_SET (ATTR_MSS_MCS_GROUP_32)");
                break;
            }

            // set HTM/OCC allocation attributes
            rc = FAPI_ATTR_SET(ATTR_PROC_HTM_BAR_BASE_ADDR,
                               iv_target,
                               iv_alloc_base[PROC_CHIP_MEMMAP_HTM_ALLOC_INDEX]);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_SET (ATTR_PROC_HTM_BAR_BASE_ADDR)");
                break;
            }

            rc = FAPI_ATTR_SET(ATTR_PROC_OCC_SANDBOX_BASE_ADDR,
                               iv_target,
                               iv_alloc_base[PROC_CHIP_MEMMAP_OCC_ALLOC_INDEX]);
            if (!rc.ok())
            {
                FAPI_ERR("Error from FAPI_ATTR_SET (ATTR_PROC_OCC_SANDBOX_BASE_ADDR)");
                break;
            }
        } while(0);

        return rc;
    }
};


ReturnCode opt_memmap(std::vector<fapi::Target> & i_procs, bool i_init)
{
    ReturnCode rc;
    std::vector<ProcChipMemmap> l_system_memmap;
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

        FAPI_INF("opt_memmap called with i_init = %d, mirror_policy: %d",
                 (i_init)?(1):(0), l_mirror_policy);

        // first pass of execution
        if (i_init)
        {
            // loop across all chips in system, set common
            // base for non-mirrored/mirrored memory on each chip in preparation
            // for mss_eff_grouping call
            for (std::vector<fapi::Target>::iterator l_iter = i_procs.begin();
                 l_iter != i_procs.end();
                 ++l_iter)
            {
                uint64_t mem_base = OPT_MEMMAP_BASE_ORIGIN;
                rc = FAPI_ATTR_SET(ATTR_PROC_MEM_BASE,
                                   &(*l_iter),
                                   mem_base);
                if (!rc.ok())
                {
                    FAPI_ERR("Error from FAPI_ATTR_SET (ATTR_PROC_MEM_BASE)!");
                    break;
                }

                uint64_t mirror_base = OPT_MEMMAP_OFFSET_ORIGIN;
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
        // reorder chips based on their effective size
        else
        {
            // loop across all chips in system, consume results of
            // mss_eff_grouping call
            for (std::vector<fapi::Target>::iterator l_iter = i_procs.begin();
                 l_iter != i_procs.end();
                 ++l_iter)
            {
                ProcChipMemmap p(&(*l_iter), l_mirror_policy);
                rc = p.processAttributes();
                if (!rc.ok())
                {
                    FAPI_ERR("Error from processAttributes");
                    break;
                }
                l_system_memmap.push_back(p);
            }
            if (!rc.ok())
            {
                break;
            }

            // sort chips based on their effective stackable size
            std::sort(l_system_memmap.begin(), l_system_memmap.end());

            // establish base for alignment of mirrored/non-mirrored regions
            uint64_t l_m_base_curr;
            uint64_t l_nm_base_curr;
            if (l_mirror_policy ==
                ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL)
            {
                // non-mirrored at zero, mirrored at offset
                l_nm_base_curr = OPT_MEMMAP_BASE_ORIGIN;
                l_m_base_curr  = OPT_MEMMAP_OFFSET_ORIGIN;
            }
            else if (l_mirror_policy ==
                     ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED)
            {
                // mirrored at zero, non-mirrored at offset
                l_nm_base_curr = OPT_MEMMAP_OFFSET_ORIGIN;
                l_m_base_curr  = OPT_MEMMAP_BASE_ORIGIN;
            }
            else
            {
                // start at zero, mirrored region will stack on top
                // of non-mirrored address space, handle offset in loop
                l_nm_base_curr = OPT_MEMMAP_BASE_ORIGIN;
                l_m_base_curr  = OPT_MEMMAP_BASE_ORIGIN;
            }

            // walk through chips, from largest->smallest effective size &
            // assign base addresses for each group
            for (uint8_t i = l_system_memmap.size(); i != 0; --i)
            {
                FAPI_DBG("Stacking chip n%d:p%d (eff nm size = %lld GB, eff m size = %lld GB)...",
                         l_system_memmap[i-1].iv_node_id,
                         l_system_memmap[i-1].iv_chip_id,
                         l_system_memmap[i-1].iv_nm_eff_size / OPT_MEMMAP_GB,
                         l_system_memmap[i-1].iv_m_eff_size / OPT_MEMMAP_GB);

                if (l_mirror_policy ==
                    ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_SELECTIVE)
                {
                    l_m_base_curr += l_system_memmap[i-1].iv_nm_eff_size;
                }

                // establish base addresses for this chip & realign
                // all groups on this chip to reflect this
                l_system_memmap[i-1].setNMBase(l_nm_base_curr);
                l_system_memmap[i-1].setMBase(l_m_base_curr);
                FAPI_DBG("nm base: %016llX", l_nm_base_curr);
                FAPI_DBG("m base: %016llX", l_m_base_curr);
                if (l_mirror_policy ==
                    ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL)
                {
                    l_nm_base_curr += l_system_memmap[i-1].iv_nm_eff_size;
                    l_m_base_curr += l_system_memmap[i-1].iv_nm_eff_size / 2;
                }
                else if (l_mirror_policy ==
                         ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED)
                {
                    l_nm_base_curr += l_system_memmap[i-1].iv_nm_eff_size;
                    l_m_base_curr += l_system_memmap[i-1].iv_m_eff_size;
                }
                else
                {
                    l_nm_base_curr += PowerOf2Roundedup(
                        l_system_memmap[i-1].iv_nm_eff_size +
                        l_system_memmap[i-1].iv_m_eff_size);
                    l_m_base_curr = l_nm_base_curr;
                }

                // allocate HTM/OCC memory requests for this chip
                rc = l_system_memmap[i-1].allocate();
                if (!rc.ok())
                {
                    FAPI_ERR("Error from allocate");
                    break;
                }

                // flush attributes for this chip
                rc = l_system_memmap[i-1].flushAttributes();
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
