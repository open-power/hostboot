/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_funcs.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// $Id: mss_funcs.H,v 1.16 2013/08/27 22:23:53 kcook Exp $
/* File mss_funcs.H created by SLOAT JACOB D. (JAKE),2D3970 on Fri Apr 22 2011. */

//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2007
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE : mss_funcs.H
// *! DESCRIPTION : Tools for centaur procedures
// *! OWNER NAME :
// *! BACKUP NAME :
// #! ADDITIONAL COMMENTS :
//
// CCS related and general utility functions.

//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.16   | kcook    | 08/27/13| Removed LRDIMM functions to mss_lrdimm_funcs.H. Use with mss_funcs.C v1.33.
//  1.15   | kcook    | 08/16/13| Added LRDIMM support. Use with mss_funcs.C v1.32.
//  1.14   | jdsloat  | 04/09/13| Moved Address mirror mode sub function in  from mss_draminit
//  1.13   | jsabrow  | 11/19/12| added CCS data loader: mss_ccs_load_data_pattern
//  1.12   | 07/16/12 | bellows | added in Id tag
//  1.11   | 3/21/12  | divyakum| Added mss_execute_zq_cal function 
//  1.10   | 2/14/12  | jdsloat | Comment section filled in, elimated unnecessary constant, added enums
//  1.9    | 2/08/12  | jdsloat | Target to Target&
//  1.8    | 2/02/12  | jdsloat | Added fapi:: to arguments in function prototypes
//  1.7    | 1/13/12  | jdsloat | Capatilization, cleaned up includes, address names, "mss_" prefix, argument prefix
//  1.6    | 1/6/12   | jdsloat | Added a function call
//  1.5    | 1/5/12   | jdsloat | Got rid of Globals
//  1.4    | 10/31/11 | jdsloat | CCS Update - goto_inst now assumed to be +1, CCS_fail fix, CCS_status fix
//  1.3    | 10/06/11 | jdsloat | argument data type fix
//  1.2    | 10/05/11 | jdsloat | Convert integers to ecmdDataBufferBase in CCS_INST_1, CCS_INST_2, CCS_MODE
//  1.1    | 10/04/11 | jdsloat | First drop of Centaur in FAPI dir
//---------|----------|---------|-----------------------------------------------
//  1.6    | 09/29/11 | jdsloat | global CCS counts, port added to calls, temp dimms defined as #
//  1.5    | 09/27/11 | jdsloat | Added port information.
//  1.4    | 09/22/11 | jdsloat | Full update to FAPI.  Functional changes to match procedure.
//  1.3    | 09/13/11 | jdsloat | First attempt at FAPI upgrade - attributes still in ecmd
//  1.00   | 04/22/11 | jdsloat | First drop of Centaur

#ifndef _MSS_FUNCS_H
#define _MSS_FUNCS_H

//----------------------------------------------------------------------
//  Constants for CCS Operations
//----------------------------------------------------------------------
const uint64_t CCS_INST_ARRY0_AB_REG0_0x03010615 = 0x03010615;
const uint64_t CCS_INST_ARRY1_AB_REG0_0x03010635 = 0x03010635;

const uint64_t CCS_CNTLQ_AB_REG_0x030106A5 =   0x030106A5;
const uint64_t CCS_MODEQ_AB_REG_0x030106A7 =   0x030106A7;
const uint64_t CCS_STATQ_AB_REG_0x030106A6 =   0x030106A6;
const uint64_t MBA01_CALFIR_REG_0x03010402 =   0x03010402;


//----------------------------------------------------------------------
//  Enums for CCS Operations
//----------------------------------------------------------------------

enum mss_ccs_status_query_result
{
    MSS_STAT_QUERY_PASS = 1,
    MSS_STAT_QUERY_IN_PROGRESS = 2,
    MSS_STAT_QUERY_FAIL = 3
};


enum mss_ccs_data_pattern
{
    MSS_CCS_DATA_PATTERN_00 = 1,
    MSS_CCS_DATA_PATTERN_0F = 2,
    MSS_CCS_DATA_PATTERN_F0 = 3,
    MSS_CCS_DATA_PATTERN_FF = 4
};


const bool MSS_CCS_START = 0;
const bool MSS_CCS_STOP = 1;


//----------------------------------------------------------------------
//  CCS FUNCS
//----------------------------------------------------------------------

//--------------------------------------------------------------
// mss_ccs_inst_arry_0
// Adding information to the CCS - 0 instruction array by index
// Target = centaur.mba
//--------------------------------------------------------------
fapi::ReturnCode mss_ccs_inst_arry_0( fapi::Target& i_target,
                                      uint32_t& io_instruction_number,
                                      ecmdDataBufferBase i_address,
                                      ecmdDataBufferBase i_bank,
                                      ecmdDataBufferBase i_activate,
                                      ecmdDataBufferBase i_rasn,
                                      ecmdDataBufferBase i_casn,
                                      ecmdDataBufferBase i_wen,
                                      ecmdDataBufferBase i_cke,
                                      ecmdDataBufferBase i_csn,
                                      ecmdDataBufferBase i_odt,
                                      ecmdDataBufferBase i_ddr_cal_type,
                                      uint32_t i_port);

