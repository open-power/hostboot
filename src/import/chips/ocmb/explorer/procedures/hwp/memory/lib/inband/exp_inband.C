/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/inband/exp_inband.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

/// @file exp_inband.C
/// @brief implement OpenCAPI config, scom, and MSCC MMIO operations.
//
// *HWP HWP Owner: bgass@us.ibm.com
// *HWP FW Owner: dcrowell@us.ibm.com
// *HWP Team:
// *HWP Level: 3
// *HWP Consumed by: HB

#include <lib/inband/exp_inband.H>
#include <lib/omi/crc32.H>
#include <lib/shared/exp_consts.H>
#include <lib/exp_draminit_utils.H>
#include <lib/exp_attribute_accessors_manual.H>
#include <mmio_access.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/endian_utils.H>

namespace mss
{

namespace exp
{

namespace ib
{

//--------------------------------------------------------------------------------
// Write operations
//--------------------------------------------------------------------------------

/// @brief Writes 64 bits of data to MMIO space to the selected Explorer
///
/// @param[in] i_target     The Explorer chip to write
/// @param[in] i_addr       The address to write
/// @param[in] i_data       The data to write
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode putMMIO64(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint64_t i_addr,
    const fapi2::buffer<uint64_t>& i_data)
{
    uint64_t l_v = static_cast<uint64_t>(i_data);
    std::vector<uint8_t> l_wd;
    forceLE(l_v, l_wd);
    return fapi2::putMMIO(i_target, EXPLR_IB_MMIO_OFFSET | i_addr, 8, l_wd);
}

/// @brief Writes 32 bits of data to MMIO space to the selected Explorer
///
/// @param[in] i_target     The Explorer chip to write
/// @param[in] i_addr       The address to write
/// @param[in] i_data       The data to write
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode putMMIO32(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint64_t i_addr,
    const fapi2::buffer<uint32_t>& i_data)
{
    uint32_t l_v = static_cast<uint32_t>(i_data);
    std::vector<uint8_t> l_wd;
    forceLE(l_v, l_wd);
    return fapi2::putMMIO(i_target, EXPLR_IB_MMIO_OFFSET | i_addr, 4, l_wd);
}

/// @brief Writes 64 bits of data to SCOM MMIO space
///
/// @param[in] i_target     The Explorer chip to write
/// @param[in] i_scomAddr   The address to write
/// @param[in] i_data       The data to write
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode putScom(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint64_t i_scomAddr,
    const fapi2::buffer<uint64_t>& i_data)
{
    // Converts from the scom address to the MMIO address by shifting left by 3 bits
    uint64_t l_scomAddr = i_scomAddr << OCMB_ADDR_SHIFT;
    return putMMIO64(i_target, l_scomAddr, i_data);
}

/// @brief Writes user_input_msdg to the data buffer
///
/// @param[in] i_target     The Explorer chip to issue the command to
/// @param[in] i_data       The user_input_msdg data to write
/// @param[out] o_crc       The calculated crc of the data.
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode putUserInputMsdg(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const user_input_msdg& i_data,
    uint32_t& o_crc)
{
    uint32_t l_fw_version = 0;
    FAPI_TRY(mss::get_booted_fw_version(i_target, l_fw_version));

    {
        const bool is_new_fw_ver = is_new_fw_msdg_supported(l_fw_version);
        std::vector<uint8_t> l_data;

        FAPI_TRY(user_input_msdg_to_little_endian(i_data, is_new_fw_ver, l_data, o_crc));

        FAPI_TRY(fapi2::putMMIO(i_target, EXPLR_IB_DATA_ADDR, BUFFER_TRANSACTION_SIZE, l_data));
    }

fapi_try_exit:
    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t)fapi2::current_err);
    return fapi2::current_err;
}

/// @brief Writes 32 bits of data to OpenCAPI config space
///
/// @param[in] i_target     The Explorer chip to write
/// @param[in] i_cfgAddr    The address to write
/// @param[in] i_data       The data to write
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode putOCCfg(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint64_t i_cfgAddr,
    const fapi2::buffer<uint32_t>& i_data)
{
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    uint32_t l_v = static_cast<uint32_t>(i_data);
    std::vector<uint8_t> l_wd;
    fapi2::ATTR_MSS_OCMB_EXP_OMI_CFG_ENDIAN_CTRL_Type l_endian;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_EXP_OMI_CFG_ENDIAN_CTRL,
                           FAPI_SYSTEM, l_endian));

    if (l_endian == fapi2::ENUM_ATTR_MSS_OCMB_EXP_OMI_CFG_ENDIAN_CTRL_LITTLE_ENDIAN)
    {
        forceLE(l_v, l_wd);
    }
    else
    {
        forceBE(l_v, l_wd);
    }

    FAPI_TRY(fapi2::putMMIO(i_target, i_cfgAddr, 4, l_wd));

fapi_try_exit:
    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t)fapi2::current_err);
    return fapi2::current_err;
}

fapi2::ReturnCode host_fw_command_struct_to_little_endian(const host_fw_command_struct& i_input,
        std::vector<uint8_t>& o_data)
{
    uint32_t l_cmd_header_crc = 0;
    FAPI_TRY(forceCrctEndian(i_input.cmd_id, o_data));
    FAPI_TRY(forceCrctEndian(i_input.cmd_flags, o_data));
    FAPI_TRY(forceCrctEndian(i_input.request_identifier, o_data));
    FAPI_TRY(forceCrctEndian(i_input.cmd_length, o_data));
    FAPI_TRY(forceCrctEndian(i_input.cmd_crc, o_data));
    FAPI_TRY(forceCrctEndian(i_input.host_work_area, o_data));
    FAPI_TRY(forceCrctEndian(i_input.cmd_work_area, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.padding, CMD_PADDING_SIZE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.command_argument, ARGUMENT_SIZE, o_data));

    // Generates and adds on the CRC
    l_cmd_header_crc = crc32_gen(o_data);
    FAPI_DBG("Command header crc: %xl", l_cmd_header_crc);
    FAPI_TRY(forceCrctEndian(l_cmd_header_crc, o_data));
    padCommData(o_data);
    FAPI_TRY(correctMMIOEndianForStruct(o_data));
    FAPI_TRY(correctMMIOword_order(o_data));

fapi_try_exit:
    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t)fapi2::current_err);
    return fapi2::current_err;
}

