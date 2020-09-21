/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_reset.C $         */
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
/// @file p9_pm_reset.C
/// @brief Wrapper that calls underlying HWPs to perform a Power Management
///        Reset function when needing to restart the OCC complex.
///
// *HWP HWP Owner        : Greg Still <stillgs@us.ibm.com>
// *HWP HWP Backup Owner : Prasad BG Ranganath <prasadbgr@in.ibm.com>
// *HWP FW Owner         : Prem S Jha <premjha2@in.ibm.com>
// *HWP Team             : PM
// *HWP Level            : 3
// *HWP Consumed by      : HS

///
/// High-level procedure flow:
///
/// @verbatim
///
///     - Mask the OCC FIRs
///     - Halt and then Reset the PPC405
///     - Put all EX chiplets in special wakeup
///     - Mask PBA, PPM and CME FIRs
///     - Reset OCC, PSTATE and STOP GPEs
///     - Reset the Cores and Quads
///     - Reset OCB
///     - Reset PSS
///
/// @endverbatim
///
// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p9_pm_reset.H>
#include <p9_pm_utils.H>
#include <p9_setup_evid.H>
#include <p9_quad_scom_addresses.H>
#include <p9_quad_scom_addresses_fld.H>
#include <p9n2_misc_scom_addresses.H>
#include <p9_pm_occ_firinit.H>

#include <p9_pm_recovery_ffdc_base.H>
#include <p9_pm_recovery_ffdc_cme.H>
#include <p9_pm_recovery_ffdc_sgpe.H>
#include <p9_pm_recovery_ffdc_pgpe.H>
#include <p9_pm_recovery_ffdc_occ.H>
#include <p9_pm_recovery_ffdc_cppm.H>
#include <p9_pm_recovery_ffdc_qppm.H>
#include <p9n2_perv_scom_addresses.H>
#include <p9a_quad_scom_addresses.H>

// -----------------------------------------------------------------------------
// Constant definitions
// -----------------------------------------------------------------------------
// Map the auto generated names to clearer ones
static const uint64_t PU_OCB_OCI_OCCFLG_CLEAR  = PU_OCB_OCI_OCCFLG_SCOM1;
static const uint64_t PU_OCB_OCI_OCCFLG_SET    = PU_OCB_OCI_OCCFLG_SCOM2;
static const uint64_t PU_OCB_OCI_OCCFLG2_CLEAR = P9N2_PU_OCB_OCI_OCCFLG2_SCOM1;
static const uint64_t PU_OCB_OCI_OCCFLG2_SET   = P9N2_PU_OCB_OCI_OCCFLG2_SCOM2;
// -----------------------------------------------------------------------------
// Global variables
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Constant Defintions
// -----------------------------------------------------------------------------
enum PPM_MASK
{
    CME_FIRMASK = 0xFFFFFFFF,
    CORE_ERRMASK = 0xFFFFFFFF,
    QUAD_ERRMASK = 0xFFFFFFFF
};


