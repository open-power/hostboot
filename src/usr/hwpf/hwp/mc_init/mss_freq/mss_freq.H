//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/mc_init/mss_freq/mss_freq.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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

#ifndef MSS_FREQHWPB_H_
#define MSS_FREQHWPB_H_

#include <fapi.H>

typedef fapi::ReturnCode (*mss_freq_FP_t)(fapi::Target &);

extern "C"
{

/**
 * @brief mss_freq procedure. Determines operating frequency for dimms behind a centaur
 *
 * @param[in]  fapi::Target &l_targets  reference to one centaur
 *
 * @return ReturnCode
 */

  fapi::ReturnCode mss_freq(fapi::Target & i_target);

} // extern "C"

#endif // MSS_FREQHWPB_H_