/// @brief Writes a command to the command buffer and issues interrupt
///
/// @param[in] i_target     The Explorer chip to issue the command to
/// @param[in] i_cmd        The command structure to write
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode putCMD(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const host_fw_command_struct& i_cmd)
{
    std::vector<uint8_t> l_data;
    fapi2::buffer<uint64_t> l_scom;

    FAPI_TRY(host_fw_command_struct_to_little_endian(i_cmd, l_data));

    // Clear the doorbell
    l_scom.setBit<EXPLR_MMIO_MDBELLC_MDBELL_MDBELL>();
    FAPI_DBG("Clearing the inbound doorbell...");
    FAPI_TRY(fapi2::putScom(i_target, EXPLR_MMIO_MDBELLC, l_scom), "Failed to clear inbound doorbell register");

    // Clear the response doorbell, just in case the last response didn't get cleared
    FAPI_TRY(clear_outbound_doorbell(i_target));

    // Set the command
    FAPI_DBG("Writing the command...");
    FAPI_TRY(fapi2::putMMIO(i_target, EXPLR_IB_CMD_ADDR, BUFFER_TRANSACTION_SIZE, l_data),
             "Failed to write to the command buffer");

    // Ring the doorbell - aka the bit that interrupts the microchip FW and tells it to do the thing
    l_scom.flush<0>();
    l_scom.setBit<EXPLR_MMIO_MDBELL_MDBELL>();
    FAPI_DBG("Setting the inbound doorbell...");
    FAPI_TRY(fapi2::putScom(i_target, EXPLR_MMIO_MDBELL, l_scom), "Failed to set inbound doorbell bit");

fapi_try_exit:
    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t)fapi2::current_err);
    return fapi2::current_err;
}

//--------------------------------------------------------------------------------
// Read operations
//--------------------------------------------------------------------------------

/// @brief Reads 64 bits of data from MMIO space on the selected Explorer
///
/// @param[in] i_target     The Explorer chip to read data from
/// @param[in] i_addr       The address to read
/// @param[out] o_data      The data read from the address
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode getMMIO64(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint64_t i_addr,
    fapi2::buffer<uint64_t>& o_data)
{
    uint64_t l_rd = 0;
    std::vector<uint8_t> l_data(8);
    uint32_t l_idx = 0;
    FAPI_TRY(fapi2::getMMIO(i_target, EXPLR_IB_MMIO_OFFSET | i_addr, 8, l_data));
    readLE(l_data, l_idx, l_rd);
    o_data = l_rd;
fapi_try_exit:
    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t)fapi2::current_err);
    return fapi2::current_err;
}

/// @brief Reads 32 bits of data from MMIO space on the selected Explorer
///
/// @param[in] i_target     The Explorer chip to read data from
/// @param[in] i_addr       The address to read
/// @param[out] o_data      The data read from the address
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode getMMIO32(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint64_t i_addr,
    fapi2::buffer<uint32_t>& o_data)
{
    uint32_t l_rd = 0;
    std::vector<uint8_t> l_data(4);
    uint32_t l_idx = 0;
    FAPI_TRY(fapi2::getMMIO(i_target, EXPLR_IB_MMIO_OFFSET | i_addr, 4, l_data));
    readLE(l_data, l_idx, l_rd);
    o_data = l_rd;
fapi_try_exit:
    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t)fapi2::current_err);
    return fapi2::current_err;
}

/// @brief Reads 64 bits of data from SCOM MMIO space on the selected Explorer
///
/// @param[in] i_target     The Explorer chip to read data from
/// @param[in] i_scomAddr   The address to read
/// @param[out] o_data      The data read from the address
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode getScom(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint64_t i_scomAddr,
    fapi2::buffer<uint64_t>& o_data)
{
    // Converts from the scom address to the MMIO address by shifting left by 3 bits
    uint64_t l_scomAddr = i_scomAddr << OCMB_ADDR_SHIFT;
    return getMMIO64(i_target, l_scomAddr, o_data);
}

/// @brief Reads 32 bits of data from OpenCAPI config space on the selected Explorer
///
/// @param[in] i_target     The Explorer chip to read data from
/// @param[in] i_cfgAddr    The address to read
/// @param[out] o_data      The data read from the address
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode getOCCfg(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint64_t i_cfgAddr,
    fapi2::buffer<uint32_t>& o_data)
{
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    uint32_t l_rd = 0;
    std::vector<uint8_t> l_data(4);
    uint32_t l_idx = 0;
    fapi2::ATTR_MSS_OCMB_EXP_OMI_CFG_ENDIAN_CTRL_Type l_endian;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_EXP_OMI_CFG_ENDIAN_CTRL,
                           FAPI_SYSTEM, l_endian));

    FAPI_TRY(fapi2::getMMIO(i_target, i_cfgAddr, 4, l_data));

    if (l_endian == fapi2::ENUM_ATTR_MSS_OCMB_EXP_OMI_CFG_ENDIAN_CTRL_LITTLE_ENDIAN)
    {
        readLE(l_data, l_idx, l_rd);
    }
    else
    {
        readBE(l_data, l_idx, l_rd);
    }

    o_data = l_rd;
fapi_try_exit:
    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t)fapi2::current_err);
    return fapi2::current_err;
}

///
/// @brief Converts a little endian data array to a host_fw_response_struct
/// @param[in,out] io_data little endian data to process
/// @param[out] o_crc computed CRC
/// @param[out] o_response response structure
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode host_fw_response_struct_from_little_endian(
    std::vector<uint8_t>& io_data,
    uint32_t& o_crc,
    host_fw_response_struct& o_response)
{
    uint32_t l_idx = 0;

    uint8_t l_response_id = 0;
    uint8_t l_response_flags = 0;
    uint16_t l_request_identifier = 0;
    uint32_t l_response_length = 0;
    uint32_t l_response_crc = 0;
    uint32_t l_host_work_area = 0;
    uint32_t l_response_header_crc = 0;

    FAPI_TRY(correctMMIOEndianForStruct(io_data));
    FAPI_TRY(correctMMIOword_order(io_data));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_id));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_flags));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_request_identifier));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_length));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_crc));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_host_work_area));
    FAPI_TRY(readCrctEndianArray(io_data, RSP_PADDING_SIZE, l_idx, o_response.padding));
    FAPI_TRY(readCrctEndianArray(io_data, ARGUMENT_SIZE, l_idx, o_response.response_argument));

    o_response.response_id = l_response_id;
    o_response.response_flags = l_response_flags;
    o_response.request_identifier = l_request_identifier;
    o_response.response_length = l_response_length;
    o_response.response_crc = l_response_crc;
    o_response.host_work_area = l_host_work_area;

    o_crc = crc32_gen(io_data, l_idx);

    FAPI_TRY(readCrctEndian(io_data, l_idx, l_response_header_crc));
    o_response.response_header_crc = l_response_header_crc;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Converts a little endian data array to a host_fw_response_struct
