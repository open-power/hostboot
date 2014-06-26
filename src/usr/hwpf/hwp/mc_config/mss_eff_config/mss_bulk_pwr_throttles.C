/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_bulk_pwr_throttles.C $ */
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
// $Id: mss_bulk_pwr_throttles.C,v 1.22 2014/06/02 13:10:53 pardeik Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/
//          centaur/working/procedures/ipl/fapi/mss_bulk_pwr_throttles.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_bulk_pwr_throttles
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Michael Pardeik   Email: pardeik@us.ibm.com
// *! BACKUP NAME : Jacob Sloat       Email: jdsloat@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// applicable CQ component memory_screen
//
// DESCRIPTION:
// The purpose of this procedure is to set the throttle attributes based on a
// power limit for the dimms on the channel pair
// At the end, output attributes will be updated with throttle values that will
// have dimms at or below the limit
// NOTE:  ISDIMMs and CDIMMs are handled differently
//   ISDIMMs use a power per DIMM for the thermal power limit from the MRW
//   CDIMM will use power per CDIMM (power for all virtual dimms) for the
//    thermal power limit from the MRW
// Plan is to have ISDIMM use the per-slot throttles (thermal throttles) or
//  per-mba throttles (power throttles), and CDIMM to use the per-chip throttles
// Note that throttle_n_per_mba takes on different meanings depending on how
// cfg_nm_per_slot_enabled is set
//   Can be slot0/slot1 OR slot0/MBA throttling
// Note that throttle_n_per_chip takes on different meaning depending on how
// cfg_count_other_mba_dis is set
//  Can be per-chip OR per-mba throttling
// These inits here are done in mss_scominit
// ISDIMM:  These registers need to be setup to these values, will be able to
//  do per slot or per MBA throttling
//   cfg_nm_per_slot_enabled = 1
//   cfg_count_other_mba_dis = 1
// CDIMM:  These registers need to be setup to these values, will be able to
//  do per mba or per chip throttling
//   cfg_nm_per_slot_enabled = 0
//   cfg_count_other_mba_dis = 0
//
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.22  | pardeik  |21-MAY-14| Removed section that adjusts power limit
//         |          |         | (was not getting correct throttle values
//         |          |         | to have channel pair power be under limit)
//         |          |         | Limit channel pair power limit to thermal limit
//         |          |         | Start with runtime throttle attributes
//   1.21  | jdsloat  |10-MAR-14| Edited comments
//   1.20  | pardeik  |06-MAR-14| RAS update for HWP error
//         |          |         |   (changed the callout from centaur to mba)
//   1.19  | pardeik  |24-JAN-14| RAS update for HWP error
//   1.18  | pardeik  |23-JAN-14| gerrit review updates to break out of for loop
//   1.17  | pardeik  |21-JAN-14| updates to prevent a negative power limit
//   1.16  | pardeik  |06-JAN-14| use max utiliation from MRW for MAX_UTIL
//         |          |         | Use ATTR_MRW_MEM_THROTTLE_DENOMINATOR instead
//         |          |         |  of ATTR_MRW_SAFEMODE_MEM_THROTTLE_DENOMINATOR
//   1.15  | pardeik  |13-NOV-13| changed MAX_UTIL from 75 to 56.25
//         |          |         | get default M throttle value from MRW
//         |          |         | return error if not enough memory power
//         |          |         | comment fixes to align with scominit settings
//   1.14  | bellows  |19-SEP-13| fixed possible buffer overrun found by stradale
//   1.13  | pardeik  |19-JUL-13| removed code to identify if throttles are 
//         |          |         |   based on thermal or power reasons since the
//         |          |         |   runtime throttles will now be determined
//         |          |         |   whenever mss_eff_config_thermal runs
//   1.12  | pardeik  |08-JUL-13| Update to use CUSTOM_DIMM instead of DIMM_TYPE
//         |          |         | removed incrementing of throttle denominator
//         |          |         | set throttle per_mba at end of procedure
//   1.11  | pardeik  |04-DEC-12| update lines to have a max width of 80 chars
//         |          |         | added FAPI_ERR before return code lines
//         |          |         | made trace statements for procedure FAPI_IMP
//         |          |         | updates for FAPI_SET_HWP_ERROR
//   1.10  | pardeik  |08-NOV-12| attribute name update for runtime per chip
//         |          |         | throttles
//   1.9   | pardeik  |25-OCT-12| updated FAPI_ERR sections, use per_chip
//         |          |         | variables (in if statements) in the throttle
//         |          |         | update section when channel pair power is
//         |          |         | greater than the limit, added CQ component
//         |          |         | comment line
//   1.8   | pardeik  |19-OCT-12| Changed throttle_n_per_chip to be based on
//         |          |         | num_mba_with_dimms
//         | pardeik  |19-OCT-12| Updated default throttle values to represent
//         |          |         | cmd bus utilization instead of dram bus
//         |          |         | utilization
//         | pardeik  |19-OCT-12| multiple throttle N values by 4 to get dram
//         |          |         | utilization
//   1.7   | pardeik  |10-OCT-12| Changed throttle attributes and call new
//         |          |         | function (mss_throttle_to_power) to calculate
//         |          |         | the power
//   1.6   | pardeik  |10-APR-12| power calculation fixes and updates
//   1.5   | pardeik  |04-APR-12| moved cdimm power calculation to end of
//         |          |         |section instead of having it in multiple places
//   1.4   | pardeik  |04-APR-12| do channel throttle denominator check as zero
//         |          |         |only if there are ranks present
//         | pardeik  |04-APR-12| use else if instead of if after checking
//         |          |         | throttle denominator to zero
//   1.3   | pardeik  |03-APR-12| added cdimm power calculation for half of
//         |          |         |cdimm, changed i_target from mbs to mba
//   1.2   | pardeik  |03-APR-12| call mss_eff_config_thermal directly
//   1.1   | pardeik  |28-MAR-12| Updated to use Attributes
//         | pardeik  |11-NOV-11| First Draft.