// -----------------------------------------------------------------------------
// Function definitions
// -----------------------------------------------------------------------------
fapi2::ReturnCode p9_pm_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    void* i_pHomerImage = NULL)
{
    using namespace p9_stop_recov_ffdc;
    FAPI_IMP(">> p9_pm_reset");

    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_data64;
    fapi2::ATTR_PM_RESET_PHASE_Type l_phase = PM_RESET_INIT;
    fapi2::ATTR_INITIATED_PM_RESET_Type l_pmResetActive =
        fapi2::ENUM_ATTR_INITIATED_PM_RESET_ACTIVE;
    fapi2::ATTR_PM_MALF_ALERT_ENABLE_Type l_malfEnabled =
        fapi2::ENUM_ATTR_PM_MALF_ALERT_ENABLE_FALSE;
    fapi2::ATTR_SKIP_WAKEUP_Type l_skip_wakeup;

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    bool l_malfAlert = false;
    fapi2::buffer<uint64_t> l_cpmmmrVal;
    fapi2::buffer<uint64_t> l_qmeScrVal;
    auto ex_list = i_target.getChildren<fapi2::TARGET_TYPE_EX>();

    fapi2::ATTR_PM_MALF_CYCLE_Type l_pmMalfCycle =
        fapi2::ENUM_ATTR_PM_MALF_CYCLE_INACTIVE;
    FAPI_TRY (FAPI_ATTR_GET (fapi2::ATTR_PM_MALF_CYCLE, i_target,
                             l_pmMalfCycle));

    // Avoid another PM Reset before we get through the PM Init
    // Protect FIR Masks, Special Wakeup States, PM FFDC, etc. from being
    // trampled.
    if (l_pmMalfCycle == fapi2::ENUM_ATTR_PM_MALF_CYCLE_ACTIVE)
    {
        FAPI_IMP ("PM Malf Cycle Active: Skip extraneous PM Reset!");
        FAPI_IMP( "<< p9_pm_reset");

        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SKIP_WAKEUP, FAPI_SYSTEM, l_skip_wakeup),
             "fapiGetAttribute of ATTR_SKIP_WAKEUP failed");

    FAPI_TRY (FAPI_ATTR_GET (fapi2::ATTR_PM_MALF_ALERT_ENABLE, FAPI_SYSTEM, l_malfEnabled));

    //  ************************************************************************
    //  Put a mark on the wall that we are in the Reset Flow
    //  ************************************************************************
    FAPI_TRY (FAPI_ATTR_SET (fapi2::ATTR_INITIATED_PM_RESET, i_target, l_pmResetActive));
    FAPI_TRY (FAPI_ATTR_SET (fapi2::ATTR_PM_RESET_PHASE, i_target, l_phase));

    //  ************************************************************************
    //  Check if the PM Complex Reset came in due to a Malf Alert
    //  ************************************************************************
    if (l_malfEnabled == fapi2::ENUM_ATTR_PM_MALF_ALERT_ENABLE_TRUE)
    {
        FAPI_TRY(fapi2::getScom(i_target, P9N2_PU_OCB_OCI_OCCFLG2_SCOM, l_data64),
                 "Error reading P9N2_PU_OCB_OCI_OCCFLG2_SCOM to check for Malf Alert");

        if (l_data64.getBit<p9hcd::PM_CALLOUT_ACTIVE>())
        {
            l_malfAlert = true;
            FAPI_IMP("OCC FLAG2 Bit 28 [PM_CALLOUT_ACTIVE] Set: In Malf Path");
        }

        // Disable a spurious malf alert from within PM Reset, as we go about
        // halting the PPEs
        l_data64.flush<0>().setBit<p9hcd::STOP_RECOVERY_TRIGGER_ENABLE>();
        FAPI_TRY(fapi2::putScom(i_target, PU_OCB_OCI_OCCFLG2_CLEAR, l_data64));
    }

    //  ************************************************************************
    //  Initialize the PM FFDC section headers in HOMER, record the PPE halt
    //  states and FIR data before resetting the subsystem
    //  ************************************************************************
    FAPI_DBG("Init PM FFDC section in HOMER & collect PPE Halt and FIR states");
    FAPI_TRY ( p9_pm_collect_ffdc(i_target, i_pHomerImage, PLAT_INIT),
               "PM FFDC Error, Plat: 0x%02X", PLAT_INIT );
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After PM FFDC Init & Read PPE Halt, FIR states"));

    //  ************************************************************************
    //  Mask the OCC FIRs as errors can occur in what follows
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_occ_firinit for masking errors in reset operation.");
    l_phase = PM_RESET_FIR_OCC;
    FAPI_TRY (FAPI_ATTR_SET (fapi2::ATTR_PM_RESET_PHASE, i_target, l_phase));
    FAPI_EXEC_HWP(l_rc, p9_pm_occ_firinit, i_target, p9pm::PM_RESET);
    FAPI_TRY(l_rc, "ERROR: Failed to mask OCC FIRs.");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After masking FIRs"));

    //  ************************************************************************
    //  Halt the OCC PPC405 and reset it safely
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_occ_control to put OCC PPC405 into reset safely.");
    l_phase = PM_RESET_OCC_CTRL;
    FAPI_TRY (FAPI_ATTR_SET (fapi2::ATTR_PM_RESET_PHASE, i_target, l_phase));
    FAPI_EXEC_HWP(l_rc, p9_pm_occ_control,
                  i_target,
                  p9occ_ctrl::PPC405_RESET_SEQUENCE, //Operation on PPC405
                  p9occ_ctrl::PPC405_BOOT_NULL, // Boot instruction location
                  0); //Jump to 405 main instruction - not used here
    FAPI_TRY(l_rc, "ERROR: Failed to reset OCC PPC405");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After safe reset of OCC PPC405"));

    //Call special wake up if ATTR_SKIP_WAKEUP is not set.
    if (!l_skip_wakeup)
    {
        if (l_malfAlert == false)
        {
            // Clear the hcode error injection bits so special wake-up can succeed
            FAPI_TRY(p9_pm_reset_clear_errinj(i_target));

            //  ************************************************************************
            //  Put all EX chiplets in special wakeup
            //  ************************************************************************
            FAPI_DBG("Enable special wakeup for all functional  EX targets.");
            l_phase = PM_RESET_SPL_WKUP_EX_ALL;
            FAPI_TRY (FAPI_ATTR_SET (fapi2::ATTR_PM_RESET_PHASE, i_target, l_phase));
            FAPI_TRY(special_wakeup_all(i_target,
                                        true),//Enable splwkup
                     "ERROR: Failed to remove EX chiplets from special wakeup");

            // To prevent unnecessary Quad Special Wakeup request timeout,
            // Upon upcoming reset(ppe down, thus cannot service quad special wakeup),
            // Assert Quad Special Wakeup Done as Core Special Wakeup Done is asserted
            // Note: This Done will be reset by SGPE code upon reboot
            FAPI_DBG("Assert Quad Special Wakeup Done upon upcoming PPE reset");
            std::vector<fapi2::Target<fapi2::TARGET_TYPE_EQ>> l_eqChiplets =
                        i_target.getChildren<fapi2::TARGET_TYPE_EQ>(fapi2::TARGET_STATE_FUNCTIONAL);

            for ( auto l_itr = l_eqChiplets.begin(); l_itr != l_eqChiplets.end(); ++l_itr)
            {
                FAPI_TRY(fapi2::putScom(*l_itr, EQ_PPM_GPMMR_SCOM2, l_data64.flush<0>().setBit<0>()),
                         "ERROR: Failed to write EQ_PPM_GPMMR_SCOM2");
            }

            FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After EX in special wakeup"));
        }
        else
        {
            // Put a mark that we are in a PM Reset as part of handling a PM Malf Alert
            l_pmMalfCycle = fapi2::ENUM_ATTR_PM_MALF_CYCLE_ACTIVE;
            FAPI_TRY (FAPI_ATTR_SET (fapi2::ATTR_PM_MALF_CYCLE, i_target, l_pmMalfCycle));
            FAPI_TRY(p9_pm_glob_fir_trace(i_target, "Skip special wakeup in malf alert path"));
        }

        //  ************************************************************************
        //  Set Auto Special Wake-up Mode to all EXs ECs if spl. wkup done is asserted
        //  ************************************************************************
        FAPI_DBG("Set auto special wakeup for all functional  EX targets.");
        l_phase = PM_RESET_SET_AUTO_SPL_WKUP;
        FAPI_TRY (FAPI_ATTR_SET (fapi2::ATTR_PM_RESET_PHASE, i_target, l_phase));
        FAPI_TRY(p9_pm_set_auto_spwkup(i_target));
    }
    else
    {
        FAPI_INF("Skipping enabling special wakeup and auto-special wakeup"
                 " because SKIP_WAKEUP attribute is set");
    }

    //  ************************************************************************
    //  Mask the PBA & CME FIRs as errors can occur in what follows
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_firinit for masking errors in reset operation.");
    FAPI_EXEC_HWP(l_rc, p9_pm_firinit, i_target, p9pm::PM_RESET);
    FAPI_TRY(l_rc, "ERROR: Failed to mask PBA & CME FIRs.");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After masking FIRs"));

    //  ************************************************************************
    //  Issue reset to OCC GPEs ( GPE0 and GPE1) (Bring them to HALT)
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_occ_gpe_init to reset OCC GPE");
    l_phase = PM_RESET_OCC_GPE;
    FAPI_TRY (FAPI_ATTR_SET (fapi2::ATTR_PM_RESET_PHASE, i_target, l_phase));
    FAPI_EXEC_HWP(l_rc, p9_pm_occ_gpe_init,
                  i_target,
                  p9pm::PM_RESET,
                  p9occgpe::GPEALL // Apply to both OCC GPEs
                 );
    FAPI_TRY(l_rc, "ERROR: Failed to reset the OCC GPEs");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After reset of OCC GPEs"));

    //  ************************************************************************
    //  Collect OCC FFDC into FFDC section in HOMER
    //  ************************************************************************
    FAPI_DBG("Collect FFDC from 405, GPE0 and GPE1 to HOMER");
    FAPI_TRY ( p9_pm_collect_ffdc (i_target, i_pHomerImage, PLAT_OCC),
               "PM FFDC Error, Plat: 0x%02X", PLAT_OCC );
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After OCC, GPE0 and GPE1 FFDC"));

    //  ************************************************************************
    //  Reset the PSTATE GPE (Bring it to HALT)
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_pstate_gpe_init to reset PGPE");
    l_phase = PM_RESET_PGPE;
    FAPI_TRY (FAPI_ATTR_SET (fapi2::ATTR_PM_RESET_PHASE, i_target, l_phase));
    FAPI_EXEC_HWP(l_rc, p9_pm_pstate_gpe_init, i_target, p9pm::PM_RESET);
    FAPI_TRY(l_rc, "ERROR: Failed to reset the PGPE");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After reset of PGPE"));

    // Mask OCC HB bit in OCC fir mask register
    {
        const uint32_t l_OCC_HB_ERR_NOTIFY = 4;
        p9pmFIR::PMFir <p9pmFIR::FIRTYPE_OCC_LFIR> l_occFir(i_target);
        FAPI_TRY(l_occFir.get(p9pmFIR::REG_ALL),
                 "ERROR: Failed to get the OCC FIR values");
        FAPI_TRY(l_occFir.mask(l_OCC_HB_ERR_NOTIFY));
        // Not doing the restoreSavedMask, as this is a special case between reset->init
        // and pm init handles it
        FAPI_TRY(l_occFir.put(),
                 "ERROR: Failed to write OCC LFIR setting for STOP_RCV_NOTIFY_PRD");
    }

    //  ************************************************************************
    //  Collect PGPE FFDC into FFDC section in HOMER
    //  ************************************************************************
    FAPI_DBG("Collect FFDC from PGPE to HOMER");
    FAPI_TRY ( p9_pm_collect_ffdc (i_target, i_pHomerImage, PLAT_PGPE),
               "PM FFDC Error, Plat: 0x%02X", PLAT_PGPE );
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After PGPE FFDC"));

    //  ************************************************************************
    //  Reset the STOP GPE (Bring it to HALT)
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_stop_gpe_init to reset SGPE");
    l_phase = PM_RESET_SGPE;
    FAPI_TRY (FAPI_ATTR_SET (fapi2::ATTR_PM_RESET_PHASE, i_target, l_phase));
    FAPI_EXEC_HWP(l_rc, p9_pm_stop_gpe_init, i_target, p9pm::PM_RESET);
    FAPI_TRY(l_rc, "ERROR: Failed to reset SGPE");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After reset of SGPE"));

    //  ************************************************************************
    //  Collect SGPE FFDC into FFDC section in HOMER
    //  ************************************************************************
    FAPI_DBG("Collect FFDC from SGPE to HOMER");
    FAPI_TRY ( p9_pm_collect_ffdc ( i_target, i_pHomerImage, PLAT_SGPE),
               "PM FFDC Error, Plat: 0x%02X", PLAT_SGPE );
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After SGPE FFDC"));

    //  ************************************************************************
    // Clear the OCC Flag and Scratch2 registers
    // which contain runtime settings and modes for PM GPEs (Pstate and Stop functions)
    //  ************************************************************************
    l_data64.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, PU_OCB_OCI_OCCFLG_SCOM, l_data64),
             "ERROR: Failed to write to OCC Flag Register");
    FAPI_TRY(fapi2::putScom(i_target, PU_OCB_OCI_OCCS2_SCOM, l_data64),
             "ERROR: Failed to write to OCC Scratch2 Register");

    //  ************************************************************************
    //  Collect FFDC from CPPMs into FFDC section in HOMER
    //  ************************************************************************
    FAPI_DBG("Collect FFDC from CPPMs to HOMER");
    FAPI_TRY ( p9_pm_collect_ffdc (i_target, i_pHomerImage, PLAT_CPPM),
               "PM FFDC Error, Plat: 0x%02X", PLAT_CPPM );
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After CPPMs FFDC"));

    //  ************************************************************************
    //  Collect FFDC from QPPMs into FFDC section in HOMER
    //  ************************************************************************
    FAPI_DBG("Collect FFDC from QPPMs to HOMER");
    FAPI_TRY ( p9_pm_collect_ffdc (i_target, i_pHomerImage, PLAT_QPPM),
               "PM FFDC Error, Plat: 0x%02X", PLAT_QPPM );
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After QPPMs FFDC"));

    //  ************************************************************************
    //  Reset Cores and Quads
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_corequad_init to reset cores & quads");
    l_phase = PM_RESET_EC_EQ;
    FAPI_TRY (FAPI_ATTR_SET (fapi2::ATTR_PM_RESET_PHASE, i_target, l_phase));
    FAPI_EXEC_HWP(l_rc, p9_pm_corequad_init,
                  i_target,
                  p9pm::PM_RESET,
                  CME_FIRMASK, // CME FIR MASK
                  CORE_ERRMASK,// Core Error Mask
                  QUAD_ERRMASK // Quad Error Mask
                 );
    FAPI_TRY(l_rc, "ERROR: Failed to reset cores & quads");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After reset of core quad"));

    //  ************************************************************************
    //  Collect FFDC from CMEs into FFDC section in HOMER
    //  ************************************************************************
    FAPI_DBG("Collect FFDC from CMEs to HOMER");
    FAPI_TRY ( p9_pm_collect_ffdc (i_target, i_pHomerImage, PLAT_CME),
               "PM FFDC Error, Plat: 0x%02X", PLAT_CME );
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After CME FFDC"));

    //  ************************************************************************
    //  Move PSAFE values to DPLL and Ext Voltage
    //  ************************************************************************
    l_phase = PM_RESET_PSAFE_UPDATE;
    FAPI_TRY (FAPI_ATTR_SET (fapi2::ATTR_PM_RESET_PHASE, i_target, l_phase));
    FAPI_TRY(p9_pm_reset_psafe_update(i_target),
             "Error from p9_pm_reset_psafe_update");

    //  ************************************************************************
    //  Issue reset to OCC-SRAM
    //  ************************************************************************
    FAPI_DBG("Executing p8_occ_sram_init to reset OCC-SRAM");
    l_phase = PM_RESET_OCC_SRAM;
    FAPI_TRY (FAPI_ATTR_SET (fapi2::ATTR_PM_RESET_PHASE, i_target, l_phase));
    FAPI_EXEC_HWP(l_rc, p9_pm_occ_sram_init, i_target, p9pm::PM_RESET);
    FAPI_TRY(l_rc, "ERROR: Failed to reset OCC SRAM");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After reset of OCC SRAM"));

    //  ************************************************************************
    //  Issue reset to OCB
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_ocb_init to reset OCB");
    l_phase = PM_RESET_OCB;
    FAPI_TRY (FAPI_ATTR_SET (fapi2::ATTR_PM_RESET_PHASE, i_target, l_phase));
    FAPI_EXEC_HWP(l_rc, p9_pm_ocb_init,
                  i_target,
                  p9pm::PM_RESET,
                  p9ocb::OCB_CHAN0, // Channel
                  p9ocb::OCB_TYPE_NULL, // Channel type
                  0, // Base address
                  0, // Length of circular push/pull queue
                  p9ocb::OCB_Q_OUFLOW_NULL, // Channel flow control
                  p9ocb::OCB_Q_ITPTYPE_NULL // Channel interrupt control
                 );
    FAPI_TRY(l_rc, "ERROR: Failed to reset OCB");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After reset of OCB channels"));

    //  ************************************************************************
    //  Resets P2S and HWC logic
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_pss_init to reset P2S and HWC logic");
    l_phase = PM_RESET_PSS;
    FAPI_TRY (FAPI_ATTR_SET (fapi2::ATTR_PM_RESET_PHASE, i_target, l_phase));
    FAPI_EXEC_HWP(l_rc, p9_pm_pss_init, i_target, p9pm::PM_RESET);
    FAPI_TRY(l_rc, "ERROR: Failed to reset PSS & HWC");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After reset of PSS"));

    //  ************************************************************************
    //  Trigger OCC LFIR so that bad ec/ex/eq are updated for pm_init and prd
    //  gets a chance to deconfig cores and callout hw and grab ffdc to logs
    //  This should be the last phase in pm reset
    //  ************************************************************************
    if (l_malfAlert == true)
    {
        const uint32_t l_OCC_LFIR_BIT_STOP_RCV_NOTIFY_PRD = 3;

        l_phase = PM_RESET_NOTIFY_PRD;
        FAPI_TRY (FAPI_ATTR_SET (fapi2::ATTR_PM_RESET_PHASE, i_target, l_phase));

        p9pmFIR::PMFir <p9pmFIR::FIRTYPE_OCC_LFIR> l_occFir(i_target);
        FAPI_TRY(l_occFir.get(p9pmFIR::REG_ALL),
                 "ERROR: Failed to get the OCC FIR values");
        FAPI_TRY(l_occFir.setRecvAttn(l_OCC_LFIR_BIT_STOP_RCV_NOTIFY_PRD),
                 FIR_REC_ATTN_ERROR);
        // Not doing the restoreSavedMask, as this is a special case between reset->init
        // and pm init handles it
        FAPI_TRY(l_occFir.put(),
                 "ERROR: Failed to write OCC LFIR setting for STOP_RCV_NOTIFY_PRD");

        l_data64.flush<0>();
        l_data64.setBit(l_OCC_LFIR_BIT_STOP_RCV_NOTIFY_PRD);

        FAPI_IMP ("p9_pm_reset: Signalling PRD via OCCLFIR Bit 3 [STOP_RCV_NOTIFY_PRD]!");
        FAPI_TRY(fapi2::putScom(i_target, PERV_TP_OCC_SCOM_OCCLFIR_OR, l_data64),
                 "ERROR: Failed to write to OCC Flag Register");
    }

    l_phase = PM_RESET_DONE;
    FAPI_TRY (FAPI_ATTR_SET (fapi2::ATTR_PM_RESET_PHASE, i_target, l_phase));

