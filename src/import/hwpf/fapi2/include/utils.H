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
 * @file erro_infor.H
 * @brief Defines the Error Information structures and classes
 */

#ifndef FAPI2_UTILS_H_
#define FAPI2_UTILS_H_

#include <stdint.h>
#include <return_code.H>
#include <error_info.H>

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
};

#endif // FAPI2_UTILS_H_
