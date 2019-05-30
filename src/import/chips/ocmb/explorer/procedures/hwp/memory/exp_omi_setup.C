/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_omi_setup.C $ */
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
/// @file exp_omi_setup.C
/// @brief Contains the explorer OMI setup
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#include <fapi2.H>
#include <generic/memory/lib/utils/c_str.H>
#include <lib/exp_attribute_accessors_manual.H>
#include <lib/omi/exp_omi_utils.H>
#include <generic/memory/mss_git_data_helper.H>

extern "C"
{

    ///
    /// @brief Setup the OCMB for enterprise and half-DIMM modes as desired
    /// @param[in] i_target the OCMB target to operate on
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode exp_omi_setup( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
    {
        mss::display_git_commit_info("exp_omi_setup");

        // Declares variables
        fapi2::buffer<uint64_t> l_data;
        bool l_is_enterprise = false;
        bool l_is_half_dimm = false;

        // Gets the configuration information from attributes
        FAPI_TRY(mss::enterprise_mode(i_target, l_is_enterprise));
        FAPI_TRY(mss::half_dimm_mode(i_target, l_is_half_dimm));

        // Prints out the data
        FAPI_INF("%s is %s enterprise mode, and %s-DIMM mode", mss::c_str(i_target), l_is_enterprise ? "" : "non",
                 l_is_half_dimm ? "half" : "full");

        // Sets up the register
        mss::exp::omi::set_enterprise_set_bit(l_data, l_is_enterprise);
        mss::exp::omi::set_half_dimm_mode(l_data, l_is_half_dimm);

        // Writes the data to the register
        FAPI_TRY(mss::exp::omi::write_enterprise_config(i_target, l_data));

        // Checks that the chip is configured correctly
        FAPI_TRY(mss::exp::omi::read_enterprise_config(i_target, l_data));
        FAPI_TRY(mss::exp::omi::check_enterprise_mode(i_target, l_is_enterprise, l_data));

    fapi_try_exit:
        return fapi2::current_err;
    }
}
