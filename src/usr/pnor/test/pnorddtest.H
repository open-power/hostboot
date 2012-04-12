//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pnor/test/pnorddtest.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
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
#ifndef __PNORDDTEST_H
#define __PNORDDTEST_H

/**
 *  @file pnorddtest.H
 *
 *  @brief Test case for PNOR Resource Provider
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <pnor/pnorif.H>
#include <devicefw/userif.H>
#include <kernel/console.H>
#include <sys/time.h>
#include "../pnordd.H"
#include <list>
#include <targeting/common/attributes.H>

//$$ #define BASE_SCRATCH_SPACE (3*1024*1024+1024*512)  //3.5MB offset in fake PNOR
#define BASE_SCRATCH_SPACE (3*1024*1024)  //3.0MB offset in fake PNOR

extern trace_desc_t* g_trac_pnor;

/*
 Note - Some of these tests will run against non-singleton instances of the
 PNOR DD to allow full testing of the different operating modes while leaving
 the default mode in place for performance reasons.  That will change when we
 get to a complete PNOR model in sim or hardware.
 */

class PnorDdTest : public CxxTest::TestSuite
{
  public:

    /**
     * @brief PNOR DD readWriteTest
     *        Write some data to PNOR and read it back again
     *        Using fakePNOR scratch space (3.5 - 4 MB)
     */
    void test_readwrite(void)
    {
        TARGETING::Target* l_testTarget =
          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
        size_t l_size = sizeof(uint64_t);
        errlHndl_t l_err = NULL;
        uint64_t fails = 0;
        uint64_t total = 0;

        do{
            TS_TRACE("PnorDdTest::test_readwrite: starting");

            // Perform PnorDD Write 1
            uint64_t l_address = BASE_SCRATCH_SPACE+0x100;
            uint64_t l_writeData = 0x12345678FEEDB0B0;
            l_size = sizeof(uint64_t);
            l_err = deviceWrite(l_testTarget,
                                &l_writeData,
                                l_size,
                                DEVICE_PNOR_ADDRESS(0, l_address));
            total++;
            if (l_err)
            {
                TS_FAIL("PnorDdTest::test_readwrite: PNORDD write 1: deviceWrite() failed! Error committed.");
                errlCommit(l_err,PNOR_COMP_ID);
                fails++;
            }
            total++;
            if(l_size != sizeof(uint64_t))
            {
                TS_FAIL("PnorDdTest::test_readwrite: PNORDD write 1: Write length not expected value. Addr: 0x%llx, Exp: %d, Act: %d", l_address,
                        sizeof(uint64_t), l_size);
                fails++;
            }

            // Perform PnorDD Write 2
            l_address = BASE_SCRATCH_SPACE+0x108;
            l_writeData = 0xFEEDBEEF000ABCDE;
            l_size = sizeof(uint64_t);
            l_err = deviceWrite(l_testTarget,
                                &l_writeData,
                                l_size,
                                DEVICE_PNOR_ADDRESS(0, l_address));
            total++;
            if (l_err)
            {
                TS_FAIL("PnorDdTest::test_readwrite: PNORDD write 2: deviceWrite() failed! Error committed.");
                errlCommit(l_err,PNOR_COMP_ID);
                fails++;
            }
            total++;
            if(l_size != sizeof(uint64_t))
            {
                TS_FAIL("PnorDdTest::test_readwrite: PNORDD write 2: Write length not expected value. Addr: 0x%llx, Exp: %d, Act: %d", l_address,
                        sizeof(uint64_t), l_size);
                fails++;
            }

            // Perform PnorDD read 1
            l_address = BASE_SCRATCH_SPACE+0x100;
            uint64_t l_readData = 0;
            l_size = sizeof(uint64_t);
            l_err = deviceRead(l_testTarget,
                               &l_readData,
                               l_size,
                               DEVICE_PNOR_ADDRESS(0, l_address));
            total++;
            if (l_err)
            {
                TS_FAIL("PnorDdTest::test_readwrite: PNORDD read 1: deviceRead() failed! Error committed.");
                errlCommit(l_err,PNOR_COMP_ID);
                fails++;
            }
            total++;
            if(l_readData != 0x12345678FEEDB0B0)
            {
                TS_FAIL("PnorDdTest::test_readwrite: PNORDD read 1: Read data not expected value. Addr: 0x%llx, ExpData: 0x12345678FEEDB0B0, ActData: 0x%llx",
                        l_address, (long long unsigned)l_readData);
                fails++;
            }
            total++;
            if(l_size != sizeof(uint64_t))
            {
                TS_FAIL("PnorDdTest::test_readwrite: PNORDD read 1: Read length not expected value. Addr: 0x%llx, Exp: %d, Act: %d", l_address,
                        sizeof(uint64_t), l_size);
                fails++;
            }

            // Perform PnorDD read 2
            l_address = BASE_SCRATCH_SPACE+0x108;
            l_size = sizeof(uint64_t);
            l_err = deviceRead(l_testTarget,
                               &l_readData,
                               l_size,
                               DEVICE_PNOR_ADDRESS(0, l_address));
            total++;
            if (l_err)
            {
                TS_FAIL("PnorDdTest::test_readwrite: PNORDD read 2: deviceRead() failed! Error committed.");
                errlCommit(l_err,PNOR_COMP_ID);
                fails++;
            }
            total++;
            if(l_readData != 0xFEEDBEEF000ABCDE)
            {
                TS_FAIL("PnorDdTest::test_readwrite: PNORDD read 2: Read data not expected value. Addr: 0x%llx, ExpData: 0xFEEDBEEF000ABCDE, ActData: 0x%llx",
                        l_address, (long long unsigned)l_readData );
                fails++;
            }
            total++;
            if(l_size != sizeof(uint64_t))
            {
                TS_FAIL("PnorDdTest::test_readwrite: PNORDD read 2: Read length not expected value. Addr: 0x%llx, Exp: %d, Act: %d", l_address,
                        sizeof(uint64_t), l_size);
                fails++;
            }

        }while(0);

        TRACFCOMP(g_trac_pnor, "PnorDdTest::test_readwrite> %d/%d fails", fails, total );

    };

