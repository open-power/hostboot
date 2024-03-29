/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_mss_eff_grouping.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// ----------------------------------------------------------------------------
/// @file  p10_mss_eff_grouping.H
///
/// @brief Perform Memory Controller grouping on each processor chip
///
/// The purpose of this procedure is to effectively group the memory on each
/// processor chip based on available memory behind its memory ports.
/// Some placement policy/scheme and other info that are stored in the
/// attributes are used as part of the grouping process.
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
/// ----------------------------------------------------------------------------

#ifndef _P10_MSS_EFF_GROUPING_H_
#define _P10_MSS_EFF_GROUPING_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

///----------------------------------------------------------------------------
/// Constant definitions
///----------------------------------------------------------------------------

// Constants used for EffGroupingData struct
const uint8_t DATA_GROUPS   = 16;   // 8 regular groups, 8 mirrored groups
const uint8_t MIRR_OFFSET   = 8;    // Start of mirrored offset in DATA_GROUPS
const uint8_t DATA_ELEMENTS = 21;   // 21 items of data for each group
const uint8_t SUBCHANNEL_PER_CHANNEL = 2; // Number of OMI's per MCC

// Indexes used for EffGroupingData::iv_data DATA ELEMENTS
const uint8_t MCC_SIZE = 0;          // Memory size of each MCC in group (GB)
const uint8_t MCC_IN_GROUP = 1;      // Number of MCC in group
const uint8_t GROUP_SIZE = 2;        // Memory size of entire group (GB)
const uint8_t BASE_ADDR = 3;         // Base Address
#define MEMBER_IDX(X) ((X) + 4)      // List of MCC in group
#define ALT_VALID(X) ((X) + 12)      // Alt Memory Valid (2 alt memory regions)
#define ALT_SIZE(X) ((X) + 14)       // Alt Memory Size
#define ALT_BASE_ADDR(X) ((X) + 16)  // Alt Base Address
const uint8_t SMF_VALID = 18;        // SMF Memory Valid
const uint8_t SMF_SIZE = 19;         // SMF Memory Size
const uint8_t SMF_BASE_ADDR = 20;    // SMF Base Address

// Number of memory regions
const uint8_t NUM_NON_MIRROR_REGIONS = 8;
const uint8_t NUM_MIRROR_REGIONS     = 8;  // Each MCC does its own mirroring
const uint8_t NUM_OF_CHTM_REGIONS    = 32; // 32 CHTM memory regions
const uint8_t NUM_OF_ALT_MEM_REGIONS = 2;  // 2 memory holes

// ------------------------------------------
// MC: 4 per proc, contains 2 MCCs (channel)
// ------------------------------------------
const uint8_t NUM_MC_PER_PROC       = 4;  // MI
const uint8_t NUM_MCC_PER_PROC      = 8;

/// Function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_mss_eff_grouping_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
/// @brief p10_mss_eff_grouping procedure
///
/// This HWP is to group the Memory channels of the input target processor chip
/// based on the amount of memory behind its ports and some policy attribute
/// settings.
///
/// @param[in]    i_target   Reference to TARGET_TYPE_PROC_CHIP target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
extern "C"
{
    fapi2::ReturnCode p10_mss_eff_grouping(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

} // extern "C"

#endif  // _P10_MSS_EFF_GROUPING_H_
