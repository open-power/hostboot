/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_eff_config_thermal.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
// $Id: mss_eff_config_thermal.C,v 1.14 2012/12/12 20:10:33 pardeik Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/
//          centaur/working/procedures/ipl/fapi/mss_eff_config_thermal.C,v $
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
// applicable CQ component memory_screen
//
// DESCRIPTION:
// The purpose of this procedure is to set the default throttle and power
// attributes for dimms in a given system
// -- The power attributes are the slope/intercept values.  Note that these
//    values are in cW.
//    -- ISDIMM will calculate values based on various attributes
//    -- CDIMM will get values from VPD
// -- The throttle attributes will setup values for safemode and runtime
//
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
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

Waiting for platinit attributes to enable sections in this procedure:
1.  Power Curves to originate from CDIMM VPD (platinit)
2.  Thermal memory power limit from MRW (platinit)
3.  Safemode throttles from MRW (platinit)
5.  Need runtime throttles non-volatile and initialized to zero by firmware on
    the first IPL
6.  Call out error for CDIMM and lab VPD power curves when it makes sense
7.  Update power table after hardware measurements are done

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
const uint32_t ISDIMM_POWER_SLOPE_DEFAULT = 940;
const uint32_t ISDIMM_POWER_INT_DEFAULT = 900;
const uint32_t CDIMM_POWER_SLOPE_DEFAULT = 0x8240;
const uint32_t CDIMM_POWER_INT_DEFAULT = 0x80CE;
// These are based on what was used when ISDIMM power values were taken from the
// power calculator
const uint8_t IDLE_DIMM_UTILIZATION = 0;
const uint8_t ACTIVE_DIMM_UTILIZATION = 70;
const uint8_t DATA_BUS_READ_PERCENT = 66;
const uint8_t DATA_BUS_WRITE_PERCENT = 34;


extern "C" {

    using namespace fapi;

//------------------------------------------------------------------------------
// Funtions in this file
//------------------------------------------------------------------------------
    fapi::ReturnCode mss_eff_config_thermal(const fapi::Target & i_target_mba);

    fapi::ReturnCode mss_eff_config_thermal_term
      (
       const char nom_or_wc_term[4],
       uint8_t i_port,
       uint8_t i_dimm,
       uint8_t i_rank,
       uint32_t i_dimm_voltage,
       uint8_t i_dram_width,
       uint8_t i_dram_tdqs,
       uint8_t i_ibm_type[NUM_PORTS][NUM_DIMMS],
       uint8_t i_dimm_ranks_configed_array[NUM_PORTS][NUM_DIMMS],
       uint8_t i_dimm_dram_ron[NUM_PORTS][NUM_DIMMS],
       uint8_t i_dimm_rank_odt_rd[NUM_PORTS][NUM_DIMMS][NUM_RANKS],
       uint8_t i_dimm_rank_odt_wr[NUM_PORTS][NUM_DIMMS][NUM_RANKS],
       uint8_t i_dram_rtt_nom[NUM_PORTS][NUM_DIMMS][NUM_RANKS],
       uint8_t i_dram_rtt_wr[NUM_PORTS][NUM_DIMMS][NUM_RANKS],
       uint8_t i_cen_dq_dqs_rcv_imp[NUM_PORTS],
       uint8_t i_cen_dq_dqs_drv_imp[NUM_PORTS],
       float &o_dimm_power_adder_termination
       );

    fapi::ReturnCode mss_eff_config_thermal_get_wc_term
      (
       const fapi::Target &i_target_mba,
       uint8_t i_port,
       uint8_t &o_cen_dq_dqs_rcv_imp_wc,
       uint8_t &o_cen_dq_dqs_drv_imp_wc
       );

    fapi::ReturnCode mss_eff_config_thermal_get_cen_drv_value
      (
       uint8_t i_cen_dq_dqs_drv_imp,
       uint8_t &o_cen_dq_dqs_drv_imp
       );

//------------------------------------------------------------------------------
// @brief mss_eff_config_thermal(): This function determines the power and
// throttle attribute values to use
//
// @param[in]	const fapi::Target & i_target_mba:  MBA Target passed in
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------

    fapi::ReturnCode mss_eff_config_thermal(const fapi::Target & i_target_mba)
    {
	fapi::ReturnCode rc = fapi::FAPI_RC_SUCCESS;

	char procedure_name[32];
	sprintf(procedure_name, "mss_eff_config_thermal");
	FAPI_IMP("*** Running %s ***", procedure_name);

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

// Structure types for the table that holds dimm power and adjustment values
// that will be used

	struct dimm_power_t
	{
	    uint32_t	idle;
	    uint32_t	active;
	};
	struct dimm_type_t
	{
	    int32_t	udimm;
	    int32_t	lrdimm;
	    int32_t	rdimm;
	};
	struct power_data_t
	{
	    uint8_t		dram_generation;
	    uint8_t		dram_width;
	    uint8_t		dimm_ranks;
	    dimm_power_t	rank_power;
	    dimm_type_t		dimm_type_adder;
	    int32_t		dimm_voltage_base;
	    int32_t		dimm_frequency_base;	    
	};

//------------------------------------------------------------------------------
// Master Ranks column uses the values in the same table entry for the number of
// master ranks specified.  Default is to have it use same power for each master
// rank, so that is why master ranks = 1.  If we need to separate power based on
// number of master ranks, then have the table setup for descending master rank
// values.  We always need an entry for master ranks of 1.  Table lookup will
// stop after first matching entry is found (DRAM Generation, DRAM Width, and
// Master Ranks = dimm_master_ranks_array OR 1)
//
// These values need to cover the power of all IBM dimms.  Values will come from
// the power calculator and be verified by hardware measurements.
//
// Base Voltage and Base Frequency values need to match what mss_volt/mss_freq
// uses.
//
//            DRAM  DRAM  Master RankPower  DIMMType    Base    Base
//            Gen   Width Ranks	 idle,full  Adder       Volt    Freq
//                               cW         U,LR,RDIMM  mV      MHz
//------------------------------------------------------------------------------
	power_data_t power_table[] =
	{
	    { DDR3, X4,   1,     { 70,373}, {0,93,104}, 1350,	1066 },
	    { DDR3, X8,   1,     { 52,300}, {0,93,104}, 1350,	1066 },
	    { DDR4, X4,   1,     { 70,373}, {0,93,104}, 1350,	1066 },
	    { DDR4, X8,   1,     { 52,300}, {0,93,104}, 1350,	1066 },
	};

// other variables used in this function
	fapi::Target target_chip;
	std::vector<fapi::Target> target_mba_array;
	std::vector<fapi::Target> target_dimm_array;
	uint8_t port;
	uint8_t dimm;
	uint8_t mba_port;
	uint8_t mba_dimm;
	uint8_t rank;
	uint8_t entry;
	uint8_t dimm_type;
	uint8_t dimm_ranks_array[NUM_PORTS][NUM_DIMMS];
	uint32_t power_table_size;
	uint32_t power_slope_array[NUM_PORTS][NUM_DIMMS];
	uint32_t power_int_array[NUM_PORTS][NUM_DIMMS];
	uint32_t power_slope2_array[NUM_PORTS][NUM_DIMMS];
	uint32_t power_int2_array[NUM_PORTS][NUM_DIMMS];
	uint8_t found_entry_in_table;
	uint8_t dram_width;
	uint8_t dram_tdqs;
	uint8_t dram_gen;
	uint32_t dimm_voltage;
	uint32_t dimm_frequency;
	uint8_t dimm_ranks_configed_array[NUM_PORTS][NUM_DIMMS];
	uint8_t dimm_master_ranks_array[NUM_PORTS][NUM_DIMMS];
	int32_t dimm_power_adder_type;
	float dimm_power_multiplier_volt;
	float dimm_power_mulitiplier_freq;
	float dimm_idle_power;
	float dimm_active_power;
	float dimm_power_adder_termination;
	float dimm_power_adder_termination_largest = 0;
	uint8_t dimm_rank_odt_rd[NUM_PORTS][NUM_DIMMS][NUM_RANKS];
	uint8_t dimm_rank_odt_wr[NUM_PORTS][NUM_DIMMS][NUM_RANKS];
	uint8_t dimm_dram_ron[NUM_PORTS][NUM_DIMMS];
	uint8_t cen_dq_dqs_rcv_imp[NUM_PORTS];
	uint8_t cen_dq_dqs_drv_imp[NUM_PORTS];
	float dimm_power_adder_termination_wc;
	float dimm_power_adder_termination_largest_wc = 0;
	uint8_t cen_dq_dqs_rcv_imp_wc[NUM_PORTS];
	uint8_t cen_dq_dqs_drv_imp_wc[NUM_PORTS];
	uint8_t num_dimms_on_port;
	uint32_t throttle_n_per_mba;
	uint32_t throttle_n_per_chip;
	uint32_t throttle_d;
	uint32_t runtime_throttle_n_per_mba;
	uint32_t runtime_throttle_n_per_chip;
	uint32_t runtime_throttle_d;
	uint8_t dram_rtt_nom[NUM_PORTS][NUM_DIMMS][NUM_RANKS];
	uint8_t dram_rtt_wr[NUM_PORTS][NUM_DIMMS][NUM_RANKS];
	uint8_t ibm_type[NUM_PORTS][NUM_DIMMS];
	char dram_gen_str[4];
	uint32_t dimm_thermal_power_limit;
	uint32_t channel_pair_thermal_power_limit;
	uint8_t num_mba_with_dimms = 0;
	uint8_t mba_index;
	uint8_t dimm_number_registers[NUM_PORTS][NUM_DIMMS];
	uint8_t dimm_index;
	uint32_t cdimm_master_power_slope;
	uint32_t cdimm_master_power_intercept;
	uint32_t cdimm_supplier_power_slope;
	uint32_t cdimm_supplier_power_intercept;
	uint32_t safemode_throttle_n_per_mba;
	uint32_t safemode_throttle_n_per_chip;
	uint32_t safemode_throttle_d;

	power_table_size = (sizeof(power_table))/(sizeof(power_data_t));

//------------------------------------------------------------------------------
// Get input attributes
//------------------------------------------------------------------------------
	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN, &i_target_mba, dram_gen);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_DRAM_GEN");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target_mba, dimm_type);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_DIMM_TYPE");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target_mba, dram_width);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_DRAM_WIDTH");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_TDQS, &i_target_mba, dram_tdqs);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_DRAM_TDQS");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM,
			   &i_target_mba, dimm_ranks_array);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_NUM_RANKS_PER_DIMM");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM,
			   &i_target_mba, dimm_master_ranks_array);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_RANKS_CONFIGED,
			   &i_target_mba, dimm_ranks_configed_array);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_DIMM_RANKS_CONFIGED");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_RON, &i_target_mba, dimm_dram_ron);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_DRAM_RON");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_ODT_RD, &i_target_mba, dimm_rank_odt_rd);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_ODT_RD");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_ODT_WR, &i_target_mba, dimm_rank_odt_wr);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_ODT_WR");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_CEN_RCV_IMP_DQ_DQS,
			   &i_target_mba, cen_dq_dqs_rcv_imp);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_CEN_RCV_IMP_DQ_DQS");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS,
			   &i_target_mba, cen_dq_dqs_drv_imp);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_CEN_DRV_IMP_DQ_DQS");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_RTT_NOM, &i_target_mba, dram_rtt_nom);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_DRAM_RTT_NOM");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_RTT_WR, &i_target_mba, dram_rtt_wr);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_DRAM_RTT_WR");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_IBM_TYPE, &i_target_mba, ibm_type);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_IBM_TYPE");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_NUM_DROPS_PER_PORT,
			   &i_target_mba, num_dimms_on_port);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_NUM_DROPS_PER_PORT");
	    return rc;
	}
