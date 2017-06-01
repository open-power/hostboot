/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/tests/cen_mem_size_ut.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
///
/// @file cen_mem_size_ut.C
/// @brief Unit tests for memory size utilities
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 4
// *HWP Consumed by: CI

#include <cstdarg>
#include <fapi2.H>
#include <catch.hpp>
#include <target_fixture.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/memory_size.H>
#include <lib/shared/dimmConsts.H>

using fapi2::TARGET_TYPE_MEMBUF_CHIP;
using fapi2::TARGET_TYPE_MBA;
using fapi2::TARGET_TYPE_DIMM;

namespace mss
{
namespace test
{

///
/// @brief Unit test cases for core utility API
/// @param[in] test_fixture
/// @param[in] description
/// @param[in] tag
/// @return void
/// @note mba_target_test_fixture is the fixture to use with this test case
///
SCENARIO_METHOD(mba_target_test_fixture, "memory_size API testing", "[size]")
{
    FAPI_INF("Test is_dimm_functional API")
    {
        // Case where all DIMMs under and MBA should be functional
        {
            constexpr uint8_t VALID_DIMM_BITMAP = 0xCC;

            for( size_t p = 0; p < MAX_PORTS_PER_MBA; ++p)
            {
                for( size_t d = 0; d < MAX_DIMM_PER_PORT; ++d)
                {
                    FAPI_INF("Testing all case where all DIMM are functional");
                    REQUIRE( is_dimm_functional(VALID_DIMM_BITMAP, p, d) );
                }// port
            }// dimm
        }

        // Case where PORT 0 DIMM 0 and PORT1 DIMM1 is invalid
        // All others are valid
        {
            constexpr uint8_t VALID_DIMM_BITMAP = 0x48;

            // Testing all  port/dimm positions
            FAPI_INF("Testing case wher PORT 0 DIMM 0 and PORT1 DIMM1 are invalid");
            REQUIRE_FALSE( is_dimm_functional(VALID_DIMM_BITMAP, 0, 0) );
            REQUIRE( is_dimm_functional(VALID_DIMM_BITMAP, 0, 1) );
            REQUIRE( is_dimm_functional(VALID_DIMM_BITMAP, 1, 0) );
            REQUIRE_FALSE( is_dimm_functional(VALID_DIMM_BITMAP, 1, 1) );
        }

        // All dimms are invalid
        {
            constexpr uint8_t VALID_DIMM_BITMAP = 0x00;

            // Testing all  port/dimm positions
            FAPI_INF("Testing all case where all DIMM are NOT functional");
            REQUIRE_FALSE( is_dimm_functional(VALID_DIMM_BITMAP, 0, 0) );
            REQUIRE_FALSE( is_dimm_functional(VALID_DIMM_BITMAP, 0, 1) );
            REQUIRE_FALSE( is_dimm_functional(VALID_DIMM_BITMAP, 1, 0) );
            REQUIRE_FALSE( is_dimm_functional(VALID_DIMM_BITMAP, 1, 1) );
        }

    }

    //Loops over MBA targets that were defined in the associated config
    FAPI_INF("Test eff_memory_size API")
    {
        for_each_target([](const fapi2::Target<TARGET_TYPE_MBA>& i_target)
        {
            uint64_t l_out = 0;
            const auto l_dmi(mss::find_target<fapi2::TARGET_TYPE_DMI>(i_target));

            REQUIRE( fapi2::FAPI2_RC_SUCCESS == uint64_t(eff_memory_size(l_dmi, l_out)) );

            // One Centaur per DMI, 2 MBAs per Centaur, 4 DIMMs per MBA, each size 8GB
            REQUIRE( 64 == l_out );
            return 0;
        }); //for_each
    }
}// scenario

} // ns test
} // ns mss