//--------------------------------------------------------------
// mss_ccs_inst_arry_1
// Adding information to the CCS - 1 instruction array by index
// Target = centaur.mba
//--------------------------------------------------------------
fapi::ReturnCode mss_ccs_inst_arry_1( fapi::Target& i_target,
                                      uint32_t& io_instruction_number,
                                      ecmdDataBufferBase i_num_idles,
                                      ecmdDataBufferBase i_num_repeat,
                                      ecmdDataBufferBase i_data,
                                      ecmdDataBufferBase i_read_compare,
                                      ecmdDataBufferBase i_rank_cal,
                                      ecmdDataBufferBase i_ddr_cal_enable,
                                      ecmdDataBufferBase i_ccs_end);


//---------------------------------------------------------------
// mss_ccs_load_data_pattern
// load predefined pattern (enum) into specified array1 index
// Target = centaur.mba
//---------------------------------------------------------------
fapi::ReturnCode mss_ccs_load_data_pattern( fapi::Target& i_target,
					    uint32_t io_instruction_number,
                                            mss_ccs_data_pattern data_pattern);


//---------------------------------------------------------------
// mss_ccs_load_data_pattern
// load specified pattern (20 bits) into specified array1 index
// Target = centaur.mba
//---------------------------------------------------------------
fapi::ReturnCode mss_ccs_load_data_pattern( fapi::Target& i_target,
					    uint32_t io_instruction_number,
                                            uint32_t data_pattern);


//-----------------------------------------
// mss_ccs_status_query
// Querying the status of the CCS
// Target = centaur.mba
//-----------------------------------------
fapi::ReturnCode mss_ccs_status_query( fapi::Target& i_target,
                                       mss_ccs_status_query_result& io_status);


//-----------------------------------------
// mss_ccs_start_stop
// Issuing a start or stop of the CCS
// Target = centaur.mba
//-----------------------------------------
fapi::ReturnCode mss_ccs_start_stop( fapi::Target& i_target,
                                     uint32_t i_start_stop);

//----------------------------------------------
// mss_ccs_mode
// Adding info the the Mode Register of the CCS
// Target = centaur.mba
//----------------------------------------------
fapi::ReturnCode mss_ccs_mode( fapi::Target& i_target,
                               ecmdDataBufferBase i_stop_on_err,
                               ecmdDataBufferBase i_ue_disable,
                               ecmdDataBufferBase i_data_sel,
                               ecmdDataBufferBase i_pclk,
                               ecmdDataBufferBase i_nclk,
                               ecmdDataBufferBase i_cal_time_cnt,
                               ecmdDataBufferBase i_resetn,
                               ecmdDataBufferBase i_reset_recover,
                               ecmdDataBufferBase i_copy_spare_cke);

//-----------------------------------------
// mss_ccs_fail_type
// Extracting the type of ccs fail
// Target = centaur.mba
//-----------------------------------------
fapi::ReturnCode mss_ccs_fail_type( fapi::Target& i_target);


//-----------------------------------
// mss_execute_ccs_inst_array
// Execute the CCS intruction array
// Target = centaur.mba
//-----------------------------------
fapi::ReturnCode mss_execute_ccs_inst_array( fapi::Target& i_target,
                                             uint32_t i_num_poll,
                                             uint32_t i_wait_timer);

//-------------------------------------------
// mss_ccs_set_end_bit
// Setting the End location of the CCS array
// Target = centaur.mba
//-------------------------------------------
fapi::ReturnCode mss_ccs_set_end_bit( fapi::Target& i_target,
                                      uint32_t i_instruction_number);

//--------------------------------------------------------
// mss_rcd_parity_check
// Checking the Parity Error Bits associated with the RCD
// Target = centaur.mba
//--------------------------------------------------------
fapi::ReturnCode mss_rcd_parity_check(fapi::Target& i_target,
                                      uint32_t i_port);

//-----------------------------------------
// mss_reverse_32bits, mss_reverse_8bits
// Reversing bit order of 8 or 32 bit uint
//-----------------------------------------
uint32_t mss_reverse_32bits( uint32_t i_x);
uint8_t mss_reverse_8bits(uint8_t i_number);


//-----------------------------------------
// mss_execute_zq_cal
// execute init ZQ Cal on given target and port
// Target = centaur.mba
//-----------------------------------------
fapi::ReturnCode mss_execute_zq_cal(fapi::Target& i_target, 
                                    uint8_t i_port);


//-----------------------------------------
// mss_address_mirror_swizzle
// swizzle the address bus and bank address bus for address mirror mode
// Target = centaur.mba
//-----------------------------------------
fapi::ReturnCode mss_address_mirror_swizzle(fapi::Target& i_target,
            				    uint32_t i_port,
	    				    uint32_t i_dimm,
	    				    uint32_t i_rank,
            				    ecmdDataBufferBase& io_address,
            				    ecmdDataBufferBase& io_bank);

#endif /* _MSS_FUNCS_H */

