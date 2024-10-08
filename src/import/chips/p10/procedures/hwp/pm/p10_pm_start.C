/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_start.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
/// @file p10_pm_start.C
/// @brief Wrapper that starts the PM complex.
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
///    Initialize Cores and Quads
///    Initialize OCB channels
///    Initialize PSS
///    Set the OCC FIR actions
///    Set the QME, PPM and PBA FIR actions
///    Initialize XGPE
///    Initialize Pstate GPE
///    Clear off pending Special Wakeup requests on all configured Core chiplets
///    Disable special wakeup of all the Core chiplets
///    Start OCC PPC405
///
///
/// @endverbatim
///

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p10_pm_start.H>
#include <p10_pm_hcd_flags.h>
#include <p10_core_special_wakeup.H>
#include <multicast_group_defs.H>
#include <p10_scom_proc.H>
using namespace scomt::proc;

// Function prototypes
// -----------------------------------------------------------------------------
fapi2::ReturnCode p10_pm_glob_fir_trace(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const char* i_msg);

fapi2::ReturnCode  deassertSPWU(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);
// -----------------------------------------------------------------------------
// Function definitions
// -----------------------------------------------------------------------------
fapi2::ReturnCode p10_pm_start(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    void* i_pHomerImage)
{
    FAPI_INF(">>>>>>>>> p10_pm_start...");

    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_data64;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_PM_MALF_CYCLE_Type l_malfCycle =
        fapi2::ENUM_ATTR_PM_MALF_CYCLE_INACTIVE;

    fapi2::ATTR_PM_MALF_ALERT_ENABLE_Type malfAlertEnable =
        fapi2::ENUM_ATTR_PM_MALF_ALERT_ENABLE_FALSE;
    //  ************************************************************************
    //  Issue init to OCB
    //  ************************************************************************
    FAPI_DBG("Executing p10_pm_ocb_init to start OCB channels");
    FAPI_EXEC_HWP(l_rc, p10_pm_ocb_init,
                  i_target,
                  pm::PM_START,// Channel setup type
                  ocb::OCB_CHAN1,// Channel
                  ocb:: OCB_TYPE_NULL,// Channel type
                  0,// Channel base address
                  0,// Push/Pull queue length
                  ocb::OCB_Q_OUFLOW_NULL,// Channel flow control
                  ocb::OCB_Q_ITPTYPE_NULL// Channel interrupt control
                 );
    FAPI_TRY(l_rc,
             "ERROR: Failed to start channel 1");
    FAPI_TRY(p10_pm_glob_fir_trace(i_target, "After OCB channels init"));

    //  ************************************************************************
    //  Initializes P2S and HWC logic
    //  ************************************************************************
    FAPI_DBG("Executing p10_pm_pss_init to start P2S and HWC logic");
    FAPI_EXEC_HWP(l_rc, p10_pm_pss_init, i_target, pm::PM_START);
    FAPI_TRY(l_rc, "ERROR: Failed to start PSS & HWC");
    FAPI_TRY(p10_pm_glob_fir_trace(i_target, "After PSS & HWC init"));

    //TBD:Need to check with Greg,should we initialize pba here or in XGPE
    // start procedure
#if 0
    //  ************************************************************************
    //  Initializes PBA
    //  ************************************************************************
    FAPI_DBG("Executing p10_pm_pba_init to start powerbus");
    FAPI_EXEC_HWP(l_rc, p10_pm_pba_init, i_target, pm::PM_START);
    FAPI_TRY(l_rc, "ERROR: Failed to start powerbus");
    FAPI_TRY(p10_pm_glob_fir_trace(i_target, "After powerbus init"));
#endif

    //  ************************************************************************
    //  Set the OCC FIR actions
    //  ************************************************************************
    FAPI_DBG("Executing p10_pm_occ_firinit to set FIR actions.");
    FAPI_EXEC_HWP(l_rc, p10_pm_occ_firinit, i_target, pm::PM_INIT_SOFT);
    FAPI_TRY(l_rc, "ERROR: Failed to set OCC FIR actions.");
    FAPI_TRY(p10_pm_glob_fir_trace(i_target, "After setting FIRs"));

    //  ************************************************************************
    //  Set the FIR actions
    //  ************************************************************************
    FAPI_DBG("Executing p10_pm_firinit to set PBA, PPM, QME FIR actions");
    FAPI_EXEC_HWP(l_rc, p10_pm_firinit, i_target, pm::PM_INIT_SOFT);
    FAPI_TRY(l_rc, "ERROR: Failed to set PPM, PBA & QME FIRs.");
    FAPI_TRY(p10_pm_glob_fir_trace(i_target, "After setting FIRs"));

    //  ************************************************************************
    //  Initialize the QME Engine
    //  pm::PM_START_RUNTIME => This is  for internal purpose to know we are in
    //  runtime mode, as this procedure is called only after istep 18
    //  ************************************************************************
    FAPI_DBG("Executing p10_pm_qme_init to start QME");
    FAPI_EXEC_HWP(l_rc, p10_pm_qme_init, i_target, pm::PM_START_RUNTIME);
    FAPI_TRY(l_rc, "ERROR: Failed to start QME");
    FAPI_TRY(p10_pm_glob_fir_trace(i_target, "After QME initialization"));

    //  ************************************************************************
    //  ************************************************************************
    //  Clear the special wakeup for all cores.
    //  Note:  The auto special wakeup is cleared by QME Hcode.  The
    //  STOP_OVERRIDE_MODE and STOP_ACTIVE_MASK bits are cleared by the
    //  p10_pm_qme_init(halt) procedure."
    //  ************************************************************************
    FAPI_TRY (FAPI_ATTR_GET (fapi2::ATTR_PM_MALF_CYCLE, i_target,
                             l_malfCycle));

    if (l_malfCycle == fapi2::ENUM_ATTR_PM_MALF_CYCLE_INACTIVE)
    {

        FAPI_DBG("Disable special wakeup for all functional  core targets");
        FAPI_TRY(deassertSPWU(i_target));
    }
    else
    {
        // Do not deassert wakeup's in Malf path, as we did not assert them in Reset
        // as well and reset the attribute.
        FAPI_INF("MALF Handling in progress! Skipped Disable Special Wakeup");
        l_malfCycle = fapi2::ENUM_ATTR_PM_MALF_CYCLE_INACTIVE;
        FAPI_TRY (FAPI_ATTR_SET (fapi2::ATTR_PM_MALF_CYCLE, i_target,
                                 l_malfCycle));
    }

    //  Initialize the XGPE Engine
    //  ************************************************************************
    FAPI_DBG("Executing p10_pm_xgpe_init to start XGPE");
    FAPI_EXEC_HWP(l_rc, p10_pm_xgpe_init, i_target, pm::PM_START);
    FAPI_TRY(l_rc, "ERROR: Failed to start XGPE");
    FAPI_TRY(p10_pm_glob_fir_trace(i_target, "After XGPE initialization"));

    //  ************************************************************************
    //  Initialize the PSTATE GPE Engine
    //  ************************************************************************
    FAPI_DBG("Executing p10_pm_pstate_gpe_init to start PGPE");
    FAPI_EXEC_HWP(l_rc, p10_pm_pgpe_init, i_target, pm::PM_START);
    FAPI_TRY(l_rc, "ERROR: Failed to start PGPE");
    FAPI_TRY(p10_pm_glob_fir_trace(i_target, "After PGPE initialization"));

    //  ************************************************************************
    //  Set up the configuration content in HOMER for the 24x7 function
    //  ************************************************************************
    FAPI_DBG("Executing p10_check_proc_config to create configuration settings for 24x7");
    FAPI_EXEC_HWP(l_rc, p10_check_proc_config, i_target, i_pHomerImage);
    FAPI_TRY(l_rc, "ERROR: Failed to initialize 24x7 configuration");

#ifndef __HOSTBOOT_MODULE
    fapi2::ATTR_OCC_START_DISABLE_Type l_occ_disable;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OCC_START_DISABLE,
                           FAPI_SYSTEM,
                           l_occ_disable),
             "Error from FAPI_ATTR_GET for attribute ATTR_OCC_START_DISABLE");

    if (l_occ_disable == fapi2::ENUM_ATTR_OCC_START_DISABLE_OFF)
    {
#endif
        //  ************************************************************************
        //  Start OCC PPC405
        //  ************************************************************************
        FAPI_DBG("Executing p10_pm_occ_control to start OCC PPC405");
        FAPI_EXEC_HWP(l_rc, p10_pm_occ_control, i_target,
                      occ_ctrl::PPC405_START,// Operation on PPC405
                      occ_ctrl::PPC405_BOOT_MEM, // PPC405 boot location
                      0 //Jump to 405 main instruction - not used here
                     );
        FAPI_TRY(l_rc, "ERROR: Failed to start OCC PPC405");
        FAPI_TRY(p10_pm_glob_fir_trace(i_target, "After OCC PPC405 init"));
#ifndef __HOSTBOOT_MODULE
    }

