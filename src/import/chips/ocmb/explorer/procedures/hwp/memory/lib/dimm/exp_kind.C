/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/dimm/exp_kind.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2023                        */
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
/// @file exp_kind.C
/// @brief Encapsulation for dimms of all types
///
// *HWP HWP Owner: Amita Banchhor <Amita.Banchhor@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <generic/memory/lib/utils/dimm/kind.H>
#include <mss_generic_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>
#include <mss_explorer_attribute_getters.H>
#include <lib/shared/exp_consts.H>
#include <lib/dimm/exp_kind.H>
#include <lib/exp_attribute_accessors_manual.H>

namespace mss
{

namespace dimm
{

///
/// @brief Function to get number of dimms
/// @param[in] i_target ocmb chip target
/// @return number of the dimms
///
template<>
size_t count_num_dimms<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    return mss::count_mem_port(mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target),
                               fapi2::TARGET_STATE_PRESENT);
}

///
/// @brief Check if any dimms exist that have RCD enabled - explorer/DIMM specialization
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_has_rcd - true iff any DIMM with RCD detected
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode has_rcd<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        bool& o_has_rcd )
{
    // Call manual accessor for dimm
    return mss::has_rcd(i_target, o_has_rcd);
}

///
/// @brief Check if any dimms exist that have RCD enabled - explorer/PORT specialization
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_has_rcd - true iff any DIMM with RCD detected
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode has_rcd<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        bool& o_has_rcd )
{
    // Call manual accessor for mem_port
    return mss::has_rcd(i_target, o_has_rcd);
}

///
/// @brief Check if any dimms exist that have RCD enabled - explorer/OCMB specialization
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_has_rcd - true iff any DIMM with RCD detected
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode has_rcd<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        bool& o_has_rcd )
{
    // Call manual accessor for ocmb_chip
    return mss::has_rcd(i_target, o_has_rcd);
}

} // end dimm ns
} // end mss ns
