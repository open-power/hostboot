/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_volt/mss_count_active_centaurs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
// $Id: mss_count_active_centaurs.C,v 1.1 2014/06/16 16:06:23 dcadiga Exp $
/* File mss_volt_vpp_offset.C created by Stephen Glancy on Tue 20 May 2014. */

//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2007
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE : mss_volt_vpp_offset.C
// *! DESCRIPTION : Tools for centaur procedures
// *! OWNER NAME :   Stephen Glancy (sglancy@us.ibm.com)
// *! BACKUP NAME :  Jacob Sloat (jdsloat@us.ibm.com)
// #! ADDITIONAL COMMENTS :
//
// General purpose funcs

//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:   | Comment:
//---------|----------|----------|-----------------------------------------------
//  1.1    | sglancy  | 05/20/14 | File created

// This procedure takes a vector of Centaurs and finds the total number of active and inactive centaurs


//----------------------------------------------------------------------
//  Includes - FAPI
//----------------------------------------------------------------------
#include <fapi.H>
#include <mss_count_active_centaurs.H>

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------


fapi::ReturnCode mss_count_active_centaurs(std::vector<fapi::Target> & i_targets, uint32_t & var_num_active_centaur, uint32_t &var_num_inactive_centaur)
{
    fapi::ReturnCode l_rc;
    //sets up the variables
    uint8_t is_functional = 0;
    var_num_active_centaur = 0;
    var_num_inactive_centaur = 0;
    
    //loops through and generates the counts
    for(uint32_t i=0;i<i_targets.size();i++) {
       //gets the functional attribute to check for an active centaur
       l_rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL,&i_targets[i],is_functional);
       
       //found an error
       if(l_rc) return l_rc;
       
       //found an active centaur
       if(is_functional == fapi::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL) {
           var_num_active_centaur++;
       }
       //centaur must be inactive
       else  {
           var_num_inactive_centaur++;
       }
    }
    
    //debug print
    FAPI_INF("RETURNING ACTIVE: %d INACTIVE: %d\n",var_num_active_centaur,var_num_inactive_centaur);
    
    //return
    return l_rc;
}
