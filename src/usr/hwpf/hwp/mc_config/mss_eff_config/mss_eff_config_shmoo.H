/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_eff_config_shmoo.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: mss_eff_config_shmoo.H,v 1.1 2013/02/26 12:38:36 lapietra Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_eff_config_shmoo.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_eff_config_shmoo.H
// *! DESCRIPTION : Header file for mss_eff_config_shmoo.C
// *! OWNER NAME  : Saurabh Chadha    Email: sauchadh@in.ibm.com 
// *! BACKUP NAME :                   Email: 
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
//   1.1   | sauchadh |26-Feb-13| First Draft


#ifndef MSS_EFF_CONFIG_SHMOO_H_
#define MSS_EFF_CONFIG_SHMOO_H_

//----------------------------------------------------------------------
//  My Includes
//----------------------------------------------------------------------


//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi.H>


typedef fapi::ReturnCode (*mss_eff_config_shmoo_FP_t)(const fapi::Target i_target_mba);

extern "C" {

//******************************************************************************
//* name=mss_eff_config_shmoo, param=i_target_mba, return=ReturnCode
//******************************************************************************
fapi::ReturnCode mss_eff_config_shmoo(const fapi::Target i_target_mba);

} // extern "C"

#endif // MSS_EFF_CONFIG_SHMOO_H_
