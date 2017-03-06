/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_draminit_mc.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
