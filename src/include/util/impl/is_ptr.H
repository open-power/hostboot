/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/impl/is_ptr.H $                              */
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
#ifndef __UTIL_IMPL_IS_PTR_H
#define __UTIL_IMPL_IS_PTR_H

#include <util/impl/integral.H>

namespace std
{
    template <typename T> struct _is_pointer : std::false_type {};
    template <typename T> struct _is_pointer<T*> : std::true_type {};
    template <typename T> struct is_pointer :
        _is_pointer<typename remove_cv<T>::type> {};

    template <typename T> struct is_lvalue_reference : std::false_type {};
    template <typename T> struct is_lvalue_reference<T&> : std::true_type {};

    template <typename T> struct is_rvalue_reference : std::false_type {};
    template <typename T> struct is_rvalue_reference<T&&> : std::true_type {};

    template <typename T> struct is_reference : std::false_type {};
    template <typename T> struct is_reference<T&> : std::true_type {};
    template <typename T> struct is_reference<T&&> : std::true_type {};
}

#endif
