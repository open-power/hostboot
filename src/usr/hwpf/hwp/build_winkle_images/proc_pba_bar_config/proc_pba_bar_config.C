/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/build_winkle_images/proc_pba_bar_config/proc_pba_bar_config.C $
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
// $Id: proc_pba_bar_config.C,v 1.6 2012/05/23 15:22:10 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_pba_bar_config.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Klaus P. Gungl         Email: kgungl@de.ibm.com
// *!
// *!
/// \file proc_pba_bar_config.C
/// \brief Initialize PAB and PAB_MSK of PBA
// *!
// *! The purpose of this procedure is to set the PBA BAR, PBA BAR Mask and PBA scope value / registers
// *!
// *! Following proposals here: pass values for one set of pbabar, pass reference to structure for one set of pbabar, pass struct of struct containing
// *! all setup values
// *!
// *! High-level procedure flow:
// *!   parameter checking
// *!   set PBA_BAR
// *!   set PBA_BARMSK
// *!
// *! Procedure Prereq:
// *!   o System clocks are running
// *!
// *! list of changes
// *! 2011/11/22 all variables / passing calling parameters are uint64_t, cmd_scope is enum, MASK is not bitmask parameter but size
// *!            structure for init contain uint64_t only.
// *!
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi.H>
#include "p8_scom_addresses.H"
#include "proc_pba_init.H"
#include "proc_pba_bar_config.H"
#include "proc_pm.H"


