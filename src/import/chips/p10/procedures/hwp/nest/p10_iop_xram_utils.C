/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_iop_xram_utils.C $ */
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
/// @file p10_iop_xram_utils.C
/// @brief Common code/definitions to support xram read/write HWPs.
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB, Cronus
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_iop_xram_utils.H>
#include <p10_scom_pec.H>

//@TODO: RTC 214852 - Use SCOM accessors

//------------------------------------------------------------------------------
// scomt name spaces
//------------------------------------------------------------------------------
using namespace scomt;
using namespace scomt::pec;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/// ############################################################
/// See doxygen in header file
fapi2::buffer<uint64_t> getXramAddress(const uint32_t i_offset)
{
    uint64_t l_bank = 0;
    uint64_t l_row = 0;
    fapi2::buffer<uint64_t> l_buffer(0);
    l_bank = i_offset / NUM_OF_BYTES_PER_BANK;
    l_row  = (i_offset % NUM_OF_BYTES_PER_BANK) / NUM_OF_BYTES_PER_ROW;
    // Bank = bits 0:1
    // Row  = bits 2:11
    l_buffer = (l_bank << 62) | (l_row << 52);
    return l_buffer;
}

/// ############################################################
/// See doxygen in header file
fapi2::ReturnCode validateXramAccessParms(
    const fapi2::Target < fapi2::TARGET_TYPE_PEC |
    fapi2::TARGET_TYPE_MULTICAST > & i_target,
    const uint32_t i_offset,
    const xramIopTopNum_t i_top,
    const xramPhyNum_t i_phy,
    const uint32_t i_bytes)
{
    fapi2::ATTR_CHIP_EC_FEATURE_PARTIAL_IOP_XRAM_ACCESS_ALLOWED_Type l_partialAllowed;
    // Get the proc target
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_proc = i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    // Validate offset is within range and 8-byte aligned
    FAPI_ASSERT( (i_offset < MAX_XRAM_IMAGE_SIZE) &&
                 (!(i_offset & 0x7)),
                 fapi2::P10_IOP_XRAM_OFFSET_ERROR().set_OFFSET(i_offset),
                 "validateXramAccessParms: XRAM offset must be < 32K and 8-byte aligned: Offset 0x%.16llX.",
                 i_offset);

    // Validate Top and Phy numbers
    FAPI_ASSERT( (i_top <= 1) && (i_phy <= 1),
                 fapi2::P10_IOP_TOP_PHY_ERROR()
                 .set_IOP_TOP(i_top)
                 .set_XRAM_PHY(i_phy),
                 "validateXramAccessParms: XRAM Iop_top and/or Phy values are invalid. i_top %d, i_phy %d.",
                 i_top, i_phy);

    // Validate read/write size: Must write full XRAM (32K) if DD1.0
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_PARTIAL_IOP_XRAM_ACCESS_ALLOWED,
                           l_proc, l_partialAllowed),
             "Error getting the ATTR_CHIP_EC_FEATURE_PARTIAL_IOP_XRAM_ACCESS_ALLOWED");
    FAPI_ASSERT( (l_partialAllowed && i_bytes <= MAX_XRAM_IMAGE_SIZE) ||
                 (i_bytes == MAX_XRAM_IMAGE_SIZE),
                 fapi2::P10_IOP_XRAM_ACCESS_SIZE_ERROR()
                 .set_ACCESS_SIZE(i_bytes),
                 "validateXramAccessParms: Access size (%u) is invalid.", i_bytes);

fapi_try_exit:
    return fapi2::current_err;
}

/// ############################################################
/// See doxygen in header file
fapi2::ReturnCode doPhyReset(
    const fapi2::Target < fapi2::TARGET_TYPE_PEC |
    fapi2::TARGET_TYPE_MULTICAST > & i_target)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_CPLT_CTRL0_reg(0);
    fapi2::buffer<uint64_t> l_arrayModeReg(0);
    uint64_t l_xramBaseReg = 0;
    uint32_t l_pollCount = 0;

    // display target information for this chip
#ifdef __PPE__
    FAPI_INF("Input Multicast Target:0x%.8x", i_target.get());
#else
    char l_target_str[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_target, l_target_str, sizeof(l_target_str));
    FAPI_INF("Target: %s", l_target_str);
