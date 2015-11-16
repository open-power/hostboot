/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_occ_control.H $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file  p9_pm_occ_control.H
/// @brief Reset and halt control of the OCC PPC405
///
// *HWP HWP Owner: Greg Still <stillgs @us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: FSP:HS
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
///       - If (i_ppc405_boot_ctrl = PPC405_BOOT_MEM)
///            Initialize to Branch Absolute 0x00000010
///       - If (i_ppc405_boot_ctrl = PPC405_BOOT_OLD)
///            initialize to Branch Relative -16
/// - Write PPC405 reset/halt bits based on i_ppc405_reset_ctrl (OCR, OJCFG)
///     - if PPC405_RESET_NULL , do nothing
///     - if PPC405_RESET_OFF  , write reset bit to 0 (PPC405 not reset)
///     - if PPC405_RESET_ON   , write reset bit to 1 (PPC405 reset)
///     - if PPC405_HALT_OFF   , write halt bit to 0  (PPC405 not halted)
///     - if PPC405_HALT_ON    , write halt bit to 1  (PPC405 halted)
///     - if PPC405_RESET_SEQUENCE , Perform the safe halt->reset sequence
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
    PPC405_RESET_SEQUENCE    ///< Perform the safe halt->reset sequence
};

enum PPC_BOOT_CONTROL
{
    PPC405_BOOT_NULL,        ///< Do nothing
    PPC405_BOOT_SRAM,        ///< Boot from OCC SRAM
    PPC405_BOOT_MEM,         ///< Boot from memory
    PPC405_BOOT_OLD          ///< Deprecated
};
}

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pm_occ_control_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
 const p9occ_ctrl::PPC_CONTROL,
 const p9occ_ctrl::PPC_BOOT_CONTROL);

extern "C" {

// -----------------------------------------------------------------------------
//  Function prototype
// -----------------------------------------------------------------------------

/// @brief Control the operation of the OCC PPC405
/// @param [in]  i_target            Chip Target
/// @param [in]  i_ppc405_reset_ctrl Actionto be taken on PPC405
/// @param [in]  i_ppc405_boot_ctrl  Location of boot instruction
///
/// @return FAPI_RC_SUCCESS on success or error return code
    fapi2::ReturnCode p9_pm_occ_control(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const p9occ_ctrl::PPC_CONTROL i_ppc405_reset_ctrl,
        const p9occ_ctrl::PPC_BOOT_CONTROL i_ppc405_boot_ctrl);
} // extern "C"

#endif // _P9_OCC_CONTROL_H_
