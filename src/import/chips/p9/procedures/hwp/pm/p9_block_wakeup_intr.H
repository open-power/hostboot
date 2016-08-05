/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_block_wakeup_intr.H $ */
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

/// @file  p9_block_wakeup_intr.H
/// @brief Set/reset the BLOCK_REG_WKUP_SOURCES bit in the PPM
///         associated with an EX chiplet
///
// *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: FSP:HS
///
///-----------------------------------------------------------------------------

#ifndef _P9_BLKWKUP_H_
#define _P9_BLKWKUP_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <p9_quad_scom_addresses.H>
#include <p9_quad_scom_addresses_fld.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

namespace p9pmblockwkup
{

enum OP_TYPE
{
    SET = 0,
    SET_NOSPWUP = 1,
    CLEAR = 2
};

// Used by checking infrasture checking code
static const uint32_t END_OP = CLEAR;

} // namespace p9pmblockwkup


//
// CPMMR Bit definitions
const uint32_t      BLOCK_REG_WKUP_EVENTS = 6;

// GPMMR Address mappings (for clarity)
static const uint64_t C_PPM_GPMMR       = C_PPM_GPMMR_SCOM;
static const uint64_t C_PPM_GPMMR_CLEAR = C_PPM_GPMMR_SCOM1;
static const uint64_t C_PPM_GPMMR_OR    = C_PPM_GPMMR_SCOM2;

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_block_wakeup_intr_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>&,
    const p9pmblockwkup::OP_TYPE);

extern "C"
{

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

/// @brief @brief Set/reset the BLOCK_REG_WKUP_SOURCES bit in the PPM
///         associated with an EX chiplet
///
/// @param[in] i_core_target    Core target
/// @param[in] i_operation      SET, CLEAR
///
/// @return FAPI2_RC_SUCCESS if success, else error code.

    fapi2::ReturnCode
    p9_block_wakeup_intr(
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_core_target,
        const p9pmblockwkup::OP_TYPE i_operation);

} // extern "C"

#endif // _P9_BLKWKUP_H_
