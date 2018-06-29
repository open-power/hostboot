/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/io/p9_io_cen_scominit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
/// @file p9_io_cen_scominit.C
/// @brief Invoke OBUS initfile
///
///----------------------------------------------------------------------------
/// *HWP HWP Owner       : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner: Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner        : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team            : IO
/// *HWP Level           : 1
/// *HWP Consumed by     : FSP:HB
///----------------------------------------------------------------------------
///
/// @verbatim
/// High-level procedure flow:
///
///   Invoke CEN scominit file.
///
/// Procedure Prereq:
///   - System clocks are running.
/// @endverbatim
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <p9_io_cen_scominit.H>
#include <centaur_dmi_scom.H>

//------------------------------------------------------------------------------
//  Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// HWP entry point, comments in header
fapi2::ReturnCode p9_io_cen_scominit(const CEN_TGT& i_tgt)
{
    // mark HWP entry
    FAPI_INF("p9_io_cen_scominit: Entering...");

    fapi2::ReturnCode rc = fapi2::FAPI2_RC_SUCCESS;

    // Get system target
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> sys_tgt;

    FAPI_INF("Invoke FAPI procedure core: input_target");
    FAPI_EXEC_HWP(rc, centaur_dmi_scom, i_tgt, sys_tgt);

    if(rc)
    {
        FAPI_ERR("P9 I/O Cen Scominit Failed");
        fapi2::current_err = rc;
    }

    // mark HWP exit
    FAPI_INF("p9_io_cen_scominit: ...Exiting");
    return fapi2::current_err;
}

