/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dmi_training/proc_cen_set_inband_addr/proc_cen_set_inband_addr.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
// $Id: proc_cen_set_inband_addr.H,v 1.2 2012/11/30 15:33:55 mfred Exp $
// $Source: /afs/awd.austin.ibm.com/proj/p9/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_cen_set_inband_addr.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_cen_set_inband_addr.H
// *! DESCRIPTION : Set the inband base address in the MCS unit MCFGPR registers
// *!
// *! OWNER NAME  : Mark Fredrickson     Email: mfred@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_CEN_SET_INBAND_ADDR_H_
#define _PROC_CEN_SET_INBAND_ADDR_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*proc_cen_set_inband_addr_FP_t)(const fapi::Target &);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

/**
 * @brief proc_cen_set_inband_addr procedure.  The purpose of this procedure is to set the inband base address in the MCS unit MCFGPR registers
 *
 * @param[in]  i_target  Reference to pu.mcs target
 *
 * @return ReturnCode
 */

    fapi::ReturnCode proc_cen_set_inband_addr(const fapi::Target & i_target);
    // Target is pu.mcs

} // extern "C"

#endif // _PROC_CEN_SET_INBAND_ADDR_H_
