/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/kernel/ptmgrtest.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2022                        */
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
#ifndef __PTMGRTEST_H
#define __PTMGRTEST_H
/**
 *  @file ptmgr.H
 *
 *  @brief Test cases for the Page Table Manager
*/
#include <cxxtest/TestSuite.H>
#include <arch/ppc.H>
#include <sys/time.h>
#include <kernel/ptmgr.H>
#include <kernel/console.H>

//#define PASS_TRACE(args...) TS_TRACE(args)
#define PASS_TRACE(args...)

typedef struct pte_test_t {
    uint64_t va;
    uint64_t hash;
    uint64_t page;
    bool loaded;
    bool delrangeva;
} pte_test_t;


const pte_test_t TEST_DATA[] = {
    { 0x0000000000000100,  0x0000000000000000,  100,  true,   false }, // Page 0
    { 0x000000000053C008,  0x000000000000053C,  101,  true,   false }, // Something on the heap
    { 0x0000000035004000,  0x0000000000035004,  102,  true,   false }, // <1TB
    { 0x0000000040000000,  0x0000000000040000,  103,  true,   false }, // 1TB
    { 0x0000000066666660,  0x0000000000066666,  104,  true,   false }, // 1TB < x < 2TB
    { 0x0000000080000000,  0x0000000000080000,  105,  true,   false }, // 2TB
    { 0x0000000080002000,  0x0000000000080002,  106,  true,   true  }, // 2TB + 2 4K pages
    { 0x0000000088888880,  0x0000000000088888,  107,  true,   false }, // 2TB < x < 3TB
    { 0x00000000C0005000,  0x00000000000C0005,  108,  true,   false }, // >3TB
    { 0x0000000040001FF8,  0x0000000000040001,  109,  true,   false }, // just before a page boundary

    //2 addresses in the same page
    { 0x0000000090000040,  0x0000000000090000,  110,  true,   false  },
    { 0x0000000090000100,  0x0000000000090000,  110,  true,   false  },

    //Out of range address (too big) ??
    { 0x0040000000000000,  0x0000000000004000,  111,  true,   false  },

    //Several addresses with the same PTEG, enough to overflow a PTEG
    { 0x0000000080803000,  0x0000000000080803,  112,  false,  true  }, // 2TB+8MB+12K
    { 0x0000000081003000,  0x0000000000081003,  113,  true,   true  }, // 2TB+16MB+12K
    { 0x0000000082003000,  0x0000000000082003,  114,  true,   true  }, // 2TB+32MB+12K
    { 0x0000000084003000,  0x0000000000084003,  115,  true,   true  }, // 2TB+64MB+12K
    { 0x0000000084803000,  0x0000000000084803,  116,  true,   true  }, // 2TB+72MB+12K
    { 0x0000000085003000,  0x0000000000085003,  117,  true,   true  }, // 2TB+80MB+12K
    { 0x0000000085803000,  0x0000000000085803,  118,  true,   false }, // 2TB+88MB+12K
    { 0x0000000086003000,  0x0000000000086003,  119,  true,   false }, // 2TB+96MB+12K
    { 0x0000000086803000,  0x0000000000086803,  120,  true,   false }, // 2TB+124MB+12K
};


class ptmgrtest : public CxxTest::TestSuite
{
  private:
    enum {
        VA_RANGE_START  = 0x0000000080001000,
        VA_RANGE_FINISH = 0x0000000085800000,

        PN_RANGE_START  = 107,
        PN_RANGE_FINISH = 115,
    };

  public:

    /**
     *  1) Generate hash values for a range of addresses
     *  2) Verify hash against hardcoded expected results
     */
    void test_hash40( void )
    {
        TS_TRACE( ">> ptmgrtest::test_hash40 <<" );
        uint64_t fails = 0, total = 0;

        // Initialize the Page Table
        PageTableManager* ptmgr = new PageTableManager(true);

        // test the hashes
        uint64_t hash = 0;
        for( uint64_t x = 0; x < (sizeof(TEST_DATA)/sizeof(TEST_DATA[0])); x++ )
        {
            hash = ptmgr->computeHash( TEST_DATA[x].va );
            if( TEST_DATA[x].hash != hash )
            {
                TS_FAIL( "ptmgrtest::test_hash40> ERROR : Hash mismatch" );
                printkd( "VA=0x%.16lX, Exp: %.16lX, Act: %.16lX\n", TEST_DATA[x].va, TEST_DATA[x].hash, hash );
                fails++;
            }
            else
            {
                PASS_TRACE( "ptmgrtest::test_hash40> PASS : 0x%.16lX", TEST_DATA[x].va );
            }
            total++;
        }

        delete ptmgr;

        TS_TRACE( "ptmgrtest::test_hash40> fails=%d/%d", fails, total );
    }

