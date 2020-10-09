/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/call_host_secureboot_lockdown.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
   @file call_host_secureboot_lockdown.C
 *
 *  Support file for IStep: host_secureboot_lockdown
 *    This istep will do these things:
 *      1) Check for TPM policies are valid
 *      2) Check for secureboot consistency between procs
 *      3) Set the SUL security bit so that SBE image cannot be updated
 *      4) Ensure that the SAB security bit is read only
 *      5) If a TPM is non functional, set the TDP (TPM Deconfig Protection)
 *         to prevent attack vector
 *      6) Check for a reason, such as a Key Clear Request, to re-IPL the
 *         system so the system owner can assert physical presence
 *
 */

// For istep and error logging support
#include <isteps/hwpisteperror.H>
#include <isteps/istep_reasoncodes.H>
#include <initservice/initserviceif.H>
#include <istepHelperFuncs.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>


// For Secureboot, Trustedboot support
#include <secureboot/service.H>
#include <secureboot/phys_presence_if.H>

// Secureboot lockdown HWP
#include <plat_hwp_invoker.H>
#include <p10_update_security_ctrl.H>

namespace ISTEP_10
{

void* call_host_secureboot_lockdown (void *io_pArgs)
{
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                ENTER_MRK"call_host_secureboot_lockdown");

    ISTEP_ERROR::IStepError l_istepError;
#ifndef CONFIG_VPO_COMPILE
    errlHndl_t l_err = nullptr;
#endif

    do {
#ifdef CONFIG_SECUREBOOT
    if(SECUREBOOT::enabled())
    {
        TARGETING::TargetHandleList l_procList;
        getAllChips(l_procList,TARGETING::TYPE_PROC);

        for(const auto& l_proc : l_procList)
        {
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapiProc(l_proc);
            const bool DO_NOT_FORCE_SECURITY = false; // No need to force security
            const bool DO_NOT_LOCK_ABUS_MAILBOXES = false; // Do not lock abus mailboxes
            FAPI_INVOKE_HWP(l_err,
                            p10_update_security_ctrl,
                            l_fapiProc,
                            DO_NOT_FORCE_SECURITY,
                            DO_NOT_LOCK_ABUS_MAILBOXES);
            if(l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "call_host_secureboot_lockdown: p10_update_security_ctrl failed for Proc HUID 0x%08x "
                          TRACE_ERR_FMT, TARGETING::get_huid(l_proc),
                          TRACE_ERR_ARGS(l_err));
                l_istepError.addErrorDetails(l_err);
                ERRORLOG::errlCommit(l_err, ISTEP_COMP_ID);
                // Try to run the HWP on all procs regardless of error.
            }
        }
    }
    if(l_istepError.getErrorHandle())
    {
        break;
    }
#endif

#ifdef CONFIG_PHYS_PRES_PWR_BUTTON
    // Check to see if a Physical Presence Window should be opened,
    // and if so, open it.  This could result in the system being shutdown
    // to allow the system administrator to assert physical presence
    l_err = SECUREBOOT::handlePhysPresenceWindow();
    if (l_err)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "call_host_secureboot_lockdown: Error back from "
                   "SECUREBOOT::handlePhysPresence: "
                   TRACE_ERR_FMT,
                   TRACE_ERR_ARGS(l_err));
        l_istepError.addErrorDetails(l_err);
        ERRORLOG::errlCommit(l_err, ISTEP_COMP_ID);
        break;
    }
#endif
    }while(0);

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                EXIT_MRK"call_host_secureboot_lockdown");

    return l_istepError.getErrorHandle();
}

};