// TODO:  use vpd values when power curve data is available from CDIMM VPD
// (platinit), remove hardcoding
	cdimm_master_power_slope = CDIMM_POWER_SLOPE_DEFAULT;
	cdimm_master_power_intercept = CDIMM_POWER_INT_DEFAULT;
	cdimm_supplier_power_slope = CDIMM_POWER_SLOPE_DEFAULT;
	cdimm_supplier_power_intercept = CDIMM_POWER_INT_DEFAULT;
/*
	rc = FAPI_ATTR_GET(ATTR_SPD_CDIMM_MASTER_POWER_SLOPE,
			   &i_target_mba, cdimm_master_power_slope);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_SPD_CDIMM_MASTER_POWER_SLOPE");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_SPD_CDIMM_MASTER_POWER_INTERCEPT,
			   &i_target_mba, cdimm_master_power_intercept);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_SPD_CDIMM_MASTER_POWER_INTERCEPT");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_SPD_CDIMM_SUPPLIER_POWER_SLOPE,
			   &i_target_mba, cdimm_supplier_power_slope);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_SPD_CDIMM_SUPPLIER_POWER_SLOPE");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_SPD_CDIMM_SUPPLIER_POWER_INTERCEPT,
			   &i_target_mba, cdimm_supplier_power_intercept);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_SPD_CDIMM_SUPPLIER_POWER_INTERCEPT");
	    return rc;
	}
*/
// TODO:  Get Safemode throttles from MRW (platinit), hardcode until available
	safemode_throttle_n_per_mba = 96;
	safemode_throttle_n_per_chip = 32;
	safemode_throttle_d = 512;
/*
	rc = FAPI_ATTR_GET(ATTR_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_MBA,
			   &i_target_mba, safemode_throttle_n_per_mba);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_MBA");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_CHIP,
			   &i_target_mba, safemode_throttle_n_per_chip);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_CHIP");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_MRW_SAFEMODE_MEM_THROTTLE_DENOMINATOR,
			   &i_target_mba, safemode_throttle_d);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MRW_SAFEMODE_MEM_THROTTLE_DENOMINATOR");
	    return rc;
	}
*/
// TODO:  Get Thermal power Limit from MRW (platinit), hardcode until available
	if (dimm_type == CDIMM)
	{
	    dimm_thermal_power_limit = 5000; // in cW, per CDIMM, high limit
	}
	else
	{
	    dimm_thermal_power_limit = 2000; // in cW, per ISDIMM, high limit
	}
/*
	rc = FAPI_ATTR_GET(ATTR_MRW_THERMAL_MEMORY_POWER_LIMIT,
			   &i_target_mba, dimm_thermal_power_limit);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MRW_THERMAL_MEMORY_POWER_LIMIT");
	    return rc;
	}
*/

// Get Centaur target for the given MBA
	rc = fapiGetParentChip(i_target_mba, target_chip);
	if (rc) {
	    FAPI_ERR("Error from fapiGetParentChip");
	    return rc;
	}
// Get voltage and frequency attributes
	rc = FAPI_ATTR_GET(ATTR_MSS_VOLT, &target_chip, dimm_voltage);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MSS_VOLT");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &target_chip, dimm_frequency);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_MSS_FREQ");
	    return rc;
	}


// get any attributes from DIMM SPD
	if (dimm_type != CDIMM)
	{
	    rc = fapiGetAssociatedDimms(i_target_mba, target_dimm_array,
					fapi::TARGET_STATE_PRESENT);
	    if (rc) {
		FAPI_ERR("Error from fapiGetAssociatedDimms");
		return rc;
	    }
	    for (dimm_index=0;
		 dimm_index < target_dimm_array.size();
		 dimm_index++)
	    {
		rc = FAPI_ATTR_GET(ATTR_MBA_PORT,
				   &target_dimm_array[dimm_index], port);
		if (rc) {
		    FAPI_ERR("Error getting attribute ATTR_MBA_PORT");
		    return rc;
		}
		rc = FAPI_ATTR_GET(ATTR_MBA_DIMM,
				   &target_dimm_array[dimm_index], dimm);
		if (rc) {
		    FAPI_ERR("Error getting attribute ATTR_MBA_DIMM");
		    return rc;
		}
		rc = FAPI_ATTR_GET(ATTR_SPD_NUM_OF_REGISTERS_USED_ON_RDIMM,
				   &target_dimm_array[dimm_index],
				   dimm_number_registers[port][dimm]);
		if (rc) {
		    FAPI_ERR("Error getting attribute ATTR_SPD_NUM_OF_REGISTERS_USED_ON_RDIMM");
		    return rc;
		}
	    }
	}

// Get number of Centaur MBAs that have dimms present
	if (dimm_type == CDIMM)
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

// determine worst case termination settings here for ISDIMMs (to be used later)
	if (dimm_type != CDIMM)
	{
// get worst case termination values that will be used
// Only look at Centaur DQ/DQS Driver and Receiver termination settings
// Note that the DRAM rtt_nom, rtt_wr, and ron will not be allowed to change,
// all these will stay at the nominal settings
	    for (port=0; port < NUM_PORTS; port++)
	    {
		rc = mss_eff_config_thermal_get_wc_term
		  (
		   i_target_mba,
		   port,
		   cen_dq_dqs_rcv_imp_wc[port],
		   cen_dq_dqs_drv_imp_wc[port]
		   );
		if (rc)
		{
		    FAPI_ERR("Error (0x%x) calling mss_eff_config_thermal_get_wc_term", static_cast<uint32_t>(rc));
		    return rc;
		}
	    }
	}

