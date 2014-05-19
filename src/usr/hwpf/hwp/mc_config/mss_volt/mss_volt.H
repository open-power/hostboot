/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_volt/mss_volt.H $              */
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
// $Id: mss_volt.H,v 1.5 2012/07/17 13:23:39 bellows Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_volt.H
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Jeff Sabrowski    Email: jsabrow@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// Header file for mss_volt.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:   | Comment:
//---------|----------|----------|-----------------------------------------------
//  1.0    | jsabrow  | 11/30/11 | initial drop
//  1.2    | bellows  | 12/21/11 | fixed missing ;
//  1.4    | jsabrow  | 02/14/12 | Updates for code review
//  1.5    | bellows  | 07/16/12 | added $Id tag
#ifndef MSS_VOLTHWPB_H_
#define MSS_VOLTHWPB_H_

#include <fapi.H>

typedef fapi::ReturnCode (*mss_volt_FP_t)(std::vector<fapi::Target> &);

extern "C"
{

/**
 * @brief mss_volt procedure. Determines operating voltage for dimms behind a voltage domain
 *
 * @param[in]  std::vector<fapi::Target> l_targets  Reference to vector of Centaur Targets in a particular power domain
 *
 * @return ReturnCode
 */

  fapi::ReturnCode mss_volt(std::vector<fapi::Target> & l_targets_memb);

} // extern "C"

#endif // MSS_VOLTHWPB_H_
