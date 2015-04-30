/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_eff_config_thermal.C $ */
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
// $Id: mss_eff_config_thermal.C,v 1.31 2015/04/06 22:33:11 pardeik Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/
//          centaur/working/procedures/ipl/fapi/mss_eff_config_thermal.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_eff_config_thermal
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Michael Pardeik   Email: pardeik@us.ibm.com
// *! BACKUP NAME : Jacob Sloat       Email: jdsloat@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// applicable CQ component memory_screen
//
// DESCRIPTION:
// The purpose of this procedure is to set the default throttle and power
// attributes for dimms in a given system
// -- The power attributes are the slope/intercept values.  Note that these
//    values are in cW.
//    -- ISDIMM will calculate values based on various attributes
//    -- CDIMM will get values from VPD
// -- The throttle attributes will setup values for IPL and runtime
//
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.31  | pardeik  | 04/06/15 | attribute name changed for adjustment enable
//   1.30  | pardeik  |12-FEB-15| CDIMM DDR4 throttle updates (set Nmba to Nchip)
//         |          |         | Support for vmem regulator power adjustment
//   1.29  | pardeik  |06-NOV-14| removed strings in trace statements
//         |          |         | changed FAPI_IMP to FAPI_INF
//         |          |         | removed unused constants
//   1.28  | pardeik  |28-OCT-14| Updates for non custom dimm power procedure
//         |          |         |  Removed mss_eff_config_thermal_term
//         |          |         |  Removed mss_eff_config_thermal_get_wc_term
//         |          |         |  Removed mss_eff_config_thermal_get_cen_drv_value
//         |          |         |  Updates to mss_eff_config_thermal_powercurve
//   1.27  | pardeik  |22-MAY-14| Removed attribute update section not needed
//         |          |         | Initialize runtime throttle attributes before
//         |          |         |   calling bulk_pwr_throttles
//         |          |         | RAS update to split code into smaller
//         |          |         |   subfunctions (powercurve and throttles)
//   1.26  | jdsloat  |10-MAR-14| Edited comments
//   1.25  | pardeik  |21-JAN-14| fixed default power curve values for CDIMM
//         |          |         | removed unneeded comments
//   1.24  | pardeik  |20-DEC-13| only get power curve attributes if custom dimm
//   1.23  | pardeik  |02-DEC-13| enable supplier power curve attributes
//   1.22  | pardeik  |18-NOV-13| rename attributes (eff to vpd)
//   1.21  | pardeik  |14-NOV-13| hardcode supplier power curves until lab is
//         |          |         | using read VPD
//   1.20  | pardeik  |13-NOV-13| enable power curve attribute data from VPD
//   1.19  | pardeik  |23-SEP-13| initial support for the ras/cas increments
//   1.18  | bellows  |19-SEP-13| fixed possible buffer overrun found by stradale
//   1.17  | pardeik  |19-JUL-13| Use runtime throttles for IPL for scominit
//         |          |         | Removed MRW safemode throttle stuff
//         |          |         | Always determine runtime throttles now
//   1.16  | pardeik  |08-JUL-13| Using CUSTOM_DIMM attribute
//         |          |         | Initialize some termination variables to zero
//         |          |         | changed handling of TYPE_1D
//         |          |         | only get NUM_OF_REGISTERS_USED_ON_RDIMM 
//         |          |         |   for RDIMM (non custom)
//         |          |         | get thermal power limit from MRW
//   1.15  | pardeik  |11-FEB-13| set safemode throttles to unthrottled value
//         |          |         | for lab until fw sets runtime throttles
//   1.14  | pardeik  |03-DEC-12| update lines to have a max width of 80 chars
//         |          |         | added FAPI_ERR before return code lines
//         |          |         | made trace statements for procedures FAPI_IMP
//         |          |         | changed some FAPI_INF to FAPI_DBG
//         |          |         | set per_chip safemode throttles to 32
//         |          |         | updates for FAPI_SET_HWP_ERROR
//   1.13  | pardeik  |28-NOV-12| fixed hostboot compile errors
//   1.12  | pardeik  |07-NOV-12| updated to use new SI attributes and their
//         |          |         | enums
//   1.11  | pardeik  |22-OCT-12| Use the schmoo attributes to find wc
//         |          |         | termination, updated hwp errors, removed
//         |          |         | unneeded variables, added CQ component comment
//         |          |         | line, updated safemode throttle default values
//   1.10  | pardeik  |19-OCT-12| Enable TYPE_1D for ODT mapping.  Set ISDIMM
//         |          |         | supplier power curve to master power curve
//   1.9   | pardeik  |11-OCT-12| updated to use new attributes, termination
//         |          |         | power calculation added in
//   1.8   | pardeik  |13-JUN-12| Major rewrite to have dimm power determined by
//         |          |         | dram generation and width, with uplifts
//         |          |         | applied (not based on dimm size lookup table
//         |          |         | any longer)
//   1.7   | pardeik  |04-MAY-12| removed typedef from structures, use fapi to
//         |          |         | define dimm type enums
//   1.6   | pardeik  |10-APR-12| update cdimm power/int default, change
//         |          |         | power_thermal_values_t to use int32_t instead
//         |          |         | of uint32_t in order to identify a negative
//         |          |         | value correctly, added dimm config to the
//         |          |         | messages printed out
//   1.5   | pardeik  |03-APR-12| fix cdimm size/rank addition to cycle through
//         |          |         | both mba's
//   1.4   | pardeik  |26-MAR-12| Rewrite to iterate through the MBA's using
//         |          |         | fapi functions
//         | pardeik  |01-DEC-11| Updated to align with procedure definition
//   1.3   | asaetow  |03-NOV-11| Fixed to comply with mss_eff_config_thermal.H
//   1.2   | asaetow  |03-NOV-11| Changed format of file and made function lower
//         |          |         | case. 
//   1.1   | pardeik  |01-NOV-11| First Draft.

