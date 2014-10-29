/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_volt/mss_volt_vddr_offset.C $  */
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
// $Id: mss_volt_vddr_offset.C,v 1.20 2014/10/06 15:56:56 sglancy Exp $
/* File mss_volt_vddr_offset.C created by Stephen Glancy on Tue 20 May 2014. */

//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2007
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
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
//  1.20   | sglancy  | 10/06/14 | Added in checks for going over voltage limits
//  1.19   | sglancy  | 09/12/14 | Removed references to EFF attributes
//  1.18   | sglancy  | 09/11/14 | Fixed bugs and fixed typos
//  1.17   | sglancy  | 09/10/14 | Added additional checks for bad master power values
//  1.16   | sglancy  | 09/08/14 | Updated to fix FW compile and logic bugs
//  1.15   | sglancy  | 09/03/14 | Updated to go with new HWP design and added updates to code for new idle uplift attribute
//  1.14   | sglancy  | 08/27/14 | Changed code to set VDDR offset value to 0 if code is unable to read the VPD of all DIMMs, which should disable the VDDR plane
//  1.13   | sglancy  | 08/22/14 | Changed code to make the risky assumption that the box is running DDR3 if code is unable to read the VPD of all DIMMs
//  1.12   | sglancy  | 07/16/14 | Fixed attribute name bug
//  1.11   | sglancy  | 06/30/14 | Adds DDR4 support
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
    fapi::ReturnCode l_rc, bad_vpd_rc;
    uint32_t vpd_master_power_slope, vpd_master_power_intercept, volt_util_active, volt_util_inactive, volt_slope, volt_intercept;
    uint32_t good_master_power_slope, good_master_power_intercept, num_dimms_to_add;
    good_master_power_slope = good_master_power_intercept = 0;
    vpd_master_power_slope = vpd_master_power_intercept = volt_util_active = volt_util_inactive = volt_slope = volt_intercept = 0;
    uint32_t var_power_on_vddr = 0;
    uint32_t data_bus_util;
    uint32_t num_logical_dimms;
    uint8_t dram_gen , cur_dram_gen;    
    bool dram_gen_found = false;
    uint8_t enable, is_functional;
    uint8_t num_non_functional = 0;
    uint8_t percent_uplift,percent_uplift_idle;
    uint32_t vddr_max_limit_mv;
    std::vector<fapi::Target>  l_mbaChiplets;
    std::vector<fapi::Target>  l_dimm_targets;
    
    //checks to make sure that all of the DRAM generation attributes are the same, if not error out
    for(uint32_t i = 0; i < i_targets.size();i++) {
       //gets the functional attribute to check for an active centaur
       l_rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL,&i_targets[i],is_functional);
       //found an error
       if(l_rc) return l_rc;
       
       //found a non-functional DIMM, add it to the count
       if(is_functional != fapi::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL) {
          num_non_functional++;
       }
       
       //loops through all MBA chiplets to compare the DRAM technology generation attribute
       l_mbaChiplets.clear();
       l_rc=fapiGetChildChiplets(i_targets[i], fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets, fapi::TARGET_STATE_PRESENT);
       if(l_rc) return l_rc;
       for(uint32_t mba=0;mba<l_mbaChiplets.size();mba++) {
          //gets the dimm level target
          l_dimm_targets.clear();
          //gets the number of declared dimms
	  l_rc = fapiGetAssociatedDimms(l_mbaChiplets[mba], l_dimm_targets);
	  if(l_rc) return l_rc;
	  for(uint32_t dimm=0;dimm<l_dimm_targets.size();dimm++) {
	     //gets the attributes and computes var_power_on based upon whether the DRAM type is DDR3 or DDR4
             l_rc = FAPI_ATTR_GET(ATTR_SPD_DRAM_DEVICE_TYPE,&l_dimm_targets[dimm],cur_dram_gen); 
	     //found an error reading the VPD
	     if(l_rc) {
	        //if the dimm is non-functional, assume that it's bad VPD was the reason that it crashed, then skip this DIMM with a FAPI INF note
	        if(is_functional == fapi::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL) {
		   FAPI_ERR("Problem reading VPD on functional DIMM. Logging error and proceding to the next DIMM.");
		   if(bad_vpd_rc) {
	              fapiLogError(bad_vpd_rc); 
		   }
		   
		   const fapi::Target & TARGET_DIMM_ERROR = l_dimm_targets[dimm];
		   const fapi::Target & MBA_TARGET = l_mbaChiplets[mba];
		   const uint32_t MBA_POSITION = mba;
	    	   const uint32_t TARGET_POSITION = i;
	    	   const uint32_t DIMM_POSITION = dimm;
	    	   FAPI_SET_HWP_ERROR(bad_vpd_rc, RC_VDDR_FUNCTIONAL_DIMM_VPD_READ_ERROR);
		   continue;
		}
		else {
		   FAPI_INF("Problem reading VPD on non-functional DIMM. Skipping current DIMM and proceding to the next DIMM.");
		   continue;
		}
	     }
	     //if this is the first DIMM that has a valid DRAM Technology level, then set the level and continue
	     //otherwise throw an error and exit
	     if(!dram_gen_found) {
	        dram_gen = cur_dram_gen;
		dram_gen_found = true;
	     } //end if
	     else {
	        //values are not equal -> set the fapi RC and exit out
    	  	if(cur_dram_gen != dram_gen){
    	  	   // this just needs to be deconfiged at the dimm level
    	  	   const uint8_t &DRAM_GEN_MISCOMPARE = cur_dram_gen;
    	  	   const uint8_t &DRAM_GEN_START = dram_gen;
    	  	   const uint32_t &CEN_MBA_NUM = mba;
    	  	   const uint32_t &CEN_TARGET_NUM = i;
    	  	   FAPI_SET_HWP_ERROR(l_rc, RC_MSS_VOLT_VDDR_OFFSET_DRAM_GEN_MISCOMPARE);
    	  	   FAPI_ERR("Not all DRAM technology generations are the same.  Exiting....");
    	  	   return l_rc;
    	  	}//end if
	     }//end else
	  }
       }//end for
    }//end for
    
    //found a bad VPD
    if(bad_vpd_rc) {
       FAPI_ERR("Bad VPD found on a functional DIMM");
       return bad_vpd_rc;
    } 
    
    //did not find a valid DRAM generation 
    if(num_non_functional >= i_targets.size()) {
       FAPI_ERR("No functional centaurs found!  Exiting....");
       FAPI_SET_HWP_ERROR(l_rc, RC_VOLT_VDDR_FUNCTIONAL_CENTAUR_NOT_FOUND);
       return l_rc;
    } 
    
    //checks to make sure that the code actually found a dimm with a value for its dram generation. if not, exit out
    if(!dram_gen_found) {
       FAPI_ERR("No DRAM generation found!  Exiting....");
       FAPI_SET_HWP_ERROR(l_rc, RC_VOLT_VDDR_DRAM_GEN_NOT_FOUND);
       return l_rc;
    }
    
    //voltage should not be updated if the disable is set
    l_rc = FAPI_ATTR_GET(ATTR_MSS_VDDR_OFFSET_DISABLE,NULL,enable); 
    //error check
    if(l_rc) return l_rc;
    if(enable == fapi::ENUM_ATTR_MSS_VDDR_OFFSET_DISABLE_DISABLE){
       FAPI_INF("ATTR_MSS_VDDR_OFFSET_DISABLE is set to be disabled. Exiting....., %d",enable);
       return l_rc;
    }
    
    //gets the attributes and computes var_power_on based upon whether the DRAM type is DDR3 or DDR4
    if(dram_gen == fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR3) {
       l_rc = FAPI_ATTR_GET(ATTR_MSS_DDR3_VDDR_SLOPE,NULL,volt_slope); 
       if(l_rc) return l_rc;
       l_rc = FAPI_ATTR_GET(ATTR_MSS_DDR3_VDDR_INTERCEPT,NULL,volt_intercept); 
       if(l_rc) return l_rc;
       l_rc = FAPI_ATTR_GET(ATTR_MRW_DDR3_VDDR_MAX_LIMIT,NULL,vddr_max_limit_mv); 
       if(l_rc) return l_rc;
    }
    //ddr4
    else {
       l_rc = FAPI_ATTR_GET(ATTR_MSS_DDR4_VDDR_SLOPE,NULL,volt_slope); 
       if(l_rc) return l_rc;
       l_rc = FAPI_ATTR_GET(ATTR_MSS_DDR4_VDDR_INTERCEPT,NULL,volt_intercept); 
       if(l_rc) return l_rc;
       l_rc = FAPI_ATTR_GET(ATTR_MRW_DDR4_VDDR_MAX_LIMIT,NULL,vddr_max_limit_mv); 
       if(l_rc) return l_rc;
    }
    
    //computes the active an inactive attribute values
    l_rc = FAPI_ATTR_GET(ATTR_MRW_MAX_DRAM_DATABUS_UTIL,NULL,data_bus_util); 
    if(l_rc) return l_rc;
    l_rc = FAPI_ATTR_GET(ATTR_MRW_DIMM_POWER_CURVE_PERCENT_UPLIFT,NULL,percent_uplift); 
    if(l_rc) return l_rc;
    l_rc = FAPI_ATTR_GET(ATTR_MRW_DIMM_POWER_CURVE_PERCENT_UPLIFT_IDLE,NULL,percent_uplift_idle); 
    if(l_rc) return l_rc;
    volt_util_active = data_bus_util;
    volt_util_inactive = 0;
    
    //checks to make sure that none of the values that were read or computed were set to zeros.  If any of the values are 0's then 0 * any other value = 0
    if((volt_util_active * volt_slope * volt_intercept) == 0) {
       const uint32_t &VDDR_SLOPE_ACTIVE = volt_util_active;
       const uint32_t &VDDR_SLOPE_INACTIVE = volt_slope;
       const uint32_t &VDDR_SLOPE_INTERCEPT = volt_intercept;
       FAPI_SET_HWP_ERROR(l_rc, RC_MSS_VOLT_VDDR_OFFSET_VALUE_ERROR);
       FAPI_ERR("One or more dynamic VDD attributes is 0.  Exiting....");
       return l_rc;
    }
    
    //debug print
    FAPI_INF("data_bus_util %d per 10k volt_util_active: %d per 10k volt_util_inactive: %d per 10k",data_bus_util,volt_util_active,volt_util_inactive);
    
    
    num_dimms_to_add = 1;
    //computes the preliminary VDDR value
    for(uint32_t i=0;i<i_targets.size();i++) {
       //gets the functional attribute to check for an active centaur
       l_rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL,&i_targets[i],is_functional);
       //found an error
       if(l_rc) return l_rc;
       
       //gets the power slope values and does error checks if this card is functional, as it should have good VPD.  if the card is non-functional, continue using good VPD power slope values
       l_rc = FAPI_ATTR_GET(ATTR_CDIMM_VPD_MASTER_POWER_SLOPE,&i_targets[i],vpd_master_power_slope); 
       if(l_rc  && (is_functional == fapi::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL)) return l_rc;
       l_rc = FAPI_ATTR_GET(ATTR_CDIMM_VPD_MASTER_POWER_INTERCEPT,&i_targets[i],vpd_master_power_intercept); 
       if(l_rc  && (is_functional == fapi::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL)) return l_rc;
       
       //removes leading bits from the VPD MASTER POWER attributes, leaving only the values needed for the power calculations
       vpd_master_power_slope &= 0x1FFF;
       vpd_master_power_intercept &= 0x1FFF;
       
       //checks to make sure that the attribute values are non-zero - calls out all bad DIMMs
       if(((vpd_master_power_slope * vpd_master_power_intercept) == 0) && (is_functional == fapi::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL)) {
          if(bad_vpd_rc) {
	     fapiLogError(bad_vpd_rc); 
	  }
	  
	  const fapi::Target & CHIP_TARGET = i_targets[i]; 
          const uint32_t &VPD_MASTER_POWER_SLOPE = vpd_master_power_slope;
          const uint32_t &VPD_MASTER_POWER_INTERCEPT = vpd_master_power_intercept;
	  const uint32_t &CEN_TARGET_NUM = i;
          FAPI_SET_HWP_ERROR(bad_vpd_rc, RC_MSS_VOLT_VDDR_OFFSET_VPD_VALUE_ERROR);
          FAPI_ERR("One or more VPD Power slope attributes is 0.  Logging error and looking for additional bad DIMMs.");
          continue;
       }
       //one or more DIMM has already been called out, skip doing the calculation and continue to try to find bad DIMMs
       else if(bad_vpd_rc) {
          FAPI_INF("Already found a bad DIMM.  Skipping calculations on this DIMM.");
	  continue;
       }
       //has not found good master_power_slopes and has bad master power slopes
       else if(((good_master_power_slope * good_master_power_intercept) == 0)  && ((vpd_master_power_slope * vpd_master_power_intercept) == 0)) {
          num_dimms_to_add++;
	  FAPI_INF("Found bad vpd_master_power_slope or vpd_master_power_intercept values on non-functional DIMM. Program has not found good values yet, adding one more DIMM to run when good values are found. Currently going to run %d DIMMs in the next dimm.",num_dimms_to_add);
	  continue;
       }
       //found bad master power slope or power intercept but has good master power slope or intercepts
       else if(((vpd_master_power_slope * vpd_master_power_intercept) == 0) && ((good_master_power_slope * good_master_power_intercept) > 0)) {
          //uses assumed (last good master power slope and intercept) values for these calculations
	  FAPI_INF("Found bad vpd_master_power_slope or vpd_master_power_intercept values on non-functional DIMM. Program is using the last good values for the calculations for this DIMM.");
	  vpd_master_power_slope = good_master_power_slope;
	  vpd_master_power_intercept = good_master_power_intercept;
       }
       //found good master power slopes -> set the good master power slope values
       else if((vpd_master_power_slope * vpd_master_power_intercept) > 0 ){
          good_master_power_slope = vpd_master_power_slope;
	  good_master_power_intercept = vpd_master_power_intercept;
       }
       
       //loops through all MBA chiplets to compare the compute the total number of logical dimms on a dimm
       l_mbaChiplets.clear();
       l_rc=fapiGetChildChiplets(i_targets[i], fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets, fapi::TARGET_STATE_PRESENT);
       if(l_rc) return l_rc;
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
           var_power_on_vddr += num_dimms_to_add*((vpd_master_power_slope*volt_util_active/10000+vpd_master_power_intercept)*num_logical_dimms*(100+percent_uplift)/100);
	   FAPI_INF("var_power_on_vddr: %d cW vpd_master_power_slope: %d cW volt_util_active: %d per 10k vpd_master_power_intercept %d cW num_logical_dimms %d percent_uplift %d %%",var_power_on_vddr,vpd_master_power_slope,volt_util_active,vpd_master_power_intercept,num_logical_dimms,percent_uplift);
       }
       //centaur must be inactive
       else  {
           var_power_on_vddr += num_dimms_to_add*((vpd_master_power_slope*volt_util_inactive/10000+vpd_master_power_intercept)*num_logical_dimms*(100+percent_uplift_idle)/100);
	   FAPI_INF("var_power_on_vddr: %d cW vpd_master_power_slope: %d cW volt_util_inactive: %d per 10k vpd_master_power_intercept %d cW num_logical_dimms %d percent_uplift_idle %d %%",var_power_on_vddr,vpd_master_power_slope,volt_util_inactive,vpd_master_power_intercept,num_logical_dimms,percent_uplift_idle);
       }
       
       //resets the number of DIMMs to add.
       num_dimms_to_add = 1;
    }//end for
    
    //found a bad DIMM, exit
    if(bad_vpd_rc) {
       FAPI_ERR("Found one or more functional DIMM with bad VPD. Exiting....");
       return bad_vpd_rc;
    }
    
    //debug print
    FAPI_INF("var_power_on_vddr: %d cW volt_slope: %d uV/W volt_intercept: %d mV",var_power_on_vddr,volt_slope,volt_intercept);
    
    //computes and converts the voltage offset into mV
    uint32_t param_vddr_voltage_mv = (500 + var_power_on_vddr*volt_slope/100) / 1000 + volt_intercept;
    FAPI_INF("param_vddr_voltage_mv: %d mV",param_vddr_voltage_mv);
    //found that the VDDR voltage is over the maximum limit
    if(param_vddr_voltage_mv > vddr_max_limit_mv) {
       FAPI_INF("param_vddr_voltage_mv, %d mV, is over vddr_max_limit_mv of %d mV.",param_vddr_voltage_mv,vddr_max_limit_mv);
       FAPI_INF("Setting param_vddr_voltage_mv to vddr_max_limit_mv");
       param_vddr_voltage_mv = vddr_max_limit_mv;
    }
    //prints a debug statement
    FAPI_INF("ATTR_MSS_VDDR_OFFSET: %d mV",param_vddr_voltage_mv);
    
    //sets the output attributes
    for(uint32_t i = 0; i< i_targets.size();i++) {
       l_rc = FAPI_ATTR_SET(ATTR_MSS_VDDR_OFFSET,&i_targets[i],param_vddr_voltage_mv); 
       if(l_rc) return l_rc;
    }//end for 
    
    return l_rc;
}
