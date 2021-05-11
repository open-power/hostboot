/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/test/mdiatestsm.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
#ifndef __TEST_MDIATESTSM_H
#define __TEST_MDIATESTSM_H

/**
 * @file mdiatestsm.H
 * @brief state machine unit test
 */

#include <builtins.h>
#include <cxxtest/TestSuite.H>
#include "../mdiasm.H"
#include "../mdiasmimpl.H"
#include <targeting/common/utilFilter.H>
#include "../mdiatrace.H"
#include "../mdiamonitor.H"
#include "../mdiafwd.H"
#include <sys/time.h>
#include "mdiafakesm.H"

using namespace MDIA;
using namespace TARGETING;

class MdiaSmTest : public CxxTest::TestSuite
{
    private:

        void getTargets(uint64_t i_count, TARGETING::TargetHandleList & o_list)
        {
            TargetHandleList tmp;
            TARGETING::getAllChips(tmp, TYPE_OCMB_CHIP);

            TargetHandleList::iterator it = tmp.end();

            while(i_count-- != 0 && it-- != tmp.begin())
            {
                o_list.push_back(*it);
            }
        }

        static void* startSm(void * i_sm)
        {
            static_cast<MDIA::StateMachine *>(i_sm)->start();
            return NULL;
        }

    public:

        void testSmReset(void)
        {
            using namespace MDIA;
            using namespace TARGETING;

            TS_TRACE(ENTER_MRK "testSmReset");

            StateMachine s;

            // should be able to call reset

            s.reset();

            if(!s.iv_workFlowProperties.empty())
            {
                TS_FAIL("unexpected workflow properties found (1)");
            }

            // should be able to call reset again

            s.reset();

            if(!s.iv_workFlowProperties.empty())
            {
                TS_FAIL("unexpected workflow properties found (2)");
            }

            // should be able to call reset multiple times

            s.reset();

            if(!s.iv_workFlowProperties.empty())
            {
                TS_FAIL("unexpected workflow properties found (3)");
            }

            WorkFlowAssocMap wkFlentries;
            s.setup(wkFlentries);

            // should be able to call reset after calling setup, with
            // empty list

            s.reset();

            if(!s.iv_workFlowProperties.empty())
            {
                TS_FAIL("unexpected workflow properties found (4)");
            }

            // should be able to call reset after calling setup, with
            // list

            TargetHandleList targets;
            getTargets(2, targets);

            if(targets.size() > 0)
            {
                wkFlentries[targets[0]] = wkFlentries[targets[1]];

                s.setup(wkFlentries);

                s.reset();

                if(!s.iv_workFlowProperties.empty())
                {
                    TS_FAIL("unexpected workflow properties found (5)");
                }
            }
            TS_TRACE(EXIT_MRK "testSmReset");
        }

        void testSmSetup(void)
        {
            using namespace MDIA;
            using namespace TARGETING;

            TS_TRACE(ENTER_MRK "testSmSetup");

            StateMachine s;

            // should be able to call setup with empty map entries

            WorkFlowAssocMap wkFlentries;

            s.setup(wkFlentries);

            if(s.iv_workFlowProperties.size() != wkFlentries.size())
            {
                TS_FAIL("unexpected number of workflow properties (1)");
            }

            s.reset();

            if(!s.iv_workFlowProperties.empty())
            {
                TS_FAIL("unexpected number of workflow properties (2)");
            }

            // should be able to call setup with a list

            TargetHandleList targets;
            getTargets(2, targets);

            if(targets.size() > 0)
            {
                wkFlentries[targets[0]] = wkFlentries[targets[1]];

                s.setup(wkFlentries);

                uint64_t idx = s.iv_workFlowProperties.size();

                while(idx-- != 0)
                {
                    TargetHandle_t t = getTarget(*s.iv_workFlowProperties[idx]);

                    WorkFlowAssoc assoc = wkFlentries.find(t);

                    if(static_cast<const WorkFlowAssocMap &>(wkFlentries).end()
                        == assoc)
                    {
                        TS_FAIL("unexpected target found in workflow properties");
                    }

                    if(s.iv_workFlowProperties[idx]->status != IN_PROGRESS)
                    {
                        TS_FAIL("unexpected status found in workflow properties");
                    }

                    if(s.iv_workFlowProperties[idx]->workItem
                        != getWorkFlow(assoc).begin())
                    {
                        TS_FAIL("unexpected work item found in"
                                " workflow properties");
                    }
                }
            }
            TS_TRACE(EXIT_MRK "testSmSetup");
        }

