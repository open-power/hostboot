/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/mdiaworkitem.C $                            */
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
 * @file mdiaworkitem.C
 * @brief threadpool workitem implementation
 */

#include "mdiaworkitem.H"
#include "mdiasm.H"

using namespace TARGETING;

namespace MDIA
{

void WorkItem::operator()()
{
    iv_sm.executeWorkItem(iv_wfp);
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

    if(iv_chipUnit < i_r.iv_chipUnit)
    {
        return -1;
    }

    if(i_r.iv_chipUnit < iv_chipUnit)
    {
        return 1;
    }

    return 0;
}

WorkItem::WorkItem(StateMachine & i_sm,
        WorkFlowProperties * i_wfp,
        uint64_t i_priority,
        uint8_t i_chipUnit) :
    iv_sm(i_sm),
    iv_wfp(i_wfp),
    iv_priority(i_priority),
    iv_chipUnit(i_chipUnit)
{

}
}
