/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/host_mpipl_service/proc_mpipl_chip_cleanup.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: proc_mpipl_chip_cleanup.H,v 1.3 2014/03/02 23:16:17 belldi Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_mpipl_chip_cleanup.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_mpipl_chip_cleanup.H
// *! DESCRIPTION : To enable MCD recovery
// *!
// *! OWNER  NAME  : Dion Bell                Email: belldi@us.ibm.com
// *! BACKUP NAME  : Dion Bell                Email: belldi@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_MPIPL_CHIP_CLEANUP_H_
#define _PROC_MPIPL_CHIP_CLEANUP_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>

//------------------------------------------------------------------------------
// Structure Definition(s)
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*proc_mpipl_chip_cleanup_FP_t) (const fapi::Target &);

extern "C"
{
  /**
  * @brief To enable MCD recovery
  *
  * @param[in] (1) 'i_target' Reference to processor chip target
  *
  * @return ReturnCode
  *
  *
  */
  fapi::ReturnCode proc_mpipl_chip_cleanup(const fapi::Target & i_target);



} //extern "C"

#endif
