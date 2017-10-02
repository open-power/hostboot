/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/core/p9_thread_control.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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

///----------------------------------------------------------------------------
///
/// @file p9_thread_control.C
///
/// @brief Core Thread start/stop/step/query/activate operations
///        See detailed description in header file.
///
/// *HWP HWP Owner   : Nick Klazynski <jklazyns@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Quad
/// *HWP Consumed by : FSP:HB:HS
/// *HWP Level       : 3
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_thread_control.H>
#include <p9_quad_scom_addresses_fld.H>

using fapi2::TARGET_TYPE_CORE;

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------
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

static const uint64_t g_poll_for_running = 10;
static const uint8_t PTC_STEP_COMP_POLL_LIMIT = 10;

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
/// @brief threads_in_maint : static funtion to encapsulate the maint state
/// @param[in] i_target core target
/// @param[in] i_threads normal core thread bitset (0b0000..0b1111)
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
/// @param[in] i_threads normal core thread bitset (0b0000..0b1111)
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
/// @param[in] i_threads normal core thread bitset (0b0000..0b1111)
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
/// @param[in] i_threads normal core thread bitset (0b0000..0b1111)
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

        default: // full proof, in case this routine is called with an
            // invalid casted value
            PTC_ASSERT_WARN(false,
                            i_warncheck,
                            fapi2::P9_THREAD_CONTROL_INVALID_COMMAND()
                            .set_CORE_TARGET(i_target)
                            .set_THREAD(i_threads)
                            .set_COMMAND(i_command),
                            "Invalid p9_thread_control command: %d", i_command);
            break;
    };

