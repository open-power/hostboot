/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/lib/is_integral.H $                          */
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
#ifndef __LIB_IS_INTEGRAL_H
#define __LIB_IS_INTEGRAL_H

#include <cxxtest/TestSuite.H>
#include <type_traits>

class STLIsIntegralTest : public CxxTest::TestSuite
{
    public:
        void testIsIntegral()
        {
            using namespace std;

            if(!is_integral<bool>::value)
            {
                TS_FAIL("is_integral<bool> is false.");
            }
            if(!is_integral<const bool>::value)
            {
                TS_FAIL("is_integral<const bool> is false.");
            }
            if(!is_integral<bool&>::value)
            {
                TS_FAIL("is_integral<bool&> is false.");
            }
            if(!is_integral<int>::value)
            {
                TS_FAIL("is_integral<int> is false.");
            }
            if(!is_integral<unsigned int>::value)
            {
                TS_FAIL("is_integral<unsigned int> is false.");
            }
            if(is_integral<float>::value)
            {
                TS_FAIL("is_integral<float> is true.");
            }
            if(is_integral<char*>::value)
            {
                TS_FAIL("is_integral<char*> is true.");
            }
        }

};

#endif
