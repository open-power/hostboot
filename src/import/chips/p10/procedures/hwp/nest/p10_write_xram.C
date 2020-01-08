/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_write_xram.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p10_write_xram.C
/// @brief Write data to IOP XRAM
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB, Cronus
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_write_xram.H>
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
fapi2::ReturnCode p10_write_xram(
    const fapi2::Target < fapi2::TARGET_TYPE_PEC |
    fapi2::TARGET_TYPE_MULTICAST > & i_target,
    const uint32_t i_offset,
    const uint32_t i_bytes,
    const xramIopTopNum_t i_top,
    const xramPhyNum_t i_phy,
    uint8_t* i_data)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_dataBuf(0);
    fapi2::buffer<uint64_t> l_offsetBuf(0);
    uint8_t* l_dataPtr = i_data;
    uint64_t l_xramBaseReg = getXramBaseReg(i_top);
    uint64_t l_data = 0;

    FAPI_INF("p10_write_xram: i_offset %p, i_bytes %lu, i_top %d, i_phy %d.",
             i_offset, i_bytes, i_top, i_phy);

    // Validate input parameters
    FAPI_TRY(validateXramAccessParms(i_target, i_offset, i_top, i_phy, i_bytes),
             "validateXramAccessParms returns an error.");

    // Enable auto-inc mode for write
    FAPI_TRY(autoIncrementControl(i_target, i_top, true, true),
             "autoIncrementControl Enable returns an error.");

    // Auto-increment write:
    //   - Do NOT setup Array Address Register.  The write will start
    //     at address 0 as was set via scaninit.
    //
    // Individual write:
    //   - Need to setup Array Address Register with write address and
    //     bit 16 set.
    //   - Currently, we don't support individual write operation.
    //
// For furture invidual write support
#if 0
    // Setup Array Address Register for write
    l_offsetBuf = getXramAddress(i_offset);
    l_offsetBuf.setBit<ARRAY_ADDR_REG_RW_SELECT_BIT>();
    FAPI_TRY(fapi2::putScom(i_target,
                            l_xramBaseReg + XRAM_ARRAY_ADDR_REG_PHY0_OFFSET + i_phy,
                            l_offsetBuf),
             "Error from putScom 0x%.16llX",
             l_xramBaseReg + XRAM_ARRAY_ADDR_REG_PHY0_OFFSET + i_phy);
#endif

    // Write data, 8-byte chunk at a time
    FAPI_DBG("p10_write_xram: Start writing data...");


    while (l_dataPtr < (i_data + i_bytes))
    {
        // Load 8 bytes into 64-bit word
        l_data = 0;

        for (uint8_t ii = 0; ii < 8; ii++)
        {
            l_data |= ( static_cast<uint64_t>(*l_dataPtr++) << (56 - (8 * ii)) );

            // Exit if size has reached. Remaining data in double words are zeroes
            if (l_dataPtr >= i_data + i_bytes)
            {
                break;
            }
        }

        // Write data to Array Data Register
        l_dataBuf = l_data;
        FAPI_TRY(fapi2::putScom(i_target,
                                l_xramBaseReg + XRAM_ARRAY_DATA_REG_PHY0_OFFSET + i_phy,
                                l_dataBuf),
                 "Error from putScom 0x%.16llX",
                 l_xramBaseReg + XRAM_ARRAY_DATA_REG_PHY0_OFFSET + i_phy);
    }

    FAPI_DBG("p10_write_xram: Done writing data.");

    // Disable auto-inc mode
    FAPI_TRY(autoIncrementControl(i_target, i_top, false, true),
             "autoIncrementControl disable returns an error.");

    // Set XRAM load done
    FAPI_TRY(setPhyLoadDone(i_target, i_top, i_phy),
             "p10_write_xram: setPhyLoadDone returns an error.");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
