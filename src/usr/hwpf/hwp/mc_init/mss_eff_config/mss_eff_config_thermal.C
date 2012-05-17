//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/mc_init/mss_eff_config/mss_eff_config_thermal.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
// $Id: mss_eff_config_thermal.C,v 1.7 2012/05/04 15:53:44 pardeik Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_eff_config_thermal.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_eff_config_thermal
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Joab Henderson    Email: joabhend@us.ibm.com
// *! BACKUP NAME : Michael Pardeik   Email: pardeik@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// DESCRIPTION:
// The purpose of this procedure is to set the default throttle and power attributes for dimms in a given system
// -- The throttles here are intended to be the thermal runtime throttles for dimm/channel N/M
// -- The power attributes are the slope/intercept values.  Note that these values are in cW.
// -- The values are determined by system based on power/thermal characterization
// -- Thermal values are system dependent and will need to come from the machine readable workbook
// -- Power values are going to be based on measurements and uplifted as needed based on voltage, frequency, termination, etc.
//
// TODO:
// 1.  Thermal attributes (IPL and Runtime Throttles) need to come from machine readable workbook
// 2.  Uplifts need to be done based on volt, freq, termination, etc.
// 3.  Power values need to be updated/added for the dimms that will be supported
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.7   | pardeik  |04-MAY-12| removed typedef from structures, use fapi to define dimm type enums
//   1.6   | pardeik  |10-APR-12| update cdimm power/int default, change power_thermal_values_t to use int32_t instead of uint32_t in order to identify a negative value correctly, added dimm config to the messages printed out
//   1.5   | pardeik  |03-APR-12| fix cdimm size/rank addition to cycle through both mba's
//   1.4   | pardeik  |26-MAR-12| Rewrite to iterate through the MBA's using fapi functions
//         | pardeik  |01-DEC-11| Updated to align with procedure definition
//   1.3   | asaetow  |03-NOV-11| Fixed to comply with mss_eff_config_thermal.H
//   1.2   | asaetow  |03-NOV-11| Changed format of file and made function lower case. 
//   1.1   | pardeik  |01-NOV-11| First Draft.


//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi.H>
#include <mss_eff_config_thermal.H>

