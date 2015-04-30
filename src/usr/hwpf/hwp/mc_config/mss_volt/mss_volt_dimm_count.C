/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_volt/mss_volt_dimm_count.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
// $Id: mss_volt_dimm_count.C,v 1.3 2015/04/06 22:33:05 pardeik Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/
//          centaur/working/procedures/ipl/fapi/mss_volt_dimm_count.C,v $

//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2007
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE : mss_volt_dimm_count.C
// *! DESCRIPTION : Tools for centaur procedures
// *! OWNER NAME :  Michael Pardeik (pardeik@us.ibm.com) 
// *! BACKUP NAME : Jacob Sloat (jdsloat@us.ibm.com)
// #! ADDITIONAL COMMENTS :
//
// applicable CQ component memory_screen
//
// DESCRIPTION:
// This procedure takes a vector of Centaurs behind a vmem voltage domain,
// and counts the number of dimms that are present.  Only the highest
// number of dimms found under any given vmem power domain will be saved away.
// The array of centaur targets are to be present (configured and deconfigured).
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:   | Comment:
//---------|----------|----------|-----------------------------------------------
//  1.3    | pardeik  | 04/06/15 | attribute name changed for adjustment enable
//  1.2    | pardeik  | 03/06/15 | Review update to check l_rc after for loops
//  1.1    | pardeik  | 02/17/15 | Initial draft.


//----------------------------------------------------------------------
//  Includes - FAPI
//----------------------------------------------------------------------
#include <fapi.H>
#include <mss_volt_dimm_count.H>

fapi::ReturnCode mss_volt_dimm_count(std::vector<fapi::Target> & i_targets_memb)
{

    fapi::ReturnCode l_rc;
    uint8_t l_memb_count=0;
    uint8_t l_dimm_count=0;
    uint8_t l_mrw_reg_power_limit_adj_enable;
    uint8_t l_mrw_max_number_dimms_per_reg;
    uint8_t l_spd_custom;
    uint8_t l_custom_dimm = 0;
    uint8_t l_dimm_count_under_reg;
    uint8_t l_max_dimm_count_per_reg;

    do {
	l_rc = FAPI_ATTR_GET(ATTR_MRW_VMEM_REGULATOR_POWER_LIMIT_PER_DIMM_ADJ_ENABLE, NULL, l_mrw_reg_power_limit_adj_enable);
	if (l_rc) break;
	if (l_mrw_reg_power_limit_adj_enable == fapi::ENUM_ATTR_MRW_VMEM_REGULATOR_POWER_LIMIT_PER_DIMM_ADJ_ENABLE_TRUE)
	{
	    l_rc = FAPI_ATTR_GET(ATTR_MRW_MAX_NUMBER_DIMMS_POSSIBLE_PER_VMEM_REGULATOR, NULL, l_mrw_max_number_dimms_per_reg);
	    if (l_rc) break;
	    l_rc = FAPI_ATTR_GET(ATTR_MSS_VMEM_REGULATOR_MAX_DIMM_COUNT, NULL, l_max_dimm_count_per_reg);
	    if (l_rc) break;

	// Iterate through the list of centaurs (configured and deconfigured)
	    for (uint32_t i=0; i < i_targets_memb.size(); i++)
	    {
		l_memb_count++;
		std::vector<fapi::Target> l_mbaChiplets;
	    // Get associated MBA's on this centaur
		l_rc=fapiGetChildChiplets(i_targets_memb[i], fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets, fapi::TARGET_STATE_PRESENT);
		if (l_rc) break;
	    // Loop through the 2 MBA's
		for (uint32_t j=0; j < l_mbaChiplets.size(); j++)
		{
		    l_dimm_count++;
		    std::vector<fapi::Target> l_dimm_targets;
		// Get a vector of DIMM targets
		    l_rc = fapiGetAssociatedDimms(l_mbaChiplets[j], l_dimm_targets, fapi::TARGET_STATE_PRESENT);
		    if (l_rc) break;

		    for (uint32_t k=0; k < l_dimm_targets.size(); k++)
		    {
			l_rc = FAPI_ATTR_GET(ATTR_SPD_CUSTOM, &l_dimm_targets[k], l_spd_custom);
			if (l_rc) break;
			if (l_spd_custom == fapi::ENUM_ATTR_SPD_CUSTOM_YES)
			{
			    l_custom_dimm=1;
			}
		    }
		    if (l_rc) break;
		}
		if (l_rc) break;
	    }
	    if (l_rc) break;

	    // DIMM count will be number of centaurs for custom dimms
	    // or number of dimms for non custom dimms
	    if (l_custom_dimm == 1)
	    {
		l_dimm_count_under_reg = l_memb_count;
	    }
	    else
	    {
		l_dimm_count_under_reg = l_dimm_count;
	    }
	    FAPI_INF("mss_volt_dimm_count complete:  DIMM Count %d/%d", l_dimm_count_under_reg, l_mrw_max_number_dimms_per_reg);
	    if (l_dimm_count_under_reg > l_max_dimm_count_per_reg)
	    {
		l_rc = FAPI_ATTR_SET(ATTR_MSS_VMEM_REGULATOR_MAX_DIMM_COUNT, NULL, l_dimm_count_under_reg);
		if (l_rc) break;
	    }
	}
    }while(0);
    return(l_rc);
}
