/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/lib/is_same.H $                              */
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
#ifndef __LIB_IS_SAME_H
#define __LIB_IS_SAME_H

#include <cxxtest/TestSuite.H>
#include <type_traits>

class STLIsSameTest : public CxxTest::TestSuite
{
    public:
        void testIsSame()
        {
            using namespace std;

            static_assert(!is_same<char,int>::value,"is_same<char,int> is true.");
            static_assert(!is_same<char*,void*>::value,"is_same<char*,void*> is true.");
            static_assert(!is_same<size_t, const size_t>::value,"is_same<size_t, const size_t> is true.");
            static_assert(is_same<int,int>::value,"is_same<int,int> is false.");
            static_assert(is_same<const char*,const char*>::value,"is_same<const char*, const char*> is false.");
        }
};

#endif
