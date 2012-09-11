/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_eff_config_thermal.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: mss_eff_config_thermal.C,v 1.8 2012/06/13 20:53:57 pardeik Exp $
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
// -- The power values are determined by DRAM Generation and Width (with various uplifts/adders applied)
//	and will be derived from the model and then verified with hardware measurements
//	-- Power will be per rank for a given dram generation and width
//	-- Uplifts will be applied for dimm type, number of ranks
// -- Thermal values are system dependent and will need to come from the machine readable workbook
//
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.8   | pardeik  |13-JUN-12| Major rewrite to have dimm power determined by dram generation and width, with uplifts applied (not based on dimm size lookup table any longer)
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
	    DDR3 = fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR3,
	    DDR4 = fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
	    X4 = fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
	    X8 = fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X8,
	};

// Structure types for the table that holds dimm power and adjustment values that will be used

	struct dimm_power_t
	{
	    uint32_t	idle;
	    uint32_t	max;
	};
	struct dimm_type_t
	{
	    int32_t	udimm;
	    int32_t	lrdimm;
	    int32_t	rdimm;
	    int32_t	cdimm;
	};
	struct dimm_voltage_t
	{
	    int8_t	volt1500;
	    int8_t	volt1350;
	    int8_t	volt1200;
	};
	struct dimm_frequency_t
	{
	    int8_t	freq1066;
	    int8_t	freq1333;
	    int8_t	freq1600;
	};
	struct power_data_t
	{
	    uint8_t		dram_generation;
	    uint8_t		dram_width;
	    uint8_t		dimm_ranks;
	    dimm_power_t	rank_master_power;
	    dimm_type_t		dimm_type_adder;
	    dimm_power_t	rank_slave_adder;
	    dimm_voltage_t	dimm_voltage_adder;
	    dimm_frequency_t	dimm_frequency_adder;	    
	};

power_data_t l_power_table[] =
{
// Master Ranks column uses the values in the same table entry for the number of master ranks specified.  Default is to have it use same power for each master rank, so that is why master ranks = 1.  If we need to separate power based on number of master ranks, then have the table setup for descending master rank values.  We always need an entry for master ranks of 1.  Table lookup will stop after first matching entry is found (DRAM Generation, DRAM Width, and Master Ranks = l_dimm_master_ranks_array OR 1)
//
// Note:  Slave rank full bw is set to idle, since the active power for full bw will be acounted for the master rank (ie.  only one rank active at a time).  Set slave rank full bw to the slave rank idle bw power value.
//
//  DRAM	DRAM	Master	MasterRankPower	DIMMTypeAdder	SlaveRankAdder	VoltageAdder	FrequencyAdder
//  Generation	Width	Ranks	(cW)		(cW)		(cW)		(%)		(%)
//  DDR3	X4	1	idle,full	UDIMM,LRDIMM,	idle,full	1.5,1.35,1.2	1066,1333,1600
//  or		or				RDIMM,CDIMM
//  DDR4	X8		
//				

// TODO:  Finalize these values against model.  These are just place holders for now and will work for the time being.
    { DDR3,	X4,	1,	{ 65,650},	{0,50,100,0},	{ 65,65},	{10,0,-10},     {0,10,20}         },
    { DDR3,	X8,	1,	{ 50,500},	{0,50,100,0},	{ 50,50},	{10,0,-10},     {0,10,20}         },
    { DDR4,	X4,	1,	{ 65,650},	{0,50,100,0},	{ 65,65},	{10,0,-10},     {0,10,20}         },
    { DDR4,	X8,	1,	{ 50,500},	{0,50,100,0},	{ 50,50},	{10,0,-10},     {0,10,20}         },
};