    /**
     * @brief PNOR DD smart write/erase test
     *        Write some data to PNOR to force an erase
     */
    void test_smartwrite(void)
    {
        TARGETING::Target* l_testTarget =
          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
        size_t l_size = sizeof(uint64_t);
        errlHndl_t l_err = NULL;
        uint64_t fails = 0;
        uint64_t total = 0;

        do{
            TS_TRACE("PnorDdTest::test_smartwrite: starting");

            // Perform PnorDD Write 1
            uint64_t l_address = BASE_SCRATCH_SPACE+0x120;
            uint64_t l_writeData = 0xAAAAAAAA55555555;
            l_size = sizeof(uint64_t);
            l_err = deviceWrite(l_testTarget,
                                &l_writeData,
                                l_size,
                                DEVICE_PNOR_ADDRESS(0, l_address));
            total++;
            if (l_err)
            {
                TS_FAIL("PnorDdTest::test_smartwrite: PNORDD write 1: deviceWrite() failed! Error committed.");
                errlCommit(l_err,PNOR_COMP_ID);
                fails++;
            }

            // Perform PnorDD Write 2 - no erase
            l_writeData = 0xAAAAAAAAFFFFFFFF;
            l_size = sizeof(uint64_t);
            l_err = deviceWrite(l_testTarget,
                                &l_writeData,
                                l_size,
                                DEVICE_PNOR_ADDRESS(0, l_address));
            total++;
            if (l_err)
            {
                TS_FAIL("PnorDdTest::test_smartwrite: PNORDD write 2: deviceWrite() failed! Error committed.");
                errlCommit(l_err,PNOR_COMP_ID);
                fails++;
            }

            // Perform PnorDD Write 3 - put some words after the next write
            l_writeData = 0x1234567887654321;
            l_size = sizeof(uint64_t);
            l_err = deviceWrite(l_testTarget,
                                &l_writeData,
                                l_size,
                                DEVICE_PNOR_ADDRESS(0, l_address+sizeof(uint64_t)));
            total++;
            if (l_err)
            {
                TS_FAIL("PnorDdTest::test_smartwrite: PNORDD write 3: deviceWrite() failed! Error committed.");
                errlCommit(l_err,PNOR_COMP_ID);
                fails++;
            }

            // Perform PnorDD Write 4 - requires erase
            l_writeData = 0x8888888811111111;
            l_size = sizeof(uint64_t);
            l_err = deviceWrite(l_testTarget,
                                &l_writeData,
                                l_size,
                                DEVICE_PNOR_ADDRESS(0, l_address));
            total++;
            if (l_err)
            {
                TS_FAIL("PnorDdTest::test_smartwrite: PNORDD write 4: deviceWrite() failed! Error committed.");
                errlCommit(l_err,PNOR_COMP_ID);
                fails++;
            }

            // Perform PnorDD read of the data we just wrote
            uint64_t l_readData = 0;
            l_size = sizeof(uint64_t);
            l_err = deviceRead(l_testTarget,
                               &l_readData,
                               l_size,
                               DEVICE_PNOR_ADDRESS(0, l_address));
            total++;
            if (l_err)
            {
                TS_FAIL("PnorDdTest::test_smartwrite: PNORDD read: deviceRead() failed! Error committed.");
                errlCommit(l_err,PNOR_COMP_ID);
                fails++;
            }
            total++;
            if(l_readData != l_writeData)
            {
                TS_FAIL("PnorDdTest::test_smartwrite: PNORDD read: Read data not expected value. Addr: 0x%llx, ExpData: 0x%llx, ActData: 0x%llx",
                        l_address, l_writeData, l_readData);
                fails++;
            }

            // Perform PnorDD read of the data after what we just wrote
            //   verifies that we restored the rest of the block
            l_readData = 0;
            l_size = sizeof(uint64_t);
            l_err = deviceRead(l_testTarget,
                               &l_readData,
                               l_size,
                               DEVICE_PNOR_ADDRESS(0, l_address+sizeof(uint64_t)));
            total++;
            if (l_err)
            {
                TS_FAIL("PnorDdTest::test_smartwrite: PNORDD read: deviceRead() failed! Error committed.");
                errlCommit(l_err,PNOR_COMP_ID);
                fails++;
            }
            total++;
            if(l_readData != 0x1234567887654321)
            {
                TS_FAIL("PnorDdTest::test_smartwrite: PNORDD read: Read data not expected value. Addr: 0x%llx, ExpData: 0x%llx, ActData: 0x%llx",
                        l_address, 0x1234567887654321, l_readData);
                fails++;
            }

        }while(0);

        TRACFCOMP(g_trac_pnor, "PnorDdTest::test_smartwrite> %d/%d fails", fails, total );
    }

