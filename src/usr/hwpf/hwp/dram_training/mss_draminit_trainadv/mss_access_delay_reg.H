/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_access_delay_reg.H $ */
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
//$Id: mss_access_delay_reg.H,v 1.12 2014/01/24 17:22:16 sasethur Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_demo_access_delay_reg.H
// *! DESCRIPTION : Header file for mss_access_delay_reg.
// *! OWNER NAME  : Saurabh Chadha    Email: sauchadh@in.ibm.com
// *! ADDITIONAL COMMENTS :
//
//
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.12  | mjjones  |20-Jan-14| RAS Review Updates
//   1.1   | sauchadh |15-Oct-12| First Draft.
//------------------------------------------------------------------------------


#ifndef MSS_ACCESS_DELAY_REG_H_
#define MSS_ACCESS_DELAY_REG_H_

//------------------------------------------------------------------------------
// My Includes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>


//----------------------------------------------------------------------
// ENUMs   
//----------------------------------------------------------------------
enum access_type_t {
   READ = 0,
   WRITE = 1
};

enum input_type_t {
   WR_DQ,
   RAW_WR_DQ_0,
   RAW_WR_DQ_1,
   RAW_WR_DQ_2,
   RAW_WR_DQ_3,
   RAW_WR_DQ_4,
   RD_DQ,
   RAW_RD_DQ_0,
   RAW_RD_DQ_1,
   RAW_RD_DQ_2,
   RAW_RD_DQ_3,
   RAW_RD_DQ_4,
   WR_DQS,
   RAW_WR_DQS_0,
   RAW_WR_DQS_1,
   RAW_WR_DQS_2,
   RAW_WR_DQS_3,
   RAW_WR_DQS_4,
   RD_DQS,
   RAW_RD_DQS_0,
   RAW_RD_DQS_1,
   RAW_RD_DQS_2,
   RAW_RD_DQS_3,
   RAW_RD_DQS_4,
   RAW_SYS_ADDR_CLK,
   RAW_SYS_CLK_0,
   RAW_SYS_CLK_1,
   RAW_SYS_CLK_2,
   RAW_SYS_CLK_3,
   RAW_SYS_CLK_4,
   RAW_WR_CLK_0,
   RAW_WR_CLK_1,
   RAW_WR_CLK_2,
   RAW_WR_CLK_3,
   RAW_WR_CLK_4,
   RAW_ADDR_0,
   RAW_ADDR_1,
   RAW_ADDR_2,
   RAW_ADDR_3,
   DQS_GATE,
   RAW_DQS_GATE_0,
   RAW_DQS_GATE_1,
   RAW_DQS_GATE_2,
   RAW_DQS_GATE_3,
   RAW_DQS_GATE_4,
   DQS_ALIGN,
   RAW_DQS_ALIGN_0,
   RAW_DQS_ALIGN_1,
   RAW_DQS_ALIGN_2,
   RAW_DQS_ALIGN_3,
   RAW_DQS_ALIGN_4,
   RAW_RDCLK_0,
   RAW_RDCLK_1,
   RAW_RDCLK_2,
   RAW_RDCLK_3,
   RAW_RDCLK_4,
   RDCLK,
   RAW_DQSCLK_0,
   RAW_DQSCLK_1,
   RAW_DQSCLK_2,
   RAW_DQSCLK_3,
   RAW_DQSCLK_4,
   DQSCLK,
   COMMAND,
   CONTROL,
   CLOCK,
   ADDRESS,
   DATA_DISABLE
   };

enum ip_type_t {
   WR_DQ_t,
   RAW_WR_DQ,
   RD_DQ_t,
   RAW_RD_DQ,
   WR_DQS_t,
   RAW_WR_DQS,
   RD_DQS_t,
   RAW_RD_DQS,
   RD_CLK_t,
   RAW_SYS_ADDR_CLKS0S1,
   RAW_SYS_CLK,
   RAW_WR_CLK,
   RAW_ADDR,
   DQS_GATE_t,
   RAW_DQS_GATE,
   DQS_ALIGN_t,
   RAW_DQS_ALIGN,
   RDCLK_t,
   RAW_RDCLK,
   DQSCLK_t,
   RAW_DQSCLK,
   COMMAND_t,
   CONTROL_t,
   CLOCK_t,
   ADDRESS_t,
   DATA_DISABLE_t
};


enum input_type {
  ISDIMM_DQ,
  ISDIMM_DQS,
  CDIMM_DQS,
  CDIMM_DQ,
  GL_NET_DQ,
  GL_NET_DQS
};

struct scom_location {
   uint64_t scom_addr;
   uint8_t start_bit;
   uint8_t bit_length;
};


typedef fapi::ReturnCode (*mss_access_delay_reg_FP_t)(const fapi::Target &,
                                                      access_type_t,
                                                      uint8_t,
                                                      uint8_t,
                                                      input_type_t,
                                                      uint8_t,
                                                      uint8_t,
                                                      uint32_t &);

