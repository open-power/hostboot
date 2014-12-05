/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/test/mdiatestmonitor.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
#ifndef __TEST_MDIATESTMONITOR_H
#define __TEST_MDIATESTMONITOR_H

#include <cxxtest/TestSuite.H>
#include <sys/task.h>
#include <sys/time.h>
#include <stdint.h>
#include <targeting/common/util.H>
#include "../mdiafwd.H"
#include "../mdiamonitor.H"
#include "../mdiasm.H"
#include "../mdiatrace.H"
#include "mdiafakesm.H"

using namespace MDIA;

class MdiaCommandMonitorTest: public CxxTest::TestSuite
{
    private:
        void nanoSleep(uint64_t i_sleepSec, uint64_t i_sleepNanoSec) const
        {
            if( TARGETING::is_vpo() )
            {
                nanosleep(0, TEN_CTX_SWITCHES_NS);
            }
            else
            {
                nanosleep(i_sleepSec, i_sleepNanoSec);
            }
        }

        void TimeoutAll(mutex_t *i_mutex, sync_cond_t *i_cond)
        {
            TS_TRACE(ENTER_MRK "TimeoutAll");

            uint64_t l_mntCmdTime = 10000000;
            FakeStateMachine1 l_sm;
            CommandMonitor l_cm;

            //Start the CM thread. Force a timeout.
            //All monitorIDs should timeout.
            uint64_t l_monID1 = 0, l_monID2 = 0;
            l_cm.start(l_sm);
            l_monID1 = l_cm.addMonitor(l_mntCmdTime);
            l_sm.addMonitor(l_monID1);
            l_monID2 = l_cm.addMonitor(l_mntCmdTime);
            l_sm.addMonitor(l_monID2);

            //2 monitorIDs should timeout
            l_sm.setTotalExpectedMons(2);
            l_sm.setSyncVars(i_mutex, i_cond);

            mutex_lock(i_mutex);
            // Wait until all monitorIDs timeout
            while(false == l_sm.isTimeoutProcessed())
            {
                sync_cond_wait(i_cond, i_mutex);
            }
            mutex_unlock(i_mutex);

            if(true != l_sm.isContentsEqual())
            {
                TS_FAIL("Expected monitorIDs to timeout are not equal "
                        "to actual timedout monitorIDs");
            }

            //All maint cmds/monitorIDs have timedout
            //Therefore all timedout iv_monitors should be erased
            if(l_cm.iv_monitors.size() != 0)
            {
                TS_FAIL("Size not zero");
            }

            TS_TRACE(EXIT_MRK "TimeoutAll");
        }

        void TimeoutSubset(mutex_t *i_mutex, sync_cond_t *i_cond)
        {
            TS_TRACE(ENTER_MRK "TimeoutSubset");

            FakeStateMachine1 l_sm;
            CommandMonitor l_cm;
            l_sm.setSyncVars(i_mutex, i_cond);
            l_cm.start(l_sm);

            uint64_t l_mntCmdTime = 10000000;

            //Add 7 more
            //3 of the 7 monitorIDs should timeout.
            uint64_t l_monID1 = 0,
                     l_monID2 = 0,
                     l_monID3 = 0,
                     l_monID4 = 0,
                     l_monID5 = 0,
                     l_monID6 = 0,
                     l_monID7 = 0;
            l_monID1 = l_cm.addMonitor(l_mntCmdTime);
            l_sm.addMonitor(l_monID1);
            l_monID2 = l_cm.addMonitor(l_mntCmdTime);
            l_sm.addMonitor(l_monID2);
            l_monID3 = l_cm.addMonitor(l_mntCmdTime);
            l_sm.addMonitor(l_monID3);
            l_monID4 = l_cm.addMonitor(l_mntCmdTime);
            l_sm.addMonitor(l_monID4);
            l_monID5 = l_cm.addMonitor(l_mntCmdTime);
            l_sm.addMonitor(l_monID5);
            l_monID6 = l_cm.addMonitor(l_mntCmdTime);
            l_sm.addMonitor(l_monID6);
            l_monID7 = l_cm.addMonitor(l_mntCmdTime);
            l_sm.addMonitor(l_monID7);

            //Remove 4 of the 7 monIDs
            l_cm.removeMonitor(l_monID1);
            l_sm.removeMonitor(0);
            nanoSleep(0, 100);
            l_cm.removeMonitor(l_monID4);
            l_sm.removeMonitor(2);
            l_cm.removeMonitor(l_monID5);
            l_sm.removeMonitor(2);
            l_cm.removeMonitor(l_monID6);
            l_sm.removeMonitor(2);

            //3 monitorIDs should timeout
            l_sm.setTotalExpectedMons(3);

            if(false != l_sm.isTimeoutProcessed())
            {
                TS_FAIL("Unexpected timeout");
            }

            //Wait till all monitorIDs have timed out
            mutex_lock(i_mutex);
            while(false == l_sm.isTimeoutProcessed())
            {
                sync_cond_wait(i_cond, i_mutex);
            }
            mutex_unlock(i_mutex);

            if(true != l_sm.isContentsEqual())
            {
                TS_FAIL("Expected monitorIDs to timeout are not equal "
                        "to actual timedout monitorIDs");
            }

            TS_TRACE(EXIT_MRK "TimeoutSubset");

        }

    public:
        void testCommandMonitor(void)
        {

            TS_TRACE(ENTER_MRK "testCommandMonitor");

            CommandMonitor l_cm;
            do
            {
                if(0 != l_cm.iv_tid)
                {
                    TS_FAIL("Thread id != 0");
                    break;
                }
                else if(true == l_cm.iv_shutdown)
                {
                    TS_FAIL("Var iv_shutdown != false");
                    break;
                }
                else if(0 != l_cm.iv_nextMonitor)
                {
                    TS_FAIL("Monitor ID counter != 0");
                    break;
                }
            }while(0);

            TS_TRACE(EXIT_MRK "testCommandMonitor");
        }

