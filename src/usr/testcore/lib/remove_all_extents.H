/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/lib/remove_all_extents.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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

class STLRemoveAllExtentsTest : public CxxTest::TestSuite
{
    public:
        void testRemoveAllExtents()
        {
            // Leveraging std::is_same, which has already been unit tested
	    {
              using test_type = std::remove_all_extends<uint8_t>::type;
              TS_ASSERT(std::is_same<uint8_t, test_type>::value);
            }

            {
              using test_type = std::remove_all_extends<uint16_t[ ][ ][ ]>::type;
              TS_ASSERT(std::is_same<uint16_t, test_type>::value);
            }
              
            {
              using test_type = std::remove_all_extends<uint32_t[ ]>::type;
              TS_ASSERT(std::is_same<uint32_t, test_type>::value);
            }
              
            {
              using test_type = std::remove_all_extends<int[ ][ ]>::type;
              TS_ASSERT(std::is_same<int, test_type>::value);
            }
              
	}
};

#endif
