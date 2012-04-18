//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/diag/mdia/test/mdiatestmonitor.H $
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

using namespace MDIA;

class MdiaStateMachineTest: public StateMachine
{
    public:
        void processCommandTimeout(std::vector<uint64_t>)
        {
            iv_processedTimeout = true;
        }

        bool timeoutProcessed()
        {
            return iv_processedTimeout;
        }

        MdiaStateMachineTest() : iv_processedTimeout(false) {}

        ~MdiaStateMachineTest()
        {
            iv_processedTimeout = false;
        }

    private:

        bool iv_processedTimeout;
};

class MdiaCommandMonitorTest: public CxxTest::TestSuite
{
    public:
        void testCommandMonitor(void)
        {

            CommandMonitor l_cm;
            do
            {
                if( 0 != l_cm.getTID())
                {
                    TS_FAIL("Thread id != 0");
                    break;
                }
                else if(true == l_cm.isShutdown())
                {
                    TS_FAIL("Var iv_shutdown != false");
                    break;
                }
                else if(0 != l_cm.getMonitorID())
                {
                    TS_FAIL("Monitor ID counter != 0");
                    break;
                }
                else
                {
                    TS_TRACE("SUCCESS:Dflt CommandMonitor ctor");
                }
            }while(0);
        }

        void teststart(void)
        {
            tid_t l_tid = 0;
            StateMachine l_sm;
            CommandMonitor* l_cm1 = new CommandMonitor();
            l_cm1->start(l_sm);
            l_tid = l_cm1->getTID();
            if(0 == l_cm1->getTID())
            {
                TS_FAIL("Command Monitor task not started");
            }
            else
            {
                l_cm1->start(l_sm);
                if(l_tid != l_cm1->getTID())
                {
                    TS_FAIL("Command Monitor task started again");
                }
                else
                {
                    TS_TRACE("SUCCESS: CommandMonitor::start");
                }
            }

            delete l_cm1;
            l_cm1 = NULL;
        }

        void testaddMonitor(void)
        {
            uint64_t l_timeout = 10;
            CommandMonitor l_cm1;
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
                    TS_FAIL("Map entries not set right");
                }
                else
                {
                    TS_TRACE("SUCCESS: CommandMonitor::addMonitor");
                }
            }
        }

        void testthreadMainTimeout(void)
        {
            uint64_t timeoutNanosecs = 10000000;
            MdiaStateMachineTest l_sm;
            CommandMonitor l_cm;
            l_cm.start(l_sm);
            l_cm.addMonitor(timeoutNanosecs);
            l_cm.addMonitor(timeoutNanosecs);
            if( TARGETING::is_vpo() )
            {
                nanosleep(0, TEN_CTX_SWITCHES_NS);
            }
            else
            {
                //sleep for 100ms
                nanosleep(0, 100000000);
            }
            if(true != l_sm.timeoutProcessed())
            {
                TS_FAIL("Not a timeout");
            }
            else
            {
                TS_TRACE("SUCCESS: testthreadMainTimeout");
            }
        }

        void testremoveMonitor(void)
        {
            uint64_t l_timeout = 20;
            CommandMonitor l_cm1;
            l_cm1.addMonitor(l_timeout);
            l_cm1.addMonitor(++l_timeout);
            l_cm1.removeMonitor(2);
            if(0 != l_cm1.getMonitorMapTimeoutEntry(2))
            {
                TS_FAIL("Map entry not removed");
            }
            else
            {
                TS_TRACE("SUCCESS: CommandMonitor::removeMonitor");
            }
        }

        void testshutdown(void)
        {
            StateMachine l_sm;
            CommandMonitor l_cm;
            l_cm.start(l_sm);
            l_cm.shutdown();
            if(false == l_cm.isShutdown() && (0 != l_cm.getTID()))
            {
                TS_FAIL("Command Monitor not shutdown");
            }
            else
            {
                TS_TRACE("SUCCESS: CommandMonitor::shutdown");
            }
        }

};
#endif