/// @param[in] i_target OCMB target on which to operate
/// @param[in,out] io_data little endian data to process
/// @param[out] o_response response structure
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
/// @note helper function to allow for checking FFDC
///
fapi2::ReturnCode host_fw_response_struct_from_little_endian(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    std::vector<uint8_t>& io_data,
    host_fw_response_struct& o_response)
{
    uint32_t l_crc = 0;
    fapi2::current_err = host_fw_response_struct_from_little_endian(io_data, l_crc, o_response);
    // Re-assert here so we capture the OCMB target (lower level code uses FAPI_SYSTEM)
    FAPI_ASSERT(fapi2::current_err == fapi2::FAPI2_RC_SUCCESS,
                fapi2::EXP_INBAND_LE_DATA_RANGE()
                .set_TARGET(i_target)
                .set_FUNCTION(mss::exp::READ_HOST_FW_RESPONSE_STRUCT)
                .set_DATA_SIZE(io_data.size())
                .set_MAX_INDEX(sizeof(host_fw_response_struct)),
                "%s Failed to convert from data to host_fw_response_struct data size %u expected size %u",
                mss::c_str(i_target), io_data.size(), sizeof(host_fw_response_struct));

    FAPI_ASSERT(l_crc == o_response.response_header_crc,
                fapi2::EXP_INBAND_RSP_CRC_ERR()
                .set_COMPUTED(l_crc)
                .set_RECEIVED(o_response.response_header_crc)
                .set_OCMB_TARGET(i_target),
                "%s Response CRC failed to validate computed: 0x%08x got: 0x%08x",
                mss::c_str(i_target), l_crc, o_response.response_header_crc);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Polls for response ready door bell bit
/// @param[in] i_target the OCMB target on which to operate
/// @param[in] i_cmd the command ID for which we are waiting for a response
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode poll_for_response_ready(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint8_t i_cmd)
{
    // NUM_LOOPS is based on EXP_FW_DDR_PHY_INIT command, which completes in ~370ms in HW.
    // We initially delay 8ms, so we should only need to poll for ~360ms here.
    // Update: for MDS parts training takes on the order of 23 seconds with UART attached.
    // We're waiting 20ms between polls so we poll 1300 times.
    // Max timeout is (1300 x 20ms) = 26 seconds
    constexpr uint64_t NUM_LOOPS = 1300;

    // So, why aren't we using the memory team's polling API?
    // This is a base function that will be utilized by the platform code
    // As such, we don't want to pull in more libraries than we need to: it would cause extra dependencies
    // So, we're decomposing the polling library below
    bool l_doorbell_response = false;
    uint64_t l_loop = 0;
    fapi2::buffer<uint64_t> l_data;

    // Loop until we max our our loop count or get a doorbell response
    for (; l_loop < NUM_LOOPS && !l_doorbell_response; ++l_loop)
    {
        FAPI_TRY(fapi2::getScom(i_target, EXPLR_MIPS_TO_OCMB_INTERRUPT_REGISTER1, l_data));
        l_doorbell_response = l_data.getBit<EXPLR_MIPS_TO_OCMB_INTERRUPT_REGISTER1_DOORBELL>();
        FAPI_TRY(fapi2::delay(20 * DELAY_1MS, 200));
    }

    FAPI_DBG("%s stopped on loop%u/%u data:0x%016lx %u",
             mss::c_str(i_target), l_loop, NUM_LOOPS, l_data, l_doorbell_response);

    // Error check - doorbell response should be true
    FAPI_ASSERT(l_doorbell_response,
                fapi2::EXP_INBAND_RSP_NO_DOORBELL()
                .set_OCMB_TARGET(i_target)
                .set_DATA(l_data)
                .set_CMD(i_cmd)
                .set_NUM_LOOPS(l_loop),
                "%s doorbell timed out after %u loops: data 0x%016lx",
                mss::c_str(i_target), l_loop, l_data);

    // Ding-dong! the doorbell is rung and the response is ready
    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Clears outbound (response ready) door bell bit
/// @param[in] i_target the OCMB target on which to operate
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode clear_outbound_doorbell(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::buffer<uint64_t> l_data;

    // Doorbell is cleared by writing a '1' to the doorbell bit
    l_data.setBit<EXPLR_MIPS_TO_OCMB_INTERRUPT_REGISTER1_DOORBELL>();

    FAPI_DBG("%s Clearing outbound doorbell...", mss::c_str(i_target));
    FAPI_TRY(fapi2::putScom(i_target, EXPLR_MIPS_TO_OCMB_INTERRUPT_REGISTER1, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reads a response from the response buffer
///
/// @param[in] i_target     The Explorer chip to read data from
/// @param[in] i_cmd        The original command
/// @param[out] o_rsp       The response data read from the buffer
/// @param[out] o_data      Raw (little-endian) response data buffer portion
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode getRSP(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint8_t i_cmd,
    host_fw_response_struct& o_rsp,
    std::vector<uint8_t>& o_data)
{
    std::vector<uint8_t> l_data(static_cast<int>(sizeof(o_rsp)));

    // Polls for the response to be ready first
    FAPI_TRY(poll_for_response_ready(i_target, i_cmd));

    FAPI_DBG("Reading the response buffer...");
    FAPI_TRY(fapi2::getMMIO(i_target, EXPLR_IB_RSP_ADDR, BUFFER_TRANSACTION_SIZE, l_data));
    FAPI_TRY(host_fw_response_struct_from_little_endian(i_target, l_data, o_rsp));

    FAPI_DBG("Checking if we have response data...");

    // If response data in buffer portion, return that too
    if (o_rsp.response_length > 0)
    {
        // make sure expected size is a multiple of 8
        const uint32_t l_padding = ((o_rsp.response_length % 8) > 0) ? (8 - (o_rsp.response_length % 8)) : 0;
        o_data.resize(o_rsp.response_length + l_padding);
        FAPI_DBG("Reading response data...");

        FAPI_TRY(fapi2::getMMIO(i_target, EXPLR_IB_DATA_ADDR, BUFFER_TRANSACTION_SIZE, o_data));
        FAPI_TRY(correctMMIOEndianForStruct(o_data));
        FAPI_TRY(correctMMIOword_order(o_data));
    }
    else
    {
        FAPI_DBG("No response data returned...");
        // make sure no buffer data is returned
        o_data.clear();
    }

    FAPI_TRY(clear_outbound_doorbell(i_target));

fapi_try_exit:
    FAPI_DBG("%s Exiting with return code : 0x%08X...", mss::c_str(i_target), (uint64_t)fapi2::current_err);
    return fapi2::current_err;
}

///
/// @brief Reads a response from the response buffer and checks request_id
///
/// @param[in] i_target     The Explorer chip to read data from
/// @param[in] i_cmd        The original command
/// @param[out] o_rsp       The response data read from the buffer
/// @param[out] o_data      Raw (little-endian) response data buffer portion
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode getRSP(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const host_fw_command_struct& i_cmd,
    host_fw_response_struct& o_rsp,
    std::vector<uint8_t>& o_data)
{
    FAPI_TRY(getRSP(i_target, i_cmd.cmd_id, o_rsp, o_data));
    FAPI_TRY(check::request_id(i_target, o_rsp, i_cmd));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Converts a little endian data array to a sensor_cache_struct
/// @param[in,out] io_data little endian data to process
/// @param[out] o_data sensor cache structure
/// @return true if success false if failure
/// @note helper function - returning a bool and will have true FFDC in a separate function
///
fapi2::ReturnCode sensor_cache_struct_from_little_endian(
    std::vector<uint8_t>& io_data,
    sensor_cache_struct& o_data)
{
    // Local variables to avoid error in passing packed struct fields by reference
    uint32_t l_idx = 0;
    uint16_t l_status = 0;
    uint16_t l_ocmb_dts = 0;
    uint16_t l_mem_dts0 = 0;
    uint16_t l_mem_dts1 = 0;
    uint32_t l_mba_reads = 0;
    uint32_t l_mba_writes = 0;
    uint32_t l_mba_activations = 0;
    uint32_t l_mba_powerups = 0;
    uint8_t l_self_timed_refresh = 0;
    uint32_t l_frame_count = 0;
    uint32_t l_mba_arrival_histo_base = 0;
    uint32_t l_mba_arrival_histo_low = 0;
    uint32_t l_mba_arrival_histo_med = 0;
    uint32_t l_mba_arrival_histo_high = 0;
    uint8_t l_initial_packet1 = 0;

    FAPI_TRY(correctMMIOEndianForStruct(io_data));
    FAPI_TRY(correctMMIOword_order(io_data));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_status));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_ocmb_dts));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_mem_dts0));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_mem_dts1));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_mba_reads));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_mba_writes));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_mba_activations));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_mba_powerups));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_self_timed_refresh));
    FAPI_TRY(readCrctEndianArray(io_data, SENSOR_CACHE_PADDING_SIZE_0, l_idx, o_data.reserved0));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_frame_count));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_mba_arrival_histo_base));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_mba_arrival_histo_low));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_mba_arrival_histo_med));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_mba_arrival_histo_high));
    FAPI_TRY(readCrctEndian(io_data, l_idx, l_initial_packet1));

    o_data.frame_count = l_frame_count;
    o_data.mba_arrival_histo_base = l_mba_arrival_histo_base;
    o_data.mba_arrival_histo_low = l_mba_arrival_histo_low;
    o_data.mba_arrival_histo_med = l_mba_arrival_histo_med;
    o_data.mba_arrival_histo_high = l_mba_arrival_histo_high;
    o_data.initial_packet1 = l_initial_packet1;
    o_data.status = l_status;
    o_data.ocmb_dts = l_ocmb_dts;
    o_data.mem_dts0 = l_mem_dts0;
    o_data.mem_dts1 = l_mem_dts1;
    o_data.mba_reads = l_mba_reads;
    o_data.mba_writes = l_mba_writes;
    o_data.mba_activations = l_mba_activations;
    o_data.mba_powerups = l_mba_powerups;
    o_data.self_timed_refresh = l_self_timed_refresh;

    FAPI_TRY(readCrctEndianArray(io_data, SENSOR_CACHE_PADDING_SIZE_1, l_idx, o_data.reserved1));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Converts a little endian data array to a sensor_cache_struct
