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
/// @brief Draminit utility procedures unit tests
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP FW Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: CI

#include <fapi2.H>
#include <generic/memory/tests/target_fixture.H>

#include <generic/memory/lib/utils/find.H>

#include <lib/phy/ody_draminit_utils.H>
#include <ody_scom_mp_apbonly0.H>
#include <ody_scom_mp_mastr_b0.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <lib/phy/ody_draminit_utils.H>



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

    GIVEN("SMBus to RCW decoding")
    {
        const fapi2::buffer<uint64_t> l_data(0xffffffff12345678);
        const mss::ody::phy::rcw_id l_rcw_info(l_data);
        REQUIRE(l_rcw_info.iv_channel_id == 0x01);
        REQUIRE(l_rcw_info.iv_dimm_id == 0x02);
        REQUIRE(l_rcw_info.iv_rcw_id == 0x34);
        REQUIRE(l_rcw_info.iv_rcw_page == 0x56);
        REQUIRE(l_rcw_info.iv_rcw_val == 0x78);
    }

    GIVEN("Calculate image end addr")
    {
        REQUIRE(mss::ody::phy::calculate_image_end_addr(0x50000, 65536) == 0x57fff);
        REQUIRE(mss::ody::phy::calculate_image_end_addr(0x50000, 6553) == 0x50CCC);
        REQUIRE(mss::ody::phy::calculate_image_end_addr(0x50000, 66000) == 0x580E7);
        REQUIRE(mss::ody::phy::calculate_image_end_addr(0x50000, 1) == 0x50000);
        REQUIRE(mss::ody::phy::calculate_image_end_addr(0x50000, 2) == 0x50000);
        REQUIRE(mss::ody::phy::calculate_image_end_addr(0x50000, 3) == 0x50001);

        REQUIRE(mss::ody::phy::calculate_image_end_addr(0x58000, 65536) == 0x5ffff);
        REQUIRE(mss::ody::phy::calculate_image_end_addr(0x58000, 6553) == 0x58CCC);
        REQUIRE(mss::ody::phy::calculate_image_end_addr(0x58000, 66000) == 0x600E7);
        REQUIRE(mss::ody::phy::calculate_image_end_addr(0x58000, 1) == 0x58000);
        REQUIRE(mss::ody::phy::calculate_image_end_addr(0x58000, 2) == 0x58000);
        REQUIRE(mss::ody::phy::calculate_image_end_addr(0x58000, 3) == 0x58001);

    }

    GIVEN("Testing the NULL pointer in load_mem_bin_data()")
    {
        FAPI_INF("Testing NULL pointer for DMEM/IMEM image data");

        // Loops over OCMB chip targets that were defined in the associated config
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
        {
            REQUIRE_SPECIFIC_RC_FAIL(mss::ody::phy::load_mem_bin_data(i_target, 0x58000, NULL, 0x400, 0x8000),
                                     fapi2::RC_ODY_DRAMINIT_START_DATA_PTR_NULL);
            REQUIRE_SPECIFIC_RC_FAIL(mss::ody::phy::load_mem_bin_data(i_target, 0x50000, NULL, 0x400, 0x8000),
                                     fapi2::RC_ODY_DRAMINIT_START_DATA_PTR_NULL);

            return 0;
        });
    }

    GIVEN("Testing out of bounds check in load_dmem_helper()")
    {
        FAPI_INF("Testing out of bounds check for dmem image data");

        // Loops over OCMB chip targets that were defined in the associated config
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
        {
            uint8_t l_dmem_image_data[] = {0x12, 0x34, 0x56, 0x78, 0x9a};

            REQUIRE_SPECIFIC_RC_FAIL(mss::ody::phy::ody_load_dmem_helper(i_target, l_dmem_image_data, 0x5, 0xFFFE),
                                     fapi2::RC_ODY_DRAMINIT_MEM_ADDR_RANGE_OUT_OF_BOUNDS);
            REQUIRE_SPECIFIC_RC_FAIL(mss::ody::phy::ody_load_dmem_helper(i_target, l_dmem_image_data, 0x10001, 0),
                                     fapi2::RC_ODY_DRAMINIT_MEM_ADDR_RANGE_OUT_OF_BOUNDS);


            return 0;
        });
    }

    GIVEN("Testing pass case scenario for load_dmem_helper()")
    {
        FAPI_INF("Testing passing scenario for DMEM image data");
        // Loops over OCMB chip targets that were defined in the associated config
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
        {
            uint8_t l_dmem_image_data[0x10000] = {};

            REQUIRE_RC_PASS(mss::ody::phy::ody_load_dmem_helper(i_target, l_dmem_image_data, 0x10000, 0));
            REQUIRE_RC_PASS(mss::ody::phy::ody_load_dmem_helper(i_target, l_dmem_image_data, 0x8000, 0x8000));

            return 0;
        });
    }


    GIVEN("Testing odd offset check in load_dmem_helper()")
    {
        FAPI_INF("Testing offset check for DMEM image data");

        // Loops over OCMB chip targets that were defined in the associated config
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
        {
            REQUIRE_SPECIFIC_RC_FAIL(mss::ody::phy::ody_load_dmem_helper(i_target, NULL, 0x10000, 1),
                                     fapi2::RC_ODY_DRAMINIT_OFFSET_UNSUPPORTED);
            return 0;
        });
    }

    GIVEN("Testing out of bounds check in load_imem_helper()")
    {
        FAPI_INF("Testing out of bounds check for imem image data");

        // Loops over OCMB chip targets that were defined in the associated config
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
        {
            uint8_t l_imem_image_data[] = {0x12, 0x34, 0x56, 0x78, 0x9a};

            REQUIRE_SPECIFIC_RC_FAIL(mss::ody::phy::ody_load_imem_helper(i_target, l_imem_image_data, 0x5, 0xFFFE),
                                     fapi2::RC_ODY_DRAMINIT_MEM_ADDR_RANGE_OUT_OF_BOUNDS);
            REQUIRE_SPECIFIC_RC_FAIL(mss::ody::phy::ody_load_imem_helper(i_target, l_imem_image_data, 0x10001, 0),
                                     fapi2::RC_ODY_DRAMINIT_MEM_ADDR_RANGE_OUT_OF_BOUNDS);


            return 0;
        });
    }

    GIVEN("Testing pass case scenario for load_imem_helper()")
    {
        FAPI_INF("Testing pass scenario for imem image data");

        // Loops over OCMB chip targets that were defined in the associated config
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
        {
            uint8_t l_imem_image_data[0x10000] = {};

            REQUIRE_RC_PASS(mss::ody::phy::ody_load_imem_helper(i_target, l_imem_image_data, 0x10000, 0));
            REQUIRE_RC_PASS(mss::ody::phy::ody_load_imem_helper(i_target, l_imem_image_data, 0x8000, 0x8000));

            return 0;
        });
    }


    GIVEN("Testing odd offset check in load_imem_helper()")
    {
        FAPI_INF("Testing offset check for imem image data");

        // Loops over OCMB chip targets that were defined in the associated config
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
        {
            REQUIRE_SPECIFIC_RC_FAIL(mss::ody::phy::ody_load_imem_helper(i_target, NULL, 0x10000, 1),
                                     fapi2::RC_ODY_DRAMINIT_OFFSET_UNSUPPORTED);
            return 0;
        });
    }
}// scenario

} // end ns test
} // end ns mss