//------------------------------------------------------------------------------
// Power Curve Determination
//------------------------------------------------------------------------------
// Iterate through the MBA ports to get power slope/intercept values
	for (port=0; port < NUM_PORTS; port++)
	{
// Get termination power for ISDIMM
	    if (dimm_type != CDIMM)
	    {
		dimm_power_adder_termination_largest=0;
		dimm_power_adder_termination_largest_wc=0;

// iterate through the dimms on each port to determine termination power to use
		for (dimm=0; dimm < NUM_DIMMS; dimm++)
		{
// calculate the effective net termination for each rank
		    for (rank=0; rank < NUM_RANKS; rank++)
		    {
// nominal termination
			rc = mss_eff_config_thermal_term
			  (
			   "NOM",
			   port,
			   dimm,
			   rank,
			   dimm_voltage,
			   dram_width,
			   dram_tdqs,
			   ibm_type,
			   dimm_ranks_configed_array,
			   dimm_dram_ron,
			   dimm_rank_odt_rd,
			   dimm_rank_odt_wr,
			   dram_rtt_nom,
			   dram_rtt_wr,
			   cen_dq_dqs_rcv_imp,
			   cen_dq_dqs_drv_imp,
			   dimm_power_adder_termination
			   );
			if (rc)
			{
			    FAPI_ERR("Error (0x%x) calling mss_eff_config_thermal_term", static_cast<uint32_t>(rc));
			    return rc;
			}
			if (dimm_power_adder_termination >
			    dimm_power_adder_termination_largest)
			{
			    dimm_power_adder_termination_largest =
			      dimm_power_adder_termination;
			}

// worst case termination
			rc = mss_eff_config_thermal_term
			  (
			   "WC",
			   port,
			   dimm,
			   rank,
			   dimm_voltage,
			   dram_width,
			   dram_tdqs,
			   ibm_type,
			   dimm_ranks_configed_array,
			   dimm_dram_ron,
			   dimm_rank_odt_rd,
			   dimm_rank_odt_wr,
			   dram_rtt_nom,
			   dram_rtt_wr,
			   cen_dq_dqs_rcv_imp_wc,
			   cen_dq_dqs_drv_imp_wc,
			   dimm_power_adder_termination_wc
			   );
			if (rc)
			{
			    FAPI_ERR("Error (0x%x) calling mss_eff_config_thermal_term", static_cast<uint32_t>(rc));
			    return rc;
			}
			if (dimm_power_adder_termination_wc >
			    dimm_power_adder_termination_largest_wc)
			{
			    dimm_power_adder_termination_largest_wc =
			      dimm_power_adder_termination_wc;
			}
		    }
		}
	    }

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
		    if (dimm_type == CDIMM)
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
// TODO:  enable error reporting for this when it makes sense to do (after ship
// level power curve data is known), remove warning message.  Log error and
// allow IPL to continue and use the lab data if it is there.
				FAPI_INF("WARNING:  power curve data is lab data, not ship level data. Using data anyways.");
/*
				power_slope_array[port][dimm] =
				  CDIMM_POWER_SLOPE_DEFAULT;
				power_int_array[port][dimm] =
				  CDIMM_POWER_INT_DEFAULT;
				power_slope2_array[port][dimm] =
				  CDIMM_POWER_SLOPE_DEFAULT;
				power_int2_array[port][dimm] =
				  CDIMM_POWER_INT_DEFAULT;
				FAPI_ERR("power curve data is lab data, not ship level data.  Use default values");
				const fapi::Target & MEM_CHIP = target_chip;
				uint32_t FFDC_DATA_1 = cdimm_master_power_slope;
				uint32_t FFDC_DATA_2 =
				  cdimm_master_power_intercept;
				uint32_t FFDC_DATA_3 =
				  cdimm_supplier_power_slope;
				uint32_t FFDC_DATA_4 =
				  cdimm_supplier_power_intercept;
				FAPI_SET_HWP_ERROR
				  (rc, RC_MSS_DIMM_POWER_CURVE_DATA_LAB);
				if (rc) fapiLogError(rc);
*/
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
// ISDIMM power slope/intercept will come from equation
		    else
		    {
// Get the dimm power from table and add on any adjustments (if not found in
//  table - should never happen - then default values will be used)
			power_slope_array[port][dimm] =
			  ISDIMM_POWER_SLOPE_DEFAULT;
			power_int_array[port][dimm] = ISDIMM_POWER_INT_DEFAULT;

			found_entry_in_table = 0;
			for (entry = 0; entry < power_table_size; entry++)
			{
			    if (
				(power_table[entry].dram_generation == dram_gen)
				&&
				(power_table[entry].dram_width == dram_width)
				&&
				((power_table[entry].dimm_ranks ==
				  dimm_master_ranks_array[port][dimm]) ||
				 (power_table[entry].dimm_ranks == 1))
				)
			    {
// get adder for dimm type
				if (dimm_type == UDIMM)
				{
				    dimm_power_adder_type =
				      power_table[entry].dimm_type_adder.udimm;
				}
				else if (dimm_type == LRDIMM)
				{
				    dimm_power_adder_type =
				      power_table[entry].dimm_type_adder.lrdimm;
				}
				else // RDIMM
				{
				    dimm_power_adder_type =
				      power_table[entry].dimm_type_adder.rdimm;
				}


				if (dimm_type == RDIMM) {
				    dimm_power_adder_type =
				      dimm_power_adder_type *
				      dimm_number_registers[port][dimm];
				}

// get adder for dimm voltage
				dimm_power_multiplier_volt =
				  (
				   (float(dimm_voltage) /
				    power_table[entry].dimm_voltage_base)
				   *
				   (float(dimm_voltage) /
				    power_table[entry].dimm_voltage_base)
				   );
// get adder for dimm frequency
				dimm_power_mulitiplier_freq =
				  (float(dimm_frequency) /
				   power_table[entry].dimm_frequency_base);
// get adder for termination using equation (in cW)
				dimm_power_adder_termination =
				  dimm_power_adder_termination_largest * 100;
				dimm_power_adder_termination_wc =
				  dimm_power_adder_termination_largest_wc * 100;
// add up power for each dimm on channel and divide by number of dimms to get an
// average power for each dimm
// calculate idle and active dimm power (active power includes worst case
// termination power)
				dimm_idle_power =
				  (
				   (float(
					  (
					   (
					    power_table[entry].rank_power.idle
					    *
					    (
					     dimm_master_ranks_array[port][dimm]
					     + (dimm_ranks_array[port][dimm] -
						dimm_master_ranks_array
						[port][dimm])
					     ) + dimm_power_adder_type
					    )
					   * (dimm_power_multiplier_volt)
					   * (dimm_power_mulitiplier_freq)
					   )
					  *
					  num_dimms_on_port
					  )
				    / (num_dimms_on_port)
				    )
				   );
//------------------------------------------------------------------------------
				dimm_active_power =
				  (
				   (float(
					  (
					   (
					    (power_table[entry].rank_power.idle
					     *
					     (
					      dimm_master_ranks_array[port][dimm]
					      +
					      (
					       dimm_ranks_array[port][dimm] -
					       dimm_master_ranks_array
					       [port][dimm]
					       )
					      )
					     +
					     (
					      power_table[entry].rank_power.active
					      -
					      power_table[entry].rank_power.idle
					      )
					     )
					    +
					    dimm_power_adder_type
					    )
					   * (dimm_power_multiplier_volt)
					   * (dimm_power_mulitiplier_freq)
					   )
					  * num_dimms_on_port -
					  (power_table[entry].rank_power.active
					   - power_table[entry].rank_power.idle)
					  * (num_dimms_on_port - 1)
					  + dimm_power_adder_termination
					  + (dimm_power_adder_termination_wc -
					     dimm_power_adder_termination)
					  )
				    /
				    (num_dimms_on_port)
				    )
				   );
//------------------------------------------------------------------------------
// calculate dimm power slope and intercept (add on 0.5 so value is effectively
// rounded to nearest integer)
				power_slope_array[port][dimm] =
				  int(
				      (dimm_active_power - dimm_idle_power) /
				      (float(ACTIVE_DIMM_UTILIZATION -
					     IDLE_DIMM_UTILIZATION) / 100)
				      + 0.5
				      );
				power_int_array[port][dimm] =
				  int(dimm_idle_power + 0.5);
				power_slope2_array[port][dimm] =
				  power_slope_array[port][dimm];
				power_int2_array[port][dimm] =
				  power_int_array[port][dimm];
				if (power_table[entry].dram_generation == DDR3)
				{
				    sprintf(dram_gen_str, "DDR3");
				}
				if (power_table[entry].dram_generation == DDR4)
				{
				    sprintf(dram_gen_str, "DDR4");
				}

				found_entry_in_table = 1;
				FAPI_DBG("FOUND ENTRY:  GEN=%s WIDTH=X%d RANK=%d IDLE(%d%%)=%d ACTIVE(%d%%)=%d ADDER[TYPE=%d WCTERM=%4.2f] Multiplier[VOLT=%4.2f FREQ=%4.2f]", dram_gen_str, power_table[entry].dram_width, power_table[entry].dimm_ranks, IDLE_DIMM_UTILIZATION, power_table[entry].rank_power.idle, ACTIVE_DIMM_UTILIZATION, power_table[entry].rank_power.active, dimm_power_adder_type, dimm_power_adder_termination_wc, dimm_power_multiplier_volt, dimm_power_mulitiplier_freq);
				FAPI_DBG("ISDIMM Power [P%d:D%d][%s:X%d:R%d/%d:%d:%d][IDLE(%d%%)=%4.2f:ACTIVE(%d%%)=%4.2f cW][SLOPE=%d:INT=%d cW]", port, dimm, dram_gen_str, power_table[entry].dram_width, dimm_master_ranks_array[port][dimm], (dimm_ranks_array[port][dimm] - dimm_master_ranks_array[port][dimm]), dimm_voltage, dimm_frequency, IDLE_DIMM_UTILIZATION, dimm_idle_power, ACTIVE_DIMM_UTILIZATION, dimm_active_power, power_slope_array[port][dimm], power_int_array[port][dimm]);
				FAPI_DBG("ISDIMM Power [P%d:D%d][SLOPE=%d:INT=%d cW][SLOPE2=%d:INT2=%d cW]", port, dimm, power_slope_array[port][dimm], power_int_array[port][dimm], power_slope2_array[port][dimm], power_int2_array[port][dimm]);
				break;
			    }

			}
//------------------------------------------------------------------------------
			if (found_entry_in_table == 0)
			{
			    FAPI_ERR("Failed to Find DIMM Power Values on %s.  Default values will be used [P%d:D%d][Slope=%d:INT=%d cW]", i_target_mba.toEcmdString(), port, dimm, power_slope_array[port][dimm], power_int_array[port][dimm]);

// get dimm target, we should always find a valid dimm target from this
// since we have ranks present on this dimm if we are here in the code
			    for (dimm_index=0;
				 dimm_index < target_dimm_array.size();
				 dimm_index++)
			    {
				rc = FAPI_ATTR_GET
				  (ATTR_MBA_PORT,
				   &target_dimm_array[dimm_index], mba_port);
				if (rc) {
				    FAPI_ERR("Error getting attribute ATTR_MBA_PORT");
				    return rc;
				}
				rc = FAPI_ATTR_GET
				  (ATTR_MBA_DIMM,
				   &target_dimm_array[dimm_index], mba_dimm);
				if (rc) {
				    FAPI_ERR("Error getting attribute ATTR_MBA_DIMM");
				    return rc;
				}
				if ( (mba_port == port) && (mba_dimm == dimm)) {
				    break;
				}
			    }
			    const fapi::Target & MEM_DIMM =
			      target_dimm_array[dimm_index];
			    uint32_t FFDC_DATA_1 = dram_gen;
			    uint32_t FFDC_DATA_2 = dram_width;
			    uint8_t  FFDC_DATA_3 =
			      dimm_master_ranks_array[port][dimm];
			    FAPI_SET_HWP_ERROR
			      (rc, RC_MSS_DIMM_NOT_FOUND_IN_POWER_TABLE);
			    if (rc) fapiLogError(rc);
			}
		    }
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


//------------------------------------------------------------------------------
// Memory Throttle Determination
//------------------------------------------------------------------------------

// Runtime throttles will be non-volatile, so don't recalculate them if they
// have already been set

// TODO:  remove this section when firmware initializes attributes to zero AND
// runtime throttles are non-volatile
	runtime_throttle_n_per_mba = 0;
	runtime_throttle_n_per_chip = 0;
	runtime_throttle_d = 0;
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

// Get the runtime throttle attributes here
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
// check to see if runtime throttles are all zero here
	if (
	    (runtime_throttle_n_per_mba == 0) &&
	    (runtime_throttle_n_per_chip == 0) &&
	    (runtime_throttle_d == 0)
	    )
	{
// Values have not been initialized, so get them initialized
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
	    if (dimm_type == CDIMM)
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

// Call the procedure function that takes a channel pair power limit and
// converts it to throttle values

	    FAPI_EXEC_HWP(rc, mss_bulk_pwr_throttles, i_target_mba);
	    if (rc)
	    {
		FAPI_ERR("Error (0x%x) calling mss_bulk_pwr_throttles", static_cast<uint32_t>(rc));
		return rc;
	    }

// Read back in the updated throttle attribute values (these are now set to values that will give dimm/channel power underneath the thermal power limit)
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

	}

// Initialize the generic throttle attributes to safemode throttles (since the
// IPL will be done at the safemode throttles)
	throttle_n_per_mba = safemode_throttle_n_per_mba;
	throttle_n_per_chip = safemode_throttle_n_per_chip;
	throttle_d = safemode_throttle_d;

// write output attributes
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

	FAPI_IMP("*** %s COMPLETE ***", procedure_name);
	return rc;
    }

