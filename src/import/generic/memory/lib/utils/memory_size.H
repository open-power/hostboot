/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/memory_size.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
/// @file memory_size.H
/// @brief Return the effective memory size behind a target
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_EFF_MEMORY_SIZE_H_
#define _MSS_EFF_MEMORY_SIZE_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/find.H>

namespace mss
{

///
/// @brief Return the total memory size behind the target
/// @tparam MC the type of memory controller (defaults to DEFAULT_MC_TYPE)
/// @tparam T fapi2 target template parameter
/// @param[in] i_target the fapi2::Target, typically a port
/// @param[out] o_size the size of memory in GB behind the target
/// @return FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
fapi2::ReturnCode eff_memory_size( const fapi2::Target<T>& i_target, uint64_t& o_size );

///
/// @brief Return the total memory size behind a MEM_PORT target
/// @param[in] i_target the port target
/// @param[out] o_size the size of memory in GB behind the target
/// @return FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC >
inline fapi2::ReturnCode eff_memory_size( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, uint64_t& o_size )
{
    // Don't try to get cute and read the attributes once and loop over the array.
    // Cronus honors initToZero which would work, but HB might not and so we might get
    // crap in some of the attributes (which we shouldn't access as there's no DIMM there)
    uint64_t l_sizes = 0;
    o_size = 0;

    for (const auto& d : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        FAPI_TRY( eff_memory_size<MC>(d, l_sizes) );
        o_size += l_sizes;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return the total memory size behind an OCMB_CHIP target
/// @param[in] i_target the OCMB target
/// @param[out] o_size the size of memory in GB behind the target
/// @return FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC >
inline fapi2::ReturnCode eff_memory_size( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        uint64_t& o_size )
{
    o_size = 0;

    for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        uint64_t l_size = 0;
        FAPI_TRY( eff_memory_size<MC>(p, l_size) );
        o_size += l_size;
    }

fapi_try_exit:
    return fapi2::current_err;
}

}

#endif
