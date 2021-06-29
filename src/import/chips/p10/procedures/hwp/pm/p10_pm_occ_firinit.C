/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_occ_firinit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p10/procedures/hwp/pm/p10_pm_occ_firinit.C $            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2019                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p10_pm_occ_firinit.C
/// @brief Configures the OCC LFIR Mask and Action
///
// *HWP HW Owner        :   Greg Still <stillgs@us.ibm.com>
// *HWP Backup Owner    :   Prasad BG Ranganath <prasadbgr@in.ibm.com>
// *HWP FW Owner        :   Prem S Jha <premjha2@in.ibm.com>
// *HWP Team            :   PM
// *HWP Level           :   3
// *HWP Consumed by     :   HS

/// High-level procedure flow:
/// @verbatim
///   if reset:
///      Mask all bits of FIR
///   else if init:
///      Establish the respective mask/action bits for the following settings:
///          1) Checkstop
///          2) Malf Alert
///          3) Recoverable Attention
///          4) Recoverable Interrupt
/// @endverbatim
///
/// Procedure Prereq:
///   o System clocks are running
///

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p10_pm_occ_firinit.H>

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------


enum OCC_FIR_BITS
{
    OCC_FW0 = 0,
    OCC_FW1 = 1,
    QME_ERROR_NOTIFY = 2,
    SPARE_3 = 3,
    OCC_HB_ERROR = 4,
    GPE0_WATCHDOG_TIMEOUT = 5,
    GPE1_WATCHDOG_TIMEOUT = 6,
    GPE2_WATCHDOG_TIMEOUT = 7,
    GPE3_WATCHDOG_TIMEOUT = 8,
    GPE0_ERROR = 9,
    GPE1_ERROR = 10,
    GPE2_ERROR = 11,
    GPE3_ERROR = 12,
    OCB_ERROR = 13,
    SRT_UE = 14,
    SRT_CE = 15,
    GPE0_HALTED = 16,
    GPE1_HALTED = 17,
    GPE2_HALTED = 18,
    GPE3_HALTED = 19,
    GPE0_WRITE_PROTECT_ERROR = 20,
    GPE1_WRITE_PROTECT_ERROR = 21,
    GPE2_WRITE_PROTECT_ERROR = 22,
    GPE3_WRITE_PROTECT_ERROR = 23,
    SAFE_MODE = 24,
    SPARE_25 = 25,
    EXTERNAL_TRAP = 26,
    PPC405_CORE_RESET = 27,
    PPC405_CHIP_RESET = 28,
    PPC405_SYSTEM_RESET = 29,
    PPC405_DBGMSRWE = 30,
    PPC405_DBGSTOPACK = 31,
    OCB_DB_ERROR = 32,
    OCB_PIB_ADDR_PARITY_ERR = 33,
    OCB_IDC_ERROR = 34,
    OPIT_PARITY_ERROR = 35,
    OPIT_FSM_ERR = 36,
    SPARE_37 = 37,
    SPARE_38 = 38,
    SPARE_39 = 39,
    SPARE_40 = 40,
    SPARE_41 = 41,
    JTAGACC_ERR = 42,
    OCB_OCI_OCISLV_ERR = 43,
    C405_ECC_UE = 44,
    C405_ECC_CE = 45,
    C405_OCI_MACHINECHECK = 46,
    SRAM_SPARE_DIRECT_ERROR = 47,
    SRT_OTHER_ERROR = 48,
    SPARE_49 = 49,
    SPARE_50 = 50,
    GPE0_OCISLV_ERR = 51,
    GPE1_OCISLV_ERR = 52,
    GPE2_OCISLV_ERR = 53,
    GPE3_OCISLV_ERR = 54,
    C405ICU_M_TIMEOUT = 55,
    C405DCU_M_TIMEOUT = 56,
    OCC_COMPLEX_FAULT = 57,
    OCC_COMPLEX_NOTIFY = 58,
    SPARE_59 = 59,
    SPARE_60 = 60,
    SPARE_61 = 61,
};

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------