extern "C" {

    using namespace fapi;

// Procedures in this file
    fapi::ReturnCode mss_eff_config_thermal(const fapi::Target & i_target);

//******************************************************************************
// 
//******************************************************************************

    fapi::ReturnCode mss_eff_config_thermal(const fapi::Target & i_target)
    {

	fapi::ReturnCode l_rc;

	char procedure_name[32];
	sprintf(procedure_name, "mss_eff_config_thermal");
	FAPI_INF("*** Running %s ***", procedure_name);

	enum
	{
	    CDIMM  = fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM,
	    RDIMM  = fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
	    UDIMM  = fapi::ENUM_ATTR_EFF_DIMM_TYPE_UDIMM,
	    LRDIMM = fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM,
	};

// number of dimms on channel/port
	enum
	{
	    SINGLEDROP = 0,
	    DOUBLEDROP = 1,
	    DIMM_CONFIG_TYPES = 2,	// count of all possible various dimm configurations on port
	};

// Structure type for the table that holds dimm power slope and intercept values
// use int32_t for slope and intercept in case values are entered wrong (ie.  negative values will then be flagged)
	struct power_thermal_values_t
	{
	    int32_t	power_slope;
	    int32_t	power_int;
	};
	struct power_thermal_data_t
	{
	    uint32_t			dimm_type;
	    uint32_t			dimm_size;
	    uint8_t			dimm_ranks;
	    power_thermal_values_t	data[DIMM_CONFIG_TYPES];
	};
// Default values defined here
	const uint8_t l_num_ports = 2;				// number of ports per MBA
	const uint8_t l_num_dimms = 2;				// number of dimms per MBA port
	const uint32_t l_dimm_power_slope_default = 800;	// default power slope for rdimm, udimm, lrdimm
	const uint32_t l_dimm_power_int_default = 900;		// default power intercept for rdimm, udimm, lrdimm
	const uint32_t l_cdimm_power_slope_default = 2000;	// default power slope for cdimm
	const uint32_t l_cdimm_power_int_default = 700;		// default power intercept for cdimm
	const uint32_t l_dimm_throttle_n_default = 100;		// default dimm throttle numerator
	const uint32_t l_dimm_throttle_d_default = 100;		// default dimm throttle denominator
	const uint32_t l_channel_throttle_n_default = 100;	// default channel throttle numerator
	const uint32_t l_channel_throttle_d_default = 100;	// default channel throttle denominator
// other variables used in this procedure
	uint8_t port;
	uint8_t dimm;
	uint8_t entry;
	uint8_t l_dimm_type;
	uint8_t l_dimm_size_array[l_num_ports][l_num_dimms];
	uint8_t l_dimm_ranks_array[l_num_ports][l_num_dimms];
	uint32_t l_half_cdimm_size = 0;
	uint8_t l_half_cdimm_ranks = 0;
	uint32_t l_list_sz;
	uint32_t l_power_slope_array[l_num_ports][l_num_dimms];
	uint32_t l_power_int_array[l_num_ports][l_num_dimms];
	uint32_t l_power_int_uplift;
	uint32_t l_dimm_throttle_n_array[l_num_ports][l_num_dimms];
	uint32_t l_dimm_throttle_d_array[l_num_ports][l_num_dimms];
	uint32_t l_channel_throttle_n_array[l_num_ports];
	uint32_t l_channel_throttle_d_array[l_num_ports];
	uint8_t l_found_entry_in_table;
	uint8_t l_dimm_config[l_num_ports];

// This sets up the power curve values for the DIMMs
// NOTE:  If a value of zero is in the slope or intercept fields, then the default settings will be used
// NOTE:  Power Slope and Intercept values are in cW
// NOTE:  For CDIMM, the power values need to be based on the dimm within the CDIMM (not based on power for whole CDIMM)
//    DIMM, Size, Ranks, Double drop config power slope and intercept, Single drop config power slope and intercept

	power_thermal_data_t l_power_thermal_values[]=
	{
//                                SINGLE       DOUBLE
//                                DROP         DROP
//	      Type,  Size, Ranks, slope,int,   slope,int
// RDIMMs - data from P7 based ISDIMMs (1066MHz and 1.35V)
	    { RDIMM,    2,  1, {{  522, 154}, {  526, 153}}},	// example RDIMM 2GB 1Rx8 2Gb
	    { RDIMM,    4,  2, {{  472, 187}, {  512, 182}}},	// example RDIMM 4GB 2Rx8 2Gb
	    { RDIMM,    4,  1, {{  472, 187}, {  512, 182}}},	// example RDIMM 4GB 1Rx8 4Gb
	    { RDIMM,    8,  4, {{  654, 274}, {  657, 262}}},	// example RDIMM 8GB 4Rx8 2Gb
	    { RDIMM,    8,  2, {{  654, 274}, {  657, 262}}},	// example RDIMM 8GB 2Rx4 2Gb OR 8GB 2Rx8 4Gb
	    { RDIMM,   16,  4, {{  770, 458}, {  738, 479}}},	// example RDIMM 16GB 4Rx4 2Gb
	    { RDIMM,   16,  2, {{  770, 458}, {  738, 479}}},	// example RDIMM 16GB 2Rx4 4Gb
	    { RDIMM,   32,  4, {{  770, 458}, {  738, 479}}},	// example RDIMM 32GB 4Rx4 4Gb
// CDIMMs - projections based on Warren's dimm support table + 3% spread + 10% uplift
// power values here are HALF of the cdimm power (since we handle one mba at a time) - need to divide this up and give each dimm an equal power amount
//                                    SingleDrop  DoubleDrop
//            TYPE   Size/X, Ranks/X, Slope,Int,  Slope, Int
// where X=number of MBA port pairs populated on CDIMM
	    { CDIMM,   16/2,  4/2, {{ 957, 153}, { 957, 153}}},	// example short CDIMM 16GB 4Rx8 4Gb OR 8GB 2Rx8 4Gb (Channel A/B populated)
	    { CDIMM,   32/2,  8/2, {{1130, 254}, {1130, 254}}},	// example short CDIMM 32GB 4Rx8 4Gb
	    { CDIMM,   64/2,  8/2, {{1763, 469}, {1763, 469}}},	// example short CDIMM 64GB 4Rx4 4Gb
	    { CDIMM,  128/2,  8/2, {{1763, 599}, {1763, 599}}},	// example  tall CDIMM 128GB 4Rx4 4Gb (2H 3DS)
// UDIMMs
// LRDIMMs
	};
	l_list_sz = (sizeof(l_power_thermal_values))/(sizeof(power_thermal_data_t));

// Get input attributes
	l_rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, l_dimm_type);
	if(l_rc) return l_rc;
	l_rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_SIZE, &i_target, l_dimm_size_array);
	if(l_rc) return l_rc;
	l_rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, l_dimm_ranks_array);
	if(l_rc) return l_rc;

