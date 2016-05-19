/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_cme_sram_access.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file  p9_cme_sram_access.H
/// @brief Display data from the targetted CME's SRAM array.
///
// *HWP HWP Owner       : Brian Vanderpool <vanderp@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 2
// *HWP Consumed by     : HS:CRO:SBE
///
///-----------------------------------------------------------------------------

#ifndef _p9_cme_sram_access_H_
#define _p9_cme_sram_access_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <p9_quad_scom_addresses.H>

#include <p9_pm.H>


// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_cme_sram_access_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_cme_target,
    const uint32_t i_start_address,
    const uint32_t i_length_dword,
    uint64_t* o_data,
    uint32_t& o_dwords_read);

extern "C" {


// -----------------------------------------------------------------------------
//  Function prototype
// -----------------------------------------------------------------------------

/// @addtogroup pm_fapi
/// @{

/// @brief Display data from the targetted CME's SRAM array.
///
/// High-level procedure flow:
///
///
///  Procedure Prereq:
///     - System clocks are running
///     - CME to display is enabled and unfenced
///  Note that the address does not wrap if the length + starting address exceeds the maximum address
///
/// @param [in]  i_cme_target         EX target
/// @param [in]  i_start_address      Start Address is between 0xFFFF80000 and 0xFFFFFFFF and must be 8B aligned
/// @param [in]  i_length_dword       Length in dwords (# of accesses)
/// @param [out] o_data               Output Data
/// @param [out] o_dwords_read        Number of actual words in the output buffer.

///
/// @retval FAPI2_RC_SUCCESS
/// @retval RC_PROCPM_GPE_CODE_BAD_MODE
    fapi2::ReturnCode p9_cme_sram_access(
        const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_cme_target,
        const uint32_t i_start_address,
        const uint32_t i_length_dword,
        uint64_t* o_data,
        uint32_t& o_dwords_read);

/// @}  end addtogroup

} // extern "C"

#endif // _p9_cme_sram_access_H_