    /**
     * @brief PNOR DD Cross-Block testcase
     *        Access some data that crosses an erase block boundary
     */
    void test_crossblock(void)
    {
        TARGETING::Target* l_testTarget =
          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
        size_t l_size = sizeof(uint64_t);
        errlHndl_t l_err = NULL;
        uint64_t fails = 0;
        uint64_t total = 0;

        do{
            TS_TRACE("PnorDdTest::test_crossblock: starting");

            // Find the nearest erase-block (4K) boundary
            uint64_t l_boundary = (BASE_SCRATCH_SPACE+4096)
                                   - (BASE_SCRATCH_SPACE%4096);
            uint64_t l_address = 0;

            // Perform PnorDD Write 1 - write through boundary
            l_address = l_boundary - sizeof(uint32_t);
            uint64_t l_writeData = 0x6666666699999999;
            l_size = sizeof(uint64_t);
            l_err = deviceWrite(l_testTarget,
                                &l_writeData,
                                l_size,
                                DEVICE_PNOR_ADDRESS(0, l_address));
            total++;
            if (l_err)
            {
                TS_FAIL("PnorDdTest::test_crossblock: PNORDD write 1: deviceWrite() failed! Error committed.");
                errlCommit(l_err,PNOR_COMP_ID);
                fails++;
            }

            // Perform PnorDD Read 1 - verify previous write
            l_address = l_boundary - sizeof(uint32_t);
            uint64_t l_readData = 0x0;
            l_size = sizeof(uint64_t);
            l_err = deviceRead(l_testTarget,
                               &l_readData,
                               l_size,
                               DEVICE_PNOR_ADDRESS(0, l_address));
            total++;
            if (l_err)
            {
                TS_FAIL("PnorDdTest::test_crossblock: PNORDD Read 1: deviceRead() failed! Error committed.");
                errlCommit(l_err,PNOR_COMP_ID);
                fails++;
            }
            total++;
            if(l_readData != l_writeData)
            {
                TS_FAIL("PnorDdTest::test_crossblock: PNORDD read: Read data not expected value. Addr: 0x%.llx, ExpData: 0x%.llx, ActData: 0x%llx", l_address, l_writeData, l_readData);
                fails++;
            }

        }while(0);

        TRACFCOMP(g_trac_pnor, "PnorDdTest::test_crossblock> %d/%d fails", fails, total );
    }

