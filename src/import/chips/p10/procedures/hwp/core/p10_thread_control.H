/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/core/p10_thread_control.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file p10_thread_control.H
///
/// @brief Core Thread start/stop/step/query/activate operations
///        Use to start (start or sreset) thread instruction execution,
///        stop instruction execution, or single instruction step.
///        Also used to query the state of a thread.
/// *HWP HW Maintainer: Nicholas Landi <nlandi@ibm.com>
/// *HWP FW Maintainer: Raja Das <rajadas2@in.ibm.com>
/// *HWP Consumed by  : SBE
///----------------------------------------------------------------------------
#ifndef _P10_THREAD_CONTROL_H_
#define _P10_THREAD_CONTROL_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

#include <p10_scom_c.H>

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
    do{                                                                     \
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
    } while(0)                                                              \

// ProcThreadControl input commands
        enum ThreadCommands
    {
        PTC_CMD_SRESET  = 0,
        PTC_CMD_STEP    = 1,
        PTC_CMD_START   = 2,
        PTC_CMD_STOP    = 3,
        PTC_CMD_QUERY   = 4,
    };

    enum ThreadSpecifier
    {
        NO_THREADS =  0b0000,
        THREAD0 =     0b1000,
        THREAD1 =     0b0100,
        THREAD2 =     0b0010,
        THREAD3 =     0b0001,
        ALL_THREADS = 0b1111
    };

/// @typedef p10_thread_control_FP_t
/// function pointer typedef definition for HWP call support
    typedef fapi2::ReturnCode (*p10_thread_control_FP_t) (
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>&,
        const ThreadSpecifier, const ThreadCommands, const bool,
        fapi2::buffer<uint64_t>&, uint64_t&);

    extern "C"
    {

///--------------------------------------------------------------------------
/// @brief p10_thread_control: utility subroutine to control thread state
///
/// @param[in] i_target    Core target
/// @param[in] i_threads   Desired thread bit set, multiple thread settings
///                        are allowed.
///                             0b0000         No thread (No-op)
///                             0b1000         Thread 0
///                             0b0100         Thread 1
///                             0b0010         Thread 2
///                             0b0001         Thread 3
/// @param[in] i_command   One of
///                            PTC_CMD_SRESET => initiate sreset thread command
///                            PTC_CMD_START  => initiate start thread command
///                            PTC_CMD_STOP   => initiate stop thread command
///                            PTC_CMD_STEP   => initiate step thread command
///                            PTC_CMD_QUERY  => query and return thread state
/// @param[in] i_warncheck convert pre/post checks errors to warnings
/// @param[out] o_rasStatusReg  Complete RAS status reg 64-bit buffer after
///                             executing command.
/// @param[out] o_state Thread state, only valid for PTC_CMD_QUERY command.
///                     See THREAD_STATE bit definitions above.
///
/// @return FAPI_RC_SUCCESS if operation was successful,
///         function-specific fail codes (see function definitions),
///         else error
///--------------------------------------------------------------------------
        fapi2::ReturnCode p10_thread_control(
            const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
            const ThreadSpecifier i_threads, const ThreadCommands i_command,
            const bool i_warncheck,
            fapi2::buffer<uint64_t>& o_rasStatusReg,
            uint64_t& o_state);

    } // extern

#endif // _P10_THREAD_CONTROL_H_
