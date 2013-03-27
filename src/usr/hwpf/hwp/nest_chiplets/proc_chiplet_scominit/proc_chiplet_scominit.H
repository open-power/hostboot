/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_chiplet_scominit/proc_chiplet_scominit.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
// $Id: proc_chiplet_scominit.H,v 1.10 2013/03/25 02:39:43 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_chiplet_scominit.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_chiplet_scominit.H
// *! DESCRIPTION : Invoke initfiles for proc_chiplet_scominit istep (FAPI)
// *!
// *! OWNER NAME  : Mike Jones        Email: mjjones@us.ibm.com
// *! BACKUP NAME : Joe McGill        Email: jmcgill@us.ibm.com
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------

#ifndef PROC_CHIPLET_SCOMINIT_H_
#define PROC_CHIPLET_SCOMINIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

const char * const PROC_CHIPLET_SCOMINIT_FBC_IF       = "p8.fbc.scom.if";
const char * const PROC_CHIPLET_SCOMINIT_PSI_IF       = "p8.psi.scom.if";
const char * const PROC_CHIPLET_SCOMINIT_TPBRIDGE_IF  = "p8.tpbridge.scom.if";
const char * const PROC_CHIPLET_SCOMINIT_NX_IF        = "p8.nx.scom.if";
const char * const PROC_CHIPLET_SCOMINIT_AS_IF        = "p8.as.scom.if";
const char * const PROC_CHIPLET_SCOMINIT_MCS_IF       = "p8.mcs.scom.if";

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*proc_chiplet_scominit_FP_t)(const fapi::Target & i_target);

extern "C" {

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

/**
 * @brief HWP which invokes initfiles for proc_chiplet_scominit istep
 *
 * Should be called with all functional proc chips. It invokes initfiles
 * on chiplets.
 *
 * @param[in] i_target Reference to target
 *                     If TARGET_TYPE_PROC_CHIP, calls:
 *                     - p8.fbc.scom.initfile
 *                     - p8.psi.scom.initfile
 *                     - p8.tpbridge.scom.initfile
 *                     - p8.nx.scom.initfile
 *                     - p8.as.scom.initfile
 *                     - p8.mcs.scom.initfile for each functional MCS chiplet
 *
 * @return ReturnCode
 */
fapi::ReturnCode proc_chiplet_scominit(const fapi::Target & i_target);


} // extern "C"

#endif // PROC_CHIPLET_SCOMINIT_H_
