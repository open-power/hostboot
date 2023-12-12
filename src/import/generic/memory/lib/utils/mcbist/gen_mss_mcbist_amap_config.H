/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mcbist/gen_mss_mcbist_amap_config.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
// EKB-Mirror-To: hostboot

///
/// @file gen_mss_amap_config.H
/// @brief Run and manage the MCBIST engine
///
// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _GEN_MSS_MCBIST_AMAP_CONFIG_H_
#define _GEN_MSS_MCBIST_AMAP_CONFIG_H_

#ifndef __PPE__

#include <fapi2.H>

#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>

// TODO:MST-ZEN2572 Create a constant for DIMM per port for attributes and update code

namespace mss
{
namespace mcbist
{
///
/// @brief Configure the ports
/// @tparam MC the memory controller type
/// @param[in,out] io_current_bit_index bit index that is updated
/// @param[in,out] io_program mcbist program
/// @return none
/// @note The caller is responsible for determining when this should be called
///      depending on how many ports are there
///
template< mss::mc_type MC>
void configure_port(uint64_t& io_current_bit_index,
                    mcbist::program<MC>& io_program)
{
    // There are 2 ports for odyssey
    io_program.change_roq_bit(io_current_bit_index--);
    FAPI_DBG("After configure_port() the current bit index: %d", io_current_bit_index);
}

///
/// @brief Configure the banks
/// @tparam MC the mc type
/// @tparam T the fapi2::TargetType
/// @param[in] i_target port target
/// @param[in,out] io_current_bit_index bit index that is updated
/// @param[in,out] io_program mcbist program
/// @return FAPI2_RC_SUCCESS iff everything ok
///
template< mss::mc_type MC, fapi2::TargetType T >
fapi2::ReturnCode  configure_bank(const fapi2::Target<T>& i_target,
                                  uint64_t& io_current_bit_index,
                                  mcbist::program<MC>& io_program)
{
    uint8_t l_attr_bank[2] = {};

    // There are 2 bank address: BA0, BA1, BA2
    FAPI_TRY(mss::attr::get_dram_bank_bits(i_target, l_attr_bank));
    FAPI_DBG(TARGTIDFORMAT "l_attr_bank: %d", TARGTID, l_attr_bank[0]);
    io_program.change_bank2_bit(l_attr_bank[0] > 2 ? io_current_bit_index-- : 0);
    io_program.change_bank1_bit(l_attr_bank[0] > 1 ? io_current_bit_index-- : 0);
    io_program.change_bank0_bit(l_attr_bank[0] > 0 ? io_current_bit_index-- : 0);
    FAPI_DBG(TARGTIDFORMAT "After configure_bank() the current bit index: %d", TARGTID, io_current_bit_index);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Configure the mranks
/// @tparam MC the mc type
/// @tparam T the fapi2::TargetType
/// @param[in] i_target port target
/// @param[in,out] io_current_bit_index bit index that is updated
/// @param[in,out] io_program mcbist program
/// @return FAPI2_RC_SUCCESS iff everything ok
///
// TODO: Zen:MST-2564: Specialize address map configuration for Explorer
template< mss::mc_type MC, fapi2::TargetType T >
fapi2::ReturnCode configure_mranks(const fapi2::Target<T>& i_target,
                                   uint64_t& io_current_bit_index,
                                   mcbist::program<MC>& io_program);


///
/// @brief Configure the bank groups to handle special cases based on MC type
/// @tparam MC the mc type
/// @tparam T the fapi2::TargetType
/// @param[in] i_target port target
/// @param[in,out] io_current_bit_index bit index that is updated
/// @param[in,out] io_program mcbist program
/// @return FAPI2_RC_SUCCESS iff everything ok
///
template< mss::mc_type MC, fapi2::TargetType T>
fapi2::ReturnCode configure_bank_groups(const fapi2::Target<T>& i_target,
                                        uint64_t& io_current_bit_index,
                                        mcbist::program<MC>& io_program)
{
    uint8_t l_attr_bg_bits[2] = {};
    // Get the attr for bank groups ATTR_MEM_EFF_DRAM_BANK_GROUP_BITS
    // There are 3 bank groups: BG0, BG1, BG2
    FAPI_TRY(mss::attr::get_dram_bank_group_bits(i_target, l_attr_bg_bits));
    FAPI_DBG(TARGTIDFORMAT "l_attr_bg_bits: %d", TARGTID, l_attr_bg_bits[0]);
    io_program.change_bank_group2_bit(l_attr_bg_bits[0] > 2 ? io_current_bit_index-- : 0);
    io_program.change_bank_group1_bit(l_attr_bg_bits[0] > 1 ? io_current_bit_index-- : 0);
    io_program.change_bank_group0_bit(l_attr_bg_bits[0] > 0 ? io_current_bit_index-- : 0);
    FAPI_DBG(TARGTIDFORMAT "After configure_bank_groups() the current bit index: %d", TARGTID, io_current_bit_index);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configure the columns helper to handle special cases based on MC type
/// @tparam MC the mc type
/// @tparam T the fapi2::TargetType
/// @param[in] i_target port target
/// @param[in] i_attr_col_bits attr value of the dram col bits
/// @param[in,out] io_current_bit_index bit index that is updated
/// @param[in,out] io_program mcbist program
/// @note Odyssey never uses col2,
///       For col 3 in odyssey set if burst chop 8 mode is selected for BC8_OTF
///       Explorer uses col3
///       For col2 in explorer set if burst chop 8 mode is selected for BC8_OTF
/// @return FAPI2_RC_SUCCESS iff everything ok
///
// TODO: Zen:MST-2564: Specialize address map configuration for Explorer
template< mss::mc_type MC, fapi2::TargetType T>
fapi2::ReturnCode configure_col_helper(const fapi2::Target<T>& i_target,
                                       const uint8_t i_attr_col_bits,
                                       uint64_t& io_current_bit_index,
                                       mcbist::program<MC>& io_program);


///
/// @brief Configure the columns
/// @tparam MC the mc type
/// @tparam T the fapi2::TargetType
/// @param[in] i_target port target
/// @param[in,out] io_current_bit_index bit index that is updated
/// @param[in,out] io_program mcbist program
/// @return FAPI2_RC_SUCCESS iff everything ok
///
template< mss::mc_type MC, fapi2::TargetType T>
fapi2::ReturnCode configure_col(const fapi2::Target<T>& i_target,
                                uint64_t& io_current_bit_index,
                                mcbist::program<MC>& io_program)
{
    uint8_t l_attr_col_bits[2] = {};
    FAPI_TRY(mss::attr::get_dram_column_bits(i_target, l_attr_col_bits));
    FAPI_DBG(TARGTIDFORMAT "l_attr_col_bits[0]: %d", TARGTID, l_attr_col_bits[0]);
    io_program.change_col10_bit(l_attr_col_bits[0] > 10 ? io_current_bit_index-- : 0);
    io_program.change_col9_bit(l_attr_col_bits[0]  >  9 ? io_current_bit_index-- : 0);
    io_program.change_col8_bit(l_attr_col_bits[0]  >  8 ? io_current_bit_index-- : 0);
    io_program.change_col7_bit(l_attr_col_bits[0]  >  7 ? io_current_bit_index-- : 0);
    io_program.change_col6_bit(l_attr_col_bits[0]  >  6 ? io_current_bit_index-- : 0);
    io_program.change_col5_bit(l_attr_col_bits[0]  >  5 ? io_current_bit_index-- : 0);
    io_program.change_col4_bit(l_attr_col_bits[0]  >  4 ? io_current_bit_index-- : 0);
    // Call the helper function to handle special cases
    FAPI_TRY(configure_col_helper<MC>(i_target, l_attr_col_bits[0], io_current_bit_index, io_program));
    FAPI_DBG(TARGTIDFORMAT "After configure_col() the current bit index: %d", TARGTID, io_current_bit_index);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configure the rows
/// @tparam MC the mc type
/// @tparam T the fapi2::TargetType
/// @param[in] i_target port target
/// @param[in,out] io_current_bit_index bit index that is updated
/// @param[in,out] io_program mcbist program
/// @return FAPI2_RC_SUCCESS iff everything ok
///
template< mss::mc_type MC, fapi2::TargetType T>
fapi2::ReturnCode configure_row(const fapi2::Target<T>& i_target,
                                uint64_t& io_current_bit_index,
                                mcbist::program<MC>& io_program)
{
    // There are 18 rows
    uint8_t l_attr_row_bits[2] = {};
    FAPI_TRY( mss::attr::get_dram_row_bits(i_target, l_attr_row_bits) );
    FAPI_DBG(TARGTIDFORMAT "l_attr_row_bits[0]: %d", TARGTID, l_attr_row_bits[0]);
    io_program.change_row17_bit(l_attr_row_bits[0] > 17 ? io_current_bit_index-- : 0);
    io_program.change_row16_bit(l_attr_row_bits[0] > 16 ? io_current_bit_index-- : 0);
    io_program.change_row15_bit(l_attr_row_bits[0] > 15 ? io_current_bit_index-- : 0);
    io_program.change_row14_bit(l_attr_row_bits[0] > 14 ? io_current_bit_index-- : 0);
    io_program.change_row13_bit(l_attr_row_bits[0] > 13 ? io_current_bit_index-- : 0);
    io_program.change_row12_bit(l_attr_row_bits[0] > 12 ? io_current_bit_index-- : 0);
    io_program.change_row11_bit(l_attr_row_bits[0] > 11 ? io_current_bit_index-- : 0);
    io_program.change_row10_bit(l_attr_row_bits[0] > 10 ? io_current_bit_index-- : 0);
    io_program.change_row9_bit(l_attr_row_bits[0]  >  9 ? io_current_bit_index-- : 0);
    io_program.change_row8_bit(l_attr_row_bits[0]  >  8 ? io_current_bit_index-- : 0);
    io_program.change_row7_bit(l_attr_row_bits[0]  >  7 ? io_current_bit_index-- : 0);
    io_program.change_row6_bit(l_attr_row_bits[0]  >  6 ? io_current_bit_index-- : 0);
    io_program.change_row5_bit(l_attr_row_bits[0]  >  5 ? io_current_bit_index-- : 0);
    io_program.change_row4_bit(l_attr_row_bits[0]  >  4 ? io_current_bit_index-- : 0);
    io_program.change_row3_bit(l_attr_row_bits[0]  >  3 ? io_current_bit_index-- : 0);
    io_program.change_row2_bit(l_attr_row_bits[0]  >  2 ? io_current_bit_index-- : 0);
    io_program.change_row1_bit(l_attr_row_bits[0]  >  1 ? io_current_bit_index-- : 0);
    io_program.change_row0_bit(l_attr_row_bits[0]  >  0 ? io_current_bit_index-- : 0);
    FAPI_DBG(TARGTIDFORMAT "After configure_row() the current bit index: %d", TARGTID, io_current_bit_index);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configure the sranks
/// @tparam MC the mc type
/// @tparam T the fapi2::TargetType
/// @param[in] i_target port target
/// @param[in,out] io_current_bit_index bit index that is updated
/// @param[in,out] io_program mcbist program
/// @return FAPI2_RC_SUCCESS iff everything ok
///
template< mss::mc_type MC, fapi2::TargetType T>
fapi2::ReturnCode configure_srank(const fapi2::Target<T>& i_port_target,
                                  uint64_t& io_current_bit_index,
                                  mcbist::program<MC>& io_program)
{
    // There are 3 SRANKS: SRANK0, SRANK1, SRANK1
    uint8_t l_attr_num_mranks[2] = {};
    uint8_t l_attr_num_lranks[2] = {};
    uint8_t l_num_mranks = 0;
    uint8_t l_num_sranks = 0;

    FAPI_TRY(mss::attr::get_num_master_ranks_per_dimm(i_port_target, l_attr_num_mranks));
    FAPI_TRY(mss::attr::get_logical_ranks_per_dimm(i_port_target, l_attr_num_lranks));

    l_num_mranks = (l_attr_num_mranks[0] == 0) ? 1 : l_attr_num_mranks[0];
    l_num_sranks = l_attr_num_lranks[0] / l_num_mranks;

    FAPI_DBG(TARGTIDFORMAT "l_num_sranks: %d", GENTARGTID(i_port_target), l_num_sranks);

    //calculate the l_num_sranks by  divinding logical_ranks/master_ranks
    io_program.change_srank2_bit(l_num_sranks >= 2 ? io_current_bit_index-- : 0);
    io_program.change_srank1_bit(l_num_sranks >= 4 ? io_current_bit_index-- : 0);
    io_program.change_srank0_bit(l_num_sranks >= 8 ? io_current_bit_index-- : 0);
    FAPI_DBG(TARGTIDFORMAT "After configure_srank() the current bit index: %d", GENTARGTID(i_port_target),
             io_current_bit_index);

fapi_try_exit:
    return fapi2::current_err;
}

} // ns mcbist
} // ns mss

#endif

#endif
