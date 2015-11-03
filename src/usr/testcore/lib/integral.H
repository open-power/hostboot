/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/lib/integral.H $                             */
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
#ifndef __LIB_INTEGRAL_H
#define __LIB_INTEGRAL_H

#include <cxxtest/TestSuite.H>
#include <type_traits>
#include <stdint.h>

class STLIntegralTest : public CxxTest::TestSuite
{
    public:
        void testIntegral()
        {
            using namespace std;

            if (!integral_constant<bool, true>::value)
            {
                TS_FAIL("integral_constant<bool, true>::value != true");
            }
            if (integral_constant<bool, false>::value)
            {
                TS_FAIL("integral_constant<bool, false>::value != false");
            }
            if (integral_constant<size_t, 100>::value != 100)
            {
                TS_FAIL("integral_constant<size_t, 100>::value != 100");
            }
            auto v = integral_constant<size_t, 20>();
            if (v() != 20)
            {
                TS_FAIL("v() != 20");
            }

            // Test compile of value_type.
            integral_constant<size_t, 20>::value_type a = 30;
            if (a != 30)
            {
                TS_FAIL("a != 30");
            }
            // Test compile of type.
            integral_constant<size_t, 20>::type::value_type b = 40;
            if (b != 40)
            {
                TS_FAIL("b != 40");
            }

        }

        void testBoolTypes()
        {
            using namespace std;

            if (!true_type::value)
            {
                TS_FAIL("true_type is not true.");
            }
            if (false_type::value)
            {
                TS_FAIL("false_type is not false.");
            }
        }
};

#endif
