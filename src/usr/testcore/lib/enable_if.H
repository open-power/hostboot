/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/lib/enable_if.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#ifndef __LIB_ENABLE_IF_H
#define __LIB_ENABLE_IF_H

#include <cxxtest/TestSuite.H>
#include <type_traits>

// STLEnableIfTest1 overloads are enabled via the return type
template<class T>
typename std::enable_if<std::is_integral<T>::value, T>::type
    STLEnableIfTest1(T t)
{
    t += 2;
    return t;
}

template<class T>
typename std::enable_if<!std::is_integral<T>::value, T>::type
    STLEnableIfTest1(T t)
{
    // if floating point
    if ( std::is_same<float, typename std::remove_cv<T>::type>::value  ||
         std::is_same<double, typename std::remove_cv<T>::type>::value  ||
         std::is_same<long double, typename std::remove_cv<T>::type>::value )
    {
        t += 1.1;
    }
    return t;
}


class STLEnableIfTest : public CxxTest::TestSuite
{
    public:
        void testEnableIf()
        {
            using namespace std;

            int i = 1;
            if (STLEnableIfTest1(i) != 3)
            {
                TS_FAIL("enable_if: expected integral function call to return 3 but see %d",
                    STLEnableIfTest1(i));
            }
            else
            {
                TS_TRACE("enable_if: expected integral function called");
            }

            float f = 1.1;
            if (STLEnableIfTest1(f) != 2.2)
            {
                TS_FAIL("enable_if: expected non-integral function call to return 2.2 but see %f",
                    STLEnableIfTest1(f));
            }
        }

};

#endif
