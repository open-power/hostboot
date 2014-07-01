/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_error_support.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
// $Id: mss_error_support.H,v 1.1 2013/03/21 19:04:22 bellows Exp $

//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2013
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
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

