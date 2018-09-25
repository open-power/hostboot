/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_host_attnlisten_memb.C $          */
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
#include    <errl/errlentry.H>

#include    <initservice/isteps_trace.H>
#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>
#include    <errl/errlmanager.H>

//  targeting support.
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

// to send chipId list for ATTN monitoring
#include    <initservice/istepdispatcherif.H>
#include    <initservice/initserviceif.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;


namespace ISTEP_12
{
/**
 * @brief  Send a list of functional procs and centaurs that ATTN
 *         can start monitoring for checkstop analysis
 */
void send_analyzable_procs_and_centaurs()
{
    errlHndl_t l_err = nullptr;
    std::vector<TARGETING::ATTR_HUID_type> l_chipHuids;

    // Get all functional Centaur targets
    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    // Get all functional Proc targets
    TARGETING::TargetHandleList l_procsList;
    getAllChips(l_procsList, TYPE_PROC);

    // now fill in the list with proc huids
    for (const auto & l_cpu_target : l_procsList)
    {
        l_chipHuids.push_back(TARGETING::get_huid(l_cpu_target));
    }

    // now fill in the list with Centaur huids
    for (const auto & l_membuf_target : l_membufTargetList)
    {
        l_chipHuids.push_back(TARGETING::get_huid(l_membuf_target));
    }

    // send the message to alert ATTN to start monitoring these chips
    l_err = INITSERVICE::sendAttnMonitorChipIdMsg(l_chipHuids);
    if (l_err)
    {
        errlCommit(l_err, ISTEP_COMP_ID);
    }
}

void* call_host_attnlisten_memb (void *io_pArgs)
{
    IStepError l_StepError;

    // Send list of functional procs and centaurs that ATTN
    // can start monitoring for checkstop analysis
    if( INITSERVICE::spBaseServicesEnabled() )
    {
        send_analyzable_procs_and_centaurs();
    }

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
