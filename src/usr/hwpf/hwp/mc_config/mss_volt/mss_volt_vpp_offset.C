/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_volt/mss_volt_vpp_offset.C $   */
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
// $Id: mss_volt_vpp_offset.C,v 1.6 2014/06/18 20:34:41 dcadiga Exp $
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
//  1.6    | sglancy  | 06/18/14 | Deletes two unused variables and updated errors
//  1.5    | sglancy  | 06/09/14 | Updated debug statements
//  1.4    | sglancy  | 06/04/14 | Updated to include output attribute
//  1.3    | sglancy  | 05/30/14 | Formatted code
//  1.2    | sglancy  | 05/29/14 | Fixed attributes units and equations
//  1.1    | sglancy  | 05/20/14 | File created

// This procedure takes a vector of Centaurs behind the vpp voltage domain,
// reads in supported DIMM voltages from SPD and determines optimal
//  voltage bin for the DIMM voltage domain.
// supported voltage bins:  DDR3 0V  DDR4 2.5V


//----------------------------------------------------------------------
//  Includes - FAPI
//----------------------------------------------------------------------
#include <fapi.H>
#include <mss_volt_vpp_offset.H>
#include <mss_count_active_centaurs.H>

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------


fapi::ReturnCode mss_volt_vpp_offset(std::vector<fapi::Target> & i_targets)
{
    //declares variables
    fapi::ReturnCode l_rc;
    uint32_t num_chips = 0;
    uint32_t vpp_slope, vpp_intercept;
    uint8_t dram_width, enable, dram_gen;
    uint8_t cur_dram_gen;
    uint8_t num_spares[2][2][4];
    uint8_t rank_config[2][2];
    std::vector<fapi::Target>  l_mbaChiplets;
      
    //gets the attributes and computes var_power_on based upon whether the DRAM type is DDR3 or DDR4
    l_rc=fapiGetChildChiplets(i_targets[0], fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets);
    if(l_rc) return l_rc;
    l_rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN,&l_mbaChiplets[0],dram_gen); 
    if(l_rc) return l_rc;
    
    //checks to make sure that all of the DRAM generation attributes are the same, if not error out
    for(uint32_t i = 0; i < i_targets.size();i++) {
       //loops through all MBA chiplets to compare the DRAM technology generation attribute
       l_mbaChiplets.clear();
       l_rc=fapiGetChildChiplets(i_targets[i], fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets);
       for(uint32_t j=0;j<l_mbaChiplets.size();j++) {
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
             FAPI_SET_HWP_ERROR(l_rc, RC_MSS_VOLT_VPP_OFFSET_DRAM_GEN_MISCOMPARE);
             FAPI_ERR("Not all DRAM technology generations are the same.\nExiting....");
             if(l_rc) return l_rc;
          }//end if
       }//end for
    }//end for

    //checks to see if the DIMMs are DDR3 DIMMs if so, return 0 and exit
    if(dram_gen == fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR3) {
       uint32_t param_vpp_voltage_mv = 0; 
       //debug output statement
       FAPI_INF("ATTR_MSS_VPP_OFFSET: %d",param_vpp_voltage_mv);
       //sets the output attributes
       for(uint32_t i = 0; i< i_targets.size();i++) {
          l_rc = FAPI_ATTR_SET(ATTR_MSS_VPP_OFFSET,&i_targets[i],param_vpp_voltage_mv); 
          if(l_rc) return l_rc;
       }
       return l_rc;
    }
    
    //voltage should not be updated if the disable is set
    l_rc = FAPI_ATTR_GET(ATTR_MSS_VPP_OFFSET_DISABLE,NULL,enable); 
    //error check
    if(l_rc) return l_rc;
    //add print statement for enable/disable check
    
    if(enable == fapi::ENUM_ATTR_MSS_VPP_OFFSET_DISABLE_DISABLE) return l_rc;

    //gets the slope and intercepts
    l_rc = FAPI_ATTR_GET(ATTR_MSS_VPP_SLOPE,NULL,vpp_slope); 
    if(l_rc) return l_rc;
    l_rc = FAPI_ATTR_GET(ATTR_MSS_VPP_SLOPE_INTERCEPT,NULL,vpp_intercept); 
    if(l_rc) return l_rc;
    //checks to make sure that none of the values are zeros.  If any of the values are 0's then 0 * any other value = 0
    if((vpp_slope * vpp_intercept) == 0) {
       const uint32_t &VPP_SLOPE = vpp_slope;
       const uint32_t &VPP_INTERCEPT = vpp_intercept;
       FAPI_SET_HWP_ERROR(l_rc, RC_MSS_VOLT_VPP_OFFSET_VALUE_ERROR);
       FAPI_ERR("One or more dynamic VPP attributes is 0.\nExiting....");
       return l_rc;
    }
    

    //continues computing VPP for DDR4
    //loops through all DIMMs
    num_chips=0;
    for(uint32_t i=0;i<i_targets.size();i++) {
       //resets the number of ranks and spares
       l_mbaChiplets.clear();
       l_rc=fapiGetChildChiplets(i_targets[i], fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets);
       //loops through the each MBA chiplet to get the number of ranks and the number of spares
       for(uint32_t mba = 0;mba<l_mbaChiplets.size();mba++) {
          //gets if the centaur is a x4 or a x8
          l_rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH,&l_mbaChiplets[mba],dram_width); 
	  if(l_rc) return l_rc;
          l_rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM,&l_mbaChiplets[mba],rank_config); 
	  if(l_rc) return l_rc;
          l_rc = FAPI_ATTR_GET(ATTR_VPD_DIMM_SPARE,&l_mbaChiplets[mba],num_spares); 
	  if(l_rc) return l_rc;
	  for(uint32_t port=0;port<2;port++) {
	     for(uint32_t dimm=0;dimm<2;dimm++) {
	        //adds the appropriate number of DRAM found per dimm for each rank
		if(dram_width == fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X4) num_chips += 18*rank_config[port][dimm];
		else num_chips += 9*rank_config[port][dimm];
	        for(uint32_t rank=0;rank<4;rank++) {
		   //figures out the spares
		   if(dram_width == fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X4) {
		      if(num_spares[port][dimm][rank] == fapi::ENUM_ATTR_EFF_DIMM_SPARE_LOW_NIBBLE) {
		         num_chips += rank_config[port][dimm];
		      }
		      if(num_spares[port][dimm][rank] == fapi::ENUM_ATTR_EFF_DIMM_SPARE_HIGH_NIBBLE) {
		         num_chips += rank_config[port][dimm];
		      }
		      if(num_spares[port][dimm][rank] == fapi::ENUM_ATTR_EFF_DIMM_SPARE_FULL_BYTE) {
		         num_chips += 2*rank_config[port][dimm];
		      }
		   }
		   else {
		      if(num_spares[port][dimm][rank] == fapi::ENUM_ATTR_EFF_DIMM_SPARE_FULL_BYTE) {
		         num_chips += rank_config[port][dimm];
		      }
		   }
		}
	     }
	  }
       }
    }

    FAPI_INF("vpp_slope: %d uV/DRAM chip vpp_intercept: %d mV num_chips: %d DRAM chips\n",vpp_slope,vpp_intercept,num_chips);

    //does the final computation
    uint32_t param_vpp_voltage_uv = vpp_slope*num_chips+1000*vpp_intercept;
    //rounds and converts the voltage offset into mV
    uint32_t param_vpp_voltage_mv = (500 + param_vpp_voltage_uv) / 1000;
    FAPI_INF("ATTR_MSS_VPP_OFFSET: %d mV",param_vpp_voltage_mv);
    
    //sets the output attributes
    for(uint32_t i = 0; i< i_targets.size();i++) {
       l_rc = FAPI_ATTR_SET(ATTR_MSS_VPP_OFFSET,&i_targets[i],param_vpp_voltage_mv); 
       if(l_rc) return l_rc;
    }//end for 
    
    return l_rc;
}