fapi_try_exit:
    // current_err can get overridden by any call to FAPI_TRY so we
    //  need to save it away before we execute additional code
    fapi2::ReturnCode l_current_err = fapi2::current_err;

    //  Update PM FFDC Section Header with Miscellaneous Info
    l_rc = p9_pm_collect_ffdc (i_target, i_pHomerImage, PLAT_MISC);

    if (l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        FAPI_ERR ("Failed updating Miscellaneous FFDC to PM FFDC section!", PLAT_MISC );
    }

    l_pmResetActive = fapi2::ENUM_ATTR_INITIATED_PM_RESET_INACTIVE;
    FAPI_ATTR_SET (fapi2::ATTR_INITIATED_PM_RESET, i_target, l_pmResetActive);

    FAPI_ATTR_GET (fapi2::ATTR_PM_RESET_PHASE, i_target, l_phase);
    FAPI_IMP("<< p9_pm_reset: Phase 0x%02X", l_phase);
    return l_current_err;
}

fapi2::ReturnCode
p9_pm_reset_psafe_update(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    uint32_t l_safe_mode_freq_dpll = 0;
    bool l_external_voltage_update = true;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_EQ>> l_eqChiplets;
    fapi2::Target<fapi2::TARGET_TYPE_EQ> l_firstEqChiplet;
    fapi2::buffer<uint64_t> l_dpll_data64;
    fapi2::buffer<uint64_t> l_vdm_data64;
    fapi2::buffer<uint64_t> l_dpll_fmult;
    uint32_t l_dpll_mhz;
    fapi2::buffer<uint64_t> l_occflg_data(0);
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    uint8_t l_chipNum = 0xFF;
    fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ_Type l_attr_safe_mode_freq_mhz;
    fapi2::ATTR_SAFE_MODE_VOLTAGE_MV_Type l_attr_safe_mode_mv;
    fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ_Type l_attr_reset_safe_mode_freq_mhz = 0;
    fapi2::ATTR_SAFE_MODE_VOLTAGE_MV_Type l_attr_reset_safe_mode_mv = 0;
    fapi2::ATTR_VDD_AVSBUS_BUSNUM_Type l_vdd_bus_num;
    fapi2::ATTR_VDD_AVSBUS_RAIL_Type   l_vdd_bus_rail;
    fapi2::ATTR_VDD_BOOT_VOLTAGE_Type       l_vdd_voltage_mv;
    fapi2::ATTR_FREQ_DPLL_REFCLOCK_KHZ_Type l_freq_proc_refclock_khz;
    fapi2::ATTR_PROC_DPLL_DIVIDER_Type      l_proc_dpll_divider;
    fapi2::ATTR_SAFE_MODE_NOVDM_UPLIFT_MV_Type l_uplift_mv;
    fapi2::ATTR_EXTERNAL_VRM_STEPSIZE_Type l_ext_vrm_step_size_mv;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ, i_target, l_attr_safe_mode_freq_mhz));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAFE_MODE_VOLTAGE_MV, i_target, l_attr_safe_mode_mv));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDD_AVSBUS_BUSNUM, i_target, l_vdd_bus_num));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDD_AVSBUS_RAIL, i_target, l_vdd_bus_rail));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDD_BOOT_VOLTAGE, i_target, l_vdd_voltage_mv));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_DPLL_DIVIDER, i_target, l_proc_dpll_divider));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_DPLL_REFCLOCK_KHZ, FAPI_SYSTEM, l_freq_proc_refclock_khz));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAFE_MODE_NOVDM_UPLIFT_MV, i_target, l_uplift_mv));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EXTERNAL_VRM_STEPSIZE, FAPI_SYSTEM, l_ext_vrm_step_size_mv));
    l_attr_safe_mode_mv += l_uplift_mv;
    //Reset safe mode attributes
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ, i_target, l_attr_reset_safe_mode_freq_mhz));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SAFE_MODE_VOLTAGE_MV, i_target, l_attr_reset_safe_mode_mv));

    do
    {
        FAPI_INF(">> p9_pm_reset_psafe_update");
        FAPI_TRY(fapi2::getScom(i_target, PU_OCB_OCI_OCCFLG_SCOM2, l_occflg_data),
                 "Error setting OCC Flag register bit REQUEST_OCC_SAFE_STATE");

        if (l_occflg_data.getBit<p9hcd::PGPE_SAFE_MODE_ACTIVE>())
        {
            FAPI_IMP("PGPE indicates valid safe mode has been achieved");
            break;
        }


        if (!l_attr_safe_mode_freq_mhz || !l_attr_safe_mode_mv)
        {
            break;
        }

        l_eqChiplets = i_target.getChildren<fapi2::TARGET_TYPE_EQ>(fapi2::TARGET_STATE_FUNCTIONAL);

        for ( auto l_itr = l_eqChiplets.begin(); l_itr != l_eqChiplets.end(); ++l_itr)
        {
            l_dpll_fmult.flush<0>();
            FAPI_TRY(fapi2::getScom(*l_itr, EQ_QPPM_DPLL_FREQ , l_dpll_data64),
                     "ERROR: Failed to read EQ_QPPM_DPLL_FREQ");

            l_dpll_data64.extractToRight<EQ_QPPM_DPLL_FREQ_FMULT,
                                         EQ_QPPM_DPLL_FREQ_FMULT_LEN>(l_dpll_fmult);

            // Convert frequency value to a format that needs to be written to the
            // register
            l_safe_mode_freq_dpll = ((l_attr_safe_mode_freq_mhz * 1000) * l_proc_dpll_divider) /
                                    l_freq_proc_refclock_khz;

            FAPI_INF("l_dpll_fmult %08x  l_safe_mode_freq_dpll %08x",
                     l_dpll_fmult, l_safe_mode_freq_dpll);

            // Convert back to the complete frequency value
            l_dpll_mhz =  ((l_dpll_fmult * l_freq_proc_refclock_khz ) / l_proc_dpll_divider ) / 1000;


            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, *l_itr, l_chipNum));
            FAPI_INF("For EQ number %u, l_dpll_mhz %08X l_attr_safe_mode_freq_mhz %08X",
                     l_chipNum, l_dpll_mhz, l_attr_safe_mode_freq_mhz);
            FAPI_INF ("l_vdd_voltage_mv %08x, l_attr_safe_mode_mv %08x", l_vdd_voltage_mv, l_attr_safe_mode_mv);

            // if DPLL freq is less than safe mode freq.. we need to first update
            // vdd voltage and then freq. And if DPLL is greater .. then need to
            // update freq first and then VDD.
            if (l_dpll_mhz < l_attr_safe_mode_freq_mhz)
            {
                //Here we need to update VDD only once.. because we are in EQ
                //target loop.VDD is updated for the whole proc once.
                if (l_external_voltage_update)
                {
                    FAPI_TRY(p9_setup_evid_voltageWrite(i_target,
                                                        l_vdd_bus_num,
                                                        l_vdd_bus_rail,
                                                        l_attr_safe_mode_mv,
                                                        l_ext_vrm_step_size_mv,
                                                        VDD_SETUP),
                             "Error from VDD setup function");
                    l_external_voltage_update = false;
                }
            }

            //FMax
            l_dpll_data64.insertFromRight<EQ_QPPM_DPLL_FREQ_FMAX,
                                          EQ_QPPM_DPLL_FREQ_FMAX_LEN>(l_safe_mode_freq_dpll);
            //FMin
            l_dpll_data64.insertFromRight<EQ_QPPM_DPLL_FREQ_FMIN,
                                          EQ_QPPM_DPLL_FREQ_FMIN_LEN>(l_safe_mode_freq_dpll);
            //FMult
            l_dpll_data64.insertFromRight<EQ_QPPM_DPLL_FREQ_FMULT,
                                          EQ_QPPM_DPLL_FREQ_FMULT_LEN>(l_safe_mode_freq_dpll);

            FAPI_TRY(fapi2::putScom(*l_itr, EQ_QPPM_DPLL_FREQ, l_dpll_data64),
                     "ERROR: Failed to write for EQ_QPPM_DPLL_FREQ");
        } //end of eq list

        //Update Avs Bus voltage
        //Here this condition will be true, when DPLL is greater than safe mode
        //freq.
        if (l_external_voltage_update)
        {
            FAPI_TRY(p9_setup_evid_voltageWrite(i_target,
                                                l_vdd_bus_num,
                                                l_vdd_bus_rail,
                                                l_attr_safe_mode_mv,
                                                l_ext_vrm_step_size_mv,
                                                VDD_SETUP),
                     "Error from VDD setup function");
        }

    }
    while (0);

