/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/lib/shared_ptr.H $                           */
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
#ifndef __LIB_SHARED_PTR_H
#define __LIB_SHARED_PTR_H

#include <cxxtest/TestSuite.H>
#include <memory>

struct __STLSharedPtrTester
{
    __STLSharedPtrTester(int, int) {};
    __STLSharedPtrTester(int&) {};
    __STLSharedPtrTester(const __STLSharedPtrTester&) {}
};

struct __STLSharedPtrTester2 : __STLSharedPtrTester
{
    using __STLSharedPtrTester::__STLSharedPtrTester;
};

struct __STLSharedPtrTester3
{
    std::shared_ptr<uint8_t> foo;

    explicit __STLSharedPtrTester3(size_t i)
    {
        foo = std::shared_ptr<uint8_t>(new uint8_t[i]());
    }
};

class STLSharedPtrTest : public CxxTest::TestSuite
{
    public:
        void testSharedPtr()
        {
            using namespace std;
            typedef __STLSharedPtrTester T1;
            typedef __STLSharedPtrTester2 T2;

            auto p0 = make_shared<T1>(1,2);
            if (!p0.unique())
            {
                TS_FAIL("p0 is not unique.");
            }

            int a = 10;
            auto p1 = make_shared<T1>(a);
            auto p2 = make_shared<T1>(*p1);
            auto p3 = make_shared<T2>(3,4);
            if (!p3.unique())
            {
                TS_FAIL("p3 is not unique.");
            }

            shared_ptr<T1> p4 = static_pointer_cast<T1>(p3);
            if (p3.use_count() != 2)
            {
                TS_FAIL("p3 is not shared now.");
            }
            if (p4.use_count() != 2)
            {
                TS_FAIL("p4 is not shared now.");
            }

            p3.reset();
            if (p3)
            {
                TS_FAIL("p3 is not NULL after reset.");
            }
            if (!p4.unique())
            {
                TS_FAIL("p4 is not unique after p3.reset.");
            }
        }

        void testSharedPtr_Compile1()
        {
            // This was a compile issue for the FAPI2 code.
            __STLSharedPtrTester3 foo(10);
        }
};

#endif
