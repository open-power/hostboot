/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_dimm_power_test/mss_dimm_power_test.H $ */
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
// $Id: mss_dimm_power_test.H,v 1.1 2013/04/18 14:14:50 joabhend Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_dimm_power_test.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_throttle_to_power.H
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Joab Henderson    Email: joabhend@us.ibm.com
// *! BACKUP NAME : Michael Pardeik   Email: pardeik@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// Header file for mss_dimm_power_test.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.1   | joabhend |04-APR-13| First Draft.



#ifndef MSS_DIMM_POWER_TEST_H_
#define MSS_DIMM_POWER_TEST_H_

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi.H>

//----------------------------------------------------------------------
//  Defines
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  ENUMs
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Data Types
//----------------------------------------------------------------------

typedef fapi::ReturnCode (*mss_dimm_power_test_FP_t)(const fapi::Target & i_target);

extern "C"
{

/**
 * @brief mss_dimm_power_test procedure. Run power test on ISDIMMs to determine max power draw
 *
 * @param[in]  i_target  Reference to centaur.mba target
 *
 * @return ReturnCode
 */

    fapi::ReturnCode mss_dimm_power_test(const fapi::Target & i_target);

} // extern "C"

#endif // MSS_DIMM_POWER_TEST_H_
