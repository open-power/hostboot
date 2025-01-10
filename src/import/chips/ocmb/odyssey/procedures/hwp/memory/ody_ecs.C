/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_ecs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2025                        */
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
/// @file ody_ecs.C
/// @brief Run DDR5 DRAM error Check Scrub manufacturing test
///
// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot


#include <fapi2.H>
#include <ody_ecs.H>
#include <lib/ccs/ody_error_check_scrub.H>

extern "C"
{
    ///
    /// @brief Run DDR5 DRAM error Check Scrub manufacturing test
    /// @note This gets called by PRD when the appropriate MFG_FLAG is set
    /// @param[in] i_target OCMB chip
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode ody_ecs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
    {
        FAPI_INF_NO_SBE(TARGTIDFORMAT " ody_ecs: Entering...", TARGTID);

        std::vector<mss::rank::info<mss::mc_type::ODYSSEY>> l_vec_ranks;
        FAPI_TRY(mss::rank::ranks_on_mc<mss::mc_type::ODYSSEY>(i_target, l_vec_ranks));

        // Run ECS test
        FAPI_TRY( mss::ccs::ody::run_ecs(l_vec_ranks), TARGTIDFORMAT "Failed ody_ecs", TARGTID );


        FAPI_INF_NO_SBE(TARGTIDFORMAT " ody_ecs: Exiting...", TARGTID);

    fapi_try_exit:
        return fapi2::current_err;
    }

}