//------------------------------------------------------------------------------
// @brief mss_eff_config_thermal_term(): This function calculates the data bus
// termination power
//
// @param[in]   const char i_nom_or_wc_term[4]:  description of what is being
//              calculated (ie.  NOM or WC)
// @param[in]   uint8_t i_port:  MBA port being worked on
// @param[in]   uint8_t i_dimm:  DIMM being worked on
// @param[in]   uint8_t i_rank:  Rank being worked on
// @param[in]   uint32_t i_dimm_voltage:  DIMM Voltage
// @param[in]   uint8_t i_dram_width:  DRAM Width
// @param[in]   uint8_t i_dram_tdqs:  DRAM TDQS enable/disable
// @param[in]   uint8_t i_ibm_type[NUM_PORTS][NUM_DIMMS]:  IBM bus topology
//              type
// @param[in]   uint8_t i_dimm_ranks_configed_array[NUM_PORTS][NUM_DIMMS]:
//              Master Ranks configured
// @param[in]   uint8_t i_dimm_dram_ron[NUM_PORTS][NUM_DIMMS]:  DRAM RON driver
//              impedance
// @param[in]   uint8_t i_dimm_rank_odt_rd[NUM_PORTS][NUM_DIMMS][NUM_RANKS]:
//              Read ODT
// @param[in]   uint8_t i_dimm_rank_odt_wr[NUM_PORTS][NUM_DIMMS][NUM_RANKS]:
//              Write ODT
// @param[in]   uint8_t i_dram_rtt_nom[NUM_PORTS][NUM_DIMMS][NUM_RANKS]:  DRAM
//              RTT NOM
// @param[in]   uint8_t i_dram_rtt_wr[NUM_PORTS][NUM_DIMMS][NUM_RANKS]:  DRAM
//              RTT WR
// @param[in]   uint8_t i_cen_dq_dqs_rcv_imp[NUM_PORTS]:  Centaur DQ/DQS 
//              receiver impedance
// @param[in]	uint8_t i_cen_dq_dqs_drv_imp[NUM_PORTS]:  Centaur DQ/DQS driver
//              impedance
// @param[out]  float &o_dimm_power_adder_termination:  Termination Power
//              Calculated in Watts
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------

    fapi::ReturnCode mss_eff_config_thermal_term
      (
       const char i_nom_or_wc_term[4],
       uint8_t i_port,
       uint8_t i_dimm,
       uint8_t i_rank,
       uint32_t i_dimm_voltage,
       uint8_t i_dram_width,
       uint8_t i_dram_tdqs,
       uint8_t i_ibm_type[NUM_PORTS][NUM_DIMMS],
       uint8_t i_dimm_ranks_configed_array[NUM_PORTS][NUM_DIMMS],
       uint8_t i_dimm_dram_ron[NUM_PORTS][NUM_DIMMS],
       uint8_t i_dimm_rank_odt_rd[NUM_PORTS][NUM_DIMMS][NUM_RANKS],
       uint8_t i_dimm_rank_odt_wr[NUM_PORTS][NUM_DIMMS][NUM_RANKS],
       uint8_t i_dram_rtt_nom[NUM_PORTS][NUM_DIMMS][NUM_RANKS],
       uint8_t i_dram_rtt_wr[NUM_PORTS][NUM_DIMMS][NUM_RANKS],
       uint8_t i_cen_dq_dqs_rcv_imp[NUM_PORTS],
       uint8_t i_cen_dq_dqs_drv_imp[NUM_PORTS],
       float &o_dimm_power_adder_termination
       )
    {
	fapi::ReturnCode rc = fapi::FAPI_RC_SUCCESS;

	char procedure_name[32];
	sprintf(procedure_name, "mss_eff_config_thermal_term");
	FAPI_IMP("*** Running %s ***", procedure_name);

	uint8_t number_nets_term_rd;
	uint8_t number_nets_term_wr;
	uint8_t ma0odt01_dimm;
	uint8_t ma1odt01_dimm;
	uint8_t ma0odt0_rank;
	uint8_t ma0odt1_rank;
	uint8_t ma1odt0_rank;
	uint8_t ma1odt1_rank;
	uint8_t rank_mask;
	float eff_term_rd;
	float eff_net_term_rd;
	float term_odt_mult_rd;
	float eff_term_wr;
	float eff_net_term_wr;
	float term_odt_mult_wr;
	uint8_t cen_dq_dqs_drv_imp_value;

// Get number of nets that will have termination applied from ODT (DQ,DQS,DM,
// TDQS)
// number of nets for DQ (9 DRAMs x 8 bits each, or 18 DRAMs x 4 bits each = 72)
	number_nets_term_rd = 72;
	number_nets_term_wr = 72;
// add in number of nets for DQS + DM + TDQS (TDQS only supported for X8, DM
// only used for writes)
	if (i_dram_width == fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X4)
	{
	    number_nets_term_rd = number_nets_term_rd + 36 + 0 + 0;
	    number_nets_term_wr = number_nets_term_wr + 36 + 0 + 0;
	}
	else if ((i_dram_width == fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X8) &&
		 (i_dram_tdqs == fapi::ENUM_ATTR_EFF_DRAM_TDQS_DISABLE))
	{
	    number_nets_term_rd = number_nets_term_rd + 18 + 0 + 0;
	    number_nets_term_wr = number_nets_term_wr + 18 + 9 + 0;
	}
	else if ((i_dram_width == fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X8) &&
		 (i_dram_tdqs == fapi::ENUM_ATTR_EFF_DRAM_TDQS_ENABLE))
	{
	    number_nets_term_rd = number_nets_term_rd + 18 + 0 + 18;
	    number_nets_term_wr = number_nets_term_wr + 18 + 0 + 18;
	}

// which rank is mapped to the [01]ODT[01] nets, from centaur spec, every type
// uses Ranks 0,1,4,5, with the following exceptions
// Type 1D used Ranks 0,2,4,6 in that order (0_ODT0,0_ODT1,1_ODT0,1_ODT1)
// expect that EFF_ODT_RD and EFF_ODT_WR will be setup correctly so we just need
// to add up any termination in parallel for the bits set in these attributes
// Also need to consider if ODT is tied high for writes (if rtt_wr is set for
// the rank being written to, then it will be assumed that ODT is tied high)

	if (i_ibm_type[i_port][i_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_1D)
	{
	    ma0odt01_dimm = 0;
	    ma1odt01_dimm = 1;
	    ma0odt0_rank = 0;
	    ma0odt1_rank = 2;
	    ma1odt0_rank = 0;
	    ma1odt1_rank = 2;
	}
	else
	{
	    ma0odt01_dimm = 0;
	    ma1odt01_dimm = 1;
	    ma0odt0_rank = 0;
	    ma0odt1_rank = 1;
	    ma1odt0_rank = 0;
	    ma1odt1_rank = 1;
	}

// check to see if rank is configured, only get termination power for these
// ranks
	rank_mask = 0x00;
	if (i_rank == 0)
	{
	    rank_mask = 0x80;
	}
	else if (i_rank == 1)
	{
	    rank_mask = 0x40;
	}
	else if (i_rank == 2)
	{
	    rank_mask = 0x20;
	}
	else if (i_rank == 3)
	{
	    rank_mask = 0x10;
	}
	if ((i_dimm_ranks_configed_array[i_port][i_dimm] & rank_mask) != 0)
	{
// effective net termination = [(active termination in parallel || driver
// impedance) + active termination in parallel]



//------------------------------------------------------------------------------
// calculate out effective termination for reads
//------------------------------------------------------------------------------
	    eff_term_rd = 0;

//------------------------------------------------------------------------------
// 0ODT0
	    if (
		((i_dimm_rank_odt_rd[i_port][i_dimm][i_rank] & 0x80) != 0)
		&&
		(i_dram_rtt_nom[i_port][ma0odt01_dimm][ma0odt0_rank] !=
		 fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE)
		)
	    {
		if (eff_term_rd == 0)
		{
		    eff_term_rd =
		      i_dram_rtt_nom[i_port][ma0odt01_dimm][ma0odt0_rank];
		}
		else
		{
		    eff_term_rd =
		      (eff_term_rd *
		       i_dram_rtt_nom[i_port][ma0odt01_dimm][ma0odt0_rank])
		      /
		      (eff_term_rd +
		       i_dram_rtt_nom[i_port][ma0odt01_dimm][ma0odt0_rank]);
		}
		FAPI_DBG("[P%d:D%d:R%d] 0ODT0 RD TERMINATION = %4.2f (%d)", i_port, i_dimm, i_rank, eff_term_rd, i_dram_rtt_nom[i_port][ma0odt01_dimm][ma0odt0_rank]);

	    }
//------------------------------------------------------------------------------
// 0ODT1
	    if (
		((i_dimm_rank_odt_rd[i_port][i_dimm][i_rank] & 0x40) != 0)
		&&
		(i_dram_rtt_nom[i_port][ma0odt01_dimm][ma0odt1_rank] !=
		 fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE)
		)
	    {
		if (eff_term_rd == 0)
		{
		    eff_term_rd =
		      i_dram_rtt_nom[i_port][ma0odt01_dimm][ma0odt1_rank];
		}
		else
		{
		    eff_term_rd =
		      (eff_term_rd *
		       i_dram_rtt_nom[i_port][ma0odt01_dimm][ma0odt1_rank])
		      /
		      (eff_term_rd +
		       i_dram_rtt_nom[i_port][ma0odt01_dimm][ma0odt1_rank]);
		}
		FAPI_DBG("[P%d:D%d:R%d] 0ODT1 RD TERMINATION = %4.2f (%d)", i_port, i_dimm, i_rank, eff_term_rd, i_dram_rtt_nom[i_port][ma0odt01_dimm][ma0odt1_rank]);
	    }
//------------------------------------------------------------------------------
// 1ODT0
	    if (
		((i_dimm_rank_odt_rd[i_port][i_dimm][i_rank] & 0x20) != 0)
		&&
		(i_dram_rtt_nom[i_port][ma1odt01_dimm][ma1odt0_rank] !=
		 fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE)
		)
	    {
		if (eff_term_rd == 0)
		{
		    eff_term_rd =
		      i_dram_rtt_nom[i_port][ma1odt01_dimm][ma1odt0_rank];
		}
		else
		{
		    eff_term_rd =
		      (eff_term_rd *
		       i_dram_rtt_nom[i_port][ma1odt01_dimm][ma1odt0_rank])
		      /
		      (eff_term_rd +
		       i_dram_rtt_nom[i_port][ma1odt01_dimm][ma1odt0_rank]);
		}
		FAPI_DBG("[P%d:D%d:R%d] 1ODT0 RD TERMINATION = %4.2f (%d)", i_port, i_dimm, i_rank, eff_term_rd, i_dram_rtt_nom[i_port][ma1odt01_dimm][ma1odt0_rank]);
	    }
//------------------------------------------------------------------------------
// 1ODT1
	    if (
		((i_dimm_rank_odt_rd[i_port][i_dimm][i_rank] & 0x10) != 0)
		&&
		(i_dram_rtt_nom[i_port][ma1odt01_dimm][ma1odt1_rank] !=
		 fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE)
		)
	    {
		if (eff_term_rd == 0)
		{
		    eff_term_rd =
		      i_dram_rtt_nom[i_port][ma1odt01_dimm][ma1odt1_rank];
		}
		else
		{
		    eff_term_rd =
		      (eff_term_rd *
		       i_dram_rtt_nom[i_port][ma1odt01_dimm][ma1odt1_rank])
		      /
		      (eff_term_rd +
		       i_dram_rtt_nom[i_port][ma1odt01_dimm][ma1odt1_rank]);
		}
		FAPI_DBG("[P%d:D%d:R%d] 1ODT1 RD TERMINATION = %4.2f (%d)", i_port, i_dimm, i_rank, eff_term_rd, i_dram_rtt_nom[i_port][ma1odt01_dimm][ma1odt1_rank]);
	    }

// calculate out effective read termination
	    if (eff_term_rd != 0)
	    {
		eff_net_term_rd =
		  (float(
			 (float(eff_term_rd * i_cen_dq_dqs_rcv_imp[i_port]) /
			  (eff_term_rd + i_cen_dq_dqs_rcv_imp[i_port]))
			 * i_dimm_dram_ron[i_port][i_dimm]
			 )
		   /
		   (
		    (float(eff_term_rd * i_cen_dq_dqs_rcv_imp[i_port]) /
		     (eff_term_rd + i_cen_dq_dqs_rcv_imp[i_port])
		     )
		    + i_dimm_dram_ron[i_port][i_dimm]
		    )
		   )
		  +
		  (float(eff_term_rd * i_cen_dq_dqs_rcv_imp[i_port]) /
		   (eff_term_rd + i_cen_dq_dqs_rcv_imp[i_port]));
		term_odt_mult_rd = 1.25;
	    }
	    else
	    {
		eff_net_term_rd =
		  (float((i_cen_dq_dqs_rcv_imp[i_port]) *
			 i_dimm_dram_ron[i_port][i_dimm])
		   / ((i_cen_dq_dqs_rcv_imp[i_port]) +
		      i_dimm_dram_ron[i_port][i_dimm])
		   )
		  +
		  (i_cen_dq_dqs_rcv_imp[i_port]);
		term_odt_mult_rd = 1;
	    }
// writes
//------------------------------------------------------------------------------
// calculate out effective termination for writes
//------------------------------------------------------------------------------
	    eff_term_wr = 0;

// check to see if ODT is tied high (rank is not one of the ranks that get ODT
// driven to it, and rtt_wr or rtt_nom are enabled)
	    if (
		(
		 (((i_rank != ma0odt0_rank) && (i_rank != ma0odt1_rank)) &&
		  (i_dimm == 0))
		 ||
		 (((i_rank != ma1odt0_rank) && (i_rank != ma1odt1_rank)) &&
		  (i_dimm == 1))
		 )
		&&
		((i_dram_rtt_wr[i_port][i_dimm][i_rank] !=
		  fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE) ||
		 (i_dram_rtt_nom[i_port][i_dimm][i_rank] !=
		  fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE))
		)
	    {
// dynamic ODT enabled, so use rtt_wr (only if the rank being written to has
// it enabled)
		if (i_dram_rtt_wr[i_port][i_dimm][i_rank] !=
		    fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE)
		{
		    if (eff_term_wr == 0)
		    {
			eff_term_wr = i_dram_rtt_wr[i_port][i_dimm][i_rank];
		    }
		    else
		    {
			eff_term_wr =
			  (eff_term_wr * i_dram_rtt_wr[i_port][i_dimm][i_rank])
			  /
			  (eff_term_wr + i_dram_rtt_wr[i_port][i_dimm][i_rank]);
		    }
		}

		// dynamic ODT disabled, so use rtt_nom
		else if (i_dram_rtt_nom[i_port][i_dimm][i_rank] !=
			 fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE)
		{
		    if (eff_term_wr == 0)
		    {
			eff_term_wr = i_dram_rtt_nom[i_port][i_dimm][i_rank];
		    }
		    else
		    {
			eff_term_wr =
			  (eff_term_wr * i_dram_rtt_nom[i_port][i_dimm][i_rank])
			  /
			  (eff_term_wr +
			   i_dram_rtt_nom[i_port][i_dimm][i_rank]);
		    }

		}
		FAPI_DBG("[P%d:D%d:R%d] WR TERMINATION = %4.2f (%d/%d)", i_port, i_dimm, i_rank, eff_term_wr, i_dram_rtt_wr[i_port][i_dimm][i_rank], i_dram_rtt_nom[i_port][i_dimm][i_rank]);
	    }
//------------------------------------------------------------------------------
// 0ODT0
	    if (
		((i_dimm_rank_odt_wr[i_port][i_dimm][i_rank] & 0x80) != 0)
		&&
		((i_dram_rtt_wr[i_port][ma0odt01_dimm][ma0odt0_rank] !=
		  fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE) ||
		 (i_dram_rtt_nom[i_port][ma0odt01_dimm][ma0odt0_rank] !=
		  fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE))
		)
	    {
// dynamic ODT enabled, so use rtt_wr (only if the rank being written to has
// it enabled)
		if (
		    (i_dram_rtt_wr[i_port][ma0odt01_dimm][ma0odt0_rank] !=
		     fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE)
		    && (i_dimm == 0)
		    && (i_rank == ma0odt0_rank)
		    )
		{
		    if (eff_term_wr == 0)
		    {
			eff_term_wr =
			  i_dram_rtt_wr[i_port][ma0odt01_dimm][ma0odt0_rank];
		    }
		    else
		    {
			eff_term_wr =
			  (eff_term_wr *
			   i_dram_rtt_wr[i_port][ma0odt01_dimm][ma0odt0_rank])
			  /
			  (eff_term_wr +
			   i_dram_rtt_wr[i_port][ma0odt01_dimm][ma0odt0_rank]);
		    }
		}
		// dynamic ODT disabled, so use rtt_nom
		else if (i_dram_rtt_nom[i_port][ma0odt01_dimm][ma0odt0_rank] !=
			 fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE)
		{
		    if (eff_term_wr == 0)
		    {
			eff_term_wr =
			  i_dram_rtt_nom[i_port][ma0odt01_dimm][ma0odt0_rank];
		    }
		    else
		    {
			eff_term_wr =
			  (eff_term_wr *
			   i_dram_rtt_nom[i_port][ma0odt01_dimm][ma0odt0_rank])
			  /
			  (eff_term_wr +
			   i_dram_rtt_nom[i_port][ma0odt01_dimm][ma0odt0_rank]);
		    }

		}
		FAPI_DBG("[P%d:D%d:R%d] 0ODT0 WR TERMINATION = %4.2f (%d/%d)", i_port, i_dimm, i_rank, eff_term_wr, i_dram_rtt_nom[i_port][ma0odt01_dimm][ma0odt0_rank], i_dram_rtt_wr[i_port][ma0odt01_dimm][ma0odt0_rank]);
	    }
//------------------------------------------------------------------------------
// 0ODT1
	    if (
		((i_dimm_rank_odt_wr[i_port][i_dimm][i_rank] & 0x40) != 0)
		&&
		((i_dram_rtt_wr[i_port][ma0odt01_dimm][ma0odt1_rank] !=
		  fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE) ||
		 (i_dram_rtt_nom[i_port][ma0odt01_dimm][ma0odt1_rank] !=
		  fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE))
		)
	    {
// dynamic ODT enabled, so use rtt_wr (only if the rank being written to has
// it enabled)
		if (
		    (i_dram_rtt_wr[i_port][ma0odt01_dimm][ma0odt1_rank] !=
		     fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE)
		    && (i_dimm == 0)
		    && (i_rank == ma0odt1_rank)
		    )
		{
		    if (eff_term_wr == 0)
		    {
			eff_term_wr =
			  i_dram_rtt_wr[i_port][ma0odt01_dimm][ma0odt1_rank];
		    }
		    else
		    {
			eff_term_wr =
			  (eff_term_wr *
			   i_dram_rtt_wr[i_port][ma0odt01_dimm][ma0odt1_rank])
			  /
			  (eff_term_wr +
			   i_dram_rtt_wr[i_port][ma0odt01_dimm][ma0odt1_rank]);
		    }
		}
// dynamic ODT disabled, so use rtt_nom
		else if (i_dram_rtt_nom[i_port][ma0odt01_dimm][ma0odt1_rank] !=
			 fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE)
		{
		    if (eff_term_wr == 0)
		    {
			eff_term_wr =
			  i_dram_rtt_nom[i_port][ma0odt01_dimm][ma0odt1_rank];
		    }
		    else
		    {
			eff_term_wr =
			  (eff_term_wr *
			   i_dram_rtt_nom[i_port][ma0odt01_dimm][ma0odt1_rank])
			  /
			  (eff_term_wr +
			   i_dram_rtt_nom[i_port][ma0odt01_dimm][ma0odt1_rank]);
		    }

		}
		FAPI_DBG("[P%d:D%d:R%d] 0ODT1 WR TERMINATION = %4.2f (%d/%d)", i_port, i_dimm, i_rank, eff_term_wr, i_dram_rtt_nom[i_port][ma0odt01_dimm][ma0odt1_rank], i_dram_rtt_wr[i_port][ma0odt01_dimm][ma0odt1_rank]);
	    }
//------------------------------------------------------------------------------
// 1ODT0
	    if (
		((i_dimm_rank_odt_wr[i_port][i_dimm][i_rank] & 0x20) != 0)
		&&
		((i_dram_rtt_wr[i_port][ma1odt01_dimm][ma1odt0_rank] !=
		  fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE) ||
		 (i_dram_rtt_nom[i_port][ma1odt01_dimm][ma1odt0_rank] !=
		  fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE))
		)
	    {
// dynamic ODT enabled, so use rtt_wr (only if the rank being written to has
// it enabled)
		if (
		    (i_dram_rtt_wr[i_port][ma1odt01_dimm][ma1odt0_rank] !=
		     fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE)
		    && (i_dimm == 1)
		    && (i_rank == ma1odt0_rank)
		    )
		{
		    if (eff_term_wr == 0)
		    {
			eff_term_wr =
			  i_dram_rtt_wr[i_port][ma1odt01_dimm][ma1odt0_rank];
		    }
		    else
		    {
			eff_term_wr =
			  (eff_term_wr *
			   i_dram_rtt_wr[i_port][ma1odt01_dimm][ma1odt0_rank])
			  /
			  (eff_term_wr +
			   i_dram_rtt_wr[i_port][ma1odt01_dimm][ma1odt0_rank]);
		    }
		}
		// dynamic ODT disabled, so use rtt_nom
		else if (i_dram_rtt_nom[i_port][ma1odt01_dimm][ma1odt0_rank] !=
			 fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE)
		{
		    if (eff_term_wr == 0)
		    {
			eff_term_wr =
			  i_dram_rtt_nom[i_port][ma1odt01_dimm][ma1odt0_rank];
		    }
		    else
		    {
			eff_term_wr =
			  (eff_term_wr *
			   i_dram_rtt_nom[i_port][ma1odt01_dimm][ma1odt0_rank])
			  /
			  (eff_term_wr +
			   i_dram_rtt_nom[i_port][ma1odt01_dimm][ma1odt0_rank]);
		    }

		}
		FAPI_DBG("[P%d:D%d:R%d] 1ODT0 WR TERMINATION = %4.2f (%d/%d)", i_port, i_dimm, i_rank, eff_term_wr, i_dram_rtt_nom[i_port][ma1odt01_dimm][ma1odt0_rank], i_dram_rtt_wr[i_port][ma1odt01_dimm][ma1odt0_rank]);
	    }
//------------------------------------------------------------------------------
// 1ODT1
	    if (
		((i_dimm_rank_odt_wr[i_port][i_dimm][i_rank] & 0x10) != 0)
		&&
		((i_dram_rtt_wr[i_port][ma1odt01_dimm][ma1odt1_rank] !=
		  fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE) ||
		 (i_dram_rtt_nom[i_port][ma1odt01_dimm][ma1odt1_rank] !=
		  fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE))
		)
	    {
// dynamic ODT enabled, so use rtt_wr (only if the rank being written to has
// it enabled)
		if (
		    (i_dram_rtt_wr[i_port][ma1odt01_dimm][ma1odt1_rank] !=
		     fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE)
		    && (i_dimm == 1)
		    && (i_rank == ma1odt1_rank)
		    )
		{
		    if (eff_term_wr == 0)
		    {
			eff_term_wr =
			  i_dram_rtt_wr[i_port][ma1odt01_dimm][ma1odt1_rank];
		    }
		    else
		    {
			eff_term_wr =
			  (eff_term_wr *
			   i_dram_rtt_wr[i_port][ma1odt01_dimm][ma1odt1_rank])
			  /
			  (eff_term_wr +
			   i_dram_rtt_wr[i_port][ma1odt01_dimm][ma1odt1_rank]);
		    }
		}
		// dynamic ODT disabled, so use rtt_nom
		else if (i_dram_rtt_nom[i_port][ma1odt01_dimm][ma1odt1_rank] !=
			 fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE)
		{
		    if (eff_term_wr == 0)
		    {
			eff_term_wr =
			  i_dram_rtt_nom[i_port][ma1odt01_dimm][ma1odt1_rank];
		    }
		    else
		    {
			eff_term_wr =
			  (eff_term_wr *
			   i_dram_rtt_nom[i_port][ma1odt01_dimm][ma1odt1_rank])
			  /
			  (eff_term_wr +
			   i_dram_rtt_nom[i_port][ma1odt01_dimm][ma1odt1_rank]);
		    }

		}
		FAPI_DBG("[P%d:D%d:R%d] 1ODT1 WR TERMINATION = %4.2f (%d/%d)", i_port, i_dimm, i_rank, eff_term_wr, i_dram_rtt_nom[i_port][ma1odt01_dimm][ma1odt1_rank], i_dram_rtt_wr[i_port][ma1odt01_dimm][ma1odt1_rank]);
	    }


// Translate enum value to a resistance value for i_cen_dq_dqs_drv_imp[i_port]
	    rc = mss_eff_config_thermal_get_cen_drv_value
	      (
	       i_cen_dq_dqs_drv_imp[i_port],
	       cen_dq_dqs_drv_imp_value
	       );
	    if (rc)
	    {
		FAPI_ERR("Error (0x%x) calling mss_eff_config_thermal_get_cen_drv_value", static_cast<uint32_t>(rc));
		return rc;
	    }

	    if (eff_term_wr != 0)
	    {
		eff_net_term_wr =
		  (float(eff_term_wr * cen_dq_dqs_drv_imp_value) /
		   (eff_term_wr + cen_dq_dqs_drv_imp_value)) + eff_term_wr;
		term_odt_mult_wr = 1.25;
	    }
	    else
	    {
		eff_net_term_wr = cen_dq_dqs_drv_imp_value;
		term_odt_mult_wr = 1;
	    }

//------------------------------------------------------------------------------
// From Warren:
// Termination power = (voltage/net termination) * number of nets *
// (% of traffic on bus*1.25)
// The net termination is the effective termination that exists between the
// power rail and ground. So in my calculations this is all the active
// termination in parallel with the driver impedance + all the active
//  termination in parallel. The value is different for reads and writes. 
// Number of nets includes the strobe nets (2 nets per strobe)
// % of traffic on bus is the % of the bus used for data traffic split out from
// reads and writes. The 1.25 factor is due to the odt_en signals being active
// longer then the data windows.
// Value here is in Watts (W)
	    o_dimm_power_adder_termination =
	      float(i_dimm_voltage) / 1000
	      *
	      (
	       ((float(i_dimm_voltage) / 1000 / eff_net_term_rd) *
		(number_nets_term_rd) *
		(float(ACTIVE_DIMM_UTILIZATION) / 100) *
		(float(DATA_BUS_READ_PERCENT) / 100) * (term_odt_mult_rd))
	       +
	       ((float(i_dimm_voltage) / 1000 / eff_net_term_wr) *
		(number_nets_term_wr) *
		(float(ACTIVE_DIMM_UTILIZATION) / 100) *
		(float(DATA_BUS_WRITE_PERCENT) / 100) * (term_odt_mult_wr))
	       );
	    FAPI_DBG("%s TERM:[P%d:D%d:R%d] CEN[DRV=%d RCV=%d] DRAM[DRV=%d ODT_RD=%4.2f ODT_WR=%4.2f]", i_nom_or_wc_term, i_port, i_dimm, i_rank, cen_dq_dqs_drv_imp_value, i_cen_dq_dqs_rcv_imp[i_port], i_dimm_dram_ron[i_port][i_dimm], eff_term_rd, eff_term_wr);
	    FAPI_DBG("%s TERM POWER:[P%d:D%d:R%d] RD[Nets=%d EffTerm=%3.2f ODTMult=%1.2f] WR[Nets=%d EffTerm=%3.2f ODTMult=%1.2f] TermPower(%d%%)=%2.2f W", i_nom_or_wc_term, i_port, i_dimm, i_rank, number_nets_term_rd, eff_net_term_rd, term_odt_mult_rd, number_nets_term_wr, eff_net_term_wr, term_odt_mult_wr, ACTIVE_DIMM_UTILIZATION, o_dimm_power_adder_termination);
	}	

	FAPI_IMP("*** %s COMPLETE ***", procedure_name);
	return rc;
    }

//------------------------------------------------------------------------------
// @brief mss_eff_config_thermal_get_wc_term(): This function finds the worst
// case termination settings possible for a given set of termination settings
//
// @param[in]	const fapi::Target &i_target_mba:  MBA Target
// @param[in]   uint8_t i_port:  MBA port being worked on
// @param[out]  uint8_t &o_cen_dq_dqs_rcv_imp_wc:  Worst Case Centaur DQ/DQS
//              receiver impedance (output)
// @param[out]  uint8_t &o_cen_dq_dqs_drv_imp_wc:  Worst Case Centaur DQ/DQS 
//              driver impedance (output)
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------

    fapi::ReturnCode mss_eff_config_thermal_get_wc_term
      (
       const fapi::Target &i_target_mba,
       uint8_t i_port,
       uint8_t &o_cen_dq_dqs_rcv_imp_wc,
       uint8_t &o_cen_dq_dqs_drv_imp_wc
       )
    {
	fapi::ReturnCode rc = fapi::FAPI_RC_SUCCESS;

	char procedure_name[32];
	sprintf(procedure_name, "mss_eff_config_thermal_get_wc_term");
	FAPI_IMP("*** Running %s ***", procedure_name);

	uint8_t l_cen_dq_dqs_rcv_imp[NUM_PORTS];
	uint8_t l_cen_dq_dqs_drv_imp[NUM_PORTS];
	uint32_t l_cen_dq_dqs_rcv_imp_schmoo[NUM_PORTS];
	uint32_t l_cen_dq_dqs_drv_imp_schmoo[NUM_PORTS];
	uint32_t l_loop;
	uint32_t l_schmoo_mask;

// This lists out the number and enum values for the centaur dq/dqs receiver and
// driver impedance.  Have the list go from strongest to weakest termination.
// If the size changes at all, then updates are needed below to get the correct
// mask

	const uint8_t MAX_CEN_RCV_IMP = 10;
	uint8_t cen_rcv_imp_array[] = {
	    fapi::ENUM_ATTR_EFF_CEN_RCV_IMP_DQ_DQS_OHM15,
	    fapi::ENUM_ATTR_EFF_CEN_RCV_IMP_DQ_DQS_OHM20,
	    fapi::ENUM_ATTR_EFF_CEN_RCV_IMP_DQ_DQS_OHM30,
	    fapi::ENUM_ATTR_EFF_CEN_RCV_IMP_DQ_DQS_OHM40,
	    fapi::ENUM_ATTR_EFF_CEN_RCV_IMP_DQ_DQS_OHM48,
	    fapi::ENUM_ATTR_EFF_CEN_RCV_IMP_DQ_DQS_OHM60,
	    fapi::ENUM_ATTR_EFF_CEN_RCV_IMP_DQ_DQS_OHM80,
	    fapi::ENUM_ATTR_EFF_CEN_RCV_IMP_DQ_DQS_OHM120,
	    fapi::ENUM_ATTR_EFF_CEN_RCV_IMP_DQ_DQS_OHM160,
	    fapi::ENUM_ATTR_EFF_CEN_RCV_IMP_DQ_DQS_OHM240
	}; 

	const uint8_t MAX_CEN_DRV_IMP = 16;
	uint8_t cen_drv_imp_array[] = {
	    fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM24_FFE0,
	    fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE0,
	    fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE480,
	    fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE240,
	    fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE160,
	    fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE120,
	    fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0,
	    fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE480,
	    fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE240,
	    fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE160,
	    fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE120,
	    fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE0,
	    fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE480,
	    fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE240,
	    fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE160,
	    fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE120
	};


// Get attributes for nominal settings and possible settings to choose from
	rc = FAPI_ATTR_GET(ATTR_EFF_CEN_RCV_IMP_DQ_DQS,
			   &i_target_mba, l_cen_dq_dqs_rcv_imp);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_CEN_RCV_IMP_DQ_DQS");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS,
			   &i_target_mba, l_cen_dq_dqs_drv_imp);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_CEN_DRV_IMP_DQ_DQS");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_CEN_RCV_IMP_DQ_DQS_SCHMOO,
			   &i_target_mba, l_cen_dq_dqs_rcv_imp_schmoo);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_CEN_RCV_IMP_DQ_DQS_SCHMOO");
	    return rc;
	}
	rc = FAPI_ATTR_GET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS_SCHMOO,
			   &i_target_mba, l_cen_dq_dqs_drv_imp_schmoo);
	if (rc) {
	    FAPI_ERR("Error getting attribute ATTR_EFF_CEN_DRV_IMP_DQ_DQS_SCHMOO");
	    return rc;
	}

