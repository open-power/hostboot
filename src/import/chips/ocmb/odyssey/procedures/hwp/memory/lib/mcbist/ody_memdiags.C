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

#include <lib/shared/ody_consts.H>
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
#ifndef __PPE__
///
/// @brief Helper to encapsualte the setting of multi-port address configurations - Odyssey specialization
/// @return FAPI2_RC_SUCCESS iff ok
/// @note due to an erratum on Odyssey we need to run a subtest per srank
///
template<>
fapi2::ReturnCode operation<mss::mc_type::ODYSSEY>::multi_port_addr()
{
    constexpr uint8_t MAX_SUBTEST_ADDR_PAIRS = 4;

    // Get the port/DIMM information for the addresses. This is what we need to use to set up the MCBMR address select
    // bit, and decide if we need to duplicate subtests across ports.
    // For Odyssey, The port bits are reserved and we use the DIMM bit to select the port
    const uint64_t l_port_start_address = iv_const.iv_start_address.get_port();
    const uint64_t l_port_end_address = iv_const.iv_end_address.get_port();

    // <start, end> address pairs
    std::vector<mss::pair<mss::mcbist::address<mss::mc_type::ODYSSEY>, mss::mcbist::address<mss::mc_type::ODYSSEY>>>
    l_addrs;

    bool l_port_exists[mss::ody::MAX_PORT_PER_OCMB] = {};

    for (const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(iv_target))
    {
        l_port_exists[mss::relative_pos<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(l_port)] = true;

        // Only need to build address ranges for one port because we reuse them between ports
        if (l_addrs.size() > 0)
        {
            continue;
        }

        uint8_t l_attr_num_mranks[mss::ody::MAX_DIMM_PER_PORT] = {};
        uint8_t l_attr_num_lranks[mss::ody::MAX_DIMM_PER_PORT] = {};
        uint8_t l_num_mranks = 0;
        uint8_t l_num_sranks = 0;

        FAPI_TRY(mss::attr::get_num_master_ranks_per_dimm(l_port, l_attr_num_mranks));
        FAPI_TRY(mss::attr::get_logical_ranks_per_dimm(l_port, l_attr_num_lranks));

        l_num_mranks = (l_attr_num_mranks[0] == 0) ? 1 : l_attr_num_mranks[0];
        l_num_sranks = l_attr_num_lranks[0] / l_attr_num_mranks[0];

        // First set up our address ranges to cover the full range of addresses for all the mranks/sranks
        for (uint8_t l_mrank = 0; l_mrank < l_num_mranks; l_mrank++)
        {
            for (uint8_t l_srank = 0; l_srank < l_num_sranks; l_srank++)
            {
                mss::mcbist::address<mss::mc_type::ODYSSEY> l_start_addr = 0;
                mss::mcbist::address<mss::mc_type::ODYSSEY> l_end_addr = 0;

                // Each range will cover a single srank (or the full mrank if we only have one srank)
                if (l_num_sranks > 1)
                {
                    l_start_addr.get_srank_range(0, 0, l_mrank, l_srank, l_start_addr, l_end_addr);
                }
                else
                {
                    l_start_addr.get_mrank_range(0, 0, l_mrank, l_start_addr, l_end_addr);
                }

                // Fix up the end address for sim. The end address given has to be limited so
                // we don't run too many cycles
                if (iv_sim)
                {
                    l_start_addr.get_sim_end_address(l_end_addr);
                }

                // Omit the below trace for PPE because splitting the uint64s would result in too many formatters
                FAPI_INF_NO_SBE(TARGTIDFORMAT " mrank,srank %d,%d start addr 0x%016lx",
                                GENTARGTID(iv_target), l_mrank, l_srank, uint64_t(l_start_addr));
                FAPI_INF_NO_SBE(TARGTIDFORMAT " mrank,srank %d,%d end addr 0x%016lx",
                                GENTARGTID(iv_target), l_mrank, l_srank, uint64_t(l_end_addr));

                mss::pair<mss::mcbist::address<mss::mc_type::ODYSSEY>, mss::mcbist::address<mss::mc_type::ODYSSEY>> l_pair =
                {l_start_addr, l_end_addr};

                l_addrs.emplace_back(l_pair);
            }
        }

        // Assert if our vector is larger than the number of supported address pairs (4)
        FAPI_ASSERT( l_addrs.size() <= MAX_SUBTEST_ADDR_PAIRS,
                     fapi2::ODY_TOO_MANY_RANKS_FOR_SUBTEST_SUPPORT()
                     .set_MC_TARGET(iv_target)
                     .set_RANK_COUNT(l_addrs.size())
                     .set_MAX_RANK_COUNT(MAX_SUBTEST_ADDR_PAIRS),
                     "Number of mranks/sranks (%d) greater than number of supported addr pairs for subtests (%d) for " TARGTIDFORMAT,
                     l_addrs.size(), MAX_SUBTEST_ADDR_PAIRS, GENTARGTID(iv_target));

    }

    // Call config_address_rangeN for each address pair
    if (l_addrs.size() > 0)
    {
        FAPI_TRY( mss::mcbist::config_address_range0<mss::mc_type::ODYSSEY>(iv_target, l_addrs[0].first, l_addrs[0].second) );
    }

    if (l_addrs.size() > 1)
    {
        FAPI_TRY( mss::mcbist::config_address_range1<mss::mc_type::ODYSSEY>(iv_target, l_addrs[1].first, l_addrs[1].second) );
    }

    if (l_addrs.size() > 2)
    {
        FAPI_TRY( mss::mcbist::config_address_range2<mss::mc_type::ODYSSEY>(iv_target, l_addrs[2].first, l_addrs[2].second) );
    }

    if (l_addrs.size() > 3)
    {
        FAPI_TRY( mss::mcbist::config_address_range3<mss::mc_type::ODYSSEY>(iv_target, l_addrs[3].first, l_addrs[3].second) );
    }

    // Now we create the subtests we need for the requested address range
    for (uint8_t l_addr_count = 0; l_addr_count < l_addrs.size(); l_addr_count++)
    {
        auto l_range_start = l_addrs[l_addr_count].first;
        auto l_range_end = l_addrs[l_addr_count].second;

        // Add subtest for port0 if range is within start/end boundaries and start address is on port0
        if (l_port_exists[0] &&
            (l_port_start_address == 0) &&
            (uint64_t(l_range_start) >= uint64_t(iv_const.iv_start_address)) &&
            (uint64_t(l_range_end) <= uint64_t(iv_const.iv_end_address)))
        {
            auto l_subtest = iv_subtest;

            l_subtest.enable_port(0);

            l_subtest.change_addr_sel(l_addr_count);

            iv_program.iv_subtests.push_back(l_subtest);
            FAPI_DBG("adding subtest for " TARGTIDFORMAT " (port 0)", GENTARGTID(iv_target));
        }

        // Set up range boundaries for port1
        l_range_start.set_port(1);
        l_range_end.set_port(1);

        // Add subtest for port1 if range is within start/end boundaries and end address is on port1
        if (l_port_exists[1] &&
            (l_port_end_address == 1) &&
            (uint64_t(l_range_start) >= uint64_t(iv_const.iv_start_address)) &&
            (uint64_t(l_range_end) <= uint64_t(iv_const.iv_end_address)))
        {
            auto l_subtest = iv_subtest;

            l_subtest.enable_port(1);

            l_subtest.change_addr_sel(l_addr_count);

            iv_program.iv_subtests.push_back(l_subtest);
            FAPI_DBG("adding subtest for " TARGTIDFORMAT " (port 1)", GENTARGTID(iv_target));
        }
    }

    FAPI_INF("Total subtests added: %d for " TARGTIDFORMAT, iv_program.iv_subtests.size(), GENTARGTID(iv_target));

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
    // Nothing to do here since we set up our subtests in multi_port_addr
    return;
}

