/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mcbist/exp_mcbist.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file exp_mcbist.H
/// @brief Run and manage the MCBIST engine
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_EXP_MCBIST_H_
#define _MSS_EXP_MCBIST_H_

#include <fapi2.H>

#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>

#include <lib/shared/exp_consts.H>
#include <lib/ecc/ecc_traits_explorer.H>
#include <lib/mcbist/exp_mcbist_traits.H>
#include <lib/mc/exp_port.H>
#include <lib/utils/mss_exp_conversions.H>
#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/memory_size.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_patterns.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_settings.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist.H>

namespace mss
{

namespace mcbist
{

///
/// @brief Get the address of mrank 0 buffer
/// @return Address of mrank 0 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_mrank0_bit();

///
/// @brief Get the address of mrank0 buffer when in 5D mode
/// @return Address of mrank0 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_mrank0_bit_5d();

///
/// @brief Get the address of mrank1 buffer
/// @return Address of mrank1 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_mrank1_bit();

///
/// @brief Get the address of mrank1 buffer when in 5D mode
/// @return Address of mrank1 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_mrank1_bit_5d();

///
/// @brief Get the address of mrank2 buffer when in 5D mode
/// @return Address of mrank2 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_mrank2_bit_5d();

///
/// @brief Get the address of srank0 buffer
/// @return Address of mrank0 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_srank0_bit();

///
/// @brief Get the address of srank1 buffer
/// @return Address of srank1 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_srank1_bit();

///
/// @brief Get the address of srank2 buffer
/// @return Address of srank2 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_srank2_bit();

///
/// @brief Get the address of bank2 buffer
/// @return Address of bank2 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_bank2_bit();

///
/// @brief Get the address of bank1 buffer
/// @return Address of bank1 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_bank1_bit();

///
/// @brief Get the address of bank 0 buffer
/// @return Address of bank 0 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_bank0_bit();

///
/// @brief Get the address of bank group1 buffer
/// @return Address of bank group1 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_bank_group1_bit();

///
/// @brief Get the address of bank group0 buffer
/// @return Address of bank group0 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_bank_group0_bit();

///
/// @brief Get the address of row17 buffer
/// @return Address of row17 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row17_bit();

///
/// @brief Get the address of row16 buffer
/// @return Address of row16 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row16_bit();

///
/// @brief Get the address of row15 buffer
/// @return Address of row15 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row15_bit();

///
/// @brief Get the address of row14 buffer
/// @return Address of row14 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row14_bit();

///
/// @brief Get the address of row13 buffer
/// @return Address of row13 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row13_bit();

///
/// @brief Get the address of row12 buffer
/// @return Address of row12 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row12_bit();

///
/// @brief Get the address of row11 buffer
/// @return Address of row11 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row11_bit();

///
/// @brief Get the address of row10 buffer
/// @return Address of row10 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row10_bit();

///
/// @brief Get the address of row9 buffer
/// @return Address of row9 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row9_bit();

///
/// @brief Get the address of row8 buffer
/// @return Address of row8 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row8_bit();

///
/// @brief Get the address of row7 buffer
/// @return Address of row7 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row7_bit();

///
/// @brief Get the address of row6 buffer
/// @return Address of row6 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row6_bit();

///
/// @brief Get the address of row5 buffer
/// @return Address of row5 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row5_bit();

///
/// @brief Get the address of row4 buffer
/// @return Address of row4 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row4_bit();

///
/// @brief Get the address of row3 buffer
/// @return Address of row3 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row3_bit();

///
/// @brief Get the address of row2 buffer
/// @return Address of row2 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row2_bit();

///
/// @brief Get the address of row1 buffer
/// @return Address of row1 fapi2 buffer
///template <>
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row1_bit();

///
/// @brief Get the address of row0 buffer
/// @return Address of row0 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_row0_bit();

///
/// @brief Get the address of col9 buffer
/// @return Address of col9 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_col9_bit();

///
/// @brief Get the address of col8 buffer
/// @return Address of col8 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_col8_bit();

///
/// @brief Get the address of col7 buffer
/// @return Address of col7 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_col7_bit();

///
/// @brief Get the address of col6 buffer
/// @return Address of col6 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_col6_bit();

///
/// @brief Get the address of col5 buffer
/// @return Address of col5 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_col5_bit();

///
/// @brief Get the address of col4 buffer
/// @return Address of col4 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_col4_bit();

///
/// @brief Get the address of col3 buffer
/// @return Address of col3 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_col3_bit();

///
/// @brief Get the address of col2 buffer
/// @return Address of col2 fapi2 buffer
///
template <>
fapi2::buffer<uint64_t>& program<mss::mc_type::EXPLORER>::get_addr_map_col2_bit();

///
/// @brief Change the BANK2 address mapping
/// @param[in] i_bitmap BANK2 bit map in the address counter
/// @note Assumes data is right-aligned
///
template <>
void program<mss::mc_type::EXPLORER>::change_bank2_bit( const uint64_t i_bitmap );

///
/// @brief Change the DIMM select in the address mapping
/// @param[in] i_bitmap DIMM select bit map in the address counter
/// @note Assumes data is right-aligned
///
template <>
void program<mss::mc_type::EXPLORER>::change_dimm_select_bit( const uint64_t i_bitmap );

///
/// @brief Change the COL10 address mapping
/// @param[in] i_bitmap COL10 bit map in the address counter
/// @note Assumes data is right-aligned
///
template <>
void program<mss::mc_type::EXPLORER>::change_col10_bit( const uint64_t i_bitmap );

/// @brief Change the ROQ address mapping
/// @param[in] i_bitmap ROQ bit map in the address counter
/// @note Assumes data is right-aligned
///
template <>
void program<mss::mc_type::EXPLORER>::change_roq_bit( const uint64_t i_bitmap );

///
/// @brief Change the BANK_GROUP2 address mapping
/// @param[in] i_bitmap BANK_GROUP2 bit map in the address counter
/// @note Assumes data is right-aligned
///
template <>
void program<mss::mc_type::EXPLORER>::change_bank_group2_bit( const uint64_t i_bitmap );

} // ns mss

} // ns mcbist
#endif
