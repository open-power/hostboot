/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/mcbist/memdiags.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
/// @file memdiags.C
/// @brief Run and manage the MEMDIAGS engine
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/shared/nimbus_defaults.H>

#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <lib/mcbist/memdiags.H>
#include <lib/mcbist/mcbist.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/poll.H>


namespace mss
{

namespace memdiags
{

///
/// @brief Helper to encapsualte the setting of multi-port address configurations
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode operation<DEFAULT_MC_TYPE>::multi_port_addr()
{
    using TT = mcbistTraits<>;

    mss::mcbist::address l_end_of_start_port;
    mss::mcbist::address l_end_of_complete_port(TT::LARGEST_ADDRESS);
    mss::mcbist::address l_start_of_end_port;

    // The last address in the start port is the start address thru the "DIMM range" (all addresses left on this DIMM)
    iv_const.iv_start_address.get_range<mss::mcbist::address::DIMM>(l_end_of_start_port);

    // The first address in the end port is the 0th address of the 0th DIMM on said port.
    l_start_of_end_port.set_port(iv_const.iv_end_address.get_port());

    // Before we do anything else, fix up the address for sim. The end address given has to be limited so
    // we don't run too many cycles. Also, if there are intermediate ports the end addresses of those ports
    // need to be limited as well - they override the end address of a complete port (which is otherwise the
    // largest address.)
    if (iv_sim)
    {
        iv_const.iv_start_address.get_sim_end_address(l_end_of_start_port);
        mss::mcbist::address().get_sim_end_address(l_end_of_complete_port);
        l_start_of_end_port.get_sim_end_address(iv_const.iv_end_address);
    }

    FAPI_INF("last addr in start port 0x%016lx first addr in end port 0x%016lx for %s",
             uint64_t(l_end_of_start_port), uint64_t(l_start_of_end_port), mss::c_str(iv_target));

    // We know we have three address configs: start address -> end of DIMM, 0 -> end of DIMM and 0 -> end address.
    FAPI_TRY( mss::mcbist::config_address_range0(iv_target, iv_const.iv_start_address, l_end_of_start_port) );
    FAPI_TRY( mss::mcbist::config_address_range1(iv_target, mss::mcbist::address(), l_end_of_complete_port) );
    FAPI_TRY( mss::mcbist::config_address_range2(iv_target, l_start_of_end_port, iv_const.iv_end_address) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configures all subtests for a multiport init
/// @param[in] i_dimms a vector of DIMM targets
///
template<>
void operation<DEFAULT_MC_TYPE>::configure_multiport_subtests(
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_DIMM>>& i_dimms)
{
    // Constexpr's to beautify the code
    constexpr uint64_t FIRST_ADDRESS = 0;
    constexpr uint64_t MIDDLE_ADDRESS = 1;
    constexpr uint64_t LAST_ADDRESS = 2;

    // Get the port/DIMM information for the addresses. This is an integral value which allows us to index
    // all the DIMM across a controller.
    const uint64_t l_portdimm_start_address = iv_const.iv_start_address.get_port_dimm();
    const uint64_t l_portdimm_end_address = iv_const.iv_end_address.get_port_dimm();

    // Loop over all the DIMM on this MCBIST. Check the port/DIMM value for what to do.
    FAPI_INF("Adding subtests for %d DIMMs on %s", i_dimms.size(), mss::c_str(iv_target));

    for (const auto& d : i_dimms)
    {
        // The port/DIMM value for this DIMM is a three-bit field where the left-two are the relative position of the port
        // and the right-most is the DIMM's index. We use this to decide how to process this dimm
        // Due to this combination, the port/DIMM ID is just the relative position of the DIMM from the MCBIST
        const uint64_t l_portdimm_this_dimm = mss::relative_pos<TARGET_TYPE_MCBIST>(d);
        const auto l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(d);

        // The port and DIMM indexes are needed to set the addressing scheme below - compute them here
        const auto l_port_for_dimm = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(l_mca);
        const auto l_dimm_index = mss::index(d);

        FAPI_INF("%s port/dimm %d, port/dimm start: %d", mss::c_str(iv_target), l_portdimm_this_dimm, l_portdimm_start_address);

        // No need to process DIMM which are lower as they're not between the start and the end of the port.
        if (l_portdimm_this_dimm < l_portdimm_start_address)
        {
            FAPI_INF("%s Skipping adding the subtest for this DIMM %lu < %lu", mss::c_str(d), l_portdimm_this_dimm,
                     l_portdimm_start_address);
            continue;
        }

        // Ok, we're gonna need to push on a subtest.
        auto l_subtest = iv_subtest;

        l_subtest.enable_port(l_port_for_dimm);
        l_subtest.enable_dimm(l_dimm_index);

        // Ok this is the starting point. We know it's address selection is config0
        if (l_portdimm_this_dimm == l_portdimm_start_address)
        {
            l_subtest.change_addr_sel(FIRST_ADDRESS);
        }

        // If this DIMM represents the end, we know that's address config2
        else if (l_portdimm_this_dimm == l_portdimm_end_address)
        {
            l_subtest.change_addr_sel(LAST_ADDRESS);
        }

        // Otherwise, we're someplace in between - address config1
        else
        {
            l_subtest.change_addr_sel(MIDDLE_ADDRESS);
        }

        iv_program.iv_subtests.push_back(l_subtest);
        FAPI_INF("adding subtest for %s (port: %d dimm %d dimm relative position to MCBIST: )", mss::c_str(iv_target),
                 l_port_for_dimm, l_dimm_index, l_portdimm_this_dimm);
    }

    FAPI_INF("Total subtests added: %d for %s", iv_program.iv_subtests.size(), mss::c_str(iv_target));
}

///
/// @brief Checks that the starting port/dimm address is in range for broadcast mode - helper for testing
/// @param[in] i_targets a vector of MCA targets
/// @param[in] i_start_addr the starting port_dimm select address
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode broadcast_mode_start_address_check_helper(
    const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCA> >& i_targets,
    const uint64_t i_start_addr)
{
    if( i_targets.size() == 0 )
    {
        // Programming bug, multi_port_init check assures we shouldn't get here
        FAPI_INF("No ports passed in");
        fapi2::Assert(false);
    }

    // The check makes for bugs of not hitting the first port or hitting the middle dimm's multiple times
    // since multi_port_init loops through all valid DIMM's and plops the addresses in
    const auto l_first_configured_mca = i_targets[0];
    const auto l_dimms = mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_first_configured_mca);
    const auto l_mcbist = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(l_first_configured_mca);
    const size_t l_dimms_under_mca = mss::count_dimm(l_first_configured_mca);

    if( l_dimms.size() == 0)
    {
        FAPI_INF("No DIMMs under %s", mss::c_str(l_first_configured_mca));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_INF("%d DIMMs under %s", l_dimms_under_mca, mss::c_str(l_first_configured_mca));

    // Bomb out if we have incorrect addresses
    // The following assert catches the error incorrect address error earlier
    // It also keeps the error meaningful with an invalid address callout rather than a generic MCBIST error callout

    // Note: we are guaranteed to have at least one DIMM, as we are not broadcast capable without DIMM's
    // The ports are also required to have the same number and type of DIMM's to be broadcast capable
    // As such, we can be guaranteed that we have at least one DIMM below
    const uint64_t l_port_dimm_offset = l_dimms_under_mca - 1;
    const uint64_t l_portdimm_this_dimm_min = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(l_dimms[0]);
    const uint64_t l_portdimm_this_dimm_max = l_portdimm_this_dimm_min + l_port_dimm_offset;

    FAPI_INF("Start port_dimm address %d, %s first configured mca start address %d",
             i_start_addr,
             mss::c_str(l_first_configured_mca),
             l_portdimm_this_dimm_min);


    // Checking that we are received a valid address (port_dimm) that is no less than the first configured port_dimm
    // on this MCBIST. This vector is sorted to make sure this is true.
    // Note: cronus always passes in a 0 address, so we need to support an address that is on or before this port
    FAPI_ASSERT( i_start_addr <= l_portdimm_this_dimm_max,
                 fapi2::MSS_MEMDIAGS_BCMODE_INVALID_ADDRESS()
                 .set_MCA_TARGET(l_first_configured_mca)
                 .set_START_ADDRESS(i_start_addr)
                 .set_MCA_START_ADDRESS(l_portdimm_this_dimm_min),
                 "%s address (%lu) is not the MCBIST's first configured port address (%lu)",
                 mss::c_str(l_mcbist), i_start_addr, l_portdimm_this_dimm_min);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Start address port dimm check
/// @param[in] i_target the MCBIST target
/// @param[in] i_start_addr the starting port_dimm select address
/// @param[out] o_dimms DIMM(s) associated with the first valid MCA
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode broadcast_mode_start_address_check(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
        const uint64_t i_start_addr,
        std::vector< fapi2::Target<fapi2::TARGET_TYPE_DIMM> >& o_dimms)
{
    o_dimms.clear();
    auto l_mcas = mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target);

    std::sort(l_mcas.begin(), l_mcas.end(),
              [](const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_lhs,
                 const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_rhs) -> bool
    {
        return mss::pos(i_lhs) < mss::pos(i_rhs);
    });

    FAPI_TRY( broadcast_mode_start_address_check_helper(l_mcas, i_start_addr),
              "Failed broadcast_mode_start_address_check_helper for %s", mss::c_str(i_target));

    // Since sorted the vector of MCAs, the 1st index is the first
    // configured MCA under this MCBIST.
    o_dimms = mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_mcas[0]);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief memdiags multi-port init
/// Initializes common sections. Broken out rather than the base class ctor to enable checking return codes
/// in subclassed constructors more easily.
/// @return FAPI2_RC_SUCCESS iff everything ok
///
template<>
fapi2::ReturnCode operation<DEFAULT_MC_TYPE>::multi_port_init_internal()
{
    FAPI_INF("multi-port init internal for %s", mss::c_str(iv_target));


    // Let's assume we are going to send out all subtest unless we are in broadcast mode,
    // where we only send up to 2 subtests under an MCA ( 1 for each DIMM) which is why no const
    auto l_dimms = mss::find_targets<fapi2::TARGET_TYPE_DIMM>(iv_target);

    // Get the port/DIMM information for the addresses. This is an integral value which allows us to index
    // all the DIMM across a controller.
    const uint64_t l_portdimm_start_address = iv_const.iv_start_address.get_port_dimm();
    const uint64_t l_portdimm_end_address = iv_const.iv_end_address.get_port_dimm();

    FAPI_INF("%s start port/dimm: %d end port/dimm: %d", mss::c_str(iv_target), l_portdimm_start_address,
             l_portdimm_end_address);

    // If start address == end address we can handle the single port case simply
    if (l_portdimm_start_address == l_portdimm_end_address)
    {
        // Single port case; simple.
        return single_port_init();
    }

    FAPI_ASSERT( l_portdimm_start_address < l_portdimm_end_address,
                 fapi2::MSS_START_ADDR_BIGGER_THAN_END_ADDR()
                 .set_TARGET(iv_target)
                 .set_START_ADDRESS(l_portdimm_start_address)
                 .set_END_ADDRESS(l_portdimm_end_address),
                 "Start address %d larger than end address %d for %s",
                 l_portdimm_start_address, l_portdimm_end_address, mss::c_str(iv_target));

// Determine which ports are functional and whether we can broadcast to them
    // If we're in broadcast mode, PRD sends DIMM 0/1 of the first functional and configured port,
    // and we then run all ports in parallel (ports set in subtest config)
    if( mss::mcbist::is_broadcast_capable(iv_target) == mss::YES )
    {
        const auto l_prev_size = l_dimms.size();
        FAPI_TRY( broadcast_mode_start_address_check(iv_target, l_portdimm_start_address, l_dimms) );

        FAPI_INF("Updated %d DIMMs on the MCBIST to %d on the first configured MCA due to broadcast mode for %s",
                 l_prev_size, l_dimms.size(), mss::c_str(iv_target));
    }

    // Configures all subtests under an MCBIST
    // If we're here we know start port < end port. We want to run one subtest (for each DIMM) from start_address
    // to the max range of the start address port, then one subtest (for each DIMM) for each port between the
    // start/end ports and one test (for each DIMM) from the start of the end port to the end address.

    // Setup the address configurations
    FAPI_TRY( multi_port_addr() );

    // We need to do three things here. One is to create a subtest which starts at start address and runs to
    // the end of the port. Next, create subtests to go from the start of the next port to the end of the
    // next port. Last we need a subtest which goes from the start of the last port to the end address specified
    // in the end address. Notice this may mean one subtest (start and end are on the same port) or it might
    // mean two subtests (start is one one port, end is on the next.) Or it might mean three or more subtests.

    // Configure multiport subtests, can be all subtests for the DIMMs under an MCBIST,
    // or just the DIMMs under the first configured MCA if in broadcast mode.
    configure_multiport_subtests(l_dimms);

    // Here's an interesting problem. PRD (and others maybe) expect the operation to proceed in address-order.
    // That is, when PRD finds an address it stops on, it wants to continue from there "to the end." That means
    // we need to keep the subtests sorted, otherwise PRD could pass one subtest come upon a fail in a subsequent
    // subtest and re-test something it already passed. So we sort the resulting iv_subtest vector by port/DIMM
    // in the subtest.
    std::sort(iv_program.iv_subtests.begin(), iv_program.iv_subtests.end(),
              [](const decltype(iv_subtest)& a, const decltype(iv_subtest)& b) -> bool
    {
        const uint64_t l_a_portdimm = (a.get_port() << 1) | a.get_dimm();
        const uint64_t l_b_portdimm = (b.get_port() << 1) | b.get_dimm();

        return l_a_portdimm < l_b_portdimm;
    });

    // Initialize the common sections
    FAPI_TRY( base_init() );

    // And configure broadcast mode if required
    FAPI_TRY(mss::mcbist::configure_broadcast_mode(iv_target, iv_program));

fapi_try_exit:
    return fapi2::current_err;
}


} // namespace memdiags

} // namespace mss