fapi_try_exit:
    return fapi2::current_err;
}

// Walk through each EX chiplet (and each core within an EX) to determine if
// special wake-up done is asserted.  If so, set auto special wake-up mode to
// protect the core(s) while the PM complex is being reset.

fapi2::ReturnCode
p9_pm_set_auto_spwkup(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{

    FAPI_INF(">> p9_set_auto_spwkup");

    fapi2::buffer <uint64_t> l_deadCoreVector;
    uint8_t l_malfAlertActive = fapi2::ENUM_ATTR_PM_MALF_CYCLE_INACTIVE;
    FAPI_TRY (FAPI_ATTR_GET (fapi2::ATTR_PM_MALF_CYCLE, i_target,
                             l_malfAlertActive));

    if (l_malfAlertActive == fapi2::ENUM_ATTR_PM_MALF_CYCLE_ACTIVE)
    {
        FAPI_TRY( getScom (i_target, P9N2_PU_OCB_OCI_OCCFLG2_SCOM,
                           l_deadCoreVector),
                  "Failed to Read OCC Flag2 Register for PM Malf Dead Core Vector" );
    }

    // For each EX target
    for (auto& l_ex_chplt : i_target.getChildren<fapi2::TARGET_TYPE_EX>
         (fapi2::TARGET_STATE_FUNCTIONAL))
    {

        fapi2::buffer<uint64_t> l_gpmmr;
        fapi2::buffer<uint64_t> l_lmcr;
        uint32_t l_bit;

        fapi2::ATTR_CHIP_UNIT_POS_Type l_ex_num;
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                l_ex_chplt,
                                l_ex_num));

        for (auto& l_core : l_ex_chplt.getChildren<fapi2::TARGET_TYPE_CORE>
             (fapi2::TARGET_STATE_FUNCTIONAL))
        {
            fapi2::ATTR_CHIP_UNIT_POS_Type l_core_num;
            FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                    l_core,
                                    l_core_num));
            FAPI_DBG("Checking for special wakeup done on core %d in EX %d ",
                     l_core_num, l_ex_num);

            FAPI_TRY(fapi2::getScom(l_core, C_PPM_GPMMR_SCOM,  l_gpmmr),
                     "GetScom of GPMMR failed");

            if (l_deadCoreVector.getBit(l_core_num))
            {
                // HYP could not spl. wkup. this core on a PM Malf HMI.
                // Leave it that way and do not enable auto spl. wkup. on it
                FAPI_INF ("==> Skip auto spl wkup enabled on HYP dead core %d", l_core_num);
                continue; // move on to the next core
            }

            if (l_gpmmr.getBit<EQ_PPM_GPMMR_SPECIAL_WKUP_DONE>())
            {
                // Clear the auto special wake-up disable (eg enable it) for the core.
                l_bit = EQ_CME_SCOM_LMCR_C0_AUTO_SPECIAL_WAKEUP_DISABLE + (l_core_num % 2);
                l_lmcr.flush<0>().setBit(l_bit);
                FAPI_TRY(fapi2::putScom(l_ex_chplt, EX_CME_SCOM_LMCR_SCOM1,  l_lmcr),
                         "PutScom of LMCR failed: core %d", l_core_num);
                FAPI_INF ("==> Auto spl wakeup enabled for core %d", l_core_num);
            }
            else
            {
                if (l_malfAlertActive == fapi2::ENUM_ATTR_PM_MALF_CYCLE_INACTIVE)
                {
                    FAPI_ASSERT (false,
                                 fapi2::PM_RESET_SPWKUP_DONE_ERROR ()
                                 .set_CORE_TARGET(l_core)
                                 .set_GPMMR(l_gpmmr)
                                 .set_MALF_ALERT_ACTIVE(l_malfAlertActive),
                                 "Core expected to be in special wake-up is not "
                                 "prior to setting auto special wake-up mode");
                }
                else
                {
                    // In Malf Path, it is possible that special wakeup failed
                    // on cores above a bad CME. These cores should come in as
                    // bad via the PHYP bad core vector & PM Init is expected to
                    // come up without them (the CME catering to these).
                    // So, do not break the PM Reset/Recvoery flow in this case
                    FAPI_ASSERT_NOEXIT ( false,
                                         fapi2::PM_RESET_SPWKUP_DONE_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                         .set_CORE_TARGET(l_core)
                                         .set_GPMMR(l_gpmmr)
                                         .set_MALF_ALERT_ACTIVE(l_malfAlertActive),
                                         "Core expected to be in special wake-up is not prior to setting"
                                         " auto special wake-up mode. Ignored in PM recovery Path!");
                }
            }
        }
    }

