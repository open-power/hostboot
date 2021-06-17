/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/call_host_secure_rng.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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

/**
 * @file call_host_secure_rng.C
 *
 *  Support file for IStep: core_activate
 *   Core Activate
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

#include <stdint.h>

#include <trace/interface.H>
#include <initservice/taskargs.H>
#include <errl/errlentry.H>

#include <isteps/hwpisteperror.H>
#include <errl/errludtarget.H>
#include <errl/errlreasoncodes.H>

#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>

//  MVPD
#include <devicefw/userif.H>
#include <vpd/mvpdenums.H>

#include <fapi2/plat_hwp_invoker.H>
#include <p10_rng_init_phase2.H>
#include <p10_disable_ocmb_i2c.H>

#include <secureboot/service.H>

#include <istepHelperFuncs.H>           // captureError

#include <i2c/i2c.H>
#include <i2c/i2c_common.H>

using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

namespace ISTEP_14
{

//******************************************************************************
// wrapper function to call host_secure_rng
//******************************************************************************
void* call_host_secure_rng(void* const io_pArgs)
{

    IStepError l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_secure_rng entry" );

    errlHndl_t l_err = nullptr;

    //  get a list of all the procs in the system
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    do
    {

    // Loop through all processors including master
    for (const auto& l_cpu_target : l_cpuTargetList)
    {
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapi2_proc_target(l_cpu_target);

        // Check for functional NX
        TARGETING::TargetHandleList l_nxTargetList;
        getChildChiplets(l_nxTargetList, l_cpu_target, TYPE_NX, true);

        if (l_nxTargetList.empty())
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Running host_secure_rng; no functional NX "
                      "found for proc %.8X",
                      TARGETING::get_huid(l_cpu_target));
            continue;
        }

        FAPI_INVOKE_HWP(l_err, p10_rng_init_phase2, l_fapi2_proc_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR: call p10_rng_init_phase2, PLID=0x%x, rc=0x%.4X: "
                      TRACE_ERR_FMT,
                      l_err->plid(), l_err->reasonCode(),
                      TRACE_ERR_ARGS(l_err));

            for (const auto l_callout
                     : l_err->getUDSections(HWPF_COMP_ID,
                                            ERRORLOG::ERRL_UDT_CALLOUT))
            {
                if (reinterpret_cast<HWAS::callout_ud_t*>(l_callout)->type
                    == HWAS::HW_CALLOUT)
                {
                    for (const auto& l_nxTarget : l_nxTargetList)
                    {
                        l_err->addHwCallout(l_nxTarget,
                                            HWAS::SRCI_PRIORITY_HIGH,
                                            HWAS::DECONFIG,
                                            HWAS::GARD_NULL);
                    }
                 }
            }

            l_StepError.addErrorDetails(l_err);
            errlCommit(l_err, HWPF_COMP_ID);
        }
        else
        {
            // All good now so process OCMBs
#ifdef CONFIG_SECUREBOOT
            if(SECUREBOOT::enabled())
            {
                const bool overrideForceDisable = false; // No need to force security
                const bool overrideSULsetup = false;     // Flag for the HWP to skip the
                                                         // SUL stage OCMB lock,
                                                         // i.e. when Engine A is setup
                                                         // to block OCMB I2C reads and writes
                                                         // SUL (SEEPROM UPDATE LOCK) stage
                                                         // SUL logic in call_host_secureboot_lockdown
                const bool overrideSOLsetup = true;      // Flag for SOL stage OCMB lock
                                                         // i.e. when Engine B, C, E is setup
                                                         // to block OCMB I2C reads and writes
                                                         // SOL (Secure OCMB Lock) stage

                I2C::ocmb_data_t l_ocmb_data = {};
                // see I2C::calcOcmbPortMaskForEngine for details
                I2C::calcOcmbPortMaskForEngine(l_cpu_target, l_ocmb_data);

                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "p10_disable_ocmb_i2c HWP target HUID 0x%.8x",
                    get_huid(l_cpu_target));

                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_host_secure_rng: PIB_ENGINE DEVICE_PROTECTION_DEVADDR=0x%X "
                    "portlist_B=0x%llx portlist_C=0x%llx portlist_E=0x%llx",
                    l_ocmb_data.devAddr, l_ocmb_data.portlist_B,
                    l_ocmb_data.portlist_C, l_ocmb_data.portlist_E);

                FAPI_INVOKE_HWP(l_err, p10_disable_ocmb_i2c,
                                l_fapi2_proc_target,
                                l_ocmb_data.devAddr,       // devAddr ENGINE A
                                l_ocmb_data.devAddr,       // devAddr ENGINE B
                                l_ocmb_data.devAddr,       // devAddr ENGINE C
                                l_ocmb_data.devAddr,       // devAddr ENGINE E
                                l_ocmb_data.portlist_A,    // portlist for A
                                l_ocmb_data.portlist_B,    // portlist for B
                                l_ocmb_data.portlist_C,    // portlist for C
                                l_ocmb_data.portlist_E,    // portlist for E
                                overrideForceDisable,
                                overrideSULsetup,
                                overrideSOLsetup);

                if (l_err)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR : call_host_secure_rng: p10_disable_ocmb_i2c "
                        "failed for PROC HUID 0x%08X "
                        TRACE_ERR_FMT,
                        get_huid(l_cpu_target),
                        TRACE_ERR_ARGS(l_err));
                    // Knock out the OCMBs but allow to continue
                    TARGETING::TargetHandleList l_ocmb_list;
                    // get the functional OCMBs
                    getChildAffinityTargets(l_ocmb_list, l_cpu_target,
                                            TARGETING::CLASS_CHIP,
                                            TARGETING::TYPE_OCMB_CHIP);
                    for (const auto& l_ocmb : l_ocmb_list)
                    {
                        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                            "call_host_secure_rng: Deconfiguring OCMBs "
                            "due to HWP p10_disable_ocmb_i2c failure: "
                            "PROC HUID=0x%08X OCMB HUID=0x%08X ",
                             get_huid(l_cpu_target), get_huid(l_ocmb));
                        l_err->addHwCallout(l_ocmb,
                                            HWAS::SRCI_PRIORITY_MED,
                                            HWAS::DECONFIG,
                                            HWAS::GARD_NULL);
                    }
                    l_err->collectTrace(ISTEP_COMP_NAME);
                    errlCommit(l_err, HWPF_COMP_ID);
                }
                else // all good so set attribute to skip engine B/C diagnostic resets during MPIPL
                {
                    TARGETING::ATTR_I2C_INHIBIT_DIAGNOSTIC_RESET_ENGINE_B_type l_engine_B_inhibit =
                        l_cpu_target->getAttr<TARGETING::ATTR_I2C_INHIBIT_DIAGNOSTIC_RESET_ENGINE_B>();
                    // Log some informational traces for MPIPL flows if needed
                    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "call_host_secure_rng: DIAG MODE RESET "
                        "GET Engine B=%d", l_engine_B_inhibit);
                    l_cpu_target->setAttr<TARGETING::ATTR_I2C_INHIBIT_DIAGNOSTIC_RESET_ENGINE_B>(0x1);
                    l_engine_B_inhibit = l_cpu_target->getAttr<TARGETING::ATTR_I2C_INHIBIT_DIAGNOSTIC_RESET_ENGINE_B>();
                    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "call_host_secure_rng: DIAG MODE RESET "
                        "SET Engine B=%d", l_engine_B_inhibit);

                    TARGETING::ATTR_I2C_INHIBIT_DIAGNOSTIC_RESET_ENGINE_C_type l_engine_C_inhibit =
                        l_cpu_target->getAttr<TARGETING::ATTR_I2C_INHIBIT_DIAGNOSTIC_RESET_ENGINE_C>();
                    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "call_host_secure_rng: DIAG MODE RESET "
                        "GET Engine C=%d", l_engine_C_inhibit);
                    l_cpu_target->setAttr<TARGETING::ATTR_I2C_INHIBIT_DIAGNOSTIC_RESET_ENGINE_C>(0x1);
                    l_engine_C_inhibit = l_cpu_target->getAttr<TARGETING::ATTR_I2C_INHIBIT_DIAGNOSTIC_RESET_ENGINE_C>();
                    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "call_host_secure_rng: DIAG MODE RESET "
                        "SET Engine C=%d", l_engine_C_inhibit);
                }
            } // end SECUREBOOT::enabled
#endif
        }  // end else
    } // end of going through all processors
    } while (0);

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_host_secure_rng exit");

    return l_StepError.getErrorHandle();
} // end call_host_secure_rng

} // end namespace ISTEP_14
