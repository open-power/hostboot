/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/impl/type_add.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
#ifndef __UTIL_IMPL_TYPE_ADD_H
#define __UTIL_IMPL_TYPE_ADD_H

#include <util/impl/type_remove.H>

namespace std
{
    template <typename T> struct add_const { typedef const T type; };
    template <typename T> struct add_volatile { typedef volatile T type; };
    template <typename T> struct add_cv { typedef const volatile T type; };

    template <typename T> struct add_pointer
        { typedef typename std::remove_reference<T>::type* type; };

    template <typename T> struct add_lvalue_reference
        { typedef T& type; };

    template <typename T> struct add_rvalue_reference
        { typedef T&& type; };
}

#endif
