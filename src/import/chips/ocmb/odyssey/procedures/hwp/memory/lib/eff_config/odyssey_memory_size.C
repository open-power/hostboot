/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/eff_config/odyssey_memory_size.C $ */
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
// EKB-Mirror-To: hostboot

///
/// @file odyssey_memory_size.C
/// @brief Return the effective memory size behind a target
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <fapi2.H>

#include <lib/shared/ody_consts.H>
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
fapi2::ReturnCode eff_memory_size<mss::mc_type::ODYSSEY>(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    uint64_t& o_size )
{
    uint32_t l_size = 0;
    o_size = 0;
    FAPI_TRY( mss::attr::get_dimm_size(i_target, l_size) );
    o_size = l_size;

fapi_try_exit:
    return fapi2::current_err;
}

} // ns mss
