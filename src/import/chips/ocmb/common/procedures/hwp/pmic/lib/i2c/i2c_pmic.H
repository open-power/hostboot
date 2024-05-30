/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/i2c/i2c_pmic.H $ */
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
/// @file pmic_i2c.H
/// @brief PMIC I2C utility function declarations
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP
// EKB-Mirror-To: hw/ppe

#ifndef _MSS_I2C_PMIC_H_
#define _MSS_I2C_PMIC_H_

#include <fapi2.H>
#include <i2c_access.H>
#include <lib/utils/pmic_consts.H>

#ifdef __PPE__
    #define TARGTIDFORMAT "0x%08X"
    #define MSSTARGID(T) T.get()
    #include "index.H"
#else
    #include <generic/memory/lib/utils/pos.H>
    #include <generic/memory/lib/utils/c_str.H>
    #include <generic/memory/lib/utils/index.H>
    #include <generic/memory/lib/utils/find.H>
    #define TARGTIDFORMAT "%s"
    #define MSSTARGID(T) mss::c_str(T)
#endif

namespace mss
{
namespace pmic
{
namespace i2c
{

///
/// @brief Add provided opcode if the Target is an ADC
///
/// @param[in] i_target GENERICI2CRESPONDER target
/// @param[in] i_opcode opcode to add
/// @param[in,out] io_command command vector
///
inline void add_adc_opcode(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_target,
                           const mss::adc::i2c::opcode i_opcode,
                           std::vector<uint8_t>& io_command)
{
    // For DDR4:ADC's are index 0,1; GPIO0 is index 2
    // For DDR5: Going to use the same function for DDR5 since there is only 1 ADC supported in DDR5
    // and the below condition will still be satisfied
    if (mss::index(i_target) <= mss::generic_i2c_responder_ddr4::ADC2)
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
/// @param[in] i_length size of the data
/// @return FAPI2_RC_SUCCESS iff okay
///
template<fapi2::TargetType T>
inline fapi2::ReturnCode reg_write_helper(const fapi2::Target<T>& i_target,
        const uint8_t i_addr,
        const std::vector<uint8_t>& i_data_buffer,
        const uint8_t i_length);

///
/// @brief Set up i2c command buffer for the given target
/// @param[in] i_target the PMIC target
/// @param[in] i_addr address to read
/// @param[in] i_data_buffer data buffer
/// @param[in] i_length size of the data
/// @return FAPI2_RC_SUCCESS iff okay
///
template<>
inline fapi2::ReturnCode reg_write_helper(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_target,
        const uint8_t i_addr,
        const std::vector<uint8_t>& i_data_buffer,
        const uint8_t i_length)
{
    // #ifndef needs to be here because P10 SBE doesn't have ATTR_MEM_EFF_DRAM_GEN, and this is ok since P10 SBE only runs ddr4 pmic code
    // This #ifndef will be removed in ekb-src
#ifndef __PPE__
    static const uint8_t RETRIES = 11;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_dram_gen = 0;
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    // TODO: ZEN-MST:2632 Replace indexed DRAM gen reading with DRAM gen accessor
    // Get the dram generation
    for (const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(l_ocmb))
    {
        uint8_t l_value[2] = {};
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_GEN, l_port, l_value) );
        l_dram_gen = l_value[0];
        break;
    }

