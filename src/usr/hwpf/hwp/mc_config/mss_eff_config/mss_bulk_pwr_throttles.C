/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_bulk_pwr_throttles.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
// $Id: mss_bulk_pwr_throttles.C,v 1.30 2015/03/06 15:54:35 pardeik Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/
//          centaur/working/procedures/ipl/fapi/mss_bulk_pwr_throttles.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
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
//   1.30  | pardeik  |12-FEB-15| Review change to check for l_throttle_n_per_chip
//         |          |         |   being zero (shouldn't have any impact to hwp)
//   1.29  | pardeik  |12-FEB-15| CDIMM DDR4 throttle updates (set Nmba to Nchip)
//   1.28  | pardeik  |01-DEC-14| Gerrit review updates
//         |          |         |   changed MAX_UTIL to max_util
//         |          |         |   changed MIN_UTIL const to min_util float
//         |          |         |   changed IDLE_UTIL const to idle_util float
//   1.27  | pardeik  |13-NOV-14| initialize l_channel_power_intercept and 
//         |          |         | l_channel_power_slope to zero to prevent 
//         |          |         | compile errors
//   1.26  | pardeik  |05-NOV-14| removed strings in trace statements
//         |          |         | changed FAPI_IMP to FAPI_INF
//   1.25  | pardeik  |31-OCT-14| change ISDIMM_MEMORY_THROTTLE_PERCENT to 65
//   1.24  | pardeik  |31-OCT-14| fixed equation using ISDIMM_MEMORY_THROTTLE_PERCENT
//         |          |         | use power instead of utilization for error check
//         |          |         |  RC_MSS_NOT_ENOUGH_AVAILABLE_DIMM_POWER
//   1.23  | pardeik  |27-OCT-14| Change to not call mss_power_to_throttle_calc
//         |          |         | Make throttle determination more efficient
//         |          |         | Non Custom DIMMs use hardcoded values and do
//         |          |         |   not use power curves for these
//         |          |         | Remove mss_throttle_to_power.H include
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
	fapi::ReturnCode rc = fapi::FAPI_RC_SUCCESS;

	FAPI_INF("*** Running mss_bulk_pwr_throttles ***");

	const uint8_t MAX_NUM_PORTS = 2;
	const uint8_t MAX_NUM_DIMMS = 2;
	float idle_util = 0; // in percent
	float min_util = 1; // in percent
// These are the constants to use for ISDIMM power/throttle support
// Note that these are hardcoded and ISDIMMs will not use power curves
// No Throttling if available power is >= ISDIMM_MAX_DIMM_POWER
// Throttle when ISDIMM_MIN_DIMM_POWER <= available power <= ATTR_MSS_MEM_WATT_TARGET
//   Throttle value will be maximum throttle * ISDIMM_MEMORY_THROTTLE_PERCENT
	const uint32_t ISDIMM_MAX_DIMM_POWER = 1200;  // cW, max ISDIMM power for no throttling
	const uint32_t ISDIMM_MIN_DIMM_POWER = 800;   // cW, min ISDIMM power for throttling
	const uint8_t ISDIMM_MEMORY_THROTTLE_PERCENT = 65;  // percent, throttle impact when limit is between min and max power.  A value of 0 would be for no throttle impact.

	uint32_t l_power_slope_array[MAX_NUM_PORTS][MAX_NUM_DIMMS];
	uint32_t l_power_int_array[MAX_NUM_PORTS][MAX_NUM_DIMMS];
	uint8_t l_dimm_ranks_array[MAX_NUM_PORTS][MAX_NUM_DIMMS];
	uint8_t l_port;
	uint8_t l_dimm;
	float l_dimm_power_array_idle[MAX_NUM_PORTS][MAX_NUM_DIMMS];
	float l_dimm_power_array_max[MAX_NUM_PORTS][MAX_NUM_DIMMS];
	float l_channel_power_array_idle[MAX_NUM_PORTS];
	float l_channel_power_array_max[MAX_NUM_PORTS];
	uint8_t l_power_curve_percent_uplift;
	uint8_t l_power_curve_percent_uplift_idle;
	uint32_t l_max_dram_databus_util;
	uint8_t l_num_mba_with_dimms;
	uint8_t l_custom_dimm;
	fapi::Target l_target_chip;
	std::vector<fapi::Target> l_target_mba_array;
	std::vector<fapi::Target> l_target_dimm_array;
	uint8_t l_mba_index;
	uint32_t l_throttle_d;
	float l_channel_pair_power_idle;
	float l_channel_pair_power_max;
	uint32_t l_channel_pair_watt_target;
	float l_utilization;
	uint32_t l_number_of_dimms;
	float l_channel_power_slope = 0;
	float l_channel_power_intercept = 0;
	uint32_t l_throttle_n_per_mba;
	uint32_t l_throttle_n_per_chip;
	uint32_t channel_pair_power;
	uint32_t runtime_throttle_n_per_mba;
	uint32_t runtime_throttle_n_per_chip;
	uint8_t l_dram_gen;

