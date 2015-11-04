/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/impl/_is_integral.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
#ifndef __UTIL_IMPL_IS_INTEGRAL_H
#define __UTIL_IMPL_IS_INTEGRAL_H

#include <util/impl/integral.H>
#include <util/impl/type_remove.H>

namespace std
{
    template <typename T> struct _is_integral : std::false_type {};
    template <> struct _is_integral<bool> : std::true_type {};
    template <> struct _is_integral<char> : std::true_type {};
    template <> struct _is_integral<short> : std::true_type {};
    template <> struct _is_integral<int> : std::true_type {};
    template <> struct _is_integral<long> : std::true_type {};
    template <> struct _is_integral<long long> : std::true_type {};
    template <> struct _is_integral<unsigned char> : std::true_type {};
    template <> struct _is_integral<unsigned short> : std::true_type {};
    template <> struct _is_integral<unsigned int> : std::true_type {};
    template <> struct _is_integral<unsigned long> : std::true_type {};
    template <> struct _is_integral<unsigned long long> : std::true_type {};

    template <typename T> struct is_integral :
        _is_integral<
            typename std::remove_cv<
                typename std::remove_reference<T>::type>::type> {};

}
#endif
