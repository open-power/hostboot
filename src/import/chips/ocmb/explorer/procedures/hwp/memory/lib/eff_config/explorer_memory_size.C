/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/eff_config/explorer_memory_size.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file explorer_memory_size.C
/// @brief Return the effective memory size behind a target
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <fapi2.H>

#include <lib/shared/exp_consts.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/memory_size.H>

namespace mss
{

///
/// @brief Return the total memory size behind a DIMM target
/// @param[in] i_target the DIMM target
/// @param[out] o_size the size of memory in GB behind the target
/// @return FAPI2_RC_SUCCESS if ok
/// @note The purpose of this specialization is to bridge the gap between different accessor functions
///
template<>
fapi2::ReturnCode eff_memory_size<mss::mc_type::EXPLORER>(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    uint64_t& o_size )
{
#ifdef ACCESSORS_FIXED
    uint32_t l_size = 0;
    o_size = 0;
    FAPI_TRY( mss::attr::get_dimm_size(i_target, l_size) );
    o_size = l_size;

fapi_try_exit:
    return fapi2::current_err;
#endif

    // Temporarily unrolling attribute accessor here until mss library is fixed
    uint32_t l_value[2] = {};
    const auto l_port = i_target.getParent<fapi2::TARGET_TYPE_MEM_PORT>();
    uint8_t l_pos;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_REL_POS, i_target, l_pos) );
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DIMM_SIZE, l_port, l_value) );
    o_size = l_value[l_pos];

fapi_try_exit:
    return fapi2::current_err;

}

} // ns mss