#endif

#ifdef __HOSTBOOT_MODULE
    // Only enable malfunction alert under Hostboot
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PM_MALF_ALERT_ENABLE,
                           FAPI_SYSTEM,
                           malfAlertEnable),
             "Error from FAPI_ATTR_GET for attribute ATTR_PM_MALF_ALERT_ENABLE");
    // Set the Malf Alert Enabled policy to OCCFLG2 reg bit 29
    l_data64.flush<0>().setBit<p10hcd::STOP_RECOVERY_TRIGGER_ENABLE>();
#else
    // Disable malfunction alert under Cronus
    malfAlertEnable = fapi2::ENUM_ATTR_PM_MALF_ALERT_ENABLE_FALSE;
#endif // malfunction alert

    if (malfAlertEnable ==
        fapi2::ENUM_ATTR_PM_MALF_ALERT_ENABLE_TRUE)
    {
        FAPI_TRY(fapi2::putScom(i_target,
                                TP_TPCHIP_OCC_OCI_OCB_OCCFLG3_WO_OR, l_data64));
    }
    else
    {
        FAPI_TRY(fapi2::putScom(i_target,
                                TP_TPCHIP_OCC_OCI_OCB_OCCFLG3_WO_CLEAR,
                                l_data64));
    }

    FAPI_IMP ("Malf Alert Policy Enabled: %d", malfAlertEnable);

fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode deassertSPWU(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_xsr;

    auto l_core_functional_vector =
        i_target.getChildren<fapi2::TARGET_TYPE_CORE>
        (fapi2::TARGET_STATE_FUNCTIONAL);


    FAPI_INF("Disable special wakeup for all functional Core targets");

    // Iterate through the returned chiplets.
    for (auto l_core_target : l_core_functional_vector)
    {
        FAPI_TRY( fapi2::specialWakeup (l_core_target, false),
                  "Special Wakeup Failed" );
    }

fapi_try_exit:

    FAPI_IMP("<< deassertSPWU");
    return fapi2::current_err;
}

fapi2::ReturnCode p10_pm_glob_fir_trace(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const char* i_msg)
{
    return fapi2::current_err;
}