    /**
     *  1) Initialize a local Page Table
     *  2) Add some PTEs
     *  3) Verify the PTE we just added is in the Page Table
     *  4) Verify expected PTEs are still in the Page Table
     */
    void test_addEntry( void )
    {
        TS_TRACE( ">> ptmgrtest::test_addEntry <<" );
        uint64_t fails = 0;
        uint64_t total = 0;
        uint64_t status = 0;
        uint64_t pn = 0;

        // 1) Initialize the Page Table
        PageTableManager* ptmgr = new PageTableManager(true);

        for( uint64_t x = 0; x < (sizeof(TEST_DATA)/sizeof(TEST_DATA[0])); x++ )
        {
            // 2) Add some PTEs
            ptmgr->_addEntry( TEST_DATA[x].va, TEST_DATA[x].page, WRITABLE );

            // 3) Verify the PTE we just added is in the Page Table
            status = ptmgr->_getStatus( TEST_DATA[x].va, pn );
            if( !(status & PageTableManager::PTE_PRESENT) )
            {
                TS_FAIL( "ptmgrtest::test_addEntry> ERROR1 : entry not found" );
                TS_TRACE( "Addr=%.16lX, Status=%.16lX", TEST_DATA[x].va, status );
                fails++;
            }
            else if( (status & PageTableManager::PTE_VALID)
                     && (pn == TEST_DATA[x].page) )
            {
                PASS_TRACE( "ptmgrtest::test_addEntry> PASS1 : 0x%.16lX", TEST_DATA[x].va );

		PageTableManager::PageTableEntry* pte = ptmgr->findPTE(TEST_DATA[x].va);
		uint64_t va = ptmgr->getVirtAddrFromPTE(pte);
		if( va != (TEST_DATA[x].va - TEST_DATA[x].va%4096) )
		{
		    TS_FAIL( "ptmgrtest::test_addEntry> ERROR6 : VA doesn't match expected" );
		    TS_TRACE( "Exp=%.16lX, Act=%.16lX", TEST_DATA[x].va, va );
		    fails++;
		}
		total++;
            }
            else
            {
                TS_FAIL( "ptmgrtest::test_addEntry> ERROR2 : unknown error" );
                TS_TRACE( "Addr=%.16lX, Status=%.16lX", TEST_DATA[x].va, status );
                fails++;
            }
            total++;
        }

        // 4) Verify expected PTEs are still in the Page Table
        //PRINT_PT;

        status = PageTableManager::PTE_UNKNOWN;
        for( uint64_t x = 0; x < (sizeof(TEST_DATA)/sizeof(TEST_DATA[0])); x++ )
        {
            status = ptmgr->_getStatus( TEST_DATA[x].va, pn );

            if( !(status & PageTableManager::PTE_PRESENT) && TEST_DATA[x].loaded )
            {
                TS_FAIL( "ptmgrtest::test_addEntry> ERROR3 : entry not found" );
                TS_TRACE( "Addr=%.16lX, Status=%.16lX, Exp Page=%ld", TEST_DATA[x].va, status, TEST_DATA[x].page );
                fails++;
            }
            else if( (status & PageTableManager::PTE_VALID)
                     && !TEST_DATA[x].loaded )
            {
                TS_FAIL( "ptmgrtest::test_addEntry> ERROR4 : PTE should be unloaded" );
                TS_TRACE( "Addr=%.16lX, Status=%.16lX", TEST_DATA[x].va, status );
                TS_TRACE( "Exp Page = %ld, Act Page = %ld", TEST_DATA[x].page, pn );
                fails++;
            }
            else if( (status & PageTableManager::PTE_VALID)
                     && (pn == TEST_DATA[x].page)
                     && TEST_DATA[x].loaded )
            {
                PASS_TRACE( "ptmgrtest::test_addEntry> PASS2 : 0x%.16lX", TEST_DATA[x].va );
            }
            else if( !(status & PageTableManager::PTE_VALID)
                     && !TEST_DATA[x].loaded )
            {
                PASS_TRACE( "ptmgrtest::test_addEntry> PASS3 : 0x%.16lX", TEST_DATA[x].va );
            }
            else
            {
                TS_FAIL( "ptmgrtest::test_addEntry> ERROR5 : unknown error" );
                TS_TRACE( "Addr=%.16lX, Status=%.16lX", TEST_DATA[x].va, status );
                TS_TRACE( "Exp Page = %ld, Act Page = %ld", TEST_DATA[x].page, pn );
                fails++;
            }
            total++;
        }

        // delete our local table
        delete ptmgr;

        TS_TRACE( "ptmgrtest::test_addEntry> fails=%d/%d", fails, total );
    }

