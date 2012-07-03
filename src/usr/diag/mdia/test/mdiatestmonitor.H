/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/mdia/test/mdiatestmonitor.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
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
using namespace MDIA;

class FakeStateMachineTest: public StateMachine
{
    public:
        void processCommandTimeout(const std::vector<uint64_t> & i_monitorIDs)
        {
            if(true != isEqual(i_monitorIDs))
            {
                //TODO: This is commented out due to Issue 44509.
                //TS_FAIL("i_monitorIDs and iv_monitors vectors are not equal");
            }

            iv_processedTimeout = true;
        }

        void addMonitor(uint64_t i_mon)
        {
            iv_monitors.push_back(i_mon);
        }

        void removeMonitor(const uint64_t i_position)
        {
            iv_monitors.erase(iv_monitors.begin() + i_position);
        }

        void clearMonitors()
        {
            iv_monitors.clear();
        }

        void resetTimeout()
        {
            iv_processedTimeout = false;
        }

        bool isTimeoutProcessed() const
        {
            return iv_processedTimeout;
        }

        FakeStateMachineTest() : iv_processedTimeout(false) {}

        ~FakeStateMachineTest() {}

    private:

        bool isEqual(const std::vector<uint64_t> & i_monitorIDs) const
        {
            bool isEqual = true;
            if(i_monitorIDs.size() == iv_monitors.size())
            {
                std::vector<uint64_t>::const_iterator mon = i_monitorIDs.begin();
                std::vector<uint64_t>::const_iterator mon1 = iv_monitors.begin();
                while(mon != i_monitorIDs.end())
                {
                    if(*mon == *mon1)
                    {
                        mon++;
                        mon1++;
                    }
                    else
                    {
                        isEqual = false;
                        break;
                    }
                }
            }
            else
                isEqual = false;

            return isEqual;
        }

        bool iv_processedTimeout;
        std::vector<uint64_t> iv_monitors;
};

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
                FakeStateMachineTest l_sm;
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

            uint64_t l_mntCmdTime = 10000000;
            FakeStateMachineTest l_sm;
            CommandMonitor l_cm;

            //Start the CM thread. Force a timeout.
            //All monitorIDs should timeout.
            uint64_t l_monID1, l_monID2 = 0;
            l_cm.start(l_sm);
            l_monID1 = l_cm.addMonitor(l_mntCmdTime);
            l_sm.addMonitor(l_monID1);
            l_monID2 = l_cm.addMonitor(l_mntCmdTime);
            l_sm.addMonitor(l_monID2);
            nanoSleep(0, 100000000);
            if(true != l_sm.isTimeoutProcessed())
            {
                TS_FAIL("Did not timeout");
            }
            l_sm.clearMonitors();
            l_sm.resetTimeout();

            //All maint cmds/monitorIDs have timedout
            //Therefore all timedout iv_monitors should be erased
            if(l_cm.iv_monitors.size() != 0)
            {
                TS_FAIL("Size not zero");
            }

            //Add 7 more
            //3 of the 7 monitorIDs should timeout.
            uint64_t l_monID3, l_monID4, l_monID5, l_monID6, l_monID7 = 0;
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

            if(false != l_sm.isTimeoutProcessed())
            {
                TS_FAIL("Unexpected timeout");
            }

            nanoSleep(0, 100000000);
            if(true != l_sm.isTimeoutProcessed())
            {
                TS_FAIL("Did not timeout");
            }

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