/// @param[in] i_target OCMB target on which to operate
/// @param[in,out] io_data little endian data to process
/// @param[out] o_data sensor cache structure
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
/// @note helper function to allow for checking FFDC
///
fapi2::ReturnCode sensor_cache_struct_from_little_endian(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    std::vector<uint8_t>& io_data,
    sensor_cache_struct& o_data)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    FAPI_TRY(sensor_cache_struct_from_little_endian(io_data, o_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reads the complete 64 byte sensor cache on the selected Explorer
///
/// @param[in] i_target     The Explorer chip to read data from
/// @param[out] o_data      The data read from the buffer
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode getSensorCache(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    sensor_cache_struct& o_data)
{
    std::vector<uint8_t> l_data(static_cast<int>(sizeof(o_data)));

    // The sensor cache is accessed exclusively via 2 32-byte MMIO reads
    FAPI_TRY(fapi2::getMMIO(i_target, EXPLR_IB_SENSOR_CACHE_ADDR, 32, l_data));

    FAPI_TRY(sensor_cache_struct_from_little_endian(i_target, l_data, o_data));

fapi_try_exit:
    FAPI_DBG("%s Exiting with return code : 0x%08X...", mss::c_str(i_target), (uint64_t)fapi2::current_err);
    return fapi2::current_err;
}

///
/// @brief UT helper for correctMMIOEndianForStruct
///
/// @param[in] i_endian_ctrl value of ATTR_MSS_OCMB_EXP_STRUCT_MMIO_ENDIAN_CTRL
/// @param[in,out] io_data value to swizzle
///
void correctMMIOEndianForStruct_helper(fapi2::ATTR_MSS_OCMB_EXP_STRUCT_MMIO_ENDIAN_CTRL_Type i_endian_ctrl,
                                       std::vector<uint8_t>& io_data)
{
    size_t l_loops = 0;

    if (i_endian_ctrl == fapi2::ENUM_ATTR_MSS_OCMB_EXP_STRUCT_MMIO_ENDIAN_CTRL_SWAP)
    {
        l_loops = io_data.size() / BUFFER_TRANSACTION_SIZE;

        for (size_t l_idx = 0; l_idx < l_loops; l_idx++)
        {
            for (int l_bidx = BUFFER_TRANSACTION_SIZE - 1; l_bidx >= 0; l_bidx--)
            {
                io_data.push_back(io_data.at(l_bidx));
            }

            io_data.erase(io_data.begin(), io_data.begin() + BUFFER_TRANSACTION_SIZE);
        }
    }
}

///
/// @brief We will use 4 or 8 byte reads via fapi2::put/getMMIO for buffer
/// data structures.  The byte order of the 4 or 8 byte reads should be little
/// endian.  In order to represent the data structure in its proper layout
/// the endianness of each 4 or 8 byte read must be corrected.
/// @param[in,out] io_data   Either data structure in proper byte order that we
///      want to swizzle prior to writing to the buffer, or the data returned
///      from reading the buffer that we want to unsizzle.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode correctMMIOEndianForStruct(std::vector<uint8_t>& io_data)
{
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_MSS_OCMB_EXP_STRUCT_MMIO_ENDIAN_CTRL_Type l_endian_ctrl;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_EXP_STRUCT_MMIO_ENDIAN_CTRL,
                           FAPI_SYSTEM, l_endian_ctrl));
    correctMMIOEndianForStruct_helper(l_endian_ctrl, io_data);

fapi_try_exit:
    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t)fapi2::current_err);
    return fapi2::current_err;
}

