/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_volt/mss_volt_vdd_offset.C $   */
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
// $Id: mss_volt_vdd_offset.C,v 1.6 2014/06/18 20:34:34 dcadiga Exp $
/* File mss_volt_vdd_offset.C created by Stephen Glancy on Tue 20 May 2014. */

//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2007
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE : mss_volt_vdd_offset.C
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
//  1.6    | sglancy  | 06/18/14 | Updated error flags
//  1.5    | sglancy  | 06/09/14 | Updated debug statements
//  1.4    | sglancy  | 06/04/14 | Updated to include output attribute
//  1.3    | sglancy  | 05/30/14 | Formatted code
//  1.2    | sglancy  | 05/29/14 | Fixed attributes units and equations
//  1.1    | sglancy  | 05/20/14 | File created

// This procedure takes a vector of Centaurs behind the vdd voltage domain,
// reads in supported DIMM voltages from SPD and determines optimal
//  voltage bin for the DIMM voltage domain.
// supported voltage bins:  0.97V


//----------------------------------------------------------------------
//  Includes - FAPI
//----------------------------------------------------------------------
#include <fapi.H>
#include <mss_volt_vdd_offset.H>
#include <mss_count_active_centaurs.H>

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------


fapi::ReturnCode mss_volt_vdd_offset(std::vector<fapi::Target> & i_targets)
{
    //declares variables
    fapi::ReturnCode l_rc;
    uint32_t var_num_active_centaur   = 0;
    uint32_t var_num_inactive_centaur = 0;
    uint32_t slope_active, slope_inactive, intercept;
    uint8_t enable;

    //voltage should not be updated if the disable is set
    l_rc = FAPI_ATTR_GET(ATTR_MSS_VDD_OFFSET_DISABLE,NULL,enable); 
    //error check
    if(l_rc) return l_rc;
    if(enable == fapi::ENUM_ATTR_MSS_VDD_OFFSET_DISABLE_DISABLE) {
       FAPI_INF("ATTR_MSS_VCS_OFFSET_DISABLE is set to be disabled. Exiting.....");
       return l_rc;
    }

    //computes vdd value
    //gets the necessary attributes and checks for errors
    l_rc = FAPI_ATTR_GET(ATTR_MSS_VDD_SLOPE_ACTIVE,NULL,slope_active); 
    if(l_rc) return l_rc;
    l_rc = FAPI_ATTR_GET(ATTR_MSS_VDD_SLOPE_INACTIVE,NULL,slope_inactive); 
    if(l_rc) return l_rc;
    l_rc = FAPI_ATTR_GET(ATTR_MSS_VDD_SLOPE_INTERCEPT,NULL,intercept); 
    if(l_rc) return l_rc;
    
    //checks to make sure that none of the values are zeros.  If any of the values are 0's then 0 * any other value = 0
    if((slope_active * slope_inactive * intercept) == 0) {
       const uint32_t &VDD_SLOPE_ACTIVE = slope_active;
       const uint32_t &VDD_SLOPE_INACTIVE = slope_inactive;
       const uint32_t &VDD_SLOPE_INTERCEPT = intercept;
       FAPI_SET_HWP_ERROR(l_rc, RC_MSS_VOLT_VDD_OFFSET_VALUE_ERROR);
       FAPI_ERR("One or more dynamic VDD attributes is 0.\nExiting....");
       return l_rc;
    }
    
    //debug print
    FAPI_INF("slope_active: %d uV/centaur slope_inactive: %d uV/centaur slope_intercept: %d mV\n",slope_active,slope_inactive,intercept);    
       
    //generates the list of active and inactive centaurs
    l_rc = mss_count_active_centaurs(i_targets, var_num_active_centaur, var_num_inactive_centaur);
    if(l_rc) return l_rc;
    FAPI_INF("var_active: %d centaurs var_inactive: %d centaurs\n",var_num_active_centaur,var_num_inactive_centaur);
        
    //computes and sets the appropriate attribute
    uint32_t param_vdd_voltage_uv =  (slope_active * var_num_active_centaur) + (slope_inactive * var_num_inactive_centaur) + 1000 * intercept;
    //rounds and converts the voltage offset into mV
    uint32_t param_vdd_voltage_mv = (500 + param_vdd_voltage_uv) / 1000;
    FAPI_INF("ATTR_MSS_VDD_OFFSET: %d mV",param_vdd_voltage_mv);
    
    //sets the output attributes
    for(uint32_t i = 0; i< i_targets.size();i++) {
       l_rc = FAPI_ATTR_SET(ATTR_MSS_VDD_OFFSET,&i_targets[i],param_vdd_voltage_mv); 
       if(l_rc) return l_rc;
    }//end for 
    
    return l_rc;
}
