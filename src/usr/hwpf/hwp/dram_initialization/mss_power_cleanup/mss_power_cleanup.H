/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/mss_power_cleanup/mss_power_cleanup.H $ */
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
// $Id: mss_power_cleanup.H,v 1.3 2014/02/19 13:41:35 bellows Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_power_cleanup.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_power_cleanup.H
// *! DESCRIPTION : Header file for mss_eff_config.
// *! OWNER NAME  : Mark Bellows      Email: bellows@us.ibm.com
// *! BACKUP NAME : Anuwat Saetow     Email: asaetow@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
//
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.3   | bellows  |19-FEB-14| RAS Review Updates
//   1.2   |bellows   |11-Nov-13| Gerrit Review Comments
//   1.1   |bellows   |07-Nov-13| copied from mss_cnfg_cleanup.H version 1.2
//------------------------------------------------------------------------------


#ifndef mss_power_cleanup_H_
#define mss_power_cleanup_H_

//------------------------------------------------------------------------------
// My Includes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>

typedef fapi::ReturnCode (*mss_power_cleanup_FP_t)(const fapi::Target & i_target_centaur,
                                                  const fapi::Target & i_target_mba0, const fapi::Target & i_target_mba1);
typedef fapi::ReturnCode (*mss_power_cleanup_mba_FP_t)( const fapi::Target & i_target_mba);

extern "C" {

//------------------------------------------------------------------------------
// @brief mss_power_cleanup(): Clean up a centaur and also MBAs, also calls the mba cleanup under the covers
//
// @param const fapi::Target i_target_centaur: the centaur
// @param const fapi::Target i_target_mba0: the mba0 
// @param const fapi::Target i_target_mba1: the mba1
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------
fapi::ReturnCode mss_power_cleanup(const fapi::Target & i_target_centaur,
                                                  const fapi::Target & i_target_mba0, const fapi::Target & i_target_mba1);
//------------------------------------------------------------------------------
// @brief mss_power_cleanup_mba(): Clean up a centaur and also MBAs
//
// @param const fapi::Target i_target_mba0: the mba0 
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------
fapi::ReturnCode mss_power_cleanup_mba(const fapi::Target & i_target_mba); // clean up an mba

fapi::ReturnCode mss_power_cleanup_centaur(const fapi::Target & i_target_centaur);
fapi::ReturnCode mss_power_cleanup_mba_part1(const fapi::Target & i_target_centaur, const fapi::Target & i_target_mba);
fapi::ReturnCode mss_power_cleanup_mba_fence(const fapi::Target & i_target_centaur, const fapi::Target & i_target_mba0, const fapi::Target & i_target_mba1 );



} // extern "C"

#endif // mss_power_cleanup_H

