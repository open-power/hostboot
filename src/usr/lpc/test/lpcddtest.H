/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/lpc/test/lpcddtest.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#ifndef __LPCDDTEST_H
#define __LPCDDTEST_H

/**
 *  @file lpcddtest.H
 *
 *  @brief Test case for LPC Device Driver
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/userif.H>
#include <lpc/lpcif.H>
#include <kernel/console.H>

extern trace_desc_t* g_trac_lpc;

class LpcDdTest : public CxxTest::TestSuite
{
  private:
    // Test task for bad size
    static void* task_badsize(void * ignored)
    {
        errlHndl_t l_err = NULL;
        TARGETING::Target* sentinel =
          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
        size_t opsize = 3;
        uint8_t data[12];
        l_err = deviceRead( sentinel,
                            data,
                            opsize,
                            DEVICE_LPC_ADDRESS(LPC::TRANS_ABS,0x12345678) );
        TS_FAIL("LpcDD::task_badsize> Task should have died");
        return l_err;
    };

  public:

    /**
     * @brief LPC Bad Args
     *        Test handling of bad arguments
     */
    void test_badargs(void)
    {
        TRACFCOMP( g_trac_lpc, "LpcDdTest::test_badargs>" );
        errlHndl_t l_err = NULL;

        TARGETING::Target* master = NULL;
        TARGETING::targetService().masterProcChipTargetHandle( master );
        size_t opsize = 0;
        uint8_t data[12];

        // Invalid target
        opsize = 4;
        l_err = deviceRead( master,
                            data,
                            opsize,
                            DEVICE_LPC_ADDRESS(LPC::TRANS_ABS,0x12345678) );
        if( l_err )
        {
            delete l_err;
        }
        else
        {
            TS_FAIL("LpcDD::test_badargs> No error from bad target");
        }

        // Invalid size
        // Expects an assert so need to create a task
        int l_childsts = 0;
        void* l_childerrl = NULL;
        printk("\nExpect to see exception for assert! ");
        tid_t tid1 = task_create( task_badsize, NULL );
        tid_t tid2 = task_wait_tid( tid1,
                                    &l_childsts,
                                    &l_childerrl);
        if( (tid2 != tid1)
            || (l_childsts == TASK_STATUS_EXITED_CLEAN) )
        {
            TS_FAIL("LpcDD::test_badargs> No error from bad target");
        }
        else if( l_childerrl )
        {
            delete ((errlHndl_t)l_childerrl);
        }
    }



    /**
     * @brief LPC Alt Master
     *        Test creation/deletion of altmaster objects
     */
    void test_altmaster(void)
    {
        TRACFCOMP( g_trac_lpc, "LpcDdTest::test_altmaster>" );
        errlHndl_t l_err = NULL;
        TARGETING::Target* master = NULL;
        TARGETING::targetService().masterProcChipTargetHandle( master );

        // Should get error if we use the master proc
        l_err = LPC::create_altmaster_objects( true, master );
        if( !l_err )
        {
            TS_FAIL("LpcDD::test_altmaster> No error from master target");
        }
        else
        {
            delete l_err;
        }

        // Should get error if we use the sentinel master
        l_err = LPC::create_altmaster_objects( true,
                 TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL );
        if( !l_err )
        {
            TS_FAIL("LpcDD::test_altmaster> No error from sentinel target");
        }
        else
        {
            delete l_err;
        }

        // Should not get error doing a NOOP destroy
        l_err = LPC::create_altmaster_objects( false, NULL );
        if( l_err )
        {
            TS_FAIL("LpcDD::test_altmaster> Error from destroy");
            errlCommit( l_err, LPC_COMP_ID );
        }

        // find other processor target (physical:sys-0/node-0/proc-1)
        TARGETING::Target* proc1 = NULL;
        TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
        epath.addLast(TARGETING::TYPE_SYS,0);
        epath.addLast(TARGETING::TYPE_NODE,0);
        epath.addLast(TARGETING::TYPE_PROC,1);
        proc1 = TARGETING::targetService().toTarget(epath);
        if( proc1 )
        {
            // Should not get error using proc1
            l_err = LPC::create_altmaster_objects( true, proc1 );
            if( l_err )
            {
                TS_FAIL("LpcDD::test_altmaster> Error from proc1 create");
                errlCommit( l_err, LPC_COMP_ID );
            }

            // Should get error if we create twice in a row
            l_err = LPC::create_altmaster_objects( true, proc1 );
            if( !l_err )
            {
                TS_FAIL("LpcDD::test_altmaster> No error from double create");
            }
            else
            {
                delete l_err;
            }

            // Should not get error when we delete
            l_err = LPC::create_altmaster_objects( false, proc1 );
            if( l_err )
            {
                TS_FAIL("LpcDD::test_altmaster> Error from proc1 delete");
                errlCommit( l_err, LPC_COMP_ID );
            }
        }
    }


    //DISABLED because Sim doesn't do what we expect
    /**
     * @brief LPC HW Failure
     *        Test handling of hw error
     */
    void _test_hwfail(void)
    {
        TRACFCOMP( g_trac_lpc, "LpcDdTest::test_hwfail>" );
        errlHndl_t l_err = NULL;

        TARGETING::Target* sentinel =
          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
        size_t opsize = 4;
        uint8_t data[12];

        // pass a bad address
        l_err = deviceRead( sentinel,
                            data,
                            opsize,
                            DEVICE_LPC_ADDRESS(LPC::TRANS_ABS,0x12345678) );
        if( l_err )
        {
            delete l_err;
        }
        else
        {
            TS_FAIL("LpcDD::test_hwfail> No error from bad address");
        }
    }
};

#endif
