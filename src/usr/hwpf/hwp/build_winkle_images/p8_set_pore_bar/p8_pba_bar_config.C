/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_pba_bar_config.C $ */
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
// $Id: p8_pba_bar_config.C,v 1.6 2015/01/23 14:57:37 cmolsen Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pba_bar_config.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Klaus P. Gungl         Email: kgungl@de.ibm.com
// *!
// *!
// *! To build  -  buildfapiprcd -e ../../xml/error_info/p8_pba_bar_config_errors.xml p8_pba_bar_config.C
// *!
/// \file p8_pba_bar_config.C
/// \brief Initialize PAB and PAB_MSK of PBA
///
/// \verbatim
///     The purpose of this procedure is to set the PBA BAR, PBA BAR Mask and
///     PBA scope value / registers
///
///     Following proposals here: pass values for one set of pbabar, pass reference to structure for one set of pbabar, pass struct of struct containing
///     all setup values
///
///     High-level procedure flow:
///       parameter checking
///       set PBA_BAR
///      set PBA_BARMSK
///
///    Procedure Prereq:
///      o System clocks are running
///
///  CQ Class:  power_management
/// \endverbatim
///
///   list of changes
///     2011/11/2   all variables / passing calling parameters are uint64_t,    
///                 cmd_scope is enum, MASK is not bitmask parameter but size    
///                 structure for init contain uint64_t only.                    
///
///     2012/10/0   made isPowerofTwo() and PowerOfTwoRoundedup() inline
///                 included pba_firmware_registers.h vs pba_firmware_register.H  
///
///     2012/10/18  Added support for BAR reset (BAR=0, Size=0) as being legal
///                 Added 1M alignment checking
///
//------------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <fapi.H>
#include "p8_scom_addresses.H"
#include "p8_pba_init.H"
#include "p8_pba_bar_config.H"
//#include "pba_firmware_register.H"
#include "pba_firmware_registers.h"
#include "p8_pm.H"