///
/// @brief UT helper for correctMMIOword_order
/// @param[in] i_word_swap value of ATTR_MSS_OCMB_EXP_STRUCT_MMIO_WORD_SWAP
/// @param[in,out] io_data value to swizzle
///
void correctMMIOword_order_helper(fapi2::ATTR_MSS_OCMB_EXP_STRUCT_MMIO_WORD_SWAP_Type i_word_swap,
                                  std::vector<uint8_t>& io_data)
{
    if (i_word_swap == fapi2::ENUM_ATTR_MSS_OCMB_EXP_STRUCT_MMIO_WORD_SWAP_SWAP)
    {
        for (size_t l_idx = 0; l_idx < io_data.size(); l_idx += BUFFER_TRANSACTION_SIZE)
        {
            for (size_t l_bidx = l_idx; l_bidx < l_idx + BUFFER_TRANSACTION_SIZE / 2; l_bidx++)
            {
                uint8_t l_temp_first_word = io_data.at(l_bidx);
                uint8_t l_temp_second_word = io_data.at(l_bidx + BUFFER_TRANSACTION_SIZE / 2);
                io_data[l_bidx] = l_temp_second_word;
                io_data[l_bidx + BUFFER_TRANSACTION_SIZE / 2] = l_temp_first_word;
            }
        }
    }
}

///
/// @brief Because of how the AXI bridge in Explorer breaks up the transaction,
///      we might need to swap 32-bit word order
/// @param[in,out] io_data   Either data structure in proper byte order that we
///      want to swizzle prior to writing to the buffer, or the data returned
///      from reading the buffer that we want to unsizzle.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode correctMMIOword_order(std::vector<uint8_t>& io_data)
{
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_MSS_OCMB_EXP_STRUCT_MMIO_WORD_SWAP_Type l_word_swap;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_EXP_STRUCT_MMIO_WORD_SWAP,
                           FAPI_SYSTEM, l_word_swap));
    correctMMIOword_order_helper(l_word_swap, io_data);

fapi_try_exit:
    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t)fapi2::current_err);
    return fapi2::current_err;
}

///
/// @brief Forces native data into the correct endianness necessary for Explorer
/// buffer data structures.
/// @tparam T the data type to process
/// @param[in] i_input inputted data to process
/// @param[in,out] io_data vector to append data to
///
template <typename T>
fapi2::ReturnCode forceCrctEndian(const T& i_input, std::vector<uint8_t>& io_data)
{
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_MSS_OCMB_EXP_STRUCT_ENDIAN_Type l_struct_endian;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_EXP_STRUCT_ENDIAN,
                           FAPI_SYSTEM, l_struct_endian));

    if (l_struct_endian == fapi2::ENUM_ATTR_MSS_OCMB_EXP_STRUCT_ENDIAN_LITTLE_ENDIAN)
    {
        forceLE(i_input, io_data);
    }
    else
    {
        forceBE(i_input, io_data);
    }

fapi_try_exit:
    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t)fapi2::current_err);
    return fapi2::current_err;
}

///
/// @brief Forces native data into the correct endianness for an array buffer
/// data structures.
/// @tparam T the data type to process
/// @param[in] i_input inputted data to process
/// @param[in] i_size size of the array
/// @param[in,out] io_data vector to append data to
///
template <typename T>
fapi2::ReturnCode forceCrctEndianArray(const T* i_input, const uint64_t i_size, std::vector<uint8_t>& io_data)
{
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_MSS_OCMB_EXP_STRUCT_ENDIAN_Type l_struct_endian;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_EXP_STRUCT_ENDIAN,
                           FAPI_SYSTEM, l_struct_endian));

    if (l_struct_endian == fapi2::ENUM_ATTR_MSS_OCMB_EXP_STRUCT_ENDIAN_LITTLE_ENDIAN)
    {
        forceLEArray(i_input, i_size, io_data);
    }
    else
    {
        forceBEArray(i_input, i_size, io_data);
    }

fapi_try_exit:
    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t)fapi2::current_err);
    return fapi2::current_err;
}

