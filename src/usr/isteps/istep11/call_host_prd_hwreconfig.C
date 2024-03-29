/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep11/call_host_prd_hwreconfig.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
 *  @file call_host_prd_hwreconfig.C
 *
 *  Support file for IStep: host_prd_hwreconfig
 *    Hook to handle HW reconfig
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

//  Error handling support
#include <errl/errlentry.H>             // errlHndl_t
#include <errl/errlmanager.H>
#include <isteps/hwpisteperror.H>       // IStepError
#include <istepHelperFuncs.H>           // captureError

//  Tracing support
#include <initservice/isteps_trace.H>   // g_trac_isteps_trace

using namespace ISTEPS_TRACE;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;

namespace ISTEP_11
{
void* call_host_prd_hwreconfig (void *io_pArgs)
{
    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"call_host_prd_hwreconfig");

    IStepError l_StepError;

    // TODO RTC:208835 P10 -- Reconfig loop
    // p10_enable_reconfig.C (MCS, OMI)

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_host_prd_hwreconfig");
    return l_StepError.getErrorHandle();
}

};