#endif

    // Note: Reset CPLT_CTRL0 bit 55 feeds to both iop_top instances and both PHYs
    //    1. Drive PHY reset to 1
    //    2. Drive PHY reset to 0
    //    3. Poll for SRAM init done

    // 1. Drive PHY reset to 1
    FAPI_TRY(PREP_CPLT_CTRL0_WO_OR(i_target),
             "doPhyReset: PREP_CPLT_CTRL0_WO_OR returns an error.");
    SET_CPLT_CTRL0_TC_CCFG_FUNC_PHY_RESET_DC(l_CPLT_CTRL0_reg); // Set bit 55 to reset
    FAPI_TRY(PUT_CPLT_CTRL0_WO_OR(i_target, l_CPLT_CTRL0_reg),
             "doPhyReset: PUT_CPLT_CTRL0_WO_OR returns an error.");

    // 2. Drive PHY reset to 0
    FAPI_TRY(PREP_CPLT_CTRL0_WO_CLEAR(i_target),
             "doPhyReset: PREP_CPLT_CTRL0_WO_CLEAR returns an error.");
    FAPI_TRY(PUT_CPLT_CTRL0_WO_CLEAR(i_target, l_CPLT_CTRL0_reg), // Clear bit 55
             "doPhyReset: PUT_CPLT_CTRL0_WO_CLEAR returns an error..");

    // 3. Poll for SRAM init done (on both tops and both PHYs of each PEC)
    for (auto l_pec : i_target.getChildren<fapi2::TARGET_TYPE_PEC>())
    {
        for (uint8_t l_top = 0; l_top < NUM_OF_IO_TOPS; l_top++)
        {
            l_pollCount = 0;

            while (l_pollCount <= SRAM_INIT_DONE_POLLS)
            {
                l_xramBaseReg = getXramBaseReg(static_cast<xramIopTopNum_t>(l_top));
                FAPI_TRY(fapi2::getScom(l_pec,
                                        l_xramBaseReg + XRAM_ARRAY_MODE_REG_OFFSET,
                                        l_arrayModeReg),
                         "Error from getScom 0x%.16llX", l_xramBaseReg + XRAM_ARRAY_MODE_REG_OFFSET);

                if ( l_arrayModeReg.getBit<ARRAY_MODE_REG_PHY0_SRAM_INIT_DONE_BIT>() &&
                     l_arrayModeReg.getBit<ARRAY_MODE_REG_PHY1_SRAM_INIT_DONE_BIT>() )
                {
                    break;
                }

                l_pollCount++;
                fapi2::delay(SRAM_INIT_DONE_POLL_DELAY_HW_NS,
                             SRAM_INIT_DONE_POLL_DELAY_SIM_CYCLE);
            }

            FAPI_ASSERT( (l_pollCount < SRAM_INIT_DONE_POLLS),
                         fapi2::P10_IOP_XRAM_INIT_TIMEOUT_ERROR()
                         .set_TARGET(l_pec)
                         .set_TOP(l_top)
                         .set_ARRAY_MODE_REG(l_arrayModeReg),
                         "doPhyReset: SRAM init_done timeout error , top %d.", l_top);

        }
    }


fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// ############################################################
/// See doxygen in header file
uint64_t getXramBaseReg(xramIopTopNum_t i_top)
{
    uint64_t l_xramBaseReg = 0;

    if (i_top == XRAM_TOP_0)
    {
        l_xramBaseReg = IOP_TOP0_XRAM_BASE_REG;
    }
    else
    {
        l_xramBaseReg = IOP_TOP1_XRAM_BASE_REG;
    }

    return l_xramBaseReg;
}

