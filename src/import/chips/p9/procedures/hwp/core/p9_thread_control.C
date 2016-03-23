/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/core/p9_thread_control.C $            */
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
/// @file p9_thread_control.C
/// @brief Implementation of sreset, start, stop and step
///

// *HWP HWP Owner: Nick Klazynski <jklazyns@us.ibm.com>
// *HWP FW Owner:  Thi Tran <thi@us.ibm.com>
// *HWP Team:  Quad
// *HWP Level: 2
// Current Status: Only start function tested as working
// *HWP Consumed by: FSP:HB:HS

#include <fapi2.H>
#include <p9_thread_control.H>

using fapi2::TARGET_TYPE_EX;
using fapi2::TARGET_TYPE_CORE;

using fapi2::FAPI2_RC_SUCCESS;

// The control bits for each thread are contained in DIRECT_CONTROLS
// in regular offsets. This map allows us to go from a thread_bitset
// to a generic register with the proper bits set. We can then shift
// this result to align with the actual operation bit in the reg.
// PS. this map works for C_RAS_STATUS as well.
static const uint64_t g_control_reg_map[] =
{
    0x0000000000000000, // b0000, no threads
    0x0000008000000000, // b0001, thread 3
    0x0000800000000000, // b0010, thread 2
    0x0000808000000000, // b0011, thread 2,3
    0x0080000000000000, // b0100, thread 1
    0x0080008000000000, // b0101, thread 1,3
    0x0080800000000000, // b0110
    0x0080808000000000, // b0111
    0x8000000000000000, // b1000
    0x8000008000000000, // b1001
    0x8000800000000000, // b1010
    0x8000808000000000, // b1011
    0x8080000000000000, // b1100
    0x8080008000000000, // b1101
    0x8080800000000000, // b1110
    0x8080808000000000, // b1111
};

//--------------------------------------------------------------------------
// Function definitions
//--------------------------------------------------------------------------

fapi2::ReturnCode p9_thread_control_sreset(
    const fapi2::Target<TARGET_TYPE_CORE>& i_target,
    const uint8_t i_threads, const bool i_warncheck,
    fapi2::buffer<uint64_t>& o_rasStatusReg);

fapi2::ReturnCode p9_thread_control_start(
    const fapi2::Target<TARGET_TYPE_CORE>& i_target,
    const uint8_t i_threads, const bool i_warncheck,
    fapi2::buffer<uint64_t>& o_rasStatusReg);

fapi2::ReturnCode p9_thread_control_stop(
    const fapi2::Target<TARGET_TYPE_CORE>& i_target,
    const uint8_t i_threads, const bool i_warncheck,
    fapi2::buffer<uint64_t>& o_rasStatusReg);

fapi2::ReturnCode p9_thread_control_step(
    const fapi2::Target<TARGET_TYPE_CORE>& i_target,
    const uint8_t i_threads, const bool i_warncheck,
    fapi2::buffer<uint64_t>& o_rasStatusReg);

fapi2::ReturnCode p9_thread_control_query(
    const fapi2::Target<TARGET_TYPE_CORE>& i_target,
    const uint8_t i_threads,
    fapi2::buffer<uint64_t>& o_rasStatusReg,
    uint64_t& o_state);

//--------------------------------------------------------------------------
/// @brief threads_running : static funtion to encapsulate the running state
/// @param[in] i_target core target
/// @param[in] i_thread normal core thread bitset (0b0000..0b1111)
/// @param[out] o_rasStatusReg  Complete RAS status reg 64-bit buffer.
/// @param[out] o_ok true if the threads are running
/// @return FAPI2_RC_SUCCESS if the underlying hw operations succeeded
//--------------------------------------------------------------------------
static inline fapi2::ReturnCode threads_running(
    const fapi2::Target<TARGET_TYPE_CORE>& i_target,
    const uint8_t i_threads,
    fapi2::buffer<uint64_t>& o_rasStatusReg,
    bool& o_ok)
{
    // Running is defined as not in maint mode and not quiesced.
    uint64_t l_state = 0;
    FAPI_TRY(p9_thread_control_query(i_target, i_threads, o_rasStatusReg, l_state),
             "threads_running(): p9_thread_control_query() returns an error.");
    o_ok = (l_state & THREAD_STATE_RUNNING);

fapi_try_exit:
    return fapi2::current_err;
}

