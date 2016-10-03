/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_init.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file p9_pm_init.C
/// @brief Wrapper that initializes or resets the OCC complex.
///
// *HWP HWP Owner        : Greg Still <stillgs@us.ibm.com>
// *HWP HWP Backup Owner :
// *HWP FW Owner         : Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team             : PM
// *HWP Level            : 2
// *HWP Consumed by      : HS

///
/// High-level procedure flow:
///
/// @verbatim
///
///  PM_INIT
///    Initialize Cores and Quads
///    Initialize OCB channels
///    Initialize PSS
///    Initialize PBA
///    Mask CME FIRs and Core-Quad Errors
///    Initialize Stop GPE
///    Initialize Pstate GPE
///    Start OCC PPC405
///    Clear off pending Special Wakeup requests on all configured EX chiplets
///
///  PM_RESET
///    Invoke "p9_pm_reset()" to reset the PM OCC complex (Cores, Quads, CMEs,
///    OCB channels, PBA bus, PSS, PPC405 and GPEs)
///
/// @endverbatim
///

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p9_pm_init.H>

// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------

///
/// @brief Call underlying unit procedures to initialize the PM complex.
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error code.
///
fapi2::ReturnCode pm_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

///
/// @brief Clears OCC special wake-up on all configured EX chiplets
///
/// @param[in] i_target   Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error code.
///
fapi2::ReturnCode clear_occ_special_wakeups(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

// -----------------------------------------------------------------------------
// Function definitions
// -----------------------------------------------------------------------------

fapi2::ReturnCode p9_pm_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::PM_FLOW_MODE i_mode)
{
    FAPI_INF("Entering p9_pm_init ...");

    fapi2::ReturnCode l_rc;

    if (i_mode == p9pm::PM_INIT)
    {
        FAPI_DBG("Initialize the OCC Complex.");
        FAPI_TRY(pm_init(i_target),
                 "ERROR: Failed to initialize OCC Complex");
    }
    else if (i_mode == p9pm::PM_RESET)
    {
        FAPI_DBG("Reset the OCC Complex.");
        FAPI_EXEC_HWP(l_rc, p9_pm_reset, i_target);
        FAPI_TRY(l_rc, "ERROR: Failed to reset OCC complex");
    }
    else
    {
        FAPI_ASSERT(false, fapi2::PM_INIT_BAD_MODE().set_BADMODE(i_mode),
                    "ERROR; Unknown mode passed to p9_pm_init. Mode %x",
                    i_mode);
    }

fapi_try_exit:
    FAPI_INF("Exiting p9_pm_init...");
    return fapi2::current_err;
}

