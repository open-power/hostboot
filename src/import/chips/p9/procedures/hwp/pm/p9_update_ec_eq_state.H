/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_update_ec_eq_state.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file p9_update_ec_eq_state.H
/// @brief Update the "permanent" multicast groups  reflect any additional
///          deconfigured by Hostboot
// *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: SBE
///

#ifndef _p9_update_ec_eq_state_H_
#define _p9_update_ec_eq_state_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <p9_misc_scom_addresses.H>
#include <p9_perv_scom_addresses.H>
#include <p9_quad_scom_addresses.H>



// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_update_ec_eq_state_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);



namespace p9UpdateECEQ
{
enum P9_Update_EQ_EC_Constants
{
    MCGR_CNFG_SETTING_GROUP0 = 0xE0001C0000000000ull,
    MCGR_CNFG_SETTING_GROUP1 = 0xE4001C0000000000ull,
    MCGR_CNFG_SETTING_GROUP2 = 0xE8001C0000000000ull,
    MCGR_CNFG_SETTING_GROUP3 = 0xEC001C0000000000ull,
    MCGR_CNFG_SETTING_GROUP4 = 0xF0001C0000000000ull,
    MCGR_CNFG_SETTING_GROUP5 = 0xF4001C0000000000ull,
    MCGR_CNFG_SETTING_GROUP6 = 0xF8001C0000000000ull,
    MCGR_CLEAR_CNFG_SETTINGS = 0xFC001C0000000000ull,   // Group  7
};
}



extern "C" {

// -----------------------------------------------------------------------------
//  Function prototype
// -----------------------------------------------------------------------------

/// @brief Select the Hostboot core from the available cores on the chip
///
/// @param [in] i_target    Chip target
///

    fapi2::ReturnCode p9_update_ec_eq_state(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

} // extern "C"

#endif // _p9_update_ec_eq_state_H_