        void testSmWait(void)
        {
            using namespace MDIA;
            using namespace TARGETING;

            TS_TRACE(ENTER_MRK "testSmWait");

            // start & wait without calling setup shouldn't hang

            int status;
            StateMachine s;

            tid_t tid = task_create(&startSm, &s);

            if(tid < 0)
            {
                TS_FAIL("child task not started (1)");
            }

            s.wait();

            task_wait_tid(tid, &status, 0);

            if(status != TASK_STATUS_EXITED_CLEAN)
            {
                TS_FAIL("child task crashed (1)");
            }

            // start & wait with empty list shouldn't hang

            WorkFlowAssocMap wkFlentries;

            s.setup(wkFlentries);

            tid = task_create(&startSm, &s);

            if(tid < 0)
            {
                TS_FAIL("child task not started (2)");
            }

            s.wait();

            task_wait_tid(tid, &status, 0);

            if(status != TASK_STATUS_EXITED_CLEAN)
            {
                TS_FAIL("child task crashed (2)");
            }

            // start & wait with list shouldn't hang

            TargetHandleList targets;
            getTargets(2, targets);

            if(targets.size() > 0)
            {
                wkFlentries[targets[0]] = wkFlentries[targets[1]];

                s.setup(wkFlentries);

                tid = task_create(&startSm, &s);

                if(tid < 0)
                {
                    TS_FAIL("child task not started (3)");
                }

                s.wait();

                task_wait_tid(tid, &status, 0);

                if(status != TASK_STATUS_EXITED_CLEAN)
                {
                    TS_FAIL("child task crashed (3)");
                }
            }
            TS_TRACE(ENTER_MRK "testSmWait");
        }

        void testSmWorkItemIsAsync(void)
        {
            using namespace MDIA;
            using namespace TARGETING;

            TS_TRACE(ENTER_MRK "testSmWorkItemIsAsync");

            static const struct Checks
            {
                Checks(WorkFlowPhase i_workItem, bool i_expected) :
                    workItem(i_workItem), expected(i_expected)
                {

                }

                WorkFlowPhase workItem;
                bool expected;

            } checks[] = {
                Checks(RESTORE_DRAM_REPAIRS, false),
                Checks(DUMMY_SYNC_PHASE, false),
                Checks(DUMMY_ASYNC_PHASE, true),
                Checks(START_PATTERN_0, true),
                Checks(START_PATTERN_1, true),
                Checks(START_PATTERN_2, true),
                Checks(START_PATTERN_3, true),
                Checks(START_PATTERN_4, true),
                Checks(START_PATTERN_5, true),
                Checks(START_PATTERN_6, true),
                Checks(START_PATTERN_7, true),
                Checks(START_SCRUB, true),
                Checks(CLEAR_HW_CHANGED_STATE, false),
                Checks(POST_MEMDIAGS_HWPS, false)
            };

            StateMachine sm;
            WorkFlowAssocMap wkFlentries;
            TargetHandleList targets;

            getTargets(1, targets);

            if(targets.size() > 0)
            {
                const Checks * it = checks + sizeof(checks)/sizeof(*checks);
                while(it-- != checks)
                {
                    sm.reset();
                    wkFlentries.clear();
                    wkFlentries[targets[0]].push_back(it->workItem);

                    sm.setup(wkFlentries);
                    WorkFlowProperties & tmp = *sm.iv_workFlowProperties.front();

                    if(StateMachine::workItemIsAsync(tmp) != it->expected)
                    {
                        TS_FAIL("unexpected result from "
                                "StateMachine::workItemIsAsync: %d", it->workItem);
                    }
                }
            }
            TS_TRACE(EXIT_MRK "testSmWorkItemIsAsync");
        }

