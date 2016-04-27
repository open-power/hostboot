/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep13/call_host_disable_memvolt.C $          */
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
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include "platform_vddr.H"

using   namespace   ERRORLOG;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;

namespace ISTEP_13
{

void* call_host_disable_memvolt (void *io_pArgs)
{
    errlHndl_t l_err = NULL;
    IStepError l_StepError;

    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              ENTER_MRK"call_host_disable_memvolt");

    // This function has Compile-time binding for desired platform
    l_err = platform_disable_vddr();

    if(l_err)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR 0x%.8X: call_host_disable_memvolt returns error",
                  l_err->reasonCode());
        // Create IStep error log and cross reference to error that occurred
        l_StepError.addErrorDetails( l_err );

        errlCommit( l_err, HWPF_COMP_ID );

    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               EXIT_MRK"call_host_disable_memvolt");

    return l_StepError.getErrorHandle();
}

};
