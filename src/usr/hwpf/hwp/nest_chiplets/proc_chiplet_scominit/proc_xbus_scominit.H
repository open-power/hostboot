/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_chiplet_scominit/proc_xbus_scominit.H $ */
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
// $Id: proc_xbus_scominit.H,v 1.2 2013/02/04 23:08:13 thomsen Exp $
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
//------------------------------------------------------------------------------
//  Version		Date		Owner		Description
//------------------------------------------------------------------------------
//    1.2	   	02/04/13	thomsen		Added separate calls to base & customized scominit files. Removed separate calls to SIM vs. HW scominit files
//           	01/09/13	thomsen		Added SIM and HW scominit filename strings
//										Added *_OVERRIDE_IF to allow DMI initfile overrides for specific bus instances
//                                      Changed passed targets in order to match scominit file updates.
//    1.1       8/11/12     jmcgill		Initial release
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
 * @param[in] i_xbus_target            Reference to XBUS target
 *            i_connected_abus_target  Reference to connected ABUS target
 *                              If i_xbus_target is TARGET_TYPE_XBUS_ENDPOINT,
 *                                 i_connected_abus_target is TARGET_TYPE_ABUS_ENDPOINT,
 *                              calls:
 *                              - p8.xbus.scom.initfile
 *
 * @return ReturnCode
 */
fapi::ReturnCode proc_xbus_scominit(
    const fapi::Target & i_xbus_target,
    const fapi::Target & i_connected_xbus_target);


} // extern "C"

#endif // PROC_XBUS_SCOMINIT_H_
