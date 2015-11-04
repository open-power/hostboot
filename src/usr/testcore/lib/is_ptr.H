/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/lib/is_ptr.H $                               */
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
#ifndef __LIB_IS_PTR_H
#define __LIB_IS_PTR_H

#include <cxxtest/TestSuite.H>
#include <type_traits>

class STLIsPtrTest : public CxxTest::TestSuite
{
    public:
        void testIsPtr()
        {
            using namespace std;

            if (is_pointer<int>::value)
            {
                TS_FAIL("is_pointer<int> is true.");
            }
            if (!is_pointer<char*>::value)
            {
                TS_FAIL("is_pointer<char*> is not true.");
            }
            if (!is_pointer<char* const>::value)
            {
                TS_FAIL("is_pointer<char* const> is not true.");
            }
            if (!is_pointer<char* volatile>::value)
            {
                TS_FAIL("is_pointer<char* volatile> is not true.");
            }
            if (is_pointer<int&>::value)
            {
                TS_FAIL("is_pointer<int&> is true.");
            }
        }

        void testIsReference()
        {
            using namespace std;

            if (is_reference<int>::value)
            {
                TS_FAIL("is_reference<int> is true.");
            }
            if (!is_reference<int&>::value)
            {
                TS_FAIL("is_reference<int&> is false.");
            }
            if (!is_reference<int&&>::value)
            {
                TS_FAIL("is_reference<int&&> is false.");
            }
            if (!is_reference<const int&>::value)
            {
                TS_FAIL("is_reference<const int&> is false.");
            }
        }

        void testIsLReference()
        {
            using namespace std;

            if (is_lvalue_reference<int>::value)
            {
                TS_FAIL("is_lvalue_reference<int> is true.");
            }
            if (!is_lvalue_reference<int&>::value)
            {
                TS_FAIL("is_lvalue_reference<int&> is false.");
            }
            if (is_lvalue_reference<int&&>::value)
            {
                TS_FAIL("is_lvalue_reference<int&&> is true.");
            }
        }

        void testIsRReference()
        {
            using namespace std;

            if (is_rvalue_reference<int>::value)
            {
                TS_FAIL("is_rvalue_reference<int> is true.");
            }
            if (is_rvalue_reference<int&>::value)
            {
                TS_FAIL("is_rvalue_reference<int&> is true.");
            }
            if (!is_rvalue_reference<int&&>::value)
            {
                TS_FAIL("is_rvalue_reference<int&&> is false.");
            }
        }

};

#endif
