/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/host_mpipl_service/proc_mpipl_chip_cleanup.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
// $Id: proc_mpipl_chip_cleanup.H,v 1.3 2014/03/02 23:16:17 belldi Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_mpipl_chip_cleanup.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
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
