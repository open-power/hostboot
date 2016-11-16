/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_access_delay_reg.H $ */
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
/// @file p9c_mss_access_delay_reg.H
/// @brief Header file for p9c_mss_access_delay_reg
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Steve Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
////




#ifndef MSS_ACCESS_DELAY_REG_H_
#define MSS_ACCESS_DELAY_REG_H_

//------------------------------------------------------------------------------
// My Includes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>


//----------------------------------------------------------------------
// ENUMs
//----------------------------------------------------------------------
enum access_type_t
{
    READ = 0,
    WRITE = 1
};

enum input_type_t
{
    WR_DQ,
    RAW_CDIMM_WR_DQ,
    RAW_WR_DQ_0,
    RAW_WR_DQ_1,
    RAW_WR_DQ_2,
    RAW_WR_DQ_3,
    RAW_WR_DQ_4,
    RD_DQ,
    RAW_CDIMM_RD_DQ,
    RAW_RD_DQ_0,
    RAW_RD_DQ_1,
    RAW_RD_DQ_2,
    RAW_RD_DQ_3,
    RAW_RD_DQ_4,
    WR_DQS,
    RAW_CDIMM_WR_DQS,
    RAW_WR_DQS_0,
    RAW_WR_DQS_1,
    RAW_WR_DQS_2,
    RAW_WR_DQS_3,
    RAW_WR_DQS_4,
    RD_DQS,
    RAW_CDIMM_RD_DQS,
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
    RAW_CDIMM_DQS_GATE,
    RAW_DQS_GATE_0,
    RAW_DQS_GATE_1,
    RAW_DQS_GATE_2,
    RAW_DQS_GATE_3,
    RAW_DQS_GATE_4,
    DQS_ALIGN,
    RAW_CDIMM_DQS_ALIGN,
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
    DQSCLK,
    RAW_CDIMM_DQSCLK,
    RAW_DQSCLK_0,
    RAW_DQSCLK_1,
    RAW_DQSCLK_2,
    RAW_DQSCLK_3,
    RAW_DQSCLK_4,
    COMMAND,
    CONTROL,
    CLOCK,
    ADDRESS,
    DATA_DISABLE
};

enum ip_type_t
{
    WR_DQ_t,
    RAW_WR_DQ,
    RAW_CDIMM_WR_DQ_t,
    RD_DQ_t,
    RAW_RD_DQ,
    RAW_CDIMM_RD_DQ_t,
    WR_DQS_t,
    RAW_WR_DQS,
    RAW_CDIMM_WR_DQS_t,
    RD_DQS_t,
    RAW_RD_DQS,
    RAW_CDIMM_RD_DQS_t,
    RD_CLK_t,
    RAW_SYS_ADDR_CLKS0S1,
    RAW_SYS_CLK,
    RAW_WR_CLK,
    RAW_ADDR,
    DQS_GATE_t,
    RAW_DQS_GATE,
    RAW_CDIMM_DQS_GATE_t,
    DQS_ALIGN_t,
    RAW_DQS_ALIGN,
    RAW_CDIMM_DQS_ALIGN_t,
    RDCLK_t,
    RAW_RDCLK,
    DQSCLK_t,
    RAW_DQSCLK,
    RAW_CDIMM_DQSCLK_t,
    COMMAND_t,
    CONTROL_t,
    CLOCK_t,
    ADDRESS_t,
    DATA_DISABLE_t
};


enum input_type
{
    ISDIMM_DQ,
    ISDIMM_DQS,
    CDIMM_DQS,
    CDIMM_DQ,
    GL_NET_DQ,
    GL_NET_DQS
};

struct scom_location
{
    uint64_t scom_addr;
    uint8_t start_bit;
    uint8_t bit_length;
};


typedef fapi2::ReturnCode (*p9c_mss_access_delay_reg_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_MBA>&,
        access_type_t,
        uint8_t,
        uint8_t,
        input_type_t,
        uint8_t,
        uint8_t,
        uint32_t&);