fapi_try_exit:
    FAPI_INF("<< p9_set_auto_spwkup");
    return fapi2::current_err;
}

fapi2::ReturnCode p9_pm_collect_ffdc (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    void* i_pHomerImage,
    const uint8_t i_plat )
{
    using namespace p9_stop_recov_ffdc;
    FAPI_DBG (">>  p9_pm_collect_ffdc: Plat %d", i_plat);

    fapi2::ReturnCode l_rc;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_PM_RESET_FFDC_ENABLE_Type l_ffdcEnable =
        fapi2::ENUM_ATTR_PM_RESET_FFDC_ENABLE_FALSE;
    fapi2::ATTR_PM_RESET_PHASE_Type l_phase = PM_RESET_UNKNOWN;

    if( i_pHomerImage == nullptr )
    {
        FAPI_INF ("HOMER is not valid, skipping p9_pm_collect_ffdc");
        goto fapi_try_exit;
    }

    FAPI_TRY (FAPI_ATTR_GET (fapi2::ATTR_PM_RESET_PHASE, i_target, l_phase));
    FAPI_TRY (FAPI_ATTR_GET (fapi2::ATTR_PM_RESET_FFDC_ENABLE, FAPI_SYSTEM, l_ffdcEnable));

    if (l_ffdcEnable == fapi2::ENUM_ATTR_PM_RESET_FFDC_ENABLE_TRUE)
    {
        switch (i_plat)
        {
            case PLAT_INIT:
                FAPI_INF ("Init PM FFDC sections, collect PPE and FIR states to HOMER");
                FAPI_EXEC_HWP (l_rc, p9_pm_recovery_ffdc_base, i_target, i_pHomerImage);
                break;

            case PLAT_CME:
                FAPI_DBG("Collecting CME(s) FFDC to HOMER");
                FAPI_EXEC_HWP(l_rc, p9_pm_recovery_ffdc_cme, i_target, i_pHomerImage);
                break;

            case PLAT_SGPE:
                FAPI_DBG("Collecting SGPE FFDC to HOMER");
                FAPI_EXEC_HWP(l_rc, p9_pm_recovery_ffdc_sgpe, i_target, i_pHomerImage);
                break;

            case PLAT_PGPE:
                FAPI_DBG("Collecting PGPE FFDC to HOMER");
                FAPI_EXEC_HWP(l_rc, p9_pm_recovery_ffdc_pgpe, i_target, i_pHomerImage);
                break;

            case PLAT_OCC:
                FAPI_DBG("Collecting OCC 405, GPE0 and GPE1 FFDC to HOMER");
                FAPI_EXEC_HWP(l_rc, p9_pm_recovery_ffdc_occ, i_target, i_pHomerImage);
                break;

            case PLAT_CPPM:
                FAPI_DBG("Collecting CPPM(s) FFDC to HOMER");
                FAPI_EXEC_HWP(l_rc, p9_pm_recovery_ffdc_cppm, i_target, i_pHomerImage);
                break;

            case PLAT_QPPM:
                FAPI_DBG("Collecting QPPM(s) FFDC to HOMER");
                FAPI_EXEC_HWP(l_rc, p9_pm_recovery_ffdc_qppm, i_target, i_pHomerImage);
                break;

            case PLAT_MISC:
                FAPI_DBG("Collecting Miscellaneous FFDC to HOMER");
                l_rc = p9_pm_recovery_ffdc_misc (i_target, i_pHomerImage);
                break;

            default:
                FAPI_ERR ("Bad Input Platform: 0x%02X .. Ignored!", i_plat);
                l_rc = fapi2::RC_PM_RESET_FFDC_ERROR;
                break;
        }

        FAPI_ASSERT_NOEXIT (l_rc == fapi2::FAPI2_RC_SUCCESS,
                            fapi2::PM_RESET_FFDC_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                            .set_CHIP_TARGET(i_target)
                            .set_PM_RESET_PHASE(l_phase)
                            .set_PM_FFDC_PLAT(i_plat),
                            "Failed PM FFDC collection: Plat: 0x%02X Phase: 0x%02X",
                            i_plat, l_phase);
    }

fapi_try_exit:
    FAPI_DBG ( "<< p9_pm_collect_ffdc: Plat: 0x%02X Phase: 0x%02X Enabled: %d",
               i_plat, l_phase, l_ffdcEnable );
    return fapi2::current_err;
}

