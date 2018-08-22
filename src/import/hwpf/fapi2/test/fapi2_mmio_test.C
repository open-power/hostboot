/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/test/fapi2_mmio_test.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/**
 * @file fapi2_mmio_test.C
 * @brief simple testcase for vpd function does not go to
 *        offical platfom code.
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <stdint.h>
#include <iostream>
#include <thread>
#include <assert.h>

#include <target.H>
#include <target_types.H>
#include <return_code_defs.H>
#include <return_code.H>
#include <mmio_access.H>

TEST_CASE("doMMIO:")
{

    fapi2::ReturnCode l_rc;
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_target;

    // Do a read
    constexpr size_t BUF1_SIZE_BYTES = 4;
    uint64_t l_mmio1 = 0x100;
    std::vector<uint8_t> l_buf1(BUF1_SIZE_BYTES);
    l_rc = fapi2::getMMIO( l_target, l_mmio1, 4, l_buf1 );
    REQUIRE( (uint64_t)l_rc == fapi2::FAPI2_RC_SUCCESS );

    for (uint8_t i = 0; i < BUF1_SIZE_BYTES; i++)
    {
        REQUIRE( i == l_buf1[i] );
    }


    // Do a write
    uint64_t l_mmio2 = 0x200;
    std::vector<uint8_t> l_buf2(60);

    for (uint32_t i = 0; i < l_buf2.size(); i++)
    {
        l_buf2[i] = i + 0x10;
    }

    l_rc = fapi2::putMMIO( l_target, l_mmio2, 2, l_buf2 );
    REQUIRE( (uint64_t)l_rc == fapi2::FAPI2_RC_SUCCESS );

}
