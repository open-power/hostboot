/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_util_to_throttle.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
// $Id: mss_util_to_throttle.H,v 1.2 2013/11/07 20:39:38 pardeik Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/
//          centaur/working/procedures/ipl/fapi/mss_util_to_throttle.H,v $
//------------------------------------------------------------------------------
// *! TITLE       : mss_util_to_throttle.H
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Michael Pardeik   Email: pardeik@us.ibm.com
// *! BACKUP NAME : Mark Bellows Email:  bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// Header file for mss_util_to_throttle.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.2   | pardeik  |07-NOV-13| gerrit review updates
//   1.1   | pardeik  |06-OCT-13| First Draft.



#ifndef MSS_UTIL_TO_THROTTLE_H_
#define MSS_UTIL_TO_THROTTLE_H_

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapi.H>

typedef fapi::ReturnCode (*mss_util_to_throttle_FP_t)(const fapi::Target &);

extern "C"
{

//------------------------------------------------------------------------------
// @brief mss_util_to_throttle(): This function will determine the minimum
// N throttle settings for N/M throttling given a dram data bus utilization
// and update the attribute ATTR_MSS_UTIL_N_PER_MBA with the result
//
// @param[in]	const fapi::Target &i_target_mba:  MBA Target
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------

    fapi::ReturnCode mss_util_to_throttle(const fapi::Target & i_target_mba);

} // extern "C"

#endif // MSS_UTIL_TO_THROTTLE_H_
