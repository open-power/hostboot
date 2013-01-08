/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_throttle_to_power.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
// $Id: mss_throttle_to_power.H,v 1.4 2012/12/12 20:10:50 pardeik Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/
//          centaur/working/procedures/ipl/fapi/mss_throttle_to_power.H,v $
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
// Header file for mss_throttle_to_power.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.4   | pardeik  |04-DEC-12| update lines to have a max width of 80 chars
//         |          |         | removed variable names in typedef's
//   1.3   | pardeik  |11-OCT-12| change i_target to i_target_mba
//   1.2   | pardeik  |03-APR-12| use mba target instead of mbs
//   1.1   | pardeik  |01-DEC-11| First Draft.



#ifndef MSS_THROTTLE_TO_POWER_H_
#define MSS_THROTTLE_TO_POWER_H_

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapi.H>

typedef fapi::ReturnCode (*mss_throttle_to_power_FP_t)(const fapi::Target &);

typedef fapi::ReturnCode (*mss_throttle_to_power_calc_FP_t)
(
 const fapi::Target &,
 uint32_t,
 uint32_t,
 uint32_t,
 float &
 );

extern "C"
{

//------------------------------------------------------------------------------
// @brief mss_throttle_to_power(): This function will get the throttle
// attributes and call another function to determine the dimm and channel pair
// power based on those throttles
//
// @param[in]	const fapi::Target &i_target_mba:  MBA Target
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------

    fapi::ReturnCode mss_throttle_to_power(const fapi::Target & i_target_mba);

//------------------------------------------------------------------------------
// @brief mss_throttle_to_power_calc(): This function will calculate the dimm
// and channel pair power and update attributes with the power values
//
// @param[in]   const fapi::Target &i_target_mba:  MBA Target
// @param[in]   uint32_t i_throttle_n_per_mba:  Throttle value for
//              cfg_nm_n_per_mba
// @param[in]   uint32_t i_throttle_n_per_chip:  Throttle value for
//              cfg_nm_n_per_chip
// @param[in]   uint32_t i_throttle_d:  Throttle value for cfg_nm_m
// @param[out]	float &o_channel_pair_power:  channel pair power at these
//              throttle settings
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------

    fapi::ReturnCode mss_throttle_to_power_calc
      (
       const fapi::Target &i_target_mba,
       uint32_t i_throttle_n_per_mba,
       uint32_t i_throttle_n_per_chip,
       uint32_t i_throttle_d,
       float &channel_pair_power
       );

} // extern "C"

#endif // MSS_THROTTLE_TO_POWER_H_
