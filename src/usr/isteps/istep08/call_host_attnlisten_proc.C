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
#include <initservice/istepdispatcherif.H>
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

/**
 * @brief  Send a list of functional procs that ATTN can start monitoring
 *         for checkstop analysis
 */
void send_analyzable_procs(void)
{
    errlHndl_t l_err = nullptr;
    std::vector<TARGETING::ATTR_HUID_type> l_chipHuids;

    // get all functional Proc targets
    TARGETING::TargetHandleList l_procsList;
    getAllChips(l_procsList, TYPE_PROC);

    // now fill in the list with proc huids
    for (const auto & l_cpu_target : l_procsList)
    {
        l_chipHuids.push_back(TARGETING::get_huid(l_cpu_target));
    }

    // send the message to alert ATTN to start monitoring these chips
    l_err = INITSERVICE::sendAttnMonitorChipIdMsg(l_chipHuids);
    if (l_err)
    {
        errlCommit(l_err, ISTEP_COMP_ID);
    }
}


//******************************************************************************
// call_host_attnlisten_proc()
//******************************************************************************
void* call_host_attnlisten_proc(void *io_pArgs)
{
    IStepError  l_stepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_attnlisten_proc entry" );

    // Function is a NOOP because with security enabled, PRD is unable
    // to write FIRs due to blacklist violations.  All of the slave
    // processor attentions will be ignored until the SMP comes up.

    // Send list of functional procs that ATTN
    // can start monitoring for checkstop analysis
    if( INITSERVICE::spBaseServicesEnabled() )
    {
        send_analyzable_procs();
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
             "call_host_attnlisten_proc exit" );
    return l_stepError.getErrorHandle();
}

};
