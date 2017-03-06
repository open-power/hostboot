/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/tests/mss_example_ut.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file mss_freq_ut.C
/// @brief Unit tests for mss_freq
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

using fapi2::TARGET_TYPE_MEMBUF_CHIP;
using fapi2::TARGET_TYPE_MBA;
using fapi2::TARGET_TYPE_DIMM;

namespace mss
{
namespace test
{

///
/// @brief Unit test cases for eff_config
/// @param[in] test_fixture
/// @param[in] description
/// @param[in] tag
/// @return void
/// @note mcbist_target_test_fixture is the fixture to use with this test case
///
SCENARIO_METHOD(mba_target_test_fixture, "Example test case", "[test]")
{
    GIVEN("Example test")
    {
        //Loops over MCBIST targets that were defined in the associated config
        for_each_target([](const fapi2::Target<TARGET_TYPE_MBA>& i_target)
        {
            FAPI_INF("%s", mss::c_str(i_target) );
            REQUIRE( 0 == 0 );
            REQUIRE( 0 != 1 );

            return 0;
        }); //for_each
    } // GIVEN


}// scenario

} // ns test
} // ns mss
