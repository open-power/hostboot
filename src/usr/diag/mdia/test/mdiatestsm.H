/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/test/mdiatestsm.H $                         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
#include <diag/mdia/mdiamevent.H>

using namespace MDIA;
using namespace TARGETING;

class MdiaSmTest : public CxxTest::TestSuite
{
    private:

        void getTargets(uint64_t i_count, TARGETING::TargetHandleList & o_list)
        {
            // TODO...real target mbas

            TARGETING::TargetHandle_t first = 0;

            while(i_count-- != 0)
            {
                o_list.push_back(first + i_count);
            }
        }

        static void startSm(void * i_sm)
        {
            static_cast<MDIA::StateMachine *>(i_sm)->start();
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

            wkFlentries[targets[0]] = wkFlentries[targets[1]];

            s.setup(wkFlentries);

            s.reset();

            if(!s.iv_workFlowProperties.empty())
            {
                TS_FAIL("unexpected workflow properties found (5)");
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
                Checks(START_PATTERN_8, true),
                Checks(START_SCRUB, true)
            };

            StateMachine sm;
            WorkFlowAssocMap wkFlentries;
            TargetHandleList targets;

            getTargets(1, targets);

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

            TS_TRACE(EXIT_MRK "testSmExecuteWorkItem");
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

            TS_TRACE(EXIT_MRK "testSmRun");
        }

        void testSmDoMaintCommand(void)
        {
            using namespace MDIA;
            using namespace TARGETING;

            TS_TRACE(ENTER_MRK "testSmDoMaintCommand");

            StateMachine s;

            WorkFlowAssocMap wkFlentries;

            TargetHandleList targets;
            getTargets(1, targets);

            wkFlentries[targets[0]].push_back(START_SCRUB);
            s.setup(wkFlentries);

            WorkFlowProperties & wfp = *s.iv_workFlowProperties.front();
            s.executeWorkItem(&wfp);

            TS_TRACE(EXIT_MRK "testSmDoMaintCommand");
        }

        void testSmRunning(void)
        {
            TS_TRACE(ENTER_MRK "testSmRunning");

            StateMachine s;

            bool running = false;

            do {

                s.running(running);

                if(running)
                {
                    TS_FAIL("unexpected result calling running (1)");
                    break;
                }

                WorkFlowAssocMap wkFlentries;

                TargetHandleList targets;
                getTargets(1, targets);

                wkFlentries[targets[0]].push_back(START_SCRUB);

                s.setup(wkFlentries);

                s.running(running);

                if(!running)
                {
                    TS_FAIL("unexpected result calling running (2)");
                    break;
                }

                s.reset();

                s.run(wkFlentries);

                s.running(running);

                if(running)
                {
                    TS_FAIL("unexpected result calling running (3)");
                    break;
                }

            } while(0);

            TS_TRACE(EXIT_MRK "testSmRunning");
        }
};
#endif
