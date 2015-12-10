/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/plat_utils.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
///
/// @file plat_utils.H
///
/// @brief FAPI2 utility functions
///
/// Note that platform code must provide the implementation.
///

#ifndef PLAT_UTILS_H_
#define PLAT_UTILS_H_

#include <return_code.H>

namespace fapi2
{

///
///  @brief This function answers the question, is scand tracing turned on?
///  The implementation of this function is specific to the platform.
///
///  @returns Boolean indication
///
bool platIsScanTraceEnabled();

///
/// @brief Converts a fapi2::ReturnCode to a HostBoot PLAT error log
///
/// @param[io] io_rc Reference to ReturnCode (set to success after function)
/// @param[in] i_sev Error log severity defaulted to unrecoverable
///
/// @return errlHndl_t (NULL if Return Code contained success)
///
errlHndl_t rcToErrl(ReturnCode & io_rc,
                    ERRORLOG::errlSeverity_t i_sev =
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE);

} // End namespace fapi2

#endif // PLAT_UTILS_H_
