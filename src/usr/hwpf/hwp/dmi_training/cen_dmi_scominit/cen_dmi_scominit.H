/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dmi_training/cen_dmi_scominit/cen_dmi_scominit.H $ */
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
// $Id: cen_dmi_scominit.H,v 1.3 2013/10/28 23:07:08 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/cen_dmi_scominit.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : cen_dmi_scominit.H
// *! DESCRIPTION : Invoke DMI initfiles (FAPI)
// *!
// *! OWNER NAME  : Mike Jones        Email: mjjones@us.ibm.com
// *! BACKUP NAME : Joe McGill        Email: jmcgill@us.ibm.com
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//  Version     Date        Owner       Description
//------------------------------------------------------------------------------
//    1.4       10/28/13    jmcgill     Updates for RAS review
//    1.3       01/23/13    thomsen     Added separate calls to base & custom
//                                      scominit files. Removed separate calls
//                                      to SIM vs. HW scominit files
//    1.1       08/11/12    jmcgill     Initial release
//------------------------------------------------------------------------------


#ifndef CEN_DMI_SCOMINIT_H_
#define CEN_DMI_SCOMINIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const char * const CEN_DMI_BASE_IF   = "cen.dmi.scom.if";
const char * const CEN_DMI_CUSTOM_IF = "cen.dmi.custom.scom.if";

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*cen_dmi_scominit_FP_t)(const fapi::Target & i_target);

extern "C" {

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

/**
 * @brief HWP that calls the DMI SCOM initfiles
 *
 * Should be called with all functional Centaur chips
 *
 *
 * @param[in] i_target Reference to target
 *                     If TARGET_TYPE_MEMBUF_CHIP, calls:
 *                     - cen.dmi.scom.initfile
 *
 * @return ReturnCode
 */
fapi::ReturnCode cen_dmi_scominit(const fapi::Target & i_target);


} // extern "C"

#endif // CEN_DMI_SCOMINIT_H_