        void testSmAllWorkFlowsComplete(void)
        {
            using namespace MDIA;
            using namespace TARGETING;

            TS_TRACE(ENTER_MRK "testSmAllWorkFlowsComplete");

            StateMachine s;

            // empty state machine should indicate all workflows complete

            if(!s.allWorkFlowsComplete())
            {
                TS_FAIL("unexpected result from "
                        "StateMachine::allWorkFlowsComplete (1)");
            }

            s.reset();

            // empty list should indicate all workflows complete

            WorkFlowAssocMap wkFlentries;

            s.setup(wkFlentries);

            if(!s.allWorkFlowsComplete())
            {
                TS_FAIL("unexpected result from "
                        "StateMachine::allWorkFlowsComplete (2)");
            }

            s.reset();

            // list with empty workflow should indicate all workflows complete
            TargetHandleList targets;
            getTargets(2, targets);

            if(targets.size() > 0)
            {
                wkFlentries[targets[0]] = wkFlentries[targets[0]];

                s.setup(wkFlentries);

                if(s.allWorkFlowsComplete())
                {
                    TS_FAIL("unexpected result from "
                            "StateMachine::allWorkFlowsComplete (3)");
                }

                s.reset();

                // list with non-empty workflow should not indicate
                // all workflows complete

                wkFlentries[targets[0]].push_back(RESTORE_DRAM_REPAIRS);

                s.setup(wkFlentries);

                if(s.allWorkFlowsComplete())
                {
                    TS_FAIL("unexpected result from "
                            "StateMachine::allWorkFlowsComplete (4)");
                }

                // single entry with FAILED status should indicate
                // all workflows complete

                s.iv_workFlowProperties.front()->status = FAILED;

                if(!s.allWorkFlowsComplete())
                {
                    TS_FAIL("unexpected result from "
                            "StateMachine::allWorkFlowsComplete (5)");
                }

                // single entry with TIMED_OUT status should indicate
                // all workflows complete

                s.iv_workFlowProperties.front()->status = COMMAND_TIMED_OUT;

                if(!s.allWorkFlowsComplete())
                {
                    TS_FAIL("unexpected result from "
                            "StateMachine::allWorkFlowsComplete (6)");
                }

                // single entry with COMPLETE status should indicate
                // all workflows complete

                s.iv_workFlowProperties.front()->status = COMPLETE;

                if(!s.allWorkFlowsComplete())
                {
                    TS_FAIL("unexpected result from "
                            "StateMachine::allWorkFlowsComplete (7)");
                }

                s.reset();

                // list with two non-empty workflow should not indicate
                // all workflows complete

                wkFlentries[targets[0]] = wkFlentries[targets[1]];

                wkFlentries[targets[0]].push_back(RESTORE_DRAM_REPAIRS);
                wkFlentries[targets[1]].push_back(RESTORE_DRAM_REPAIRS);

                s.setup(wkFlentries);

                if(s.allWorkFlowsComplete())
                {
                    TS_FAIL("unexpected result from "
                            "StateMachine::allWorkFlowsComplete (8)");
                }

                // single entry with FAILED status should not indicate
                // not workflows complete

                s.iv_workFlowProperties.front()->status = FAILED;

                if(s.allWorkFlowsComplete())
                {
                    TS_FAIL("unexpected result from "
                            "StateMachine::allWorkFlowsComplete (9)");
                }

                // single entry with TIMED_OUT status should not
                // indicate all workflows complete

                s.iv_workFlowProperties.front()->status = COMMAND_TIMED_OUT;

                if(s.allWorkFlowsComplete())
                {
                    TS_FAIL("unexpected result from "
                            "StateMachine::allWorkFlowsComplete (10)");
                }

                // single entry with COMPLETE status should not indicate
                // all workflows complete

                s.iv_workFlowProperties.front()->status = COMPLETE;

                if(s.allWorkFlowsComplete())
                {
                    TS_FAIL("unexpected result from "
                            "StateMachine::allWorkFlowsComplete (11)");
                }
            }
            TS_TRACE(EXIT_MRK "testSmAllWorkFlowsComplete");
        }

        void testSmExecuteWorkItem(void)
        {
            using namespace MDIA;
            using namespace TARGETING;

            TS_TRACE(ENTER_MRK "testSmExecuteWorkItem");

            StateMachine sm;
            WorkFlowAssocMap list;
            TargetHandleList targets;

            getTargets(1, targets);

            if(targets.size() > 0)
            {
                list[targets[0]].push_back(DUMMY_ASYNC_PHASE);
                sm.setup(list);

                WorkFlowProperties * tmp = sm.iv_workFlowProperties.front();

                WorkFlow::const_iterator sit = tmp->workItem;

                sm.executeWorkItem(tmp);

                // should not have advanced the work item for async

                if(sit != tmp->workItem)
                {
                    TS_FAIL("unexpected next work item after "
                            "executing work item (1)");
                }

                if(tmp->status != IN_PROGRESS)
                {
                    TS_FAIL("unexpected status after executing work item (1)");
                }

                sm.reset();
                list.clear();

                list[targets[0]].push_back(DUMMY_SYNC_PHASE);
                sm.setup(list);

                tmp = sm.iv_workFlowProperties.front();

                sit = tmp->workItem;

                sm.executeWorkItem(tmp);

                // should have advanced the work item for sync

                if(std::distance(sit, tmp->workItem) != 1)
                {
                    TS_FAIL("unexpected next work item after "
                            "executing work item (2)");
                }

                if(tmp->status != COMPLETE)
                {
                    TS_FAIL("unexpected status after executing work item (2)");
                }
            }
            TS_TRACE(EXIT_MRK "testSmExecuteWorkItem");
        }

