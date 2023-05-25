/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/lib/decay.H $                                */
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
#ifndef __LIB_DECAY_H
#define __LIB_DECAY_H

#include <cxxtest/TestSuite.H>
#include <type_traits>

template<typename T, typename U>
constexpr bool is_decay_equal = std::is_same<std::decay_t<T>, U>::value;

class STLDecayTest : public CxxTest::TestSuite
{
    public:
        void testDecay()
        {
            using namespace std;

            // Tests whether the lefthand side template arg can be type-converted to the righthand side.
            // decay should perform type conversions equivalent to ones performed when passing by value to a function.
            static_assert(is_decay_equal<int, int>);
            static_assert( ! is_decay_equal<int, float>);
            static_assert(is_decay_equal<int&, int>);
            static_assert(is_decay_equal<int&&, int>);
            static_assert(is_decay_equal<const int&, int>);
            static_assert(is_decay_equal<int[2], int*>);
            static_assert( ! is_decay_equal<int[4][2], int*>);
            static_assert( ! is_decay_equal<int[4][2], int**>);
            static_assert(is_decay_equal<int[4][2], int(*)[2]>);
            static_assert(is_decay_equal<int(int), int(*)(int)>);
        }
};

#endif
