/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/build_winkle_images/proc_set_pore_bar/proc_set_pore_bar.C $
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
// $Id: proc_set_pore_bar.C,v 1.7 2012/07/25 12:26:28 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_set_pore_bar.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Greg Still         Email: stillgs@us.ibm.com
// *!
/// \file proc_set_pore_bar.C
/// \brief Set up the Sleep/Winkle (SLW) PORE Memory Relocation (MRR) and
/// Table Base Address (TBA) for accessing the SLW image
///
/// High-level procedure flow:
/// \verbatim
///
///     Address and size of SLW image for the target (chip) is passed based on
///     where the caller has placed the image for this target in the platform 
///     memory.  
///
///     The Base Address (BAR) and a mask for the region in which the SLW
///     image is placed is passed.  This is used to establish the PBA BAR and
///     mask hardware to set the legal bounds for SLW accesses.
///
///     The BAR defines address bits 14:43 in natural bit alignment (eg no shifting)
///     The Mask defines validity for bits 23:43 in natural bit alignment.  This
///         is a "thermometer" mask to define a power of 2 size.
///
///         A "1" in the mask indicates that bit location comes from the SLW; a "0"
///         indicates the bit comes from the BAR.  Thus, the size of the region is
///         ((mask+1)) MB.  (eg the mask value 7 yields an 8MB region)
///
///     Check that passed address is within the 50 bit real address range
///     Check that image address + image size does not extend past the 50 bit
///         boundary
///
///     Read image link address at image offset 0x10
///     Link Address(0:1) is the OCI region that will invoke the MRR.  These
///         are set into MRR(30:31).
///     Calculate MRR address (32:63) = image address - link address (32 bit)
///     Store MRR to PORE SLW
///
///     Call proc_pba_bar_config to set up PBA BAR 2 with the address and
///         size of the SLW region as passed via calling parameters
///         i_mem_bar and i_mem_mask.
///
///  Procedure Prereq:
///     - SLW image memory region has been allocated and XIP image loaded.
/// \endverbatim
///
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi.H>
#include "p8_scom_addresses.H"
#include "proc_set_pore_bar.H"
#include "proc_pm.H"
#include "proc_pba_init.H"
#include "proc_pba_bar_config.H"
#include "sbe_xip_image.h"


