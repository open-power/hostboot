/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/proc_enable_reconfig/proc_enable_reconfig.H $    */
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
// $Id: proc_enable_reconfig.H,v 1.3 2013/11/11 21:29:36 bellows Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_enable_reconfig.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2013
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
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

typedef fapi::ReturnCode (*proc_enable_reconfig_FP_t)(fapi::Target &  i_target_pu_mcs, fapi::Target &  i_target_cen);

extern "C"
{
  using namespace fapi;

  CONST_UINT64_T( CENTAUR_MBI_CFG_0x0201080A                     , ULL(0x0201080A) );
  CONST_UINT64_T( CENTAUR_MBI_FIR_0x02010800                     , ULL(0x02010800) );
  CONST_UINT64_T( CENTAUR_MBI_CRCSYN_0x0201080C                  , ULL(0x0201080C) );
  CONST_UINT64_T( CENTAUR_CEN_DMIFIR_0x02010400                  , ULL(0x02010400) );

/**
 * @brief proc_clear_firs procedure. Turn off FIR spreading and causes a channel fail
 *
 * @param[in]   std::vector<fapi::Target> i_target_mcs,  // an MCS with an attached centaur
 * @param[in]   std::vector<fapi::Target> i_target_cen,  // The associated centaur
 *
 * @return ReturnCode
 */

  ReturnCode proc_enable_reconfig(fapi::Target &  i_target_pu_mcs, fapi::Target &  i_target_cen);

} // extern "C"

#endif
