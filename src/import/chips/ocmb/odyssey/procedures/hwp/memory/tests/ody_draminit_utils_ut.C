/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/tests/ody_draminit_utils_ut.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
/// @file ody_draminit_utils_ut.C
/// @brief Draminit utility unit tests
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP FW Owner: Geetha Pisipati <Geetha.Pisapati@ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: CI

#include <fapi2.H>
#include <generic/memory/tests/target_fixture.H>

#include <generic/memory/lib/utils/find.H>

#include <lib/phy/ody_draminit_utils.H>
#include <ody_scom_mp_apbonly0.H>
#include <ody_scom_mp_mastr_b0.H>


namespace mss
{
namespace test
{

SCENARIO_METHOD(ocmb_chip_target_test_fixture, "DRAMINIT utility unit tests", "[draminit_utils]")
{
    GIVEN("Tests utils")
    {
        // Loops over OCMB chip targets that were defined in the associated config
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
        {
            for(const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
            {
                // Injects bad values
                static const fapi2::buffer<uint64_t> INJECT(0x1234);
                REQUIRE_RC_PASS(fapi2::putScom(l_port, scomt::mp::DWC_DDRPHYA_APBONLY0_MICROCONTMUXSEL, 0));
                REQUIRE_RC_PASS(fapi2::putScom(l_port, scomt::mp::DWC_DDRPHYA_APBONLY0_MICRORESET, INJECT));
                REQUIRE_RC_PASS(fapi2::putScom(l_port, scomt::mp::DWC_DDRPHYA_MASTER0_BASE0_CALZAP, INJECT));

                REQUIRE_RC_PASS(mss::ody::phy::start_training(l_port));
                fapi2::buffer<uint64_t> l_data;
                REQUIRE_RC_PASS(fapi2::getScom(l_port, scomt::mp::DWC_DDRPHYA_APBONLY0_MICROCONTMUXSEL, l_data));
                REQUIRE(l_data == 1); // scom access set to training only
                REQUIRE_RC_PASS(fapi2::getScom(l_port, scomt::mp::DWC_DDRPHYA_APBONLY0_MICRORESET, l_data));
                REQUIRE(l_data == 0); // ARC processor running

                REQUIRE_RC_PASS(mss::ody::phy::stall_arc_processor(l_port));
                REQUIRE_RC_PASS(fapi2::getScom(l_port, scomt::mp::DWC_DDRPHYA_APBONLY0_MICRORESET, l_data));
                REQUIRE(l_data == 1); // ARC processor stalled

                REQUIRE_RC_PASS(fapi2::putScom(l_port, scomt::mp::DWC_DDRPHYA_APBONLY0_MICRORESET, INJECT));
                REQUIRE_RC_PASS(mss::ody::phy::cleanup_training(l_port));
                REQUIRE_RC_PASS(fapi2::getScom(l_port, scomt::mp::DWC_DDRPHYA_APBONLY0_MICRORESET, l_data));
                REQUIRE(l_data == 1); // ARC processor stalled
                REQUIRE_RC_PASS(fapi2::getScom(l_port, scomt::mp::DWC_DDRPHYA_MASTER0_BASE0_CALZAP, l_data));
                REQUIRE(l_data == 1); // Calibration engines Zap'ed!
            }

            return 0;
        });
    }

} // scenario

} // end ns test
} // end ns mss