// get input attributes
	rc = FAPI_ATTR_GET(ATTR_EFF_CUSTOM_DIMM, &i_target_mba, l_custom_dimm);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_CUSTOM_DIMM");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_MRW_MAX_DRAM_DATABUS_UTIL,
			   NULL, l_max_dram_databus_util);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MRW_MAX_DRAM_DATABUS_UTIL");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_MRW_MEM_THROTTLE_DENOMINATOR, NULL, l_throttle_d);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MRW_MEM_THROTTLE_DENOMINATOR");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_MSS_MEM_WATT_TARGET,
			   &i_target_mba, l_channel_pair_watt_target);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MSS_MEM_WATT_TARGET");
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
	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN,
			   &i_target_mba, l_dram_gen);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_DRAM_GEN");
	    return rc;
	}

// other attributes for custom dimms to get
	if (l_custom_dimm == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)
	{
	    rc = FAPI_ATTR_GET(ATTR_MRW_DIMM_POWER_CURVE_PERCENT_UPLIFT,
			       NULL, l_power_curve_percent_uplift);
	    if (rc) {
		FAPI_ERR("Error getting attribute ATTR_MRW_DIMM_POWER_CURVE_PERCENT_UPLIFT");
		return rc;
	    }
	    rc = FAPI_ATTR_GET(ATTR_MRW_DIMM_POWER_CURVE_PERCENT_UPLIFT_IDLE,
			       NULL, l_power_curve_percent_uplift_idle);
	    if (rc) {
		FAPI_ERR("Error getting attribute ATTR_MRW_DIMM_POWER_CURVE_PERCENT_UPLIFT_IDLE");
		return rc;
	    }
	    rc = FAPI_ATTR_GET(ATTR_MSS_POWER_SLOPE,
			       &i_target_mba, l_power_slope_array);
	    if (rc) {
		FAPI_ERR("Error getting attribute ATTR_MSS_POWER_SLOPE");
		return rc;
	    }
	    rc = FAPI_ATTR_GET(ATTR_MSS_POWER_INT,
			       &i_target_mba, l_power_int_array);
	    if (rc) {
		FAPI_ERR("Error getting attribute ATTR_MSS_POWER_INT");
		return rc;
	    }
	    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM,
			       &i_target_mba, l_dimm_ranks_array);
	    if (rc) {
		FAPI_ERR("Error getting attribute ATTR_EFF_NUM_RANKS_PER_DIMM");
		return rc;
	    }
	}

// Maximum theoretical data bus utilization (percent of max) (for ceiling)
// Comes from MRW value in c% - convert to %
	float max_util = (float) l_max_dram_databus_util / 100;