//--------------------------------------------------------------------------
/// @brief threads_in_maint : static funtion to encapsulate the maint state
/// @param[in] i_target core target
/// @param[in] i_thread normal core thread bitset (0b0000..0b1111)
/// @param[out] o_rasStatusReg  Complete RAS status reg 64-bit buffer.
/// @param[out] o_ok true if the threads are in maint mode
/// @return FAPI2_RC_SUCCESS if the underlying hw operations succeeded
//--------------------------------------------------------------------------
static inline fapi2::ReturnCode threads_in_maint(
    const fapi2::Target<TARGET_TYPE_CORE>& i_target,
    const uint8_t i_threads,
    fapi2::buffer<uint64_t>& o_rasStatusReg,
    bool& o_ok)
{
    uint64_t l_state = 0;
    FAPI_TRY(p9_thread_control_query(i_target, i_threads, o_rasStatusReg, l_state),
             "threads_in_maint(): p9_thread_control_query() returns an error.");
    o_ok = (l_state & THREAD_STATE_MAINT);

fapi_try_exit:
    return fapi2::current_err;
}

//--------------------------------------------------------------------------
/// @brief all_threads_stopped : static funtion to encapsulate the stopped state
/// @param[in] i_target core target
/// @param[in] i_thread normal core thread bitset (0b0000..0b1111)
/// @param[out] o_rasStatusReg  Complete RAS status reg 64-bit buffer.
/// @param[out] o_ok true if the threads are stopped
/// @return FAPI2_RC_SUCCESS if the underlying hw operations succeeded
//--------------------------------------------------------------------------
static inline fapi2::ReturnCode threads_stopped(
    const fapi2::Target<TARGET_TYPE_CORE>& i_target,
    const uint8_t i_threads,
    fapi2::buffer<uint64_t>& o_rasStatusReg,
    bool& o_ok)
{
    // Running is defined as not in maint mode and not quiesced.
    uint64_t l_state = 0;
    FAPI_TRY(p9_thread_control_query(i_target, i_threads, o_rasStatusReg, l_state),
             "threads_stopped(): p9_thread_control_query() returns an error.");
    o_ok = (l_state & THREAD_STATE_STOP);

fapi_try_exit:
    return fapi2::current_err;
}

//--------------------------------------------------------------------------
/// @brief all_threads_step_done : static funtion to encapsulate the step
/// complete state
/// @param[in] i_target core target
/// @param[in] i_thread normal core thread bitset (0b0000..0b1111)
/// @param[out] o_rasStatusReg  Complete RAS status reg 64-bit buffer.
/// @param[out] o_ok true if the threads are done stepping
/// @return FAPI2_RC_SUCCESS if the underlying hw operations succeeded
//--------------------------------------------------------------------------
static inline fapi2::ReturnCode threads_step_done(
    const fapi2::Target<TARGET_TYPE_CORE>& i_target,
    const uint8_t i_threads,
    fapi2::buffer<uint64_t>& o_rasStatusReg,
    bool& o_ok)
{
    uint64_t l_state = 0;
    FAPI_TRY(p9_thread_control_query(i_target, i_threads, o_rasStatusReg, l_state),
             "threads_step_done(): p9_thread_control_query() returns an error.");
    o_ok = (l_state & THREAD_STATE_ISTEP_SUCCESS);

fapi_try_exit:
    return fapi2::current_err;
}

//--------------------------------------------------------------------------
/// @brief threads_step_ready : static funtion to encapsulate the step
/// ready state
/// @param[in] i_target core target
/// @param[in] i_thread normal core thread bitset (0b0000..0b1111)
/// @param[out] o_rasStatusReg  Complete RAS status reg 64-bit buffer.
/// @param[out] o_ok true if the threads are ready to step
/// @return FAPI2_RC_SUCCESS if the underlying hw operations succeeded
//--------------------------------------------------------------------------
static inline fapi2::ReturnCode threads_step_ready(
    const fapi2::Target<TARGET_TYPE_CORE>& i_target,
    const uint8_t i_threads,
    fapi2::buffer<uint64_t>& o_rasStatusReg,
    bool& o_ok)
{
    uint64_t l_state = 0;
    FAPI_TRY(p9_thread_control_query(i_target, i_threads, o_rasStatusReg, l_state),
             "threads_step_ready(): p9_thread_control_query() returns an error.");
    o_ok = (l_state & THREAD_STATE_ISTEP_READY);

fapi_try_exit:
    return fapi2::current_err;
}

