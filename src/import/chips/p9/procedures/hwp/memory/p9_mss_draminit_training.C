/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/p9_mss_draminit_training.C $   */
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
/// @file p9_mss_draminit_training.C
/// @brief Train dram
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <mss.H>

#include "p9_mss_draminit_training.H"

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;

extern "C"
{
///
/// @brief Train dram
/// @param[in] i_target, the McBIST of the ports of the dram you're training
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode p9_mss_draminit_training( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
    {
        fapi2::buffer<uint16_t> l_cal_steps_enabled;

        FAPI_INF("Start draminit training");

        uint8_t l_reset_disable = 0;
        FAPI_TRY( mss::draminit_reset_disable(l_reset_disable) );

        // Configure the CCS engine.
        {
            fapi2::buffer<uint64_t> l_ccs_config;

            FAPI_TRY( mss::ccs::read_mode(i_target, l_ccs_config) );

            // It's unclear if we want to run with this true or false. Right now (10/15) this
            // has to be false. Shelton was unclear if this should be on or off in general BRS
            mss::ccs::stop_on_err(i_target, l_ccs_config, false);
            mss::ccs::ue_disable(i_target, l_ccs_config, false);
            mss::ccs::copy_cke_to_spare_cke(i_target, l_ccs_config, true);

            // Hm. Centaur sets this up for the longest duration possible. Can we do better?
            mss::ccs::cal_count(i_target, l_ccs_config, ~0, ~0);

#ifndef JIM_SAYS_TURN_OFF_ECC
            mss::ccs::disable_ecc(i_target, l_ccs_config);
#endif
            FAPI_TRY( mss::ccs::write_mode(i_target, l_ccs_config) );
        }

        // Clean out any previous calibration results, set bad-bits and configure the ranks.
        FAPI_DBG("MCA's on this McBIST: %d", i_target.getChildren<TARGET_TYPE_MCA>().size());

        for( auto p : i_target.getChildren<TARGET_TYPE_MCA>())
        {
            mss::ccs::program<TARGET_TYPE_MCBIST> l_program;

            // Delays in the CCS instruction ARR1 for training are supposed to be 0xFFFF,
            // and we're supposed to poll for the done or timeout bit. But we don't want
            // to wait 0xFFFF cycles before we start polling - that's too long. So we put
            // in a best-guess of how long to wait. This, in a perfect world, would be the
            // time it takes one rank to train one training algorithm times the number of
            // ranks we're going to train. We fail-safe as worst-case we simply poll the
            // register too much - so we can tune this as we learn more.
            l_program.iv_poll.iv_initial_sim_delay = mss::DELAY_100US;
            l_program.iv_poll.iv_initial_sim_delay = 200;
            l_program.iv_poll.iv_poll_count = 0xFFFF;

            // Returned from set_rank_pairs, it tells us how many rank pairs
            // we configured on this port.
            std::vector<uint64_t> l_pairs;

#ifdef CAL_STATUS_DOESNT_REPORT_COMPLETE
            // This isn't correct - shouldn't be setting
            static const uint64_t CLEAR_CAL_COMPLETE = 0x000000000000F000;
            FAPI_TRY( mss::putScom(p, MCA_DDRPHY_PC_INIT_CAL_STATUS_P0, CLEAR_CAL_COMPLETE) );
#endif
            FAPI_TRY( mss::putScom(p, MCA_DDRPHY_PC_INIT_CAL_ERROR_P0, 0) );
            FAPI_TRY( mss::putScom(p, MCA_DDRPHY_PC_INIT_CAL_CONFIG0_P0, 0) );

            // Hit the reset button for wr_lvl values. These won't reset until the next run of wr_lvl
            FAPI_TRY( mss::reset_wc_config0(p) );
            FAPI_TRY( mss::reset_wc_config1(p) );
            FAPI_TRY( mss::reset_wc_config2(p) );

            FAPI_TRY( mss::reset_wc_rtt_wr_swap_enable(p) );

            // The following registers must be configured to the correct operating environment:

            // Unclear, can probably be 0's for sim BRS
            // • Section 5.2.5.10 SEQ ODT Write Configuration {0-3} on page 422

            FAPI_TRY( mss::reset_seq_config0(p) );
            FAPI_TRY( mss::reset_seq_rd_wr_data(p) );

            FAPI_TRY( mss::reset_odt_config(p) );

            // These are reset in phy_scominit
            // • Section 5.2.6.1 WC Configuration 0 Register on page 434
            // • Section 5.2.6.2 WC Configuration 1 Register on page 436
            // • Section 5.2.6.3 WC Configuration 2 Register on page 438

            // Get our rank pairs.
            FAPI_TRY( mss::get_rank_pairs(p, l_pairs) );

            // Setup the config register
            //
            // Grab the attribute which contains the information on what cal steps we should run
            FAPI_TRY( mss::cal_step_enable(p, l_cal_steps_enabled) );

            // Check to see if we're supposed to reset the delay values before starting training
            if (l_reset_disable == fapi2::ENUM_ATTR_MSS_DRAMINIT_RESET_DISABLE_ENABLE)
            {
                FAPI_TRY( mss::dp16::reset_delay_values(p, l_pairs) );
            }

            FAPI_TRY( mss::dump_cal_registers(p) );

            FAPI_DBG("generating calibration CCS instructions: %d rank-pairs", l_pairs.size());

            // For each rank pair we need to calibrate, pop a ccs instruction in an array and execute it.
            // NOTE: IF YOU CALIBRATE MORE THAN ONE RANK PAIR PER CCS PROGRAM, MAKE SURE TO CHANGE
            // THE PROCESSING OF THE ERRORS. (it's hard to figure out which DIMM failed, too) BRS.
            for (auto rp : l_pairs)
            {
                auto l_inst = mss::ccs::initial_cal_command<TARGET_TYPE_MCBIST>(rp);

                FAPI_DBG("exeecuting training CCS instruction: 0x%llx, 0x%llx", l_inst.arr0, l_inst.arr1);
                l_program.iv_instructions.push_back(l_inst);

                // We need to figure out how long to wait before we start polling. Each cal step has an expected
                // duration, so for each cal step which was enabled, we update the CCS program.
                FAPI_TRY( mss::cal_timer_setup(p, l_program.iv_poll, l_cal_steps_enabled) );
                FAPI_TRY( mss::setup_cal_config(p, rp, l_cal_steps_enabled) );

                // In the event of an init cal hang, CCS_STATQ(2) will assert and CCS_STATQ(3:5) = “001” to indicate a
                // timeout. Otherwise, if calibration completes, FW should inspect DDRPHY_FIR_REG bits (50) and (58)
                // for signs of a calibration error. If either bit is on, then the DDRPHY_PC_INIT_CAL_ERROR register
                // should be polled to determine which calibration step failed.

                // If we got a cal timeout, or another CCS error just leave now. If we got success, check the error
                // bits for a cal failure. We'll return the proper ReturnCode so all we need to do is FAPI_TRY.
                FAPI_TRY( mss::ccs::execute(i_target, l_program, p) );
                FAPI_TRY( mss::process_initial_cal_errors(p) );
            }
        }

    fapi_try_exit:
        FAPI_INF("End draminit training");
        return fapi2::current_err;
    }
}
