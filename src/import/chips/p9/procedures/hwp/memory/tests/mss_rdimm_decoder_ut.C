/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/tests/mss_rdimm_decoder_ut.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file mss_spd_ut.C
/// @brief Unit tests for spd decoder api
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 4
// *HWP Consumed by: CI

#include <cstdarg>
#include <fapi2.H>

#include <mss.H>
#include <catch.hpp>

#include <tests/target_fixture.H>
#include <lib/utils/fake_spd.H>
#include <lib/spd/spd_factory.H>
#include <lib/spd/common/spd_decoder.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_DIMM;

namespace mss
{
namespace test
{

// Blob of "bad" SPD data used for unit testing
// Involves using key-byte values that are not in the SPD maps
static constexpr uint8_t BAD_SPD[] =
{

//  Byte 0      Byte 1       Byte 2       Byte 3      Byte 4       Byte 5      Byte 6       Byte 7
    0x35,       0xFF,        0x07,        0x45,       0xDA,       0x3F,        0x83,        0x3A,

//  Byte 8       Byte 9      Byte 10      Byte 11     Byte 12      Byte 13     Byte 14      Byte 15
    uint8_t(~0), 0xD0,       0xFF,        0x00,       0x04,       0x1F,        0x80,        0x01,

//  Byte 16     Byte 17      Byte 18      Byte 19     Byte 20      Byte 21     Byte 22      Byte 23
    uint8_t(~0), 0x0F,       0x00,        0x00,       0x01,       0x01,        0x01,        0x40,

//  Byte 24     Byte 25      Byte 26      Byte 27     Byte 28      Byte 29     Byte 30      Byte 31
    0x00,       0x00,        0x00,        0x00,       0x00,       0x00,        0x00,        0x00,

//  Byte 32     Byte 33      Byte 34      Byte 35     Byte 36      Byte 37     Byte 38      Byte 39
    0x00,       0x00,        0x00,        0x00,       0x00,       0x00,        0x00,        0x00,

//  Byte 40     Byte 41      Byte 42      Byte 43     Byte 44      Byte 45     Byte 46      Byte 47
    0x00,       0x00,        0x00,        0xFF,       0xFF,       0xFF,        0x00,        0x00,

//  Byte 48     Byte 49      Byte 50      Byte 51     Byte 52      Byte 53     Byte 54       Byte 55
    0x00,       0x00,        0x00,        0x00,       0x00,       0x00,        0x00,        0x00,

//  Byte 56     Byte 57      Byte 58      Byte 59     Byte 60      Byte 61     Byte 62      Byte 63
    0x00,       0x00,        0x00,        0x00,       0x00,       0x00,        0x00,        0x00,

//  Byte 64     Byte 65      Byte 66      Byte 67     Byte 68      Byte 69     Byte 70      Byte 71
    0x00,       0x00,        0x00,        0x00,       0x00,       0x00,        0x00,        0x00,

//  Byte 72     Byte 73      Byte 74      Byte 75     Byte 76      Byte 77     Byte 78      Byte 79
    0x00,       0x00,        0x00,        0x00,       0x00,       0x00,        0x00,        0x00,

//  Byte 80     Byte 81      Byte 82      Byte 83     Byte 84      Byte 85     Byte 86      Byte 87
    0x00,       0x00,        0x00,        0x00,       0x00,       0x00,        0x00,        0x00,

//  Byte 88     Byte 89      Byte 90      Byte 91     Byte 92      Byte 93     Byte 94      Byte 95
    0x00,       0x00,        0x00,        0x00,       0x00,       0x00,        0x00,        0x00,

//  Byte 96     Byte 97      Byte 98      Byte 99     Byte 100     Byte 101    Byte 102     Byte 103
    0x00,       0x00,        0x00,        0x00,       0x00,       0x00,        0x00,        0x00,

//  Byte 104    Byte 105     Byte 106     Byte 107    Byte 108     Byte 109    Byte 110     Byte 111
    0x00,       0x00,        0x00,        0x00,       0x00,       0x00,        0x00,        0x00,

//  Byte 112    Byte 113     Byte 114     Byte 115    Byte 116     Byte 117    Byte 118     Byte 119
    0x00,       0x00,        0x00,        0x00,       0x00,       0xFF,        0xFF,        0xFF,

//Byte 120      Byte 121     Byte 122     Byte 123    Byte 124    Byte 125     Byte 126     Byte 127
    0xFF,       0xFF,        0xFF,        0xFF,       0xFF,       0xFF,        0xC0,        0xFE,

//Byte 128      Byte 129     Byte 130     Byte 131    Byte 132    Byte 133     Byte 134     Byte 135
    0xFF,       0xFF,        0xFF,        0xFF,       0xFF,       0xFF,        0xC0,        0xFE,

//Byte 136      Byte 137     Byte 138     Byte 139    Byte 140    Byte 141     Byte 142     Byte 143
    0xFF,       0xFF,        0x0F,        0xFF,       0xFF,       0xFF,        0xC0,        0xFE,


    // add rest here
};

///
/// @brief Unit test cases for SPD Decoder
/// @param[in] test_fixture, description, tag
/// @return void
/// @note mcbist_target_test_fixture is the fixture to use with this test case
///
SCENARIO_METHOD(mcbist_target_test_fixture, "Verify RDIMM SPD Decoding", "[rdimm_decoder]")
{
    //////////////////////////////
    // SPD Byte 128~191. Module-Specific Section
    /////////////////////////////

    GIVEN("Passing test cases w/valid VBU SPD data (rev 1.0)")
    {
        //Loops over MCBIST targets that were defined in the associated config
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target)
        {
            for( const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target) )
            {
                size_t l_read_spd_size = 0;
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

                // Enforce requirements
                REQUIRE(l_read_spd_size == 0);
                REQUIRE_FALSE(fapi2::current_err);

                // Get the SPD size
                REQUIRE_FALSE(getSPD(l_dimm, nullptr, l_read_spd_size));

                // "Container" for SPD data
                std::vector<uint8_t> l_spd(l_read_spd_size, 0);

                // Retrive SPD data
                REQUIRE_FALSE(getSPD(l_dimm, l_spd.data(), l_read_spd_size));

                // Create RDIMM decoder w/good VBU SPD Data
                mss::spd::rdimm_decoder_v1_0 l_decoder(l_dimm, l_spd);

                {
                    //////////////////////////////
                    /// SPD Byte 128 (Bits 4~0)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 17; // from VBU fake SPD

                    REQUIRE_FALSE( l_decoder.max_module_nominal_height(l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 129 (Bits 3~0)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0x1; // from VBU fake SPD
                    REQUIRE_FALSE( l_decoder.front_module_max_thickness(l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 129 (Bits 7~4)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0x1; // from VBU fake SPD
                    REQUIRE_FALSE( l_decoder.back_module_max_thickness(l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 130 (Bits 7~0)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0x23; // from VBU fake SPD
                    REQUIRE_FALSE( spd::reference_raw_card(l_dimm, l_spd, l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 131 (Bits 1~0)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0x1; // from VBU fake SPD
                    REQUIRE_FALSE( l_decoder.num_registers_used(l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 131 (Bits 3~2)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0x1; // from VBU fake SPD
                    REQUIRE_FALSE( l_decoder.num_rows_of_drams(l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 132 (Bits 6~0)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0x0; // from VBU fake SPD
                    REQUIRE_FALSE( l_decoder.heat_spreader_thermal_char( l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 132 (Bit 7)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0x0; // from VBU fake SPD
                    REQUIRE_FALSE( l_decoder.heat_spreader_solution( l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 133 (Bits 6~0)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0x0; // from VBU fake SPD
                    REQUIRE_FALSE( l_decoder.num_continuation_codes( l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 134 (Bits 7~0)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0xB3; // from VBU fake SPD
                    REQUIRE_FALSE( l_decoder.manufacturer_id_code(l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 135 (Bits 7~0)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0x30; // from VBU fake SPD
                    REQUIRE_FALSE( l_decoder.register_rev_num( l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 136 (Bit 0)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0x1; // from VBU fake SPD
                    REQUIRE_FALSE( l_decoder.register_to_dram_addr_mapping( l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 137 (Bits 1~0)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0x1; // from VBU fake SPD
                    REQUIRE_FALSE( l_decoder.cke_signal_output_driver( l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 137 (Bits 3~2)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0x1; // from VBU fake SPD
                    REQUIRE_FALSE( l_decoder.odt_signal_output_driver( l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 137 (Bits 5~4)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0x2; // from VBU fake SPD
                    REQUIRE_FALSE( l_decoder.ca_signal_output_driver( l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 137 (Bits 7~6)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0x1; // from VBU fake SPD
                    REQUIRE_FALSE( l_decoder.cs_signal_output_driver( l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 138 (Bits 1~0)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0x1; // from VBU fake SPD
                    REQUIRE_FALSE( l_decoder.b_side_clk_output_driver( l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 138 (Bits 3~2)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0x1; // from VBU fake SPD
                    REQUIRE_FALSE( l_decoder.a_side_clk_output_driver( l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

            }// dimm

            return 0;
        });

    }// GIVEN

    GIVEN("FAILING test cases w/invalid SPD data (rev 1.0)")
    {
        //Loops over MCBIST targets that were defined in the associated config
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target)
        {
            for( const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target) )
            {
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                uint8_t l_decoder_output = 0;
                std::vector<uint8_t> l_spd( std::begin(BAD_SPD), std::end(BAD_SPD) );

                // Enforce requirements
                REQUIRE_FALSE(fapi2::current_err);
                REQUIRE(0 == l_decoder_output);

                // Create RDIMM decoder w/BAD VBU SPD Data
                mss::spd::rdimm_decoder_v1_0 l_decoder(l_dimm, l_spd);

                //////////////////////////////
                /// SPD Byte 128 - 136
                /////////////////////////////

                // All bits are used for encoding
                // All bit combinations are valid
                // Any errors will be caught in the previous test case
                // What this means is that I CAN'T inject invalid SPD
                // to make it fail
                //////////////////////////////

                {
                    //////////////////////////////
                    /// SPD Byte 137 (Bits 1~0)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    REQUIRE( l_decoder.cke_signal_output_driver( l_decoder_output) );

                    // Output should never return JEDEC RESERVED encoding value
                    REQUIRE( 0 == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 137 (Bits 3~2)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    REQUIRE( l_decoder.odt_signal_output_driver( l_decoder_output) );

                    // Output should never return JEDEC RESERVED encoding value
                    REQUIRE( 0 == l_decoder_output);
                }

                //////////////////////////////
                /// SPD Byte 137 (Bits 5~4)
                /////////////////////////////

                // All bits are used for encoding
                // All bit combinations are valid
                // Any errors will be caught in the previous test case
                // What this means is that I CAN'T inject invalid SPD
                // to make it fail
                //////////////////////////////

                {
                    //////////////////////////////
                    /// SPD Byte 137 (Bits 7~6)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    REQUIRE( l_decoder.cs_signal_output_driver( l_decoder_output) );

                    // Output should remain unchanged
                    REQUIRE( 0 == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 138 (Bits 1~0)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    REQUIRE( l_decoder.b_side_clk_output_driver( l_decoder_output) );

                    // Output should remain unchanged
                    REQUIRE( 0 == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 138 (Bits 3~2)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    REQUIRE( l_decoder.a_side_clk_output_driver( l_decoder_output) );

                    // Output should remain unchanged
                    REQUIRE( 0 == l_decoder_output);
                }

            }// dimm

            return 0;
        });

    }// GIVEN

    GIVEN("Passing test cases w/valid VBU SPD data (rev 1.1)")
    {
        //Loops over MCBIST targets that were defined in the associated config
        for_each_target([](const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target)
        {
            for( const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target) )
            {
                size_t l_read_spd_size = 0;
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

                // Enforce requirements
                REQUIRE(l_read_spd_size == 0);
                REQUIRE_FALSE(fapi2::current_err);

                // Get the SPD size
                REQUIRE_FALSE(getSPD(l_dimm, nullptr, l_read_spd_size));

                // "Container" for SPD data
                std::vector<uint8_t> l_spd(l_read_spd_size, 0);

                // Retrive SPD data
                REQUIRE_FALSE(getSPD(l_dimm, l_spd.data(), l_read_spd_size));

                // Create RDIMM decoder w/good VBU SPD Data
                mss::spd::rdimm_decoder_v1_0 l_decoder(l_dimm, l_spd);

                //////////////////////////////
                /// SPD Byte 128 - 136
                /////////////////////////////

                // Remain unchanged from previous rev so
                // tests from rev 1.0 still valid due to inheritane

                {
                    //////////////////////////////
                    /// SPD Byte 137 (Bits 1~0)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0x1; // from VBU fake SPD
                    REQUIRE_FALSE( l_decoder.cke_signal_output_driver( l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 137 (Bits 3~2)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0x1; // from VBU fake SPD
                    REQUIRE_FALSE( l_decoder.odt_signal_output_driver( l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 137 (Bits 5~4)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0x2; // from VBU fake SPD
                    REQUIRE_FALSE( l_decoder.ca_signal_output_driver( l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 137 (Bits 7~6)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0x01; // from VBU fake SPD
                    REQUIRE_FALSE( l_decoder.cs_signal_output_driver( l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 138 (Bits 1~0)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0x1; // from VBU fake SPD
                    REQUIRE_FALSE( l_decoder.b_side_clk_output_driver( l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                {
                    //////////////////////////////
                    /// SPD Byte 138 (Bits 3~2)
                    /////////////////////////////
                    uint8_t l_decoder_output = 0;
                    uint8_t l_expected = 0x1; // from VBU fake SPD
                    REQUIRE_FALSE( l_decoder.a_side_clk_output_driver( l_decoder_output) );
                    REQUIRE( l_expected == l_decoder_output);
                }

                /////////////////////////////////
                // SPD Bytes 137 - 138 for rev 1.1
                /////////////////////////////////
                // All bits are used for encoding
                // All bit combinations are valid
                // Any errors will be caught in the previous test case
                // What this means is that I CAN'T inject invalid SPD
                // to make it fail
                //////////////////////////////

            }// dimm

            return 0;
        });

    }// GIVEN

}//scenario

} /* ns test */
} /* ns mss */
