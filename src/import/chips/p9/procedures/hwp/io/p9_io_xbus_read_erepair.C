/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_xbus_read_erepair.C $ */
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
/// @file p9_io_xbus_read_erepair.C
/// @brief Read eRepair.
///----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 1
/// *HWP Consumed by      : FSP:HB
///----------------------------------------------------------------------------
///
/// @verbatim
/// High-level procedure flow:
///
/// A HWP that runs Read eRepair. This procedure reads the current bad
/// lanes and passes by reference the lane numbers in a vector.
///
/// Procedure Prereq:
///     - System clocks are running.
///
/// @endverbatim
///----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------------
#include "p9_io_xbus_read_erepair.H"

// ----------------------------------------------------------------------------
// Procedure Function
// ----------------------------------------------------------------------------


/**
 * @brief A HWP that runs Read eRepair. This procedure reads the current bad
 * lanes and passes by reference the lane numbers in a vector
 * @param[in] i_target Reference to Target
 * @param[out] o_bad_lanes Vector of bad lanes
 * @retval ReturnCode
 */
fapi2::ReturnCode
p9_io_xbus_read_erepair(const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
                        std::vector< uint8_t >& o_bad_lanes)
{
    FAPI_IMP("Entering...");
    fapi2::ReturnCode rc = 0;
#if 0

fapi_try_exit:
#endif
    FAPI_IMP("Exiting...");
    return fapi2::FAPI2_RC_SUCCESS;
}