fapi2::ReturnCode pm_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF("Entering pm_init...");

    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_data64;

    //  ************************************************************************
    //  Initialize Cores and Quads
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_corequad_init to initialize cores & quads");
    FAPI_EXEC_HWP(l_rc, p9_pm_corequad_init,
                  i_target,
                  p9pm::PM_INIT,
                  0,//CME FIR MASK for reset
                  0,//Core Error Mask for reset
                  0 //Quad Error Mask for reset
                 );
    FAPI_TRY(l_rc, "ERROR: Failed to initialize cores & quads");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After cores & quads init"));

    //  ************************************************************************
    //  Issue init to OCB
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_ocb_init to initialize OCB channels");
    FAPI_EXEC_HWP(l_rc, p9_pm_ocb_init,
                  i_target,
                  p9pm::PM_INIT,// Channel setup type
                  p9ocb::OCB_CHAN1,// Channel
                  p9ocb:: OCB_TYPE_NULL,// Channel type
                  0,// Channel base address
                  0,// Push/Pull queue length
                  p9ocb::OCB_Q_OUFLOW_NULL,// Channel flow control
                  p9ocb::OCB_Q_ITPTYPE_NULL// Channel interrupt control
                 );
    FAPI_TRY(l_rc,
             "ERROR: Failed to initialize channel 1");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After OCB channels init"));

    //  ************************************************************************
    //  Initializes P2S and HWC logic
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_pss_init to initialize P2S and HWC logic");
    FAPI_EXEC_HWP(l_rc, p9_pm_pss_init, i_target, p9pm::PM_INIT);
    FAPI_TRY(l_rc, "ERROR: Failed to initialize PSS & HWC");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After PSS & HWC init"));

    //  ************************************************************************
    //  Initializes PBA
    //  Note:  This voids the channel used by the GPEs
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_pba_init to initialize PBA");
    FAPI_EXEC_HWP(l_rc, p9_pm_pba_init, i_target, p9pm::PM_INIT);
    FAPI_TRY(l_rc, "ERROR: Failed to initialize PBA BUS");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After PBA bus init"));

    //  ************************************************************************
    //  Mask the FIRs as errors can occur in what follows
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_firinit to mask errors/FIRs");
    FAPI_EXEC_HWP(l_rc, p9_pm_firinit, i_target, p9pm::PM_INIT);
    FAPI_TRY(l_rc, "ERROR: Failed to mask OCC,PBA & CME FIRs/Errors.");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After masking FIRs and Errors"));

    //  ************************************************************************
    //  Initialize the STOP GPE Engine
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_stop_gpe_init to initialize SGPE");
    FAPI_EXEC_HWP(l_rc, p9_pm_stop_gpe_init, i_target, p9pm::PM_INIT);
    FAPI_TRY(l_rc, "ERROR: Failed to initialize SGPE");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After SGPE initialization"));

    // ************************************************************************
    // Switch off OCC initiated special wakeup on EX to allowSTOP functionality
    // ************************************************************************
    FAPI_DBG("Clear off the wakeup");
    FAPI_TRY(clear_occ_special_wakeups(i_target),
             "ERROR: Failed to clear off the wakeup");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "EX targets off special wakeup"));

    //  ************************************************************************
    //  Initialize the PSTATE GPE Engine
    //  ************************************************************************
    /* TODO: RTC 157096: Enable pstate GPE initialization in PM_INIT phase
    FAPI_DBG("Executing p9_pm_pstate_gpe_init to initialize PGPE");
    FAPI_EXEC_HWP(l_rc, p9_pm_pstate_gpe_init, i_target, p9pm::PM_INIT);
    FAPI_TRY(l_rc, "ERROR: Failed to initialize PGPE");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After PGPE initialization"));
    */

    // Clear the OCC's PIB I2C engine locks.
    // All other OCC owned flag bits are retained.
    l_data64.setBit<17>().setBit<19>().setBit<21>();
    FAPI_TRY(fapi2::putScom(i_target, PU_OCB_OCI_OCCFLG_SCOM1, l_data64),
             "ERROR: Failed to write to OCC FLAG");


    //  ************************************************************************
    //  Start OCC PPC405
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_occ_control to start OCC PPC405");
    FAPI_EXEC_HWP(l_rc, p9_pm_occ_control, i_target,
                  p9occ_ctrl::PPC405_START,// Operation on PPC405
                  p9occ_ctrl::PPC405_BOOT_MEM // PPC405 boot location
                 );
    FAPI_TRY(l_rc, "ERROR: Failed to initialize OCC PPC405");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After OCC PPC405 init"));

fapi_try_exit:

    return fapi2::current_err;

}

fapi2::ReturnCode clear_occ_special_wakeups(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF("Entering clear_occ_special_wakeups...");
    fapi2::buffer<uint64_t> l_data64;

    auto l_exChiplets = i_target.getChildren<fapi2::TARGET_TYPE_EX>
                        (fapi2::TARGET_STATE_FUNCTIONAL);

    FAPI_DBG("No. of functional EX chiplets: %u ", l_exChiplets.size());

    // Iterate through the EX chiplets
    for (auto l_ex_chplt : l_exChiplets)
    {
        FAPI_DBG("Clear OCC special wakeup on ex chiplet 0x%08X", l_ex_chplt);
        FAPI_TRY(fapi2::getScom(i_target, EX_PPM_SPWKUP_OCC, l_data64),
                 "ERROR: Failed to read OCC Spl wkup on EX 0x%08X", l_ex_chplt);
        l_data64.clearBit<0>();
        FAPI_TRY(fapi2::putScom(i_target, EX_PPM_SPWKUP_OCC, l_data64),
                 "ERROR: Failed to clear OCC Spl wkup on EX 0x%08X", l_ex_chplt);
    }

fapi_try_exit:
    return fapi2::current_err;
}

