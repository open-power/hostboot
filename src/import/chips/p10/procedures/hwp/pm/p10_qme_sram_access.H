/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_qme_sram_access.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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

/// @file  p10_qme_sram_access.H
/// @brief Display data from the targetted QME's SRAM array.
///
// *HWP HWP Owner       : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Amit Tendolkar <amit.tendolkar@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 3
// *HWP Consumed by     : HS:CRO:SBE
///

///-----------------------------------------------------------------------------

#ifndef _QME_SRAM_ACCESS_H_
#define _QME_SRAM_ACCESS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

namespace qmesram
{

enum Op
{
    GET,
    PUT,
    GET_NOAUTOINC,
    PUT_NOAUTOINC
};

} // end of namespace qmesram


// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_qme_sram_access_FP_t) (
    const fapi2::Target < fapi2::TARGET_TYPE_EQ | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > &,
    const uint32_t,
    const uint32_t,
    const qmesram::Op,
    uint64_t*,
    uint32_t&);

extern "C" {

// -----------------------------------------------------------------------------
//  Function prototype
// -----------------------------------------------------------------------------

/// @addtogroup pm_fapi
/// @{

/// @brief Display data from the targetted QME's SRAM array.
///
/// High-level procedure flow:
///
///  Procedure Prereq:
///     - System clocks are running
///     - QME to display is enabled and unfenced
///  Note that the address does not wrap if the length + starting address exceeds the maximum address
///
/// @param [in]  i_qme_target         EQ target
/// @param [in]  i_start_address      Start Address is between 0xFFFF80000 and 0xFFFFFFFF and must be 8B aligned
/// @param [in]  i_length_dword       Length in dwords (# of accesses)
/// @param [in]  i_operation          Access operatio to perform (GET/PUT/)
/// @param [out] o_data               Output Data
/// @param [out] o_dwords_read        Number of actual words in the output buffer.
///
/// @retval FAPI2_RC_SUCCESS
/// @retval RC_PROCPM_GPE_CODE_BAD_MODE
    fapi2::ReturnCode p10_qme_sram_access(
        const fapi2::Target < fapi2::TARGET_TYPE_EQ | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_qme_target,
        const uint32_t i_start_address,
        const uint32_t i_length_dword,
        const qmesram::Op i_operation,
        uint64_t* o_data,
        uint32_t& o_dwords_read);

/// @}  end addtogroup

} // extern "C"

#endif // _QME_SRAM_ACCESS_H_
