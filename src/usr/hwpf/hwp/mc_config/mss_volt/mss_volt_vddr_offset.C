/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_volt/mss_volt_vddr_offset.C $  */
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
// $Id: mss_volt_vddr_offset.C,v 1.10 2014/06/25 21:04:50 dcadiga Exp $
/* File mss_volt_vddr_offset.C created by Stephen Glancy on Tue 20 May 2014. */

//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2007
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE : mss_volt_vddr_offset.C
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
//  1.10   | sglancy  | 06/25/14 | Fixed targetting bug
//  1.9    | sglancy  | 06/25/14 | Removed all references to EFF attributes
//  1.8    | sglancy  | 06/25/14 | Commented out DRAM_GEN checking section of the code and forced it to default DDR3 - WILL UPDATE TO CHECK THE DRAM GENERATIONS FOR FUTURE CODE GENERATIONS
//  1.7    | sglancy  | 06/24/14 | Fixed bugs associated with empty returns from fapiGetChildChiplets
//  1.6    | sglancy  | 06/18/14 | Updated to add more debug information into error
//  1.5    | sglancy  | 06/09/14 | Updated to change output attribute name and update debug statements
//  1.4    | sglancy  | 06/04/14 | Updated to include output attribute
//  1.3    | sglancy  | 05/30/14 | Formatted code
//  1.2    | sglancy  | 05/29/14 | Fixed attributes units and equations
//  1.1    | sglancy  | 05/20/14 | File created

// This procedure takes a vector of Centaurs behind the vddr voltage domain,
// reads in supported DIMM voltages from SPD and determines optimal
//  voltage bin for the DIMM voltage domain.
// supported voltage bins:  DDR3 1.35V DDR4 1.20V


//----------------------------------------------------------------------
//  Includes - FAPI
//----------------------------------------------------------------------
#include <fapi.H>
#include <mss_volt_vddr_offset.H>
#include <mss_count_active_centaurs.H>
 
//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------


