/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/ody_phy_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
/// @file ody_phy_utils.H
/// @brief Odyssey PHY utility functions
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _ODY_PHY_UTILS_H_
#define _ODY_PHY_UTILS_H_

#include <fapi2.H>

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>


namespace mss
{
namespace ody
{
namespace phy
{

///
/// @brief Configure the PHY to allow/disallow register accesses via scom
/// @param[in] i_target the target on which to operate
/// @param[in] i_state the state to set the PHY to - either mss::states::ON_N (scom access) or mss::states::OFF_N (training access)
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_phy_scom_access(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const mss::states i_state);

///
/// @brief Converts from a Synopsys register address to an IBM register address
/// @param[in] i_synopsys_addr the Synopsys register address to convert
/// @return The IBM register address converted from
///
uint64_t convert_synopsys_to_ibm_reg_addr( const uint64_t i_synopsys_addr);

///
/// @brief Loads two contiguous 8-bit fields into the DMEM register format
/// @param[in] i_even_field field at the even byte offset
/// @param[in] i_odd_field field at the odd byte offset
/// @param[in,out] io_data the register data
///
void load_dmem_8bit_fields( const uint8_t i_even_field, const uint8_t i_odd_field, fapi2::buffer<uint64_t>& io_data);

///
/// @brief Reads two contiguous 8-bit fields from the DMEM
/// @param[in] i_target the target on which to operate
/// @param[in] i_addr the starting address to read from
/// @param[out] o_even_field field at the even byte offset
/// @param[out] o_odd_field field at the odd byte offset
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode read_dmem_field( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, const uint64_t i_addr,
                                   uint8_t& o_even_field, uint8_t& o_odd_field);

///
/// @brief Reads two contiguous 8-bit fields from the DMEM
/// @param[in] i_target the target on which to operate
/// @param[in] i_addr the starting address to read from
/// @param[out] o_field the 16-bit field
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode read_dmem_field( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, const uint64_t i_addr,
                                   uint16_t& o_field);

///
/// @brief Reads two contiguous 8-bit fields from the DMEM
/// @param[in] i_target the target on which to operate
/// @param[in] i_addr the starting address to read from
/// @param[out] o_field the 32-bit field, read in from two registers
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode read_dmem_field( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, const uint64_t i_addr,
                                   uint32_t& o_field);

///
/// @brief Reads two contiguous 8-bit fields from the DMEM
/// @param[in] i_target the target on which to operate
/// @param[in] i_addr the starting address to read from
/// @param[out] o_field the 64-bit field, read in from four registers
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode read_dmem_field( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, const uint64_t i_addr,
                                   uint64_t& o_field);

///
/// @brief A helper to check if loads to two IMEM/DMEM fields are needed
/// @param[in] i_attr the attribute value dictating if this is the first load or not
/// @param[in] i_data_even even address data
/// @param[in] i_data_odd odd address data
/// @return true if the data should be loaded, otherwise false
/// @note the IMEM/DMEM should be guaranteed to be initialized to zeroes
/// As such, we can gain performance benefits by only loading non-zero data on the first load
/// the data for these addresses will be loaded if:
/// 1. this is not the first time the IMEM/DMEM have been loaded this boot
/// 2. this is the first IMEM/DMEM load and the data for one of the addresses is non-zero
///
bool phy_mem_load_helper( const uint8_t i_attr,
                          const uint64_t i_data_even,
                          const uint64_t i_data_odd);

///
/// @brief A helper to load two IMEM/DMEM fields only if needed
/// @param[in] i_target the target on which to operate
/// @param[in] i_attr the attribute value dictating if this is the first load or not
/// @param[in] i_addr the starting address to write to - must be the even address
/// @param[in] i_data_even even address data
/// @param[in] i_data_odd odd address data
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note the IMEM/DMEM should be guaranteed to be initialized to zeroes
/// As such, we can gain performance benefits by only loading non-zero data on the first load
/// the data for these addresses will be loaded if:
/// 1. this is not the first time the IMEM/DMEM have been loaded this boot
/// 2. this is the first IMEM/DMEM load and the data for one of the addresses is non-zero
///
fapi2::ReturnCode phy_mem_load_helper( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                       const uint8_t i_attr,
                                       const uint64_t i_addr,
                                       const uint64_t i_data_even,
                                       const uint64_t i_data_odd);

///
/// @brief Resets the DMEM values to all 0's
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode reset_dmem( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

} // namespace phy
} // namespace ody
} // namespace mss
#endif
