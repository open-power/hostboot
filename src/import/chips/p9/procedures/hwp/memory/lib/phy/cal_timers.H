/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/phy/cal_timers.H $         */
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
/// @file cal_timers.H
/// @brief Subroutines to calculate the duration of training operations
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_CAL_TIMERS_H_
#define _MSS_CAL_TIMERS_H_

#include <fapi2.H>
#include "../shared/mss_const.H"
#include "../utils/conversions.H"
#include "../utils/poll.H"

namespace mss
{

///
/// @brief Return the cycles taken for write leveling on a single rank
/// @tparam T, the target type used to get attributes
/// @param[in] i_target, used to get attributes
/// @return uint64_t, the cycles taken for write leveling on a single rank
///
template<fapi2::TargetType T>
uint64_t wr_lvl_cycles(const fapi2::Target<T>& i_target )
{
    const uint64_t TWLO_TWLOE = mss::twlo_twloe(i_target);

    // This step runs for approximately (80 + TWLO_TWLOE) x NUM_VALID_SAMPLES x (384/(BIG_STEP + 1) +
    // (2 x (BIG_STEP + 1))/(SMALL_STEP + 1)) + 20 memory clock cycles per rank.

    const uint64_t l_wr_lvl_cycles = (80 + TWLO_TWLOE) * WR_LVL_NUM_VALID_SAMPLES * (384 / (WR_LVL_BIG_STEP + 1) +
                                     (2 * (WR_LVL_BIG_STEP + 1)) / (WR_LVL_SMALL_STEP + 1)) + 20;
    FAPI_DBG("wr_lvl_cycles: %llu(%lluns) (%llu, %llu, %llu, %llu)", l_wr_lvl_cycles, mss::cycles_to_ns(i_target,
             l_wr_lvl_cycles),
             TWLO_TWLOE, WR_LVL_NUM_VALID_SAMPLES, WR_LVL_BIG_STEP, WR_LVL_SMALL_STEP);

    return l_wr_lvl_cycles;
}

///
/// @brief Return the cycles taken for DQS align on a single rank
/// @tparam T, the target type used to get attributes
/// @param[in] i_target, used to get attributes
/// @return uint64_t, the cycles taken for DQS align on a single rank
///
template<fapi2::TargetType T>
uint64_t dqs_align_cycles(const fapi2::Target<T>& i_target )
{
    // This step runs for approximately 6 x 600 x 4 DRAM clocks per rank pair.
    const uint64_t l_dqs_align_cycles = 6 * 600 * 4;

    FAPI_DBG("dqs_align_cycles: %llu(%lluns)", l_dqs_align_cycles, mss::cycles_to_ns(i_target, l_dqs_align_cycles));
    return l_dqs_align_cycles;
}

///
/// @brief Return the cycles taken for RD clock align on a single rank
/// @tparam T, the target type used to get attributes
/// @param[in] i_target, used to get attributes
/// @return uint64_t, the cycles taken for RD clock align on a single rank
///
template<fapi2::TargetType T>
uint64_t rdclk_align_cycles(const fapi2::Target<T>& i_target )
{
    // This step runs for approximately 24 x ((1024/COARSE_CAL_STEP_SIZE + 4 x COARSE_CAL_STEP_SIZE) x 4 + 32) DRAM
    // clocks per rank pair
    const uint64_t l_rdclk_align_cycles = 24 * ((1024 / COARSE_CAL_STEP_SIZE + 4 * COARSE_CAL_STEP_SIZE) * 4 + 32);
    FAPI_DBG("rdclk_align_cycles: %llu(%lluns) (%llu)", l_rdclk_align_cycles,
             mss::cycles_to_ns(i_target, l_rdclk_align_cycles), COARSE_CAL_STEP_SIZE);
    return l_rdclk_align_cycles;
}

///
/// @brief Return the cycles taken for read centering on a single rank
/// @tparam T, the target type used to get attributes
/// @param[in] i_target, used to get attributes
/// @return uint64_t, the cycles taken for read centering on a single rank
///
template<fapi2::TargetType T>
uint64_t read_ctr_cycles(const fapi2::Target<T>& i_target )
{
    // This step runs for approximately 6 x (512/COARSE_CAL_STEP_SIZE + 4 x (COARSE_CAL_STEP_SIZE +
    // 4 x CONSEQ_PASS)) x 24 DRAM clocks per rank pair.

    const uint64_t l_read_ctr_cycles = 6 * (512 / COARSE_CAL_STEP_SIZE + 4 * (COARSE_CAL_STEP_SIZE + 4 * CONSEQ_PASS)) * 24;
    FAPI_DBG("read_ctr_cycles %llu(%lluns) (%llu, %llu)", l_read_ctr_cycles, mss::cycles_to_ns(i_target, l_read_ctr_cycles),
             COARSE_CAL_STEP_SIZE, CONSEQ_PASS);
    return l_read_ctr_cycles;
}

///
/// @brief Return the cycles taken for write centering on a single rank
/// @tparam T, the target type used to get attributes
/// @param[in] i_target, used to get attributes
/// @return uint64_t, the cycles taken for write centering on a single rank
///
template<fapi2::TargetType T>
uint64_t write_ctr_cycles(const fapi2::Target<T>& i_target )
{
    // 1000 + (NUM_VALID_SAMPLES * (FW_WR_RD + FW_RD_WR + 16) *
    // (1024/(SMALL_STEP +1) + 128/(BIG_STEP +1)) + 2 * (BIG_STEP+1)/(SMALL_STEP+1)) x 24 DRAM
    // clocks per rank pair.
    uint64_t l_write_ctr_cycles = 1000 + (WR_LVL_NUM_VALID_SAMPLES * (WR_CNTR_FW_WR_RD + WR_CNTR_FW_RD_WR + 16) *
                                          (1024 / (WR_LVL_SMALL_STEP + 1) + 128 / (WR_LVL_BIG_STEP + 1)) + 2 *
                                          (WR_LVL_BIG_STEP + 1) / (WR_LVL_SMALL_STEP + 1)) * 24;

    FAPI_DBG("write_ctr_cycles: %lu(%luns) (%u, %u, %u, %u, %u)",
             l_write_ctr_cycles, mss::cycles_to_ns(i_target, l_write_ctr_cycles),
             WR_LVL_NUM_VALID_SAMPLES, WR_CNTR_FW_WR_RD, WR_CNTR_FW_RD_WR, WR_LVL_BIG_STEP, WR_LVL_SMALL_STEP);

    return l_write_ctr_cycles;
}

///
/// @brief Return the cycles taken for coarse write on a single rank
/// @tparam T, the target type used to get attributes
/// @param[in] i_target, used to get attributes
/// @return uint64_t, the cycles taken for coarse write on a single rank
///
template<fapi2::TargetType T>
uint64_t coarse_wr_cycles(const fapi2::Target<T>& i_target )
{
    // The run length given here is the maximum run length for this calibration algorithm.
    // This step runs for approximately 40 DRAM clocks per rank pair.
    static const uint64_t l_coarse_wr_cycles = 40;
    FAPI_DBG("coarse_wr_cycles: %llu(%lluns)", l_coarse_wr_cycles, mss::cycles_to_ns(i_target, l_coarse_wr_cycles));
    return l_coarse_wr_cycles;
}

///
/// @brief Return the cycles taken for coarse read on a single rank
/// @tparam T, the target type used to get attributes
/// @param[in] i_target, used to get attributes
/// @return uint64_t, the cycles taken for coarse rd on a single rank
///
template<fapi2::TargetType T>
uint64_t coarse_rd_cycles(const fapi2::Target<T>& i_target )
{
    // The run length given here is the maximum run length for this calibration algorithm.
    // This step runs for approximately 32 DRAM clocks per rank pair.
    static const uint64_t l_coarse_rd_cycles = 32;
    FAPI_DBG("coarse_rd_cycles: %llu(%lluns)", l_coarse_rd_cycles, mss::cycles_to_ns(i_target, l_coarse_rd_cycles));
    return l_coarse_rd_cycles;
}

///
/// @brief Configure the polling intervals with the proper timeings based on the cal steps enabled
/// @tparam T, the fapi2::TargetType of the port
/// @param[in] i_target, the port target
/// @param[in] the poll_parameters to update
/// @param[in] a fapi2::buffer<uint8_t> representing the cal steps enabled
/// @return FAPI2_RC_SUCCESS iff everything is OK
///
template<fapi2::TargetType T>
inline fapi2::ReturnCode cal_timer_setup(const fapi2::Target<T>& i_target,
        poll_parameters& i_poll,
        const fapi2::buffer<uint16_t>& i_cal_steps_enabled)
{
    // First, calculate the total number of cycles this cal should take if everything
    // runs to completion
    uint64_t l_total_cycles = i_cal_steps_enabled.getBit<WR_LEVEL>() ? wr_lvl_cycles(i_target) : 0;
    l_total_cycles += i_cal_steps_enabled.getBit<DQS_ALIGN>()   ? dqs_align_cycles(i_target)   : 0;
    l_total_cycles += i_cal_steps_enabled.getBit<RDCLK_ALIGN>() ? rdclk_align_cycles(i_target) : 0;
    l_total_cycles += i_cal_steps_enabled.getBit<READ_CTR>()    ? read_ctr_cycles(i_target)    : 0;
    l_total_cycles += i_cal_steps_enabled.getBit<WRITE_CTR>()   ? write_ctr_cycles(i_target)   : 0;
    l_total_cycles += i_cal_steps_enabled.getBit<COARSE_WR>()   ? coarse_wr_cycles(i_target)   : 0;
    l_total_cycles += i_cal_steps_enabled.getBit<COARSE_RD>()   ? coarse_rd_cycles(i_target)   : 0;

    // Now we have to decide if we're going to abort on an error or keep going. If we keep going,
    // then we want our initial delay to be the expected time to completion - we don't have much
    // of a choice. If we abort on error then we want to have a small initial delay, and poll more
    // times with longer durations between the polling.

#define THRASH_CCS_IP_IN_SIM 1
#ifdef THRASH_CCS_IP_IN_SIM

    i_poll.iv_initial_delay = mss::cycles_to_ns(i_target, 1);
    i_poll.iv_initial_sim_delay = mss::cycles_to_simcycles(1);

    i_poll.iv_delay = DELAY_1US;
    i_poll.iv_sim_delay = mss::cycles_to_simcycles(mss::ns_to_cycles(i_target, DELAY_1US));

    // Round up to the cycles left after the initial delay
    int64_t l_ns_left = std::max(0L,
                                 (int64_t(mss::cycles_to_ns(i_target, l_total_cycles)) - int64_t(i_poll.iv_initial_delay)));
    i_poll.iv_poll_count = l_ns_left / i_poll.iv_delay;
    i_poll.iv_poll_count += l_ns_left % i_poll.iv_delay ? 0 : 1;

    // Don't let the poll count be 0 - that just makes for a bad day.
    i_poll.iv_poll_count = (i_poll.iv_poll_count == 0) ? 1 : i_poll.iv_poll_count;
#else

    if (CAL_ABORT_ON_ERROR)
    {
        // We don't want to wait too long for the initial check, just some hueristics here
        i_poll.iv_initial_delay = mss::cycles_to_ns(i_target, l_total_cycles / 8);
        i_poll.iv_initial_sim_delay = mss::cycles_to_simcycles(l_total_cycles / 8);

        // Delay 1us between polls, and setup the poll count so
        // iv_initial_delay + (iv_delay * iv_poll_count) == l_total_cycles;
        i_poll.iv_delay = DELAY_1US;
        i_poll.iv_sim_delay = mss::cycles_to_simcycles(mss::ns_to_cycles(i_target, DELAY_1US));

        // Round up to the cycles left after the initial delay
        int64_t l_ns_left = std::max(0L,
                                     (int64_t(mss::cycles_to_ns(i_target, l_total_cycles)) - int64_t(i_poll.iv_initial_delay)));
        i_poll.iv_poll_count = l_ns_left / i_poll.iv_delay;
        i_poll.iv_poll_count += l_ns_left % i_poll.iv_delay ? 0 : 1;

        // Don't let the poll count be 0 - that just makes for a bad day.
        i_poll.iv_poll_count = (i_poll.iv_poll_count == 0) ? 1 : i_poll.iv_poll_count;
    }
    else
    {
        i_poll.iv_initial_delay = mss::cycles_to_ns(i_target, l_total_cycles);
        i_poll.iv_initial_sim_delay = mss::cycles_to_simcycles(l_total_cycles);
    }

#endif

    FAPI_INF("cal abort on error? %s. tc: %luc, id: %luns(%lusc), d: %lu(%lusc), pc: %lu",
             (CAL_ABORT_ON_ERROR ? "yup" : "nope"), l_total_cycles, i_poll.iv_initial_delay,
             i_poll.iv_initial_sim_delay, i_poll.iv_delay, i_poll.iv_sim_delay, i_poll.iv_poll_count);

    return fapi2::FAPI2_RC_SUCCESS;
}

}
#endif
