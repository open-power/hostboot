/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_util_to_throttle.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
// $Id: mss_util_to_throttle.C,v 1.7 2014/11/06 21:07:06 pardeik Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/
//          centaur/working/procedures/ipl/fapi/mss_util_to_throttle.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_util_to_throttle
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Michael Pardeik   Email: pardeik@us.ibm.com
// *! BACKUP NAME : Mark Bellows Email:  bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// applicable CQ component memory_screen
//
// DESCRIPTION:
// The purpose of this procedure is to set the N throttle attributes for a
// given dram data bus utilization.  TMGT will call this to determine a
// minimum N_MBA setting for the minimum MBA utilization allowed for that system
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.7    | pardeik  |06-NOV-14| removed string in trace statement
//         |          |         | changed FAPI_IMP to FAPI_INF
//  1.6    | pardeik  |11-FEB-14| RAS review fix:  change %% to percent
//  1.5    | pardeik  |13-JAN-14| Fixed calculation to not include x2 factor for
//         |          |         |  other MBA for custom DIMMs
//  1.4    | pardeik  |06-JAN-14| Use ATTR_MRW_MEM_THROTTLE_DENOMINATOR instead
//         |          |         |  of ATTR_MRW_SAFEMODE_MEM_THROTTLE_DENOMINATOR
//  1.3    | pardeik  |07-NOV-13| gerrit review updates
//  1.2    | pardeik  |07-NOV-13| gerrit review updates
//  1.1    | pardeik  |06-OCT-13| First Draft.


//------------------------------------------------------------------------------
//  My Includes
//------------------------------------------------------------------------------
#include <mss_util_to_throttle.H>

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapi.H>


extern "C" {

    using namespace fapi;


//------------------------------------------------------------------------------
// @brief mss_util_to_throttle(): This function will determine the minimum
// N throttle settings for N/M throttling given a dram data bus utilization
//
// @param[in]	const fapi::Target &i_target_mba:  MBA Target
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------

    fapi::ReturnCode mss_util_to_throttle(const fapi::Target & i_target_mba)
    {
	fapi::ReturnCode rc = fapi::FAPI_RC_SUCCESS;

	FAPI_INF("*** Running mss_util_to_throttle ***");

	uint32_t throttle_d;
	uint8_t data_bus_util;
	uint32_t min_throttle_n_per_mba;

// Get input attributes
	rc = FAPI_ATTR_GET(ATTR_MSS_DATABUS_UTIL_PER_MBA,
			   &i_target_mba, data_bus_util);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MSS_DATABUS_UTIL_PER_MBA");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_MRW_MEM_THROTTLE_DENOMINATOR,
			   NULL, throttle_d);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MRW_MEM_THROTTLE_DENOMINATOR");
	    return rc;
	}

// Calculate out the minimum N_MBA throttle number for the given utilization
//   Uses N/M Throttling.   Equation:  (DRAM data bus utilization Percent / 100 ) = ((N * 4) / M)
//   The 4 is a constant since dram data bus utilization is 4X the address bus utilization
//   Add one since integer will truncate floating point number, so we we do not end up with a
//   lower than intended setting
	min_throttle_n_per_mba =((data_bus_util * throttle_d) / 4 / 100) + 1;
	FAPI_INF("MIN N_MBA Throttle for %d percent DRAM data bus util = %d", data_bus_util, min_throttle_n_per_mba);


// Update output attributes
	rc = FAPI_ATTR_SET(ATTR_MSS_UTIL_N_PER_MBA,
			   &i_target_mba, min_throttle_n_per_mba);
	if (rc) {
	    FAPI_ERR("Error writing attribute ATTR_MSS_UTIL_N_PER_MBA");
	    return rc;
	}

	FAPI_INF("*** mss_util_to_throttle COMPLETE ***");
	return rc;

    }



} //end extern C
