/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_set_pore_bar.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: p8_set_pore_bar.C,v 1.9 2014/03/07 14:38:52 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_set_pore_bar.C,v $
//-------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//-------------------------------------------------------------------------------
// *! OWNER NAME: Greg Still         Email: stillgs@us.ibm.com
// *!
/// \file p8_set_pore_bar.C
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
///     The BAR defines address bits 14:43 in natural bit alignment (eg no
///     shifting)
///
///     The Size (in MB) of the region where image is located.
///         If not a power of two value, the value will be rounded up to the
///         next power of 2 for setting the hardware mask
///
///         If 0 is defined and the BAR is also defined as 0, then the BAR
///         is set (to 0) but no image accessing is done as this is considered
///         a BAR reset condition.  The TBA and MRR values in the PORE-SLW are
///         not altered.
///
///         If 0 is defined and the BAR is NOT 0, an error is returned as this
///         is defining a zero sized, real region.
///
///     Flow (given BAR and Size are ok per the above)
///        Check that passed address is within the 50 bit real address range
///        Check that image address + image size does not extend past the 50 bit
///            boundary
///
///        Read image link address at image offset 0x10
///        Link Address(0:1) is the OCI region that will invoke the MRR.  These
///            are set into MRR(30:31).
///        Calculate MRR address (32:63) = image address - link address (32 bit)
///        Store MRR to PORE SLW
///
///        Call p8_pba_bar_config to set up PBA BAR 2 with the address and
///            size of the SLW region as passed via calling parameters
///         i_mem_bar and i_mem_mask.
///
///  Procedure Prereq:
///     - SLW image memory region has been allocated and XIP image loaded.
///
///  CQ Class:  power_management
/// \endverbatim
///
//-------------------------------------------------------------------------------


// ------------------------------------------------------------------------------
// Includes
// ------------------------------------------------------------------------------
#include <fapi.H>
#include "p8_scom_addresses.H"
#include "pgp_common.h"
#include "p8_set_pore_bar.H"
#include "p8_pm.H"
#include "p8_pba_init.H"
#include "p8_pba_bar_config.H"
#include "pgp_pba.h"
#include "sbe_xip_image.h"


