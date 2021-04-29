/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mss_log_utils.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
// EKB-Mirror-To: hostboot

///
/// @file mss_log_utils.H
/// @brief Error log helpers
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_LOG_UTILS_H_
#define _MSS_LOG_UTILS_H_

#include <fapi2.H>

namespace mss
{

///
/// @brief Log fapi2::current_err and save it to captured error variable
/// @param[in] i_sev the severity of the error
/// @param[in,out] io_rc the variable in which to capture the error
///
inline void log_and_capture_error( const fapi2::errlSeverity_t i_sev, fapi2::ReturnCode& io_rc )
{
    if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
    {
        io_rc = fapi2::current_err;
        fapi2::logError(io_rc, i_sev);

        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }
}

} // ns mss
#endif