    /**
     *  1) Initialize a local Page Table
     *  2) Add the idle task's PTE
     *  3) Add some PTEs that match the idle task's PTEG
     *  4) Verify the PTE we just added is in the Page Table
     *  5) Verify idle PTE is still in the Page Table
     */
    void test_pinIdle( void )
    {
        TS_INFO( ">> ptmgrtest::test_pinIdle <<" );
        uint64_t fails = 0;
        uint64_t total = 0;
        uint64_t status = 0;
        uint64_t pn = 0;

        // 1) Initialize the Page Table
        PageTableManager* ptmgr = new PageTableManager(true);

        // 2) Add the idle task's PTE
        TS_INFO("Adding Idle va=%X pn=%X", ptmgr->ivIdleTaskFunction, ptmgr->ivIdleTaskPN );
        ptmgr->_addEntry( ptmgr->ivIdleTaskFunction, ptmgr->ivIdleTaskPN, EXECUTABLE );

        // Verify the PTE we just added is in the Page Table
        status = ptmgr->_getStatus( ptmgr->ivIdleTaskFunction, pn );
        if( !(status & PageTableManager::PTE_PRESENT) )
        {
            TS_FAIL( "ptmgrtest::test_pinIdle> ERROR1 : idle entry not found" );
            fails++;
        }
        else if( (status & PageTableManager::PTE_VALID)
                 && (pn == ptmgr->ivIdleTaskPN) )
        {
            PASS_TRACE( "ptmgrtest::test_pinIdle> PASS1 : 0x%.16lX", ptmgr->ivIdleTaskFunction );

            PageTableManager::PageTableEntry* pte = ptmgr->findPTE(ptmgr->ivIdleTaskFunction);
            uint64_t va = ptmgr->getVirtAddrFromPTE(pte);
            if( va != (ptmgr->ivIdleTaskFunction - ptmgr->ivIdleTaskFunction%4096) )
            {
                TS_FAIL( "ptmgrtest::test_pinIdle> ERROR2 : Idle VA doesn't match expected" );
                TS_INFO( "Exp=%.16lX, Act=%.16lX", ptmgr->ivIdleTaskFunction, va );
                fails++;
            }
            total++;

            // force the idle task PTE to a high LRU to make it a good
            // target to steal
            pte->LRU = 0b11;
        }
        else
        {
            TS_FAIL( "ptmgrtest::test_pinIdle> ERROR3 : unknown error adding idle PTE" );
            TS_INFO( "Addr=%.16lX, Status=%.16lX", ptmgr->ivIdleTaskFunction, status );
            fails++;
        }


        // 3) Add some PTEs that match the idle task's PTEG
        for( uint64_t x = 1; x < 10; x++ )
        {
            // PTEs repeat at 1 TB and 8 MB boundaries
            uint64_t offsets[2] = { x*TERABYTE, x*8*MEGABYTE };
            for( uint64_t v = 0; v < 2; v++ )
            {
                uint64_t x_va = ptmgr->ivIdleTaskFunction | offsets[v];
                uint64_t x_pn = x*100+v;
                TS_INFO("Adding va=%X pn=%X", x_va, x_pn );
                ptmgr->_addEntry( x_va, x_pn, WRITABLE );

                // 4) Verify the PTE we just added is in the Page Table
                status = ptmgr->_getStatus( x_va, pn );
                if( !(status & PageTableManager::PTE_PRESENT) )
                {
                    TS_FAIL( "ptmgrtest::test_pinIdle> ERROR4 : entry not found" );
                    TS_INFO( "Addr=%.16lX, Status=%.16lX", x_va, status );
                    fails++;
                }
                else if( (status & PageTableManager::PTE_VALID)
                         && (pn == x_pn) )
                {
                    PASS_TRACE( "ptmgrtest::test_pinIdle> PASS2 : 0x%.16lX", x_va );

                    PageTableManager::PageTableEntry* pte = ptmgr->findPTE(x_va);
                    uint64_t va = ptmgr->getVirtAddrFromPTE(pte);
                    if( va != (x_va - x_va%4096) )
                    {
                        TS_FAIL( "ptmgrtest::test_pinIdle> ERROR5 : VA doesn't match expected" );
                        TS_INFO( "Exp=%.16lX, Act=%.16lX", x_va, va );
                        fails++;
                    }
                    total++;
                }
                else
                {
                    TS_FAIL( "ptmgrtest::test_pinIdle> ERROR6 : unknown error" );
                    TS_INFO( "Addr=%.16lX, Status=%.16lX, PN=0x%lX", x_va, status, pn );
                    fails++;
                }
                total++;
            }
        }

        // 5) Verify idle PTE is still in the Page Table
        //PRINT_PT;
        status = ptmgr->_getStatus( ptmgr->ivIdleTaskFunction, pn );
        if( !(status & PageTableManager::PTE_PRESENT) )
        {
            TS_FAIL( "ptmgrtest::test_pinIdle> ERROR7 : idle entry not found" );
            fails++;
        }
        else if( (status & PageTableManager::PTE_VALID)
                 && (pn == ptmgr->ivIdleTaskPN) )
        {
            PASS_TRACE( "ptmgrtest::test_pinIdle> PASS3 : 0x%.16lX", ptmgr->ivIdleTaskFunction );

            PageTableManager::PageTableEntry* pte = ptmgr->findPTE(ptmgr->ivIdleTaskFunction);
            uint64_t va = ptmgr->getVirtAddrFromPTE(pte);
            if( va != (ptmgr->ivIdleTaskFunction - ptmgr->ivIdleTaskFunction%4096) )
            {
                TS_FAIL( "ptmgrtest::test_pinIdle> ERROR8 : Idle VA doesn't match expected" );
                TS_INFO( "Exp=%.16lX, Act=%.16lX", ptmgr->ivIdleTaskFunction, va );
                fails++;
            }
            total++;

            // force the idle task PTE to a high LRU to make it a good
            // target to steal
            pte->LRU = 0b11;
        }
        else
        {
            TS_FAIL( "ptmgrtest::test_pinIdle> ERROR9 : unknown error adding idle PTE" );
            TS_INFO( "Addr=%.16lX, Status=%.16lX", ptmgr->ivIdleTaskFunction, status );
            fails++;
        }


        // delete our local table
        delete ptmgr;

        TS_INFO( "ptmgrtest::test_pinIdle> fails=%d/%d", fails, total );
    }