//------------------------------------------------------------------------------
//  My Includes
//------------------------------------------------------------------------------
#include <mss_bulk_pwr_throttles.H>
#include <mss_throttle_to_power.H>

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapi.H>


extern "C" {

    using namespace fapi;


//------------------------------------------------------------------------------
// Funtions in this file
//------------------------------------------------------------------------------
    fapi::ReturnCode mss_bulk_pwr_throttles(
					    const fapi::Target & i_target_mba
					    );


//------------------------------------------------------------------------------
// @brief mss_bulk_pwr_throttles(): This function determines the throttle values
// from a MBA channel pair power limit
//
// @param[in]	const fapi::Target & i_target_mba:  MBA Target passed in
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------

    fapi::ReturnCode mss_bulk_pwr_throttles(const fapi::Target & i_target_mba
					    )
    {
	fapi::ReturnCode rc;

	const char* procedure_name = "mss_bulk_pwr_throttles";

	FAPI_IMP("*** Running %s on %s ***", procedure_name,
		 i_target_mba.toEcmdString());

// min utilization (percent of max) allowed for floor
	const float MIN_UTIL = 1;

	uint32_t channel_pair_watt_target;
	uint32_t throttle_n_per_mba;
	uint32_t throttle_n_per_chip;
	uint32_t throttle_d;
	bool not_enough_available_power;
	bool channel_pair_throttle_done;
	float channel_pair_power;
	uint8_t custom_dimm;
	uint32_t runtime_throttle_n_per_mba;
	uint32_t runtime_throttle_n_per_chip;
	uint32_t runtime_throttle_d;

// Get input attributes
	rc = FAPI_ATTR_GET(ATTR_EFF_CUSTOM_DIMM, &i_target_mba, custom_dimm);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_CUSTOM_DIMM");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_MSS_MEM_WATT_TARGET,
			   &i_target_mba, channel_pair_watt_target);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MSS_MEM_WATT_TARGET");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_MRW_MEM_THROTTLE_DENOMINATOR, NULL, throttle_d);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MRW_MEM_THROTTLE_DENOMINATOR");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_MBA,
			   &i_target_mba, runtime_throttle_n_per_mba);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_MBA");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_CHIP,
			   &i_target_mba, runtime_throttle_n_per_chip);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_CHIP");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_MSS_RUNTIME_MEM_THROTTLE_DENOMINATOR,
			   &i_target_mba, runtime_throttle_d);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MSS_RUNTIME_MEM_THROTTLE_DENOMINATOR");
	    return rc;
	}


//------------------------------------------------------------------------------
// THROTTLE SECTION
//------------------------------------------------------------------------------

// Determine if the channel pair power for this MBA is over the limit when the
// runtime memory throttle settings are used
// If not over the limit, then use the runtime throttle settings (defined in
// mss_eff_config_thermal)
// If over limit, then increase throttle value until it is at or below limit
// If unable to get power below limit, then call out an error

// Start with the runtime throttle settings since we may have a thermal/power limit
	throttle_n_per_mba = runtime_throttle_n_per_mba;
	throttle_n_per_chip = runtime_throttle_n_per_chip;

