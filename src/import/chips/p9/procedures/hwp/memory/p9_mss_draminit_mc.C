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

        // While we're doing the scominit in here, lets do it for all ports before we dump the MCS regs.
        for (auto p : i_target.getChildren<TARGET_TYPE_MCA>())
        {
            mss::mc<TARGET_TYPE_MCS> l_mc;

            // Don't do this yet - leverage the sim inits for the moment
#if 0
            // All the scominit for this MCA
            l_mc.scominit(p);
#endif
            // Setup the MC port/dimm address translation registers
            FAPI_TRY( l_mc.setup_xlate_map(p) );
        }

        // Setup the read_pointer_delay
        // TK: Do we need to do this in general or is this a place holder until the
        // init file gets here?
        {
            fapi2::buffer<uint64_t> l_data;
            FAPI_TRY( mss::getScom(i_target, MCBIST_MBSEC0Q, l_data) );
            l_data.insertFromRight<MCA_RECR_MBSECCQ_READ_POINTER_DELAY, MCA_RECR_MBSECCQ_READ_POINTER_DELAY_LEN>(0x1);
            FAPI_DBG("writing read pointer delay 0x%016lx", l_data);
            FAPI_TRY( mss::putScom(i_target, MCBIST_MBSEC0Q, l_data) );
        }

        for (auto p : l_mca)
        {

            // Set the IML Complete bit MBSSQ(3) (SCOM Addr: 0x02011417) to indicate that IML has completed
            // Can't find MBSSQ or the iml_complete bit - asked Steve. Gary VH created this bit as a scratch
            // 'you are hre bit' and it was removed for Nimbus. Gary VH asked for it to be put back in. Not
            // sure if that happened yet. BRS (2/16).

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

            // Cram a fast write, followed by a read in here for giggles
            {
                mss::mcbist::program<TARGET_TYPE_MCBIST> l_program;
                uint64_t l_start = 0;
                uint64_t l_end = 0;
                uint64_t l_pattern = 0;

                // Write
                {
                    // Uses address register set 0
                    mss::mcbist::subtest_t<TARGET_TYPE_MCBIST> l_fw_subtest =
                        mss::mcbist::write_subtest<TARGET_TYPE_MCBIST>();
                    l_fw_subtest.enable_port(mss::index(p));

                    // HACK: We only need to worry about the DIMM in slot 0 right now
                    l_fw_subtest.enable_dimm(0);
                    l_program.iv_subtests.push_back(l_fw_subtest);
                }

                // Read
                {
                    // Uses address register set 0
                    mss::mcbist::subtest_t<TARGET_TYPE_MCBIST> l_fr_subtest =
                        mss::mcbist::read_subtest<TARGET_TYPE_MCBIST>();
                    l_fr_subtest.enable_port(mss::index(p));

                    // HACK: We only need to worry about the DIMM in slot 0 right now
                    l_fr_subtest.enable_dimm(0);
                    l_program.iv_subtests.push_back(l_fr_subtest);
                }


                FAPI_TRY( mss::mcbist_start_addr(p, l_start) );
                FAPI_TRY( mss::mcbist_end_addr(p, l_end) );

                // TK: calculate proper polling based on address range

                // Setup a nice pattern for writing
                FAPI_TRY( mss::mcbist_write_data(i_target, l_pattern) );
                FAPI_TRY( mss::putScom(i_target, MCBIST_MCBFD0Q, l_pattern) );
                FAPI_TRY( mss::putScom(i_target, MCBIST_MCBFD1Q, l_pattern) );
                FAPI_TRY( mss::putScom(i_target, MCBIST_MCBFD2Q, l_pattern) );
                FAPI_TRY( mss::putScom(i_target, MCBIST_MCBFD3Q, l_pattern) );
                FAPI_TRY( mss::putScom(i_target, MCBIST_MCBFD4Q, l_pattern) );
                FAPI_TRY( mss::putScom(i_target, MCBIST_MCBFD5Q, l_pattern) );
                FAPI_TRY( mss::putScom(i_target, MCBIST_MCBFD6Q, l_pattern) );
                FAPI_TRY( mss::putScom(i_target, MCBIST_MCBFD7Q, l_pattern) );

                // Sanity check - can't do much if end is before start.
                // This is either a programming error or a mistake in attribute settings. So we'll just assert.
                if (l_end < l_start)
                {
                    FAPI_ERR("mcbist end address is less than mcbist starting address. s: 0x%x e: 0x%x", l_start, l_end);
                    fapi2::Assert(false);
                }

                // By default we're in maint address mode so we do a start + len and the 'BIST increments for us.
                // By default, the write subtest uses the 0'th address start/end registers.
                mss::mcbist::config_address_range0(i_target, l_start, l_end - l_start);

                // Just one port for now. Per Shelton we need to set this in maint adress mode
                // even tho we specify the port/dimm in the subtest.
                fapi2::buffer<uint8_t> l_port;
                l_port.setBit(mss::pos(p));
                l_program.select_ports(l_port >> 4);

                // Kick it off, wait for a result
                FAPI_TRY( mss::mcbist::execute(i_target, l_program) );
            }
        }

    fapi_try_exit:
        FAPI_INF("End draminit MC");
        return fapi2::current_err;
    }
}