    /**
     * @brief PNOR DD readWriteTest modes
     *        Same as test_readwrite but forcing the use of all supported modes
     */
    void test_readwrite_modes(void)
    {
        PnorDD* pnordd = NULL;
        size_t l_size = sizeof(uint64_t);
        errlHndl_t l_err = NULL;
        uint64_t fails = 0;
        uint64_t total = 0;

        do{
            TS_TRACE("PnorDdTest::test_readwrite_modes: starting");

            // list of all modes to test
            std::list<PnorDD::PnorMode_t> supported_modes;
            supported_modes.push_back(PnorDD::MODEL_MEMCPY);
            supported_modes.push_back(PnorDD::MODEL_LPC_MEM);

            uint64_t scratch_space = BASE_SCRATCH_SPACE;

            // loop through all of the supported modes
            for( std::list<PnorDD::PnorMode_t>::iterator m
                 = supported_modes.begin();
                 m != supported_modes.end();
                 ++m )
            {
                scratch_space += 0x100;

                if( pnordd )
                {
                    delete pnordd;
                }
                pnordd = new PnorDD(*m);

                // Perform PnorDD Write 1
                uint64_t l_address = scratch_space;
                uint64_t l_writeData = 0x12345678FEEDB0B0;
                l_size = sizeof(uint64_t);
                l_err = pnordd->writeFlash(&l_writeData,
                                           l_size,
                                           l_address);
                total++;
                if (l_err)
                {
                    TS_FAIL("PnorDdTest::test_readwrite_modes: PNORDD write 1: writeFlash() failed! Error committed. mode=%d",
                            *m);
                    errlCommit(l_err,PNOR_COMP_ID);
                    fails++;
                }
                total++;
                if(l_size != sizeof(uint64_t))
                {
                    TS_FAIL("PnorDdTest::test_readwrite_modes: PNORDD write 1: Write length not expected value. Addr: 0x%llx, Exp: %d, Act: %d, mode=%d",
                            l_address, sizeof(uint64_t), l_size, *m);
                    fails++;
                }

                // Perform PnorDD Write 2
                l_address = scratch_space+0x08;
                l_writeData = 0xFEEDBEEF000ABCDE;
                l_size = sizeof(uint64_t);
                l_err = pnordd->writeFlash(&l_writeData,
                                           l_size,
                                           l_address);
                total++;
                if (l_err)
                {
                    TS_FAIL("PnorDdTest::test_readwrite_modes: PNORDD write 2: writeFlash() failed! Error committed. mode=%d",
                            *m);
                    errlCommit(l_err,PNOR_COMP_ID);
                    fails++;
                }
                total++;
                if(l_size != sizeof(uint64_t))
                {
                    TS_FAIL("PnorDdTest::test_readwrite_modes: PNORDD write 2: Write length not expected value. Addr: 0x%llx, Exp: %d, Act: %d, mode=%d",
                            l_address, sizeof(uint64_t), l_size, *m);
                    fails++;
                }

                // Perform PnorDD read 1
                l_address = scratch_space;
                uint64_t l_readData = 0;
                l_size = sizeof(uint64_t);
                l_err = pnordd->readFlash(&l_readData,
                                          l_size,
                                          l_address);
                total++;
                if (l_err)
                {
                    TS_FAIL("PnorDdTest::test_readwrite_modes: PNORDD read 1: readFlash() failed! Error committed. mode=%d",
                            *m);
                    errlCommit(l_err,PNOR_COMP_ID);
                    fails++;
                }
                total++;
                if(l_readData != 0x12345678FEEDB0B0)
                {
                    TS_FAIL("PnorDdTest::test_readwrite_modes: PNORDD read 1: Read data not expected value. Addr: 0x%llx, ExpData: 0x12345678FEEDB0B0, ActData: 0x%llx, mode=%d",
                            l_address, (long long unsigned)l_readData, *m);
                    fails++;
                }
                total++;
                if(l_size != sizeof(uint64_t))
                {
                    TS_FAIL("PnorDdTest::test_readwrite_modes: PNORDD read 1: Read length not expected value. Addr: 0x%llx, Exp: %d, Act: %d, mode=%d",
                            l_address, sizeof(uint64_t), l_size, *m);
                    fails++;
                }

                // Perform PnorDD read 2
                l_address = scratch_space+0x08;
                l_size = sizeof(uint64_t);
                l_err = pnordd->readFlash(&l_readData,
                                          l_size,
                                          l_address);
                total++;
                if (l_err)
                {
                    TS_FAIL("PnorDdTest::test_readwrite_modes: PNORDD read 2: readFlash() failed! Error committed. mode=%d",
                            *m);
                    errlCommit(l_err,PNOR_COMP_ID);
                    fails++;
                }
                total++;
                if(l_readData != 0xFEEDBEEF000ABCDE)
                {
                    TS_FAIL("PnorDdTest::test_readwrite_modes: PNORDD read 2: Read data not expected value. Addr: 0x%llx, ExpData: 0xFEEDBEEF000ABCDE, ActData: 0x%llx, mode=%d",
                            l_address, (long long unsigned)l_readData, *m);
                    fails++;
                }
                total++;
                if(l_size != sizeof(uint64_t))
                {
                    TS_FAIL("PnorDdTest::test_readwrite_modes: PNORDD read 2: Read length not expected value. Addr: 0x%llx, Exp: %d, Act: %d, mode=%d",
                            l_address, sizeof(uint64_t), l_size, *m);
                    fails++;
                }
            }

        }while(0);

        TRACFCOMP(g_trac_pnor, "PnorDdTest::test_readwrite_modes> %d/%d fails", fails, total );

        if( pnordd )
        {
            delete pnordd;
        }
    }

