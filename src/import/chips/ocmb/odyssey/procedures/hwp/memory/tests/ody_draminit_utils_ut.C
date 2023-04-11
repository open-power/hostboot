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

#include <lib/phy/ody_phy_utils.H>
#include <lib/phy/ody_draminit_utils.H>
#include <ody_scom_mp_apbonly0.H>
#include <ody_scom_mp_mastr_b0.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <lib/phy/ody_draminit_utils.H>
#include <lib/shared/ody_consts.H>
#include <mss_generic_attribute_getters.H>
#include <mss_generic_attribute_setters.H>
#include <mss_odyssey_attribute_getters.H>
#include <mss_odyssey_attribute_setters.H>

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
                REQUIRE(l_data == 0); // Calibration engines un-Zap'ed!
                REQUIRE_RC_PASS(fapi2::getScom(l_port, scomt::mp::DWC_DDRPHYA_APBONLY0_MICROCONTMUXSEL, l_data));
                REQUIRE(l_data == 0); // scom access set to on
            }

            return 0;
        });
    }

    GIVEN("Testing skip_this_step")
    {
        // Don't skip anything
        REQUIRE_FALSE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_LOAD_IMEM, 0xFF));
        REQUIRE_FALSE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_LOAD_DMEM, 0xFF));
        REQUIRE_FALSE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_LOAD_MSG_BLOCK, 0xFF));
        REQUIRE_FALSE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_RUN_TRAINING, 0xFF));
        REQUIRE_FALSE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_LOAD_PIE, 0xFF));

        // Skip load_imem and load_msg_block
        REQUIRE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_LOAD_IMEM, 0x5F));
        REQUIRE_FALSE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_LOAD_DMEM, 0x5F));
        REQUIRE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_LOAD_MSG_BLOCK, 0x5F));
        REQUIRE_FALSE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_RUN_TRAINING, 0x5F));
        REQUIRE_FALSE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_LOAD_PIE, 0x5F));

        // Skip load_dmem and run_training
        REQUIRE_FALSE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_LOAD_IMEM, 0xAF));
        REQUIRE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_LOAD_DMEM, 0xAF));
        REQUIRE_FALSE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_LOAD_MSG_BLOCK, 0xAF));
        REQUIRE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_RUN_TRAINING, 0xAF));
        REQUIRE_FALSE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_LOAD_PIE, 0xAF));

        // Skip load_pie
        REQUIRE_FALSE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_LOAD_IMEM, 0xF7));
        REQUIRE_FALSE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_LOAD_DMEM, 0xF7));
        REQUIRE_FALSE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_LOAD_MSG_BLOCK, 0xF7));
        REQUIRE_FALSE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_RUN_TRAINING, 0xF7));
        REQUIRE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_LOAD_PIE, 0xF7));

        // Skip all
        REQUIRE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_LOAD_IMEM, 0x00));
        REQUIRE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_LOAD_DMEM, 0x00));
        REQUIRE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_LOAD_MSG_BLOCK, 0x00));
        REQUIRE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_RUN_TRAINING, 0x00));
        REQUIRE(mss::ody::skip_this_step(fapi2::ENUM_ATTR_ODY_DRAMINIT_STEP_ENABLE_LOAD_PIE, 0x00));

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
            REQUIRE_SPECIFIC_RC_FAIL(mss::ody::phy::load_mem_bin_data(i_target, fapi2::ENUM_ATTR_ODY_DMEM_FIRST_LOAD_YES, 0x58000,
                                     NULL, 0x400, 0x8000),
                                     fapi2::RC_ODY_DRAMINIT_START_DATA_PTR_NULL);
            REQUIRE_SPECIFIC_RC_FAIL(mss::ody::phy::load_mem_bin_data(i_target, fapi2::ENUM_ATTR_ODY_DMEM_FIRST_LOAD_YES, 0x50000,
                                     NULL, 0x400, 0x8000),
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

            REQUIRE_SPECIFIC_RC_FAIL(mss::ody::phy::ody_load_dmem_helper(i_target, l_dmem_image_data, 0x5, 0xFFFc),
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

            // Skips zero data writes
            // This is safe to do for this UT as the code checking the in bounds cases for the mem data size is at the start of the function
            for(const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
            {
                REQUIRE_RC_PASS(mss::attr::set_ody_dmem_first_load(l_port, fapi2::ENUM_ATTR_ODY_DMEM_FIRST_LOAD_YES));
            }

            uint8_t l_dmem_image_data[0x10000] = {};

            REQUIRE_RC_PASS(mss::ody::phy::ody_load_dmem_helper(i_target, l_dmem_image_data, 0x10000, 0));
            REQUIRE_RC_PASS(mss::ody::phy::ody_load_dmem_helper(i_target, l_dmem_image_data, 0x8000, 0x8000));

            return 0;
        });
    }


    GIVEN("Tests register values for load_dmem_helper()")
    {
        FAPI_INF("Testing passing scenario for DMEM image data");
        // Loops over OCMB chip targets that were defined in the associated config
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
        {
            uint8_t l_dmem_image_data[8] =
            {
                0x00, 0x00, 0x00, 0x00, // zero load will be skipped the first time
                0x01, 0x02, 0x03, 0x04, // non-zero load will always go through
            };

            // Does register injects
            for(const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
            {
                REQUIRE_RC_PASS(fapi2::putScom(l_port, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58000), 0xffff));
                REQUIRE_RC_PASS(fapi2::putScom(l_port, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58001), 0xffff));
                REQUIRE_RC_PASS(fapi2::putScom(l_port, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58002), 0xffff));
                REQUIRE_RC_PASS(fapi2::putScom(l_port, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58003), 0xffff));
            }

            // Skips zero data writes for the first load
            for(const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
            {
                REQUIRE_RC_PASS(mss::attr::set_ody_dmem_first_load(l_port, fapi2::ENUM_ATTR_ODY_DMEM_FIRST_LOAD_YES));
            }

            REQUIRE_RC_PASS(mss::ody::phy::ody_load_dmem_helper(i_target, l_dmem_image_data, 8, 0));

            for(const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
            {
                fapi2::buffer<uint64_t> l_data;
                REQUIRE_RC_PASS(fapi2::getScom(l_port, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58000), l_data));
                REQUIRE(l_data == 0xffff); // no change as the address was not written
                REQUIRE_RC_PASS(fapi2::getScom(l_port, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58001), l_data));
                REQUIRE(l_data == 0xffff); // no change as the address was not written
                REQUIRE_RC_PASS(fapi2::getScom(l_port, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58002), l_data));
                REQUIRE(l_data == 0x0201);
                REQUIRE_RC_PASS(fapi2::getScom(l_port, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58003), l_data));
                REQUIRE(l_data == 0x0403);
            }

            // Runs zero writes for subsequent loads
            for(const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
            {
                REQUIRE_RC_PASS(mss::attr::set_ody_dmem_first_load(l_port, fapi2::ENUM_ATTR_ODY_DMEM_FIRST_LOAD_NO));
            }

            REQUIRE_RC_PASS(mss::ody::phy::ody_load_dmem_helper(i_target, l_dmem_image_data, 8, 0));

            for(const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
            {
                fapi2::buffer<uint64_t> l_data;
                REQUIRE_RC_PASS(fapi2::getScom(l_port, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58000), l_data));
                REQUIRE(l_data == 0x0000); // no change as the address was not written
                REQUIRE_RC_PASS(fapi2::getScom(l_port, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58001), l_data));
                REQUIRE(l_data == 0x0000); // no change as the address was not written
                REQUIRE_RC_PASS(fapi2::getScom(l_port, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58002), l_data));
                REQUIRE(l_data == 0x0201);
                REQUIRE_RC_PASS(fapi2::getScom(l_port, mss::ody::phy::convert_synopsys_to_ibm_reg_addr(0x58003), l_data));
                REQUIRE(l_data == 0x0403);
            }

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

    SECTION("Test message block config")
    {
        // Loops over OCMB chip targets that were defined in the associated config
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
        {
            for(const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
            {
                if (mss::count_dimm(l_port) == 0)
                {
                    continue;
                }

                GIVEN("Test configure_dram_train_message_block");
                {
                    // Save attribute values
                    uint8_t l_supported_rcd_save[mss::ody::MAX_DIMM_PER_PORT] = {0};
                    uint8_t l_supported_rcd_test[mss::ody::MAX_DIMM_PER_PORT] = {0};
                    uint8_t l_AdvTrainOpt_save = 0;
                    uint8_t l_MsgMisc_save = 0;
                    uint8_t l_PllBypassEn_save = 0;
                    uint64_t l_DRAMFreq_save = 0;
                    //uint8_t l_RCW05_next_save = 0;
                    //uint8_t l_RCW06_next_save = 0;
                    uint8_t l_RXEN_ADJ_save = 0;
                    uint8_t l_RX2D_DFE_Misc_save = 0;
                    uint8_t l_PhyVref_save = 0;
                    uint8_t l_D5Misc_save = 0;
                    uint8_t l_WL_ADJ_save = 0;
                    uint16_t l_SequenceCtrl_save = 0;
                    uint8_t l_HdtCtrl_save = 0;
                    uint8_t l_PhyCfg_save = 0;
                    uint8_t l_DFIMRLMargin_save = 0;
                    uint8_t l_UseBroadcastMR_save = 0;
                    uint8_t l_DisabledDbyte_save = 0;
                    uint8_t l_CATrainOpt_save = 0;
                    uint8_t l_TX2D_DFE_Misc_save = 0;
                    uint8_t l_RX2D_TrainOpt_save = 0;
                    uint8_t l_TX2D_TrainOpt_save = 0;
                    uint16_t l_PhyConfigOverride_save = 0;
                    uint8_t l_EnabledDQsChA_save = 0;
                    uint8_t l_EnabledDQsChB_save = 0;
                    uint8_t l_CsPresent_save[mss::ody::MAX_DIMM_PER_PORT] = {0};
                    uint8_t l_CsPresent_test[mss::ody::MAX_DIMM_PER_PORT] = {0};
                    uint8_t l_cas_latency_save = 0;
                    uint8_t l_burst_length_save = 0;
                    uint8_t l_2n_mode_save = 0;
                    uint8_t l_mpsm_save = 0;
                    uint8_t l_cs_during_mpc_save = 0;
                    uint8_t l_device15_mpsm_save = 0;
                    uint8_t l_internal_wr_timing_save = 0;
                    uint8_t l_wr_lvl_internal_lower_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][mss::ody::MAX_NIBBLES_PER_PORT]
                        = {0};
                    uint8_t l_wr_lvl_internal_lower_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][mss::ody::MAX_NIBBLES_PER_PORT]
                        = {0};
                    uint8_t l_min_refresh_rate_save = 0;
                    uint8_t l_wide_range_save = 0;
                    uint8_t l_tuf_save = 0;
                    uint8_t l_refresh_interval_rate_save = 0;
                    uint8_t l_pu_drv_imp_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    uint8_t l_pu_drv_imp_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    uint8_t l_drv_test_mode_supported_save = 0;
                    uint8_t l_pd_drv_imp_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    uint8_t l_pd_drv_imp_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    uint8_t l_wr_recovery_save = 0;
                    uint8_t l_trtp_save = 0;
                    uint16_t l_ck_odt_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][2] = {0};
                    uint16_t l_ck_odt_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][2] = {0};
                    uint16_t l_cs_odt_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][2] = {0};
                    uint16_t l_cs_odt_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][2] = {0};
                    uint8_t l_rd_preamble_save = 0;
                    uint8_t l_wr_preamble_save = 0;
                    uint8_t l_rd_postamble_save = 0;
                    uint8_t l_wr_postamble_save = 0;
                    uint8_t l_vrefdq_value_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][mss::ody::MAX_NIBBLES_PER_PORT] = {0};
                    uint8_t l_vrefdq_value_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][mss::ody::MAX_NIBBLES_PER_PORT] = {0};
                    uint8_t l_vrefca_value_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][mss::ody::MAX_NIBBLES_PER_PORT] = {0};
                    uint8_t l_vrefca_value_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][mss::ody::MAX_NIBBLES_PER_PORT] = {0};
                    uint8_t l_vrefcs_value_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][mss::ody::MAX_NIBBLES_PER_PORT] = {0};
                    uint8_t l_vrefcs_value_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][mss::ody::MAX_NIBBLES_PER_PORT] = {0};
                    uint8_t l_tccd_l_save = 0;
                    uint8_t l_ecs_mode_save = 0;
                    uint8_t l_ecs_reset_save = 0;
                    uint8_t l_row_count_save = 0;
                    uint8_t l_ecs_reg_index_save = 0;
                    uint8_t l_ecs_err_threshold_save = 0;
                    uint8_t l_ecs_in_str_save = 0;
                    uint8_t l_ecs_writeback_save = 0;
                    uint8_t l_x4_writes_save = 0;
                    uint8_t l_global_dfe_gain_enable_save = 0;
                    uint8_t l_global_dfe1_enable_save = 0;
                    uint8_t l_global_dfe2_enable_save = 0;
                    uint8_t l_global_dfe3_enable_save = 0;
                    uint8_t l_global_dfe4_enable_save = 0;
                    uint16_t l_ca_odt_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][2] = {0};
                    uint16_t l_ca_odt_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][2] = {0};
                    uint8_t l_dqs_rtt_park_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][2] = {0};
                    uint8_t l_dqs_rtt_park_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][2] = {0};
                    uint8_t l_rtt_park_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][mss::ddr5::mr::ATTR_NUM_CHANNELS] = {0};
                    uint8_t l_rtt_park_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][mss::ddr5::mr::ATTR_NUM_CHANNELS] = {0};
                    uint8_t l_rtt_wr_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][mss::ddr5::mr::ATTR_NUM_CHANNELS] = {0};
                    uint8_t l_rtt_wr_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][mss::ddr5::mr::ATTR_NUM_CHANNELS] = {0};
                    uint8_t l_rtt_nom_wr_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][mss::ddr5::mr::ATTR_NUM_CHANNELS] = {0};
                    uint8_t l_rtt_nom_wr_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][mss::ddr5::mr::ATTR_NUM_CHANNELS] = {0};
                    uint8_t l_rtt_nom_rd_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][mss::ddr5::mr::ATTR_NUM_CHANNELS] = {0};
                    uint8_t l_rtt_nom_rd_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM][mss::ddr5::mr::ATTR_NUM_CHANNELS] = {0};
                    int8_t l_odtlon_wr_offset_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    int8_t l_odtlon_wr_offset_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    int8_t l_odtloff_wr_offset_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    int8_t l_odtloff_wr_offset_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    int8_t l_odtlon_wr_nt_offset_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    int8_t l_odtlon_wr_nt_offset_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    int8_t l_odtloff_wr_nt_offset_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    int8_t l_odtloff_wr_nt_offset_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    int8_t l_odtlon_rd_offset_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    int8_t l_odtlon_rd_offset_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    int8_t l_odtloff_rd_offset_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    int8_t l_odtloff_rd_offset_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    uint8_t l_rd_crc_enable = 0;
                    uint8_t l_wr_crc_enable = 0;
                    uint8_t l_wr_crc_error_status_save = 0;
                    uint8_t l_wr_crc_autodisable_enable_save = 0;
                    uint8_t l_wr_crc_autodisable_status_save = 0;
                    uint8_t l_wr_crc_autodisable_threshold_save = 0;
                    uint8_t l_wr_crc_autodisable_window_save = 0;
                    uint8_t l_dfe_gain_bias_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    uint8_t l_dfe_gain_bias_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    uint8_t l_dfe_sign_bit_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    uint8_t l_dfe_sign_bit_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    uint16_t l_wl_adj_start_save = 0;
                    uint16_t l_wl_adj_end_save = 0;
                    uint8_t l_rtt_park_rd_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    uint8_t l_rtt_park_rd_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    uint8_t l_rtt_park_wr_save[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    uint8_t l_rtt_park_wr_test[mss::ody::MAX_DIMM_PER_PORT][mss::ody::MAX_RANK_PER_DIMM] = {0};
                    uint8_t l_ca_dfe_train_options_save = 0;
                    uint8_t l_debug_train_options_save = 0;
                    uint32_t l_nibbles_enables_save[mss::ody::MAX_DIMM_PER_PORT] = {0};
                    uint32_t l_nibbles_enables_test[mss::ody::MAX_DIMM_PER_PORT] = {0};
                    uint8_t l_redundant_cs_orig[mss::ody::MAX_DIMM_PER_PORT] = {};
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_redundant_cs_en(l_port, l_redundant_cs_orig));

                    REQUIRE_RC_PASS(mss::attr::get_supported_rcd(l_port, l_supported_rcd_save));
                    REQUIRE_RC_PASS(mss::attr::get_supported_rcd(l_port, l_supported_rcd_test));
                    REQUIRE_RC_PASS(mss::attr::get_phy_adv_train_opt(l_port, l_AdvTrainOpt_save));
                    REQUIRE_RC_PASS(mss::attr::get_phy_msg_misc(l_port, l_MsgMisc_save));
                    REQUIRE_RC_PASS(mss::attr::get_phy_pll_bypass_en(l_port, l_PllBypassEn_save));
                    REQUIRE_RC_PASS(mss::attr::get_freq(l_port, l_DRAMFreq_save));

                    // TODO: Zen:MST-1668 RCW05_next and RCW06_next: need to decide how to set these
                    //REQUIRE_RC_PASS(mss::attr::get_rcw05_next(l_port, l_RCW05_next_save));
                    //REQUIRE_RC_PASS(mss::attr::get_rcw06_next(l_port, l_RCW06_next_save));

                    REQUIRE_RC_PASS(mss::attr::get_ddr5_rxen_adj(l_port, l_RXEN_ADJ_save));
                    REQUIRE_RC_PASS(mss::attr::get_phy_rx2d_dfe_misc(l_port, l_RX2D_DFE_Misc_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_phy_vref_rd(l_port, l_PhyVref_save));
                    REQUIRE_RC_PASS(mss::attr::get_phy_d5misc(l_port, l_D5Misc_save));
                    REQUIRE_RC_PASS(mss::attr::get_phy_wl_adj(l_port, l_WL_ADJ_save));
                    REQUIRE_RC_PASS(mss::attr::get_phy_sequence_ctrl(l_port, l_SequenceCtrl_save));
                    REQUIRE_RC_PASS(mss::attr::get_ody_draminit_verbosity(l_port, l_HdtCtrl_save));
                    REQUIRE_RC_PASS(mss::attr::get_phy_cfg(l_port, l_PhyCfg_save));
                    REQUIRE_RC_PASS(mss::attr::get_dfimrl_margin(l_port, l_DFIMRLMargin_save));
                    REQUIRE_RC_PASS(mss::attr::get_phy_use_broadcast_mr(l_port, l_UseBroadcastMR_save));
                    REQUIRE_RC_PASS(mss::attr::get_disabled_dbyte(l_port, l_DisabledDbyte_save));
                    REQUIRE_RC_PASS(mss::attr::get_ca_train_options(l_port, l_CATrainOpt_save));
                    REQUIRE_RC_PASS(mss::attr::get_tx2d_dfe_misc(l_port, l_TX2D_DFE_Misc_save));
                    REQUIRE_RC_PASS(mss::attr::get_rx2d_train_opt(l_port, l_RX2D_TrainOpt_save));
                    REQUIRE_RC_PASS(mss::attr::get_tx2d_train_opt(l_port, l_TX2D_TrainOpt_save));
                    REQUIRE_RC_PASS(mss::attr::get_phy_config_override(l_port, l_PhyConfigOverride_save));
                    REQUIRE_RC_PASS(mss::attr::get_phy_enabled_dq_cha(l_port, l_EnabledDQsChA_save));
                    REQUIRE_RC_PASS(mss::attr::get_phy_enabled_dq_chb(l_port, l_EnabledDQsChB_save));
                    REQUIRE_RC_PASS(mss::attr::get_dimm_ranks_configed(l_port, l_CsPresent_save));
                    REQUIRE_RC_PASS(mss::attr::get_dimm_ranks_configed(l_port, l_CsPresent_test));
                    REQUIRE_RC_PASS(mss::attr::get_dram_cl(l_port, l_cas_latency_save));
                    REQUIRE_RC_PASS(mss::attr::get_burst_length(l_port, l_burst_length_save));
                    REQUIRE_RC_PASS(mss::attr::get_mem_2n_mode(i_target, l_2n_mode_save));
                    REQUIRE_RC_PASS(mss::attr::get_mpsm(l_port, l_mpsm_save));
                    REQUIRE_RC_PASS(mss::attr::get_cs_assert_in_mpc(l_port, l_cs_during_mpc_save));
                    REQUIRE_RC_PASS(mss::attr::get_device15_mpsm(l_port, l_device15_mpsm_save));
                    REQUIRE_RC_PASS(mss::attr::get_internal_wr_timing_mode(l_port, l_internal_wr_timing_save));
                    REQUIRE_RC_PASS(mss::attr::get_wl_internal_cycle_alignment(l_port, l_wr_lvl_internal_lower_save));
                    REQUIRE_RC_PASS(mss::attr::get_wl_internal_cycle_alignment(l_port, l_wr_lvl_internal_lower_test));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_min_ref_rate(l_port, l_min_refresh_rate_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_ref_wide_range(l_port, l_wide_range_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_ref_tuf(l_port, l_tuf_save));
                    REQUIRE_RC_PASS(mss::attr::get_ref_rate_indic(l_port, l_refresh_interval_rate_save));
                    REQUIRE_RC_PASS(mss::attr::get_dram_pu_drv_imp(l_port, l_pu_drv_imp_save));
                    REQUIRE_RC_PASS(mss::attr::get_dram_pu_drv_imp(l_port, l_pu_drv_imp_test));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_test_mode(l_port, l_drv_test_mode_supported_save));
                    REQUIRE_RC_PASS(mss::attr::get_dram_pd_drv_imp(l_port, l_pd_drv_imp_save));
                    REQUIRE_RC_PASS(mss::attr::get_dram_pd_drv_imp(l_port, l_pd_drv_imp_test));
                    REQUIRE_RC_PASS(mss::attr::get_dram_twr(l_port, l_wr_recovery_save));
                    REQUIRE_RC_PASS(mss::attr::get_dram_trtp(l_port, l_trtp_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_ck_odt(l_port, l_ck_odt_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_ck_odt(l_port, l_ck_odt_test));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_cs_odt(l_port, l_cs_odt_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_cs_odt(l_port, l_cs_odt_test));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_rd_preamble(l_port, l_rd_preamble_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_wr_preamble(l_port, l_wr_preamble_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_rd_postamble(l_port, l_rd_postamble_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_wr_postamble(l_port, l_wr_postamble_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_wr_vrefdq(l_port, l_vrefdq_value_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_wr_vrefdq(l_port, l_vrefdq_value_test));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_vrefca(l_port, l_vrefca_value_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_vrefca(l_port, l_vrefca_value_test));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_vrefcs(l_port, l_vrefcs_value_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_vrefcs(l_port, l_vrefcs_value_test));
                    REQUIRE_RC_PASS(mss::attr::get_dram_tccd_l(l_port, l_tccd_l_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_ecs_mode(l_port, l_ecs_mode_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_ecs_reset_counter(l_port, l_ecs_reset_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_ecs_count_mode(l_port, l_row_count_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_ecs_srank_select(l_port, l_ecs_reg_index_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_ecs_threshold_count(l_port, l_ecs_err_threshold_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_ecs_in_self_refresh(l_port, l_ecs_in_str_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_ecs_writeback(l_port, l_ecs_writeback_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_ecs_x4_writes(l_port, l_x4_writes_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_global_dfe_gain(l_port, l_global_dfe_gain_enable_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_global_dfe_tap1(l_port, l_global_dfe1_enable_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_global_dfe_tap2(l_port, l_global_dfe2_enable_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_global_dfe_tap3(l_port, l_global_dfe3_enable_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_global_dfe_tap4(l_port, l_global_dfe4_enable_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_ca_odt(l_port, l_ca_odt_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_ca_odt(l_port, l_ca_odt_test));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_dqs_rtt_park(l_port, l_dqs_rtt_park_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_dqs_rtt_park(l_port, l_dqs_rtt_park_test));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_rtt_park(l_port, l_rtt_park_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_rtt_park(l_port, l_rtt_park_test));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_rtt_wr(l_port, l_rtt_wr_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_rtt_wr(l_port, l_rtt_wr_test));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_rtt_nom_wr(l_port, l_rtt_nom_wr_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_rtt_nom_wr(l_port, l_rtt_nom_wr_test));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_rtt_nom_rd(l_port, l_rtt_nom_rd_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_rtt_nom_rd(l_port, l_rtt_nom_rd_test));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_odtlon_wr(l_port, l_odtlon_wr_offset_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_odtlon_wr(l_port, l_odtlon_wr_offset_test));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_odtloff_wr(l_port, l_odtloff_wr_offset_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_odtloff_wr(l_port, l_odtloff_wr_offset_test));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_odtlon_wr_nt(l_port, l_odtlon_wr_nt_offset_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_odtlon_wr_nt(l_port, l_odtlon_wr_nt_offset_test));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_odtloff_wr_nt(l_port, l_odtloff_wr_nt_offset_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_odtloff_wr_nt(l_port, l_odtloff_wr_nt_offset_test));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_odtlon_rd_nt(l_port, l_odtlon_rd_offset_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_odtlon_rd_nt(l_port, l_odtlon_rd_offset_test));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_odtloff_rd_nt(l_port, l_odtloff_rd_offset_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_odtloff_rd_nt(l_port, l_odtloff_rd_offset_test));
                    REQUIRE_RC_PASS(mss::attr::get_mrw_ddr5_dram_read_crc(l_rd_crc_enable));
                    REQUIRE_RC_PASS(mss::attr::get_mrw_dram_write_crc(l_wr_crc_enable));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_wr_crc_err_status(l_port, l_wr_crc_error_status_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_wr_crc_autodisable_enable(l_port, l_wr_crc_autodisable_enable_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_wr_crc_autodisable_status(l_port, l_wr_crc_autodisable_status_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_wr_crc_autodisable_threshold(l_port, l_wr_crc_autodisable_threshold_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_wr_crc_autodisable_window(l_port, l_wr_crc_autodisable_window_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dfe_gain_bias(l_port, l_dfe_gain_bias_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dfe_gain_bias(l_port, l_dfe_gain_bias_test));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dfe_sign_bit(l_port, l_dfe_sign_bit_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dfe_sign_bit(l_port, l_dfe_sign_bit_test));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_wl_adj_start(l_port, l_wl_adj_start_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_wl_adj_end(l_port, l_wl_adj_end_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_rtt_park_rd(l_port, l_rtt_park_rd_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_rtt_park_rd(l_port, l_rtt_park_rd_test));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_rtt_park_wr(l_port, l_rtt_park_wr_save));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_rtt_park_wr(l_port, l_rtt_park_wr_test));
                    REQUIRE_RC_PASS(mss::attr::get_ca_dfe_train_options(l_port, l_ca_dfe_train_options_save));
                    REQUIRE_RC_PASS(mss::attr::get_debug_train_options(l_port, l_debug_train_options_save));
                    REQUIRE_RC_PASS(mss::attr::get_nibble_enables(l_port, l_nibbles_enables_save));

                    // Setup some attributes
                    l_supported_rcd_test[0] = fapi2::ENUM_ATTR_MEM_EFF_SUPPORTED_RCD_NO_RCD;
                    REQUIRE_RC_PASS(mss::attr::set_supported_rcd(l_port, l_supported_rcd_test));
                    REQUIRE_RC_PASS(mss::attr::set_phy_adv_train_opt(l_port, 0x7));
                    REQUIRE_RC_PASS(mss::attr::set_phy_msg_misc(l_port, 0x5));
                    // Pstate is always zero for Odyssey
                    REQUIRE_RC_PASS(mss::attr::set_phy_pll_bypass_en(l_port, 0x1));
                    REQUIRE_RC_PASS(mss::attr::set_freq(l_port, 3200));

                    // TODO: Zen:MST-1668 RCW05_next and RCW06_next: need to decide how to set these
                    //REQUIRE_RC_PASS(mss::attr::set_rcw05_next(l_port, 0x01));
                    //REQUIRE_RC_PASS(mss::attr::set_rcw06_next(l_port, 0x02));
                    uint8_t l_redundant_cs_disable[mss::ody::MAX_DIMM_PER_PORT] = {fapi2::ENUM_ATTR_MEM_EFF_REDUNDANT_CS_EN_DISABLE, 0};
                    uint8_t l_redundant_cs_enable[mss::ody::MAX_DIMM_PER_PORT] = {fapi2::ENUM_ATTR_MEM_EFF_REDUNDANT_CS_EN_ENABLE, 0};

                    REQUIRE_RC_PASS(mss::attr::set_ddr5_redundant_cs_en(l_port, l_redundant_cs_disable));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_rxen_adj(l_port, 0x03));
                    REQUIRE_RC_PASS(mss::attr::set_phy_rx2d_dfe_misc(l_port, 0x04));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_phy_vref_rd(l_port, 0x05));
                    REQUIRE_RC_PASS(mss::attr::set_phy_d5misc(l_port, 0x06));
                    REQUIRE_RC_PASS(mss::attr::set_phy_wl_adj(l_port, 0x07));
                    REQUIRE_RC_PASS(mss::attr::set_phy_sequence_ctrl(l_port, 0xFFFF));
                    REQUIRE_RC_PASS(mss::attr::set_ody_draminit_verbosity(l_port, 0x08));
                    REQUIRE_RC_PASS(mss::attr::set_phy_cfg(l_port, 0x89));
                    REQUIRE_RC_PASS(mss::attr::set_dfimrl_margin(l_port, 0x0A));
                    REQUIRE_RC_PASS(mss::attr::set_phy_use_broadcast_mr(l_port, 0x0B));
                    REQUIRE_RC_PASS(mss::attr::set_disabled_dbyte(l_port, 0x0C));
                    REQUIRE_RC_PASS(mss::attr::set_ca_train_options(l_port, 0xe3));
                    REQUIRE_RC_PASS(mss::attr::set_tx2d_dfe_misc(l_port, 0x03));
                    REQUIRE_RC_PASS(mss::attr::set_rx2d_train_opt(l_port, 0xF0));
                    REQUIRE_RC_PASS(mss::attr::set_tx2d_train_opt(l_port, 0x84));
                    REQUIRE_RC_PASS(mss::attr::set_phy_config_override(l_port, 0x89AB));
                    REQUIRE_RC_PASS(mss::attr::set_phy_enabled_dq_cha(l_port, 0x0D));
                    REQUIRE_RC_PASS(mss::attr::set_phy_enabled_dq_chb(l_port, 0x00));
                    l_CsPresent_test[0] = 0x80;
                    REQUIRE_RC_PASS(mss::attr::set_dimm_ranks_configed(l_port, l_CsPresent_test));
                    REQUIRE_RC_PASS(mss::attr::set_dram_cl(l_port, 0x22));
                    REQUIRE_RC_PASS(mss::attr::set_burst_length(l_port, 0x02));
                    REQUIRE_RC_PASS(mss::attr::set_mem_2n_mode(i_target, 0x00));
                    REQUIRE_RC_PASS(mss::attr::set_mpsm(l_port, 0x01));
                    REQUIRE_RC_PASS(mss::attr::set_cs_assert_in_mpc(l_port, 0x00));
                    REQUIRE_RC_PASS(mss::attr::set_device15_mpsm(l_port, 0x01));
                    REQUIRE_RC_PASS(mss::attr::set_internal_wr_timing_mode(l_port, 0x00));
                    l_wr_lvl_internal_lower_test[0][0][0] = 0x0B;
                    l_wr_lvl_internal_lower_test[0][0][1] = 0x0C;
                    l_wr_lvl_internal_lower_test[0][0][5] = 0x0D;
                    l_wr_lvl_internal_lower_test[0][0][10] = 0x0E;
                    l_wr_lvl_internal_lower_test[0][1][0] = 0x02;
                    l_wr_lvl_internal_lower_test[0][1][2] = 0x03;
                    l_wr_lvl_internal_lower_test[0][1][6] = 0x04;
                    l_wr_lvl_internal_lower_test[0][1][12] = 0x05;
                    REQUIRE_RC_PASS(mss::attr::set_wl_internal_cycle_alignment(l_port, l_wr_lvl_internal_lower_test));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_min_ref_rate(l_port, 0x04));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_ref_wide_range(l_port, 0x00));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_ref_tuf(l_port, 0x01));
                    REQUIRE_RC_PASS(mss::attr::set_ref_rate_indic(l_port, 0x00));
                    l_pu_drv_imp_test[0][0] = 40;
                    l_pu_drv_imp_test[0][1] = 34;
                    REQUIRE_RC_PASS(mss::attr::set_dram_pu_drv_imp(l_port, l_pu_drv_imp_test));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_test_mode(l_port, 0x01));
                    l_pd_drv_imp_test[0][0] = 48;
                    l_pd_drv_imp_test[0][1] = 34;
                    REQUIRE_RC_PASS(mss::attr::set_dram_pd_drv_imp(l_port, l_pd_drv_imp_test));
                    REQUIRE_RC_PASS(mss::attr::set_dram_twr(l_port, 90));
                    REQUIRE_RC_PASS(mss::attr::set_dram_trtp(l_port, 17));
                    l_ck_odt_test[0][0][0] = 120;
                    l_ck_odt_test[0][1][0] = 240;
                    l_ck_odt_test[0][0][1] = 40;
                    l_ck_odt_test[0][1][1] = 60;
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_ck_odt(l_port, l_ck_odt_test));
                    l_cs_odt_test[0][0][0] = 40;
                    l_cs_odt_test[0][1][0] = 60;
                    l_cs_odt_test[0][0][1] = 80;
                    l_cs_odt_test[0][1][1] = 480;
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_cs_odt(l_port, l_cs_odt_test));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_rd_preamble(l_port, 0x03));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_wr_preamble(l_port, 0x01));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_rd_postamble(l_port, 0x00));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_wr_postamble(l_port, 0x01));
                    l_vrefdq_value_test[0][0][0] = 0x25;
                    l_vrefdq_value_test[0][0][3] = 0x27;
                    l_vrefdq_value_test[0][0][11] = 0x29;
                    l_vrefdq_value_test[0][0][17] = 0x2B;
                    l_vrefdq_value_test[0][1][0] = 0x26;
                    l_vrefdq_value_test[0][1][6] = 0x28;
                    l_vrefdq_value_test[0][1][9] = 0x2A;
                    l_vrefdq_value_test[0][1][18] = 0x2C;
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_wr_vrefdq(l_port, l_vrefdq_value_test));
                    l_vrefca_value_test[0][0][0] = 0x27;
                    l_vrefca_value_test[0][0][5] = 0x29;
                    l_vrefca_value_test[0][0][10] = 0x2B;
                    l_vrefca_value_test[0][0][15] = 0x2D;
                    l_vrefca_value_test[0][1][0] = 0x28;
                    l_vrefca_value_test[0][1][4] = 0x2A;
                    l_vrefca_value_test[0][1][8] = 0x2C;
                    l_vrefca_value_test[0][1][12] = 0x2E;
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_vrefca(l_port, l_vrefca_value_test));
                    l_vrefcs_value_test[0][0][0] = 0x29;
                    l_vrefcs_value_test[0][0][6] = 0x2B;
                    l_vrefcs_value_test[0][0][12] = 0x2D;
                    l_vrefcs_value_test[0][0][18] = 0x2F;
                    l_vrefcs_value_test[0][1][0] = 0x2A;
                    l_vrefcs_value_test[0][1][7] = 0x2C;
                    l_vrefcs_value_test[0][1][14] = 0x2E;
                    l_vrefcs_value_test[0][1][19] = 0x30;
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_vrefcs(l_port, l_vrefcs_value_test));
                    REQUIRE_RC_PASS(mss::attr::set_dram_tccd_l(l_port, 0x0C));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_ecs_mode(l_port, 0x01));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_ecs_reset_counter(l_port, 0x00));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_ecs_count_mode(l_port, 0x01));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_ecs_srank_select(l_port, 0x03));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_ecs_threshold_count(l_port, 0x04));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_ecs_in_self_refresh(l_port, 0x01));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_ecs_writeback(l_port, 0x01));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_ecs_x4_writes(l_port, 0x00));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_global_dfe_gain(l_port, 0x01));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_global_dfe_tap1(l_port, 0x00));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_global_dfe_tap2(l_port, 0x01));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_global_dfe_tap3(l_port, 0x01));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_global_dfe_tap4(l_port, 0x00));
                    l_ca_odt_test[0][0][0] = 120;
                    l_ca_odt_test[0][1][0] = 480;
                    l_ca_odt_test[0][0][1] = 80;
                    l_ca_odt_test[0][1][1] = 240;
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_ca_odt(l_port, l_ca_odt_test));
                    l_dqs_rtt_park_test[0][0][0] = 34;
                    l_dqs_rtt_park_test[0][1][0] = 80;
                    l_dqs_rtt_park_test[0][0][1] = 48;
                    l_dqs_rtt_park_test[0][1][1] = 240;
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_dqs_rtt_park(l_port, l_dqs_rtt_park_test));
                    l_rtt_park_test[0][0][0] = 40;
                    l_rtt_park_test[0][0][1] = 240;
                    l_rtt_park_test[0][1][0] = 48;
                    l_rtt_park_test[0][1][1] = 34;
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_rtt_park(l_port, l_rtt_park_test));
                    l_rtt_wr_test[0][0][0] = 60;
                    l_rtt_wr_test[0][0][1] = 48;
                    l_rtt_wr_test[0][1][0] = 120;
                    l_rtt_wr_test[0][1][1] = 80;
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_rtt_wr(l_port, l_rtt_wr_test));
                    l_rtt_nom_wr_test[0][0][0] = 240;
                    l_rtt_nom_wr_test[0][0][1] = 34;
                    l_rtt_nom_wr_test[0][1][0] = 120;
                    l_rtt_nom_wr_test[0][1][1] = 40;
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_rtt_nom_wr(l_port, l_rtt_nom_wr_test));
                    l_rtt_nom_rd_test[0][0][0] = 48;
                    l_rtt_nom_rd_test[0][0][1] = 60;
                    l_rtt_nom_rd_test[0][1][0] = 120;
                    l_rtt_nom_rd_test[0][1][1] = 80;
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_rtt_nom_rd(l_port, l_rtt_nom_rd_test));
                    l_odtlon_wr_offset_test[0][0] = -4;
                    l_odtlon_wr_offset_test[0][1] = 1;
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_odtlon_wr(l_port, l_odtlon_wr_offset_test));
                    l_odtloff_wr_offset_test[0][0] = 0;
                    l_odtloff_wr_offset_test[0][1] = 4;
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_odtloff_wr(l_port, l_odtloff_wr_offset_test));
                    l_odtlon_wr_nt_offset_test[0][0] = -3;
                    l_odtlon_wr_nt_offset_test[0][1] = 2;
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_odtlon_wr_nt(l_port, l_odtlon_wr_nt_offset_test));
                    l_odtloff_wr_nt_offset_test[0][0] = -1;
                    l_odtloff_wr_nt_offset_test[0][1] = 4;
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_odtloff_wr_nt(l_port, l_odtloff_wr_nt_offset_test));
                    l_odtlon_rd_offset_test[0][0] = -3;
                    l_odtlon_rd_offset_test[0][1] = 0;
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_odtlon_rd_nt(l_port, l_odtlon_rd_offset_test));
                    l_odtloff_rd_offset_test[0][0] = -1;
                    l_odtloff_rd_offset_test[0][1] = 3;
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_odtloff_rd_nt(l_port, l_odtloff_rd_offset_test));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_wr_crc_err_status(l_port, 0x01));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_wr_crc_autodisable_enable(l_port, 0x00));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_wr_crc_autodisable_status(l_port, 0x01));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_wr_crc_autodisable_threshold(l_port, 0x7B));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_wr_crc_autodisable_window(l_port, 0x6C));
                    l_dfe_gain_bias_test[0][0] = 0x03;
                    l_dfe_gain_bias_test[0][1] = 0x02;
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dfe_gain_bias(l_port, l_dfe_gain_bias_test));
                    l_dfe_sign_bit_test[0][0] = 0x01;
                    l_dfe_sign_bit_test[0][1] = 0x00;
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dfe_sign_bit(l_port, l_dfe_sign_bit_test));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_wl_adj_start(l_port, 0x0060));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_wl_adj_end(l_port, 0x00A0));
                    l_rtt_park_rd_test[0][0] = 0x03;
                    l_rtt_park_rd_test[0][1] = 0x04;
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_rtt_park_rd(l_port, l_rtt_park_rd_test));
                    l_rtt_park_wr_test[0][0] = 0x05;
                    l_rtt_park_wr_test[0][1] = 0x06;
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_rtt_park_wr(l_port, l_rtt_park_wr_test));
                    REQUIRE_RC_PASS(mss::attr::set_ca_dfe_train_options(l_port, 0x30));
                    REQUIRE_RC_PASS(mss::attr::set_debug_train_options(l_port, 0x49));
                    l_nibbles_enables_test[0] = 0x00000F00;
                    l_nibbles_enables_test[1] = 0x0;
                    REQUIRE_RC_PASS(mss::attr::set_nibble_enables(l_port, l_nibbles_enables_test));


                    // Test that the message block gets the correct values for sim mode
                    constexpr uint8_t SIM_MODE = 1;
                    PMU_SMB_DDR5U_1D_t l_msg_block;
                    REQUIRE_RC_PASS(mss::ody::phy::configure_dram_train_message_block(l_port, SIM_MODE, l_msg_block));

                    REQUIRE( l_msg_block.AdvTrainOpt == 0x07 );
                    REQUIRE( l_msg_block.MsgMisc == 0x05 );
                    REQUIRE( l_msg_block.Pstate == 0 );
                    REQUIRE( l_msg_block.PllBypassEn == 0x01 );
                    REQUIRE( l_msg_block.DRAMFreq == 3200 );
                    REQUIRE( l_msg_block.RCW05_next == 0x00 );
                    REQUIRE( l_msg_block.RCW06_next == 0x00 );
                    REQUIRE( l_msg_block.RXEN_ADJ == 0x03 );
                    REQUIRE( l_msg_block.RX2D_DFE_Misc == 0x04 );
                    REQUIRE( l_msg_block.PhyVref == 0x05 );
                    REQUIRE( l_msg_block.D5Misc == 0x04 );
                    REQUIRE( l_msg_block.WL_ADJ == 0x07 );
                    REQUIRE( l_msg_block.SequenceCtrl == 0x827F );
                    REQUIRE( l_msg_block.HdtCtrl == 0x08 );
                    REQUIRE( l_msg_block.PhyCfg == 0x09 );
                    REQUIRE( l_msg_block.DFIMRLMargin == 0x0A );
                    REQUIRE( l_msg_block.X16Present == 0x00 );
                    REQUIRE( l_msg_block.UseBroadcastMR == 0x0B );
                    REQUIRE( l_msg_block.D5Quickboot == 0x00 );
                    REQUIRE( l_msg_block.DisabledDbyte == 0x0C );
                    REQUIRE( l_msg_block.CATrainOpt == 0x9C ); // CA13 skip is set
                    REQUIRE( l_msg_block.TX2D_DFE_Misc == 0xFC );
                    REQUIRE( l_msg_block.RX2D_TrainOpt == 0x7E );
                    REQUIRE( l_msg_block.TX2D_TrainOpt == 0x1E );
                    REQUIRE( l_msg_block.Share2DVrefResult == 0x00 );
                    REQUIRE( l_msg_block.MRE_MIN_PULSE == 0x00 );
                    REQUIRE( l_msg_block.DWL_MIN_PULSE == 0x00 );
                    REQUIRE( l_msg_block.PhyConfigOverride == 0x89AB );
                    REQUIRE( l_msg_block.EnabledDQsChA == 0x0D );
                    REQUIRE( l_msg_block.EnabledDQsChB == 0x00 );
                    REQUIRE( l_msg_block.CsPresentChA == 0x01 );
                    REQUIRE( l_msg_block.CsPresentChB == 0x00 );  // Zero'ed out DQ for channel B zeroes out this field
                    REQUIRE( l_msg_block.MR0_A0 == 0x1A );
                    REQUIRE( l_msg_block.MR0_A1 == 0x1A );
                    REQUIRE( l_msg_block.MR0_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR0_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR0_B0 == 0x1A );
                    REQUIRE( l_msg_block.MR0_B1 == 0x1A );
                    REQUIRE( l_msg_block.MR0_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR0_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR2_A0 == 0x28 );
                    REQUIRE( l_msg_block.MR2_A1 == 0x28 );
                    REQUIRE( l_msg_block.MR2_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR2_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR2_B0 == 0x28 );
                    REQUIRE( l_msg_block.MR2_B1 == 0x28 );
                    REQUIRE( l_msg_block.MR2_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR2_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR3_A0 == 0x0B );
                    REQUIRE( l_msg_block.MR3_A1 == 0x02 );
                    REQUIRE( l_msg_block.MR3_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR3_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR3_B0 == 0x0B );
                    REQUIRE( l_msg_block.MR3_B1 == 0x02 );
                    REQUIRE( l_msg_block.MR3_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR3_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR4_A0 == 0x84 );
                    REQUIRE( l_msg_block.MR4_A1 == 0x84 );
                    REQUIRE( l_msg_block.MR4_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR4_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR4_B0 == 0x84 );
                    REQUIRE( l_msg_block.MR4_B1 == 0x84 );
                    REQUIRE( l_msg_block.MR4_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR4_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR5_A0 == 0x8A );
                    REQUIRE( l_msg_block.MR5_A1 == 0x08 );
                    REQUIRE( l_msg_block.MR5_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR5_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR5_B0 == 0x8A );
                    REQUIRE( l_msg_block.MR5_B1 == 0x08 );
                    REQUIRE( l_msg_block.MR5_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR5_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR6_A0 == 0x37 );
                    REQUIRE( l_msg_block.MR6_A1 == 0x37 );
                    REQUIRE( l_msg_block.MR6_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR6_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR6_B0 == 0x37 );
                    REQUIRE( l_msg_block.MR6_B1 == 0x37 );
                    REQUIRE( l_msg_block.MR6_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR6_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR32_A0_next == 0x3B );
                    REQUIRE( l_msg_block.MR32_A1_next == 0x2A );
                    REQUIRE( l_msg_block.MR32_A2_next == 0x00 );
                    REQUIRE( l_msg_block.MR32_A3_next == 0x00 );
                    REQUIRE( l_msg_block.MR32_B0_next == 0x3B );
                    REQUIRE( l_msg_block.MR32_B1_next == 0x2A );
                    REQUIRE( l_msg_block.MR32_B2_next == 0x00 );
                    REQUIRE( l_msg_block.MR32_B3_next == 0x00 );
                    REQUIRE( l_msg_block.MR8_A0 == 0x8B );
                    REQUIRE( l_msg_block.MR8_A1 == 0x8B );
                    REQUIRE( l_msg_block.MR8_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR8_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR8_B0 == 0x8B );
                    REQUIRE( l_msg_block.MR8_B1 == 0x8B );
                    REQUIRE( l_msg_block.MR8_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR8_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR32_ORG_A0_next == 0x67 );
                    REQUIRE( l_msg_block.MR32_ORG_A1_next == 0x4D );
                    REQUIRE( l_msg_block.MR32_ORG_A2_next == 0x00 );
                    REQUIRE( l_msg_block.MR32_ORG_A3_next == 0x00 );
                    REQUIRE( l_msg_block.MR32_ORG_B0_next == 0x67 );
                    REQUIRE( l_msg_block.MR32_ORG_B1_next == 0x4D );
                    REQUIRE( l_msg_block.MR32_ORG_B2_next == 0x00 );
                    REQUIRE( l_msg_block.MR32_ORG_B3_next == 0x00 );
                    REQUIRE( l_msg_block.MR10_A0 == 0x25 );
                    REQUIRE( l_msg_block.MR10_A1 == 0x26 );
                    REQUIRE( l_msg_block.MR10_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR10_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR10_B0 == 0x25 );
                    REQUIRE( l_msg_block.MR10_B1 == 0x26 );
                    REQUIRE( l_msg_block.MR10_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR10_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR11_A0 == 0x27 );
                    REQUIRE( l_msg_block.MR11_A1 == 0x28 );
                    REQUIRE( l_msg_block.MR11_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR11_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR11_B0 == 0x27 );
                    REQUIRE( l_msg_block.MR11_B1 == 0x28 );
                    REQUIRE( l_msg_block.MR11_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR11_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR12_A0 == 0x29 );
                    REQUIRE( l_msg_block.MR12_A1 == 0x2A );
                    REQUIRE( l_msg_block.MR12_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR12_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR12_B0 == 0x29 );
                    REQUIRE( l_msg_block.MR12_B1 == 0x2A );
                    REQUIRE( l_msg_block.MR12_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR12_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR13_A0 == 0x04 );
                    REQUIRE( l_msg_block.MR13_A1 == 0x04 );
                    REQUIRE( l_msg_block.MR13_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR13_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR13_B0 == 0x04 );
                    REQUIRE( l_msg_block.MR13_B1 == 0x04 );
                    REQUIRE( l_msg_block.MR13_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR13_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR14_A0 == 0xA3 );
                    REQUIRE( l_msg_block.MR14_A1 == 0xA3 );
                    REQUIRE( l_msg_block.MR14_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR14_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR14_B0 == 0xA3 );
                    REQUIRE( l_msg_block.MR14_B1 == 0xA3 );
                    REQUIRE( l_msg_block.MR14_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR14_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR15_A0 == 0x4C );
                    REQUIRE( l_msg_block.MR15_A1 == 0x4C );
                    REQUIRE( l_msg_block.MR15_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR15_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR15_B0 == 0x4C );
                    REQUIRE( l_msg_block.MR15_B1 == 0x4C );
                    REQUIRE( l_msg_block.MR15_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR15_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR111_A0 == 0x0D );
                    REQUIRE( l_msg_block.MR111_A1 == 0x0D );
                    REQUIRE( l_msg_block.MR111_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR111_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR111_B0 == 0x0D );
                    REQUIRE( l_msg_block.MR111_B1 == 0x0D );
                    REQUIRE( l_msg_block.MR111_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR111_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR32_A0 == 0x3B );
                    REQUIRE( l_msg_block.MR32_A1 == 0x2A );
                    REQUIRE( l_msg_block.MR32_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR32_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR32_B0 == 0x3B );
                    REQUIRE( l_msg_block.MR32_B1 == 0x2A );
                    REQUIRE( l_msg_block.MR32_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR32_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR33_A0 == 0x3B );
                    REQUIRE( l_msg_block.MR33_A1 == 0x19 );
                    REQUIRE( l_msg_block.MR33_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR33_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR33_B0 == 0x3B );
                    REQUIRE( l_msg_block.MR33_B1 == 0x19 );
                    REQUIRE( l_msg_block.MR33_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR33_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR34_A0 == 0x26 );
                    REQUIRE( l_msg_block.MR34_A1 == 0x15 );
                    REQUIRE( l_msg_block.MR34_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR34_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR34_B0 == 0x29 );
                    REQUIRE( l_msg_block.MR34_B1 == 0x1F );
                    REQUIRE( l_msg_block.MR34_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR34_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR35_A0 == 0x29 );
                    REQUIRE( l_msg_block.MR35_A1 == 0x12 );
                    REQUIRE( l_msg_block.MR35_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR35_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR35_B0 == 0x27 );
                    REQUIRE( l_msg_block.MR35_B1 == 0x1E );
                    REQUIRE( l_msg_block.MR35_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR35_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR32_ORG_A0 == 0x67 );
                    REQUIRE( l_msg_block.MR32_ORG_A1 == 0x4D );
                    REQUIRE( l_msg_block.MR32_ORG_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR32_ORG_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR32_ORG_B0 == 0x67 );
                    REQUIRE( l_msg_block.MR32_ORG_B1 == 0x4D );
                    REQUIRE( l_msg_block.MR32_ORG_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR32_ORG_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR37_A0 == 0x29 );
                    REQUIRE( l_msg_block.MR37_A1 == 0x0E );
                    REQUIRE( l_msg_block.MR37_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR37_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR37_B0 == 0x29 );
                    REQUIRE( l_msg_block.MR37_B1 == 0x0E );
                    REQUIRE( l_msg_block.MR37_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR37_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR38_A0 == 0x32 );
                    REQUIRE( l_msg_block.MR38_A1 == 0x0F );
                    REQUIRE( l_msg_block.MR38_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR38_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR38_B0 == 0x32 );
                    REQUIRE( l_msg_block.MR38_B1 == 0x0F );
                    REQUIRE( l_msg_block.MR38_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR38_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR39_A0 == 0x32 );
                    REQUIRE( l_msg_block.MR39_A1 == 0x15 );
                    REQUIRE( l_msg_block.MR39_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR39_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR39_B0 == 0x32 );
                    REQUIRE( l_msg_block.MR39_B1 == 0x15 );
                    REQUIRE( l_msg_block.MR39_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR39_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR33_ORG_A0 == 0x2C );
                    REQUIRE( l_msg_block.MR33_ORG_A1 == 0x0A );
                    REQUIRE( l_msg_block.MR33_ORG_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR33_ORG_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR33_ORG_B0 == 0x2C );
                    REQUIRE( l_msg_block.MR33_ORG_B1 == 0x0A );
                    REQUIRE( l_msg_block.MR33_ORG_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR33_ORG_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR11_A0_next == 0x27 );
                    REQUIRE( l_msg_block.MR11_A1_next == 0x28 );
                    REQUIRE( l_msg_block.MR11_A2_next == 0x00 );
                    REQUIRE( l_msg_block.MR11_A3_next == 0x00 );
                    REQUIRE( l_msg_block.MR11_B0_next == 0x27 );
                    REQUIRE( l_msg_block.MR11_B1_next == 0x28 );
                    REQUIRE( l_msg_block.MR11_B2_next == 0x00 );
                    REQUIRE( l_msg_block.MR11_B3_next == 0x00 );
                    REQUIRE( l_msg_block.MR12_A0_next == 0x29 );
                    REQUIRE( l_msg_block.MR12_A1_next == 0x2A );
                    REQUIRE( l_msg_block.MR12_A2_next == 0x00 );
                    REQUIRE( l_msg_block.MR12_A3_next == 0x00 );
                    REQUIRE( l_msg_block.MR12_B0_next == 0x29 );
                    REQUIRE( l_msg_block.MR12_B1_next == 0x2A );
                    REQUIRE( l_msg_block.MR12_B2_next == 0x00 );
                    REQUIRE( l_msg_block.MR12_B3_next == 0x00 );
                    REQUIRE( l_msg_block.MR13_A0_next == 0x04 );
                    REQUIRE( l_msg_block.MR13_A1_next == 0x04 );
                    REQUIRE( l_msg_block.MR13_A2_next == 0x00 );
                    REQUIRE( l_msg_block.MR13_A3_next == 0x00 );
                    REQUIRE( l_msg_block.MR13_B0_next == 0x04 );
                    REQUIRE( l_msg_block.MR13_B1_next == 0x04 );
                    REQUIRE( l_msg_block.MR13_B2_next == 0x00 );
                    REQUIRE( l_msg_block.MR13_B3_next == 0x00 );
                    REQUIRE( l_msg_block.MR33_ORG_A0_next == 0x2C );
                    REQUIRE( l_msg_block.MR33_ORG_A1_next == 0x0A );
                    REQUIRE( l_msg_block.MR33_ORG_A2_next == 0x00 );
                    REQUIRE( l_msg_block.MR33_ORG_A3_next == 0x00 );
                    REQUIRE( l_msg_block.MR33_ORG_B0_next == 0x2C );
                    REQUIRE( l_msg_block.MR33_ORG_B1_next == 0x0A );
                    REQUIRE( l_msg_block.MR33_ORG_B2_next == 0x00 );
                    REQUIRE( l_msg_block.MR33_ORG_B3_next == 0x00 );
                    REQUIRE( l_msg_block.MR33_A0_next == 0x3B );
                    REQUIRE( l_msg_block.MR33_A1_next == 0x19 );
                    REQUIRE( l_msg_block.MR33_A2_next == 0x00 );
                    REQUIRE( l_msg_block.MR33_A3_next == 0x00 );
                    REQUIRE( l_msg_block.MR33_B0_next == 0x3B );
                    REQUIRE( l_msg_block.MR33_B1_next == 0x19 );
                    REQUIRE( l_msg_block.MR33_B2_next == 0x00 );
                    REQUIRE( l_msg_block.MR33_B3_next == 0x00 );
                    // MR50 has a couple MRW values in it which aren't writeable, so have to use the available values
                    fapi2::buffer<uint8_t> l_mr50 = 0x28;
                    l_mr50.writeBit<5, 2>(l_wr_crc_enable)
                    .writeBit<7>(l_rd_crc_enable);
                    REQUIRE( l_msg_block.MR50_A0 == l_mr50 );
                    REQUIRE( l_msg_block.MR50_A1 == l_mr50 );
                    REQUIRE( l_msg_block.MR50_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR50_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR50_B0 == l_mr50 );
                    REQUIRE( l_msg_block.MR50_B1 == l_mr50 );
                    REQUIRE( l_msg_block.MR50_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR50_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR51_A0 == 0x7B );
                    REQUIRE( l_msg_block.MR51_A1 == 0x7B );
                    REQUIRE( l_msg_block.MR51_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR51_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR51_B0 == 0x7B );
                    REQUIRE( l_msg_block.MR51_B1 == 0x7B );
                    REQUIRE( l_msg_block.MR51_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR51_B3 == 0x00 );
                    REQUIRE( l_msg_block.MR52_A0 == 0x6C );
                    REQUIRE( l_msg_block.MR52_A1 == 0x6C );
                    REQUIRE( l_msg_block.MR52_A2 == 0x00 );
                    REQUIRE( l_msg_block.MR52_A3 == 0x00 );
                    REQUIRE( l_msg_block.MR52_B0 == 0x6C );
                    REQUIRE( l_msg_block.MR52_B1 == 0x6C );
                    REQUIRE( l_msg_block.MR52_B2 == 0x00 );
                    REQUIRE( l_msg_block.MR52_B3 == 0x00 );
                    REQUIRE( l_msg_block.DFE_GainBias_A0 == 0x0B );
                    REQUIRE( l_msg_block.DFE_GainBias_A1 == 0x02 );
                    REQUIRE( l_msg_block.DFE_GainBias_A2 == 0x00 );
                    REQUIRE( l_msg_block.DFE_GainBias_A3 == 0x00 );
                    REQUIRE( l_msg_block.DFE_GainBias_B0 == 0x0B );
                    REQUIRE( l_msg_block.DFE_GainBias_B1 == 0x02 );
                    REQUIRE( l_msg_block.DFE_GainBias_B2 == 0x00 );
                    REQUIRE( l_msg_block.DFE_GainBias_B3 == 0x00 );
                    REQUIRE( l_msg_block.ReservedF6 == 0x00 );
                    REQUIRE( l_msg_block.ReservedF7 == 0x00 );
                    REQUIRE( l_msg_block.ReservedF8 == 0x00 );
                    REQUIRE( l_msg_block.ReservedF9 == 0x00 );
                    REQUIRE( l_msg_block.BCW04_next == 0x00 );
                    REQUIRE( l_msg_block.BCW05_next == 0x00 );
                    REQUIRE( l_msg_block.WR_RD_RTT_PARK_A0 == 0x35 );
                    REQUIRE( l_msg_block.WR_RD_RTT_PARK_A1 == 0x46 );
                    REQUIRE( l_msg_block.WR_RD_RTT_PARK_A2 == 0x00 );
                    REQUIRE( l_msg_block.WR_RD_RTT_PARK_A3 == 0x00 );
                    REQUIRE( l_msg_block.WR_RD_RTT_PARK_B0 == 0x35 );
                    REQUIRE( l_msg_block.WR_RD_RTT_PARK_B1 == 0x46 );
                    REQUIRE( l_msg_block.WR_RD_RTT_PARK_B2 == 0x00 );
                    REQUIRE( l_msg_block.WR_RD_RTT_PARK_B3 == 0x00 );
                    REQUIRE( l_msg_block.Reserved1E2 == 0x3C );
                    REQUIRE( l_msg_block.Reserved1E3 == 0x00 );
                    REQUIRE( l_msg_block.Reserved1E4 == 0x49 );
                    REQUIRE( l_msg_block.Reserved1E5 == 0x00 );
                    REQUIRE( l_msg_block.Reserved1E6 == 0x00 );
                    REQUIRE( l_msg_block.Reserved1E7 == 0x00 );
                    REQUIRE( l_msg_block.WL_ADJ_START == 0x0060 );
                    REQUIRE( l_msg_block.WL_ADJ_END == 0x00A0 );
                    REQUIRE( l_msg_block.VrefDqR0Nib0 == 0x25 );
                    REQUIRE( l_msg_block.VrefDqR0Nib3 == 0x27 );
                    REQUIRE( l_msg_block.VrefDqR0Nib11 == 0x29 );
                    REQUIRE( l_msg_block.VrefDqR0Nib17 == 0x2B );
                    REQUIRE( l_msg_block.VrefDqR1Nib0 == 0x26 );
                    REQUIRE( l_msg_block.VrefDqR1Nib6 == 0x28 );
                    REQUIRE( l_msg_block.VrefDqR1Nib9 == 0x2A );
                    REQUIRE( l_msg_block.VrefDqR1Nib18 == 0x2C );
                    REQUIRE( l_msg_block.MR3R0Nib0 == 0x0B );
                    REQUIRE( l_msg_block.MR3R0Nib1 == 0x0C );
                    REQUIRE( l_msg_block.MR3R0Nib5 == 0x0D );
                    REQUIRE( l_msg_block.MR3R0Nib10 == 0x0E );
                    REQUIRE( l_msg_block.MR3R1Nib0 == 0x02 );
                    REQUIRE( l_msg_block.MR3R1Nib2 == 0x03 );
                    REQUIRE( l_msg_block.MR3R1Nib6 == 0x04 );
                    REQUIRE( l_msg_block.MR3R1Nib12 == 0x05 );
                    REQUIRE( l_msg_block.VrefCSR0Nib0 == 0x29 );
                    REQUIRE( l_msg_block.VrefCSR0Nib6 == 0x2B );
                    REQUIRE( l_msg_block.VrefCSR0Nib12 == 0x2D );
                    REQUIRE( l_msg_block.VrefCSR0Nib18 == 0x2F );
                    REQUIRE( l_msg_block.VrefCSR1Nib0 == 0x2A );
                    REQUIRE( l_msg_block.VrefCSR1Nib7 == 0x2C );
                    REQUIRE( l_msg_block.VrefCSR1Nib14 == 0x2E );
                    REQUIRE( l_msg_block.VrefCSR1Nib19 == 0x30 );
                    REQUIRE( l_msg_block.VrefCAR0Nib0 == 0x27 );
                    REQUIRE( l_msg_block.VrefCAR0Nib5 == 0x29 );
                    REQUIRE( l_msg_block.VrefCAR0Nib10 == 0x2B );
                    REQUIRE( l_msg_block.VrefCAR0Nib15 == 0x2D );
                    REQUIRE( l_msg_block.VrefCAR1Nib0 == 0x28 );
                    REQUIRE( l_msg_block.VrefCAR1Nib4 == 0x2A );
                    REQUIRE( l_msg_block.VrefCAR1Nib8 == 0x2C );
                    REQUIRE( l_msg_block.VrefCAR1Nib12 == 0x2E );
                    REQUIRE( l_msg_block.DisabledDB0LaneR0 == 0xFF );
                    REQUIRE( l_msg_block.DisabledDB1LaneR0 == 0xFF );
                    REQUIRE( l_msg_block.DisabledDB2LaneR0 == 0xFF );
                    REQUIRE( l_msg_block.DisabledDB3LaneR0 == 0xFF );
                    REQUIRE( l_msg_block.DisabledDB4LaneR0 == 0x00 );
                    REQUIRE( l_msg_block.DisabledDB5LaneR0 == 0xFF );
                    REQUIRE( l_msg_block.DisabledDB6LaneR0 == 0xFF );
                    REQUIRE (l_msg_block.DisabledDB7LaneR0 == 0xFF );
                    REQUIRE( l_msg_block.DisabledDB8LaneR0 == 0x00 );
                    REQUIRE( l_msg_block.DisabledDB9LaneR0 == 0xFF );

                    // Testing D5misc[1] enabling when redundant_cs is enabled
                    {
                        uint8_t l_redundant_cs_en_save[mss::ody::MAX_DIMM_PER_PORT] = {};
                        uint8_t l_redundant_cs_en_test[mss::ody::MAX_DIMM_PER_PORT] = {fapi2::ENUM_ATTR_MEM_EFF_REDUNDANT_CS_EN_ENABLE, fapi2::ENUM_ATTR_MEM_EFF_REDUNDANT_CS_EN_ENABLE};
                        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
                        mss::ody::phy::msg_block_params l_params(l_port, l_rc);
                        REQUIRE_RC_PASS(l_rc);

                        l_msg_block.D5Misc = 0;

                        // Save the original
                        REQUIRE_RC_PASS(mss::attr::get_ddr5_redundant_cs_en(l_port, l_redundant_cs_en_save));

                        // Overriding redundant attr to be enabled
                        REQUIRE_RC_PASS(mss::attr::set_ddr5_redundant_cs_en(l_port, l_redundant_cs_en_test));

                        // Run the setup for D5_Misc
                        REQUIRE_RC_PASS(l_params.setup_D5Misc(l_msg_block));
                        REQUIRE( l_msg_block.D5Misc == 0x6 );

                        l_redundant_cs_en_test[0] = {fapi2::ENUM_ATTR_MEM_EFF_REDUNDANT_CS_EN_DISABLE};
                        l_redundant_cs_en_test[1] = {fapi2::ENUM_ATTR_MEM_EFF_REDUNDANT_CS_EN_DISABLE};

                        // Overriding redundant attr to be disabled
                        REQUIRE_RC_PASS(mss::attr::set_ddr5_redundant_cs_en(l_port, l_redundant_cs_en_test));

                        // Run the setup for D5_Misc
                        REQUIRE_RC_PASS(l_params.setup_D5Misc(l_msg_block));
                        REQUIRE( l_msg_block.D5Misc == 0x4 );


                        // Restore the original
                        REQUIRE_RC_PASS(mss::attr::set_ddr5_redundant_cs_en(l_port, l_redundant_cs_en_save));

                    }

                    constexpr uint8_t NON_SIM_MODE = 0;
                    REQUIRE_RC_PASS(mss::ody::phy::configure_dram_train_message_block(l_port, NON_SIM_MODE, l_msg_block));
                    REQUIRE( l_msg_block.CATrainOpt == 0x90 );
                    REQUIRE( l_msg_block.TX2D_DFE_Misc == 0x03 );
                    REQUIRE( l_msg_block.RX2D_TrainOpt == 0x70 );
                    REQUIRE( l_msg_block.TX2D_TrainOpt == 0x04 );

                    // Explicitly tests CA 13 skip for attribute combinations
                    {
                        uint16_t l_stack_height_h4_inject[mss::ody::MAX_DIMM_PER_PORT] = {fapi2::ENUM_ATTR_MEM_3DS_HEIGHT_H4, fapi2::ENUM_ATTR_MEM_3DS_HEIGHT_H4};
                        uint8_t l_density_48gb_inject[mss::ody::MAX_DIMM_PER_PORT] = {fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_48G, fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_48G};
                        uint16_t l_stack_height_h8_inject[mss::ody::MAX_DIMM_PER_PORT] = {fapi2::ENUM_ATTR_MEM_3DS_HEIGHT_H8, fapi2::ENUM_ATTR_MEM_3DS_HEIGHT_H8};
                        uint8_t l_density_64gb_inject[mss::ody::MAX_DIMM_PER_PORT] = {fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_64G, fapi2::ENUM_ATTR_MEM_EFF_DRAM_DENSITY_64G};

                        uint8_t l_CATrainOpt_save = 0;
                        uint16_t l_stack_height_saved[mss::ody::MAX_DIMM_PER_PORT] = {0};
                        uint8_t l_density_saved[mss::ody::MAX_DIMM_PER_PORT] = {0};
                        REQUIRE_RC_PASS(mss::attr::get_3ds_height(l_port, l_stack_height_saved));
                        REQUIRE_RC_PASS(mss::attr::get_dram_density(l_port, l_density_saved));
                        REQUIRE_RC_PASS(mss::attr::get_ca_train_options(l_port, l_CATrainOpt_save));
                        REQUIRE_RC_PASS(mss::attr::set_ca_train_options(l_port, 0));

                        l_msg_block.CATrainOpt = 0;
                        REQUIRE_RC_PASS(mss::ody::phy::configure_dram_train_message_block(l_port, SIM_MODE, l_msg_block));

                        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
                        mss::ody::phy::msg_block_params l_params(l_port, l_rc);
                        REQUIRE_RC_PASS(l_rc);

                        // 4H and 48Gb -> set skip
                        l_msg_block.CATrainOpt = 0;
                        REQUIRE_RC_PASS(mss::attr::set_3ds_height(l_port, l_stack_height_h4_inject));
                        REQUIRE_RC_PASS(mss::attr::set_dram_density(l_port, l_density_48gb_inject));
                        REQUIRE_RC_PASS(l_params.setup_CATrainOpt(SIM_MODE, l_msg_block));
                        REQUIRE(l_msg_block.CATrainOpt == 0x1c);

                        // 8H and 48Gb -> clear skip
                        REQUIRE_RC_PASS(mss::attr::set_3ds_height(l_port, l_stack_height_h8_inject));
                        REQUIRE_RC_PASS(mss::attr::set_dram_density(l_port, l_density_48gb_inject));
                        REQUIRE_RC_PASS(l_params.setup_CATrainOpt(SIM_MODE, l_msg_block));
                        REQUIRE(l_msg_block.CATrainOpt == 0x0c);

                        // 8H and 64Gb -> clear skip
                        l_msg_block.CATrainOpt = 0x10;
                        REQUIRE_RC_PASS(mss::attr::set_3ds_height(l_port, l_stack_height_h8_inject));
                        REQUIRE_RC_PASS(mss::attr::set_dram_density(l_port, l_density_64gb_inject));
                        REQUIRE_RC_PASS(l_params.setup_CATrainOpt(SIM_MODE, l_msg_block));
                        REQUIRE(l_msg_block.CATrainOpt == 0x0c);

                        // 4H and 64Gb -> clear skip
                        l_msg_block.CATrainOpt = 0x10;
                        REQUIRE_RC_PASS(mss::attr::set_3ds_height(l_port, l_stack_height_h4_inject));
                        REQUIRE_RC_PASS(mss::attr::set_dram_density(l_port, l_density_64gb_inject));
                        REQUIRE_RC_PASS(l_params.setup_CATrainOpt(SIM_MODE, l_msg_block));
                        REQUIRE(l_msg_block.CATrainOpt == 0x0c);

                        REQUIRE_RC_PASS(mss::attr::set_3ds_height(l_port, l_stack_height_saved));
                        REQUIRE_RC_PASS(mss::attr::set_dram_density(l_port, l_density_saved));
                        REQUIRE_RC_PASS(mss::attr::set_ca_train_options(l_port, l_CATrainOpt_save));
                    }

                    // Tests redundant CS enable on -> retests ALL of the message block to be safe
                    {
                        REQUIRE_RC_PASS(mss::attr::set_ddr5_redundant_cs_en(l_port, l_redundant_cs_enable));
                        constexpr uint8_t SIM_MODE = 1;
                        PMU_SMB_DDR5U_1D_t l_msg_block;
                        REQUIRE_RC_PASS(mss::ody::phy::configure_dram_train_message_block(l_port, SIM_MODE, l_msg_block));

                        REQUIRE( l_msg_block.AdvTrainOpt == 0x07 );
                        REQUIRE( l_msg_block.MsgMisc == 0x05 );
                        REQUIRE( l_msg_block.Pstate == 0 );
                        REQUIRE( l_msg_block.PllBypassEn == 0x01 );
                        REQUIRE( l_msg_block.DRAMFreq == 3200 );
                        REQUIRE( l_msg_block.RCW05_next == 0x00 );
                        REQUIRE( l_msg_block.RCW06_next == 0x00 );
                        REQUIRE( l_msg_block.RXEN_ADJ == 0x03 );
                        REQUIRE( l_msg_block.RX2D_DFE_Misc == 0x04 );
                        REQUIRE( l_msg_block.PhyVref == 0x05 );
                        REQUIRE( l_msg_block.D5Misc == 0x06 );
                        REQUIRE( l_msg_block.WL_ADJ == 0x07 );
                        REQUIRE( l_msg_block.SequenceCtrl == 0x827F );
                        REQUIRE( l_msg_block.HdtCtrl == 0x08 );
                        REQUIRE( l_msg_block.PhyCfg == 0x09 );
                        REQUIRE( l_msg_block.DFIMRLMargin == 0x0A );
                        REQUIRE( l_msg_block.X16Present == 0x00 );
                        REQUIRE( l_msg_block.UseBroadcastMR == 0x0B );
                        REQUIRE( l_msg_block.D5Quickboot == 0x00 );
                        REQUIRE( l_msg_block.DisabledDbyte == 0x0C );
                        REQUIRE( l_msg_block.CATrainOpt == 0x9C ); // CA13 skip is set
                        REQUIRE( l_msg_block.TX2D_DFE_Misc == 0xFC );
                        REQUIRE( l_msg_block.RX2D_TrainOpt == 0x7E );
                        REQUIRE( l_msg_block.TX2D_TrainOpt == 0x1E );
                        REQUIRE( l_msg_block.Share2DVrefResult == 0x00 );
                        REQUIRE( l_msg_block.MRE_MIN_PULSE == 0x00 );
                        REQUIRE( l_msg_block.DWL_MIN_PULSE == 0x00 );
                        REQUIRE( l_msg_block.PhyConfigOverride == 0x89AB );
                        REQUIRE( l_msg_block.EnabledDQsChA == 0x0D );
                        REQUIRE( l_msg_block.EnabledDQsChB == 0x00 );
                        REQUIRE( l_msg_block.CsPresentChA == 0x01 );
                        REQUIRE( l_msg_block.CsPresentChB == 0x00 );  // Zero'ed out DQ for channel B zeroes out this field
                        REQUIRE( l_msg_block.MR0_A0 == 0x1A );
                        REQUIRE( l_msg_block.MR0_A1 == 0x1A );
                        REQUIRE( l_msg_block.MR0_A2 == 0x1A );
                        REQUIRE( l_msg_block.MR0_A3 == 0x1A );
                        REQUIRE( l_msg_block.MR0_B0 == 0x1A );
                        REQUIRE( l_msg_block.MR0_B1 == 0x1A );
                        REQUIRE( l_msg_block.MR0_B2 == 0x1A );
                        REQUIRE( l_msg_block.MR0_B3 == 0x1A );
                        REQUIRE( l_msg_block.MR2_A0 == 0x28 );
                        REQUIRE( l_msg_block.MR2_A1 == 0x28 );
                        REQUIRE( l_msg_block.MR2_A2 == 0x28 );
                        REQUIRE( l_msg_block.MR2_A3 == 0x28 );
                        REQUIRE( l_msg_block.MR2_B0 == 0x28 );
                        REQUIRE( l_msg_block.MR2_B1 == 0x28 );
                        REQUIRE( l_msg_block.MR2_B2 == 0x28 );
                        REQUIRE( l_msg_block.MR2_B3 == 0x28 );
                        REQUIRE( l_msg_block.MR3_A0 == 0x0B );
                        REQUIRE( l_msg_block.MR3_A1 == 0x0B );
                        REQUIRE( l_msg_block.MR3_A2 == 0x02 );
                        REQUIRE( l_msg_block.MR3_A3 == 0x02 );
                        REQUIRE( l_msg_block.MR3_B0 == 0x0B );
                        REQUIRE( l_msg_block.MR3_B1 == 0x0B );
                        REQUIRE( l_msg_block.MR3_B2 == 0x02 );
                        REQUIRE( l_msg_block.MR3_B3 == 0x02 );
                        REQUIRE( l_msg_block.MR4_A0 == 0x84 );
                        REQUIRE( l_msg_block.MR4_A1 == 0x84 );
                        REQUIRE( l_msg_block.MR4_A2 == 0x84 );
                        REQUIRE( l_msg_block.MR4_A3 == 0x84 );
                        REQUIRE( l_msg_block.MR4_B0 == 0x84 );
                        REQUIRE( l_msg_block.MR4_B1 == 0x84 );
                        REQUIRE( l_msg_block.MR4_B2 == 0x84 );
                        REQUIRE( l_msg_block.MR4_B3 == 0x84 );
                        REQUIRE( l_msg_block.MR5_A0 == 0x8A );
                        REQUIRE( l_msg_block.MR5_A1 == 0x8A );
                        REQUIRE( l_msg_block.MR5_A2 == 0x08 );
                        REQUIRE( l_msg_block.MR5_A3 == 0x08 );
                        REQUIRE( l_msg_block.MR5_B0 == 0x8A );
                        REQUIRE( l_msg_block.MR5_B1 == 0x8A );
                        REQUIRE( l_msg_block.MR5_B2 == 0x08 );
                        REQUIRE( l_msg_block.MR5_B3 == 0x08 );
                        REQUIRE( l_msg_block.MR6_A0 == 0x37 );
                        REQUIRE( l_msg_block.MR6_A1 == 0x37 );
                        REQUIRE( l_msg_block.MR6_A2 == 0x37 );
                        REQUIRE( l_msg_block.MR6_A3 == 0x37 );
                        REQUIRE( l_msg_block.MR6_B0 == 0x37 );
                        REQUIRE( l_msg_block.MR6_B1 == 0x37 );
                        REQUIRE( l_msg_block.MR6_B2 == 0x37 );
                        REQUIRE( l_msg_block.MR6_B3 == 0x37 );
                        REQUIRE( l_msg_block.MR32_A0_next == 0x3B );
                        REQUIRE( l_msg_block.MR32_A1_next == 0x3B );
                        REQUIRE( l_msg_block.MR32_A2_next == 0x2A );
                        REQUIRE( l_msg_block.MR32_A3_next == 0x2A );
                        REQUIRE( l_msg_block.MR32_B0_next == 0x3B );
                        REQUIRE( l_msg_block.MR32_B1_next == 0x3B );
                        REQUIRE( l_msg_block.MR32_B2_next == 0x2A );
                        REQUIRE( l_msg_block.MR32_B3_next == 0x2A );
                        REQUIRE( l_msg_block.MR8_A0 == 0x8B );
                        REQUIRE( l_msg_block.MR8_A1 == 0x8B );
                        REQUIRE( l_msg_block.MR8_A2 == 0x8B );
                        REQUIRE( l_msg_block.MR8_A3 == 0x8B );
                        REQUIRE( l_msg_block.MR8_B0 == 0x8B );
                        REQUIRE( l_msg_block.MR8_B1 == 0x8B );
                        REQUIRE( l_msg_block.MR8_B2 == 0x8B );
                        REQUIRE( l_msg_block.MR8_B3 == 0x8B );
                        REQUIRE( l_msg_block.MR32_ORG_A0_next == 0x67 );
                        REQUIRE( l_msg_block.MR32_ORG_A1_next == 0x67 );
                        REQUIRE( l_msg_block.MR32_ORG_A2_next == 0x4D );
                        REQUIRE( l_msg_block.MR32_ORG_A3_next == 0x4D );
                        REQUIRE( l_msg_block.MR32_ORG_B0_next == 0x67 );
                        REQUIRE( l_msg_block.MR32_ORG_B1_next == 0x67 );
                        REQUIRE( l_msg_block.MR32_ORG_B2_next == 0x4D );
                        REQUIRE( l_msg_block.MR32_ORG_B3_next == 0x4D );
                        REQUIRE( l_msg_block.MR10_A0 == 0x25 );
                        REQUIRE( l_msg_block.MR10_A1 == 0x25 );
                        REQUIRE( l_msg_block.MR10_A2 == 0x26 );
                        REQUIRE( l_msg_block.MR10_A3 == 0x26 );
                        REQUIRE( l_msg_block.MR10_B0 == 0x25 );
                        REQUIRE( l_msg_block.MR10_B1 == 0x25 );
                        REQUIRE( l_msg_block.MR10_B2 == 0x26 );
                        REQUIRE( l_msg_block.MR10_B3 == 0x26 );
                        REQUIRE( l_msg_block.MR11_A0 == 0x27 );
                        REQUIRE( l_msg_block.MR11_A1 == 0x27 );
                        REQUIRE( l_msg_block.MR11_A2 == 0x28 );
                        REQUIRE( l_msg_block.MR11_A3 == 0x28 );
                        REQUIRE( l_msg_block.MR11_B0 == 0x27 );
                        REQUIRE( l_msg_block.MR11_B1 == 0x27 );
                        REQUIRE( l_msg_block.MR11_B2 == 0x28 );
                        REQUIRE( l_msg_block.MR11_B3 == 0x28 );
                        REQUIRE( l_msg_block.MR12_A0 == 0x29 );
                        REQUIRE( l_msg_block.MR12_A1 == 0x29 );
                        REQUIRE( l_msg_block.MR12_A2 == 0x2A );
                        REQUIRE( l_msg_block.MR12_A3 == 0x2A );
                        REQUIRE( l_msg_block.MR12_B0 == 0x29 );
                        REQUIRE( l_msg_block.MR12_B1 == 0x29 );
                        REQUIRE( l_msg_block.MR12_B2 == 0x2A );
                        REQUIRE( l_msg_block.MR12_B3 == 0x2A );
                        REQUIRE( l_msg_block.MR13_A0 == 0x04 );
                        REQUIRE( l_msg_block.MR13_A1 == 0x04 );
                        REQUIRE( l_msg_block.MR13_A2 == 0x04 );
                        REQUIRE( l_msg_block.MR13_A3 == 0x04 );
                        REQUIRE( l_msg_block.MR13_B0 == 0x04 );
                        REQUIRE( l_msg_block.MR13_B1 == 0x04 );
                        REQUIRE( l_msg_block.MR13_B2 == 0x04 );
                        REQUIRE( l_msg_block.MR13_B3 == 0x04 );
                        REQUIRE( l_msg_block.MR14_A0 == 0xA3 );
                        REQUIRE( l_msg_block.MR14_A1 == 0xA3 );
                        REQUIRE( l_msg_block.MR14_A2 == 0xA3 );
                        REQUIRE( l_msg_block.MR14_A3 == 0xA3 );
                        REQUIRE( l_msg_block.MR14_B0 == 0xA3 );
                        REQUIRE( l_msg_block.MR14_B1 == 0xA3 );
                        REQUIRE( l_msg_block.MR14_B2 == 0xA3 );
                        REQUIRE( l_msg_block.MR14_B3 == 0xA3 );
                        REQUIRE( l_msg_block.MR15_A0 == 0x4C );
                        REQUIRE( l_msg_block.MR15_A1 == 0x4C );
                        REQUIRE( l_msg_block.MR15_A2 == 0x4C );
                        REQUIRE( l_msg_block.MR15_A3 == 0x4C );
                        REQUIRE( l_msg_block.MR15_B0 == 0x4C );
                        REQUIRE( l_msg_block.MR15_B1 == 0x4C );
                        REQUIRE( l_msg_block.MR15_B2 == 0x4C );
                        REQUIRE( l_msg_block.MR15_B3 == 0x4C );
                        REQUIRE( l_msg_block.MR111_A0 == 0x0D );
                        REQUIRE( l_msg_block.MR111_A1 == 0x0D );
                        REQUIRE( l_msg_block.MR111_A2 == 0x0D );
                        REQUIRE( l_msg_block.MR111_A3 == 0x0D );
                        REQUIRE( l_msg_block.MR111_B0 == 0x0D );
                        REQUIRE( l_msg_block.MR111_B1 == 0x0D );
                        REQUIRE( l_msg_block.MR111_B2 == 0x0D );
                        REQUIRE( l_msg_block.MR111_B3 == 0x0D );
                        REQUIRE( l_msg_block.MR32_A0 == 0x3B );
                        REQUIRE( l_msg_block.MR32_A1 == 0x3B );
                        REQUIRE( l_msg_block.MR32_A2 == 0x2A );
                        REQUIRE( l_msg_block.MR32_A3 == 0x2A );
                        REQUIRE( l_msg_block.MR32_B0 == 0x3B );
                        REQUIRE( l_msg_block.MR32_B1 == 0x3B );
                        REQUIRE( l_msg_block.MR32_B2 == 0x2A );
                        REQUIRE( l_msg_block.MR32_B3 == 0x2A );
                        REQUIRE( l_msg_block.MR33_A0 == 0x3B );
                        REQUIRE( l_msg_block.MR33_A1 == 0x3B );
                        REQUIRE( l_msg_block.MR33_A2 == 0x19 );
                        REQUIRE( l_msg_block.MR33_A3 == 0x19 );
                        REQUIRE( l_msg_block.MR33_B0 == 0x3B );
                        REQUIRE( l_msg_block.MR33_B1 == 0x3B );
                        REQUIRE( l_msg_block.MR33_B2 == 0x19 );
                        REQUIRE( l_msg_block.MR33_B3 == 0x19 );
                        REQUIRE( l_msg_block.MR34_A0 == 0x26 );
                        REQUIRE( l_msg_block.MR34_A1 == 0x26 );
                        REQUIRE( l_msg_block.MR34_A2 == 0x15 );
                        REQUIRE( l_msg_block.MR34_A3 == 0x15 );
                        REQUIRE( l_msg_block.MR34_B0 == 0x29 );
                        REQUIRE( l_msg_block.MR34_B1 == 0x29 );
                        REQUIRE( l_msg_block.MR34_B2 == 0x1F );
                        REQUIRE( l_msg_block.MR34_B3 == 0x1F );
                        REQUIRE( l_msg_block.MR35_A0 == 0x29 );
                        REQUIRE( l_msg_block.MR35_A1 == 0x29 );
                        REQUIRE( l_msg_block.MR35_A2 == 0x12 );
                        REQUIRE( l_msg_block.MR35_A3 == 0x12 );
                        REQUIRE( l_msg_block.MR35_B0 == 0x27 );
                        REQUIRE( l_msg_block.MR35_B1 == 0x27 );
                        REQUIRE( l_msg_block.MR35_B2 == 0x1E );
                        REQUIRE( l_msg_block.MR35_B3 == 0x1E );
                        REQUIRE( l_msg_block.MR32_ORG_A0 == 0x67 );
                        REQUIRE( l_msg_block.MR32_ORG_A1 == 0x67 );
                        REQUIRE( l_msg_block.MR32_ORG_A2 == 0x4D );
                        REQUIRE( l_msg_block.MR32_ORG_A3 == 0x4D );
                        REQUIRE( l_msg_block.MR32_ORG_B0 == 0x67 );
                        REQUIRE( l_msg_block.MR32_ORG_B1 == 0x67 );
                        REQUIRE( l_msg_block.MR32_ORG_B2 == 0x4D );
                        REQUIRE( l_msg_block.MR32_ORG_B3 == 0x4D );
                        REQUIRE( l_msg_block.MR37_A0 == 0x29 );
                        REQUIRE( l_msg_block.MR37_A1 == 0x29 );
                        REQUIRE( l_msg_block.MR37_A2 == 0x0E );
                        REQUIRE( l_msg_block.MR37_A3 == 0x0E );
                        REQUIRE( l_msg_block.MR37_B0 == 0x29 );
                        REQUIRE( l_msg_block.MR37_B1 == 0x29 );
                        REQUIRE( l_msg_block.MR37_B2 == 0x0E );
                        REQUIRE( l_msg_block.MR37_B3 == 0x0E );
                        REQUIRE( l_msg_block.MR38_A0 == 0x32 );
                        REQUIRE( l_msg_block.MR38_A1 == 0x32 );
                        REQUIRE( l_msg_block.MR38_A2 == 0x0F );
                        REQUIRE( l_msg_block.MR38_A3 == 0x0F );
                        REQUIRE( l_msg_block.MR38_B0 == 0x32 );
                        REQUIRE( l_msg_block.MR38_B1 == 0x32 );
                        REQUIRE( l_msg_block.MR38_B2 == 0x0F );
                        REQUIRE( l_msg_block.MR38_B3 == 0x0F );
                        REQUIRE( l_msg_block.MR39_A0 == 0x32 );
                        REQUIRE( l_msg_block.MR39_A1 == 0x32 );
                        REQUIRE( l_msg_block.MR39_A2 == 0x15 );
                        REQUIRE( l_msg_block.MR39_A3 == 0x15 );
                        REQUIRE( l_msg_block.MR39_B0 == 0x32 );
                        REQUIRE( l_msg_block.MR39_B1 == 0x32 );
                        REQUIRE( l_msg_block.MR39_B2 == 0x15 );
                        REQUIRE( l_msg_block.MR39_B3 == 0x15 );
                        REQUIRE( l_msg_block.MR33_ORG_A0 == 0x2C );
                        REQUIRE( l_msg_block.MR33_ORG_A1 == 0x2C );
                        REQUIRE( l_msg_block.MR33_ORG_A2 == 0x0A );
                        REQUIRE( l_msg_block.MR33_ORG_A3 == 0x0A );
                        REQUIRE( l_msg_block.MR33_ORG_B0 == 0x2C );
                        REQUIRE( l_msg_block.MR33_ORG_B1 == 0x2C );
                        REQUIRE( l_msg_block.MR33_ORG_B2 == 0x0A );
                        REQUIRE( l_msg_block.MR33_ORG_B3 == 0x0A );
                        REQUIRE( l_msg_block.MR11_A0_next == 0x27 );
                        REQUIRE( l_msg_block.MR11_A1_next == 0x27 );
                        REQUIRE( l_msg_block.MR11_A2_next == 0x28 );
                        REQUIRE( l_msg_block.MR11_A3_next == 0x28 );
                        REQUIRE( l_msg_block.MR11_B0_next == 0x27 );
                        REQUIRE( l_msg_block.MR11_B1_next == 0x27 );
                        REQUIRE( l_msg_block.MR11_B2_next == 0x28 );
                        REQUIRE( l_msg_block.MR11_B3_next == 0x28 );
                        REQUIRE( l_msg_block.MR12_A0_next == 0x29 );
                        REQUIRE( l_msg_block.MR12_A1_next == 0x29 );
                        REQUIRE( l_msg_block.MR12_A2_next == 0x2A );
                        REQUIRE( l_msg_block.MR12_A3_next == 0x2A );
                        REQUIRE( l_msg_block.MR12_B0_next == 0x29 );
                        REQUIRE( l_msg_block.MR12_B1_next == 0x29 );
                        REQUIRE( l_msg_block.MR12_B2_next == 0x2A );
                        REQUIRE( l_msg_block.MR12_B3_next == 0x2A );
                        REQUIRE( l_msg_block.MR13_A0_next == 0x04 );
                        REQUIRE( l_msg_block.MR13_A1_next == 0x04 );
                        REQUIRE( l_msg_block.MR13_A2_next == 0x04 );
                        REQUIRE( l_msg_block.MR13_A3_next == 0x04 );
                        REQUIRE( l_msg_block.MR13_B0_next == 0x04 );
                        REQUIRE( l_msg_block.MR13_B1_next == 0x04 );
                        REQUIRE( l_msg_block.MR13_B2_next == 0x04 );
                        REQUIRE( l_msg_block.MR13_B3_next == 0x04 );
                        REQUIRE( l_msg_block.MR33_ORG_A0_next == 0x2C );
                        REQUIRE( l_msg_block.MR33_ORG_A1_next == 0x2C );
                        REQUIRE( l_msg_block.MR33_ORG_A2_next == 0x0A );
                        REQUIRE( l_msg_block.MR33_ORG_A3_next == 0x0A );
                        REQUIRE( l_msg_block.MR33_ORG_B0_next == 0x2C );
                        REQUIRE( l_msg_block.MR33_ORG_B1_next == 0x2C );
                        REQUIRE( l_msg_block.MR33_ORG_B2_next == 0x0A );
                        REQUIRE( l_msg_block.MR33_ORG_B3_next == 0x0A );
                        REQUIRE( l_msg_block.MR33_A0_next == 0x3B );
                        REQUIRE( l_msg_block.MR33_A1_next == 0x3B );
                        REQUIRE( l_msg_block.MR33_A2_next == 0x19 );
                        REQUIRE( l_msg_block.MR33_A3_next == 0x19 );
                        REQUIRE( l_msg_block.MR33_B0_next == 0x3B );
                        REQUIRE( l_msg_block.MR33_B1_next == 0x3B );
                        REQUIRE( l_msg_block.MR33_B2_next == 0x19 );
                        REQUIRE( l_msg_block.MR33_B3_next == 0x19 );
                        // MR50 has a couple MRW values in it which aren't writeable, so have to use the available values
                        fapi2::buffer<uint8_t> l_mr50 = 0x28;
                        l_mr50.writeBit<5, 2>(l_wr_crc_enable)
                        .writeBit<7>(l_rd_crc_enable);
                        REQUIRE( l_msg_block.MR50_A0 == l_mr50 );
                        REQUIRE( l_msg_block.MR50_A1 == l_mr50 );
                        REQUIRE( l_msg_block.MR50_A2 == l_mr50 );
                        REQUIRE( l_msg_block.MR50_A3 == l_mr50 );
                        REQUIRE( l_msg_block.MR50_B0 == l_mr50 );
                        REQUIRE( l_msg_block.MR50_B1 == l_mr50 );
                        REQUIRE( l_msg_block.MR50_B2 == l_mr50 );
                        REQUIRE( l_msg_block.MR50_B3 == l_mr50 );
                        REQUIRE( l_msg_block.MR51_A0 == 0x7B );
                        REQUIRE( l_msg_block.MR51_A1 == 0x7B );
                        REQUIRE( l_msg_block.MR51_A2 == 0x7B );
                        REQUIRE( l_msg_block.MR51_A3 == 0x7B );
                        REQUIRE( l_msg_block.MR51_B0 == 0x7B );
                        REQUIRE( l_msg_block.MR51_B1 == 0x7B );
                        REQUIRE( l_msg_block.MR51_B2 == 0x7B );
                        REQUIRE( l_msg_block.MR51_B3 == 0x7B );
                        REQUIRE( l_msg_block.MR52_A0 == 0x6C );
                        REQUIRE( l_msg_block.MR52_A1 == 0x6C );
                        REQUIRE( l_msg_block.MR52_A2 == 0x6C );
                        REQUIRE( l_msg_block.MR52_A3 == 0x6C );
                        REQUIRE( l_msg_block.MR52_B0 == 0x6C );
                        REQUIRE( l_msg_block.MR52_B1 == 0x6C );
                        REQUIRE( l_msg_block.MR52_B2 == 0x6C );
                        REQUIRE( l_msg_block.MR52_B3 == 0x6C );
                        REQUIRE( l_msg_block.DFE_GainBias_A0 == 0x0B );
                        REQUIRE( l_msg_block.DFE_GainBias_A1 == 0x0B );
                        REQUIRE( l_msg_block.DFE_GainBias_A2 == 0x02 );
                        REQUIRE( l_msg_block.DFE_GainBias_A3 == 0x02 );
                        REQUIRE( l_msg_block.DFE_GainBias_B0 == 0x0B );
                        REQUIRE( l_msg_block.DFE_GainBias_B1 == 0x0B );
                        REQUIRE( l_msg_block.DFE_GainBias_B2 == 0x02 );
                        REQUIRE( l_msg_block.DFE_GainBias_B3 == 0x02 );
                        REQUIRE( l_msg_block.ReservedF6 == 0x00 );
                        REQUIRE( l_msg_block.ReservedF7 == 0x00 );
                        REQUIRE( l_msg_block.ReservedF8 == 0x00 );
                        REQUIRE( l_msg_block.ReservedF9 == 0x00 );
                        REQUIRE( l_msg_block.BCW04_next == 0x00 );
                        REQUIRE( l_msg_block.BCW05_next == 0x00 );
                        REQUIRE( l_msg_block.WR_RD_RTT_PARK_A0 == 0x35 );
                        REQUIRE( l_msg_block.WR_RD_RTT_PARK_A1 == 0x35 );
                        REQUIRE( l_msg_block.WR_RD_RTT_PARK_A2 == 0x46 );
                        REQUIRE( l_msg_block.WR_RD_RTT_PARK_A3 == 0x46 );
                        REQUIRE( l_msg_block.WR_RD_RTT_PARK_B0 == 0x35 );
                        REQUIRE( l_msg_block.WR_RD_RTT_PARK_B1 == 0x35 );
                        REQUIRE( l_msg_block.WR_RD_RTT_PARK_B2 == 0x46 );
                        REQUIRE( l_msg_block.WR_RD_RTT_PARK_B3 == 0x46 );
                        REQUIRE( l_msg_block.Reserved1E2 == 0x3C );
                        REQUIRE( l_msg_block.Reserved1E3 == 0x00 );
                        REQUIRE( l_msg_block.Reserved1E4 == 0x49 );
                        REQUIRE( l_msg_block.Reserved1E5 == 0x00 );
                        REQUIRE( l_msg_block.Reserved1E6 == 0x00 );
                        REQUIRE( l_msg_block.Reserved1E7 == 0x00 );
                        REQUIRE( l_msg_block.WL_ADJ_START == 0x0060 );
                        REQUIRE( l_msg_block.WL_ADJ_END == 0x00A0 );
                        REQUIRE( l_msg_block.VrefDqR0Nib0 == 0x25 );
                        REQUIRE( l_msg_block.VrefDqR0Nib3 == 0x27 );
                        REQUIRE( l_msg_block.VrefDqR0Nib11 == 0x29 );
                        REQUIRE( l_msg_block.VrefDqR0Nib17 == 0x2B );
                        REQUIRE( l_msg_block.VrefDqR1Nib0 == 0x25 );
                        REQUIRE( l_msg_block.VrefDqR1Nib3 == 0x27 );
                        REQUIRE( l_msg_block.VrefDqR1Nib11 == 0x29 );
                        REQUIRE( l_msg_block.VrefDqR1Nib17 == 0x2B );
                        REQUIRE( l_msg_block.VrefDqR2Nib0 == 0x26 );
                        REQUIRE( l_msg_block.VrefDqR2Nib6 == 0x28 );
                        REQUIRE( l_msg_block.VrefDqR2Nib9 == 0x2A );
                        REQUIRE( l_msg_block.VrefDqR2Nib18 == 0x2C );
                        REQUIRE( l_msg_block.VrefDqR3Nib0 == 0x26 );
                        REQUIRE( l_msg_block.VrefDqR3Nib6 == 0x28 );
                        REQUIRE( l_msg_block.VrefDqR3Nib9 == 0x2A );
                        REQUIRE( l_msg_block.VrefDqR3Nib18 == 0x2C );
                        REQUIRE( l_msg_block.MR3R0Nib0 == 0x0B );
                        REQUIRE( l_msg_block.MR3R0Nib1 == 0x0C );
                        REQUIRE( l_msg_block.MR3R0Nib5 == 0x0D );
                        REQUIRE( l_msg_block.MR3R0Nib10 == 0x0E );
                        REQUIRE( l_msg_block.MR3R1Nib0 == 0x0B );
                        REQUIRE( l_msg_block.MR3R1Nib1 == 0x0C );
                        REQUIRE( l_msg_block.MR3R1Nib5 == 0x0D );
                        REQUIRE( l_msg_block.MR3R1Nib10 == 0x0E );
                        REQUIRE( l_msg_block.MR3R2Nib0 == 0x02 );
                        REQUIRE( l_msg_block.MR3R2Nib2 == 0x03 );
                        REQUIRE( l_msg_block.MR3R2Nib6 == 0x04 );
                        REQUIRE( l_msg_block.MR3R2Nib12 == 0x05 );
                        REQUIRE( l_msg_block.MR3R3Nib0 == 0x02 );
                        REQUIRE( l_msg_block.MR3R3Nib2 == 0x03 );
                        REQUIRE( l_msg_block.MR3R3Nib6 == 0x04 );
                        REQUIRE( l_msg_block.MR3R3Nib12 == 0x05 );
                        REQUIRE( l_msg_block.VrefCSR0Nib0 == 0x29 );
                        REQUIRE( l_msg_block.VrefCSR0Nib6 == 0x2B );
                        REQUIRE( l_msg_block.VrefCSR0Nib12 == 0x2D );
                        REQUIRE( l_msg_block.VrefCSR0Nib18 == 0x2F );
                        REQUIRE( l_msg_block.VrefCSR1Nib0 == 0x29 );
                        REQUIRE( l_msg_block.VrefCSR1Nib6 == 0x2B );
                        REQUIRE( l_msg_block.VrefCSR1Nib12 == 0x2D );
                        REQUIRE( l_msg_block.VrefCSR1Nib18 == 0x2F );
                        REQUIRE( l_msg_block.VrefCSR2Nib0 == 0x2A );
                        REQUIRE( l_msg_block.VrefCSR2Nib7 == 0x2C );
                        REQUIRE( l_msg_block.VrefCSR2Nib14 == 0x2E );
                        REQUIRE( l_msg_block.VrefCSR2Nib19 == 0x30 );
                        REQUIRE( l_msg_block.VrefCSR3Nib0 == 0x2A );
                        REQUIRE( l_msg_block.VrefCSR3Nib7 == 0x2C );
                        REQUIRE( l_msg_block.VrefCSR3Nib14 == 0x2E );
                        REQUIRE( l_msg_block.VrefCSR3Nib19 == 0x30 );
                        REQUIRE( l_msg_block.VrefCAR0Nib0 == 0x27 );
                        REQUIRE( l_msg_block.VrefCAR0Nib5 == 0x29 );
                        REQUIRE( l_msg_block.VrefCAR0Nib10 == 0x2B );
                        REQUIRE( l_msg_block.VrefCAR0Nib15 == 0x2D );
                        REQUIRE( l_msg_block.VrefCAR1Nib0 == 0x27 );
                        REQUIRE( l_msg_block.VrefCAR1Nib5 == 0x29 );
                        REQUIRE( l_msg_block.VrefCAR1Nib10 == 0x2B );
                        REQUIRE( l_msg_block.VrefCAR1Nib15 == 0x2D );
                        REQUIRE( l_msg_block.VrefCAR2Nib0 == 0x28 );
                        REQUIRE( l_msg_block.VrefCAR2Nib4 == 0x2A );
                        REQUIRE( l_msg_block.VrefCAR2Nib8 == 0x2C );
                        REQUIRE( l_msg_block.VrefCAR2Nib12 == 0x2E );
                        REQUIRE( l_msg_block.VrefCAR3Nib0 == 0x28 );
                        REQUIRE( l_msg_block.VrefCAR3Nib4 == 0x2A );
                        REQUIRE( l_msg_block.VrefCAR3Nib8 == 0x2C );
                        REQUIRE( l_msg_block.VrefCAR3Nib12 == 0x2E );
                        REQUIRE( l_msg_block.DisabledDB0LaneR0 == 0xFF );
                        REQUIRE( l_msg_block.DisabledDB1LaneR0 == 0xFF );
                        REQUIRE( l_msg_block.DisabledDB2LaneR0 == 0xFF );
                        REQUIRE( l_msg_block.DisabledDB3LaneR0 == 0xFF );
                        REQUIRE( l_msg_block.DisabledDB4LaneR0 == 0x00 );
                        REQUIRE( l_msg_block.DisabledDB5LaneR0 == 0xFF );
                        REQUIRE( l_msg_block.DisabledDB6LaneR0 == 0xFF );
                        REQUIRE (l_msg_block.DisabledDB7LaneR0 == 0xFF );
                        REQUIRE( l_msg_block.DisabledDB8LaneR0 == 0x00 );
                        REQUIRE( l_msg_block.DisabledDB9LaneR0 == 0xFF );

                    }

                    // Restore the attributes
                    REQUIRE_RC_PASS(mss::attr::set_supported_rcd(l_port, l_supported_rcd_save));
                    REQUIRE_RC_PASS(mss::attr::set_phy_adv_train_opt(l_port, l_AdvTrainOpt_save));
                    REQUIRE_RC_PASS(mss::attr::set_phy_msg_misc(l_port, l_MsgMisc_save));
                    REQUIRE_RC_PASS(mss::attr::set_phy_pll_bypass_en(l_port, l_PllBypassEn_save));
                    REQUIRE_RC_PASS(mss::attr::set_freq(l_port, l_DRAMFreq_save));

                    // TODO: Zen:MST-1668 RCW05_next and RCW06_next: need to decide how to set these
                    //REQUIRE_RC_PASS(mss::attr::set_rcw05_next(l_port, l_RCW05_next_save));
                    //REQUIRE_RC_PASS(mss::attr::set_rcw06_next(l_port, l_RCW06_next_save));

                    REQUIRE_RC_PASS(mss::attr::set_ddr5_rxen_adj(l_port, l_RXEN_ADJ_save));
                    REQUIRE_RC_PASS(mss::attr::set_phy_rx2d_dfe_misc(l_port, l_RX2D_DFE_Misc_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_phy_vref_rd(l_port, l_PhyVref_save));
                    REQUIRE_RC_PASS(mss::attr::set_phy_d5misc(l_port, l_D5Misc_save));
                    REQUIRE_RC_PASS(mss::attr::set_phy_wl_adj(l_port, l_WL_ADJ_save));
                    REQUIRE_RC_PASS(mss::attr::set_phy_sequence_ctrl(l_port, l_SequenceCtrl_save));
                    REQUIRE_RC_PASS(mss::attr::set_ody_draminit_verbosity(l_port, l_HdtCtrl_save));
                    REQUIRE_RC_PASS(mss::attr::set_phy_cfg(l_port, l_PhyCfg_save));
                    REQUIRE_RC_PASS(mss::attr::set_dfimrl_margin(l_port, l_DFIMRLMargin_save));
                    REQUIRE_RC_PASS(mss::attr::set_phy_use_broadcast_mr(l_port, l_UseBroadcastMR_save));
                    REQUIRE_RC_PASS(mss::attr::set_disabled_dbyte(l_port, l_DisabledDbyte_save));
                    REQUIRE_RC_PASS(mss::attr::set_ca_train_options(l_port, l_CATrainOpt_save));
                    REQUIRE_RC_PASS(mss::attr::set_tx2d_dfe_misc(l_port, l_TX2D_DFE_Misc_save));
                    REQUIRE_RC_PASS(mss::attr::set_rx2d_train_opt(l_port, l_RX2D_TrainOpt_save));
                    REQUIRE_RC_PASS(mss::attr::set_tx2d_train_opt(l_port, l_TX2D_TrainOpt_save));
                    REQUIRE_RC_PASS(mss::attr::set_phy_config_override(l_port, l_PhyConfigOverride_save));
                    REQUIRE_RC_PASS(mss::attr::set_phy_enabled_dq_cha(l_port, l_EnabledDQsChA_save));
                    REQUIRE_RC_PASS(mss::attr::set_phy_enabled_dq_chb(l_port, l_EnabledDQsChB_save));
                    REQUIRE_RC_PASS(mss::attr::set_dimm_ranks_configed(l_port, l_CsPresent_save));
                    REQUIRE_RC_PASS(mss::attr::set_dram_cl(l_port, l_cas_latency_save));
                    REQUIRE_RC_PASS(mss::attr::set_burst_length(l_port, l_burst_length_save));
                    REQUIRE_RC_PASS(mss::attr::set_mem_2n_mode(i_target, l_2n_mode_save));
                    REQUIRE_RC_PASS(mss::attr::set_mpsm(l_port, l_mpsm_save));
                    REQUIRE_RC_PASS(mss::attr::set_cs_assert_in_mpc(l_port, l_cs_during_mpc_save));
                    REQUIRE_RC_PASS(mss::attr::set_device15_mpsm(l_port, l_device15_mpsm_save));
                    REQUIRE_RC_PASS(mss::attr::set_internal_wr_timing_mode(l_port, l_internal_wr_timing_save));
                    REQUIRE_RC_PASS(mss::attr::set_wl_internal_cycle_alignment(l_port, l_wr_lvl_internal_lower_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_min_ref_rate(l_port, l_min_refresh_rate_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_ref_wide_range(l_port, l_wide_range_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_ref_tuf(l_port, l_tuf_save));
                    REQUIRE_RC_PASS(mss::attr::set_ref_rate_indic(l_port, l_refresh_interval_rate_save));
                    REQUIRE_RC_PASS(mss::attr::set_dram_pu_drv_imp(l_port, l_pu_drv_imp_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_test_mode(l_port, l_drv_test_mode_supported_save));
                    REQUIRE_RC_PASS(mss::attr::set_dram_pd_drv_imp(l_port, l_pd_drv_imp_save));
                    REQUIRE_RC_PASS(mss::attr::set_dram_twr(l_port, l_wr_recovery_save));
                    REQUIRE_RC_PASS(mss::attr::set_dram_trtp(l_port, l_trtp_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_ck_odt(l_port, l_ck_odt_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_cs_odt(l_port, l_cs_odt_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_rd_preamble(l_port, l_rd_preamble_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_wr_preamble(l_port, l_wr_preamble_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_rd_postamble(l_port, l_rd_postamble_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_wr_postamble(l_port, l_wr_postamble_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_wr_vrefdq(l_port, l_vrefdq_value_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_vrefca(l_port, l_vrefca_value_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_vrefcs(l_port, l_vrefcs_value_save));
                    REQUIRE_RC_PASS(mss::attr::set_dram_tccd_l(l_port, l_tccd_l_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_ecs_mode(l_port, l_ecs_mode_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_ecs_reset_counter(l_port, l_ecs_reset_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_ecs_count_mode(l_port, l_row_count_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_ecs_srank_select(l_port, l_ecs_reg_index_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_ecs_threshold_count(l_port, l_ecs_err_threshold_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_ecs_in_self_refresh(l_port, l_ecs_in_str_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_ecs_writeback(l_port, l_ecs_writeback_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_ecs_x4_writes(l_port, l_x4_writes_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_global_dfe_gain(l_port, l_global_dfe_gain_enable_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_global_dfe_tap1(l_port, l_global_dfe1_enable_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_global_dfe_tap2(l_port, l_global_dfe2_enable_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_global_dfe_tap3(l_port, l_global_dfe3_enable_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_global_dfe_tap4(l_port, l_global_dfe4_enable_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_ca_odt(l_port, l_ca_odt_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_dqs_rtt_park(l_port, l_dqs_rtt_park_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_rtt_park(l_port, l_rtt_park_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_rtt_wr(l_port, l_rtt_wr_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_rtt_nom_wr(l_port, l_rtt_nom_wr_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_rtt_nom_rd(l_port, l_rtt_nom_rd_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_odtlon_wr(l_port, l_odtlon_wr_offset_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_odtloff_wr(l_port, l_odtloff_wr_offset_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_odtlon_wr_nt(l_port, l_odtlon_wr_nt_offset_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_odtloff_wr_nt(l_port, l_odtloff_wr_nt_offset_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_odtlon_rd_nt(l_port, l_odtlon_rd_offset_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_odtloff_rd_nt(l_port, l_odtloff_rd_offset_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_wr_crc_err_status(l_port, l_wr_crc_error_status_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_wr_crc_autodisable_enable(l_port, l_wr_crc_autodisable_enable_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_wr_crc_autodisable_status(l_port, l_wr_crc_autodisable_status_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_wr_crc_autodisable_threshold(l_port, l_wr_crc_autodisable_threshold_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_wr_crc_autodisable_window(l_port, l_wr_crc_autodisable_window_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dfe_gain_bias(l_port, l_dfe_gain_bias_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_dfe_sign_bit(l_port, l_dfe_sign_bit_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_wl_adj_start(l_port, l_wl_adj_start_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_wl_adj_end(l_port, l_wl_adj_end_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_rtt_park_rd(l_port, l_rtt_park_rd_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_rtt_park_wr(l_port, l_rtt_park_wr_save));
                    REQUIRE_RC_PASS(mss::attr::set_ca_dfe_train_options(l_port, l_ca_dfe_train_options_save));
                    REQUIRE_RC_PASS(mss::attr::set_debug_train_options(l_port, l_debug_train_options_save));
                    REQUIRE_RC_PASS(mss::attr::set_nibble_enables(l_port, l_nibbles_enables_save));
                    REQUIRE_RC_PASS(mss::attr::set_ddr5_redundant_cs_en(l_port, l_redundant_cs_orig));
                }
            }

            return 0;
        });
    }

    GIVEN("Tests setting of attributes after draminit has run")
    {
        // Loops over OCMB chip targets that were defined in the associated config
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
        {
            for(const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
            {
                // First, save off attributes
                uint8_t l_orig_ranks[mss::ody::MAX_DIMM_PER_PORT] = {};
                uint8_t l_orig_wl_internal_cycle_alignment[mss::ody::MAX_DIMM_PER_PORT][mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_DRAM]
                    = {};
                uint8_t l_orig_vrefdq[mss::ody::MAX_DIMM_PER_PORT][mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_DRAM] = {};
                uint8_t l_orig_vrefca[mss::ody::MAX_DIMM_PER_PORT][mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_DRAM] = {};
                uint8_t l_orig_vrefcs[mss::ody::MAX_DIMM_PER_PORT][mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_DRAM] = {};
                uint16_t l_orig_fw_rev = 0;
                uint16_t l_orig_internal_fw_rev0 = 0;
                uint16_t l_orig_internal_fw_rev1 = 0;
                uint16_t l_orig_fw_data_addr = 0;
                REQUIRE_RC_PASS(mss::attr::get_num_master_ranks_per_dimm(l_port, l_orig_ranks));
                REQUIRE_RC_PASS(mss::attr::get_wl_internal_cycle_alignment(l_port, l_orig_wl_internal_cycle_alignment));
                REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_wr_vrefdq(l_port, l_orig_vrefdq));
                REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_vrefca(l_port, l_orig_vrefca));
                REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_vrefcs(l_port, l_orig_vrefcs));
                REQUIRE_RC_PASS(mss::attr::get_ody_draminit_fw_revision(l_port, l_orig_fw_rev));
                REQUIRE_RC_PASS(mss::attr::get_ody_draminit_internal_fw_revision0(l_port, l_orig_internal_fw_rev0));
                REQUIRE_RC_PASS(mss::attr::get_ody_draminit_internal_fw_revision1(l_port, l_orig_internal_fw_rev1));
                REQUIRE_RC_PASS(mss::attr::get_ody_draminit_fw_data_addr_offset(l_port, l_orig_fw_data_addr));

                // Sets up two ranks
                uint8_t l_inject_ranks[mss::ody::MAX_DIMM_PER_PORT] = {2, 2};
                REQUIRE_RC_PASS(mss::attr::set_num_master_ranks_per_dimm(l_port, l_inject_ranks));

                // Initialize the structure to use
                _PMU_SMB_DDR5_1D_t l_struct;
                REQUIRE_RC_PASS(mss::ody::phy::configure_dram_train_message_block_hardcodes(l_port, l_struct));

                // Override portions of the structure for tests
                {
                    // MR3 injects
                    l_struct.MR3R0Nib0 = 0x02;
                    l_struct.MR3R0Nib1 = 0x03;
                    l_struct.MR3R0Nib2 = 0x04;
                    l_struct.MR3R0Nib3 = 0x05;
                    l_struct.MR3R0Nib4 = 0x06;
                    l_struct.MR3R0Nib5 = 0x07;
                    l_struct.MR3R0Nib6 = 0x08;
                    l_struct.MR3R0Nib7 = 0x09;
                    l_struct.MR3R0Nib8 = 0x0a;
                    l_struct.MR3R0Nib9 = 0x0b;
                    l_struct.MR3R0Nib10 = 0x0c;
                    l_struct.MR3R0Nib11 = 0x0d;
                    l_struct.MR3R0Nib12 = 0x0e;
                    l_struct.MR3R0Nib13 = 0x0f;
                    l_struct.MR3R0Nib14 = 0x00;
                    l_struct.MR3R0Nib15 = 0x01;
                    l_struct.MR3R0Nib16 = 0x02;
                    l_struct.MR3R0Nib17 = 0x03;
                    l_struct.MR3R0Nib18 = 0x04;
                    l_struct.MR3R0Nib19 = 0x05;
                    l_struct.MR3R1Nib0 = 0x06;
                    l_struct.MR3R1Nib1 = 0x07;
                    l_struct.MR3R1Nib2 = 0x08;
                    l_struct.MR3R1Nib3 = 0x09;
                    l_struct.MR3R1Nib4 = 0x0a;
                    l_struct.MR3R1Nib5 = 0x0b;
                    l_struct.MR3R1Nib6 = 0x0c;
                    l_struct.MR3R1Nib7 = 0x0d;
                    l_struct.MR3R1Nib8 = 0x0e;
                    l_struct.MR3R1Nib9 = 0x0f;
                    l_struct.MR3R1Nib10 = 0x04;
                    l_struct.MR3R1Nib11 = 0x05;
                    l_struct.MR3R1Nib12 = 0x06;
                    l_struct.MR3R1Nib13 = 0x07;
                    l_struct.MR3R1Nib14 = 0x08;
                    l_struct.MR3R1Nib15 = 0x09;
                    l_struct.MR3R1Nib16 = 0x0a;
                    l_struct.MR3R1Nib17 = 0x0b;
                    l_struct.MR3R1Nib18 = 0x0c;
                    l_struct.MR3R1Nib19 = 0x0d;
                    l_struct.MR3R2Nib0 = 0x3e;
                    l_struct.MR3R2Nib1 = 0x3f;
                    l_struct.MR3R2Nib2 = 0x40;
                    l_struct.MR3R2Nib3 = 0x41;
                    l_struct.MR3R2Nib4 = 0x42;
                    l_struct.MR3R2Nib5 = 0x43;
                    l_struct.MR3R2Nib6 = 0x44;
                    l_struct.MR3R2Nib7 = 0x45;
                    l_struct.MR3R2Nib8 = 0x46;
                    l_struct.MR3R2Nib9 = 0x47;
                    l_struct.MR3R2Nib10 = 0x48;
                    l_struct.MR3R2Nib11 = 0x49;
                    l_struct.MR3R2Nib12 = 0x4a;
                    l_struct.MR3R2Nib13 = 0x4b;
                    l_struct.MR3R2Nib14 = 0x4c;
                    l_struct.MR3R2Nib15 = 0x4d;
                    l_struct.MR3R2Nib16 = 0x4e;
                    l_struct.MR3R2Nib17 = 0x4f;
                    l_struct.MR3R2Nib18 = 0x50;
                    l_struct.MR3R2Nib19 = 0x51;
                    l_struct.MR3R3Nib0 = 0x52;
                    l_struct.MR3R3Nib1 = 0x53;
                    l_struct.MR3R3Nib2 = 0x54;
                    l_struct.MR3R3Nib3 = 0x55;
                    l_struct.MR3R3Nib4 = 0x56;
                    l_struct.MR3R3Nib5 = 0x57;
                    l_struct.MR3R3Nib6 = 0x58;
                    l_struct.MR3R3Nib7 = 0x59;
                    l_struct.MR3R3Nib8 = 0x5a;
                    l_struct.MR3R3Nib9 = 0x5b;
                    l_struct.MR3R3Nib10 = 0x5c;
                    l_struct.MR3R3Nib11 = 0x5d;
                    l_struct.MR3R3Nib12 = 0x5e;
                    l_struct.MR3R3Nib13 = 0x5f;
                    l_struct.MR3R3Nib14 = 0x60;
                    l_struct.MR3R3Nib15 = 0x61;
                    l_struct.MR3R3Nib16 = 0x62;
                    l_struct.MR3R3Nib17 = 0x63;
                    l_struct.MR3R3Nib18 = 0x64;
                    l_struct.MR3R3Nib19 = 0x65;

                    // MR10 injects
                    l_struct.VrefDqR0Nib0 = 0x01;
                    l_struct.VrefDqR0Nib1 = 0x02;
                    l_struct.VrefDqR0Nib2 = 0x03;
                    l_struct.VrefDqR0Nib3 = 0x04;
                    l_struct.VrefDqR0Nib4 = 0x05;
                    l_struct.VrefDqR0Nib5 = 0x06;
                    l_struct.VrefDqR0Nib6 = 0x07;
                    l_struct.VrefDqR0Nib7 = 0x08;
                    l_struct.VrefDqR0Nib8 = 0x09;
                    l_struct.VrefDqR0Nib9 = 0x0a;
                    l_struct.VrefDqR0Nib10 = 0x0b;
                    l_struct.VrefDqR0Nib11 = 0x0c;
                    l_struct.VrefDqR0Nib12 = 0x0d;
                    l_struct.VrefDqR0Nib13 = 0x0e;
                    l_struct.VrefDqR0Nib14 = 0x0f;
                    l_struct.VrefDqR0Nib15 = 0x10;
                    l_struct.VrefDqR0Nib16 = 0x11;
                    l_struct.VrefDqR0Nib17 = 0x12;
                    l_struct.VrefDqR0Nib18 = 0x13;
                    l_struct.VrefDqR0Nib19 = 0x14;
                    l_struct.VrefDqR1Nib0 = 0x14;
                    l_struct.VrefDqR1Nib1 = 0x13;
                    l_struct.VrefDqR1Nib2 = 0x12;
                    l_struct.VrefDqR1Nib3 = 0x11;
                    l_struct.VrefDqR1Nib4 = 0x0f;
                    l_struct.VrefDqR1Nib5 = 0x0e;
                    l_struct.VrefDqR1Nib6 = 0x0d;
                    l_struct.VrefDqR1Nib7 = 0x0c;
                    l_struct.VrefDqR1Nib8 = 0x0b;
                    l_struct.VrefDqR1Nib9 = 0x0a;
                    l_struct.VrefDqR1Nib10 = 0x09;
                    l_struct.VrefDqR1Nib11 = 0x08;
                    l_struct.VrefDqR1Nib12 = 0x07;
                    l_struct.VrefDqR1Nib13 = 0x06;
                    l_struct.VrefDqR1Nib14 = 0x05;
                    l_struct.VrefDqR1Nib15 = 0x14;
                    l_struct.VrefDqR1Nib16 = 0x13;
                    l_struct.VrefDqR1Nib17 = 0x12;
                    l_struct.VrefDqR1Nib18 = 0x11;
                    l_struct.VrefDqR1Nib19 = 0x10;
                    l_struct.VrefDqR2Nib0 = 0xba;
                    l_struct.VrefDqR2Nib1 = 0xbb;
                    l_struct.VrefDqR2Nib2 = 0xbc;
                    l_struct.VrefDqR2Nib3 = 0xbd;
                    l_struct.VrefDqR2Nib4 = 0xbe;
                    l_struct.VrefDqR2Nib5 = 0xbf;
                    l_struct.VrefDqR2Nib6 = 0xc0;
                    l_struct.VrefDqR2Nib7 = 0xc1;
                    l_struct.VrefDqR2Nib8 = 0xc2;
                    l_struct.VrefDqR2Nib9 = 0xc3;
                    l_struct.VrefDqR2Nib10 = 0xc4;
                    l_struct.VrefDqR2Nib11 = 0xc5;
                    l_struct.VrefDqR2Nib12 = 0xc6;
                    l_struct.VrefDqR2Nib13 = 0xc7;
                    l_struct.VrefDqR2Nib14 = 0xc8;
                    l_struct.VrefDqR2Nib15 = 0xc9;
                    l_struct.VrefDqR2Nib16 = 0xca;
                    l_struct.VrefDqR2Nib17 = 0xcb;
                    l_struct.VrefDqR2Nib18 = 0xcc;
                    l_struct.VrefDqR2Nib19 = 0xcd;
                    l_struct.VrefDqR3Nib0 = 0xce;
                    l_struct.VrefDqR3Nib1 = 0xcf;
                    l_struct.VrefDqR3Nib2 = 0xd0;
                    l_struct.VrefDqR3Nib3 = 0xd1;
                    l_struct.VrefDqR3Nib4 = 0xd2;
                    l_struct.VrefDqR3Nib5 = 0xd3;
                    l_struct.VrefDqR3Nib6 = 0xd4;
                    l_struct.VrefDqR3Nib7 = 0xd5;
                    l_struct.VrefDqR3Nib8 = 0xd6;
                    l_struct.VrefDqR3Nib9 = 0xd7;
                    l_struct.VrefDqR3Nib10 = 0xd8;
                    l_struct.VrefDqR3Nib11 = 0xd9;
                    l_struct.VrefDqR3Nib12 = 0xda;
                    l_struct.VrefDqR3Nib13 = 0xdb;
                    l_struct.VrefDqR3Nib14 = 0xdc;
                    l_struct.VrefDqR3Nib15 = 0xdd;
                    l_struct.VrefDqR3Nib16 = 0xde;
                    l_struct.VrefDqR3Nib17 = 0xdf;
                    l_struct.VrefDqR3Nib18 = 0xe0;
                    l_struct.VrefDqR3Nib19 = 0xe1;

                    // MR11 injects
                    l_struct.VrefCAR0Nib0 = 0x26;
                    l_struct.VrefCAR0Nib1 = 0x27;
                    l_struct.VrefCAR0Nib2 = 0x28;
                    l_struct.VrefCAR0Nib3 = 0x29;
                    l_struct.VrefCAR0Nib4 = 0x2a;
                    l_struct.VrefCAR0Nib5 = 0x2b;
                    l_struct.VrefCAR0Nib6 = 0x2c;
                    l_struct.VrefCAR0Nib7 = 0x2d;
                    l_struct.VrefCAR0Nib8 = 0x2e;
                    l_struct.VrefCAR0Nib9 = 0x2f;
                    l_struct.VrefCAR0Nib10 = 0x30;
                    l_struct.VrefCAR0Nib11 = 0x31;
                    l_struct.VrefCAR0Nib12 = 0x32;
                    l_struct.VrefCAR0Nib13 = 0x33;
                    l_struct.VrefCAR0Nib14 = 0x34;
                    l_struct.VrefCAR0Nib15 = 0x35;
                    l_struct.VrefCAR0Nib16 = 0x36;
                    l_struct.VrefCAR0Nib17 = 0x37;
                    l_struct.VrefCAR0Nib18 = 0x38;
                    l_struct.VrefCAR0Nib19 = 0x39;
                    l_struct.VrefCAR1Nib0 = 0x4a;
                    l_struct.VrefCAR1Nib1 = 0x4b;
                    l_struct.VrefCAR1Nib2 = 0x4c;
                    l_struct.VrefCAR1Nib3 = 0x4d;
                    l_struct.VrefCAR1Nib4 = 0x4e;
                    l_struct.VrefCAR1Nib5 = 0x4f;
                    l_struct.VrefCAR1Nib6 = 0x50;
                    l_struct.VrefCAR1Nib7 = 0x51;
                    l_struct.VrefCAR1Nib8 = 0x52;
                    l_struct.VrefCAR1Nib9 = 0x53;
                    l_struct.VrefCAR1Nib10 = 0x54;
                    l_struct.VrefCAR1Nib11 = 0x55;
                    l_struct.VrefCAR1Nib12 = 0x56;
                    l_struct.VrefCAR1Nib13 = 0x57;
                    l_struct.VrefCAR1Nib14 = 0x58;
                    l_struct.VrefCAR1Nib15 = 0x59;
                    l_struct.VrefCAR1Nib16 = 0x5a;
                    l_struct.VrefCAR1Nib17 = 0x5b;
                    l_struct.VrefCAR1Nib18 = 0x5c;
                    l_struct.VrefCAR1Nib19 = 0x5d;
                    l_struct.VrefCAR2Nib0 = 0xde;
                    l_struct.VrefCAR2Nib1 = 0xdf;
                    l_struct.VrefCAR2Nib2 = 0xe0;
                    l_struct.VrefCAR2Nib3 = 0xe1;
                    l_struct.VrefCAR2Nib4 = 0xe2;
                    l_struct.VrefCAR2Nib5 = 0xe3;
                    l_struct.VrefCAR2Nib6 = 0xe4;
                    l_struct.VrefCAR2Nib7 = 0xe5;
                    l_struct.VrefCAR2Nib8 = 0xe6;
                    l_struct.VrefCAR2Nib9 = 0xe7;
                    l_struct.VrefCAR2Nib10 = 0xe8;
                    l_struct.VrefCAR2Nib11 = 0xe9;
                    l_struct.VrefCAR2Nib12 = 0xea;
                    l_struct.VrefCAR2Nib13 = 0xeb;
                    l_struct.VrefCAR2Nib14 = 0xec;
                    l_struct.VrefCAR2Nib15 = 0xed;
                    l_struct.VrefCAR2Nib16 = 0xee;
                    l_struct.VrefCAR2Nib17 = 0xef;
                    l_struct.VrefCAR2Nib18 = 0xf0;
                    l_struct.VrefCAR2Nib19 = 0xf1;
                    l_struct.VrefCAR3Nib0 = 0xf2;
                    l_struct.VrefCAR3Nib1 = 0xf3;
                    l_struct.VrefCAR3Nib2 = 0xf4;
                    l_struct.VrefCAR3Nib3 = 0xf5;
                    l_struct.VrefCAR3Nib4 = 0xf6;
                    l_struct.VrefCAR3Nib5 = 0xf7;
                    l_struct.VrefCAR3Nib6 = 0xf8;
                    l_struct.VrefCAR3Nib7 = 0xf9;
                    l_struct.VrefCAR3Nib8 = 0xfa;
                    l_struct.VrefCAR3Nib9 = 0xfb;
                    l_struct.VrefCAR3Nib10 = 0xfc;
                    l_struct.VrefCAR3Nib11 = 0xfd;
                    l_struct.VrefCAR3Nib12 = 0xfe;
                    l_struct.VrefCAR3Nib13 = 0xff;
                    l_struct.VrefCAR3Nib14 = 0x34;
                    l_struct.VrefCAR3Nib15 = 0x35;
                    l_struct.VrefCAR3Nib16 = 0x36;
                    l_struct.VrefCAR3Nib17 = 0x37;
                    l_struct.VrefCAR3Nib18 = 0x38;
                    l_struct.VrefCAR3Nib19 = 0x39;

                    // MR12 injects
                    l_struct.VrefCSR0Nib0 = 0x66;
                    l_struct.VrefCSR0Nib1 = 0x67;
                    l_struct.VrefCSR0Nib2 = 0x68;
                    l_struct.VrefCSR0Nib3 = 0x69;
                    l_struct.VrefCSR0Nib4 = 0x6a;
                    l_struct.VrefCSR0Nib5 = 0x6b;
                    l_struct.VrefCSR0Nib6 = 0x6c;
                    l_struct.VrefCSR0Nib7 = 0x6d;
                    l_struct.VrefCSR0Nib8 = 0x6e;
                    l_struct.VrefCSR0Nib9 = 0x6f;
                    l_struct.VrefCSR0Nib10 = 0x50;
                    l_struct.VrefCSR0Nib11 = 0x51;
                    l_struct.VrefCSR0Nib12 = 0x52;
                    l_struct.VrefCSR0Nib13 = 0x53;
                    l_struct.VrefCSR0Nib14 = 0x54;
                    l_struct.VrefCSR0Nib15 = 0x55;
                    l_struct.VrefCSR0Nib16 = 0x56;
                    l_struct.VrefCSR0Nib17 = 0x57;
                    l_struct.VrefCSR0Nib18 = 0x58;
                    l_struct.VrefCSR0Nib19 = 0x59;
                    l_struct.VrefCSR1Nib0 = 0x5a;
                    l_struct.VrefCSR1Nib1 = 0x5b;
                    l_struct.VrefCSR1Nib2 = 0x5c;
                    l_struct.VrefCSR1Nib3 = 0x5d;
                    l_struct.VrefCSR1Nib4 = 0x5e;
                    l_struct.VrefCSR1Nib5 = 0x5f;
                    l_struct.VrefCSR1Nib6 = 0x20;
                    l_struct.VrefCSR1Nib7 = 0x21;
                    l_struct.VrefCSR1Nib8 = 0x22;
                    l_struct.VrefCSR1Nib9 = 0x23;
                    l_struct.VrefCSR1Nib10 = 0x24;
                    l_struct.VrefCSR1Nib11 = 0x25;
                    l_struct.VrefCSR1Nib12 = 0x26;
                    l_struct.VrefCSR1Nib13 = 0x27;
                    l_struct.VrefCSR1Nib14 = 0x28;
                    l_struct.VrefCSR1Nib15 = 0x29;
                    l_struct.VrefCSR1Nib16 = 0x2a;
                    l_struct.VrefCSR1Nib17 = 0x2b;
                    l_struct.VrefCSR1Nib18 = 0x2c;
                    l_struct.VrefCSR1Nib19 = 0x2d;
                    l_struct.VrefCSR2Nib0 = 0x8e;
                    l_struct.VrefCSR2Nib1 = 0x8f;
                    l_struct.VrefCSR2Nib2 = 0x90;
                    l_struct.VrefCSR2Nib3 = 0x91;
                    l_struct.VrefCSR2Nib4 = 0x92;
                    l_struct.VrefCSR2Nib5 = 0x93;
                    l_struct.VrefCSR2Nib6 = 0x94;
                    l_struct.VrefCSR2Nib7 = 0x95;
                    l_struct.VrefCSR2Nib8 = 0x96;
                    l_struct.VrefCSR2Nib9 = 0x97;
                    l_struct.VrefCSR2Nib10 = 0x98;
                    l_struct.VrefCSR2Nib11 = 0x99;
                    l_struct.VrefCSR2Nib12 = 0x9a;
                    l_struct.VrefCSR2Nib13 = 0x9b;
                    l_struct.VrefCSR2Nib14 = 0x9c;
                    l_struct.VrefCSR2Nib15 = 0x9d;
                    l_struct.VrefCSR2Nib16 = 0x9e;
                    l_struct.VrefCSR2Nib17 = 0x9f;
                    l_struct.VrefCSR2Nib18 = 0xa0;
                    l_struct.VrefCSR2Nib19 = 0xa1;
                    l_struct.VrefCSR3Nib0 = 0xa2;
                    l_struct.VrefCSR3Nib1 = 0xa3;
                    l_struct.VrefCSR3Nib2 = 0xa4;
                    l_struct.VrefCSR3Nib3 = 0xa5;
                    l_struct.VrefCSR3Nib4 = 0xa6;
                    l_struct.VrefCSR3Nib5 = 0xa7;
                    l_struct.VrefCSR3Nib6 = 0xa8;
                    l_struct.VrefCSR3Nib7 = 0xa9;
                    l_struct.VrefCSR3Nib8 = 0xaa;
                    l_struct.VrefCSR3Nib9 = 0xab;
                    l_struct.VrefCSR3Nib10 = 0xac;
                    l_struct.VrefCSR3Nib11 = 0xad;
                    l_struct.VrefCSR3Nib12 = 0xae;
                    l_struct.VrefCSR3Nib13 = 0xaf;
                    l_struct.VrefCSR3Nib14 = 0xb0;
                    l_struct.VrefCSR3Nib15 = 0xb1;
                    l_struct.VrefCSR3Nib16 = 0xb2;
                    l_struct.VrefCSR3Nib17 = 0xb3;
                    l_struct.VrefCSR3Nib18 = 0xb4;
                    l_struct.VrefCSR3Nib19 = 0xb5;

                    // Generic inputs
                    l_struct.PmuRevision      = 0x1234;
                    l_struct.PmuInternalRev0  = 0x2345;
                    l_struct.PmuInternalRev1  = 0x3456;
                    l_struct.ResultAddrOffset = 0x4567;
                }

                // Run tests and check the expected values
                {
                    // Sets up the expected results
                    uint8_t l_exp_wl_internal_cycle_alignment[mss::ody::MAX_DIMM_PER_PORT][mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_DRAM]
                        = {};
                    uint8_t l_exp_vrefdq[mss::ody::MAX_DIMM_PER_PORT][mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_DRAM] = {};
                    uint8_t l_exp_vrefca[mss::ody::MAX_DIMM_PER_PORT][mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_DRAM] = {};
                    uint8_t l_exp_vrefcs[mss::ody::MAX_DIMM_PER_PORT][mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_DRAM] = {};
                    constexpr uint16_t l_exp_fw_rev = 0x1234;
                    constexpr uint16_t l_exp_internal_fw_rev0 = 0x2345;
                    constexpr uint16_t l_exp_internal_fw_rev1 = 0x3456;
                    constexpr uint16_t l_exp_fw_data_addr = 0x4567;
                    REQUIRE_RC_PASS(mss::attr::get_wl_internal_cycle_alignment(l_port, l_exp_wl_internal_cycle_alignment));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_wr_vrefdq(l_port, l_exp_vrefdq));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_vrefca(l_port, l_exp_vrefca));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_vrefcs(l_port, l_exp_vrefcs));

                    // MR3 expected
                    {
                        l_exp_wl_internal_cycle_alignment[0][0][0] = 0x02;
                        l_exp_wl_internal_cycle_alignment[0][0][1] = 0x03;
                        l_exp_wl_internal_cycle_alignment[0][0][2] = 0x04;
                        l_exp_wl_internal_cycle_alignment[0][0][3] = 0x05;
                        l_exp_wl_internal_cycle_alignment[0][0][4] = 0x06;
                        l_exp_wl_internal_cycle_alignment[0][0][5] = 0x07;
                        l_exp_wl_internal_cycle_alignment[0][0][6] = 0x08;
                        l_exp_wl_internal_cycle_alignment[0][0][7] = 0x09;
                        l_exp_wl_internal_cycle_alignment[0][0][8] = 0x0a;
                        l_exp_wl_internal_cycle_alignment[0][0][9] = 0x0b;
                        l_exp_wl_internal_cycle_alignment[0][0][10] = 0x0c;
                        l_exp_wl_internal_cycle_alignment[0][0][11] = 0x0d;
                        l_exp_wl_internal_cycle_alignment[0][0][12] = 0x0e;
                        l_exp_wl_internal_cycle_alignment[0][0][13] = 0x0f;
                        l_exp_wl_internal_cycle_alignment[0][0][14] = 0x00;
                        l_exp_wl_internal_cycle_alignment[0][0][15] = 0x01;
                        l_exp_wl_internal_cycle_alignment[0][0][16] = 0x02;
                        l_exp_wl_internal_cycle_alignment[0][0][17] = 0x03;
                        l_exp_wl_internal_cycle_alignment[0][0][18] = 0x04;
                        l_exp_wl_internal_cycle_alignment[0][0][19] = 0x05;
                        l_exp_wl_internal_cycle_alignment[0][1][0] = 0x06;
                        l_exp_wl_internal_cycle_alignment[0][1][1] = 0x07;
                        l_exp_wl_internal_cycle_alignment[0][1][2] = 0x08;
                        l_exp_wl_internal_cycle_alignment[0][1][3] = 0x09;
                        l_exp_wl_internal_cycle_alignment[0][1][4] = 0x0a;
                        l_exp_wl_internal_cycle_alignment[0][1][5] = 0x0b;
                        l_exp_wl_internal_cycle_alignment[0][1][6] = 0x0c;
                        l_exp_wl_internal_cycle_alignment[0][1][7] = 0x0d;
                        l_exp_wl_internal_cycle_alignment[0][1][8] = 0x0e;
                        l_exp_wl_internal_cycle_alignment[0][1][9] = 0x0f;
                        l_exp_wl_internal_cycle_alignment[0][1][10] = 0x04;
                        l_exp_wl_internal_cycle_alignment[0][1][11] = 0x05;
                        l_exp_wl_internal_cycle_alignment[0][1][12] = 0x06;
                        l_exp_wl_internal_cycle_alignment[0][1][13] = 0x07;
                        l_exp_wl_internal_cycle_alignment[0][1][14] = 0x08;
                        l_exp_wl_internal_cycle_alignment[0][1][15] = 0x09;
                        l_exp_wl_internal_cycle_alignment[0][1][16] = 0x0a;
                        l_exp_wl_internal_cycle_alignment[0][1][17] = 0x0b;
                        l_exp_wl_internal_cycle_alignment[0][1][18] = 0x0c;
                        l_exp_wl_internal_cycle_alignment[0][1][19] = 0x0d;
                    }

                    // MR10 expected
                    {
                        l_exp_vrefdq[0][0][0] = 0x01;
                        l_exp_vrefdq[0][0][1] = 0x02;
                        l_exp_vrefdq[0][0][2] = 0x03;
                        l_exp_vrefdq[0][0][3] = 0x04;
                        l_exp_vrefdq[0][0][4] = 0x05;
                        l_exp_vrefdq[0][0][5] = 0x06;
                        l_exp_vrefdq[0][0][6] = 0x07;
                        l_exp_vrefdq[0][0][7] = 0x08;
                        l_exp_vrefdq[0][0][8] = 0x09;
                        l_exp_vrefdq[0][0][9] = 0x0a;
                        l_exp_vrefdq[0][0][10] = 0x0b;
                        l_exp_vrefdq[0][0][11] = 0x0c;
                        l_exp_vrefdq[0][0][12] = 0x0d;
                        l_exp_vrefdq[0][0][13] = 0x0e;
                        l_exp_vrefdq[0][0][14] = 0x0f;
                        l_exp_vrefdq[0][0][15] = 0x10;
                        l_exp_vrefdq[0][0][16] = 0x11;
                        l_exp_vrefdq[0][0][17] = 0x12;
                        l_exp_vrefdq[0][0][18] = 0x13;
                        l_exp_vrefdq[0][0][19] = 0x14;
                        l_exp_vrefdq[0][1][0] = 0x14;
                        l_exp_vrefdq[0][1][1] = 0x13;
                        l_exp_vrefdq[0][1][2] = 0x12;
                        l_exp_vrefdq[0][1][3] = 0x11;
                        l_exp_vrefdq[0][1][4] = 0x0f;
                        l_exp_vrefdq[0][1][5] = 0x0e;
                        l_exp_vrefdq[0][1][6] = 0x0d;
                        l_exp_vrefdq[0][1][7] = 0x0c;
                        l_exp_vrefdq[0][1][8] = 0x0b;
                        l_exp_vrefdq[0][1][9] = 0x0a;
                        l_exp_vrefdq[0][1][10] = 0x09;
                        l_exp_vrefdq[0][1][11] = 0x08;
                        l_exp_vrefdq[0][1][12] = 0x07;
                        l_exp_vrefdq[0][1][13] = 0x06;
                        l_exp_vrefdq[0][1][14] = 0x05;
                        l_exp_vrefdq[0][1][15] = 0x14;
                        l_exp_vrefdq[0][1][16] = 0x13;
                        l_exp_vrefdq[0][1][17] = 0x12;
                        l_exp_vrefdq[0][1][18] = 0x11;
                        l_exp_vrefdq[0][1][19] = 0x10;
                    }

                    // MR11 expected
                    {
                        l_exp_vrefca[0][0][0] = 0x26;
                        l_exp_vrefca[0][0][1] = 0x27;
                        l_exp_vrefca[0][0][2] = 0x28;
                        l_exp_vrefca[0][0][3] = 0x29;
                        l_exp_vrefca[0][0][4] = 0x2a;
                        l_exp_vrefca[0][0][5] = 0x2b;
                        l_exp_vrefca[0][0][6] = 0x2c;
                        l_exp_vrefca[0][0][7] = 0x2d;
                        l_exp_vrefca[0][0][8] = 0x2e;
                        l_exp_vrefca[0][0][9] = 0x2f;
                        l_exp_vrefca[0][0][10] = 0x30;
                        l_exp_vrefca[0][0][11] = 0x31;
                        l_exp_vrefca[0][0][12] = 0x32;
                        l_exp_vrefca[0][0][13] = 0x33;
                        l_exp_vrefca[0][0][14] = 0x34;
                        l_exp_vrefca[0][0][15] = 0x35;
                        l_exp_vrefca[0][0][16] = 0x36;
                        l_exp_vrefca[0][0][17] = 0x37;
                        l_exp_vrefca[0][0][18] = 0x38;
                        l_exp_vrefca[0][0][19] = 0x39;
                        l_exp_vrefca[0][1][0] = 0x4a;
                        l_exp_vrefca[0][1][1] = 0x4b;
                        l_exp_vrefca[0][1][2] = 0x4c;
                        l_exp_vrefca[0][1][3] = 0x4d;
                        l_exp_vrefca[0][1][4] = 0x4e;
                        l_exp_vrefca[0][1][5] = 0x4f;
                        l_exp_vrefca[0][1][6] = 0x50;
                        l_exp_vrefca[0][1][7] = 0x51;
                        l_exp_vrefca[0][1][8] = 0x52;
                        l_exp_vrefca[0][1][9] = 0x53;
                        l_exp_vrefca[0][1][10] = 0x54;
                        l_exp_vrefca[0][1][11] = 0x55;
                        l_exp_vrefca[0][1][12] = 0x56;
                        l_exp_vrefca[0][1][13] = 0x57;
                        l_exp_vrefca[0][1][14] = 0x58;
                        l_exp_vrefca[0][1][15] = 0x59;
                        l_exp_vrefca[0][1][16] = 0x5a;
                        l_exp_vrefca[0][1][17] = 0x5b;
                        l_exp_vrefca[0][1][18] = 0x5c;
                        l_exp_vrefca[0][1][19] = 0x5d;
                    }

                    // MR12 expected
                    {
                        l_exp_vrefcs[0][0][0] = 0x66;
                        l_exp_vrefcs[0][0][1] = 0x67;
                        l_exp_vrefcs[0][0][2] = 0x68;
                        l_exp_vrefcs[0][0][3] = 0x69;
                        l_exp_vrefcs[0][0][4] = 0x6a;
                        l_exp_vrefcs[0][0][5] = 0x6b;
                        l_exp_vrefcs[0][0][6] = 0x6c;
                        l_exp_vrefcs[0][0][7] = 0x6d;
                        l_exp_vrefcs[0][0][8] = 0x6e;
                        l_exp_vrefcs[0][0][9] = 0x6f;
                        l_exp_vrefcs[0][0][10] = 0x50;
                        l_exp_vrefcs[0][0][11] = 0x51;
                        l_exp_vrefcs[0][0][12] = 0x52;
                        l_exp_vrefcs[0][0][13] = 0x53;
                        l_exp_vrefcs[0][0][14] = 0x54;
                        l_exp_vrefcs[0][0][15] = 0x55;
                        l_exp_vrefcs[0][0][16] = 0x56;
                        l_exp_vrefcs[0][0][17] = 0x57;
                        l_exp_vrefcs[0][0][18] = 0x58;
                        l_exp_vrefcs[0][0][19] = 0x59;
                        l_exp_vrefcs[0][1][0] = 0x5a;
                        l_exp_vrefcs[0][1][1] = 0x5b;
                        l_exp_vrefcs[0][1][2] = 0x5c;
                        l_exp_vrefcs[0][1][3] = 0x5d;
                        l_exp_vrefcs[0][1][4] = 0x5e;
                        l_exp_vrefcs[0][1][5] = 0x5f;
                        l_exp_vrefcs[0][1][6] = 0x20;
                        l_exp_vrefcs[0][1][7] = 0x21;
                        l_exp_vrefcs[0][1][8] = 0x22;
                        l_exp_vrefcs[0][1][9] = 0x23;
                        l_exp_vrefcs[0][1][10] = 0x24;
                        l_exp_vrefcs[0][1][11] = 0x25;
                        l_exp_vrefcs[0][1][12] = 0x26;
                        l_exp_vrefcs[0][1][13] = 0x27;
                        l_exp_vrefcs[0][1][14] = 0x28;
                        l_exp_vrefcs[0][1][15] = 0x29;
                        l_exp_vrefcs[0][1][16] = 0x2a;
                        l_exp_vrefcs[0][1][17] = 0x2b;
                        l_exp_vrefcs[0][1][18] = 0x2c;
                        l_exp_vrefcs[0][1][19] = 0x2d;
                    }

                    // Runs the test
                    REQUIRE_RC_PASS(mss::ody::phy::set_attributes(l_port, l_struct));

                    // Checks the expected vs actual values
                    uint8_t l_act_wl_internal_cycle_alignment[mss::ody::MAX_DIMM_PER_PORT][mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_DRAM]
                        = {};
                    uint8_t l_act_vrefdq[mss::ody::MAX_DIMM_PER_PORT][mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_DRAM] = {};
                    uint8_t l_act_vrefca[mss::ody::MAX_DIMM_PER_PORT][mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_DRAM] = {};
                    uint8_t l_act_vrefcs[mss::ody::MAX_DIMM_PER_PORT][mss::ddr5::mr::ATTR_RANKS][mss::ddr5::mr::ATTR_DRAM] = {};
                    uint16_t l_act_fw_rev = 0;
                    uint16_t l_act_internal_fw_rev0 = 0;
                    uint16_t l_act_internal_fw_rev1 = 0;
                    uint16_t l_act_fw_data_addr = 0;
                    REQUIRE_RC_PASS(mss::attr::get_wl_internal_cycle_alignment(l_port, l_act_wl_internal_cycle_alignment));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_wr_vrefdq(l_port, l_act_vrefdq));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_vrefca(l_port, l_act_vrefca));
                    REQUIRE_RC_PASS(mss::attr::get_ddr5_dram_vrefcs(l_port, l_act_vrefcs));
                    REQUIRE_RC_PASS(mss::attr::get_ody_draminit_fw_revision(l_port, l_act_fw_rev));
                    REQUIRE_RC_PASS(mss::attr::get_ody_draminit_internal_fw_revision0(l_port, l_act_internal_fw_rev0));
                    REQUIRE_RC_PASS(mss::attr::get_ody_draminit_internal_fw_revision1(l_port, l_act_internal_fw_rev1));
                    REQUIRE_RC_PASS(mss::attr::get_ody_draminit_fw_data_addr_offset(l_port, l_act_fw_data_addr));

                    REQUIRE(l_exp_fw_rev == l_act_fw_rev);
                    REQUIRE(l_exp_internal_fw_rev0 == l_act_internal_fw_rev0);
                    REQUIRE(l_exp_internal_fw_rev1 == l_act_internal_fw_rev1);
                    REQUIRE(l_exp_fw_data_addr == l_act_fw_data_addr);

                    REQUIRE(memcmp(&l_exp_wl_internal_cycle_alignment[0][0][0], &l_act_wl_internal_cycle_alignment[0][0][0],
                                   sizeof(l_act_wl_internal_cycle_alignment)) == mss::MEMCMP_EQUAL);
                    REQUIRE(memcmp(&l_exp_vrefdq[0][0][0], &l_act_vrefdq[0][0][0], sizeof(l_act_vrefdq)) == mss::MEMCMP_EQUAL);
                    REQUIRE(memcmp(&l_exp_vrefca[0][0][0], &l_act_vrefca[0][0][0], sizeof(l_act_vrefca)) == mss::MEMCMP_EQUAL);
                    REQUIRE(memcmp(&l_exp_vrefcs[0][0][0], &l_act_vrefcs[0][0][0], sizeof(l_act_vrefcs)) == mss::MEMCMP_EQUAL);
                }

                // Restore attributes
                REQUIRE_RC_PASS(mss::attr::set_num_master_ranks_per_dimm(l_port, l_orig_ranks));
                REQUIRE_RC_PASS(mss::attr::set_wl_internal_cycle_alignment(l_port, l_orig_wl_internal_cycle_alignment));
                REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_wr_vrefdq(l_port, l_orig_vrefdq));
                REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_vrefca(l_port, l_orig_vrefca));
                REQUIRE_RC_PASS(mss::attr::set_ddr5_dram_vrefcs(l_port, l_orig_vrefcs));
                REQUIRE_RC_PASS(mss::attr::set_ody_draminit_fw_revision(l_port, l_orig_fw_rev));
                REQUIRE_RC_PASS(mss::attr::set_ody_draminit_internal_fw_revision0(l_port, l_orig_internal_fw_rev0));
                REQUIRE_RC_PASS(mss::attr::set_ody_draminit_internal_fw_revision1(l_port, l_orig_internal_fw_rev1));
                REQUIRE_RC_PASS(mss::attr::set_ody_draminit_fw_data_addr_offset(l_port, l_orig_fw_data_addr));
            }

            return 0;
        });
    }

    GIVEN("Tests check_training_result")
    {
        // Loops over OCMB chip targets that were defined in the associated config
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
        {
            for(const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
            {
                _PMU_SMB_DDR5_1D_t l_struct;
                uint64_t l_mail = 0;
                uint8_t l_dq_bitmap_save[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT] = {};

                // Initialize some training lane fails in the message block
                l_struct.DisabledDB0LaneR0 = 0x00;
                l_struct.DisabledDB1LaneR0 = 0x01;
                l_struct.DisabledDB2LaneR0 = 0x02;
                l_struct.DisabledDB3LaneR0 = 0x03;
                l_struct.DisabledDB4LaneR0 = 0x04;
                l_struct.DisabledDB5LaneR0 = 0x05;
                l_struct.DisabledDB6LaneR0 = 0x06;
                l_struct.DisabledDB7LaneR0 = 0x07;
                l_struct.DisabledDB8LaneR0 = 0x08;
                l_struct.DisabledDB9LaneR0 = 0x09;
                l_struct.DisabledDB0LaneR1 = 0xA0;
                l_struct.DisabledDB1LaneR1 = 0xA1;
                l_struct.DisabledDB2LaneR1 = 0xA2;
                l_struct.DisabledDB3LaneR1 = 0xA3;
                l_struct.DisabledDB4LaneR1 = 0xA4;
                l_struct.DisabledDB5LaneR1 = 0xA5;
                l_struct.DisabledDB6LaneR1 = 0xA6;
                l_struct.DisabledDB7LaneR1 = 0xA7;
                l_struct.DisabledDB8LaneR1 = 0xA8;
                l_struct.DisabledDB9LaneR1 = 0xA9;
                l_struct.DisabledDB0LaneR2 = 0x20;
                l_struct.DisabledDB1LaneR2 = 0x21;
                l_struct.DisabledDB2LaneR2 = 0x22;
                l_struct.DisabledDB3LaneR2 = 0x23;
                l_struct.DisabledDB4LaneR2 = 0x24;
                l_struct.DisabledDB5LaneR2 = 0x25;
                l_struct.DisabledDB6LaneR2 = 0x26;
                l_struct.DisabledDB7LaneR2 = 0x27;
                l_struct.DisabledDB8LaneR2 = 0x28;
                l_struct.DisabledDB9LaneR2 = 0x29;
                l_struct.DisabledDB0LaneR3 = 0xB0;
                l_struct.DisabledDB1LaneR3 = 0xB1;
                l_struct.DisabledDB2LaneR3 = 0xB2;
                l_struct.DisabledDB3LaneR3 = 0xB3;
                l_struct.DisabledDB4LaneR3 = 0xB4;
                l_struct.DisabledDB5LaneR3 = 0xB5;
                l_struct.DisabledDB6LaneR3 = 0xB6;
                l_struct.DisabledDB7LaneR3 = 0xB7;
                l_struct.DisabledDB8LaneR3 = 0xB8;
                l_struct.DisabledDB9LaneR3 = 0xB9;

                // Save the bad bits attribute
                for(const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_port))
                {
                    REQUIRE_RC_PASS( mss::attr::get_bad_dq_bitmap(l_dimm, l_dq_bitmap_save) );
                }

                // Test failing mail RC
                l_mail = 0xFF;
                l_struct.CsTestFail = 0x00;
                REQUIRE_SPECIFIC_RC_FAIL(mss::ody::phy::check_training_result(l_port, l_mail, l_struct),
                                         fapi2::RC_ODY_DRAMINIT_TRAINING_FAILURE_MAIL);

                for(const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_port))
                {
                    uint8_t l_dq_bitmap[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT] = {};
                    REQUIRE_RC_PASS( mss::attr::get_bad_dq_bitmap(l_dimm, l_dq_bitmap) );
                    REQUIRE(l_dq_bitmap[0][0] == 0x00);
                    REQUIRE(l_dq_bitmap[0][1] == 0x00);
                    REQUIRE(l_dq_bitmap[0][2] == 0x00);
                    REQUIRE(l_dq_bitmap[0][3] == 0x00);
                    REQUIRE(l_dq_bitmap[0][4] == 0x00);
                    REQUIRE(l_dq_bitmap[0][5] == 0x00);
                    REQUIRE(l_dq_bitmap[0][6] == 0x00);
                    REQUIRE(l_dq_bitmap[0][7] == 0x00);
                    REQUIRE(l_dq_bitmap[0][8] == 0x00);
                    REQUIRE(l_dq_bitmap[0][9] == 0x00);
                    REQUIRE(l_dq_bitmap[1][0] == 0x00);
                    REQUIRE(l_dq_bitmap[1][1] == 0x00);
                    REQUIRE(l_dq_bitmap[1][2] == 0x00);
                    REQUIRE(l_dq_bitmap[1][3] == 0x00);
                    REQUIRE(l_dq_bitmap[1][4] == 0x00);
                    REQUIRE(l_dq_bitmap[1][5] == 0x00);
                    REQUIRE(l_dq_bitmap[1][6] == 0x00);
                    REQUIRE(l_dq_bitmap[1][7] == 0x00);
                    REQUIRE(l_dq_bitmap[1][8] == 0x00);
                    REQUIRE(l_dq_bitmap[1][9] == 0x00);
                    REQUIRE(l_dq_bitmap[2][0] == 0x00);
                    REQUIRE(l_dq_bitmap[2][1] == 0x00);
                    REQUIRE(l_dq_bitmap[2][2] == 0x00);
                    REQUIRE(l_dq_bitmap[2][3] == 0x00);
                    REQUIRE(l_dq_bitmap[2][4] == 0x00);
                    REQUIRE(l_dq_bitmap[2][5] == 0x00);
                    REQUIRE(l_dq_bitmap[2][6] == 0x00);
                    REQUIRE(l_dq_bitmap[2][7] == 0x00);
                    REQUIRE(l_dq_bitmap[2][8] == 0x00);
                    REQUIRE(l_dq_bitmap[2][9] == 0x00);
                    REQUIRE(l_dq_bitmap[3][0] == 0x00);
                    REQUIRE(l_dq_bitmap[3][1] == 0x00);
                    REQUIRE(l_dq_bitmap[3][2] == 0x00);
                    REQUIRE(l_dq_bitmap[3][3] == 0x00);
                    REQUIRE(l_dq_bitmap[3][4] == 0x00);
                    REQUIRE(l_dq_bitmap[3][5] == 0x00);
                    REQUIRE(l_dq_bitmap[3][6] == 0x00);
                    REQUIRE(l_dq_bitmap[3][7] == 0x00);
                    REQUIRE(l_dq_bitmap[3][8] == 0x00);
                    REQUIRE(l_dq_bitmap[3][9] == 0x00);
                }

                // Test failing message block RC
                // Test failing mail RC
                l_mail = 0x07;
                l_struct.CsTestFail = 0x01;
                REQUIRE_SPECIFIC_RC_FAIL(mss::ody::phy::check_training_result(l_port, l_mail, l_struct),
                                         fapi2::RC_ODY_DRAMINIT_TRAINING_FAILURE_MSG_BLOCK);

                for(const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_port))
                {
                    uint8_t l_dq_bitmap[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT] = {};
                    REQUIRE_RC_PASS( mss::attr::get_bad_dq_bitmap(l_dimm, l_dq_bitmap) );
                    REQUIRE(l_dq_bitmap[0][0] == 0x00);
                    REQUIRE(l_dq_bitmap[0][1] == 0x00);
                    REQUIRE(l_dq_bitmap[0][2] == 0x00);
                    REQUIRE(l_dq_bitmap[0][3] == 0x00);
                    REQUIRE(l_dq_bitmap[0][4] == 0x00);
                    REQUIRE(l_dq_bitmap[0][5] == 0x00);
                    REQUIRE(l_dq_bitmap[0][6] == 0x00);
                    REQUIRE(l_dq_bitmap[0][7] == 0x00);
                    REQUIRE(l_dq_bitmap[0][8] == 0x00);
                    REQUIRE(l_dq_bitmap[0][9] == 0x00);
                    REQUIRE(l_dq_bitmap[1][0] == 0x00);
                    REQUIRE(l_dq_bitmap[1][1] == 0x00);
                    REQUIRE(l_dq_bitmap[1][2] == 0x00);
                    REQUIRE(l_dq_bitmap[1][3] == 0x00);
                    REQUIRE(l_dq_bitmap[1][4] == 0x00);
                    REQUIRE(l_dq_bitmap[1][5] == 0x00);
                    REQUIRE(l_dq_bitmap[1][6] == 0x00);
                    REQUIRE(l_dq_bitmap[1][7] == 0x00);
                    REQUIRE(l_dq_bitmap[1][8] == 0x00);
                    REQUIRE(l_dq_bitmap[1][9] == 0x00);
                    REQUIRE(l_dq_bitmap[2][0] == 0x00);
                    REQUIRE(l_dq_bitmap[2][1] == 0x00);
                    REQUIRE(l_dq_bitmap[2][2] == 0x00);
                    REQUIRE(l_dq_bitmap[2][3] == 0x00);
                    REQUIRE(l_dq_bitmap[2][4] == 0x00);
                    REQUIRE(l_dq_bitmap[2][5] == 0x00);
                    REQUIRE(l_dq_bitmap[2][6] == 0x00);
                    REQUIRE(l_dq_bitmap[2][7] == 0x00);
                    REQUIRE(l_dq_bitmap[2][8] == 0x00);
                    REQUIRE(l_dq_bitmap[2][9] == 0x00);
                    REQUIRE(l_dq_bitmap[3][0] == 0x00);
                    REQUIRE(l_dq_bitmap[3][1] == 0x00);
                    REQUIRE(l_dq_bitmap[3][2] == 0x00);
                    REQUIRE(l_dq_bitmap[3][3] == 0x00);
                    REQUIRE(l_dq_bitmap[3][4] == 0x00);
                    REQUIRE(l_dq_bitmap[3][5] == 0x00);
                    REQUIRE(l_dq_bitmap[3][6] == 0x00);
                    REQUIRE(l_dq_bitmap[3][7] == 0x00);
                    REQUIRE(l_dq_bitmap[3][8] == 0x00);
                    REQUIRE(l_dq_bitmap[3][9] == 0x00);
                }

                // Test passing case
                l_mail = 0x07;
                l_struct.CsTestFail = 0x00;
                REQUIRE_RC_PASS(mss::ody::phy::check_training_result(l_port, l_mail, l_struct));

                // Check the bad bits data in the attribute
                for(const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_port))
                {
                    // Note we will only have data for ranks that are in our config here
                    uint8_t l_dq_bitmap[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT] = {};
                    REQUIRE_RC_PASS( mss::attr::get_bad_dq_bitmap(l_dimm, l_dq_bitmap) );
                    REQUIRE(l_dq_bitmap[0][0] == 0x00);
                    REQUIRE(l_dq_bitmap[0][1] == 0x01);
                    REQUIRE(l_dq_bitmap[0][2] == 0x02);
                    REQUIRE(l_dq_bitmap[0][3] == 0x03);
                    REQUIRE(l_dq_bitmap[0][4] == 0x04);
                    REQUIRE(l_dq_bitmap[0][5] == 0x05);
                    REQUIRE(l_dq_bitmap[0][6] == 0x06);
                    REQUIRE(l_dq_bitmap[0][7] == 0x07);
                    REQUIRE(l_dq_bitmap[0][8] == 0x08);
                    REQUIRE(l_dq_bitmap[0][9] == 0x09);
                    REQUIRE(l_dq_bitmap[1][0] == 0xA0);
                    REQUIRE(l_dq_bitmap[1][1] == 0xA1);
                    REQUIRE(l_dq_bitmap[1][2] == 0xA2);
                    REQUIRE(l_dq_bitmap[1][3] == 0xA3);
                    REQUIRE(l_dq_bitmap[1][4] == 0xA4);
                    REQUIRE(l_dq_bitmap[1][5] == 0xA5);
                    REQUIRE(l_dq_bitmap[1][6] == 0xA6);
                    REQUIRE(l_dq_bitmap[1][7] == 0xA7);
                    REQUIRE(l_dq_bitmap[1][8] == 0xA8);
                    REQUIRE(l_dq_bitmap[1][9] == 0xA9);
                    REQUIRE(l_dq_bitmap[2][0] == 0x00);
                    REQUIRE(l_dq_bitmap[2][1] == 0x00);
                    REQUIRE(l_dq_bitmap[2][2] == 0x00);
                    REQUIRE(l_dq_bitmap[2][3] == 0x00);
                    REQUIRE(l_dq_bitmap[2][4] == 0x00);
                    REQUIRE(l_dq_bitmap[2][5] == 0x00);
                    REQUIRE(l_dq_bitmap[2][6] == 0x00);
                    REQUIRE(l_dq_bitmap[2][7] == 0x00);
                    REQUIRE(l_dq_bitmap[2][8] == 0x00);
                    REQUIRE(l_dq_bitmap[2][9] == 0x00);
                    REQUIRE(l_dq_bitmap[3][0] == 0x00);
                    REQUIRE(l_dq_bitmap[3][1] == 0x00);
                    REQUIRE(l_dq_bitmap[3][2] == 0x00);
                    REQUIRE(l_dq_bitmap[3][3] == 0x00);
                    REQUIRE(l_dq_bitmap[3][4] == 0x00);
                    REQUIRE(l_dq_bitmap[3][5] == 0x00);
                    REQUIRE(l_dq_bitmap[3][6] == 0x00);
                    REQUIRE(l_dq_bitmap[3][7] == 0x00);
                    REQUIRE(l_dq_bitmap[3][8] == 0x00);
                    REQUIRE(l_dq_bitmap[3][9] == 0x00);
                }


                // Restore the bad bits attribute
                for(const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_port))
                {
                    REQUIRE_RC_PASS( mss::attr::set_bad_dq_bitmap(l_dimm, l_dq_bitmap_save) );
                }
            }

            return 0;
        });
    }


    GIVEN("Tests host_bad_bit_interface")
    {
        // Loops over OCMB chip targets that were defined in the associated config
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
        {
            for(const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
            {
                for(const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_port))
                {
                    uint8_t l_dq_bitmap[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT] = {};
                    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_FALSE;

                    REQUIRE_RC_PASS( mss::attr::get_bad_dq_bitmap(l_dimm, l_dq_bitmap) );
                    mss::ody::phy::host_bad_bit_interface l_interface(l_dimm, l_rc);
                    REQUIRE_RC_PASS(l_rc);

                    // Test that bad bits in interface are equal to those in the attribute
                    for (uint8_t l_rank = 0; l_rank < BAD_BITS_RANKS; l_rank++)
                    {
                        for (uint8_t l_dq = 0; l_dq < BAD_DQ_BYTE_COUNT; l_dq++)
                        {
                            REQUIRE(l_dq_bitmap[l_rank][l_dq] == l_interface.iv_bad_bits[l_rank][l_dq]);
                        }
                    }
                }
            }

            return 0;
        });
    }
    GIVEN("Tests nibble_enable_db_disable")
    {
        // Loops over OCMB chip targets that were defined in the associated config
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
        {
            uint8_t l_byte_disables[10] = {};
            REQUIRE_RC_PASS(mss::ody::phy::nibble_enable_db_disable(0x00000F00, l_byte_disables));
            REQUIRE( l_byte_disables[0] == 0xFF );
            REQUIRE( l_byte_disables[1] == 0xFF );
            REQUIRE( l_byte_disables[2] == 0xFF );
            REQUIRE( l_byte_disables[3] == 0xFF );
            REQUIRE( l_byte_disables[4] == 0x00 );
            REQUIRE( l_byte_disables[5] == 0xFF );
            REQUIRE( l_byte_disables[6] == 0xFF );
            REQUIRE( l_byte_disables[7] == 0xFF );
            REQUIRE( l_byte_disables[8] == 0x00 );
            REQUIRE( l_byte_disables[9] == 0xFF );

            // Walking 1's test
            REQUIRE_RC_PASS(mss::ody::phy::nibble_enable_db_disable(0x00000001, l_byte_disables));
            REQUIRE( l_byte_disables[0] == 0xF0 );
            REQUIRE( l_byte_disables[1] == 0xFF );
            REQUIRE( l_byte_disables[2] == 0xFF );
            REQUIRE( l_byte_disables[3] == 0xFF );
            REQUIRE( l_byte_disables[4] == 0xFF );
            REQUIRE( l_byte_disables[5] == 0xFF );
            REQUIRE( l_byte_disables[6] == 0xFF );
            REQUIRE( l_byte_disables[7] == 0xFF );
            REQUIRE( l_byte_disables[8] == 0xFF );
            REQUIRE( l_byte_disables[9] == 0xFF );

            REQUIRE_RC_PASS(mss::ody::phy::nibble_enable_db_disable(0x00000002, l_byte_disables));
            REQUIRE( l_byte_disables[0] == 0x0F );
            REQUIRE( l_byte_disables[1] == 0xFF );
            REQUIRE( l_byte_disables[2] == 0xFF );
            REQUIRE( l_byte_disables[3] == 0xFF );
            REQUIRE( l_byte_disables[4] == 0xFF );
            REQUIRE( l_byte_disables[5] == 0xFF );
            REQUIRE( l_byte_disables[6] == 0xFF );
            REQUIRE( l_byte_disables[7] == 0xFF );
            REQUIRE( l_byte_disables[8] == 0xFF );
            REQUIRE( l_byte_disables[9] == 0xFF );

            REQUIRE_RC_PASS(mss::ody::phy::nibble_enable_db_disable(0x00000004, l_byte_disables));
            REQUIRE( l_byte_disables[0] == 0xFF );
            REQUIRE( l_byte_disables[1] == 0xF0 );
            REQUIRE( l_byte_disables[2] == 0xFF );
            REQUIRE( l_byte_disables[3] == 0xFF );
            REQUIRE( l_byte_disables[4] == 0xFF );
            REQUIRE( l_byte_disables[5] == 0xFF );
            REQUIRE( l_byte_disables[6] == 0xFF );
            REQUIRE( l_byte_disables[7] == 0xFF );
            REQUIRE( l_byte_disables[8] == 0xFF );
            REQUIRE( l_byte_disables[9] == 0xFF );

            REQUIRE_RC_PASS(mss::ody::phy::nibble_enable_db_disable(0x00000008, l_byte_disables));
            REQUIRE( l_byte_disables[0] == 0xFF );
            REQUIRE( l_byte_disables[1] == 0x0F );
            REQUIRE( l_byte_disables[2] == 0xFF );
            REQUIRE( l_byte_disables[3] == 0xFF );
            REQUIRE( l_byte_disables[4] == 0xFF );
            REQUIRE( l_byte_disables[5] == 0xFF );
            REQUIRE( l_byte_disables[6] == 0xFF );
            REQUIRE( l_byte_disables[7] == 0xFF );
            REQUIRE( l_byte_disables[8] == 0xFF );
            REQUIRE( l_byte_disables[9] == 0xFF );

            REQUIRE_RC_PASS(mss::ody::phy::nibble_enable_db_disable(0x00000010, l_byte_disables));
            REQUIRE( l_byte_disables[0] == 0xFF );
            REQUIRE( l_byte_disables[1] == 0xFF );
            REQUIRE( l_byte_disables[2] == 0xF0 );
            REQUIRE( l_byte_disables[3] == 0xFF );
            REQUIRE( l_byte_disables[4] == 0xFF );
            REQUIRE( l_byte_disables[5] == 0xFF );
            REQUIRE( l_byte_disables[6] == 0xFF );
            REQUIRE( l_byte_disables[7] == 0xFF );
            REQUIRE( l_byte_disables[8] == 0xFF );
            REQUIRE( l_byte_disables[9] == 0xFF );

            REQUIRE_RC_PASS(mss::ody::phy::nibble_enable_db_disable(0x00000020, l_byte_disables));
            REQUIRE( l_byte_disables[0] == 0xFF );
            REQUIRE( l_byte_disables[1] == 0xFF );
            REQUIRE( l_byte_disables[2] == 0x0F );
            REQUIRE( l_byte_disables[3] == 0xFF );
            REQUIRE( l_byte_disables[4] == 0xFF );
            REQUIRE( l_byte_disables[5] == 0xFF );
            REQUIRE( l_byte_disables[6] == 0xFF );
            REQUIRE( l_byte_disables[7] == 0xFF );
            REQUIRE( l_byte_disables[8] == 0xFF );
            REQUIRE( l_byte_disables[9] == 0xFF );

            REQUIRE_RC_PASS(mss::ody::phy::nibble_enable_db_disable(0x00000040, l_byte_disables));
            REQUIRE( l_byte_disables[0] == 0xFF );
            REQUIRE( l_byte_disables[1] == 0xFF );
            REQUIRE( l_byte_disables[2] == 0xFF );
            REQUIRE( l_byte_disables[3] == 0xF0 );
            REQUIRE( l_byte_disables[4] == 0xFF );
            REQUIRE( l_byte_disables[5] == 0xFF );
            REQUIRE( l_byte_disables[6] == 0xFF );
            REQUIRE( l_byte_disables[7] == 0xFF );
            REQUIRE( l_byte_disables[8] == 0xFF );
            REQUIRE( l_byte_disables[9] == 0xFF );

            REQUIRE_RC_PASS(mss::ody::phy::nibble_enable_db_disable(0x00000080, l_byte_disables));
            REQUIRE( l_byte_disables[0] == 0xFF );
            REQUIRE( l_byte_disables[1] == 0xFF );
            REQUIRE( l_byte_disables[2] == 0xFF );
            REQUIRE( l_byte_disables[3] == 0x0F );
            REQUIRE( l_byte_disables[4] == 0xFF );
            REQUIRE( l_byte_disables[5] == 0xFF );
            REQUIRE( l_byte_disables[6] == 0xFF );
            REQUIRE( l_byte_disables[7] == 0xFF );
            REQUIRE( l_byte_disables[8] == 0xFF );
            REQUIRE( l_byte_disables[9] == 0xFF );

            REQUIRE_RC_PASS(mss::ody::phy::nibble_enable_db_disable(0x00000100, l_byte_disables));
            REQUIRE( l_byte_disables[0] == 0xFF );
            REQUIRE( l_byte_disables[1] == 0xFF );
            REQUIRE( l_byte_disables[2] == 0xFF );
            REQUIRE( l_byte_disables[3] == 0xFF );
            REQUIRE( l_byte_disables[4] == 0xFF );
            REQUIRE( l_byte_disables[5] == 0xFF );
            REQUIRE( l_byte_disables[6] == 0xFF );
            REQUIRE( l_byte_disables[7] == 0xFF );
            REQUIRE( l_byte_disables[8] == 0xF0 );
            REQUIRE( l_byte_disables[9] == 0xFF );

            REQUIRE_RC_PASS(mss::ody::phy::nibble_enable_db_disable(0x00000200, l_byte_disables));
            REQUIRE( l_byte_disables[0] == 0xFF );
            REQUIRE( l_byte_disables[1] == 0xFF );
            REQUIRE( l_byte_disables[2] == 0xFF );
            REQUIRE( l_byte_disables[3] == 0xFF );
            REQUIRE( l_byte_disables[4] == 0xFF );
            REQUIRE( l_byte_disables[5] == 0xFF );
            REQUIRE( l_byte_disables[6] == 0xFF );
            REQUIRE( l_byte_disables[7] == 0xFF );
            REQUIRE( l_byte_disables[8] == 0x0F );
            REQUIRE( l_byte_disables[9] == 0xFF );

            REQUIRE_RC_PASS(mss::ody::phy::nibble_enable_db_disable(0x00000400, l_byte_disables));
            REQUIRE( l_byte_disables[0] == 0xFF );
            REQUIRE( l_byte_disables[1] == 0xFF );
            REQUIRE( l_byte_disables[2] == 0xFF );
            REQUIRE( l_byte_disables[3] == 0xFF );
            REQUIRE( l_byte_disables[4] == 0xF0 );
            REQUIRE( l_byte_disables[5] == 0xFF );
            REQUIRE( l_byte_disables[6] == 0xFF );
            REQUIRE( l_byte_disables[7] == 0xFF );
            REQUIRE( l_byte_disables[8] == 0xFF );
            REQUIRE( l_byte_disables[9] == 0xFF );

            REQUIRE_RC_PASS(mss::ody::phy::nibble_enable_db_disable(0x00000800, l_byte_disables));
            REQUIRE( l_byte_disables[0] == 0xFF );
            REQUIRE( l_byte_disables[1] == 0xFF );
            REQUIRE( l_byte_disables[2] == 0xFF );
            REQUIRE( l_byte_disables[3] == 0xFF );
            REQUIRE( l_byte_disables[4] == 0x0F );
            REQUIRE( l_byte_disables[5] == 0xFF );
            REQUIRE( l_byte_disables[6] == 0xFF );
            REQUIRE( l_byte_disables[7] == 0xFF );
            REQUIRE( l_byte_disables[8] == 0xFF );
            REQUIRE( l_byte_disables[9] == 0xFF );

            REQUIRE_RC_PASS(mss::ody::phy::nibble_enable_db_disable(0x00001000, l_byte_disables));
            REQUIRE( l_byte_disables[0] == 0xFF );
            REQUIRE( l_byte_disables[1] == 0xFF );
            REQUIRE( l_byte_disables[2] == 0xFF );
            REQUIRE( l_byte_disables[3] == 0xFF );
            REQUIRE( l_byte_disables[4] == 0xFF );
            REQUIRE( l_byte_disables[5] == 0xF0 );
            REQUIRE( l_byte_disables[6] == 0xFF );
            REQUIRE( l_byte_disables[7] == 0xFF );
            REQUIRE( l_byte_disables[8] == 0xFF );
            REQUIRE( l_byte_disables[9] == 0xFF );

            REQUIRE_RC_PASS(mss::ody::phy::nibble_enable_db_disable(0x00002000, l_byte_disables));
            REQUIRE( l_byte_disables[0] == 0xFF );
            REQUIRE( l_byte_disables[1] == 0xFF );
            REQUIRE( l_byte_disables[2] == 0xFF );
            REQUIRE( l_byte_disables[3] == 0xFF );
            REQUIRE( l_byte_disables[4] == 0xFF );
            REQUIRE( l_byte_disables[5] == 0x0F );
            REQUIRE( l_byte_disables[6] == 0xFF );
            REQUIRE( l_byte_disables[7] == 0xFF );
            REQUIRE( l_byte_disables[8] == 0xFF );
            REQUIRE( l_byte_disables[9] == 0xFF );

            REQUIRE_RC_PASS(mss::ody::phy::nibble_enable_db_disable(0x00004000, l_byte_disables));
            REQUIRE( l_byte_disables[0] == 0xFF );
            REQUIRE( l_byte_disables[1] == 0xFF );
            REQUIRE( l_byte_disables[2] == 0xFF );
            REQUIRE( l_byte_disables[3] == 0xFF );
            REQUIRE( l_byte_disables[4] == 0xFF );
            REQUIRE( l_byte_disables[5] == 0xFF );
            REQUIRE( l_byte_disables[6] == 0xF0 );
            REQUIRE( l_byte_disables[7] == 0xFF );
            REQUIRE( l_byte_disables[8] == 0xFF );
            REQUIRE( l_byte_disables[9] == 0xFF );

            REQUIRE_RC_PASS(mss::ody::phy::nibble_enable_db_disable(0x00008000, l_byte_disables));
            REQUIRE( l_byte_disables[0] == 0xFF );
            REQUIRE( l_byte_disables[1] == 0xFF );
            REQUIRE( l_byte_disables[2] == 0xFF );
            REQUIRE( l_byte_disables[3] == 0xFF );
            REQUIRE( l_byte_disables[4] == 0xFF );
            REQUIRE( l_byte_disables[5] == 0xFF );
            REQUIRE( l_byte_disables[6] == 0x0F );
            REQUIRE( l_byte_disables[7] == 0xFF );
            REQUIRE( l_byte_disables[8] == 0xFF );
            REQUIRE( l_byte_disables[9] == 0xFF );

            REQUIRE_RC_PASS(mss::ody::phy::nibble_enable_db_disable(0x00010000, l_byte_disables));
            REQUIRE( l_byte_disables[0] == 0xFF );
            REQUIRE( l_byte_disables[1] == 0xFF );
            REQUIRE( l_byte_disables[2] == 0xFF );
            REQUIRE( l_byte_disables[3] == 0xFF );
            REQUIRE( l_byte_disables[4] == 0xFF );
            REQUIRE( l_byte_disables[5] == 0xFF );
            REQUIRE( l_byte_disables[6] == 0xFF );
            REQUIRE( l_byte_disables[7] == 0xF0 );
            REQUIRE( l_byte_disables[8] == 0xFF );
            REQUIRE( l_byte_disables[9] == 0xFF );

            REQUIRE_RC_PASS(mss::ody::phy::nibble_enable_db_disable(0x00020000, l_byte_disables));
            REQUIRE( l_byte_disables[0] == 0xFF );
            REQUIRE( l_byte_disables[1] == 0xFF );
            REQUIRE( l_byte_disables[2] == 0xFF );
            REQUIRE( l_byte_disables[3] == 0xFF );
            REQUIRE( l_byte_disables[4] == 0xFF );
            REQUIRE( l_byte_disables[5] == 0xFF );
            REQUIRE( l_byte_disables[6] == 0xFF );
            REQUIRE( l_byte_disables[7] == 0x0F );
            REQUIRE( l_byte_disables[8] == 0xFF );
            REQUIRE( l_byte_disables[9] == 0xFF );

            REQUIRE_RC_PASS(mss::ody::phy::nibble_enable_db_disable(0x00040000, l_byte_disables));
            REQUIRE( l_byte_disables[0] == 0xFF );
            REQUIRE( l_byte_disables[1] == 0xFF );
            REQUIRE( l_byte_disables[2] == 0xFF );
            REQUIRE( l_byte_disables[3] == 0xFF );
            REQUIRE( l_byte_disables[4] == 0xFF );
            REQUIRE( l_byte_disables[5] == 0xFF );
            REQUIRE( l_byte_disables[6] == 0xFF );
            REQUIRE( l_byte_disables[7] == 0xFF );
            REQUIRE( l_byte_disables[8] == 0xFF );
            REQUIRE( l_byte_disables[9] == 0xF0 );

            REQUIRE_RC_PASS(mss::ody::phy::nibble_enable_db_disable(0x00080000, l_byte_disables));
            REQUIRE( l_byte_disables[0] == 0xFF );
            REQUIRE( l_byte_disables[1] == 0xFF );
            REQUIRE( l_byte_disables[2] == 0xFF );
            REQUIRE( l_byte_disables[3] == 0xFF );
            REQUIRE( l_byte_disables[4] == 0xFF );
            REQUIRE( l_byte_disables[5] == 0xFF );
            REQUIRE( l_byte_disables[6] == 0xFF );
            REQUIRE( l_byte_disables[7] == 0xFF );
            REQUIRE( l_byte_disables[8] == 0xFF );
            REQUIRE( l_byte_disables[9] == 0x0F );

            return 0;
        });
    }
    GIVEN("Tests endian swapping fix")
    {
        // Note: this code is only called in the SBE and here
        // Including an identical array and calls to ensure that it functions as expected
        // Array to hold list of addresses that are uint16_t's and do NOT need endianness swapping for SBE
        const uint32_t NO_SWAP_ADDR[]__attribute__ ((aligned (8))) =
        {
            0x58003,
            0x58008,
            0x58011,
            0x580fe,
            0x580ff,
        };
        auto l_no_swap_it = std::begin(NO_SWAP_ADDR);
        const auto NO_SWAP_END = std::end(NO_SWAP_ADDR);

        fapi2::buffer<uint64_t> l_data(0x0102030405060708);

        // Not in the array? swap it up but do not increment the iterator
        mss::ody::phy::endian_swap_msg_block_data(0x58000, NO_SWAP_END, l_no_swap_it, l_data);
        REQUIRE(0x0102030405060807 == l_data);
        REQUIRE(0x58003 == *l_no_swap_it);

        // Checks that the code iterates through the array expected
        mss::ody::phy::endian_swap_msg_block_data(0x58003, NO_SWAP_END, l_no_swap_it, l_data);
        REQUIRE(0x0102030405060807 == l_data);
        REQUIRE(0x58008 == *l_no_swap_it);
        mss::ody::phy::endian_swap_msg_block_data(0x58008, NO_SWAP_END, l_no_swap_it, l_data);
        REQUIRE(0x0102030405060807 == l_data);
        REQUIRE(0x58011 == *l_no_swap_it);
        mss::ody::phy::endian_swap_msg_block_data(0x58011, NO_SWAP_END, l_no_swap_it, l_data);
        REQUIRE(0x0102030405060807 == l_data);
        REQUIRE(0x580fe == *l_no_swap_it);
        mss::ody::phy::endian_swap_msg_block_data(0x580fe, NO_SWAP_END, l_no_swap_it, l_data);
        REQUIRE(0x0102030405060807 == l_data);
        REQUIRE(0x580ff == *l_no_swap_it);
        mss::ody::phy::endian_swap_msg_block_data(0x580ff, NO_SWAP_END, l_no_swap_it, l_data);
        REQUIRE(0x0102030405060807 == l_data);
        // Swap iterator should be at end now
        REQUIRE(NO_SWAP_END == l_no_swap_it);

        // If we're at the ending point, always swap even for an address in the array
        mss::ody::phy::endian_swap_msg_block_data(0x58003, NO_SWAP_END, l_no_swap_it, l_data);
        REQUIRE(0x0102030405060708 == l_data);
        REQUIRE(NO_SWAP_END == l_no_swap_it);
    }

}// scenario

} // end ns test
} // end ns mss