/// ############################################################
/// See doxygen in header file
fapi2::ReturnCode setPhyLoadDone(
    const fapi2::Target < fapi2::TARGET_TYPE_PEC |
    fapi2::TARGET_TYPE_MULTICAST > & i_target,
    const xramIopTopNum_t i_top,
    const xramPhyNum_t i_phy)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_xramArrayMode_reg(0);
    uint64_t l_xramBaseReg = getXramBaseReg(i_top);

    FAPI_DBG("setPhyLoadDone: i_top %d, i_phy %d", i_top, i_phy);

    // Need to do RMW on individual PEC
    for (auto l_pec : i_target.getChildren<fapi2::TARGET_TYPE_PEC>())
    {
        FAPI_TRY(fapi2::getScom(l_pec,
                                l_xramBaseReg + XRAM_ARRAY_MODE_REG_OFFSET,
                                l_xramArrayMode_reg),
                 "Error from getScom 0x%.16llX", l_xramBaseReg + XRAM_ARRAY_MODE_REG_OFFSET);

        l_xramArrayMode_reg.setBit(ARRAY_MODE_REG_PHY0_SRAM_EXT_LOAD_DONE_BIT + i_phy);

        FAPI_TRY(fapi2::putScom(l_pec, l_xramBaseReg + XRAM_ARRAY_MODE_REG_OFFSET,
                                l_xramArrayMode_reg),
                 "Error from putScom 0x%.16llX", l_xramBaseReg + XRAM_ARRAY_MODE_REG_OFFSET);
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// ############################################################
/// See doxygen in header file
fapi2::ReturnCode enableXramScrubber(
    const fapi2::Target < fapi2::TARGET_TYPE_PEC |
    fapi2::TARGET_TYPE_MULTICAST > & i_target,
    const xramIopTopNum_t i_top)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_xramArrayMode_reg(0);
    uint64_t l_xramBaseReg = getXramBaseReg(i_top);

    FAPI_DBG("enableXramScrubber: i_top %d", i_top);

    // Need to do RMW on individual PEC
    for (auto l_pec : i_target.getChildren<fapi2::TARGET_TYPE_PEC>())
    {
        // Set scrubber bit in mode reg
        FAPI_TRY(fapi2::getScom(l_pec,
                                l_xramBaseReg + XRAM_ARRAY_MODE_REG_OFFSET,
                                l_xramArrayMode_reg),
                 "Error from getScom 0x%.16llX", l_xramBaseReg + XRAM_ARRAY_MODE_REG_OFFSET);
        l_xramArrayMode_reg.setBit<ARRAY_MODE_REG_ENABLE_SCRUBBER_BIT>();

        FAPI_TRY(fapi2::putScom(l_pec, l_xramBaseReg + XRAM_ARRAY_MODE_REG_OFFSET,
                                l_xramArrayMode_reg),
                 "Error from putScom 0x%.16llX", l_xramBaseReg + XRAM_ARRAY_MODE_REG_OFFSET);
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// ############################################################
/// See doxygen in header file
fapi2::ReturnCode autoIncrementControl(
    const fapi2::Target < fapi2::TARGET_TYPE_PEC |
    fapi2::TARGET_TYPE_MULTICAST > & i_target,
    const xramIopTopNum_t i_top,
    const bool i_enable,
    const bool i_write_op)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_xramArrayMode_reg(0);
    uint64_t l_xramBaseReg = getXramBaseReg(i_top);

    FAPI_DBG("enableAutoIncrement: i_top %d, Action - Enable[1]/Disable[0] - %d,"
             " Oper - Write[1]/Read[0] - %d", i_top, i_enable, i_write_op);

    // Need to do RMW on individual PEC
    for (auto l_pec : i_target.getChildren<fapi2::TARGET_TYPE_PEC>())
    {
        FAPI_TRY(fapi2::getScom(l_pec,
                                l_xramBaseReg + XRAM_ARRAY_MODE_REG_OFFSET,
                                l_xramArrayMode_reg),
                 "Error from getScom 0x%.16llX", l_xramBaseReg + XRAM_ARRAY_MODE_REG_OFFSET);

        // Enable autoinc
        if (i_enable)
        {
            l_xramArrayMode_reg.setBit<ARRAY_MODE_REG_SCOM_ACCESS_MODE>();

            if (i_write_op) // Write
            {
                l_xramArrayMode_reg.setBit<ARRAY_MODE_REG_SCOM_AUTOINC_RW>();
            }
            else // Read
            {
                l_xramArrayMode_reg.clearBit<ARRAY_MODE_REG_SCOM_AUTOINC_RW>();
            }
        }
        // Disable autoinc
        else
        {
            l_xramArrayMode_reg.clearBit<ARRAY_MODE_REG_SCOM_ACCESS_MODE>();
        }

        FAPI_TRY(fapi2::putScom(l_pec, l_xramBaseReg + XRAM_ARRAY_MODE_REG_OFFSET,
                                l_xramArrayMode_reg),
                 "Error from putScom 0x%.16llX", l_xramBaseReg + XRAM_ARRAY_MODE_REG_OFFSET);
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
