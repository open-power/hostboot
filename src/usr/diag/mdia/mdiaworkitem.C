//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/diag/mdia/mdiaworkitem.C $
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
 * @file mdiaworkitem.C
 * @brief threadpool workitem implementation
 */

#include "mdiaworkitem.H"
#include "mdiasm.H"
#include "mdiatrace.H"

using namespace TARGETING;

namespace MDIA
{

void WorkItem::operator()()
{
    MDIA_FAST("executing workitem: %d", iv_workFlowPhase);

    iv_sm.executeWorkItem(iv_target, iv_workFlowPhase);
}

int64_t WorkItem::compare(const WorkItem & i_r) const
{
    // schedule based on state machine computed priority

    if(i_r.iv_priority < iv_priority)
    {
        return -1;
    }

    if(iv_priority < i_r.iv_priority)
    {
        return 1;
    }

    // if the state machine computed priority is the same,
    // give higher priority to mbas on different dmi busses

    // TODO

    return 0;
}

WorkItem::WorkItem(StateMachine & i_sm,
        WorkFlowPhase i_workFlowPhase,
        TargetHandle_t i_target,
        uint64_t i_priority) :
    iv_sm(i_sm),
    iv_workFlowPhase(i_workFlowPhase),
    iv_target(i_target),
    iv_priority(i_priority)
{

}
}
