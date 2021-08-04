/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/i2c/mds_i2c_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
/// @file mds_i2c_scom.C
/// @brief MDS I2C utility function implementation
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <i2c_access.H>
#include <lib/i2c/exp_i2c.H>
#include <lib/i2c/mds_i2c_scom.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/utils/endian_utils.H>
#include <lib/shared/exp_consts.H>

namespace mss
{
namespace mds
{
namespace i2c
{

///
/// @brief Setup the i2c write command data for the given MDS media controller
/// @param[in] i_target the MDS media controller target
/// @param[in] i_addr   The translated address
/// @param[in] i_data_buffer buffer of data we want to write to the register
/// @param[out] o_cmd_vector vector of bytes we want to write to the command data to
///
void setup_mds_write_command(const fapi2::Target<fapi2::TARGET_TYPE_MDS_CTLR>& i_target,
                             const uint32_t i_addr,
                             const fapi2::buffer<uint32_t>& i_data_buffer,
                             std::vector<uint8_t>& o_cmd_vector)
{
    // Clear command vector for stale data
    o_cmd_vector.clear();

    // Build the cmd vector for the write
    // TODO: Zenhub #1177 Check for variable data size if needed
    //       Currently removed due to conversation with lab
    o_cmd_vector.push_back(mss::mds::MDS_I2C_REG_WRITE);          // Byte 0 = 0xC6 (MDS_I2C_REG_WRITE)
    o_cmd_vector.push_back(mss::mds::MDS_WRITE_REG_DATA_SIZE);    // Byte 1 = 0x05 (MDS_WRITE_REG_DATA_SIZE)

    // Byte 2:5 = Address
    // Push back address input, in byte sized chunks
    o_cmd_vector.push_back( (i_addr >> 24) & 0xFF);
    o_cmd_vector.push_back( (i_addr >> 16) & 0xFF);
    o_cmd_vector.push_back( (i_addr >>  8) & 0xFF);
    o_cmd_vector.push_back( (i_addr >>  0) & 0xFF);

    // Byte 6 = Data (one byte of data due to MDS_WRITE_REG_DATA_SIZE being 5 (4 bytes address, 1 byte data)
    o_cmd_vector.push_back(i_data_buffer & 0xFF);
}

///
/// @brief Setup the i2c read command data for the given MDS media controller
/// @param[in] i_target the MDS media controller target
/// @param[in] i_addr   The translated address
/// @param[out] o_cmd_vector vector of bytes we want to write to the command data to
///
void setup_mds_read_command(const fapi2::Target<fapi2::TARGET_TYPE_MDS_CTLR>& i_target,
                            const uint32_t i_addr,
                            std::vector<uint8_t>& o_cmd_vector)
{
    // Clear command vector for stale data
    o_cmd_vector.clear();

    // Build the cmd vector for the write
    // TODO: Zenhub #1177 Check for variable data size if needed
    //       Currently removed due to conversation with lab
    o_cmd_vector.push_back(mss::mds::MDS_I2C_REG_READ);         // Byte 0 = 0xC2 (MDS_I2C_REG_READ)
    o_cmd_vector.push_back(mss::mds::MDS_READ_REG_DATA_SIZE);   // Byte 1 = 0x04 (MDS_READ_REG_DATA_SIZE)

    // Byte 2:5 = Address
    // Push back address input, in byte sized chunks
    o_cmd_vector.push_back( (i_addr >> 24) & 0xFF);
    o_cmd_vector.push_back( (i_addr >> 16) & 0xFF);
    o_cmd_vector.push_back( (i_addr >>  8) & 0xFF);
    o_cmd_vector.push_back( (i_addr >>  0) & 0xFF);
}

///
/// @brief Perform a register write operation on the given MDS media controller
/// @param[in] i_target the MDS media controller target
/// @param[in] i_addr   The translated address
/// @param[in] i_data_buffer buffer of data we want to write to the register
/// @return FAPI2_RC_SUCCESS iff okay
/// @note Only one byte register writes are supported currently. i_data_buffer will be truncated to its LSB
///
fapi2::ReturnCode mds_fw_reg_write(const fapi2::Target<fapi2::TARGET_TYPE_MDS_CTLR>& i_target,
                                   const uint32_t i_addr,
                                   const fapi2::buffer<uint32_t>& i_data_buffer)
{
    // create byte vector that will hold command bytes in sequence that will do the scom
    std::vector<uint8_t> l_cmd_vector;

    // Setup the command bytes for the write command
    setup_mds_write_command(i_target, i_addr, i_data_buffer, l_cmd_vector);

    FAPI_TRY(fapi2::putI2c(i_target, l_cmd_vector),
             "I2C MDS_FW_REG_WRITE op failed to write to 0x%.8X on MDS Media Controller w/ fapiPos = 0x%.8X",
             i_addr, mss::fapi_pos(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a register write operation on the given MDS media controller
/// @param[in] i_target the MDS media controller target
/// @param[in] i_addr   The translated address
/// @param[out] o_data_buffer buffer of data we will write the contents of the register to
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode mds_fw_reg_read(const fapi2::Target<fapi2::TARGET_TYPE_MDS_CTLR>& i_target,
                                  const uint32_t i_addr,
                                  fapi2::buffer<uint32_t>& o_data_buffer)
{
    // create byte vector that will hold command bytes in sequence that will do the scom
    std::vector<uint8_t> l_cmd_vector;
    std::vector<uint8_t> l_byte_vector;

    // Setup the command bytes for the read command
    setup_mds_read_command(i_target, i_addr, l_cmd_vector);

    // Clear out the tmp_vector because we will re-use as the read buffer
    l_byte_vector.clear();

    // Use fapi2 getI2c interface to execute command
    FAPI_TRY(fapi2::getI2c(i_target, mss::mds::MDS_READ_REG_DATA_SIZE,  l_cmd_vector, l_byte_vector),
             "getI2c returned error for MDS_FW_REG_READ operation to 0x%.8X on MDS Media Controller w/ fapiPos = 0x%.8X",
             i_addr, mss::fapi_pos(i_target));

    // Check status of operation
    FAPI_TRY(check::mds_i2c_response(i_target, l_byte_vector, l_cmd_vector));

    // Build uint32_t from bytes 1-4 of the returned data. Bytes are
    // returned in BE so no translation neccesary. Faster to just access
    // the 4 bytes and shift than to perform vector operations to pop off front
    // entry and convert vector to uint32.
    o_data_buffer = ( l_byte_vector[1] << 24 |
                      l_byte_vector[2] << 16 |
                      l_byte_vector[3] << 8 |
                      l_byte_vector[4]);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a put scom operation over i2c to MDS Media Controller
///
/// @param[in] i_target  the MDS Media Controller target
/// @param[in] i_addr    32 bit MDS scom address we want to write on the MDS Media Controller
/// @param[in] i_data_buffer  Contains data which will be written to i_addr on i_target
///
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode i2c_put_scom( const fapi2::Target<fapi2::TARGET_TYPE_MDS_CTLR>& i_target,
                                const uint32_t i_addr,
                                const fapi2::buffer<uint32_t>& i_data_buffer)
{
    // Perform the write operation
    // NOTE: The addition of UNCACHED_OFFSET to IBM/Microchip I2C has been removed
    FAPI_TRY(mds_fw_reg_write(i_target, i_addr, i_data_buffer),
             "Failed mds i2c scom register write to scom addr 0x%lx on MDS Media Controller w/ fapi_pos = %d",
             i_addr, mss::fapi_pos(i_target));

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Perform a get scom operation over i2c to MDS Media Controller
///
/// @param[in]  i_target  the MDS Media Controller target
/// @param[in]  i_addr    32 bit Microchip scom address we want to read from on the MDS Media Controller
/// @param[out] o_data_buffer  Buffer where data found at i_addr will be written to
///
/// @return FAPI2_RC_SUCCESS iff okay
///
/// @note this is the Microchip scom version the overloaded function i2c_get_scom for mds
///       Microchip i2c scoms to the explorer chips are 32 bits of data
fapi2:: ReturnCode i2c_get_scom(const fapi2::Target<fapi2::TARGET_TYPE_MDS_CTLR>& i_target,
                                const uint32_t i_addr,
                                fapi2::buffer<uint32_t>& o_data_buffer)
{
    // Perform the read operation
    // NOTE: The addition of UNCACHED_OFFSET to IBM/Microchip I2C has been removed
    FAPI_TRY(mds_fw_reg_read(i_target, i_addr, o_data_buffer),
             "Failed mds i2c scom register read from microchip scom addr 0x%.8X on MDS Media Controller w/ fapiPos = 0x%.8X",
             i_addr, mss::fapi_pos(i_target));


fapi_try_exit:
    return fapi2::current_err;
}

namespace check
{

///
/// @brief Check MDS I2C status for errors
/// @param[in] i_target the MDS media controller target
/// @param[in] i_rsp_data returned data from scom with status code to check
/// @param[in] i_cmd_data the command in byte vector format
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode mds_i2c_response( const fapi2::Target<fapi2::TARGET_TYPE_MDS_CTLR>& i_target,
                                    const std::vector<uint8_t>& i_rsp_data,
                                    const std::vector<uint8_t>& i_cmd_data )
{
    uint8_t l_status_code = 0;
    // Extract command data for traces
    uint64_t l_rsp_data = mss::exp::i2c::convert_to_long(i_rsp_data);
    uint64_t l_cmd_data = mss::exp::i2c::convert_to_long(i_cmd_data);

    // Check size of returned data
    FAPI_ASSERT( (i_rsp_data.size() == mss::mds::MDS_READ_RSP_SIZE),
                 fapi2::MSS_MDS_I2C_WRONG_RSP_SIZE().
                 set_MDS_MDIA_CTL_TARGET(i_target).
                 set_RSP_SIZE(i_rsp_data.size()).
                 set_COMMAND(l_cmd_data).
                 set_RESPONSE(l_rsp_data),
                 "Failing response size %d expected %d for MDS I2C command for contoller %s",
                 i_rsp_data.size(), mss::mds::MDS_READ_RSP_SIZE,  mss::c_str(i_target));

    // Extract status code from data
    l_status_code = i_rsp_data[1];

    // Check that MDS gave a successful return code
    // TODO: Zenhub #1177 Confirm the correct response to fails
    FAPI_ASSERT( (l_status_code == mss::mds::i2c_handling::MDS_I2C_SUCCESS),
                 fapi2::MSS_MDS_I2C_CMD_FAIL().
                 set_MDS_MDIA_CTL_TARGET(i_target).
                 set_STATUS(l_status_code).
                 set_COMMAND(l_cmd_data).
                 set_RESPONSE(l_rsp_data),
                 "Failing RC %d for MDS I2C command for contoller %s",
                 l_status_code, mss::c_str(i_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace check
} // namespace i2c
} // namespace mds
} // namespace mss
