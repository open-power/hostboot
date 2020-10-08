/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_qme_firinit.C $ */
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
/// @file p10_pm_qme_firinit.C
/// @brief Configures the QME FIRs, Mask & Actions
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
///      loop over all functional chiplets {
///         Mask all bits of FIR
///      }
///   else if init:
///      loop over all functional chiplets {
///         Establish the mask/action bits for the following settings:
///         1) Checkstop
///         2) Malf Alert
///         3) Recoverable Attention
///         4) Recoverable Interrupt
///      }
///
/// Procedure Prereq:
///   o System clocks are running
/// @endverbatim

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p10_pm_qme_firinit.H>

// ----------------------------------------------------------------------
// Constant Definitions
// ----------------------------------------------------------------------

enum QME_FIRS
{
    PPE_HALT_ERROR = 0,
    DEBUG_TRIGGER = 1,
    SPARE_TRIGGER = 2,
    PPE_WATCHDOG = 3,
    LOCAL_PCB_TIMEOUT = 4,
    FABRIC_ERROR = 5,
    SRAM_UE = 6,
    SRAM_CE = 7,
    RESCLK_ARRAY_PARITY_ERR = 8,
    PCB_INTERRUPT_PROTOCOL_ERR = 9,
    SRAM_SCRUB_ERR = 10,
    CTFS_ERR = 11,
    CPMS_ERR = 12,
    PGPE_HEARTBEAT_LOST = 13,
    BCE_TIMEOUT = 14,
    RESCLK_PROTOCOL_ERR = 15,
    PCB_RESET_WHEN_ACTIVE = 16,
    SPECIAL_WKUP_PROTOCOL_ERR = 17,
    SPECIAL_WKUP_DONE_WINDOW = 18,
    DISABLED_INTR = 19,
    DECONFIGURED_INTR = 20,
    RS4_TIMEOUT = 21,
    PB_DATA_HANG = 22,
    WRITE_PROTECT_FAIL = 23,
    DTC_ERROR = 24,
    PB_CE = 25,
    PB_UE = 26,
    PB_SUE = 27,
    PB_INVALID_TOPOTABLE_ENTRY = 28,
    PB_TAG_PERR = 29,
    PIG_PROTOCOL_ERR = 30,
    LOCAL_ACCESS_ERR = 31,
    PB_SSA_CE = 32,
    PB_SSA_UE = 33,
    RESCLK_CCFG_PAR_ERR = 34,
    STOP11_SPWKUP_IN_XSTOP = 35,
};

// ----------------------------------------------------------------------
// Function prototype
// ----------------------------------------------------------------------

/// @brief Initialize the actions for QME FIR, MASK and Action registers
///
/// @param[in] i_target   Chip target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode pm_qme_fir_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

/// @brief Reset the actions for QME FIR, MASK and Action registers
///
/// @param[in] i_target   Chip target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode pm_qme_fir_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

fapi2::ReturnCode p10_pm_qme_firinit(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP("p10_pm_qme_firinit start");

    if(i_mode == pm::PM_RESET_SOFT)
    {
        FAPI_TRY(pm_qme_fir_reset(i_target),
                 "ERROR: Failed to reset the QME FIRs");
    }
    else if(i_mode == pm::PM_INIT_SOFT)
    {
        FAPI_TRY(pm_qme_fir_init(i_target),
                 "ERROR: Failed to initialize the QME FIRs");
    }
    else
    {
        FAPI_ASSERT(false, fapi2::PM_QME_FIRINIT_BAD_MODE().set_BADMODE(i_mode),
                    "ERROR; Unknown mode passed to p10_pm_qme_firinit. Mode %x",
                    i_mode);
    }

fapi_try_exit:
    FAPI_INF("p10_pm_qme_firinit end");
    return fapi2::current_err;
}