    /**
     *  1) Initialize the Page Table
     *  2) Populate the Page Table
     *  3) Remove PTEs one at a time and verify they have been removed
     */
    void test_delEntry( void )
    {
        TS_TRACE( ">> ptmgrtest::test_delEntry <<" );
        uint64_t fails = 0;
        uint64_t total = 0;
        uint64_t ignored = 0;

        // 1) Initialize the Page Table
        PageTableManager* ptmgr = new PageTableManager(true);

        // 2) Populate the Page Table
        fillTable(ptmgr);
        //ptmgr->_printPT();

        // 3) Remove PTEs one at a time and verify they have been removed
        for( uint64_t x = 0; x < (sizeof(TEST_DATA)/sizeof(TEST_DATA[0])); x++ )
        {
            ptmgr->_delEntry( TEST_DATA[x].va );

            uint64_t status = ptmgr->_getStatus( TEST_DATA[x].va, ignored );
            if( status & PageTableManager::PTE_VALID )
            {
                TS_FAIL( "ptmgrtest::test_delEntry> ERROR : entry still present!" );
                printkd( "VA = %.16lX\n", TEST_DATA[x].va );
                PageTableManager::printPTE( TEST_DATA[x].va, true );
                fails++;
            }
            else
            {
                PASS_TRACE( "ptmgrtest::test_delEntry> PASS : 0x%.16lX", TEST_DATA[x].va );
            }
            total++;
        }

        // should print out an empty table
        //ptmgr->_printPT();

        delete ptmgr;

        TS_TRACE( "ptmgrtest::test_delEntry> fails=%d/%d", fails, total );
    }