// Default values defined here
	const uint8_t l_num_ports = 2;				// number of ports per MBA
	const uint8_t l_num_dimms = 2;				// number of dimms per MBA port
	const uint32_t l_dimm_power_slope_default = 940;	// default power slope (cW/utilization)
	const uint32_t l_dimm_power_int_default = 900;		// default power intercept (cW)
	const uint32_t l_dimm_throttle_n_default = 100;		// default dimm throttle numerator
	const uint32_t l_dimm_throttle_d_default = 100;		// default dimm throttle denominator
	const uint32_t l_channel_throttle_n_default = 100;	// default channel throttle numerator
	const uint32_t l_channel_throttle_d_default = 100;	// default channel throttle denominator
	const uint8_t l_idle_dimm_utilization = 0;		// DRAM data bus utilization for the idle power defined in table below
	const uint8_t l_max_dimm_utilization = 100;		// DRAM data bus utilization for the active power defined in table below

// other variables used in this procedure
	fapi::Target l_targetCentaur;
	std::vector<fapi::Target> l_targetDimm;
	uint8_t port;
	uint8_t dimm;
	uint8_t entry;
	uint8_t l_dimm_type;
	uint8_t l_dimm_ranks_array[l_num_ports][l_num_dimms];
	uint32_t l_list_sz;
	uint32_t l_power_slope_array[l_num_ports][l_num_dimms];
	uint32_t l_power_int_array[l_num_ports][l_num_dimms];
	uint32_t l_dimm_throttle_n_array[l_num_ports][l_num_dimms];
	uint32_t l_dimm_throttle_d_array[l_num_ports][l_num_dimms];
	uint32_t l_channel_throttle_n_array[l_num_ports];
	uint32_t l_channel_throttle_d_array[l_num_ports];
	uint8_t l_found_entry_in_table;
	uint8_t l_dram_width;
	uint8_t l_dram_gen;
	uint32_t l_dimm_voltage;
	uint32_t l_dimm_frequency;
	uint8_t l_dimm_ranks_configed_array[l_num_ports][l_num_dimms];
	uint8_t l_dimm_master_ranks_array[l_num_ports][l_num_dimms];
	int32_t l_dimm_power_adder_type;
	int8_t l_dimm_power_adder_volt;
	int8_t l_dimm_power_adder_freq;
	uint32_t l_dimm_idle_power_adder_slave;
	uint32_t l_dimm_max_power_adder_slave;
	int32_t l_dimm_idle_power;
	int32_t l_dimm_max_power;
	uint8_t l_dimm_num_slave_ranks;

	l_list_sz = (sizeof(l_power_table))/(sizeof(power_data_t));

// Get input attributes
	l_rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN, &i_target, l_dram_gen);
	if(l_rc) return l_rc;
	l_rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target, l_dimm_type);
	if(l_rc) return l_rc;
	l_rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target, l_dram_width);
	if(l_rc) return l_rc;
	l_rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target, l_dimm_ranks_array);
	if(l_rc) return l_rc;
	l_rc = FAPI_ATTR_GET(ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, &i_target, l_dimm_master_ranks_array);
	if(l_rc) return l_rc;
	l_rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_RANKS_CONFIGED, &i_target, l_dimm_ranks_configed_array);
	if(l_rc) return l_rc;
// TODO:  Get Attributes for number of registers on ISDIMM and Termination settings being used

// Get Centaur target for the given MBA
// Get voltage and frequency attributes
	l_rc = fapiGetParentChip(i_target, l_targetCentaur);
	if(l_rc)
	{
	    FAPI_ERR("Error getting Centaur parent target for the given MBA");
	    return l_rc;
	}
	l_rc = FAPI_ATTR_GET(ATTR_MSS_VOLT, &l_targetCentaur, l_dimm_voltage);
	if(l_rc) return l_rc;
	l_rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_targetCentaur, l_dimm_frequency);
	if(l_rc) return l_rc;