fapi2::ReturnCode pm_occ_fir_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

fapi2::ReturnCode pm_occ_fir_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

fapi2::ReturnCode p10_pm_occ_firinit(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP("p10_pm_occ_firinit Enter");

    if(i_mode == pm::PM_RESET_SOFT)
    {
        FAPI_TRY(pm_occ_fir_reset(i_target),
                 "ERROR: Failed to reset the OCC FIRs");
    }
    else if(i_mode == pm::PM_INIT_SOFT)
    {
        FAPI_TRY(pm_occ_fir_init(i_target),
                 "ERROR: Failed to initialize the OCC FIRs");
    }
    else
    {
        FAPI_ASSERT(false, fapi2::PM_OCC_FIRINIT_BAD_MODE()
                    .set_BADMODE(i_mode)
                    .set_CURPROC(i_target),
                    "ERROR; Unknown mode passed to p10_pm_occ_firinit. Mode %x",
                    i_mode);
    }

fapi_try_exit:
    FAPI_IMP("p10_pm_occ_firinit Exit");
    return fapi2::current_err;
}

fapi2::ReturnCode pm_occ_fir_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("pm_occ_fir_reset Enter");

    pmFIR::PMFir <pmFIR::FIRTYPE_OCC_LFIR,
          fapi2::TARGET_TYPE_PROC_CHIP> l_occFir(i_target);

    FAPI_TRY(l_occFir.get(pmFIR::REG_FIRMASK),
             "ERROR: Failed to get the OCC FIR MASK value");

    /* Fetch the OCC FIR MASK; Save it to HWP attribute; clear its contents */
    FAPI_TRY(l_occFir.saveMask(),
             "ERROR: Failed to save the OCC FIR Mask to the attribute");

    FAPI_TRY(l_occFir.setAllRegBits(pmFIR::REG_FIRMASK),
             "ERROR: Faled to set the OCC FIR MASK");

    FAPI_TRY(l_occFir.put(),
             "ERROR:Failed to write to the OCC FIR MASK");

fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode pm_occ_fir_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("pm_occ_fir_init Enter");

    pmFIR::PMFir <pmFIR::FIRTYPE_OCC_LFIR,
          fapi2::TARGET_TYPE_PROC_CHIP> l_occFir(i_target);

    FAPI_TRY(l_occFir.get(pmFIR::REG_ALL),
             "ERROR: Failed to get the OCC FIR values");

    /* Clear all the FIR and action buffers */
    FAPI_TRY(l_occFir.clearAllRegBits(pmFIR::REG_FIR),
             "ERROR: Failed to clear OCC FIR");
    FAPI_TRY(l_occFir.clearAllRegBits(pmFIR::REG_ACTION0),
             "ERROR: Failed to clear OCC action 0");
    FAPI_TRY(l_occFir.clearAllRegBits(pmFIR::REG_ACTION1),
             "ERROR: Failed to clear OCC action 1");

    /*  Set the action and mask for the OCC LFIR bits */
    FAPI_TRY(l_occFir.mask(OCC_FW0),                         FIR_MASK_ERROR);       // 0
    FAPI_TRY(l_occFir.mask(OCC_FW1),                         FIR_MASK_ERROR);       // 1
    FAPI_TRY(l_occFir.mask(QME_ERROR_NOTIFY),                FIR_MASK_ERROR);       // 2
    FAPI_TRY(l_occFir.mask(SPARE_3),                         FIR_MASK_ERROR);       // 3
    FAPI_TRY(l_occFir.mask(OCC_HB_ERROR),                    FIR_MASK_ERROR);       // 4  Set to RECOV_INTR by PGPE Hcode
    FAPI_TRY(l_occFir.mask(GPE0_WATCHDOG_TIMEOUT),           FIR_MASK_ERROR);       // 5
    FAPI_TRY(l_occFir.mask(GPE1_WATCHDOG_TIMEOUT),           FIR_MASK_ERROR);       // 6
    FAPI_TRY(l_occFir.mask(GPE2_WATCHDOG_TIMEOUT),           FIR_MASK_ERROR);       // 7
    FAPI_TRY(l_occFir.mask(GPE3_WATCHDOG_TIMEOUT),           FIR_MASK_ERROR);       // 8
    FAPI_TRY(l_occFir.setRecvAttn(GPE0_ERROR),               FIR_REC_ATTN_ERROR);   // 9
    FAPI_TRY(l_occFir.setRecvAttn(GPE1_ERROR),               FIR_REC_ATTN_ERROR);   // 10
    FAPI_TRY(l_occFir.mask(GPE2_ERROR),                      FIR_MASK_ERROR);       // 11
    FAPI_TRY(l_occFir.mask(GPE3_ERROR),                      FIR_MASK_ERROR);       // 12
    FAPI_TRY(l_occFir.setRecvIntr(OCB_ERROR),                FIR_REC_INTR_ERROR);   // 13
    FAPI_TRY(l_occFir.setRecvIntr(SRT_UE),                   FIR_REC_INTR_ERROR);   // 14
    FAPI_TRY(l_occFir.setRecvAttn(SRT_CE),                   FIR_REC_ATTN_ERROR);   // 15
    FAPI_TRY(l_occFir.mask(GPE0_HALTED),                     FIR_MASK_ERROR);       // 16
    FAPI_TRY(l_occFir.mask(GPE1_HALTED),                     FIR_MASK_ERROR);       // 17
    FAPI_TRY(l_occFir.mask(GPE2_HALTED),                     FIR_MASK_ERROR);       // 18
    FAPI_TRY(l_occFir.mask(GPE3_HALTED),                     FIR_MASK_ERROR);       // 19
    FAPI_TRY(l_occFir.setRecvAttn(GPE0_WRITE_PROTECT_ERROR), FIR_REC_ATTN_ERROR);   // 20
    FAPI_TRY(l_occFir.setRecvAttn(GPE1_WRITE_PROTECT_ERROR), FIR_REC_ATTN_ERROR);   // 21
    FAPI_TRY(l_occFir.setRecvAttn(GPE2_WRITE_PROTECT_ERROR), FIR_REC_ATTN_ERROR);   // 22
    FAPI_TRY(l_occFir.setRecvAttn(GPE3_WRITE_PROTECT_ERROR), FIR_REC_ATTN_ERROR);   // 23
    FAPI_TRY(l_occFir.mask(SAFE_MODE),                       FIR_MASK_ERROR);       // 24
    FAPI_TRY(l_occFir.mask(SPARE_25),                        FIR_MASK_ERROR);       // 25
    FAPI_TRY(l_occFir.mask(EXTERNAL_TRAP),                   FIR_MASK_ERROR);       // 26
    FAPI_TRY(l_occFir.mask(PPC405_CORE_RESET),               FIR_MASK_ERROR);       // 27
    FAPI_TRY(l_occFir.mask(PPC405_CHIP_RESET),               FIR_MASK_ERROR);       // 38
    FAPI_TRY(l_occFir.mask(PPC405_SYSTEM_RESET),             FIR_MASK_ERROR);       // 39
    FAPI_TRY(l_occFir.mask(PPC405_DBGMSRWE),                 FIR_MASK_ERROR);       // 30
    FAPI_TRY(l_occFir.mask(PPC405_DBGSTOPACK),               FIR_MASK_ERROR);       // 31
    FAPI_TRY(l_occFir.setRecvAttn(OCB_DB_ERROR),             FIR_REC_ATTN_ERROR);   // 32
    FAPI_TRY(l_occFir.setRecvAttn(OCB_PIB_ADDR_PARITY_ERR),  FIR_REC_ATTN_ERROR);   // 33
    FAPI_TRY(l_occFir.setRecvAttn(OCB_IDC_ERROR),            FIR_REC_ATTN_ERROR);   // 34
    FAPI_TRY(l_occFir.setRecvIntr(OPIT_PARITY_ERROR),        FIR_REC_INTR_ERROR);   // 35
    FAPI_TRY(l_occFir.setRecvAttn(OPIT_FSM_ERR),             FIR_REC_ATTN_ERROR);   // 36
    FAPI_TRY(l_occFir.mask(SPARE_37),                        FIR_MASK_ERROR);       // 37
    FAPI_TRY(l_occFir.mask(SPARE_38),                        FIR_MASK_ERROR);       // 38
    FAPI_TRY(l_occFir.mask(SPARE_39),                        FIR_MASK_ERROR);       // 39
    FAPI_TRY(l_occFir.mask(SPARE_40),                        FIR_MASK_ERROR);       // 40
    FAPI_TRY(l_occFir.mask(SPARE_41),                        FIR_MASK_ERROR);       // 41
    FAPI_TRY(l_occFir.setRecvAttn(JTAGACC_ERR),              FIR_REC_ATTN_ERROR);   // 42
    FAPI_TRY(l_occFir.setRecvAttn(OCB_OCI_OCISLV_ERR),       FIR_REC_ATTN_ERROR);   // 43
    FAPI_TRY(l_occFir.setRecvIntr(C405_ECC_UE),              FIR_REC_INTR_ERROR);   // 44
    FAPI_TRY(l_occFir.setRecvAttn(C405_ECC_CE),              FIR_REC_ATTN_ERROR);   // 45
    FAPI_TRY(l_occFir.setRecvAttn(C405_OCI_MACHINECHECK),    FIR_REC_ATTN_ERROR);   // 46
    FAPI_TRY(l_occFir.setRecvAttn(SRAM_SPARE_DIRECT_ERROR),  FIR_REC_ATTN_ERROR);   // 47
    FAPI_TRY(l_occFir.setRecvAttn(SRT_OTHER_ERROR),          FIR_REC_ATTN_ERROR);   // 48
    FAPI_TRY(l_occFir.mask(SPARE_49),                        FIR_MASK_ERROR);       // 49
    FAPI_TRY(l_occFir.mask(SPARE_50),                        FIR_MASK_ERROR);       // 50
    FAPI_TRY(l_occFir.setRecvAttn(GPE0_OCISLV_ERR),          FIR_REC_ATTN_ERROR);   // 51
    FAPI_TRY(l_occFir.setRecvAttn(GPE1_OCISLV_ERR),          FIR_REC_ATTN_ERROR);   // 52
    FAPI_TRY(l_occFir.setRecvAttn(GPE2_OCISLV_ERR),          FIR_REC_ATTN_ERROR);   // 53
    FAPI_TRY(l_occFir.setRecvAttn(GPE3_OCISLV_ERR),          FIR_REC_ATTN_ERROR);   // 54
    FAPI_TRY(l_occFir.mask(C405ICU_M_TIMEOUT),               FIR_MASK_ERROR);       // 55
    FAPI_TRY(l_occFir.mask(C405DCU_M_TIMEOUT),               FIR_MASK_ERROR);       // 56
    FAPI_TRY(l_occFir.setRecvAttn(OCC_COMPLEX_FAULT),        FIR_REC_ATTN_ERROR);   // 57
    FAPI_TRY(l_occFir.mask(OCC_COMPLEX_NOTIFY),              FIR_MASK_ERROR);       // 58
    FAPI_TRY(l_occFir.mask(SPARE_59),                        FIR_MASK_ERROR);       // 59
    FAPI_TRY(l_occFir.mask(SPARE_60),                        FIR_MASK_ERROR);       // 60
    FAPI_TRY(l_occFir.mask(SPARE_61),                        FIR_MASK_ERROR);       // 61

    FAPI_TRY(l_occFir.put(),
             "ERROR: Failed to write the OCC FIR values");

fapi_try_exit:
    return fapi2::current_err;
}
