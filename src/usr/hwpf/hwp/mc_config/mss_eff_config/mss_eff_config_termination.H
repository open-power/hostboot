/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_eff_config_termination.H $ */
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
// $Id: mss_eff_config_termination.H,v 1.3 2014/03/05 21:16:57 dcadiga Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_eff_config_termination.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_eff_config_termination.H
// *! DESCRIPTION : Header file for mss_eff_config_termination.
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
//   1.4   | dcadiga  |05-MAR-14|Added term vpd
//   1.3   |          |         |
//   1.2   | asaetow  |22-JAN-14| Fixed target "const fapi::Target" to "const fapi::Target&" for mss_eff_config.C v1.38 and mss_eff_config_termination.C v1.42
//   1.1   | asaetow  |25-APR-12| First Draft.


#ifndef MSS_EFF_CONFIG_TERMINATION_H_
#define MSS_EFF_CONFIG_TERMINATION_H_

//----------------------------------------------------------------------
//  My Includes
//----------------------------------------------------------------------


//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi.H>


typedef fapi::ReturnCode (*mss_eff_config_termination_FP_t)(const fapi::Target& i_target_mba);

extern "C" {

//******************************************************************************
//* name=mss_eff_config_termination, param=i_target_mba, return=ReturnCode
//******************************************************************************
fapi::ReturnCode mss_eff_config_termination(const fapi::Target& i_target_mba);
fapi::ReturnCode mss_eff_config_termination_vpd(const fapi::Target& i_target_mba);

} // extern "C"

#endif // MSS_EFF_CONFIG_TERMINATION_H_
