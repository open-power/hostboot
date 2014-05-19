/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/test/tcetest.H $                              */
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

#ifndef __TEST_TCETEST_H
#define __TEST_TCETEST_H

/**
 *  @file tcetest.H
 *
 */

#include <cxxtest/TestSuite.H>

#include <arch/ppc.H> //for MAGIC
#include <errl/errlmanager.H>
#include <runtime/runtime.H>
#include <targeting/common/commontargeting.H>
#include <runtime/tceif.H>
#include "../tce.H"
#include <util/align.H>
#include <kernel/console.H>
#include <sys/mmio.h>
#include <kernel/pagemgr.H>

extern trace_desc_t* g_trac_tce;

class TCETest: public CxxTest::TestSuite
{
  public:
    void testTCE(void)
    {
        TRACFCOMP( g_trac_tce, "testTCE> start" );
        errlHndl_t errhdl = NULL;
        uint64_t token0 = 0;
        uint64_t token1 = 0;
        uint64_t token2 = 0;
        uint64_t token3 = 0;
        uint64_t token4 = 0;
        uint64_t token5 = 0;

        uint64_t l_tceTable =
          reinterpret_cast<uint64_t>(PageManager::allocatePage(4, true));


        TceMgr *TceTable = new
             TceMgr(l_tceTable+100,100*(sizeof(uint64_t)));

        //---------------------------------------------------
        // TEST 1 - Call Create with unaligned addr
        //---------------------------------------------------

            errhdl = TceTable->createTceTable();

            if (errhdl == NULL)
            {
                TRACFCOMP( g_trac_tce,"TestTce: T1:  Did not get expected error from CreateTce ");
                TS_FAIL("testTcE> T1 Did not get expected error back.");
            }
            else
            {
                TRACFCOMP( g_trac_tce,"TestTce: T1: Got expected error unaligedn addr back from CreateTce ");
                delete errhdl;
            }

        // Since we are not page aligned.. Delete the TceTable
        delete TceTable;

        // create new TCE table with the aligned address but with a size too
        // large
        TceTable = new TceMgr(l_tceTable, THIRTYTWO_MB + PAGESIZE);


        //---------------------------------------------------
        // TEST 2 - Call create with aligned addr with large addr
        //---------------------------------------------------
        errhdl = TceTable->createTceTable();

        if (errhdl == NULL)
        {
            TRACFCOMP( g_trac_tce,"TestTce: T2:  Did not get expected error from CreateTce ");
            TS_FAIL("testTcE> T2 Did not get expected error back.");
        }
        else
        {
            TRACFCOMP( g_trac_tce,"TestTce: T2: Got expected error, size > 32M back from CreateTce ");
            delete errhdl;
        }


        // Since the size was too big. Delete the TceTable
        delete TceTable;

        // create new TCE table with the aligned address and valid size
        TceTable = new TceMgr(l_tceTable,100*(sizeof(uint64_t)));


        //---------------------------------------------------
        // TEST 3 - Call allocate before init.
        //---------------------------------------------------
        errhdl = TceTable->allocateTces(0x0, ((16*PAGESIZE)), token0);

        if (errhdl != NULL)
        {
            delete errhdl;
            errhdl = NULL;
        }
        else
        {
            TRACFCOMP( g_trac_tce,"TestTCE T3: Did not get back expected error");
            TS_FAIL("testTCE:T3: No error when address not page aligned.");
        }

        //---------------------------------------------------
        // TEST 4 - Call create with aligned addr
        //---------------------------------------------------
        errhdl = TceTable->createTceTable();

        if (errhdl != NULL)
        {
            TRACFCOMP( g_trac_tce,
                      "TestTce: T4:  Got unexpected error from CreateTce ");
            TS_FAIL("testTcE> T4 got unexpected error back.");
            errlCommit(errhdl,RUNTIME_COMP_ID);

        }

        //---------------------------------------------------
        // TEST 5 - Call init.
        //---------------------------------------------------

        errhdl = TceTable->initTceInHdw();

        if (errhdl != NULL)
        {
            TRACFCOMP( g_trac_tce,
                      "TestTce: T5:  Got unexpected error from InitTCEINHdw ");
            TS_FAIL("testTcE> T5 got unexpected error back.");
            errlCommit(errhdl,RUNTIME_COMP_ID);

        }

        token0 = 0;

        //---------------------------------------------------
        // TEST 6 - trying to allocate too large of size.
        //---------------------------------------------------
        errhdl = TceTable->allocateTces(0x0,
                                         (520*KILOBYTE*PAGESIZE),
                                         token0);

        if (errhdl != NULL)
        {
            delete errhdl;
            errhdl = NULL;
        }
        else
        {
            TRACFCOMP( g_trac_tce, "testTCE>T6: Did not get expecte error");
            TS_FAIL("testTCE> T6: No errorLog when size too large");
        }


        //---------------------------------------------------
        // TEST 7 - Address not page aligned.
        //---------------------------------------------------
        errhdl = TceTable->allocateTces(0x4140, ((16*PAGESIZE)), token0);

        if (errhdl != NULL)
        {
            delete errhdl;
            errhdl = NULL;
        }
        else
        {
            TRACFCOMP( g_trac_tce, "testTCE:T7: Did not get back expected error");
            TS_FAIL("testTCE:T7 No error when addr not page aligned");
        }


        //---------------------------------------------------
        // TEST 8 - valid address with  8 pages in size
        //---------------------------------------------------
        errhdl = TceTable->allocateTces(0x0000000004000000,
                                         PAGESIZE*8,
                                         token1);

        if (errhdl != NULL)
        {
            TRACFCOMP( g_trac_tce, "testTCE> T8:  Got unexpected error ");
            TS_FAIL("testTCE> T8 got unexpected error back.");

            errlCommit(errhdl,RUNTIME_COMP_ID);
        }
        else if (token1 != 0)
        {
            TRACFCOMP( g_trac_tce, "testTCEs> T8:  Did not get back expected Token= %lx", token1);
            TS_FAIL("testTCEs> T8 got wrong Token.");

        }

        //---------------------------------------------------
        // TEST 9 - valid address with  16 pages in size
        //---------------------------------------------------
        errhdl = TceTable->allocateTces(0x0000000004010000,
                                        PAGESIZE*16,
                                        token2);

        if (errhdl != NULL)
        {
            TRACFCOMP( g_trac_tce, "testTCE> T9:  Got unexpected error ");
            TS_FAIL("testTCE> T9 got unexpected error back.");

            errlCommit(errhdl,RUNTIME_COMP_ID);
        }
        else if (token2 != 0x8000)
        {
            TRACFCOMP( g_trac_tce, "testTCE> T9:  Did not get back expected Token = %lx ", token2);
            TS_FAIL("testTCE> T9 got wrong Token.");
        }


        //---------------------------------------------------
        // TEST 10 - valid address with  50 pages in size
        //---------------------------------------------------
        errhdl = TceTable->allocateTces(0x0000000004800000,
                                        PAGESIZE*50,
                                        token3);

        if (errhdl != NULL)
        {
            TRACFCOMP( g_trac_tce, "testTCE> T10:  Got unexpected error ");
            TS_FAIL("testTCE> T10 got unexpected error back.");

            errlCommit(errhdl,RUNTIME_COMP_ID);
        }
        else if (token3 != 0x18000)
        {
            TRACFCOMP( g_trac_tce, "testTCE> T10:  Did not get back expected Token = %lx ", token3);
            TS_FAIL("testTCE> T10 got wrong Token.");
        }


        //---------------------------------------------------
        // TEST 11 - Deallocate token with 16 pages from above
        //---------------------------------------------------
        errhdl = TceTable->deallocateTces(token2,
                                          PAGESIZE*16);
        if (errhdl != NULL)
        {
            TRACFCOMP( g_trac_tce, "testTCE:T11:  Got unexpected error ");
            TS_FAIL("testTCE:T11 Deallocate got unexpected error");

            errlCommit(errhdl,RUNTIME_COMP_ID);
        }


        token2 = 0;

        //---------------------------------------------------
        // TEST 12 Allocate 10 pages.. will go into the slot left by the
        // previous allocate
        //---------------------------------------------------
        errhdl = TceTable->allocateTces(0x0000000004010000,
                                        PAGESIZE*10,
                                        token2);

        if (errhdl != NULL)
        {
            TRACFCOMP( g_trac_tce, "T12:  Got unexpected error ");
            TS_FAIL("testAllocateTCEs> T12 Allocate got unexpected error");

            errlCommit(errhdl,RUNTIME_COMP_ID);
        }
        else if (token2 != 0x8000)
        {
            TRACFCOMP( g_trac_tce, "testTCE:T12:  Did not get back expected Token = %lx", token2);
            TS_FAIL("testTCE:T12: got wrong Token.");
        }


        //---------------------------------------------------
        // TEST 13 Allocate 10 pages.. will have ot pass the 6 slots avail from
        // the 16 page dealloate.. So will go past that to find a valid index to
        // fit the 20 entries
        //---------------------------------------------------
        errhdl = TceTable->allocateTces(0x0000000005010000,
                                        PAGESIZE*20,
                                        token4);

        if (errhdl != NULL)
        {
            TRACFCOMP( g_trac_tce, "testTCE:T13:  Got unexpected error ");
            TS_FAIL("testTCE:T13: Allocate got unexpected error");

            errlCommit(errhdl,RUNTIME_COMP_ID);
        }
        else if (token4 != 0x4a000)
        {
            TRACFCOMP( g_trac_tce, "testTCE:T13:  Did not get back expected Token = %lx ", token4);
            TS_FAIL("testTCE:T10: got wrong Token.");
        }



        //---------------------------------------------------
        // TEST 14 Allocate 6 pages.. will go into the 6 slots avail from
        // the 16 page dealloate..
        //---------------------------------------------------
        errhdl = TceTable->allocateTces(0x0000000006010000,
                                        PAGESIZE*6,
                                        token5);

        if (errhdl != NULL)
        {
            TRACFCOMP( g_trac_tce, "testTCE:T14:  Got unexpected error ");
            TS_FAIL("testTCE:T14: Allocate got unexpected error");

            errlCommit(errhdl,RUNTIME_COMP_ID);
        }
        else if (token5 != 0x12000)
        {
            TRACFCOMP( g_trac_tce, "testTCE:T14:  Did not get back expected Token ");
            TS_FAIL("testTCE:T14: got wrong Token.");
        }


        //---------------------------------------------------
        // TEST 15 Deallocate 20 pages from above
        //---------------------------------------------------
        errhdl = TceTable->deallocateTces(token4,  PAGESIZE*20);
        if (errhdl != NULL)
        {
            TRACFCOMP( g_trac_tce, "testTCE:T15:  Got unexpected error ");
            TS_FAIL("testTCE:T15: Deallocate got unexpected error");

            errlCommit(errhdl,RUNTIME_COMP_ID);
        }

        //---------------------------------------------------
        // TEST 16 Deallocate 10 pages from above
        //---------------------------------------------------
        errhdl = TceTable->deallocateTces(token2,  PAGESIZE*10);
        if (errhdl != NULL)
        {
            TRACFCOMP( g_trac_tce, "testTCE:T16: Got unexpected error ");
            TS_FAIL("testTCE:T16: Deallocate got unexpected error");

            errlCommit(errhdl,RUNTIME_COMP_ID);
        }

        //---------------------------------------------------
        // TEST 17 Deallocate Too large of size.   No error returned instead the
        // code should to end of the TCE table and commit errorlog and return
        //---------------------------------------------------
        errhdl = TceTable->deallocateTces(token5,  (520*KILOBYTE*PAGESIZE));

        if (errhdl != NULL)
        {
            TRACFCOMP( g_trac_tce, "testTCE:T17:  Got unexpected error returned");
            TS_FAIL("testTCE:T17: Deallocate got unexpected error");

            errlCommit(errhdl,RUNTIME_COMP_ID);
        }

        TRACFCOMP(g_trac_tce, "testTCE> complete" );
    }



};
#endif
