/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_occ_control.C $              */
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

