/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/utils/mss_pair.H $ */
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
/// @file mss_pair.H
/// @brief Creates a pair class that has a constexpr constructor
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP


#ifndef _MSS_PAIR_CONST_H_
#define _MSS_PAIR_CONST_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/c_str.H>

namespace mss
{

///
/// @brief a version of std::pair that has a constexpr constructor
/// allows for MUCH cleaner code and code that can be run at compile time
/// @tparam T1 - type of first
/// @tparam T2 - type of second
///
template <typename T1, typename T2>
struct pair
{
    // forces the user to initialize the values
    pair() = delete;

    // disables the copy constructor
    pair( const pair<T1, T2>& i_rhs) = delete;

    ///
    /// @brief default destructor
    ///
    ~pair() = default;

    ///
    /// @brief constexpr constructor
    /// @param[in] i_first - input to the first internal variable
    /// @param[in] i_second - input to the second internal variable
    ///
    constexpr pair(const T1& i_first, const T2& i_second) :
        first(i_first),
        second(i_second)
    {}

    // not using iv_ to keep this as close as possible to pair
    T1 first;
    T2 second;
};

}
#endif
