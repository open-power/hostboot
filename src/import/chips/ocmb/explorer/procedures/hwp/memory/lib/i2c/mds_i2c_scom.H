/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/i2c/mds_i2c_scom.H $ */
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
/// @file mds_i2c_scom.H
/// @brief MDS I2C utility function implementation
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP
// EKB-Mirror-To: hostboot

#ifndef _MDS_I2C_SCOM_H_
#define _MDS_I2C_SCOM_H_

#include <fapi2.H>

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
                             std::vector<uint8_t>& o_cmd_vector);

///
/// @brief Setup the i2c read command data for the given MDS media controller
/// @param[in] i_target the MDS media controller target
/// @param[in] i_addr   The translated address
/// @param[out] o_cmd_vector vector of bytes we want to write to the command data to
///
void setup_mds_read_command(const fapi2::Target<fapi2::TARGET_TYPE_MDS_CTLR>& i_target,
                            const uint32_t i_addr,
                            std::vector<uint8_t>& o_cmd_vector);

///
/// @brief Perform a register write operation on the given MDS media controller
/// @param[in] i_target the MDS media controller target
/// @param[in] i_addr   The translated address
/// @param[in] i_data_buffer buffer of data we want to write to the register
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode mds_fw_reg_write(const fapi2::Target<fapi2::TARGET_TYPE_MDS_CTLR>& i_target,
                                   const uint32_t i_addr,
                                   const fapi2::buffer<uint32_t>& i_data_buffer);

///
/// @brief Perform a register write operation on the given MDS media controller
/// @param[in] i_target the MDS media controller target
/// @param[in] i_addr   The translated address
/// @param[out] o_data_buffer buffer of data we will write the contents of the register to
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode mds_fw_reg_read(const fapi2::Target<fapi2::TARGET_TYPE_MDS_CTLR>& i_target,
                                  const uint32_t i_addr,
                                  fapi2::buffer<uint32_t>& o_data_buffer);

///
/// @brief Perform a put scom operation over i2c to MDS Media Controller
///
/// @param[in] i_target  the MDS Media Controller target
/// @param[in] i_addr    32 bit Microchip scom address we want to write on the MDS Media Controller
/// @param[in] i_data_buffer  Contains data which will be written to i_addr on i_target
///
/// @return FAPI2_RC_SUCCESS iff okay
///
/// @note this is the Microchip scom version the overloaded function i2c_put_scom for mds
///       Microchip i2c scoms to the explorer chips are 32 bits of data
fapi2::ReturnCode i2c_put_scom( const fapi2::Target<fapi2::TARGET_TYPE_MDS_CTLR>& i_target,
                                const uint32_t i_addr,
                                const fapi2::buffer<uint32_t>& i_data_buffer);

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
fapi2::ReturnCode i2c_get_scom(const fapi2::Target<fapi2::TARGET_TYPE_MDS_CTLR>& i_target,
                               const uint32_t i_addr,
                               fapi2::buffer<uint32_t>& o_data_buffer);

namespace check
{

///
/// @brief Check MDS I2C status for errors
/// @param[in] i_target the MDS media controller target
/// @param[in] i_cmd_data the command in byte vector format
/// @param[in] i_rsp_data data to check for status
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode mds_i2c_response( const fapi2::Target<fapi2::TARGET_TYPE_MDS_CTLR>& i_target,
                                    const std::vector<uint8_t>& i_rsp_data,
                                    const std::vector<uint8_t>& i_cmd_data );

} // namespace check
} // namespace i2c
} // namespace mds
} // namespace mss

#endif // _MDS_I2C_SCOM_H
