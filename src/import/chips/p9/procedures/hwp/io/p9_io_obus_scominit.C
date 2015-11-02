/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_obus_scominit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
/// @file p9_io_obus_scominit.C
/// @brief Invoke OBUS initfile
///
//----------------------------------------------------------------------------
// *HWP HWP Owner       : Chris Steffen <cwsteffen@us.ibm.com>
// *HWP HWP Backup Owner:
// *HWP FW Owner        : Sumit Kumar <sumit_kumar@in.ibm.com>
// *HWP Team            : IO
// *HWP Level           : 1
// *HWP Consumed by     : FSP:HB
//----------------------------------------------------------------------------
//
// @verbatim
// High-level procedure flow:
//
//   Invoke OBUS scominit file.
//
// Procedure Prereq:
//   - System clocks are running.
// @endverbatim
//----------------------------------------------------------------------------


//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <p9_io_gcr.H>
#include <p9_io_regs.H>
#include <p9_io_obus_scominit.H>


//------------------------------------------------------------------------------
//  Constant definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// HWP entry point, comments in header
fapi2::ReturnCode p9_io_obus_scominit(
    const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& i_target,
    const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& i_connected_target)
{
    // mark HWP entry
    FAPI_INF("p9_io_obus_scominit: Entering...");


    // mark HWP exit
    FAPI_INF("p9_io_obus_scominit: ...Exiting");

    return fapi2::FAPI2_RC_SUCCESS;
}
