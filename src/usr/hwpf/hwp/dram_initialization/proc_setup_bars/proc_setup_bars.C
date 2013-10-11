/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/proc_setup_bars/proc_setup_bars.C $ */
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
// $Id: proc_setup_bars.C,v 1.19 2013/10/11 14:58:56 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_setup_bars.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_setup_bars.C
// *! DESCRIPTION : Program nest base address registers (BARs) (FAPI)
// *!
// *! OWNER NAME  : Joe McGill    Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_setup_bars.H"

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// logical size->physical encoding translation maps
const std::map<uint64_t, uint64_t> proc_setup_bars_nf_bar_size::xlate_map =
    proc_setup_bars_nf_bar_size::create_map();

const std::map<uint64_t, uint64_t> proc_setup_bars_f_bar_size::xlate_map =
    proc_setup_bars_f_bar_size::create_map();

const std::map<uint64_t, uint64_t> proc_setup_bars_fsp_bar_size::xlate_map =
    proc_setup_bars_fsp_bar_size::create_map();

const std::map<uint64_t, uint64_t> proc_setup_bars_fsp_mmio_mask_size::xlate_map =
    proc_setup_bars_fsp_mmio_mask_size::create_map();

const std::map<uint64_t, uint64_t> proc_setup_bars_nx_mmio_bar_size::xlate_map =
    proc_setup_bars_nx_mmio_bar_size::create_map();

const std::map<uint64_t, uint64_t> proc_setup_bars_hca_nm_bar_size::xlate_map =
    proc_setup_bars_hca_nm_bar_size::create_map();

const std::map<uint64_t, uint64_t> proc_setup_bars_as_mmio_bar_size::xlate_map =
    proc_setup_bars_as_mmio_bar_size::create_map();

const std::map<uint64_t, uint64_t> proc_setup_bars_mcd_bar_size::xlate_map =
    proc_setup_bars_mcd_bar_size::create_map();

const std::map<uint64_t, uint64_t> proc_setup_bars_pcie_bar_size::xlate_map =
    proc_setup_bars_pcie_bar_size::create_map();


