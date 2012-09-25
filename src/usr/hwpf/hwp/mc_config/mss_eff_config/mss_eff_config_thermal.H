/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_eff_config_thermal.H $ */
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
// $Id: mss_eff_config_thermal.H,v 1.3 2012/04/03 22:13:03 pardeik Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_eff_config_thermal.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_eff_config_thermal.H
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Joab Henderson    Email: joabhend@us.ibm.com
// *! BACKUP NAME : Michael Pardeik   Email: pardeik@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// Header file for mss_eff_config_thermal.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.3   | pardeik  |03-APR-12| use mba target instead of mbs
//   1.2   | pardeik  |26-MAR-12| Removed structure (going into .C file)
//         | pardeik  |01-DEC-11| Added structures and defines
//   1.1   | asaetow  |03-NOV-11| First Draft.



#ifndef MSS_EFF_CONFIG_THERMAL_H_
#define MSS_EFF_CONFIG_THERMAL_H_

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi.H>


typedef fapi::ReturnCode (*mss_eff_config_thermal_FP_t)(const fapi::Target & i_target);


extern "C" {
/**
 * @brief mss_eff_config_thermal procedure. Sets up dimm power curve attributes and dimm and channel throttle attributes
 *
 * @param[in]  i_target  Reference to centaur mba target
 *
 * @return ReturnCode
 */

    fapi::ReturnCode mss_eff_config_thermal(const fapi::Target & i_target);

} //extern C

#endif // MSS_EFF_CONFIG_THERMAL_H_