extern "C" {

    /// @brief Reads or Writes delay values
    /// @param[in] i_target_mba     Reference to centaur.mba target
    /// @param[in] i_access_type_e  Access type (READ or WRITE)
    /// @param[in] i_port_u8        Port number
    /// @param[in] i_rank_u8        Rank number
    /// @param[in] i_input_type_e   Input type (from input_type_t)
    /// @param[in] i_input_index_u8 Input index
    /// @param[in] i_verbose        1 = Verbose tracing
    /// @param[io] io_value_u32     READ=input, WRITE=output
    /// @return ReturnCode
    fapi2::ReturnCode mss_access_delay_reg_schmoo(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
            const access_type_t i_access_type_e,
            const uint8_t i_port_u8,
            const uint8_t i_rank_u8,
            const input_type_t i_input_type_e,
            const uint8_t i_input_index_u8,
            const bool i_verbose,
            uint16_t& io_value_u32);

    /// @brief Reads or Writes delay values
    /// @param[in] i_target_mba     Reference to centaur.mba target
    /// @param[in] i_access_type_e  Access type (READ or WRITE)
    /// @param[in] i_port_u8        Port number
    /// @param[in] i_rank_u8        Rank number
    /// @param[in] i_input_type_e   Input type (from input_type_t)
    /// @param[in] i_input_index_u8 Input index
    /// @param[in] i_verbose        1 = Verbose tracing
    /// @param[io] io_value_u32     READ=input, WRITE=output
    /// @return ReturnCode
    fapi2::ReturnCode mss_access_delay_reg(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                           const access_type_t i_access_type_e,
                                           const uint8_t i_port_u8,
                                           const uint8_t i_rank_u8,
                                           const input_type_t i_input_type_e,
                                           const uint8_t i_input_index_u8,
                                           const bool i_verbose,
                                           uint32_t& io_value_u32);

    /// @brief cross_coupled
    /// @param[in]  i_target_mba   Reference to centaur.mba target
    /// @param[in]  i_port         Port number
    /// @param[in]  i_rank_pair    Rank pair
    /// @param[in]  i_input_type_e Input type (from input_type_t)
    /// @param[in]  i_input_index  Input index
    /// @param[in]  i_verbose      1 = Verbose tracing
    /// @param[out] out            Output
    /// @return ReturnCode
    fapi2::ReturnCode cross_coupled(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                    const uint8_t i_port,
                                    const uint8_t i_rank_pair,
                                    const input_type_t i_input_type_e,
                                    const uint8_t i_input_index,
                                    const bool i_verbose,
                                    scom_location& out);

    /// @brief mss_c4_phy
    /// @param[in] i_target_mba   Reference to centaur.mba target
    /// @param[in] i_port         Port number
    /// @param[in] i_rank_pair    Rank pair
    /// @param[in] i_input_type_e Input type (from input_type_t)
    /// @param[in,out] io_input_index  Input index
    /// @param[in] i_verbose      1 = Verbose tracing
    /// @param[in,out] phy_lane       PHY Lane
    /// @param[in,out] phy_block      PHY Block
    /// @param[in] flag           Flag
    /// @return ReturnCode
    fapi2::ReturnCode mss_c4_phy(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                 const uint8_t i_port,
                                 const uint8_t i_rank_pair,
                                 const input_type_t i_input_type_e,
                                 uint8_t& io_input_index,
                                 const bool i_verbose,
                                 uint8_t& phy_lane,
                                 uint8_t& phy_block,
                                 const uint8_t flag);

    /// @brief get_address
    /// @param[in]  i_target_mba      Reference to centaur.mba target
    /// @param[in]  i_port            Port number
    /// @param[in]  i_rank_pair       Rank pair
    /// @param[in]  i_input_type_e    Input type (from input_type_t)
    /// @param[in]  i_block           Block
    /// @param[in]  i_lane            Lane
    /// @param[out] o_scom_address_64 Output scom address
    /// @param[out] o_start_bit       Output Start bit
    /// @param[out] o_len             Output length
    /// @return ReturnCode
    fapi2::ReturnCode get_address(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                  const uint8_t i_port,
                                  const uint8_t i_rank_pair,
                                  const ip_type_t i_input_type_e,
                                  const uint8_t i_block,
                                  uint8_t i_lane,
                                  uint64_t& o_scom_address_64,
                                  uint8_t& o_start_bit,
                                  uint8_t& o_len);

    /// @brief Returns C4 bit for the corresponding ISDIMM bit
    /// @param[in]  i_target_mba   Reference to centaur.mba target
    /// @param[in]  i_port         Port number
    /// @param[in]  i_input_type_e Input type (from input_type_t)
    /// @param[in]  i_input_index  Input index
    /// @param[in]  i_verbose      1 = Verbose tracing
    /// @param[out] o_value        Output C4 bit
    /// @return ReturnCode
    fapi2::ReturnCode rosetta_map(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                  const uint8_t i_port,
                                  const input_type i_input_type_e,
                                  uint8_t i_input_index,
                                  const bool i_verbose,
                                  uint8_t& o_value);

    /// @brief Gets the rank pair
    /// @param[in]  i_target_mba     Reference to centaur.mba target
    /// @param[in]  i_port           Port
    /// @param[in]  i_rank           Rank
    /// @param[out] o_rank_pair      Output rank pair
    /// @param[out] o_rankpair_table Output rank pair table
    /// @return ReturnCode
    fapi2::ReturnCode mss_getrankpair(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                      const uint8_t i_port,
                                      const uint8_t i_rank,
                                      uint8_t* o_rank_pair,
                                      uint8_t o_rankpair_table[]);
    /// @brief Return a port number from MBA and port positions
    /// @param[in] i_mbaPos MBA Position  (0 or 1)
    /// @param[in] i_port   Port Position (0 or 1)
    /// @return Port number (0-3)
    inline uint8_t get_port(const uint8_t i_mbaPos, const uint8_t i_port)
    {
        return (i_mbaPos * 2) + i_port;
    }
} // extern "C"

#endif // MSS_ACCESS_DELAY_REG_H

