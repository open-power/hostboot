/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep21/call_host_verify_hdat.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
#include <initservice/isteps_trace.H>
#include <isteps/hwpisteperror.H>
#include <hwpf/istepreasoncodes.H>
#include <initservice/initserviceif.H>
#include <initservice/istepdispatcherif.H>

#include <hbotcompid.H>

using namespace ERRORLOG;
using namespace ISTEP;
using namespace ISTEP_ERROR;

namespace ISTEP_21
{
void* call_host_verify_hdat (void *io_pArgs)
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_verify_hdat entry" );

    errlHndl_t l_err = NULL;

    // Host Start Payload procedure, per documentation from Patrick.
    //  - Verify target image
    //      - TODO - Done via call to Secure Boot ROM.
    //      - Will be done in future sprints

    // stub for now..

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_verify_hdat exit" );

    return l_err;
}

};
