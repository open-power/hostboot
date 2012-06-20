/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/dram_initialization/mss_extent_setup/mss_extent_setup.H $
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
// *! TITLE       : mss_extent_setup.H
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : girisankar paulraj     Email: gpaulraj@in.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// Header file for mss_extent_setup.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.7    | bellows  |15-Jun-12| Updated for Firmware
//   1.2   |          |         |
//   1.1   | gpaulraj |11-NOV-11| First Draft.

#ifndef MSS_EXTENT_SETUP_H_
#define MSS_EXTENT_SETUP_H_

#include <fapi.H>

typedef fapi::ReturnCode (*mss_extent_setup_FP_t)();

extern "C"
{
/**
 * @brief extent setup  procedure -- currently an open shell until extent functions are found t obe needed 
 *
 *
 * @return ReturnCode
 */

fapi::ReturnCode mss_extent_setup();

} // extern "C"

#endif // MSS_EXTENT_SETUP_H_
