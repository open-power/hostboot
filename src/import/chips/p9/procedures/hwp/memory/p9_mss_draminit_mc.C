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

#include <p9_mss_draminit_mc.H>

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
        FAPI_INF("Start draminit MC");

        // No need to check to see if we have ports - this loop will just be skipped
        for (const auto& p : i_target.getChildren<TARGET_TYPE_MCA>())
        {
            mss::mc<TARGET_TYPE_MCS> l_mc;

            // Don't do this yet - leverage the sim inits for the moment
#if 0
            // All the scominit for this MCA
            l_mc.scominit(p);
#endif
            // Setup the MC port/dimm address translation registers
            FAPI_TRY( l_mc.setup_xlate_map(p) );

            // Setup the read_pointer_delay
            // TK: Do we need to do this in general or is this a place holder until the
            // init file gets here?
            {
                fapi2::buffer<uint64_t> l_data;
                FAPI_TRY( mss::getScom(p, MCA_RECR, l_data) );
                l_data.insertFromRight<MCA_RECR_MBSECCQ_READ_POINTER_DELAY, MCA_RECR_MBSECCQ_READ_POINTER_DELAY_LEN>(0x1);
                FAPI_DBG("writing read pointer delay 0x%016lx %s", l_data, mss::c_str(p));
                FAPI_TRY( mss::putScom(p, MCA_RECR, l_data) );
            }

            // Set the IML Complete bit MBSSQ(3) (SCOM Addr: 0x02011417) to indicate that IML has completed
            // Can't find MBSSQ or the iml_complete bit - asked Steve. Gary VH created this bit as a scratch
            // 'you are hre bit' and it was removed for Nimbus. Gary VH asked for it to be put back in. Not
            // sure if that happened yet. BRS (2/16).

            // Reset addr_mux_sel to “0” to allow the MCA to take control of the DDR interface over from CCS.
            // (Note: this step must remain in this procedure to ensure that data path is placed into mainline
            // mode prior to running memory diagnostics. This step maybe superfluous but not harmful.)
            // Note: addr_mux_sel is set low in p9_mss_draminit(), however that might be a work-around so we
            // set it low here kind of like belt-and-suspenders. BRS
            FAPI_TRY( mss::change_addr_mux_sel(p, mss::LOW) );

            // Re-enable port fails. Turned off in draminit_training
            FAPI_TRY( mss::change_port_fail_disable(p, mss::OFF ) );

            // MC work around for OE bug (seen in periodics + PHY)
#ifndef REMOVE_FOR_DD2
            // Turn on output-enable always on. Shelton tells me they'll fix for DD2
            FAPI_TRY( mss::change_oe_always_on(p, mss::ON ) );
#endif
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
