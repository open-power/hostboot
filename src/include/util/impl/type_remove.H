/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/impl/type_remove.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2023                        */
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
#ifndef __UTIL_IMPL_TYPE_REMOVE_H
#define __UTIL_IMPL_TYPE_REMOVE_H

#include <stdint.h>

namespace std
{
    template <typename T> struct remove_const { typedef T type; };
    template <typename T> struct remove_const<const T> { typedef T type; };

    template <typename T> struct remove_volatile { typedef T type; };
    template <typename T> struct remove_volatile<volatile T>
        { typedef T type; };

    template <typename T> struct remove_cv
    {
        typedef typename remove_const<typename remove_volatile<T>::type>::type
                type;
    };

    template <typename T> struct remove_reference { typedef T type; };
    template <typename T> struct remove_reference<T&> { typedef T type; };
    template <typename T> struct remove_reference<T&&> { typedef T type; };

    template <typename T> struct remove_pointer { typedef T type; };
    template <typename T> struct remove_pointer<T*> { typedef T type; };
    template <typename T> struct remove_pointer<T* const> { typedef T type; };
    template <typename T> struct remove_pointer<T* volatile>
        { typedef T type; };
    template <typename T> struct remove_pointer<T* const volatile>
        { typedef T type; };

    template<typename T>
    struct remove_extent
    {
        using type = T;
    };

    template<typename T>
    struct remove_extent<T[]>
    {
        using type = T;
    };

    template<typename T, size_t N>
    struct remove_extent<T[N]>
    {
        using type = T;
    };

    template<class T> struct remove_all_extents { typedef T type;};
    template<class T> struct remove_all_extents<T[]>
        { typedef typename remove_all_extents<T>::type type; };
    template<class T, size_t N> struct remove_all_extents<T[N]>
        { typedef typename remove_all_extents<T>::type type; };
}

#endif
