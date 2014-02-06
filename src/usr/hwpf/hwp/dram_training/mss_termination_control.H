/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_termination_control.H $    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: mss_termination_control.H,v 1.12 2014/01/22 15:39:22 mjjones Exp $
/* File is created by SARAVANAN SETHURAMAN on Thur Sept 28 2011. */

//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2007
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE :mss_draminit_training_advanced.H
// *! DESCRIPTION : Tools for centaur procedures
// *! OWNER NAME :  Saravanan sethuraman    Email ID: saravanans@in.ibm.com
// *! BACKUP NAME : Menlo Wuu               Email ID: menlowuu@us.ibm.com
// #! ADDITIONAL COMMENTS :
//
// General purpose funcs

//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author:  |  Date:   | Comment:
//---------|---------- |--------- |---------------------------------------------
//  1.12   | 22-Jan-14 | mjjones  | Removed FW header
//  1.11   | 21-Jan-14 | abhijsau | mike and menlo fixed ras review comments
//  1.10   | 14-Dec-12 | sasethur | Updated for fw review comments
//  1.9    | 07-Dec-12 | sasethur | Updated for fw review comments
//  1.8	   | 16-Nov-12 | mwuu	  | Added typedef for external call of
//                                  mss_slew_cal F
//  1.7	   | 14-Nov-12 | mwuu	  | Changed "l_" variables to "i_" in 
//  								config_slew_rate FN
//  1.6	   | 14-Nov-12 | mwuu	  | Fixed revision numbering in comments
//  1.5    | 14-Nov-12 | mwuu     | Added additional slew rates, and new const
//  1.4    | 26-Oct-12 | mwuu     | Added additional slew types enums, need to
//  								change MAX_NUM_SLEW_TYPES when attributes
//  								updated.
//  1.3    | 26-Oct-12 | sasethur | Updated FW review comments fapi::,
//  								const fapi::Target
//  1.2	   | 17-Oct-12 | mwuu	  | updates to enum and consts
//  1.1    | 28-Sep-12 | sasethur | First draft


#ifndef MSS_TERMINATION_CONTROL_H
#define MSS_TERMINATION_CONTROL_H
//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi.H>

enum {
	SLEW_TYPE_DATA = 0,
	SLEW_TYPE_ADR_ADDR = 1,
	SLEW_TYPE_ADR_CNTL = 2,
	SLEW_TYPE_ADR_CLK = 3,
	SLEW_TYPE_ADR_SPCKE = 4,

	OHM15 = 15,
	OHM20 = 20,
	OHM24 = 24,
	OHM30 = 30,
	OHM34 = 34,
	OHM40 = 40,

	SLEW_3V_NS = 3,
	SLEW_4V_NS = 4,
	SLEW_5V_NS = 5,
	SLEW_6V_NS = 6,
	SLEW_MAXV_NS = 7,
};

const uint8_t MAX_NUM_PORTS = 2;		// max number of ports
const uint8_t MAX_NUM_SLEW_TYPES = 5;	// data(dq/dqs), adr_cmd, adr_cntl, clk, spcke, used by slew_cal FN only
const uint8_t MAX_NUM_IMP = 4;		// number of impedances valid per slew type

//Address shmoo is not done as a part of Training advanced, so the order matches
//attribute enum
const uint8_t adr_imp_array[] = {
	15,
	20,
	30,
	40,
};

// bypass slew (MAX slew rate) not included since it is not calibrated.
const uint8_t MAX_NUM_CAL_SLEW_RATES = 4 ;	// 3V/ns, 4V/ns, 5V/ns, 6V/n
const uint8_t MAX_NUM_SLEW_RATES = 4;	// 3V/ns, 4V/ns, 5V/ns, 6V/n, MAX?
const uint8_t slew_rate_array[] = {
	6,
	5,
	4,
    3,
};

const uint8_t MAX_SLEW_VALUE = 15;		// 4 bit value
const uint8_t MAX_WR_VREF = 32;

const uint32_t wr_vref_array[] = {
	420,
	425,
	430,
	435,
	440,
	445,
	450,
	455,
	460,
	465,
	470,
	475,
	480,
	485,
	490,
	495,
	500,
	505,
	510,
	515,
	520,
	525,
	530,
	535,
	540,
	545,
	550,
	555,
	560,
	565,
	570,
	575
	};


