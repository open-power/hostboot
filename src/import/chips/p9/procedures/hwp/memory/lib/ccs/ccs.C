/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/ccs/ccs.C $                */
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
/// @file ccs.C
/// @brief Run and manage the CCS engine
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Craig Hamilton <cchamilt@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <mss.H>
#include <lib/ccs/ccs.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;

using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{
namespace ccs
{

///
/// @brief Start or stop the CCS engine
/// @param[in] i_target The MCBIST containing the CCS engine
/// @param[in] i_start_stop bool MSS_CCS_START for starting, MSS_CCS_STOP otherwise
/// @return FAPI2_RC_SUCCESS iff success
///
template<>
fapi2::ReturnCode start_stop( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target, bool i_start_stop )
{
    typedef ccsTraits<TARGET_TYPE_MCBIST> TT;

    fapi2::buffer<uint64_t> l_buf;

    // Do we need to read this? We are setting the only bit defined in the scomdef? BRS
    FAPI_TRY(mss::getScom(i_target, TT::CNTLQ_REG, l_buf));

    FAPI_TRY( mss::putScom(i_target, TT::CNTLQ_REG,
                           i_start_stop ? l_buf.setBit<TT::CCS_START>() : l_buf.setBit<TT::CCS_STOP>()) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determine the CCS failure type
/// @tparam T the fapi2 target type of the target for this error
/// @param[in] i_target
/// @param[in] i_type the failure type
/// @return ReturnCode associated with the fail.
/// @note FFDC is handled here, caller doesn't need to do it
///
template< fapi2::TargetType T >
fapi2::ReturnCode fail_type( const fapi2::Target<T>& i_target, const uint64_t& i_type )
{
    FAPI_ASSERT(STAT_READ_MISCOMPARE != i_type,
                fapi2::MSS_CCS_READ_MISCOMPARE().set_TARGET_IN_ERROR(i_target),
                "CCS FAIL Read Miscompare");

    FAPI_ASSERT(STAT_UE_SUE != i_type,
                fapi2::MSS_CCS_UE_SUE().set_TARGET_IN_ERROR(i_target),
                "CCS FAIL UE or SUE Error");

    FAPI_ASSERT(STAT_CAL_TIMEOUT != i_type,
                fapi2::MSS_CCS_CAL_TIMEOUT().set_TARGET_IN_ERROR(i_target),
                "CCS FAIL Calibration Operation Time Out");

    FAPI_ASSERT(STAT_HUNG != i_type,
                fapi2::MSS_CCS_HUNG().set_TARGET_IN_ERROR(i_target),
                "CCS appears hung");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Execute the contents of the CCS array
/// @param[in] i_target The MCBIST containing the array
/// @param[in] i_program the MCBIST ccs program - to get the polling parameters
/// @return FAPI2_RC_SUCCESS iff success
///
template<>
fapi2::ReturnCode execute_inst_array(const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                                     ccs::program<TARGET_TYPE_MCBIST>& i_program)
{
    typedef ccsTraits<TARGET_TYPE_MCBIST> TT;

    fapi2::buffer<uint64_t> status;

    FAPI_TRY(start_stop(i_target, mss::START));

    mss::poll(i_target, TT::STATQ_REG, i_program.iv_poll,
              [&status](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_DBG("ccs statq 0x%llx, remaining: %d", stat_reg, poll_remaining);
        status = stat_reg;
        return status.getBit<TT::CCS_IN_PROGRESS>() != 1;
    },
    i_program.iv_probes);

    // Check for done and success. DONE being the only bit set.
    if (status == STAT_QUERY_SUCCESS)
    {
        FAPI_DBG("CCS Executed Successfully.");
        goto fapi_try_exit;
    }

    // So we failed or we're still in progress. Mask off the fail bits
    // and run this through the FFDC generator.
    FAPI_TRY( fail_type(i_target, status & 0x1C00000000000000) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Execute a set of CCS instructions
/// @param[in] i_target the target to effect
/// @param[in] i_program the vector of instructions
/// @param[in] i_ports the vector of ports
/// @return FAPI2_RC_SUCCSS iff ok
/// @note assumes the CCS engine has been configured.
///
template<>
fapi2::ReturnCode execute( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                           ccs::program<TARGET_TYPE_MCBIST>& i_program,
                           const std::vector< fapi2::Target<TARGET_TYPE_MCA> >& i_ports)
{
    // Subtract one for the idle we insert at the end
    static const size_t CCS_INSTRUCTION_DEPTH = 32 - 1;
    static const uint64_t CCS_ARR0_ZERO = MCBIST_CCS_INST_ARR0_00;
    static const uint64_t CCS_ARR1_ZERO = MCBIST_CCS_INST_ARR1_00;

    ccs::instruction_t<TARGET_TYPE_MCBIST> l_des = ccs::des_command<TARGET_TYPE_MCBIST>();

    FAPI_DBG("loading ccs instructions (%d) for %s", i_program.iv_instructions.size(), mss::c_str(i_target));

    auto l_inst_iter = i_program.iv_instructions.begin();

    while (l_inst_iter != i_program.iv_instructions.end())
    {
        size_t l_inst_count = 0;

        uint64_t l_total_delay = 0;
        uint64_t l_delay = 0;
        uint64_t l_repeat = 0;

        // Shove the instructions into the CCS engine, in 32 instruction chunks, and execute them
        for (; l_inst_iter != i_program.iv_instructions.end()
             && l_inst_count < CCS_INSTRUCTION_DEPTH; ++l_inst_count, ++l_inst_iter)
        {
            // Make sure this instruction leads to the next. Notice this limits this mechanism to pretty
            // simple (straight line) CCS programs. Anything with a loop or such will need another mechanism.
            l_inst_iter->arr1.insertFromRight<MCBIST_CCS_INST_ARR1_00_GOTO_CMD,
                        MCBIST_CCS_INST_ARR1_00_GOTO_CMD_LEN>(l_inst_count + 1);
            FAPI_TRY( mss::putScom(i_target, CCS_ARR0_ZERO + l_inst_count, l_inst_iter->arr0) );
            FAPI_TRY( mss::putScom(i_target, CCS_ARR1_ZERO + l_inst_count, l_inst_iter->arr1) );

            // arr1 contains a specification of the delay and repeat after this instruction, as well
            // as a repeat. Total up the delays as we go so we know how long to wait before polling
            // the CCS engine for completion
            l_inst_iter->arr1.extractToRight<MCBIST_CCS_INST_ARR1_00_IDLES, MCBIST_CCS_INST_ARR1_00_IDLES_LEN>(l_delay);
            l_inst_iter->arr1.extractToRight<MCBIST_CCS_INST_ARR1_00_REPEAT_CMD_CNT,
                        MCBIST_CCS_INST_ARR1_00_REPEAT_CMD_CNT>(l_repeat);

            l_total_delay += l_delay * (l_repeat + 1);

            FAPI_DBG("css inst %d: 0x%016lX 0x%016lX (0x%lx, 0x%lx) delay: 0x%x (0x%x) %s",
                     l_inst_count, l_inst_iter->arr0, l_inst_iter->arr1,
                     CCS_ARR0_ZERO + l_inst_count, CCS_ARR1_ZERO + l_inst_count,
                     l_delay, l_total_delay, mss::c_str(i_target));
        }

        // Check our program for any delays. If there isn't a iv_initial_delay configured, then
        // we use the delay we just summed from the instructions.
        if (i_program.iv_poll.iv_initial_delay == 0)
        {
            i_program.iv_poll.iv_initial_delay = cycles_to_ns(i_target, l_total_delay);
        }

        if (i_program.iv_poll.iv_initial_sim_delay == 0)
        {
            i_program.iv_poll.iv_initial_sim_delay = cycles_to_simcycles(l_total_delay);
        }

        FAPI_DBG("executing ccs instructions (%d:%d, %d) for %s",
                 i_program.iv_instructions.size(), l_inst_count, i_program.iv_poll.iv_initial_delay, mss::c_str(i_target));

        // Insert a DES as our last instruction. DES is idle state anyway and having this
        // here as an instruction forces the CCS engine to wait the delay specified in
        // the last instruction in this array (which it otherwise doesn't do.)
        l_des.arr1.setBit<MCBIST_CCS_INST_ARR1_00_END>();
        FAPI_TRY( mss::putScom(i_target, CCS_ARR0_ZERO + l_inst_count, l_des.arr0) );
        FAPI_TRY( mss::putScom(i_target, CCS_ARR1_ZERO + l_inst_count, l_des.arr1) );

        FAPI_DBG("css inst %d fixup: 0x%016lX 0x%016lX (0x%lx, 0x%lx) %s",
                 l_inst_count, l_des.arr0, l_des.arr1,
                 CCS_ARR0_ZERO + l_inst_count, CCS_ARR1_ZERO + l_inst_count, mss::c_str(i_target));

        // Kick off the CCS engine - per port. No broadcast mode for CCS (per Shelton 9/23/15)
        for (auto p : i_ports)
        {
            FAPI_DBG("executing CCS array for port %d (%s)", mss::relative_pos<TARGET_TYPE_MCBIST>(p), mss::c_str(p));
            FAPI_TRY( select_ports( i_target, mss::relative_pos<TARGET_TYPE_MCBIST>(p)) );
            FAPI_TRY( execute_inst_array(i_target, i_program) );
        }
    }

fapi_try_exit:
    i_program.iv_instructions.clear();
    return fapi2::current_err;
}

///
/// @brief Nimbus specialization for modeq_copy_cke_to_spare_cke
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the ccsTraits associated with T - derived
/// @param[in] fapi2::Target<TARGET_TYPE_MCBIST>& the target to effect
/// @param[in] the buffer representing the mode register
/// @param[in] bool true iff Copy CKE signals to CKE Spare on both ports
/// @return void
/// @note no-op for p9n
///
template<>
void copy_cke_to_spare_cke<TARGET_TYPE_MCBIST>( const fapi2::Target<TARGET_TYPE_MCBIST>&, fapi2::buffer<uint64_t>&,
        bool )
{
    return;
}

} // namespace
} // namespace
