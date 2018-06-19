/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep11/call_host_prd_hwreconfig.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
#include <isteps/hwpisteperror.H>
#include <pnor/pnorif.H>
#include <config.h>
#include <initservice/isteps_trace.H>

using namespace ERRORLOG;

namespace ISTEP_11
{
void* call_host_prd_hwreconfig (void *io_pArgs)
{
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ENTER_MRK"call_host_prd_hwreconfig");

    errlHndl_t l_err = NULL;
    ISTEP_ERROR::IStepError l_StepError;
    //@TODO-RTC:158411 call p9_enable_reconfig.C


#ifdef CONFIG_SECUREBOOT
    // Load the MEMD section here as the first part of step11, it
    //  will stay loaded until the end of step14
    l_err = loadSecureSection(PNOR::MEMD);
    if( l_err )
    {
        l_StepError.addErrorDetails(l_err);
        ERRORLOG::errlCommit(l_err, HWPF_COMP_ID);
    }
#endif

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, EXIT_MRK"call_host_prd_hwreconfig");
    return l_StepError.getErrorHandle();
}

};
