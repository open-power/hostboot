/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_sppe_draminit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2024                        */
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
/// @file ody_sppe_draminit.C
/// @brief Runs the dram initialization on the SPPE
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <ody_sppe_draminit.H>

#include <lib/phy/ody_draminit_procedure.H>
#include <lib/phy/ody_draminit_utils.H>
#include <generic/memory/mss_git_data_helper.H>
#include <generic/memory/lib/utils/find.H>
extern "C"
{
///
/// @brief Runs the dram initialization on the SPPE
/// @param[in] i_target the controller
/// @param[out] o_log_data hwp_data_ostream of streaming log
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode ody_sppe_draminit(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                        fapi2::hwp_data_ostream& o_log_data)
    {
        mss::display_git_commit_info("ody_sppe_draminit");


#ifdef __PPE__
        FAPI_TRY(mss::ody::phy::check_draminit_verbosity(i_target));
#endif
        FAPI_TRY(mss::ody::draminit(i_target, o_log_data));

    fapi_try_exit:
        return fapi2::current_err;

    }
    ///
    /// @brief Runs the dram initialization on the SPPE on a single port
    /// @param[in] i_target the controller
    /// @param[out] o_log_data hwp_data_ostream of streaming log
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode ody_sppe_draminit_single_port(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port,
            fapi2::hwp_data_ostream& o_log_data)
    {
        mss::display_git_commit_info("ody_sppe_draminit");

        FAPI_TRY(mss::ody::draminit(i_port, o_log_data));

    fapi_try_exit:
        return fapi2::current_err;

    }


}// extern C