// iterate through the MBA ports to define power and thermal attributes
	for (port=0; port < l_num_ports; port++)
	{
// initialize channel entries to zero
	    l_channel_throttle_n_array[port] = 0;
	    l_channel_throttle_d_array[port] = 0;
// iterate through the dimms on each port
	    for (dimm=0; dimm < l_num_dimms; dimm++)
	    {
// initialize dimm entries to zero
		l_dimm_throttle_n_array[port][dimm] = 0;
		l_dimm_throttle_d_array[port][dimm] = 0;
		l_power_slope_array[port][dimm] = 0;
		l_power_int_array[port][dimm] = 0;
// only update values for dimms that are physically present
		if (l_dimm_ranks_array[port][dimm] > 0)
		{
// TODO:  Placeholder for thermal attributes that will come from machine readable workbook (runtime throttles) - Hardcode these to the default values for now.
// TODO:  IPL throttles will need to be added into an initfile once available.
		    l_dimm_throttle_n_array[port][dimm] = l_dimm_throttle_n_default;
		    l_dimm_throttle_d_array[port][dimm] = l_dimm_throttle_d_default;
		    l_channel_throttle_n_array[port] = l_channel_throttle_n_default;
		    l_channel_throttle_d_array[port] = l_channel_throttle_d_default;

// Get the dimm power from table and add on any adjustments (if not found in table - should never happen, then default values will be used)
		    l_power_slope_array[port][dimm] = l_dimm_power_slope_default;
		    l_power_int_array[port][dimm] = l_dimm_power_int_default;
		    l_found_entry_in_table = 0;
		    for (entry = 0; entry < l_list_sz; entry++) {
			if ((l_power_table[entry].dram_generation == l_dram_gen) && (l_power_table[entry].dram_width == l_dram_width) && ((l_power_table[entry].dimm_ranks == l_dimm_master_ranks_array[port][dimm]) || (l_power_table[entry].dimm_ranks == 1)))
			{
// get adder for dimm type
			    if (l_dimm_type == UDIMM) {
				l_dimm_power_adder_type = l_power_table[entry].dimm_type_adder.udimm;
			    }
			    else if (l_dimm_type == LRDIMM)
			    {
				l_dimm_power_adder_type = l_power_table[entry].dimm_type_adder.lrdimm;
			    }
			    else if (l_dimm_type == CDIMM)
			    {
				l_dimm_power_adder_type = l_power_table[entry].dimm_type_adder.cdimm;
			    }
			    else if ( l_dimm_type == RDIMM )
			    {
				l_dimm_power_adder_type = l_power_table[entry].dimm_type_adder.rdimm;
			    }
			    else
			    {
				FAPI_ERR("UNKNOWN DIMM TYPE FOUND:  ldimm_type");
				l_dimm_power_adder_type = 0;
			    }
// TODO:  Use attribute for number of registers for RDIMM when available - via SPD byte 63 bits 1:0
// TODO:  Remove the double uplift below when SPD byte 63 is used
			    // double the uplift for additional register if dimm has more than 2 ranks
			    if ((l_dimm_master_ranks_array[port][dimm] > 2) && (l_dram_width == X4) && ((l_dimm_type == LRDIMM) || (l_dimm_type == RDIMM)))
			    {
				l_dimm_power_adder_type = l_dimm_power_adder_type * 2;
			    }
// get adder for dimm voltage
			    if (l_dimm_voltage == 1200)
			    {
				l_dimm_power_adder_volt = l_power_table[entry].dimm_voltage_adder.volt1200;
			    }
			    else if (l_dimm_voltage == 1350)
			    {
				l_dimm_power_adder_volt = l_power_table[entry].dimm_voltage_adder.volt1350;
			    }
			    else if (l_dimm_voltage == 1500)
			    {
				l_dimm_power_adder_volt = l_power_table[entry].dimm_voltage_adder.volt1500;
			    }
			    else
			    {
				FAPI_ERR("UNKNOWN DIMM VOLTAGE FOUND:  l_dimm_voltage");
				l_dimm_power_adder_volt = 0;
			    }
// get adder for dimm frequency
			    if (l_dimm_frequency == 1066)
			    {
				l_dimm_power_adder_freq = l_power_table[entry].dimm_frequency_adder.freq1066;
			    }
			    else if (l_dimm_frequency == 1333)
			    {
				l_dimm_power_adder_freq = l_power_table[entry].dimm_frequency_adder.freq1333;
			    }
			    else if (l_dimm_frequency == 1600)
			    {
				l_dimm_power_adder_freq = l_power_table[entry].dimm_frequency_adder.freq1600;
			    }
			    else
			    {
				FAPI_ERR("UNKNOWN DIMM FREQ FOUND:  l_dimm_frequency");
				l_dimm_power_adder_freq = 0;
			    }
// get adder for slave ranks
			    l_dimm_num_slave_ranks=l_dimm_ranks_array[port][dimm] - l_dimm_master_ranks_array[port][dimm];
			    if (l_dimm_num_slave_ranks > 0)
			    {
				l_dimm_idle_power_adder_slave = l_power_table[entry].rank_slave_adder.idle * l_dimm_num_slave_ranks;
				l_dimm_max_power_adder_slave = l_dimm_idle_power_adder_slave + (l_power_table[entry].rank_slave_adder.max - l_power_table[entry].rank_slave_adder.idle);
			    }
			    else
			    {
				l_dimm_idle_power_adder_slave = 0;
				l_dimm_max_power_adder_slave = 0;
			    }
// get adder for termination using equation
// TODO:  Need to add this in once equations are available for termination adder

// calculate idle and max dimm power
			    l_dimm_idle_power = int((l_power_table[entry].rank_master_power.idle * l_dimm_master_ranks_array[port][dimm] + l_dimm_power_adder_type + l_dimm_idle_power_adder_slave) * (1 + float(l_dimm_power_adder_volt + l_dimm_power_adder_freq) / 100));
			    l_dimm_max_power = int(((l_power_table[entry].rank_master_power.idle * l_dimm_master_ranks_array[port][dimm] + l_power_table[entry].rank_master_power.max - l_power_table[entry].rank_master_power.idle) + l_dimm_power_adder_type + l_dimm_max_power_adder_slave) * (1 + float(l_dimm_power_adder_volt + l_dimm_power_adder_freq) / 100));
// caculcate dimm power slope and intercept
			    l_power_slope_array[port][dimm] = int((l_dimm_max_power - l_dimm_idle_power) / (float(l_max_dimm_utilization - l_idle_dimm_utilization) / 100));
			    l_power_int_array[port][dimm] = l_dimm_idle_power;

			    l_found_entry_in_table = 1;
			    FAPI_INF("FOUND ENTRY:  GEN=%d WIDTH=%d RANK=%d IDLE=%d MAX=%d ADDER[SLAVE_IDLE=%d SLAVE_MAX=%d TYPE=%d VOLT=%d FREQ=%d]", l_power_table[entry].dram_generation, l_power_table[entry].dram_width, l_power_table[entry].dimm_ranks, l_power_table[entry].rank_master_power.idle, l_power_table[entry].rank_master_power.max, l_power_table[entry].rank_slave_adder.idle, l_power_table[entry].rank_slave_adder.max, l_dimm_power_adder_type, l_dimm_power_adder_volt, l_dimm_power_adder_freq);
			    FAPI_INF("DIMM Power Calculated [P%d:D%d:R%d/%d][IDLE=%d:MAX=%d cW][SLOPE=%d:INT=%d cW]", port, dimm, l_dimm_master_ranks_array[port][dimm], l_dimm_num_slave_ranks, l_dimm_idle_power, l_dimm_max_power, l_power_slope_array[port][dimm], l_power_int_array[port][dimm]);
			    break;
			}

		    }
		    if (l_found_entry_in_table == 0)
		    {
			FAPI_ERR( "WARNING:  Failed to Find DIMM Power Values, so default values will be used [%d:%d][%d:%d]", port, dimm, l_power_slope_array[port][dimm], l_power_int_array[port][dimm] );
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
