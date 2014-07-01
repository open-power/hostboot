/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit/mss_draminit.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// $Id: mss_draminit.H,v 1.5 2012/02/10 21:59:20 jdsloat Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_draminit.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_draminit.H
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Jacob Sloat     Email: jdsloat@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// Header file for mss_draminit.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.4    | jdsloat  |  2/10/12| & fix
//  1.3    | jdsloat  |  2/08/12| added description to target
//  1.2    | jdsloat  |  1/13/12| added "fapi::" and "const" in typedef to match the call in the extern
//  1.1    | jdsloat  | 11/18/11| Updated

#ifndef MSS_DRAMINITHWPB_H_
#define MSS_DRAMINITHWPB_H_

#include <fapi.H>

typedef fapi::ReturnCode (*mss_draminit_FP_t)(const fapi::Target& i_target);

extern "C"
{

/**
 * @brief Draminit procedure. Loading RCD and MRS into the drams.
 *
 * @param[in]  i_target  Reference to centaur.mba target
 *
 * @return ReturnCode
 */

fapi::ReturnCode mss_draminit(const fapi::Target& i_target);

} // extern "C"

#endif // MSS_DRAMINITHWPB_H_