/*
TODO ITEMS:
1.  Update ISDIMM power table after hardware measurements are done (GA3)
*/

//------------------------------------------------------------------------------
//  My Includes
//------------------------------------------------------------------------------
#include <mss_eff_config_thermal.H>
#include <mss_bulk_pwr_throttles.H>

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapi.H>

//------------------------------------------------------------------------------
//  Constants
//------------------------------------------------------------------------------
const uint8_t NUM_PORTS = 2;
const uint8_t NUM_DIMMS = 2;
const uint8_t NUM_RANKS = 4;
// Only use values here (not any valid bits or flag bits)
const uint32_t CDIMM_POWER_SLOPE_DEFAULT = 0x0240;
const uint32_t CDIMM_POWER_INT_DEFAULT = 0x00CE;

extern "C" {

    using namespace fapi;

//------------------------------------------------------------------------------
// Funtions in this file
//------------------------------------------------------------------------------
    fapi::ReturnCode mss_eff_config_thermal(
					    const fapi::Target & i_target_mba
					    );

    fapi::ReturnCode mss_eff_config_thermal_powercurve(
					    const fapi::Target & i_target_mba
					    );

    fapi::ReturnCode mss_eff_config_thermal_throttles(
					    const fapi::Target & i_target_mba
					    );


//------------------------------------------------------------------------------
// @brief mss_eff_config_thermal(): This function determines the
// power curve and throttle attribute values to use
//
// @param[in]	const fapi::Target & i_target_mba:  MBA Target passed in
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------

    fapi::ReturnCode mss_eff_config_thermal(const fapi::Target & i_target_mba)
    {
	fapi::ReturnCode rc = fapi::FAPI_RC_SUCCESS;

	FAPI_INF("*** Running mss_eff_config_thermal on %s ***",
		 i_target_mba.toEcmdString());

	rc = mss_eff_config_thermal_powercurve(i_target_mba);
	if (rc)
	{
	    FAPI_ERR("Error (0x%x) calling mss_eff_config_thermal_powercurve", static_cast<uint32_t>(rc));
	    return rc;
	}
	rc = mss_eff_config_thermal_throttles(i_target_mba);
	if (rc)
	{
	    FAPI_ERR("Error (0x%x) calling mss_eff_config_thermal_throttles", static_cast<uint32_t>(rc));
	    return rc;
	}


	FAPI_INF("*** mss_eff_config_thermal COMPLETE on %s ***",
		 i_target_mba.toEcmdString());
	return rc;
    }

//------------------------------------------------------------------------------
// @brief mss_eff_config_thermal_powercurve(): This function determines the
// power curve attribute values to use
//
// @param[in]	const fapi::Target & i_target_mba:  MBA Target passed in
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------

    fapi::ReturnCode mss_eff_config_thermal_powercurve(const fapi::Target & i_target_mba)
    {
	fapi::ReturnCode rc = fapi::FAPI_RC_SUCCESS;

	FAPI_INF("*** Running mss_eff_config_thermal_powercurve on %s ***",
		 i_target_mba.toEcmdString());

// other variables used in this function
	fapi::Target target_chip;
	uint8_t port;
	uint8_t dimm;
	uint8_t custom_dimm;
	uint8_t dimm_ranks_array[NUM_PORTS][NUM_DIMMS];
	uint32_t power_slope_array[NUM_PORTS][NUM_DIMMS];
	uint32_t power_int_array[NUM_PORTS][NUM_DIMMS];
	uint32_t power_slope2_array[NUM_PORTS][NUM_DIMMS];
	uint32_t power_int2_array[NUM_PORTS][NUM_DIMMS];
	uint32_t cdimm_master_power_slope;
	uint32_t cdimm_master_power_intercept;
	uint32_t cdimm_supplier_power_slope;
	uint32_t cdimm_supplier_power_intercept;


//------------------------------------------------------------------------------
// Get input attributes
//------------------------------------------------------------------------------

// Get Centaur target for the given MBA
	rc = fapiGetParentChip(i_target_mba, target_chip);
	if (rc) {
	    FAPI_ERR("Error from fapiGetParentChip");
	    return rc;
	}

	rc = FAPI_ATTR_GET(ATTR_EFF_CUSTOM_DIMM, &i_target_mba, custom_dimm);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_CUSTOM_DIMM");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM,
			   &i_target_mba, dimm_ranks_array);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_NUM_RANKS_PER_DIMM");
	    return rc;
	}
	// Only get power curve values for custom dimms to prevent errors
	if (custom_dimm == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)
	{
	    rc = FAPI_ATTR_GET(ATTR_CDIMM_VPD_MASTER_POWER_SLOPE,
			       &target_chip, cdimm_master_power_slope);
	    if (rc) {
		FAPI_ERR("Error getting attribute ATTR_CDIMM_VPD_MASTER_POWER_SLOPE");
		return rc;
	    }
	    rc = FAPI_ATTR_GET(ATTR_CDIMM_VPD_MASTER_POWER_INTERCEPT,
			       &target_chip, cdimm_master_power_intercept);
	    if (rc) {
		FAPI_ERR("Error getting attribute ATTR_CDIMM_VPD_MASTER_POWER_INTERCEPT");
		return rc;
	    }

	    rc = FAPI_ATTR_GET(ATTR_CDIMM_VPD_SUPPLIER_POWER_SLOPE,
			       &target_chip, cdimm_supplier_power_slope);
	    if (rc) {
		FAPI_ERR("Error getting attribute ATTR_CDIMM_VPD_SUPPLIER_POWER_SLOPE");
		return rc;
	    }
	    rc = FAPI_ATTR_GET(ATTR_CDIMM_VPD_SUPPLIER_POWER_INTERCEPT,
			       &target_chip, cdimm_supplier_power_intercept);
	    if (rc) {
		FAPI_ERR("Error getting attribute ATTR_CDIMM_VPD_SUPPLIER_POWER_INTERCEPT");
		return rc;
	    }
	}