extern "C" {

using namespace fapi;

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------

const uint32_t  SLW_PBA_BAR = 2;

// ----------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------


/// \param[in] i_target     Procesor Chip target
/// \param[in] i_image      Platform memory pointer where image is
///                         located
/// \param[in] i_mem_bar    Base address of the region where image is located
/// \param[in] i_mem_mask   Mask that defines which address bits of the
///                         BAR apply such to define the region size
/// \param[in] i_mem_type Defines where the SLW image was loaded.  See
///                         proc_set_pore_bar.H enum for valid values.
///
/// \retval SUCCESS
/// \retval RC_PROCPM_POREBAR_IMAGE_BRANCH_VALUE_ERROR
/// \retval RC_PROCPM_POREBAR_LOC_ERROR
/// \retval RC_PROCPM_POREBAR_IMAGE_ADDR_ERROR (future version)
/// \retval RC_PROCPM_POREBAR_IMAGE_PLACEMENT_ERROR (future version)

fapi::ReturnCode
proc_set_pore_bar(      const fapi::Target& i_target,
                        void                *i_image,
                        uint64_t            i_mem_bar,
                        uint64_t            i_mem_mask,
                        uint32_t            i_mem_type)
{
    fapi::ReturnCode    rc;
    uint32_t            l_ecmdRc = 0;
    ecmdDataBufferBase  data;

    uint64_t            image_address;
    uint64_t            image_size;
//    uint64_t            region_begin_address;
//    uint64_t            region_end_address;
    uint64_t            region_masked_address;
//    uint64_t            region_inverted_mask;
//    uint64_t            computed_image_address;
//    uint64_t            computed_last_image_address;

    uint64_t            slw_branch_table_address;

    // Hardcoded use of PBA BAR and Slave
    const uint32_t      pba_bar = PBA_BAR2;
    const uint32_t      pba_bar_slw = PBA_SLW_BAR2;
    const uint32_t      pba_slave = PBA_SLAVE2;

    const uint64_t      slw_pba_cmd_scope = 0x2;   // Set to system


    // -----------------------------------------------------------------

    FAPI_INF("Executing proc_set_pore_bar...");
    image_address = (uint64_t) i_image;
    FAPI_DBG("Passed address 0x%16llX ", image_address);

    // Get the Table Base Address from the image
    l_ecmdRc = sbe_xip_get_scalar((void*)   i_image,
                                            "slw_branch_table",
                                            &slw_branch_table_address);
    if (l_ecmdRc)
    {
        FAPI_ERR("Get XIP of slw_branch_table failed. rc = %x\n", l_ecmdRc);
        FAPI_SET_HWP_ERROR(rc, RC_PROCPM_POREBAR_IMAGE_BRANCH_VALUE_ERROR);
        return rc;
    }
    FAPI_DBG("slw_branch_table_address:   %16llX", slw_branch_table_address);

    // Initialize the ecmdDataBuffer
    l_ecmdRc |= data.clear();
    l_ecmdRc |= data.setBitLength(64);
    if(l_ecmdRc)
    {
        FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", l_ecmdRc);
        rc.setEcmdError(l_ecmdRc);
        return rc;
    }


    // Setup the the table base address register
    //
    //  Table Base Address Register layout
    //  16      Interface (0=PIB, 1=OCI)
    //  17      Reserved
    //  18:23   Chiplet ID (used only for PIB fetch; unused for OCI)-SLW unused
    //  24:27   PIB ID (used only for PIB fetch; unused for OCI)-SLW unused
    //  28:31   PORT ID (used only for PIB fetch; unused for OCI)-SLW unused
    //  32:64   Table base address for jump table
    //
    //  1   2         3  3     6
    //  6789012345678901 2-----3
    //  1                           OCI
    //   0
    //    000000                    Chiplet ID
    //          0000                PIB  ID
    //              0000            PORT ID
    //
    //  For SLW images that will run on PORE-SLW, the PORT ID is set to C
    //
    //

    // Set the table base address (32:63) with passed value
    l_ecmdRc |= data.setDoubleWord( 0, slw_branch_table_address);
    if(l_ecmdRc)
    {
        FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", l_ecmdRc);
        rc.setEcmdError(l_ecmdRc);
        return rc;
    }
    rc = fapiPutScom(i_target, PORE_SLW_TABLE_BASE_ADDR_0x00068008, data);
    if (rc)
    {
        FAPI_ERR("Put SCOM error for Table Base Address");
        return rc;
    }
    FAPI_INF("SLW PORE Table Base Address set to 0x%16llx", data.getDoubleWord(0));
    
    

    // Setup the memory relocation register
    //
    // This is hardcoded as the SLW image build process has all images to be:
    //  1) Relocatable and thus must have the region match bits set
    //  2) Built for region 0x80000XXX
    //
    //  MRR Layout
    //      30:31:  Memory Reloc Region - 2 MSbs of 32 bit address that
    //          defines the region match
    //      32:51   Memory Relocation Base Address added to 0:19 of the OCI
    //              address
    //
    //    Table Base Address Register layout
    //    16      Interface (0=PIB, 1=OCI)
    //    17      Reserved
    //    18:23   Chiplet ID (used only for PIB fetch; unused for OCI)-SLW unused
    //    24:27   PIB ID (used only for PIB fetch; unused for OCI)-SLW unused
    //    28:31   PORT ID (used only for PIB fetch; unused for OCI)-SLW unused
    //    32:64   Table base address for jump table
    //
    //    1   2         3  3     6
    //    6789012345678901 2-----3
    //    1                           OCI
    //     0
    //      000000                    Chiplet ID
    //            0000                PIB  ID
    //                0000            PORT ID
    //
    //    For SLW images that will run on PORE-SLW, the PORT ID is set to C in
    //    the image but this is unused by the hardware.

    l_ecmdRc |= data.flushTo0();

    // Set 30:31 to 10 to yield a region of 0x8XXXXXXX (eg unused OCI region)
    l_ecmdRc |= data.setBit( 30, 1);

    if(l_ecmdRc)
    {
        FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", l_ecmdRc);
        rc.setEcmdError(l_ecmdRc);
        return rc;
    }

    // SLW image has effective addresses in the form of 0x8XXXXXXX.
    // The PORE memory relocation function adds the mem_reloc(32:52) to
    // effective address 0:19 to form the real address where:
    //      effective address(0:1) defines the region: 00 = memory/L3, 11 = SRAM
    //      effective address(2:3) defines the PBA BAR to use (if memory/L3)

    // Set the Memory Relocation Base based on the placement of the SLW image
    if (i_mem_type == SLW_SRAM)
    {
        // Set the beginning of 512KB SRAM tank.

        FAPI_DBG("SLW PORE Memory Relocation Register before SRAM 0x%16llx", data.getDoubleWord(0));

        l_ecmdRc |= data.setOr(0x7FF80<<12, 32, 20);
        if(l_ecmdRc)
        {
            FAPI_ERR("Error (0x%x) manipulating ecmdDataBufferBase", l_ecmdRc);
            rc.setEcmdError(l_ecmdRc);
            return rc;
        }
    }
    else if (i_mem_type == SLW_MEMORY || i_mem_type == SLW_L3)
    {
        // The 00 (from the buffer flush) in 0:1 goes toward PBA (memory or L3)
        // Set to use the PBA with BAR(0:3) encoded in bits 2:3 (eg shift of 30)
        // 0x80000 + 0xA0000 => 20000 (upper overflow discarded)
        // The 00 in 0:1 goes toward PBA; 2:3 for PBA BAR 2
        FAPI_DBG("SLW PORE PBA BAR %x", pba_bar_slw);
        FAPI_DBG("SLW PORE Memory Relocation Register before MEM 0x%16llx", data.getDoubleWord(0));

        l_ecmdRc |= data.setOr(pba_bar_slw<<28, 32, 20);
        if(l_ecmdRc)
        {
            FAPI_ERR("Error (0x%x) manipulating ecmdDataBufferBase", l_ecmdRc);
            rc.setEcmdError(l_ecmdRc);
            return rc;
        }

        FAPI_DBG("SLW PORE Memory Relocation Register after MEM 0x%16llx", data.getDoubleWord(0));
        
        // Check that the bar address passed is 1MB aligned (eg bits 44:63 are zero)
        //
        region_masked_address = i_mem_bar & 0x00000000000FFFFF;
        if (region_masked_address != 0 )                        
        {                                                                
            FAPI_ERR("SLW BAR address is not 1MB aligned:  0x%16llx", i_mem_bar );               
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_POREBAR_PBABAR_ERROR);  
            return rc;                                                   
        }                                                                


        // The PBA Mask indicates which bits from 23:43 (1MB grandularity) are
        // enabled to be passed from the OCI addresses.  Inverting this mask
        // indicates which address bits are going to come from the PBA BAR value.
        // The image address (the starting address) must match these post mask bits
        // to be resident in the range.
        //
        // Starting bit number: 64 bit Big Endian
        //                                          12223344
        //                                          60482604
        // region_inverted_mask = i_mem_mask ^ BAR_MASK_LIMIT;  // XOR


        // Check that the image address passed is within the memory region that
        // is also passed.
        //
        // The PBA Mask indicates which bits from 23:43 (1MB grandularity) are
        // enabled to be passed from the OCI addresses.  Inverting this mask
        // indicates which address bits are going to come from the PBA BAR value.
        // The image address (the starting address) must match these post mask bits
        // to be resident in the range.
        //
        // Starting bit number: 64 bit Big Endian
        //                                          12223344
        //                                          60482604
        // region_inverted_mask = i_mem_mask ^ BAR_MASK_LIMIT;  // XOR

        // Set bits 14:22 as these are unconditional address bits
        //region_inverted_mask = region_inverted_mask | BAR_ADDR_UNMASKED;
        //computed_image_address = region_inverted_mask && image_address;
        // Need to AND the address
        //if (computed_image_address != i_mem_bar )
        //{
        //    FAPI_ERR("SLW image address check failure. ");
        //    FAPI_SET_HWP_ERROR(rc, RC_PROCPM_POREBAR_IMAGE_ADDR_ERROR);
        //    return rc;
        //}


        // Additionally, the size of the image must not extend beyond the above
        // masked range either.

        // Get the image size from the image itself
        l_ecmdRc = sbe_xip_get_scalar((void*)   i_image,
                                                "image_size",
                                                 &image_size);

        if (l_ecmdRc)
        {
            FAPI_ERR("Get of XIP Image size failed");
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_POREBAR_IMAGE_SIZE_ERROR);
            return rc;
        }

        FAPI_DBG("SLW image size: 0x%08llX", image_size );
        //  computed_last_image_address = image_address + image_size;
        //
        //  if (computed_last_image_address > region_end_address)
        //    {
        //        FAPI_ERR("SLW image placement error.");
        //        FAPI_SET_HWP_ERROR(rc, RC_PROCPM_POREBAR_IMAGE_PLACEMENT_ERROR);
        //        return rc;
        //    }

    }
    else
    {
        FAPI_ERR("Invalid image location passed %x ", i_mem_type);
        FAPI_SET_HWP_ERROR(rc, RC_PROCPM_POREBAR_LOC_ERROR);
        return rc;
    }
    
    FAPI_INF("SLW PORE Memory Relocation Register set to 0x%16llx", data.getDoubleWord(0));
    rc = fapiPutScom(i_target, PORE_SLW_MEMORY_RELOC_0x00068016, data);
    if (rc)
    {
        FAPI_ERR("Put SCOM error for Memory Relocation Address");
        return rc;
    }
    
    


    

    FAPI_DBG("Calling pba_bar_config to BAR %x Addr: 0x%16llX  Mask: 0x%16llX",
                    pba_bar, i_mem_bar, i_mem_mask);

    // Set the PBA BAR for the SLW region
    FAPI_EXEC_HWP(rc, proc_pba_bar_config, i_target,
                                           pba_bar,
                                           i_mem_bar,
                                           i_mem_mask,
                                           slw_pba_cmd_scope);
    if(rc) { return rc; }

    // Set the PBA Slave to use the above BAR
    // \todo Does not yet comprehend the 24x7 setting to allow writing!!
    //
    // enable = 1;                 // Enable the slave
    // mid_match_value=0x4;        // PORE-SLW engine
    // mid_care_mask=0x7;          // Only the PORE-SLW
    // write_ttype=0;              // DMA - though NA
    // read_ttype=0;               // CL_RD_NC
    // read_prefetch_ctl=0;        // Auto Early
    // buf_invalidate_ctl=0;       // Disabled
    // buf_alloc_w=0;              // SLW does not write.  24x7 will
    // buf_alloc_a=0;              // SLW uses Buf A
    // buf_alloc_b=0;              // SLW does not use buffer B
    // buf_alloc_c=0;              // SLW does not use buffer C
    // dis_write_gather=0;         // SLW does not write.  \todo 24x7
    // wr_gather_timeout=0;        // SLW does not write   \todo 24x7
    // write_tsize=0;              // SLW does not write   \todo 24x7
    // extaddr=0;                  // Bits 23:36.  NA for SLW
    //

    // Clear the data buffer (for cleanliness)
    l_ecmdRc |= data.flushTo0();


    // set the PBASLVCTL reg
    l_ecmdRc |= data.setBit(0);     // Enable the slave
    l_ecmdRc |= data.setBit(1);     // PORE-SLW engine - 0b100
    l_ecmdRc |= data.setBit(5,3);   // Care mask-only PORE-SLW

    if(l_ecmdRc)
    {
        FAPI_ERR("Error (0x%x) manipulating ecmdDataBufferBase for PBASLVCTL", l_ecmdRc);
        rc.setEcmdError(l_ecmdRc);
        return rc;
    }

    FAPI_DBG("  PBA_SLVCTL%x: 0x%16llx", pba_slave, data.getDoubleWord(0));
    rc = fapiPutScom(i_target, PBA_SLVCTLs[pba_slave], data);
    if (rc)
    {
        FAPI_ERR("Put SCOM error for PBA Slave Control");
        return rc;
    }

    return rc;
}


} //end extern C
