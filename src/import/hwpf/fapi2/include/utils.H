/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source:  $                                                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
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
/**
 * @file utils.H
 * @brief Defines common fapi2 utilities
 */

#ifndef FAPI2_UTILS_H_
#define FAPI2_UTILS_H_

#include <stdint.h>
#include <return_code.H>
#include <error_info_defs.H>

namespace fapi2
{
    ///
    /// @brief Log an error.
    ///
    /// @param[in,out] io_rc Reference to ReturnCode (Any references to data and error
    ///            target are removed and rc value is set to success after
    ///            function ends.)
    /// @param[in] i_sev Fapi error log severity defaulted to unrecoverable
    /// @param[in] i_unitTestError - flag to log error which does not cause a unit
    ///                              test to fail.
    ///
    /// @note This function is called from the ffdc collection classes and no longer
    /// needs to be called directly.
    /// @note Implemented by platform code
    ///
    void logError(
        fapi2::ReturnCode & io_rc,
        fapi2::errlSeverity_t i_sev = fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE,
        bool i_unitTestError = false );

    ///
    /// @brief Delay this thread. Hostboot will use the nanoseconds parameter
    /// and make a syscall to nanosleep. While in the syscall, the hostboot
    /// kernel will continue to consume CPU cycles as it looks for a runnable
    /// task.  When the delay time expires, the task becomes runnable and will soon
    /// return from the syscall.  Callers of delay() in the hostboot environment
    /// will likely have to know the mHz clock speed they are running on and
    /// compute a non-zero value for i_nanoSeconds.
    ///
    /// On the FSP, it was sometimes acceptable to just provide zero for the
    /// sleep delay time, causing the task to yield its time slice. By the
    /// time the calling task could run again, it was pretty certain enough
    /// host cycles had past.  This is probably not acceptable in
    /// the hostboot environment. Callers should calculate and provide a
    /// sleep value in nanoseconds relative to host clock speed.
    ///
    /// On FSP when VBU is the target, then the i_simCycles parameter will be
    /// used instead.  The FSP needs to use the simdispatcher client/server
    /// API and issue a command to the awan to advance the simulation the
    /// specified number of cycles.
    ///
    /// @param[in] i_nanoSeconds    nanoseconds to sleep
    /// @param[in] i_simCycles      count of Awan cycles to advance
    ///
    /// @return ReturnCode. Zero on success, else platform specified error.
    ///
    ReturnCode delay(uint64_t i_nanoSeconds, uint64_t i_simCycles);

    ///
    /// @brief Assert a condition, and halt
    ///
    /// @param[in] a boolean representing the assertion
    ///
    void Assert(bool i_expression);
};

#endif // FAPI2_UTILS_H_