//------------------------------------------------------------------------------
// Power Curve Determination
//------------------------------------------------------------------------------
// Iterate through the MBA ports to get power slope/intercept values
	for (port=0; port < NUM_PORTS; port++)
	{
// iterate through the dimms on each port again to determine power slope and
// intercept
	    for (dimm=0; dimm < NUM_DIMMS; dimm++)
	    {
// initialize dimm entries to zero
		power_slope_array[port][dimm] = 0;
		power_int_array[port][dimm] = 0;
		power_slope2_array[port][dimm] = 0;
		power_int2_array[port][dimm] = 0;
// only update values for dimms that are physically present
		if (dimm_ranks_array[port][dimm] > 0)
		{

// CDIMM power slope/intercept will come from VPD
// Data in VPD needs to be the power per virtual dimm on the CDIMM
		    if (custom_dimm == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)
		    {
			power_slope_array[port][dimm] =
			  cdimm_master_power_slope;
			power_int_array[port][dimm] =
			  cdimm_master_power_intercept;
			power_slope2_array[port][dimm] =
			  cdimm_supplier_power_slope;
			power_int2_array[port][dimm] =
			  cdimm_supplier_power_intercept;

// check to see if data is valid
			if (
			    (((cdimm_master_power_slope & 0x8000) != 0) &&
			     ((cdimm_master_power_intercept & 0x8000) != 0))
			    &&
			    (((cdimm_supplier_power_slope & 0x8000) != 0) &&
			     ((cdimm_supplier_power_intercept & 0x8000) != 0))
			    )
			{
			    power_slope_array[port][dimm] =
			      cdimm_master_power_slope & 0x1FFF;
			    power_int_array[port][dimm] =
			      cdimm_master_power_intercept & 0x1FFF;
			    power_slope2_array[port][dimm] =
			      cdimm_supplier_power_slope & 0x1FFF;
			    power_int2_array[port][dimm] =
			      cdimm_supplier_power_intercept & 0x1FFF;
// check to see if data is lab data
			    if (
				(((cdimm_master_power_slope & 0x4000) == 0) ||
				 ((cdimm_master_power_intercept & 0x4000) == 0))
				||
				(((cdimm_supplier_power_slope & 0x4000) == 0) ||
				 ((cdimm_supplier_power_intercept &
				   0x4000) == 0))
				)
			    {
				FAPI_INF("WARNING:  power curve data is lab data, not ship level data. Using data anyways.");
			    }
			}
			else
			{
			    power_slope_array[port][dimm] =
			      CDIMM_POWER_SLOPE_DEFAULT;
			    power_int_array[port][dimm] =
			      CDIMM_POWER_INT_DEFAULT;
			    power_slope2_array[port][dimm] =
			      CDIMM_POWER_SLOPE_DEFAULT;
			    power_int2_array[port][dimm] =
			      CDIMM_POWER_INT_DEFAULT;
			    FAPI_ERR("power curve data not valid, use default values");
			    const fapi::Target & MEM_CHIP = target_chip;
			    uint32_t FFDC_DATA_1 = cdimm_master_power_slope;
			    uint32_t FFDC_DATA_2 = cdimm_master_power_intercept;
			    uint32_t FFDC_DATA_3 = cdimm_supplier_power_slope;
			    uint32_t FFDC_DATA_4 =
			      cdimm_supplier_power_intercept;
			    FAPI_SET_HWP_ERROR
			      (rc, RC_MSS_DIMM_POWER_CURVE_DATA_INVALID);
			    if (rc) fapiLogError(rc);
			}
			FAPI_DBG("CDIMM Power [P%d:D%d][SLOPE=%d:INT=%d cW][SLOPE2=%d:INT2=%d cW]", port, dimm, power_slope_array[port][dimm], power_int_array[port][dimm], power_slope2_array[port][dimm], power_int2_array[port][dimm]);
		    }
// non custom dimms will no longer use power curves
// These will use a simplified approach of using throttle values for certain ranges of power
// in mss_bulk_pwr_throttles.
		}
	    }
	}