///
/// @brief Converts endianness of data read from Explorer buffer data structures
//  into native order.
/// @tparam T the data type to output to
/// @param[in] i_input inputted data to process
/// @param[in,out] io_idx current index
/// @param[out] o_data data that has been converted into native endianness
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template <typename T>
fapi2::ReturnCode readCrctEndian(const std::vector<uint8_t>& i_input, uint32_t& io_idx, T& o_data)
{
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_MSS_OCMB_EXP_STRUCT_ENDIAN_Type l_struct_endian;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_EXP_STRUCT_ENDIAN,
                           FAPI_SYSTEM, l_struct_endian));

    if (l_struct_endian == fapi2::ENUM_ATTR_MSS_OCMB_EXP_STRUCT_ENDIAN_LITTLE_ENDIAN)
    {
        FAPI_ASSERT(readLE(i_input, io_idx, o_data),
                    fapi2::EXP_INBAND_LE_DATA_RANGE()
                    .set_TARGET(FAPI_SYSTEM)
                    .set_FUNCTION(mss::exp::READ_CRCT_ENDIAN)
                    .set_DATA_SIZE(i_input.size())
                    .set_MAX_INDEX(sizeof(o_data)),
                    "Failed to convert from LE data read, size %u expected size %u",
                    i_input.size(), sizeof(o_data));
    }
    else
    {
        FAPI_ASSERT(readBE(i_input, io_idx, o_data),
                    fapi2::EXP_INBAND_BE_DATA_RANGE()
                    .set_TARGET(FAPI_SYSTEM)
                    .set_FUNCTION(mss::exp::READ_CRCT_ENDIAN)
                    .set_DATA_SIZE(i_input.size())
                    .set_MAX_INDEX(sizeof(o_data)),
                    "Failed to convert from BE data read, size %u expected size %u",
                    i_input.size(), sizeof(o_data));
    }

fapi_try_exit:
    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t)fapi2::current_err);
    return fapi2::current_err;
}

template <typename T>
fapi2::ReturnCode readCrctEndianArray(const std::vector<uint8_t>& i_input, const uint32_t i_size, uint32_t& io_idx,
                                      T* o_data)
{
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_MSS_OCMB_EXP_STRUCT_ENDIAN_Type l_struct_endian;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_EXP_STRUCT_ENDIAN,
                           FAPI_SYSTEM, l_struct_endian));

    if (l_struct_endian == fapi2::ENUM_ATTR_MSS_OCMB_EXP_STRUCT_ENDIAN_LITTLE_ENDIAN)
    {
        FAPI_ASSERT(readLEArray(i_input, i_size, io_idx, o_data),
                    fapi2::EXP_INBAND_LE_DATA_RANGE()
                    .set_TARGET(FAPI_SYSTEM)
                    .set_FUNCTION(mss::exp::READ_CRCT_ENDIAN)
                    .set_DATA_SIZE(i_input.size())
                    .set_MAX_INDEX(sizeof(o_data)),
                    "Failed to convert from LE array data read, size %u expected size %u",
                    i_input.size(), sizeof(o_data));
    }
    else
    {
        FAPI_ASSERT(readBEArray(i_input, i_size, io_idx, o_data),
                    fapi2::EXP_INBAND_BE_DATA_RANGE()
                    .set_TARGET(FAPI_SYSTEM)
                    .set_FUNCTION(mss::exp::READ_CRCT_ENDIAN)
                    .set_DATA_SIZE(i_input.size())
                    .set_MAX_INDEX(sizeof(o_data)),
                    "Failed to convert from BE array data read, size %u expected size %u",
                    i_input.size(), sizeof(o_data));
    }

fapi_try_exit:
    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t)fapi2::current_err);
    return fapi2::current_err;
}

///
/// @brief Converts user_input_msdg to little endian and calculates the crc
/// @param[in] i_input user_input_msdg structure to convert
/// @param[in] i_is_new_fw_version denotes if newer than FW ver397559
/// @param[out] o_data vector of bytes for mmio
/// @param[out] o_crc the calculated crc of the data
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode user_input_msdg_to_little_endian(const user_input_msdg& i_input,
        const bool i_is_new_fw_version,
        std::vector<uint8_t>& o_data,
        uint32_t& o_crc)
{
    o_data.clear();

    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.version_number, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.DimmType, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.CsPresent, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.DramDataWidth, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.Height3DS, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.ActiveDBYTE, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.ActiveNibble, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.AddrMirror, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.ColumnAddrWidth, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.RowAddrWidth, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.SpdCLSupported, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.SpdtAAmin, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.Rank4Mode, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.EncodedQuadCs, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.DDPCompatible, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.TSV8HSupport, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.MRAMSupport, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.MDSSupport, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.NumPStates, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.Frequency, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.PhyOdtImpedance, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.PhyDrvImpedancePU, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.PhyDrvImpedancePD, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.PhySlewRate, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.ATxImpedance, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.ATxSlewRate, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.CKTxImpedance, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.CKTxSlewRate, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.AlertOdtImpedance, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.DramRttNomR0, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.DramRttNomR1, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.DramRttNomR2, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.DramRttNomR3, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.DramRttWrR0, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.DramRttWrR1, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.DramRttWrR2, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.DramRttWrR3, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.DramRttParkR0, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.DramRttParkR1, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.DramRttParkR2, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.DramRttParkR3, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.DramDic, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.DramWritePreamble, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.DramReadPreamble, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.PhyEqualization, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.InitVrefDQ, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.InitPhyVref, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.OdtWrMapCs, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.OdtRdMapCs, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.Geardown, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.CALatencyAdder, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.BistCALMode, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.BistCAParityLatency, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.RcdDic, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.RcdVoltageCtrl, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.RcdIBTCtrl, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.RcdDBDic, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.RcdSlewRate, MSDG_MAX_PSTATE, o_data));
    FAPI_TRY(forceCrctEndian(i_input.iv_user_msdg_upto_ver397559.DFIMRL_DDRCLK, o_data));

    for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
    {
        FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.ATxDly_A[l_pstate], DRAMINIT_NUM_ADDR_DELAYS,
                                      o_data));
    }

    for (uint8_t l_pstate = 0; l_pstate < MSDG_MAX_PSTATE; ++l_pstate)
    {
        FAPI_TRY(forceCrctEndianArray(i_input.iv_user_msdg_upto_ver397559.ATxDly_B[l_pstate], DRAMINIT_NUM_ADDR_DELAYS,
                                      o_data));
    }

    if(i_is_new_fw_version)
    {
        FAPI_TRY(forceCrctEndian(i_input.F1RC1x, o_data));
        FAPI_TRY(forceCrctEndian(i_input.F1RC2x, o_data));
        FAPI_TRY(forceCrctEndian(i_input.F1RC3x, o_data));
        FAPI_TRY(forceCrctEndian(i_input.F1RC4x, o_data));
        FAPI_TRY(forceCrctEndian(i_input.F1RC5x, o_data));
        FAPI_TRY(forceCrctEndian(i_input.F1RC6x, o_data));
        FAPI_TRY(forceCrctEndian(i_input.F1RC7x, o_data));
    }

    o_crc = crc32_gen(o_data);
    padCommData(o_data);
    FAPI_TRY(correctMMIOEndianForStruct(o_data));
    FAPI_TRY(correctMMIOword_order(o_data));

