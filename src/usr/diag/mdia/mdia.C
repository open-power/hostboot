/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/mdia.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
 * @file mdia.C
 * @brief mdia entry points, utility function implementations
 */

// The following is required because MDIA implements its own version of these
// hardware procedures:
// $Id: mss_memdiags.H,v 1.9 2013/12/02 14:58:58 bellows Exp $
// $Id: mss_memdiags.C,v 1.24 2014/03/11 19:05:18 gollub Exp $

#include "mdiafwd.H"
#include "mdiatrace.H"
#include "mdiasm.H"
#include "mdiasmimpl.H"
#include <util/singleton.H>
#include <util/misc.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H> // for getAllChips

using namespace TARGETING;
using namespace Util;

namespace MDIA
{

errlHndl_t runStep(const TargetHandleList & i_targetList)
{
    MDIA_FAST("memory diagnostics entry with %d target(s)",
            i_targetList.size());

    // memory diagnostics ipl step entry point

    errlHndl_t err = nullptr;

    Globals globals {}; // Constructor initializes from targeting attributes.

    // get the workflow for each target passed in.
    // associate each workflow with the target handle.

    WorkFlowAssocMap list;

    TargetHandleList::const_iterator tit;
    DiagMode mode;

    for(tit = i_targetList.begin(); tit != i_targetList.end(); ++tit)
    {
        err = getDiagnosticMode(globals, *tit, mode);

        if(err)
        {
            break;
        }

        err = getWorkFlow(mode, list[*tit], globals);

        if(err)
        {
            break;
        }
    }

    if(nullptr == err)
    {
        // set global data
        Singleton<StateMachine>::instance().setGlobals(globals);

        err = Singleton<StateMachine>::instance().run(list);
    }

    // ensure threads and pools are shutdown when finished

    if(nullptr == err)
    {
        err = doStepCleanup(globals);
    }

    // If this step completes without the need for a reconfig due to an RCD
    // parity error, clear all RCD parity error counters.
    TargetHandle_t top = nullptr;
    targetService().getTopLevelTarget(top);

    ATTR_RECONFIGURE_LOOP_type attr = top->getAttr<ATTR_RECONFIGURE_LOOP>();
    if ( 0 == (attr & RECONFIGURE_LOOP_RCD_PARITY_ERROR) )
    {
        TargetHandleList trgtList; getAllChips( trgtList, TYPE_OCMB_CHIP );
        for ( auto & trgt : trgtList )
        {
            if ( 0 != trgt->getAttr<ATTR_RCD_PARITY_RECONFIG_LOOP_COUNT>() )
                trgt->setAttr<ATTR_RCD_PARITY_RECONFIG_LOOP_COUNT>(0);
        }
    }

    if (nullptr != err)
    {
        MDIA_FAST("runStep: error in runStep");
    }

    return err;

}

errlHndl_t doStepCleanup(const Globals & i_globals)
{
    // stop the state machine

    errlHndl_t l_errl = Singleton<StateMachine>::instance().shutdown();

    // TODO ... stop the command monitor
    return l_errl;
}

errlHndl_t processEvent(MaintCommandEvent & i_event)
{
        errlHndl_t err = 0;
        // Call State machine processEvent
        Singleton<StateMachine>::instance().processMaintCommandEvent(i_event);

        return err;
}

void waitingForMaintCmdEvents(bool & o_waiting)
{
    Singleton<StateMachine>::instance().running(o_waiting);
}
}
