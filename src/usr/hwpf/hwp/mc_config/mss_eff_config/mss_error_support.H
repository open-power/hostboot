/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_error_support.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: mss_error_support.H,v 1.1 2013/03/21 19:04:22 bellows Exp $

//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2013
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE : mss_error_support.H
// *! DESCRIPTION : Tools
// *! OWNER NAME : bellows@us.ibm.com
// *! BACKUP NAME :
// #! ADDITIONAL COMMENTS :
//

//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.0    | 03/08/13 | bellows | First version

#ifndef _MSS_ERROR_SUPPORT_H
#define _MSS_ERROR_SUPPORT_H

#include <fapi.H>

typedef fapi::ReturnCode (*hwpCollectMemGrouping_FP_t)(const fapi::Target&,  fapi::ReturnCode &);

extern "C"
{


fapi::ReturnCode hwpCollectMemGrouping(const fapi::Target & i_target,fapi::ReturnCode & o_rc);
fapi::ReturnCode hwpCollectMemFIRs(const fapi::Target & i_target,fapi::ReturnCode & o_rc);



} // extern "C"

#endif /* _MSS_ERROR_SUPPORT_H */

