/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/mcbist/ody_memdiags.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
/// @file ody_memdiags.C
/// @brief Run and manage the MEMDIAGS engine
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <lib/dimm/ody_rank.H>
#include <lib/mcbist/ody_memdiags.H>
#include <lib/mcbist/ody_mcbist.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <lib/utils/ody_bad_bits.H>


namespace mss
{

///
/// @brief Update bad DQ bits in SPD - Odyssey specialization
/// @param[in] i_target A target representing an ocmb_chip
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode update_bad_bits<mss::mc_type::ODYSSEY>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
{
    for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

        // Get the bad bits from the attribute (read from Odyssey SPPE previously)
        mss::ody::phy::host_bad_bit_interface l_interface(l_dimm, l_rc);
        FAPI_TRY(l_rc);

        // Record the bad bits data into our attribute and SPD
        FAPI_TRY(mss::record_bad_bits(i_target, l_interface));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

namespace memdiags
{

///
/// @brief Helper to encapsualte the setting of multi-port address configurations - Odyssey specialization
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode operation<mss::mc_type::ODYSSEY>::multi_port_addr()
{
    using TT = mcbistTraits<mss::mc_type::ODYSSEY>;

    mss::mcbist::address l_end_of_start_port;
    mss::mcbist::address l_end_of_complete_port(TT::LARGEST_ADDRESS);
    mss::mcbist::address l_start_of_end_port;

    // The last address in the start port is the start address thru the "DIMM range" (all addresses left on this DIMM)
    iv_const.iv_start_address.get_range<mss::mcbist::address::DIMM>(l_end_of_start_port);

    // The first address in the end port is the 0th address of the 0th DIMM on said port.
    // Note the DIMM bit is used as the port select for Odyssey according to the design team
    l_start_of_end_port.set_dimm(iv_const.iv_end_address.get_dimm());

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

    FAPI_INF("last addr in start port 0x%016lx first addr in end port 0x%016lx for " TARGTIDFORMAT,
             uint64_t(l_end_of_start_port), uint64_t(l_start_of_end_port), GENTARGTID(iv_target));

    // We know we have three address configs: start address -> end of DIMM, 0 -> end of DIMM and 0 -> end address.
    FAPI_TRY( mss::mcbist::config_address_range0<mss::mc_type::ODYSSEY>(iv_target, iv_const.iv_start_address,
              l_end_of_start_port) );
    FAPI_TRY( mss::mcbist::config_address_range1<mss::mc_type::ODYSSEY>(iv_target, mss::mcbist::address(),
              l_end_of_complete_port) );
    FAPI_TRY( mss::mcbist::config_address_range2<mss::mc_type::ODYSSEY>(iv_target, l_start_of_end_port,
              iv_const.iv_end_address) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configures all subtests for a multiport init - Odyssey specialization
/// @param[in] i_dimms a vector of DIMM targets
///
template<>
void operation<mss::mc_type::ODYSSEY>::configure_multiport_subtests(
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
    FAPI_INF("Adding subtests for %d DIMMs on " TARGTIDFORMAT, i_dimms.size(), GENTARGTID(iv_target));

    for (const auto& l_dimm : i_dimms)
    {
        // The port/DIMM value for this DIMM is a three-bit field the right-most is the port's index.
        // For Odyssey, The first two bits are reserved
        // We use this to decide how to process this dimm/port
        // Due to this combination, the port/DIMM ID is just the relative position of the port from the MCBIST
        const auto l_port = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(l_dimm);

        // The port and DIMM indexes are needed to set the addressing scheme below - compute them here
        const auto l_portdimm_this_dimm = mss::relative_pos<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(l_port);

        FAPI_INF(TARGTIDFORMAT " port/dimm %d, port/dimm start: %d", GENTARGTID(iv_target), l_portdimm_this_dimm,
                 l_portdimm_start_address);

        // No need to process DIMM which are lower as they're not between the start and the end of the port.
        if (l_portdimm_this_dimm < l_portdimm_start_address)
        {
            FAPI_INF(TARGTIDFORMAT " Skipping adding the subtest for this DIMM %lu < %lu", GENTARGTID(l_dimm), l_portdimm_this_dimm,
                     l_portdimm_start_address);
            continue;
        }

        // Ok, we're gonna need to push on a subtest.
        auto l_subtest = iv_subtest;

        // Again, the DIMM select is used for the port on Odyssey
        // ZEN:MST-2063 Update to the API that handles port/DIMM seleciton in maint addressing
        l_subtest.enable_dimm(l_portdimm_this_dimm);

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
        FAPI_INF("adding subtest for " TARGTIDFORMAT " (port: %d)", GENTARGTID(iv_target), l_portdimm_this_dimm);
    }

    FAPI_INF("Total subtests added: %d for " TARGTIDFORMAT, iv_program.iv_subtests.size(), GENTARGTID(iv_target));
}

///
/// @brief memdiags multi-port init for specific chip - Odyssey specialization
/// Initializes common sections. Broken out rather than the base class ctor to enable checking return codes
/// in subclassed constructors more easily.
/// @return FAPI2_RC_SUCCESS iff everything ok
///
template <>
fapi2::ReturnCode operation<mss::mc_type::ODYSSEY>::multi_port_init_internal()
{
    FAPI_INF("multi-port init internal for " TARGTIDFORMAT, GENTARGTID(iv_target));


    // Let's assume we are going to send out all subtest unless we are in broadcast mode,
    // where we only send up to 2 subtests under an MCA ( 1 for each DIMM) which is why no const
    auto l_dimms = mss::find_targets<fapi2::TARGET_TYPE_DIMM>(iv_target);

    // Get the port/DIMM information for the addresses. This is an integral value which allows us to index
    // all the DIMM across a controller.
    const uint64_t l_portdimm_start_address = iv_const.iv_start_address.get_port_dimm();
    const uint64_t l_portdimm_end_address = iv_const.iv_end_address.get_port_dimm();

    FAPI_INF(TARGTIDFORMAT " start port/dimm: %d end port/dimm: %d", GENTARGTID(iv_target), l_portdimm_start_address,
             l_portdimm_end_address);

    // If start address == end address we can handle the single port case simply
    if (l_portdimm_start_address == l_portdimm_end_address)
    {
        // Single port case; simple.
        return single_port_init();
    }

    FAPI_ASSERT( l_portdimm_start_address < l_portdimm_end_address,
                 fapi2::ODY_START_ADDR_BIGGER_THAN_END_ADDR()
                 .set_MC_TARGET(iv_target)
                 .set_START_ADDRESS(l_portdimm_start_address)
                 .set_END_ADDRESS(l_portdimm_end_address),
                 "Start address %d larger than end address %d for " TARGTIDFORMAT,
                 l_portdimm_start_address, l_portdimm_end_address, GENTARGTID(iv_target));

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
        return a.get_dimm() < b.get_dimm();
    });

    // Initialize the common sections
    FAPI_TRY( base_init() );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to get the subtest to run continuous scrub for this memory controller type - Odyssey specialization
/// @return The subtest used to run continuous scrub
///
template<>
mss::mcbist::subtest_t<mss::mc_type::ODYSSEY> get_scrub_subtest<mss::mc_type::ODYSSEY>()
{
    return mss::mcbist::steer_subtest<mss::mc_type::ODYSSEY>();
}

///
/// @brief Mask MCBISTFIRQ[MCBIST_PROGRAM_COMPLETE] and return the original mask value - specialization for Odyssey
/// @param[in] i_target the target
/// @param[out] o_fir_mask_save the original mask value to be restored later
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode mask_program_complete<mss::mc_type::ODYSSEY>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    fapi2::buffer<uint64_t>& o_fir_mask_save )
{
    using TT = mss::mcbistTraits<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>;

    fapi2::buffer<uint64_t> l_fir_mask;

    // Save the masked/unmasked state of MCBIST_PROGRAM_COMPLETE so it can be restored later
    o_fir_mask_save.flush<0>();
    FAPI_TRY( mss::getScom(i_target, scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRMASK_RW_WCLEAR, l_fir_mask) );
    o_fir_mask_save.writeBit<TT::MCB_PROGRAM_COMPLETE>(l_fir_mask.getBit<TT::MCB_PROGRAM_COMPLETE>());

    // Mask the FIR
    l_fir_mask.flush<0>();
    l_fir_mask.setBit<TT::MCB_PROGRAM_COMPLETE>();
    FAPI_TRY( mss::putScom(i_target, scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRMASK_WO_OR, l_fir_mask) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Restore MCBISTFIRQ[MCBIST_PROGRAM_COMPLETE] mask value and clear the FIR - specialization for Odyssey
/// @param[in] i_target the target
/// @param[in] i_fir_mask_save the original mask value to be restored
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode clear_and_restore_program_complete<mss::mc_type::ODYSSEY>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const fapi2::buffer<uint64_t>& i_fir_mask_save )
{
    using TT = mss::mcbistTraits<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>;

    fapi2::buffer<uint64_t> l_fir;

    // Clear the FIR
    // The FIRQ register for Odyssey has a write clear functionality
    // Any bit set to a 1 will clear out the FIR in this register
    l_fir.setBit<TT::MCB_PROGRAM_COMPLETE>();
    FAPI_TRY( mss::putScom(i_target, TT::FIRQ_REG, l_fir) );

    // Then restore the mask value
    if (i_fir_mask_save.getBit<TT::MCB_PROGRAM_COMPLETE>())
    {
        FAPI_TRY( mss::putScom(i_target, scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRMASK_WO_OR, l_fir) );
    }
    else
    {
        FAPI_TRY( mss::putScom(i_target, scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRMASK_RW_WCLEAR, l_fir) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // memdiags
} // namespace mss
