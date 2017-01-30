/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_memdiag.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file p9_mss_memdiag.C
/// @brief Mainstore pattern testing
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mss_memdiag.H>

#include <lib/utils/poll.H>
#include <lib/utils/find.H>
#include <lib/utils/count_dimm.H>
#include <lib/mcbist/address.H>
#include <lib/mcbist/memdiags.H>
#include <lib/mcbist/mcbist.H>
#include <lib/mc/port.H>
#include <lib/ecc/ecc.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_SYSTEM;
using fapi2::TARGET_TYPE_MCA;

extern "C"
{
    ///
    /// @brief Pattern test the DRAM
    /// @param[in] i_target the McBIST of the ports of the dram you're training
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode p9_mss_memdiag( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
    {
        FAPI_INF("Start memdiag");

        // If there are no DIMM we don't need to bother. In fact, we can't as we didn't setup
        // attributes for the PHY, etc.
        if (mss::count_dimm(i_target) == 0)
        {
            FAPI_INF("... skipping mem_diags %s - no DIMM ...", mss::c_str(i_target));
            return fapi2::FAPI2_RC_SUCCESS;
        }

        uint8_t is_sim = false;
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<TARGET_TYPE_SYSTEM>(), is_sim) );

        // Read the bad_dq_bitmap attribute and place corresponding symbol and chip marks
        for (const auto& l_mca : mss::find_targets<TARGET_TYPE_MCA>(i_target))
        {
            fapi2::buffer<uint8_t> l_repairs_applied;
            fapi2::buffer<uint8_t> l_repairs_exceeded;
            std::vector<uint64_t> l_ranks;

            FAPI_TRY( mss::restore_repairs( l_mca, l_repairs_applied, l_repairs_exceeded) );

            // assert if we have exceeded the allowed repairs
            for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_mca))
            {
                FAPI_ASSERT( !(l_repairs_exceeded.getBit(mss::index(l_dimm))),
                             fapi2::MSS_MEMDIAGS_REPAIRS_EXCEEDED().set_TARGET(l_dimm),
                             "p9_mss_memdiag bad bit repairs exceeded %s", mss::c_str(l_dimm) );
            }

#ifdef __HOSTBOOT_MODULE
            // assert if both chip and symbol marks exist for any given rank
            FAPI_TRY( mss::rank::ranks(l_mca, l_ranks) );

            for (const auto l_rank : l_ranks)
            {
                if (l_repairs_applied.getBit(l_rank))
                {
                    uint64_t l_galois = 0;
                    mss::states l_confirmed = mss::NO;
                    // check for chip mark in hardware mark store
                    FAPI_TRY( mss::ecc::get_hwms(l_mca, l_rank, l_galois, l_confirmed) );

                    if (l_confirmed)
                    {
                        auto l_type = mss::ecc::fwms::mark_type::CHIP;
                        auto l_region = mss::ecc::fwms::mark_region::DISABLED;
                        auto l_addr = mss::mcbist::address(0);
                        // check for symbol mark in firmware mark store
                        FAPI_TRY( mss::ecc::get_fwms(l_mca, l_rank, l_galois, l_type, l_region, l_addr) );

                        FAPI_ASSERT( l_region == mss::ecc::fwms::mark_region::DISABLED,
                                     fapi2::MSS_MEMDIAGS_CHIPMARK_AND_SYMBOLMARK().set_TARGET(l_mca).set_RANK(l_rank),
                                     "p9_mss_memdiag both chip mark and symbol mark on rank %d: %s", l_rank, mss::c_str(l_mca) );
                    }
                }
            }

#endif
        }

        // We start the sf_init (write 0's) and it'll tickle the MCBIST complete FIR. PRD will see that
        // and start a background scrub.
        FAPI_TRY( memdiags::sf_init(i_target, mss::mcbist::PATTERN_0) );

        // If we're in the sim, we want to poll for the FIR bit. I don't think this ever really happens
        // unless we're expressly testing this API.
        if (is_sim)
        {
            // Poll for the fir bit. We expect this to be set ...
            fapi2::buffer<uint64_t> l_status;

            // A small vector of addresses to poll during the polling loop
            const std::vector<mss::poll_probe<fapi2::TARGET_TYPE_MCBIST>> l_probes =
            {
                {i_target, "mcbist current address", MCBIST_MCBMCATQ},
            };

            mss::poll_parameters l_poll_parameters;
            bool l_poll_results = mss::poll(i_target, MCBIST_MCBISTFIRQ, l_poll_parameters,
                                            [&l_status](const size_t poll_remaining,
                                                    const fapi2::buffer<uint64_t>& stat_reg) -> bool
            {
                FAPI_DBG("mcbist firq 0x%llx, remaining: %d", stat_reg, poll_remaining);
                l_status = stat_reg;
                return l_status.getBit<MCBIST_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>() == true;
            },
            l_probes);

            FAPI_ASSERT( l_poll_results == true,
                         fapi2::MSS_MEMDIAGS_SUPERFAST_INIT_FAILED_TO_INIT().set_TARGET(i_target),
                         "p9_mss_memdiags timedout %s", mss::c_str(i_target) );
        }

    fapi_try_exit:
        FAPI_INF("End memdiag");
        return fapi2::current_err;
    }
}
