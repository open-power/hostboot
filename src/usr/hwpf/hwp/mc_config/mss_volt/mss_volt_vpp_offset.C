/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_volt/mss_volt_vpp_offset.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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
// $Id: mss_volt_vpp_offset.C,v 1.21 2015/12/22 15:33:03 sglancy Exp $
/* File mss_volt_vpp_offset.C created by Stephen Glancy on Tue 20 May 2014. */

//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2007
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
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
//  1.21   | pardeik  | 12/16/15 | fixed dram die count for 3DS
//  1.20   | sglancy  | 07/22/15 | DDR4 updates allowing both DDR3 and DDR4 DIMMs on the same VPP plane
//  1.19   | sglancy  | 04/21/15 | Added support for mixed voltage plane configurations.  still checks for mixed centaur bugs
//  1.18   | sglancy  | 09/12/14 | Removed references to EFF attributes
//  1.17   | sglancy  | 09/12/14 | Fixed bugs
//  1.16   | sglancy  | 09/11/14 | Fixed bugs
//  1.15   | sglancy  | 09/09/14 | Fixed bug
//  1.14   | sglancy  | 09/08/14 | Updated to fix FW compile and logic bugs
//  1.13   | sglancy  | 09/03/14 | Updated to go with a new HWP design
//  1.12   | sglancy  | 08/27/14 | Changed code to set VPP offset value to 0 if code is unable to read the VPD of all DIMMs, which should disable the VPP plane
//  1.11   | sglancy  | 08/22/14 | Changed code to make the risky assumption that the box is running DDR3 if code is unable to read the VPD of all DIMMs
//  1.10   | sglancy  | 07/16/14 | Fixed attribute name bug
//  1.9    | sglancy  | 07/01/14 | Included updates for DDR4
//  1.8    | sglancy  | 06/25/14 | Commented out DRAM_GEN checking section of the code and forced it to default DDR3 - WILL UPDATE TO CHECK THE DRAM GENERATIONS FOR FUTURE CODE GENERATIONS
//  1.7    | sglancy  | 06/24/14 | Fixed bugs associated with empty returns from fapiGetChildChiplets
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
    fapi::ReturnCode l_rc, bad_vpd_rc;
    uint32_t num_chips = 0;
    uint32_t vpp_slope, vpp_intercept;
    uint8_t dram_width, enable, dram_gen;
    uint8_t cur_dram_gen, is_functional; 
    bool dram_gen_found_mc = false; 
    bool dram_gen_found = false;
    bool dram_gen_ddr4 = false;
    uint8_t num_spares[2][2][4];
    uint8_t rank_config, num_non_functional, die_count, dram_device_signal_loading;
    num_non_functional = 0;
    std::vector<fapi::Target>  l_mbaChiplets;
    std::vector<fapi::Target>  l_dimm_targets;
    std::vector<uint8_t> dram_gen_vector; //used to ID whether an MC needs to be used in the VPP offset calculations
    
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
       
       dram_gen_found_mc = false;
       
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
		   const uint32_t FAILING_ATTRIBUTE = fapi::ATTR_SPD_DRAM_DEVICE_TYPE;
	    	   FAPI_SET_HWP_ERROR(bad_vpd_rc, RC_VPP_FUNCTIONAL_DIMM_VPD_READ_ERROR);
		   continue;
		}
		else {
		   FAPI_INF("Problem reading VPD on non-functional DIMM. Skipping current DIMM and proceding to the next DIMM.");
		   continue;
		}
	     }
	     //if this is the first DIMM that has a valid DRAM Technology level, then set the level and continue
	     //otherwise throw an error and exit
	     if(!dram_gen_found_mc) {
	        dram_gen = cur_dram_gen;
		dram_gen_found = true;
		dram_gen_found_mc = true;
	     } //end if
	     else {
	        //values are not equal for one given centaur -> set the fapi RC and exit out
    	  	if(cur_dram_gen != dram_gen){
    	  	   // this just needs to be deconfiged at the dimm level
    	  	   const uint8_t &DRAM_GEN_MISCOMPARE = cur_dram_gen;
    	  	   const uint8_t &DRAM_GEN_START = dram_gen;
    	  	   const uint32_t &CEN_MBA_NUM = mba;
    	  	   const uint32_t &CEN_TARGET_NUM = i;
    	  	   FAPI_SET_HWP_ERROR(l_rc, RC_MSS_VOLT_VPP_OFFSET_DRAM_GEN_MISCOMPARE);
    	  	   FAPI_ERR("Not all DRAM technology generations are the same.\nExiting....");
    	  	   return l_rc;
    	  	}//end if
		//is a DDR4 type, go and set the DDR4 flag -> means that the vpp offset flag will be set
		if(cur_dram_gen == fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR4) {
		   dram_gen_ddr4 = true;
		}
	     }//end else
	  }
       }//end for
       
       //if a DRAM gen was not found for this MC, then assume that this is a DDR4 DIMM to err on the side of caution
       //please note: dram_gen_ddr4 flag is not set here intentionally, this is because the voltage offset is only desirable if a card is confirmed as DDR4
       if(!dram_gen_found_mc) {
          dram_gen_vector.push_back(fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR4);
       }
       //otherwise, do the current DRAM gen for the card
       else {
          dram_gen_vector.push_back(cur_dram_gen);
       }
    }//end for
    
    //found a bad VPD
    if(bad_vpd_rc) {
       FAPI_ERR("Bad VPD found on a functional DIMM");
       return bad_vpd_rc;
    } 
    
    //did not find a valid DRAM generation 
    if(num_non_functional >= i_targets.size()) {
       FAPI_ERR("No functional centaurs found!  Exiting....");
       FAPI_SET_HWP_ERROR(l_rc, RC_VOLT_VPP_FUNCTIONAL_CENTAUR_NOT_FOUND);
       return l_rc;
    } 
    
    //checks to make sure that the code actually found a dimm with a value for its dram generation. if not, exit out
    if(!dram_gen_found) {
       FAPI_ERR("No DRAM generation found!  Exiting....");
       FAPI_SET_HWP_ERROR(l_rc, RC_VOLT_VPP_DRAM_GEN_NOT_FOUND);
       return l_rc;
    }
    
    //checks to see if the DIMMs are DDR3 DIMMs if so, return 0 and exit
    if(!dram_gen_ddr4) {
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
    l_rc = FAPI_ATTR_GET(ATTR_MSS_VPP_SLOPE,&i_targets[0],vpp_slope); 
    if(l_rc) return l_rc;
    l_rc = FAPI_ATTR_GET(ATTR_MSS_VPP_SLOPE_INTERCEPT,&i_targets[0],vpp_intercept); 
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
       //skips the curent target if it's not DDR4 (no DRAMs drawing power)
       if(dram_gen_vector[i] != fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR4) continue;
       
       //resets the number of ranks and spares
       l_mbaChiplets.clear();
       l_rc=fapiGetChildChiplets(i_targets[i], fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets, fapi::TARGET_STATE_PRESENT);
       if(l_rc) return l_rc;
       //loops through the each MBA chiplet to get the number of ranks and the number of spares
       for(uint32_t mba = 0;mba<l_mbaChiplets.size();mba++) {
	  //gets the dimm level target
	  l_rc = FAPI_ATTR_GET(ATTR_VPD_DIMM_SPARE,&l_mbaChiplets[mba],num_spares); 
          //found an error reading the VPD
	  if(l_rc) {
	     //if the dimm is non-functional, assume that it's bad VPD was the reason that it crashed, then log an error and exit out
	     if(is_functional != fapi::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL) {
	     	FAPI_INF("Problem reading VPD on non-functional DIMM. Using default values for the number of spares");
	     	//uses assumed value
		for(uint32_t port=0;port<2;port++) {
		   for(uint32_t dimm=0;dimm<2;dimm++) {
		      for(uint32_t rank=0;rank<4;rank++) {
	     	         num_spares[port][dimm][rank] = DIMM_SPARE_DEFAULT;
		      }
		   }
		}
	     }
	     //otherwise, just return the error code
	     else {
	        FAPI_ERR("Problem reading VPD on functional DIMM. Logging error and proceding to the next DIMM.");
		if(bad_vpd_rc) {
		   fapiLogError(bad_vpd_rc);
		}
		
		const fapi::Target & TARGET_CEN_ERROR = i_targets[i];
		const fapi::Target & MBA_TARGET = l_mbaChiplets[mba];
		const uint32_t MBA_POSITION = mba;
	    	const uint32_t TARGET_POSITION = i;
		const uint32_t FAILING_ATTRIBUTE = fapi::ATTR_VPD_DIMM_SPARE;
	    	FAPI_SET_HWP_ERROR(bad_vpd_rc, RC_VPP_FUNCTIONAL_CENTAUR_VPD_READ_ERROR);
		continue;
	     }
	  }
	  
          l_dimm_targets.clear();
          //gets the number of declared dimms
	  l_rc = fapiGetAssociatedDimms(l_mbaChiplets[mba], l_dimm_targets);
	  if(l_rc) return l_rc;
	  for(uint32_t dimm=0;dimm<l_dimm_targets.size();dimm++) {
	     //gets if the centaur is a x4 or a x8
             l_rc = FAPI_ATTR_GET(ATTR_SPD_DRAM_WIDTH,&l_dimm_targets[dimm],dram_width); 
             //found an error reading the VPD
	     if(l_rc) {
	        //if the dimm is non-functional, assume that it's bad VPD was the reason that it crashed, then log an error and exit out
	        if(is_functional != fapi::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL) {
		   FAPI_INF("Problem reading VPD on non-functional DIMM. Using default value for DRAM_WIDTH");
		   //uses assumed value
		   dram_width = DRAM_WIDTH_DEFAULT;
		}
		//otherwise, callout and deconfigure the DIMM
	     	else {
	     	   FAPI_ERR("Problem reading VPD on functional DIMM. Logging error and proceding to the next DIMM.");
	  	   if(bad_vpd_rc) {
		      fapiLogError(bad_vpd_rc);
		   }  
		   
		   const fapi::Target & TARGET_DIMM_ERROR = l_dimm_targets[dimm];
	  	   const fapi::Target & MBA_TARGET = l_mbaChiplets[mba];
	  	   const uint32_t MBA_POSITION = mba;
	     	   const uint32_t TARGET_POSITION = i;
	     	   const uint32_t DIMM_POSITION = dimm;
		   const uint32_t FAILING_ATTRIBUTE = fapi::ATTR_SPD_DRAM_WIDTH;
	     	   FAPI_SET_HWP_ERROR(bad_vpd_rc, RC_VPP_FUNCTIONAL_DIMM_VPD_READ_ERROR);
	  	   continue;
	     	}
	     }
             l_rc = FAPI_ATTR_GET(ATTR_SPD_SDRAM_DIE_COUNT,&l_dimm_targets[dimm],die_count);
	     if(l_rc) {
	        //if the dimm is non-functional, assume that it's bad VPD was the reason that it crashed, then log an error and exit out
	        if(is_functional != fapi::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL) {
		   FAPI_INF("Problem reading VPD on non-functional DIMM. Using default value for DIE COUNT");
		   //uses assumed values
		   die_count = DIE_COUNT_DEFAULT;
		}
		//otherwise, callout and deconfigure the DIMM
	     	else {
	     	   FAPI_ERR("Problem reading VPD on functional DIMM. Logging error and proceding to the next DIMM.");
	  	   if(bad_vpd_rc) {
		      fapiLogError(bad_vpd_rc);
		   }
	  	   const fapi::Target & TARGET_DIMM_ERROR = l_dimm_targets[dimm];
	  	   const fapi::Target & MBA_TARGET = l_mbaChiplets[mba];
	  	   const uint32_t MBA_POSITION = mba;
	     	   const uint32_t TARGET_POSITION = i;
	     	   const uint32_t DIMM_POSITION = dimm;
		   const uint32_t FAILING_ATTRIBUTE = fapi::ATTR_SPD_SDRAM_DIE_COUNT;
	     	   FAPI_SET_HWP_ERROR(bad_vpd_rc, RC_VPP_FUNCTIONAL_DIMM_VPD_READ_ERROR);
	  	   continue;
	     	}
	     }
             l_rc = FAPI_ATTR_GET(ATTR_SPD_SDRAM_DEVICE_TYPE_SIGNAL_LOADING,&l_dimm_targets[dimm],dram_device_signal_loading);
	     if(l_rc) {
	        //if the dimm is non-functional, assume that it's bad VPD was the reason that it crashed, then log an error and exit out
	        if(is_functional != fapi::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL) {
		   FAPI_INF("Problem reading VPD on non-functional DIMM. Using default value for DEVICE TYPE SIGNAL LOADING");
		   //uses assumed values
		   dram_device_signal_loading = SIGNAL_LOADING_DEFAULT;
		}
		//otherwise, callout and deconfigure the DIMM
	     	else {
	     	   FAPI_ERR("Problem reading VPD on functional DIMM. Logging error and proceding to the next DIMM.");
	  	   if(bad_vpd_rc) {
		      fapiLogError(bad_vpd_rc);
		   }
	  	   const fapi::Target & TARGET_DIMM_ERROR = l_dimm_targets[dimm];
	  	   const fapi::Target & MBA_TARGET = l_mbaChiplets[mba];
	  	   const uint32_t MBA_POSITION = mba;
	     	   const uint32_t TARGET_POSITION = i;
	     	   const uint32_t DIMM_POSITION = dimm;
		   const uint32_t FAILING_ATTRIBUTE = fapi::ATTR_SPD_SDRAM_DEVICE_TYPE_SIGNAL_LOADING;
	     	   FAPI_SET_HWP_ERROR(bad_vpd_rc, RC_VPP_FUNCTIONAL_DIMM_VPD_READ_ERROR);
	  	   continue;
	     	}
	     }
             l_rc = FAPI_ATTR_GET(ATTR_SPD_NUM_RANKS,&l_dimm_targets[dimm],rank_config); 
             //found an error reading the VPD
	     if(l_rc) {
	        //if the dimm is non-functional, assume that it's bad VPD was the reason that it crashed, then log an error and exit out
	        if(is_functional != fapi::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL) {
		   FAPI_INF("Problem reading VPD on non-functional DIMM. Using default value for NUM_RANKS");
		   //uses assumed values
		   rank_config = NUM_RANKS_PER_DIMM_DEFAULT;
		}
		//otherwise, callout and deconfigure the DIMM
	     	else {
	     	   FAPI_ERR("Problem reading VPD on functional DIMM. Logging error and proceding to the next DIMM.");
	  	   if(bad_vpd_rc) {
		      fapiLogError(bad_vpd_rc);
		   }
	  	   const fapi::Target & TARGET_DIMM_ERROR = l_dimm_targets[dimm];
	  	   const fapi::Target & MBA_TARGET = l_mbaChiplets[mba];
	  	   const uint32_t MBA_POSITION = mba;
	     	   const uint32_t TARGET_POSITION = i;
	     	   const uint32_t DIMM_POSITION = dimm;
		   const uint32_t FAILING_ATTRIBUTE = fapi::ATTR_SPD_NUM_RANKS;
	     	   FAPI_SET_HWP_ERROR(bad_vpd_rc, RC_VPP_FUNCTIONAL_DIMM_VPD_READ_ERROR);
	  	   continue;
	     	}
	     }
	     //adjusts the number of ranks so it's the actual number of ranks on the DIMM
	     rank_config++;
	     // increment by 1 to get correct number of DIE (ENUM value is one less than actual)
	     die_count++;

	     //adds the appropriate number of DRAM found per dimm for each rank
	     if (dram_device_signal_loading == fapi::ENUM_ATTR_SPD_SDRAM_DEVICE_TYPE_SIGNAL_LOADING_SINGLE_LOAD_STACK)
	     {
		 if(dram_width == fapi::ENUM_ATTR_SPD_DRAM_WIDTH_W4) num_chips += 18*rank_config*die_count;
		 else num_chips += 9*rank_config*die_count;
	     }
	     else {
		 if(dram_width == fapi::ENUM_ATTR_SPD_DRAM_WIDTH_W4) num_chips += 18*rank_config;
		 else num_chips += 9*rank_config;
	     }
	  }
	  //loops through and computes the number of spares
	  //assuming that all dram_widths are the same across the centaur and am using the last one
	  for(uint32_t port=0;port<2;port++) {
	     for(uint32_t dimm=0;dimm<2;dimm++) {
	     	for(uint32_t rank=0;rank<4;rank++) {
	     	   if(dram_width == fapi::ENUM_ATTR_SPD_DRAM_WIDTH_W4) {
	     	      if(num_spares[port][dimm][rank] == fapi::ENUM_ATTR_VPD_DIMM_SPARE_LOW_NIBBLE) {
	     		 num_chips += 1;
	     	      }
	     	      if(num_spares[port][dimm][rank] == fapi::ENUM_ATTR_VPD_DIMM_SPARE_HIGH_NIBBLE) {
	     		 num_chips += 1;
	     	      }
	     	      if(num_spares[port][dimm][rank] == fapi::ENUM_ATTR_VPD_DIMM_SPARE_FULL_BYTE) {
	     		 num_chips += 2;
	     	      }
	     	   }
	     	   else {
	     	      if(num_spares[port][dimm][rank] == fapi::ENUM_ATTR_VPD_DIMM_SPARE_FULL_BYTE) {
	     		 num_chips += 1;
	     	      }
	     	   }
	     	}
	     }
	  }
       }
    }
    
    //found a bad VPD
    if(bad_vpd_rc) {
       FAPI_ERR("Bad VPD found on a functional DIMM or centaur");
       return bad_vpd_rc;
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
