/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dmi_training/proc_dmi_scominit/proc_dmi_scominit.H $ */
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
// $Id: proc_dmi_scominit.H,v 1.3 2013/01/24 20:20:34 thomsen Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_dmi_scominit.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_dmi_scominit.H
// *! DESCRIPTION : Invoke DMI initfile (FAPI)
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
//    1.3	   	01/23/13	thomsen		Added separate calls to base & customized scominit files. Removed separate calls to SIM vs. HW scominit files
//    1.2	   	01/10/13	thomsen		Added SIM and HW scominit filename strings
//										Added *_OVERRIDE_IF to allow initfile overrides for specific bus instances
//                                      CO-REQs required: p8.dmi.vbu.scom.initfile v1.1 and p8.dmi.hw.scom.initfile v1.1
//    1.1       8/11/12     jmcgill		Initial release
//------------------------------------------------------------------------------

#ifndef PROC_DMI_SCOMINIT_H_
#define PROC_DMI_SCOMINIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const char * const MCS_DMI_BASE_IF   = "p8.dmi.scom.if";
const char * const MCS_DMI_CUSTOM_IF = "p8.dmi.custom.scom.if";

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*proc_dmi_scominit_FP_t)(const fapi::Target & i_target);

extern "C" {

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

/**
 * @brief HWP that calls the DMI SCOM initfiles
 *
 * Should be called with all functional MCS chiplets
 *
 * @param[in] i_target Reference to target
 *                     If TARGET_TYPE_MCS_CHIPLET, calls:
 *                     - p8.dmi.scom.initfile
 *
 * @return ReturnCode
 */
fapi::ReturnCode proc_dmi_scominit(const fapi::Target & i_target);


} // extern "C"

#endif // PROC_DMI_SCOMINIT_H_
