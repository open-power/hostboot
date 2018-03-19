/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_draminit_mc.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
/// @file p9c_mss_draminit_mc.H
/// @brief Procedure for handing over control to the MC
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

#ifndef mss_draminit_mc_H_
#define mss_draminit_mc_H_
#include <fapi2.H>

typedef fapi2::ReturnCode (*p9c_mss_draminit_mc_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& target);

extern "C"
{

    ///
    /// @brief Draminit MC procedure. Enable MC functions and set IML complete within centaur
    /// @param[in]  i_target  Reference to centaur target
    /// @return ReturnCode
    ///
    fapi2::ReturnCode p9c_mss_draminit_mc(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& target);

    ///
    ///@brief Enable periodic calibration on centaur
    ///@param[in] i_target Membuf target
    ///@return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode mss_enable_periodic_cal(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

    ///
    ///@brief Set IML complete bit
    ///@param[in] i_target Membuf target
    ///@return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode mss_set_iml_complete(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target);

    ///
    ///@briefa Enable power management and domain control
    ///@param[in] i_target Membuf target
    ///@return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode mss_enable_power_management(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

    ///
    ///@brief Enable ECC checks
    ///@param[in] i_target Membuf target
    ///@return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode mss_enable_control_bit_ecc(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target);

    ///
    ///@brief Switch address mux from CCS logic to mainline logic
    ///@param[in] i_target Membuf target
    ///@return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode mss_ccs_mode_reset(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

    ///
    /// @brief Checks parity error reporting and sets up RCD recovery
    /// @param[in] i_target MBA target
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode check_parity_and_enable_rcd_recovery(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

    ///
    /// @brief Sets up the firs for the RCD response time calibration
    /// @param[in] i_target MBA target
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode setup_firs_for_rcd_response_time_calibration(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

    ///
    /// @brief Finds the maximum allowable RCD protect time
    /// @param[in] i_target MBA target
    /// @param[out] o_max_rcd_protect maximum allowable RCD protect time
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode find_max_rcd_protect_time(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            uint8_t& o_max_rcd_protect);

    ///
    /// @brief Loads the RCD protection maint commands
    /// @param[in] i_target MBA target
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode load_rcd_protect_maint_cmd(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

    ///
    /// @brief Clears the RCD parity FIR bit
    /// @param[in] i_target MBA target
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode clear_rcd_parity_fir(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

    ///
    /// @brief Clears the RCD parity errors in the MBACAL FIR register
    /// @param[in] i_target MBA target
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode clear_rcd_parity_mbacal_fir(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

    ///
    /// @brief Sets up the RCD protect time
    /// @param[in] i_time the RCD protect time
    /// @param[in,out] io_data the data buffer to modify
    ///
    void set_rcd_protect_time(const uint8_t i_time, fapi2::buffer<uint64_t>& io_data);

    ///
    /// @brief Sets up the RCD parity inject
    /// @param[in] i_port the port on which to do the inject
    /// @param[in,out] io_data the data buffer to modify
    ///
    void set_rcd_inject(const uint8_t i_port, fapi2::buffer<uint64_t>& io_data);

    ///
    /// @brief Setup RCD parity inject and time
    /// @param[in] i_target MBA target
    /// @param[in] i_time the RCD protect time
    /// @param[in] i_port the port on which to operate
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode setup_rcd_protect_inject_time(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const uint8_t i_time,
            const uint8_t i_port);

    ///
    /// @brief Setup RCD parity inject and time
    /// @param[in] i_target MBA target
    /// @param[in] i_dimm the DIMM number on which to operate
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode start_single_address_maint(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const uint8_t i_dimm);

    ///
    /// @brief Checks the maintenance engine's address FIR for errors
    /// @param[in] i_target MBA target
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode check_maint_fir(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

    ///
    /// @brief Checks the maintenance engine's address FIR for errors
    /// @param[in] i_target MBA target
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode check_maint_timeout(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

    ///
    /// @brief Processes the RCD timeout results
    /// @param[in] i_target MBA target
    /// @param[in] i_port the port on which the code is operating
    /// @param[in] i_dimm the DIMM on which the code is operating
    /// @param[in] i_max_cfg_rcd_protection_time maximum allowable configuration time
    /// @param[in,out] io_cfg_rcd_protection_time current RCD protection time
    /// @param[in,out] io_highest_cfg_rcd_protection_time highest configuration time from all calibrated ports
    /// @param[out] o_loop_done true if the RCD error was found and the current loop is done
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode process_rcd_timeout_results(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const uint8_t i_port,
            const uint8_t i_dimm,
            const uint8_t i_max_cfg_rcd_protection_time,
            uint8_t& io_cfg_rcd_protection_time,
            uint8_t& io_highest_cfg_rcd_protection_time,
            bool& o_loop_done);

    ///
    /// @brief Sets up the FIR mask for the RCD parity error in mainline
    /// @param[in] i_target MBA target
    /// @return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode setup_firs_mask_rcd_parity_mainline(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

    ///
    ///@brief validate RCD protect time
    ///@param[in] i_target Membuf target
    ///@return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode mss_check_RCD_protect_time(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

    ///
    ///@brief Disable spare CKE
    ///@param[in] i_target Membuf target
    ///@return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode mss_spare_cke_disable(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

    ///
    ///@brief Enable port 1 address inversion
    ///@param[in] i_target Membuf target
    ///@return FAPI2_RC_SUCCESS iff function complete
    ///
    fapi2::ReturnCode mss_enable_addr_inversion(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);
} // extern "C"

#endif // mss_draminit_mc_H_
