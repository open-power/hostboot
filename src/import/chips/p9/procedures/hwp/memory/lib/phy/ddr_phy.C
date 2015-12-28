/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/phy/ddr_phy.C $            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
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
#include "../mss.H"

#include "ddr_phy.H"
#include "../utils/bit_count.H"

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
/// @brief Blast one peice of data across a vector of addresses
/// @param[in] i_target, the target for the scom
/// @param[in] const std::vector<uint64_t>&, addresses
/// @param[in] const fapi2::buffer<uint64_t>&, the data to blast
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Author is originally from Boston (Pahk mah cah in Havahd Yahd)

/// @note std::transform might have been tidier, but because of the ReturnCode
/// and the FAPI_TRY mechanism, this is the simplest.
///
template< fapi2::TargetType T >
fapi2::ReturnCode scom_blastah( const fapi2::Target<T>& i_target, const std::vector<uint64_t>& i_addrs,
                                const fapi2::buffer<uint64_t>& i_data )
{
    size_t count(0);

    for (auto a : i_addrs)
    {
        FAPI_TRY( fapi2::putScom(i_target, a, i_data) );
        ++count;
    }

    return fapi2::current_err;

fapi_try_exit:
    FAPI_ERR( "scom_blastah failed: %d of %d executed against %s", count, i_addrs.size(), mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief Blast one peice of data across a vector of targets
/// @param[in] the vector of targets for the scom
/// @param[in] the address
/// @param[in] const fapi2::buffer<uint64_t>&, the data to blast
/// @return FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode scom_blastah( const std::vector<fapi2::Target<T> >& i_targets, const uint64_t i_addr,
                                const fapi2::buffer<uint64_t>& i_data )
{
    size_t count(0);

    for (auto t : i_targets)
    {
        FAPI_TRY( fapi2::putScom(t, i_addr, i_data) );
        ++count;
    }

    return fapi2::current_err;

fapi_try_exit:
    FAPI_ERR( "scom_blastah failed: %d of %d written to 0x%llx", count, i_targets.size(), i_addr);
    return fapi2::current_err;
}

///
/// @brief Blast one peice of data across a vector of targets
/// @param[in] the vector of targets for the scom
/// @param[in] the vector of addresses
/// @param[in] const fapi2::buffer<uint64_t>&, the data to blast
/// @return FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode scom_blastah( const std::vector<fapi2::Target<T> >& i_targets,
                                const std::vector<uint64_t>& i_addrs,
                                const fapi2::buffer<uint64_t>& i_data )
{
    size_t count(0);

    for (auto t : i_targets)
    {
        FAPI_TRY( mss::scom_blastah(t, i_addrs, i_data) );
        ++count;
    }

    return fapi2::current_err;

fapi_try_exit:
    FAPI_ERR( "scom_blastah failed: %d of %dx%d", count, i_targets.size(), i_addrs.size() );
    return fapi2::current_err;
}