///
/// @brief memdiags multi-port init for specific chip - Odyssey specialization
/// Initializes common sections. Broken out rather than the base class ctor to enable checking return codes
/// in subclassed constructors more easily.
/// @return FAPI2_RC_SUCCESS iff everything ok
/// @note due to an erratum on Odyssey we need to run a subtest per srank
///
template <>
fapi2::ReturnCode operation<mss::mc_type::ODYSSEY>::multi_port_init_internal()
{
    FAPI_INF("multi-port init internal for " TARGTIDFORMAT, GENTARGTID(iv_target));
    using TT = mss::mcbistTraits<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>;

    // Let's assume we are going to send out all subtest unless we are in broadcast mode,
    // where we only send up to 2 subtests under an MCA ( 1 for each DIMM) which is why no const
    auto l_dimms = mss::find_targets<fapi2::TARGET_TYPE_DIMM>(iv_target);

    // Get the port/DIMM information for the addresses. This is an integral value which allows us to index
    // all the DIMM across a controller.
    const uint64_t l_portdimm_start_address = iv_const.iv_start_address.get_port_dimm();
    const uint64_t l_portdimm_end_address = iv_const.iv_end_address.get_port_dimm();

    FAPI_INF(TARGTIDFORMAT " start port/dimm: %d end port/dimm: %d", GENTARGTID(iv_target), l_portdimm_start_address,
             l_portdimm_end_address);

    FAPI_ASSERT( iv_const.iv_start_address <= iv_const.iv_end_address,
                 fapi2::ODY_START_ADDR_BIGGER_THAN_END_ADDR()
                 .set_MC_TARGET(iv_target)
                 .set_START_ADDRESS(l_portdimm_start_address)
                 .set_END_ADDRESS(l_portdimm_end_address),
                 "Start address %d larger than end address %d for " TARGTIDFORMAT,
                 l_portdimm_start_address, l_portdimm_end_address, GENTARGTID(iv_target));

    // If we're here we know start port/rank < end port/rank. We want to run one subtest from start_address
    // to the max range of the start address port/rank, then one subtest for each port/rank between the
    // start/end ports/ranks and one test from the start of the end port/rank to the end address.
    // If the address range crosses between ports we need to duplicate subtests for the affected ranges

    // Setup the address configurations and subtests
    FAPI_TRY( multi_port_addr() );

    // Here's an interesting problem. PRD (and others maybe) expect the operation to proceed in address-order.
    // That is, when PRD finds an address it stops on, it wants to continue from there "to the end." That means
    // we need to keep the subtests sorted, otherwise PRD could pass one subtest come upon a fail in a subsequent
    // subtest and re-test something it already passed. So we sort the resulting iv_subtest vector by port/DIMM
    // in the subtest.
    std::sort(iv_program.iv_subtests.begin(), iv_program.iv_subtests.end(),
              [](const decltype(iv_subtest)& a, const decltype(iv_subtest)& b) -> bool
    {
        uint16_t l_a_addr_sel = 0;
        uint16_t l_b_addr_sel = 0;
        a.iv_mcbmr.extractToRight<TT::ADDR_SEL, TT::ADDR_SEL_LEN>(l_a_addr_sel);
        b.iv_mcbmr.extractToRight<TT::ADDR_SEL, TT::ADDR_SEL_LEN>(l_b_addr_sel);

        if (a.get_port() == b.get_port())
        {
            return(l_a_addr_sel < l_b_addr_sel);
        }
        return (a.get_port() < b.get_port());
    });

    // Initialize the common sections
    FAPI_TRY( base_init() );

    // Configures all subtests under an MCBIST
    // Odyssey workaround: PAUSE_AFTER_RANK doesn't work so we have to create a subtest per rank per port and
    // set PAUSE_ON_ERROR_MODE to PAUSE_AFTER_SUBTEST
    if ((iv_const.iv_end_boundary == end_boundary::STOP_AFTER_MASTER_RANK) ||
        (iv_const.iv_end_boundary == end_boundary::STOP_AFTER_SLAVE_RANK))
    {
        iv_program.change_end_boundary(end_boundary::STOP_AFTER_SUBTEST);
    }

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
#endif
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
