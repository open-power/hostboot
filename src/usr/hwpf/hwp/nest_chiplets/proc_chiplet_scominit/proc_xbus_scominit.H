/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_chiplet_scominit/proc_xbus_scominit.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: proc_xbus_scominit.H,v 1.3 2013/11/09 18:37:40 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_xbus_scominit.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_xbus_scominit.H
// *! DESCRIPTION : Invoke XBUS initfile (FAPI)
// *!
// *! OWNER NAME  : Mike Jones        Email: mjjones@us.ibm.com
// *! BACKUP NAME : Joe McGill        Email: jmcgill@us.ibm.com
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------

#ifndef PROC_XBUS_SCOMINIT_H_
#define PROC_XBUS_SCOMINIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const char * const XBUS_BASE_IF   = "p8.xbus.scom.if";
const char * const XBUS_CUSTOM_IF = "p8.xbus.custom.scom.if";

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*proc_xbus_scominit_FP_t)(const fapi::Target & i_xbus_target,
                           const fapi::Target & i_connected_xbus_target);

extern "C" {

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

/**
 * @brief HWP that calls the XBUS SCOM initfiles
 *
 * Should be called for all valid/connected XBUS endpoints
 *
 * @param[in] i_xbus_target           Reference to XBUS chiplet target
 *            i_connected_xbus_target Reference to connected XBUS chiplet target
 *                                    If TARGET_TYPE_XBUS_ENDPOINT, calls:
 *                                    - p8.xbus.scom.initfile
 *                                    - p8.xbus.custom.scom.initfile
 *
 * @return ReturnCode
 */
fapi::ReturnCode proc_xbus_scominit(
    const fapi::Target & i_xbus_target,
    const fapi::Target & i_connected_xbus_target);


} // extern "C"

#endif // PROC_XBUS_SCOMINIT_H_
