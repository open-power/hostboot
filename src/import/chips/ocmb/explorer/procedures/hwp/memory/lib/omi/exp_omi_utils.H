/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/omi/exp_omi_utils.H $ */
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
/// @file exp_omi_utils.H
/// @brief OMI utility functions
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory
#ifndef EXP_OMI_UTILS_H_
#define EXP_OMI_UTILS_H_

#include <fapi2.H>
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

static constexpr uint8_t OPTIMAL_NUM_TL_CREDITS = 18;
static constexpr uint8_t STATE_MACHINE_SUCCESS = 0b111; // This value is from Lonny Lambrecht

namespace mss
{
namespace exp
{
namespace omi
{

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
    return i_data.getBit<EXPLR_MMIO_MENTERP_MMIO_ENTERPRISE_MODE>();
}

///
/// @brief Sets the enterprise set bit
/// @param[in,out] io_data the register data
/// @param[in] i_is_enterprise true IFF we're in enterprise mode
///
inline void set_enterprise_set_bit( fapi2::buffer<uint64_t>& io_data, const bool i_is_enterprise )
{
    io_data.writeBit<EXPLR_MMIO_MENTERP_MMIO_ENTERPRISE_MODE>(i_is_enterprise);
}

///
/// @brief Gets the half-DIMM mode
/// @param[in] i_data the register data
/// @return The register's HALF_DIMM_MODE
///
inline bool get_half_dimm_mode( const fapi2::buffer<uint64_t>& i_data )
{
    return i_data.getBit<EXPLR_MMIO_MENTERP_HALF_DIMM_MODE>();
}

///
/// @brief Sets the half-DIMM mode
/// @param[in,out] io_data the register data
/// @param[in] i_is_half_dimm_mode true IFF we're in half_dimm_mode mode
///
inline void set_half_dimm_mode( fapi2::buffer<uint64_t>& io_data, const bool i_is_half_dimm_mode )
{
    io_data.writeBit<EXPLR_MMIO_MENTERP_HALF_DIMM_MODE>(i_is_half_dimm_mode);
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
    return i_data.getBit<EXPLR_MMIO_MENTERP_CFG_ENTERPRISE_MODE>();
}


///
/// @brief Get edpl enable bit
/// @param[in] i_data the register data
/// @return The register's EDPL_ENA bit
///
inline bool get_edpl_enable_bit( const fapi2::buffer<uint64_t>& i_data )
{
    return i_data.getBit<EXPLR_DLX_DL0_CONFIG1_CFG_EDPL_ENA>();
}

///
/// @brief Set edpl enable bit
/// @param[in,out] io_data the register data
/// @param[in] i_enable The register's EDPL_ENA bit
///
inline void set_edpl_enable_bit( fapi2::buffer<uint64_t>& io_data, const bool i_enable )
{
    io_data.writeBit<EXPLR_DLX_DL0_CONFIG1_CFG_EDPL_ENA>(i_enable);
}

///
/// @brief Setup edpl time window for mnfg test
/// @param[in,out] io_data the register data
/// @param[in] i_enable true if edpl is enabled
/// @param[in] i_mnfg_screen_test true if OMI mfg screen is enabled
///
inline void setup_edpl_time_window( fapi2::buffer<uint64_t>& io_data,
                                    const bool i_enable,
                                    const bool i_mnfg_screen_test )
{
    if (i_enable && i_mnfg_screen_test)
    {
        // set EDPL for 'no time window', so the counters will keep accumulating (until max 0xff)
        // and can be compared to attribute at end of mnfg run
        io_data.insertFromRight<EXPLR_DLX_DL0_CONFIG1_CFG_EDPL_TIME,
                                EXPLR_DLX_DL0_CONFIG1_CFG_EDPL_TIME_LEN>(mss::omi::edpl_time_win::EDPL_TIME_WIN_NO);
    }
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

    return fapi2::FAPI2_RC_SUCCESS;

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
    return fapi2::getScom(i_target, EXPLR_MMIO_MENTERP, o_data);
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
    return fapi2::putScom(i_target, EXPLR_MMIO_MENTERP, i_data);
}

///
/// @brief Reads the EXPLR_DLX_DL0_CONFIG1 register using I2C
/// @param[in] i_target the OCMB target on which to operate
/// @param[out] o_data the register contents
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
inline fapi2::ReturnCode read_dlx_config1( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        fapi2::buffer<uint64_t>& o_data )
{
    return fapi2::getScom(i_target, EXPLR_DLX_DL0_CONFIG1, o_data);
}

///
/// @brief Writes the EXPLR_DLX_DL0_CONFIG1 register using I2C
/// @param[in] i_target the OCMB target on which to operate
/// @param[in] i_data the register contents
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
inline fapi2::ReturnCode write_dlx_config1( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const  fapi2::buffer<uint64_t>& i_data )
{
    return fapi2::putScom(i_target, EXPLR_DLX_DL0_CONFIG1, i_data);
}

///
/// @brief Set the OMI_DL0 configuration register for a given mode
///
/// @param[in] i_target OCMB target
/// @param[in] i_train_mode mode to use
/// @param[in] i_dl_x4_backoff_en backoff enable bit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note Algorithm from p10_omi_train.C
///
fapi2::ReturnCode setup_omi_dl0_config0(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint8_t i_train_mode,
    const uint8_t i_dl_x4_backoff_en);

///
/// @brief Set up the OMI object handles for intrp_req commands
/// @param[in] i_target OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode setup_obj_handles(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Set up the OMI interrupt command flags
/// @param[in] i_target OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode setup_int_cmd_flags(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Sets up the FFE_SETTINGS command
/// @param[in] i_target target on which the code is operating
/// @param[out] o_data data for the FFE_SETTINGS command
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
fapi2::ReturnCode ffe_setup( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                             std::vector<uint8_t>& o_data );

namespace train
{

///
/// @brief Sets up the OMI training
/// @param[in] i_target target on which the code is operating
/// @param[out] o_data data for the FW_BOOT_CONFIG
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
fapi2::ReturnCode setup_fw_boot_config( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                        std::vector<uint8_t>& o_data );

///
/// @brief Check the OMI train status on the OCMB chip
///
/// @param[in] i_target OCMB chil
/// @param[out] o_state_machine_state training state mahcine
/// @param[out] o_omi_training_status training status
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode omi_train_status(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                   uint8_t& o_state_machine_state,
                                   fapi2::buffer<uint64_t>& o_omi_training_status);

///
/// @brief Poll for OMI training completion
///
/// @param[in] i_target OCMB target
/// @param[out] o_state_machine_state state machine state
/// @param[out] o_omi_status omi status register buffer
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode poll_for_training_completion(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    uint8_t& o_state_machine_state,
    fapi2::buffer<uint64_t>& o_omi_status);

///
/// @brief Abort Explorer FW polling for OMI training completion
/// @param[in] i_target OCMB target
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode poll_abort(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

} // ns train

} // ns omi

} // ns exp

} // ns mss

#endif
