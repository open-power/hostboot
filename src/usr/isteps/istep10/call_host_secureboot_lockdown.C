/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/call_host_secureboot_lockdown.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
#include <secureboot/service_ext.H>
#include <secureboot/trustedbootif.H>

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

    do {

    // Attempt to initialize the backup TPM.
    TRUSTEDBOOT::initBackupTpm();

    // Always poison the backup TPM because we want to ensure
    // it varies from the primary.
    l_err = TRUSTEDBOOT::poisonBackupTpm();

    if(l_err)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "call_host_secureboot_lockdown: poisonBackupTpm returned an error"
                  TRACE_ERR_FMT,
                  TRACE_ERR_ARGS(l_err));
        l_istepError.addErrorDetails(l_err);
        TARGETING::Target * backup_tpm = nullptr;
        TRUSTEDBOOT::getBackupTpm(backup_tpm);
        assert(backup_tpm != nullptr, "call_host_secureboot_lockdown: poisonBackupTpm returned an error when no backup tpm available");
        // tpmMarkFailed will ensure there is at minimum a deconfig callout for the backup
        // TPM and also set the deconfig bit to force fencing if security is enabled
        TRUSTEDBOOT::tpmMarkFailed(backup_tpm, l_err);
    }

#ifdef CONFIG_SECUREBOOT

    if(SECUREBOOT::enabled())
    {
        TARGETING::TargetHandleList l_procList;
        TARGETING::TargetHandleList l_tpmList;

        getAllChips(l_procList,TARGETING::TYPE_PROC);
        getAllChips(l_tpmList,TARGETING::TYPE_TPM,false);

        for(const auto& l_proc : l_procList)
        {

            bool l_notInMrw = true;
            // check if processor has a TPM according to the mrw
            // for each TPM in the list compare SPI master path with
            // the path of the current processor
            for (auto itpm : l_tpmList)
            {
                auto l_physPath = l_proc->getAttr<TARGETING::ATTR_PHYS_PATH>();

                auto l_tpmInfo = itpm->getAttr<TARGETING::ATTR_SPI_TPM_INFO>();

                if (l_tpmInfo.spiMasterPath == l_physPath)
                {
                    l_notInMrw = false;
                    break;
                }
            }
            if (l_notInMrw)
            {
                uint8_t l_protectTpm = 1;
                l_proc->setAttr<
                    TARGETING::ATTR_SECUREBOOT_PROTECT_DECONFIGURED_TPM
                                                                    >(l_protectTpm);
            }

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

    SECUREBOOT::validateSecuritySettings();

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

#endif // CONFIG_VPO_COMPILE

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                EXIT_MRK"call_host_secureboot_lockdown");

    return l_istepError.getErrorHandle();
}

};
