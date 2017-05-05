/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_cme_firinit.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file p9_pm_cme_firinit.C
/// @brief Configures the CME FIRs, Mask & Actions
///
// *HWP HW Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 3
// *HWP Consumed by: HS

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
#include <p9_pm_cme_firinit.H>
#include <p9_query_cache_access_state.H>

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
    SRAM_SCRUB_ERR,      // 9
    BCE_ERR,             // 10
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

        FAPI_TRY(l_cmeFir.get(p9pmFIR::REG_ALL),
                 "ERROR: Failed to get the CME FIR values");

        /* Clear the FIR and action buffers */
        FAPI_TRY(l_cmeFir.clearAllRegBits(p9pmFIR::REG_FIR),
                 "ERROR: Failed to clear CME FIR");
        FAPI_TRY(l_cmeFir.clearAllRegBits(p9pmFIR::REG_ACTION0),
                 "ERROR: Failed to clear CME FIR");
        FAPI_TRY(l_cmeFir.clearAllRegBits(p9pmFIR::REG_ACTION1),
                 "ERROR: Failed to clear CME FIR");

        /*  Set the action and mask for the CME LFIR bits */
        FAPI_TRY(l_cmeFir.mask(PPE_INT_ERR), FIR_MASK_ERROR);
        FAPI_TRY(l_cmeFir.mask(PPE_EXT_ERR), FIR_MASK_ERROR);
        FAPI_TRY(l_cmeFir.mask(PPE_PROG_ERR), FIR_MASK_ERROR);
        FAPI_TRY(l_cmeFir.mask(PPE_BRKPT_ERR), FIR_MASK_ERROR);
        FAPI_TRY(l_cmeFir.mask(PPE_WATCHDOG), FIR_MASK_ERROR);
        FAPI_TRY(l_cmeFir.mask(PPE_HALT), FIR_MASK_ERROR);
        FAPI_TRY(l_cmeFir.mask(PPE_DBGTRG), FIR_MASK_ERROR);
        FAPI_TRY(l_cmeFir.setRecvAttn(CME_SRAM_UE),
                 FIR_REC_ATTN_ERROR);
        FAPI_TRY(l_cmeFir.setRecvAttn(CME_SRAM_CE),
                 FIR_REC_ATTN_ERROR);
        FAPI_TRY(l_cmeFir.setRecvAttn(SRAM_SCRUB_ERR),
                 FIR_REC_ATTN_ERROR);
        FAPI_TRY(l_cmeFir.mask(BCE_ERR), FIR_MASK_ERROR);
        FAPI_TRY(l_cmeFir.mask(CME_SPARE_11), FIR_MASK_ERROR);
        FAPI_TRY(l_cmeFir.mask(CME_SPARE_12), FIR_MASK_ERROR);
        FAPI_TRY(l_cmeFir.setRecvAttn(C0_iVRM_DPOUT),
                 FIR_REC_ATTN_ERROR);
        FAPI_TRY(l_cmeFir.setRecvAttn(C1_iVRM_DPOUT),
                 FIR_REC_ATTN_ERROR);
        FAPI_TRY(l_cmeFir.setRecvAttn(CACHE_iVRM_DPOUT),
                 FIR_REC_ATTN_ERROR);
        FAPI_TRY(l_cmeFir.setRecvAttn(EXTRM_DROOP_ERR),
                 FIR_REC_ATTN_ERROR);
        FAPI_TRY(l_cmeFir.setRecvAttn(LARGE_DROOP_ERR),
                 FIR_REC_ATTN_ERROR);
        FAPI_TRY(l_cmeFir.setRecvAttn(SMALL_DROOP_ERR),
                 FIR_REC_ATTN_ERROR);
        FAPI_TRY(l_cmeFir.setRecvAttn(UNEXP_DROOP_ENCODE),
                 FIR_REC_ATTN_ERROR);
        FAPI_TRY(l_cmeFir.mask(CME_FIR_PAR_ERR_DUP), FIR_MASK_ERROR);
        FAPI_TRY(l_cmeFir.mask(CME_FIR_PAR_ERR), FIR_MASK_ERROR);

        //todo: Yet to confirm on the action for the following bits

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
    auto l_eqChiplets = i_target.getChildren<fapi2::TARGET_TYPE_EQ>
                        (fapi2::TARGET_STATE_FUNCTIONAL);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PM_FIRINIT_DONE_ONCE_FLAG,
                           i_target, l_firinit_done_flag),
             "ERROR: Failed to fetch the entry status of FIRINIT");

    for (auto l_eq_chplt : l_eqChiplets)
    {
        //We cannot rely on the HWAS state because during an MPIPL
        //the cores get stopped and the SP doesnt know until an
        //attr sync occurs with the platform. We must use the
        //query_cache_state to safely determine if we can scom
        //the ex targets
        fapi2::ReturnCode l_rc;
        bool l_l2_is_scanable = false;
        bool l_l3_is_scanable = false;
        bool l_l2_is_scomable = false;
        bool l_l3_is_scomable = false;
        uint8_t l_chip_unit_pos;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                               l_eq_chplt, l_chip_unit_pos),
                 "ERROR: Failed to get the chip unit pos attribute from the eq");

        FAPI_EXEC_HWP(l_rc, p9_query_cache_access_state, l_eq_chplt,
                      l_l2_is_scomable, l_l2_is_scanable,
                      l_l3_is_scomable, l_l3_is_scanable);
        FAPI_TRY(l_rc, "ERROR: failed to query cache access state for EQ %d",
                 l_chip_unit_pos);

        //If this cache isnt scommable continue to the next EQ
        if(!l_l3_is_scomable)
        {
            continue;
        }

        auto l_exChiplets = l_eq_chplt.getChildren<fapi2::TARGET_TYPE_EX>
                            (fapi2::TARGET_STATE_FUNCTIONAL);

        for(auto l_ex_chplt : l_exChiplets)
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

    }

fapi_try_exit:
    return fapi2::current_err;
}
