/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_scominit/mss_scominit.H $  */
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
// $Id: mss_scominit.H,v 1.7 2012/11/10 02:53:17 mwuu Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_scominit.H
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Menlo Wuu         Email: menlowuu@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// Header file for mss_scominit.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.7   | menlowuu |09-NOV-12| Removed mss_set_bbm_regs since now done in
//   							  draminit_training
//   1.6   | menlowuu |15-AUG-12| added bad bitmask function
//   1.5   |bellows   |16-JUL-12| added in Id tag
//   1.4   | menlowuu |20-JUN-12| added type to the typedef
//   1.3   | menlowuu |13-JUN-12| added & to reference i_target in FP_t function
//	 							  added comment expecting centaur target
//   1.2   | menlowuu |06-JUN-12| Removed char* parameter for function
//   0.1   | menlowuu |01-DEC-11| First Draft.


#ifndef MSS_SCOMINIT_H_
#define MSS_SCOMINIT_H_

//----------------------------------------------------------------------
//  My Includes
//----------------------------------------------------------------------


//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi.H>

typedef fapi::ReturnCode (*mss_scominit_FP_t)(const fapi::Target & i_target);

extern "C" {

//******************************************************************************
// mss_scominit
//******************************************************************************
// mss_scominit procedure [Calls the vaious memory initfiles]
// param[in] i_target [Reference to target, expecting centaur(MEMBUF) target]
// return ReturnCode

fapi::ReturnCode mss_scominit(const fapi::Target & i_target);

} // extern "C"

#endif // MSS_SCOMINIT_H_
