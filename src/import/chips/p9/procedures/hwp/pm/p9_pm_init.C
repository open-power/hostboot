/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_init.C $          */
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
/// @file p9_pm_init.C
/// @brief Wrapper that initializes or resets the OCC complex.
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
///  PM_INIT
///    Initialize Cores and Quads
///    Initialize OCB channels
///    Initialize PSS
///    Set the OCC FIR actions
///    Set the CME, PPM and PBA FIR actions
///    Initialize Stop GPE
///    Initialize Pstate GPE
///    Clear off pending Special Wakeup requests on all configured EX chiplets
///    Disable special wakeup of all the EX chiplets
///    Start OCC PPC405
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
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    void* i_pHomerImage);

// -----------------------------------------------------------------------------
// Function definitions
// -----------------------------------------------------------------------------

fapi2::ReturnCode p9_pm_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::PM_FLOW_MODE i_mode,
    void* i_pHomerImage = NULL)
{
    FAPI_INF("Entering p9_pm_init ...");

    fapi2::ReturnCode l_rc;

    if (i_mode == p9pm::PM_INIT)
    {
        FAPI_DBG("Initialize the OCC Complex.");
        FAPI_TRY(pm_init(i_target, i_pHomerImage),
                 "ERROR: Failed to initialize OCC Complex");
    }
    else if (i_mode == p9pm::PM_RESET)
    {
        FAPI_DBG("Reset the OCC Complex.");
        FAPI_EXEC_HWP(l_rc, p9_pm_reset, i_target, i_pHomerImage);
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
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    void* i_pHomerImage)
{
    FAPI_INF("Entering pm_init...");

    fapi2::ReturnCode l_rc;

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
    //  Set the OCC FIR actions
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_occ_firinit to set FIR actions.");
    FAPI_EXEC_HWP(l_rc, p9_pm_occ_firinit, i_target, p9pm::PM_INIT);
    FAPI_TRY(l_rc, "ERROR: Failed to set OCC FIR actions.");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After setting FIRs"));

    //  ************************************************************************
    //  Set the FIR actions
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_firinit to set PBA, PPM, CME FIR actions");
    FAPI_EXEC_HWP(l_rc, p9_pm_firinit, i_target, p9pm::PM_INIT);
    FAPI_TRY(l_rc, "ERROR: Failed to set PPM, PBA & CME FIRs.");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After setting FIRs"));

    //  ************************************************************************
    //  Initialize the STOP GPE Engine
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_stop_gpe_init to initialize SGPE");
    FAPI_EXEC_HWP(l_rc, p9_pm_stop_gpe_init, i_target, p9pm::PM_INIT);
    FAPI_TRY(l_rc, "ERROR: Failed to initialize SGPE");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After SGPE initialization"));

    //  ************************************************************************
    //  Initialize the PSTATE GPE Engine
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_pstate_gpe_init to initialize PGPE");
    FAPI_EXEC_HWP(l_rc, p9_pm_pstate_gpe_init, i_target, p9pm::PM_INIT);
    FAPI_TRY(l_rc, "ERROR: Failed to initialize PGPE");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After PGPE initialization"));

    //  ************************************************************************
    //  Set up the configuration content in HOMER for the 24x7 function
    //  ************************************************************************
    if (i_pHomerImage != NULL)
    {
        FAPI_DBG("Executing p9_check_proc_config to create configuration settings for 24x7");
        FAPI_EXEC_HWP(l_rc, p9_check_proc_config, i_target, i_pHomerImage);
        FAPI_TRY(l_rc, "ERROR: Failed to initialize 24x7 configuration");
    }

    // ************************************************************************
    // Switch off OCC initiated special wakeup on EX to allowSTOP functionality
    // ************************************************************************
    FAPI_DBG("Clearing OCC special wake-up to be sure");
    FAPI_TRY(clear_occ_special_wakeups(i_target),
             "ERROR: Failed to clear off the wakeup");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "EX targets OCC clear special wakeup"));

    //  ************************************************************************
    //  Take all EX chiplets out of special wakeup
    //  ************************************************************************
    FAPI_DBG("Disable special wakeup for all functional  EX targets.");
    FAPI_TRY(special_wakeup_all(i_target,
                                false),//Disable splwkup
             "ERROR: Failed to remove EX chiplets from special wakeup");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After EX out of special wakeup"));

    //  ************************************************************************
    //  Start OCC PPC405
    //  ************************************************************************
    FAPI_DBG("Executing p9_pm_occ_control to start OCC PPC405");
    FAPI_EXEC_HWP(l_rc, p9_pm_occ_control, i_target,
                  p9occ_ctrl::PPC405_START,// Operation on PPC405
                  p9occ_ctrl::PPC405_BOOT_MEM, // PPC405 boot location
                  0 //Jump to 405 main instruction - not used here
                 );
    FAPI_TRY(l_rc, "ERROR: Failed to initialize OCC PPC405");
    FAPI_TRY(p9_pm_glob_fir_trace(i_target, "After OCC PPC405 init"));

fapi_try_exit:

    return fapi2::current_err;

}

fapi2::ReturnCode clear_occ_special_wakeups(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG(">> clear_occ_special_wakeups...");
    fapi2::buffer<uint64_t> l_data64;

    auto l_exChiplets = i_target.getChildren<fapi2::TARGET_TYPE_EX>
                        (fapi2::TARGET_STATE_FUNCTIONAL);

    FAPI_DBG("No. of functional EX chiplets: %u ", l_exChiplets.size());

    // Iterate through the EX chiplets
    for (auto l_ex_chplt : l_exChiplets)
    {
        fapi2::ATTR_CHIP_UNIT_POS_Type l_ex_num;
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                l_ex_chplt,
                                l_ex_num));

        FAPI_DBG("Clear OCC special wakeup on ex chiplet 0x%08X", l_ex_num);
        FAPI_TRY(fapi2::getScom(i_target, EX_PPM_SPWKUP_OCC, l_data64),
                 "ERROR: Failed to read OCC Spl wkup on EX 0x%08X", l_ex_num);
        l_data64.clearBit<0>();
        FAPI_TRY(fapi2::putScom(i_target, EX_PPM_SPWKUP_OCC, l_data64),
                 "ERROR: Failed to clear OCC Spl wkup on EX 0x%08X", l_ex_num);
    }

fapi_try_exit:
    FAPI_DBG("<< clear_occ_special_wakeups...");
    return fapi2::current_err;
}

