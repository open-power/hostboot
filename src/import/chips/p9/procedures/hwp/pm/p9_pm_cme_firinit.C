/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_cme_firinit.C $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_pm_cme_firinit.C
/// @brief Configures the CME FIRs, Mask & Actions
///
// *HWP HW Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: FSP:HS

/// High-level procedure flow:
/// \verbatim
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
/// \endverbatim

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p9_pm_cme_firinit.H>

// ----------------------------------------------------------------------
// Constant Definitions
// ----------------------------------------------------------------------

enum CME_FIRS
{
    PPE_INT_ERR,         // 0
    PPE_EXT_ERR,         // 1
    PPE_PROG_ERR,        // 2
    PPE_BRKPT_ERR,       // 3
    PPE_WATCHDOG,        // 4
    PPE_HALT,            // 5
    PPE_DBGTRG,          // 6
    CME_SRAM_UE,         // 7
    CME_SRAM_CE,         // 8
    BCE_ERR,             // 9
    SRAM_SCRUB_ERR,      // 10
    CME_SPARE_11,        // 11
    CME_SPARE_12,        // 12
    C0_iVRM_DPOUT,       // 13
    C1_iVRM_DPOUT,       // 14
    CACHE_iVRM_DPOUT,    // 15
    EXTRM_DROOP_ERR,     // 16
    LARGE_DROOP_ERR,     // 17
    SMALL_DROOP_ERR,     // 18
    UNEXP_DROOP_ENCODE,  // 19
    CME_FIR_PAR_ERR_DUP, // 20
    CME_FIR_PAR_ERR      // 21
};

// ----------------------------------------------------------------------
// Function prototype
// ----------------------------------------------------------------------

/// @brief Initialize the actions for CME FIR, MASK and Action registers
///
/// @param[in] i_target   Chip target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode pm_cme_fir_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

/// @brief Reset the actions for CME FIR, MASK and Action registers
///
/// @param[in] i_target   Chip target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode pm_cme_fir_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

fapi2::ReturnCode p9_pm_cme_firinit(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP("p9_pm_cme_firinit start");

    if(i_mode == p9pm::PM_RESET)
    {
        FAPI_TRY(pm_cme_fir_reset(i_target),
                 "ERROR: Failed to reset the CME FIRs");
    }
    else if(i_mode == p9pm::PM_INIT)
    {
        FAPI_TRY(pm_cme_fir_init(i_target),
                 "ERROR: Failed to initialize the CME FIRs");
    }
    else
    {
        FAPI_ASSERT(false, fapi2::PM_CME_FIRINIT_BAD_MODE().set_BADMODE(i_mode),
                    "ERROR; Unknown mode passed to p9_pm_cme_firinit. Mode %x",
                    i_mode);
    }

fapi_try_exit:
    FAPI_INF("p9_pm_cme_firinit end");
    return fapi2::current_err;
}