// determine the dimm power
// For custom dimms, use the VPD power curve data
	if (l_custom_dimm == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)
	{
// get number of mba's with dimms
// Get Centaur target for the given MBA
	    rc = fapiGetParentChip(i_target_mba, l_target_chip);
	    if (rc) {
		FAPI_ERR("Error calling fapiGetParentChip");
		return rc;
	    }
// Get MBA targets from the parent chip centaur
	    rc = fapiGetChildChiplets(l_target_chip,
				      fapi::TARGET_TYPE_MBA_CHIPLET,
				      l_target_mba_array,
				      fapi::TARGET_STATE_PRESENT);
	    if (rc) {
		FAPI_ERR("Error calling fapiGetChildChiplets");
		return rc;
	    }
	    l_num_mba_with_dimms = 0;
	    for (l_mba_index=0; l_mba_index < l_target_mba_array.size(); l_mba_index++)
	    {
		rc = fapiGetAssociatedDimms(l_target_mba_array[l_mba_index],
					    l_target_dimm_array,
					    fapi::TARGET_STATE_PRESENT);
		if (rc) {
		    FAPI_ERR("Error calling fapiGetAssociatedDimms");
		    return rc;
		}
		if (l_target_dimm_array.size() > 0)
		{
		    l_num_mba_with_dimms++;
		}
	    }

// add up the power from all dimms for this MBA (across both channels)
// for IDLE (utilization=0) and maximum utilization
	    l_channel_pair_power_idle = 0;
	    l_channel_pair_power_max = 0;
	    for (l_port = 0; l_port < MAX_NUM_PORTS; l_port++)
	    {
		l_channel_power_array_idle[l_port] = 0;
		l_channel_power_array_max[l_port] = 0;
		for (l_dimm=0; l_dimm < MAX_NUM_DIMMS; l_dimm++)
		{
// default dimm power is zero (used for dimms that are not physically present)
		    l_dimm_power_array_idle[l_port][l_dimm] = 0;
		    l_dimm_power_array_max[l_port][l_dimm] = 0;
// See if there are any ranks present on the dimm (configured or deconfigured)
		    if (l_dimm_ranks_array[l_port][l_dimm] > 0)
		    {
			l_dimm_power_array_idle[l_port][l_dimm] = l_dimm_power_array_idle[l_port][l_dimm] + (idle_util / 100 * l_power_slope_array[l_port][l_dimm]) + l_power_int_array[l_port][l_dimm];
			l_dimm_power_array_max[l_port][l_dimm] = l_dimm_power_array_max[l_port][l_dimm] + (max_util / 100 * l_power_slope_array[l_port][l_dimm]) + l_power_int_array[l_port][l_dimm];
		    }
// Include any system uplift here too
		    if (l_dimm_power_array_idle[l_port][l_dimm] > 0)
		    {
			l_dimm_power_array_idle[l_port][l_dimm] =
			  l_dimm_power_array_idle[l_port][l_dimm] *
			       (1 + (float)l_power_curve_percent_uplift_idle / 100);
		    }
		    if (l_dimm_power_array_max[l_port][l_dimm] > 0)
		    {
			l_dimm_power_array_max[l_port][l_dimm] =
			  l_dimm_power_array_max[l_port][l_dimm] *
			       (1 + (float)l_power_curve_percent_uplift / 100);
		    }
// calculate channel power by adding up the power of each dimm
		    l_channel_power_array_idle[l_port] = l_channel_power_array_idle[l_port] + l_dimm_power_array_idle[l_port][l_dimm];
		    l_channel_power_array_max[l_port] = l_channel_power_array_max[l_port] + l_dimm_power_array_max[l_port][l_dimm];
		    FAPI_DBG("[P%d:D%d][CH Util %4.2f/%4.2f][Slope:Int %d:%d][UpliftPercent idle/max %d/%d)][Power min/max %4.2f/%4.2f cW]", l_port, l_dimm, idle_util, max_util, l_power_slope_array[l_port][l_dimm], l_power_int_array[l_port][l_dimm], l_power_curve_percent_uplift_idle, l_power_curve_percent_uplift, l_dimm_power_array_idle[l_port][l_dimm], l_dimm_power_array_max[l_port][l_dimm]);
		}
		FAPI_DBG("[P%d][CH Util %4.2f/%4.2f][Power %4.2f/%4.2f cW]", l_port, min_util, max_util, l_channel_power_array_idle[l_port], l_channel_power_array_max[l_port]);
		l_channel_pair_power_idle = l_channel_pair_power_idle + l_channel_power_array_idle[l_port];
		l_channel_pair_power_max = l_channel_pair_power_max + l_channel_power_array_max[l_port];
	    }

// calculate the slope/intercept values from power values just calculated above
	    l_channel_power_slope = (l_channel_pair_power_max - l_channel_pair_power_idle) / ( (max_util / 100) - (idle_util / 100) );
	    l_channel_power_intercept = l_channel_pair_power_idle;

// calculate the utilization needed to be under power limit
	    l_utilization = 0;
	    if (l_channel_pair_watt_target > l_channel_power_intercept)
	    {
		l_utilization = (l_channel_pair_watt_target - l_channel_power_intercept) / l_channel_power_slope * 100;
		if (l_utilization > max_util)
		{
		    l_utilization = max_util;
		}
	    }

// Calculate the NperChip and NperMBA Throttles
	    l_throttle_n_per_chip = int((l_utilization / 100 * l_throttle_d / 4) * l_num_mba_with_dimms);
	    if (l_throttle_n_per_chip > (max_util / 100 * l_throttle_d / 4) )
	    {
		l_throttle_n_per_mba = int((max_util / 100 * l_throttle_d / 4));
	    }
	    else
	    {
		l_throttle_n_per_mba = l_throttle_n_per_chip;
	    }

// Calculate the channel power at the utilization determined
	    channel_pair_power = int(l_utilization / 100 * l_channel_power_slope + l_channel_power_intercept);

	FAPI_DBG("[Channel Pair Power min/max %4.2f/%4.2f cW][Slope/Intercept %4.2f/%4.2f cW][Utilization Percent %4.2f, Power %d cW]", l_channel_pair_power_idle, l_channel_pair_power_max, l_channel_power_slope, l_channel_power_intercept, l_utilization, channel_pair_power);
	}