    /**
     *  1) Initialize the Page Table
     *  2) Populate the Page Table
     *  3) Remove a range of PTEs
     *  4) Verify they have been removed
     */
    void test_delRangeVA( void )
    {
        TS_TRACE( ">> ptmgrtest::test_delRangeVA <<" );
        uint64_t fails = 0;
        uint64_t total = 0;
        uint64_t ignored = 0;

        // 1) Initialize the Page Table
        PageTableManager* ptmgr = new PageTableManager(true);

        // 2) Populate the Page Table
        fillTable(ptmgr);
        //ptmgr->_printPT();

        // 3) Remove a range of PTEs
        ptmgr->_delRangeVA( VA_RANGE_START, VA_RANGE_FINISH );

        // 4) Verify they have been removed
        for( uint64_t x = 0; x < (sizeof(TEST_DATA)/sizeof(TEST_DATA[0])); x++ )
        {
            if( TEST_DATA[x].loaded )
            {
                uint64_t status = ptmgr->_getStatus( TEST_DATA[x].va, ignored );
                if( (status & PageTableManager::PTE_VALID) && TEST_DATA[x].delrangeva )
                {
                    TS_FAIL( "ptmgrtest::test_delRangeVA> ERROR1 : entry still present" );
                    printkd( "addr = %.16lX\n", TEST_DATA[x].va );
                    PageTableManager::printPTE( TEST_DATA[x].va, false );
                    fails++;
                }
                else if( !(status & PageTableManager::PTE_VALID) && !TEST_DATA[x].delrangeva )
                {
                    TS_FAIL( "ptmgrtest::test_delRangeVA> ERROR2 : deleted a wrong entry" );
                    printkd( "addr = %.16lX\n", TEST_DATA[x].va );
                    PageTableManager::printPTE( TEST_DATA[x].va, false );
                    fails++;
                }
                else
                {
                    PASS_TRACE( "%s> PASS : 0x%.16lX\n", __FUNCTION__, TEST_DATA[x].va );
                }
                total++;
            }
        }

        //ptmgr->_printPT();

        delete ptmgr;

        TS_TRACE( "ptmgrtest::test_delRangeVA> fails=%d/%d", fails, total );
    }

    /**
     *  1) Initialize the Page Table
     *  2) Populate the Page Table
     *  3) Remove a range of PTEs
     *  4) Verify they have been removed
     */
    void test_delRangePN( void )
    {
        TS_TRACE( ">> ptmgrtest::test_delRangePN <<" );
        uint64_t fails = 0;
        uint64_t total = 0;
        uint64_t pagenum = 0;

        // 1) Initialize the Page Table
        PageTableManager* ptmgr = new PageTableManager(true);

        // 2) Populate the Page Table
        fillTable(ptmgr);
        //ptmgr->_printPT();

        // 3) Remove a range of PTEs
        ptmgr->_delRangePN( PN_RANGE_START, PN_RANGE_FINISH );

        // 4) Verify they have been removed
        for( uint64_t x = 0; x < (sizeof(TEST_DATA)/sizeof(TEST_DATA[0])); x++ )
        {
            if( TEST_DATA[x].loaded )
            {
                uint64_t status = ptmgr->_getStatus( TEST_DATA[x].va, pagenum );
                if( (status & PageTableManager::PTE_VALID)
                    && (pagenum >= PN_RANGE_START)
                    && (pagenum <= PN_RANGE_FINISH) )
                {
                    TS_FAIL( "ptmgrtest::test_delRangePN> ERROR1 : entry still present" );
                    printkd( "addr = %.16lX, page=%ld\n", TEST_DATA[x].va, pagenum );
                    PageTableManager::printPTE( TEST_DATA[x].va, false );
                    fails++;
                }
                else if( !(status & PageTableManager::PTE_VALID)
                         && (pagenum < PN_RANGE_START)
                         && (pagenum > PN_RANGE_FINISH) )
                {
                    TS_FAIL( "ptmgrtest::test_delRangePN> ERROR2 : deleted a wrong entry" );
                    printkd( "addr = %.16lX, page=%ld\n", TEST_DATA[x].va, pagenum );
                    PageTableManager::printPTE( TEST_DATA[x].va, false );
                    fails++;
                }
                else
                {
                    PASS_TRACE( "%s> PASS : 0x%.16lX\n", __FUNCTION__, TEST_DATA[x].va );
                }
                total++;
            }
        }

        //ptmgr->_printPT();

        delete ptmgr;

        TS_TRACE( "ptmgrtest::test_delRangePN> fails=%d/%d", fails, total );
    }

    //@todo - Test LRU

    //@todo - Test propagation of C/R bits to blocks

  private:
    /**
     * @brief  Populate the table with entries
     */
    void fillTable( PageTableManager* ptmgr )
    {
        for( uint64_t x = 0; x < (sizeof(TEST_DATA)/sizeof(TEST_DATA[0])); x++ )
        {
            // 2) Add some PTEs
	  ptmgr->_addEntry( TEST_DATA[x].va, TEST_DATA[x].page, WRITABLE );
        }
    }

};


#endif