fapi_try_exit:
    FAPI_INF("p9_thread_control : Exit");

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
        (g_control_reg_map[i_threads] >> C_RAS_STATUS_T0_CORE_MAINT) |
        (g_control_reg_map[i_threads] >> C_RAS_STATUS_T0_THREAD_QUIESCED);
    const uint64_t l_step_ready_mask =
        (g_control_reg_map[i_threads] >> C_RAS_STATUS_T0_CORE_MAINT) |
        (g_control_reg_map[i_threads] >> C_RAS_STATUS_T0_THREAD_QUIESCED) |
        (g_control_reg_map[i_threads] >> C_RAS_STATUS_T0_ICT_EMPTY);

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
         g_control_reg_map[i_threads] >> C_RAS_STATUS_T0_CORE_MAINT )
    {
        o_state |= THREAD_STATE_MAINT;
    }

    // Check for THREAD_STATE_QUIESCED
    if ( o_rasStatusReg &
         g_control_reg_map[i_threads] >> C_RAS_STATUS_T0_THREAD_QUIESCED )
    {
        o_state |= THREAD_STATE_QUIESCED;
    }

    // Check for THREAD_STATE_ICT_EMPTY
    if ( o_rasStatusReg &
         g_control_reg_map[i_threads] >> C_RAS_STATUS_T0_ICT_EMPTY )
    {
        o_state |= THREAD_STATE_ICT_EMPTY;
    }

    // Check for THREAD_STATE_LSU_QUIESCED
    if ( o_rasStatusReg &
         g_control_reg_map[i_threads] >> C_RAS_STATUS_T0_LSU_QUIESCED )
    {
        o_state |= THREAD_STATE_LSU_QUIESCED;
    }

    // Check for THREAD_STATE_ISTEP_SUCCESS
    if ( o_rasStatusReg &
         g_control_reg_map[i_threads] >> C_RAS_STATUS_T0_STEP_SUCCESS )
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
    // Clear blocking interrupts
    {
        fapi2::buffer<uint64_t> l_mode_data;

        // SW375288: Reads to C_RAS_MODEREG causes SPR corruption.
        // For now, the code will assume no other bits are set and only
        // set/clear mr_fence_interrupts
        // FAPI_TRY(fapi2::getScom(i_target, C_RAS_MODEREG, l_mode_data),
        //         "p9_thread_control_step: getScom error when reading "
        //         "ras_modreg for threads 0x%x", i_threads);
        // l_mode_data.clearBit<C_RAS_MODEREG_MR_FENCE_INTERRUPTS>();
        FAPI_TRY(fapi2::putScom(i_target, C_RAS_MODEREG, l_mode_data),
                 "p9_thread_control_step: putScom error when issuing "
                 "ras_modreg step mode for threads 0x%x", i_threads);
    }

    // Setup & Initiate SReset Command
    {
        fapi2::buffer<uint64_t> l_scom_data(
            g_control_reg_map[i_threads] >> C_DIRECT_CONTROLS_DC_T0_SRESET_REQUEST);
        FAPI_TRY(fapi2::putScom(i_target, C_DIRECT_CONTROLS, l_scom_data),
                 "p9_thread_control_sreset: putScom error when issuing "
                 "sp_sreset for threads 0x%x", i_threads);
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
///         RC_P9_THREAD_CONTROL_START_FAIL if start command failed,
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
                 "p9_thread_control_start: unable to determine if threads are "
                 "in maint mode. threads: 0x%x",  i_threads);

        PTC_ASSERT_WARN(l_in_maint == true,
                        i_warncheck,
                        fapi2::P9_THREAD_CONTROL_START_PRE_NOMAINT()
                        .set_CORE_TARGET(i_target)
                        .set_THREAD(i_threads)
                        .set_C_RAS_STATUS_REG(o_rasStatusReg),
                        "p9_thread_control_start: ERROR: Cannot issue Thread Start "
                        "because the threads aren't in maint mode (threads=%x), "
                        "C_RAS_STATUS reg 0x%.16llX", i_threads, o_rasStatusReg);
    }

    // Clear blocking interrupts
    {
        fapi2::buffer<uint64_t> l_mode_data;

        // SW375288: Reads to C_RAS_MODEREG causes SPR corruption.
        // For now, the code will assume no other bits are set and only
        // set/clear mr_fence_interrupts
        // FAPI_TRY(fapi2::getScom(i_target, C_RAS_MODEREG, l_mode_data),
        //         "p9_thread_control_step: getScom error when reading "
        //         "ras_modreg for threads 0x%x", i_threads);
        //l_mode_data.clearBit<C_RAS_MODEREG_MR_FENCE_INTERRUPTS>();
        FAPI_TRY(fapi2::putScom(i_target, C_RAS_MODEREG, l_mode_data),
                 "p9_thread_control_step: putScom error when issuing ras_modreg "
                 "step mode for threads 0x%x", i_threads);
    }

    // Start the threads
    {
        fapi2::buffer<uint64_t> l_scom_data(
            g_control_reg_map[i_threads] >> C_DIRECT_CONTROLS_DC_T0_CORE_START);
        FAPI_TRY(fapi2::putScom(i_target, C_DIRECT_CONTROLS, l_scom_data),
                 "p9_thread_control_start: putScom error when issuing sp_start "
                 "for threads 0x%x", i_threads);
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

    // Block interrupts while stopped
    {
        fapi2::buffer<uint64_t> l_mode_data;

        // SW375288: Reads to C_RAS_MODEREG causes SPR corruption.  For now,
        // the code will assume no other bits are set and only set/clear
        // mr_fence_interrupts.
        // FAPI_TRY(fapi2::getScom(i_target, C_RAS_MODEREG, l_mode_data),
        //         "p9_thread_control_step: getScom error when reading "
        //         "ras_modreg for threads 0x%x", i_threads);
        l_mode_data.setBit<C_RAS_MODEREG_MR_FENCE_INTERRUPTS>();
        FAPI_TRY(fapi2::putScom(i_target, C_RAS_MODEREG, l_mode_data),
                 "p9_thread_control_step: putScom error when issuing ras_modreg "
                 "step mode for threads 0x%x", i_threads);
    }

    // Stop the threads
    {
        fapi2::buffer<uint64_t> l_scom_data(
            g_control_reg_map[i_threads] >> C_DIRECT_CONTROLS_DC_T0_CORE_STOP);
        FAPI_TRY(fapi2::putScom(i_target, C_DIRECT_CONTROLS, l_scom_data),
                 "p9_thread_control_stop: putScom error when issuing sp_stop "
                 "for threads 0x%x", i_threads);
    }

    // Post-conditions check
    {
        bool l_stopped = false;
        FAPI_TRY(threads_stopped(i_target, i_threads, o_rasStatusReg, l_stopped),
                 "p9_thread_control_stop: unable to determine if threads are "
                 "stopped. threads: 0x%x", i_threads);

        PTC_ASSERT_WARN(l_stopped == true,
                        i_warncheck,
                        fapi2::P9_THREAD_CONTROL_STOP_FAIL()
                        .set_CORE_TARGET(i_target)
                        .set_THREAD(i_threads)
                        .set_C_RAS_STATUS_REG(o_rasStatusReg),
                        "p9_thread_control_stop: ERROR: Thread Stop issued, "
                        "but the threads are running. Stop might have failed "
                        "for threads 0x%x, C_RAS_STATUS reg 0x%.16llX",
                        i_threads, o_rasStatusReg);
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
    FAPI_DBG("p9_thread_control_stop : Initiating step command to core PC "
             "logic for threads 0x%x", i_threads);

    // Preconditions
    {
        bool l_step_ready = false;
        FAPI_TRY(threads_step_ready(i_target, i_threads, o_rasStatusReg, l_step_ready),
                 "p9_thread_control_step: unable to determine if threads are "
                 "ready to step. threads: 0x%x", i_threads);

        PTC_ASSERT_WARN(l_step_ready == true,
                        i_warncheck,
                        fapi2::P9_THREAD_CONTROL_STEP_PRE_NOTSTOPPING()
                        .set_CORE_TARGET(i_target)
                        .set_THREAD(i_threads)
                        .set_C_RAS_STATUS_REG(o_rasStatusReg),
                        "p9_thread_control_step: ERROR: Thread cannot be "
                        "stepped because they are not ready to step (threads=%x), "
                        "C_RAS_STATUS reg 0x%.16llX", i_threads, o_rasStatusReg);
    }


    // Setup single step mode and issue step.
    {
        fapi2::buffer<uint64_t> l_step_data(
            g_control_reg_map[i_threads] >> C_DIRECT_CONTROLS_DC_T0_CORE_STEP);

        // Set issue the step
        FAPI_TRY(fapi2::putScom(i_target, C_DIRECT_CONTROLS, l_step_data),
                 "p9_thread_control_step: putScom error when issuing step "
                 "command for threads 0x%x", i_threads);
    }


    // Poll for completion.
    {
        bool l_step_done = false;
        uint8_t l_governor = PTC_STEP_COMP_POLL_LIMIT;

        do
        {
            FAPI_DBG("polling for step done. governor: %d", l_governor);
            FAPI_TRY(threads_step_done(i_target, i_threads, o_rasStatusReg, l_step_done),
                     "p9_thread_control_step: thread step issued but something "
                     "went wrong polling for step_done for threads 0x%x",
                     i_threads);
        }
        while((l_step_done != true) && l_governor--);

        // We ran out of tries. If the scom failed, fapi_try kicked us out long ago.
        PTC_ASSERT_WARN(l_governor != 0,
                        i_warncheck,
                        fapi2::P9_THREAD_CONTROL_STEP_FAIL()
                        .set_CORE_TARGET(i_target)
                        .set_THREAD(i_threads)
                        .set_C_RAS_STATUS_REG(o_rasStatusReg)
                        .set_PTC_STEP_COMP_POLL_LIMIT(PTC_STEP_COMP_POLL_LIMIT),
                        "p9_thread_control_stop: ERROR: Thread Step failed."
                        "Complete bits aren't set after %d poll atempts. "
                        "WARNING: C_RAS_STATUS bit still in single instruction "
                        "mode. Threads 0x%x, C_RAS_STATUS reg 0x%.16llX",
                        PTC_STEP_COMP_POLL_LIMIT, i_threads, o_rasStatusReg);
    }

fapi_try_exit:
    return fapi2::current_err;
}
