/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_dmi_scominit.C $  */
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
/// @file p9_io_dmi_scominit.C
/// @brief Invoke DMI processor side initfile
///
//----------------------------------------------------------------------------
// *HWP HWP Owner       : Chris Steffen <cwsteffen@us.ibm.com>
// *HWP HWP Backup Owner: Gary Peterson <garyp@us.ibm.com>
// *HWP FW Owner        : Sumit Kumar <sumit_kumar@in.ibm.com>
// *HWP Team            : IO
// *HWP Level           : 2
// *HWP Consumed by     : FSP:HB
//----------------------------------------------------------------------------
//
// @verbatim
// High-level procedure flow:
//
//   Invoke DMI scominit file.
//
// Procedure Prereq:
//   - System clocks are running.
// @endverbatim
//----------------------------------------------------------------------------


//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <p9_io_regs.H>
#include <p9_io_scom.H>
#include <p9_io_dmi_scominit.H>
#include <p9c_dmi_io_scom.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/**
 * @brief Gets the value of the ATTR_CHIP_UNIT_NUM and passes back by reference
 * @param[in]  i_tgt         Fapi2 Target
 * @param[out] o_chipunitnum Chip Unit Number
 * @return FAPI2_RC_SUCCESS on success, otherwise error
 */
fapi2::ReturnCode p9_dmi_get_chipunit_num(const DMI_TGT& i_tgt, uint8_t& o_chipunitnum)
{
    FAPI_IMP("I/O DMI Scominit: Get Chipunit Number Start.");

    // Retrieve chipunitnum attribute
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_tgt, o_chipunitnum ),
             "Error getting ATTR_CHIP_UNIT_POS, rc = 0x%.8X",
             (uint64_t)fapi2::current_err );

fapi_try_exit:
    FAPI_IMP("I/O DMI Scominit: Get Chipunit Number Exit.");
    return fapi2::current_err;
}


/**
 * @brief HWP that calls the DMI SCOM initfiles
 * Should be called for all valid/connected DMI endpoints
 *
 * @param[in] i_tgt  Reference to DMI chiplet target
 *
 * @return FAPI2_RC_SUCCESS on success, error otherwise
 */
fapi2::ReturnCode p9_io_dmi_scominit(const DMI_TGT& i_tgt)
{
    // mark HWP entry
    FAPI_INF("p9_io_dmi_scominit: Entering ...");
    const uint8_t GRP_03  = 3;
    const uint8_t LANE_00 = 0;
    fapi2::ReturnCode rc  = fapi2::FAPI2_RC_SUCCESS;

    // Get system target
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> sys_tgt;

    // assert IO reset to power-up bus endpoint logic
    // read-modify-write, set single reset bit (HW auto-clears)
    // on writeback
    FAPI_TRY(io::rmw(EDIP_RX_IORESET, i_tgt, GRP_03, LANE_00, 1));

    // Calculated HW Delay needed based on counter size and clock speed.
    // 50us -- Based on Counter Size, 40us minimum
    // 1 Million sim cycles -- Based on sim learning
    FAPI_TRY(fapi2::delay(50000, 1000000));

    FAPI_TRY(io::rmw(EDIP_TX_IORESET, i_tgt, GRP_03, LANE_00, 1));

    // Calculated HW Delay needed based on counter size and clock speed.
    // 50us -- Based on Counter Size, 40us minimum
    // 1 Million sim cycles -- Based on sim learning
    FAPI_TRY(fapi2::delay(50000, 1000000));

    FAPI_INF("Invoke FAPI2 p9c_dmi_scom Procedure");
    FAPI_EXEC_HWP(rc, p9c_dmi_io_scom, i_tgt, sys_tgt);

    if(rc)
    {
        FAPI_ERR("P9 I/O DMI Scominit Failed");
        fapi2::current_err = rc;
    }

    // mark HWP exit
    FAPI_INF("p9_io_dmi_scominit: ... Exiting");

fapi_try_exit:
    return fapi2::current_err;
}