//The Array is re-arranged inorder to find the best Eye margin based on the
//Fitness level - 500 is the best value
const uint32_t wr_vref_array_fitness[] = {
	420,
	425,
	575,
	430,
	570,
	435,
	565,
	440,
	560,
	445,
	555,
	450,
	550,
	455,
	545,
	460,
	540,
	465,
	535,
	470,
	530,
	475,
	525,
	480,
	520,
	485,
	515,
	490,
	510,
	495,
	505,
	500
	};

const uint8_t MAX_RD_VREF = 16;
const uint32_t rd_cen_vref_array[] = {
	40375,
	41750,
	43125,
	44500,
	45875,
	47250,
	48625,
	50000,
	51375,
	52750,
	54125,
	55500,
	56875,
	58250,
	59625,
	61000
	};

//The Array is re-arranged inorder to find the best Eye margin based on the
//Fitness level - 50000 is the best value
const uint32_t rd_cen_vref_array_fitness[] = {
	61000,
	59625,
	40375,
	58250,
	41750,
	56875,
	43125,
	55500,
	44500,
	54125,
	45875,
	52750,
	47250,
	51375,
	48625,
	50000
	};

//The Array is re-arranged inorder to find the best Eye margin based on the
//Fitness level - 24 is the best value
const uint8_t MAX_DRV_IMP = 4;
const uint8_t drv_imp_array[] = {
	40,
	34,
	30,
	24
	};

//The Array is re-arranged inorder to find the best Eye margin based on the
//Fitness level - 15 is the best value
const uint8_t MAX_RCV_IMP = 9;
const uint8_t rcv_imp_array[] = {
	120,
    80,
    60,
    48,
    40,
    34,
    30,
    20,
    15
    };

extern "C"
{
/**
 * @brief configures PC_VREF_DRV_CONTROL registers to vary the DRAM VREF
 *
 * @param[in] i_target_mba   Reference to centaur.mba target
 * @param[in] i_port         MBA Port
 * @param[in] i_wr_dram_vref DRAM VREF to set
 *
 * @return ReturnCode
 */
fapi::ReturnCode config_wr_dram_vref(const fapi::Target & i_target_mba,
                                     uint8_t i_port,
                                     uint32_t i_wr_dram_vref);

/**
 * @brief configures read vref registers to vary the CEN VREF
 *
 * @param[in] i_target_mba   Reference to centaur.mba target
 * @param[in] i_port         MBA Port
 * @param[in] i_rd_cen_vref  CEN VREF to set
 *
 * @return ReturnCode
 */
fapi::ReturnCode config_rd_cen_vref(const fapi::Target & i_target_mba,
                                    uint8_t i_port,
                                    uint32_t i_rd_cen_vref);

/**
 * @brief configures the Driver impedance values to the registers
 *
 * @param[in] i_target_mba     Reference to centaur.mba target
 * @param[in] i_port           MBA Port
 * @param[in] i_drv_imp_dq_dqs Driver impedance values
 *
 * @return ReturnCode
 */
fapi::ReturnCode config_drv_imp(const fapi::Target & i_target_mba,
                                uint8_t i_port,
                                uint8_t i_drv_imp_dq_dqs);

/**
 * @brief configures the Receiver impedance values to the registers
 *
 * @param[in] i_target_mba     Reference to centaur.mba target
 * @param[in] i_port           MBA Port
 * @param[in] i_rcv_imp_dq_dqs Receiver impedance values
 *
 * @return ReturnCode
 */
fapi::ReturnCode config_rcv_imp(const fapi::Target & i_target_mba,
                                uint8_t i_port,
                                uint8_t i_rcv_imp_dq_dqs);

/**
 * @brief configures the Slew rate values to the registers
 *
 * @param[in] i_target_mba Reference to centaur.mba target
 * @param[in] i_port       MBA Port
 * @param[in] i_slew_type  Slew Type
 * @param[in] i_slew_imp   Slew Impedance
 * @param[in] i_slew_rate  Slew Rate
 *
 * @return ReturnCode
 */
fapi::ReturnCode config_slew_rate(const fapi::Target & i_target_mba,
	                              const uint8_t i_port,
	                              const uint8_t i_slew_type,
	                              const uint8_t i_slew_imp,
	                              const uint8_t i_slew_rate);

/**
 * @brief runs the slew calibration engine
 *
 * Configures MSS_SLEW_DATA/ADR attributes and calls config_slew_rate to set
 * the slew rate in the registers.
 *
 * @param[in] i_target_mba     Reference to centaur.mba target
 *
 * @return ReturnCode
 */
fapi::ReturnCode mss_slew_cal(const fapi::Target & i_target_mba);

} // extern C
#endif
