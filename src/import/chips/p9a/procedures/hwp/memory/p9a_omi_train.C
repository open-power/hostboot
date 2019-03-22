/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/p9a_omi_train.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
/// @file p9a_omi_train.C
/// @brief Check the omi status
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#include <lib/shared/axone_defaults.H>
#include <p9a_omi_train.H>

#include <fapi2.H>
#include <p9a_mc_scom_addresses.H>
#include <p9a_mc_scom_addresses_fld.H>
#include <p9a_mc_scom_addresses_fixes.H>
#include <p9a_mc_scom_addresses_fld_fixes.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/buffer_ops.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <lib/mc/omi.H>


///
/// @brief Turn on Axone config regs to enable training
/// @param[in] i_target the OMI target to operate on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p9a_omi_train( const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target)
{
    FAPI_INF("%s Start p9a_omi_train", mss::c_str(i_target));

    const auto l_mc = mss::find_target<fapi2::TARGET_TYPE_MC>(i_target);

    FAPI_TRY(mss::mc::setup_mc_mcn_config_helper(l_mc));
    FAPI_TRY(mss::mc::setup_mc_config1_helper(i_target));
    FAPI_TRY(mss::mc::setup_mc_cya_bits_helper(i_target));
    FAPI_TRY(mss::mc::setup_mc_error_action_helper(i_target));
    FAPI_TRY(mss::mc::setup_mc_rmt_config_helper(i_target));

    // *_CONFIG0 should be the last one written, since it starts the training.
    FAPI_TRY(mss::mc::setup_mc_config0_helper(i_target));


fapi_try_exit:
    return fapi2::current_err;

}// p9a_omi_train