///
/// @brief change resetn to the given state
/// @param[in] i_target, the mcbist
/// @param[in] the desired state
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode change_resetn( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target, states i_state )
{
    fapi2::buffer<uint64_t> l_data;

    for (auto p : i_target.getChildren<TARGET_TYPE_MCA>())
    {
        FAPI_DBG("Change reset to %s PHY: %s", (i_state == HIGH ? "high" : "low"), mss::c_str(p));

        FAPI_TRY( fapi2::getScom(p, MCA_MBA_CAL0Q, l_data) );
        i_state == HIGH ? l_data.setBit<MCA_MBA_CAL0Q_RESET_RECOVER>() : l_data.clearBit<MCA_MBA_CAL0Q_RESET_RECOVER>();
        FAPI_TRY( fapi2::putScom(p, MCA_MBA_CAL0Q, l_data) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief perform the zctl toggle process
/// @param[in] i_target, the mcbist for the reset recover
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode toggle_zctl( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    fapi2::buffer<uint64_t> l_data;

    auto l_ports = i_target.getChildren<TARGET_TYPE_MCA>();
    //
    // 4. Write 0x0010 to PC IO PVT N/P FET driver control registers to assert ZCTL reset and enable the internal impedance controller.
    // (SCOM Addr: 0x8000C0140301143F,  0x8000C0140301183F, 0x8001C0140301143F, 0x8001C0140301183F)
    FAPI_DBG("Write 0x0010 to PC IO PVT N/P FET driver control registers to assert ZCTL reset");
    l_data.setBit<59>();
    FAPI_TRY( mss::scom_blastah(l_ports, MCA_DDRPHY_PC_IO_PVT_FET_CONTROL_P0, l_data) );

    //
    // 5. Write 0x0018 to PC IO PVT N/P FET driver control registers to deassert ZCTL reset while impedance controller is still enabled.
    //    (SCOM Addr: 0x8000C0140301143F,  0x8000C0140301183F, 0x8001C0140301143F, 0x8001C0140301183F)
    FAPI_DBG("Write 0x0018 to PC IO PVT N/P FET driver control registers to deassert ZCTL reset.");
    l_data.setBit<59>().setBit<60>();
    FAPI_TRY( mss::scom_blastah(l_ports, MCA_DDRPHY_PC_IO_PVT_FET_CONTROL_P0, l_data) );

    //
    // 6. Write 0x0008 to PC IO PVT N/P FET driver control registers to deassert the impedance controller.
    //    (SCOM Addr: 0x8000C0140301143F,  0x8000C0140301183F, 0x8001C0140301143F, 0x8001C0140301183F)

    FAPI_DBG("Write 0x0008 to PC IO PVT N/P FET driver control registers to deassert the impedance controller");
    l_data.clearBit<59>().setBit<60>();
    FAPI_TRY( mss::scom_blastah(l_ports, MCA_DDRPHY_PC_IO_PVT_FET_CONTROL_P0, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Change mclk low
/// @param[in] mcbist target
/// @param[in] mss::HIGH or mss::LOW - desired state.
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode change_force_mclk_low (const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
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

    FAPI_DBG("force mclk %s for all ports", (i_state == mss::LOW ? "low" : "high") );

    // Might as well do this for all the ports while we're here.
    for (auto p : i_target.getChildren<TARGET_TYPE_MCA>())
    {
        FAPI_TRY(fapi2::getScom( p, MCA_MBA_FARB5Q, l_data));

        if (i_state == mss::HIGH)
        {
            l_data.setBit<MCA_MBA_FARB5Q_CFG_FORCE_MCLK_LOW_N>();
        }
        else
        {
            l_data.clearBit<MCA_MBA_FARB5Q_CFG_FORCE_MCLK_LOW_N>();
        }

        FAPI_TRY(fapi2::putScom( p, MCA_MBA_FARB5Q, l_data));
    }

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Unset the PLL and check to see that the PLL's have started
/// @param[in] the mcbist target
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode deassert_pll_reset( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    fapi2::buffer<uint64_t> l_data;

#ifdef KNOW_ADR_DLL_PROCESS
    static const uint64_t dp16_lock_mask = 0x000000000000FFFE;
    static const uint64_t ad_lock_mask = fapi2::buffer<uint64_t>().setBit<48>().setBit<49>();
#endif

    //
    // Write 0x4000 into the PC Resets Registers. This deasserts the PLL_RESET and leaves the SYSCLK_RESET bit active
    //                                                (SCOM Addr: 0x8000C00E0301143F, 0x8001C00E0301143F, 0x8000C00E0301183F, 0x8001C00E0301183F)
    FAPI_DBG("Write 0x4000 into the PC Resets Regs. This deasserts the PLL_RESET and leaves the SYSCLK_RESET bit active");

    l_data.setBit<MCA_DDRPHY_PC_RESETS_P0_SYSCLK_RESET>();
    FAPI_TRY( mss::scom_blastah(i_target.getChildren<TARGET_TYPE_MCA>(), MCA_DDRPHY_PC_RESETS_P0, l_data) );

    //
    // Wait at least 1 millisecond to allow the PLLs to lock. Otherwise, poll the PC DP18 PLL Lock Status
    //    and the PC AD32S PLL Lock Status to determine if all PLLs have locked.
    //    PC DP18 PLL Lock Status should be 0xF800:  (SCOM Addr: 0x8000C0000301143F, 0x8001C0000301143F, 0x8000C0000301183F, 0x8001C0000301183F)
    //    PC AD32S PLL Lock Status should be 0xC000: (SCOM Addr: 0x8000C0010301143F, 0x8001C0010301143F, 0x8000C0010301183F, 0x8001C0010301183F)

#ifdef KNOW_ADR_DLL_PROCESS
    // Poll for lock bits
    FAPI_DBG("Poll until DP18 and AD32S PLLs have locked");

    do
    {
        // Set in the CHECK_PLL macro
        done_polling = true;

        fapi2::delay(DELAY_1US, cycles_to_simcycles(us_to_cycles(i_target, 1)));

        // Note: in the latest scomdef this is DP16 BRS
        // Note: Not sure what the proper registers here are. I took the following old addresses from Ed's
        // version of the code and mapped the addresses to the latests mc_scom_addresses.H. This needs to
        // be fixed up when the extended addressing is fixed up. BRS

        // CONST_UINT64_T(DDRPHY_PC_DP18_PLL_LOCK_STATUS_P0_0x8000C0000701143F,                  ULL(0x8000C0000701143F) );
        CHECK_PLL( l_target_proc, MCA_0_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P0, l_data, dp16_lock_mask );

        // CONST_UINT64_T(DDRPHY_PC_DP18_PLL_LOCK_STATUS_P1_0x8001C0000701143F,                  ULL(0x8001C0000701143F) );
        CHECK_PLL( l_target_proc, MCA_1_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P1, l_data, dp16_lock_mask );

        // CONST_UINT64_T(DDRPHY_PC_DP18_PLL_LOCK_STATUS_P2_0x8000C0000701183F,                  ULL(0x8000C0000701183F) );
        CHECK_PLL( l_target_proc, MCA_2_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P2, l_data, dp16_lock_mask );

        // CONST_UINT64_T(DDRPHY_PC_DP18_PLL_LOCK_STATUS_P3_0x8001C0000701183F,                  ULL(0x8001C0000701183F) );
        CHECK_PLL( l_target_proc, MCA_3_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P3, l_data, dp16_lock_mask );

        // CONST_UINT64_T( DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P0_0x8000C0010701143F,        ULL(0x8000C0010701143F) );
        CHECK_PLL( l_target_proc, MCA_0_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P0, l_data, ad_lock_mask );

        // CONST_UINT64_T( DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P1_0x8001C0010701143F,        ULL(0x8001C0010701143F) );
        CHECK_PLL( l_target_proc, MCA_1_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P1, l_data, ad_lock_mask );

        // CONST_UINT64_T( DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P2_0x8000C0010701183F,        ULL(0x8000C0010701183F) );
        CHECK_PLL( l_target_proc, MCA_2_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P2, l_data, ad_lock_mask );

        // CONST_UINT64_T( DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P3_0x8001C0010701183F,        ULL(0x8001C0010701183F) );
        CHECK_PLL( l_target_proc, MCA_3_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P3, l_data, ad_lock_mask );
    }
    while (!done_polling && --max_poll_loops);

    // If we ran out of iterations, report we have a pll lock failure.
    if (max_poll_loops == 0)
    {
        FAPI_ERR("DDR PHY PLL failed to lock for %s", mss::c_str(i_target));
        FFDC_PLL( l_target_proc, MCA_0_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P0, l_data, dp16_lock_mask,
                  fapi2::MSS_DP16_PLL_FAILED_TO_LOCK() );
        FFDC_PLL( l_target_proc, MCA_1_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P1, l_data, dp16_lock_mask,
                  fapi2::MSS_DP16_PLL_FAILED_TO_LOCK() );
        FFDC_PLL( l_target_proc, MCA_2_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P2, l_data, dp16_lock_mask,
                  fapi2::MSS_DP16_PLL_FAILED_TO_LOCK() );
        FFDC_PLL( l_target_proc, MCA_3_DDRPHY_PC_DP18_PLL_LOCK_STATUS_P3, l_data, dp16_lock_mask,
                  fapi2::MSS_DP16_PLL_FAILED_TO_LOCK() );

        FFDC_PLL( l_target_proc, MCA_0_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P0, l_data, ad_lock_mask,
                  fapi2::MSS_AD32S_PLL_FAILED_TO_LOCK() );
        FFDC_PLL( l_target_proc, MCA_1_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P1, l_data, ad_lock_mask,
                  fapi2::MSS_AD32S_PLL_FAILED_TO_LOCK() );
        FFDC_PLL( l_target_proc, MCA_2_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P2, l_data, ad_lock_mask,
                  fapi2::MSS_AD32S_PLL_FAILED_TO_LOCK() );
        FFDC_PLL( l_target_proc, MCA_3_DDRPHY_PC_AD32S_PLL_LOCK_STATUS_P3, l_data, ad_lock_mask,
                  fapi2::MSS_AD32S_PLL_FAILED_TO_LOCK() );
    }

#endif
fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Setup the phase rotator control registers
/// @param[in] the mcbist target
/// @param[in] the value for the registers
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode setup_phase_rotator_control_registers( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
        const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_DBG("Write 0x%lx into the ADR SysClk Phase Rotator Control Regs and the DP18 SysClk Phase Rotator Control Regs",
             i_data);

    std::vector<uint64_t> addrs(
    {
        MCA_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S0, MCA_DDRPHY_ADR_SYSCLK_CNTL_PR_P0_ADR32S1,
        MCA_DDRPHY_DP16_WRCLK_PR_P0_0, MCA_DDRPHY_DP16_WRCLK_PR_P0_1,
        MCA_DDRPHY_DP16_WRCLK_PR_P0_2, MCA_DDRPHY_DP16_WRCLK_PR_P0_3, MCA_DDRPHY_DP16_WRCLK_PR_P0_4,
    } );

    FAPI_TRY( mss::scom_blastah(i_target.getChildren<TARGET_TYPE_MCA>(), addrs, i_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Deassetr the sys clk reset
/// @param[in] the mcbist target
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode deassert_sysclk_reset( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    FAPI_DBG("Write 0x0000 into the PC Resets Register. This deasserts the SysClk Reset.");
    FAPI_TRY( mss::scom_blastah(i_target.getChildren<TARGET_TYPE_MCA>(), MCA_DDRPHY_PC_RESETS_P0, 0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Flush the DDR PHY
/// @param[in] the mcbist target
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode ddr_phy_flush( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    fapi2::buffer<uint64_t> l_data;
    fapi2::buffer<uint64_t> l_mask;

    FAPI_INF( "Performing mss_ddr_phy_flush routine" );

    FAPI_INF("ADR/DP18 FLUSH: 1) set PC_POWERDOWN_1 register, powerdown enable(48), flush bit(58)");
    // set MASTER_PD_CNTL bit set WR_FIFO_STAB bit
    l_data.setBit<48>().setBit<58>();
    l_mask.setBit<48>().setBit<58>();

    auto l_ports = i_target.getChildren<TARGET_TYPE_MCA>();

    for (auto p : l_ports)
    {
        FAPI_TRY(fapi2::putScomUnderMask(p, MCA_DDRPHY_PC_POWERDOWN_1_P0, l_data, l_mask) );
    }

    fapi2::delay(DELAY_100NS, cycles_to_simcycles(ns_to_cycles(i_target, 100)));

    FAPI_INF("ADR/DP18 FLUSH: 2) clear PC_POWERDOWN_1 register, powerdown enable(48), flush bit(58)");

    for (auto p : l_ports)
    {
        FAPI_TRY(fapi2::putScomUnderMask(p, MCA_DDRPHY_PC_POWERDOWN_1_P0, 0, l_mask) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Send a scom to all instances of a block on the phy.
/// @param[in] the MCA target
/// @param[in] the address
/// @param[in] the value
/// @note this iterates creating addresses - needs to change to use the
/// braodcast bits in the phy when we can scom it directly.
///
static inline fapi2::ReturnCode phy_block_broadcast( const fapi2::Target<TARGET_TYPE_MCA>& i_target,
        const uint64_t l_addr,
        const fapi2::buffer<uint64_t> i_data)
{
#ifndef BROADSIDE_SCOM_ONLY
    static const size_t PHY_INSTANCE_COUNT = 5;

    // We have to use a dull knife since broadisde scom has to have the address in
    // the scomdef. When we get a full system model (or the PIE driver supports scomming
    // the PHY) we can use the broadcast bits and iterate over the DIMM ranks.
    for (size_t i = 0; i < PHY_INSTANCE_COUNT; ++i)
    {
        FAPI_TRY( fapi2::putScom(i_target, l_addr | fapi2::buffer<uint64_t>().insertFromRight<18, 4>(i), i_data) );
    }

fapi_try_exit:
    return fapi2::current_err;
#endif
}

///
/// @brief Lock dphy_gckn and sysclk
/// @param[in] a port target
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode bang_bang_lock( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    fapi2::buffer<uint64_t> l_start_update(0x8024);
    fapi2::buffer<uint64_t> l_stop_update(0x8020);

    // Per Bialas, we don't want to do true alignment in the cycle sim as we have
    // a chnace of being off one-tick (which is detremental.) Per his recomendations,
    // we write 0's to the control registers and then configure them with x8080.
    uint8_t is_sim = 0;
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<TARGET_TYPE_SYSTEM>(), is_sim) );

    if (is_sim)
    {
        l_start_update = 0x0;
        l_stop_update = 0x8080;
    }

    // 9.
    FAPI_TRY( mss::setup_phase_rotator_control_registers(i_target, l_start_update),
              "set up of phase rotator controls failed (in to cont update) %s", mss::c_str(i_target) );

    //
    // 10.Wait at least 5932 memory clock cycles to allow the clock alignment circuit to perform initial alignment.
    // wait 2000 simcycles per Ed Maj,
    FAPI_DBG("Wait at least 5932 memory clock cycles to allow the clock alignment circuit to perform initial alignment");
    FAPI_TRY( fapi2::delay(mss::cycles_to_ns(i_target, 5932), 2000) );

    //
    // 11.Write 0x0000 into the PC Resets Register. This deasserts the SysClk Reset
    //                                                (SCOM Addr: 0x8000C00E0301143F, 0x8001C00E0301143F, 0x8000C00E0301183F, 0x8001C00E0301183F)
    FAPI_TRY( mss::deassert_sysclk_reset(i_target), "deassert_sysclk_reset failed for %s", mss::c_str(i_target) );

    // 12.
    FAPI_TRY( mss::setup_phase_rotator_control_registers(i_target, l_stop_update),
              "set up of phase rotator controls failed (out of cont update) %s", mss::c_str(i_target) );

    // 13.
    FAPI_DBG("Wait at least 32 memory clock cycles");
    FAPI_TRY( fapi2::delay(mss::cycles_to_ns(i_target, 32), mss::cycles_to_simcycles(32)) );

    // Don't bother in cycle sim, we don't do the actual aligment
    if (!is_sim)
    {
        // Check for BB lock.
        for (auto p : i_target.getChildren<TARGET_TYPE_MCA>())
        {
            FAPI_DBG("Wait for BB lock in status register, bit %u",
                     MCA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S0_ADR0_BB_LOCK);

            FAPI_ASSERT( mss::poll(p, MCA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S0, mss::poll_parameters(DELAY_100NS),
                                   [](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
            {
                FAPI_DBG("stat_reg 0x%llx, remaining: %d", stat_reg, poll_remaining);
                return stat_reg.getBit<MCA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S0_ADR0_BB_LOCK>();
            }),
            fapi2::MSS_BANG_BANG_FAILED_TO_LOCK().set_MCA_IN_ERROR(p),
            "MCA %s failed bang-bang alignment", mss::c_str(p) );
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return the DIMM target for the primary rank in the specificed rank pair
/// @param[in] the MCA target
/// @param[in] the rank pair
/// @param[out] fapi2::Target<TARGET_TYPE_DIMM>
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode rank_pair_primary_to_dimm(
    const fapi2::Target<TARGET_TYPE_MCA>& i_target,
    const uint64_t i_rp,
    fapi2::Target<TARGET_TYPE_DIMM>& o_dimm)
{
    fapi2::buffer<uint64_t> l_data;
    fapi2::buffer<uint64_t> l_rank;
    uint64_t l_rank_on_dimm;
    auto l_dimms = i_target.getChildren<TARGET_TYPE_DIMM>();

    // Sanity check the rank pair
    FAPI_INF("%s rank pair: %d", mss::c_str(i_target), i_rp);

    fapi2::Assert(i_rp < MAX_RANK_PER_DIMM);

    // We need to get the register containing the specification for this rank pair,
    // and fish out the primary rank for this rank pair
    switch(i_rp)
    {
        case 0:
            FAPI_TRY( fapi2::getScom(i_target, MCA_DDRPHY_PC_RANK_PAIR0_P0, l_data) );
            l_data.extractToRight<MCA_DDRPHY_PC_RANK_PAIR0_P0_PRI,
                                  MCA_DDRPHY_PC_RANK_PAIR0_P0_PRI_LEN>(l_rank);
            break;

        case 1:
            FAPI_TRY( fapi2::getScom(i_target, MCA_DDRPHY_PC_RANK_PAIR0_P0, l_data) );
            l_data.extractToRight<MCA_DDRPHY_PC_RANK_PAIR0_P0_PAIR1_PRI,
                                  MCA_DDRPHY_PC_RANK_PAIR0_P0_PAIR1_PRI_LEN>(l_rank);
            break;

        case 2:
            FAPI_TRY( fapi2::getScom(i_target, MCA_DDRPHY_PC_RANK_PAIR1_P0, l_data) );
            l_data.extractToRight<MCA_DDRPHY_PC_RANK_PAIR1_P0_PAIR2_PRI,
                                  MCA_DDRPHY_PC_RANK_PAIR1_P0_PAIR2_PRI_LEN>(l_rank);
            break;

        case 3:
            FAPI_TRY( fapi2::getScom(i_target, MCA_DDRPHY_PC_RANK_PAIR1_P0, l_data) );
            l_data.extractToRight<MCA_DDRPHY_PC_RANK_PAIR1_P0_PAIR3_PRI,
                                  MCA_DDRPHY_PC_RANK_PAIR1_P0_PAIR3_PRI_LEN>(l_rank);
            break;
    };

    // Now we need to figure out which DIMM this rank is on. It's either on DIMM0 or DIMM1, and DIMM0
    // has ranks 0-3 and DIMM1 has ranks 4-7. Return the DIMM associated.
    l_rank_on_dimm = get_dimm_from_rank(l_rank);

    // Sanity check the DIMM list
    FAPI_INF("%s rank is on dimm: %d, number of dimms: %d", mss::c_str(i_target), l_rank_on_dimm, l_dimms.size());

    fapi2::Assert(l_rank_on_dimm < l_dimms.size());

    o_dimm = l_dimms[l_rank_on_dimm];

    return FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief check and process initial cal errors
/// @param[in] the port in question
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff no error
///
template<>
fapi2::ReturnCode process_initial_cal_errors( const fapi2::Target<TARGET_TYPE_MCA>& i_target )
{
    static const uint64_t init_cal_err_mask = 0x7FF;

    uint64_t l_errors = 0;
    uint64_t l_rank_pairs = 0;

    fapi2::buffer<uint64_t> l_fir_data;
    fapi2::buffer<uint64_t> l_err_data;

    fapi2::Target<TARGET_TYPE_DIMM> l_failed_dimm;

    FAPI_TRY( fapi2::getScom(i_target, MCA_DDRPHY_APB_FIR_ERR1_P0, l_fir_data) );

    FAPI_DBG("initial cal FIR: 0x%016llx", uint64_t(l_fir_data));

    if ((init_cal_err_mask & l_fir_data) == 0)
    {
        return FAPI2_RC_SUCCESS;
    }

    // We have bits to check ...
    FAPI_TRY( fapi2::getScom(i_target, MCA_DDRPHY_PC_INIT_CAL_ERROR_P0, l_err_data) );

    l_err_data.extractToRight<MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_WR_LEVEL, 11>(l_errors);
    l_err_data.extractToRight<MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_RANK_PAIR,
                              MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_RANK_PAIR_LEN>(l_rank_pairs);
    FAPI_DBG("initial cal err: 0x%016llx, rp: 0x%016llx (0x%016llx)", l_errors, l_rank_pairs, uint64_t(l_err_data));

    if ((l_rank_pairs == 0) || (l_errors == 0))
    {
        FAPI_INF("Initial CAL FIR is 0x%016llx but missing info in the error register: 0x%016llx",
                 l_fir_data, l_err_data);
        return FAPI2_RC_SUCCESS;
    }

    // Get the DIMM which failed. We should only have one rank pair as we calibrate the
    // rank pairs individually (we do this so we can see which DIMM failed if more than one
    // fails ...) Note first_bit_set gives a bit position (0 being left most.) So, the rank
    // in question is the bit postion minus the position of the 0th rank in the register.
    // (the rank bits are bits 60:63, for example, so rank 0 is in position 60)
    FAPI_TRY( mss::rank_pair_primary_to_dimm(i_target,
              mss::first_bit_set(l_rank_pairs) - MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_RANK_PAIR,
              l_failed_dimm) );
    FAPI_ERR("initial cal failed for %s", mss::c_str(l_failed_dimm));

    // So we can do a few things here. If we're aborting on the first calibration error,
    // we only expect to have one error bit set. If we ran all the calibrations, we can
    // either have one bit set or more than one bit set. If we have more than one bit set
    // the result is the same - a broken DIMM which will be deconfigured. So put enough
    // information in the FFDC for the lab but we don't need one error for every cal fail.
    FAPI_ASSERT(mss::bit_count(l_errors) == 1,
                fapi2::MSS_DRAMINIT_TRAINING_MULTIPLE_ERRORS()
                .set_FAILED_STEPS(uint64_t(l_err_data))
                .set_PORT_POSITION(mss::pos(i_target))
                .set_RANKGROUP_POSITION(l_rank_pairs)
                .set_TARGET_IN_ERROR(l_failed_dimm),
                "Initial CAL failed multiple training steps. dimm: %s, cal err: 0x%016llx",
                mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

    FAPI_ASSERT( ! l_err_data.getBit<MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_WR_LEVEL>(),
                 fapi2::MSS_DRAMINIT_TRAINING_WR_LVL_ERROR()
                 .set_PORT_POSITION(mss::pos(i_target))
                 .set_RANKGROUP_POSITION(l_rank_pairs)
                 .set_TARGET_IN_ERROR(l_failed_dimm),
                 "Initial CAL failed write leveling. dimm: %s, cal err: 0x%016llx",
                 mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

    FAPI_ASSERT( ! l_err_data.getBit<MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_INITIAL_PAT_WRITE>(),
                 fapi2::MSS_DRAMINIT_TRAINING_INITIAL_PAT_WRITE_ERROR()
                 .set_PORT_POSITION(mss::pos(i_target))
                 .set_RANKGROUP_POSITION(l_rank_pairs)
                 .set_TARGET_IN_ERROR(l_failed_dimm),
                 "Initial CAL failed initial pattern write. dimm: %s, cal err: 0x%016llx",
                 mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

    FAPI_ASSERT( ! l_err_data.getBit<MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_DQS_ALIGN>(),
                 fapi2::MSS_DRAMINIT_TRAINING_DQS_ALIGNMENT_ERROR()
                 .set_PORT_POSITION(mss::pos(i_target))
                 .set_RANKGROUP_POSITION(l_rank_pairs)
                 .set_TARGET_IN_ERROR(l_failed_dimm),
                 "Initial CAL failed DQS alignenment. dimm: %s, cal err: 0x%016llx",
                 mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

    FAPI_ASSERT( ! l_err_data.getBit<MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_RDCLK_ALIGN>(),
                 fapi2::MSS_DRAMINIT_TRAINING_RD_CLK_SYS_CLK_ALIGNMENT_ERROR()
                 .set_PORT_POSITION(mss::pos(i_target))
                 .set_RANKGROUP_POSITION(l_rank_pairs)
                 .set_TARGET_IN_ERROR(l_failed_dimm),
                 "Initial CAL failed read clk alignenment. dimm: %s, cal err: 0x%016llx",
                 mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

    FAPI_ASSERT( ! l_err_data.getBit<MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_READ_CTR>(),
                 fapi2::MSS_DRAMINIT_TRAINING_RD_CENTERING_ERROR()
                 .set_PORT_POSITION(mss::pos(i_target))
                 .set_RANKGROUP_POSITION(l_rank_pairs)
                 .set_TARGET_IN_ERROR(l_failed_dimm),
                 "Initial CAL failed read centering. dimm: %s, cal err: 0x%016llx",
                 mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

    FAPI_ASSERT( ! l_err_data.getBit<MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_WRITE_CTR>(),
                 fapi2::MSS_DRAMINIT_TRAINING_WR_CENTERING_ERROR()
                 .set_PORT_POSITION(mss::pos(i_target))
                 .set_RANKGROUP_POSITION(l_rank_pairs)
                 .set_TARGET_IN_ERROR(l_failed_dimm),
                 "Initial CAL failed write centering. dimm: %s, cal err: 0x%016llx",
                 mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

    FAPI_ASSERT( ! l_err_data.getBit<MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_INITIAL_COARSE_WR>(),
                 fapi2::MSS_DRAMINIT_TRAINING_INITIAL_COARSE_WR_ERROR()
                 .set_PORT_POSITION(mss::pos(i_target))
                 .set_RANKGROUP_POSITION(l_rank_pairs)
                 .set_TARGET_IN_ERROR(l_failed_dimm),
                 "Initial CAL failed initial coarse write. dimm: %s, cal err: 0x%016llx",
                 mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

    FAPI_ASSERT( ! l_err_data.getBit<MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_COARSE_RD>(),
                 fapi2::MSS_DRAMINIT_TRAINING_COARSE_RD_ERROR()
                 .set_PORT_POSITION(mss::pos(i_target))
                 .set_RANKGROUP_POSITION(l_rank_pairs)
                 .set_TARGET_IN_ERROR(l_failed_dimm),
                 "Initial CAL failed coarse read. dimm: %s, cal err: 0x%016llx",
                 mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

    FAPI_ASSERT( ! l_err_data.getBit<MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_CUSTOM_RD>(),
                 fapi2::MSS_DRAMINIT_TRAINING_CUSTOM_PATTERN_RD_ERROR()
                 .set_PORT_POSITION(mss::pos(i_target))
                 .set_RANKGROUP_POSITION(l_rank_pairs)
                 .set_TARGET_IN_ERROR(l_failed_dimm),
                 "Initial CAL failed custom read. dimm: %s, cal err: 0x%016llx",
                 mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

    FAPI_ASSERT( ! l_err_data.getBit<MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_CUSTOM_WR>(),
                 fapi2::MSS_DRAMINIT_TRAINING_CUSTOM_PATTERN_WR_ERROR()
                 .set_PORT_POSITION(mss::pos(i_target))
                 .set_RANKGROUP_POSITION(l_rank_pairs)
                 .set_TARGET_IN_ERROR(l_failed_dimm),
                 "Initial CAL failed custom write. dimm: %s, cal err: 0x%016llx",
                 mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

    FAPI_ASSERT( ! l_err_data.getBit<MCA_DDRPHY_PC_INIT_CAL_ERROR_P0_DIGITAL_EYE>(),
                 fapi2::MSS_DRAMINIT_TRAINING_DIGITAL_EYE_ERROR()
                 .set_PORT_POSITION(mss::pos(i_target))
                 .set_RANKGROUP_POSITION(l_rank_pairs)
                 .set_TARGET_IN_ERROR(l_failed_dimm),
                 "Initial CAL failed digital eye. dimm: %s, cal err: 0x%016llx",
                 mss::c_str(l_failed_dimm), uint64_t(l_err_data)
               );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setup the PC CONFIG0 register
/// @tparam T the fapi2::TargetType
/// @param[in] the target (MCA or MBA?)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode set_pc_config0(const fapi2::Target<TARGET_TYPE_MCA>& i_target)
{
    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY( fapi2::getScom(i_target, MCA_DDRPHY_PC_CONFIG0_P0, l_data) );

    // Note: This needs to get the DRAM gen from an attribute. - 0x1 is DDR4 Note for Nimbus PHY
    // this is ignored and hard-wired to DDR4, per John Bialas 10/15 BRS
    l_data.insertFromRight<MCA_DDRPHY_PC_CONFIG0_P0_PROTOCOL, MCA_DDRPHY_PC_CONFIG0_P0_PROTOCOL_LEN>(0x1);

    l_data.setBit<MCA_DDRPHY_PC_CONFIG0_P0_DDR4_CMD_SIG_REDUCTION>();
    l_data.setBit<MCA_DDRPHY_PC_CONFIG0_P0_DDR4_VLEVEL_BANK_GROUP>();

    FAPI_DBG("phy pc_config0 0x%0llx", l_data);
    FAPI_TRY( fapi2::putScom(i_target, MCA_DDRPHY_PC_CONFIG0_P0, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setup the PC CONFIG1 register
/// @tparam T the fapi2::TargetType
/// @param[in] the target (MCA or MBA?)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode set_pc_config1(const fapi2::Target<TARGET_TYPE_MCA>& i_target)
{
    // Static table of PHY config values for MEMORY_TYPE.
    // [EMPTY, RDIMM, CDIMM, or LRDIMM][EMPTY, DDR3 or DDR4]
    static const uint64_t memory_type[4][3] =
    {
        { 0, 0,     0     },  // Empty, never really used.
        { 0, 0b001, 0b101 },  // RDIMM
        { 0, 0b000, 0b000 },  // CDIMM
        { 0, 0b011, 0b111 },  // LRDIMM
    };

    fapi2::buffer<uint64_t> l_data;

    uint8_t l_rlo = 0;
    uint8_t l_wlo = 0;
    uint8_t l_dram_gen[MAX_DIMM_PER_PORT]    = {0};
    uint8_t l_dimm_type[MAX_DIMM_PER_PORT]   = {0};
    uint8_t l_custom_dimm[MAX_DIMM_PER_PORT] = {0};
    uint8_t l_type_index = 0;
    uint8_t l_gen_index = 0;

    FAPI_TRY( mss::vpd_rlo(i_target, l_rlo) );
    FAPI_TRY( mss::vpd_wlo(i_target, l_wlo) );
    FAPI_TRY( mss::eff_dram_gen(i_target, &(l_dram_gen[0])) );
    FAPI_TRY( mss::eff_dimm_type(i_target, &(l_dimm_type[0])) );
    FAPI_TRY( mss::eff_custom_dimm(i_target, &(l_custom_dimm[0])) );

    // There's no way to configure the PHY for more than one value. However, we don't know if there's
    // a DIMM in one slot, the other or double drop. So we do a little gyration here to make sure
    // we have one of the two values (and assume effective config caught a bad config.)
    l_type_index = (l_custom_dimm[0] | l_custom_dimm[1]) == fapi2::ENUM_ATTR_EFF_CUSTOM_DIMM_YES ?
                   2 : l_dimm_type[0] | l_dimm_type[1];
    l_gen_index = l_dram_gen[0] | l_dram_gen[1];

    // FOR NIMBUS PHY (as the protocol choice above is) BRS
    FAPI_TRY( fapi2::getScom(i_target, MCA_DDRPHY_PC_CONFIG1_P0, l_data) );

    l_data.insertFromRight<MCA_DDRPHY_PC_CONFIG1_P0_MEMORY_TYPE,
                           MCA_DDRPHY_PC_CONFIG1_P0_MEMORY_TYPE_LEN>(memory_type[l_type_index][l_gen_index]);
    l_data.insertFromRight<MCA_DDRPHY_PC_CONFIG1_P0_READ_LATENCY_OFFSET,
                           MCA_DDRPHY_PC_CONFIG1_P0_READ_LATENCY_OFFSET_LEN>(l_rlo);
    l_data.insertFromRight<MCA_DDRPHY_PC_CONFIG1_P0_WRITE_LATENCY_OFFSET,
                           MCA_DDRPHY_PC_CONFIG1_P0_WRITE_LATENCY_OFFSET_LEN>(l_wlo);

    l_data.setBit<MCA_DDRPHY_PC_CONFIG1_P0_DDR4_LATENCY_SW>();

    FAPI_DBG("phy pc_config1 0x%0llx", l_data);
    FAPI_TRY( fapi2::putScom(i_target, MCA_DDRPHY_PC_CONFIG1_P0, l_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations for the PHY
/// @param[in] i_target, the MCBIST which has the PHYs to initialize
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode phy_scominit(const fapi2::Target<TARGET_TYPE_MCBIST>& i_target)
{
    // Returned from set_rank_pairs, it tells us how many rank pairs we configured on this port.
    std::vector<uint64_t> l_pairs;

    for( auto p : i_target.getChildren<TARGET_TYPE_MCA>())
    {
        // The following registers must be configured to the correct operating environment:

        // Undocumented, noted by Bialas
        FAPI_TRY( mss::set_pc_config0(p) );
        FAPI_TRY( mss::set_pc_config1(p) );

        // Section 5.2.1.3 PC Rank Pair 0 on page 177
        // Section 5.2.1.4 PC Rank Pair 1 on page 179
        FAPI_TRY( mss::set_rank_pairs(p) );

        // Section 5.2.4.1 DP16 Data Bit Enable 0 on page 284
        // Section 5.2.4.2 DP16 Data Bit Enable 1 on page 285
        // Section 5.2.4.3 DP16 Data Bit Disable 0 on page 288
        // Section 5.2.4.4 DP16 Data Bit Disable 1 on page 289
        FAPI_TRY( mss::dp16::write_data_bit_enable(p) );
        FAPI_TRY( mss::dp16::set_bad_bits(p) );

        FAPI_TRY( mss::get_rank_pairs(p, l_pairs) );

        // Section 5.2.4.8 DP16 Write Clock Enable & Clock Selection on page 301
        FAPI_TRY( mss::dp16::write_clock_enable(p, l_pairs) );
        FAPI_TRY( mss::dp16::read_clock_enable(p, l_pairs) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

}