fapi::ReturnCode mss_volt_vddr_offset(std::vector<fapi::Target> & i_targets)
{
    
    //declares variables
    fapi::ReturnCode l_rc;
    uint32_t vpd_master_power_slope, vpd_master_power_intercept, volt_util_active, volt_util_inactive, volt_slope, volt_intercept;
    uint32_t var_power_on_vddr = 0;
    uint32_t data_bus_util;
    uint32_t num_logical_dimms;
    uint8_t dram_gen =  fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR3; //, cur_dram_gen; WILL BE UNCOMMENTED IN A FUTURE RELEASE - need to fix the checking for the DRAM technology generation section of the code   
    //bool dram_gen_found = false;
    uint8_t enable, is_functional;
    uint8_t percent_uplift;
    std::vector<fapi::Target>  l_mbaChiplets;
    std::vector<fapi::Target>  l_dimm_targets;

    /*
    ///////////////////////// WILL BE UNCOMMENTED IN A FUTURE RELEASE - need to fix the checking for the DRAM technology generation section of the code    
    //gets the attributes and computes var_power_on based upon whether the DRAM type is DDR3 or DDR4
    l_rc=fapiGetChildChiplets(i_targets[0], fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets, fapi::TARGET_STATE_PRESENT);
    if(l_rc) return l_rc;
    l_rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN,&l_mbaChiplets[0],dram_gen); 
    if(l_rc) return l_rc;
    
    //checks to make sure that all of the DRAM generation attributes are the same, if not error out
    for(uint32_t i = 0; i < i_targets.size();i++) {
       //gets the functional attribute to check for an active centaur
       l_rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL,&i_targets[i],is_functional);
       //found an error
       if(l_rc) return l_rc;
       
       //loops through all MBA chiplets to compare the DRAM technology generation attribute
       l_mbaChiplets.clear();
       l_rc=fapiGetChildChiplets(i_targets[i], fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets, fapi::TARGET_STATE_PRESENT);
       for(uint32_t j=0;j<l_mbaChiplets.size();j++) {
          //gets the dimm level target
          l_dimm_targets.clear();
          //gets the number of declared dimms
	  l_rc = fapiGetAssociatedDimms(l_mbaChiplets[i], l_dimm_targets);
	  for(uint32_t dimm=0;dimm<l_dimm_targets.size();dimm++) {
	     //gets the attributes and computes var_power_on based upon whether the DRAM type is DDR3 or DDR4
             l_rc = FAPI_ATTR_GET(ATTR_SPD_DRAM_GEN,&l_mbaChiplets[j],cur_dram_gen); 
	     //found an error reading the VPD
	     if(l_rc) {
	        //if the dimm is non-functional, assume that it's bad VPD was the reason that it crashed, then log an error and exit out
	        if()
		//otherwise, just return the error code
		return l_rc;
	     }
	     return l_rc;
	  }
	  
          //gets the attributes and computes var_power_on based upon whether the DRAM type is DDR3 or DDR4
          l_rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN,&l_mbaChiplets[j],cur_dram_gen); 
	  if(l_rc) return l_rc;
          //values are not equal -> set the fapi RC and exit out
          if(cur_dram_gen != dram_gen){
             // this just needs to be deconfiged at the dimm level
             const fapi::Target & CHIP_TARGET = i_targets[i];
             const uint8_t &DRAM_GEN_MISCOMPARE = cur_dram_gen;
             const uint8_t &DRAM_GEN_START = dram_gen;
             const uint32_t &CEN_MBA_NUM = j;
             const uint32_t &CEN_TARGET_NUM = i;
             FAPI_SET_HWP_ERROR(l_rc, RC_MSS_VOLT_VDDR_OFFSET_DRAM_GEN_MISCOMPARE);
             FAPI_ERR("Not all DRAM technology generations are the same.\nExiting....");
             if(l_rc) return l_rc;
          }//end if
       }//end for
    }//end for
    */
    
    //voltage should not be updated if the disable is set
    l_rc = FAPI_ATTR_GET(ATTR_MSS_VDDR_OFFSET_DISABLE,NULL,enable); 
    //error check
    if(l_rc) return l_rc;
    if(enable == fapi::ENUM_ATTR_MSS_VDDR_OFFSET_DISABLE_DISABLE){
       FAPI_INF("ATTR_MSS_VDDR_OFFSET_DISABLE is set to be disabled. Exiting....., %d",enable);
       return l_rc;
    }
    
    //gets the attributes and computes var_power_on based upon whether the DRAM type is DDR3 or DDR4
    if(dram_gen == fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR3) {
       l_rc = FAPI_ATTR_GET(ATTR_MSS_DDR3_VDDR_SLOPE,NULL,volt_slope); 
       if(l_rc) return l_rc;
       l_rc = FAPI_ATTR_GET(ATTR_MSS_DDR3_VDDR_INTERCEPT,NULL,volt_intercept); 
       if(l_rc) return l_rc;
    }
    //ddr4
    else {
       l_rc = FAPI_ATTR_GET(ATTR_MSS_DDR4_VDDR_SLOPE,NULL,volt_slope); 
       if(l_rc) return l_rc;
       l_rc = FAPI_ATTR_GET(ATTR_MSS_DDR4_VDDR_INTERCEPT,NULL,volt_intercept); 
       if(l_rc) return l_rc;
    }
    
    //computes the active an inactive attribute values
    l_rc = FAPI_ATTR_GET(ATTR_MRW_MAX_DRAM_DATABUS_UTIL,NULL,data_bus_util); 
    if(l_rc) return l_rc;
    l_rc = FAPI_ATTR_GET(ATTR_MRW_DIMM_POWER_CURVE_PERCENT_UPLIFT,NULL,percent_uplift); 
    if(l_rc) return l_rc;
    volt_util_active = data_bus_util;
    volt_util_inactive = 0;
    
    //checks to make sure that none of the values that were read or computed were set to zeros.  If any of the values are 0's then 0 * any other value = 0
    if((volt_util_active * volt_slope * volt_intercept) == 0) {
       const uint32_t &VDDR_SLOPE_ACTIVE = volt_util_active;
       const uint32_t &VDDR_SLOPE_INACTIVE = volt_slope;
       const uint32_t &VDDR_SLOPE_INTERCEPT = volt_intercept;
       FAPI_SET_HWP_ERROR(l_rc, RC_MSS_VOLT_VDDR_OFFSET_VALUE_ERROR);
       FAPI_ERR("One or more dynamic VDD attributes is 0.\nExiting....");
       return l_rc;
    }
    
    //debug print
    FAPI_INF("data_bus_util %d per 10k volt_util_active: %d per 10k volt_util_inactive: %d per 10k",data_bus_util,volt_util_active,volt_util_inactive);

    //computes the preliminary VDDR value
    for(uint32_t i=0;i<i_targets.size();i++) {
       //gets the power slope values and does error checks
       l_rc = FAPI_ATTR_GET(ATTR_CDIMM_VPD_MASTER_POWER_SLOPE,&i_targets[i],vpd_master_power_slope); 
       if(l_rc) return l_rc;
       l_rc = FAPI_ATTR_GET(ATTR_CDIMM_VPD_MASTER_POWER_INTERCEPT,&i_targets[i],vpd_master_power_intercept); 
       if(l_rc) return l_rc;
       
       //removes leading bits from the VPD MASTER POWER attributes, leaving only the values needed for the power calculations
       vpd_master_power_slope &= 0x1FFF;
       vpd_master_power_intercept &= 0x1FFF;
       
       //checks to make sure that the attribute values are non-zero
       if((vpd_master_power_slope * vpd_master_power_intercept) == 0 ) {
          const fapi::Target & CHIP_TARGET = i_targets[i]; 
          const uint32_t &VPD_MASTER_POWER_SLOPE = vpd_master_power_slope;
          const uint32_t &VPD_MASTER_POWER_INTERCEPT = vpd_master_power_intercept;
	  const uint32_t &CEN_TARGET_NUM = i;
          FAPI_SET_HWP_ERROR(l_rc, RC_MSS_VOLT_VDDR_OFFSET_VPD_VALUE_ERROR);
          FAPI_ERR("One or more VPD Power slope attributes is 0.\nExiting....");
          return l_rc;
       }
       
       //gets the functional attribute to check for an active centaur
       l_rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL,&i_targets[i],is_functional);
       //found an error
       if(l_rc) return l_rc;
       
       //loops through all MBA chiplets to compare the compute the total number of logical dimms on a dimm
       l_mbaChiplets.clear();
       l_rc=fapiGetChildChiplets(i_targets[i], fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets, fapi::TARGET_STATE_PRESENT);
       num_logical_dimms = 0;
       for(uint32_t mba=0;mba<l_mbaChiplets.size();mba++) {
          l_dimm_targets.clear();
          //gets the number of declared dimms
	   l_rc = fapiGetAssociatedDimms(l_mbaChiplets[mba], l_dimm_targets);
	  if(l_rc) return l_rc;
	  num_logical_dimms += l_dimm_targets.size();
       }//end for
       
       //found an active centaur
       //multiply by total number of active logical dimms
       if(is_functional == fapi::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL) {
           var_power_on_vddr += (vpd_master_power_slope*volt_util_active/10000+vpd_master_power_intercept)*num_logical_dimms;
	   FAPI_INF("var_power_on_vddr: %d cW vpd_master_power_slope: %d cW volt_util_active: %d per 10k vpd_master_power_intercept %d cW num_logical_dimms %d",var_power_on_vddr,vpd_master_power_slope,volt_util_active,vpd_master_power_intercept,num_logical_dimms);
       }
       //centaur must be inactive
       else  {
           var_power_on_vddr += (vpd_master_power_slope*volt_util_inactive/10000+vpd_master_power_intercept)*num_logical_dimms;
	   FAPI_INF("var_power_on_vddr: %d cW vpd_master_power_slope: %d cW volt_util_inactive: %d per 10k vpd_master_power_intercept %d cW num_logical_dimms %d",var_power_on_vddr,vpd_master_power_slope,volt_util_inactive,vpd_master_power_intercept,num_logical_dimms);
       }
    }//end for
    
    //debug print
    FAPI_INF("var_power_on_vddr: %d cW percent_uplift: %d %%",var_power_on_vddr,percent_uplift);
    //does computes the uplift
    var_power_on_vddr = ((100 + percent_uplift) * var_power_on_vddr) / 100;
    
    //debug print
    FAPI_INF("var_power_on_vddr: %d cW volt_slope: %d uV/W volt_intercept: %d mV",var_power_on_vddr,volt_slope,volt_intercept);
    
    //computes and converts the voltage offset into mV
    uint32_t param_vddr_voltage_mv = (500 + var_power_on_vddr*volt_slope/100) / 1000 + volt_intercept;
    FAPI_INF("param_vddr_voltage_mv: %d mV",param_vddr_voltage_mv);
    //prints a debug statement
    if(dram_gen == fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR3) {
       FAPI_INF("ATTR_MSS_DDR3_VDDR_OFFSET: %d mV",param_vddr_voltage_mv);
    }
    else {
       FAPI_INF("ATTR_MSS_DDR4_VDDR_OFFSET: %d mV",param_vddr_voltage_mv);
    }
    
    //sets the output attributes
    for(uint32_t i = 0; i< i_targets.size();i++) {
       l_rc = FAPI_ATTR_SET(ATTR_MSS_VDDR_OFFSET,&i_targets[i],param_vddr_voltage_mv); 
       if(l_rc) return l_rc;
    }//end for 
    
    return l_rc;
}
