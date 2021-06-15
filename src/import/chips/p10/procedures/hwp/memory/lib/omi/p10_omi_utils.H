/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/omi/p10_omi_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file p10_omi_utils.H
/// @brief OMI utils for P10
///
// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#ifndef _P10_OMI_UTILS_H_
#define _P10_OMI_UTILS_H_

#include <fapi2.H>

#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/buffer_ops.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{
namespace omi
{

///
/// @brief State machine state post omi-train
///
enum state_machine_state
{
    STATE_MACHINE_SUCCESS = 0b111,
};

///
/// @brief Function to setup the CMN_CONFIG
/// @param[in] i_target the TARGET_TYPE_OMIC to operate on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_mc_cmn_config(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target);

///
/// @brief Function to set the CONFIG0 for the given train mode and backoff_en bit
/// @param[in] i_target the TARGET_TYPE_OMI to operate on
/// @param[in] i_train_mode training step to enable
/// @param[in] i_dl_x4_backoff_en backoff enable mode
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_mc_config0(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target,
    const uint8_t i_train_mode,
    const uint8_t i_dl_x4_backoff_en);

///
/// @brief Function to setup the CONFIG1
/// @param[in] i_target the TARGET_TYPE_OMI to operate on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_mc_config1(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target);

///
/// @brief Function to set the DL0_CYA_BITS
/// @param[in] i_target the TARGET_TYPE_OMI to operate on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_mc_cya_bits(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target);

///
/// @brief Function to set the DL0_ERROR_ACTION
/// @param[in] i_target the TARGET_TYPE_OMI to operate on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_mc_error_action(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target);

///
/// @brief Function to setup CONFIG1_EDPL_TIME for MFG screen test
/// @param[in] i_target the TARGET_TYPE_OMI to operate on
/// @param[in] i_edpl_disable value from ATTR_MSS_OMI_EDPL_DISABLE
/// @param[in] i_mnfg_screen_test true if OMI mfg screen is enabled
/// @param[in] i_mnfg_edpl_time value of ATTR_MSS_MNFG_EDPL_TIME
/// @param[in,out] io_data the register data to work on
/// @return FAPI2_RC_SUCCESS iff ok
///
void setup_mfg_test_edpl_time(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target,
                              const uint8_t i_edpl_disable,
                              const bool i_mnfg_screen_test,
                              const uint8_t i_mnfg_edpl_time,
                              fapi2::buffer<uint64_t>& io_data);

///
/// @brief Function to setup CONFIG1_EDPL_THRESHOLD for MFG screen test
/// @param[in] i_target the TARGET_TYPE_OMI to operate on
/// @param[in] i_edpl_disable value from ATTR_MSS_OMI_EDPL_DISABLE
/// @param[in] i_mnfg_screen_test true if OMI mfg screen is enabled
/// @param[in] i_mnfg_edpl_threshold value of ATTR_MSS_MNFG_EDPL_THRESHOLD
/// @param[in,out] io_data the register data to work on
/// @return FAPI2_RC_SUCCESS iff ok
///
void setup_mfg_test_edpl_threshold(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target,
                                   const uint8_t i_edpl_disable,
                                   const bool i_mnfg_screen_test,
                                   const uint8_t i_mnfg_edpl_threshold,
                                   fapi2::buffer<uint64_t>& io_data);

///
/// @brief P10 OMI setup helper function, to perform PRBS workarounds if needed
/// @param[in] i_omic OMIC target
/// @param[in] i_omi OMI target
/// @param[in] i_ocmb OCMB on the other side of the link
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error
///
fapi2::ReturnCode p10_omi_setup_prbs_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_omic,
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi,
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb);

///
/// @brief P10 OMI train helper function, to perform PRBS workarounds if needed
/// @param[in] i_omi OMI target
/// @param[in] i_ocmb OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode p10_omi_train_prbs_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi,
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb);

///
/// @brief P10 omi train procedure for simulation
///
/// @param[in] i_omic OMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode p10_omi_train_sim(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_omic);

///
/// @brief Get the OMI training status and state machine state
/// @param[in] i_omi OMI target
/// @param[out] o_state_machine_state state machine state
/// @param[out] o_omi_status omi status register buffer
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode omi_train_status(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi,
    uint64_t& o_state_machine_state,
    fapi2::buffer<uint64_t>& o_omi_status);

///
/// @brief Check state machine state for success code
/// @param[in] i_state_machine_state state machine state
/// @return true/false success
///
inline bool state_machine_success(const uint64_t i_state_machine_state)
{
    return (i_state_machine_state == STATE_MACHINE_SUCCESS);
}

///
/// @brief Check the OMI CRC counters for MFG screen test
/// @param[in] i_target OMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode check_omi_mfg_screen_crc_counts(
    const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target);

///
/// @brief Check the OMI EDPL counters for MFG screen test
/// @param[in] i_target OMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode check_omi_mfg_screen_edpl_counts(
    const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target);

} // namespace omi
} // namespace mss


#endif