        void testaddMonitor(void)
        {
            TS_TRACE(ENTER_MRK "testaddMonitor");

            uint64_t l_timeout = 10;
            CommandMonitor l_cm1;

            //Add mutiple <monitor, timeout> entries
            uint64_t l_mon = l_cm1.addMonitor(l_timeout);
            if(1 != l_mon)
            {
                TS_FAIL("Key monitor ID not set corretly");
            }
            else
            {
                l_mon = l_cm1.addMonitor(++l_timeout);
                if(l_timeout != l_cm1.getMonitorMapTimeoutEntry(l_mon))
                {
                    TS_FAIL("Map entries not set right (1)");
                }

                // Add monitor after starting the CM thread
                StateMachine l_sm;
                l_cm1.start(l_sm);
                l_cm1.addMonitor(++l_timeout);
                l_mon = l_cm1.addMonitor(++l_timeout);
                if(l_timeout != l_cm1.getMonitorMapTimeoutEntry(l_mon))
                {
                    TS_FAIL("Map entries not set right (2)");
                }
            }

            TS_TRACE(EXIT_MRK "testaddMonitor");
        }

        void teststart(void)
        {
            TS_TRACE(ENTER_MRK "teststart");

            tid_t l_tid = 0;
            StateMachine l_sm;
            CommandMonitor l_cm1;
            //Check if CM thread was created.
            l_cm1.start(l_sm);
            l_tid = l_cm1.iv_tid;
            if(0 == l_tid)
            {
                TS_FAIL("Command Monitor task not started (1)");
            }
            else
            {
                //Once started should not start again.
                l_cm1.start(l_sm);
                if(l_tid != l_cm1.iv_tid)
                {
                    TS_FAIL("Command Monitor task started again");
                }

                //Call start after shutdown
                l_cm1.shutdown();
                if(0 != l_cm1.iv_tid)
                {
                    TS_FAIL("CM not shutdown");
                }
                else
                {
                    l_cm1.start(l_sm);
                    if(0 == l_cm1.iv_tid)
                    {
                        TS_FAIL("CommandMonitor task not started (2)");
                    }
                }
            }

            TS_TRACE(EXIT_MRK "teststart");
        }

        void testthreadMainTimeout(void)
        {
            TS_TRACE(ENTER_MRK "testthreadMainTimeout");

            mutex_t mutex;
            sync_cond_t cond;
            mutex_init(&mutex);
            sync_cond_init(&cond);

            for(uint64_t iterations=0; iterations<20; iterations++)
            {
                TimeoutAll(&mutex, &cond);
            }

            for(uint64_t iterations=0; iterations<20; iterations++)
            {
                TimeoutSubset(&mutex, &cond);
            }

            sync_cond_destroy(&cond);
            mutex_destroy(&mutex);

            TS_TRACE(EXIT_MRK "testthreadMainTimeout");
        }

        void testremoveMonitor(void)
        {
            TS_TRACE(ENTER_MRK "testremoveMonitor");

            CommandMonitor l_cm1;
            uint64_t l_monID = 0;
            //Removing from empty list
            l_cm1.removeMonitor(l_monID);

            //Populate monitor. Remove last entry
            uint64_t l_timeout = 20;
            l_monID = l_cm1.addMonitor(l_timeout);
            l_monID = l_cm1.addMonitor(++l_timeout);
            l_monID = l_cm1.addMonitor(++l_timeout);
            l_cm1.removeMonitor(l_monID);
            //Check if removed
            if(0 != l_cm1.getMonitorMapTimeoutEntry(l_monID))
            {
                TS_FAIL("Last Map entry not removed");
            }

            //Remove first entry
            l_monID = 1;
            l_cm1.removeMonitor(l_monID);
            if(0 != l_cm1.getMonitorMapTimeoutEntry(l_monID))
            {
                TS_FAIL("First Map entry not removed");
            }

            l_cm1.addMonitor(l_timeout);
            l_cm1.addMonitor(l_timeout);
            l_cm1.addMonitor(l_timeout);
            l_cm1.addMonitor(l_timeout);
            l_cm1.addMonitor(l_timeout);
            //Remove 2nd and 3rd entry
            l_cm1.removeMonitor(2);
            l_cm1.removeMonitor(4);
            //Verify removal
            if(0 != l_cm1.getMonitorMapTimeoutEntry(2) &&
               0 != l_cm1.getMonitorMapTimeoutEntry(4) )
            {
                TS_FAIL("Entries in middle not removed");
            }

            TS_TRACE(EXIT_MRK "testremoveMonitor");
        }

        void testshutdown(void)
        {
            TS_TRACE(ENTER_MRK "testshutdown");

            StateMachine l_sm;
            CommandMonitor l_cm;

            //Shutdown without starting CM
            l_cm.shutdown();
            if(false == l_cm.iv_shutdown && (0 != l_cm.iv_tid))
            {
                TS_FAIL("Command Monitor not shutdown (1)");
            }

            //Start CM, then shutdown
            l_cm.start(l_sm);
            l_cm.shutdown();
            if(false == l_cm.iv_shutdown && (0 != l_cm.iv_tid))
            {
                TS_FAIL("Command Monitor not shutdown (2)");
            }

            //Shutdown again
            l_cm.shutdown();
            if(false == l_cm.iv_shutdown && (0 != l_cm.iv_tid))
            {
                TS_FAIL("Command Monitor not shutdown (3");
            }

            TS_TRACE(EXIT_MRK "testshutdown");
        }

};
#endif
