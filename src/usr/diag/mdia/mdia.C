/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/mdia.C $                                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 * @file mdia.C
 * @brief mdia entry points, utility function implementations
 */

// The following is required because MDIA implements its own version of these
// hardware procedures:
// $Id: mss_memdiags.H,v 1.6 2013/04/19 15:48:43 gollub Exp $
// $Id: mss_memdiags.C,v 1.22 2013/10/31 20:44:46 gollub Exp $

#include "mdiafwd.H"
#include "mdiaglobals.H"
#include "mdiatrace.H"
#include "mdiasm.H"
#include "mdiasmimpl.H"
#include <util/singleton.H>
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

    Globals globals = {};

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
              MNFG_FLAG_BIT_MNFG_ENABLE_EXHAUSTIVE_PATTERN_TEST;
        }

        uint8_t isMpipl = top->getAttr<ATTR_IS_MPIPL_HB>();
        globals.mpipl = (isMpipl ? true:false);
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