fapi_try_exit:
    FAPI_DBG("Exiting with return code : 0x%08X...",
             static_cast<uint64_t>(fapi2::current_err));
    return fapi2::current_err;
}

///
/// @brief Converts little endian data array to big endian data and saves into app_fw_ddr_calibration_data_struct
/// @param[in] i_target the controller
/// @param[in,out] io_data little endian data to process
/// @param[out] o_calib_params app_fw_ddr_calibration_data_struct structure
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
/// TODO:ZEN-MST909: Fix SPI flash reader once microchip re-adds support and do the following before saving the struct:
///                  1. Correct endianness of the data received
///                  2. Exit out if calculated crc not equal to received crc
///
fapi2::ReturnCode app_fw_ddr_calibration_data_struct_from_little_endian(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    std::vector<uint8_t>& io_data,
    app_fw_ddr_calibration_data_struct& o_calib_params)
{
    uint32_t l_idx = 0;
    uint32_t l_temp_var_for_conversion = 0;
    uint32_t l_crc = 0;

    FAPI_TRY(correctMMIOEndianForStruct(io_data));
    FAPI_TRY(correctMMIOword_order(io_data));

    FAPI_TRY(readCrctEndian(io_data, l_idx, l_temp_var_for_conversion));
    o_calib_params.header = l_temp_var_for_conversion;

    FAPI_TRY(readCrctEndianArray(io_data, (MSDG_MAX_PSTATE * MAX_NUM_RANKS * NUM_DQ), l_idx,
                                 &o_calib_params.timing_data.delay_data.TxDqDly[0][0][0]));

    FAPI_TRY(readCrctEndianArray(io_data, (MSDG_MAX_PSTATE * MAX_NUM_RANKS * NUM_BYTES), l_idx,
                                 &o_calib_params.timing_data.delay_data.TxDmDly[0][0][0]));

    FAPI_TRY(readCrctEndianArray(io_data, (MSDG_MAX_PSTATE * MAX_NUM_RANKS * NUM_BYTES), l_idx,
                                 &o_calib_params.timing_data.delay_data.TxDqsDly_u0[0][0][0]));

    FAPI_TRY(readCrctEndianArray(io_data, (MSDG_MAX_PSTATE * MAX_NUM_RANKS * NUM_BYTES), l_idx,
                                 &o_calib_params.timing_data.delay_data.TxDqsDly_u1[0][0][0]));

    FAPI_TRY(readCrctEndianArray(io_data, (MSDG_MAX_PSTATE * MAX_NUM_RANKS * NUM_BYTES), l_idx,
                                 &o_calib_params.timing_data.delay_data.RxClkDly_u0[0][0][0]));

    FAPI_TRY(readCrctEndianArray(io_data, (MSDG_MAX_PSTATE * MAX_NUM_RANKS * NUM_BYTES), l_idx,
                                 &o_calib_params.timing_data.delay_data.RxClkDly_u1[0][0][0]));

    FAPI_TRY(readCrctEndianArray(io_data, (MSDG_MAX_PSTATE * MAX_NUM_RANKS * NUM_BYTES), l_idx,
                                 &o_calib_params.timing_data.delay_data.RxEnDly_u0[0][0][0]));

    FAPI_TRY(readCrctEndianArray(io_data, (MSDG_MAX_PSTATE * MAX_NUM_RANKS * NUM_BYTES), l_idx,
                                 &o_calib_params.timing_data.delay_data.RxEnDly_u1[0][0][0]));

    FAPI_TRY(readCrctEndianArray(io_data, (MSDG_MAX_PSTATE * NUM_BYTES), l_idx,
                                 &o_calib_params.timing_data.delay_data.ATxDly_A[0][0]));

    FAPI_TRY(readCrctEndianArray(io_data, (MSDG_MAX_PSTATE * NUM_BYTES), l_idx,
                                 &o_calib_params.timing_data.delay_data.ATxDly_B[0][0]));

    FAPI_TRY(readCrctEndianArray(io_data, (MSDG_MAX_PSTATE * NUM_BYTES), l_idx,
                                 &o_calib_params.timing_data.delay_data.DFIMRL[0][0]));

    FAPI_TRY(readCrctEndianArray(io_data, (MAX_NUM_RANKS * NUM_DQ), l_idx,
                                 &o_calib_params.timing_data.delay_data.RxPBDly[0][0]));

    FAPI_TRY(readCrctEndianArray(io_data, NUM_BYTES, l_idx, &o_calib_params.timing_data.delay_data.StepSize[0]));
    FAPI_TRY(readCrctEndianArray(io_data, MSDG_MAX_PSTATE, l_idx, &o_calib_params.timing_data.delay_data.DFIMRL_ddrclk[0]));

    FAPI_TRY(readCrctEndian(io_data, l_idx, o_calib_params.timing_data.cdd_data.rr));
    FAPI_TRY(readCrctEndian(io_data, l_idx, o_calib_params.timing_data.cdd_data.ww));
    FAPI_TRY(readCrctEndian(io_data, l_idx, o_calib_params.timing_data.cdd_data.rw));
    FAPI_TRY(readCrctEndian(io_data, l_idx, o_calib_params.timing_data.cdd_data.wr));

    FAPI_TRY(readCrctEndianArray(io_data, NUM_DQ, l_idx, &o_calib_params.vref_data.vrefdqDeviceVoltageSetting.VrefDAC0[0]));
    FAPI_TRY(readCrctEndianArray(io_data, NUM_DQ, l_idx, &o_calib_params.vref_data.vrefdqDeviceVoltageSetting.VrefDAC1[0]));
    FAPI_TRY(readCrctEndianArray(io_data, MSDG_MAX_PSTATE, l_idx,
                                 &o_calib_params.vref_data.vrefdqDeviceVoltageSetting.VrefInGlobal[0]));

    FAPI_TRY(readCrctEndianArray(io_data, (MSDG_MAX_PSTATE * NUM_BYTES * NIBBLES_PER_BYTE), l_idx,
                                 &o_calib_params.vref_data.vrefdqDeviceVoltageSetting.DqDqsRcvCntrl[0][0][0]));

    FAPI_TRY(readCrctEndian(io_data, l_idx, l_temp_var_for_conversion));
    o_calib_params.vref_data.vrefdqDeviceVoltageSetting.PllTestMode = l_temp_var_for_conversion;

    FAPI_TRY(readCrctEndian(io_data, l_idx, l_temp_var_for_conversion));
    o_calib_params.vref_data.vrefdqDeviceVoltageSetting.PllCtrl2 = l_temp_var_for_conversion;

    FAPI_TRY(readCrctEndian(io_data, l_idx, l_temp_var_for_conversion));
    o_calib_params.vref_data.vrefdqDeviceVoltageSetting.PllCtrl3 = l_temp_var_for_conversion;

    FAPI_TRY(readCrctEndianArray(io_data, MSDG_MAX_PSTATE, l_idx,
                                 &o_calib_params.vref_data.vrefdqDeviceVoltageSetting.DllLockParam[0]));
    FAPI_TRY(readCrctEndianArray(io_data, MSDG_MAX_PSTATE, l_idx,
                                 &o_calib_params.vref_data.vrefdqDeviceVoltageSetting.DllGainCtl[0]));

    FAPI_TRY(readCrctEndianArray(io_data, (MSDG_MAX_PSTATE * MAX_NUM_RANKS * NUM_DRAM), l_idx,
                                 &o_calib_params.vref_data.vrefdqDramVoltageSetting.VrefDQ[0][0][0]));

    l_crc = crc32_gen(io_data, l_idx);

    FAPI_TRY(readCrctEndian(io_data, l_idx, l_temp_var_for_conversion));
    o_calib_params.crc = l_temp_var_for_conversion;

    FAPI_ASSERT(l_crc == o_calib_params.crc,
                fapi2::EXP_INBAND_RSP_CRC_ERR()
                .set_COMPUTED(l_crc)
                .set_RECEIVED(o_calib_params.crc)
                .set_OCMB_TARGET(i_target),
                "%s Response CRC failed to validate computed: 0x%08x got: 0x%08x",
                mss::c_str(i_target), l_crc, o_calib_params.crc);

fapi_try_exit:
    return fapi2::current_err;
}


