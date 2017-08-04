/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_occ_control.H $   */
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
/// @file  p9_pm_occ_control.H
/// @brief Reset and halt control of the OCC PPC405
///
// *HWP HWP Owner: Greg Still <stillgs @us.ibm.com>
// *HWP HWP Backup Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 3
// *HWP Consumed by: HS
///
/// @verbatim
/// High-level procedure flow:
/// - process parameters passed to procedure
/// - If (i_ppc405_boot_ctrl != PPC405_BOOT_NULL)
///     Initialize boot vector registers in SRAM (SRBV0,1,2,3)
///     - Initialize SRBV0,1,2 with all 0's (illegal instructions)
///     - Initialize SRBV0 per passed parameter (i_ppc405_boot_ctrl)
///       - If (i_ppc405_boot_ctrl = PPC405_BOOT_SRAM)
///            Initialize to Branch Absolute 0xFFF80010
///       - Else If (i_ppc405_boot_ctrl = PPC405_BOOT_OLD)
///            initialize to Branch Relative -16
///       - Else (i_ppc405_boot_ctrl = PPC405_BOOT_MEM || NULL)
///             Load branch formation code into OCC SRAM at 0xFFF40000
///             to branch to 0x80000010 (HOMER + 0x40)
///            Initialize to Branch Absolute  0xFFF40000
/// - Write PPC405 reset/halt bits based on i_ppc405_reset_ctrl (OCR, OJCFG)
///     - if PPC405_RESET_NULL , do nothing
///     - if PPC405_RESET_OFF  , write reset bit to 0 (PPC405 not reset)
///     - if PPC405_RESET_ON   , write reset bit to 1 (PPC405 reset)
///     - if PPC405_HALT_OFF   , write halt bit to 0  (PPC405 not halted)
///     - if PPC405_HALT_ON    , write halt bit to 1  (PPC405 halted)
///     - if PPC405_RESET_SEQUENCE , Perform the safe halt->reset sequence
///     - if PPC405_START      , Start the PPC405
///
/// Procedure Prereq:
///   - System clocks are running
/// @endverbatim


#ifndef _P9_OCC_CONTROL_H_
#define _P9_OCC_CONTROL_H_

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_pm.H>
#include <p9_misc_scom_addresses.H>
#include <p9_perv_scom_addresses.H>

// -----------------------------------------------------------------------------
//  ENUMS
// -----------------------------------------------------------------------------
namespace p9occ_ctrl
{
enum PPC_CONTROL
{
    PPC405_RESET_NULL,       ///< Do nothing
    PPC405_RESET_OFF,        ///< Deassert the PPC405 reset
    PPC405_RESET_ON,         ///< Assert the PPC405 reset
    PPC405_HALT_OFF,         ///< Deassert the PPC405 halt
    PPC405_HALT_ON,          ///< Assert the PPC405 halt
    PPC405_RESET_SEQUENCE,   ///< Perform the safe halt->reset sequence
    PPC405_START             ///< Perform start sequence
};

enum PPC_BOOT_CONTROL
{
    PPC405_BOOT_NULL,        ///< Do nothing
    PPC405_BOOT_SRAM,        ///< Boot from OCC SRAM
    PPC405_BOOT_MEM,         ///< Boot from memory
    PPC405_BOOT_OLD,         ///< Deprecated
    PPC405_BOOT_WITHOUT_BL   ///< Bypass OCC bootloader and execute main
};
}

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pm_occ_control_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
 const p9occ_ctrl::PPC_CONTROL,
 const p9occ_ctrl::PPC_BOOT_CONTROL,
 const uint64_t i_ppc405_jump_to_main_instr);

extern "C" {

// -----------------------------------------------------------------------------
//  Function prototype
// -----------------------------------------------------------------------------

/// @brief Control the operation of the OCC PPC405
/// @param [in]  i_target            Chip Target
/// @param [in]  i_ppc405_reset_ctrl Actionto be taken on PPC405
/// @param [in]  i_ppc405_boot_ctrl  Location of boot instruction
/// @param [in]  i_ppc405_jump_to_main_instr The instruction to jump to PPC405
///              main. Used to bypass the OCC bootloader. Default = 0
///
/// @return FAPI_RC_SUCCESS on success or error return code
    fapi2::ReturnCode p9_pm_occ_control(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const p9occ_ctrl::PPC_CONTROL i_ppc405_reset_ctrl,
        const p9occ_ctrl::PPC_BOOT_CONTROL i_ppc405_boot_ctrl,
        const uint64_t i_ppc405_jump_to_main_instr = 0);
} // extern "C"

#endif // _P9_OCC_CONTROL_H_
