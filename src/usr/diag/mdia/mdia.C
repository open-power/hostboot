/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/mdia.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

using namespace TARGETING;
using namespace Util;

namespace MDIA
{

errlHndl_t runStep(const TargetHandleList & i_targetList)
{
    MDIA_FAST("memory diagnostics entry with %d target(s)",
            i_targetList.size());

    // memory diagnostics ipl step entry point

    errlHndl_t err = 0;

    Globals globals;

    TargetHandle_t top = 0;
    targetService().getTopLevelTarget(top);

    if(top)
    {
        globals.mfgPolicy = top->getAttr<ATTR_MNFG_FLAGS>();

        uint8_t maxMemPatterns =
            top->getAttr<ATTR_RUN_MAX_MEM_PATTERNS>();

        // This registry / attr is the same as the
        // exhaustive mnfg one
        if(maxMemPatterns)
        {
            globals.mfgPolicy |=
              MNFG_FLAG_ENABLE_EXHAUSTIVE_PATTERN_TEST;
        }

        globals.simicsRunning = Util::isSimicsRunning();

        globals.disableScrubs =
         top->getAttr<ATTR_DISABLE_SCRUB_AFTER_PATTERN_TEST>();
    }

    // get the workflow for each target mba passed in.
    // associate each workflow with the target handle.

    WorkFlowAssocMap list;

    TargetHandleList::const_iterator tit;
    DiagMode mode;

    for(tit = i_targetList.begin(); tit != i_targetList.end(); ++tit)
    {
        err = getMbaDiagnosticMode(globals, *tit, mode);

        if(err)
        {
            break;
        }

        err = getMbaWorkFlow(mode, list[*tit], globals);

        if(err)
        {
            break;
        }
    }

    if(!err)
    {
        // set global data
        Singleton<StateMachine>::instance().setGlobals(globals);

        // TODO...run the workflow through the state machine
        err = Singleton<StateMachine>::instance().run(list);
    }

    // ensure threads and pools are shutdown when finished

    doStepCleanup(globals);

    return err;

}

void doStepCleanup(const Globals & i_globals)
{
    // stop the state machine

    Singleton<StateMachine>::instance().shutdown();

    // TODO ... stop the command monitor
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