// for non custom dimms, use hardcoded values
// If power limit is at or above max power, use unthrottled settings
// If between min and max power, use a static throttle point
// If below min power, return an error
	else
	{
// get number of dimms attached to this mba
	    rc = fapiGetAssociatedDimms(i_target_mba,
					l_target_dimm_array,
					fapi::TARGET_STATE_PRESENT);
	    if (rc) {
		FAPI_ERR("Error calling fapiGetAssociatedDimms");
		return rc;
	    }
	    l_number_of_dimms = l_target_dimm_array.size();

// ISDIMMs, set to a value of one since throttles are handled on a per MBA basis
	    l_num_mba_with_dimms = 1;

// MBA Power Limit is higher than dimm power, run unthrottled
	    if (l_channel_pair_watt_target >= (ISDIMM_MAX_DIMM_POWER * l_number_of_dimms))
	    {
		l_utilization = max_util;
		channel_pair_power = ISDIMM_MAX_DIMM_POWER * l_number_of_dimms;
	    }
	    else if (l_channel_pair_watt_target >= (ISDIMM_MIN_DIMM_POWER * l_number_of_dimms))
	    {
		if (ISDIMM_MEMORY_THROTTLE_PERCENT > 99)
		{
		    l_utilization = min_util;
		}
		else
		{
		    l_utilization = max_util * (1 - (float)ISDIMM_MEMORY_THROTTLE_PERCENT / 100);
		}
		channel_pair_power = ISDIMM_MIN_DIMM_POWER * l_number_of_dimms;
	    }
	    else
	    {
		// error case, available power less than allocated minimum dimm power
		l_utilization = 0;
		channel_pair_power = ISDIMM_MIN_DIMM_POWER * l_number_of_dimms;
	    }
	    l_throttle_n_per_mba = int(l_utilization / 100 * l_throttle_d / 4);
	    l_throttle_n_per_chip = l_throttle_n_per_mba;

	FAPI_DBG("[Power/DIMM min/max %d/%d cW][Utilization Percent %4.2f][Number of DIMMs %d]", ISDIMM_MIN_DIMM_POWER, ISDIMM_MAX_DIMM_POWER, l_utilization, l_number_of_dimms);

	}

// adjust the throttles to minimum utilization if needed
	if (l_utilization < min_util)
	{
	    l_throttle_n_per_mba = int(min_util / 100 * l_throttle_d / 4);
	    l_throttle_n_per_chip = l_throttle_n_per_mba * l_num_mba_with_dimms;
	}

// ensure that N throttle values are not zero, if so set to lowest values possible
	if ( (l_throttle_n_per_mba == 0) || (l_throttle_n_per_chip == 0))
	{
	    l_throttle_n_per_mba = 1;
	    l_throttle_n_per_chip = l_throttle_n_per_mba * l_num_mba_with_dimms;
	}

