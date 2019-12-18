/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_read_xram.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
/// @file p10_read_xram.H
/// @brief Read a block of data from IOP XRAM
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: Cronus
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_read_xram.H>
#include <p10_scom_pec.H>

//------------------------------------------------------------------------------
// scomt name spaces
//------------------------------------------------------------------------------
using namespace scomt;
using namespace scomt::pec;

//@TODO: RTC 214852 - Use SCOM accessors, remove workaround code

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/// NOTE: doxygen in header
fapi2::ReturnCode p10_read_xram(
    const fapi2::Target < fapi2::TARGET_TYPE_PEC >& i_target,
    const uint32_t i_offset,
    const uint32_t i_bytes,
    const xramIopTopNum_t i_top,
    const xramPhyNum_t i_phy,
    uint8_t* o_data)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_dataBuf(0);
    fapi2::buffer<uint64_t> l_offsetBuf(0);
    uint8_t* l_dataPtr = o_data;
    uint64_t l_xramBaseReg = getXramBaseReg(i_top);
    uint64_t l_data = 0;

    FAPI_INF("p10_read_xram: i_offset %p, i_bytes %lu, i_top %d, i_phy %d.",
             i_offset, i_bytes, i_top, i_phy);

    // Validate input parameters
    FAPI_TRY(validateXramAccessParms(i_offset, i_top, i_phy),
             "validateXramAccessParms returns an error.");

    // Enable auto-inc mode for read
    FAPI_TRY(autoIncrementControl(i_target, i_top, true, false),
             "autoIncrementControl returns an error.");

    // Auto-increment read:
    //   - Do NOT setup Array Address Register.  The read will start
    //     at address 0 as was set via scaninit.
    //
    // Individual read:
    //   - Need to setup Array Address Register with write address and
    //     bit 16 clear.
    //   - Currently, we don't support individual read operation.
    //

// For furture invidual read support
#if 0
    // Setup Array Address Register for read
    l_offsetBuf = getXramAddress(i_offset);
    l_offsetBuf.clearBit<ARRAY_ADDR_REG_RW_SELECT_BIT>();
    FAPI_TRY(fapi2::putScom(i_target,
                            l_xramBaseReg + XRAM_ARRAY_ADDR_REG_PHY0_OFFSET + i_phy,
                            l_offsetBuf),
             "Error from putScom 0x%.16llX",
             l_xramBaseReg + XRAM_ARRAY_ADDR_REG_PHY0_OFFSET + i_phy);
#endif

    // Read i_bytes data
    FAPI_DBG("p10_read_xram: Start reading data...");

    while (l_dataPtr < (o_data + i_bytes))
    {
        // Read data from Array Data Register (8 bytes)
        FAPI_TRY(fapi2::getScom(i_target,
                                l_xramBaseReg + XRAM_ARRAY_DATA_REG_PHY0_OFFSET + i_phy,
                                l_dataBuf),
                 "Error from getScom 0x%.16llX",
                 l_xramBaseReg + XRAM_ARRAY_DATA_REG_PHY0_OFFSET + i_phy);

        // Copy 8-byte data to output buffer
        l_data = l_dataBuf();

        for (uint8_t ii = 0; ii < 8; ii++)
        {
            *l_dataPtr++ = (l_data >> (56 - (ii * 8))) & 0xFFull;

            // Exit if size has reached
            if (l_dataPtr >= o_data + i_bytes)
            {
                break;
            }
        }
    }

    // Disable auto-inc mode
    FAPI_TRY(autoIncrementControl(i_target, i_top, false, false),
             "autoIncrementControl returns an error.");

    FAPI_DBG("p10_read_xram: Done reading data.");

fapi_try_exit:
    FAPI_DBG("End");

    return fapi2::current_err;
}
