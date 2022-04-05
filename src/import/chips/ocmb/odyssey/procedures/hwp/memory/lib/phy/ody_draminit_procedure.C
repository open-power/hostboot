/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/ody_draminit_procedure.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
/// @file ody_draminit_procedure.C
/// @brief Odyssey draminit procedure
/// @note Using a separate file as simulation might need a different draminit procedure for now
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <generic/memory/lib/utils/find.H>

#include <lib/phy/ody_draminit_utils.H>
#include <lib/phy/ody_phy_utils.H>

namespace mss
{
namespace ody
{

///
/// @brief Runs draminit
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Assumes PHY init has already been run
///
fapi2::ReturnCode draminit(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    // 1. Loads the IMEM Memory (instructions)
    // TODO:ZEN:MST-1561 Create code to load IMEM, DMEM, and message block onto Synopsys PHY

    // 2. Loads the DMEM Memory (data)
    // TODO:ZEN:MST-1561 Create code to load IMEM, DMEM, and message block onto Synopsys PHY

    // 3. Configures and loads the message block
    // TODO:ZEN:MST-1561 Create code to load IMEM, DMEM, and message block onto Synopsys PHY

    // 4. Starts training
    FAPI_TRY(mss::ody::phy::start_training(i_target));

    // 5. Processes and handles training messages (aka poll for completion)
    // TODO:ZEN:MST-1542 Add base code and control for Synopsys mailbox interaction

    // 6. Cleans up after training
    FAPI_TRY(mss::ody::phy::cleanup_training(i_target));

    // 7. Read the data structure and set attributes
    // TODO:ZEN:MST-1567 Create code to process data from the Synopsys message block

    // 8. Error handling
    // TODO:ZEN:MST-1568 Add Odyssey draminit error processing

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Runs draminit
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Assumes PHY init has already been run
///
fapi2::ReturnCode draminit(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    for(const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        // Note: This will need to be updated to allow training to fail on one port but continue on the second
        FAPI_TRY(draminit(l_port));
    }

    // Blame FIRs and unmask FIRs (done on the OCMB chip level)
    // TODO:ZEN:MST-1530 Specialize unmask::after_draminit_training for Odyssey

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace ody
} // namespace mss