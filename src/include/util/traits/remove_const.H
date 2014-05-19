/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/traits/remove_const.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

#ifndef __UTIL_TRAITS_REMOVE_CONST
#define __UTIL_TRAITS_REMOVE_CONST

/** @file remove_const.H
 *  Creates a template class remove_const who's type typedef will strip the
 *  "const" from another type.
 *
 *  Example:
 *      remove_const<const int>::type == int
 *      remove_const<int>::type == int
 *      remove_const<const int*>::type == int*
 *
 */

namespace Util
{
    namespace Traits
    {
        template <typename T> struct remove_const;

        template <typename T>
        struct remove_const<const T>
        {
            typedef T type;
        };

        template <typename T>
        struct remove_const<const T*>
        {
            typedef T* type;
        };

        template <typename T>
        struct remove_const<const T&>
        {
            typedef T& type;
        };

        template <typename T>
        struct remove_const
        {
            typedef T type;
        };

    };
};

#endif
