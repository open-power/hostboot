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
// *HWP HWP Owner: Greg Still <stillgs @us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: FSP:HS

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------
#include <p9_pm_occ_control.H>

// -----------------------------------------------------------------------------
//  Constant Defintions
// -----------------------------------------------------------------------------

enum PPC_BRANCH_INSTR
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

    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_firMask;
    fapi2::buffer<uint64_t> l_occfir;

    // Set up Boot Vector Registers in SRAM
    //    - set bv0-2 to all 0's (illegal instructions)
    //    - set bv3 to proper branch instruction

    if (i_ppc405_boot_ctrl != p9occ_ctrl::PPC405_BOOT_NULL)
    {
        FAPI_DBG("Writing to Boot Vector 0-2 Registers");
        FAPI_TRY(fapi2::putScom(i_target, PU_SRAM_SRBV0_SCOM, l_data64));
        FAPI_TRY(fapi2::putScom(i_target, PU_SRAM_SRBV1_SCOM, l_data64));
        FAPI_TRY(fapi2::putScom(i_target, PU_SRAM_SRBV2_SCOM, l_data64));

        FAPI_DBG("Writing to Boot Vector 3 Register");

        if (i_ppc405_boot_ctrl == p9occ_ctrl::PPC405_BOOT_SRAM)
        {
            l_data64.flush<0>().insertFromRight(PPC405_BRANCH_SRAM_INSTR, 0, 32);
        }
        else if (i_ppc405_boot_ctrl == p9occ_ctrl::PPC405_BOOT_MEM)
        {
            l_data64.flush<0>().insertFromRight(PPC405_BRANCH_MEM_INSTR, 0, 32);
        }
        else
        {
            l_data64.flush<0>().insertFromRight(PPC405_BRANCH_OLD_INSTR, 0, 32);
        }

        FAPI_TRY(fapi2::putScom(i_target, PU_SRAM_SRBV3_SCOM, l_data64));
    }
    else
    {
        FAPI_INF("Boot instruction location not specified");
    }

    // Handle the i_ppc405_reset_ctrl parameter
    switch (i_ppc405_reset_ctrl)
    {
        case p9occ_ctrl::PPC405_RESET_NULL:
            FAPI_INF("No action to be taken for PPC405");
            break;

        case p9occ_ctrl::PPC405_RESET_OFF:
            FAPI_TRY(fapi2::putScom(i_target, PU_OCB_PIB_OCR_CLEAR, ~BIT(0)));
            break;

        case p9occ_ctrl::PPC405_RESET_ON:
            FAPI_TRY(fapi2::putScom(i_target, PU_OCB_PIB_OCR_OR, BIT(0)));
            break;

        case p9occ_ctrl::PPC405_HALT_OFF:
            FAPI_TRY(fapi2::putScom(i_target, PU_JTG_PIB_OJCFG_AND, ~BIT(6)));
            break;

        case p9occ_ctrl::PPC405_HALT_ON:
            FAPI_TRY(fapi2::putScom(i_target, PU_JTG_PIB_OJCFG_OR, BIT(6)));
            break;

        case p9occ_ctrl::PPC405_RESET_SEQUENCE:

            /// It is unsafe in general to simply reset the 405, as this is an
            /// asynchronous reset that can leave OCI slaves in unrecoverable
            /// states.
            /// This is a "safe" reset-entry sequence that includes
            /// halting the 405 (a synchronous operation) before issuing the
            /// reset. Since this sequence halts/unhalts the 405 and modifies
            /// FIRs it is called apart from the simple PPC405_RESET_OFF
            /// that simply sets the 405 reset bit.
            ///
            /// The sequence:
            ///
            /// 1. Mask the "405 halted" FIR bit to avoid FW thinking the halt
            /// we are about to inject on the 405 is an error.
            ///
            /// 2. Halt the 405. If the 405 does not halt in 1ms we note that
            /// but press on, hoping (probably in vain) that any subsequent
            /// reset actions will clear up the issue.
            /// To check if the 405 halted we must clear the FIR and verify
            /// that the FIR is set again.
            ///
            /// 3. Put the 405 into reset.
            ///
            /// 4. Clear the halt bit.
            ///
            /// 5. Restore the original FIR mask
            /// Save the FIR mask, and mask the halted FIR

            FAPI_DBG("Performing the RESET SEQUENCE");
            FAPI_TRY(fapi2::getScom(i_target, PERV_TP_OCC_SCOM_OCCLFIRMASK, l_firMask));
            FAPI_TRY(fapi2::putScom(i_target, PERV_TP_OCC_SCOM_OCCLFIRMASK_OR, BIT(25)));
            // Halt the 405 and verify that it is halted
            FAPI_TRY(fapi2::putScom(i_target, PU_JTG_PIB_OJCFG_OR, BIT(6)));

            FAPI_TRY(fapi2::delay(NS_DELAY, SIM_CYCLE_DELAY));

            FAPI_TRY(fapi2::putScom(i_target, PERV_TP_OCC_SCOM_OCCLFIR_AND, ~BIT(25)));

            FAPI_TRY(fapi2::getScom(i_target, PERV_TP_OCC_SCOM_OCCLFIR, l_occfir));

            if (!(l_occfir & BIT(25)))
            {
                FAPI_ERR("OCC will not halt. Pressing on, hoping for the best.");
            }

            // Put 405 into reset, unhalt 405 and clear the halted FIR bit.
            FAPI_TRY(fapi2::putScom(i_target, PU_OCB_PIB_OCR_OR, BIT(0)));
            FAPI_TRY(fapi2::putScom(i_target, PU_JTG_PIB_OJCFG_AND, ~BIT(6)));
            FAPI_TRY(fapi2::putScom(i_target, PERV_TP_OCC_SCOM_OCCLFIR_AND, ~BIT(25)));
            // Restore the original FIR mask
            FAPI_TRY(fapi2::putScom(i_target, PERV_TP_OCC_SCOM_OCCLFIRMASK, l_firMask));
            break;

        default:
            break;
    }

fapi_try_exit:
    FAPI_IMP("Exiting p9_pm_occ_control ....");
    return fapi2::current_err;
}