        void testDoMaintCmd(void)
        {
            TS_TRACE(ENTER_MRK "testDoMaintCmd");

            StateMachine sm;
            WorkFlowAssocMap list;
            TargetHandleList targets;
            errlHndl_t err = NULL;

            getTargets(1, targets);

            if(targets.size() > 0)
            {
                list[targets[0]].push_back(DUMMY_SYNC_PHASE);

                sm.setup(list);

                WorkFlowProperties * tmp = sm.iv_workFlowProperties.front();

                err = sm.doMaintCommand(*tmp);
                if ( NULL != err )
                {
                    TS_FAIL("doMaintCommand() failed");
                }
            }
            TS_TRACE(EXIT_MRK "testDoMaintCmd");

        }

        void testProcessMaintCommandEvent(void)
        {
            TS_TRACE(ENTER_MRK "testProcessMaintCommandEvent");

            StateMachine sm;
            WorkFlowAssocMap list;
            TargetHandleList targets;

            getTargets(2, targets);

            if(targets.size() > 0)
            {
                list[targets[0]].push_back(DUMMY_SYNC_PHASE);
                list[targets[1]].push_back(DUMMY_SYNC_PHASE);

                sm.setup(list);

                TargetHandleList ocmbList;
                getAllChips(ocmbList, TYPE_OCMB_CHIP);

                if (ocmbList.size() > 0)
                {
                    TargetHandle_t ocmb = ocmbList[0];

                    MaintCommandEvent event;
                    event.target = ocmb;
                    event.type = COMMAND_COMPLETE;
                    bool rc = false;

                    rc = sm.processMaintCommandEvent(event);
                    if (true == rc)
                    {
                        TS_TRACE("testProcessMaintCommandEvent: "
                                "a work item was dispatched");
                    }
                    else
                    {
                        TS_TRACE("testProcessMaintCommandEvent: "
                                "a work item was not dispatched");

                    }
                }
            }
            TS_TRACE(EXIT_MRK "testProcessMaintCommandEvent");
        }

        void testSmRun(void)
        {
            using namespace MDIA;
            using namespace TARGETING;

            TS_TRACE(ENTER_MRK "testSmRun");

            StateMachine s;

            // run with empty list

            WorkFlowAssocMap wkFlentries;
            errlHndl_t err = s.run(wkFlentries);

            if(err)
            {
                TS_FAIL("StateMachine::run(1) failed unexpectedly");
            }

            err = s.run(wkFlentries);

            if(err)
            {
                TS_FAIL("StateMachine::run(2) failed unexpectedly");
            }

            // should be able to run again

            err = s.run(wkFlentries);

            if(err)
            {
                TS_FAIL("StateMachine::run(3) failed unexpectedly");
            }

            // run again, with a list but no workflow

            TargetHandleList targets;
            getTargets(2, targets);

            if(targets.size() > 0)
            {
                wkFlentries[targets[0]] = wkFlentries[targets[0]];

                err = s.run(wkFlentries);

                if(err)
                {
                    TS_FAIL("StateMachine::run(4) failed unexpectedly");
                }

                // run again, with a list and workflow

                wkFlentries[targets[0]].push_back(DUMMY_SYNC_PHASE);
                wkFlentries[targets[0]].push_back(DUMMY_SYNC_PHASE);
                wkFlentries[targets[1]].push_back(DUMMY_SYNC_PHASE);
                wkFlentries[targets[1]].push_back(DUMMY_SYNC_PHASE);

                err = s.run(wkFlentries);

                if(err)
                {
                    TS_FAIL("StateMachine::run(5) failed unexpectedly");
                }
            }
            TS_TRACE(EXIT_MRK "testSmRun");
        }
};
#endif
