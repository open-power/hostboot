/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/proc_prep_master_winkle/proc_prep_master_winkle.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: proc_prep_master_winkle.H,v 1.9 2014/02/10 04:51:32 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_prep_master_winkle.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_prep_master_winkle.H
// *! DESCRIPTION : Prepares for the master core to winkle
// *!
// *! OWNER NAME  : Greg Still              Email: stillgs@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_PREP_MASTER_WINKLE_H_
#define _PROC_PREP_MASTER_WINKLE_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*proc_prep_master_winkle_FP_t)(const fapi::Target &,
                                                         const bool &);

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------


extern "C"
{

/**
 * @brief Start the auto-POR engine and the SBE
 *
 * @param[in] i_ex_target  Reference to master chiplet target
 * @param[in] i_useRealSBE True if proc_sbe_trigger_winkle is supposed to be
 *                         running on the real SBE (usually true), else
 *                         false if proc_sbe_trigger_winkle is running on
 *                         the FSP (via poreve).
 *
 * @return ReturnCode
 */
  fapi::ReturnCode proc_prep_master_winkle(const fapi::Target & i_ex_target,
                                           const bool & i_useRealSBE);

} // extern "C"

#endif // _PROC_PREP_MASTER_WINKLE_H_
