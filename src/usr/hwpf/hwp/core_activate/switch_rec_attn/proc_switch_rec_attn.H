/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/switch_rec_attn/proc_switch_rec_attn.H $ */
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
// $Id: proc_switch_rec_attn.H,v 1.1 2012/12/10 20:38:07 mfred Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_switch_rec_attn.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
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
