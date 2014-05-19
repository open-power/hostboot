/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_freq/mss_freq.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: mss_freq.H,v 1.5 2012/07/17 13:22:54 bellows Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_freq.H
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Jeff Sabrowski    Email: jsabrow@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// Header file for mss_freq.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:   | Comment:
//---------|----------|---------_|-----------------------------------------------
//  1.0    | jsabrow  | 11/30/11 | initial drop
//  1.2    | jsabrow  | 02/14/12 | Updates for initial code review
//  1.3    | jdsloat  | 04/26/12 | Code review updates
//  1.5    | bellows  | 07/16/12 | added in Id tag

#ifndef MSS_FREQHWPB_H_
#define MSS_FREQHWPB_H_

#include <fapi.H>

typedef fapi::ReturnCode (*mss_freq_FP_t)(const fapi::Target &);

extern "C"
{

/**
 * @brief mss_freq procedure. Determines operating frequency for dimms behind a centaur
 *
 * @param[in]  fapi::Target &l_targets  target type = centaur
 *
 * @return ReturnCode
 */

  fapi::ReturnCode mss_freq(const fapi::Target & i_target);

} // extern "C"

#endif // MSS_FREQHWPB_H_
