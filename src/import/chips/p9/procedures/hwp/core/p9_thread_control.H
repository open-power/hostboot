/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/core/p9_thread_control.H $            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : p9_thread_control
// *! DESCRIPTION : Core Thread start/stop/step/query/activate operations
// *!               Use to start (start or sreset) thread instruction execution,
// *!                 stop instruction execution, or single instruction step.
// *!               Also used to query the state of a thread.
// *! OWNER NAME  : Nick Klazynski      Email: jklazyns@us.ibm.com
// *! BACKUP NAME : Sebastien Lafontant Email: slafont@us.ibm.com
//------------------------------------------------------------------------------

// *HWP HWP Owner: Michael Dye <dyem@us.ibm.com>
// *HWP FW Owner:  Brian Silver <bsilver@us.ibm.com>
// *HWP Team:  Quad
// *HWP Level: 2
// *HWP Consumed by: FSP:HB:HS

#ifndef _P9_THREAD_CONTROL_H_
#define _P9_THREAD_CONTROL_H_

#include <fapi2.H>
#include <return_code.H>
#include <error_scope.H>

#include "p9_quad_scom_addresses.H"

// A macro to wrap the warning check boiler plate
// If the action failed and i_warncheck is set add a trace and continue anyway
#define PTC_ASSERT_WARN( __conditional__, __warning__, __ffdc__, ... )  \
    if (! (__conditional__))                                            \
    {                                                                   \
        if (__warning__)                                                \
        {                                                               \
            FAPI_INF(__VA_ARGS__);                                      \
        }                                                               \
        \
        (__ffdc__).execute();                                           \
        FAPI_ERR(__VA_ARGS__);                                          \
        goto fapi_try_exit;                                             \
    }


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
};

enum ThreadRasStatus
{
    CORE_MAINT_MODE = 0,
    THREAD_QUIESCED = 1,
    ICT_EMPTY       = 2,
    ISU_QUIESCED    = 3,
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
extern fapi2::ReturnCode p9_thread_control(const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
        const uint8_t i_threads, const ThreadCommands i_command,
        const bool i_warncheck);


//--------------------------------------------------------------------------
/// @brief p9_thread_control: utility subroutine to control thread state
/// @param[in] i_target core target
/// @param[in] i_thread normal core thread bitset (0b0000..0b1111)
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
//--------------------------------------------------------------------------
extern fapi2::ReturnCode p9_thread_control(const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
        const uint8_t i_threads, const ThreadCommands i_command,
        const bool i_warncheck);
#endif // _P9_THREAD_CONTROL_H_
