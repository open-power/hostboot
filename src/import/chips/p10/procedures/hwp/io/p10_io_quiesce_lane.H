/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_quiesce_lane.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
/// @file p10_io_quiesce_lane.H
/// @brief Quiesce PHY resources associated with lane failed/spared by DL
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------
///

// EKB-Mirror-To: hostboot

#ifndef __P10_IO_QUIESCE_LANE__
#define __P10_IO_QUIESCE_LANE__

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_io_quiesce_lane_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_IOLINK>&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Quiesce PHY resources associated with lane failed/spared by DL
///
/// @param[in] i_target Reference to IOLINK target with recently spared lane
///
/// @return fapi::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_io_quiesce_lane(
        const fapi2::Target<fapi2::TARGET_TYPE_IOLINK>& i_iolink_target);

} // extern "C"
#endif