extern "C" {


using namespace fapi;

// -----------------------------------------------------------------------------
// Constant definitions
// -----------------------------------------------------------------------------

// for range checking            0x0123456701234567
#define BAR_ADDR_RANGECHECK_     0x0003FFFFFFF00000ull
#define BAR_ADDR_RANGECHECK_HIGH 0xFFFC000000000000ull
#define BAR_ADDR_RANGECHECK_LOW  0x00000000000FFFFFull

// -----------------------------------------------------------------------------
// Global variables
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Prototypes
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Function definitions
// -----------------------------------------------------------------------------

inline bool isPowerOfTwo (uint64_t value);
inline uint64_t PowerOf2Roundedup (uint64_t value);


/// --------------------------------------------- p8_pba_bar_config ------------
/// Initialize a specific set of PBA_BAR (=cmd_scope and address),
///  PBA_BARMSK (mask/size)
///
///  @param i_target the target
///  @param i_index specifies which set of BAR/BARMSK registers to set. [0..3]
///  @param i_pba_bar_addr PBA base address - 1MB grandularity
///  @param i_pba_bar_size PBA region size in MB;  if not a power of two value,
///          the value will be rounded up to the next power of 2 for setting the
///          hardware mask
///  @param i_pba_cmd_scope command scope according to pba spec
fapi::ReturnCode
p8_pba_bar_config (const Target&  i_target,
		             uint32_t       i_index,
		             uint64_t       i_pba_bar_addr,
		             uint64_t       i_pba_bar_size,
		             uint64_t       i_pba_cmd_scope
                     )
{


    ecmdDataBufferBase  data(64);
    fapi::ReturnCode    l_rc;
    uint32_t            l_ecmdRc = 0;

    pba_barn_t          bar;
    pba_barmskn_t       barmask;

    uint64_t            work_size;

    FAPI_DBG("Called with index %x, address 0x%08llX, size 0x%04llX scope 0x%04llX",
                       i_index, i_pba_bar_addr, i_pba_bar_size, i_pba_cmd_scope);

    // check if pba_bar scope in range
    if ( i_pba_cmd_scope > PBA_CMD_SCOPE_FOREIGN1 )
    {
        FAPI_ERR("ERROR: PB Command Scope out of Range: 0x%04llX > 0x%04X", i_pba_cmd_scope, PBA_CMD_SCOPE_FOREIGN1 );
        const uint64_t exp_PBA_CMD_SCOPE_FOREIGN1 = PBA_CMD_SCOPE_FOREIGN1;
        FAPI_SET_HWP_ERROR(l_rc, RC_PROC_PBA_BAR_SCOPE_OUT_OF_RANGE);
        return l_rc;
    }

    // Check if pba_addr amd pba_size are within range,
    // High order bits checked to ensure a valid real address
    if ( (BAR_ADDR_RANGECHECK_HIGH & i_pba_bar_addr) != 0x0ull )
    {
        FAPI_ERR("ERROR: Address out of Range : i_pba_bar_addr=0x%08llX", i_pba_bar_addr);
        const uint64_t exp_BAR_ADDR_RANGECHECK_HIGH = BAR_ADDR_RANGECHECK_HIGH;
        FAPI_SET_HWP_ERROR(l_rc, RC_PROC_PBA_ADDR_OUT_OF_RANGE);
        return l_rc;
    }

    // Low order bits checked for alignment
    if ( (BAR_ADDR_RANGECHECK_LOW & i_pba_bar_addr) != 0x0ull )
    {
        FAPI_ERR("ERROR: Address must be on a 1MB boundary : i_pba_bar_addr=0x%08llX",i_pba_bar_addr);
        const uint64_t exp_BAR_ADDR_RANGECHECK_LOW = BAR_ADDR_RANGECHECK_LOW;
        FAPI_SET_HWP_ERROR(l_rc, RC_PROC_PBA_ADDR_ALIGNMENT_ERROR);
        return l_rc;
    }

    // Check if the BAR size is 0 but the BAR addr is not zero.  If so, return error.
    // The combination of both the BAR size and addr being zero is legal.
    if ( (i_pba_bar_size == 0) && (i_pba_bar_addr != 0) )
    {
        FAPI_ERR("ERROR: Bar size must be >=1MB for PBABAR%d but i_pba_bar_size=0x%08llx",
                    i_index, i_pba_bar_size);
        FAPI_SET_HWP_ERROR(l_rc, RC_PROC_PBA_BAR_SIZE_INVALID);
        return l_rc;
    }

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



    // put the parameters into the correct fields
    bar.value=0;
    bar.fields.cmd_scope = i_pba_cmd_scope;
    bar.fields.addr = i_pba_bar_addr >> 20;

    FAPI_DBG("\tbar.fields addr  0x%16llX, scope  0x%llX",
                        bar.fields.addr, bar.fields.cmd_scope);
    FAPI_DBG("\tbar.value        0x%16llX", bar.value);

    // Write the BAR
    l_ecmdRc |= data.setDoubleWord(0, bar.value);
    if (l_ecmdRc)
    {
       FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", l_ecmdRc);
       l_rc.setEcmdError(l_ecmdRc);
       return l_rc;
    }

    FAPI_DBG("\tPBA_BAR%x:        0x%16llX", i_index,  data.getDoubleWord(0));
    l_rc = fapiPutScom(i_target, PBA_BARs[i_index], data);
    if(l_rc)
    {
        FAPI_ERR("PBA_BAR Putscom failed");
        return l_rc;
    }

    // Compute and write the mask based on passed region size.

    // If the size is already a power of 2, then set the mask to that value - 1.
    // If the size is not a power of 2, then set the maskto  the rounded up power of 2
    // value - 1.
    // If the size is zero, then treat as if equal to 1 and then do the round up check.

    if (i_pba_bar_size!=0)
    {
        work_size = PowerOf2Roundedup(i_pba_bar_size);
        FAPI_INF("\ti_pba_bar_size: 0x%llX.  Final work_size: 0x%llX", 
                    i_pba_bar_size, work_size);
    }
    else
    { // If bar_size==0, treat as if ==1. Otherwize, range will max out to 2TB.
        work_size = PowerOf2Roundedup(1ull);
        FAPI_INF("\ti_pba_bar_size: 0x%llX but treated as if bar_size=1. Final work_size: 0x%llX", 
                    i_pba_bar_size, work_size);
    }

    barmask.value=0;
    barmask.fields.mask = work_size-1;

    FAPI_DBG("\tbar.fields mask  0x%16llX", barmask.fields.mask);
    FAPI_DBG("\tbar.value        0x%16llX", barmask.value);

    // Write the MASK
    l_ecmdRc |= data.setDoubleWord(0, barmask.value);
    if (l_ecmdRc)
    {
        FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", l_ecmdRc);
        l_rc.setEcmdError(l_ecmdRc);
        return l_rc;
    }

    FAPI_DBG("  PBA_BARMSK%x:     0x%16llX", i_index,  data.getDoubleWord(0));
    l_rc = fapiPutScom(i_target, PBA_BARMSKs[i_index], data);
    if(l_rc)
    {
        FAPI_ERR("PBA_MASK Putscom failed");
        return l_rc;
    }

    return l_rc;
}

///-----------------------------------------------------------------------------
/// Determine if a number is a power of two or not
///-----------------------------------------------------------------------------
inline bool
isPowerOfTwo(uint64_t value)
{
    // if value ANDed with the value-1 is 0, then value is a power of 2.
    // if value is 0, this is considered not a power of 2 and will return false.

    return !(value & (value - 1));

}

///-----------------------------------------------------------------------------
/// Round up to next higher power of 2 (return value if it's already a power of
/// 2).
///-----------------------------------------------------------------------------
inline uint64_t
PowerOf2Roundedup (uint64_t value)
{
    if (value < 0)
        return 0;
    --value;
    value |= value >> 1;
    value |= value >> 2;
    value |= value >> 4;
    value |= value >> 8;
    value |= value >> 16;
    return value+1;
}


} //end extern C

