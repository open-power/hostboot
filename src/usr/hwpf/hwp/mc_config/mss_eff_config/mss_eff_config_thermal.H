/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_eff_config_thermal.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// $Id: mss_eff_config_thermal.H,v 1.5 2012/12/12 20:10:37 pardeik Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/
//          centaur/working/procedures/ipl/fapi/mss_eff_config_thermal.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
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
//   1.5   | pardeik  |03-DEC-12| update lines to have a max width of 80 chars
//         |          |         | removed variable names in typedef
//   1.4   | pardeik  |11-OCT-12| change i_target to i_target_mba
//   1.3   | pardeik  |03-APR-12| use mba target instead of mbs
//   1.2   | pardeik  |26-MAR-12| Removed structure (going into .C file)
//         | pardeik  |01-DEC-11| Added structures and defines
//   1.1   | asaetow  |03-NOV-11| First Draft.


#ifndef MSS_EFF_CONFIG_THERMAL_H_
#define MSS_EFF_CONFIG_THERMAL_H_

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapi.H>

typedef fapi::ReturnCode (*mss_eff_config_thermal_FP_t)
(
 const fapi::Target &
 );


extern "C" {
//------------------------------------------------------------------------------
// @brief mss_eff_config_thermal procedure. Sets up dimm power curve attributes
//  and dimm and channel throttle attributes
//
// @param[in]  i_target_mba  Reference to centaur mba target
//
// @return ReturnCode
//------------------------------------------------------------------------------

    fapi::ReturnCode mss_eff_config_thermal(const fapi::Target & i_target_mba);

} //extern C

#endif // MSS_EFF_CONFIG_THERMAL_H_
