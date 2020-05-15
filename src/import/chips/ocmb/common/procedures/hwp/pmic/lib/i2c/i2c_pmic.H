/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/i2c/i2c_pmic.H $ */
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
/// @file pmic_i2c.H
/// @brief PMIC I2C utility function declarations
///
// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP HWP Backup: Andre A. Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_I2C_PMIC_H_
#define _MSS_I2C_PMIC_H_

#include <fapi2.H>
#include <i2c_access.H>
#include <lib/utils/pmic_consts.H>
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/utils/index.H>
#include <generic/memory/lib/utils/c_str.H>

namespace mss
{
namespace pmic
{
namespace i2c
{

///
/// @brief Add provided opcode if the Target is an ADC
///
/// @param[in] i_target GENERICI2CSLAVE target
/// @param[in] i_opcode opcode to add
/// @param[in,out] io_command command vector
///
inline void add_adc_opcode(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_target,
                           const mss::adc::i2c::opcode i_opcode,
                           std::vector<uint8_t>& io_command)
{
    // ADC's are index 0,1; GPIO0 is index 2
    if (mss::index(i_target) <= mss::generic_i2c_slave::ADC2)
    {
        // ADC devices need an extra opcode frame
        io_command.push_back(i_opcode);
    }
}

///
/// @brief Set up i2c command buffer for the given target
/// @param[in] i_target the PMIC target
/// @param[in] i_addr address to read
/// @param[in] i_data_buffer data buffer
/// @param[in,out] io_command command buffer
/// @return FAPI2_RC_SUCCESS iff okay
///
template<fapi2::TargetType T>
inline void reg_write_helper(const fapi2::Target<T>& i_target,
                             const uint8_t i_addr,
                             const fapi2::buffer<uint8_t> i_data_buffer,
                             std::vector<uint8_t>& io_command);

///
/// @brief Set up i2c command buffer for the given target
/// @param[in] i_target the PMIC target
/// @param[in] i_addr address to read
/// @param[in] i_data_buffer data buffer
/// @param[in,out] io_command command buffer
/// @return FAPI2_RC_SUCCESS iff okay
///
template<>
inline void reg_write_helper(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_target,
                             const uint8_t i_addr,
                             const fapi2::buffer<uint8_t> i_data_buffer,
                             std::vector<uint8_t>& io_command)
{
    io_command.push_back(i_addr);
    io_command.push_back(uint8_t(i_data_buffer));
}

///
/// @brief Set up i2c command buffer for the given target
/// @param[in] i_target the GENERICI2CSLAVE target
/// @param[in] i_addr address to read
/// @param[in] i_data_buffer data buffer
/// @param[in,out] io_command command buffer
/// @return FAPI2_RC_SUCCESS iff okay
///
template<>
inline void reg_write_helper(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_target,
                             const uint8_t i_addr,
                             const fapi2::buffer<uint8_t> i_data_buffer,
                             std::vector<uint8_t>& io_command)
{
    add_adc_opcode(i_target, mss::adc::i2c::opcode::WRITE, io_command);
    io_command.push_back(i_addr);
    io_command.push_back(uint8_t(i_data_buffer));
}

///
/// @brief Perform a register write operation on the given I2C device
/// @tparam T target type
/// @param[in] i_target the I2C device target
/// @param[in] i_addr address to write to
/// @param[in] i_data_buffer buffer of data to write to the register
/// @return FAPI2_RC_SUCCESS iff okay
///
template<fapi2::TargetType T>
inline fapi2::ReturnCode reg_write(const fapi2::Target<T>& i_target,
                                   const uint8_t i_addr,
                                   const fapi2::buffer<uint8_t>& i_data_buffer)
{
    std::vector<uint8_t> l_command;
    reg_write_helper(i_target, i_addr, i_data_buffer, l_command);

    // Use fapi2 putI2c interface to execute command
    FAPI_TRY(fapi2::putI2c(i_target, l_command),
             "putI2C returned error for WRITE operation to 0x%02X on %s",
             i_addr, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a register read operation on the given target
/// @tparam T target type (PMIC, GENERICI2CSLAVE, etc.)
/// @param[in] i_target the target
/// @param[in] i_addr address to read
/// @param[in,out] io_command command buffer
/// @return FAPI2_RC_SUCCESS iff okay
///
template<fapi2::TargetType T>
inline void reg_read_helper(const fapi2::Target<T>& i_target,
                            const uint8_t i_addr,
                            std::vector<uint8_t>& io_command);

///
/// @brief Perform a register read operation on the given target
/// @param[in] i_target the PMIC device target
/// @param[in] i_addr address to read
/// @param[in,out] io_command command buffer
/// @return FAPI2_RC_SUCCESS iff okay
///
template<>
inline void reg_read_helper(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_target,
                            const uint8_t i_addr,
                            std::vector<uint8_t>& io_command)
{
    io_command.push_back(i_addr);
}

///
/// @brief Perform a register read operation on the given target
/// @param[in] i_target the GENERICI2CSLAVE target
/// @param[in] i_addr address to read
/// @param[in,out] io_command command buffer
/// @return FAPI2_RC_SUCCESS iff okay
///
template<>
inline void reg_read_helper(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_target,
                            const uint8_t i_addr,
                            std::vector<uint8_t>& io_command)
{
    add_adc_opcode(i_target, mss::adc::i2c::opcode::READ, io_command);
    io_command.push_back(i_addr);
}

///
/// @brief Perform a register read operation on the given PMIC chip
/// @tparam T target type
/// @param[in] i_target the PMIC/I2C device target
/// @param[in] i_addr address to read
/// @param[out] o_data_buffer buffer of data we will write the contents of the register to
/// @return FAPI2_RC_SUCCESS iff okay
///
template <fapi2::TargetType T>
inline fapi2::ReturnCode reg_read(const fapi2::Target<T>& i_target,
                                  const uint8_t i_addr,
                                  fapi2::buffer<uint8_t>& o_data_buffer)
{
    std::vector<uint8_t> l_data;
    std::vector<uint8_t> l_command;

    reg_read_helper(i_target, i_addr, l_command);

    FAPI_TRY(fapi2::getI2c(i_target, mss::pmic::i2c::sizes::DATA_LENGTH, l_command, l_data),
             "i2C read failed on %s for address 0x%02x", mss::c_str(i_target), i_addr);

    // Flush o_data_buffer to avoid stale data
    o_data_buffer.flush<0>();

    FAPI_ASSERT( (l_data.size() == mss::pmic::i2c::sizes::DATA_LENGTH),
                 fapi2::I2C_PMIC_INVALID_READ_SIZE()
                 .set_TARGET(i_target)
                 .set_ADDRESS(i_addr)
                 .set_SIZE_REQUESTED(mss::pmic::i2c::sizes::DATA_LENGTH)
                 .set_SIZE_RETURNED(l_data.size()),
                 "%s I2C read returned vector size of %u. Expected %u",
                 mss::c_str(i_target), l_data.size(), mss::pmic::i2c::sizes::DATA_LENGTH);

    o_data_buffer = l_data[0];

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a register write operation after flipping the data buffer
/// @tparam T target type
/// @param[in] i_target the PMIC/I2C device target
/// @param[in] i_addr address to write to
/// @param[in] i_data_buffer buffer of data to flip & write to the register
/// @return FAPI2_RC_SUCCESS iff okay
/// @note flips buffer from fapi2-style [0:7] to PMIC-style [7:0]
///
template <fapi2::TargetType T>
inline fapi2::ReturnCode reg_write_reverse_buffer(const fapi2::Target<T>& i_target,
        const uint8_t i_addr,
        const fapi2::buffer<uint8_t>& i_data_buffer)
{
    // Copy as to not modify original referenced buffer
    auto l_reg_buffer_copy = i_data_buffer;
    l_reg_buffer_copy.reverse();

    FAPI_TRY(mss::pmic::i2c::reg_write<T>(i_target, i_addr, l_reg_buffer_copy));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a register read operation, then flip data buffer
/// @tparam T target type
/// @param[in] i_target the PMIC/I2C device target
/// @param[in] i_addr address to read
/// @param[out] o_data_buffer buffer of data we will write the contents of the register to
/// @return FAPI2_RC_SUCCESS iff okay
/// @note flips buffer from PMIC-style [7:0], to fapi2-style [0:7]
///
template <fapi2::TargetType T>
inline fapi2::ReturnCode reg_read_reverse_buffer(const fapi2::Target<T>& i_target,
        const uint8_t i_addr,
        fapi2::buffer<uint8_t>& o_data_buffer)
{
    FAPI_TRY(mss::pmic::i2c::reg_read<T>(i_target, i_addr, o_data_buffer));
    o_data_buffer.reverse();
fapi_try_exit:
    return fapi2::current_err;
}
} // i2c
} // pmic
} // mss

#endif
