/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/switch_rec_attn/cen_switch_rec_attn.H $ */
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
// $Id: cen_switch_rec_attn.H,v 1.1 2012/12/10 22:39:06 mfred Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/cen_switch_rec_attn.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : cen_switch_rec_attn.H
// *! DESCRIPTION : The purpose of this procedure is to route Centaur recoverable attentions to the FSP instead of to the P8 host.
// *! OWNER NAME  : Mark Fredrickson  Email: mfred@us.ibm.com
//
// Header file for cen_switch_rec_attn.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.0    | mfred    | 05/30/12| Initial creation

#ifndef CEN_SWITCH_REC_ATTNHWPB_H_
#define CEN_SWITCH_REC_ATTNHWPB_H_

#include <fapi.H>

typedef fapi::ReturnCode (*cen_switch_rec_attn_FP_t)(const fapi::Target& i_target);

extern "C"
{
    // Target is centaur

/**
 * @brief cen_switch_rec_attn procedure.  The purpose of this procedure is to route Centaur recoverable attentions to the FSP instead of to the P8 host.
 *
 * @param[in]  i_target  Reference to centaur target
 *
 * @return ReturnCode
 */

    fapi::ReturnCode cen_switch_rec_attn(const fapi::Target& i_target);
    // Target is centaur

} // extern "C"

#endif // CEN_SWITCH_REC_ATTNHWPB_H_