    /**
     * @brief PNOR DD smart write/erase test
     *        Same as test_smartwrite but forcing the use of all supported modes
     */
    void test_smartwrite_modes(void)
    {
        PnorDD* pnordd = NULL;
        size_t l_size = sizeof(uint64_t);
        errlHndl_t l_err = NULL;
        uint64_t fails = 0;
        uint64_t total = 0;

        do{
            TS_TRACE("PnorDdTest::test_smartwrite_modes: starting");

            // list of all modes to test
            std::list<PnorDD::PnorMode_t> supported_modes;
            supported_modes.push_back(PnorDD::MODEL_MEMCPY);
            supported_modes.push_back(PnorDD::MODEL_LPC_MEM);

            uint64_t scratch_space = BASE_SCRATCH_SPACE;

            // loop through all of the supported modes
            for( std::list<PnorDD::PnorMode_t>::iterator m
                 = supported_modes.begin();
                 m != supported_modes.end();
                 ++m )
            {
                scratch_space += 0x100;

                if( pnordd )
                {
                    delete pnordd;
                }
                pnordd = new PnorDD(*m);

                // Perform PnorDD Write 1
                uint64_t l_address = scratch_space+0x20;
                uint64_t l_writeData = 0xAAAAAAAA55555555;
                l_size = sizeof(uint64_t);
                l_err = pnordd->writeFlash(&l_writeData,
                                           l_size,
                                           l_address);
                total++;
                if (l_err)
                {
                    TS_FAIL("PnorDdTest::test_smartwrite_modes: PNORDD write 1: writeFlash() failed! Error committed.");
                    errlCommit(l_err,PNOR_COMP_ID);
                    fails++;
                }

                // Perform PnorDD Write 2 - no erase
                l_writeData = 0xAAAAAAAAFFFFFFFF;
                l_size = sizeof(uint64_t);
                l_err = pnordd->writeFlash(&l_writeData,
                                           l_size,
                                           l_address);
                total++;
                if (l_err)
                {
                    TS_FAIL("PnorDdTest::test_smartwrite_modes: PNORDD write 2: writeFlash() failed! Error committed.");
                    errlCommit(l_err,PNOR_COMP_ID);
                    fails++;
                }

                // Perform PnorDD Write 3 - put some words after the next write
                l_writeData = 0x1234567887654321;
                l_size = sizeof(uint64_t);
                l_err = pnordd->writeFlash(&l_writeData,
                                           l_size,
                                           l_address+sizeof(uint64_t));
                total++;
                if (l_err)
                {
                    TS_FAIL("PnorDdTest::test_smartwrite_modes: PNORDD write 3: writeFlash() failed! Error committed.");
                    errlCommit(l_err,PNOR_COMP_ID);
                    fails++;
                }

                // Perform PnorDD Write 4 - requires erase
                l_writeData = 0x8888888811111111;
                l_size = sizeof(uint64_t);
                l_err = pnordd->writeFlash(&l_writeData,
                                           l_size,
                                           l_address);
                total++;
                if (l_err)
                {
                    TS_FAIL("PnorDdTest::test_smartwrite_modes: PNORDD write 4: writeFlash() failed! Error committed.");
                    errlCommit(l_err,PNOR_COMP_ID);
                    fails++;
                }

                // Perform PnorDD read of the data we just wrote
                uint64_t l_readData = 0;
                l_size = sizeof(uint64_t);
                l_err = pnordd->readFlash(&l_readData,
                                          l_size,
                                          l_address);
                total++;
                if (l_err)
                {
                    TS_FAIL("PnorDdTest::test_smartwrite_modes: PNORDD read: readFlash() failed! Error committed.");
                    errlCommit(l_err,PNOR_COMP_ID);
                    fails++;
                }
                total++;
                if(l_readData != l_writeData)
                {
                    TS_FAIL("PnorDdTest::test_smartwrite_modes: PNORDD read: Read data not expected value. Addr: 0x%llx, ExpData: 0x%llx, ActData: 0x%llx",
                            l_address, l_writeData, l_readData);
                    fails++;
                }

                // Perform PnorDD read of the data after what we just wrote
                //   verifies that we restored the rest of the block
                l_readData = 0;
                l_size = sizeof(uint64_t);
                l_err = pnordd->readFlash(&l_readData,
                                          l_size,
                                          l_address+sizeof(uint64_t));
                total++;
                if (l_err)
                {
                    TS_FAIL("PnorDdTest::test_smartwrite_modes: PNORDD read: readFlash() failed! Error committed.");
                    errlCommit(l_err,PNOR_COMP_ID);
                    fails++;
                }
                total++;
                if(l_readData != 0x1234567887654321)
                {
                    TS_FAIL("PnorDdTest::test_smartwrite_modes: PNORDD read: Read data not expected value. Addr: 0x%llx, ExpData: 0x%llx, ActData: 0x%llx",
                            l_address, 0x1234567887654321, l_readData);
                    fails++;
                }
            }

        }while(0);

        if( pnordd )
        {
            delete pnordd;
        }

        TRACFCOMP(g_trac_pnor, "PnorDdTest::test_smartwrite> %d/%d fails", fails, total );
    }

