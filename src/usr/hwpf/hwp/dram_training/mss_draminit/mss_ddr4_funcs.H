/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit/mss_ddr4_funcs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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
// $Id: mss_ddr4_funcs.H,v 1.6 2015/11/09 17:22:00 sglancy Exp $

//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2013
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE : mss_ddr4_funcs.H
// *! DESCRIPTION : Tools for DDR4 DIMMs centaur procedures
// *! OWNER NAME : jdsloat@us.ibm.com
// *! BACKUP NAME : sglancy@us.ibm.com
// #! ADDITIONAL COMMENTS :
//

//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//         |          |         |
//  1.5    | 09/04/15 | thi     | Fix Doxygen
//  1.4    | 03/14/14 | kcook   | Added DDR4 Register function support.
//  1.3    | 10/10/13 | bellows | Added required CVS Id comment
//  1.2    | 10/09/13 | jdsloat | Fixed argument list in function call
//  1.1    | 10/04/13 | jdsloat | First revision

#ifndef _MSS_DDR4_FUNCS_H
#define _MSS_DDR4_FUNCS_H


//----------------------------------------------------------------------
// DDR4 FUNCS
//----------------------------------------------------------------------


//--------------------------------------------------------------
// @brief Set MRS1 settings for Rank 0 and Rank 1
//
// @param[in] i_target             Reference to MBA Target.
// @param[in] i_port_number        MBA port number
// @param[in/out] io_ccs_inst_cnt  CCS instruction count
//
// @return ReturnCode
//--------------------------------------------------------------
fapi::ReturnCode mss_mrs_load_ddr4( fapi::Target& i_target,
                                      uint32_t i_port_number,
                                      uint32_t& io_ccs_inst_cnt);

//--------------------------------------------------------------
// @brief Writes MPR pattern for inverted address location for
//        training with DDR4 RDIMMs.
//
// @param[in] i_target_mba          Reference to MBA Target.
//
// @return ReturnCode
//--------------------------------------------------------------
fapi::ReturnCode mss_ddr4_invert_mpr_write( fapi::Target& i_target_mba);

//--------------------------------------------------------------
// @brief Writes RCD control words for DDR4 register.
//
// @param[in] i_target             Reference to MBA Target.
// @param[in] i_port_number        MBA port number
// @param[in/out] io_ccs_inst_cnt  CCS instruction count
//
// @return ReturnCode
//--------------------------------------------------------------
fapi::ReturnCode mss_rcd_load_ddr4(
            fapi::Target& i_target,
            uint32_t i_port_number,
            uint32_t& io_ccs_inst_cnt);

//--------------------------------------------------------------
// @brief Creates RCD_CNTRL_WORD attribute for DDR4 register
//
// @param[in] i_target_mba          Reference to MBA Target.
//
// @return ReturnCode
//--------------------------------------------------------------
fapi::ReturnCode mss_create_rcd_ddr4( const fapi::Target& i_target_mba);

/**
 * @loads in a nominal MRS value into the address_16 and bank_3
 *
 * @param[in]  target:  Reference to centaur.mba target, 
 * @param[out]  ecmdDataBufferBase& bank_3:  bank bits to be issued during MRS
 * @param[out]  ecmdDataBufferBase& address_16:  16 address lanes to be issued during MRS - setup during function
 * @param[in]  uint8_t MRS:  which MRS to configure
 * @param[in]  uint8_t i_port_number: the port on which to configure the MRS - used for ID'ing which attributes to use
 * @param[in]  uint8_t dimm_number: the DIMM on which to configure the MRS - used for ID'ing which attributes to use
 * @param[in]  uint8_t rank_number: the rank on which to configure the MRS - used for ID'ing which attributes to use
 *
 * @return ReturnCode
 */
fapi::ReturnCode mss_ddr4_load_nominal_mrs_pda(fapi::Target& i_target,ecmdDataBufferBase& bank_3,ecmdDataBufferBase& address_16,uint8_t MRS,uint8_t i_port_number, uint8_t dimm_number, uint8_t rank_number);
/**
 * @Modifies the passed in address_16 buffer based upon the given attribute and data
 *
 * @param[in]  target:  Reference to centaur.mba target, 
 * @param[in/out]  ecmdDataBufferBase& address_16:  MRS values - this is modified by the given attribute name and data
 * @param[in]  uint32_t attribute_name:  enumerated value containing the attribute name to be modified - attr_name tells the function which bits to modify
 * @param[in]  uint8_t attribute_data:   data telss the function what values to set to the modified bits
 *
 * @return ReturnCode
 */
fapi::ReturnCode mss_ddr4_modify_mrs_pda(fapi::Target& i_target,ecmdDataBufferBase& address_16,uint32_t attribute_name,uint8_t attribute_data);

fapi::ReturnCode mss_ddr4_rtt_nom_rtt_wr_swap(fapi::Target& i_target, uint8_t i_mbaPosition, uint32_t i_port_number, uint8_t i_rank, uint32_t i_rank_pair_group, uint32_t& io_ccs_inst_cnt, uint8_t& io_dram_rtt_nom_original);
#endif /* _MSS_DDR4_FUNCS_H */


