/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/proc_throttle_sync/proc_throttle_sync.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: proc_throttle_sync.H,v 1.2 2013/11/25 21:13:13 bellows Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_throttle_sync.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2013
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *!  Licensed material - Program property of IBM
// *!  Refer to copyright instructions form no. G120-2083
// *! Created on Tue Nov 12 2013 at 13:42:15
//------------------------------------------------------------------------------
// *! TITLE       : proc_throttle_sync
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  :  Bellows Mark D.Email: bellows@us.ibm.com
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
//   1.2   | bellows  |25-NOV-13| Updated call to procedure
//   1.1   | bellows  |12-NOV-13| Created.
#ifndef __PROC_THROTTLE_SYNC_H
#define __PROC_THROTTLE_SYNC_H

#include <fapi.H>
#include <p8_scom_addresses.H>

typedef fapi::ReturnCode (*proc_throttle_sync_FP_t)(fapi::Target &  i_target_proc );

extern "C"
{
  using namespace fapi;

/**
 * @brief proc_throttle_sync procedure. Sync all MBA below this processor when changing thermal parameters
 *
 * @param[in]   fapi::Target i_target_proc,              // Platform runs this on each processor *
 * @return ReturnCode
 */

  ReturnCode proc_throttle_sync(fapi::Target &  i_target_proc );

} // extern "C"

#endif