// Add up DIMM Size and Ranks if a CDIMM - this will be for half of the cdimm - and dimm config for each mba port (1 or 2 dimms per channel)
	for (port=0; port < l_num_ports; port++)
	{
	    l_dimm_config[port] = 0;
	    for (dimm=0; dimm < l_num_dimms; dimm++)
	    {
		if ((l_dimm_type == CDIMM) && (l_dimm_ranks_array[port][dimm] > 0))
		{
		    l_half_cdimm_size = l_half_cdimm_size + l_dimm_size_array[port][dimm];
		    l_half_cdimm_ranks = l_half_cdimm_ranks + l_dimm_ranks_array[port][dimm];
		}
		if (l_dimm_ranks_array[port][dimm] > 0)
		{
		    l_dimm_config[port]++;
		}
	    }
	    if (l_dimm_config[port] == 1)
	    {
		l_dimm_config[port] = SINGLEDROP;
	    }
	    else if (l_dimm_config[port] == 2)
	    {
		l_dimm_config[port] = DOUBLEDROP;
	    }
	    else
	    {
		l_dimm_config[port] = DIMM_CONFIG_TYPES;
	    }
	}


// iterate through the MBA ports to define power and thermal attributes
	for (port=0; port < l_num_ports; port++)
	{
// initialize entries to zero
	    l_channel_throttle_n_array[port] = 0;
	    l_channel_throttle_d_array[port] = 0;
	    for (dimm=0; dimm < l_num_dimms; dimm++)
	    {
// initialize entries to zero
		l_dimm_throttle_n_array[port][dimm] = 0;
		l_dimm_throttle_d_array[port][dimm] = 0;
		l_power_slope_array[port][dimm] = 0;
		l_power_int_array[port][dimm] = 0;
// only update values for dimms that are physically present (with default value or table entry value)
		if (l_dimm_ranks_array[port][dimm] > 0)
		{
// TODO:  Placeholder for thermal attributes from machine readable workbook (runtime throttles) - Hardcode these for now.  IPL throttles will need to be added into an initfile once available.
// Can remove this section once infrastructure is in place to get these from the MRW (probably done in a different firmware procedure)
		    l_dimm_throttle_n_array[port][dimm] = l_dimm_throttle_n_default;
		    l_dimm_throttle_d_array[port][dimm] = l_dimm_throttle_d_default;
		    l_channel_throttle_n_array[port] = l_channel_throttle_n_default;
		    l_channel_throttle_d_array[port] = l_channel_throttle_d_default;
// Look up DIMM in Table, get size and ranks first, set slope/int to default values first in case entry is not found in table
// If table entry is less than zero, then set value to default values
		    if (l_dimm_type == CDIMM)
		    {
			l_dimm_size_array[port][dimm] = l_half_cdimm_size;
			l_dimm_ranks_array[port][dimm] = l_half_cdimm_ranks;
			l_power_slope_array[port][dimm] = l_cdimm_power_slope_default;
			l_power_int_array[port][dimm] = l_cdimm_power_int_default;
		    }
		    else
		    {
			l_power_slope_array[port][dimm] = l_dimm_power_slope_default;
			l_power_int_array[port][dimm] = l_dimm_power_int_default;
		    }
		    l_found_entry_in_table = 0;
		    for (entry = 0; entry < l_list_sz; entry++) {
			if ((l_power_thermal_values[entry].dimm_type == l_dimm_type) && (l_power_thermal_values[entry].dimm_size == l_dimm_size_array[port][dimm]) && (l_power_thermal_values[entry].dimm_ranks == l_dimm_ranks_array[port][dimm]))
			{
			    if ((l_power_thermal_values[entry].data[l_dimm_config[port]].power_slope > 0) && (l_power_thermal_values[entry].data[l_dimm_config[port]].power_int > 0))
			    {
				l_power_slope_array[port][dimm]=l_power_thermal_values[entry].data[l_dimm_config[port]].power_slope;
				l_power_int_array[port][dimm]=l_power_thermal_values[entry].data[l_dimm_config[port]].power_int;
				FAPI_INF("Found DIMM Entry in Power Table [%d:%d:%d:%d:%d:%d][%d:%d]", port, dimm, l_dimm_type, l_dimm_size_array[port][dimm], l_dimm_ranks_array[port][dimm], l_dimm_config[port], l_power_slope_array[port][dimm], l_power_int_array[port][dimm]);
			    }
			    else
			    {
				FAPI_ERR( "DIMM Entry in Power Table not greater than zero, so default values will be used [%d:%d:%d:%d:%d:%d][%d:%d]", port, dimm, l_dimm_type, l_dimm_size_array[port][dimm], l_dimm_ranks_array[port][dimm], l_dimm_config[port], l_power_slope_array[port][dimm], l_power_int_array[port][dimm]);
			    }
// break out since first match was found
			    l_found_entry_in_table = 1;
			    break;
			}
		    }
// Apply any uplifts to the Slope or intercept values based on various parameters if entry is found in table
// TODO:  What uplifts do we need to do (Frequency, Voltage, Termination, etc) - Use zero uplift for now.
		    if (l_found_entry_in_table == 1)
		    {
			l_power_int_uplift = 0;
			l_power_int_array[port][dimm] = l_power_int_array[port][dimm] + l_power_int_uplift;
		    }
// post error if entry was not found
		    else
		    {
			FAPI_ERR( "Failed to Find DIMM Entry in Power Table, so default values will be used [%d:%d:%d:%d:%d:%d][%d:%d]", port, dimm, l_dimm_type, l_dimm_size_array[port][dimm], l_dimm_ranks_array[port][dimm], l_dimm_config[port], l_power_slope_array[port][dimm], l_power_int_array[port][dimm] );
		    }
		}
	    }
	}