extern "C" {

using namespace fapi;

// ------------------------------------------------------------------------------
// Constant definitions
// ------------------------------------------------------------------------------

const uint32_t  SLW_PBA_BAR = 2;
const uint32_t  SLW_PBA_SLAVE = 2;

// ------------------------------------------------------------------------------
// Global variables
// ------------------------------------------------------------------------------

// ------------------------------------------------------------------------------
// Function prototypes
// ------------------------------------------------------------------------------

fapi::ReturnCode bar_pba_slave_reset( const fapi::Target& i_target,
                                      uint32_t id );

// ------------------------------------------------------------------------------
// Function definitions
// ------------------------------------------------------------------------------


/// \param[in] i_target     Procesor Chip target
/// \param[in] i_image      Platform memory pointer where image is
///                         located
/// \param[in] i_mem_bar    Base address of the region where image is located
/// \param[in] i_mem_size   Size (in MB) of the region where image is located
///                         if not a power of two value, the value will be
///                         rounded up to the next power of 2 for setting the
///                         hardware mask.  The value of 0 is only legal if
///                         i_mem_bar is also 0;  else an error is indicated.
/// \param[in] i_mem_type   Defines where the SLW image was loaded.  See
///                         p8_set_pore_bar.H enum for valid values.
///
/// \retval SUCCESS
/// \retval RC_PROCPM_POREBAR_IMAGE_BRANCH_VALUE_ERROR
/// \retval RC_PROCPM_POREBAR_LOC_ERROR
/// \retval RC_PROCPM_POREBAR_IMAGE_ADDR_ERROR (future version)
/// \retval RC_PROCPM_POREBAR_IMAGE_PLACEMENT_ERROR (future version)
fapi::ReturnCode
p8_set_pore_bar(      const fapi::Target& i_target,
                        void                *i_image,
                        uint64_t            i_mem_bar,
                        uint64_t            i_mem_size,
                        uint32_t            i_mem_type)
{
    fapi::ReturnCode    rc;
    uint32_t            l_ecmdRc = 0;
    ecmdDataBufferBase  data(64);

    uint64_t            image_address;
    uint64_t            image_size;
//    uint64_t            region_begin_address;
//    uint64_t            region_end_address;
    uint64_t            region_masked_address;
//    uint64_t            region_inverted_mask;
//    uint64_t            computed_image_address;
//    uint64_t            computed_last_image_address;

    uint64_t            slw_branch_table_address;

    pba_slvctln_t       ps;                         // PBA Slave

    // Hardcoded use of PBA BAR and Slave
    const uint32_t      pba_bar = PBA_BAR2;
    const uint32_t      pba_bar_slw = PBA_SLW_BAR2;
    const uint32_t      pba_slave = PBA_SLAVE2;

    const uint64_t      slw_pba_cmd_scope = 0x2;   // Set to system
    
    SbeXipItem          slw_control_vector_info;
    uint32_t            slw_control_vector_offset;
    
    SbeXipItem          slw_deep_winkle_exit_good_halt_info;
    uint32_t            slw_deep_winkle_exit_good_halt_offset;
    
    SbeXipItem          slw_deep_sleep_exit_good_halt_info;
    uint32_t            slw_deep_sleep_exit_good_halt_offset;



    // -----------------------------------------------------------------
    do
    {
        FAPI_INF("Executing p8_set_pore_bar...");
        image_address = (uint64_t) i_image;
        FAPI_DBG("Passed address 0x%16llX ", image_address);

        // Check if this is a BAR reset case.
        if (i_mem_size == 0)
        {
            if(i_mem_bar != 0)
            {
                FAPI_ERR("SLW Size is 0 but BAR is non-zero:  0x%16llx", i_mem_bar );
                const fapi::Target & CHIP = i_target;
                const uint64_t     & IMAGEADDR = (uint64_t)i_image;
                const uint32_t     & MEMSIZE = i_mem_size;
                const uint64_t     & MEMBAR = i_mem_bar;
                FAPI_SET_HWP_ERROR(rc, RC_PROCPM_POREBAR_SIZE0_ERROR);
                break;
            }
            else
            {
                FAPI_DBG("Calling pba_bar_config to BAR %x Addr: 0x%16llX  Size: 0x%16llX",
                           pba_bar, i_mem_bar, i_mem_size);

                // Set the PBA BAR for the SLW region
                FAPI_EXEC_HWP(rc, p8_pba_bar_config, i_target,
                                                       pba_bar,
                                                       i_mem_bar,
                                                       i_mem_size,
                                                       slw_pba_cmd_scope);

                // No rc check is made as we're exiting anyway.

                // Exit the procedure as we don't want to access the image nor
                // touch the SLW TBA or MRR settings.
                break;
            }
        }


        // Get the Table Base Address from the image
        l_ecmdRc = sbe_xip_get_scalar((void*)   i_image,
                                                "slw_branch_table",
                                                &slw_branch_table_address);
        if (l_ecmdRc)
        {
            FAPI_ERR("Get XIP of slw_branch_table failed. rc = %x\n", l_ecmdRc);
            const fapi::Target & CHIP = i_target;
            const uint64_t     & IMAGEADDR = (uint64_t)i_image;
            const uint32_t     & XIPRC = l_ecmdRc;
            const uint64_t     & BRANCHTABLEADDRESS = slw_branch_table_address;
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_POREBAR_IMAGE_BRANCH_VALUE_ERROR);
            break;
        }
        FAPI_DBG("slw_branch_table_address:   %16llX", slw_branch_table_address);

        // Get the SLW Control Vector offset from the image
        l_ecmdRc = sbe_xip_find((void*)   i_image,
                                          "slw_control_vector",
                                          &slw_control_vector_info);
        if (l_ecmdRc)
        {
            FAPI_ERR("XIP Find of slw_control_vector failed. rc = %x\n", l_ecmdRc);
            const fapi::Target & CHIP = i_target;
            const uint64_t     & IMAGEADDR = (uint64_t)i_image;
            const uint32_t     & XIPRC = l_ecmdRc;
            const uint64_t     & SLWCONTROLVECTOR = (uint64_t)slw_control_vector_info.iv_address;
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_POREBAR_IMAGE_SLW_CONTROL_VECTOR_ERROR);
            break;
        }
        
        slw_control_vector_offset = slw_control_vector_info.iv_address;
        FAPI_DBG("slw_control_vector offset:  %16llX", (uint64_t)slw_control_vector_info.iv_address);
       
       
        SETATTR(rc,
                ATTR_PM_SLW_CONTROL_VECTOR_OFFSET,
                "ATTR_PM_SLW_CONTROL_VECTOR_OFFSET",
                NULL,
                slw_control_vector_offset);

        
        // Get the Deep Winkle Good Exit halt offset from the image to save in 
        // at attribute for other HWP use.
        l_ecmdRc = sbe_xip_find((void*)   i_image,
                                          "slw_deep_winkle_exit_good_halt",
                                          &slw_deep_winkle_exit_good_halt_info);
        if (l_ecmdRc)
        {
            FAPI_ERR("XIP Find of slw_deep_winkle_exit_good_halt failed. rc = %x\n", l_ecmdRc);
            const fapi::Target & CHIP = i_target;
            const uint64_t     & IMAGEADDR = (uint64_t)i_image;
            const uint32_t     & XIPRC = l_ecmdRc;
            const uint64_t     & SLWDEEPWINKLEEXITHALT = (uint64_t)slw_deep_winkle_exit_good_halt_info.iv_address;
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_POREBAR_IMAGE_SLW_DEEP_WINKLE_EXIT_HALT_ERROR);
            break;
        }
        
        slw_deep_winkle_exit_good_halt_offset = slw_deep_winkle_exit_good_halt_info.iv_address;
        FAPI_DBG("slw_deep_winkle_exit_good_halt offset: %16llX", (uint64_t)slw_deep_winkle_exit_good_halt_info.iv_address);
             
        SETATTR(rc,
                ATTR_PM_SLW_DEEP_WINKLE_EXIT_GOOD_HALT_ADDR,
                "ATTR_PM_SLW_DEEP_WINKLE_EXIT_GOOD_HALT_ADDR",
                NULL,
                slw_deep_winkle_exit_good_halt_offset);
        
        // Get the Deep Sleep Good Exit halt offset from the image to save in 
        // at attribute for other HWP use.
        l_ecmdRc = sbe_xip_find((void*)   i_image,
                                          "slw_deep_sleep_exit_good_halt",
                                          &slw_deep_sleep_exit_good_halt_info);
        if (l_ecmdRc)
        {
            FAPI_ERR("XIP Find of slw_deep_sleep_exit_good_halt failed. rc = %x\n", l_ecmdRc);
            const fapi::Target & CHIP = i_target;
            const uint64_t     & IMAGEADDR = (uint64_t)i_image;
            const uint32_t     & XIPRC = l_ecmdRc;
            const uint64_t     & SLWDEEPSLEEPEXITHALT = (uint64_t)slw_deep_sleep_exit_good_halt_info.iv_address;
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_POREBAR_IMAGE_SLW_DEEP_SLEEP_EXIT_HALT_ERROR);
            break;
        }
        
        slw_deep_sleep_exit_good_halt_offset = slw_deep_sleep_exit_good_halt_info.iv_address;
        FAPI_DBG("slw_deep_sleep_exit_good_halt offset:  %16llX", (uint64_t)slw_deep_sleep_exit_good_halt_info.iv_address);
             
        SETATTR(rc,
                ATTR_PM_SLW_DEEP_SLEEP_EXIT_GOOD_HALT_ADDR,
                "ATTR_PM_SLW_DEEP_SLEEP_EXIT_GOOD_HALT_ADDR",
                NULL,
                slw_deep_sleep_exit_good_halt_offset);

               

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
            break;
        }
        rc = fapiPutScom(i_target, PORE_SLW_TABLE_BASE_ADDR_0x00068008, data);
        if (rc)
        {
            FAPI_ERR("Put SCOM error for Table Base Address");
            break;
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
            break;
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
                break;
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
                break;
            }

            FAPI_DBG("SLW PORE Memory Relocation Register after MEM 0x%16llx", data.getDoubleWord(0));

            // Check that the bar address passed is 1MB aligned (eg bits 44:63 are zero)
            //
            region_masked_address = i_mem_bar & 0x00000000000FFFFF;
            if (region_masked_address != 0 )
            {
                FAPI_ERR("SLW BAR address is not 1MB aligned:  0x%16llx", i_mem_bar );
                const fapi::Target & CHIP = i_target;
                const uint64_t     & MEMBAR = i_mem_bar;
                const uint64_t     & REGIONMASKEDADDR = region_masked_address;
                FAPI_SET_HWP_ERROR(rc, RC_PROCPM_POREBAR_PBABAR_ERROR);
                break;
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
                const fapi::Target & CHIP = i_target;
                const uint64_t     & IMAGEADDR = (uint64_t)i_image;
                const uint32_t     & XIPRC = l_ecmdRc;
                const uint64_t     & IMAGESIZE = image_size;
                FAPI_SET_HWP_ERROR(rc, RC_PROCPM_POREBAR_XIP_IMAGE_SIZE_ERROR);
                break;
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
            const fapi::Target & CHIP = i_target;
            const uint64_t     & MEMLOC = i_mem_type;
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_POREBAR_LOC_ERROR);
            break;
        }

        FAPI_INF("SLW PORE Memory Relocation Register set to 0x%16llx", data.getDoubleWord(0));
        rc = fapiPutScom(i_target, PORE_SLW_MEMORY_RELOC_0x00068016, data);
        if (rc)
        {
            FAPI_ERR("Put SCOM error for Memory Relocation Address");
            break;
        }

        if (i_mem_type == SLW_MEMORY || i_mem_type == SLW_L3)
        {

            FAPI_DBG("Calling pba_bar_config to BAR %x Addr: 0x%16llX  Size: 0x%16llX",
                            pba_bar, i_mem_bar, i_mem_size);

            // Set the PBA BAR for the SLW region
            FAPI_EXEC_HWP(rc, p8_pba_bar_config, i_target,
                                                   pba_bar,
                                                   i_mem_bar,
                                                   i_mem_size,
                                                   slw_pba_cmd_scope);
            if(rc)
            {
                break;
            }

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
            // buf_alloc_a=1;              // SLW uses Buf A
            // buf_alloc_b=0;              // SLW does not use buffer B
            // buf_alloc_c=0;              // SLW does not use buffer C
            // dis_write_gather=0;         // SLW does not write.  \todo 24x7
            // wr_gather_timeout=0;        // SLW does not write   \todo 24x7
            // write_tsize=0;              // SLW does not write   \todo 24x7
            // extaddr=0;                  // Bits 23:36.  NA for SLW
            //

            // Slave 2 (PORE-SLW).  This is a read/write slave. Write gathering is
            // allowed, but with the shortest possible timeout.  The slave is set up
            // to allow normal reads and writes at initialization.  The 24x7 code may
            // reprogram this slave for IMA writes using special code sequences that
            // restore normal DMA writes after each IMA sequence.

            rc = bar_pba_slave_reset(i_target, SLW_PBA_SLAVE);
            if (rc)
            {
                FAPI_ERR("PBA Slave Reset failed");
                // \todo add FFDC
                 break;
            }


            ps.value = 0;
            ps.fields.enable = 1;
            ps.fields.mid_match_value = OCI_MASTER_ID_PORE_SLW;
            ps.fields.mid_care_mask = 0x7;
            ps.fields.read_ttype = PBA_READ_TTYPE_CL_RD_NC;
            ps.fields.read_prefetch_ctl = PBA_READ_PREFETCH_NONE;
            ps.fields.write_ttype = PBA_WRITE_TTYPE_DMA_PR_WR;
            ps.fields.wr_gather_timeout = PBA_WRITE_GATHER_TIMEOUT_2_PULSES;
            ps.fields.buf_alloc_a = 1;
            ps.fields.buf_alloc_b = 1;
            ps.fields.buf_alloc_c = 1;
            ps.fields.buf_alloc_w = 1;

            l_ecmdRc |=  data.setDoubleWord(0, ps.value);
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
        } // PBA setup for Memory or L3
    } while (0);
    return rc;
}

