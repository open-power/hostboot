/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/algorithm.H $                                */
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
#ifndef __UTIL_ALGORITHM_H
#define __UTIL_ALGORITHM_H

namespace Util
{
    namespace Algorithm
    {

        /** @struct static_min
         *  @brief Template class to perform a compile-time min calculation.
         *
         *  Example:
         *      static_min<size_t, 5, 7>::value == 5
         */
        template <typename T, T a, T b>
        struct static_min
        {
            static const T value = (a < b) ? a : b;
        };

        /** @struct static_max
         *  @brief Template class to perform a compile-time max calculation.
         *
         *  Example:
         *      static_max<size_t, 5, 7>::value == 7
         */
        template <typename T, T a, T b>
        struct static_max
        {
            static const T value = (a > b) ? a : b;
        };

    };
};
#endif