// initialize to default values in case below does not find a match
	o_cen_dq_dqs_rcv_imp_wc = l_cen_dq_dqs_rcv_imp[i_port];
	o_cen_dq_dqs_drv_imp_wc = l_cen_dq_dqs_drv_imp[i_port];

// find strongest termination setting that could be used, if none found, then
// use nominal
	l_schmoo_mask = 0x00000000;
	for (l_loop=0; l_loop < MAX_CEN_RCV_IMP; l_loop++)
	{
	    switch (l_loop)
	    {
		case 0:
		    l_schmoo_mask = 0x80000000;
		    break;
		case 1:
		    l_schmoo_mask = 0x40000000;
		    break;
		case 2:
		    l_schmoo_mask = 0x20000000;
		    break;
		case 3:
		    l_schmoo_mask = 0x10000000;
		    break;
		case 4:
		    l_schmoo_mask = 0x08000000;
		    break;
		case 5:
		    l_schmoo_mask = 0x04000000;
		    break;
		case 6:
		    l_schmoo_mask = 0x02000000;
		    break;
		case 7:
		    l_schmoo_mask = 0x01000000;
		    break;
		case 8:
		    l_schmoo_mask = 0x00800000;
		    break;
		case 9:
		    l_schmoo_mask = 0x00400000;
		    break;
		default:
		    o_cen_dq_dqs_rcv_imp_wc = l_cen_dq_dqs_rcv_imp[i_port];
	    }
	    if ((l_cen_dq_dqs_rcv_imp_schmoo[i_port] & l_schmoo_mask) != 0)
	    {
		o_cen_dq_dqs_rcv_imp_wc = cen_rcv_imp_array[l_loop];
		break;
	    }
	}

	l_schmoo_mask = 0x00000000;
	for (l_loop=0; l_loop < MAX_CEN_DRV_IMP; l_loop++)
	{
	    switch (l_loop)
	    {
		case 0:
		    l_schmoo_mask = 0x80000000;
		    break;
		case 1:
		    l_schmoo_mask = 0x40000000;
		    break;
		case 2:
		    l_schmoo_mask = 0x20000000;
		    break;
		case 3:
		    l_schmoo_mask = 0x10000000;
		    break;
		case 4:
		    l_schmoo_mask = 0x08000000;
		    break;
		case 5:
		    l_schmoo_mask = 0x04000000;
		    break;
		case 6:
		    l_schmoo_mask = 0x02000000;
		    break;
		case 7:
		    l_schmoo_mask = 0x01000000;
		    break;
		case 8:
		    l_schmoo_mask = 0x00800000;
		    break;
		case 9:
		    l_schmoo_mask = 0x00400000;
		    break;
		case 10:
		    l_schmoo_mask = 0x00200000;
		    break;
		case 11:
		    l_schmoo_mask = 0x00100000;
		    break;
		case 12:
		    l_schmoo_mask = 0x00080000;
		    break;
		case 13:
		    l_schmoo_mask = 0x00040000;
		    break;
		case 14:
		    l_schmoo_mask = 0x00020000;
		    break;
		case 15:
		    l_schmoo_mask = 0x00010000;
		    break;
		default:
		    o_cen_dq_dqs_drv_imp_wc = l_cen_dq_dqs_drv_imp[i_port];
	    }
	    if ((l_cen_dq_dqs_drv_imp_schmoo[i_port] & l_schmoo_mask) != 0)
	    {
		o_cen_dq_dqs_drv_imp_wc = cen_drv_imp_array[l_loop];
		break;
	    }
	}

	FAPI_IMP("*** %s COMPLETE ***", procedure_name);
	return rc;
    }


