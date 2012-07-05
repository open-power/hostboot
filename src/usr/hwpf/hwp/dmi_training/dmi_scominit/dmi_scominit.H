/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/dmi_training/dmi_scominit/dmi_scominit.H $
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
// *! TITLE       : dmi_scominit.H
// *! DESCRIPTION : Wrapper HWP that invokes the dmi_scominit initfiles
// *! OWNER NAME  : Mike Jones        Email: mjjones@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// Header file for dmi_scominit.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.1   | mjjones  |05-JUL-12| Initial version


#ifndef DMI_SCOMINIT_H_
#define DMI_SCOMINIT_H_

//----------------------------------------------------------------------
//  My Includes
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi.H>

typedef fapi::ReturnCode (*dmi_scominit_FP_t)(const fapi::Target & i_target);

extern "C" {

/**
 * @brief HWP that calls the dmi_scominit initfiles
 * 
 * Should be called with all functional MCS chiplets and all functional
 * membuf chips.
 * 
 * @param[in] i_target Reference to target
 *                     If MCS_CHIPLET, calls:
 *                     - p8.dmi.scom.initfile
 *                     If MEMBUF_CHIP, calls:
 *                     - cen.dmi.scom.initfile
 *
 * @return ReturnCode
 */
fapi::ReturnCode dmi_scominit(const fapi::Target & i_target);

} // extern "C"

#endif // DMI_SCOMINIT_H_
