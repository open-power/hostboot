/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/ddr_phy.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file ddr_phy.C
/// @brief Subroutines to manipulate the phy, or used during phy procedures
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <vector>
#include <initializer_list>

#include <fapi2.H>
#include <mss.H>

#include <lib/phy/ddr_phy.H>
#include <lib/phy/read_cntrl.H>
#include <lib/phy/phy_cntrl.H>
#include <lib/phy/apb.H>
#include <lib/phy/adr32s.H>
#include <lib/phy/adr.H>
#include <lib/phy/seq.H>
#include <lib/workarounds/dp16_workarounds.H>
#include <lib/workarounds/wr_vref_workarounds.H>
#include <lib/dimm/ddr4/latch_wr_vref.H>

#include <lib/utils/bit_count.H>
#include <lib/utils/find.H>
#include <lib/utils/dump_regs.H>
#include <lib/utils/scom.H>
#include <lib/utils/count_dimm.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_PROC_CHIP;
using fapi2::TARGET_TYPE_SYSTEM;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;
using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{

///
/// @brief change resetn to the given state
/// @param[in] i_target the mcbist
/// @param[in] i_state the desired state
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode change_resetn( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target, states i_state )
{
    fapi2::buffer<uint64_t> l_data;

    // Need to run on the magic port too
    for (const auto& p : mss::find_targets_with_magic<TARGET_TYPE_MCA>(i_target))
    {
        FAPI_INF("Change reset to %s PHY: %s", (i_state == HIGH ? "high" : "low"), mss::c_str(p));

        FAPI_TRY( mss::getScom(p, MCA_MBA_CAL0Q, l_data) );
        i_state == HIGH ? l_data.setBit<MCA_MBA_CAL0Q_RESET_RECOVER>() : l_data.clearBit<MCA_MBA_CAL0Q_RESET_RECOVER>();
        FAPI_TRY( mss::putScom(p, MCA_MBA_CAL0Q, l_data) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform the zctl enable process
/// @param[in] i_target the mcbist for the reset recover
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode enable_zctl( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    // We only need to zcal the magic ports - they have the logic for all the other ports.
    const auto l_ports = mss::find_magic_targets<TARGET_TYPE_MCA>(i_target);

    fapi2::buffer<uint64_t> l_data;
    constexpr uint64_t l_zcal_reset_reg = pcTraits<TARGET_TYPE_MCA>::PC_RESETS_REG;
    constexpr uint64_t l_zcal_status_reg = pcTraits<TARGET_TYPE_MCA>::PC_DLL_ZCAL_CAL_STATUS_REG;
    uint8_t is_sim = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<TARGET_TYPE_SYSTEM>(), is_sim) );

    if (is_sim)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // 11. Assert the ZCNTL enable to the internal impedance controller in DDRPHY_PC_RESETS register
    mss::pc::set_enable_zcal(l_data, mss::HIGH);
    FAPI_TRY( mss::scom_blastah(l_ports, l_zcal_reset_reg, l_data) );

    // 12. Wait at least 1024 dphy_gckn cycles (no sense in doing this in the polling loop as
    // we'll end up doing this delay for every port when we only need to do it once since we
    // kicked them all off in parallel
    fapi2::delay(mss::cycles_to_ns(i_target, 1024), mss::cycles_to_simcycles(1024));

    // 13. Check for DONE in DDRPHY_PC_DLL_ZCAL
    for (const auto& p : l_ports)
    {
        bool l_poll = mss::poll(p, l_zcal_status_reg, poll_parameters(),
                                [](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
        {
            FAPI_INF("phy control zcal cal stat 0x%llx, remaining: %d", stat_reg, poll_remaining);
            return mss::pc::get_zcal_status(stat_reg) == mss::YES;
        });

        FAPI_ASSERT(l_poll,
                    fapi2::MSS_ZCNTL_FAILED_TO_COMPLETE().set_MCA_IN_ERROR(p),
                    "zctl enable failed: %s", mss::c_str(p));
    }

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Change mclk low
/// @param[in] i_target mcbist target
/// @param[in] i_state mss::HIGH or mss::LOW - desired state.
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode change_force_mclk_low (const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
        const mss::states i_state)
{

    // Working with Goldade, we learned this:
    // From John Bailas:  9:49:46 AM: you need to use that force_mclk_low signal, it needs to be asserted which
    // forces RESETN on, and CK/CKN to 0, and all other address/cmd to Z. Then the MC has to establish valid
    // values for all signals after PHY reset before force_mclk_low gets de-asserted
    // And to celar up the ambiguity of "on" <grin>
    // John S. Bialas Jr: Hi Brian, force_mclk_low should force RESETN, CK, and CK# to 0, and all
    // other address/command signals to Z
    // So, this should be enough to get us going. BRS

    // Additionally: from John Bailas
    // The PHY should be reset and initialized such that it can synchronously control the RESETN, CK, and CKN
    // to the DIMM, then force_mclk_low can be de-asserted and the control of those signals will be synchronously
    // maintained. Beyond that the remainder of the DIMM init sequence can be performed, ie. start CK/CKN,
    // de-assert RESETN, etc

    fapi2::buffer<uint64_t> l_data;
    uint8_t is_sim = 0;

    // We want to force the memory clocks low for all ports, including the magic port if it's not
    // otherwise functional. We don't want to re-enable memory clocks for the magic port if it's
    // not otherwise functional.
    auto l_ports = (i_state == mss::LOW) ? mss::find_targets_with_magic<TARGET_TYPE_MCA>(i_target) :
                   mss::find_targets<TARGET_TYPE_MCA>(i_target);
    FAPI_INF("force mclk %s for all ports", (i_state == mss::LOW ? "low" : "high") );

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<TARGET_TYPE_SYSTEM>(), is_sim) );

    // On cycle sim for some reason clearing force_mclk_low makes the DIMM interface go tri-state.
    // On real hardware this should release the memory clocks
    if (is_sim && (i_state == mss::LOW))
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    for (const auto& p : l_ports)
    {
        FAPI_TRY( mss::getScom(p, MCA_MBA_FARB5Q, l_data) );
        l_data.writeBit<MCA_MBA_FARB5Q_CFG_FORCE_MCLK_LOW_N>(i_state);
        FAPI_TRY(mss::putScom( p, MCA_MBA_FARB5Q, l_data));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Change the continuous update mode of the PR CNTL registers
/// @note Will take the SYSCLK control out of reset, too
/// @param[in] i_target the mcbist target
/// @param[in] i_state, mss::ON if you want to be in continuous mode, mss::OFF to turn it off
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode setup_phase_rotator_control_registers( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
        const states i_state )
{
    // From the DDR PHY workbook
    constexpr uint64_t CONTINUOUS_UPDATE = 0x8024;

    FAPI_INF("continuous update: 0x%x", CONTINUOUS_UPDATE);

    constexpr uint64_t SIM_OVERRIDE = 0x8080;
    constexpr uint64_t PHASE_CNTL_EN = 0x8020;

    uint8_t is_sim = 0;

    fapi2::buffer<uint64_t> l_update( i_state == mss::ON ? CONTINUOUS_UPDATE : PHASE_CNTL_EN );
    const auto l_mca = find_targets<TARGET_TYPE_MCA>(i_target);

    std::vector<uint64_t> addrs(
    {
        MCA_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S0, MCA_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S1,
        MCA_DDRPHY_DP16_SYSCLK_PR0_P0_0, MCA_DDRPHY_DP16_SYSCLK_PR1_P0_0,
        MCA_DDRPHY_DP16_SYSCLK_PR0_P0_1, MCA_DDRPHY_DP16_SYSCLK_PR1_P0_1,
        MCA_DDRPHY_DP16_SYSCLK_PR0_P0_2, MCA_DDRPHY_DP16_SYSCLK_PR1_P0_2,
        MCA_DDRPHY_DP16_SYSCLK_PR0_P0_3, MCA_DDRPHY_DP16_SYSCLK_PR1_P0_3,

        // Don't enable MCA_DDRPHY_DP16_SYSCLK_PR1_P0_4 on Nimbus, there is no dp8 there
        MCA_DDRPHY_DP16_SYSCLK_PR0_P0_4,
    } );

    if (l_mca.size() == 0)
    {
        // No MCA, no problem
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<TARGET_TYPE_SYSTEM>(), is_sim) );

    if (is_sim)
    {
        // Per Bialas, we don't want to do true alignment in the cycle sim as we have
        // a chance of being off one-tick (which is detrimental.) Per his recomendations,
        // we write 0's to the control registers and then configure them with 0x8080.
        l_update = (i_state == mss::ON) ? 0x0 : SIM_OVERRIDE;
    }

    // All the MCA (and both registers) will be in the same state, so we can get the first and use it to create the
    // values for the others.

    FAPI_INF("Write 0x%lx into the ADR SysClk Phase Rotator Control Regs", l_update);

    // WRCLK Phase rotators are taken care of in the phy initfile. BRS 6/16.

    FAPI_TRY( mss::scom_blastah(l_mca, addrs, l_update) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Deassert the sys clk reset
/// @param[in] i_target the mcbist target
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode deassert_sysclk_reset( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    typedef pcTraits<TARGET_TYPE_MCA> TT;

    // Can't just cram 0's in to PC_RESETS as we can't clear the ZCTL_ENABLE bit
    FAPI_INF("Clear SysClk reset in the PC Resets Register. This deasserts the SysClk Reset.");

    for (const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
    {
        fapi2::buffer<uint64_t> l_read;
        FAPI_TRY( mss::getScom(p, TT::PC_RESETS_REG, l_read) );
        l_read.clearBit<TT::SYSCLK_RESET>();
        FAPI_TRY( mss::putScom(p, TT::PC_RESETS_REG, l_read) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check if the bang bang lock has succeeded
/// @param[in] i_target a MCBIST target
/// @return FAPI2_RC_SUCCESs iff ok
///
fapi2::ReturnCode check_bang_bang_lock( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target )
{
    fapi2::buffer<uint64_t> l_read;
    uint8_t is_sim = 0;

    // On each port there are 5 DP16's which have lock registers.
    static const std::vector<uint64_t> l_addresses =
    {
        MCA_DDRPHY_DP16_SYSCLK_PR_VALUE_P0_0,
        MCA_DDRPHY_DP16_SYSCLK_PR_VALUE_P0_1,
        MCA_DDRPHY_DP16_SYSCLK_PR_VALUE_P0_2,
        MCA_DDRPHY_DP16_SYSCLK_PR_VALUE_P0_3,
        MCA_DDRPHY_DP16_SYSCLK_PR_VALUE_P0_4,
    };

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<TARGET_TYPE_SYSTEM>(), is_sim) );

    // There's nothing going on in sim ...
    if (is_sim)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    for (const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
    {
        // Check the ADR lock bit
        // Little duplication - makes things more clear and simpler, and allows us to callout the
        // bugger which first caused a problem. Since we waited before the check (us) was called
        // we can just use the default poll parameters. It will also allow all the subsequent
        // polls to complete quickly - as if they're done they don't need a delay.

        FAPI_INF("checking %s MCA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S0 0x%016x",
                 mss::c_str(p), MCA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S0);

        FAPI_ASSERT(
            mss::poll(p, MCA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S0, poll_parameters(),
                      [&l_read](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
        {
            FAPI_INF("adr32s0 sysclk pr bb lock 0x%llx, remaining: %d", stat_reg, poll_remaining);
            l_read = stat_reg;
            return stat_reg.getBit<MCA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S0_ADR0_BB_LOCK>() == mss::ON;
        }),
        fapi2::MSS_ADR_BANG_BANG_FAILED_TO_LOCK().set_MCA_IN_ERROR(p).set_ADR(0),
        "ADR failed bb lock. ADR%d register 0x%016lx 0x%016lx", 0,
        MCA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S0, l_read
        );


        FAPI_INF("checking %s MCA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S1 0x%016x",
                 mss::c_str(p), MCA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S1);

        FAPI_ASSERT(
            mss::poll(p, MCA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S1, poll_parameters(),
                      [&l_read](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
        {
            FAPI_INF("adr32s1 sysclk pr bb lock 0x%llx, remaining: %d", stat_reg, poll_remaining);
            l_read = stat_reg;
            return stat_reg.getBit<MCA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S1_ADR1_BB_LOCK>() == mss::ON;
        }),
        fapi2::MSS_ADR_BANG_BANG_FAILED_TO_LOCK().set_MCA_IN_ERROR(p).set_ADR(1),
        "ADR failed bb lock. ADR%d register 0x%016lx 0x%016lx", 1,
        MCA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S1, l_read
        );

        // Pop thru the registers on the ports and see if all the sysclks are locked.
        // FFDC regiser collection will collect interesting information so we only need
        // to catch the first fail.
        for (const auto r : l_addresses)
        {

            FAPI_TRY( mss::getScom(p, r, l_read) );

            FAPI_INF("checking %s MCA_DDRPHY_DP16_SYSCLK_PR_VALUE_P0_0_01_BB_LOCK0 0x%016x",
                     mss::c_str(p), l_read);

            FAPI_ASSERT(
                mss::poll(p, r, poll_parameters(),
                          [&l_read](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
            {
                FAPI_INF("dp16 sysclk pr bb lock 0x%llx, remaining: %d", stat_reg, poll_remaining);
                l_read = stat_reg;
                return stat_reg.getBit<MCA_DDRPHY_DP16_SYSCLK_PR_VALUE_P0_0_01_BB_LOCK0>() == mss::ON;
            }),

            fapi2::MSS_DP16_BANG_BANG_FAILED_TO_LOCK().set_MCA_IN_ERROR(p).set_ROTATOR(0),
            "DP16 failed bb lock. rotator %d register 0x%016lx 0x%016lx", 0, r, l_read
            );

            FAPI_INF("checking %s MCA_DDRPHY_DP16_SYSCLK_PR_VALUE_P0_0_01_BB_LOCK1 0x%016x",
                     mss::c_str(p), l_read);

            // We're on Nimbus, there are no spares which means the BB_LOCK1 of the last dp16 will never lock
            if (r != MCA_DDRPHY_DP16_SYSCLK_PR_VALUE_P0_4)
            {

                FAPI_ASSERT(
                    mss::poll(p, r, poll_parameters(),
                              [&l_read](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
                {
                    FAPI_INF("dp16 sysclk pr bb lock 0x%llx, remaining: %d", stat_reg, poll_remaining);
                    l_read = stat_reg;
                    return stat_reg.getBit<MCA_DDRPHY_DP16_SYSCLK_PR_VALUE_P0_0_01_BB_LOCK1>() == mss::ON;
                }),

                fapi2::MSS_DP16_BANG_BANG_FAILED_TO_LOCK().set_MCA_IN_ERROR(p).set_ROTATOR(1),
                "DP16 failed bb lock. rotator %d register 0x%016lx 0x%016lx", 1, r, l_read
                );
            }
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return the DIMM target for the primary rank in the specificed rank pair
/// @param[in] i_target the MCA target
/// @param[in] i_rp the rank pair
/// @param[out] o_dimm fapi2::Target<TARGET_TYPE_DIMM>
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode rank_pair_primary_to_dimm( const fapi2::Target<TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        fapi2::Target<TARGET_TYPE_DIMM>& o_dimm)
{
    fapi2::buffer<uint64_t> l_data;
    fapi2::buffer<uint64_t> l_rank;
    uint64_t l_rank_on_dimm;

    const auto l_dimms = mss::find_targets<TARGET_TYPE_DIMM>(i_target);

    // Sanity check the rank pair
    FAPI_INF("%s rank pair: %d", mss::c_str(i_target), i_rp);

    fapi2::Assert(i_rp < MAX_RANK_PER_DIMM);

    // We need to get the register containing the specification for this rank pair,
    // and fish out the primary rank for this rank pair
    switch(i_rp)
    {
        case 0:
            FAPI_TRY( mss::getScom(i_target, MCA_DDRPHY_PC_RANK_PAIR0_P0, l_data) );
            l_data.extractToRight<MCA_DDRPHY_PC_RANK_PAIR0_P0_PRI,
                                  MCA_DDRPHY_PC_RANK_PAIR0_P0_PRI_LEN>(l_rank);
            break;

        case 1:
            FAPI_TRY( mss::getScom(i_target, MCA_DDRPHY_PC_RANK_PAIR0_P0, l_data) );
            l_data.extractToRight<MCA_DDRPHY_PC_RANK_PAIR0_P0_PAIR1_PRI,
                                  MCA_DDRPHY_PC_RANK_PAIR0_P0_PAIR1_PRI_LEN>(l_rank);
            break;

        case 2:
            FAPI_TRY( mss::getScom(i_target, MCA_DDRPHY_PC_RANK_PAIR1_P0, l_data) );
            l_data.extractToRight<MCA_DDRPHY_PC_RANK_PAIR1_P0_PAIR2_PRI,
                                  MCA_DDRPHY_PC_RANK_PAIR1_P0_PAIR2_PRI_LEN>(l_rank);
            break;

        case 3:
            FAPI_TRY( mss::getScom(i_target, MCA_DDRPHY_PC_RANK_PAIR1_P0, l_data) );
            l_data.extractToRight<MCA_DDRPHY_PC_RANK_PAIR1_P0_PAIR3_PRI,
                                  MCA_DDRPHY_PC_RANK_PAIR1_P0_PAIR3_PRI_LEN>(l_rank);
            break;
    };

    // Now we need to figure out which DIMM this rank is on. It's either on DIMM0 or DIMM1, and DIMM0
    // has ranks 0-3 and DIMM1 has ranks 4-7. Return the DIMM associated.
    l_rank_on_dimm = mss::rank::get_dimm_from_rank(l_rank);

    // Sanity check the DIMM list
    FAPI_INF("%s rank is on dimm: %d, number of dimms: %d", mss::c_str(i_target), l_rank_on_dimm, l_dimms.size());

    fapi2::Assert(l_rank_on_dimm < l_dimms.size());

    o_dimm = l_dimms[l_rank_on_dimm];

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief check and process initial cal errors
/// @param[in] i_target the port in question
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff no error
///
template<>
fapi2::ReturnCode process_initial_cal_errors( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    typedef pcTraits<TARGET_TYPE_MCA> TT;

    uint64_t l_errors = 0;
    uint64_t l_rank_pairs = 0;
    uint8_t cal_abort_on_error = 0;

    fapi2::buffer<uint64_t> l_err_data;

    fapi2::Target<TARGET_TYPE_DIMM> l_failed_dimm;

    FAPI_TRY( mss::cal_abort_on_error(cal_abort_on_error) );

    FAPI_TRY( pc::read_init_cal_error(i_target, l_err_data) );

    l_err_data.extractToRight<TT::INIT_CAL_ERROR_WR_LEVEL, TT::CAL_ERROR_FIELD_LEN>(l_errors);
    l_err_data.extractToRight<TT::INIT_CAL_ERROR_RANK_PAIR, TT::INIT_CAL_ERROR_RANK_PAIR_LEN>(l_rank_pairs);
    FAPI_INF("initial cal err: 0x%016llx, rp: 0x%016llx (0x%016llx)", l_errors, l_rank_pairs, uint64_t(l_err_data));

    if ((l_rank_pairs == 0) || (l_errors == 0))
    {
        FAPI_INF("Initial cal - no errors reported");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Error information from other registers is gathered in the FFDC from the XML

    // Get the DIMM which failed. We should only have one rank pair as we calibrate the
    // rank pairs individually (we do this so we can see which DIMM failed if more than one
    // fails ...) Note first_bit_set gives a bit position (0 being left most.) So, the rank
    // in question is the bit postion minus the position of the 0th rank in the register.
    // (the rank bits are bits 60:63, for example, so rank 0 is in position 60)
    FAPI_TRY( mss::rank_pair_primary_to_dimm(i_target, mss::first_bit_set(l_rank_pairs) - TT::INIT_CAL_ERROR_RANK_PAIR,
              l_failed_dimm) );
    FAPI_ERR("initial cal failed for %s", mss::c_str(l_failed_dimm));

    // If we aborted on error, the disable bits aren't complete so we can't make a determination about
    // whether the port is repairable.
    if (cal_abort_on_error == fapi2::ENUM_ATTR_MSS_CAL_ABORT_ON_ERROR_YES)
    {
        FAPI_INF("can't process disable bits as we aborted on error - disable bits might be incomplete");
    }
    else
    {
        // Process the disable bits. The PHY will disable bits that it finds don't work for whatever reason.
        // However, we can handle a number of bad bits without resorting to killing the DIMM. Do the bad
        // bit processing here, and if we can go on and ignore these bad bits, we'll see a succcess here.
        if (dp16::process_bad_bits(i_target, l_failed_dimm, l_rank_pairs) == fapi2::FAPI2_RC_SUCCESS)
        {
            FAPI_INF("Initial cal - errors reported, but only 1 nibble + 1 bit marked %s", mss::c_str(l_failed_dimm));
            // TK processing recoverable bad bits ...
        }
    }

    // So we can do a few things here. If we're aborting on the first calibration error,
    // we only expect to have one error bit set. If we ran all the calibrations, we can
    // either have one bit set or more than one bit set. If we have more than one bit set
    // the result is the same - a broken DIMM which will be deconfigured. So put enough
    // information in the FFDC for the lab but we don't need one error for every cal fail.
    FAPI_ASSERT(mss::bit_count(l_errors) == 1,
                fapi2::MSS_DRAMINIT_TRAINING_MULTIPLE_ERRORS()
                .set_FAILED_STEPS(uint64_t(l_err_data))
                .set_PORT_POSITION(mss::fapi_pos(i_target))
                .set_RANKGROUP_POSITION(l_rank_pairs)
                .set_TARGET_IN_ERROR(l_failed_dimm)
                .set_TARGET_WITH_REGISTERS(i_target),
                "Initial CAL failed multiple training steps. dimm: %s, cal err: 0x%016llx",
                mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

    FAPI_ASSERT( ! l_err_data.getBit<TT::INIT_CAL_ERROR_WR_LEVEL>(),
                 fapi2::MSS_DRAMINIT_TRAINING_WR_LVL_ERROR()
                 .set_PORT_POSITION(mss::fapi_pos(i_target))
                 .set_RANKGROUP_POSITION(l_rank_pairs)
                 .set_TARGET_IN_ERROR(l_failed_dimm)
                 .set_TARGET_WITH_REGISTERS(i_target),
                 "Initial CAL failed write leveling. dimm: %s, cal err: 0x%016llx",
                 mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

    FAPI_ASSERT( ! l_err_data.getBit<TT::INIT_CAL_ERROR_INITIAL_PAT_WRITE>(),
                 fapi2::MSS_DRAMINIT_TRAINING_INITIAL_PAT_WRITE_ERROR()
                 .set_PORT_POSITION(mss::fapi_pos(i_target))
                 .set_RANKGROUP_POSITION(l_rank_pairs)
                 .set_TARGET_IN_ERROR(l_failed_dimm)
                 .set_TARGET_WITH_REGISTERS(i_target),
                 "Initial CAL failed initial pattern write. dimm: %s, cal err: 0x%016llx",
                 mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

    FAPI_ASSERT( ! l_err_data.getBit<TT::INIT_CAL_ERROR_DQS_ALIGN>(),
                 fapi2::MSS_DRAMINIT_TRAINING_DQS_ALIGNMENT_ERROR()
                 .set_PORT_POSITION(mss::fapi_pos(i_target))
                 .set_RANKGROUP_POSITION(l_rank_pairs)
                 .set_TARGET_IN_ERROR(l_failed_dimm)
                 .set_TARGET_WITH_REGISTERS(i_target),
                 "Initial CAL failed DQS alignenment. dimm: %s, cal err: 0x%016llx",
                 mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

    FAPI_ASSERT( ! l_err_data.getBit<TT::INIT_CAL_ERROR_RDCLK_ALIGN>(),
                 fapi2::MSS_DRAMINIT_TRAINING_RD_CLK_SYS_CLK_ALIGNMENT_ERROR()
                 .set_PORT_POSITION(mss::fapi_pos(i_target))
                 .set_RANKGROUP_POSITION(l_rank_pairs)
                 .set_TARGET_IN_ERROR(l_failed_dimm)
                 .set_TARGET_WITH_REGISTERS(i_target),
                 "Initial CAL failed read clk alignenment. dimm: %s, cal err: 0x%016llx",
                 mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

    FAPI_ASSERT( ! l_err_data.getBit<TT::INIT_CAL_ERROR_READ_CTR>(),
                 fapi2::MSS_DRAMINIT_TRAINING_RD_CENTERING_ERROR()
                 .set_PORT_POSITION(mss::fapi_pos(i_target))
                 .set_RANKGROUP_POSITION(l_rank_pairs)
                 .set_TARGET_IN_ERROR(l_failed_dimm)
                 .set_TARGET_WITH_REGISTERS(i_target),
                 "Initial CAL failed read centering. dimm: %s, cal err: 0x%016llx",
                 mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

    FAPI_ASSERT( ! l_err_data.getBit<TT::INIT_CAL_ERROR_WRITE_CTR>(),
                 fapi2::MSS_DRAMINIT_TRAINING_WR_CENTERING_ERROR()
                 .set_PORT_POSITION(mss::fapi_pos(i_target))
                 .set_RANKGROUP_POSITION(l_rank_pairs)
                 .set_TARGET_IN_ERROR(l_failed_dimm)
                 .set_TARGET_WITH_REGISTERS(i_target),
                 "Initial CAL failed write centering. dimm: %s, cal err: 0x%016llx",
                 mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

    FAPI_ASSERT( ! l_err_data.getBit<TT::INIT_CAL_ERROR_INITIAL_COARSE_WR>(),
                 fapi2::MSS_DRAMINIT_TRAINING_INITIAL_COARSE_WR_ERROR()
                 .set_PORT_POSITION(mss::fapi_pos(i_target))
                 .set_RANKGROUP_POSITION(l_rank_pairs)
                 .set_TARGET_IN_ERROR(l_failed_dimm)
                 .set_TARGET_WITH_REGISTERS(i_target),
                 "Initial CAL failed initial coarse write. dimm: %s, cal err: 0x%016llx",
                 mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

    FAPI_ASSERT( ! l_err_data.getBit<TT::INIT_CAL_ERROR_COARSE_RD>(),
                 fapi2::MSS_DRAMINIT_TRAINING_COARSE_RD_ERROR()
                 .set_PORT_POSITION(mss::fapi_pos(i_target))
                 .set_RANKGROUP_POSITION(l_rank_pairs)
                 .set_TARGET_IN_ERROR(l_failed_dimm)
                 .set_TARGET_WITH_REGISTERS(i_target),
                 "Initial CAL failed coarse read. dimm: %s, cal err: 0x%016llx",
                 mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

    FAPI_ASSERT( ! l_err_data.getBit<TT::INIT_CAL_ERROR_CUSTOM_RD>(),
                 fapi2::MSS_DRAMINIT_TRAINING_CUSTOM_PATTERN_RD_ERROR()
                 .set_PORT_POSITION(mss::fapi_pos(i_target))
                 .set_RANKGROUP_POSITION(l_rank_pairs)
                 .set_TARGET_IN_ERROR(l_failed_dimm)
                 .set_TARGET_WITH_REGISTERS(i_target),
                 "Initial CAL failed custom read. dimm: %s, cal err: 0x%016llx",
                 mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

    FAPI_ASSERT( ! l_err_data.getBit<TT::INIT_CAL_ERROR_CUSTOM_WR>(),
                 fapi2::MSS_DRAMINIT_TRAINING_CUSTOM_PATTERN_WR_ERROR()
                 .set_PORT_POSITION(mss::fapi_pos(i_target))
                 .set_RANKGROUP_POSITION(l_rank_pairs)
                 .set_TARGET_IN_ERROR(l_failed_dimm)
                 .set_TARGET_WITH_REGISTERS(i_target),
                 "Initial CAL failed custom write. dimm: %s, cal err: 0x%016llx",
                 mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

    FAPI_ASSERT( ! l_err_data.getBit<TT::INIT_CAL_ERROR_DIGITAL_EYE>(),
                 fapi2::MSS_DRAMINIT_TRAINING_DIGITAL_EYE_ERROR()
                 .set_PORT_POSITION(mss::fapi_pos(i_target))
                 .set_RANKGROUP_POSITION(l_rank_pairs)
                 .set_TARGET_IN_ERROR(l_failed_dimm)
                 .set_TARGET_WITH_REGISTERS(i_target),
                 "Initial CAL failed digital eye. dimm: %s, cal err: 0x%016llx",
                 mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets up the IO impedances (ADR DRV's and DP DRV's/RCV's) - MCA specialization
/// @tparam T the fapi2::TargetType
/// @param[in] i_target the target (MCA/MCBIST or MBA?)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode reset_io_impedances(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{

    FAPI_TRY( mss::dp16::reset_dq_dqs_drv_imp(i_target) );
    FAPI_TRY( mss::dp16::reset_dq_dqs_rcv_imp(i_target) );
    FAPI_TRY( mss::adr::reset_imp_clk(i_target) );
    FAPI_TRY( mss::adr::reset_imp_cmd_addr(i_target) );
    FAPI_TRY( mss::adr::reset_imp_cntl(i_target) );
    FAPI_TRY( mss::adr::reset_imp_cscid(i_target) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations for the PHY
/// @param[in] i_target the MCBIST which has the PHYs to initialize
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode phy_scominit(const fapi2::Target<TARGET_TYPE_MCBIST>& i_target)
{
    // Returned from set_rank_pairs, it tells us how many rank pairs we configured on this port.
    std::vector<uint64_t> l_pairs;

    // Setup the DP16 IO TX, DLL/VREG. They use freq which is an MCBIST attribute
    FAPI_TRY( mss::dp16::reset_io_tx_config0(i_target) );
    FAPI_TRY( mss::dp16::reset_dll_vreg_config1(i_target) );

    for (const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
    {

        // No point in bothering if we don't have any DIMM
        if (mss::count_dimm(p) == 0)
        {
            FAPI_INF("No DIMM on %s, not running phy_scominit", mss::c_str(p));
            continue;
        }

        // The following registers must be configured to the correct operating environment:

        // Section 5.2.1.3 PC Rank Pair 0 on page 177
        // Section 5.2.1.4 PC Rank Pair 1 on page 179
        FAPI_TRY( mss::rank::set_rank_pairs(p) );

        // Section 5.2.4.1 DP16 Data Bit Enable 0 on page 284
        // Section 5.2.4.2 DP16 Data Bit Enable 1 on page 285
        // Section 5.2.4.3 DP16 Data Bit Disable 0 on page 288
        // Section 5.2.4.4 DP16 Data Bit Disable 1 on page 289
        FAPI_TRY( mss::dp16::reset_data_bit_enable(p) );

        // Not going to load bad bits from the attributes until after f/w bring up
#ifdef LOAD_BAD_BITS_FROM_ATTR
        FAPI_TRY( mss::dp16::reset_bad_bits(p) );
#endif

        // New for Nimbus reset the DLL
        FAPI_TRY( mss::dp16::reset_dll(p) );

        FAPI_TRY( mss::rank::get_rank_pairs(p, l_pairs) );

        // Section 5.2.4.8 DP16 Write Clock Enable & Clock Selection on page 301
        FAPI_TRY( mss::dp16::reset_write_clock_enable(p, l_pairs) );
        FAPI_TRY( mss::dp16::reset_read_clock_enable(p, l_pairs) );

        // Reset Read VREF according to ATTR_MSS_VPD_MT_VREF_MC_RD value
        FAPI_TRY( mss::dp16::reset_rd_vref(p) );

        // PHY Control reset
        FAPI_TRY( mss::pc::reset(p) );

        // Write Control reset
        FAPI_TRY( mss::wc::reset(p) );

        // Read Control reset
        FAPI_TRY( mss::rc::reset(p) );

        // Reset the SEQ block
        FAPI_TRY( mss::seq::reset(p) );

        // Reset the AC Boost controls from the values in VPD
        FAPI_TRY( mss::dp16::reset_ac_boost_cntl(p) );

        // Reset the CTLE controls from the values in VPD
        FAPI_TRY( mss::dp16::reset_ctle_cntl(p) );

        // Shove the ADR delay values from VPD into the ADR delay registers
        FAPI_TRY( mss::adr::reset_delay(p) );

        // Write tsys adr and tsys data
        FAPI_TRY( mss::adr32s::reset_tsys_adr(p) );
        FAPI_TRY( mss::dp16::reset_tsys_data(p) );

        // Resets all of the IO impedances
        FAPI_TRY( mss::reset_io_impedances(p) );

        // Resets all WR VREF related registers
        FAPI_TRY( mss::dp16::reset_wr_vref_registers(p));

        // Reset the windage registers
        FAPI_TRY( mss::dp16::reset_read_delay_offset_registers(p) );

        //
        // Workarounds
        //
        FAPI_TRY( mss::workarounds::dp16::dqs_polarity(p) );
        FAPI_TRY( mss::workarounds::dp16::rd_dia_config5(p) );
        FAPI_TRY( mss::workarounds::dp16::dqsclk_offset(p) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setup all the cal config register
/// @param[in] i_target the MCA target associated with this cal setup
/// @param[in] i_rank_pairs the vector of currently configured rank pairs
/// @param[in] i_cal_steps_enabled fapi2::buffer<uint8_t> representing the cal steps to enable
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode setup_cal_config( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                    const std::vector<uint64_t> i_rank_pairs,
                                    fapi2::buffer<uint16_t> i_cal_steps_enabled)
{
    fapi2::buffer<uint64_t> l_cal_config;
    fapi2::buffer<uint64_t> l_vref_config;
    uint8_t is_sim = 0;
    uint8_t cal_abort_on_error = 0;

    FAPI_TRY( mss::cal_abort_on_error(cal_abort_on_error) );
    FAPI_TRY( mss::is_simulation(is_sim) );

    // This is the buffer which will be written to CAL_CONFIG0. It starts
    // life assuming no cal sequences, no rank pairs - but we set the abort-on-error
    // bit ahead of time.
    l_cal_config.writeBit<MCA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ABORT_ON_ERROR>(cal_abort_on_error);

    // Check the write centering bits - if write centering is defined, don't run 2D. Vice versa.
    if (i_cal_steps_enabled.getBit<WRITE_CTR>() && i_cal_steps_enabled.getBit<WRITE_CTR_2D_VREF>())
    {
        FAPI_INF("Both 1D and 2D write centering were defined - only performing 2D");
        i_cal_steps_enabled.clearBit<WRITE_CTR>();
    }

    // Sadly, the bits in the register don't align directly with the bits in the attribute.
    // So, arrange the bits accordingly and write the config register.
    {
        // Skip EXT_ZQCAL as it's not in the config register - we do it outside.
        // Loop (unrolled because static) over the remaining bits.
        l_cal_config.writeBit<MCA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_WR_LEVEL>(
            i_cal_steps_enabled.getBit<WR_LEVEL>());
        l_cal_config.writeBit<MCA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_DQS_ALIGN>(
            i_cal_steps_enabled.getBit<DQS_ALIGN>());
        l_cal_config.writeBit<MCA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_RDCLK_ALIGN>(
            i_cal_steps_enabled.getBit<RDCLK_ALIGN>());
        l_cal_config.writeBit<MCA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_READ_CTR>(
            i_cal_steps_enabled.getBit<READ_CTR>() || i_cal_steps_enabled.getBit<READ_CTR_2D_VREF>());
        l_cal_config.writeBit<MCA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_WRITE_CTR>(
            i_cal_steps_enabled.getBit<WRITE_CTR>() || i_cal_steps_enabled.getBit<WRITE_CTR_2D_VREF>());
        l_cal_config.writeBit<MCA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_INITIAL_COARSE_WR>(
            i_cal_steps_enabled.getBit<COARSE_WR>());
        l_cal_config.writeBit<MCA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_COARSE_RD>(
            i_cal_steps_enabled.getBit<COARSE_RD>());

        // Always turn on initial pattern write in h/w, never for sim (makes the DIMM behavioral lose it's mind)
        if (!is_sim)
        {
            l_cal_config.setBit<MCA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_INITIAL_PAT_WR>();
        }
    }

    // Blast the VREF config with the proper setting for these cal bits.
    // Read Centering
    {
        fapi2::buffer<uint64_t> l_data;

        // The two bits we care about are the calibration enable and skip read centering
        // bits in rc_vref_config1. If CALIBRATION_ENABLE is set, the vref is run before
        // read centering. If SKIPRDCENTERING is set, the cal stops after vref centering.
        // So
        // If READ_CNTR == 1 && READ_CTR_2D_VREF == 1, CALIBRATION_ENABLE = 1 and SKIP = 0
        // If READ_CNTR == 0 && READ_CTR_2D_VREF == 1, CALIBRATION_ENABLE = 1 and SKIP = 1
        // If READ_CNTR == 1 && READ_CTR_2D_VREF == 0, CALIBRATION_ENABLE = 0 and SKIP = don't care
        // If READ_CNTR == 0 && READ_CTR_2D_VREF == 0, CALIBRATION_ENABLE = 0 and SKIP = don't care
        FAPI_TRY( mss::rc::read_vref_config1(i_target, l_data) );

        l_data.writeBit<MCA_DDRPHY_RC_RDVREF_CONFIG1_P0_CALIBRATION_ENABLE>(
            i_cal_steps_enabled.getBit<WRITE_CTR_2D_VREF>());
        l_data.writeBit<MCA_DDRPHY_RC_RDVREF_CONFIG1_P0_SKIP_RDCENTERING>(
            ! i_cal_steps_enabled.getBit<WRITE_CTR>());

        FAPI_TRY( mss::rc::write_vref_config1(i_target, l_data) );
    }

    // Write Centering
    {
        static const std::vector<uint64_t> l_vref_regs =
        {
            MCA_DDRPHY_DP16_WR_VREF_CONFIG0_P0_0,
            MCA_DDRPHY_DP16_WR_VREF_CONFIG0_P0_1,
            MCA_DDRPHY_DP16_WR_VREF_CONFIG0_P0_2,
            MCA_DDRPHY_DP16_WR_VREF_CONFIG0_P0_3,
            MCA_DDRPHY_DP16_WR_VREF_CONFIG0_P0_4
        };

        if (i_cal_steps_enabled.getBit<WRITE_CTR>())
        {
            l_vref_config.setBit<MCA_DDRPHY_DP16_WR_VREF_CONFIG0_P0_0_01_CTR_1D_CHICKEN_SWITCH>();
        }

        // loops through all RP's running workarounds and latching the VREF's as need be
        for(const auto& l_rp : i_rank_pairs)
        {
            // Overrides will be set by mss::workarounds::wr_vref::execute.
            // If the execute code is skipped, then it will read from the attributes
            uint8_t l_vrefdq_train_range_override = mss::ddr4::USE_DEFAULT_WR_VREF_SETTINGS;
            uint8_t l_vrefdq_train_value_override = mss::ddr4::USE_DEFAULT_WR_VREF_SETTINGS;

            // Runs the workaround
            if (i_cal_steps_enabled.getBit<WRITE_CTR_2D_VREF>())
            {
                l_vref_config.clearBit<MCA_DDRPHY_DP16_WR_VREF_CONFIG0_P0_0_01_CTR_1D_CHICKEN_SWITCH>();

                // Runs WR VREF workarounds if needed
                // it will check and see if it needs to run, if not it will return success - needs 0th rankpair to hit

                FAPI_TRY( mss::workarounds::wr_vref::execute(i_target, l_rp, l_vrefdq_train_range_override,
                          l_vrefdq_train_value_override) );
            }

            // Latches the VREF's
            FAPI_TRY( mss::ddr4::latch_wr_vref_commands_by_rank_pair( i_target,
                      l_rp,
                      l_vrefdq_train_range_override,
                      l_vrefdq_train_value_override ) );
        }

        FAPI_INF("wr_vref_config: 0x%016lu", l_vref_config);
        FAPI_TRY( mss::scom_blastah(i_target, l_vref_regs, l_vref_config) );
    }

    // Note: This rank encoding isn't used if the cal is initiated from the CCS engine
    // as they use the recal inteface.
    // Configure the rank pairs
    for (const auto& rp : i_rank_pairs)
    {
        l_cal_config.setBit(MCA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_RANK_PAIR + rp);
    }

    FAPI_INF("cal_config for %s: 0x%lx (steps: 0x%lx)",
             mss::c_str(i_target), uint16_t(l_cal_config), uint16_t(i_cal_steps_enabled));
    FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_PC_INIT_CAL_CONFIG0_P0, l_cal_config) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setup all the cal config register
/// @param[in] i_target the target associated with this cal setup
/// @param[in] i_rank one currently configured rank pairs
/// @param[in] i_cal_steps_enabled fapi2::buffer<uint16_t> representing the cal steps to enable
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode setup_cal_config( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                    const uint64_t i_rank,
                                    const fapi2::buffer<uint16_t> i_cal_steps_enabled)
{
    std::vector< uint64_t > l_ranks({i_rank});
    return setup_cal_config(i_target, l_ranks, i_cal_steps_enabled);
}

///
/// @brief Setup odt_wr/rd_config
/// @param[in] i_target the MCA target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode reset_odt_config( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    uint8_t l_odt_rd[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];
    uint8_t l_odt_wr[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM];

    FAPI_TRY( mss::vpd_mt_odt_rd(i_target, &(l_odt_rd[0][0])) );
    FAPI_TRY( mss::vpd_mt_odt_wr(i_target, &(l_odt_wr[0][0])) );

    // Nimbus PHY is more or less hard-wired for 2 DIMM/port 4R/DIMM
    // So there's not much point in looping over DIMM or ranks.

    //
    // ODT Read
    //
    {
        // DPHY01_DDRPHY_SEQ_ODT_RD_CONFIG0_P0
        // 48:55, ATTR_VPD_ODT_RD[0][0][0]; # when Read of Rank0
        // 56:63, ATTR_VPD_ODT_RD[0][0][1]; # when Read of Rank1
        fapi2::buffer<uint64_t> l_data;

        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_RD_CONFIG0_P0_VALUES0,
                               MCA_DDRPHY_SEQ_ODT_RD_CONFIG0_P0_VALUES0_LEN>(l_odt_rd[0][0]);
        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_RD_CONFIG0_P0_VALUES1,
                               MCA_DDRPHY_SEQ_ODT_RD_CONFIG0_P0_VALUES1_LEN>(l_odt_rd[0][1]);
        FAPI_INF("odt_rd_config0: 0x%016llx", uint64_t(l_data));
        FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_SEQ_ODT_RD_CONFIG0_P0, l_data) );
    }

    {
        // DPHY01_DDRPHY_SEQ_ODT_RD_CONFIG1_P0
        // 48:55, ATTR_VPD_ODT_RD[0][0][2]; # when Read of Rank2
        // 56:63, ATTR_VPD_ODT_RD[0][0][3]; # when Read of Rank3
        fapi2::buffer<uint64_t> l_data;

        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_RD_CONFIG1_P0_VALUES2,
                               MCA_DDRPHY_SEQ_ODT_RD_CONFIG1_P0_VALUES2_LEN>(l_odt_rd[0][2]);
        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_RD_CONFIG1_P0_VALUES3,
                               MCA_DDRPHY_SEQ_ODT_RD_CONFIG1_P0_VALUES3_LEN>(l_odt_rd[0][3]);
        FAPI_INF("odt_rd_config1: 0x%016llx", uint64_t(l_data));
        FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_SEQ_ODT_RD_CONFIG1_P0, l_data) );
    }

    {
        // DPHY01_DDRPHY_SEQ_ODT_RD_CONFIG2_P0
        // 48:55, ATTR_VPD_ODT_RD[0][1][0]; # when Read of Rank4
        // 56:63, ATTR_VPD_ODT_RD[0][1][1]; # when Read of Rank5
        fapi2::buffer<uint64_t> l_data;

        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_RD_CONFIG2_P0_VALUES4,
                               MCA_DDRPHY_SEQ_ODT_RD_CONFIG2_P0_VALUES4_LEN>(l_odt_rd[1][0]);
        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_RD_CONFIG2_P0_VALUES5,
                               MCA_DDRPHY_SEQ_ODT_RD_CONFIG2_P0_VALUES5_LEN>(l_odt_rd[1][1]);
        FAPI_INF("odt_rd_config2: 0x%016llx", uint64_t(l_data));
        FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_SEQ_ODT_RD_CONFIG2_P0, l_data) );
    }

    {
        // DPHY01_DDRPHY_SEQ_ODT_RD_CONFIG3_P0
        // 48:55, ATTR_VPD_ODT_RD[0][1][2]; # when Read of Rank6
        // 56:63, ATTR_VPD_ODT_RD[0][1][3]; # when Read of Rank7
        fapi2::buffer<uint64_t> l_data;

        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_RD_CONFIG3_P0_VALUES6,
                               MCA_DDRPHY_SEQ_ODT_RD_CONFIG3_P0_VALUES6_LEN>(l_odt_rd[1][2]);
        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_RD_CONFIG3_P0_VALUES7,
                               MCA_DDRPHY_SEQ_ODT_RD_CONFIG3_P0_VALUES7_LEN>(l_odt_rd[1][3]);
        FAPI_INF("odt_rd_config3: 0x%016llx", uint64_t(l_data));
        FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_SEQ_ODT_RD_CONFIG3_P0, l_data) );
    }

    //
    // ODT Write
    //
    {
        // DPHY01_DDRPHY_SEQ_ODT_WR_CONFIG0_P0
        // 48:55, ATTR_VPD_ODT_WR[0][0][0]; # when Read of Rank0
        // 56:63, ATTR_VPD_ODT_WR[0][0][1]; # when Read of Rank1
        fapi2::buffer<uint64_t> l_data;

        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_WR_CONFIG0_P0_VALUES0,
                               MCA_DDRPHY_SEQ_ODT_WR_CONFIG0_P0_VALUES0_LEN>(l_odt_wr[0][0]);
        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_WR_CONFIG0_P0_VALUES1,
                               MCA_DDRPHY_SEQ_ODT_WR_CONFIG0_P0_VALUES1_LEN>(l_odt_wr[0][1]);
        FAPI_INF("odt_wr_config0: 0x%016llx", uint64_t(l_data));
        FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_SEQ_ODT_WR_CONFIG0_P0, l_data) );
    }

    {
        // DPHY01_DDRPHY_SEQ_ODT_WR_CONFIG1_P0
        // 48:55, ATTR_VPD_ODT_WR[0][0][2]; # when Read of Rank2
        // 56:63, ATTR_VPD_ODT_WR[0][0][3]; # when Read of Rank3
        fapi2::buffer<uint64_t> l_data;

        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_WR_CONFIG1_P0_VALUES2,
                               MCA_DDRPHY_SEQ_ODT_WR_CONFIG1_P0_VALUES2_LEN>(l_odt_wr[0][2]);
        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_WR_CONFIG1_P0_VALUES3,
                               MCA_DDRPHY_SEQ_ODT_WR_CONFIG1_P0_VALUES3_LEN>(l_odt_wr[0][3]);
        FAPI_INF("odt_wr_config1: 0x%016llx", uint64_t(l_data));
        FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_SEQ_ODT_WR_CONFIG1_P0, l_data) );
    }

    {
        // DPHY01_DDRPHY_SEQ_ODT_WR_CONFIG2_P0
        // 48:55, ATTR_VPD_ODT_WR[0][1][0]; # when Read of Rank4
        // 56:63, ATTR_VPD_ODT_WR[0][1][1]; # when Read of Rank5
        fapi2::buffer<uint64_t> l_data;

        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_WR_CONFIG2_P0_VALUES4,
                               MCA_DDRPHY_SEQ_ODT_WR_CONFIG2_P0_VALUES4_LEN>(l_odt_wr[1][0]);
        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_WR_CONFIG2_P0_VALUES5,
                               MCA_DDRPHY_SEQ_ODT_WR_CONFIG2_P0_VALUES5_LEN>(l_odt_wr[1][1]);
        FAPI_INF("odt_wr_config2: 0x%016llx", uint64_t(l_data));
        FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_SEQ_ODT_WR_CONFIG2_P0, l_data) );
    }

    {
        // DPHY01_DDRPHY_SEQ_ODT_WR_CONFIG3_P0
        // 48:55, ATTR_VPD_ODT_WR[0][1][2]; # when Read of Rank6
        // 56:63, ATTR_VPD_ODT_WR[0][1][3]; # when Read of Rank7
        fapi2::buffer<uint64_t> l_data;

        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_WR_CONFIG3_P0_VALUES6,
                               MCA_DDRPHY_SEQ_ODT_WR_CONFIG3_P0_VALUES6_LEN>(l_odt_wr[1][2]);
        l_data.insertFromRight<MCA_DDRPHY_SEQ_ODT_WR_CONFIG3_P0_VALUES7,
                               MCA_DDRPHY_SEQ_ODT_WR_CONFIG3_P0_VALUES7_LEN>(l_odt_wr[1][3]);
        FAPI_INF("odt_wr_config3: 0x%016llx", uint64_t(l_data));
        FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_SEQ_ODT_WR_CONFIG3_P0, l_data) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Start the DLL calibration, monitor for fails.
/// @param[in] i_target the target associated with this DLL cal
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode dll_calibration( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target )
{
    uint8_t is_sim = 0;
    fapi2::buffer<uint64_t> l_status;
    constexpr uint64_t l_dll_status_reg = pcTraits<TARGET_TYPE_MCA>::PC_DLL_ZCAL_CAL_STATUS_REG;
    const auto& l_mca = mss::find_targets<TARGET_TYPE_MCA>(i_target);

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<TARGET_TYPE_SYSTEM>(), is_sim) );

    // Nothing works here in cycle sim ...
    if (is_sim)
    {
        return FAPI2_RC_SUCCESS;
    }

    // If we don't have any MCA, we can go
    if (l_mca.size() == 0)
    {
        return FAPI2_RC_SUCCESS;
    }

    // 14. Begin DLL calibrations by setting INIT_RXDLL_CAL_RESET=0 in the DDRPHY_DP16_DLL_CNTL{0:1} registers
    // and DDRPHY_ADR_DLL_CNTL registers
    for (const auto& p : l_mca)
    {
        // Note: Keep INIT_RXDLL_CAL_UPDATE at 0 to ensure PC CAL_GOOD indicator is accurate.
        // Read, modify, write the DLL_RESET in the ADR_DLL registers
        {
            std::vector<fapi2::buffer<uint64_t>> i_read;

            FAPI_TRY(mss::scom_suckah(p, adr32sTraits<TARGET_TYPE_MCA>::DLL_CNFG_REG, i_read));
            std::for_each( i_read.begin(), i_read.end(),
                           [](fapi2::buffer<uint64_t>& b)
            {
                adr32s::set_dll_cal_reset(b);
            } );
            FAPI_TRY(mss::scom_blastah(p, adr32sTraits<TARGET_TYPE_MCA>::DLL_CNFG_REG, i_read));
        }

        // Read, modify, write the DLL_RESET in the DP16_DLL registers
        {
            std::vector< std::pair<fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t> > > i_read;

            FAPI_TRY(mss::scom_suckah(p, dp16Traits<TARGET_TYPE_MCA>::DLL_CNTRL_REG, i_read));

            size_t l_index = 0;

            for (const auto& r : dp16Traits<TARGET_TYPE_MCA>::DLL_CNTRL_REG)
            {
                mss::states l_state = (r.second == MCA_DDRPHY_DP16_DLL_CNTL1_P0_4) ? mss::HIGH : mss::LOW;

                dp16::set_dll_cal_reset(i_read[l_index].first,  mss::LOW);
                dp16::set_dll_cal_reset(i_read[l_index].second, l_state);
                l_index += 1;
            }

            FAPI_TRY(mss::scom_blastah(p, dp16Traits<TARGET_TYPE_MCA>::DLL_CNTRL_REG, i_read));
        }
    }

    // The [delay value] gives software a reasonable amount of time to wait for an individual
    // DLL to calibrate starting from when it is taken out of reset. As some internal state machine transitions
    // between steps may not have been counted, software should add some margin.
    // 32,772 dphy_nclk cycles from Reset=0 to VREG Calibration to exhaust all values
    // 37,382 dphy_nclk cycles for full calibration to start and fail (“worst case”)
    // More or less a fake value for sim delay as this isn't executed in sim.
    fapi2::delay(mss::cycles_to_ns(i_target, 37382), DELAY_1US);

    // 15. Monitor the DDRPHY_PC_DLL_ZCAL_CAL_STATUS register to determine when calibration is
    // complete. One of the 3 bits will be asserted for ADR and DP16.
    // To keep things simple, we'll poll for the change in one of the ports. Once that's completed, we'll
    // check the others. If any one has failed, or isn't notifying complete, we'll pop out an error
    mss::poll(l_mca[0], l_dll_status_reg, poll_parameters(),
              [&l_status](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_INF("phy control dll/zcal stat 0x%llx, remaining: %d", stat_reg, poll_remaining);
        l_status = stat_reg;
        return mss::pc::get_dll_cal_status(l_status) != mss::INVALID;
    });

    for (const auto& p : l_mca)
    {
        fapi2::buffer<uint64_t> l_read;
        FAPI_TRY( mss::getScom(p, l_dll_status_reg, l_read) );
        FAPI_ASSERT(mss::pc::get_dll_cal_status(l_read) == mss::YES,
                    fapi2::MSS_DLL_FAILED_TO_CALIBRATE().set_MCA_IN_ERROR(p),
                    "dll fapiled to calibrate: %s", mss::c_str(p));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Flush the output drivers
/// @param[in] i_target the target associated with the phy reset sequence
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode flush_output_drivers( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target )
{
    fapi2::buffer<uint64_t> l_adr_data;
    fapi2::buffer<uint64_t> l_dp16_data;

    // Need to run on the magic ports too
    const auto l_ports = mss::find_targets_with_magic<TARGET_TYPE_MCA>(i_target);
    const auto& l_force_atest_reg = adr32sTraits<TARGET_TYPE_MCA>::OUTPUT_DRIVER_REG;
    const auto& l_data_dir_reg = dp16Traits<TARGET_TYPE_MCA>::DATA_BIT_DIR1;

    // Per PHY review 8/16, setup the DATA_BIT_DIR1 with advance_ping_pong and delay_ping_pong_half
    mss::dp16::set_adv_pp(l_dp16_data, mss::HIGH);
    mss::dp16::set_delay_pp_half(l_dp16_data, mss::HIGH);

    // 8. Set FLUSH=1 and INIT_IO=1 in the DDRPHY_ADR_OUTPUT_FORCE_ATEST_CNTL and DDRPHY_DP16_DATA_BIT_DIR1 register
    {
        mss::adr32s::set_output_flush( l_adr_data, mss::HIGH );
        mss::adr32s::set_init_io( l_adr_data, mss::HIGH);
        FAPI_TRY( mss::scom_blastah(l_ports, l_force_atest_reg, l_adr_data) );

        mss::dp16::set_output_flush( l_dp16_data, mss::HIGH );
        mss::dp16::set_init_io( l_dp16_data, mss::HIGH);
        FAPI_TRY( mss::scom_blastah(l_ports, l_data_dir_reg, l_dp16_data) );
    }

    // 9. Wait at least 32 dphy_gckn clock cycles.
    fapi2::delay(mss::cycles_to_ns(i_target, 32), mss::cycles_to_simcycles(1024));

    // 10. Set FLUSH=0 and INIT_IO=0 in the DDRPHY_ADR_OUTPUT_FORCE_ATEST_CNTL register and
    // DDRPHY_DP16_DATA_BIT_DIR1 register
    {
        mss::adr32s::set_output_flush( l_adr_data, mss::LOW );
        mss::adr32s::set_init_io( l_adr_data, mss::LOW);
        FAPI_TRY( mss::scom_blastah(l_ports, l_force_atest_reg, l_adr_data) );

        mss::dp16::set_output_flush( l_dp16_data, mss::LOW );
        mss::dp16::set_init_io( l_dp16_data, mss::LOW);
        FAPI_TRY( mss::scom_blastah(l_ports, l_data_dir_reg, l_dp16_data) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // ns mss
