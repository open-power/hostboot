/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/p9_mss_memdiag.C $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file p9_mss_memdiag.C
/// @brief Mainstore pattern testing
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mss_memdiag.H>

#include <lib/utils/poll.H>
#include <lib/mcbist/address.H>
#include <lib/mcbist/memdiags.H>
#include <lib/mcbist/mcbist.H>

using fapi2::TARGET_TYPE_MCBIST;

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

        FAPI_TRY( memdiags::sf_init(i_target, mss::mcbist::PATTERN_0) );

        // TODO RTC:153951
        // Remove the polling when the attention bits are hooked up
        {
            // Poll for the fir bit. We expect this to be set ...
            fapi2::buffer<uint64_t> l_status;

            // A small vector of addresses to poll during the polling loop
            static const std::vector<mss::poll_probe<fapi2::TARGET_TYPE_MCBIST>> l_probes =
            {
                {i_target, "mcbist current address", MCBIST_MCBMCATQ},
            };

            mss::poll_parameters l_poll_parameters;
            bool l_poll_results = mss::poll(i_target, MCBIST_MCBISTFIRQ, l_poll_parameters,
                                            [&l_status](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
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
