/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/utils/c_str.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
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
const char* c_str( const fapi2::template Target<T>& i_target )
{
    fapi2::toString( i_target, c_str_storage, fapi2::MAX_ECMD_STRING_LEN );
    return c_str_storage;
}

template<>
const char* c_str( const fapi2::template Target<fapi2::TARGET_TYPE_DIMM>& i_target );

}
#endif
