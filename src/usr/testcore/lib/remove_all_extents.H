/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/lib/remove_all_extents.H $                   */
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
#ifndef __LIB_REMOVE_ALL_EXTENTS_H
#define __LIB_REMOVE_ALL_EXTENTS_H

#include <cxxtest/TestSuite.H>
#include <type_traits>

#define TS_CHECK(...)                                                  \
    if (!__VA_ARGS__)                                                   \
    {                                                                   \
        TS_FAIL("testRemoveAllExtents: Test " #__VA_ARGS__ " is false, should be true"); \
    }

class STLRemoveAllExtentsTest : public CxxTest::TestSuite
{
    public:
        void testRemoveAllExtents()
        {
            // Leveraging std::is_same, which has already been unit tested
            {
                using test_type = std::remove_all_extents<uint8_t>::type;
                TS_CHECK(std::is_same<uint8_t, test_type>::value);
            }

            {
                using test_type = std::remove_all_extents<uint16_t[ ][1][1]>::type;
                TS_CHECK(std::is_same<uint16_t, test_type>::value);
            }

            {
                using test_type = std::remove_all_extents<uint32_t[ ]>::type;
                TS_CHECK(std::is_same<uint32_t, test_type>::value);
            }

            {
                using test_type = std::remove_all_extents<int[ ][1]>::type;
                TS_CHECK(std::is_same<int, test_type>::value);
            }

        }
};

#undef TS_CHECK

#endif