// calculate power and change throttle values in this while loop until limit has
// been satisfied or throttles have reached the minimum limit
	not_enough_available_power = false;
	channel_pair_throttle_done = false;
	while (channel_pair_throttle_done == false)
	{
	    rc = mss_throttle_to_power_calc(
					    i_target_mba,
					    throttle_n_per_mba,
					    throttle_n_per_chip,
					    throttle_d,
					    channel_pair_power
					    );
	    if (rc)
	    {
		FAPI_ERR("Error (0x%x) calling mss_throttle_to_power_calc", static_cast<uint32_t>(rc));
		return rc;
	    }

// compare channel pair power to mss_watt_target for channel and decrease
// throttles if it is above this limit
// throttle decrease will decrement throttle numerator by one
// and recalculate power until utilization (N/M) reaches a lower limit

	    if (channel_pair_power > channel_pair_watt_target)
	    {
// check to see if dimm utilization is greater than the min utilization limit,
// continue if it is, error if it is not
		if ((((float)throttle_n_per_chip * 100 * 4) / throttle_d) >
		      MIN_UTIL)
		{
		    if (throttle_n_per_chip > 1)
		    {
			if (custom_dimm == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)
			{
// CDIMMs, use per chip throttling for any thermal or available power limits
			    throttle_n_per_chip--;
			}
			else
			{
// ISDIMMs, use per mba throttling for available power limit
// per_mba throttling (ie.  per dimm for ISDIMMs) will limit performance if all
// traffic is sent to one dimm, so use the per_chip
			    throttle_n_per_chip--;
			}
		    }
// This was increment throttle_d++, but don't want to change the denominator since OCC does not set it.
// Done if we reach this point (ie.  not enough power)
		    else
		    {
			channel_pair_throttle_done = true;
			not_enough_available_power = true;
		    }
		    FAPI_DBG("Throttle update [N_per_mba/N_per_chip/M %d/%d/%d]", throttle_n_per_mba, throttle_n_per_chip, throttle_d);
		}
// minimum utilization limit was reached for this throttle N/M value
		else
		{
// Throttles can't be changed anymore (already at or below MIN_UTIL)
		    channel_pair_throttle_done = true;
		    not_enough_available_power = true;
		}
	    }
// channel pair power is less than limit, so keep existing throttles
	    else
	    {
		FAPI_INF("There is enough available memory power [Channel Pair Power %4.2f/%d cW]", channel_pair_power, channel_pair_watt_target);
		channel_pair_throttle_done = true;
	    }
	}

// Set per_mba throttle to per_chip throttle if it is greater
// This way, when OCC throttles using per_mba due to thermal reasons,
// it has a higher chance of making an immediate impact
// NOTE:  If above throttle determination uses throttle_n_per_mba, then
// we need to change this around
	if (throttle_n_per_mba > throttle_n_per_chip)
	{
	    throttle_n_per_mba = throttle_n_per_chip;
	}

	FAPI_INF("Final Throttle Settings [N_per_mba/N_per_chip/M %d/%d/%d]", throttle_n_per_mba, throttle_n_per_chip, throttle_d);

//------------------------------------------------------------------------------
// update output attributes
	rc = FAPI_ATTR_SET(ATTR_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA,
			   &i_target_mba, throttle_n_per_mba);
	if (rc) {
	    FAPI_ERR("Error writing attribute ATTR_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA");
	    return rc;
	}
	rc = FAPI_ATTR_SET(ATTR_MSS_MEM_THROTTLE_NUMERATOR_PER_CHIP,
			   &i_target_mba, throttle_n_per_chip);
	if (rc) {
	    FAPI_ERR("Error writing attribute ATTR_MSS_MEM_THROTTLE_NUMERATOR_PER_CHIP");
	    return rc;
	}
	rc = FAPI_ATTR_SET(ATTR_MSS_MEM_THROTTLE_DENOMINATOR,
			   &i_target_mba, throttle_d);
	if (rc) {
	    FAPI_ERR("Error writing attribute ATTR_MSS_MEM_THROTTLE_DENOMINATOR");
	    return rc;
	}

	if (not_enough_available_power == true)
	{
// return error for TMGT to handle if there is not enough available memory power
// at the minimum utilization throttle setting
	    FAPI_ERR("Not enough available memory power [Channel Pair Power %4.2f/%d cW]", channel_pair_power, channel_pair_watt_target);
	    const float & PAIR_POWER = channel_pair_power;
	    const uint32_t & PAIR_WATT_TARGET = channel_pair_watt_target;
	    const fapi::Target & MEM_MBA = i_target_mba;
	    FAPI_SET_HWP_ERROR(rc, RC_MSS_NOT_ENOUGH_AVAILABLE_DIMM_POWER);
	    return rc;
	}

	FAPI_IMP("*** %s COMPLETE on %s ***", procedure_name,
		 i_target_mba.toEcmdString());
	return rc;
    }

} //end extern C