    /**
     * @brief PNOR DD Cross-Block testcase
     *        Same as test_crossblock but forcing the use of all supported modes
     */
    void test_crossblock_modes(void)
    {
        PnorDD* pnordd = NULL;
        size_t l_size = sizeof(uint64_t);
        errlHndl_t l_err = NULL;
        uint64_t fails = 0;
        uint64_t total = 0;

        do{
            TS_TRACE("PnorDdTest::test_crossblock_modes: starting");

            // list of all modes to test
            std::list<PnorDD::PnorMode_t> supported_modes;
            supported_modes.push_back(PnorDD::MODEL_MEMCPY);
            supported_modes.push_back(PnorDD::MODEL_LPC_MEM);

            uint64_t scratch_space = BASE_SCRATCH_SPACE;

            // loop through all of the supported modes
            for( std::list<PnorDD::PnorMode_t>::iterator m
                 = supported_modes.begin();
                 m != supported_modes.end();
                 ++m )
            {
                scratch_space += 4096;

                if( pnordd )
                {
                    delete pnordd;
                }
                pnordd = new PnorDD(*m);

                // Find the nearest erase-block (4K) boundary
                uint64_t l_boundary = (BASE_SCRATCH_SPACE+4096)
                  - (BASE_SCRATCH_SPACE%4096);
                uint64_t l_address = 0;

                // Perform PnorDD Write 1 - write through boundary
                l_address = l_boundary - sizeof(uint32_t);
                uint64_t l_writeData = 0x6666666699999999;
                l_size = sizeof(uint64_t);
                l_err = pnordd->writeFlash(&l_writeData,
                                           l_size,
                                           l_address);
                total++;
                if (l_err)
                {
                    TS_FAIL("PnorDdTest::test_crossblock_modes: PNORDD write 1: writeFlash() failed! Error committed.");
                    errlCommit(l_err,PNOR_COMP_ID);
                    fails++;
                }

                // Perform PnorDD Read 1 - verify previous write
                l_address = l_boundary - sizeof(uint32_t);
                uint64_t l_readData = 0x0;
                l_size = sizeof(uint64_t);
                l_err = pnordd->readFlash(&l_readData,
                                          l_size,
                                          l_address);
                total++;
                if (l_err)
                {
                    TS_FAIL("PnorDdTest::test_crossblock_modes: PNORDD Read 1: readFlash() failed! Error committed.");
                    errlCommit(l_err,PNOR_COMP_ID);
                    fails++;
                }
                total++;
                if(l_readData != l_writeData)
                {
                    TS_FAIL("PnorDdTest::test_crossblock_modes: PNORDD read: Read data not expected value. Addr: 0x%.llx, ExpData: 0x%.llx, ActData: 0x%llx", l_address, l_writeData, l_readData);
                    fails++;
                }
            }
        }while(0);

        if( pnordd )
        {
            delete pnordd;
        }

        TRACFCOMP(g_trac_pnor, "PnorDdTest::test_crossblock_modes> %d/%d fails", fails, total );
    }


};

