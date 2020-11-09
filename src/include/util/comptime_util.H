/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/comptime_util.H $                            */
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
#ifndef __COMPTIME_UTIL_H
#define __COMPTIME_UTIL_H

#include <cstddef>
/**
 * @brief Common header for compile time utilties
 */

namespace Util
{
/** Compile-time strlen implementation.
  *
  *  @param s - A const char ptr pointing to a null-terminated string
  *  @return size_t containing the length of string not including null terminator
  */
constexpr inline size_t comptime_strlen(const char* s)
{
    size_t length = 0;
    while (*s)
    {
        ++length;
        ++s;
    }
    return length;
}
}
#endif