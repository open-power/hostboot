/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_io_ppe_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/// @file p10_io_ppe_utils.C
///
/// @brief Common code to support p10_get/putsram_io_ppe HWPs.
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: N/A
/// *HWP Consumed by: HB, Cronus, SBE
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_io_ppe_utils.H>
#include <p10_scom_pauc.H>

//------------------------------------------------------------------------------
// scomt name spaces
//------------------------------------------------------------------------------
using namespace scomt;
using namespace scomt::pauc;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
/// NOTE: doxygen in header
fapi2::ReturnCode enableDisableIoPpeAutoInc(
    const fapi2::Target < fapi2::TARGET_TYPE_PAUC | fapi2::TARGET_TYPE_MULTICAST > & i_target,
    bool i_enable)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_SRAM_ctrl_reg(0);

    // There are write-only OR/CLEAR addresses for SRAM control reg 0x10012C0A
    // PHY_PPE_WRAP_ARB_CSCR_WO_OR    (0x10012C0C, write 1 to set)
    // PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR (0x10012C0B, write 1 to clear)
    if (i_enable == true)
    {
        FAPI_DBG("Enable SRAM Auto Increment.");
        FAPI_TRY(PREP_PHY_PPE_WRAP_ARB_CSCR_WO_OR(i_target),
                 "enableDisableIoPpeAutoInc: PREP_PHY_PPE_WRAP_ARB_CSCR_WO_OR returns an error.");
        SET_PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE(l_SRAM_ctrl_reg); // Write 1 to set
        FAPI_TRY(PUT_PHY_PPE_WRAP_ARB_CSCR_WO_OR(i_target, l_SRAM_ctrl_reg),
                 "enableDisableIoPpeAutoInc: PUT_PHY_PPE_WRAP_ARB_CSCR_WO_OR returns an error (Enable auto-inc).");
    }
    else
    {
        FAPI_DBG("Disable SRAM Auto Increment.");
        FAPI_TRY(PREP_PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR(i_target),
                 "enableDisableIoPpeAutoInc: PREP_PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR returns an error.");
        SET_PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE(l_SRAM_ctrl_reg); // Write 1 to clear
        FAPI_TRY(PUT_PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR(i_target, l_SRAM_ctrl_reg),
                 "enableDisableIoPpeAutoInc: PUT_PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR returns an error (Disable auto-inc).");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
