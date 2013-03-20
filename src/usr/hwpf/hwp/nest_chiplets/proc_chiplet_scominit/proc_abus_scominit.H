/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_chiplet_scominit/proc_abus_scominit.H $ */
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
// $Id: proc_abus_scominit.H,v 1.2 2013/02/11 04:27:41 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_abus_scominit.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_abus_scominit.H
// *! DESCRIPTION : Invoke ABUS initfile (FAPI)
// *!
// *! OWNER NAME  : Mike Jones        Email: mjjones@us.ibm.com
// *! BACKUP NAME : Joe McGill        Email: jmcgill@us.ibm.com
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------

#ifndef PROC_ABUS_SCOMINIT_H_
#define PROC_ABUS_SCOMINIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const char * const ABUS_BASE_IF = "p8.abus.scom.if";
const char * const ABUS_CUSTOM_IF = "p8.abus.custom.scom.if";

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*proc_abus_scominit_FP_t)(const fapi::Target & i_abus_target,
                           const fapi::Target & i_this_pu_target,
                           const fapi::Target & i_other_pu_target);

extern "C" {

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

/**
 * @brief HWP that calls the ABUS SCOM initfiles
 *
 * Should be called for all valid/connected ABUS endpoints
 *
 * @param[in] i_abus_target     Reference to ABUS target
 *            i_this_pu_target  Reference to enclosing chip target
 *            i_other_pu_target Reference to connected chip target
 *                              If i_abus_target is TARGET_TYPE_ABUS_ENDPOINT,
 *                                 i_this_pu_target is TARGET_TYPE_PROC_CHIP,
 *                                 i_other_pu_target is TARGET_TYPE_PROC_CHIP,
 *                              calls:
 *                              - p8.abus.scom.initfile
 *
 * @return ReturnCode
 */
fapi::ReturnCode proc_abus_scominit(
    const fapi::Target & i_abus_target,
    const fapi::Target & i_this_pu_target,
    const fapi::Target & i_other_pu_target);


} // extern "C"

#endif // PROC_ABUS_SCOMINIT_H_