//------------------------------------------------------------------------------
// @brief mss_eff_config_thermal_get_cen_drv_value(): This function will
// translate the centaur driver impedance enum value to a termination resistance
//
// @param[in]	uint8_t &i_cen_dq_dqs_drv_imp:  Centaur DQ/DQS driver impedance
//           enum setting (input)
// @param[out]  uint8_t &o_cen_dq_dqs_drv_imp:  Centaur DQ/DQS driver impedance
//           value (output)
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------

    fapi::ReturnCode mss_eff_config_thermal_get_cen_drv_value
      (
       uint8_t i_cen_dq_dqs_drv_imp,
       uint8_t &o_cen_dq_dqs_drv_imp
       )
    {
	fapi::ReturnCode rc = fapi::FAPI_RC_SUCCESS;

	char procedure_name[32];
	sprintf(procedure_name, "mss_eff_config_thermal_get_cen_drv_value");
	FAPI_IMP("*** Running %s ***", procedure_name);

	switch (i_cen_dq_dqs_drv_imp)
	{
	    case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM24_FFE0:
		o_cen_dq_dqs_drv_imp = 24;
		break;
	    case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE0:
		o_cen_dq_dqs_drv_imp = 30;
		break;
	    case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE480:
		o_cen_dq_dqs_drv_imp = 30;
		break;
	    case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE240:
		o_cen_dq_dqs_drv_imp = 30;
		break;
	    case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE160:
		o_cen_dq_dqs_drv_imp = 30;
		break;
	    case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE120:
		o_cen_dq_dqs_drv_imp = 30;
		break;
	    case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0:
		o_cen_dq_dqs_drv_imp = 34;
		break;
	    case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE480:
		o_cen_dq_dqs_drv_imp = 34;
		break;
	    case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE240:
		o_cen_dq_dqs_drv_imp = 34;
		break;
	    case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE160:
		o_cen_dq_dqs_drv_imp = 34;
		break;
	    case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE120:
		o_cen_dq_dqs_drv_imp = 34;
		break;
	    case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE0:
		o_cen_dq_dqs_drv_imp = 40;
		break;
	    case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE480:
		o_cen_dq_dqs_drv_imp = 40;
		break;
	    case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE240:
		o_cen_dq_dqs_drv_imp = 40;
		break;
	    case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE160:
		o_cen_dq_dqs_drv_imp = 40;
		break;
	    case fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE120:
		o_cen_dq_dqs_drv_imp = 40;
		break;
	    default:
		o_cen_dq_dqs_drv_imp = 24;
	}

	FAPI_IMP("*** %s COMPLETE ***", procedure_name);
	return rc;
    }


} //end extern C