// write output attributes
	rc = FAPI_ATTR_SET(ATTR_MSS_POWER_SLOPE,
			   &i_target_mba, power_slope_array);
	if (rc) {
	    FAPI_ERR("Error writing attribute ATTR_MSS_POWER_SLOPE");
	    return rc;
	}
	rc = FAPI_ATTR_SET(ATTR_MSS_POWER_INT, &i_target_mba, power_int_array);
	if (rc) {
	    FAPI_ERR("Error writing attribute ATTR_MSS_POWER_INT");
	    return rc;
	}

	rc = FAPI_ATTR_SET(ATTR_MSS_POWER_SLOPE2,
			   &i_target_mba, power_slope2_array);
	if (rc) {
	    FAPI_ERR("Error writing attribute ATTR_MSS_POWER_SLOPE2");
	    return rc;
	}
	rc = FAPI_ATTR_SET(ATTR_MSS_POWER_INT2,
			   &i_target_mba, power_int2_array);
	if (rc) {
	    FAPI_ERR("Error writing attribute ATTR_MSS_POWER_INT2");
	    return rc;
	}

	FAPI_INF("*** mss_eff_config_thermal_powercurve COMPLETE on %s ***",
		 i_target_mba.toEcmdString());
	return rc;
    }

//------------------------------------------------------------------------------
// @brief mss_eff_config_thermal_throttles(): This function determines the
// throttle attribute values to use
//
// @param[in]	const fapi::Target & i_target_mba:  MBA Target passed in
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------

    fapi::ReturnCode mss_eff_config_thermal_throttles(const fapi::Target & i_target_mba)
    {
	fapi::ReturnCode rc = fapi::FAPI_RC_SUCCESS;

	FAPI_INF("*** Running mss_eff_config_thermal_throttles on %s ***",
		 i_target_mba.toEcmdString());

// variables used in this function
	fapi::Target target_chip;
	std::vector<fapi::Target> target_mba_array;
	std::vector<fapi::Target> target_dimm_array;
	uint8_t custom_dimm;
	uint8_t num_dimms_on_port;
	uint32_t runtime_throttle_n_per_mba;
	uint32_t runtime_throttle_n_per_chip;
	uint32_t runtime_throttle_d;
	uint32_t dimm_thermal_power_limit;
	uint32_t channel_pair_thermal_power_limit;
	uint8_t num_mba_with_dimms = 0;
	uint8_t mba_index;
	uint8_t ras_increment;
	uint8_t cas_increment;
	uint32_t l_max_dram_databus_util;
	uint32_t l_dimm_reg_power_limit_per_dimm_adj;
	uint32_t l_dimm_reg_power_limit_per_dimm;
	uint8_t l_max_number_dimms_per_reg;
	uint8_t l_dimm_reg_power_limit_adj_enable;
	uint8_t l_reg_max_dimm_count;
	uint8_t l_dram_gen;
//------------------------------------------------------------------------------
// Get input attributes
//------------------------------------------------------------------------------

// Get Centaur target for the given MBA
	rc = fapiGetParentChip(i_target_mba, target_chip);
	if (rc) {
	    FAPI_ERR("Error from fapiGetParentChip");
	    return rc;
	}

	rc = FAPI_ATTR_GET(ATTR_EFF_CUSTOM_DIMM, &i_target_mba, custom_dimm);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_CUSTOM_DIMM");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_NUM_DROPS_PER_PORT,
			   &i_target_mba, num_dimms_on_port);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_NUM_DROPS_PER_PORT");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_MRW_THERMAL_MEMORY_POWER_LIMIT,
			   NULL, dimm_thermal_power_limit);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MRW_THERMAL_MEMORY_POWER_LIMIT");
	    return rc;
	}

	rc = FAPI_ATTR_GET(ATTR_MRW_MEM_THROTTLE_DENOMINATOR, NULL, runtime_throttle_d);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MRW_MEM_THROTTLE_DENOMINATOR");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_MRW_MAX_DRAM_DATABUS_UTIL,
			   NULL, l_max_dram_databus_util);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MRW_MAX_DRAM_DATABUS_UTIL");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_MRW_VMEM_REGULATOR_MEMORY_POWER_LIMIT_PER_DIMM,
			   NULL, l_dimm_reg_power_limit_per_dimm);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MRW_VMEM_REGULATOR_MEMORY_POWER_LIMIT_PER_DIMM");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_MRW_MAX_NUMBER_DIMMS_POSSIBLE_PER_VMEM_REGULATOR,
			   NULL, l_max_number_dimms_per_reg);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MRW_MAX_NUMBER_DIMMS_POSSIBLE_PER_VMEM_REGULATOR");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_MRW_VMEM_REGULATOR_POWER_LIMIT_PER_DIMM_ADJ_ENABLE,
			   NULL, l_dimm_reg_power_limit_adj_enable);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MRW_VMEM_REGULATOR_POWER_LIMIT_PER_DIMM_ADJ_ENABLE");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_MSS_VMEM_REGULATOR_MAX_DIMM_COUNT,
			   NULL, l_reg_max_dimm_count);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MSS_VMEM_REGULATOR_MAX_DIMM_COUNT");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN,
			   &i_target_mba, l_dram_gen);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_DRAM_GEN");
	    return rc;
	}

