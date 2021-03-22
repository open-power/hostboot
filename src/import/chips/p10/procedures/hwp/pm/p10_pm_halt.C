/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_halt.C $        */
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
///
/// @file p10_pm_halt.C
/// @brief Wrapper that calls underlying HWPs to perform a Power Management
///        halt function when needing to restart the OCC complex.
///
// *HWP HWP Owner        : Greg Still <stillgs@us.ibm.com>
// *HWP HWP Backup Owner : Prasad BG Ranganath <prasadbgr@in.ibm.com>
// *HWP FW Owner         : Prem S Jha <premjha2@in.ibm.com>
// *HWP Team             : PM
// *HWP Level            : 2
// *HWP Consumed by      : HS

///
/// High-level procedure flow:
///
/// @verbatim
///
///     - Mask the OCC FIRs
///     - Halt and then Reset the PPC405
///     - Put all EC chiplets in special wakeup
///     - Mask PBA, QME FIRs
///     - Halt OCC, PGPE and XGPE
///     - Halt QME
///     - Reset OCB
///     - Reset PSS
///
/// @endverbatim
///
// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p10_pm_halt.H>
#include <p10_pm_occ_gpe_init.H>
#include <p10_pm_hcd_flags.h>
#include <p10_core_special_wakeup.H>
#include <multicast_group_defs.H>
#include <p10_pm_occ_firinit.H>

#include <p10_scom_proc.H>
#include <p10_scom_eq.H>
using namespace scomt::eq;
using namespace scomt::proc;
// -----------------------------------------------------------------------------
// Global variables
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Constant Defintions
// -----------------------------------------------------------------------------

