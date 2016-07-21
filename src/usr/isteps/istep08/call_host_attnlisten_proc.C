/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_host_attnlisten_proc.C $          */
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
/**
 *  @file call_host_attnlisten_proc.C
 *
 *  Support file for IStep: host_attnlisten_proc
 *
 *  HWP_IGNORE_VERSION_CHECK
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <trace/interface.H>
#include <initservice/taskargs.H>
#include <errl/errlentry.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>
#include <initservice/initsvcreasoncodes.H>
#include <sys/time.h>
#include <devicefw/userif.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/namedtarget.H>
#include <targeting/attrsync.H>

#include <isteps/hwpisteperror.H>

#include <errl/errludtarget.H>
#include <errl/errlmanager.H>

using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

namespace ISTEP_08
{

//******************************************************************************
// call_host_attnlisten_proc()
//******************************************************************************
void* call_host_attnlisten_proc(void *io_pArgs)
{
    IStepError  l_stepError;


    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_attnlisten_proc entry" );

    uint8_t    l_useAllProcs = 1;
    TARGETING::Target  *l_sys = NULL;
    TARGETING::targetService().getTopLevelTarget( l_sys );
    assert(l_sys != NULL);

    // All we need to do is set a flag so that the
    // ATTN code will check ALL processors the next
    // time it gets called versus just the master proc.
    l_sys->trySetAttr<ATTR_ATTN_CHK_ALL_PROCS>(l_useAllProcs);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
             "call_host_attnlisten_proc exit" );
    return l_stepError.getErrorHandle();
}

};