// Clear all error injection bits of so that the reset state can succeed.

fapi2::ReturnCode p9_pm_reset_clear_errinj (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::buffer<uint64_t> l_data64;
    fapi2::ATTR_CHIP_UNIT_POS_Type l_chpltNumber = 0;

    FAPI_INF(">> p9_pm_reset_clear_errinj");

    auto l_coreChiplets =
        i_target.getChildren<fapi2::TARGET_TYPE_CORE>
        (fapi2::TARGET_STATE_FUNCTIONAL);

    FAPI_INF("Clearing SGPE and PGPE Hcode Error Injection bits");
    // *INDENT-OFF*
    l_data64.flush<0>()
        .setBit<p9hcd::OCCFLG2_SGPE_HCODE_STOP_REQ_ERR_INJ>()
        .setBit<p9hcd::OCCFLG2_PGPE_HCODE_FIT_ERR_INJ>()
        .setBit<p9hcd::OCCFLG2_PGPE_HCODE_PSTATE_REQ_ERR_INJ>();
    // *INDENT-ON*
    FAPI_TRY(fapi2::putScom(i_target, PU_OCB_OCI_OCCFLG2_CLEAR, l_data64));

    // For each core target, clear CME injection bits
    for (auto l_core_chplt : l_coreChiplets)
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                               l_core_chplt,
                               l_chpltNumber),
                 "ERROR: Failed to get the position of the Core %d",
                 l_chpltNumber);

        FAPI_INF("Clearing CME Hcode Error Injection and other CSAR settings for core %d",
                 l_chpltNumber);
        // *INDENT-OFF*
        l_data64.flush<0>()
                .setBit<p9hcd::CPPM_CSAR_FIT_HCODE_ERROR_INJECT>()
                .setBit<p9hcd::CPPM_CSAR_ENABLE_PSTATE_REGISTRATION_INTERLOCK>()
                .setBit<p9hcd::CPPM_CSAR_PSTATE_HCODE_ERROR_INJECT>()
                .setBit<p9hcd::CPPM_CSAR_STOP_HCODE_ERROR_INJECT>();
        // Note:  CPPM_CSAR_DISABLE_CME_NACK_ON_PROLONGED_DROOP is NOT
        //        cleared as this is a persistent, characterization setting
        // *INDENT-ON*
        FAPI_TRY(fapi2::putScom(l_core_chplt, C_CPPM_CSAR_CLEAR, l_data64));
    }

fapi_try_exit:
    FAPI_INF("<< p9_pm_reset_clear_errinj");
    return fapi2::current_err;
}
