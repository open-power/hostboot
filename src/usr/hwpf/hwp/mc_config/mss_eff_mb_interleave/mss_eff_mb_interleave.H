/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_mb_interleave/mss_eff_mb_interleave.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
// $Id: mss_eff_mb_interleave.H,v 1.3 2014/02/19 20:06:18 bellows Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_eff_mb_interleave.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2014
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *!  Licensed material - Program property of IBM
// *!  Refer to copyright instructions form no. G120-2083
// *! Created on Wed Jan  8 2014 at 07:56:37
//------------------------------------------------------------------------------
// *! TITLE       : mss_eff_mb_interleave
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  :  Bellows Mark D. (Mark D),319432 Email: bellows@us.ibm.com
// *! BACKUP NAME :                 Email: ______@us.ibm.com

// *! ADDITIONAL COMMENTS :
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.3   | bellows  |19-JAN-14| Additional RAS updates
//   1.2   | bellows  |17-JAN-14| RAS
//   1.1   | bellows  |08-JAN-14| Created.
#ifndef __MSS_EFF_MB_INTERLEAVE_H
#define __MSS_EFF_MB_INTERLEAVE_H

#include <fapi.H>

typedef fapi::ReturnCode (*mss_eff_mb_interleave_FP_t)(const fapi::Target& centaur );

extern "C"
{

// This hardware procedure checks the plugging rules for a centaur and works with interleaving within the centaur
// if various plug rules are violated at this level of the memory stack, error logs and deconfigures will happen
// Many deconfig by assoication rules are not checked here.  Just 4.1 and 4.2 plus a required Interleaving check
fapi::ReturnCode mss_eff_mb_interleave(const fapi::Target & i_cen_target);



} // extern "C"

#endif
