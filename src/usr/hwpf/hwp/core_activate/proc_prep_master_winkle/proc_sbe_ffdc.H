/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/core_activate/proc_prep_master_winkle/proc_sbe_ffdc.H $
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
// $Id: proc_sbe_ffdc.H,v 1.2 2012/04/25 19:56:34 jeshua Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_sbe_ffdc.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_sbe_ffdc.H
// *! DESCRIPTION : Log data for SBE fails (FAPI)
// *!
// *! OWNER NAME  : Jeshua Smith   Email: jeshua@us.ibm.com
// *! BACKUP NAME : Andreas Koenig Email: koenig@de.ibm.com
// *!
// *! ADDITIONAL COMMENTS :
// *!
// *! Collects:
// *!   o
// *!
// *! Successful operations assumes that:
// *!   o System clocks are running
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_SBE_FFDC_H_
#define _PROC_SBE_FFDC_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>
#include "p8_scom_addresses.H"

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*proc_sbe_ffdc_FP_t) (const fapi::Target&, fapi::ReturnCode&);

extern "C" {

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint16_t FSI_STATUS_0x1007 = 0x1007;
const uint16_t FSI_GP3_0x2812    = 0x2812;
const uint16_t FSI_GP4_0x2813    = 0x2813;
const uint16_t FSI_GP5_0x2814    = 0x2814;
const uint16_t FSI_GP6_0x2815    = 0x2815;
const uint16_t FSI_GP7_0x2816    = 0x2816;
const uint16_t FSI_GP8_0x2817    = 0x2817;
const uint16_t FSI_GP3MIR_0x281B = 0x281B;


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

// function: FAPI proc_sbe_ffdc HWP entry point
//           ffdc collection for SBE cache errors
// parameters: i_target => proc chip target
//             o_rc => return code to add ffdc data to
// returns: FAPI_RC_SUCCESS if no errors
//          else FAPI putscom return code for failing operation
fapi::ReturnCode proc_sbe_ffdc(const fapi::Target& i_target,
                               fapi::ReturnCode & o_rc);

} // extern "C"

#endif // _PROC_SBE_FFDC_H_
