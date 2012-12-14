/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_bulk_pwr_throttles.H $ */
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
// $Id: mss_bulk_pwr_throttles.H,v 1.3 2012/10/15 13:05:17 pardeik Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_bulk_pwr_throttles.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_bulk_pwr_throttles.H
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Joab Henderson    Email: joabhend@us.ibm.com
// *! BACKUP NAME : Michael Pardeik   Email: pardeik@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// Header file for mss_bulk_pwr_throttles.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.3   | pardeik  |11-OCT-12| change i_target to i_target_mba
//   1.2   | pardeik  |03-APR-12| use mba target intead of mbs
//   1.1   | pardeik  |11-NOV-11| First Draft.



#ifndef MSS_BULK_PWR_THROTTLES_H_
#define MSS_BULK_PWR_THROTTLES_H_

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi.H>

typedef fapi::ReturnCode (*mss_bulk_pwr_throttles_FP_t)(const fapi::Target & i_target_mba);

extern "C"
{
/**
 * @brief mss_bulk_pwr_throttles procedure. Set dimm and channel throttle attributes based on available centaur mba port power
 *
 * @param[in]  i_target_mba  Reference to centaur mba target
 *
 * @return ReturnCode
 */

    fapi::ReturnCode mss_bulk_pwr_throttles(const fapi::Target & i_target_mba);

} // extern "C"

#endif // MSS_BULK_PWR_THROTTLES_H_
