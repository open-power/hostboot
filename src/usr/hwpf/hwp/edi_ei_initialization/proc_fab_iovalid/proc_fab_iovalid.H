/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/edi_ei_initialization/proc_fab_iovalid/proc_fab_iovalid.H $ */
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
// $Id: proc_fab_iovalid.H,v 1.10 2013/05/15 04:18:04 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_fab_iovalid.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_fab_iovalid.H
// *! DESCRIPTION : Manage X/A link iovalid controls (FAPI)
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *!
// *! ADDITIONAL COMMENTS:
// *!
// *! Manage fabric X/A link iovalid controls, which control the
// *! logical link layer fabric traffic.
// *!
// *! The iovalid controls are intended to be raised in the IPL flow
// *! after the underlying physical link layer is running, to start the
// *! flow of fabric frames.
// *!
// *! The iovalid controls are intended to be lowered prior to stopping
// *! the clocks in the dump process (to provide a clean dump state,
// *! assuming that the logical layer is quiesced).
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_FAB_IOVALID_H_
#define _PROC_FAB_IOVALID_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>


//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// HWP argument structure defining properties of this chip
struct proc_fab_iovalid_proc_chip
{
    // target for this chip
    fapi::Target this_chip;

    // X busses to operate on
    bool x0;
    bool x1;
    bool x2;
    bool x3;

    // A busses to operate on
    bool a0;
    bool a1;
    bool a2;
};

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*proc_fab_iovalid_FP_t)(std::vector<proc_fab_iovalid_proc_chip>&,
                         bool);

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// GP0 register bit/field definitions
const uint8_t X_GP0_X0_IOVALID_BIT = 48;
const uint8_t X_GP0_X1_IOVALID_BIT = 49;
const uint8_t X_GP0_X2_IOVALID_BIT = 50;
const uint8_t X_GP0_X3_IOVALID_BIT = 51;

const uint8_t A_GP0_A0_IOVALID_BIT = 48;
const uint8_t A_GP0_A1_IOVALID_BIT = 49;
const uint8_t A_GP0_A2_IOVALID_BIT = 50;

// ADU Secure Iovalid register bit/field definitions
const uint8_t ADU_IOS_LINK_EN_A0_IOVALID_BIT = 0;
const uint8_t ADU_IOS_LINK_EN_A1_IOVALID_BIT = 1;
const uint8_t ADU_IOS_LINK_EN_A2_IOVALID_BIT = 2;

// PB RAS FIR register bit/field definitions
const uint8_t PB_RAS_FIR_X0_BIT = 0;
const uint8_t PB_RAS_FIR_X1_BIT = 1;
const uint8_t PB_RAS_FIR_X2_BIT = 2;
const uint8_t PB_RAS_FIR_X3_BIT = 3;
const uint8_t PB_RAS_FIR_A0_BIT = 4;
const uint8_t PB_RAS_FIR_A1_BIT = 5;
const uint8_t PB_RAS_FIR_A2_BIT = 6;

// PB X FIR register bit/field definitions
const uint64_t PB_X_FIR_X0_BIT_MASK = 0xA000800000000000ULL;
const uint64_t PB_X_FIR_X1_BIT_MASK = 0x1400400000000000ULL;
const uint64_t PB_X_FIR_X2_BIT_MASK = 0x0280200000000000ULL;
const uint64_t PB_X_FIR_X3_BIT_MASK = 0x0050100000000000ULL;

// PB A FIR register bit/field definitions
const uint64_t PB_A_FIR_A0_BIT_MASK = 0x9281980040000000ULL;
const uint64_t PB_A_FIR_A1_BIT_MASK = 0x4850066020000000ULL;
const uint64_t PB_A_FIR_A2_BIT_MASK = 0x240A001990000000ULL;


extern "C"
{

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: FAPI proc_fab_iovalid HWP entry point
//           operates on chips passed in i_proc_chips argument to perform
//           desired iovalid manipulation (set or clear) on specified X/A busses
// parameters: i_proc_chips    => vector of proc_fab_iovalid_proc_chip
//                                structures which defines busses to
//                                act on
//             i_set_not_clear => define target iovalid operation (true=set,
//                                false=clear)
// returns: FAPI_RC_SUCCESS if all specified operations complete successfully,
//          else return code for failing operation
//------------------------------------------------------------------------------
fapi::ReturnCode proc_fab_iovalid(
    std::vector<proc_fab_iovalid_proc_chip>& i_proc_chips,
    bool i_set_not_clear);

} // extern "C"

#endif // _PROC_FAB_IOVALID_H_