extern "C" {

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// function: utility function to display address range/BAR information and
//           check properties
// parameters: i_bar_def        => structure encapsulating address range/BAR
//                                 properties
//             i_bar_addr_range => structure encapsulating address range
// returns: true if any properties specified by i_bar_def are violated,
//          false otherwise
//------------------------------------------------------------------------------
bool proc_setup_bars_common_check_bar(
    const proc_setup_bars_bar_def& i_bar_def,
    const proc_setup_bars_addr_range& i_bar_addr_range)
{
    // return code
    fapi::ReturnCode rc;
    // set if error should be logged at end of function
    bool error = false;

    do
    {
        // print range information
        i_bar_addr_range.print();

        // only check if BAR enable attribute is set
        if (i_bar_addr_range.enabled)
        {
            // ensure that address range lies in fabric real address space
            if (!i_bar_addr_range.is_in_fbc_range())
            {
                FAPI_ERR("proc_setup_bars_common_check_bar: BAR range is not wholly contained in FBC real address space");
                error = true;
                break;
            }
            // ensure that base address value lies in implemented address space
            if (i_bar_addr_range.base_addr &
                i_bar_def.base_addr_mask)
            {
                FAPI_ERR("proc_setup_bars_common_check_bar: BAR base address attribute value is out-of-range");
                error = true;
                break;
            }
            // ensure that address range size is in range
            if ((i_bar_addr_range.size < i_bar_def.size_min) ||
                (i_bar_addr_range.size > i_bar_def.size_max))
            {
                FAPI_ERR("proc_setup_bars_common_check_bar: BAR size attribute value is out-of-range");
                error = true;
                break;
            }
            // check that base address range and mask are aligned
            if (i_bar_def.check_aligned &&
                !i_bar_addr_range.is_aligned())
            {
                FAPI_ERR("proc_setup_bars_common_check_bar: BAR base address/size range values are not aligned");
                error = true;
                break;
            }
        }
    } while(0);

    return error;
}


//------------------------------------------------------------------------------
// function: utility function to check for overlapping address ranges
// parameters: i_ranges => vector of pointers to address range structures that
//                         should be checked
// returns: true if any ranges overlap, false otherwise
//------------------------------------------------------------------------------
bool proc_setup_bars_common_do_ranges_overlap(
    const std::vector<proc_setup_bars_addr_range*> i_ranges)
{
    bool overlap = false;
    FAPI_DBG("proc_setup_bars_common_do_ranges_overlap: Start");

    // check that ranges are non-overlapping
    if (i_ranges.size() > 1)
    {
        for (size_t r = 0; (r < i_ranges.size()-1) && !overlap; r++)
        {
            for (size_t x = r+1; x < i_ranges.size(); x++)
            {
                if (i_ranges[r]->overlaps(*(i_ranges[x])))
                {
                    overlap = true;
                    break;
                }
            }
        }
    }

    FAPI_DBG("proc_setup_bars_common_do_ranges_overlap: End");
    return overlap;
}


//------------------------------------------------------------------------------
// function: retrieve attributes defining non-mirrored memory range
// parameters: i_target      => pointer to chip target
//             io_addr_range => address range structure encapsulating attribute
//                              values (size will be rounded up to nearest
//                              power of two)
// returns: FAPI_RC_SUCCESS if all attribute reads are successful & values
//              are valid,
//          RC_PROC_SETUP_BARS_NON_MIRRORED_RANGE_ATTR_ERR if chip non-mirrored
//              attribute content violates expected behavior,
//          RC_PROC_SETUP_BARS_NON_MIRRORED_RANGE_OVERLAP_ATTR_ERR if chip
//              non-mirrored range attributes specify overlapping ranges,
//          RC_PROC_SETUP_BARS_NON_MIRRORED_RANGE_ERR if chip non-mirrored
//              processed range content violates expected behavior,
//          else FAPI_ATTR_GET return code
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_memory_get_non_mirrored_attrs(
    const fapi::Target* i_target,
    proc_setup_bars_addr_range& io_addr_range)
{
    // return code
    fapi::ReturnCode rc;
    // temporary attribute storage used to build procedure data structures
    uint64_t mem_bases_ack[PROC_SETUP_BARS_NUM_NON_MIRRORED_RANGES];
    uint64_t mem_sizes_ack[PROC_SETUP_BARS_NUM_NON_MIRRORED_RANGES];
    proc_setup_bars_addr_range non_mirrored_ranges[PROC_SETUP_BARS_NUM_NON_MIRRORED_RANGES];

    // mark function entry
    FAPI_DBG("proc_setup_bars_memory_get_non_mirrored_attrs: Start");

    do
    {
        // retrieve non-mirrored memory base address/size ack attributes
        rc = FAPI_ATTR_GET(ATTR_PROC_MEM_BASES_ACK,
                           i_target,
                           mem_bases_ack);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_memory_get_non_mirrored_attrs: Error querying ATTR_PROC_MEM_BASES_ACK");
            break;
        }

        rc = FAPI_ATTR_GET(ATTR_PROC_MEM_SIZES_ACK,
                           i_target,
                           mem_sizes_ack);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_memory_get_non_mirrored_attrs: Error querying ATTR_PROC_MEM_SIZES_ACK");
            break;
        }

        // process attributes into range structures
        for (uint8_t r = 0; r < PROC_SETUP_BARS_NUM_NON_MIRRORED_RANGES; r++)
        {
            // build range content
            non_mirrored_ranges[r].base_addr = mem_bases_ack[r];
            non_mirrored_ranges[r].size = mem_sizes_ack[r];
            // consider range enabled if size is non-zero
            non_mirrored_ranges[r].enabled = (non_mirrored_ranges[r].size != 0x0);
            // check attribute content
            FAPI_DBG("proc_setup_bars_memory_get_non_mirrored_attrs: Range %d", r);
            if (proc_setup_bars_common_check_bar(
                    non_mirrored_range_def,
                    non_mirrored_ranges[r]) != false)
            {
                FAPI_ERR("proc_setup_bars_memory_get_non_mirrored_attrs: Error from proc_setup_bars_common_check_bar");
                const uint64_t& BASE_ADDR = non_mirrored_ranges[r].base_addr;
                const uint64_t& SIZE = non_mirrored_ranges[r].size;
                FAPI_SET_HWP_ERROR(rc,
                   RC_PROC_SETUP_BARS_NON_MIRRORED_RANGE_ATTR_ERR);
                break;
            }
        }
        if (!rc.ok())
        {
            break;
        }

        // check that ranges are non-overlapping
        std::vector<proc_setup_bars_addr_range*> check_ranges;
        for (uint8_t r = 0; r < PROC_SETUP_BARS_NUM_NON_MIRRORED_RANGES; r++)
        {
            check_ranges.push_back(&non_mirrored_ranges[r]);
        }
        if (proc_setup_bars_common_do_ranges_overlap(check_ranges))
        {
            FAPI_ERR("proc_setup_bars_memory_get_non_mirrored_attrs: Non-mirrored range attributes specify overlapping address regions");
            FAPI_SET_HWP_ERROR(rc,
                RC_PROC_SETUP_BARS_NON_MIRRORED_RANGE_OVERLAP_ATTR_ERR);
            break;
        }

        // ranges are non-overlapping, merge to single range
        for (uint8_t r = 0; r < PROC_SETUP_BARS_NUM_NON_MIRRORED_RANGES; r++)
        {
            // merge to build single range
            io_addr_range.merge(non_mirrored_ranges[r]);
        }

        // ensure range is power of 2 aligned
        if (io_addr_range.enabled && !io_addr_range.is_power_of_2())
        {
            io_addr_range.round_next_power_of_2();
        }

        // check final range content
        if (proc_setup_bars_common_check_bar(
                non_mirrored_range_def,
                io_addr_range) != false)
        {
            FAPI_ERR("proc_setup_bars_memory_get_non_mirrored_attrs: Error from proc_setup_bars_common_check_bar");
            const uint64_t& BASE_ADDR = io_addr_range.base_addr;
            const uint64_t& SIZE = io_addr_range.size;
            FAPI_SET_HWP_ERROR(rc,
               RC_PROC_SETUP_BARS_NON_MIRRORED_RANGE_ERR);
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_setup_bars_memory_get_non_mirrored_attrs: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: retrieve attributes defining mirrored memory range
// parameters: i_target      => pointer to chip target
//             io_addr_range => address range structure encapsulating attribute
//                              values (ranges will be merged and size rounded
//                              up to the nearest power of two)
// returns: FAPI_RC_SUCCESS if all attribute reads are successful & values
//              are valid,
//          RC_PROC_SETUP_BARS_MIRRORED_RANGE_ATTR_ERR if individual chip
//              mirrored range attribute content violates expected behavior,
//          RC_PROC_SETUP_BARS_MIRRORED_RANGE_OVERLAP_ATTR_ERR if chip mirrored
//              range attributes specify overlapping ranges,
//          RC_PROC_SETUP_BARS_MIRRORED_RANGE_ERR if chip mirrored processed
//              range content violates expected behavior,
//          else FAPI_ATTR_GET return code
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_memory_get_mirrored_attrs(
    const fapi::Target* i_target,
    proc_setup_bars_addr_range& io_addr_range)
{
    // return code
    fapi::ReturnCode rc;
    // temporary attribute storage used to build procedure data structures
    uint64_t mirror_bases_ack[PROC_SETUP_BARS_NUM_MIRRORED_RANGES];
    uint64_t mirror_sizes_ack[PROC_SETUP_BARS_NUM_MIRRORED_RANGES];
    proc_setup_bars_addr_range mirrored_ranges[PROC_SETUP_BARS_NUM_MIRRORED_RANGES];

    // mark function entry
    FAPI_DBG("proc_setup_bars_memory_get_mirrored_attrs: Start");

    do
    {
        // retrieve mirrored memory base address/size ack attributes
        rc = FAPI_ATTR_GET(ATTR_PROC_MIRROR_BASES_ACK,
                           i_target,
                           mirror_bases_ack);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_memory_get_mirrored_attrs: Error querying ATTR_PROC_MIRROR_BASES_ACK");
            break;
        }

        rc = FAPI_ATTR_GET(ATTR_PROC_MIRROR_SIZES_ACK,
                           i_target,
                           mirror_sizes_ack);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_memory_get_mirrored_attrs: Error querying ATTR_PROC_MIRROR_SIZES_ACK");
            break;
        }

        // process attributes into range structures
        for (uint8_t r = 0; r < PROC_SETUP_BARS_NUM_MIRRORED_RANGES; r++)
        {
            // build range content
            mirrored_ranges[r].base_addr = mirror_bases_ack[r];
            mirrored_ranges[r].size = mirror_sizes_ack[r];
            // consider range enabled if size is non-zero
            mirrored_ranges[r].enabled = (mirrored_ranges[r].size != 0x0);
            // check attribute content
            FAPI_DBG("proc_setup_bars_memory_get_mirrored_attrs: Range %d", r);
            if (proc_setup_bars_common_check_bar(
                    mirrored_range_def,
                    mirrored_ranges[r]) != false)
            {
                FAPI_ERR("proc_setup_bars_memory_get_mirrored_attrs: Error from proc_setup_bars_common_check_bar");
                const uint64_t& BASE_ADDR = mirrored_ranges[r].base_addr;
                const uint64_t& SIZE = mirrored_ranges[r].size;
                FAPI_SET_HWP_ERROR(rc,
                   RC_PROC_SETUP_BARS_MIRRORED_RANGE_ATTR_ERR);
                break;
            }
        }
        if (!rc.ok())
        {
            break;
        }

        // check that ranges are non-overlapping
        std::vector<proc_setup_bars_addr_range*> check_ranges;
        for (uint8_t r = 0; r < PROC_SETUP_BARS_NUM_MIRRORED_RANGES; r++)
        {
            check_ranges.push_back(&mirrored_ranges[r]);
        }
        if (proc_setup_bars_common_do_ranges_overlap(check_ranges))
        {
            FAPI_ERR("proc_setup_bars_memory_get_mirrored_attrs: Mirrored range attributes specify overlapping address regions");
            FAPI_SET_HWP_ERROR(rc,
                RC_PROC_SETUP_BARS_MIRRORED_RANGE_OVERLAP_ATTR_ERR);
            break;
        }

        // ranges are non-overlapping, merge to single range
        for (uint8_t r = 0; r < PROC_SETUP_BARS_NUM_MIRRORED_RANGES; r++)
        {
            // merge to build single range
            io_addr_range.merge(mirrored_ranges[r]);
        }

        // ensure range is power of 2 aligned
        if (io_addr_range.enabled && !io_addr_range.is_power_of_2())
        {
            io_addr_range.round_next_power_of_2();
        }

        // check final range content
        if (proc_setup_bars_common_check_bar(
                mirrored_range_def,
                io_addr_range) != false)
        {
            FAPI_ERR("proc_setup_bars_memory_get_mirrored_attrs: Error from proc_setup_bars_common_check_bar");
            const uint64_t& BASE_ADDR = io_addr_range.base_addr;
            const uint64_t& SIZE = io_addr_range.size;
            FAPI_SET_HWP_ERROR(rc,
               RC_PROC_SETUP_BARS_MIRRORED_RANGE_ERR);
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_setup_bars_memory_get_mirrored_attrs: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: retrieve attributes defining foreign near memory range
// parameters: i_target       => pointer to chip target
//             io_addr_ranges => array of address range structures
//                               encapsulating attribute values
//                               (one per foreign link)
// returns: FAPI_RC_SUCCESS if all attribute reads are successful & values
//              are valid,
//          RC_PROC_SETUP_BARS_FOREIGN_NEAR_RANGE_ATTR_ERR if individual chip
//              foriegn near range attribute content violates expected behavior,
//          else FAPI_ATTR_GET return code
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_memory_get_foreign_near_attrs(
    const fapi::Target* i_target,
    proc_setup_bars_addr_range io_addr_ranges[PROC_FAB_SMP_NUM_F_LINKS])
{
    // return code
    fapi::ReturnCode rc;
    // temporary attribute storage used to build procedure data structures
    uint64_t foreign_near_base_attr[PROC_FAB_SMP_NUM_F_LINKS];
    uint64_t foreign_near_size_attr[PROC_FAB_SMP_NUM_F_LINKS];

    // mark function entry
    FAPI_DBG("proc_setup_bars_memory_get_foreign_near_attrs: Start");

    do
    {
        // retrieve foreign near base address/size attributes
        rc = FAPI_ATTR_GET(ATTR_PROC_FOREIGN_NEAR_BASE,
                           i_target,
                           foreign_near_base_attr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_memory_get_foreign_near_attrs: Error querying ATTR_PROC_FOREIGN_NEAR_BASE");
            break;
        }
        rc = FAPI_ATTR_GET(ATTR_PROC_FOREIGN_NEAR_SIZE,
                           i_target,
                           foreign_near_size_attr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_memory_get_foreign_near_attrs: Error querying ATTR_PROC_FOREIGN_NEAR_SIZE");
            break;
        }

        // process attributes into range structures
        for (uint8_t r = 0; r < PROC_FAB_SMP_NUM_F_LINKS; r++)
        {
            // build range content
            io_addr_ranges[r].base_addr = foreign_near_base_attr[r];
            io_addr_ranges[r].size = foreign_near_size_attr[r];
            io_addr_ranges[r].enabled = (foreign_near_size_attr[r] != 0x0);

            // check attribute content
            FAPI_DBG("proc_setup_bars_memory_get_foreign_near_attrs: Link %d", r);
            if (proc_setup_bars_common_check_bar(
                    common_f_scope_bar_def,
                    io_addr_ranges[r]) != false)
            {
                FAPI_ERR("proc_setup_bars_memory_get_foreign_near_attrs: Error from proc_setup_bars_common_check_bar");
                const uint64_t& BASE_ADDR = io_addr_ranges[r].base_addr;
                const uint64_t& SIZE = io_addr_ranges[r].size;
                FAPI_SET_HWP_ERROR(rc,
                    RC_PROC_SETUP_BARS_FOREIGN_NEAR_RANGE_ATTR_ERR);
                break;
            }
        }
    } while(0);
    // mark function entry
    FAPI_DBG("proc_setup_bars_memory_get_foreign_near_attrs: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: retrieve attributes defining foreign far memory range
// parameters: i_target       => pointer to chip target
//             io_addr_ranges => array of address range structures
//                               encapsulating attribute values
//                               (one per foreign link)
// returns: FAPI_RC_SUCCESS if all attribute reads are successful & values
//              are valid,
//          RC_PROC_SETUP_BARS_FOREIGN_FAR_RANGE_ATTR_ERR if individual chip
//              foreign far range attribute content violates expected behavior,
//          else FAPI_ATTR_GET return code
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_memory_get_foreign_far_attrs(
    const fapi::Target* i_target,
    proc_setup_bars_addr_range io_addr_ranges[PROC_FAB_SMP_NUM_F_LINKS])
{
    // return code
    fapi::ReturnCode rc;
    // temporary attribute storage used to build procedure data structures
    uint64_t foreign_far_base_attr[PROC_FAB_SMP_NUM_F_LINKS];
    uint64_t foreign_far_size_attr[PROC_FAB_SMP_NUM_F_LINKS];

    // mark function entry
    FAPI_DBG("proc_setup_bars_memory_get_foreign_far_attrs: Start");

    do
    {
        // retrieve foreign far base address/size attributes
        rc = FAPI_ATTR_GET(ATTR_PROC_FOREIGN_FAR_BASE,
                           i_target,
                           foreign_far_base_attr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_memory_get_foreign_far_attrs: Error querying ATTR_PROC_FOREIGN_FAR_BASE");
            break;
        }
        rc = FAPI_ATTR_GET(ATTR_PROC_FOREIGN_FAR_SIZE,
                           i_target,
                           foreign_far_size_attr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_memory_get_foreign_far_attrs: Error querying ATTR_PROC_FOREIGN_FAR_SIZE");
            break;
        }

        // process attributes into range structures
        for (uint8_t r = 0; r < PROC_FAB_SMP_NUM_F_LINKS; r++)
        {
            // build range content
            io_addr_ranges[r].base_addr = foreign_far_base_attr[r];
            io_addr_ranges[r].size = foreign_far_size_attr[r];
            io_addr_ranges[r].enabled = (foreign_far_size_attr[r] != 0x0);

            // check attribute content
            FAPI_DBG("proc_setup_bars_memory_get_foreign_far_attrs: Link %d", r);
            if (proc_setup_bars_common_check_bar(
                    common_f_scope_bar_def,
                    io_addr_ranges[r]) != false)
            {
                FAPI_ERR("proc_setup_bars_memory_get_foreign_far_attrs: Error from proc_setup_bars_common_check_bar");
                const uint64_t& BASE_ADDR = io_addr_ranges[r].base_addr;
                const uint64_t& SIZE = io_addr_ranges[r].size;
                FAPI_SET_HWP_ERROR(rc,
                    RC_PROC_SETUP_BARS_FOREIGN_FAR_RANGE_ATTR_ERR);
                break;
            }
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_setup_bars_memory_get_foreign_far_attrs: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: retrieve attributes defining PSI BAR programming
// parameters: i_target      => pointer to chip target
//             io_addr_range => address range structure encapsulating
//                              attribute values
// returns: FAPI_RC_SUCCESS if all attribute reads are successful & values
//              are valid,
//          RC_PROC_SETUP_BARS_PSI_BAR_ATTR_ERR if chip PSI range
//              attribute content violates expected behavior,
//          else FAPI_ATTR_GET return code
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_psi_get_bar_attrs(
    const fapi::Target* i_target,
    proc_setup_bars_addr_range& io_addr_range)
{
    // return code
    fapi::ReturnCode rc;
    uint8_t bar_enabled;

    FAPI_DBG("proc_setup_bars_psi_get_bar_attrs: Start");
    do
    {
        // BAR base address
        rc = FAPI_ATTR_GET(ATTR_PROC_PSI_BRIDGE_BAR_BASE_ADDR,
                           i_target,
                           io_addr_range.base_addr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_psi_get_bar_attrs: Error querying ATTR_PROC_PSI_BRIDGE_BAR_BASE_ADDR");
            break;
        }

        // BAR enable
        rc = FAPI_ATTR_GET(ATTR_PROC_PSI_BRIDGE_BAR_ENABLE,
                           i_target,
                           bar_enabled);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_psi_get_bar_attrs: Error querying ATTR_PROC_PSI_BRIDGE_BAR_ENABLE");
            break;
        }
        io_addr_range.enabled = (bar_enabled == 0x1);

        // BAR size (implied to be 1MB)
        io_addr_range.size = PROC_SETUP_BARS_SIZE_1_MB;

        // check BAR attribute content
        if (proc_setup_bars_common_check_bar(
                psi_bridge_bar_def,
                io_addr_range) != false)
        {
            FAPI_ERR("proc_setup_bars_psi_get_bar_attrs: Error from proc_setup_bars_common_check_bar");
            const uint64_t& BASE_ADDR = io_addr_range.base_addr;
            const uint64_t& SIZE = io_addr_range.size;
            FAPI_SET_HWP_ERROR(rc,
               RC_PROC_SETUP_BARS_PSI_BAR_ATTR_ERR);
            break;
        }
    } while(0);

    FAPI_DBG("proc_setup_bars_psi_get_bar_attrs: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: retrieve attributes defining FSP BAR programming
// parameters: i_target      => pointer to chip target
//             io_addr_range => address range structure encapsulating
//                              attribute values
// returns: FAPI_RC_SUCCESS if all attribute reads are successful & values
//              are valid,
//          RC_PROC_SETUP_BARS_FSP_BAR_ATTR_ERR if chip FSP range
//              attribute content violates expected behavior,
//          else FAPI_ATTR_GET return code
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_fsp_get_bar_attrs(
    const fapi::Target* i_target,
    proc_setup_bars_addr_range& io_addr_range)
{
    // return code
    fapi::ReturnCode rc;
    uint8_t bar_enabled;

    FAPI_DBG("proc_setup_bars_fsp_get_bar_attrs: Start");
    do
    {
        // BAR base address
        rc = FAPI_ATTR_GET(ATTR_PROC_FSP_BAR_BASE_ADDR,
                           i_target,
                           io_addr_range.base_addr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_fsp_get_bar_attrs: Error querying ATTR_PROC_FSP_BAR_BASE_ADDR");
            break;
        }

        // BAR enable
        rc = FAPI_ATTR_GET(ATTR_PROC_FSP_BAR_ENABLE,
                           i_target,
                           bar_enabled);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_fsp_get_bar_attrs: Error querying ATTR_PROC_FSP_BAR_ENABLE");
            break;
        }
        io_addr_range.enabled = (bar_enabled == 0x1);

        // BAR size
        rc = FAPI_ATTR_GET(ATTR_PROC_FSP_BAR_SIZE,
                           i_target,
                           io_addr_range.size);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_fsp_get_bar_attrs: Error querying ATTR_PROC_FSP_BAR_SIZE");
            break;
        }

        // check BAR attribute content
        if (proc_setup_bars_common_check_bar(
                fsp_bar_def,
                io_addr_range) != false)
        {
            FAPI_ERR("proc_setup_bars_fsp_get_bar_attrs: Error from proc_setup_bars_common_check_bar");
            const uint64_t& BASE_ADDR = io_addr_range.base_addr;
            const uint64_t& SIZE = io_addr_range.size;
            FAPI_SET_HWP_ERROR(rc,
               RC_PROC_SETUP_BARS_FSP_BAR_ATTR_ERR);
            break;
        }
    } while(0);

    FAPI_DBG("proc_setup_bars_fsp_get_bar_attrs: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: retrieve attributes defining FSP MMIO mask programming
// parameters: i_target      => pointer to chip target
//             io_addr_range => address range structure encapsulating
//                              attribute values
// returns: FAPI_RC_SUCCESS if all attribute reads are successful & values
//              are valid,
//          RC_PROC_SETUP_BARS_FSP_MMIO_MASK_ATTR_ERR if chip MMIO mask
//              attribute content violates expected behavior,
//          else FAPI_ATTR_GET return code
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_fsp_get_mmio_mask_attrs(
    const fapi::Target* i_target,
    proc_setup_bars_addr_range& io_addr_range)
{
    // return code
    fapi::ReturnCode rc;

    FAPI_DBG("proc_setup_bars_fsp_get_mmio_mask_attrs: Start");
    do
    {
        // BAR base address (unused)
        io_addr_range.base_addr = 0x0ULL;

        // BAR enable (unused)
        io_addr_range.enabled = true;

        // BAR size
        rc = FAPI_ATTR_GET(ATTR_PROC_FSP_MMIO_MASK_SIZE,
                           i_target,
                           io_addr_range.size);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_fsp_get_mmio_mask_attrs: Error querying ATTR_PROC_FSP_MMIO_MASK_SIZE");
            break;
        }

        // check BAR attribute content
        if (proc_setup_bars_common_check_bar(
                fsp_mmio_mask_def,
                io_addr_range) != false)
        {
            FAPI_ERR("proc_setup_bars_fsp_get_mmio_mask_attrs: Error from proc_setup_bars_common_check_bar");
            const uint64_t& SIZE = io_addr_range.size;
            FAPI_SET_HWP_ERROR(rc,
               RC_PROC_SETUP_BARS_FSP_MMIO_MASK_ATTR_ERR);
            break;
        }
    } while(0);

    FAPI_DBG("proc_setup_bars_fsp_get_mmio_mask_attrs: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: retrieve attributes defining INTP BAR programming
// parameters: i_target      => pointer to chip target
//             io_addr_range => address range structure encapsulating
//                              attribute values
// returns: FAPI_RC_SUCCESS if all attribute reads are successful & values
//              are valid,
//          RC_PROC_SETUP_BARS_INTP_BAR_ATTR_ERR if chip INTP range
//              attribute content violates expected behavior,
//          else FAPI_ATTR_GET return code
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_intp_get_bar_attrs(
    const fapi::Target* i_target,
    proc_setup_bars_addr_range& io_addr_range)
{
    // return code
    fapi::ReturnCode rc;
    uint8_t bar_enabled;

    FAPI_DBG("proc_setup_bars_intp_get_bar_attrs: Start");
    do
    {
        // BAR base address
        rc = FAPI_ATTR_GET(ATTR_PROC_INTP_BAR_BASE_ADDR,
                           i_target,
                           io_addr_range.base_addr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_intp_get_bar_attrs: Error querying ATTR_PROC_INTP_BAR_BASE_ADDR");
            break;
        }

        // BAR enable
        rc = FAPI_ATTR_GET(ATTR_PROC_INTP_BAR_ENABLE,
                           i_target,
                           bar_enabled);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_intp_get_bar_attrs: Error querying ATTR_PROC_INTP_BAR_ENABLE");
            break;
        }
        io_addr_range.enabled = (bar_enabled == 0x1);

        // BAR size (implied to be 1MB)
        io_addr_range.size = PROC_SETUP_BARS_SIZE_1_MB;

        // check BAR attribute content
        if (proc_setup_bars_common_check_bar(
                intp_bar_def,
                io_addr_range) != false)
        {
            FAPI_ERR("proc_setup_bars_intp_get_bar_attrs: Error from proc_setup_bars_common_check_bar");
            const uint64_t& BASE_ADDR = io_addr_range.base_addr;
            const uint64_t& SIZE = io_addr_range.size;
            FAPI_SET_HWP_ERROR(rc,
               RC_PROC_SETUP_BARS_INTP_BAR_ATTR_ERR);
            break;
        }
    } while(0);

    FAPI_DBG("proc_setup_bars_intp_get_bar_attrs: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: retrieve attributes defining NX MMIO BAR programming
// parameters: i_target      => pointer to chip target
//             io_addr_range => address range structure encapsulating
//                              attribute values
// returns: FAPI_RC_SUCCESS if all attribute reads are successful & values
//              are valid,
//          RC_PROC_SETUP_BARS_NX_MMIO_BAR_ATTR_ERR if chip NX MMIO range
//              attribute content violates expected behavior,
//          else FAPI_ATTR_GET return code
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_nx_get_mmio_bar_attrs(
    const fapi::Target* i_target,
    proc_setup_bars_addr_range& io_addr_range)
{
    // return code
    fapi::ReturnCode rc;
    uint8_t bar_enabled;

    FAPI_DBG("proc_setup_bars_nx_get_mmio_bar_attrs: Start");
    do
    {
        // BAR base address
        rc = FAPI_ATTR_GET(ATTR_PROC_NX_MMIO_BAR_BASE_ADDR,
                           i_target,
                           io_addr_range.base_addr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_nx_get_mmio_bar_attrs: Error querying ATTR_PROC_NX_MMIO_BAR_BASE_ADDR");
            break;
        }

        // BAR enable
        rc = FAPI_ATTR_GET(ATTR_PROC_NX_MMIO_BAR_ENABLE,
                           i_target,
                           bar_enabled);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_nx_get_mmio_bar_attrs: Error querying ATTR_PROC_NX_MMIO_BAR_ENABLE");
            break;
        }
        io_addr_range.enabled = (bar_enabled == 0x1);

        // BAR size
        rc = FAPI_ATTR_GET(ATTR_PROC_NX_MMIO_BAR_SIZE,
                           i_target,
                           io_addr_range.size);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_nx_get_mmio_bar_attrs: Error querying ATTR_PROC_NX_MMIO_BAR_SIZE");
            break;
        }

        // check BAR attribute content
        if (proc_setup_bars_common_check_bar(
                nx_mmio_bar_def,
                io_addr_range) != false)
        {
            FAPI_ERR("proc_setup_bars_nx_get_mmio_bar_attrs: Error from proc_setup_bars_common_check_bar");
            const uint64_t& BASE_ADDR = io_addr_range.base_addr;
            const uint64_t& SIZE = io_addr_range.size;
            FAPI_SET_HWP_ERROR(rc,
               RC_PROC_SETUP_BARS_NX_MMIO_BAR_ATTR_ERR);
            break;
        }
    } while(0);

    FAPI_DBG("proc_setup_bars_nx_get_mmio_bar_attrs: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: retrieve attributes defining AS MMIO BAR programming
// parameters: i_target      => pointer to chip target
//             io_addr_range => address range structure encapsulating
//                              attribute values
// returns: FAPI_RC_SUCCESS if all attribute reads are successful & values
//              are valid,
//          RC_PROC_SETUP_BARS_AS_MMIO_BAR_ATTR_ERR if chip AS MMIO range
//              attribute content violates expected behavior,
//          else FAPI_ATTR_GET return code
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_as_get_mmio_bar_attrs(
    const fapi::Target* i_target,
    proc_setup_bars_addr_range& io_addr_range)
{
    // return code
    fapi::ReturnCode rc;
    uint8_t bar_enabled;

    FAPI_DBG("proc_setup_bars_as_get_mmio_bar_attrs: Start");
    do
    {
        // BAR base address
        rc = FAPI_ATTR_GET(ATTR_PROC_AS_MMIO_BAR_BASE_ADDR,
                           i_target,
                           io_addr_range.base_addr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_as_get_mmio_bar_attrs: Error querying ATTR_PROC_AS_MMIO_BAR_BASE_ADDR");
            break;
        }

        // BAR enable
        rc = FAPI_ATTR_GET(ATTR_PROC_AS_MMIO_BAR_ENABLE,
                           i_target,
                           bar_enabled);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_as_get_mmio_bar_attrs: Error querying ATTR_PROC_AS_MMIO_BAR_ENABLE");
            break;
        }
        io_addr_range.enabled = (bar_enabled == 0x1);

        // BAR size
        rc = FAPI_ATTR_GET(ATTR_PROC_AS_MMIO_BAR_SIZE,
                           i_target,
                           io_addr_range.size);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_as_get_mmio_bar_attrs: Error querying ATTR_PROC_AS_MMIO_BAR_SIZE");
            break;
        }

        // check BAR attribute content
        if (proc_setup_bars_common_check_bar(
                as_mmio_bar_def,
                io_addr_range) != false)
        {
            FAPI_ERR("proc_setup_bars_as_get_mmio_bar_attrs: Error from proc_setup_bars_common_check_bar");
            const uint64_t& BASE_ADDR = io_addr_range.base_addr;
            const uint64_t& SIZE = io_addr_range.size;
            FAPI_SET_HWP_ERROR(rc,
               RC_PROC_SETUP_BARS_AS_MMIO_BAR_ATTR_ERR);
            break;
        }
    } while(0);

    FAPI_DBG("proc_setup_bars_as_get_mmio_bar_attrs: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: retrieve attributes defining PCIe IO BAR programming
// parameters: i_target       => pointer to chip target
//             io_addr_ranges => 2D array of address range structures
//                               encapsulating attribute values
//                               (first dimension = unit, second dimension =
//                                links per unit)
// returns: FAPI_RC_SUCCESS if all attribute reads are successful & values
//              are valid,
//          RC_PROC_SETUP_BARS_PCIE_BAR_ATTR_ERR if individual chip PCIe IO
//              range attribute content violates expected behavior,
//          else FAPI_ATTR_GET return code
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_pcie_get_bar_attrs(
    const fapi::Target* i_target,
    proc_setup_bars_addr_range io_addr_ranges[PROC_SETUP_BARS_PCIE_NUM_UNITS][PROC_SETUP_BARS_PCIE_RANGES_PER_UNIT])
{
    // return code
    fapi::ReturnCode rc;
    // temporary attribute storage used to build procedure data structures
    uint64_t pcie_bar_addr[PROC_SETUP_BARS_PCIE_NUM_UNITS][PROC_SETUP_BARS_PCIE_RANGES_PER_UNIT];
    uint64_t pcie_bar_size[PROC_SETUP_BARS_PCIE_NUM_UNITS][PROC_SETUP_BARS_PCIE_RANGES_PER_UNIT];
    uint8_t pcie_bar_en[PROC_SETUP_BARS_PCIE_NUM_UNITS][PROC_SETUP_BARS_PCIE_RANGES_PER_UNIT];

    FAPI_DBG("proc_setup_bars_pcie_get_bar_attrs: Start");
    do
    {
        // IO BAR base addresses
        rc = FAPI_ATTR_GET(ATTR_PROC_PCIE_BAR_BASE_ADDR,
                           i_target,
                           pcie_bar_addr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_pcie_get_bar_attrs: Error querying ATTR_PROC_PCIE_BAR_BASE_ADDR");
            break;
        }

        // IO BAR enable
        rc = FAPI_ATTR_GET(ATTR_PROC_PCIE_BAR_ENABLE,
                           i_target,
                           pcie_bar_en);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_pcie_get_bar_attrs: Error querying ATTR_PROC_PCIE_BAR_ENABLE");
            break;
        }

        // IO BAR sizes
        rc = FAPI_ATTR_GET(ATTR_PROC_PCIE_BAR_SIZE,
                           i_target,
                           pcie_bar_size);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_pcie_get_bar_attrs: Error querying ATTR_PROC_PCIE_BAR_SIZE");
            break;
        }

        // loop over all units
        for (uint8_t u = 0;
             (u < PROC_SETUP_BARS_PCIE_NUM_UNITS) && (rc.ok());
             u++)
        {
            for (uint8_t r = 0;
                 r < PROC_SETUP_BARS_PCIE_RANGES_PER_UNIT;
                 r++)
            {
                // fill chip range structures
                io_addr_ranges[u][r].base_addr = pcie_bar_addr[u][r];
                io_addr_ranges[u][r].size = pcie_bar_size[u][r];
                io_addr_ranges[u][r].enabled = pcie_bar_en[u][r];
                // check BAR attribute content
                FAPI_DBG("proc_setup_bars_pcie_get_bar_attrs: Unit %d Range %d",
                         u, r);
                if (proc_setup_bars_common_check_bar(
                       ((PROC_SETUP_BARS_PCIE_RANGE_TYPE_MMIO[r])?
                        (pcie_mmio_bar_def):
                        (pcie_phb_bar_def)),
                       io_addr_ranges[u][r]) != false)
                {
                    FAPI_ERR("proc_setup_bars_pcie_get_bar_attrs: Error from proc_setup_bars_common_check_bar");
                    const uint8_t& UNIT = u;
                    const uint8_t& RANGE = r;
                    const uint64_t& BASE_ADDR = io_addr_ranges[u][r].base_addr;
                    const uint64_t& SIZE = io_addr_ranges[u][r].size;
                    FAPI_SET_HWP_ERROR(rc,
                        RC_PROC_SETUP_BARS_PCIE_BAR_ATTR_ERR);
                    break;
                }
            }
        }
    } while(0);

    FAPI_DBG("proc_setup_bars_pcie_get_bar_attrs: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: wrapper function to call all BAR attribute query functions
// parameters: io_smp_chip => structure encapsulating single chip in SMP
//                            topology (containing target for attribute
//                            query and storage for all address ranges)
// returns: FAPI_RC_SUCCESS if all attribute reads are successful & values
//              are valid,
//          else failing return code from attribute query function
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_get_bar_attrs(
    proc_setup_bars_smp_chip& io_smp_chip)
{
    // return code
    fapi::ReturnCode rc;

    // mark function entry
    FAPI_DBG("proc_setup_bars_get_bar_attrs: Start");

    do
    {
        FAPI_DBG("proc_setup_bars_get_bar_attrs: Querying base address/size attributes for non-mirrored memory range");
        rc = proc_setup_bars_memory_get_non_mirrored_attrs(
            &(io_smp_chip.chip->this_chip),
            io_smp_chip.non_mirrored_range);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_get_bar_attrs: Error from proc_setup_bars_memory_get_non_mirrored_attrs");
            break;
        }

        FAPI_DBG("proc_setup_bars_get_bar_attrs: Querying base address/size attributes for mirrored memory range");
        rc = proc_setup_bars_memory_get_mirrored_attrs(
            &(io_smp_chip.chip->this_chip),
            io_smp_chip.mirrored_range);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_get_bar_attrs: Error from proc_setup_bars_memory_get_mirrored_attrs");
            break;
        }

        FAPI_DBG("proc_setup_bars_get_bar_attrs: Querying base address/size attributes for foreign near memory ranges");
        rc = proc_setup_bars_memory_get_foreign_near_attrs(
            &(io_smp_chip.chip->this_chip),
            io_smp_chip.foreign_near_ranges);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_get_bar_attrs: Error from proc_setup_bars_memory_get_foreign_near_attrs");
            break;
        }

        FAPI_DBG("proc_setup_bars_get_bar_attrs: Querying base address/size attributes for foreign far memory ranges");
        rc = proc_setup_bars_memory_get_foreign_far_attrs(
            &(io_smp_chip.chip->this_chip),
            io_smp_chip.foreign_far_ranges);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_get_bar_attrs: Error from proc_setup_bars_memory_get_foreign_far_attrs");
            break;
        }

        FAPI_DBG("proc_setup_bars_get_bar_attrs: Querying base address/size attributes for PSI address range");
        rc = proc_setup_bars_psi_get_bar_attrs(
            &(io_smp_chip.chip->this_chip),
            io_smp_chip.psi_range);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_get_bar_attrs: Error from proc_setup_bars_psi_get_bar_attrs");
            break;
        }

        FAPI_DBG("proc_setup_bars_get_bar_attrs: Querying base address/size attributes for FSP address range");
        rc = proc_setup_bars_fsp_get_bar_attrs(
            &(io_smp_chip.chip->this_chip),
            io_smp_chip.fsp_range);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_get_bar_attrs: Error from proc_setup_bars_fsp_get_bar_attrs");
            break;
        }

        FAPI_DBG("proc_setup_bars_get_bar_attrs: Querying base address/size attributes for FSP MMIO mask");
        rc = proc_setup_bars_fsp_get_mmio_mask_attrs(
            &(io_smp_chip.chip->this_chip),
            io_smp_chip.fsp_mmio_mask_range);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_get_bar_attrs: Error from proc_setup_bars_fsp_get_mmio_mask_attrs");
            break;
        }

        FAPI_DBG("proc_setup_bars_get_bar_attrs: Querying base address/size attributes for INTP address range");
        rc = proc_setup_bars_intp_get_bar_attrs(
            &(io_smp_chip.chip->this_chip),
            io_smp_chip.intp_range);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_get_bar_attrs: Error from proc_setup_bars_intp_get_bar_attrs");
            break;
        }

        FAPI_DBG("proc_setup_bars_get_bar_attrs: Querying base address/size attributes for NX MMIO address range");
        rc = proc_setup_bars_nx_get_mmio_bar_attrs(
            &(io_smp_chip.chip->this_chip),
            io_smp_chip.nx_mmio_range);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_get_bar_attrs: Error from proc_setup_bars_intp_get_bar_attrs");
            break;
        }

        FAPI_DBG("proc_setup_bars_get_bar_attrs: Querying base address/size attributes for AS MMIO address range");
        rc = proc_setup_bars_as_get_mmio_bar_attrs(
            &(io_smp_chip.chip->this_chip),
            io_smp_chip.as_mmio_range);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_get_bar_attrs: Error from proc_setup_bars_intp_get_bar_attrs");
            break;
        }

        FAPI_DBG("proc_setup_bars_get_bar_attrs: Querying base address/size attributes for PCIe address ranges");
        rc = proc_setup_bars_pcie_get_bar_attrs(
            &(io_smp_chip.chip->this_chip),
            io_smp_chip.pcie_ranges);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_get_bar_attrs: Error from proc_setup_bars_pcie_get_bar_attrs");
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_setup_bars_get_bar_attrs: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: wrapper function to call all chip attribute query functions
//           (fabric configuration/node/position/BARs)
// parameters: i_proc_chip => pointer to HWP input structure for this chip
//             io_smp_chip => fully specified structure encapsulating
//                            single chip in SMP topology
// returns: FAPI_RC_SUCCESS if all attribute reads are successful & values
//              are valid,
//          else failing return code from attribute query function
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_process_chip(
    proc_setup_bars_proc_chip* i_proc_chip,
    proc_setup_bars_smp_chip& io_smp_chip)
{
    // return code
    fapi::ReturnCode rc;
    uint8_t pcie_enabled;
    uint8_t nx_enabled;

    // mark function entry
    FAPI_DBG("proc_setup_bars_process_chip: Start");

    do
    {
        // set HWP input pointer
        io_smp_chip.chip = i_proc_chip;

        // display target information for this chip
        FAPI_DBG("proc_setup_bars_process_chip: Target: %s",
                 io_smp_chip.chip->this_chip.toEcmdString());

        // get PCIe/DSMP mux attributes
        FAPI_DBG("proc_setup_bars_process_chip: Querying PCIe/DSMP mux attribute");
        rc = proc_fab_smp_get_pcie_dsmp_mux_attrs(&(io_smp_chip.chip->this_chip),
                                                  io_smp_chip.pcie_not_f_link);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_process_chip: Error from proc_fab_smp_get_pcie_dsmp_mux_attrs");
            break;
        }

        // get node ID attribute
        FAPI_DBG("proc_setup_bars_process_chip: Querying node ID attribute");
        rc = proc_fab_smp_get_node_id_attr(&(io_smp_chip.chip->this_chip),
                                           io_smp_chip.node_id);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_process_chip: Error from proc_fab_smp_get_node_id_attr");
            break;
        }

        // get chip ID attribute
        FAPI_DBG("proc_setup_bars_process_chip: Querying chip ID attribute");
        rc = proc_fab_smp_get_chip_id_attr(&(io_smp_chip.chip->this_chip),
                                           io_smp_chip.chip_id);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_process_chip: Error from proc_fab_smp_get_chip_id_attr");
            break;
        }

        // query NX partial good attribute
        rc = FAPI_ATTR_GET(ATTR_PROC_NX_ENABLE,
                           &(io_smp_chip.chip->this_chip),
                           nx_enabled);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_process_chip: Error querying ATTR_PROC_NX_ENABLE");
            break;
        }

        // query PCIE partial good attribute
        rc = FAPI_ATTR_GET(ATTR_PROC_PCIE_ENABLE,
                           &(io_smp_chip.chip->this_chip),
                           pcie_enabled);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_process_chip: Error querying ATTR_PROC_PCIE_ENABLE");
            break;
        }

        io_smp_chip.nx_enabled =
            (nx_enabled == fapi::ENUM_ATTR_PROC_NX_ENABLE_ENABLE);

        io_smp_chip.pcie_enabled =
            (pcie_enabled == fapi::ENUM_ATTR_PROC_PCIE_ENABLE_ENABLE);

        // get BAR attributes
        rc = proc_setup_bars_get_bar_attrs(io_smp_chip);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_process_chip: Error from proc_fab_smp_get_mem_attrs");
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_setup_bars_process_chip: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: insert chip structure into proper position within SMP model based
//           on its fabric node/chip ID
//           chip non-mirrored/mirrored range information will be merged
//           with those of its enclosing node
// parameters: i_smp_chip => structure encapsulating single chip in SMP topology
//             io_smp     => structure encapsulating full SMP
// returns: FAPI_RC_SUCCESS if insertion is successful and merged node ranges
//              are valid,
//          RC_PROC_SETUP_BARS_NODE_ADD_INTERNAL_ERR if node map insert fails,
//          RC_PROC_SETUP_BARS_DUPLICATE_FABRIC_ID_ERR if chips with duplicate
//              fabric node/chip IDs are detected,
//          RC_PROC_SETUP_BARS_NODE_NON_MIRRORED_RANGE_OVERLAP_ERR if overlap
//              is detected between existing node non-mirrored range
//              and that of new chip being processed,
//          RC_PROC_SETUP_BARS_NODE_MIRRORED_RANGE_OVERLAP_ERR if overlap
//              is detected between existing node mirrored range
//              and that of new chip being processed
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_insert_chip(
    proc_setup_bars_smp_chip& i_smp_chip,
    proc_setup_bars_smp_system& io_smp)
{
    // return code
    fapi::ReturnCode rc;
    // node/chip ID
    proc_fab_smp_node_id node_id = i_smp_chip.node_id;
    proc_fab_smp_chip_id chip_id = i_smp_chip.chip_id;

    // mark function entry
    FAPI_DBG("proc_setup_bars_insert_chip: Start");

    do
    {
        FAPI_DBG("proc_setup_bars_insert_chip: Inserting n%d p%d",
                 node_id, chip_id);

        // search to see if node structure already exists for the node ID
        // associated with this chip
        std::map<proc_fab_smp_node_id, proc_setup_bars_smp_node>::iterator
            n_iter;
        n_iter = io_smp.nodes.find(node_id);
        // no matching node found, create one
        if (n_iter == io_smp.nodes.end())
        {
            FAPI_DBG("proc_setup_bars_insert_chip: No matching node found, inserting new node structure");
            proc_setup_bars_smp_node n;
            std::pair<
                std::map<proc_fab_smp_node_id, proc_setup_bars_smp_node>::iterator,
                bool> ret;
            ret = io_smp.nodes.insert(
                std::pair<proc_fab_smp_node_id, proc_setup_bars_smp_node>
                (node_id, n));
            n_iter = ret.first;
            if (!ret.second)
            {
                FAPI_ERR("proc_setup_bars_insert_chip: Error encountered adding node to SMP");
                FAPI_SET_HWP_ERROR(rc,
                    RC_PROC_SETUP_BARS_NODE_ADD_INTERNAL_ERR);
                break;
            }
        }

        // search to see if match exists in this node for the chip ID associated
        // with this chip
        std::map<proc_fab_smp_chip_id, proc_setup_bars_smp_chip>::iterator
            p_iter;
        p_iter = io_smp.nodes[node_id].chips.find(chip_id);
        // matching chip ID & node ID already found, flag an error
        if (p_iter != io_smp.nodes[node_id].chips.end())
        {
            FAPI_ERR("proc_setup_bars_insert_chip: Duplicate fabric node ID / chip ID found");
            const uint8_t& NODE_ID = node_id;
            const uint8_t& CHIP_ID = chip_id;
            FAPI_SET_HWP_ERROR(rc,
                RC_PROC_SETUP_BARS_DUPLICATE_FABRIC_ID_ERR);
            break;
        }
        // insert chip into SMP
        io_smp.nodes[node_id].chips[chip_id] = i_smp_chip;

        // update node address regions
        io_smp.nodes[node_id].non_mirrored_ranges.push_back(&(io_smp.nodes[node_id].chips[chip_id].non_mirrored_range));
        i_smp_chip.non_mirrored_range.print();

        io_smp.nodes[node_id].mirrored_ranges.push_back(&(io_smp.nodes[node_id].chips[chip_id].mirrored_range));
        i_smp_chip.mirrored_range.print();

    } while(0);

    // mark function exit
    FAPI_DBG("proc_setup_bars_insert_chip: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: wrapper function to process all HWP input structures and build
//           SMP data structure
// parameters: i_proc_chips => vector of HWP input structures (one entry per
//                             chip in SMP)
//             io_smp       => fully specified structure encapsulating full SMP
// returns: FAPI_RC_SUCCESS if all processing is successful,
//          else failing return code from chip processing/insertion wrapper
//              functions
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_process_chips(
    std::vector<proc_setup_bars_proc_chip>& i_proc_chips,
    proc_setup_bars_smp_system& io_smp)
{
    // return code
    fapi::ReturnCode rc;

    // mark function entry
    FAPI_DBG("proc_setup_bars_process_chips: Start");

    do
    {
        // loop over all chips passed from platform to HWP
        std::vector<proc_setup_bars_proc_chip>::iterator c_iter;
        for (c_iter = i_proc_chips.begin();
             c_iter != i_proc_chips.end();
             c_iter++)
        {
            // process platform provided data in chip argument,
            // query chip specific attributes
            proc_setup_bars_smp_chip smp_chip;
            rc = proc_setup_bars_process_chip(&(*c_iter),
                                              smp_chip);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_process_chips: Error from proc_setup_bars_process_chip");
                break;
            }

            // insert chip into SMP data structure given node & chip ID
            rc = proc_setup_bars_insert_chip(smp_chip,
                                             io_smp);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_process_chips: Error from proc_setup_bars_insert_chip");
                break;
            }
        }
        if (!rc.ok())
        {
            break;
        }

        // perform final adjustment on node specific resources once
        // all chips have been processed
        std::map<proc_fab_smp_node_id, proc_setup_bars_smp_node>::iterator n_iter;
        for (n_iter = io_smp.nodes.begin();
             n_iter != io_smp.nodes.end();
             n_iter++)
        {
            FAPI_DBG("Performing final adjustment on n%d", n_iter->first);

            // merge into single range
            for (uint8_t r = 0; r < n_iter->second.non_mirrored_ranges.size(); r++)
            {
                n_iter->second.non_mirrored_ranges[r]->print();
            }

            // before merging, check that non-mirrored & mirrored ranges are non-overlapping
            if (proc_setup_bars_common_do_ranges_overlap(n_iter->second.non_mirrored_ranges))
            {
                FAPI_ERR("proc_setup_bars_process_chips: Existing node non-mirrored range overlaps chip non-mirrored range");
                const uint8_t& NODE_ID = n_iter->first;
                FAPI_SET_HWP_ERROR(rc,
                    RC_PROC_SETUP_BARS_NODE_NON_MIRRORED_RANGE_OVERLAP_ERR);
                break;
            }

            if (proc_setup_bars_common_do_ranges_overlap(n_iter->second.mirrored_ranges))
            {
                FAPI_ERR("proc_setup_bars_process_chips: Existing node mirrored range overlaps chip mirrored range");
                const uint8_t& NODE_ID = n_iter->first;
                FAPI_SET_HWP_ERROR(rc,
                    RC_PROC_SETUP_BARS_NODE_MIRRORED_RANGE_OVERLAP_ERR);
                break;
            }

            // merge into single range
            for (uint8_t r = 0; r < n_iter->second.non_mirrored_ranges.size(); r++)
            {
                n_iter->second.non_mirrored_range.merge(*(n_iter->second.non_mirrored_ranges[r]));
            }

            for (uint8_t r = 0; r < n_iter->second.mirrored_ranges.size(); r++)
            {
                n_iter->second.mirrored_range.merge(*(n_iter->second.mirrored_ranges[r]));
            }

            // update node address ranges (non-mirrored & mirrored)
            FAPI_DBG("proc_setup_bars_process_chips: Ranges after merging:");
            n_iter->second.non_mirrored_range.print();
            n_iter->second.mirrored_range.print();

            // update node address ranges (non-mirrored & mirrored) t
            // ensure ranges are power of 2 aligned
            FAPI_DBG("proc_setup_bars_process_chips: Node %d ranges after power of two alignment:",
                     n_iter->first);
            if (n_iter->second.non_mirrored_range.enabled &&
                !n_iter->second.non_mirrored_range.is_power_of_2())
            {
                n_iter->second.non_mirrored_range.round_next_power_of_2();
            }
            n_iter->second.non_mirrored_range.print();

            if (n_iter->second.mirrored_range.enabled &&
                !n_iter->second.mirrored_range.is_power_of_2())
            {
                n_iter->second.mirrored_range.round_next_power_of_2();
            }
            n_iter->second.mirrored_range.print();
        }
        if (!rc.ok())
        {
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_setup_bars_process_chips: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: utility function to write HW BAR register given address range
//           structure and register definition structure
// parameters: i_target      => chip target
//             i_scom_addr   => BAR SCOM address
//             i_bar_reg_def => structure defining rules to format address
//                              range content into register layout
//             i_addr_range  => structure defining BAR address range
//                              (enable/base/size)
// returns: FAPI_RC_SUCCESS if register write is successful,
//          RC_PROC_SETUP_BARS_INVALID_BAR_REG_DEF if BAR register definition
//              structure is invalid,
//          RC_PROC_SETUP_BARS_SIZE_XLATE_ERR if logical->physical size
//              translation is unsuccessful,
//          else failing return code from SCOM/data buffer manipulation
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_common_write_bar_reg(
    const fapi::Target& i_target,
    const uint32_t& i_scom_addr,
    const proc_setup_bars_bar_reg_def& i_bar_reg_def,
    const proc_setup_bars_addr_range& i_addr_range)
{
    // return code
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    // BAR register data buffer
    ecmdDataBufferBase bar_data(64);
    ecmdDataBufferBase bar_data_mask(64);
    ecmdDataBufferBase size_data(64);
    ecmdDataBufferBase static_data(64);
    ecmdDataBufferBase static_data_mask(64);

    FAPI_DBG("proc_setup_bars_common_write_bar_reg: Start");
    do
    {
        // write base address
        if (i_bar_reg_def.has_base)
        {
            // previous checking ensures zeroes for all non-implemented bits
            rc_ecmd |= bar_data.setDoubleWord(0, i_addr_range.base_addr);
            // shift position to proper location in register
            if (i_bar_reg_def.base_shift == PROC_SETUP_BARS_SHIFT_LEFT)
            {
                rc_ecmd |= bar_data.shiftLeft(i_bar_reg_def.base_shift_amount);
            }
            else if (i_bar_reg_def.base_shift == PROC_SETUP_BARS_SHIFT_RIGHT)
            {
                rc_ecmd |= bar_data.shiftRight(i_bar_reg_def.base_shift_amount);
            }
            else if (i_bar_reg_def.base_shift != PROC_SETUP_BARS_SHIFT_NONE)
            {
                FAPI_ERR("proc_setup_bars_common_write_bar_reg: Invalid base shift value in register definition");
                FAPI_SET_HWP_ERROR(
                    rc,
                    RC_PROC_SETUP_BARS_INVALID_BAR_REG_DEF);
                break;
            }
            // set mask
            rc_ecmd |= bar_data_mask.setBit(i_bar_reg_def.base_start_bit,
                                            (i_bar_reg_def.base_end_bit -
                                             i_bar_reg_def.base_start_bit + 1));
        }

        // write enable bit
        if (i_bar_reg_def.has_enable)
        {
            rc_ecmd |= bar_data.writeBit(i_bar_reg_def.enable_bit,
                                         i_addr_range.enabled ? 1 : 0);
            rc_ecmd |= bar_data_mask.setBit(i_bar_reg_def.enable_bit);
        }

        // write size field
        if (i_bar_reg_def.has_size)
        {
            // encoded size value for register programming
            std::map<uint64_t, uint64_t>::const_iterator s;
            uint64_t size_xlate;
            // translate size into register encoding
            s = i_bar_reg_def.xlate_map->find(i_addr_range.size);
            if (s == i_bar_reg_def.xlate_map->end())
            {
                FAPI_ERR("proc_setup_bars_common_write_bar_reg: Unsupported BAR size 0x%016llX",
                         i_addr_range.size);
                const uint64_t& SIZE = i_addr_range.size;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_SETUP_BARS_SIZE_XLATE_ERR);
                break;
            }
            size_xlate = s->second;

            rc_ecmd |= size_data.setDoubleWord(0, size_xlate);
            rc_ecmd |= size_data.shiftLeft(63 - i_bar_reg_def.size_end_bit);
            rc_ecmd |= bar_data.merge(size_data);
            rc_ecmd |= bar_data_mask.setBit(i_bar_reg_def.size_start_bit,
                                            (i_bar_reg_def.size_end_bit -
                                             i_bar_reg_def.size_start_bit + 1));
        }

        // merge static data & mask
        rc_ecmd |= static_data.setDoubleWord(
            0,
            i_bar_reg_def.static_data);
        rc_ecmd |= static_data_mask.setDoubleWord(
            0,
            i_bar_reg_def.static_data_mask);

        rc_ecmd |= bar_data.merge(static_data);
        rc_ecmd |= bar_data_mask.merge(static_data_mask);

        // check buffer manipulation return codes
        if (rc_ecmd)
        {
            FAPI_ERR("proc_setup_bars_common_write_bar_reg: Error 0x%X setting up BAR data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write BAR register with updated content
        rc = fapiPutScomUnderMask(i_target,
                                  i_scom_addr,
                                  bar_data,
                                  bar_data_mask);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_common_f_scope_write_bar_reg: fapiPutScomUnderMask error (%08X)",
                     i_scom_addr);
            break;
        }
    } while(0);

    FAPI_DBG("proc_setup_bars_common_write_bar_reg: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: write L3 BAR attributes (consumed by winkle image creation
//           procedures) specific to enabled local chip
//           non-mirrored/mirrored memory ranges
// parameters: i_target                => chip target
//             i_is_non_mirrored_range => boolean idenitfying range type
//                                        (true=non-mirrored, false=mirrored)
//             i_addr_range            => structure representing chip
//                                        non-mirrored/mirrored range
// returns: FAPI_RC_SUCCESS if attribute writes are successful,
//          RC_PROC_SETUP_BARS_SIZE_XLATE_ERR if logical->physical size
//              translation is unsuccessful,
//          else failing return code from attribute/data buffer manipulation
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_l3_write_local_chip_memory_bar_attr(
    const fapi::Target* i_target,
    const bool& i_is_non_mirrored_range,
    const proc_setup_bars_addr_range& i_addr_range)
{
    // return code
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    // BAR1 register data buffer
    ecmdDataBufferBase bar_data(64);
    ecmdDataBufferBase bar_size_data(64);
    uint64_t bar_attr_data;

    FAPI_DBG("proc_setup_bars_l3_write_local_chip_memory_bar_attr: Start");
    do
    {
        // previous checking ensures zeroes for all non-implemented bits
        rc_ecmd |= bar_data.setDoubleWord(0, i_addr_range.base_addr);
        rc_ecmd |= bar_data.shiftLeft(L3_BAR12_BASE_ADDR_LEFT_SHIFT_AMOUNT);

        // encoded size value for register programming
        std::map<uint64_t, uint64_t>::const_iterator s;
        uint64_t size_xlate;
        // translate size into register encoding
        s = proc_setup_bars_nf_bar_size::xlate_map.find(i_addr_range.size);
        if (s == proc_setup_bars_nf_bar_size::xlate_map.end())
        {
            FAPI_ERR("proc_setup_bars_l3_write_local_chip_memory_bar_attr: Unsupported BAR size 0x%016llX",
                     i_addr_range.size);
            const uint64_t& SIZE = i_addr_range.size;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_SETUP_BARS_SIZE_XLATE_ERR);
            break;
        }
        size_xlate = s->second;
        rc_ecmd |= bar_size_data.setDoubleWord(0, size_xlate);
        rc_ecmd |= bar_size_data.shiftLeft(63 - L3_BAR12_SIZE_END_BIT);
        rc_ecmd |= bar_data.merge(bar_size_data);

        // enable bit only in BAR2
        if (!i_is_non_mirrored_range)
        {
            rc_ecmd |= bar_data.writeBit(L3_BAR2_ENABLE_BIT,
                                         i_addr_range.enabled ? 1 : 0);
        }

        // check buffer manipulation return codes
        if (rc_ecmd)
        {
            FAPI_ERR("proc_setup_bars_l3_write_local_chip_memory_bar_attr: Error 0x%X setting up BAR data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // set data for attribute push
        bar_attr_data = bar_data.getDoubleWord(0);

        if (i_is_non_mirrored_range)
        {
            // L3 BAR1 (non-mirrored)
            FAPI_DBG("proc_setup_bars_l3_write_local_chip_memory_bar_attr: Setting ATTR_PROC_L3_BAR1_REG = %016llX",
                     bar_attr_data);
            rc = FAPI_ATTR_SET(ATTR_PROC_L3_BAR1_REG,
                               i_target,
                               bar_attr_data);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_l3_write_local_chip_memory_bar_attr: Error setting ATTR_PROC_L3_BAR1_REG");
                break;
            }
        }
        else
        {
            // L3 BAR2 (mirrored)
            FAPI_DBG("proc_setup_bars_l3_write_local_chip_memory_bar_attr: Setting ATTR_PROC_L3_BAR2_REG = %016llX",
                     bar_attr_data);
            rc = FAPI_ATTR_SET(ATTR_PROC_L3_BAR2_REG,
                               i_target,
                               bar_attr_data);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_l3_write_local_chip_memory_bar_attr: Error setting ATTR_PROC_L3_BAR2_REG");
                break;
            }
        }
    } while(0);

    FAPI_DBG("proc_setup_bars_l3_write_local_chip_memory_bar_attr: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: wrapper function to write PCIe BARs specific to enabled local
//           chip non-mirrored/mirrored memory ranges
// parameters: i_target             => chip target
//             i_non_mirrored_range => structure representing chip non-mirrored
//                                     address range
//             i_mirrored_range     => structure representing chip mirrored
//                                     address range
// returns: FAPI_RC_SUCCESS if all register writes are successful,
//          else failing return code from common BAR write function
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_pcie_write_local_chip_memory_bars(
    const fapi::Target& i_target,
    const proc_setup_bars_addr_range& i_non_mirrored_range,
    const proc_setup_bars_addr_range& i_mirrored_range)
{
    // return code
    fapi::ReturnCode rc;

    FAPI_DBG("proc_setup_bars_pcie_write_local_chip_memory_bars: Start");
    // loop over all units
    for (uint8_t u = 0;
         u < PROC_SETUP_BARS_PCIE_NUM_UNITS;
         u++)
    {
        if (i_non_mirrored_range.enabled)
        {
            FAPI_DBG("proc_setup_bars_pcie_write_local_chip_memory_bars: Writing PCIe %d Nodal Non-Mirrored BAR register",
                     u);
            rc = proc_setup_bars_common_write_bar_reg(
                i_target,
                PROC_SETUP_BARS_PCIE_CHIP_NON_MIRRORED_BAR[u],
                common_nf_scope_bar_reg_def,
                i_non_mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_pcie_write_local_chip_memory_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }
        }
        if (i_mirrored_range.enabled)
        {
            FAPI_DBG("proc_setup_bars_pcie_write_local_chip_memory_bars: Writing PCIe %d Nodal Mirrored BAR register",
                     u);
            rc = proc_setup_bars_common_write_bar_reg(
                i_target,
                PROC_SETUP_BARS_PCIE_CHIP_MIRRORED_BAR[u],
                common_nf_scope_bar_reg_def,
                i_mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_pcie_write_local_chip_memory_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }
        }
    }

    FAPI_DBG("proc_setup_bars_pcie_write_local_chip_memory_bars: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: write L3 BAR attributes (consumed by winkle image creation
//           procedures) specific to enabled local node
//           non-mirrored/mirrored memory ranges
// parameters: i_target                => chip target
//             i_is_non_mirrored_range => boolean idenitfying range type
//                                        (true=non-mirrored, false=mirrored)
//             i_node_addr_range       => structure representing node
//                                        non-mirrored/mirrored range
//             i_chip_addr_range       => structure representing chip
//                                        non-mirrored/mirrored range
// returns: FAPI_RC_SUCCESS if attribute writes are successful,
//          else failing return code from attribute/data buffer manipulation
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_l3_write_local_node_memory_bar_attr(
    const fapi::Target* i_target,
    const bool& i_is_non_mirrored_range,
    const proc_setup_bars_addr_range& i_node_addr_range,
    const proc_setup_bars_addr_range& i_chip_addr_range)
{
    // return code
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase base(64);
    ecmdDataBufferBase diff(64);
    ecmdDataBufferBase mask(64);
    uint64_t mask_attr = 0x0;

    FAPI_DBG("proc_setup_bars_l3_write_local_node_memory_bar_attr: Start");

    do
    {
        // retrieve mask register attribute
        rc = FAPI_ATTR_GET(ATTR_PROC_L3_BAR_GROUP_MASK_REG,
                           i_target,
                           mask_attr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_l3_write_local_node_memory_bar_attr: Error querying ATTR_PROC_L3_BAR_GROUP_MASK_REG");
            break;
        }
        FAPI_DBG("proc_setup_bars_l3_write_local_node_memory_bar_attr: Read ATTR_PROC_L3_BAR_GROUP_MASK_REG = %016llX",
                 mask_attr);
        // push current value into data buffer
        rc_ecmd |= mask.setDoubleWord(0, mask_attr);

        // set group mask based on first difference between
        // node start/end addresses
        uint32_t first_diff_bit = 0;
        // load base address
        rc_ecmd |= base.setDoubleWord(0, i_node_addr_range.base_addr);
        // load end address
        rc_ecmd |= diff.setDoubleWord(0, i_node_addr_range.end_addr());
        // XOR base/end address
        rc_ecmd |= diff.setXor(base, 0, 64);

        // walk range of XOR result over group mask, stop at first 1 found
        bool match_found = false;
        for (first_diff_bit = L3_BAR_GROUP_MASK_RA_DIFF_START_BIT;
             first_diff_bit <= L3_BAR_GROUP_MASK_RA_DIFF_END_BIT;
             first_diff_bit++)
        {
            if (diff.getBit(first_diff_bit))
            {
                match_found = true;
                break;
            }
        }

        if (match_found)
        {
            // set all group mask bits to a 1, starting from first bit which
            // was found to be different, to the end of the mask range
            uint32_t mask_set_start_bit = (i_is_non_mirrored_range)?
                L3_BAR_GROUP_MASK_NON_MIRROR_MASK_START_BIT:
                L3_BAR_GROUP_MASK_MIRROR_MASK_START_BIT;

            mask_set_start_bit += (first_diff_bit-
                                   L3_BAR_GROUP_MASK_RA_DIFF_START_BIT);

            uint32_t mask_set_num_bits = (i_is_non_mirrored_range)?
                L3_BAR_GROUP_MASK_NON_MIRROR_MASK_END_BIT:
                L3_BAR_GROUP_MASK_MIRROR_MASK_END_BIT;

            mask_set_num_bits -= (mask_set_start_bit-1);

            rc_ecmd |= mask.setBit(mask_set_start_bit,
                                   mask_set_num_bits);
        }

        // enable bit only for mirorred region
        if (!i_is_non_mirrored_range)
        {
            rc_ecmd |= mask.writeBit(L3_BAR_GROUP_MASK_MIRROR_ENABLE_BIT,
                                     i_node_addr_range.enabled ? 1 : 0);
        }

        // check buffer manipulation return codes
        if (rc_ecmd)
        {
            FAPI_ERR("proc_setup_bars_l3_write_local_node_memory_bar_attr: Error 0x%X setting up BAR mask data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // push current data buffer state back into attribute
        mask_attr = mask.getDoubleWord(0);
        FAPI_DBG("proc_setup_bars_l3_write_local_node_memory_bar_attr: Setting ATTR_PROC_L3_BAR_GROUP_MASK_REG = %016llX",
                 mask_attr);
        rc = FAPI_ATTR_SET(ATTR_PROC_L3_BAR_GROUP_MASK_REG,
                           i_target,
                           mask_attr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_l3_write_local_node_memory_bar_attr: Error setting ATTR_PROC_L3_BAR_GROUP_MASK_REG");
            break;
        }

        // if no memory is installed on the local chip, fill the shared
        // BAR address with the node base
        if (!i_chip_addr_range.enabled)
        {
            // clear size mask
            proc_setup_bars_addr_range base_addr_range = i_node_addr_range;
            base_addr_range.size = PROC_SETUP_BARS_SIZE_4_GB;

            rc = proc_setup_bars_l3_write_local_chip_memory_bar_attr(
                i_target,
                i_is_non_mirrored_range,
                base_addr_range);

            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_l3_write_local_node_memory_bar_attr: Error from proc_setup_bars_l3_write_local_chip_memory_bar_attr");
                break;
            }
        }
    } while(0);


    FAPI_DBG("proc_setup_bars_l3_write_local_node_memory_bar_attr: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: wrapper function to write PCIe BARs specific to enabled local
//           node non-mirrored/mirrored memory ranges
// parameters: i_target             => chip target
//             i_non_mirrored_range => structure representing node non-mirrored
//                                     address range
//             i_mirrored_range     => structure representing node mirrored
//                                     address range
// returns: FAPI_RC_SUCCESS if all register writes are successful,
//          else failing return code from common BAR write function
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_pcie_write_local_node_memory_bars(
    const fapi::Target& i_target,
    const proc_setup_bars_addr_range& i_non_mirrored_range,
    const proc_setup_bars_addr_range& i_mirrored_range)
{
    // return code
    fapi::ReturnCode rc;

    FAPI_DBG("proc_setup_bars_pcie_write_local_node_memory_bars: Start");
    // loop over all units
    for (uint8_t u = 0;
         u < PROC_SETUP_BARS_PCIE_NUM_UNITS;
         u++)
    {
        if (i_non_mirrored_range.enabled)
        {
            FAPI_DBG("proc_setup_bars_pcie_write_local_node_memory_bars: Writing PCIe %d Group Non-Mirrored BAR register",
                     u);
            rc = proc_setup_bars_common_write_bar_reg(
                i_target,
                PROC_SETUP_BARS_PCIE_NODE_NON_MIRRORED_BAR[u],
                common_nf_scope_bar_reg_def,
                i_non_mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_pcie_write_local_node_memory_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }
        }
        if (i_mirrored_range.enabled)
        {
            FAPI_DBG("proc_setup_bars_pcie_write_local_node_memory_bars: Writing PCIe %d Group Mirrored BAR register",
                     u);
            rc = proc_setup_bars_common_write_bar_reg(
                i_target,
                PROC_SETUP_BARS_PCIE_NODE_MIRRORED_BAR[u],
                common_nf_scope_bar_reg_def,
                i_mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_pcie_write_local_node_memory_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }
        }
    }

    FAPI_DBG("proc_setup_bars_pcie_write_local_node_memory_bars: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: wrapper function to write PCIe BARs specific to enabled local
//           chip near/far foreign memory ranges
//           NOTE: only links which are marked for processing will be acted on
// parameters: i_target              => chip target
//             i_process_links       => array of boolean values dictating which
//                                      links should be acted on (one per link)
//             i_foreign_near_ranges => array of structures representing
//                                      near foreign address range (one per link)
//             i_foreign_far_ranges  => array of structures representing
//                                      far foreign address range (one per link)
// returns: FAPI_RC_SUCCESS if all register writes are successful,
//          else failing return code from common BAR write function
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_pcie_write_foreign_memory_bars(
    const fapi::Target& i_target,
    const bool i_process_links[PROC_FAB_SMP_NUM_F_LINKS],
    const proc_setup_bars_addr_range i_foreign_near_ranges[PROC_FAB_SMP_NUM_F_LINKS],
    const proc_setup_bars_addr_range i_foreign_far_ranges[PROC_FAB_SMP_NUM_F_LINKS])
{
    // return code
    fapi::ReturnCode rc;

    FAPI_DBG("proc_setup_bars_pcie_write_foreign_memory_bars: Start");

    // loop over all units
    for (uint8_t u = 0;
         (u < PROC_SETUP_BARS_PCIE_NUM_UNITS) && (rc.ok());
         u++)
    {
        // process ranges
        for (uint8_t r = 0;
             (r < PROC_FAB_SMP_NUM_F_LINKS) && (rc.ok());
             r++)
        {
            if (i_foreign_near_ranges[r].enabled && i_process_links[r])
            {
                FAPI_DBG("proc_setup_bars_pcie_write_foreign_memory_bars: Writing PCIe %d Foreign F%d Near BAR register",
                         u, r);
                rc = proc_setup_bars_common_write_bar_reg(
                    i_target,
                    PROC_SETUP_BARS_PCIE_FOREIGN_NEAR_BAR[u][r],
                    common_f_scope_bar_reg_def,
                    i_foreign_near_ranges[r]);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_setup_bars_pcie_write_foreign_memory_bars: Error from proc_setup_bars_common_write_bar_reg");
                    break;
                }
            }
            if (i_foreign_far_ranges[r].enabled && i_process_links[r])
            {
                FAPI_DBG("proc_setup_bars_pcie_write_foreign_memory_bars: Writing PCIe %d Foreign F%d Far BAR register",
                         u, r);
                rc = proc_setup_bars_common_write_bar_reg(
                    i_target,
                    PROC_SETUP_BARS_PCIE_FOREIGN_FAR_BAR[u][r],
                    common_f_scope_bar_reg_def,
                    i_foreign_far_ranges[r]);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_setup_bars_pcie_write_foreign_memory_bars: Error from proc_setup_bars_common_write_bar_reg");
                    break;
                }
            }
        }
    }

    FAPI_DBG("proc_setup_bars_pcie_write_foreign_memory_bars: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: wrapper function to write enabled PCIe IO BARs
// parameters: i_target       => chip target
//             io_addr_ranges => 2D array of address range structures
//                               encapsulating attribute values
//                               (first dimension = unit, second dimension =
//                                links per unit)
// returns: FAPI_RC_SUCCESS if all register writes are successful,
//          else failing return code from common BAR write function or
//              data buffer manipulation
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_pcie_write_io_bar_regs(
    const fapi::Target& i_target,
    const proc_setup_bars_addr_range addr_ranges[PROC_SETUP_BARS_PCIE_NUM_UNITS][PROC_SETUP_BARS_PCIE_RANGES_PER_UNIT])
{
    // return code
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    FAPI_DBG("proc_setup_bars_pcie_write_io_bar_regs: Start");
    // loop over all units
    for (uint8_t u = 0;
         u < PROC_SETUP_BARS_PCIE_NUM_UNITS;
         u++)
    {
        // enable bit/mask bit per range
        ecmdDataBufferBase enable_data(64);
        ecmdDataBufferBase enable_mask(64);

        // loop over all ranges
        for (uint8_t r = 0;
             r < PROC_SETUP_BARS_PCIE_RANGES_PER_UNIT;
             r++)
        {
            if (addr_ranges[u][r].enabled)
            {
                // MMIO range (BAR + mask)
                if (PROC_SETUP_BARS_PCIE_RANGE_TYPE_MMIO[r])
                {
                    // write BAR register
                    FAPI_DBG("proc_setup_bars_pcie_write_io_bar_regs: Writing PCIe %d MMIO BAR%d register",
                             u, r);
                    rc = proc_setup_bars_common_write_bar_reg(
                        i_target,
                        PROC_SETUP_BARS_PCIE_BAR_REGS_MMIO[u][r],
                        pcie_mmio_bar_reg_def,
                        addr_ranges[u][r]);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_setup_bars_pcie_write_io_bar_regs: Error from proc_setup_bars_common_write_bar_reg");
                        break;
                    }

                    // write BAR mask register
                    FAPI_DBG("proc_setup_bars_pcie_write_io_bar_regs: Writing PCIe %d MMIO BAR%d Mask register",
                             u, r);
                    rc = proc_setup_bars_common_write_bar_reg(
                        i_target,
                        PROC_SETUP_BARS_PCIE_BAR_MASK_REGS_MMIO[u][r],
                        pcie_mmio_bar_mask_reg_def,
                        addr_ranges[u][r]);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_setup_bars_pcie_write_io_bar_regs: Error from proc_setup_bars_common_write_bar_reg");
                        break;
                    }
                }
                // PHB range (only BAR, mask is implied)
                else
                {
                    for (uint8_t i = 0;
                         i < PROC_SETUP_BARS_PCIE_REGS_PER_PHB_RANGE;
                         i++)
                    {
                        FAPI_DBG("proc_setup_bars_pcie_write_io_bar_regs: Writing PCIe %d PHB BAR (%s) register",
                                 u, (i == 0)?("Nest"):("PCIe"));
                        rc = proc_setup_bars_common_write_bar_reg(
                            i_target,
                            PROC_SETUP_BARS_PCIE_BAR_REGS_PHB[u][i],
                            pcie_phb_bar_reg_def,
                            addr_ranges[u][r]);
                        if (!rc.ok())
                        {
                            FAPI_ERR("proc_setup_bars_pcie_write_io_bar_regs: Error from proc_setup_bars_common_write_bar_reg");
                            break;
                        }
                    }
                    if (!rc.ok())
                    {
                        break;
                    }
                }
                // set enable bit data/mask
                rc_ecmd |= enable_data.setBit(
                    PROC_SETUP_BARS_PCIE_BAR_EN_BIT[r]);
                rc_ecmd |= enable_mask.setBit(
                    PROC_SETUP_BARS_PCIE_BAR_EN_BIT[r]);
                // check buffer manipulation return codes
                if (rc_ecmd)
                {
                    FAPI_ERR("proc_setup_bars_pcie_write_io_bar_regs: Error 0x%X setting up BAR Enable data buffer",
                             rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
            }
        }
        if (!rc.ok())
        {
            break;
        }

        if (enable_data.getDoubleWord(0) != 0x0ULL)
        {
            // set static data field with BAR enable bits
            proc_setup_bars_bar_reg_def pcie_bar_en_reg_def =
            {
                false,                         // base: other reg
                PROC_SETUP_BARS_SHIFT_NONE,
                0,
                0,
                0,
                false,                         // enable: static data
                0,
                false,                         // size: other reg
                0,
                0,
                NULL,
                enable_data.getDoubleWord(0),
                enable_mask.getDoubleWord(0)
            };
            proc_setup_bars_addr_range pcie_bar_en_dummy_range;

            // write BAR enable register (do last, when all unit BAR content is set)
            rc = proc_setup_bars_common_write_bar_reg(
                i_target,
                PROC_SETUP_BARS_PCIE_BAR_EN_REGS[u],
                pcie_bar_en_reg_def,
                pcie_bar_en_dummy_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_pcie_write_io_bar_regs: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }

            // if enabling BARs, pull ETU out of reset
            ecmdDataBufferBase etu_reset(64);
            rc = fapiPutScom(i_target,
                             PROC_SETUP_BARS_PCIE_ETU_RESET_REGS[u],
                             etu_reset);
            if (!rc.ok())
            {
               FAPI_ERR("proc_setup_bars_pcie_write_io_bar_regs: Error from fapiPutScom (PCIE%d_ETU_RESET_0x%08X)",
                        u, PROC_SETUP_BARS_PCIE_ETU_RESET_REGS[u]);
               break;
            }
        }
    }

    FAPI_DBG("proc_setup_bars_pcie_write_io_bar_regs: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: wrapper function to write all BARs tied to local chip region
//           (non-mirrored/mirrored/MMIO regions)
// parameters: i_smp_chip => structure encapsulating single chip in SMP topology
// returns: FAPI_RC_SUCCESS if all register writes are successful,
//          else failing return code from common BAR write function
//------------------------------------------------------------------------------
//
// Local chip region BARs:
//
// PSI/FSP
//   PSI Bridge BAR                           (PSI_BRIDGE_BAR_0x0201090A)
//   FSP BAR                                  (PSI_FSP_BAR_0x0201090B)
//   FSP Memory Mask                          (PSI_FSP_MMR_0x0201090C)
//   FSP MMIO Mask                            (PSI_BRIDGE_STATUS_CTL_0x0201090E)
//
// INTP
//   INTP BAR                                 (ICP_BAR_0x020109CA)
//
// L3 (transmitted via attributes)
//   L3 BAR1 (Non-Mirrored)                   (EX_L3_BAR1_0x1001080B)
//   L3 BAR2 (Mirrored)                       (EX_L3_BAR2_0x10010813)
//
// NX
//   NX MMIO BAR                              (NX_MMIO_BAR_0x0201308D)
//   NX APC Nodal Non-Mirrored BAR            (NX_APC_NODAL_BAR0_0x0201302D)
//   NX Nodal Non-Mirrored BAR                (NX_NODAL_BAR0_0x02013095)
//   NX APC Nodal Mirrored BAR                (NX_APC_NODAL_BAR1_0x0201302E)
//   NX Nodal Mirrored BAR                    (NX_NODAL_BAR1_0x02013096)
//
// HCA
//   HCA EN BAR and Range Register            (HCA_EN_BAR_0x0201094A)
//   HCA EN Mirror BAR and Range Register     (HCA_EN_MIRROR_BAR_0x02010953)
//   HCA EH BAR and Range Register            (HCA_EH_BAR_0x0201098A)
//   HCA EH Mirror BAR and Range Register     (HCA_EH_MIRROR_BAR_0x02010993)
//
// MCD
//   MCD Configuration 0 (Non-Mirrored)       (MCD_CN00_0x0201340C)
//   MCD Configuration 1 (Mirrored)           (MCD_CN01_0x0201340D)
//
// PCIe
//   PCIE0 Nodal Non-Mirrored BAR             (PCIE0_NODAL_BAR0_0x02012010)
//   PCIE0 Nodal Mirrored BAR                 (PCIE0_NODAL_BAR1_0x02012011)
//   PCIE0 IO BAR0                            (PCIE0_IO_BAR0_0x02012040)
//   PCIE0 IO BAR0 Mask                       (PCIE0_IO_MASK0_0x02012043)
//   PCIE0 IO BAR1                            (PCIE0_IO_BAR1_0x02012041)
//   PCIE0 IO BAR1 Mask                       (PCIE0_IO_MASK1_0x02012044)
//   PCIE0 IO BAR2                            (PCIE0_IO_BAR2_0x02012042)
//   PCIE0 IO BAR Enable                      (PCIE0_IO_BAR_EN_0x02012045)
//
//   PCIE1 Nodal Non-Mirrored BAR             (PCIE1_NODAL_BAR0_0x02012410)
//   PCIE1 Nodal Mirrored BAR                 (PCIE1_NODAL_BAR1_0x02012411)
//   PCIE1_IO BAR0                            (PCIE1_IO_BAR0_0x02012440)
//   PCIE1_IO BAR0 Mask                       (PCIE1_IO_MASK0_0x02012443)
//   PCIE1_IO BAR1                            (PCIE1_IO_BAR1_0x02012441)
//   PCIE1_IO BAR1 Mask                       (PCIE1_IO_MASK1_0x02012444)
//   PCIE1_IO BAR2                            (PCIE1_IO_BAR2_0x02012442)
//   PCIE1_IO BAR Enable                      (PCIE1_IO_BAR_EN_0x02012445)
//
//   PCIE2 Nodal Non-Mirrored BAR             (PCIE2_NODAL_BAR0_0x02012810)
//   PCIE2 Nodal Mirrored BAR                 (PCIE2_NODAL_BAR1_0x02012811)
//   PCIE2 IO BAR0                            (PCIE2_IO_BAR0_0x02012840)
//   PCIE2 IO BAR0 Mask                       (PCIE2_IO_MASK0_0x02012843)
//   PCIE2 IO BAR1                            (PCIE2_IO_BAR1_0x02012841)
//   PCIE2 IO BAR1 Mask                       (PCIE2_IO_MASK1_0x02012844)
//   PCIE2 IO BAR2                            (PCIE2_IO_BAR2_0x02012842)
//   PCIE2 IO BAR Enable                      (PCIE2_IO_BAR_EN_0x02012845)
//
//------------------------------------------------------------------------------
fapi::ReturnCode
proc_setup_bars_write_local_chip_region_bars(
    proc_setup_bars_smp_chip& i_smp_chip)
{
    // return code
    fapi::ReturnCode rc;

    FAPI_DBG("proc_setup_bars_write_local_chip_region_bars: Start");

    do
    {
        // PSI
        if (i_smp_chip.psi_range.enabled)
        {
            FAPI_DBG("proc_setup_bars_write_local_chip_region_bars: Writing PSI Bridge BAR register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                PSI_BRIDGE_BAR_0x0201090A,
                psi_bridge_bar_reg_def,
                i_smp_chip.psi_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_chip_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }
        }

        // FSP
        if (i_smp_chip.fsp_range.enabled)
        {
            FAPI_DBG("proc_setup_bars_write_local_chip_region_bars: Writing FSP BAR register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                PSI_FSP_BAR_0x0201090B,
                fsp_bar_reg_def,
                i_smp_chip.fsp_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_chip_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }

            FAPI_DBG("proc_setup_bars_write_local_chip_region_bars: Writing FSP Memory Mask register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                PSI_FSP_MMR_0x0201090C,
                fsp_bar_mask_reg_def,
                i_smp_chip.fsp_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_chip_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }

            FAPI_DBG("proc_setup_bars_write_local_chip_region_bars: Writing PSI Bridge Status Control register (FSP BAR enable)");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                PSI_BRIDGE_STATUS_CTL_0x0201090E,
                fsp_bar_en_reg_def,
                i_smp_chip.fsp_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_chip_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }

            if (i_smp_chip.fsp_mmio_mask_range.enabled)
            {
                FAPI_DBG("proc_setup_bars_write_local_chip_region_bars: Writing PSI Bridge Status Control register (FSP MMIO mask)");
                rc = proc_setup_bars_common_write_bar_reg(
                    i_smp_chip.chip->this_chip,
                    PSI_BRIDGE_STATUS_CTL_0x0201090E,
                    fsp_mmio_mask_reg_def,
                    i_smp_chip.fsp_mmio_mask_range);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_setup_bars_write_local_chip_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                    break;
                }
            }
        }

        // INTP
        if (i_smp_chip.intp_range.enabled)
        {
            FAPI_DBG("proc_setup_bars_write_local_chip_region_bars: Writing INTP BAR register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                ICP_BAR_0x020109CA,
                intp_bar_reg_def,
                i_smp_chip.intp_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_chip_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }
        }

        // NX (MMIO)
        if (i_smp_chip.nx_mmio_range.enabled && i_smp_chip.nx_enabled)
        {
            FAPI_DBG("proc_setup_bars_write_local_chip_region_bars: Writing NX MMIO BAR register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                NX_MMIO_BAR_0x0201308D,
                nx_mmio_bar_reg_def,
                i_smp_chip.nx_mmio_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_chip_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }

            FAPI_DBG("proc_setup_bars_write_local_chip_region_bars: Writing AS MMIO BAR register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                NX_AS_MMIO_BAR_0x0201309E,
                as_mmio_bar_reg_def,
                i_smp_chip.as_mmio_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_chip_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }
        }

        // NX (non-mirrored)
        if (i_smp_chip.non_mirrored_range.enabled && i_smp_chip.nx_enabled)
        {
            FAPI_DBG("proc_setup_bars_write_local_chip_region_bars: Writing NX APC Nodal Non-Mirrored BAR register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                NX_APC_NODAL_BAR0_0x0201302D,
                common_nf_scope_bar_reg_def,
                i_smp_chip.non_mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_chip_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }

            FAPI_DBG("proc_setup_bars_write_local_chip_region_bars: Writing NX Nodal Non-Mirrored BAR register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                NX_NODAL_BAR0_0x02013095,
                common_nf_scope_bar_reg_def,
                i_smp_chip.non_mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_chip_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }
        }

        // NX (mirrored)
        if (i_smp_chip.mirrored_range.enabled && i_smp_chip.nx_enabled)
        {
            FAPI_DBG("proc_setup_bars_write_local_chip_region_bars: Writing NX APC Nodal Mirrored BAR register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                NX_APC_NODAL_BAR1_0x0201302E,
                common_nf_scope_bar_reg_def,
                i_smp_chip.mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_chip_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }

            FAPI_DBG("proc_setup_bars_write_local_chip_region_bars: Writing NX Nodal Mirrored BAR register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                NX_NODAL_BAR1_0x02013096,
                common_nf_scope_bar_reg_def,
                i_smp_chip.mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_chip_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }
        }

        // HCA (non-mirrored)
        if (i_smp_chip.non_mirrored_range.enabled)
        {
            FAPI_DBG("proc_setup_bars_write_local_chip_region_bars: Writing HCA EN BAR and Range (Non-Mirrored) register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                HCA_EN_BAR_0x0201094A,
                hca_nm_bar_reg_def,
                i_smp_chip.non_mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_chip_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }

            FAPI_DBG("proc_setup_bars_write_local_chip_region_bars: Writing HCA EH BAR and Range (Non-Mirrored) register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                HCA_EH_BAR_0x0201098A,
                hca_nm_bar_reg_def,
                i_smp_chip.non_mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_chip_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }
        }

        // HCA (mirrored)
        if (i_smp_chip.mirrored_range.enabled)
        {
            FAPI_DBG("proc_setup_bars_write_local_chip_region_bars: Writing HCA EN Mirror BAR and Range (Mirrored) register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                HCA_EN_MIRROR_BAR_0x02010953,
                hca_m_bar_reg_def,
                i_smp_chip.mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_chip_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }

            FAPI_DBG("proc_setup_bars_write_local_chip_region_bars: Writing HCA EH Mirror BAR and Range (Mirrored) register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                HCA_EH_MIRROR_BAR_0x02010993,
                hca_m_bar_reg_def,
                i_smp_chip.mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_chip_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }
        }

        // MCD (non-mirrored)
        if (i_smp_chip.non_mirrored_range.enabled)
        {
            FAPI_DBG("proc_setup_bars_write_local_chip_region_bars: Writing MCD Configuration 0 (Non-Mirrored) register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                MCD_CN00_0x0201340C,
                mcd_nf_bar_reg_def,
                i_smp_chip.non_mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_chip_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }
        }

        // MCD (mirrored)
        if (i_smp_chip.mirrored_range.enabled)
        {
            FAPI_DBG("proc_setup_bars_write_local_chip_region_bars: Writing MCD Configuration 1 (Mirrored) register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                MCD_CN01_0x0201340D,
                mcd_nf_bar_reg_def,
                i_smp_chip.mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_chip_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }
        }

        // L3 (non-mirrored)
        if (i_smp_chip.non_mirrored_range.enabled)
        {
            FAPI_DBG("proc_setup_bars_write_local_chip_region_bars: Writing L3 BAR1 (Non-Mirrored) attribute");
            rc = proc_setup_bars_l3_write_local_chip_memory_bar_attr(
                    &(i_smp_chip.chip->this_chip),
                    true,
                    i_smp_chip.non_mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_chip_region_bars: Error from proc_setup_bars_l3_write_local_chip_memory_bar_attr");
                break;
            }
        }

        // L3 (mirrored)
        if (i_smp_chip.mirrored_range.enabled)
        {
            FAPI_DBG("proc_setup_bars_write_local_chip_region_bars: Writing L3 BAR2 (Mirrored) attribute");
            rc = proc_setup_bars_l3_write_local_chip_memory_bar_attr(
                    &(i_smp_chip.chip->this_chip),
                    false,
                    i_smp_chip.mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_chip_region_bars: Error from proc_setup_bars_l3_write_local_chip_memory_bar_attr");
                break;
            }
        }

        // PCIe (non-mirrored/mirrored)
        if (i_smp_chip.pcie_enabled)
        {
            rc = proc_setup_bars_pcie_write_local_chip_memory_bars(
                i_smp_chip.chip->this_chip,
                i_smp_chip.non_mirrored_range,
                i_smp_chip.mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_chip_region_bars: Error from proc_setup_bars_pcie_write_local_chip_memory_bars");
                break;
            }
        }

        // PCIe (IO)
        if (i_smp_chip.pcie_enabled)
        {
            rc = proc_setup_bars_pcie_write_io_bar_regs(
                i_smp_chip.chip->this_chip,
                i_smp_chip.pcie_ranges);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_chip_region_bars: Error from proc_setup_bars_pcie_write_io_bar_regs");
                break;
            }
        }
    } while(0);

    FAPI_DBG("proc_setup_bars_write_local_chip_region_bars: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: wrapper function to write all BARs tied to local node region
//           (non-mirrored/mirrored regions)
// parameters: i_smp_chip => structure encapsulating single chip in SMP topology
//             i_smp_node => structure encapsulating node which this chip
//                           resides in
// returns: FAPI_RC_SUCCESS if all register writes are successful,
//          else failing return code from common BAR write function
//------------------------------------------------------------------------------
//
// Local node region BARs:
//
// L3 (transmitted via attributes)
//   L3 BAR Group Mask                        (EX_L3_BAR_GROUP_MASK_0x10010816)
//
// NX
//   NX APC Group Non-Mirorred BAR            (NX_APC_GROUP_BAR0_0x0201302F)
//   NX Group Non-Mirorred BAR                (NX_GROUP_BAR0_0x02013097)
//   NX APC Group Mirrored BAR                (NX_APC_GROUP_BAR1_0x02013030)
//   NX Group Mirrored BAR                    (NX_GROUP_BAR1_0x02013098)
//
// PCIe
//   PCIE0 Group Non-Mirrored BAR             (PCIE0_GROUP_BAR0_0x02012012)
//   PCIE0 Group Mirrored BAR                 (PCIE0_GROUP_BAR1_0x02012013)
//
//   PCIE1 Group Non-Mirrored BAR             (PCIE1_GROUP_BAR0_0x02012412)
//   PCIE1 Group Mirrored BAR                 (PCIE1_GROUP_BAR1_0x02012413)
//
//   PCIE2 Group Non-Mirrored BAR             (PCIE2_GROUP_BAR0_0x02012812)
//   PCIE2 Group Mirrored BAR                 (PCIE2_GROUP_BAR1_0x02012813)
//
//------------------------------------------------------------------------------
fapi::ReturnCode
proc_setup_bars_write_local_node_region_bars(
    proc_setup_bars_smp_chip& i_smp_chip,
    proc_setup_bars_smp_node& i_smp_node)
{
    // return code
    fapi::ReturnCode rc;

    FAPI_DBG("proc_setup_bars_write_local_node_region_bars: Start");

    do
    {
        // NX (non-mirrored)
        if (i_smp_node.non_mirrored_range.enabled && i_smp_chip.nx_enabled)
        {
            FAPI_DBG("proc_setup_bars_write_local_node_region_bars: Writing NX APC Group Non-Mirrored BAR register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                NX_APC_GROUP_BAR0_0x0201302F,
                common_nf_scope_bar_reg_def,
                i_smp_node.non_mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_node_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }

            FAPI_DBG("proc_setup_bars_write_local_node_region_bars: Writing NX Group Non-Mirrored BAR register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                NX_GROUP_BAR0_0x02013097,
                common_nf_scope_bar_reg_def,
                i_smp_node.non_mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_node_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }
        }

        // NX (mirrored)
        if (i_smp_node.mirrored_range.enabled && i_smp_chip.nx_enabled)
        {
            FAPI_DBG("proc_setup_bars_write_local_node_region_bars: Writing NX APC Group Mirrored BAR register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                NX_APC_GROUP_BAR1_0x02013030,
                common_nf_scope_bar_reg_def,
                i_smp_node.mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_node_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }

            FAPI_DBG("proc_setup_bars_write_local_node_region_bars: Writing NX Group Mirrored BAR register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                NX_GROUP_BAR1_0x02013098,
                common_nf_scope_bar_reg_def,
                i_smp_node.mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_node_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }
        }

        // L3 (non-mirrored)
        if (i_smp_node.non_mirrored_range.enabled)
        {
            rc = proc_setup_bars_l3_write_local_node_memory_bar_attr(
                &(i_smp_chip.chip->this_chip),
                true,
                i_smp_node.non_mirrored_range,
                i_smp_chip.non_mirrored_range);

            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_node_region_bars: Error from proc_setup_bars_l3_write_local_node_memory_bar_attr");
                break;
            }
        }

        // L3 (mirrored)
        if (i_smp_node.mirrored_range.enabled)
        {
            rc = proc_setup_bars_l3_write_local_node_memory_bar_attr(
                &(i_smp_chip.chip->this_chip),
                false,
                i_smp_node.mirrored_range,
                i_smp_chip.mirrored_range);

            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_node_region_bars: Error from proc_setup_bars_l3_write_local_node_memory_bar_attr");
                break;
            }
        }

        // PCIe (non-mirrored/mirrored)
        if (i_smp_chip.pcie_enabled)
        {
            rc = proc_setup_bars_pcie_write_local_node_memory_bars(
                i_smp_chip.chip->this_chip,
                i_smp_node.non_mirrored_range,
                i_smp_node.mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_local_node_region_bars: Error from proc_setup_bars_pcie_write_local_node_memory_bars");
                break;
            }
        }
    } while(0);

    FAPI_DBG("proc_setup_bars_write_local_node_region_bars: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: wrapper function to write all BARs tied to remote node regions
//           (non-mirrored/mirrored regions)
// parameters: i_smp_chip    => structure encapsulating single chip in SMP
//                              topology
//             i_smp_node_a0 => structure encapsulating node reachable from
//                              A0 link on this chip
//             i_smp_node_a1 => structure encapsulating node reachable from
//                              A1 link on this chip
//             i_smp_node_a2 => structure encapsulating node reachable from
//                              A2 link on this chip
// returns: FAPI_RC_SUCCESS if all register writes are successful,
//          else failing return code from common BAR write function
//------------------------------------------------------------------------------
//
// Remote node region BARs:
//
// PB
//   PB Remote Group (A0) Non-Mirrored BAR    (PB_RGMCFG00_0x02010C58)
//   PB Remote Group (A0) Mirrored BAR        (PB_RGMCFGM00_0x02010C5B)
//   PB Remote Group (A1) Non-Mirrored BAR    (PB_RGMCFG01_0x02010C59)
//   PB Remote Group (A1) Mirrored BAR        (PB_RGMCFGM01_0x02010C5C)
//   PB Remote Group (A2) Non-Mirrored BAR    (PB_RGMCFG10_0x02010C5A)
//   PB Remote Group (A2) Mirrored BAR        (PB_RGMCFGM10_0x02010C5D)
//
//------------------------------------------------------------------------------
fapi::ReturnCode
proc_setup_bars_write_remote_node_region_bars(
    proc_setup_bars_smp_chip& i_smp_chip,
    proc_setup_bars_smp_node& i_smp_node_a0,
    proc_setup_bars_smp_node& i_smp_node_a1,
    proc_setup_bars_smp_node& i_smp_node_a2)
{
    // return code
    fapi::ReturnCode rc;

    FAPI_DBG("proc_setup_bars_write_remote_node_region_bars: Start");

    do
    {
        // A0 (non-mirrored)
        if (i_smp_node_a0.non_mirrored_range.enabled)
        {
            FAPI_DBG("proc_setup_bars_write_remote_node_region_bars: Writing PB Remote Group (A0) Non-Mirrored Configuration register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                PB_RGMCFG00_0x02010C58,
                common_nf_scope_bar_reg_def,
                i_smp_node_a0.non_mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_remote_node_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }
        }

        // A0 (mirrored)
        if (i_smp_node_a0.mirrored_range.enabled)
        {
            FAPI_DBG("proc_setup_bars_write_remote_node_region_bars: Writing PB Remote Group (A0) Mirrored Configuration register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                PB_RGMCFGM00_0x02010C5B,
                common_nf_scope_bar_reg_def,
                i_smp_node_a0.mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_remote_node_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }
        }

        // A1 (non-mirrored)
        if (i_smp_node_a1.non_mirrored_range.enabled)
        {
            FAPI_DBG("proc_setup_bars_write_remote_node_region_bars: Writing PB Remote Group (A1) Non-Mirrored Configuration register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                PB_RGMCFG01_0x02010C59,
                common_nf_scope_bar_reg_def,
                i_smp_node_a1.non_mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_remote_node_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }
        }

        // A1 (mirrored)
        if (i_smp_node_a1.mirrored_range.enabled)
        {
            FAPI_DBG("proc_setup_bars_write_remote_node_region_bars: Writing PB Remote Group (A1) Mirrored Configuration register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                PB_RGMCFGM01_0x02010C5C,
                common_nf_scope_bar_reg_def,
                i_smp_node_a1.mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_remote_node_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }
        }

        // A2 (non-mirrored)
        if (i_smp_node_a2.non_mirrored_range.enabled)
        {
            FAPI_DBG("proc_setup_bars_write_remote_node_region_bars: Writing PB Remote Group (A2) Non-Mirrored Configuration register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                PB_RGMCFG10_0x02010C5A,
                common_nf_scope_bar_reg_def,
                i_smp_node_a2.non_mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_remote_node_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }
        }

        // A2 (mirrored)
        if (i_smp_node_a2.mirrored_range.enabled)
        {
            FAPI_DBG("proc_setup_bars_write_remote_node_region_bars: Writing PB Remote Group (A2) Mirrored Configuration register");
            rc = proc_setup_bars_common_write_bar_reg(
                i_smp_chip.chip->this_chip,
                PB_RGMCFGM10_0x02010C5D,
                common_nf_scope_bar_reg_def,
                i_smp_node_a2.mirrored_range);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_remote_node_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                break;
            }
        }
    } while(0);

    FAPI_DBG("proc_setup_bars_write_remote_node_region_bars: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: wrapper function to write all BARs tied to local chip foreign
//           regions (near/far)
// parameters: i_smp_chip    => structure encapsulating single chip in SMP
//                              topology
// returns: FAPI_RC_SUCCESS if all register writes are successful,
//          else failing return code from common BAR write function
//------------------------------------------------------------------------------
//
// Foreign region BARs:
//
// PB
//   PB F0 Near BAR (West)                    (PB_FLMCFG0_WEST_0x02010C12)
//   PB F0 Near BAR (Center)                  (PB_FLMCFG0_CENT_0x02010C5E)
//   PB F0 Near BAR (East)                    (PB_FLMCFG0_EAST_0x02010C92)
//   PB F0 Far BAR (West)                     (PB_FRMCFG0_WEST_0x02010C14)
//   PB F0 Far BAR (Center)                   (PB_FRMCFG0_CENT_0x02010C60)
//   PB F0 Far BAR (East)                     (PB_FRMCFG0_EAST_0x02010C94)
//   PB F1 Near BAR (West)                    (PB_FLMCFG1_WEST_0x02010C13)
//   PB F1 Near BAR (Center)                  (PB_FLMCFG1_CENT_0x02010C5F)
//   PB F1 Near BAR (East)                    (PB_FLMCFG1_EAST_0x02010C93)
//   PB F1 Far BAR (West)                     (PB_FRMCFG1_WEST_0x02010C15)
//   PB F1 Far BAR (Center)                   (PB_FRMCFG1_CENT_0x02010C61)
//   PB F1 Far BAR (East)                     (PB_FRMCFG1_EAST_0x02010C95)
//
// NX
//   NX APC F0 Near BAR                       (NX_APC_NEAR_BAR_F0_0x02013031)
//   NX APC F0 Far BAR                        (NX_APC_FAR_BAR_F0_0x02013032)
//   NX APC F1 Near BAR                       (NX_APC_NEAR_BAR_F1_0x02013033)
//   NX APC F1 Far BAR                        (NX_APC_FAR_BAR_F1_0x02013034)
//   NX F0 Near BAR                           (NX_NEAR_BAR_F0_0x02013099)
//   NX F0 Far BAR                            (NX_FAR_BAR_F0_0x0201309A)
//   NX F1 Near BAR                           (NX_NEAR_BAR_F1_0x0201309B)
//   NX F1 Far BAR                            (NX_FAR_BAR_F1_0x0201309C)
//
// MCD
//   MCD Configuration 2 (F0)                 (MCD_CN10_0x0201340E)
//   MCD Configuration 3 (F1)                 (MCD_CN11_0x0201340F)
//
// PCIe
//   PCIE0 F0 Near BAR                        (PCIE0_NEAR_BAR_F0_0x02012014)
//   PCIE0 F0 Far BAR                         (PCIE0_FAR_BAR_F0_0x02012015)
//   PCIE0 F1 Near BAR                        (PCIE0_NEAR_BAR_F1_0x02012016)
//   PCIE0 F1 Far BAR                         (PCIE0_FAR_BAR_F1_0x02012017)
//
//   PCIE1 F0 Near BAR                        (PCIE1_NEAR_BAR_F0_0x02012414)
//   PCIE1 F0 Far BAR                         (PCIE1_FAR_BAR_F0_0x02012415)
//   PCIE1 F1 Near BAR                        (PCIE1_NEAR_BAR_F1_0x02012416)
//   PCIE1 F1 Far BAR                         (PCIE1_FAR_BAR_F1_0x02012417)
//
//   PCIE2 F0 Near BAR                        (PCIE2_NEAR_BAR_F0_0x02012484)
//   PCIE2 F0 Far BAR                         (PCIE2_FAR_BAR_F0_0x02012815)
//   PCIE2 F1 Near BAR                        (PCIE2_NEAR_BAR_F1_0x02012816)
//   PCIE2 F1 Far BAR                         (PCIE2_FAR_BAR_F1_0x02012817)
//
//------------------------------------------------------------------------------
fapi::ReturnCode
proc_setup_bars_write_foreign_region_bars(
    proc_setup_bars_smp_chip& i_smp_chip)
{
    // return code
    fapi::ReturnCode rc;

    FAPI_DBG("proc_setup_bars_write_foreign_region_bars: Start");

    do
    {
        bool process_links[PROC_FAB_SMP_NUM_F_LINKS] =
        {
            i_smp_chip.chip->process_f0,
            i_smp_chip.chip->process_f1
        };

        // PCIe (near/far)
        if (i_smp_chip.pcie_enabled)
        {
            rc = proc_setup_bars_pcie_write_foreign_memory_bars(
                i_smp_chip.chip->this_chip,
                process_links,
                i_smp_chip.foreign_near_ranges,
                i_smp_chip.foreign_far_ranges);
            if (!rc.ok())
            {
                FAPI_ERR("proc_setup_bars_write_foreign_region_bars: Error from proc_setup_bars_pcie_write_foreign_memory_bars");
                break;
            }
        }

        // process ranges
        for (uint8_t r = 0;
             (r < PROC_FAB_SMP_NUM_F_LINKS) && (rc.ok());
             r++)
        {
            // near
            if (process_links[r] &&
                i_smp_chip.foreign_near_ranges[r].enabled)
            {
                // PB (near, west)
                FAPI_DBG("proc_setup_bars_write_foreign_region_bars: Writing PB F%d Near BAR (West) register",
                         r);
                rc = proc_setup_bars_common_write_bar_reg(
                    i_smp_chip.chip->this_chip,
                    (r == 0)?
                    PB_FLMCFG0_WEST_0x02010C12:
                    PB_FLMCFG1_WEST_0x02010C13,
                    common_f_scope_bar_reg_def,
                    i_smp_chip.foreign_near_ranges[r]);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_setup_bars_write_foreign_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                    break;
                }

                // PB (near, cent)
                FAPI_DBG("proc_setup_bars_write_foreign_region_bars: Writing PB F%d Near BAR (Center) register",
                         r);
                rc = proc_setup_bars_common_write_bar_reg(
                    i_smp_chip.chip->this_chip,
                    (r == 0)?
                    PB_FLMCFG0_CENT_0x02010C5E:
                    PB_FLMCFG1_CENT_0x02010C5F,
                    common_f_scope_bar_reg_def,
                    i_smp_chip.foreign_near_ranges[r]);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_setup_bars_write_foreign_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                    break;
                }

                // PB (near, east)
                FAPI_DBG("proc_setup_bars_write_foreign_region_bars: Writing PB F%d Near BAR (East) register",
                         r);
                rc = proc_setup_bars_common_write_bar_reg(
                    i_smp_chip.chip->this_chip,
                    (r == 0)?
                    PB_FLMCFG0_EAST_0x02010C92:
                    PB_FLMCFG1_EAST_0x02010C93,
                    common_f_scope_bar_reg_def,
                    i_smp_chip.foreign_near_ranges[r]);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_setup_bars_write_foreign_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                    break;
                }

                // NX APC (near)
                if (i_smp_chip.nx_enabled)
                {
                    FAPI_DBG("proc_setup_bars_write_foreign_region_bars: Writing NX APC F%d Near BAR register",
                             r);
                    rc = proc_setup_bars_common_write_bar_reg(
                        i_smp_chip.chip->this_chip,
                        (r == 0)?
                        NX_APC_NEAR_BAR_F0_0x02013031:
                        NX_APC_NEAR_BAR_F1_0x02013033,
                        common_f_scope_bar_reg_def,
                        i_smp_chip.foreign_near_ranges[r]);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_setup_bars_write_foreign_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                        break;
                    }
                }

                // NX (near)
                if (i_smp_chip.nx_enabled)
                {
                    FAPI_DBG("proc_setup_bars_write_foreign_region_bars: Writing NX F%d Near BAR register",
                             r);
                    rc = proc_setup_bars_common_write_bar_reg(
                        i_smp_chip.chip->this_chip,
                        (r == 0)?
                        NX_NEAR_BAR_F0_0x02013099:
                        NX_NEAR_BAR_F1_0x0201309B,
                        common_f_scope_bar_reg_def,
                        i_smp_chip.foreign_near_ranges[r]);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_setup_bars_write_foreign_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                        break;
                    }
                }

                // MCD (near only)
                FAPI_DBG("proc_setup_bars_write_foreign_region_bars: Writing MCD Configuration %d (F%d) register",
                         r+1, r);
                rc = proc_setup_bars_common_write_bar_reg(
                    i_smp_chip.chip->this_chip,
                    (r == 0)?
                    MCD_CN10_0x0201340E:
                    MCD_CN11_0x0201340F,
                    (r == 0)?
                    mcd_f0_bar_reg_def:
                    mcd_f1_bar_reg_def,
                    i_smp_chip.foreign_near_ranges[r]);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_setup_bars_write_foreign_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                    break;
                }
            }

            // far
            if (process_links[r] &&
                i_smp_chip.foreign_near_ranges[r].enabled)
            {
                // PB (far, west)
                FAPI_DBG("proc_setup_bars_write_foreign_region_bars: Writing PB F%d Far BAR (West) register",
                         r);
                rc = proc_setup_bars_common_write_bar_reg(
                    i_smp_chip.chip->this_chip,
                    (r == 0)?
                    PB_FRMCFG0_WEST_0x02010C14:
                    PB_FRMCFG1_WEST_0x02010C15,
                    common_f_scope_bar_reg_def,
                    i_smp_chip.foreign_far_ranges[r]);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_setup_bars_write_foreign_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                    break;
                }

                // PB (far, center)
                FAPI_DBG("proc_setup_bars_write_foreign_region_bars: Writing PB F%d Far BAR (Center) register",
                         r);
                rc = proc_setup_bars_common_write_bar_reg(
                    i_smp_chip.chip->this_chip,
                    (r == 0)?
                    PB_FRMCFG0_CENT_0x02010C60:
                    PB_FRMCFG1_CENT_0x02010C61,
                    common_f_scope_bar_reg_def,
                    i_smp_chip.foreign_far_ranges[r]);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_setup_bars_write_foreign_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                    break;
                }

                // PB (far, east)
                FAPI_DBG("proc_setup_bars_write_foreign_region_bars: Writing PB F%d Far BAR (East) register",
                         r);
                rc = proc_setup_bars_common_write_bar_reg(
                    i_smp_chip.chip->this_chip,
                    (r == 0)?
                    PB_FRMCFG0_EAST_0x02010C94:
                    PB_FRMCFG1_EAST_0x02010C95,
                    common_f_scope_bar_reg_def,
                    i_smp_chip.foreign_far_ranges[r]);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_setup_bars_write_foreign_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                    break;
                }

                // NX APC (far)
                if (i_smp_chip.nx_enabled)
                {
                    FAPI_DBG("proc_setup_bars_write_foreign_region_bars: Writing NX APC F%d Far BAR register",
                             r);
                    rc = proc_setup_bars_common_write_bar_reg(
                        i_smp_chip.chip->this_chip,
                        (r == 0)?
                        NX_APC_FAR_BAR_F0_0x02013032:
                        NX_APC_FAR_BAR_F1_0x02013034,
                        common_f_scope_bar_reg_def,
                        i_smp_chip.foreign_far_ranges[r]);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_setup_bars_write_foreign_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                        break;
                    }
                }

                // NX (far)
                if (i_smp_chip.nx_enabled)
                {
                    FAPI_DBG("proc_setup_bars_write_foreign_region_bars: Writing NX F%d Far BAR register",
                             r);
                    rc = proc_setup_bars_common_write_bar_reg(
                        i_smp_chip.chip->this_chip,
                        (r == 0)?
                        NX_FAR_BAR_F0_0x0201309A:
                        NX_FAR_BAR_F1_0x0201309C,
                        common_f_scope_bar_reg_def,
                        i_smp_chip.foreign_far_ranges[r]);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_setup_bars_write_foreign_region_bars: Error from proc_setup_bars_common_write_bar_reg");
                        break;
                    }
                }
            }
        }
    } while(0);

    FAPI_DBG("proc_setup_bars_write_foreign_region_bars: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: utility function to find node structure associated with a given
//           target
// parameters: i_target => chip target
//             i_smp    => structure encapsulating SMP topology
//             o_node   => node structure associated with chip target input
// returns: FAPI_RC_SUCCESS if matching node is found
//          RC_PROC_SETUP_BARS_NODE_FIND_INTERNAL_ERR if node map lookup is
//              unsuccessful,
//          else failing return code from node ID attribute query function
//------------------------------------------------------------------------------
fapi::ReturnCode
proc_setup_bars_find_node(
    const fapi::Target& i_target,
    proc_setup_bars_smp_system& i_smp,
    proc_setup_bars_smp_node& o_node)
{
    // return code
    fapi::ReturnCode rc;
    proc_fab_smp_node_id node_id;

    FAPI_DBG("proc_setup_bars_find_node: Start");

    do
    {
        // get node ID attribute
        FAPI_DBG("proc_setup_find_node: Querying node ID attribute");
        rc = proc_fab_smp_get_node_id_attr(&(i_target),
                                           node_id);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_find_node: Error from proc_fab_smp_get_node_id_attr");
            break;
        }

        // search to see if node structure already exists for the node ID
        // associated with this chip
        std::map<proc_fab_smp_node_id, proc_setup_bars_smp_node>::iterator
            n_iter;
        n_iter = i_smp.nodes.find(node_id);
        // no match node found, exit
        if (n_iter == i_smp.nodes.end())
        {
            FAPI_ERR("proc_setup_bars_find_node: insert_chip: Error encountered finding node in SMP");
            FAPI_SET_HWP_ERROR(rc,
                RC_PROC_SETUP_BARS_NODE_FIND_INTERNAL_ERR);
            break;
        }
        o_node = n_iter->second;
    } while(0);

    FAPI_DBG("proc_setup_bars_find_node: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: wrapper function to write all chip BARs
// parameters: i_smp                        => structure encapsulating fully
//                                             specified SMP topology
//             i_init_local_chip_local_node => boolean qualifying application
//                                             of local chip/local node range
//                                             specific BAR resources
// returns: FAPI_RC_SUCCESS if all register writes are successful,
//          else failing return code from lower level BAR write/node search
//              functions
//------------------------------------------------------------------------------
fapi::ReturnCode
proc_setup_bars_write_bars(
    proc_setup_bars_smp_system& i_smp,
    const bool& i_init_local_chip_local_node)
{
    // return code
    fapi::ReturnCode rc;
    std::map<proc_fab_smp_node_id, proc_setup_bars_smp_node>::iterator n_iter;
    std::map<proc_fab_smp_chip_id, proc_setup_bars_smp_chip>::iterator p_iter;

    FAPI_DBG("proc_setup_bars_write_bars: Start");

    do
    {
        for (n_iter = i_smp.nodes.begin();
             (n_iter != i_smp.nodes.end()) && (rc.ok());
             n_iter++)
        {
            for (p_iter = n_iter->second.chips.begin();
                 (p_iter != n_iter->second.chips.end()) && (rc.ok());
                 p_iter++)
            {
                // init local chip/local node resources?
                if (i_init_local_chip_local_node)
                {
                    rc = proc_setup_bars_write_local_chip_region_bars(
                        p_iter->second);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_setup_bars_write_bars: Error from proc_setup_bars_write_local_chip_region_bars");
                        break;
                    }

                    rc = proc_setup_bars_write_local_node_region_bars(
                        p_iter->second,
                        n_iter->second);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_setup_bars_write_bars: Error from proc_setup_bars_write_local_node_region_bars");
                        break;
                    }
                }

                // determine which remote node ranges should be initialized
                proc_setup_bars_smp_node smp_node_a0;
                proc_setup_bars_smp_node smp_node_a1;
                proc_setup_bars_smp_node smp_node_a2;
                if (p_iter->second.chip->a0_chip.getType() != fapi::TARGET_TYPE_NONE)
                {
                    rc = proc_setup_bars_find_node(
                        p_iter->second.chip->a0_chip,
                        i_smp,
                        smp_node_a0);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_setup_write_bars: Error from proc_setup_bars_find_node");
                        break;
                    }
                }
                if (p_iter->second.chip->a1_chip.getType() != fapi::TARGET_TYPE_NONE)
                {
                    rc = proc_setup_bars_find_node(
                        p_iter->second.chip->a1_chip,
                        i_smp,
                        smp_node_a1);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_setup_write_bars: Error from proc_setup_bars_find_node");
                        break;
                    }
                }
                if (p_iter->second.chip->a2_chip.getType() != fapi::TARGET_TYPE_NONE)
                {
                    rc = proc_setup_bars_find_node(
                        p_iter->second.chip->a2_chip,
                        i_smp,
                        smp_node_a2);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_setup_write_bars: Error from proc_setup_bars_find_node");
                        break;
                    }
                }

                // initialize remote node related ranges
                rc = proc_setup_bars_write_remote_node_region_bars(
                    p_iter->second,
                    smp_node_a0,
                    smp_node_a1,
                    smp_node_a2);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_setup_bars_write_bars: Error from proc_setup_bars_write_remote_node_region_bars");
                    break;
                }

                // initialize foreign link related regions
                rc = proc_setup_bars_write_foreign_region_bars(
                    p_iter->second);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_setup_bars_write_bars: Error from proc_setup_bars_write_foreign_region_bars");
                    break;
                }
            }
        }
    } while(0);

    FAPI_DBG("proc_setup_bars_write_bars: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: enable MCD probes/unmask FIRs
// parameters: i_smp                        => structure encapsulating fully
//                                             specified SMP topology
//             i_init_local_chip_local_node => boolean qualifying application
//                                             of local chip/local node range
//                                             specific BAR resources
// returns: FAPI_RC_SUCCESS if all register writes are successful,
//          else failing return code from failing SCOM access
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars_config_mcd(
    proc_setup_bars_smp_system& i_smp,
    const bool& i_init_local_chip_local_node)
{
    // return code
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    ecmdDataBufferBase mcd_fir_mask_data(64);
    ecmdDataBufferBase mcd_recov_data(64);
    ecmdDataBufferBase mcd_recov_mask(64);
    std::map<proc_fab_smp_node_id, proc_setup_bars_smp_node>::iterator n_iter;
    std::map<proc_fab_smp_chip_id, proc_setup_bars_smp_chip>::iterator p_iter;

    FAPI_DBG("proc_setup_bars_config_mcd: Start");

    do
    {
        for (n_iter = i_smp.nodes.begin();
             (n_iter != i_smp.nodes.end()) && (rc.ok());
             n_iter++)
        {
            for (p_iter = n_iter->second.chips.begin();
                 (p_iter != n_iter->second.chips.end()) && (rc.ok());
                 p_iter++)
            {
                bool config_mcd = false;
                bool cfg_enable[PROC_SETUP_BARS_NUM_MCD_CFG] =
                    { false, false, false, false };

                // ensure MCD probes are enabled and FIR is unmasked if:
                //   initializing local chip resources and there is a
                //     non-mirrored/mirrored range enabled OR
                //   initializing foreign resources and there is a
                //     near range enabled

                if (i_init_local_chip_local_node &&
                    (p_iter->second.non_mirrored_range.enabled ||
                     p_iter->second.mirrored_range.enabled))
                {
                    config_mcd = true;
                    cfg_enable[0] = p_iter->second.non_mirrored_range.enabled;
                    cfg_enable[1] = p_iter->second.mirrored_range.enabled;
                }

                bool process_f_links[PROC_FAB_SMP_NUM_F_LINKS] =
                {
                    p_iter->second.chip->process_f0,
                    p_iter->second.chip->process_f1
                };

                // process ranges
                for (uint8_t r = 0;
                     (r < PROC_FAB_SMP_NUM_F_LINKS);
                     r++)
                {
                    if (process_f_links[r] &&
                        p_iter->second.foreign_near_ranges[r].enabled)
                    {
                        config_mcd = true;
                        cfg_enable[2+r] = true;
                    }
                }

                if (config_mcd)
                {
                    uint64_t mcd_fir_mask;
                    uint8_t mcd_hang_poll_bug;
                    rc = FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_MCD_HANG_RECOVERY_BUG,
                                       &(p_iter->second.chip->this_chip),
                                       mcd_hang_poll_bug);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_setup_bars_config_mcd: Error querying ATTR_CHIP_EC_FEATURE_MCD_HANG_RECOVERY_BUG");
                    }

                    if (mcd_hang_poll_bug != 0)
                    {
                        mcd_fir_mask = MCD_FIR_MASK_RUNTIME_VAL_MCD_HANG_POLL_BUG;
                    }
                    else
                    {
                        mcd_fir_mask = MCD_FIR_MASK_RUNTIME_VAL_NO_MCD_HANG_POLL_BUG;
                    }

                    // unmask MCD FIR
                    rc_ecmd |= mcd_fir_mask_data.setDoubleWord(
                        0,
                        mcd_fir_mask);

                    // check buffer manipulation return codes
                    if (rc_ecmd)
                    {
                        FAPI_ERR("proc_setup_bars_config_mcd: Error 0x%X setting up FIR mask data buffer",
                                 rc_ecmd);
                        rc.setEcmdError(rc_ecmd);
                        break;
                    }

                    rc = fapiPutScom(p_iter->second.chip->this_chip,
                                     MCD_FIR_MASK_0x02013403,
                                     mcd_fir_mask_data);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_setup_bars_config_mcd: fapiPutScomUnderMask error (MCD_FIR_MASK_0x02013403)");
                        break;
                    }

                    // enable MCD probes for selected config registers
                    rc_ecmd |= mcd_recov_data.setBit(MCD_RECOVERY_ENABLE_BIT);
                    rc_ecmd |= mcd_recov_mask.setBit(MCD_RECOVERY_ENABLE_BIT);
                    for (uint8_t i = 0;
                         i < PROC_SETUP_BARS_NUM_MCD_CFG;
                         i++)
                    {
                        rc_ecmd |= mcd_recov_data.writeBit(
                            MCD_RECOVERY_CFG_EN_BIT[i],
                            cfg_enable[i]);
                        rc_ecmd |= mcd_recov_mask.writeBit(
                            MCD_RECOVERY_CFG_EN_BIT[i],
                            cfg_enable[i]);
                    }

                    // check buffer manipulation return codes
                    if (rc_ecmd)
                    {
                        FAPI_ERR("proc_setup_bars_config_mcd: Error 0x%X setting up recovery data buffer",
                                 rc_ecmd);
                        rc.setEcmdError(rc_ecmd);
                        break;
                    }

                    rc = fapiPutScomUnderMask(p_iter->second.chip->this_chip,
                                              MCD_REC_EVEN_0x02013410,
                                              mcd_recov_data,
                                              mcd_recov_mask);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_setup_bars_config_mcd: fapiPutScomUnderMask error (MCD_REC_EVEN_0x02013410)");
                        break;
                    }

                    rc = fapiPutScomUnderMask(p_iter->second.chip->this_chip,
                                              MCD_REC_ODD_0x02013411,
                                              mcd_recov_data,
                                              mcd_recov_mask);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_setup_bars_config_mcd: fapiPutScomUnderMask error (MCD_REC_ODD_0x02013411)");
                        break;
                    }
                }
            }
        }
    } while(0);

    FAPI_DBG("proc_setup_bars_config_mcd: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: proc_setup_bars HWP entry point
//           NOTE: see comments above function prototype in header
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars(
    std::vector<proc_setup_bars_proc_chip>& i_proc_chips,
    const bool& i_init_local_chip_local_node)
{
    // return code
    fapi::ReturnCode rc;
    // SMP model
    proc_setup_bars_smp_system smp;

    // mark HWP entry
    FAPI_IMP("proc_setup_bars: Entering ...");

    do
    {
        // process all chips passed from platform to HWP, query chip
        // specific attributes and insert into system SMP data structure
        // given logical node & chip ID
        rc = proc_setup_bars_process_chips(i_proc_chips,
                                           smp);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars: Error from proc_setup_bars_process_chips");
            break;
        }

        // TODO: add more extensive range checking

        // write BAR registers
        rc = proc_setup_bars_write_bars(smp,
                                        i_init_local_chip_local_node);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars: Error from proc_setup_bars_write_bars");
            break;
        }

        // configure MCD resources
        rc = proc_setup_bars_config_mcd(smp,
                                         i_init_local_chip_local_node);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars: Error from proc_setup_bars_config_mcd");
            break;
        }

    } while(0);

    // log function exit
    FAPI_IMP("proc_setup_bars: Exiting ...");
    return rc;
}


} // extern "C"
