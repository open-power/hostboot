/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/assert_noexit.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
/// @file assert_noexit.H
/// @brief MSS specific assert, but don't exit macro
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_ASSERT_NOEXIT_H_
#define _MSS_ASSERT_NOEXIT_H_

#include <fapi2.H>

///
/// @brief Create an error log based on __conditional__,
/// the FFDC gathering function is called and the
/// trace is output as a FAPI error trace. An error log
/// is created. fapi2::current_err is set to indicate there was
/// an error so the caller can ripple thru accordingly
/// The caller is responsible for handling the error object.
///
/// @param[in] __conditional__ the condition to assert
/// @param[in] __ffdc__ the FFDC gathering function
/// @param[in] ... varargs, as input to FAPI_ERR
///
#define MSS_ASSERT_NOEXIT( __conditional__, __ffdc__, ... )             \
    if (! (__conditional__))                                            \
    {                                                                   \
        __ffdc__.execute(fapi2::FAPI2_ERRL_SEV_UNDEFINED, true);        \
        FAPI_ERR(__VA_ARGS__);                                          \
        fapi2::current_err = fapi2::FAPI2_RC_FALSE;                     \
    }

#endif
