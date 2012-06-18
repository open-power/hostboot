/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/dram_initialization/proc_setup_bars/mss_setup_bars.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_setup_bars.C
// *! DESCRIPTION : see additional comments below
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
//Owner :- Girisankar paulraj
//Back-up owner :- Mark bellows
//
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.1    | gpaulraj | 03-19-12| First drop for centaur
//  1.2    | gpaulraj | 05-07-12| 256 group configuration in
//  1.3    | gpaulraj | 05-22-12| 2MCS/group supported for 128GB CDIMM
//  1.4    | bellows  | 06-05-12| Updates to Match First Configuration, work for P8 and Murano
//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------

#include <mss_setup_bars.H>

extern "C" {

// PLAN:---
//    Parameter  of the populated Dimm details for each MCS looper
//    Starts with Zero MCS base address. Identifies Dimm parameters belong to MCS
//    Configure the Group primary MCS0 Registers
//    Configure the Group seconary MCS0 Registers /// identifies it base address based on the Primary group size
//    Identify Mirror details setup accordingly
//    Set up each translation registry accordingly
//    SIM configuration
//    -------------------------|-----------------------------------|
//    -------    MCS0 ---------|-------------MCS1------------------|
//    -------------------------|-----------------------------------|
//    ---  CH01  --- CH23 -----|--------  CH01  --- CH23 ----------|
//    D0-  32GB  --- 32GB -----|---- D0-  32GB  --- 32GB ----------|
//    D1-  32GB  --- 32GB  ----|-----D1-  32GB  --- 32GB  ---------|
//    -------------------------|-----------------------------------|
//    - Base address MCS0 - 0x0  Group Size - 128GB
//    - MCS0 -  Grouping base address  - 0GB Group size - 128GB
//    - MCS1 -  Grouping base address  - 128GB+ Group size - 128GB

fapi::ReturnCode mss_setup_bars(
    const fapi::Target& i_chip_target)
{
	fapi::ReturnCode rc;
	std::vector<fapi::Target> l_mcs_chiplets;
	ecmdDataBufferBase MCFGP_data(64);

    // platform attributes which define base addresses for this chip:
    uint64_t mem_base;
    uint64_t mirror_base;

    // storage for output attributes:
    uint64_t mem_bases[8];
    uint64_t l_memory_sizes[8];
    uint64_t mirror_bases[4];
    uint64_t l_mirror_sizes[4];
    uint8_t groups[8];

    do
    {
        //
        // process non-mirrored ranges
        //

        // read chip base address attribute
        rc = FAPI_ATTR_GET(ATTR_PROC_MEM_BASE, &i_chip_target, mem_base);
        if (!rc.ok())
        {
            FAPI_ERR("Error reading ATTR_PROC_MEM_BASE");
            break;
        }

        // base addresses for distinct non-mirrored ranges
        mem_bases[0]=mem_base;
        mem_bases[1]=0x0;
        mem_bases[2]=0x0;
        mem_bases[3]=0x0;
        mem_bases[4]=0x0;
        mem_bases[5]=0x0;
        mem_bases[6]=0x0;
        mem_bases[7]=0x0;

        FAPI_DBG("  ATTR_PROC_MEM_BASES[0]: %016llx", mem_bases[0]);
        FAPI_DBG("  ATTR_PROC_MEM_BASES[1]: %016llx", mem_bases[1]);
        FAPI_DBG("  ATTR_PROC_MEM_BASES[2]: %016llx", mem_bases[2]);
        FAPI_DBG("  ATTR_PROC_MEM_BASES[3]: %016llx", mem_bases[3]);
        FAPI_DBG("  ATTR_PROC_MEM_BASES[4]: %016llx", mem_bases[4]);
        FAPI_DBG("  ATTR_PROC_MEM_BASES[5]: %016llx", mem_bases[5]);
        FAPI_DBG("  ATTR_PROC_MEM_BASES[6]: %016llx", mem_bases[6]);
        FAPI_DBG("  ATTR_PROC_MEM_BASES[7]: %016llx", mem_bases[7]);

        rc = FAPI_ATTR_SET(ATTR_PROC_MEM_BASES, &i_chip_target, mem_bases);
        if (!rc.ok())
        {
            FAPI_ERR("Error writing ATTR_PROC_MEM_BASES");
            break;
        }

        // sizes for distinct non-mirrored ranges
        l_memory_sizes[0]=128ULL*0x40000000ULL;
        l_memory_sizes[1]=0x0;
        l_memory_sizes[2]=0x0;
        l_memory_sizes[3]=0x0;
        l_memory_sizes[4]=0x0;
        l_memory_sizes[5]=0x0;
        l_memory_sizes[6]=0x0;
        l_memory_sizes[7]=0x0;

        FAPI_DBG("  ATTR_PROC_MEM_SIZES[0]: %016llx", l_memory_sizes[0]);
        FAPI_DBG("  ATTR_PROC_MEM_SIZES[1]: %016llx", l_memory_sizes[1]);
        FAPI_DBG("  ATTR_PROC_MEM_SIZES[2]: %016llx", l_memory_sizes[2]);
        FAPI_DBG("  ATTR_PROC_MEM_SIZES[3]: %016llx", l_memory_sizes[3]);
        FAPI_DBG("  ATTR_PROC_MEM_SIZES[4]: %016llx", l_memory_sizes[4]);
        FAPI_DBG("  ATTR_PROC_MEM_SIZES[5]: %016llx", l_memory_sizes[5]);
        FAPI_DBG("  ATTR_PROC_MEM_SIZES[6]: %016llx", l_memory_sizes[6]);
        FAPI_DBG("  ATTR_PROC_MEM_SIZES[7]: %016llx", l_memory_sizes[7]);

        rc = FAPI_ATTR_SET(ATTR_PROC_MEM_SIZES, &i_chip_target, l_memory_sizes);
        if (!rc.ok())
        {
            FAPI_ERR("Error writing ATTR_PROC_MEM_SIZES");
            break;
        }


        //
        // process mirrored ranges
        //

        // read chip base address attribute
        rc = FAPI_ATTR_GET(ATTR_PROC_MIRROR_BASE, &i_chip_target, mirror_base);
        if (!rc.ok())
        {
            FAPI_ERR("Error reading ATTR_PROC_MIRROR_BASE");
            break;
        }

        // base addresses for distinct mirrored ranges
        mirror_bases[0] = mirror_base;
        mirror_bases[1] = 0x0;
        mirror_bases[2] = 0x0;
        mirror_bases[3] = 0x0;

        FAPI_DBG("  ATTR_PROC_MIRROR_BASES[0]: %016llx", mirror_bases[0]);
        FAPI_DBG("  ATTR_PROC_MIRROR_BASES[1]: %016llx", mirror_bases[1]);
        FAPI_DBG("  ATTR_PROC_MIRROR_BASES[2]: %016llx", mirror_bases[2]);
        FAPI_DBG("  ATTR_PROC_MIRROR_BASES[3]: %016llx", mirror_bases[3]);

        rc = FAPI_ATTR_SET(ATTR_PROC_MIRROR_BASES, &i_chip_target, mirror_bases);
        if (!rc.ok())
        {
            FAPI_ERR("Error writing ATTR_PROC_MIRROR_BASES");
            break;
        }

        // sizes for distinct mirrored ranges
        l_mirror_sizes[0]=0;
        l_mirror_sizes[1]=0;
        l_mirror_sizes[2]=0;
        l_mirror_sizes[3]=0;

        FAPI_DBG("  ATTR_PROC_MIRROR_SIZES[0]: %016llx", l_mirror_sizes[0]);
        FAPI_DBG("  ATTR_PROC_MIRROR_SIZES[1]: %016llx", l_mirror_sizes[1]);
        FAPI_DBG("  ATTR_PROC_MIRROR_SIZES[2]: %016llx", l_mirror_sizes[2]);
        FAPI_DBG("  ATTR_PROC_MIRROR_SIZES[3]: %016llx", l_mirror_sizes[3]);

        rc = FAPI_ATTR_SET(ATTR_PROC_MIRROR_SIZES, &i_chip_target, l_mirror_sizes);
        if (!rc.ok())
        {
            FAPI_ERR("Error writing ATTR_PROC_MIRROR_SIZES");
            break;
        }


        //
        // process group configuration
        //

        groups[0]=0x0C;
        groups[1]=0x00;
        groups[2]=0x00;
        groups[3]=0x00;
        groups[4]=0x00;
        groups[5]=0x00;
        groups[6]=0x00;
        groups[7]=0x00;
        rc = FAPI_ATTR_SET(ATTR_MSS_MEM_MC_IN_GROUP, &i_chip_target, groups);
        if (!rc.ok())
        {
            FAPI_ERR("Error writing ATTR_MSS_MEM_MC_IN_GROUP");
            break;
        }


        //
        // write HW registers
        //

        // get child MCS chiplets
        rc = fapiGetChildChiplets(i_chip_target,
                                  fapi::TARGET_TYPE_MCS_CHIPLET,
                                  l_mcs_chiplets,
                                  fapi::TARGET_STATE_FUNCTIONAL);
        if (!rc.ok())
        {
            FAPI_ERR("Error from fapiGetChildChiplets");
            break;
        }

        // loop through & set configuration of each child
        for (std::vector<fapi::Target>::iterator iter = l_mcs_chiplets.begin();
             iter != l_mcs_chiplets.end();
             iter++)
        {
            uint8_t mcs_pos = 0x0;
            rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &(*iter), mcs_pos);
            if (!rc.ok())
            {
                FAPI_ERR("Error reading ATTR_CHIP_UNIT_POS");
                break;
            }

            // set configuration registers (static to match VBU model for now)
            if (mcs_pos == 4)
            {
                MCFGP_data.setDoubleWord(0, 0x90601FC000000000ULL);
            }
            else if (mcs_pos == 5)
            {
                MCFGP_data.setDoubleWord(0, 0x90E01FC000000000ULL);
            }
            else
            {
                MCFGP_data.setDoubleWord(0, 0x0060008000000000ULL);
            }

            // write MCFGP register
            FAPI_DBG("Writing MCS %d MCFGP = 0x%llx",
                     mcs_pos, MCFGP_data.getDoubleWord(0));

            rc = fapiPutScom(*iter, MCS_MCFGP_0x02011800, MCFGP_data);
            if (!rc.ok())
            {
                FAPI_ERR("Error from fapiPutScom (MCS_MCFGP_0x02011800)");
                break;
            }
        }
    } while(0);

    return rc;
}


} // extern "C"