fapi2::ReturnCode  initiateSPWU(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

// -----------------------------------------------------------------------------
// Function definitions
// -----------------------------------------------------------------------------
fapi2::ReturnCode p10_pm_halt(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const pm::PM_DUMP_MODE i_dump_mode,
    void* i_pHomerImage = NULL)
{
    FAPI_IMP(">> p10_pm_halt");

    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_data64;
    fapi2::ATTR_PM_MALF_ALERT_ENABLE_Type l_malfEnabled =
        fapi2::ENUM_ATTR_PM_MALF_ALERT_ENABLE_FALSE;
    bool l_malfAlert = false;

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    FAPI_TRY (FAPI_ATTR_GET (fapi2::ATTR_PM_MALF_ALERT_ENABLE,
                             FAPI_SYSTEM, l_malfEnabled));

    if (l_malfEnabled == fapi2::ENUM_ATTR_PM_MALF_ALERT_ENABLE_TRUE)
    {
        FAPI_TRY(fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW, l_data64),
                 "Error reading TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW to check for Malf Alert");

        if (l_data64.getBit<p10hcd::PM_CALLOUT_ACTIVE>())
        {
            l_malfAlert = true;
            FAPI_IMP("OCC FLAG2 Bit 28 [PM_CALLOUT_ACTIVE] Set: In Malf Path");
        }

        l_data64.flush<0>().setBit<p10hcd::STOP_RECOVERY_TRIGGER_ENABLE>();
        FAPI_TRY(fapi2::putScom(i_target,
                                TP_TPCHIP_OCC_OCI_OCB_OCCFLG3_WO_CLEAR,
                                l_data64));
    }

    //  ************************************************************************
    //  Mask the OCC FIRs as errors can occur in what follows
    //  ************************************************************************
    FAPI_DBG("Executing p10_pm_occ_firinit for masking errors in halt operation.");
    FAPI_EXEC_HWP(l_rc, p10_pm_occ_firinit, i_target, pm::PM_RESET_SOFT);
    FAPI_TRY(l_rc, "ERROR: Failed to mask OCC FIRs.");

    //  ************************************************************************
    //  Halt the OCC PPC405 and halt it safely
    //  ************************************************************************
    FAPI_DBG("Executing p10_pm_occ_control to put OCC PPC405 into halt safely.");
    FAPI_EXEC_HWP(l_rc, p10_pm_occ_control,
                  i_target,
                  occ_ctrl::PPC405_RESET_SEQUENCE, //Operation on PPC405
                  occ_ctrl::PPC405_BOOT_NULL, // Boot instruction location
                  0); //Jump to 405 main instruction - not used here
    FAPI_TRY(l_rc, "ERROR: Failed to halt OCC PPC405");
    //  ************************************************************************
    //  Mask the PBA & QME FIRs as errors can occur in what follows
    //  ************************************************************************
    FAPI_DBG("Executing p10_pm_firinit for masking errors in halt operation.");
    FAPI_EXEC_HWP(l_rc, p10_pm_firinit, i_target, pm::PM_RESET_SOFT);
    FAPI_TRY(l_rc, "ERROR: Failed to mask PBA & QME FIRs.");


    //  ************************************************************************
    //  Enable the special wakeup for all cores only if QME is active
    //  ************************************************************************
    FAPI_TRY(initiateSPWU(i_target));

    //  ************************************************************************
    //  Issue halt to OCC GPEs ( GPE0 and GPE1) (Bring them to HALT)
    //  ************************************************************************
    FAPI_DBG("Executing p10_pm_occ_gpe_init to halt OCC GPE");
    FAPI_EXEC_HWP(l_rc, p10_pm_occ_gpe_init,
                  i_target,
                  pm::PM_HALT,
                  occgpe::GPEALL // Apply to both OCC GPEs
                 );
    FAPI_TRY(l_rc, "ERROR: Failed to halt the OCC GPEs");

    //  ************************************************************************
    //  Reset the PSTATE GPE (Bring it to HALT)
    //  ************************************************************************
    FAPI_DBG("Executing p10_pm_pstate_gpe_init to halt PGPE");
    FAPI_EXEC_HWP(l_rc, p10_pm_pgpe_init, i_target, pm::PM_HALT);
    FAPI_TRY(l_rc, "ERROR: Failed to halt the PGPE");

    //  ************************************************************************
    //  Reset the XGPE (Bring it to HALT)
    //  ************************************************************************
    FAPI_DBG("Executing p10_pm_stop_gpe_init to halt XGPE");
    FAPI_EXEC_HWP(l_rc, p10_pm_xgpe_init, i_target, pm::PM_HALT);
    FAPI_TRY(l_rc, "ERROR: Failed to halt XGPE");

    //TODO
    //  ************************************************************************
    // Clear the OCC Flag and Scratch2 registers
    // which contain runtime settings and modes for PM GPEs (Pstate and Stop functions)
    //  ************************************************************************

    //  ************************************************************************
    //  Reset the QME (Bring it to HALT)
    //  ************************************************************************
    FAPI_DBG("Executing p10_pm_qme_init to halt QME");
    FAPI_EXEC_HWP(l_rc, p10_pm_qme_init, i_target, pm::PM_HALT);
    FAPI_TRY(l_rc, "ERROR: Failed to halt QME");

    //  ************************************************************************
    //  Issue halt to OCB
    //  ************************************************************************
    FAPI_DBG("Executing p10_pm_ocb_init to halt OCB");
    FAPI_EXEC_HWP(l_rc, p10_pm_ocb_init,
                  i_target,
                  pm::PM_HALT,
                  ocb::OCB_CHAN0, // Channel
                  ocb::OCB_TYPE_NULL, // Channel type
                  0, // Base address
                  0, // Length of circular push/pull queue
                  ocb::OCB_Q_OUFLOW_NULL, // Channel flow control
                  ocb::OCB_Q_ITPTYPE_NULL // Channel interrupt control
                 );
    FAPI_TRY(l_rc, "ERROR: Failed to halt OCB");

    //  ************************************************************************
    //  Resets P2S and HWC logic
    //  ************************************************************************
    FAPI_DBG("Executing p10_pm_pss_init to halt P2S and HWC logic");
    FAPI_EXEC_HWP(l_rc, p10_pm_pss_init, i_target, pm::PM_HALT);
    FAPI_TRY(l_rc, "ERROR: Failed to halt PSS & HWC");


    //  ************************************************************************
    //  Trigger OCC LFIR so that bad ec/ex/eq are updated for pm_init and prd
    //  gets a chance to deconfig cores and callout hw and grab ffdc to logs
    //  This should be the last phase in pm reset
    //  ************************************************************************
    if (l_malfAlert == true)
    {
        const uint32_t l_OCC_LFIR_BIT_STOP_RCV_NOTIFY_PRD = 3;

        pmFIR::PMFir <pmFIR::FIRTYPE_OCC_LFIR, fapi2::TARGET_TYPE_PROC_CHIP> l_occFir(i_target);
        FAPI_TRY(l_occFir.get(pmFIR::REG_ALL),
                 "ERROR: Failed to get the OCC FIR values");
        FAPI_TRY(l_occFir.setRecvAttn(l_OCC_LFIR_BIT_STOP_RCV_NOTIFY_PRD),
                 FIR_REC_ATTN_ERROR);
        // Not doing the restoreSavedMask, as this is a special case between reset->init
        // and pm init handles it
        FAPI_TRY(l_occFir.put(),
                 "ERROR: Failed to write OCC LFIR setting for STOP_RCV_NOTIFY_PRD");

        l_data64.flush<0>();
        l_data64.setBit(l_OCC_LFIR_BIT_STOP_RCV_NOTIFY_PRD);

        FAPI_IMP ("p10_pm_halt: Signalling PRD via OCCLFIR Bit 3 [STOP_RCV_NOTIFY_PRD]!");
        FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_SCOM_OCCLFIR_WO_OR, l_data64),
                 "ERROR: Failed to write to OCC Flag Register");
    }

fapi_try_exit:

    FAPI_IMP("<< p10_pm_halt");
    return fapi2::current_err;
}

fapi2::ReturnCode initiateSPWU(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_qme_flag;
    fapi2::buffer<uint64_t> l_xsr;

    auto l_eq_mc_and =
        i_target.getMulticast<fapi2::TARGET_TYPE_EQ, fapi2::MULTICAST_AND >(fapi2::MCGROUP_GOOD_EQ);

    // First check if QME_ACTIVE is set before assert spwu
    FAPI_TRY( getScom( l_eq_mc_and, QME_FLAGS_RW, l_qme_flag ) );
    FAPI_TRY( getScom( l_eq_mc_and, QME_SCOM_XIDBGPRO, l_xsr ) );

    FAPI_INF("Enable special wakeup for all functional  Core targets");
    fapi2::specialWakeup (i_target, true);

fapi_try_exit:

    FAPI_IMP("<< p10_pm_halt");
    return fapi2::current_err;
}
