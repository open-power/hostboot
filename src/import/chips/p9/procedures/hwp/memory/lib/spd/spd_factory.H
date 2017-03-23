/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/spd/spd_factory.H $ */
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
/// @file spd_factory.H
/// @brief SPD factory and functions
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SPD_FACTORY_H_
#define _MSS_SPD_FACTORY_H_

// std lib
#include <cstdint>
#include <map>
#include <memory>

// fapi2
#include <fapi2.H>

// mss lib
#include <generic/memory/lib/spd/common/ddr4/spd_decoder_ddr4.H>

namespace mss
{
namespace spd
{

///
/// @brief       Decodes SPD Revision encoding level
/// @param[in]   i_target dimm target
/// @param[in]   i_spd_data SPD data
/// @param[out]  o_value encoding revision num
/// @return      FAPI2_RC_SUCCESS if okay
/// @note        Decodes SPD Byte 1 (3~0).
/// @note        Item JC-45-2220.01x
/// @note        Page 14-15
/// @note        DDR4 SPD Document Release 3
///
fapi2::ReturnCode rev_encoding_level(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const std::vector<uint8_t>& i_spd_data,
                                     uint8_t& o_value);
///
/// @brief       Decodes SPD Revision additions level
/// @param[in]   i_target dimm target
/// @param[in]   i_spd_data SPD blob
/// @param[out]  o_value additions revision num
/// @return      FAPI2_RC_SUCCESS if okay
/// @note        Decodes SPD Byte 1 (bits 7~4).
/// @note        Item JC-45-2220.01x
/// @note        Page 14-15
/// @note        DDR4 SPD Document Release 3
///
fapi2::ReturnCode rev_additions_level(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      const std::vector<uint8_t>& i_spd_data,
                                      uint8_t& o_value);

///
/// @brief      Decodes base module type (DIMM type) from SPD
/// @param[in]  i_target dimm target
/// @param[in]  i_spd_data SPD data
/// @param[out] o_value base module type
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       Decodes SPD Byte 3 (bits 3~0)
/// @note       Item JC-45-2220.01x
/// @note       Page 17
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode base_module_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const std::vector<uint8_t>& i_spd_data,
                                   uint8_t& o_value);
///
/// @brief       Decodes DRAM Device Type
/// @param[in]   i_target dimm target
/// @param[out]  o_value dram device type enumeration
/// @return      FAPI2_RC_SUCCESS if okay
/// @note        Decodes SPD Byte 2
/// @note        Item JC-45-2220.01x
/// @note        Page 16
/// @note        DDR4 SPD Document Release 3
///
fapi2::ReturnCode dram_device_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const std::vector<uint8_t>& i_spd_data,
                                   uint8_t& o_value);

///
/// @brief Decodes reference raw card
/// @param[in] i_target dimm target
/// @param[in] i_spd_data SPD data
/// @param[out] o_output encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 130 (Bits 7~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @Note Page 4.1.2.12 - 49
///
fapi2::ReturnCode reference_raw_card(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const std::vector<uint8_t>& i_spd_data,
                                     uint8_t& o_output);

///
/// @brief Retrieve current raw card settings
/// based on dimm type and raw card reference rev
/// @param[in] i_target dimm target
/// @param[in] i_spd_data SPD data
/// @param[out] o_raw_card raw card settings
/// @return FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode raw_card_factory(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const std::vector<uint8_t>& i_spd_data,
                                   rcw_settings& o_raw_card);

///
/// @brief       Object factory to select correct decoder
/// @param[in]   i_target dimm target
/// @param[in]   i_spd_data SPD data
/// @param[out]  o_fact_obj shared pointer to the factory object
/// @return      FAPI2_RC_SUCCESS if okay
/// @note        Factory dependent on SPD revision & dimm type
///
fapi2::ReturnCode factory(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                          const std::vector<uint8_t>& i_spd_data,
                          std::shared_ptr<decoder>& o_fact_obj);

///
/// @brief       Creates factory object & SPD data caches
/// @param[in]   i_target the fapi2 target
/// @param[out]  o_factory_caches vector of factory objects
/// @param[in]   i_pDecoder optional input decoder to insert custom decoder (nullptr default)
/// @return      FAPI2_RC_SUCCESS if okay
///
template<fapi2::TargetType T>
fapi2::ReturnCode populate_decoder_caches(const fapi2::Target<T>& i_target,
        std::vector< std::shared_ptr<decoder> >& o_factory_caches,
        const std::shared_ptr<decoder>& i_pDecoder = nullptr);


}// spd
}// mss

#endif //_MSS_SPD_FACTORY_H_
