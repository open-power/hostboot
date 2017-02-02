/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/call_host_update_redundant_tpm.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <isteps/istep_reasoncodes.H>

// targeting support
#include <targeting/common/target.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <errl/errludtarget.H>
#include <attributetraits.H>

#include <config.h>
#include <util/align.H>
#include <util/algorithm.H>

// Fapi Support
#include <fapi2.H>
#include <target_types.H>
#include <plat_hwp_invoker.H>
#include <attributeenums.H>
#include <istepHelperFuncs.H>

// HWP
#include <p9_update_security_ctrl.H>

// secure boot
#include <secureboot/service.H>


namespace ISTEP_10
{
void* call_host_update_redundant_tpm (void *io_pArgs)
{
    #ifdef CONFIG_SECUREBOOT
    do {

    bool l_force = false;

    if (!SECUREBOOT::enabled() && !l_force)
    {
        break;
    }

    // call p9_update_security_ctrl.C HWP
    TARGETING::TargetHandleList l_procList;
    getAllChips(l_procList,TARGETING::TYPE_PROC,true);

    TARGETING::TargetHandleList l_tpmList;
    getAllChips(l_tpmList,TARGETING::TYPE_TPM,false);

    // for each processor in list
    for(auto pProc : l_procList)
    {
        bool l_notInMrw = true;
        TARGETING::Target* l_tpm = nullptr;

        // check if processor has a TPM according to the mrw

        // for each TPM in the list compare i2c master path with
        // the path of the current processor
        for (auto itpm : l_tpmList)
        {
            auto l_physPath = pProc->getAttr<TARGETING::ATTR_PHYS_PATH>();

            auto l_tpmInfo = itpm->getAttr<TARGETING::ATTR_TPM_INFO>();

            if (l_tpmInfo.i2cMasterPath == l_physPath)
            {
                l_notInMrw = false;
                l_tpm = itpm;
                break;
            }
        }

        if (l_notInMrw)
        {
            uint8_t l_protectTpm = 1;
            pProc->setAttr<TARGETING::ATTR_SECUREBOOT_PROTECT_DECONFIGURED_TPM
                >(l_protectTpm);
        }

        errlHndl_t err = nullptr;

        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapiTarg(pProc);

        FAPI_INVOKE_HWP(err, p9_update_security_ctrl, l_fapiTarg);

        if (err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                ERR_MRK"call_host_update_redundant_tpm - "
                "p9_update_security_ctrl failed for processor tgt=0x%X, "
                "TPM tgt=0x%X. Deconfiguring processor because future "
                "security cannot be guaranteed.",
                TARGETING::get_huid(pProc),
                TARGETING::get_huid(l_tpm));

            // save the plid from the error before commiting
            auto plid = err->plid();

            ERRORLOG::ErrlUserDetailsTarget(pProc).addToLog(err);

            // commit this error log first before creating the new one
            ERRORLOG::errlCommit(err, ISTEP_COMP_ID);

            /*@
             * @errortype
             * @reasoncode       ISTEP::RC_UPDATE_SECURITY_CTRL_HWP_FAIL
             * @moduleid         ISTEP::MOD_UPDATE_REDUNDANT_TPM
             * @severity         ERRL_SEV_UNRECOVERABLE
             * @userdata1        Processor Target
             * @userdata2        TPM Target
             * @devdesc          Failed to set SEEPROM lock and/or TPM deconfig
             *                   protection for this processor, so we cannot
             *                   guarrantee platform secuirty for this processor
             * @custdesc         Platform security problem detected
            */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                ISTEP::MOD_UPDATE_REDUNDANT_TPM,
                ISTEP::RC_UPDATE_SECURITY_CTRL_HWP_FAIL,
                TARGETING::get_huid(pProc),
                TARGETING::get_huid(l_tpm),
                true);

            err->addHwCallout(pProc,
                            HWAS::SRCI_PRIORITY_LOW,
                            HWAS::DELAYED_DECONFIG,
                            HWAS::GARD_NULL);

            err->collectTrace(ISTEP_COMP_NAME);

            // pass on the plid from the previous error log to the new one
            err->plid(plid);

            ERRORLOG::ErrlUserDetailsTarget(pProc).addToLog(err);

            ERRORLOG::errlCommit(err, ISTEP_COMP_ID);

            // we don't break here. we need to continue on to the next
            // processor and run the HWP on that one
        }
    }

    } while(0);

    #endif // CONFIG_SECUREBOOT

    return nullptr;
}

};
