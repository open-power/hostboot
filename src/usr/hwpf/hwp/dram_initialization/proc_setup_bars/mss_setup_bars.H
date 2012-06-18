/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/dram_initialization/proc_setup_bars/mss_setup_bars.H $
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
// *! TITLE       : mss_setup_bars.H
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Girisankar Paulraj     Email: gpaulraj@in.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// Header file for mss_setup_bars.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.1    | gpaulraj | 03/19/12| Updated

#ifndef MSS_SETUP_BARS_H_
#define MSS_SETUP_BARS_H_

#include <fapi.H>
#include "p8_scom_addresses.H"

typedef fapi::ReturnCode (*mss_setup_bars_FP_t)(const fapi::Target&);

extern "C"
{

fapi::ReturnCode mss_setup_bars(const fapi::Target& i_chip_target);

} // extern "C"

#endif // MSS_SETUP_BARS_H_
