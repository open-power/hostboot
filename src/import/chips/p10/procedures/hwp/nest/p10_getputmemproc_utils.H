/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_getputmemproc_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#ifndef _P10_GETPUTMEMPROC_UTILS_H_
#define _P10_GETPUTMEMPROC_UTILS_H_

///
/// @file p10_getputmemproc_utils.H
///
/// @brief Common code to support get/putmemproc procedures.
///        Note: This file is not intended to be imported to SBE platform
///              to save its space.
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: N/A
/// *HWP Consumed by: Cronus, HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_adu_utils.H>

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
extern "C" {

/// @brief Verify input sbeMemoryAccessFlags is valid for a ADU operation.
/// @param[in] i_target         Reference to processor chip target
/// @param[in] i_address        Address for the read or write
/// @param[in] i_bytes          Tsize
/// @param[in] i_flags          SBE memory access flag value
/// @return FAPI_RC_SUCCESS if flag is valid; otherwise, error
    fapi2::ReturnCode p10_validateSbeMemoryAccessFlagsADU(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_address,
        const uint32_t i_bytes,
        const uint32_t i_mem_flags);

/// @brief Create ADU flags from sbeMemoryAccessFlags info
/// @param[in] i_target         Reference to processor chip target
/// @param[in] i_address        Address for the read or write
/// @param[in] i_bytes          Tsize
/// @param[in] i_flags          SBE memory access flag value
/// @return FAPI_RC_SUCCESS if flag is valid; otherwise, error
    fapi2::ReturnCode p10_getADUFlags(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_address,
        const uint32_t i_bytes,
        const uint32_t i_mem_flags,
        adu_operationFlag& o_aduFlags);

} //extern "C"

#endif //_P10_GETPUTMEMPROC_UTILS_H_
