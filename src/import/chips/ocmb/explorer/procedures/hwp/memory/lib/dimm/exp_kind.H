/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/dimm/exp_kind.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/// @file exp_kind.H
/// @brief Encapsulation for dimms of all types
///
// *HWP HWP Owner: Amita Banchhor <Amita.Banchhor@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_EXPLORER_KIND_H_
#define _MSS_EXPLORER_KIND_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/dimm/kind.H>
#include <mss_generic_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>
#include <mss_explorer_attribute_getters.H>

namespace mss
{

namespace dimm
{

///
/// @brief Check if any dimms exist that have RCD enabled - explorer/DIMM specialization
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_has_rcd - true iff any DIMM with RCD detected
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode has_rcd<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        bool& o_has_rcd );

///
/// @brief Check if any dimms exist that have RCD enabled - explorer/PORT specialization
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_has_rcd - true iff any DIMM with RCD detected
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode has_rcd<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        bool& o_has_rcd );

///
/// @brief Check if any dimms exist that have RCD enabled - explorer/OCMB specialization
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_has_rcd - true iff any DIMM with RCD detected
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode has_rcd<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        bool& o_has_rcd );

///
/// @brief Check if the dimm is hybrid media type MDS - explorer/OCMB specialization
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_is_mds - true iff any dimm is MDS
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode is_mds<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        bool& o_is_mds );

///
/// @brief Check if the dimm is hybrid media type MDS - explorer/OCMB specialization
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_is_mds - true iff any dimm is MDS
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode is_mds<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        bool& o_is_mds );

///
/// @brief Check if the dimm is hybrid media type MDS - explorer/OCMB specialization
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_is_mds - true iff any dimm is MDS
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode is_mds<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        bool& o_is_mds );

} // end dimm ns
} // end mss ns

#endif