extern "C" {

/**
 * @brief Reads or Writes delay values
 *
 * @param[in] i_target_mba     Reference to centaur.mba target
 * @param[in] i_access_type_e  Access type (READ or WRITE)
 * @param[in] i_port_u8        Port number
 * @param[in] i_rank_u8        Rank number
 * @param[in] i_input_type_e   Input type (from input_type_t)
 * @param[in] i_input_index_u8 Input index
 * @param[in] i_verbose        1 = Verbose tracing
 * @param[io] io_value_u32     READ=input, WRITE=output
 *
 * @return ReturnCode
 */
fapi::ReturnCode mss_access_delay_reg_schmoo(const fapi::Target & i_target_mba,
                                             access_type_t i_access_type_e,
                                             uint8_t i_port_u8,
                                             uint8_t i_rank_u8,
                                             input_type_t i_input_type_e,
                                             uint8_t i_input_index_u8,
                                             uint8_t i_verbose,
                                             uint16_t &io_value_u32);

/**
 * @brief Reads or Writes delay values
 *
 * @param[in] i_target_mba     Reference to centaur.mba target
 * @param[in] i_access_type_e  Access type (READ or WRITE)
 * @param[in] i_port_u8        Port number
 * @param[in] i_rank_u8        Rank number
 * @param[in] i_input_type_e   Input type (from input_type_t)
 * @param[in] i_input_index_u8 Input index
 * @param[in] i_verbose        1 = Verbose tracing
 * @param[io] io_value_u32     READ=input, WRITE=output
 *
 * @return ReturnCode
 */
fapi::ReturnCode mss_access_delay_reg(const fapi::Target & i_target_mba,
                                      access_type_t i_access_type_e,
                                      uint8_t i_port_u8,
                                      uint8_t i_rank_u8,
                                      input_type_t i_input_type_e,
                                      uint8_t i_input_index_u8,
                                      uint8_t i_verbose,
                                      uint32_t &io_value_u32);

/**
 * @brief cross_coupled
 *
 * @param[in]  i_target_mba   Reference to centaur.mba target
 * @param[in]  i_port         Port number
 * @param[in]  i_rank_pair    Rank pair
 * @param[in]  i_input_type_e Input type (from input_type_t)
 * @param[in]  i_input_index  Input index
 * @param[in]  i_verbose      1 = Verbose tracing
 * @param[out] out            Output
 *
 * @return ReturnCode
 */
fapi::ReturnCode cross_coupled(const fapi::Target & i_target_mba,
                               uint8_t i_port,
                               uint8_t i_rank_pair,
                               input_type_t i_input_type_e,
                               uint8_t i_input_index,
                               uint8_t i_verbose,
                               scom_location& out);

/**
 * @brief mss_c4_phy
 *
 * @param[in] i_target_mba   Reference to centaur.mba target
 * @param[in] i_port         Port number
 * @param[in] i_rank_pair    Rank pair
 * @param[in] i_input_type_e Input type (from input_type_t)
 * @param[in] i_input_index  Input index
 * @param[in] i_verbose      1 = Verbose tracing
 * @param[io] phy_lane       PHY Lane
 * @param[io] phy_block      PHY Block
 * @param[in] flag           Flag
 *
 * @return ReturnCode
 */
fapi::ReturnCode mss_c4_phy(const fapi::Target & i_target_mba,
                            uint8_t i_port,
                            uint8_t i_rank_pair,
                            input_type_t i_input_type_e,
                            uint8_t &i_input_index,
                            uint8_t i_verbose,
                            uint8_t &phy_lane,
                            uint8_t &phy_block,
                            uint8_t flag);

/**
 * @brief get_address
 *
 * @param[in]  i_target_mba      Reference to centaur.mba target
 * @param[in]  i_port            Port number
 * @param[in]  i_rank_pair       Rank pair
 * @param[in]  i_input_type_e    Input type (from input_type_t)
 * @param[in]  i_block           Block
 * @param[in]  i_lane            Lane
 * @param[out] o_scom_address_64 Output scom address
 * @param[out] o_start_bit       Output Start bit
 * @param[out] o_len             Output length
 *
 * @return ReturnCode
 */
fapi::ReturnCode get_address(const fapi::Target & i_target_mba,
                             uint8_t i_port,
                             uint8_t i_rank_pair,
                             ip_type_t i_input_type_e,
                             uint8_t i_block,
                             uint8_t i_lane,
                             uint64_t &o_scom_address_64,
                             uint8_t &o_start_bit,
                             uint8_t &o_len);

/**
 * @brief Returns C4 bit for the corresponding ISDIMM bit
 *
 * @param[in]  i_target_mba   Reference to centaur.mba target
 * @param[in]  i_port         Port number
 * @param[in]  i_input_type_e Input type (from input_type_t)
 * @param[in]  i_input_index  Input index
 * @param[in]  i_verbose      1 = Verbose tracing
 * @param[out] o_value        Output C4 bit
 *
 * @return ReturnCode
 */
fapi::ReturnCode rosetta_map(const fapi::Target & i_target_mba,
                             uint8_t i_port,
                             input_type i_input_type_e,
                             uint8_t i_input_index,
                             uint8_t i_verbose,
                             uint8_t &o_value);

/**
 * @brief Gets the rank pair
 *
 * @param[in]  i_target_mba     Reference to centaur.mba target
 * @param[in]  i_port           Port
 * @param[in]  i_rank           Rank
 * @param[out] o_rank_pair      Output rank pair
 * @param[out] o_rankpair_table Output rank pair table
 *
 * @return ReturnCode
 */
fapi::ReturnCode mss_getrankpair(const fapi::Target & i_target_mba,
                                 uint8_t i_port,
                                 uint8_t i_rank,
                                 uint8_t *o_rank_pair,
                                 uint8_t o_rankpair_table[]);

} // extern "C"

#endif // MSS_ACCESS_DELAY_REG_H

