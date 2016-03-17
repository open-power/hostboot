/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/p9_mss_ddr_phy_reset.C $       */
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
/// @file p9_mss_ddr_phy_reset.C
/// @brief Reset the DDR PHY
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <stdint.h>
#include <string.h>

#include <fapi2.H>
#include <mss.H>

#include <p9_mss_ddr_phy_reset.H>

using fapi2::TARGET_TYPE_MCBIST;

extern "C"
{

///
/// @brief Perform a phy reset on all the PHY related to this half-chip (mcbist)
/// @param[in] the mcbist representing the PHY
/// @return FAPI2_RC_SUCCESS iff OK
///
    fapi2::ReturnCode p9_mss_ddr_phy_reset(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target)
    {
        // Cache the name of our target. We can't just keep the pointer from c_str as
        // it points to thread-local space and anything we call might change the string.
        char l_name[fapi2::MAX_ECMD_STRING_LEN];
        strncpy(l_name, mss::c_str(i_target), fapi2::MAX_ECMD_STRING_LEN);

        FAPI_INF("********* %s start *********", __func__);

        // Initialize via scoms. Could be put in to p9_mss_scominit.C if that ever exists BRS.
        FAPI_TRY( mss::phy_scominit(i_target) );

        FAPI_TRY(mss::change_force_mclk_low(i_target, mss::HIGH),
                 "force_mclk_low (set high) Failed rc = 0x%08X", uint64_t(fapi2::current_err) );

        //
        // 1. Drive all control signals to the PHY to their inactive state, idle state, or inactive value.
        FAPI_TRY( mss::dp16::setup_sysclk(i_target) );

        //    (Note: The chip should already be in this state.)
        FAPI_DBG("All control signals to the PHYs should already be set to their inactive state, idle state, or inactive values");

        // 2. Assert reset to PHY for 32 memory clocks
        FAPI_TRY( mss::change_resetn(i_target, mss::HIGH), "change_resetn for %s failed", l_name );
        fapi2::delay(mss::cycles_to_ns(i_target, 32), mss::cycles_to_simcycles(32));

        // 3. Deassert reset_n
        FAPI_TRY( mss::change_resetn(i_target, mss::LOW), "change_resetn for %s failed", l_name );

        // 4, 5, 6.
        FAPI_TRY( mss::toggle_zctl(i_target), "toggle_zctl for %s failed", l_name );

        // 7, 8.
        FAPI_TRY( mss::deassert_pll_reset(i_target), "deassert_pll_reset failed for %s", l_name );

        // 9, 10, 11, 12 & 13. Lock dphy_gckn and sysclk
        FAPI_TRY( mss::bang_bang_lock(i_target) );

        // 14?

        //
        //
        //
        //FIXME:    Need to code..      FAPI_TRY(mss_slew_cal(i_target),
        //      "mss_slew_cal Failed rc = 0x%08X", uint64_t(fapi2::current_err) );
        // slew cal successful
//    FAPI_TRY( mss::slew_cal(i_target), "slew_cal for %s failed", l_name);

        FAPI_TRY( mss::ddr_phy_flush(i_target), "ddr_phy_flush failed for %s", l_name );

#ifdef LEAVES_OUTPUT_TO_DIMM_TRISTATE
        // Per J. Bialas, force_mclk_low can be dasserted.
        FAPI_TRY(mss::change_force_mclk_low(i_target, mss::LOW),
                 "force_mclk_low (set low) Failed rc = 0x%08X", uint64_t(fapi2::current_err) );
#endif

        // If mss_unmask_ddrphy_errors gets it's own bad rc,
        // it will commit the passed in rc (if non-zero), and return it's own bad rc.
        // Else if mss_unmask_ddrphy_errors runs clean,
        // it will just return the passed in rc.
        //FIXME:    Need to code..   FAPI_TRY(mss_unmask_ddrphy_errors(i_target, rc));

        FAPI_INF("********* %s complete *********", __func__);

    fapi_try_exit:
        return fapi2::current_err;

    }

}
