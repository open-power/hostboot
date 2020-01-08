/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_iop_xram_utils.H $ */
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
/// @file p10_iop_xram_utils.H
/// @brief Common code/definitions to support xram read/write HWPs.
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB, Cronus
///

#ifndef _P10_IO_XRAM_UTILS_H_
#define _P10_IO_XRAM_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//----------------------------------------------------------------------------
// Constant definitions
//----------------------------------------------------------------------------
const uint32_t SRAM_INIT_DONE_POLLS                = 5;
const uint32_t SRAM_INIT_DONE_POLL_DELAY_HW_NS     = 10000; // 10us poll loop delay
const uint32_t SRAM_INIT_DONE_POLL_DELAY_SIM_CYCLE = 50000; // 50k sim cycle delay

const uint32_t MAX_XRAM_IMAGE_SIZE   = 0x0000000000008000; // 32K bytes
const uint8_t  NUM_OF_BANKS          = 4;
const uint32_t NUM_OF_BYTES_PER_BANK = MAX_XRAM_IMAGE_SIZE / NUM_OF_BANKS;  // 8192
const uint8_t  NUM_OF_BYTES_PER_ROW  = 8;
const uint8_t  NUM_OF_BYTES_PER_WORD = 2;
const uint8_t  NUM_OF_IO_TOPS = 2;
const uint8_t  NUM_OF_PHYS = 2;

//@TODO: RTC 214852 - Use SCOM accessors
const uint64_t IOP_TOP0_XRAM_BASE_REG        = 0x08011100ULL;
const uint64_t IOP_TOP1_XRAM_BASE_REG        = 0x08011500ULL;
// Register offsets from base
const uint64_t XRAM_ARRAY_ADDR_REG_PHY0_OFFSET  = 10;
const uint64_t XRAM_ARRAY_ADDR_REG_PHY1_OFFSET  = 11;
const uint64_t XRAM_ARRAY_DATA_REG_PHY0_OFFSET  = 12;
const uint64_t XRAM_ARRAY_DATA_REG_PHY1_OFFSET  = 13;
const uint64_t XRAM_ARRAY_MODE_REG_OFFSET       = 14;

// Bit definitions for Array Mode Register
const uint8_t ARRAY_MODE_REG_PHY0_SRAM_EXT_LOAD_DONE_BIT  = 0;
const uint8_t ARRAY_MODE_REG_PHY1_SRAM_EXT_LOAD_DONE_BIT  = 1;
const uint8_t ARRAY_MODE_REG_SCOM_ACCESS_MODE             = 2;
const uint8_t ARRAY_MODE_REG_SCOM_AUTOINC_RW              = 3;
const uint8_t ARRAY_MODE_REG_PHY0_SRAM_INIT_DONE_BIT      = 4;
const uint8_t ARRAY_MODE_REG_PHY1_SRAM_INIT_DONE_BIT      = 5;
const uint8_t ARRAY_MODE_REG_ENABLE_SCRUBBER_BIT          = 17;

// Bit definitions for Array Address Register
const uint8_t ARRAY_ADDR_REG_RW_SELECT_BIT  = 16;

// XRAM iop_top enum
enum xramIopTopNum_t
{
    XRAM_TOP_0   = 0,
    XRAM_TOP_1   = 1
};

// XRAM PHY enum
enum xramPhyNum_t
{
    XRAM_PHY_0   = 0,
    XRAM_PHY_1   = 1
};

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
//

extern "C" {

///
/// @brief Assemble 12-bit address of XRAM based on input offset.
/// @param[in]   i_offset    Byte offset from XRAM 0 location
///
/// @return Assembled address
///
    fapi2::buffer<uint64_t> getXramAddress(const uint32_t i_offset);

///
/// @brief Check if input offset is 8-byte aligned.
/// @param[in]  i_target    Reference PEC or PEC multicast target
/// @param[in]  i_offset    Byte offset from XRAM 0 location
/// @param[in]  i_offset    Byte offset from XRAM 0 location
/// @param[in]  i_top       iop_top to read/write XRAM
/// @param[in]  i_phy       Phy to read/write XRAM
/// @param[in]  i_bytes     Read/write size (bytes)
///
/// @return FAPI_RC_SUCCESS if 8-byte aligned, else error code
///
    fapi2::ReturnCode validateXramAccessParms(
        const fapi2::Target < fapi2::TARGET_TYPE_PEC |
        fapi2::TARGET_TYPE_MULTICAST > & i_target,
        const uint32_t i_offset,
        const xramIopTopNum_t i_top,
        const xramPhyNum_t i_phy,
        const uint32_t i_bytes);

///
/// @brief Perform PHYs reset
/// @param[in]  i_target    Reference PEC or PEC multicast target
/// @return FAPI_RC_SUCCESS if 8-byte aligned, else error code
///
    fapi2::ReturnCode doPhyReset(
        const fapi2::Target < fapi2::TARGET_TYPE_PEC |
        fapi2::TARGET_TYPE_MULTICAST > & i_target);
///
/// @brief Return XRAM base address for input iop_top
/// @param[in]  i_top    iop_top
///
/// @return XRAM base address
///
    uint64_t getXramBaseReg(xramIopTopNum_t i_top);

///
/// @brief Set PHY load done. This fuction is called in p10_write_xram
///        when a PHY FW load is complete.
/// @param[in]  i_target    Reference PEC or PEC multicast target
/// @param[in]  i_top       iop_top
/// @param[in]  i_phy       Phy to read/write XRAM
///
/// @return FAPI_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode setPhyLoadDone(
        const fapi2::Target < fapi2::TARGET_TYPE_PEC |
        fapi2::TARGET_TYPE_MULTICAST > & i_target,
        const xramIopTopNum_t i_top,
        const xramPhyNum_t i_phy);

///
/// @brief Enable XRAM scrubber for this iop_top
/// @param[in]  i_target    Reference PEC or PEC multicast target
/// @param[in]  i_top       iop_top
///
/// @return FAPI_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode enableXramScrubber(
        const fapi2::Target < fapi2::TARGET_TYPE_PEC |
        fapi2::TARGET_TYPE_MULTICAST > & i_target,
        const xramIopTopNum_t i_top);

///
/// @brief Controls XRAM SCOM auto-increment mode
/// @param[in]  i_target    Reference PEC or PEC multicast target
/// @param[in]  i_top       iop_top
/// @param[in]  i_enable    true: enable; false: disable
/// @param[in]  i_write_op  true: write; false: read
///
/// @return FAPI_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode autoIncrementControl(
        const fapi2::Target < fapi2::TARGET_TYPE_PEC |
        fapi2::TARGET_TYPE_MULTICAST > & i_target,
        const xramIopTopNum_t i_top,
        const bool i_enable,
        const bool i_write_op);

} //extern "C"

#endif //_P10_IO_XRAM_UTILS_H_
