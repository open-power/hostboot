/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/utils/c_str.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file c_str.C
/// @brief Storage for the C-string name of a thing
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <lib/mss_attribute_accessors.H>
#include <c_str.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;

using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{

// Thread local storage for the string we're going to create.
//TODO RTC:153924 Remove the else case when issue is resolved
#ifndef PLAT_NO_THREAD_LOCAL_STORAGE
    thread_local char c_str_storage[fapi2::MAX_ECMD_STRING_LEN];
#else
    char c_str_storage[fapi2::MAX_ECMD_STRING_LEN];
#endif


template<>
const char* c_str( const fapi2::template Target<fapi2::TARGET_TYPE_DIMM>& i_target )
{
    constexpr auto l_max_gen = 3;
    constexpr auto l_max_type = 4;
    static const char* l_map_gen_to_string[l_max_gen] = {"empty", "DDR3", "DDR4"};
    static const char* l_map_type_to_string[l_max_type] = {"empty", "RDIMM", "UDIMM", "LRDIMM"};
    char l_buffer[fapi2::MAX_ECMD_STRING_LEN];

    uint8_t l_type = 0;
    uint8_t l_gen = 0;

    uint8_t l_value[2][2];
    auto l_mca = i_target.getParent<TARGET_TYPE_MCA>();
    auto l_mcs = l_mca.getParent<TARGET_TYPE_MCS>();

    fapi2::toString( i_target, c_str_storage, fapi2::MAX_ECMD_STRING_LEN );

    // Had to unroll FAPI_TRY so that fapi2::current_err doesn't get overwritten, causes errors
    // when calling c_str inside of a function that returns fapi2::ReturnCode
    if (FAPI_ATTR_GET(fapi2::ATTR_EFF_DIMM_TYPE, l_mcs, l_value) != FAPI2_RC_SUCCESS)
    {
        goto fapi_try_exit;
    }

    l_type = l_value[mss::index(l_mca)][mss::index(i_target)];

    if (l_type >= l_max_type)
    {
        goto fapi_try_exit;
    }

    // Had to unroll FAPI_TRY so that fapi2::current_err doesn't get overwritten, causes errors
    // when calling c_str inside of a function that returns fapi2::ReturnCode
    if (FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_GEN, l_mcs, l_value) != FAPI2_RC_SUCCESS)
    {
        goto fapi_try_exit;
    }

    l_gen = l_value[mss::index(l_mca)][mss::index(i_target)];

    if (l_gen >= l_max_gen)
    {
        goto fapi_try_exit;
    }

    snprintf(l_buffer, fapi2::MAX_ECMD_STRING_LEN, " %s (%s)", l_map_type_to_string[l_type], l_map_gen_to_string[l_gen]);
    return strncat( c_str_storage, l_buffer, fapi2::MAX_ECMD_STRING_LEN - strlen(c_str_storage) );

fapi_try_exit:
    // Probably the best we're going to do ...
    return c_str_storage;
}

}