// Get number of Centaur MBAs that have dimms present
// Custom dimms (CDIMMs) use mba/chip throttling, so count number of mbas that have dimms
	if (custom_dimm == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)
	{
	    rc = fapiGetChildChiplets(target_chip,
				      fapi::TARGET_TYPE_MBA_CHIPLET,
				      target_mba_array,
				      fapi::TARGET_STATE_PRESENT);
	    if (rc) {
		FAPI_ERR("Error from fapiGetChildChiplets");
		return rc;
	    }
	    num_mba_with_dimms = 0;
	    for (mba_index=0; mba_index < target_mba_array.size(); mba_index++)
	    {
		rc = fapiGetAssociatedDimms(target_mba_array[mba_index],
					    target_dimm_array,
					    fapi::TARGET_STATE_PRESENT);
		if (rc) {
		    FAPI_ERR("Error from fapiGetAssociatedDimms");
		    return rc;
		}
		if (target_dimm_array.size() > 0)
		{
		    num_mba_with_dimms++;
		}
	    }
	}
// ISDIMM (non custom dimm) uses dimm/mba throttling, so set num_mba_with_dimms to 1
	else
	{
	    num_mba_with_dimms = 1;
	}


//------------------------------------------------------------------------------
// Memory Throttle Determination
//------------------------------------------------------------------------------

