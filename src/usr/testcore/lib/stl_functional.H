/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/lib/stl_functional.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2023                        */
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



#ifndef __LIB_STL_FUNCTIONAL_H
#define __LIB_STL_FUNCTIONAL_H

#include <cxxtest/TestSuite.H>
#include <functional>
#include <vector>
#include <list>
#include <initializer_list>

#define TS_CHECK(...)                                                   \
    if (!(__VA_ARGS__))                                                 \
    {                                                                   \
        TS_FAIL("test comparison functors: Test " #__VA_ARGS__ " is false, should be true"); \
    }

static bool STLFunctionalTest__matches1(int i)
{
    return i == 1;
}

static bool STLFunctionalTest__matches(int n, int m)
{
    return n == m;
}

class STLFunctionalTest : public CxxTest::TestSuite
{
    public:
        void test_UnaryPtrFun()
        {
            using std::ptr_fun;

            if (!ptr_fun(&STLFunctionalTest__matches1)(1))
            {
                TS_FAIL("__matches1(1) is false.");
            }

            if (ptr_fun(&STLFunctionalTest__matches1)(100))
            {
                TS_FAIL("__matches1(100) is true.");
            }
        }

        void test_BinaryPtrFun()
        {
            using std::ptr_fun;
            using std::vector;

            vector<int> v;

            for(int i = 0; i < 10; i++)
            {
                v.push_back(i);
            }

            for(int i = 0; i < 10; i++)
            {
                if (*find_if(v.begin(), v.end(),
                        bind1st(ptr_fun(&STLFunctionalTest__matches), i)) != i)
                {
                    TS_FAIL("find_if with bind1st of %d doesn't match.", i);
                }

                if (*find_if(v.begin(), v.end(),
                        bind2nd(ptr_fun(&STLFunctionalTest__matches), i)) != i)
                {
                    TS_FAIL("find_if with bind2nd of %d doesn't match.", i);
                }
            }
        }

        void test_InitializerListVectorFun()
        {
            using std::vector;

            vector<uint32_t> v {0,1,2,3,4};
            uint32_t VEC_SIZE = 5;

            TS_TRACE("max size of vector v is %d",v.max_size());
            TS_TRACE("BEGIN: size of vector v is %d",v.size());

            if(v.size() != VEC_SIZE)
            {
                TS_FAIL("Size not equal to expected value expected:%d "
                        "actual:%d!",
                        VEC_SIZE,v.size());
            }

            for(uint32_t i=0;i<VEC_SIZE;i++)
            {
                if (v[i] != i)
                {
                    TS_FAIL("Vector array index %d is not equal to %d, "
                            "it is %d",
                            i,i,v[i]);
                }
            }

            // Pop a couple off
            v.pop_back();
            v.pop_back();

            if(v.size() != (VEC_SIZE-2))
            {
                TS_FAIL("pop_back did not reduce size as expected!");
            }

            // Add some back
            v.push_back(100);
            v.push_back(99);

            if(v.size() != VEC_SIZE)
            {
                TS_FAIL("Size not equal to expected value expected:%d "
                        "actual:%d after pop and push!",
                        VEC_SIZE,v.size());
            }

            TS_TRACE("END: size of vector v is %d",v.size());
        }

        void test_InitializerListFun()
        {
            using std::list;
            std::list<uint32_t> l = {0,1,2,3,4};

            uint32_t LIST_SIZE = 5;
            if(l.size() != LIST_SIZE)
            {
                TS_FAIL("Size not equal to expected value expected:%d "
                        "actual:%d!",
                        LIST_SIZE,l.size());
            }

            for(uint32_t i=0;i<LIST_SIZE;i++)
            {
                if (l.front() != i)
                {
                    TS_FAIL("Index %d is not equal to %d, "
                            "it is %d",
                            i,i,l.front());
                }
                l.pop_front();
            }

            if(l.size() != 0)
            {
                TS_FAIL("List size not equal to 0 like it should be! %d",
                        l.size());
            }

        }

        void test_lessFun()
        {
            TS_CHECK( std::less<uint32_t>()(1,2) );
            TS_CHECK( std::less<uint16_t>()(5,20) );
            TS_CHECK( !std::less<uint8_t>()(100,2) );
            TS_CHECK( !std::less<int>()(-40,-40) );
            TS_CHECK( std::less<int32_t>()(-40,-30) );
        }

        void test_lessEqualFun()
        {
            TS_CHECK( std::less_equal<int>()(-40,-40) );
            TS_CHECK( std::less_equal<uint8_t>()(4,4) );
            TS_CHECK( std::less_equal<uint8_t>()(4,200) );
            TS_CHECK( std::less_equal<uint32_t>()(5,20) );
            TS_CHECK( !std::less_equal<uint16_t>()(300,50) );
        }

        void test_greaterFun()
        {
            TS_CHECK( !std::greater<int>()(-40,-40) );
            TS_CHECK( !std::greater<uint8_t>()(4,4) );
            TS_CHECK( !std::greater<uint8_t>()(4,200) );
            TS_CHECK( !std::greater<uint32_t>()(5,20) );
            TS_CHECK( std::greater<int64_t>()(-5,-20) );
            TS_CHECK( std::greater<uint16_t>()(300,50) );
        }

        void test_greaterEqualFun()
        {
            TS_CHECK( std::greater_equal<int>()(-40,-40) );
            TS_CHECK( std::greater_equal<uint8_t>()(4,4) );
            TS_CHECK( !std::greater_equal<uint8_t>()(4,200) );
            TS_CHECK( !std::greater_equal<uint32_t>()(5,20) );
            TS_CHECK( std::greater_equal<int64_t>()(-5,-20) );
            TS_CHECK( std::greater_equal<uint16_t>()(300,50) );
        }

        void test_equalTolFun()
        {
            TS_CHECK( std::equal_to<int>()(-40,-40) );
            TS_CHECK( std::equal_to<uint8_t>()(4,4) );
            TS_CHECK( !std::equal_to<uint8_t>()(4,200) );
            TS_CHECK( !std::equal_to<uint32_t>()(5,20) );
            TS_CHECK( !std::equal_to<int64_t>()(-5,-20) );
            TS_CHECK( !std::equal_to<uint16_t>()(300,50) );
        }

        void test_NotEqualTolFun()
        {
            TS_CHECK( !std::not_equal_to<int>()(-40,-40) );
            TS_CHECK( !std::not_equal_to<uint8_t>()(4,4) );
            TS_CHECK( std::not_equal_to<uint8_t>()(4,200) );
            TS_CHECK( std::not_equal_to<uint32_t>()(5,20) );
            TS_CHECK( std::not_equal_to<int64_t>()(-5,-20) );
            TS_CHECK( std::not_equal_to<uint16_t>()(300,50) );
        }

    static bool predicate_positive(int x)
    {
        return x > 0;
    }

    static bool predicate_negative(int x)
    {
        return x < 0;
    }

    static bool predicate_even(int x)
    {
        return (x % 2) == 0;
    }

    void test_all_of()
    {
        std::vector<int> empty;
        std::vector<int> items { 1, 2, 3, 4 };

        // empty set
        TS_CHECK(std::all_of(begin(empty), end(empty), predicate_positive));
        // all true
        TS_CHECK(std::all_of(begin(items), end(items), predicate_positive));
        // Some true, some false
        TS_CHECK(!std::all_of(begin(items), end(items), predicate_even));
        // All false
        TS_CHECK(!std::all_of(begin(items), end(items), predicate_negative));
    }

    void test_any_of()
    {
        std::vector<int> empty;
        std::vector<int> items { 1, 2, 3, 4 };

        // empty set
        TS_CHECK(!std::any_of(begin(empty), end(empty), predicate_positive));
        // all true
        TS_CHECK(std::any_of(begin(items), end(items), predicate_positive));
        // Some true, some false
        TS_CHECK(std::any_of(begin(items), end(items), predicate_even));
        // All false
        TS_CHECK(!std::any_of(begin(items), end(items), predicate_negative));
    }

    void test_none_of()
    {
        std::vector<int> empty;
        std::vector<int> items { 1, 2, 3, 4 };

        // empty set
        TS_CHECK(std::none_of(begin(empty), end(empty), predicate_positive));
        // all true
        TS_CHECK(!std::none_of(begin(items), end(items), predicate_positive));
        // Some true, some false
        TS_CHECK(!std::none_of(begin(items), end(items), predicate_even));
        // All false
        TS_CHECK(std::none_of(begin(items), end(items), predicate_negative));
    }

    void test_count()
    {
        std::vector<int> empty;
        std::vector<int> items { 1, 2, 3, 4 };
        std::vector<int> repeats { 1, 2, 1, 3, 4, 5, 6, 1, 2, 1, 1 };

        TS_CHECK(std::count(begin(empty), end(empty), 1) == 0);

        TS_CHECK(std::count(begin(items), end(items), 0) == 0);
        TS_CHECK(std::count(begin(items), end(items), 1) == 1);
        TS_CHECK(std::count(begin(items), end(items), 2) == 1);

        TS_CHECK(std::count(begin(repeats), end(repeats), 6) == 1);
        TS_CHECK(std::count(begin(repeats), end(repeats), 1) == 5);
        TS_CHECK(std::count(begin(repeats), end(repeats), 2) == 2);
    }

    void test_count_if()
    {
        std::vector<int> empty;
        std::vector<int> items { 1, 2, 3, 4 };
        std::vector<int> repeats { 1, 2, 1, 3, 4, 5, 6, 1, 2, 1, 1 };

        TS_CHECK(std::count_if(begin(empty), end(empty), predicate_even) == 0);

        TS_CHECK(std::count_if(begin(items), end(items), predicate_even) == 2);
        TS_CHECK(std::count_if(begin(items), end(items), predicate_negative) == 0);

        TS_CHECK(std::count_if(begin(repeats), end(repeats), predicate_even) == 4);
        TS_CHECK(std::count_if(begin(repeats), end(repeats), predicate_negative) == 0);
    }
};

#undef TS_CHECK

#endif
