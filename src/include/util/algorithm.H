/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/algorithm.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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

        /**
         * @brief - utility function that determines if a given number is
         *          power of 2.
         *
         * @param[in] i_num - given number.
         *
         * @return bool - True if the number is a power of 2, False otherwise.
         */
        template <typename T>
        bool isPow2(T i_num)
        {
            return (!(i_num & (i_num-1)));
        }

    };
};
#endif