/*Not really a real test, just using to verify ext image is loading properly.
Leaving it commented out because the test-case will not dynamically find the extended image based on the TOC
//    void testPnorDD2(void)
    {

      TARGETING::Target* l_testTarget = MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
      size_t l_size = sizeof(uint64_t);
      errlHndl_t l_err = NULL;

      do{
        TS_TRACE("testPnorDD2: starting");

        //Read fakeext data
        uint64_t l_address = 0x690;
        uint64_t l_readData = 0;
        l_err = deviceRead(l_testTarget,
                           &l_readData,
                           l_size,
                           DEVICE_PNOR_ADDRESS(0, l_address);
        if (l_err)
            {
          TS_FAIL("testPnorDD2: PNORDD read fakeext: deviceRead() failed! Error committed.");
          break;
            }
        else
            {
          TS_TRACE("testPnorDD2: PNORDD read fakeext, Address 0x%llx, Data %llx",
                   l_address,
                   (long long unsigned)l_readData);
            }

        //Read fakeext data
        l_address = 0x698;
        l_readData = 0;
        l_err = deviceRead(l_testTarget,
                           &l_readData,
                           l_size,
                           DEVICE_PNOR_ADDRESS(0, l_address);
        if (l_err)
            {
          TS_FAIL("testPnorDD2: PNORDD read fakeext: deviceRead() failed! Error committed.");
          break;
            }
        else
            {
          TS_TRACE("testPnorDD2: PNORDD read fakeext, Address 0x%llx, Data %llx",
                   l_address,
                   (long long unsigned)l_readData);
            }


          }while(0);


          //@TODO: Add total fail/pass count trace to know how many passed.

    };

*/


#endif
