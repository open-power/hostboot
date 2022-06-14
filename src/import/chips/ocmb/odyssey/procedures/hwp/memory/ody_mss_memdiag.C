/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_mss_memdiag.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
/// @file ody_mss_memdiag.C
/// @brief HW Procedure pattern testing
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <ody_mss_memdiag.H>
#include <lib/dimm/ody_rank.H>
#include <lib/mcbist/ody_mcbist_traits.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/conversions.H>
#include <generic/memory/lib/utils/find.H>
#include <mss_odyssey_attribute_getters.H>
#include <lib/mc/ody_port_traits.H>
#include <lib/shared/ody_consts.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_memdiags.H>
#include <generic/memory/lib/utils/mc/gen_mss_port.H>
#include <generic/memory/lib/utils/mc/gen_mss_restore_repairs.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

extern "C"
{
    ///
    /// @brief Initializes memory and sets firs
    /// @param[in] i_target OCMB Chip
    /// @return FAPI2_RC_SUCCESS iff ok
    /// @note This is a cronus only procedure. PRD handles memdiags in hostboot
    ///
    fapi2::ReturnCode ody_mss_memdiag( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
    {
        uint8_t l_post_memdiags_subtest = 0;

        FAPI_INF("Start ody_mss_memdiag on: %s", mss::c_str( i_target ));
        FAPI_TRY(mss::memdiags::mss_initialize_memory<mss::mc_type::ODYSSEY>(i_target));

        FAPI_TRY(mss::attr::get_post_memdiags_read_subtest(i_target, l_post_memdiags_subtest));

        // Perform subtest if attribute is set to
        if (l_post_memdiags_subtest == fapi2::ENUM_ATTR_MSS_POST_MEMDIAGS_READ_SUBTEST_ENABLE)
        {
            FAPI_TRY(mss::memdiags::perform_read_only_subtest<mss::mc_type::ODYSSEY>(i_target));

            // Polls for completion here to avoid issues in future isteps
            FAPI_TRY(mss::memdiags::mss_async_polling_loop<mss::mc_type::ODYSSEY>(i_target));

            // Turn off FIFO mode again
            // Note this is normally done in mss_initialize_memory but
            // the read-only subtest above switches back to FIFO mode
            FAPI_TRY(mss::reset_reorder_queue_settings<mss::mc_type::ODYSSEY>(i_target) );
        }

    fapi_try_exit:
        FAPI_INF("End ody_mss_memdiag on %s", mss::c_str( i_target ));
        return fapi2::current_err;
    }
}