// Determine memory throttle settings needed based on dimm thermal power limit

//------------------------------------------------------------------------------
// Determine the thermal power limit to use, which represents a single channel
// pair power limit for the dimms on that channel pair (ie.  power for all dimms
// attached to one MBA).   The procedure mss_bulk_power_throttles takes the
// input of channel pair power to determine throttles.
// CDIMM thermal power limit from MRW is per CDIMM, so divide by number of mbas
// that have dimms to get channel pair power
// CDIMM:  Allow all commands to be directed toward one MBA to achieve the power
// limit
//   This means that the power limit for a MBA channel pair must be the total
// CDIMM power limit minus the idle power of the other MBAs logical dimms
//------------------------------------------------------------------------------

// adjust the regulator power limit per dimm if enabled and use this if less than the thermal limit
	l_dimm_reg_power_limit_per_dimm_adj = l_dimm_reg_power_limit_per_dimm;
	if (l_dimm_reg_power_limit_adj_enable == fapi::ENUM_ATTR_MRW_VMEM_REGULATOR_POWER_LIMIT_PER_DIMM_ADJ_ENABLE_TRUE)
	{
// adjust reg power limit per cdimm only if l_reg_max_dimm_count>0 and l_reg_max_dimm_count<l_max_number_dimms_per_reg
	    if (
		(l_reg_max_dimm_count > 0)
		 && (l_reg_max_dimm_count < l_max_number_dimms_per_reg)
		)
	    {
		l_dimm_reg_power_limit_per_dimm_adj =
		  l_dimm_reg_power_limit_per_dimm
		  * l_max_number_dimms_per_reg
		  / l_reg_max_dimm_count;
		FAPI_INF("VMEM Regulator Power/DIMM Limit Adjustment from %d to %d cW (DIMMs under regulator %d/%d)", l_dimm_reg_power_limit_per_dimm, l_dimm_reg_power_limit_per_dimm_adj, l_reg_max_dimm_count, l_max_number_dimms_per_reg);
	    }
	}
// Use the smaller of the thermal limit and regulator power limit per dimm
	if (l_dimm_reg_power_limit_per_dimm_adj < dimm_thermal_power_limit)
	{
	    dimm_thermal_power_limit = l_dimm_reg_power_limit_per_dimm_adj;
	}

// Adjust the thermal/power limit to represent the power for all dimms under an MBA
	if (custom_dimm == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)
	{
	    channel_pair_thermal_power_limit =
	      dimm_thermal_power_limit / num_mba_with_dimms;
	}
// ISDIMMs thermal power limit from MRW is per DIMM, so multiply by number of dimms on channel to get channel power and multiply by 2 to get channel pair power
	else
	{
		// ISDIMMs
	    channel_pair_thermal_power_limit =
	      dimm_thermal_power_limit * num_dimms_on_port * 2;
	}

// Update the channel pair power limit attribute
	rc = FAPI_ATTR_SET(ATTR_MSS_MEM_WATT_TARGET,
			   &i_target_mba, channel_pair_thermal_power_limit);
	if (rc) {
	    FAPI_ERR("Error writing attribute ATTR_MSS_MEM_WATT_TARGET");
	    return rc;
	}

// Initialize the runtime throttle attributes to an unthrottled value for mss_bulk_pwr_throttles
// max utilization comes from MRW value in c% - convert to %
	float MAX_UTIL = (float) l_max_dram_databus_util / 100;
	runtime_throttle_n_per_mba = (int)(runtime_throttle_d * (MAX_UTIL / 100) / 4);
	runtime_throttle_n_per_chip = (int)(runtime_throttle_d * (MAX_UTIL / 100) / 4) *
	  num_mba_with_dimms;