fapi2::ReturnCode pm_cme_fir_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("pm_cme_fir_init start");

    uint8_t l_firinit_done_flag;
    auto l_exChiplets = i_target.getChildren<fapi2::TARGET_TYPE_EX>
                        (fapi2::TARGET_STATE_FUNCTIONAL);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PM_FIRINIT_DONE_ONCE_FLAG,
                           i_target, l_firinit_done_flag),
             "ERROR: Failed to fetch the entry status of FIRINIT");

    for (auto l_ex_chplt : l_exChiplets)
    {
        p9pmFIR::PMFir <p9pmFIR::FIRTYPE_CME_LFIR> l_cmeFir(l_ex_chplt);

        /* Clear the FIR and action buffers */
        FAPI_TRY(l_cmeFir.clearAllRegBits(p9pmFIR::REG_FIR),
                 "ERROR: Failed to clear CME FIR");
        FAPI_TRY(l_cmeFir.clearAllRegBits(p9pmFIR::REG_ACTION0),
                 "ERROR: Failed to clear CME FIR");
        FAPI_TRY(l_cmeFir.clearAllRegBits(p9pmFIR::REG_ACTION1),
                 "ERROR: Failed to clear CME FIR");

        /*  Set the action and mask for the CME LFIR bits */
        FAPI_TRY(l_cmeFir.setRecvIntr(PPE_INT_ERR),
                 "ERROR: Failed to set recovery on interrupt");
        FAPI_TRY(l_cmeFir.setRecvIntr(PPE_EXT_ERR),
                 "ERROR: Failed to set recovery on interrupt");
        FAPI_TRY(l_cmeFir.setRecvIntr(PPE_PROG_ERR),
                 "ERROR: Failed to set recovery on interrupt");
        FAPI_TRY(l_cmeFir.setRecvIntr(PPE_BRKPT_ERR),
                 "ERROR: Failed to set recovery on interrupt");
        FAPI_TRY(l_cmeFir.mask(PPE_WATCHDOG), "ERROR: Failed to mask");
        FAPI_TRY(l_cmeFir.mask(PPE_HALT), "ERROR: Failed to mask");
        FAPI_TRY(l_cmeFir.mask(PPE_DBGTRG), "ERROR: Failed to mask");
        FAPI_TRY(l_cmeFir.setRecvIntr(CME_SRAM_UE),
                 "ERROR: Failed to set recovery on interrupt");
        FAPI_TRY(l_cmeFir.mask(CME_SRAM_CE), "ERROR: Failed to mask");
        FAPI_TRY(l_cmeFir.setRecvIntr(BCE_ERR),
                 "ERROR: Failed to set recovery on interrupt");
        FAPI_TRY(l_cmeFir.mask(CME_SPARE_11), "ERROR: Failed to mask");
        FAPI_TRY(l_cmeFir.mask(CME_SPARE_12), "ERROR: Failed to mask");
        FAPI_TRY(l_cmeFir.setRecvAttn(CME_FIR_PAR_ERR_DUP),
                 "ERROR: Failed to set the attention as recoverable");
        FAPI_TRY(l_cmeFir.setRecvAttn(CME_FIR_PAR_ERR),
                 "ERROR: Failed to set the attention as recoverable");

        //todo: Yet to confirm on the action for the following bits
        FAPI_TRY(l_cmeFir.mask(SRAM_SCRUB_ERR), "ERROR: Failed to mask");
        FAPI_TRY(l_cmeFir.mask(C0_iVRM_DPOUT), "ERROR: Failed to mask");
        FAPI_TRY(l_cmeFir.mask(C1_iVRM_DPOUT), "ERROR: Failed to mask");
        FAPI_TRY(l_cmeFir.mask(CACHE_iVRM_DPOUT), "ERROR: Failed to mask");
        FAPI_TRY(l_cmeFir.mask(EXTRM_DROOP_ERR), "ERROR: Failed to mask");
        FAPI_TRY(l_cmeFir.mask(LARGE_DROOP_ERR), "ERROR: Failed to mask");
        FAPI_TRY(l_cmeFir.mask(SMALL_DROOP_ERR), "ERROR: Failed to mask");
        FAPI_TRY(l_cmeFir.mask(UNEXP_DROOP_ENCODE), "ERROR: Failed to mask");

        if (l_firinit_done_flag)
        {
            FAPI_TRY(l_cmeFir.restoreSavedMask(),
                     "ERROR: Failed to restore the CME mask saved");
        }

        FAPI_TRY(l_cmeFir.put(),
                 "ERROR:Failed to write to the CME FIR MASK");
    }

fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode pm_cme_fir_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("pm_cme_fir_reset start");

    uint8_t l_firinit_done_flag;
    auto l_exChiplets = i_target.getChildren<fapi2::TARGET_TYPE_EX>
                        (fapi2::TARGET_STATE_FUNCTIONAL);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PM_FIRINIT_DONE_ONCE_FLAG,
                           i_target, l_firinit_done_flag),
             "ERROR: Failed to fetch the entry status of FIRINIT");

    for (auto l_ex_chplt : l_exChiplets)
    {
        p9pmFIR::PMFir <p9pmFIR::FIRTYPE_CME_LFIR> l_cmeFir(l_ex_chplt);

        if (l_firinit_done_flag == 1)
        {
            FAPI_TRY(l_cmeFir.get(p9pmFIR::REG_FIRMASK),
                     "ERROR: Failed to get the CME FIR MASK value");

            /* Fetch the CME FIR MASK; Save it to HWP attribute; clear it */
            FAPI_TRY(l_cmeFir.saveMask(),
                     "ERROR: Failed to save CME FIR Mask to the attribute");
        }

        FAPI_TRY(l_cmeFir.setAllRegBits(p9pmFIR::REG_FIRMASK),
                 "ERROR: Faled to set the CME FIR MASK");

        FAPI_TRY(l_cmeFir.put(),
                 "ERROR:Failed to write to the CME FIR MASK");
    }

fapi_try_exit:
    return fapi2::current_err;
}