    // Work around the i2c timeout that's included in the ddr5 pmic components,
    // by splitting getI2c into putI2c for the address, then getI2c for the read data.
    // This is not needed on ddr4 because the pmic components used there do not have this timeout issue
    if(l_dram_gen == fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR5)
    {
        auto l_addr = i_addr;

        for(auto l_count = 0; l_count < i_length; l_count++, l_addr++)
        {
            l_rc = fapi2::FAPI2_RC_SUCCESS;
            std::vector<uint8_t> l_command;
            l_command.push_back(l_addr);
            l_command.push_back(i_data_buffer[l_count]);

            // Retry for 10 times before returning error
            for(auto l_retries = 0; l_retries < RETRIES; l_retries++)
            {
                l_rc = fapi2::putI2c(i_target, l_command);

                if (l_rc != fapi2::FAPI2_RC_SUCCESS)
                {
                    // Delay for 1 ms
                    fapi2::delay(1 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);
                }
                else
                {
                    break;
                }
            }

            // In case we have not found success after 10 retires, return the error
            if(l_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                FAPI_ERR("putI2C returned error for WRITE operation to 0x%02X on " TARGTIDFORMAT,
                         l_addr, MSSTARGID(i_target));
                return l_rc;
            }
        }
    }
    else
#endif
    {
        std::vector<uint8_t> l_command;
        l_command.push_back(i_addr);

        for(auto l_count = 0; l_count < i_length; l_count++)
        {
            l_command.push_back(i_data_buffer[l_count]);
        }

        // Use fapi2 putI2c interface to execute command
        FAPI_TRY(fapi2::putI2c(i_target, l_command),
                 "putI2C returned error for WRITE operation to 0x%02X on " TARGTIDFORMAT,
                 i_addr, MSSTARGID(i_target));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set up i2c command buffer for the given target
/// @param[in] i_target the GENERICI2CRESPONDER target
/// @param[in] i_addr address to read
/// @param[in] i_data_buffer data buffer
/// @param[in] i_length size of the data
/// @return FAPI2_RC_SUCCESS iff okay
///
template<>
inline fapi2::ReturnCode reg_write_helper(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_target,
        const uint8_t i_addr,
        const std::vector<uint8_t>& i_data_buffer,
        const uint8_t i_length)
{
    std::vector<uint8_t> l_command;

    if(i_length == mss::pmic::i2c::sizes::DATA_LENGTH)
    {
        add_adc_opcode(i_target, mss::adc::i2c::opcode::WRITE, l_command);
        l_command.push_back(i_addr);
        l_command.push_back(i_data_buffer[0]);
    }
    else
    {
        add_adc_opcode(i_target, mss::adc::i2c::opcode::WRITE_CONTIGUOUS, l_command);
        l_command.push_back(i_addr);

        for(uint32_t l_count = 0; l_count < i_length; l_count++)
        {
            l_command.push_back(i_data_buffer[l_count]);
        }
    }

    // Use fapi2 putI2c interface to execute command
    FAPI_TRY(fapi2::putI2c(i_target, l_command),
             "putI2C returned error for WRITE operation to 0x%02X on " TARGTIDFORMAT,
             i_addr, MSSTARGID(i_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set up i2c command buffer for the given DT target
/// @param[in] i_target the DT target
/// @param[in] i_addr address to read
/// @param[in] i_data_buffer data buffer
/// @param[in] i_length size of the data
/// @return FAPI2_RC_SUCCESS iff okay
///
template<>
inline fapi2::ReturnCode reg_write_helper(const fapi2::Target<fapi2::TARGET_TYPE_POWER_IC>& i_target,
        const uint8_t i_addr,
        const std::vector<uint8_t>& i_data_buffer,
        const uint8_t i_length)
{
    static const uint8_t RETRIES = 11;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    auto l_addr = i_addr;

    for(auto l_count = 0; l_count < i_length; l_count++, l_addr++)
    {
        l_rc = fapi2::FAPI2_RC_SUCCESS;
        std::vector<uint8_t> l_command;
        l_command.push_back(l_addr);
        l_command.push_back(i_data_buffer[l_count]);

        // Retry for 10 times before returning error
        for(auto l_retries = 0; l_retries < RETRIES; l_retries++)
        {
            l_rc = fapi2::putI2c(i_target, l_command);

            if (l_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                // Delay for 1 ms
                fapi2::delay(1 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);
            }
            else
            {
                break;
            }
        }

        // In case we have not found success after 10 retires, return the error
        if(l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            FAPI_ERR("putI2C returned error for WRITE operation to 0x%02X on " TARGTIDFORMAT,
                     l_addr, MSSTARGID(i_target));
            return l_rc;
        }
    }

    return fapi2::FAPI2_RC_SUCCESS;
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
    std::vector<uint8_t> l_data;

    l_data.push_back(uint8_t (i_data_buffer));

    FAPI_TRY(reg_write_helper(i_target, i_addr, l_data, mss::pmic::i2c::sizes::DATA_LENGTH));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a register write operation on the Default DT Addr which shares address with ADC
/// @param[in] i_target the DT/I2C device target
/// @param[in] i_addr address to write to
/// @param[in] i_data_buffer buffer of data to write to the register
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode reg_write_default_dt(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_target,
        const uint8_t i_addr,
        const fapi2::buffer<uint8_t>& i_data_buffer)
{
    std::vector<uint8_t> l_command;

    // Default DT shares address with ADC
    // This by passes the ADC op code addition in the write helper funct for this target type
    l_command.push_back(i_addr);
    l_command.push_back(uint8_t(i_data_buffer));

    // Use fapi2 putI2c interface to execute command
    FAPI_TRY(fapi2::putI2c(i_target, l_command),
             "putI2C returned error for WRITE operation to 0x%02X on " TARGTIDFORMAT,
             i_addr, MSSTARGID(i_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a register read operation on the given target
/// @tparam T target type (PMIC, GENERICI2CRESPONDER, etc.)
/// @param[in] i_target the target
/// @param[in] i_addr address to read
/// @param[in,out] io_data data buffer
/// @param[in] i_length size of the data
/// @return FAPI2_RC_SUCCESS iff okay
///
template<fapi2::TargetType T>
inline fapi2::ReturnCode reg_read_helper(const fapi2::Target<T>& i_target,
        const uint8_t i_addr,
        std::vector<uint8_t>& io_data,
        const uint8_t i_length);

///
/// @brief Perform a register read operation on the given target
/// @param[in] i_target the PMIC device target
/// @param[in] i_addr address to read
/// @param[in,out] io_data data buffer
/// @param[in] i_length size of the data
/// @return FAPI2_RC_SUCCESS iff okay
///
template<>
inline fapi2::ReturnCode reg_read_helper(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_target,
        const uint8_t i_addr,
        std::vector<uint8_t>& io_data,
        const uint8_t i_length)
{
    // #ifndef needs to be here because P10 SBE doesn't have ATTR_MEM_EFF_DRAM_GEN, and this is ok since P10 SBE only runs ddr4 pmic code
    // This #ifndef will be removed in ekb-src
#ifndef __PPE__
    static const uint8_t RETRIES = 11;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_dram_gen = 0;
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    // TODO: ZEN-MST:2632 Replace indexed DRAM gen reading with DRAM gen accessor
    // Get the dram generation
    for (const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(l_ocmb))
    {
        uint8_t l_value[2] = {};
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_GEN, l_port, l_value) );
        l_dram_gen = l_value[0];
        break;
    }

    // Work around the i2c timeout that's included in the ddr5 pmic components,
    // by splitting getI2c into putI2c for the address, then getI2c for the read data.
    // This is not needed on ddr4 because the pmic components used there do not have this timeout issue
    if(l_dram_gen == fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR5)
    {
        auto l_addr = i_addr;

        for(auto l_count = 0; l_count < i_length; l_count++, l_addr++)
        {
            std::vector<uint8_t> l_data;
            std::vector<uint8_t> l_command;
            l_command.push_back(l_addr);

            // Retry for 10 times for putI2C before returning error
            for(auto l_retries = 0; l_retries < RETRIES; l_retries++)
            {
                l_rc = fapi2::putI2c(i_target, l_command);

                if (l_rc != fapi2::FAPI2_RC_SUCCESS)
                {
                    // Delay for 1 ms
                    fapi2::delay(1 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);
                }
                else
                {
                    l_rc = fapi2::FAPI2_RC_SUCCESS;
                    break;
                }
            }

            if (l_rc == fapi2::FAPI2_RC_SUCCESS)
            {
                l_command.clear();

                // Read 1 byte at a time
                FAPI_TRY(fapi2::getI2c(i_target, mss::pmic::i2c::sizes::DATA_LENGTH, l_command, l_data),
                         "i2C read failed on " TARGTIDFORMAT " for address 0x%02x", MSSTARGID(i_target), l_addr);
                io_data.push_back(l_data[0]);
            }
            else
            {
                FAPI_ERR("putI2C returned error for WRITE operation to 0x%02X on " TARGTIDFORMAT,
                         l_addr, MSSTARGID(i_target));
                return l_rc;
            }
        }
    }
    else
#endif
    {
        std::vector<uint8_t> l_command;
        //std::vector<uint8_t> l_data;
        l_command.push_back(i_addr);
        FAPI_TRY(fapi2::getI2c(i_target, i_length, l_command, io_data),
                 "i2C read failed on " TARGTIDFORMAT " for address 0x%02x", MSSTARGID(i_target), i_addr);
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a register read operation on the given target
/// @param[in] i_target the GENERICI2CRESPONDER target
/// @param[in] i_addr address to read
/// @param[in,out] io_data data buffer
/// @param[in] i_length size of the data
/// @return FAPI2_RC_SUCCESS iff okay
///
template<>
inline fapi2::ReturnCode reg_read_helper(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_target,
        const uint8_t i_addr,
        std::vector<uint8_t>& io_data,
        const uint8_t i_length)
{
    std::vector<uint8_t> l_command;

    if(i_length == mss::pmic::i2c::sizes::DATA_LENGTH)
    {
        add_adc_opcode(i_target, mss::adc::i2c::opcode::READ, l_command);
    }
    else
    {
        add_adc_opcode(i_target, mss::adc::i2c::opcode::READ_CONTIGUOUS, l_command);
    }

    l_command.push_back(i_addr);

    FAPI_TRY(fapi2::getI2c(i_target, i_length, l_command, io_data),
             "i2C read failed on " TARGTIDFORMAT " for address 0x%02x", MSSTARGID(i_target), i_addr);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a register read operation on the given DT target
/// @param[in] i_target the DT device target
/// @param[in] i_addr address to read
/// @param[in,out] io_data data buffer
/// @param[in] i_length size of the data
/// @return FAPI2_RC_SUCCESS iff okay
///
template<>
inline fapi2::ReturnCode reg_read_helper(const fapi2::Target<fapi2::TARGET_TYPE_POWER_IC>& i_target,
        const uint8_t i_addr,
        std::vector<uint8_t>& io_data,
        const uint8_t i_length)
{
    static const uint8_t RETRIES = 11;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    auto l_addr = i_addr;

    for(auto l_count = 0; l_count < i_length; l_count++, l_addr++)
    {
        std::vector<uint8_t> l_data;
        std::vector<uint8_t> l_command;
        l_command.push_back(l_addr);

        // Retry for 10 times for putI2C before returning error
        for(auto l_retries = 0; l_retries < RETRIES; l_retries++)
        {
            l_rc = fapi2::putI2c(i_target, l_command);

            if (l_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                // Delay for 1 ms
                fapi2::delay(1 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);
            }
            else
            {
                l_rc = fapi2::FAPI2_RC_SUCCESS;
                break;
            }
        }

        if (l_rc == fapi2::FAPI2_RC_SUCCESS)
        {
            l_command.clear();

            // Read 1 byte at a time
            FAPI_TRY(fapi2::getI2c(i_target, mss::pmic::i2c::sizes::DATA_LENGTH, l_command, l_data),
                     "I2C read failed on " TARGTIDFORMAT " for address 0x%02x", MSSTARGID(i_target), l_addr);
            io_data.push_back(l_data[0]);
        }
        else
        {
            FAPI_ERR("putI2C returned error for WRITE operation to 0x%02X on " TARGTIDFORMAT,
                     l_addr, MSSTARGID(i_target));
            return l_rc;
        }
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
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

    FAPI_TRY(reg_read_helper(i_target, i_addr, l_data, mss::pmic::i2c::sizes::DATA_LENGTH));

    // Flush o_data_buffer to avoid stale data
    o_data_buffer.flush<0>();

#ifndef __PPE__
    FAPI_ASSERT( (l_data.size() == mss::pmic::i2c::sizes::DATA_LENGTH),
                 fapi2::I2C_PMIC_INVALID_READ_SIZE()
                 .set_TARGET(i_target)
                 .set_ADDRESS(i_addr)
                 .set_SIZE_REQUESTED(mss::pmic::i2c::sizes::DATA_LENGTH)
                 .set_SIZE_RETURNED(l_data.size()),
                 TARGTIDFORMAT " I2C read returned vector size of %u. Expected %u",
                 MSSTARGID(i_target), l_data.size(), mss::pmic::i2c::sizes::DATA_LENGTH);

    o_data_buffer = l_data[0];
#else // if PPE

    if (l_data.size() > 0)
    {
        o_data_buffer = l_data[0];
    }

    // Otherwise, leave it as-is, this will be fine for PPE.
#endif

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a register read operation on the given Default DT/ADC Target
/// @param[in] i_target the DT/I2C device target
/// @param[in] i_addr address to read
/// @param[out] o_data_buffer buffer of data we will write the contents of the register to
/// @return FAPI2_RC_SUCCESS iff okay
///
inline fapi2::ReturnCode reg_read_default_dt(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_target,
        const uint8_t i_addr,
        fapi2::buffer<uint8_t>& o_data_buffer)
{
    std::vector<uint8_t> l_data;
    std::vector<uint8_t> l_command;

    // Default DT shares address with ADC
    // This by passes the ADC op code addition in the write helper funct for this target type
    l_command.push_back(i_addr);

    FAPI_TRY(fapi2::getI2c(i_target, mss::pmic::i2c::sizes::DATA_LENGTH, l_command, l_data),
             "i2C read failed on " TARGTIDFORMAT " for address 0x%02x", MSSTARGID(i_target), i_addr);

    // Flush o_data_buffer to avoid stale data
    o_data_buffer.flush<0>();

#ifndef __PPE__
    FAPI_ASSERT( (l_data.size() == mss::pmic::i2c::sizes::DATA_LENGTH),
                 fapi2::I2C_PMIC_INVALID_READ_SIZE()
                 .set_TARGET(i_target)
                 .set_ADDRESS(i_addr)
                 .set_SIZE_REQUESTED(mss::pmic::i2c::sizes::DATA_LENGTH)
                 .set_SIZE_RETURNED(l_data.size()),
                 TARGTIDFORMAT " I2C read returned vector size of %u. Expected %u",
                 MSSTARGID(i_target), l_data.size(), mss::pmic::i2c::sizes::DATA_LENGTH);

    o_data_buffer = l_data[0];
#else // if PPE

    if (l_data.size() > 0)
    {
        o_data_buffer = l_data[0];
    }

    // Otherwise, leave it as-is, this will be fine for PPE.
#endif

    return fapi2::FAPI2_RC_SUCCESS;

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
    std::vector<uint8_t> l_data;

    // Copy as to not modify original referenced buffer
    auto l_reg_buffer_copy = i_data_buffer;
    l_reg_buffer_copy.reverse();

    l_data.push_back(uint8_t (l_reg_buffer_copy));

    FAPI_TRY(mss::pmic::i2c::reg_write_helper<T>(i_target, i_addr, l_data, mss::pmic::i2c::sizes::DATA_LENGTH));

    return fapi2::FAPI2_RC_SUCCESS;

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

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform register write operation on a contiguous address of given target
/// @tparam T target type
/// @tparam N size of the data buffer
/// @param[in] i_target the PMIC/I2C/DT device target
/// @param[in] i_addr starting register address to write to
/// @param[in] i_data_buffer buffer of data to be writen to register addresses
/// @return FAPI2_RC_SUCCESS iff okay
///
template <fapi2::TargetType T, size_t N>
inline fapi2::ReturnCode reg_write_contiguous(const fapi2::Target<T>& i_target,
        const uint8_t i_addr,
        const fapi2::buffer<uint8_t> (&i_data_buffer)[N])
{
    std::vector<uint8_t> l_data;

    for(uint32_t l_count = 0; l_count < N; l_count++)
    {
        l_data.push_back(uint8_t(i_data_buffer[l_count]));
    }

    FAPI_TRY(mss::pmic::i2c::reg_write_helper(i_target, i_addr, l_data, N));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform register write operation on a contiguous address of the Default DT/ADC target as they share the same address
/// @tparam N size of the data buffer
/// @param[in] i_target the I2C/DT device target
/// @param[in] i_addr starting register address to write to
/// @param[in] i_data_buffer buffer of data to be writen to register addresses
/// @return FAPI2_RC_SUCCESS iff okay
///
template <size_t N>
inline fapi2::ReturnCode reg_write_default_dt_contiguous(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>&
        i_target,
        const uint8_t i_addr,
        const fapi2::buffer<uint8_t> (&i_data_buffer)[N])
{
    std::vector<uint8_t> l_data;

    // Default DT shares address with ADC
    // This by passes the ADC op code addition in the write helper funct for this target type
    l_data.push_back(i_addr);

    for(uint32_t l_count = 0; l_count < N; l_count++)
    {
        l_data.push_back(uint8_t(i_data_buffer[l_count]));
    }

    // Use fapi2 putI2c interface to execute command
    return fapi2::putI2c(i_target, l_data);
}

///
/// @brief Perform register read operation on a contiguous address of given target
/// @tparam T target type
/// @tparam N size of the data buffer
/// @param[in] i_target the PMIC/I2C/DT device target
/// @param[in] i_addr starting register address to read from
/// @param[out] o_data_buffer buffer of data to be read from given register addresses
/// @return FAPI2_RC_SUCCESS iff okay
///
template <fapi2::TargetType T, size_t N>
inline fapi2::ReturnCode reg_read_contiguous(const fapi2::Target<T>& i_target,
        const uint8_t i_addr,
        fapi2::buffer<uint8_t> (&o_data_buffer)[N])
{
    std::vector<uint8_t> l_data_vector;
    uint32_t l_count = 0;

    // Flush o_data_buffer to avoid stale data
    for(l_count = 0; l_count < N; l_count++)
    {
        o_data_buffer[l_count] = 0;
    }

    FAPI_TRY(reg_read_helper(i_target, i_addr, l_data_vector, N));

    // Fill the array o_data_buffer from the read vector
    l_count = 0;

    // The array indexing will not run over as we are passing the number of bytes to be read to getI2C()
    for(auto l_data : l_data_vector)
    {
        o_data_buffer[l_count] = l_data;
        l_count++;
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform register read operation on a contiguous address of the Default DT/ADC target
/// @tparam N size of the data buffer
/// @param[in] i_target the I2C/DT device target
/// @param[in] i_addr starting register address to read from
/// @param[out] o_data_buffer buffer of data to be read from given register addresses
/// @return FAPI2_RC_SUCCESS iff okay
///
template <size_t N>
inline fapi2::ReturnCode reg_read_default_dt_contiguous(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>&
        i_target,
        const uint8_t i_addr,
        fapi2::buffer<uint8_t> (&o_data_buffer)[N])
{
    std::vector<uint8_t> l_data_vector;
    std::vector<uint8_t> l_command;
    uint32_t l_count = 0;

    // Default DT shares address with ADC
    // This by passes the ADC op code addition in the write helper funct for this target type
    l_command.push_back(i_addr);

    // Flush o_data_buffer to avoid stale data
    for(l_count = 0; l_count < N; l_count++)
    {
        o_data_buffer[l_count] = 0;
    }

    FAPI_TRY(fapi2::getI2c(i_target, N, l_command, l_data_vector),
             "i2C read failed on " TARGTIDFORMAT " for address 0x%02x", MSSTARGID(i_target), i_addr);

    // Fill the array o_data_buffer from the read vector
    l_count = 0;

    // The array indexing will not run over as we are passing the number of bytes to be read to getI2C()
    for(const auto l_data : l_data_vector)
    {
        o_data_buffer[l_count] = l_data;
        l_count++;
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform register read operation on a contiguous address of given target and then reverse the buffer
/// @tparam T target type
/// @tparam N size of the data buffer
/// @param[in] i_target the PMIC/I2C/DT device target
/// @param[in] i_addr starting register address to read from
/// @param[out] o_data_buffer reverse buffer of data to be read from given register addresses
/// @return FAPI2_RC_SUCCESS iff okay
///
template <fapi2::TargetType T, size_t N>
inline fapi2::ReturnCode reg_read_contiguous_reverse(const fapi2::Target<T>& i_target,
        const uint8_t i_addr,
        fapi2::buffer<uint8_t> (&o_data_buffer)[N])
{
    FAPI_TRY(reg_read_contiguous(i_target, i_addr, o_data_buffer));

    // Reverse the read data
    for(uint32_t l_count = 0; l_count < N; l_count++)
    {
        o_data_buffer[l_count].reverse();
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reverse the buffer then perform register write operation on a contiguous address of given target
/// @tparam T target type
/// @tparam N size of the data buffer
/// @param[in] i_target the PMIC/I2C/DT device target
/// @param[in] i_addr starting register address to write to
/// @param[in] i_data_buffer buffer of data to be writen to register addresses
/// @return FAPI2_RC_SUCCESS iff okay
///
template <fapi2::TargetType T, size_t N>
inline fapi2::ReturnCode reg_write_contiguous_reverse(const fapi2::Target<T>& i_target,
        const uint8_t i_addr,
        const fapi2::buffer<uint8_t> (&i_data_buffer)[N])
{
    fapi2::buffer<uint8_t> l_buffer_copy[N];

    // Reverse the input buffer and append to write data
    for(uint32_t l_count = 0; l_count < N; l_count++)
    {
        l_buffer_copy[l_count] = i_data_buffer[l_count];
        l_buffer_copy[l_count].reverse();
    }

    FAPI_TRY(reg_write_contiguous(i_target, i_addr, l_buffer_copy));
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

} // i2c
} // pmic
} // mss

#endif
