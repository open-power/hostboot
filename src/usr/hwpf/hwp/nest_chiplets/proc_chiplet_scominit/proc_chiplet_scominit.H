/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/nest_chiplets/proc_chiplet_scominit/proc_chiplet_scominit.H $
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
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_chiplet_scominit.H
// *! DESCRIPTION : Wrapper HWP that invokes the proc_chiplet_scominit initfiles
// *! OWNER NAME  : Mike Jones        Email: mjjones@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// Header file for proc_chiplet_scominit.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.3   | mjjones  |26-JUN-12| Initial version
//   1.4   | mjjones  |05-JUL-12| Removed DMI initfiles from here


#ifndef PROC_CHIPLET_SCOMINIT_H_
#define PROC_CHIPLET_SCOMINIT_H_

//----------------------------------------------------------------------
//  My Includes
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi.H>

typedef fapi::ReturnCode (*proc_chiplet_scominit_FP_t)(const fapi::Target & i_target);

extern "C" {

/**
 * @brief HWP that calls the proc_chiplet_scominit initfiles
 * 
 * Should be called with all functional proc chips. It invokes initfiles
 * on chiplets.
 * 
 * @param[in] i_target Reference to PROC_CHIP target
 *
 * @return ReturnCode
 */
fapi::ReturnCode proc_chiplet_scominit(const fapi::Target & i_target);

} // extern "C"

#endif // PROC_CHIPLET_SCOMINIT_H_