extern "C" {


using namespace fapi;

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------

// for range checking            0x0123456701234567
#define BAR_ADDR_RANGECHECK_     0x0003FFFFFFF00000ull
#define BAR_ADDR_RANGECHECK_HIGH 0xFFFC000000000000ull
#define BAR_ADDR_RANGECHECK_LOW  0x00000000000FFFFFull
#define BAR_MASK_RANGECHECK      0x000001FFFFF00000ull
#define BAR_MASK_RANGECHECK_HIGH 0xFFFFFE0000000000ull
#define BAR_MASK_RANGECHECK_LOW  0x00000000000FFFFFull

// ----------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Prototypes
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

// --------------------------------------------- proc_pba_bar_config ----
// function:
// initialize initialize a specific set of PBA_BAR (=cmd_scope and address), PBA_BARMSK (mask/size)
// pass values directly
//! init_pba_bar_ps
//! initialize a set of  PBA_BAR and PBA_BARMSK registers, calling parameters: reference to structure of initialization values
/*!
@param i_target the target
@param i_index specifies which set of BAR / BARMSK registers to set. [0..3]
@param i_pba_bar_addr PBA base address - 1MB grandularity
@param i_pba_bar_mask PBA base address mask that defines the bits that are not used from the PBA base address - 1MB grandularity
                      The value of this mask + 1 defines the size of the window that is accessible.
                      (ex.  700000 yields an 8MB region)
@param i_pba_cmd_scope command scope according to pba spec
*/

fapi::ReturnCode
proc_pba_bar_config (const Target&  i_target,
		             uint32_t       i_index,
		             uint64_t       i_pba_bar_addr,
		             uint64_t       i_pba_bar_mask,
		             uint64_t       i_pba_cmd_scope
                     )
{

   // Define structures that map the register fields

   typedef union pba_barn {
        uint64_t value;
        struct {
#ifdef _BIG_ENDIAN
            uint32_t high_order;
            uint32_t low_order;
#else
            uint32_t low_order;
            uint32_t high_order;
#endif // _BIG_ENDIAN
        } words;
        struct {
#ifdef _BIG_ENDIAN
            uint64_t cmd_scope : 3;
            uint64_t reserved0 : 1;
            uint64_t reserved1 : 10;
            uint64_t addr : 50;
#else
            uint64_t addr : 50;
            uint64_t reserved1 : 10;
            uint64_t reserved0 : 1;
            uint64_t cmd_scope : 3;
#endif // _BIG_ENDIAN
        } fields;
    } pba_barn_t;


    typedef union pba_barmskn {
        uint64_t value;
        struct {
#ifdef _BIG_ENDIAN
            uint32_t high_order;
            uint32_t low_order;
#else
            uint32_t low_order;
            uint32_t high_order;
#endif // _BIG_ENDIAN
        } words;
        struct {
#ifdef _BIG_ENDIAN
            uint64_t reserved0 : 23;
            uint64_t mask : 41;
#else
            uint64_t mask : 41;
            uint64_t reserved0 : 23;
#endif // _BIG_ENDIAN
        } fields;
    } pba_barmskn_t;



    ecmdDataBufferBase      data(64);
    fapi::ReturnCode    l_rc;
    uint32_t            l_ecmdRc = 0;

    pba_barn_t          bar;
    pba_barmskn_t       barmask;

    FAPI_INF("Called with index %x, address 0x%16llX, mask 0x%16llX scope 0x%16llX",
                        i_index, i_pba_bar_addr, i_pba_bar_mask, i_pba_cmd_scope);

    // check if pba_bar scope in range
    if ( i_pba_cmd_scope > PBA_CMD_SCOPE_FOREIGN1 )
    {
        FAPI_ERR("ERROR: PB Command Scope out of Range");
        FAPI_SET_HWP_ERROR(l_rc, RC_PROC_PBA_BAR_SCOPE_OUT_OF_RANGE);
        return l_rc;
    }

    // check if pba_addr amd pba_mask are within range, high order bits checked, not low order!
    // this means if we need a check for "is this value on the correct boundary value => needs to be implemented
    if ( (BAR_ADDR_RANGECHECK_HIGH & i_pba_bar_addr) != 0x0ull)
    {
        FAPI_ERR("ERROR: Address out of Range");
        FAPI_SET_HWP_ERROR(l_rc, RC_PROC_PBA_ADDR_OUT_OF_RANGE);
        return l_rc;
    }
    if ( (BAR_MASK_RANGECHECK_HIGH & i_pba_bar_mask) != 0x0ull)
    {
        FAPI_ERR("ERROR: Mask out of Range");
        FAPI_SET_HWP_ERROR(l_rc, RC_PROC_PBA_BAR_MASK_OUT_OF_RANGE);
        return l_rc;
    }

    // put the parameters into the correct fields
    bar.fields.cmd_scope = i_pba_cmd_scope;
    bar.fields.addr = i_pba_bar_addr;
    barmask.fields.mask = i_pba_bar_mask;

    FAPI_INF("bar.fields   address 0x%16llX, scope  0x%16llX",
                        bar.fields.addr, bar.fields.cmd_scope);

     // Write the BAR
    l_ecmdRc |= data.setDoubleWord(0, bar.value);
    if (l_ecmdRc)
    {
       FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", l_ecmdRc);
       l_rc.setEcmdError(l_ecmdRc);
       return l_rc;
    }

// $$    FAPI_DBG("  PBA_BAR:  %s", data.genHexLeftStr(0,64).c_str());
    l_rc = fapiPutScom(i_target, PBA_BARs[i_index], data);
    if(l_rc)
    {
        FAPI_ERR("PBA_BAR Putscom failed");
        return l_rc;
    }

     // Write the MASK
    l_ecmdRc |= data.setDoubleWord(0, barmask.value);
    if (l_ecmdRc)
    {
       FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", l_ecmdRc);
       l_rc.setEcmdError(l_ecmdRc);
       return l_rc;
    }

// $$    FAPI_DBG("  PBA_BARMSK:  %s", data.genHexLeftStr(0,64).c_str());
    l_rc = fapiPutScom(i_target, PBA_BARMSKs[i_index], data);
    if(l_rc)
    {
      FAPI_ERR("PBA_MASK Putscom failed");
      return l_rc;
    }

    return l_rc;
}


} //end extern C

