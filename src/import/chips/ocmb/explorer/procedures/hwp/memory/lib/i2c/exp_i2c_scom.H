/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/i2c/exp_i2c_scom.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
/// @file exp_i2c_scom.H
/// @brief explorer I2C scom function declarations
///
// *HWP HWP Owner: Christian Geddes <crgeddes@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:SBE

#ifndef _MSS_EXP_I2C_SCOM_H_
#define _MSS_EXP_I2C_SCOM_H_


#ifdef __PPE__
    #include <exp_i2c.H>
#else
    #include <lib/i2c/exp_i2c.H>
    #include <generic/memory/lib/utils/pos.H>
#endif


namespace mss
{
namespace exp
{
namespace i2c
{

///
/// @brief Perform a put scom operation over i2c to OCMB explorer chip
///        @note OCMB chip is little-endian and Host is likely running big-endian
///
/// @param[in] i_addr    32 bit IBM scom address we want to write on the OCMB
/// @param[in] i_target  the OCMB target
/// @param[in] i_data_buffer  Contains data which will be written to i_addr on i_target
///
/// @return FAPI2_RC_SUCCESS iff okay
///
/// @note this is the IBM scom version the overloaded function i2c_put_scom
///       IBM i2c scoms to the explorer chips are 64 bits of data
fapi2::ReturnCode i2c_put_scom( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                const uint32_t i_addr,
                                const fapi2::buffer<uint64_t>& i_data_buffer)
{
    // We need to separate 64 bit input buffer into two 32-bit halves,
    // use this 32-bit buffer to pull out 32 bits at a time
    fapi2::buffer<uint32_t> l_side_specific_buffer;

    // check if this is an IBM address
    FAPI_ASSERT( ((i_addr & FIRST_BYTE_MASK) == IBM_SCOM_INDICATOR),
                 fapi2::I2C_SCOM_EXPECTED_IBM_INDICATOR()
                 .set_TARGET(i_target)
                 .set_ADDRESS(i_addr),
                 "First byte of 0x%lx does not = 0x%lx, address is not valid for IBM I2C scom",
                 i_addr, IBM_SCOM_INDICATOR);

    // The LHS is the bits 0-31 of the input buffer
    i_data_buffer.extractToRight<0, 32>(l_side_specific_buffer);

    // Perform the write operation to complete the LHS of the write
    FAPI_TRY(fw_reg_write(i_target, trans_ibm_i2c_scom_addr(i_addr, LHS), l_side_specific_buffer),
             "(LHS) Failed i2c scom register write to ibm scom addr  0x%lx on OCMB w/ fapi_pos = %d",
             i_addr, mss::fapi_pos(i_target));

    // The RHS is the bits 32-63 of the input buffer
    i_data_buffer.extractToRight<32, 32>(l_side_specific_buffer);

    // Perform the write operation to complete the RHS of the write
    FAPI_TRY(fw_reg_write(i_target, trans_ibm_i2c_scom_addr(i_addr, RHS), l_side_specific_buffer),
             "(RHS) Failed i2c scom register write to ibm scom addr 0x%lx on OCMB w/ fapi_pos = %d",
             i_addr, mss::fapi_pos(i_target) );

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Perform a put scom operation over i2c to OCMB explorer chip
///        @note OCMB chip is little-endian and Host is likely running big-endian
/// @param[in] i_target  the OCMB target
/// @param[in] i_addr    32 bit Microchip scom address we want to write on the OCMB
/// @param[in] i_data_buffer  Contains data which will be written to i_addr on i_target
///
/// @return FAPI2_RC_SUCCESS iff okay
///
/// @note this is the Microchip scom version the overloaded function i2c_put_scom
///       Microchip i2c scoms to the explorer chips are 32 bits of data
fapi2::ReturnCode i2c_put_scom( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                const uint32_t i_addr,
                                const fapi2::buffer<uint32_t>& i_data_buffer)
{
    // The micro-semi addresses should not have the IBM indicator
    FAPI_ASSERT( ((i_addr & FIRST_BYTE_MASK) != IBM_SCOM_INDICATOR),
                 fapi2::I2C_SCOM_UNEXPECTED_IBM_INDICATOR()
                 .set_TARGET(i_target)
                 .set_ADDRESS(i_addr),
                 "First byte of 0x%lx == 0x%lx, address is not valid for microchip I2C scom",
                 i_addr, IBM_SCOM_INDICATOR);

    // Perform the write operation, note we must apply the UNCACHED_OFFSET to the
    // address before performing the write
    // Also note that we pass i_data_buffer directly to the fw_reg_read function
    FAPI_TRY(fw_reg_write(i_target, trans_micro_i2c_scom_addr(i_addr) , i_data_buffer),
             "Failed i2c scom register write to microchip scom addr 0x%lx on OCMB w/ fapi_pos = %d",
             i_addr, mss::fapi_pos(i_target));

fapi_try_exit:
    return fapi2::current_err;

}




///
/// @brief Perform a get scom operation over i2c to OCMB explorer chip
///        @note OCMB chip is little-endian and Host is likely running big-endian
/// @param[in]  i_target  the OCMB target
/// @param[in]  i_addr    32 bit IBM scom address we want to read from on the OCMB
/// @param[out] o_data_buffer  Buffer where data found at i_addr will be written to
///
/// @return FAPI2_RC_SUCCESS iff okay
///
/// @note this is the IBM scom version the overloaded function i2c_get_scom
///       IBM i2c scoms to the explorer chips are 64 bits of data
fapi2:: ReturnCode i2c_get_scom(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                const uint32_t i_addr,
                                fapi2::buffer<uint64_t>& o_data_buffer)
{
    // IBM get scom expects 64 bits of data returned but we can only
    // read 32 bits of data per command so we will do 2 reads in this getscom step.
    fapi2::buffer<uint32_t> l_read_buffer;

    // check if this is an IBM address
    FAPI_ASSERT( ((i_addr & FIRST_BYTE_MASK) == IBM_SCOM_INDICATOR),
                 fapi2::I2C_SCOM_EXPECTED_IBM_INDICATOR()
                 .set_TARGET(i_target)
                 .set_ADDRESS(i_addr),
                 "First byte of 0x%lx does not = 0x%lx, address is not valid for IBM I2C scom",
                 i_addr, IBM_SCOM_INDICATOR);

    FAPI_TRY(fw_reg_read(i_target, trans_ibm_i2c_scom_addr(i_addr, LHS), l_read_buffer),
             "(LHS) Failed i2c scom register read from ibm scom addr 0x%.8X on OCMB w/ fapiPos = 0x%.8X",
             i_addr, mss::fapi_pos(i_target));

    // Data was put in correct order by fw_reg_read, copy data to LHS of out buffer
    o_data_buffer.insertFromRight<0, 32>(l_read_buffer);

    FAPI_TRY(fw_reg_read(i_target, trans_ibm_i2c_scom_addr(i_addr, RHS), l_read_buffer),
             "(RHS) Failed i2c scom register read from ibm scom addr 0x%.8X on OCMB w/ fapiPos = 0x%.8X",
             i_addr, mss::fapi_pos(i_target));

    // Data was put in correct order by fw_reg_read, copy data to RHS of out buffer
    o_data_buffer.insertFromRight<32, 32>(l_read_buffer);


fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a get scom operation over i2c to OCMB explorer chip
///        @note OCMB chip is little-endian and Host is likely running big-endian
/// @param[in]  i_target  the OCMB target
/// @param[in]  i_addr    32 bit Microchip scom address we want to read from on the OCMB
/// @param[out] o_data_buffer  Buffer where data found at i_addr will be written to
///
/// @return FAPI2_RC_SUCCESS iff okay
///
/// @note this is the Microchip scom version the overloaded function i2c_get_scom
///       Microchip i2c scoms to the explorer chips are 32 bits of data
fapi2:: ReturnCode i2c_get_scom(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                const uint32_t i_addr,
                                fapi2::buffer<uint32_t>& o_data_buffer)
{
    // The micro-semi addresses should not have the IBM indicator
    FAPI_ASSERT( ((i_addr & FIRST_BYTE_MASK) != IBM_SCOM_INDICATOR),
                 fapi2::I2C_SCOM_UNEXPECTED_IBM_INDICATOR()
                 .set_TARGET(i_target)
                 .set_ADDRESS(i_addr),
                 "First byte of 0x%lx == 0x%lx, address is not valid for microchip I2C scom",
                 i_addr, IBM_SCOM_INDICATOR);

    // Perform the read operation, note we must apply the UNCACHED_OFFSET to the
    // address before performing the read.
    // Also note that we pass o_data_buffer directly to the fw_reg_read function
    FAPI_TRY(fw_reg_read(i_target, trans_micro_i2c_scom_addr(i_addr) , o_data_buffer),
             "Failed i2c scom register read from microchip scom addr 0x%.8X on OCMB w/ fapiPos = 0x%.8X",
             i_addr, mss::fapi_pos(i_target));


fapi_try_exit:
    return fapi2::current_err;
}

} // end i2c namespace
} // end exp namespace
} // end mss namespace

#endif
