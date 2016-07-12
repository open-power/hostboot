/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_dump_stop_info.H $   */
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

/// @file  p9_dump_stop_info.H
/// @brief Dump the state of STOP processing hardware (including relevant PPEs)
///        for first failure capture debug.
///
// *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Prem S Jha <premjha2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: FSP:HS
///
///-----------------------------------------------------------------------------

#ifndef _P9_DUMPSTOPINFO_H_
#define _P9_DUMPSTOPINFO_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <p9_quad_scom_addresses.H>
#include <p9_quad_scom_addresses_fld.H>


// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_dump_stop_info_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

extern "C"
{

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

/// @brief Dump the state of STOP processing hardware (including relevant PPEs)
///        for first failure capture debug.
///
/// @param[in] i_target    Chip target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
/// @attr   ATTR_DUMP_STOP_INFO_SUPPRESS_ERROR_TRACE   if set to 1, FAPI_ERR records
///         are suppressed.  Default i that FAPI_ERR records will be produced.
/// @attr   ATTR_DUMP_STOP_INFO_ENABLE_ERRORLOG        if set to 1, will write state
///         information to error logs.

    fapi2::ReturnCode p9_dump_stop_info(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

} // extern "C"

#endif // _P9_DUMPSTOPINFO_H_
