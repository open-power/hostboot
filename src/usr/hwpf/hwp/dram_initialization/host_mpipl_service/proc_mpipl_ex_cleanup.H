/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/host_mpipl_service/proc_mpipl_ex_cleanup.H $ */
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
// $Id: proc_mpipl_ex_cleanup.H,v 1.3 2012/11/27 23:11:35 belldi Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_mpipl_ex_cleanup.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_mpipl_ex_cleanup.H
// *! DESCRIPTION : Undo step that prepared fast-winkled cores for scanning and set up deep winkle mode
// *!
// *! OWNER  NAME  : Dion Bell                Email: belldi@us.ibm.com
// *! BACKUP NAME  : Dion Bell                Email: belldi@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_MPIPL_EX_CLEANUP_H_
#define _PROC_MPIPL_EX_CLEANUP_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>
#include <vector>

//------------------------------------------------------------------------------
// Structure Definition(s)
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*proc_mpipl_ex_cleanup_FP_t) (const fapi::Target &);

extern "C"
{
  /**
  * @brief Undo step that prepared fast-winkled cores for scanning and set up deep winkle mode
  *
  * @param[in] (1) 'i_target' Reference to chip target
  *
  * @return ReturnCode
  *
  *
  */
  fapi::ReturnCode proc_mpipl_ex_cleanup(const fapi::Target &i_target);
}

#endif