// write output attributes
	l_rc = FAPI_ATTR_SET(ATTR_MSS_POWER_SLOPE, &i_target, l_power_slope_array);
	if(l_rc) return l_rc;
	l_rc = FAPI_ATTR_SET(ATTR_MSS_POWER_INT, &i_target, l_power_int_array);
	if(l_rc) return l_rc;
	l_rc = FAPI_ATTR_SET(ATTR_MSS_THROTTLE_NUMERATOR, &i_target, l_dimm_throttle_n_array);
	if(l_rc) return l_rc;
	l_rc = FAPI_ATTR_SET(ATTR_MSS_THROTTLE_DENOMINATOR, &i_target, l_dimm_throttle_d_array);
	if(l_rc) return l_rc;
	l_rc = FAPI_ATTR_SET(ATTR_MSS_THROTTLE_CHANNEL_NUMERATOR, &i_target, l_channel_throttle_n_array);
	if(l_rc) return l_rc;
	l_rc = FAPI_ATTR_SET(ATTR_MSS_THROTTLE_CHANNEL_DENOMINATOR, &i_target, l_channel_throttle_d_array);
	if(l_rc) return l_rc;

	FAPI_INF("*** %s COMPLETE ***", procedure_name);
	return l_rc;
    }

} //end extern C
