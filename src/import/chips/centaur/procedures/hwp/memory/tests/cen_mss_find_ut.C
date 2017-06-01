/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/tests/cen_mss_find_ut.C $ */
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
/// @file cen_mss_utils_ut.C
/// @brief Unit tests for core utilities
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
SCENARIO_METHOD(mba_target_test_fixture, "cen find API testing", "[find]")
{
    //Loops over MBA targets that were defined in the associated config
    for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        FAPI_INF("Test find API - Find PROC_CHIP for a MBA");
        {
            const auto l_find_proc_chip(mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target));

            const auto l_proc_chip(i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>()
                                   .getParent<fapi2::TARGET_TYPE_DMI>()
                                   .getParent<fapi2::TARGET_TYPE_PROC_CHIP>());

            REQUIRE( l_find_proc_chip == l_proc_chip );
        }

        FAPI_INF("Test find API - Find DMI for a MBA");
        {
            const auto l_find_dmi(mss::find_target<fapi2::TARGET_TYPE_DMI>(i_target));

            const auto l_dmi(i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>()
                             .getParent<fapi2::TARGET_TYPE_DMI>());

            REQUIRE( l_find_dmi == l_dmi );
        }

        FAPI_INF("Test find API - Find DMI for a MEMBUF_CHIP");
        {
            const auto l_membuf_chip(mss::find_target<fapi2::TARGET_TYPE_MEMBUF_CHIP>(i_target));

            const auto l_find_dmi(mss::find_target<fapi2::TARGET_TYPE_DMI>(l_membuf_chip));
            const auto l_dmi(l_membuf_chip.getParent<fapi2::TARGET_TYPE_DMI>());

            REQUIRE( l_find_dmi == l_dmi );
        }

        FAPI_INF("Test find API - Find PROC_CHIP for a MEMBUF_CHIP");
        {
            const auto l_membuf_chip(mss::find_target<fapi2::TARGET_TYPE_MEMBUF_CHIP>(i_target));

            const auto l_find_proc_chip(mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(l_membuf_chip));
            const auto l_proc_chip( l_membuf_chip.getParent<fapi2::TARGET_TYPE_DMI>()
                                    .getParent<fapi2::TARGET_TYPE_PROC_CHIP>() );

            REQUIRE( l_find_proc_chip == l_proc_chip );
        }

        FAPI_INF("Test find API - DMI under a PROC_CHIP");
        {
            const auto l_proc_chip(mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target));

            const auto l_dmi_children(l_proc_chip.getChildren<fapi2::TARGET_TYPE_DMI>());
            const auto l_find_dmi_children(mss::find_targets<fapi2::TARGET_TYPE_DMI>(l_proc_chip));

            REQUIRE(l_dmi_children == l_find_dmi_children);
        }

        FAPI_INF("Test find API - MEMBUF under a DMI");
        {
            const auto l_dmi(mss::find_target<fapi2::TARGET_TYPE_DMI>(i_target));

            const auto l_membuf_chip(l_dmi.getChildren<fapi2::TARGET_TYPE_MEMBUF_CHIP>());
            const auto l_find_membuf_chip(mss::find_targets<fapi2::TARGET_TYPE_MEMBUF_CHIP>(l_dmi));

            REQUIRE(l_membuf_chip == l_find_membuf_chip);
        }

        FAPI_INF("Test find API - MBAs under a MEMBUF");
        {
            const auto l_membuf_chip(mss::find_target<fapi2::TARGET_TYPE_MEMBUF_CHIP>(i_target));

            const auto l_mba(l_membuf_chip.getChildren<fapi2::TARGET_TYPE_MBA>());
            const auto l_find_mba(mss::find_targets<fapi2::TARGET_TYPE_MBA>(l_membuf_chip));

            REQUIRE(l_mba == l_find_mba);
        }

        FAPI_INF("Test find all the MBAs connected to a DMI")
        {
            // target_fixture is at a membuf but we to test against a parent target
            const auto l_dmi(mss::find_target<fapi2::TARGET_TYPE_DMI>(i_target));

            // lets get all MEMBUFs under the parent DMI
            const auto l_find_membuf_chip_list(mss::find_targets<fapi2::TARGET_TYPE_MEMBUF_CHIP>(l_dmi));

            for (const auto& membuf : l_find_membuf_chip_list)
            {
                const auto l_find_mba_list(mss::find_targets<fapi2::TARGET_TYPE_MBA>(membuf));
                const auto l_children_mba_list(membuf.getChildren<fapi2::TARGET_TYPE_MBA>());

                REQUIRE( l_find_mba_list == l_children_mba_list );
            }

        }

        return 0;
    }); //for_each

}// scenario

} // ns test
} // ns mss