namespace check
{

///
/// @brief Checks explorer request_id in fw_response_struct
/// @param[in] i_target OCMB target
/// @param[in] i_rsp response from command
/// @param[in] i_cmd original command
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode request_id(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                             const host_fw_response_struct& i_rsp,
                             const host_fw_command_struct& i_cmd)
{
    FAPI_ASSERT(i_rsp.request_identifier == i_cmd.request_identifier,
                fapi2::EXP_RESPONSE_WRONG_REQID().
                set_TARGET(i_target).
                set_CMD_ID(i_cmd.cmd_id).
                set_CMD_REQ_ID(i_cmd.request_identifier).
                set_RSP_ID(i_rsp.response_id).
                set_RSP_REQ_ID(i_rsp.request_identifier),
                "%s Received response with incorrect request id (0x%02x when expecting 0x%02x). "
                "Command ID was 0x%02x, and Response ID is 0x%02x",
                mss::c_str(i_target),
                i_rsp.request_identifier,
                i_cmd.request_identifier,
                i_cmd.cmd_id,
                i_rsp.response_id);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks explorer response argument for a successful command
/// @param[in] i_target OCMB target
/// @param[in] i_rsp response from command
/// @param[in] i_cmd original command
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode response(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                           const host_fw_response_struct& i_rsp,
                           const host_fw_command_struct& i_cmd)
{
    fapi2::buffer<uint32_t> l_error_code;

    l_error_code.insertFromRight<0, BITS_PER_BYTE>(i_rsp.response_argument[4]).
    insertFromRight<BITS_PER_BYTE, BITS_PER_BYTE>(i_rsp.response_argument[3]).
    insertFromRight<2 * BITS_PER_BYTE, BITS_PER_BYTE>(i_rsp.response_argument[2]).
    insertFromRight<3 * BITS_PER_BYTE, BITS_PER_BYTE>(i_rsp.response_argument[1]);

    // Check if cmd was successful
    FAPI_ASSERT(i_rsp.response_argument[0] == omi::response_arg::RESPONSE_SUCCESS &&
                i_rsp.request_identifier == i_cmd.request_identifier &&
                i_rsp.response_id == i_cmd.cmd_id,
                fapi2::MSS_EXP_RSP_ARG_FAILED().
                set_TARGET(i_target).
                set_CMD_ID(i_cmd.cmd_id).
                set_RSP_ID(i_rsp.response_id).
                set_EXTENDED_ERROR_CODE(l_error_code).
                set_ERROR_CODE(i_rsp.response_argument[5]).
                set_EXPECTED_REQID(i_cmd.request_identifier).
                set_ACTUAL_REQID(i_rsp.request_identifier).
                set_EXP_ACTIVE_LOG_SIZE(4096),
                "Failed Explorer command on %s, cmd_id=0x%X, rsp_id=0x%X, response_arg[0]=0x%X, extended_error_code=0x%08X error_code=0x%02X "
                "RSP RQ ID: %u CMD RQ ID: %u",
                mss::c_str(i_target), i_cmd.cmd_id, i_rsp.response_id, i_rsp.response_argument[0], l_error_code,
                i_rsp.response_argument[5],
                i_rsp.request_identifier, i_cmd.request_identifier);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace check

} // namespace ib

} // namespace exp

} // namespace mss
