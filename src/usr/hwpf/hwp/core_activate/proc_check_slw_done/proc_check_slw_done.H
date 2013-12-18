/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/proc_check_slw_done/proc_check_slw_done.H $ */
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
// $Id: proc_check_slw_done.H,v 1.2 2013/12/06 13:26:18 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_check_slw_done.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_check_slw_done.H
// *! DESCRIPTION :
// *!
// *! OWNER NAME  : Greg Still    Email: stillgs@us.ibm.com
// *! BACKUP NAME : Michael Olsen Email: cmolsen@us.ibm.coms
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_CHECKSLWDONE_H_
#define _PROC_CHECKSLWDONE_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "p8_pm.H"

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*proc_check_slw_done_FP_t) (  const fapi::Target&,
                                                        const uint64_t);

extern "C" {


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Parameter structure definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
/**
 * proc_check_slw_done
 *
 * @param[in] i_target EX target
 * @param[in] i_slw_image_address Memory Address SLW image
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR 
 */
fapi::ReturnCode
proc_check_slw_done(const fapi::Target& i_ex_target, 
                    const uint64_t      i_good_halt_address );


} // extern "C"

#endif // _PROC_CHECKSLWDONE_H_
