/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/spd/spd_factory.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SPD_FACTORY_H_
#define _MSS_SPD_FACTORY_H_

// std lib
#include <cstdint>
#include <map>
#include <memory>

// fapi2
#include <fapi2.H>
#include <fapi2_spd_access.H>

// mss lib
#include <generic/memory/lib/spd/spd_facade.H>
#include <generic/memory/lib/spd/common/rcw_settings.H>

namespace mss
{
namespace spd
{

///
/// @brief Wrapper function for finding the raw card -- helper for testing
/// @param[in] i_target the dimm target
/// @param[in] i_dimm_type
/// @param[in] i_ref_raw_card_rev for FFDC
/// @param[in] i_mrw_supported_rc
/// @param[in] i_map raw card map
/// @param[out] o_rcw raw card setting
/// @return rcw_settings vector of rcw settings
/// @note This specialization is suited for creating a cache with custom
/// SPD data (e.g. testing custom SPD).
/// @note MRW attributes are read-only, this function provides a mechanism to test
/// different code paths.
///
fapi2::ReturnCode find_raw_card_helper( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                        const uint64_t i_dimm_type,
                                        const uint8_t i_ref_raw_card_rev,
                                        const uint8_t i_mrw_supported_rc,
                                        const std::vector<std::pair<uint8_t, rcw_settings> >& i_map,
                                        rcw_settings& o_raw_card);

///
/// @brief Wrapper function for finding the raw card
/// @param[in] i_target the dimm target
/// @param[in] i_dimm_type
/// @param[in] i_ref_raw_card_rev for FFDC
/// @param[in] i_map raw card map
/// @param[out] o_rcw raw card setting
/// @return rcw_settings vector of rcw settings
/// @note This specialization is suited for creating a cache with custom
/// SPD data (e.g. testing custom SPD).
///
fapi2::ReturnCode find_raw_card( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                 const uint64_t i_dimm_type,
                                 const uint8_t i_ref_raw_card_rev,
                                 const std::vector<std::pair<uint8_t, rcw_settings> >& i_map,
                                 rcw_settings& o_raw_card);

///
/// @brief Retrieve current raw card settings
/// based on dimm type and raw card reference rev
/// @param[in] i_target dimm target
/// @param[in] i_data SPD data
/// @param[out] o_raw_card raw card settings
/// @return FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode raw_card_factory(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const facade& i_data,
                                   rcw_settings& o_raw_card);

}// spd
}// mss

#endif //_MSS_SPD_FACTORY_H_
