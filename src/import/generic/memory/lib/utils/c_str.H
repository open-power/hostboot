/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/c_str.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file c_str.H
/// @brief Function to return the C-string name of a thing
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_C_STR_H_
#define _MSS_C_STR_H_

#include <fapi2.H>

namespace mss
{

// Thread local storage for the string we're going to create.
//TODO RTC:153924 Remove the else case when issue is resolved
#ifndef PLAT_NO_THREAD_LOCAL_STORAGE
    extern thread_local char c_str_storage[fapi2::MAX_ECMD_STRING_LEN];
#else
    extern char c_str_storage[fapi2::MAX_ECMD_STRING_LEN];
#endif

///
/// @brief non-target c_str general declaration
/// @tparam T - type you want the const char * for
/// @param[in] i_input - input you want the const char * for
/// @return const char *
///
template< typename T >
const char* c_str( const T& i_input );

///
/// @brief fapi2::Target c_str general declaration
/// @tparam T - fapi2::TargetType you want the name for
/// @param[in] i_target - target you want the name for
/// @return const char *
///
template< fapi2::TargetType T >
inline const char* c_str( const fapi2::template Target<T>& i_target )
{
    fapi2::toString( i_target, c_str_storage, fapi2::MAX_ECMD_STRING_LEN );
    return c_str_storage;
}

///
/// @brief fapi2::Target c_str general declaration
/// @param[in] i_target - target you want the name for
/// @return const char *
/// @note DIMM specialization
///
template<>
inline const char* c_str( const fapi2::template Target<fapi2::TARGET_TYPE_DIMM>& i_target )
{
    static constexpr auto l_max_gen = 3;
    static constexpr auto l_max_type = 5;

    uint8_t l_gen = 0;
    uint8_t l_type = 0;

    // Had to unroll FAPI_TRY so that fapi2::current_err doesn't get overwritten, causes errors
    // when calling c_str inside of a function that returns fapi2::ReturnCode
    if (FAPI_ATTR_GET(fapi2::ATTR_MEM_DIMM_TYPE_METADATA, i_target, l_type) != fapi2::FAPI2_RC_SUCCESS)
    {
        goto fapi_try_exit;
    }

    if (l_type >= l_max_type)
    {
        goto fapi_try_exit;
    }

    // Had to unroll FAPI_TRY so that fapi2::current_err doesn't get overwritten, causes errors
    // when calling c_str inside of a function that returns fapi2::ReturnCode
    if (FAPI_ATTR_GET(fapi2::ATTR_MEM_DRAM_GEN_METADATA, i_target, l_gen) != fapi2::FAPI2_RC_SUCCESS)
    {
        goto fapi_try_exit;
    }

    if (l_gen >= l_max_gen)
    {
        goto fapi_try_exit;
    }

    {
        const char* const l_map_gen_to_string[l_max_gen] = {"empty", "DDR3", "DDR4"};
        const char* const l_map_type_to_string[l_max_type] = {"empty", "RDIMM", "UDIMM", "LRDIMM", "DDIMM"};

        char l_buffer[fapi2::MAX_ECMD_STRING_LEN] = {};
        fapi2::toString( i_target, c_str_storage, fapi2::MAX_ECMD_STRING_LEN );

        snprintf(l_buffer, fapi2::MAX_ECMD_STRING_LEN, " %s (%s)", l_map_type_to_string[l_type], l_map_gen_to_string[l_gen]);
        return strncat( c_str_storage, l_buffer, fapi2::MAX_ECMD_STRING_LEN - strlen(c_str_storage) );
    }

fapi_try_exit:
    // Probably the best we're going to do ...
    return c_str_storage;
}

namespace spd
{

///
/// @brief fapi2::Target c_str general declaration
/// @param[in] i_target - target you want the name for
/// @return const char *
///
template < fapi2::TargetType T >
inline const char* c_str( const fapi2::Target<T>& i_target )
{
    fapi2::toString( i_target, c_str_storage, fapi2::MAX_ECMD_STRING_LEN );
    return c_str_storage;
}

}// spd
}// mss
#endif
