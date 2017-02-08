/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/eff_config/memory_size.C $ */
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
/// @file memory_size.C
/// @brief Return the effective memory size behind a target
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <lib/mss_attribute_accessors.H>

#include <lib/shared/mss_const.H>
#include <lib/eff_config/memory_size.H>

#include <lib/utils/find.H>

namespace mss
{

///
/// @brief Return the total memory size behind an MCA
/// @param[in] i_target the MCA target
/// @param[out] o_size the size of memory in GB behind the target
/// @return FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode eff_memory_size( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, uint64_t& o_size )
{
    // Don't try to get cute and read the attributes once and loop over the array.
    // Cronus honors initToZero which would work, but HB might not and so we might get
    // crap in some of the attributes (which we shouldn't access as there's no DIMM there)
    uint32_t l_sizes = 0;
    o_size = 0;

    for (const auto& d : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        FAPI_TRY( mss::eff_dimm_size(d, l_sizes) );
        o_size += l_sizes;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return the total memory size behind an MBIST
/// @param[in] i_target the MCBIST target
/// @param[out] o_size the size of memory in GB behind the target
/// @return FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode eff_memory_size( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target, uint64_t& o_size )
{
    o_size = 0;

    for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
    {
        uint64_t l_size = 0;
        FAPI_TRY( eff_memory_size(p, l_size) );
        o_size += l_size;
    }

fapi_try_exit:
    return fapi2::current_err;
}

}