// for better custom dimm performance for DDR4, set the per mba throttle to the per chip throttle
// Not planning on doing this for DDR3
	if ( (l_dram_gen == fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR4)
	     && (l_custom_dimm == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES) )
	    {
		l_throttle_n_per_mba = l_throttle_n_per_chip;
	    }

// adjust the throttles to the MRW thermal limit throttles (ie.  thermal/power limit less than available power)
	if ( (l_throttle_n_per_mba > runtime_throttle_n_per_mba) ||
	     (l_throttle_n_per_chip > runtime_throttle_n_per_chip) )
	{
	    FAPI_DBG("Throttles [%d/%d/%d] will be limited by power/thermal limit [%d/%d/%d].", l_throttle_n_per_mba, l_throttle_n_per_chip, l_throttle_d, runtime_throttle_n_per_mba, runtime_throttle_n_per_chip, l_throttle_d);
	    if (l_throttle_n_per_mba > runtime_throttle_n_per_mba) {
		l_throttle_n_per_mba = runtime_throttle_n_per_mba;
	    }
	    if (l_throttle_n_per_chip > runtime_throttle_n_per_chip) {
		l_throttle_n_per_chip = runtime_throttle_n_per_chip;
	    }
	    
	}

// Calculate out the utilization at the final throttle settings
	l_utilization = (float)l_throttle_n_per_chip * 4 / l_throttle_d / l_num_mba_with_dimms * 100;

// Calculate out the utilization at this new utilization setting for custom dimms
// does not matter for non custom dimms since those do not use power curves
	if (l_custom_dimm == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)
	{
	    channel_pair_power = int(l_utilization / 100 * l_channel_power_slope + l_channel_power_intercept);
	}

	FAPI_INF("[Available Channel Pair Power %d cW][UTIL %4.2f][Channel Pair Power %d cW][Throttles %d/%d/%d]", l_channel_pair_watt_target, l_utilization, channel_pair_power, l_throttle_n_per_mba, l_throttle_n_per_chip, l_throttle_d);

// Update output attributes
	rc = FAPI_ATTR_SET(ATTR_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA,
			   &i_target_mba, l_throttle_n_per_mba);
	if (rc) {
	    FAPI_ERR("Error writing attribute ATTR_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA");
	    return rc;
	}
	rc = FAPI_ATTR_SET(ATTR_MSS_MEM_THROTTLE_NUMERATOR_PER_CHIP,
			   &i_target_mba, l_throttle_n_per_chip);
	if (rc) {
	    FAPI_ERR("Error writing attribute ATTR_MSS_MEM_THROTTLE_NUMERATOR_PER_CHIP");
	    return rc;
	}
	rc = FAPI_ATTR_SET(ATTR_MSS_MEM_THROTTLE_DENOMINATOR,
			   &i_target_mba, l_throttle_d);
	if (rc) {
	    FAPI_ERR("Error writing attribute ATTR_MSS_MEM_THROTTLE_DENOMINATOR");
	    return rc;
	}
	rc = FAPI_ATTR_SET(ATTR_MSS_CHANNEL_PAIR_MAXPOWER,
			   &i_target_mba, channel_pair_power);
	if (rc) {
	    FAPI_ERR("Error writing attribute ATTR_MSS_CHANNEL_PAIR_MAXPOWER");
	    return rc;
	}

// Check to see if there is not enough available power at min_util or higher
	if (channel_pair_power > l_channel_pair_watt_target)
	{
	    FAPI_ERR("Not enough available memory power [Channel Pair Power %d/%d cW]", channel_pair_power, l_channel_pair_watt_target);
	    const uint32_t & PAIR_POWER = channel_pair_power;
	    const uint32_t & PAIR_WATT_TARGET = l_channel_pair_watt_target;
	    const fapi::Target & MEM_MBA = i_target_mba;
	    FAPI_SET_HWP_ERROR(rc, RC_MSS_NOT_ENOUGH_AVAILABLE_DIMM_POWER);
	    return rc;

	}

	FAPI_INF("*** mss_bulk_pwr_throttles COMPLETE ***");
	return rc;

    }

} //end extern C


