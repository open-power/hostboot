/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_occ_firinit.C $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_pm_occ_firinit.C
/// @brief Configures the OCC LFIR Mask and Action
///
// *HWP HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW  Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: HS
//

/// \todo
/// High-level procedure flow:
/// \verbatim
///   if reset:
///      Mask all bits of FIR
///   else if init:
///      Establish the respective mask/action bits for the following settings:
///          1) Checkstop
///          2) Malf Alert
///          3) Recoverable Attention
///          4) Recoverable Interrupt
///
/// Procedure Prereq:
///   o System clocks are running
/// \endverbatim
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
    SRT_UE,                      // 14
    SRT_CE,                      // 15
    SRT_READ_ERR,                // 16
    SRT_WRITE_ERR,               // 17
    SRT_DATAOUT_PERR,            // 18
    SRT_OCI_WDATA_PARITY,        // 19
    SRT_OCI_BE_PARITY_ERR,       // 20
    SRT_OCI_ADDR_PARITY_ERR,     // 21
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

    if (firinit_done_flag == 1)
    {
        FAPI_TRY(l_occFir.get(p9pmFIR::REG_FIRMASK),
                 "ERROR: Failed to get the OCC FIR MASK value");

        /* Fetch the OCC FIR MASK; Save it to HWP attribute; clear its contents */
        FAPI_TRY(l_occFir.saveMask(),
                 "ERROR: Failed to save the OCC FIR Mask to the attribute");
    }

    FAPI_TRY(l_occFir.setAllRegBits(p9pmFIR::REG_FIRMASK),
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
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(OCC_FW1),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.setMalfAlert(CME_ERR_NOTIFY),
             "ERROR: Failed to set Malf alert");
    FAPI_TRY(l_occFir.setRecvAttn(STOP_RCV_NOTIFY_PRD),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.setMalfAlert(OCC_HB_NOTIFY),
             "ERROR: Failed to set Malf alert");
    FAPI_TRY(l_occFir.mask(GPE0_WD_TIMEOUT),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(GPE1_WD_TIMEOUT),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.setMalfAlert(GPE2_WD_TIMEOUT),
             "ERROR: Failed to set Malf alert");
    FAPI_TRY(l_occFir.mask(GPE3_WD_TIMEOUT),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(GPE0_ERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(GPE1_ERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.setRecvIntr(GPE2_ERR),
             "ERROR: Failed to set recovery interrupt");
    FAPI_TRY(l_occFir.setMalfAlert(GPE3_ERR),
             "ERROR: Failed to set Malf alert");
    FAPI_TRY(l_occFir.mask(OCB_ERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.setRecvAttn(SRT_UE),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.setRecvAttn(SRT_CE),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.setRecvAttn(SRT_READ_ERR),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.setRecvAttn(SRT_WRITE_ERR),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.setRecvAttn(SRT_DATAOUT_PERR),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.setRecvAttn(SRT_OCI_WDATA_PARITY),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.setRecvAttn(SRT_OCI_BE_PARITY_ERR),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.setRecvAttn(SRT_OCI_ADDR_PARITY_ERR),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.mask(GPE0_HALTED),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(GPE1_HALTED),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(GPE2_HALTED),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(GPE3_HALTED),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(EXT_TRAP),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(PPC405_CORE_RESET),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(PPC405_CHIP_RESET),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(PPC405_SYS_RESET),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(PPC405_WAIT_STATE),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(PPC405_DBGSTOPACK),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(OCB_DB_OCI_TIMEOUT),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(OCB_DB_OCI_RDATA_PARITY),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(OCB_DB_OCI_SLVERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(OCB_PIB_ADDR_PARITY_ERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(OCB_DB_PIB_DATA_PARITY_ERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(OCB_IDC0_ERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(OCB_IDC1_ERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(OCB_IDC2_ERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(OCB_IDC3_ERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(SRT_FSM_ERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(JTAGACC_ERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(SPARE_ERR_38),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.setRecvAttn(C405_ECC_UE),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.mask(C405_ECC_CE),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.mask(C405_OCI_MC_CHK),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.setRecvAttn(SRAM_SPARE_DIRERR0),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.setRecvAttn(SRAM_SPARE_DIRERR1),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.setRecvAttn(SRAM_SPARE_DIRERR2),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.setRecvAttn(SRAM_SPARE_DIRERR3),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.setRecvAttn(GPE0_OCISLV_ERR),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.setRecvAttn(GPE1_OCISLV_ERR),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.setRecvAttn(GPE2_OCISLV_ERR),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.setRecvAttn(GPE3_OCISLV_ERR),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.setRecvAttn(C405ICU_M_TIMEOUT),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.setRecvAttn(OCC_CMPLX_FAULT),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.mask(OCC_CMPLX_NOTIFY),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.setRecvAttn(OCC_CMPLX_NOTIFY),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.mask(SPARE_59),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.setRecvAttn(SPARE_59),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.mask(SPARE_60),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.setRecvAttn(SPARE_60),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.mask(SPARE_61),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_occFir.setRecvAttn(SPARE_61),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.setRecvAttn(FIR_PARITY_ERR_DUP),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_occFir.setRecvAttn(FIR_PARITY_ERR),
             "ERROR: Failed to set recovery attention");

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
