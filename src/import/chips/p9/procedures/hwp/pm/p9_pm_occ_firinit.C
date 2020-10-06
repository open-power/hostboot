/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_occ_firinit.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file p9_pm_occ_firinit.C
/// @brief Configures the OCC LFIR Mask and Action
///
// *HWP HWP Owner        : Greg Still <stillgs@us.ibm.com>
// *HWP Backup HWP Owner : Amit Kumar <akumar3@us.ibm.com>
// *HWP FW  Owner        : Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 3
// *HWP Consumed by: HS
//

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
#include <p9_pm_occ_firinit.H>

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------

enum OCC_FIR_BITS
{
    OCC_FW0,                     // 0
    OCC_FW1,                     // 1
    CME_ERR_NOTIFY,              // 2
    STOP_RCV_NOTIFY_PRD,         // 3
    OCC_HB_NOTIFY,               // 4
    GPE0_WD_TIMEOUT,             // 5
    GPE1_WD_TIMEOUT,             // 6
    GPE2_WD_TIMEOUT,             // 7
    GPE3_WD_TIMEOUT,             // 8
    GPE0_ERR,                    // 9
    GPE1_ERR,                    // 10
    GPE2_ERR,                    // 11
    GPE3_ERR,                    // 12
    OCB_ERR,                     // 13
    SRAM_UE,                      // 14
    SRAM_CE,                      // 15
    SRAM_READ_ERR,                // 16
    SRAM_WRITE_ERR,               // 17
    SRAM_DATAOUT_PERR,            // 18
    SRAM_OCI_WDATA_PARITY,        // 19
    SRAM_OCI_BE_PARITY_ERR,       // 20
    SRAM_OCI_ADDR_PARITY_ERR,     // 21
    GPE0_HALTED,                 // 22
    GPE1_HALTED,                 // 23
    GPE2_HALTED,                 // 24
    GPE3_HALTED,                 // 25
    EXT_TRAP,                    // 26
    PPC405_CORE_RESET,           // 27
    PPC405_CHIP_RESET,           // 28
    PPC405_SYS_RESET,            // 29
    PPC405_WAIT_STATE,           // 30
    PPC405_DBGSTOPACK,           // 31
    OCB_DB_OCI_TIMEOUT,          // 32
    OCB_DB_OCI_RDATA_PARITY,     // 33
    OCB_DB_OCI_SLVERR,           // 34
    OCB_PIB_ADDR_PARITY_ERR,     // 35
    OCB_DB_PIB_DATA_PARITY_ERR,  // 36
    OCB_IDC0_ERR,                // 37
    OCB_IDC1_ERR,                // 38
    OCB_IDC2_ERR,                // 39
    OCB_IDC3_ERR,                // 40
    SRT_FSM_ERR,                 // 41
    JTAGACC_ERR,                 // 42
    SPARE_ERR_38,                // 43
    C405_ECC_UE,                 // 44
    C405_ECC_CE,                 // 45
    C405_OCI_MC_CHK,             // 46
    SRAM_SPARE_DIRERR0,          // 47
    SRAM_SPARE_DIRERR1,          // 48
    SRAM_SPARE_DIRERR2,          // 49
    SRAM_SPARE_DIRERR3,          // 50
    GPE0_OCISLV_ERR,             // 51
    GPE1_OCISLV_ERR,             // 52
    GPE2_OCISLV_ERR,             // 53
    GPE3_OCISLV_ERR,             // 54
    C405ICU_M_TIMEOUT,           // 55
    C405DCU_M_TIMEOUT,           // 56
    OCC_CMPLX_FAULT,             // 57
    OCC_CMPLX_NOTIFY,            // 58
    SPARE_59,                    // 59
    SPARE_60,                    // 60
    SPARE_61,                    // 61
    FIR_PARITY_ERR_DUP,          // 62
    FIR_PARITY_ERR               // 63
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

fapi2::ReturnCode p9_pm_occ_firinit(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP("p9_pm_occ_firinit Enter");

    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_mask64;

    uint64_t l_fir;
    uint64_t l_mask;
    uint64_t l_unmaskedErrors;

    FAPI_DBG("Checking OCC FIRs");
    FAPI_TRY(fapi2::getScom(i_target, PERV_TP_OCC_SCOM_OCCLFIR, l_data64),
             "ERROR: Failed to fetch OCC FIR");
    FAPI_TRY(fapi2::getScom(i_target, PERV_TP_OCC_SCOM_OCCLFIRMASK, l_mask64),
             "ERROR: Failed to fetch OCC FIRMASK");
    l_data64.extractToRight<0, 64>(l_fir);
    l_mask64.extractToRight<0, 64>(l_mask);
    l_unmaskedErrors = l_fir & l_mask;

    if(l_unmaskedErrors)
    {
        FAPI_INF("WARNING: OCC has active errors");
    }

    if(i_mode == p9pm::PM_RESET)
    {
        FAPI_TRY(pm_occ_fir_reset(i_target),
                 "ERROR: Failed to reset the OCC FIRs");
    }
    else if(i_mode == p9pm::PM_INIT)
    {
        FAPI_TRY(pm_occ_fir_init(i_target),
                 "ERROR: Failed to initialize the OCC FIRs");
    }
    else
    {
        FAPI_ASSERT(false, fapi2::PM_OCC_FIRINIT_BAD_MODE().set_BADMODE(i_mode),
                    "ERROR; Unknown mode passed to p9_pm_occ_firinit. Mode %x",
                    i_mode);
    }

fapi_try_exit:
    FAPI_IMP("p9_pm_occ_firinit Exit");
    return fapi2::current_err;
}

fapi2::ReturnCode pm_occ_fir_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("pm_occ_fir_reset Enter");

