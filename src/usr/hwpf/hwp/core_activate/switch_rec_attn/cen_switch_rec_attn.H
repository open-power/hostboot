/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/switch_rec_attn/cen_switch_rec_attn.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
// $Id: cen_switch_rec_attn.H,v 1.1 2012/12/10 22:39:06 mfred Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/cen_switch_rec_attn.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
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
