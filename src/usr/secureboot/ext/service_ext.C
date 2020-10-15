/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/ext/service_ext.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
#include <secureboot/service_ext.H>
#include <targeting/common/util.H>
#include <targeting/common/target.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <secureboot/secure_reasoncodes.H>

#include "../common/securetrace.H"

#include <fapi2.H>
#include <fapi2/plat_hwp_invoker.H>

#include <p10_update_security_ctrl.H>

namespace SECUREBOOT
{

void lockAbusSecMailboxes()
{
#ifdef CONFIG_TPMDD
    errlHndl_t l_errl = nullptr;
    TARGETING::TargetHandleList l_procs;
    getAllChips(l_procs, TARGETING::TYPE_PROC, true);

    auto l_pProc = l_procs.begin();
    while(l_pProc != l_procs.end())
    {
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapiProc(*l_pProc);
        FAPI_INVOKE_HWP(l_errl,
                        p10_update_security_ctrl,
                        l_fapiProc,
                        false, // do not force security
                        true); // lock down Abus mailboxes

        if(l_errl)
        {
            SB_ERR("lockAbusSecMailboxes: p10_update_security_ctrl failed for"
                   " proc 0x%X!. Deconfiguring the proc.",
                   TARGETING::get_huid(*l_pProc));

            auto l_plid = l_errl->plid();

            ERRORLOG::ErrlUserDetailsTarget(*l_pProc).addToLog(l_errl);
            ERRORLOG::errlCommit(l_errl, SECURE_COMP_ID);

            /*
             * @errortype
             * @reasoncode RC_LOCK_MAILBOXES_FAILED
             * @moduleid   MOD_LOCK_ABUS_SEC_MAILBOXES
             * @userdata1  Target HUID
             * @devdesc    Failed to lock Abus secure mailboxes
             *             on target processor.
             * @custdesc   Secure Boot failure
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            SECUREBOOT::MOD_LOCK_ABUS_SEC_MAILBOXES,
                            SECUREBOOT::RC_LOCK_MAILBOXES_FAILED,
                            TARGETING::get_huid(*l_pProc),
                            0,
                            true);
            l_errl->addHwCallout(*l_pProc,
                                 HWAS::SRCI_PRIORITY_LOW,
                                 HWAS::DELAYED_DECONFIG,
                                 HWAS::GARD_NULL);
            l_errl->collectTrace(SECURE_COMP_NAME);
            l_errl->collectTrace(FAPI_TRACE_NAME);
            l_errl->plid(l_plid);
            ERRORLOG::ErrlUserDetailsTarget(*l_pProc).addToLog(l_errl);

            ERRORLOG::errlCommit(l_errl, SECURE_COMP_ID);
        }

        ++l_pProc;

    } // while
#endif
}

} // namespace SECUREBOOT