    uint8_t firinit_done_flag = 0;
    p9pmFIR::PMFir <p9pmFIR::FIRTYPE_OCC_LFIR> l_occFir(i_target);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PM_FIRINIT_DONE_ONCE_FLAG,
                           i_target, firinit_done_flag),
             "ERROR: Failed to fetch the entry status of FIRINIT");

    // Here we need to read all the OCC fir registers (action0/1,mask,fir)
    // and will be stored in the respective class variable. So that below when
    // we call put function it will be read modify write.
    FAPI_TRY(l_occFir.get(p9pmFIR::REG_ALL),
             "ERROR: Failed to get the OCC FIR/MASK/ACTION0/ACTION1 value");

    if (firinit_done_flag
        == fapi2::ENUM_ATTR_PM_FIRINIT_DONE_ONCE_FLAG_FIRS_INITED)
    {

        /* Fetch the OCC FIR MASK; Save it to HWP attribute; clear its contents */
        FAPI_TRY(l_occFir.saveMask(),
                 "ERROR: Failed to save the OCC FIR Mask to the attribute");
    }

    FAPI_TRY(l_occFir.setAllRegBits(p9pmFIR::REG_FIRMASK),
             "ERROR: Faled to set the OCC FIR MASK");

    FAPI_TRY(l_occFir.setRecvIntr(OCC_HB_NOTIFY));

    FAPI_TRY(l_occFir.put(),
             "ERROR:Failed to write to the OCC FIR MASK");

fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode pm_occ_fir_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("pm_occ_fir_init Enter");

    uint8_t firinit_done_flag = 0;
    p9pmFIR::PMFir <p9pmFIR::FIRTYPE_OCC_LFIR> l_occFir(i_target);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PM_FIRINIT_DONE_ONCE_FLAG,
                           i_target, firinit_done_flag),
             "ERROR: Failed to fetch the entry status of FIRINIT");

    FAPI_TRY(l_occFir.get(p9pmFIR::REG_ALL),
             "ERROR: Failed to get the OCC FIR values");

    /* Clear all the FIR and action buffers */
    FAPI_TRY(l_occFir.clearAllRegBits(p9pmFIR::REG_FIR),
             "ERROR: Failed to clear OCC FIR");
    FAPI_TRY(l_occFir.clearAllRegBits(p9pmFIR::REG_ACTION0),
             "ERROR: Failed to clear OCC action 0");
    FAPI_TRY(l_occFir.clearAllRegBits(p9pmFIR::REG_ACTION1),
             "ERROR: Failed to clear OCC action 1");

    /*  Set the action and mask for the OCC LFIR bits */
    FAPI_TRY(l_occFir.mask(OCC_FW0),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.mask(OCC_FW1),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.mask(CME_ERR_NOTIFY),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(STOP_RCV_NOTIFY_PRD),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.mask(OCC_HB_NOTIFY),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.mask(GPE0_WD_TIMEOUT),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.mask(GPE1_WD_TIMEOUT),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.mask(GPE2_WD_TIMEOUT),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.mask(GPE3_WD_TIMEOUT),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(GPE0_ERR),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(GPE1_ERR),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.mask(GPE2_ERR),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.mask(GPE3_ERR),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.mask(OCB_ERR),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(SRAM_UE),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(SRAM_CE),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(SRAM_READ_ERR),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(SRAM_WRITE_ERR),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(SRAM_DATAOUT_PERR),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(SRAM_OCI_WDATA_PARITY),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(SRAM_OCI_BE_PARITY_ERR),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(SRAM_OCI_ADDR_PARITY_ERR),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.mask(GPE0_HALTED),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.mask(GPE1_HALTED),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.mask(GPE2_HALTED),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.mask(GPE3_HALTED),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.mask(EXT_TRAP),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.mask(PPC405_CORE_RESET),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.mask(PPC405_CHIP_RESET),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.mask(PPC405_SYS_RESET),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.mask(PPC405_WAIT_STATE),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.mask(PPC405_DBGSTOPACK),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(OCB_DB_OCI_TIMEOUT),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(OCB_DB_OCI_RDATA_PARITY),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(OCB_DB_OCI_SLVERR),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(OCB_PIB_ADDR_PARITY_ERR),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(OCB_DB_PIB_DATA_PARITY_ERR),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(OCB_IDC0_ERR),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(OCB_IDC1_ERR),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(OCB_IDC2_ERR),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(OCB_IDC3_ERR),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(SRT_FSM_ERR),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(JTAGACC_ERR),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.mask(SPARE_ERR_38),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.setRecvIntr(C405_ECC_UE),
             FIR_REC_INTR_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(C405_ECC_CE),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(C405_OCI_MC_CHK),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(SRAM_SPARE_DIRERR0),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(SRAM_SPARE_DIRERR1),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(SRAM_SPARE_DIRERR2),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(SRAM_SPARE_DIRERR3),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(GPE0_OCISLV_ERR),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(GPE1_OCISLV_ERR),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(GPE2_OCISLV_ERR),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(GPE3_OCISLV_ERR),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.mask(C405ICU_M_TIMEOUT),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(C405DCU_M_TIMEOUT),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(OCC_CMPLX_FAULT),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.setRecvAttn(OCC_CMPLX_NOTIFY),
             FIR_REC_ATTN_ERROR);
    FAPI_TRY(l_occFir.mask(SPARE_59),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.mask(SPARE_60),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.mask(SPARE_61),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.mask(FIR_PARITY_ERR_DUP),
             FIR_MASK_ERROR);
    FAPI_TRY(l_occFir.mask(FIR_PARITY_ERR),
             FIR_MASK_ERROR);

    if (firinit_done_flag)
    {
        FAPI_TRY(l_occFir.restoreSavedMask(),
                 "ERROR: Failed to restore the mask saved");
    }

    FAPI_TRY(l_occFir.put(),
             "ERROR: Failed to write the OCC FIR values");

fapi_try_exit:
    return fapi2::current_err;
}