fapi2::ReturnCode pm_qme_fir_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("pm_qme_fir_init start");
    auto l_eqChiplets = i_target.getChildren<fapi2::TARGET_TYPE_EQ>
                        (fapi2::TARGET_STATE_FUNCTIONAL);

    for (auto l_eq_chplt : l_eqChiplets)
    {
        pmFIR::PMFir <pmFIR::FIRTYPE_QME_LFIR, fapi2::TARGET_TYPE_EQ> l_qmeFir(l_eq_chplt);
        FAPI_TRY(l_qmeFir.get(pmFIR::REG_ALL),
                 "ERROR: Failed to get the QME FIR values");

        /* Clear all the FIR and action buffers */
        FAPI_TRY(l_qmeFir.clearAllRegBits(pmFIR::REG_FIR),
                 "ERROR: Failed to clear QME FIR");
        FAPI_TRY(l_qmeFir.clearAllRegBits(pmFIR::REG_ACTION0),
                 "ERROR: Failed to clear QME action 0");
        FAPI_TRY(l_qmeFir.clearAllRegBits(pmFIR::REG_ACTION1),
                 "ERROR: Failed to clear QME action 1");

        // RTC: 261297
        FAPI_TRY(l_qmeFir.setPIG(PPE_HALT_ERROR),                   FIR_PIG_ALRT_ERROR);   // 0
        FAPI_TRY(l_qmeFir.mask(DEBUG_TRIGGER),                      FIR_MASK_ERROR);        // 1
        FAPI_TRY(l_qmeFir.mask(SPARE_TRIGGER),                      FIR_MASK_ERROR);        // 2
        FAPI_TRY(l_qmeFir.mask(PPE_WATCHDOG),                       FIR_MASK_ERROR);        // 3
        FAPI_TRY(l_qmeFir.mask(LOCAL_PCB_TIMEOUT),                  FIR_MASK_ERROR);        // 4  Logged by QME
        FAPI_TRY(l_qmeFir.mask(FABRIC_ERROR),                       FIR_MASK_ERROR);        // 5  Logged by QME
        FAPI_TRY(l_qmeFir.mask(SRAM_UE),                            FIR_MASK_ERROR);        // 6  Logged by QME
        FAPI_TRY(l_qmeFir.setRecvAttn(SRAM_CE),                     FIR_REC_ATTN_ERROR);    // 7
        FAPI_TRY(l_qmeFir.setQMEIntr(RESCLK_ARRAY_PARITY_ERR),      FIR_QME_INTR_ERROR);    // 8
        FAPI_TRY(l_qmeFir.setQMEIntr(PCB_INTERRUPT_PROTOCOL_ERR),   FIR_QME_INTR_ERROR);    // 9
        FAPI_TRY(l_qmeFir.setQMEIntr(SRAM_SCRUB_ERR),               FIR_QME_INTR_ERROR);    // 10
        FAPI_TRY(l_qmeFir.setQMEIntr(CTFS_ERR),                     FIR_QME_INTR_ERROR);    // 11
        FAPI_TRY(l_qmeFir.setQMEIntr(CPMS_ERR),                     FIR_QME_INTR_ERROR);    // 12
        FAPI_TRY(l_qmeFir.setQMEIntr(PGPE_HEARTBEAT_LOST),          FIR_QME_INTR_ERROR);    // 13
        FAPI_TRY(l_qmeFir.setQMEIntr(BCE_TIMEOUT),                  FIR_QME_INTR_ERROR);    // 14
        FAPI_TRY(l_qmeFir.setRecvAttn(RESCLK_PROTOCOL_ERR),         FIR_REC_ATTN_ERROR);    // 15
        FAPI_TRY(l_qmeFir.setQMEIntr(PCB_RESET_WHEN_ACTIVE),        FIR_QME_INTR_ERROR);    // 16
        FAPI_TRY(l_qmeFir.setQMEIntr(SPECIAL_WKUP_PROTOCOL_ERR),    FIR_QME_INTR_ERROR);    // 17
        FAPI_TRY(l_qmeFir.setQMEIntr(SPECIAL_WKUP_DONE_WINDOW),     FIR_QME_INTR_ERROR);    // 18
        FAPI_TRY(l_qmeFir.setQMEIntr(DISABLED_INTR),                FIR_QME_INTR_ERROR);    // 19
        FAPI_TRY(l_qmeFir.setQMEIntr(DECONFIGURED_INTR),            FIR_QME_INTR_ERROR);    // 20
        FAPI_TRY(l_qmeFir.mask(RS4_TIMEOUT),                        FIR_MASK_ERROR);        // 21 Not supported
        FAPI_TRY(l_qmeFir.setQMEIntr(PB_DATA_HANG),                 FIR_QME_INTR_ERROR);    // 22
        FAPI_TRY(l_qmeFir.setQMEIntr(WRITE_PROTECT_FAIL),           FIR_QME_INTR_ERROR);    // 23
        FAPI_TRY(l_qmeFir.setQMEIntr(DTC_ERROR),                    FIR_QME_INTR_ERROR);    // 24
        FAPI_TRY(l_qmeFir.setRecvAttn(PB_CE),                       FIR_REC_ATTN_ERROR);    // 25
        FAPI_TRY(l_qmeFir.setQMEIntr(PB_UE),                        FIR_QME_INTR_ERROR);    // 26
        FAPI_TRY(l_qmeFir.setQMEIntr(PB_SUE),                       FIR_QME_INTR_ERROR);    // 27
        FAPI_TRY(l_qmeFir.setQMEIntr(PB_INVALID_TOPOTABLE_ENTRY),   FIR_QME_INTR_ERROR);    // 28
        FAPI_TRY(l_qmeFir.setCheckStop(PB_TAG_PERR),                FIR_CHECKSTOP_ERROR);   // 29
        FAPI_TRY(l_qmeFir.setQMEIntr(PIG_PROTOCOL_ERR),             FIR_QME_INTR_ERROR);    // 30
        FAPI_TRY(l_qmeFir.setQMEIntr(LOCAL_ACCESS_ERR),             FIR_QME_INTR_ERROR);    // 31
        FAPI_TRY(l_qmeFir.setRecvAttn(PB_SSA_CE),                   FIR_REC_ATTN_ERROR);    // 32
        FAPI_TRY(l_qmeFir.setCheckStop(PB_SSA_UE),                  FIR_CHECKSTOP_ERROR);   // 33
        FAPI_TRY(l_qmeFir.setQMEIntr(RESCLK_CCFG_PAR_ERR),          FIR_QME_INTR_ERROR);    // 34
        FAPI_TRY(l_qmeFir.mask(STOP11_SPWKUP_IN_XSTOP),             FIR_MASK_ERROR);        // 35

        FAPI_TRY(l_qmeFir.put(),
                 "ERROR: Failed to write the QME FIR values");

    }

fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode pm_qme_fir_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("pm_qme_fir_reset start");
    auto l_eqChiplets = i_target.getChildren<fapi2::TARGET_TYPE_EQ>
                        (fapi2::TARGET_STATE_FUNCTIONAL);

    for (auto l_eq_chplt : l_eqChiplets)
    {
        pmFIR::PMFir <pmFIR::FIRTYPE_QME_LFIR,
              fapi2::TARGET_TYPE_EQ> l_qmeFir(l_eq_chplt);

        FAPI_TRY(l_qmeFir.get(pmFIR::REG_FIRMASK),
                 "ERROR: Failed to get the QME FIR QME_INTR value");

        /* Fetch the QME FIR MASK; Save it to HWP attribute; clear it */
        FAPI_TRY(l_qmeFir.saveMask(),
                 "ERROR: Failed to save QME FIR Mask to the attribute");

        FAPI_TRY(l_qmeFir.setAllRegBits(pmFIR::REG_FIRMASK),
                 "ERROR: Faled to set the QME FIR MASK");

        FAPI_TRY(l_qmeFir.put(),
                 "ERROR:Failed to write to the QME FIR MASK");
    }

fapi_try_exit:
    return fapi2::current_err;
}
