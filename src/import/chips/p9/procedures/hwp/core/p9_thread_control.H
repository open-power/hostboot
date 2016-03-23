/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/core/p9_thread_control.H $            */
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
//------------------------------------------------------------------------------
// *! TITLE       : p9_thread_control
// *! DESCRIPTION : Core Thread start/stop/step/query/activate operations
// *!               Use to start (start or sreset) thread instruction execution,
// *!                 stop instruction execution, or single instruction step.
// *!               Also used to query the state of a thread.
//------------------------------------------------------------------------------

// *HWP HWP Owner: Nick Klazynski <dyem@us.ibm.com>
// *HWP FW Owner:  Thi Tran <thi@us.ibm.com>
// *HWP Team:  Quad
// *HWP Level: 2
// *HWP Consumed by: FSP:HB:HS

#ifndef _P9_THREAD_CONTROL_H_
#define _P9_THREAD_CONTROL_H_

#include <fapi2.H>
#include <return_code.H>
#include <error_scope.H>

#include "p9_quad_scom_addresses.H"

extern "C"
{

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------
    const uint8_t MAX_NUM_OF_THREADS = 4;

// THREAD_STATE bit definitions
    const uint64_t THREAD_STATE_RUNNING            = 0x8000000000000000ULL;
    const uint64_t THREAD_STATE_STOP               = 0x4000000000000000ULL;
    const uint64_t THREAD_STATE_QUIESCED           = 0x2000000000000000ULL;
    const uint64_t THREAD_STATE_MAINT              = 0x1000000000000000ULL;
    const uint64_t THREAD_STATE_ICT_EMPTY          = 0x0800000000000000ULL;
    const uint64_t THREAD_STATE_LSU_QUIESCED       = 0x0400000000000000ULL;
    const uint64_t THREAD_STATE_ISTEP_SUCCESS      = 0x0200000000000000ULL;
    const uint64_t THREAD_STATE_ISTEP_READY        = 0x0100000000000000ULL;

// A macro to wrap the warning check boiler plate
// If the action failed and i_warncheck is set add a trace and continue anyway
#define PTC_ASSERT_WARN( __conditional__, __warning__, __ffdc__, ... )  \
    if (! (__conditional__))                                            \
    {                                                                   \
        if (__warning__)                                                \
        {                                                               \
            FAPI_INF(__VA_ARGS__);                                      \
        }                                                               \
        else                                                            \
        {                                                               \
            (__ffdc__).execute();                                       \
            FAPI_ERR(__VA_ARGS__);                                      \
            goto fapi_try_exit;                                         \
        }                                                               \
    }                                                                   \


// ProcThreadControl input commands
// If you make this an enum, the compiler can
// check that a case statement has all the elements
// covered.
    enum ThreadCommands
    {
        PTC_CMD_SRESET            = 0,
        PTC_CMD_STEP              = 1,
        PTC_CMD_START             = 2,
        PTC_CMD_STOP              = 3,
        PTC_CMD_QUERY             = 4,
    };

    enum ThreadRasStatus
    {
        CORE_MAINT_MODE = 0,
        THREAD_QUIESCED = 1,
        ICT_EMPTY       = 2,
        LSU_QUIESCED    = 3,
        STEP_SUCCESS    = 4,
    };

    enum PTC_Constants
    {
        RAS_MODE_STEP_SHIFT       = 52,
        PTC_STEP_COMP_POLL_LIMIT  = 10,
    };

// Bit positions in the DIRECT_CONTROL register
    enum ThreadControl
    {
        CLEAR_MAINT      = 3,
        SRESET_REQUEST   = 4,
        CORE_STEP        = 5,
        CORE_START       = 6,
        CORE_STOP        = 7,
    };

/// @typedef p9_thread_control_FP_t
/// function pointer typedef definition for HWP call support
    typedef fapi2::ReturnCode (*p9_thread_control_FP_t) (
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>&,
        const uint8_t, const ThreadCommands, const bool,
        fapi2::buffer<uint64_t>&, uint64_t&);

//--------------------------------------------------------------------------
/// @brief p9_thread_control: utility subroutine to control thread state
/// @param[in] i_target ex target
/// @param[in] i_threads fused thread bitset (0b00000000..0b11111111)
/// @param[in] i_command  one of
///               PTC_CMD_SRESET => initiate sreset thread command
///               PTC_CMD_START  => initiate start thread command
///               PTC_CMD_STOP   => initiate stop thread command
///               PTC_CMD_STEP   => initiate step thread command
///               PTC_CMD_QUERY  => query and return thread state
/// @param[in] i_warncheck convert pre/post checks errors to warnings
/// @return FAPI_RC_SUCCESS if operation was successful,
///         function-specific fail codes (see function definitions),
///         else error
//-------------------------------------------------------------------------
//fapi2::ReturnCode p9_thread_control(const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
//        const uint8_t i_threads, const ThreadCommands i_command,
//        const bool i_warncheck);

//--------------------------------------------------------------------------
/// @brief p9_thread_control: utility subroutine to control thread state
///
/// @param[in] i_target core target
/// @param[in] i_threads     Desired thread bit set, multiple thread settings
///                          are allowed.
///                             0b0000         No thread (No-op)
///                             0b1000         Thread 0
///                             0b0100         Thread 1
///                             0b0010         Thread 2
///                             0b0001         Thread 3
/// @param[in] i_command  one of
///               PTC_CMD_SRESET => initiate sreset thread command
///               PTC_CMD_START  => initiate start thread command
///               PTC_CMD_STOP   => initiate stop thread command
///               PTC_CMD_STEP   => initiate step thread command
///               PTC_CMD_QUERY  => query and return thread state
/// @param[in] i_warncheck convert pre/post checks errors to warnings
/// @param[out] o_rasStatusReg  Complete RAS status reg 64-bit buffer after
///                             executing command.
/// @param[out] o_state Thread state, only valid for PTC_CMD_QUERY command.
///                    See p9_thread_control.H for THREAD_STATE bit definitions.
///
/// @return FAPI_RC_SUCCESS if operation was successful,
///         function-specific fail codes (see function definitions),
///         else error
//--------------------------------------------------------------------------
    fapi2::ReturnCode p9_thread_control(const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
                                        const uint8_t i_threads, const ThreadCommands i_command,
                                        const bool i_warncheck,
                                        fapi2::buffer<uint64_t>& o_rasStatusReg,
                                        uint64_t& o_state);

} // extern

#endif // _P9_THREAD_CONTROL_H_
