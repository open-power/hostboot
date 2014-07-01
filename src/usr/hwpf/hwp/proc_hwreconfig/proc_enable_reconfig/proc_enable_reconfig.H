/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/proc_hwreconfig/proc_enable_reconfig/proc_enable_reconfig.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
// $Id: proc_enable_reconfig.H,v 1.6 2014/06/20 18:58:18 steffen Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_enable_reconfig.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2013
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *!  Licensed material - Program property of IBM
// *!  Refer to copyright instructions form no. G120-2083
// *! Created on Thu Oct 31 2013 at 15:39:28
//------------------------------------------------------------------------------
// *! TITLE       : proc_enable_reconfig
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  :  Bellows Mark   Email: bellows@us.ibm.com
// *! BACKUP NAME :                 Email: ______@us.ibm.com

// *! ADDITIONAL COMMENTS :
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.3   | bellows  |11-NOV-13| Fixed obsolete comment from when it was part of proc_prep_for_reconfig
//   1.2   | bellows  |08-NOV-13| Simplified
//   1.1   | bellows  |07-NOV-13| Created from proc_prep_for_reconfig
#ifndef __proc_enable_reconfig_H
#define __proc_enable_reconfig_H

#include <fapi.H>
#include <p8_scom_addresses.H>
#include "io_clear_firs.H"

  using namespace fapi;

	CONST_UINT64_T( CENTAUR_MBI_CFG_0x0201080A                     , ULL(0x0201080A) );
	CONST_UINT64_T( CENTAUR_MBI_FIR_0x02010800                     , ULL(0x02010800) );
	CONST_UINT64_T( CENTAUR_MBI_CRCSYN_0x0201080C                  , ULL(0x0201080C) );
	CONST_UINT64_T( CENTAUR_CEN_DMIFIR_0x02010400                  , ULL(0x02010400) );

typedef fapi::ReturnCode (*proc_enable_reconfig_FP_t)(fapi::Target & i_target_pu_mcs);

extern "C"
{

/**
 * @brief proc_enable_reconfig procedure. Reset memory controller to known state which includes masking/clearing FIRs, causing a channel fails, and global resetting the memory controller and gcr ring.
 *
 * @param[in]   fapi::Target i_target_mcs,  // an MCS with an attached centaur
 *
 * @return ReturnCode
 */

  ReturnCode proc_enable_reconfig(fapi::Target & i_target_pu_mcs);

} // extern "C"

#endif