/// Reset a PBA slave with explicit timeout.
///
/// \param id A PBA slave id in the range 0..3
///
/// \param timeout A value of SsxInterval type.  The special value
/// SSX_WAIT_FOREVER indicates no timeout.
///
/// This form of bar_pba_slave_reset() gives the caller control over timeouts and
/// error handling.
///
/// \retval 0 Succes
///
/// \retval RC_PROCPM_PBA_SLVRST_TIMED_OUT The procedure timed out waiting for the PBA
/// to reset the slave.

fapi::ReturnCode
bar_pba_slave_reset(const fapi::Target& i_target, uint32_t id)
{

    pba_slvrst_t        psr;
    fapi::ReturnCode    rc;
    uint32_t            e_rc = 0;
    ecmdDataBufferBase  data(64);
    
    bool                poll_failure = false;
    uint32_t            p;
    
    uint8_t             ec_has_pba_slvrest_bug = 0;
    uint8_t             attr_mpipl = 0;


    // Tell PBA to reset the slave, then poll for completion with timeout.
    // The PBA is always polled at least twice to guarantee that we always
    // poll once after a timeout.
    
    do
    {
        rc = FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_HW_BUG_PBASLVRESET,
                                   &i_target,
                                   ec_has_pba_slvrest_bug);
        if(rc)
        {
     	    FAPI_ERR("Error querying Chip EC feature: "
                     "ATTR_CHIP_EC_FEATURE_HW_BUG_PBASLVRESET");
            break;
        }
        
        rc = FAPI_ATTR_GET(ATTR_IS_MPIPL, NULL, attr_mpipl);
        if(rc)
        {
     	    FAPI_ERR("Error querying attribute ATTR_IS_MPIPL");
            break;
        }

        psr.value = 0;
        psr.fields.set = PBA_SLVRST_SET(id);

        FAPI_DBG("  PBA_SLVRST%x: 0x%16llx", id, psr.value);

        e_rc |= data.setDoubleWord(0, psr.value);
        if(e_rc)
        {
            FAPI_ERR("Error (0x%x) manipulating ecmdDataBufferBase for PBA_SLVRST", e_rc);
            rc.setEcmdError(e_rc);
            return rc;
        }

        rc = fapiPutScom(i_target, PBA_SLVRST_0x00064001, data);
        if (rc)
        {
            FAPI_ERR("Put SCOM error for PBA Slave Reset");
            break;
        }
        
        // Due to HW228485, skip the check of the in-progress bits for MPIPL 
        // (after the PBA channels have been used at runtime) as they
        // are unreliable in Murano 1.x.
        if (attr_mpipl && ec_has_pba_slvrest_bug)
        {
            FAPI_INF("PBA Reset Polling being skipped due to MPIPL on a chip with PBA reset bug");
        }
        else
        {                                          
            poll_failure = true;
            for (p=0; p<MAX_PBA_RESET_POLLS; p++)
            {
                // Read the reset register to check for reset completion
                rc = fapiGetScom(i_target, PBA_SLVRST_0x00064001 , data);
                if (rc)
                {
                     FAPI_ERR("fapiGetPutScom( PBA_SLVRST_0x00064001 ) failed. With rc = 0x%x", (uint32_t)rc);
                     break;
                }
                FAPI_DBG("Slave %x reset poll data = 0x%016llX", id, data.getDoubleWord(0));

                // If slave reset in progress, wait and then poll
                if (data.isBitClear(4+id))
                {
                    FAPI_INF("PBA Reset complete for Slave %d", id);
                    poll_failure = false;
                    break;
                }
                else
                {
                    rc = fapiDelay(PBA_RESET_POLL_DELAY*1000, 200000);   // In microseconds
                    if (rc)
                    {
                         FAPI_ERR("fapiDelay failed. With rc = 0x%x", (uint32_t)rc);
                         break;
                    }
                }
            } 

            // Error exit from above loop
            if (!rc.ok())
            {
                 break;
            }

            if (poll_failure)
            {
                 FAPI_ERR("PBA Slave Reset Timout");
                 const fapi::Target & CHIP = i_target;
                 const uint32_t     & POLLCOUNT = MAX_PBA_RESET_POLLS;
                 const uint32_t     & POLLVALUE = PBA_RESET_POLL_DELAY;
                 const uint64_t     & PSR = data.getDoubleWord(0);
                 const uint32_t     & SLVID = id;
	             FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PBA_SLVRST_TIMED_OUT);
                 break;
            }
        }
    } while(0);
    return rc;
}


} //end extern C
