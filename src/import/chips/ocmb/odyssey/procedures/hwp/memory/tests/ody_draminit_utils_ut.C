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
                REQUIRE_RC_PASS(mss::ody::phy::configure_dram_train_message_block(l_port, l_struct));

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
}// scenario

} // end ns test
} // end ns mss
