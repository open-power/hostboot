/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/tests/pmic_enable_ddr5_ut.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
/// @file pmic_enable_ddr5_ut.C
/// @brief Unit tests for DDR5 PMIC enable operations
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: CI

#include <fapi2.H>
#include <catch.hpp>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/tests/target_fixture.H>
#include <lib/i2c/i2c_pmic.H>
#include <lib/utils/pmic_consts.H>
#include <lib/utils/pmic_enable_utils.H>
#include <lib/utils/pmic_enable_utils_ddr5.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>
#include <mss_generic_attribute_getters.H>
#include <mss_generic_attribute_setters.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <mss_pmic_attribute_accessors_manual.H>

namespace mss
{

namespace test
{

///
/// @brief Unit test cases for PMIC enable utilities
/// @param[in] test_fixture
/// @param[in] description
/// @param[in] tag
/// @return void
/// @note ocmb_chip_target_test_fixture is the fixture to use with this test case
///
SCENARIO_METHOD(ocmb_chip_target_test_fixture, "PMIC enable ddr5", "[pmic_enable_ddr5]")
{
    SECTION("Checks setup_dt")
    {
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target)
        {
            using DT_REGS  = mss::dt::regs;
            auto l_dts = mss::find_targets_sorted_by_pos<fapi2::TARGET_TYPE_POWER_IC>(i_ocmb_target);

            fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

            // Grab the targets as a struct, if they exist
            mss::pmic::ddr5::target_info_redundancy_ddr5 l_target_info(i_ocmb_target, l_rc);

            REQUIRE_FALSE(mss::pmic::ddr5::setup_dt(l_target_info));

            for (const auto& l_dt : l_dts)
            {
                fapi2::buffer<uint8_t> l_reg_read_buffer;

                // Cannot test all the regs here as they are write only

                FAPI_INF("Enable efuse")
                REQUIRE_FALSE(mss::pmic::i2c::reg_read(l_dt, DT_REGS::EN_REGISTER, l_reg_read_buffer));
                REQUIRE(l_reg_read_buffer == 0x01);
            }

            return 0;
        });
    }
    SECTION("Checks PMIC pre-config function")
    {
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target)
        {
            auto l_pmics = mss::find_targets_sorted_by_pos<fapi2::TARGET_TYPE_PMIC>(i_ocmb_target);
            using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;
            using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
            using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;
            using TPS_REGS = pmicRegs<mss::pmic::product::TPS5383X>;

            const uint8_t l_pre_config = CONSTS::PRE_CONFIG_ON_OFF;

            static const fapi2::buffer<uint8_t> l_regs_to_be_written_soft_stop[] = { REGS::R82,
                                                                                     REGS::R85,
                                                                                     REGS::R88,
                                                                                     REGS::R8B
                                                                                   };

            fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

            // Grab the targets as a struct, if they exist
            mss::pmic::ddr5::target_info_redundancy_ddr5 l_target_info(i_ocmb_target, l_rc);
            fapi2::buffer<uint8_t> l_reg_read_buffer;

            FAPI_INF("Test PMIC pre config during initialization");
            REQUIRE_FALSE(mss::pmic::ddr5::pre_config(l_target_info, CONSTS::ENABLE));

            for (const auto& l_pmic : l_pmics)
            {
                // Check soft-stop
                for (const auto& l_reg_addr : l_regs_to_be_written_soft_stop)
                {
                    REQUIRE_FALSE(mss::pmic::i2c::reg_read_reverse_buffer(l_pmic, l_reg_addr, l_reg_read_buffer));
                    REQUIRE(l_reg_read_buffer.getBit<FIELDS::COMP_CONFIG>() == CONSTS::ENABLE);
                }

                // Check Global ON_OFF_CONFIG
                REQUIRE_FALSE(mss::pmic::i2c::reg_read(l_pmic, TPS_REGS::R9C_ON_OFF_CONFIG_GLOBAL, l_reg_read_buffer));
                REQUIRE(l_reg_read_buffer == l_pre_config);
            }

            FAPI_INF("Test PMIC pre config during power down");
            REQUIRE_FALSE(mss::pmic::ddr5::pre_config(l_target_info, CONSTS::DISABLE));

            for (const auto& l_pmic : l_pmics)
            {
                // Check soft-stop
                for (const auto& l_reg_addr : l_regs_to_be_written_soft_stop)
                {
                    REQUIRE_FALSE(mss::pmic::i2c::reg_read_reverse_buffer(l_pmic, l_reg_addr, l_reg_read_buffer));
                    REQUIRE(l_reg_read_buffer.getBit<FIELDS::COMP_CONFIG>() == CONSTS::DISABLE);
                }

                // Check Global ON_OFF_CONFIG
                REQUIRE_FALSE(mss::pmic::i2c::reg_read(l_pmic, TPS_REGS::R9C_ON_OFF_CONFIG_GLOBAL, l_reg_read_buffer));
                REQUIRE(l_reg_read_buffer == l_pre_config);
            }

            return 0;
        });
    }

    SECTION("Test PMIC post-config function")
    {
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target)
        {
            using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
            using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;
            using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;
            using TPS_REGS = pmicRegs<mss::pmic::product::TPS5383X>;
            const auto& l_pmics = mss::find_targets<fapi2::TARGET_TYPE_PMIC>(i_ocmb_target);
            fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
            fapi2::buffer<uint8_t> l_reg_read_buffer;

            const uint8_t l_post_config = CONSTS::POST_CONFIG_ON_OFF;

            // Grab the targets as a struct, if they exist
            mss::pmic::ddr5::target_info_redundancy_ddr5 l_target_info(i_ocmb_target, l_rc);

            FAPI_INF("Test PMIC post config during initialization");
            REQUIRE_FALSE(mss::pmic::ddr5::post_config(l_target_info, CONSTS::ENABLE));

            for (const auto& l_pmic : l_pmics)
            {
                // VR_ENABLE
                REQUIRE_FALSE(mss::pmic::i2c::reg_read_reverse_buffer(l_pmic, REGS::R32, l_reg_read_buffer));
                REQUIRE(l_reg_read_buffer.getBit<FIELDS::PWR_OFF_SEQ>() == CONSTS::ENABLE);

                REQUIRE_FALSE(mss::pmic::i2c::reg_read(l_pmic, TPS_REGS::R9C_ON_OFF_CONFIG_GLOBAL, l_reg_read_buffer));
                REQUIRE(l_reg_read_buffer == l_post_config);
            }

            FAPI_INF("Test PMIC post config during power down");
            REQUIRE_FALSE(mss::pmic::ddr5::post_config(l_target_info, CONSTS::DISABLE));

            for (const auto& l_pmic : l_pmics)
            {
                // VR_ENABLE
                REQUIRE_FALSE(mss::pmic::i2c::reg_read_reverse_buffer(l_pmic, REGS::R32, l_reg_read_buffer));
                REQUIRE(l_reg_read_buffer.getBit<FIELDS::PWR_OFF_SEQ>() == CONSTS::DISABLE);

                REQUIRE_FALSE(mss::pmic::i2c::reg_read(l_pmic, TPS_REGS::R9C_ON_OFF_CONFIG_GLOBAL, l_reg_read_buffer));
                REQUIRE(l_reg_read_buffer == l_post_config);
            }

            return 0;
        });
    }

    SECTION("Test enable_disable_pmic function")
    {
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target)
        {
            using ADC_REGS = mss::adc::regs;
            using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;
            const uint8_t l_disable_pmic_en = CONSTS::DISABLE_PMIC_EN;
            const uint8_t l_set_pmic_en = CONSTS::SET_PMIC_EN;

            auto l_adc = mss::find_targets_sorted_by_pos<fapi2::TARGET_TYPE_GENERICI2CSLAVE>(i_ocmb_target);

            fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
            fapi2::buffer<uint8_t> l_reg_read_buffer;
            // Grab the targets as a struct, if they exist
            mss::pmic::ddr5::target_info_redundancy_ddr5 l_target_info(i_ocmb_target, l_rc);

            FAPI_INF("Test PMIC enable during initialization");
            REQUIRE_FALSE(mss::pmic::ddr5::enable_disable_pmic(l_target_info.iv_adc, l_set_pmic_en));

            // Set PMIC_EN to 1
            REQUIRE_FALSE(mss::pmic::i2c::reg_read(l_adc[mss::generic_i2c_responder::ADC], ADC_REGS::GPO_VALUE, l_reg_read_buffer));
            REQUIRE(l_reg_read_buffer == l_set_pmic_en);

            FAPI_INF("Test PMIC disable during power down");
            REQUIRE_FALSE(mss::pmic::ddr5::enable_disable_pmic(l_target_info.iv_adc, l_disable_pmic_en));

            REQUIRE_FALSE(mss::pmic::i2c::reg_read(l_adc[mss::generic_i2c_responder::ADC], ADC_REGS::GPO_VALUE, l_reg_read_buffer));
            REQUIRE(l_reg_read_buffer == l_disable_pmic_en);

            return 0;
        });
    }

    SECTION("Test initialize ADC function")
    {
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target)
        {
            using ADC_REGS = mss::adc::regs;

            auto l_adc = mss::find_targets_sorted_by_pos<fapi2::TARGET_TYPE_GENERICI2CSLAVE>(i_ocmb_target);

            fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
            fapi2::buffer<uint8_t> l_reg_read_buffer;
            // Grab the targets as a struct, if they exist
            mss::pmic::ddr5::target_info_redundancy_ddr5 l_target_info(i_ocmb_target, l_rc);

            REQUIRE_FALSE(mss::pmic::ddr5::setup_adc(l_target_info.iv_adc));

            // Spot checking some of the ADC regs here
            REQUIRE_FALSE(mss::pmic::i2c::reg_read(l_adc[mss::generic_i2c_responder::ADC], ADC_REGS::OSR_CFG, l_reg_read_buffer));
            REQUIRE(l_reg_read_buffer == 0x07);

            REQUIRE_FALSE(mss::pmic::i2c::reg_read(l_adc[mss::generic_i2c_responder::ADC], ADC_REGS::GPO_VALUE, l_reg_read_buffer));
            REQUIRE(l_reg_read_buffer == 0x00);

            REQUIRE_FALSE(mss::pmic::i2c::reg_read(l_adc[mss::generic_i2c_responder::ADC], ADC_REGS::ALERT_CH_SEL,
                                                   l_reg_read_buffer));
            REQUIRE(l_reg_read_buffer == 0x7E);

            REQUIRE_FALSE(mss::pmic::i2c::reg_read(l_adc[mss::generic_i2c_responder::ADC], ADC_REGS::EVENT_RGN, l_reg_read_buffer));
            REQUIRE(l_reg_read_buffer == 0x00);

            REQUIRE_FALSE(mss::pmic::i2c::reg_read(l_adc[mss::generic_i2c_responder::ADC], ADC_REGS::HYSTERESIS_CH2,
                                                   l_reg_read_buffer));
            REQUIRE(l_reg_read_buffer == 0xF1);

            REQUIRE_FALSE(mss::pmic::i2c::reg_read(l_adc[mss::generic_i2c_responder::ADC], ADC_REGS::HIGH_TH_CH3,
                                                   l_reg_read_buffer));
            REQUIRE(l_reg_read_buffer == 0xFF);

            REQUIRE_FALSE(mss::pmic::i2c::reg_read(l_adc[mss::generic_i2c_responder::ADC], ADC_REGS::EVENT_COUNT_CH4,
                                                   l_reg_read_buffer));
            REQUIRE(l_reg_read_buffer == 0xF4);

            REQUIRE_FALSE(mss::pmic::i2c::reg_read(l_adc[mss::generic_i2c_responder::ADC], ADC_REGS::LOW_TH_CH6,
                                                   l_reg_read_buffer));
            REQUIRE(l_reg_read_buffer == 0x65);
            return 0;
        });
    }

    SECTION("Test initialize PMIC function")
    {
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target)
        {
            using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
            using TPS_REGS = pmicRegs<mss::pmic::product::TPS5383X>;
            fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
            fapi2::buffer<uint8_t> l_reg_read_buffer;
            // Grab the targets as a struct, if they exist
            mss::pmic::ddr5::target_info_redundancy_ddr5 l_target_info(i_ocmb_target, l_rc);

            REQUIRE_FALSE(mss::pmic::ddr5::initialize_pmic(i_ocmb_target, l_target_info));

            const auto& l_pmics = mss::find_targets<fapi2::TARGET_TYPE_PMIC>(i_ocmb_target);

            for (const auto& l_pmic : l_pmics)
            {
                // Cannot test all the regs here as they are write only

                REQUIRE_FALSE(mss::pmic::i2c::reg_read(l_pmic, REGS::R2F, l_reg_read_buffer));
                REQUIRE(l_reg_read_buffer == 0x06);

                REQUIRE_FALSE(mss::pmic::i2c::reg_read(l_pmic, TPS_REGS::RA2_REG_LOCK, l_reg_read_buffer));
                REQUIRE(l_reg_read_buffer == 0x64);

                REQUIRE_FALSE(mss::pmic::i2c::reg_read(l_pmic, REGS::R30, l_reg_read_buffer));
                REQUIRE(l_reg_read_buffer == 0xD0);

                REQUIRE_FALSE(mss::pmic::i2c::reg_read(l_pmic, REGS::R15, l_reg_read_buffer));
                REQUIRE(l_reg_read_buffer == 0x3C);

                REQUIRE_FALSE(mss::pmic::i2c::reg_read(l_pmic, REGS::R16, l_reg_read_buffer));
                REQUIRE(l_reg_read_buffer == 0x60);

                REQUIRE_FALSE(mss::pmic::i2c::reg_read(l_pmic, REGS::R1A, l_reg_read_buffer));
                REQUIRE(l_reg_read_buffer == 0x60);
            }

            return 0;
        });
    }

    SECTION("Test clear adc events function")
    {
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target)
        {
            using ADC_REGS = mss::adc::regs;

            auto l_adc = mss::find_targets_sorted_by_pos<fapi2::TARGET_TYPE_GENERICI2CSLAVE>(i_ocmb_target);

            fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
            fapi2::buffer<uint8_t> l_reg_read_buffer;
            // Grab the targets as a struct, if they exist
            mss::pmic::ddr5::target_info_redundancy_ddr5 l_target_info(i_ocmb_target, l_rc);

            REQUIRE_FALSE(mss::pmic::ddr5::clear_adc_events(l_target_info.iv_adc));

            REQUIRE_FALSE(mss::pmic::i2c::reg_read(l_adc[mss::generic_i2c_responder::ADC], ADC_REGS::LOW_EVENT_FLAGS,
                                                   l_reg_read_buffer));
            REQUIRE(l_reg_read_buffer == 0xFF);

            return 0;
        });
    }
} // scenario method
} // test
} // mss
