/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/mc_config/mss_volt/mss_volt.H $
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
