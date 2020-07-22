/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_host_attnlisten_proc.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
 */

/******************************************************************************/
// Includes
/******************************************************************************/

#include <hbotcompid.H>           // HWPF_COMP_ID
#include <attributeenums.H>       // TYPE_PROC
#include <isteps/hwpisteperror.H> //ISTEP_ERROR:IStepError
#include <istepHelperFuncs.H>     // captureError
#include <initservice/istepdispatcherif.H> // INITSERVICE
#include <initservice/initserviceif.H>
#include <fapi2/plat_hwp_invoker.H>
#include <diag/attn/attn.H>

using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ISTEPS_TRACE;
using namespace TARGETING;
using namespace INITSERVICE;

namespace ISTEP_08
{

/**
 * @brief  Send a list of functional procs that ATTN can start monitoring
 *         for checkstop analysis
 */
void send_analyzable_procs(void)
{
    errlHndl_t l_err = nullptr;
    std::vector<ATTR_HUID_type> l_chipHuids;

    // get all functional Proc targets
    TargetHandleList l_procsList;
    getAllChips(l_procsList, TYPE_PROC);


    if(spBaseServicesEnabled())
    {
        // now fill in the list with proc huids
        for (const auto & l_cpu_target : l_procsList)
        {
            l_chipHuids.push_back(get_huid(l_cpu_target));
        }

        // send the message to alert ATTN to start monitoring these chips
        l_err = sendAttnMonitorChipIdMsg(l_chipHuids);
        if (l_err)
        {
            errlCommit(l_err, ISTEP_COMP_ID);
        }
    }
    else
    {
        // not FSP, so set the TRUEMASK reg via hostboot code
        // (FSP leg above tells the FSP to set the TRUEMASK)
        ATTN::setTrueMask_otherProcs( l_procsList );
    }
}


//******************************************************************************
// call_host_attnlisten_proc()
//******************************************************************************
void* call_host_attnlisten_proc(void *io_pArgs)
{
    IStepError  l_stepError;

    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"call_host_attnlisten_proc");

    // Function is a NOOP because with security enabled, PRD is unable
    // to write FIRs due to blacklist violations.  All of the slave
    // processor attentions will be ignored until the SMP comes up.

    // Send list of functional procs that ATTN
    // can start monitoring for checkstop analysis
    send_analyzable_procs();


    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_host_attnlisten_proc");
    return l_stepError.getErrorHandle();
}

};
