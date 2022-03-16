/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/lib/unique_ptr.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2022                        */
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

#ifndef __LIB_UNIQUE_PTR_H
#define __LIB_UNIQUE_PTR_H

#include <cxxtest/TestSuite.H>
#include <memory>
#include <type_traits>

#include <stdlib.h>

using namespace std;

class STDUniquePtrTest : public CxxTest::TestSuite
{
public:

    struct practice_struct
    {
        static int instance_count;

        practice_struct(int i = 0) : x(i)
        {
            ++instance_count;
        }

        ~practice_struct()
        {
            --instance_count;
        }

        int x = 0; // not used except for compile-time tests

        // Make sure unique_ptr isn't using copy constructors or assignment
        // operators
        practice_struct(const practice_struct&) = delete;
        void operator=(const practice_struct&) = delete;
    };

    void testUniquePtr()
    {
        bool custom_lambda_deleter_check = false;

        {
            // Test constructors, move assignment operator
            unique_ptr<practice_struct> a;
            unique_ptr<practice_struct> b(new practice_struct);
            unique_ptr<practice_struct> c { new practice_struct };
            unique_ptr<practice_struct> d({ new practice_struct });
            unique_ptr<practice_struct> e = unique_ptr<practice_struct> { new practice_struct };
            unique_ptr<practice_struct> f(std::move(a));
            unique_ptr<practice_struct> g = std::move(b);
            unique_ptr<practice_struct[]> i(new practice_struct[10] { {1}, {2}, {3}, {4}, {5},
                                                                      {6}, {7}, {8}, {9}, {10} });
            unique_ptr<practice_struct> h;
            const unique_ptr<practice_struct[]> m(new practice_struct[1] { });
            const unique_ptr<const practice_struct[]> m2(new const practice_struct[1] { });

            h = std::move(c);

            // Try custom deleter with function pointer
            unique_ptr<int, decltype(&free)> k(static_cast<int*>(malloc(sizeof(int))), free);

            // Custom deleter with lambda
            auto lambda_deleter = [&custom_lambda_deleter_check](int* ptr)
                                  {
                                      custom_lambda_deleter_check = true;
                                      delete ptr;
                                  };

            unique_ptr<int, decltype(lambda_deleter)> l(new int(),
                                                        std::move(lambda_deleter));

            // test .get() and operator bool
            if (a.get() || f.get())
            {
                TS_FAIL("testUniquePtr: empty unique_ptr is non-NULL");
            }

            if (b.get() || c.get())
            {
                TS_FAIL("testUniquePtr: moved-from unique_ptr is non-NULL");
            }

            if (!d || !e || !g || !h)
            {
                TS_FAIL("testUniquePtr: unique_ptr lost value");
            }

            // test access functions
            d->x++;
            (*d).x++;

            i[4].x = 99;

            if (i[4].x != 99)
            {
                TS_FAIL("Array access through unique_ptr returned incorrect value (expected 99)");
            }

            if (i[3].x != 4)
            {
                TS_FAIL("Array access through unique_ptr returned incorrect value (expected 4)");
            }

            if (practice_struct::instance_count != 16)
            {
                TS_FAIL("testUniquePtr: unique_ptr constructed an incorrect number of objects. "
                        "Remaining object count is %d",
                        practice_struct::instance_count);
            }

            m[0].x = 0; // write through const pointer to mutable data
            m2[0].x; // read through const pointer to const data
        }

        if (practice_struct::instance_count != 0)
        {
            TS_FAIL("testUniquePtr: unique_ptr did not manage objects correctly. "
                    "Remaining object count is %d",
                    practice_struct::instance_count);
        }

        if (custom_lambda_deleter_check != true)
        {
            TS_FAIL("testUniquePtr: lambda custom deleter was not called");
        }
    }

    // Ensure that the default deleter takes up no space
    static_assert(sizeof(unique_ptr<int>) == sizeof(int*));

    /////// Tests below are for things that should fail at compile-time, like the
    /////// copy-constructor and copy-assignment operator.

    using test_success_t = int;
    using test_failure_t = char;

    // Just gives us an lvalue reference to unique_ptr to work with
    template<typename T>
    static unique_ptr<T>& unique_ptr_ref();

    //// This test ensures that it's impossible to copy unique_ptr

    // This function signature should be invalid because it tries to use the
    // copy constructor, so it shouldn't participate in overload resolution
    template<typename T>
    static decltype(unique_ptr<T>(unique_ptr_ref<T>()), test_failure_t())
               unique_ptr_copy_test(int);

    // The ellipses give this function a lower priority than the non-variadic
    // function with the same name, which serves to resolve ambiguity in
    // overload resolution. We do this so that we can provide a meaningful
    // static assert for errors, rather than some opaque error about ambiguous
    // overloads.
    template<typename T>
    static test_success_t unique_ptr_copy_test(...);

    static_assert(is_same<decltype(unique_ptr_copy_test<practice_struct>(0)),
                          test_success_t>::value,
                  "unique_ptr should not be copyable");

    //// This test ensures that it's impossible to assign unique_ptr

    // Invalid, because uses assignment operator
    template<typename T>
    static decltype(unique_ptr<T>() = unique_ptr_ref<T>(), test_failure_t())
               unique_ptr_assign_test(int);

    template<typename T>
    static test_success_t unique_ptr_assign_test(...);

    static_assert(is_same<decltype(unique_ptr_assign_test<practice_struct>(0)),
                          test_success_t>::value,
                  "unique_ptr should not be assignable");

    //// This test ensures that it's impossible to convert an array to a
    //// non-array unique_ptr

    template<typename T>
    static decltype(unique_ptr<T>(unique_ptr_ref<T[]>()), test_failure_t())
               unique_ptr_array_convert_test(int);

    template<typename T>
    static test_success_t unique_ptr_array_convert_test(...);

    static_assert(is_same<decltype(unique_ptr_array_convert_test<practice_struct>(0)),
                          test_success_t>::value,
                  "array unique_ptr should not be convertible to non-array");

    //// This test ensures that it's impossible to use array syntax to index a
    //// non-array unique_ptr

    template<typename T>
    static decltype(unique_ptr_ref<T>()[0], test_failure_t())
               unique_ptr_array_index_test(int);

    template<typename T>
    static test_success_t unique_ptr_array_index_test(...);

    static_assert(is_same<decltype(unique_ptr_array_index_test<practice_struct>(0)),
                          test_success_t>::value,
                  "array unique_ptr should not be convertible to non-array");
};

int STDUniquePtrTest::practice_struct::instance_count;

#endif
