/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/call_host_update_primary_tpm.C $       */
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
#include <stdint.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <isteps/hwpisteperror.H>
#include <trustedbootif.H>
#include <initservice/isteps_trace.H>
#include <secureboot/service.H>
#include <secureboot/phys_presence_if.H>
#include <config.h>
#include <targeting/targplatutil.H>

namespace ISTEP_06
{

void* call_host_update_primary_tpm( void *io_pArgs )
{
    using namespace TARGETING;
    ISTEP_ERROR::IStepError l_stepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_update_primary_tpm entry" );

    errlHndl_t l_err = nullptr;

    (void)SECUREBOOT::logPlatformSecurityConfiguration();


    // Set Minimum Secure Version Attribute
    // -- safe to do here because targeting is definitely up at this point
    // -- NOTE: API asserts if there's any issues returning the node target
    Target* node_tgt = TARGETING::UTIL::getCurrentNodeTarget();
    node_tgt->setAttr<ATTR_SECURE_VERSION_SEEPROM>(SECUREBOOT::getMinimumSecureVersion());


#ifdef CONFIG_TPMDD
    // Initialize the master TPM
    l_err = (errlHndl_t)TRUSTEDBOOT::host_update_primary_tpm(io_pArgs);
    if (l_err)
    {
        l_stepError.addErrorDetails(l_err);
        ERRORLOG::errlCommit( l_err, TRBOOT_COMP_ID );
    }
#endif

    l_err = SECUREBOOT::traceSecuritySettings(true);
    if (l_err)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "call_host_update_primary_tpm: Error back from "
                   "SECUREBOOT::traceSecuritySettings: rc=0x%X, plid=0x%X",
                   ERRL_GETRC_SAFE(l_err), ERRL_GETPLID_SAFE(l_err));
        l_stepError.addErrorDetails(l_err);
        ERRORLOG::errlCommit( l_err, SECURE_COMP_ID );
    }

    // Check for Physical Presence
#ifdef CONFIG_PHYS_PRES_PWR_BUTTON
    l_err = SECUREBOOT::detectPhysPresence();
    if (l_err)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "call_host_update_primary_tpm: Error back from "
                   "SECUREBOOT::detectPhysPresence: "
                   TRACE_ERR_FMT,
                   TRACE_ERR_ARGS(l_err));
        l_stepError.addErrorDetails(l_err);
        ERRORLOG::errlCommit( l_err, SECURE_COMP_ID );
    }
#endif

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_update_primary_tpm exit" );
    return l_stepError.getErrorHandle();


}

};
