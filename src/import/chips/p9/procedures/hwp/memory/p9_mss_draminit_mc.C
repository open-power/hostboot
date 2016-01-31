/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/p9_mss_draminit_mc.C $         */
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
/// @file p9_mss_draminit_mc.C
/// @brief Initialize the memory controller to take over the DRAM
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <mss.H>

#include "p9_mss_draminit_mc.H"

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;

extern "C"
{
///
/// @brief Initialize the MC now that DRAM is up
/// @param[in] i_target, the McBIST of the ports
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode p9_mss_draminit_mc( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
    {
        auto l_mca = i_target.getChildren<TARGET_TYPE_MCA>();

        FAPI_INF("Start draminit MC");

        // If we don't have any ports, lets go.
        if (l_mca.size() == 0)
        {
            FAPI_INF("No ports? %s", mss::c_str(i_target));
            return fapi2::FAPI2_RC_SUCCESS;
        }

        // Dump the registers of these MC
        for (auto c : i_target.getChildren<TARGET_TYPE_MCS>())
        {
            FAPI_TRY( mss::dump_regs<TARGET_TYPE_MCS>(c) );
        }

        for (auto p : l_mca)
        {
            // Set the IML Complete bit MBSSQ(3) (SCOM Addr: 0x02011417) to indicate that IML has completed
            // Can't find MBSSQ or the iml_complete bit - asked Steve BRS.

            // Reset addr_mux_sel to “0” to allow the MCA to take control of the DDR interface over from CCS.
            // (Note: this step must remain in this procedure to ensure that data path is placed into mainline
            // mode prior to running memory diagnostics. When Advanced DRAM Training executes, this step
            // becomes superfluous but not harmful. However, it's not guaranteed that Advanced DRAM Training
            // will be executed on every system configuration.)
            // Note: addr_mux_sel is set low in p9_mss_draminit(), however that might be a work-around so we
            // set it low here kind of like belt-and-suspenders. BRS
            FAPI_TRY( mss::change_addr_mux_sel(p, mss::LOW) );

            // Step Two.1: Check RCD protect time on RDIMM and LRDIMM
            // Step Two.2: Enable address inversion on each MBA for ALL CARDS

            // Start the refresh engines by setting MBAREF0Q(0) = “1”. Note that the remaining bits in
            // MBAREF0Q should retain their initialization values.
            FAPI_TRY( mss::change_refresh_enable(p, mss::HIGH) );

            // Power management is handled in the init file. (or should be BRS)

            // Enabling periodic calibration
            FAPI_TRY( mss::enable_periodic_cal(p) );

            // Step Six: Setup Control Bit ECC
            FAPI_TRY( mss::enable_read_ecc(p) );

            // At this point the DDR interface must be monitored for memory errors. Memory related FIRs should be unmasked.
        }

    fapi_try_exit:
        FAPI_INF("End draminit MC");
        return fapi2::current_err;
    }
}
