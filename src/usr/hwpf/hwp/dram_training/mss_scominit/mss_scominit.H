/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/dram_training/mss_scominit/mss_scominit.H $
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
//	 1.4   | menlowuu |20-JUN-12| added type to the typedef
//	 1.3   | menlowuu |13-JUN-12| added & to reference i_target in FP_t function
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
