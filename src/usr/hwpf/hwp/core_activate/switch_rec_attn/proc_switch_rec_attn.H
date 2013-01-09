/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/switch_rec_attn/proc_switch_rec_attn.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
// $Id: proc_switch_rec_attn.H,v 1.1 2012/12/10 20:38:07 mfred Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_switch_rec_attn.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_switch_rec_attn.H
// *! DESCRIPTION : The purpose of this procedure is to mask Centaur recoverable attentions from the host
// *!               (At this point in the IPL process those attentions should be routed to the FSP.)
// *!
// *! OWNER NAME  : Mark Fredrickson     Email: mfred@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_SWITCH_REC_ATTN_H_
#define _PROC_SWITCH_REC_ATTN_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*proc_switch_rec_attn_FP_t)(const fapi::Target &);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

/**
 * @brief proc_switch_rec_attn procedure.  The purpose of this procedure is to mask Centaur recoverable attentions from the host.
 *
 * @param[in]  i_target  Reference to pu.mcs target
 *
 * @return ReturnCode
 */

    fapi::ReturnCode proc_switch_rec_attn(const fapi::Target & i_target);
    // Target is pu.mcs

} // extern "C"

#endif // _PROC_SWITCH_REC_ATTN_H_
