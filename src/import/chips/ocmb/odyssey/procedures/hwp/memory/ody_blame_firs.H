/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_blame_firs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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
/// @file ody_blame_firs.H
/// @brief Check for FIR bits related to a HWP fail
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _ODY_BLAME_FIRS_
#define _ODY_BLAME_FIRS_

#include <fapi2.H>

namespace mss
{

enum class ipl_substep
{
    OCMB_OMI_SCOMINIT   = 124,
    OMI_TRAIN_CHECK     = 128,
    DRAMINIT            = 132,
    DRAMINIT_MC         = 133
};

} // namespace mss

// Required for Cronus
typedef fapi2::ReturnCode (*ody_blame_firs_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
        const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>>&,
        const mss::ipl_substep,
        bool& );

extern "C"
{

    ///
    /// @brief Check for FIR bits related to a HWP fail
    /// @param[in] i_target OCMB chip
    /// @param[in] i_ports vector of failing MEM_PORT targets
    /// @param[in] i_substep the IPL substep to check FIRs for
    /// @param[out] o_firactive indicates if FIRs were active or not
    /// @return FAPI2_RC_SUCCESS iff ok, otherwise indicates an internal failure
    /// @note This procedure should be called when a failing RC is received from SPPE draminit or draminit_mc chip-ops.
    ///       It will return the original RC if no unmasked FIR could be blamed for the fail, or
    ///       log a recovered error if an unmasked FIR was set and return SUCCESS
    ///
    fapi2::ReturnCode ody_blame_firs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                     const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>>& i_ports,
                                     const mss::ipl_substep i_substep,
                                     bool& o_firactive);

}// extern C
#endif
