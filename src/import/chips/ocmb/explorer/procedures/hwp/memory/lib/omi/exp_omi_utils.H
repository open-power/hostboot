/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/omi/exp_omi_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file exp_omi_utils.H
/// @brief OMI utility functions
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory
#ifndef EXP_OMI_UTILS_H_
#define EXP_OMI_UTILS_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/c_str.H>

namespace mss
{
namespace exp
{
namespace omi
{

///
/// @brief Constants used for the OMI register fields
///
// TODO:RTC196850 Update Explorer code to use actual register addresses/names
enum fields
{
    // Bit we set to put ourselves into enterprise mode
    ENTERPRISE_SET_BIT = 0,
    HALF_DIMM_MODE = 1,
    // How the HW is actually configured in enterprise mode
    ENTERPRISE_BIT_CONFIG = 2,
};

///
/// @brief Constants used for the OMI registers
///
// TODO:RTC196850 Update Explorer code to use actual register addresses/names
enum registers
{
    // Bit we set to put ourselves into enterprise mode
    MENTERP = 0x080108e4,
};

///////////////////////////////////////////////////////////////////////////////////
/// Bit Field Operations
///////////////////////////////////////////////////////////////////////////////////

///
/// @brief Gets the enterprise set bit
/// @param[in] i_data the register data
/// @return The register's ENTERPRISE_SET_BIT
///
inline bool get_enterprise_set_bit( const fapi2::buffer<uint64_t>& i_data )
{
    return i_data.getBit<fields::ENTERPRISE_SET_BIT>();
}

///
/// @brief Sets the enterprise set bit
/// @param[in,out] io_data the register data
/// @param[in] i_is_enterprise true IFF we're in enterprise mode
///
inline void set_enterprise_set_bit( fapi2::buffer<uint64_t>& io_data, const bool i_is_enterprise )
{
    io_data.writeBit<fields::ENTERPRISE_SET_BIT>(i_is_enterprise);
}

///
/// @brief Gets the half-DIMM mode
/// @param[in] i_data the register data
/// @return The register's HALF_DIMM_MODE
///
inline bool get_half_dimm_mode( const fapi2::buffer<uint64_t>& i_data )
{
    return i_data.getBit<fields::HALF_DIMM_MODE>();
}

///
/// @brief Sets the half-DIMM mode
/// @param[in,out] io_data the register data
/// @param[in] i_is_half_dimm_mode true IFF we're in half_dimm_mode mode
///
inline void set_half_dimm_mode( fapi2::buffer<uint64_t>& io_data, const bool i_is_half_dimm_mode )
{
    io_data.writeBit<fields::HALF_DIMM_MODE>(i_is_half_dimm_mode);
}

// Note: ENTERPRISE_BIT_CONFIG is a Read only bit, so no setting it
///
/// @brief Gets the enterprise config bit
/// @param[in] i_data the register data
/// @return The register's ENTERPRISE_BIT_CONFIG
/// @note This bit indicates whether the hardware is in enterprise mode
///
inline bool get_enterprise_config( const fapi2::buffer<uint64_t>& i_data )
{
    return i_data.getBit<fields::ENTERPRISE_BIT_CONFIG>();
}

///
/// @brief Checks if the enterprise config bit is in the correct mode
/// @param[in] i_target target on which we are operating - for logging
/// @param[in] i_is_enterprise true if the chip should be in enterprise mode
/// @param[in] i_data data from the enterprise mode register
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff everything is OK
///
inline fapi2::ReturnCode check_enterprise_mode( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const bool i_is_enterprise,
        fapi2::buffer<uint64_t>& i_data )
{
    const bool l_actual = mss::exp::omi::get_enterprise_config(i_data);
    FAPI_ASSERT(l_actual == i_is_enterprise,
                fapi2::MSS_EXP_ENTERPRISE_SETUP_ERROR()
                .set_EXPECTED(i_is_enterprise)
                .set_ACTUAL(l_actual)
                .set_REGISTER_DATA(i_data)
                .set_OCMB_TARGET(i_target),
                "%s failed to setup enterprise mode properly expected: %u actual: %u register data 0x%016lx",
                mss::c_str(i_target), i_is_enterprise, l_actual, i_data);

fapi_try_exit:
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////////////////////////////
/// Register access operations
///////////////////////////////////////////////////////////////////////////////////
// The scom API should be able to distinguish between the need for i2c vs MMIO

///
/// @brief Reads the register using I2C
/// @param[in] i_target the OCMB target on which to operate
/// @param[out] o_data the register contents
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
inline fapi2::ReturnCode read_enterprise_config( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        fapi2::buffer<uint64_t>& o_data )
{
    return fapi2::getScom(i_target, registers::MENTERP, o_data);
}

///
/// @brief Writes the register using I2C
/// @param[in] i_target the OCMB target on which to operate
/// @param[in] i_data the register contents
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
inline fapi2::ReturnCode write_enterprise_config( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const  fapi2::buffer<uint64_t>& i_data )
{
    return fapi2::putScom(i_target, registers::MENTERP, i_data);
}

} // ns mss

} // ns exp

} // ns omi

#endif