// for better custom dimm performance for DDR4, set the per mba throttle to the per chip throttle
// Not planning on doing this for DDR3
	if ( (l_dram_gen == fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR4)
	     && (custom_dimm == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES) )
	{
	    runtime_throttle_n_per_mba = runtime_throttle_n_per_chip;
	}

	rc = FAPI_ATTR_SET(ATTR_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_MBA,
			   &i_target_mba, runtime_throttle_n_per_mba);
	if (rc) {
	    FAPI_ERR("Error writing attribute ATTR_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_MBA");
	    return rc;
	}
	rc = FAPI_ATTR_SET(ATTR_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_CHIP,
			   &i_target_mba, runtime_throttle_n_per_chip);
	if (rc) {
	    FAPI_ERR("Error writing attribute ATTR_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_CHIP");
	    return rc;
	}
	rc = FAPI_ATTR_SET(ATTR_MSS_RUNTIME_MEM_THROTTLE_DENOMINATOR,
			   &i_target_mba, runtime_throttle_d);
	if (rc) {
	    FAPI_ERR("Error writing attribute ATTR_MSS_RUNTIME_MEM_THROTTLE_DENOMINATOR");
	    return rc;
	}

	FAPI_INF("Min Power/Thermal Limit per MBA %d cW.  Unthrottled values [%d/%d/%d].", channel_pair_thermal_power_limit, runtime_throttle_n_per_mba, runtime_throttle_n_per_chip, runtime_throttle_d);

// Call the procedure function that takes a channel pair power limit and
// converts it to throttle values

	FAPI_EXEC_HWP(rc, mss_bulk_pwr_throttles, i_target_mba);
	if (rc)
	{
	    FAPI_ERR("Error (0x%x) calling mss_bulk_pwr_throttles", static_cast<uint32_t>(rc));
	    return rc;
	}

// Read back in the updated throttle attribute values (these are now set to
// values that will give dimm/channel power underneath the thermal power limit)
	rc = FAPI_ATTR_GET(ATTR_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA,
			   &i_target_mba, runtime_throttle_n_per_mba);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_MSS_MEM_THROTTLE_NUMERATOR_PER_CHIP,
			   &i_target_mba, runtime_throttle_n_per_chip);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MSS_MEM_THROTTLE_NUMERATOR_PER_CHIP");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_MSS_MEM_THROTTLE_DENOMINATOR,
			   &i_target_mba, runtime_throttle_d);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MSS_MEM_THROTTLE_DENOMINATOR");
	    return rc;
	}

// Setup the RAS and CAS increments used in the throttling register
	ras_increment=0;
	cas_increment=1;

// update output attributes
	rc = FAPI_ATTR_SET(ATTR_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_MBA,
			   &i_target_mba, runtime_throttle_n_per_mba);
	if (rc) {
	    FAPI_ERR("Error writing attribute ATTR_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_MBA");
	    return rc;
	}
	rc = FAPI_ATTR_SET(ATTR_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_CHIP,
			   &i_target_mba, runtime_throttle_n_per_chip);
	if (rc) {
	    FAPI_ERR("Error writing attribute ATTR_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_CHIP");
	    return rc;
	}
	rc = FAPI_ATTR_SET(ATTR_MSS_RUNTIME_MEM_THROTTLE_DENOMINATOR,
			   &i_target_mba, runtime_throttle_d);
	if (rc) {
	    FAPI_ERR("Error writing attribute ATTR_MSS_RUNTIME_MEM_THROTTLE_DENOMINATOR");
	    return rc;
	}
	rc = FAPI_ATTR_SET(ATTR_MSS_THROTTLE_CONTROL_RAS_WEIGHT,
			   &i_target_mba, ras_increment);
	if (rc) {
	    FAPI_ERR("Error writing attribute ATTR_MSS_THROTTLE_CONTROL_RAS_WEIGHT");
	    return rc;
	}
	rc = FAPI_ATTR_SET(ATTR_MSS_THROTTLE_CONTROL_CAS_WEIGHT,
			   &i_target_mba, cas_increment);
	if (rc) {
	    FAPI_ERR("Error writing attribute ATTR_MSS_THROTTLE_CONTROL_CAS_WEIGHT");
	    return rc;
	}

	FAPI_INF("*** mss_eff_config_thermal_throttles COMPLETE on %s ***",
		 i_target_mba.toEcmdString());
	return rc;
    }

} //end extern C
