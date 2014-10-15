/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/lib/stl_functional.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
        void testUnaryPtrFun()
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

        void testBinaryPtrFun()
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
};

#endif
