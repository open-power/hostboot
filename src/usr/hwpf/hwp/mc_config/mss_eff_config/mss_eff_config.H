/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_eff_config.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: mss_eff_config.H,v 1.3 2012/09/25 17:58:36 mjjones Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur
//          /working/procedures/ipl/fapi/mss_eff_config.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_eff_config.H
// *! DESCRIPTION : Header file for mss_eff_config.
// *! OWNER NAME  : Anuwat Saetow     Email: asaetow@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
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
//   1.4   |          |         |
//   1.3   | kjpower  |27-AUG_12| Restructured code, added modularity
//   1.2   | asaetow  |14-FEB-12| Fixed "fapi::" for hostboot, added "const",
//         |          |         | renamed "i_target_mba", and changed comments.
//   1.1   | asaetow  |03-NOV-11| First Draft.
//------------------------------------------------------------------------------


#ifndef MSS_EFF_CONFIG_H_
#define MSS_EFF_CONFIG_H_

//------------------------------------------------------------------------------
// My Includes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>

typedef fapi::ReturnCode (*mss_eff_config_FP_t)(const fapi::Target i_target_mba);

extern "C" {

//------------------------------------------------------------------------------
// @brief mss_eff_config(): This function is the main functionw which calls
//                          helper functions that read and verify spd data as
//                          well as configure effective attributes.
//
// @param const fapi::Target i_target_mba: the fapi target
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------
fapi::ReturnCode mss_eff_config(const fapi::Target i_target_mba);

} // extern "C"

#endif // MSS_EFF_CONFIG_H

