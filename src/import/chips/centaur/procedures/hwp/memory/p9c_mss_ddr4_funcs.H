/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_ddr4_funcs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
///
/// @file p9c_mss_ddr4_funcs.H
/// @brief  Tools for DDR4 DIMMs centaur procedures
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Steve Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB CI

#ifndef _MSS_DDR4_FUNCS_H
#define _MSS_DDR4_FUNCS_H


//----------------------------------------------------------------------
// DDR4 FUNCS
//----------------------------------------------------------------------


/// @brief Set MRS1 settings for Rank 0 and Rank 1
/// @param[in] i_target             Reference to MBA Target<fapi2::TARGET_TYPE_MBA>.
/// @param[in] i_port_number        MBA port number
/// @param[in, out] io_ccs_inst_cnt  CCS instruction count
/// @return ReturnCode
fapi2::ReturnCode mss_mrs_load_ddr4( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                     const uint32_t i_port_number,
                                     uint32_t& io_ccs_inst_cnt);

/// @brief Writes MPR pattern for inverted address location for training with DDR4 RDIMMs.
/// @param[in] i_target_mba          Reference to MBA Target<fapi2::TARGET_TYPE_MBA>.
/// @return ReturnCode
fapi2::ReturnCode mss_ddr4_invert_mpr_write( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba);

/// @brief Writes RCD control words for DDR4 register.
/// @param[in] i_target             Reference to MBA Target<fapi2::TARGET_TYPE_MBA>.
/// @param[in] i_port_number        MBA port number
/// @param[in, out] io_ccs_inst_cnt  CCS instruction count
/// @return ReturnCode
fapi2::ReturnCode mss_rcd_load_ddr4(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
    const uint32_t i_port_number,
    uint32_t& io_ccs_inst_cnt);

/// @brief Creates RCD_CNTRL_WORD attribute for DDR4 register
/// @param[in] i_target_mba          Reference to MBA Target<fapi2::TARGET_TYPE_MBA>.
/// @return ReturnCode
fapi2::ReturnCode mss_create_rcd_ddr4( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba);

/// @brief loads in a nominal MRS value into the address_16 and bank_3
/// @param[in]  target:  Reference to centaur.mba target,
/// @param[out]  fapi2::variable_buffer& bank_3:  bank bits to be issued during MRS
/// @param[out]  fapi2::variable_buffer& address_16:  16 address lanes to be issued during MRS - setup during function
/// @param[in]  uint8_t MRS:  which MRS to configure
/// @param[in]  uint8_t i_port_number: the port on which to configure the MRS - used for ID'ing which attributes to use
/// @param[in]  uint8_t dimm_number: the DIMM on which to configure the MRS - used for ID'ing which attributes to use
/// @param[in]  uint8_t rank_number: the rank on which to configure the MRS - used for ID'ing which attributes to use
/// @return ReturnCode
fapi2::ReturnCode mss_ddr4_load_nominal_mrs_pda(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        fapi2::variable_buffer& bank_3, fapi2::variable_buffer& address_16, const uint8_t MRS, const uint8_t i_port_number,
        const uint8_t dimm_number, const uint8_t rank_number);

/// @brief Modifies the passed in address_16 buffer based upon the given attribute and data
/// @param[in]  target:  Reference to centaur.mba target,
/// @param[in,out]  fapi2::variable_buffer& address_16:  MRS values - this is modified by the given attribute name and data
/// @param[in]  uint32_t attribute_name:  enumerated value containing the attribute name to be modified - attr_name tells the function which bits to modify
/// @param[in]  uint8_t attribute_data:   data telss the function what values to set to the modified bits
/// @return ReturnCode
fapi2::ReturnCode mss_ddr4_modify_mrs_pda(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        fapi2::variable_buffer& address_16, const uint32_t attribute_name, const uint8_t attribute_data);

/// @brief Swaps RTT_NOM and RTT_WR
/// @param[in]  target:  Reference to centaur.mba target,
/// @param[in]  MBA Position
/// @param[in]  Port Number
/// @param[in]  Rank Number
/// @param[in]  Rank Pair group
/// @param[in, out]  CCS instruction Number
/// @param[in, out]  Original RTT NOM
/// @return ReturnCode
fapi2::ReturnCode mss_ddr4_rtt_nom_rtt_wr_swap(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        const uint8_t i_mbaPosition,
        const uint32_t i_port_number, const uint8_t i_rank, const uint32_t i_rank_pair_group, uint32_t& io_ccs_inst_cnt,
        uint8_t& io_dram_rtt_nom_original);
#endif /* _MSS_DDR4_FUNCS_H */


