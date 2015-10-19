/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_occ_control.C $   */
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
/// @file  p9_pm_occ_control.C
/// @brief Initialize boot vector registers and control PPC405
///
/// *HWP HWP Owner: Greg Still <stillgs @us.ibm.com>
/// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
/// *HWP Team: PM
/// *HWP Level: 1
/// *HWP Consumed by: FSP:HS
///

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------
#include <p9_pm_occ_control.H>

// -----------------------------------------------------------------------------
//  Constant Defintions
// -----------------------------------------------------------------------------

enum PPCC_BRANCH_INSTR
{
    // Branch Absolute 0xFFF80040  (boot from sram)
    PPC405_BRANCH_SRAM_INSTR = 0x4BF80042,
    // Branch Absolute 0x00000040  (boot from memory)
    PPC405_BRANCH_MEM_INSTR  = 0x48000042,
    // Branch Relative -16         (boot from sram)
    PPC405_BRANCH_OLD_INSTR  = 0x4BFFFFF0
};

enum DELAY_VALUE
{
    NS_DELAY = 1000000,// 1,000,000 ns = 1ms
    SIM_CYCLE_DELAY = 10000
};

// -----------------------------------------------------------------------------
//   Procedure Defintion
// -----------------------------------------------------------------------------
fapi2::ReturnCode p9_pm_occ_control
(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
 const p9occ_ctrl::PPC_CONTROL i_ppc405_reset_ctrl,
 const p9occ_ctrl::PPC_BOOT_CONTROL i_ppc405_boot_ctrl)
{
    FAPI_IMP("Entering p9_pm_occ_control ....");

    FAPI_IMP("Exiting p9_pm_occ_control ....");
    return fapi2::current_err;
}