//--------------------------------------------------------------------------
/// @brief p9_thread_control: utility subroutine to control thread state
//--------------------------------------------------------------------------
fapi2::ReturnCode p9_thread_control(
    const fapi2::Target<TARGET_TYPE_CORE>& i_target,
    const uint8_t i_threads, const ThreadCommands i_command,
    const bool i_warncheck,
    fapi2::buffer<uint64_t>& o_rasStatusReg,
    uint64_t& o_state)
{
    FAPI_INF("p9_thread_control : Core threads: 0x%x, Command %u", i_threads, i_command);

    // Output state is only valid for PTC_CMD_QUERY command
    o_state = 0;

    switch(i_command)
    {
        case PTC_CMD_SRESET:
            FAPI_TRY(p9_thread_control_sreset(i_target, i_threads, i_warncheck,
                                              o_rasStatusReg));
            break;

        case PTC_CMD_START:
            FAPI_TRY(p9_thread_control_start(i_target, i_threads, i_warncheck,
                                             o_rasStatusReg));
            break;

        case PTC_CMD_STOP:
            FAPI_TRY(p9_thread_control_stop(i_target, i_threads, i_warncheck,
                                            o_rasStatusReg));
            break;

        case PTC_CMD_STEP:
            FAPI_TRY(p9_thread_control_step(i_target, i_threads, i_warncheck,
                                            o_rasStatusReg));
            break;

        case PTC_CMD_QUERY:
            FAPI_TRY(p9_thread_control_query(i_target, i_threads,
                                             o_rasStatusReg, o_state));
            break;
    };

fapi_try_exit:
    FAPI_INF("p9_thread_control : Exit (core)");

    return fapi2::current_err;

}

