//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/diag/mdia/mdia.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
/**
 * @file mdia.C
 * @brief mdia entry points, utility function implementations
 */

#include "mdiafwd.H"
#include "mdiaglobals.H"
#include "mdiatrace.H"

using namespace TARGETING;

namespace MDIA
{

errlHndl_t runStep(const TargetHandleList & i_targetList)
{
    MDIA_FAST("memory diagnostics entry (runStep)");

    // memory diagnostics ipl step entry point

    errlHndl_t err = 0;

    Globals globals;

    // get the workflow for each target mba passed in.
    // associate each workflow with the target handle.

    WorkFlowAssocList list;

    TargetHandleList::const_iterator tit;
    DiagMode mode;

    for(tit = i_targetList.begin(); tit != i_targetList.end(); ++tit)
    {
        err = getMbaDiagnosticMode(globals, *tit, mode);

        if(err)
        {
            break;
        }

        err = getMbaWorkFlow(mode, list[*tit]);

        if(err)
        {
            break;
        }
    }

    if(!err)
    {
        // TODO...run the workflow through the state machine
    }

    // ensure threads and pools are shutdown when finished

    doStepCleanup(globals);

    return err;
}

void doStepCleanup(const Globals & i_globals)
{
    // TODO ... stop the state machine
    // TODO ... stop the command monitor
}
}
