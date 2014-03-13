/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_attr_cleanup/mss_attr_cleanup.H $ */
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
// $Id: mss_attr_cleanup.H,v 1.3 2014/02/19 13:41:26 bellows Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_attr_cleanup.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2013
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_attr_cleanup.H
// *! DESCRIPTION : Header file for mss_attr_cleanup.
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
//   1.2   | bellows  |11-NOV-13| Gerrit Review Comments
//   1.1   | bellows  |13-JUN-13| First Draft
//------------------------------------------------------------------------------


#ifndef MSS_ATTR_CLEANUP_H_
#define MSS_ATTR_CLEANUP_H_

//------------------------------------------------------------------------------
// My Includes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>

typedef fapi::ReturnCode (*mss_attr_cleanup_FP_t)(const fapi::Target & i_target_centaur,
                                                  const fapi::Target & i_target_mba0, const fapi::Target & i_target_mba1);

extern "C" {

//------------------------------------------------------------------------------
// @brief mss_attr_cleanup(): Clean up attributes of a centaur and also MBAs, 
//
// @param const fapi::Target i_target_centaur: the centaur
// @param const fapi::Target i_target_mba0: the mba0 
// @param const fapi::Target i_target_mba1: the mba1
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------
fapi::ReturnCode mss_attr_cleanup(const fapi::Target & i_target_centaur,
                                                  const fapi::Target & i_target_mba0, const fapi::Target & i_target_mba1);


fapi::ReturnCode mss_attr_cleanup_mba_attributes(const fapi::Target & i_target_mba);
} // extern "C"

#endif // MSS_ATTR_CLEANUP_H