//--------------------------------------------------------------------------
/// @brief Utility subroutine to query the state of a thread(s).
///
/// @param[in] i_target      Reference to core target
/// @param[in] i_threads     Desired thread bits set
///                             0b0000         No thread (No-op)
///                             0b1000         Thread 0
///                             0b0100         Thread 1
///                             0b0010         Thread 2
///                             0b0001         Thread 3
/// @param[out] o_rasStatusReg  Complete RAS status reg 64-bit buffer.
///                             Only valid for PTC_CMD_QUERY command.
/// @param[out] o_state      Current thread state. See THREAD_STATE bit
///                          definitions in header file.
///
/// @return FAPI2_RC_SUCCESS if operation was successful, else error.
//--------------------------------------------------------------------------
fapi2::ReturnCode p9_thread_control_query(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
    const uint8_t i_threads,
    fapi2::buffer<uint64_t>& o_rasStatusReg,
    uint64_t& o_state)
{
    FAPI_DBG("Entering: Thread bit set %u", i_threads);

    // Initializing
    o_state = 0;

    // Setup mask values
    const uint64_t l_running_mask =
        (g_control_reg_map[i_threads] >> CORE_MAINT_MODE) |
        (g_control_reg_map[i_threads] >> THREAD_QUIESCED);
    const uint64_t l_step_ready_mask =
        (g_control_reg_map[i_threads] >> CORE_MAINT_MODE) |
        (g_control_reg_map[i_threads] >> THREAD_QUIESCED) |
        (g_control_reg_map[i_threads] >> ICT_EMPTY);

    // Get C_RAS_STATUS reg
    FAPI_TRY(fapi2::getScom(i_target, C_RAS_STATUS, o_rasStatusReg),
             "p9_thread_control_query(): getScom() returns an error, "
             "Addr C_RAS_STATUS 0x%.16llX", C_RAS_STATUS);

    // Note: all threads must meet a given condition in order for the
    //       bit to be set.
    // Set THREAD_STATE_RUNNING
    // Running is defined as not in maint mode and not quiesced.
    if ( ((o_rasStatusReg & l_running_mask) == 0) )
    {
        o_state |= THREAD_STATE_RUNNING;
    }
    // Stop is defined as in maint mode and in quiesced.
    else if ( ((o_rasStatusReg & l_running_mask) == l_running_mask) )
    {
        o_state |= THREAD_STATE_STOP;
    }

    // Check for THREAD_STATE_MAINT
    if ( o_rasStatusReg &
         g_control_reg_map[i_threads] >> CORE_MAINT_MODE )
    {
        o_state |= THREAD_STATE_MAINT;
    }

    // Check for THREAD_STATE_QUIESCED
    if ( o_rasStatusReg &
         g_control_reg_map[i_threads] >> THREAD_QUIESCED )
    {
        o_state |= THREAD_STATE_QUIESCED;
    }

    // Check for THREAD_STATE_ICT_EMPTY
    if ( o_rasStatusReg &
         g_control_reg_map[i_threads] >> ICT_EMPTY )
    {
        o_state |= THREAD_STATE_ICT_EMPTY;
    }

    // Check for THREAD_STATE_LSU_QUIESCED
    if ( o_rasStatusReg &
         g_control_reg_map[i_threads] >> LSU_QUIESCED )
    {
        o_state |= THREAD_STATE_LSU_QUIESCED;
    }

    // Check for THREAD_STATE_ISTEP_SUCCESS
    if ( o_rasStatusReg &
         g_control_reg_map[i_threads] >> STEP_SUCCESS )
    {
        o_state |= THREAD_STATE_ISTEP_SUCCESS;
    }

    // Check for THREAD_STATE_ISTEP_READY
    // All maint, quiesced and ICT empty must be set.
    if ( ((o_rasStatusReg & l_step_ready_mask) == l_step_ready_mask) )
    {
        o_state |= THREAD_STATE_ISTEP_READY;
    }

    FAPI_DBG("C_RAS_STATUS: 0x%.16llX, Thread state 0x%.16llX",
             o_rasStatusReg, o_state);

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

//--------------------------------------------------------------------------
/// @brief p9_thread_control: utility subroutine to control thread state
//-------------------------------------------------------------------------
fapi2::ReturnCode p9_thread_control(
    const fapi2::Target<TARGET_TYPE_EX>& i_target,
    const uint8_t i_threads,
    const ThreadCommands i_command,
    fapi2::buffer<uint64_t>& o_rasStatusReg,
    const bool i_warncheck)
{
    uint64_t l_state = 0;
    FAPI_INF("p9_thread_control : Start (ex) threads: 0x%x)", i_threads);

    // Grab the normal core children and iterate over them.
    // TODO: Assumes core 0 is l_cores[0]
    auto l_cores = i_target.getChildren<TARGET_TYPE_CORE>();
    uint8_t l_ordinal = 0;

    for( auto coreItr = l_cores.begin(); coreItr != l_cores.end(); ++coreItr, ++l_ordinal )
    {
        // It is quite possible that this fused core bitset only has thread-bits set
        // for one core or the other. Don't bother to call the control function if
        // we don't have any threads to control.
        const uint8_t l_thread_set = fapi2::thread_bitset_f2n(l_ordinal, i_threads);

        if (l_thread_set != 0)
        {
            FAPI_TRY(p9_thread_control(*coreItr, l_thread_set, i_command,
                                       i_warncheck, o_rasStatusReg, l_state));
        }
    }

fapi_try_exit:
    FAPI_INF("p9_thread_control : Exit (ex)");
    return fapi2::current_err;
}

//--------------------------------------------------------------------------
/// @brief p9_thread_control_sreset: utility subroutine to sreset a thread
/// @param[in] i_target core target
/// @param[in] i_threads normal core thread bitset (0b0000..0b1111)
/// @param[in] i_warncheck convert pre/post checks errors to warnings
/// @param[out] o_rasStatusReg  Complete RAS status reg 64-bit buffer.
/// @return FAPI2_RC_SUCCESS if operation was successful,
///         RC_P9_THREAD_CONTROL_SRESET_FAIL if the threads aren't running,
///         else error
//--------------------------------------------------------------------------
fapi2::ReturnCode p9_thread_control_sreset(
    const fapi2::Target<TARGET_TYPE_CORE>& i_target,
    const uint8_t i_threads, const bool i_warncheck,
    fapi2::buffer<uint64_t>& o_rasStatusReg)
{
    FAPI_DBG("p9_thread_control_sreset : Initiating sreset command to core PC logic for threads 0x%x",
             i_threads);
    // No Precondition for Sreset; power management is handled by platform
    // Setup & Initiate SReset Command
    {
        fapi2::buffer<uint64_t> l_scom_data(
            g_control_reg_map[i_threads] >> SRESET_REQUEST);

        FAPI_TRY(fapi2::putScom(i_target, C_DIRECT_CONTROLS, l_scom_data),
                 "p9_thread_control_sreset: putScom error when issuing sp_sreset for threads 0x%x",
                 i_threads);
    }

    // Post-conditions check
    // TODO: Check for instructions having been executed?
    {
        bool l_running = false;
        FAPI_TRY(threads_running(i_target, i_threads, o_rasStatusReg, l_running),
                 "p9_thread_control_sreset: unable to determine if threads are running. threads: 0x%x",
                 i_threads);

        PTC_ASSERT_WARN(l_running == true,
                        i_warncheck,
                        fapi2::P9_THREAD_CONTROL_SRESET_FAIL()
                        .set_CORE_TARGET(i_target)
                        .set_THREAD(i_threads),
                        "p9_thread_control_sreset: ERROR: Thread SRESET issued, but the threads aren't running. "
                        "SReset might have failed for threads 0x%x", i_threads);
    }

    FAPI_INF("p9_thread_control_sreset : sreset command issued for threads 0x%x",
             i_threads);

fapi_try_exit:
    return fapi2::current_err;
}

//--------------------------------------------------------------------------
/// @brief p9_thread_control_start: utility subroutine to start a thread
/// @param[in] i_target core target
/// @param[in] i_threads normal core thread bitset (0b0000..0b1111)
/// @param[in] i_warncheck convert pre/post checks errors to warnings
/// @param[out] o_rasStatusReg  Complete RAS status reg 64-bit buffer.
/// @return FAPI2_RC_SUCCESS if operation was successful,
///          RC_P9_THREAD_CONTROL_START_FAIL if start command failed,
///         else error
//--------------------------------------------------------------------------
fapi2::ReturnCode p9_thread_control_start(
    const fapi2::Target<TARGET_TYPE_CORE>& i_target,
    const uint8_t i_threads, const bool i_warncheck,
    fapi2::buffer<uint64_t>& o_rasStatusReg)
{
    FAPI_DBG("p9_thread_control_start : Initiating start command to core PC logic for threads 0x%x",
             i_threads);

    // Preconditions: Only valid when in maint mode
    {
        bool l_in_maint = false;
        FAPI_TRY(threads_in_maint(i_target, i_threads, o_rasStatusReg, l_in_maint),
                 "p9_thread_control_start: unable to determine if threads are in maint mode. threads: 0x%x",
                 i_threads);

        PTC_ASSERT_WARN(l_in_maint == true,
                        i_warncheck,
                        fapi2::P9_THREAD_CONTROL_START_PRE_NOMAINT()
                        .set_CORE_TARGET(i_target)
                        .set_THREAD(i_threads),
                        "p9_thread_control_start: ERROR: Cannot issue Thread Start because the threads aren't in maint mode (threads=%x).",
                        i_threads);
    }

    // Start the threads
    {
        fapi2::buffer<uint64_t> l_scom_data(g_control_reg_map[i_threads] >> CORE_START);

        FAPI_TRY(fapi2::putScom(i_target, C_DIRECT_CONTROLS, l_scom_data),
                 "p9_thread_control_start: putScom error when issuing sp_start for threads 0x%x",
                 i_threads);
    }

    // Post-conditions check
    // TODO: Perhaps only run this section if i_warncheck==true to save an extranious scom
    //       Verify understanding and desire for this funtionality before implementing in all thread_control functions
    {
        bool l_running = false;
        FAPI_TRY(threads_running(i_target, i_threads, o_rasStatusReg, l_running),
                 "p9_thread_control_start: unable to determine if threads are running. threads: 0x%x",
                 i_threads);

        PTC_ASSERT_WARN(l_running == true,
                        i_warncheck,
                        fapi2::P9_THREAD_CONTROL_START_FAIL()
                        .set_CORE_TARGET(i_target)
                        .set_THREAD(i_threads),
                        "p9_thread_control_start: ERROR: Thread Start issued, but the threads aren't running. "
                        "Start might have failed for threads 0x%x", i_threads);
    }

    FAPI_INF("p9_thread_control_start : start command issued for threads 0x%x",
             i_threads);

fapi_try_exit:
    return fapi2::current_err;
}

//--------------------------------------------------------------------------
/// @brief p9_thread_control_stop: utility subroutine to stop a thread
/// @param[in] i_target core target
/// @param[in] i_threads normal core thread bitset (0b0000..0b1111)
/// @param[in] i_warncheck convert pre/post checks errors to warnings
/// @param[out] o_rasStatusReg  Complete RAS status reg 64-bit buffer.
/// @return FAPI2_RC_SUCCESS if operation was successful,
///          RC_P9_THREAD_CONTROL_STOP_FAIL if start command failed,
///         else error
//--------------------------------------------------------------------------
fapi2::ReturnCode p9_thread_control_stop(
    const fapi2::Target<TARGET_TYPE_CORE>& i_target,
    const uint8_t i_threads, const bool i_warncheck,
    fapi2::buffer<uint64_t>& o_rasStatusReg)
{
    FAPI_DBG("p9_thread_control_stop : Initiating stop command to core PC logic for threads 0x%x",
             i_threads);

    // Pre-condition for stopping is that the threads are running (see figure 5.3 in the workbook)
    // How to reconcile with 5.5.1 which says "invalid in maint mode?" Is that just a sub-precondition?
    // TODO: Do we want to check to see if all threads are stopped and just bypass this if they are?
    {
        bool l_running = false;
        FAPI_TRY(threads_running(i_target, i_threads, o_rasStatusReg, l_running),
                 "p9_thread_control_stop: unable to determine if threads are running. threads: 0x%x",
                 i_threads);

        PTC_ASSERT_WARN(l_running == true,
                        i_warncheck,
                        fapi2::P9_THREAD_CONTROL_STOP_PRE_NOTRUNNING()
                        .set_CORE_TARGET(i_target)
                        .set_THREAD(i_threads),
                        "p9_thread_control_stop: ERROR: Threads cannot be stopped because they aren't running (threads=%x).", i_threads);
    }

    // Stop the threads
    {
        fapi2::buffer<uint64_t> l_scom_data(g_control_reg_map[i_threads] >> CORE_STOP);

        FAPI_TRY(fapi2::putScom(i_target, C_DIRECT_CONTROLS, l_scom_data),
                 "p9_thread_control_stop: putScom error when issuing sp_stop for threads 0x%x",
                 i_threads);
    }

    // Post-conditions check
    {
        bool l_stopped = false;
        FAPI_TRY(threads_stopped(i_target, i_threads, o_rasStatusReg, l_stopped),
                 "p9_thread_control_stop: unable to determine if threads are stopped. threads: 0x%x",
                 i_threads);

        PTC_ASSERT_WARN(l_stopped == true,
                        i_warncheck,
                        fapi2::P9_THREAD_CONTROL_STOP_FAIL()
                        .set_CORE_TARGET(i_target)
                        .set_THREAD(i_threads),
                        "p9_thread_control_stop: ERROR: Thread Stop issued, but the threads are running. "
                        "Stop might have failed for threads 0x%x", i_threads);
    }

    FAPI_INF("p9_thread_control_stop : stop command issued for threads 0x%x",
             i_threads);

fapi_try_exit:
    return fapi2::current_err;
}

//--------------------------------------------------------------------------
/// @brief p9_thread_control_step: utility subroutine to single-instruction
/// step a thread
/// @param[in] i_target core target
/// @param[in] i_threads normal core thread bitset (0b0000..0b1111)
/// @param[in] i_warncheck convert pre/post checks errors to warnings
/// @param[out] o_rasStatusReg  Complete RAS status reg 64-bit buffer.
/// @return FAPI2_RC_SUCCESS if operation was successful,
///          RC_P9_THREAD_CONTROL_STEP_FAIL if start command failed,
///         else error
//--------------------------------------------------------------------------
fapi2::ReturnCode p9_thread_control_step(
    const fapi2::Target<TARGET_TYPE_CORE>& i_target,
    const uint8_t i_threads, const bool i_warncheck,
    fapi2::buffer<uint64_t>& o_rasStatusReg)
{
    FAPI_DBG("p9_thread_control_stop : Initiating step command to core PC logic for threads 0x%x",
             i_threads);

    // Preconditions
    {
        bool l_step_ready = false;
        FAPI_TRY(threads_step_ready(i_target, i_threads, o_rasStatusReg, l_step_ready),
                 "p9_thread_control_step: unable to determine if threads are ready to step. threads: 0x%x",
                 i_threads);

        PTC_ASSERT_WARN(l_step_ready == true,
                        i_warncheck,
                        fapi2::P9_THREAD_CONTROL_STEP_PRE_NOTSTOPPING()
                        .set_CORE_TARGET(i_target)
                        .set_THREAD(i_threads),
                        "p9_thread_control_step: ERROR: Thread cannot be stepped because they are not ready to step (threads=%x).", i_threads);
    }


    // Setup single step mode and issue step.
    {
        fapi2::buffer<uint64_t> l_mode_data;
        fapi2::buffer<uint64_t> l_step_data(g_control_reg_map[i_threads] >> CORE_STEP);

        // Set single step mode.
        FAPI_TRY(fapi2::getScom(i_target, C_RAS_MODEREG, l_mode_data),
                 "p9_thread_control_step: getScom error when reading ras_modreg for threads 0x%x",
                 i_threads);

        // i_threads is right aligned
        l_mode_data |=
            fapi2::buffer<uint64_t>().insertFromRight<RAS_MODE_STEP_SHIFT, 4>(i_threads);
        FAPI_TRY(fapi2::putScom(i_target, C_RAS_MODEREG, l_mode_data),
                 "p9_thread_control_step: putScom error when issuing ras_modreg step mode for threads 0x%x",
                 i_threads);

        // Set issue the step
        FAPI_TRY(fapi2::putScom(i_target, C_DIRECT_CONTROLS, l_step_data),
                 "p9_thread_control_step: putScom error when issuing step command for threads 0x%x",
                 i_threads);
    }


    // Poll for completion.
    {
        bool l_step_done = false;
        uint8_t l_governor = PTC_STEP_COMP_POLL_LIMIT;

        do
        {
            FAPI_DBG("polling for step done. governor: %d", l_governor);
            FAPI_TRY(threads_step_done(i_target, i_threads, o_rasStatusReg, l_step_done),
                     "p9_thread_control_step: thread step issued but something went wrong polling for step_done for threads 0x%x",
                     i_threads);
        }
        while((l_step_done != true) && l_governor--);

        // We ran out of tries. If the scom failed, fapi_try kicked us out long ago.
        PTC_ASSERT_WARN(l_governor != 0,
                        i_warncheck,
                        fapi2::P9_THREAD_CONTROL_STEP_FAIL()
                        .set_CORE_TARGET(i_target)
                        .set_THREAD(i_threads)
                        .set_PTC_STEP_COMP_POLL_LIMIT(PTC_STEP_COMP_POLL_LIMIT),
                        "p9_thread_control_stop: ERROR: Thread Step failed. Complete bits aren't set after %d poll atempts. WARNING: C_RAS_STATUS "
                        "bit still in single instruction mode. Threads 0x%x", PTC_STEP_COMP_POLL_LIMIT,
                        i_threads);
    }


    // Reset single step mode
    {
        fapi2::buffer<uint64_t> l_mode_data;

        FAPI_TRY(fapi2::getScom(i_target, C_RAS_MODEREG, l_mode_data),
                 "p9_thread_control_step: getScom error when reading ras_modreg for threads 0x%x",
                 i_threads);

        // i_threads is right aligned
        l_mode_data &= ~
                       (fapi2::buffer<uint64_t>().insertFromRight<RAS_MODE_STEP_SHIFT, 4>(i_threads));
        FAPI_TRY(fapi2::putScom(i_target, C_RAS_MODEREG, l_mode_data),
                 "p9_thread_control_step: putScom error when issuing ras_modreg step mode for threads 0x%x",
                 i_threads);
    }

fapi_try_exit:
    return fapi2::current_err;
}
