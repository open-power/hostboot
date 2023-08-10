/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_blame_firs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
// EKB-Mirror-To: hostboot

///
/// @file ody_blame_firs.C
/// @brief Check for FIR bits related to a HWP fail
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <ody_blame_firs.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mss_generic_check.H>


extern "C"
{

    ///
    /// @brief Check for FIR bits related to a HWP fail
    /// @param[in] i_target OCMB chip
    /// @param[in] i_substep the IPL substep to check FIRs for
    /// @param[in] i_rc return code from the IPL substep
    /// @return FAPI2_RC_SUCCESS iff ok
    /// @note This procedure should be called when a failing RC is received from SPPE draminit or draminit_mc chip-ops.
    ///       It will return the original RC if no unmasked FIR could be blamed for the fail, or
    ///       log a recovered error if an unmasked FIR was set and return SUCCESS
    ///
    fapi2::ReturnCode ody_blame_firs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                     const mss::ipl_substep i_substep,
                                     const fapi2::ReturnCode& i_rc)
    {
        fapi2::ReturnCode l_rc(i_rc);
        fapi2::ReturnCode l_scom_error(fapi2::FAPI2_RC_SUCCESS);

        FAPI_INF("Checking for FIRs on %s", mss::c_str(i_target));

        switch (i_substep)
        {
            case mss::ipl_substep::DRAMINIT_MC:
                l_rc = mss::check::hostboot_fir_or_pll_fail<mss::mc_type::ODYSSEY, mss::check::firChecklist::CCS>(i_target, l_rc,
                        l_scom_error);
                break;

            default:
                // If we're passed an unknown substep, just return the incoming RC
                break;
        }

        // If we took a scom error while checking FIRs, return that
        if (l_scom_error != fapi2::FAPI2_RC_SUCCESS)
        {
            return l_scom_error;
        }

        // Else return the resulting RC (the original bad RC if no FIRs blamed or SUCCESS if we found a FIR to blame)
        return l_rc;
    }

}
