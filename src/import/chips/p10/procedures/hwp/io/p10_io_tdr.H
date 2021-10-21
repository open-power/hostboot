/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_tdr.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file p10_io_tdr.H
/// @brief TDR Functions
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------

#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
enum TdrResult
{
    None              = 0x0000,
    Good              = 0x0010,
    Open              = 0x0020,
    Short             = 0x0030,
    ShortToGnd        = 0x0001 | Short,
    ShortToVdd        = 0x0002 | Short,
    DidNotRun         = 0x2000,
    NotSupported      = 0x4000,
    UnableToDetermine = 0x8000
};

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_io_tdr_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_IOLINK>&,
    const std::vector<uint32_t>&,
    std::vector<uint32_t>&,
    std::vector<uint32_t>&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{
/// @brief Use TDR to check for net opens and shorts
/// @param[in] i_iolink_target      IOLINK target to get thread id for
/// @param[in] i_lanes              Lanes to run TDR on
/// @param[out] o_status            Status of the net (Open, Short, Good)
/// @param[out] o_length_mm         Length from TX to open (in mm)
/// @return FAPI_RC_SUCCESS if arguments are valid
    fapi2::ReturnCode p10_io_tdr(
        const fapi2::Target<fapi2::TARGET_TYPE_IOLINK>& i_iolink_target,
        const std::vector<uint32_t>& i_lanes,
        std::vector<uint32_t>& o_status,
        std::vector<uint32_t>& o_length_mm);

} // extern "C"
