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
#include <lib/utils/count_dimm.H>
#include <lib/mcbist/address.H>
#include <lib/mcbist/memdiags.H>
#include <lib/mcbist/mcbist.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_SYSTEM;

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
