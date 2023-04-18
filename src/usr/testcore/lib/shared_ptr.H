/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/lib/shared_ptr.H $                           */
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

            if (p1 == p2)
            {
                TS_FAIL("p1 and p2 should not be equal pointers");
            }

            shared_ptr<T1> p4 = static_pointer_cast<T1>(p3);
            if (p3 != p4)
            {
                TS_FAIL("p3 and p4 should be equal pointers");
            }
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

        void testSharedPtrArray()
        {
            TS_INFO(ENTER_MRK"testSharedPtrArray");

            static int counter = 0;

            struct test
            {
                test() { ++counter; }
                ~test() { --counter; }

                int x = 0;
            };

            bool custom_deleter_run = false;

            {
                std::shared_ptr<test[]> foo(new test[10]);

                if (counter != 10)
                {
                    TS_FAIL("testSharedPtrArray: constructor failed to increment count");
                }

                auto newptr = new test[10];

                if (counter != 20)
                {
                    TS_FAIL("testSharedPtrArray: constructor failed to increment count (2)");
                }

                foo.reset(newptr);
                newptr = nullptr;

                if (counter != 10)
                {
                    TS_FAIL("testSharedPtrArray: constructor failed to increment count");
                }

                auto foo2 = foo;

                std::shared_ptr<test[]> foo3(new test[10]);

                if (counter != 20)
                {
                    TS_FAIL("testSharedPtrArray: constructor failed to increment count");
                }

                std::shared_ptr<const test[]> constfoo(new const test[10]);

                std::shared_ptr<test[]> foo_custom_deleter(new test[10],
                                                           [&](test* t)
                                                           {
                                                               delete[] t;
                                                               custom_deleter_run = true;
                                                           });

                // Make sure these compile
                foo.get();
                foo->x = 100;
                foo.swap(foo3);
                foo[3];

                foo == foo2;
                foo != foo2;
                foo = foo2;
            }

            if (counter != 0)
            {
                TS_FAIL("testSharedPtrArray: constructor failed to decrement count");
            }

            if (!custom_deleter_run)
            {
                TS_FAIL("testSharedPtrArray: did not run custom deleter");
            }

            {
                std::shared_ptr<test[][2]> foo(new test[5][2]);

                if (counter != 10)
                {
                    TS_FAIL("testSharedPtrArray: constructor failed to increment count for multidimensional array");
                }
            }

            TS_INFO(EXIT_MRK"testSharedPtrArray");
        }

        void testSharedPtr_Compile1()
        {
            // This was a compile issue for the FAPI2 code.
            __STLSharedPtrTester3 foo(10);
        }
};

#endif
