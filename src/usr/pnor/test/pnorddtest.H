/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/test/pnorddtest.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2014                        */
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
#include <pnor/pnor_reasoncodes.H>
#include <devicefw/userif.H>
#include <kernel/console.H>
#include <sys/time.h>
#include "../pnordd.H"
#include "../pnorrp.H"
#include <list>
#include <targeting/common/attributes.H>

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

    bool getTestSection(uint64_t &o_physAddr, uint64_t &o_size)
    {
        errlHndl_t l_err = NULL;
        PNOR::SectionInfo_t info;
        uint64_t chip_select = 0xF;
        bool needs_ecc = false;
        bool section_found = false;

        do{

            // Get SPD PNOR section info from PNOR RP
            l_err = PNOR::getSectionInfo( PNOR::TEST,
                                          info );
            if(l_err)
            {
                if(l_err->reasonCode() == PNOR::RC_INVALID_SECTION)
                {
                    //This is expected in some configurations, so just delete it.
                    delete l_err;
                }
                else
                {
                    //Any other type of error is not expected, so commit it.
                    errlCommit(l_err,PNOR_COMP_ID);
                }
                break;
            }

            l_err = PnorRP::getInstance().computeDeviceAddr((void*)info.vaddr,
                                                            o_physAddr,
                                                            chip_select,
                                                            needs_ecc);
            if(l_err)
            {
                errlCommit(l_err,PNOR_COMP_ID);
                break;
            }

            o_size = info.size;
            section_found = true;

        }while(0);

        return section_found;
    }

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

            uint64_t base_address;
            uint64_t sect_size;
            if(!getTestSection(base_address, sect_size))
            {
                TRACFCOMP(g_trac_pnor, "PnorDdTest::test_readwrite> Skipped due to not finding test section in PNOR" );
                break;
            }

            // Perform PnorDD Write 1

            uint64_t l_address = base_address+0x100;
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
            l_address = base_address+0x108;
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
            l_address = base_address+0x100;
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
            l_address = base_address+0x108;
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
            uint64_t base_address;
            uint64_t sect_size;
            if(!getTestSection(base_address, sect_size))
            {
                TRACFCOMP(g_trac_pnor, "PnorDdTest::test_smartwrite> Skipped due to not finding test section in PNOR" );
                break;
            }

            uint64_t l_address = base_address+0x120;
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

            uint64_t base_address;
            uint64_t sect_size;
            if(!getTestSection(base_address, sect_size))
            {
                TRACFCOMP(g_trac_pnor, "PnorDdTest::test_readwrite> Skipped due to not finding test section in PNOR" );
                break;
            }

            // Find the nearest erase-block (4K) boundary
            uint64_t l_boundary = (base_address+4096)
                                   - (base_address%4096);
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
        uint8_t* fake_space = NULL;
        size_t l_size = sizeof(uint64_t);
        errlHndl_t l_err = NULL;
        uint64_t fails = 0;
        uint64_t total = 0;
        uint64_t scratch_space = 0;
        uint64_t sect_size = 0;

        do{
            TS_TRACE("PnorDdTest::test_readwrite_modes: starting");

            // list of all modes to test
            std::list<PnorDD::PnorMode_t> supported_modes;
            supported_modes.push_back(PnorDD::MODEL_MEMCPY);
            supported_modes.push_back(PnorDD::MODEL_LPC_MEM);

            if(!TARGETING::is_vpo())
            {
                TRACFCOMP(g_trac_pnor, "PnorDdTest::test_readwrite_modes> Adding REAL_CMD & MODEL_REAL_MMIO modes");
                supported_modes.push_back(PnorDD::MODEL_REAL_CMD);
                supported_modes.push_back(PnorDD::MODEL_REAL_MMIO);
            }

            // loop through all of the supported modes
            for( std::list<PnorDD::PnorMode_t>::iterator m
                 = supported_modes.begin();
                 m != supported_modes.end();
                 ++m )
            {
                if( pnordd )
                {
                    delete pnordd;
                }

                //Fake PNOR
                if( (PnorDD::MODEL_MEMCPY == *m) ||
                    (PnorDD::MODEL_LPC_MEM == *m) )
                {
                    //malloc some space to use as fake-PNOR
                    if( fake_space )
                    {
                        delete fake_space;
                    }
                    fake_space = new uint8_t[4 * KILOBYTE];
                    pnordd = new PnorDD(*m,
                                        reinterpret_cast<uint64_t>(fake_space),
                                        (4 * KILOBYTE));
                    //Adjusting the address by an arbitrary multiplier to keep
                    //successive tests from always using the same memory space.
                    scratch_space = (*m)*0x20;
                }
                //Real PNOR
                else
                {
                    pnordd = new PnorDD(*m);

                    if(!getTestSection(scratch_space, sect_size))
                    {
                        TRACFCOMP(g_trac_pnor,
                                  "PnorDdTest::test_readwrite_modes> Skipped due to not finding test section in PNOR" );
                        continue;
                    }
                    //Adjusting the address by an arbitrary multiplier to keep
                    //successive tests from always using the same memory space.
                    scratch_space += (*m)*0x20;
                }

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
        if( fake_space )
        {
            delete fake_space;
        }

    }

    /**
     * @brief PNOR DD smart write/erase test
     *        Same as test_smartwrite but forcing the use of all supported modes
     */
    void test_smartwrite_modes(void)
    {
        PnorDD* pnordd = NULL;
        uint8_t* fake_space = NULL;
        size_t l_size = sizeof(uint64_t);
        errlHndl_t l_err = NULL;
        uint64_t fails = 0;
        uint64_t total = 0;
        uint64_t scratch_space = 0;
        uint64_t sect_size = 0;

        do{
            TS_TRACE("PnorDdTest::test_smartwrite_modes: starting");

            // list of all modes to test
            std::list<PnorDD::PnorMode_t> supported_modes;
            supported_modes.push_back(PnorDD::MODEL_MEMCPY);
            supported_modes.push_back(PnorDD::MODEL_LPC_MEM);

            if(!TARGETING::is_vpo())
            {
                TRACFCOMP(g_trac_pnor, "PnorDdTest::test_smartwrite_modes> Adding REAL_CMD & MODEL_REAL_MMIO modes");
                supported_modes.push_back(PnorDD::MODEL_REAL_CMD);
                supported_modes.push_back(PnorDD::MODEL_REAL_MMIO);
            }

            // loop through all of the supported modes
            for( std::list<PnorDD::PnorMode_t>::iterator m
                 = supported_modes.begin();
                 m != supported_modes.end();
                 ++m )
            {
                if( pnordd )
                {
                    delete pnordd;
                }

                //Fake PNOR
                if( (PnorDD::MODEL_MEMCPY == *m) ||
                    (PnorDD::MODEL_LPC_MEM == *m) )
                {
                    //malloc some space to use as fake-PNOR
                    if( fake_space )
                    {
                        delete fake_space;
                    }
                    fake_space = new uint8_t[4 * KILOBYTE];
                    pnordd = new PnorDD(*m,
                                        reinterpret_cast<uint64_t>(fake_space),
                                        (4 * KILOBYTE));

                    //Adjusting the address by an arbitrary multiplier to keep
                    //successive tests from always using the same memory space.
                    scratch_space = (*m)*0x30;

                }
                //Real PNOR
                else
                {
                    pnordd = new PnorDD(*m);

                    if(!getTestSection(scratch_space, sect_size))
                    {
                        TRACFCOMP(g_trac_pnor,
                                  "PnorDdTest::test_readwrite_modes> Skipped due to not finding test section in PNOR" );
                        continue;
                    }
                    //Adjusting the address by an arbitrary multiplier to keep
                    //successive tests from always using the same memory space.
                    scratch_space += (*m)*0x30;
                }

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
        if( fake_space )
        {
            delete fake_space;
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
        uint8_t* fake_space = NULL;
        size_t l_size = sizeof(uint64_t);
        errlHndl_t l_err = NULL;
        uint64_t fails = 0;
        uint64_t total = 0;
        uint64_t scratch_space = 0;
        uint64_t sect_size = 0;

        do{
            TS_TRACE("PnorDdTest::test_crossblock_modes: starting");

            // list of all modes to test
            std::list<PnorDD::PnorMode_t> supported_modes;
            supported_modes.push_back(PnorDD::MODEL_MEMCPY);
            supported_modes.push_back(PnorDD::MODEL_LPC_MEM);

            if(!TARGETING::is_vpo())
            {
                TRACFCOMP(g_trac_pnor, "PnorDdTest::test_crossblock_modes> Adding REAL_CMD & MODEL_REAL_MMIO mode");
                supported_modes.push_back(PnorDD::MODEL_REAL_CMD);
                supported_modes.push_back(PnorDD::MODEL_REAL_MMIO);
            }

            // loop through all of the supported modes
            for( std::list<PnorDD::PnorMode_t>::iterator m
                 = supported_modes.begin();
                 m != supported_modes.end();
                 ++m )
            {
                if( pnordd )
                {
                    delete pnordd;
                }


                //Fake PNOR
                if( (PnorDD::MODEL_MEMCPY == *m) ||
                    (PnorDD::MODEL_LPC_MEM == *m) )
                {
                    //malloc some space to use as fake-PNOR
                    if( fake_space )
                    {
                        delete fake_space;
                    }
                    fake_space = new uint8_t[8 * KILOBYTE];
                    pnordd = new PnorDD(*m,
                                        reinterpret_cast<uint64_t>(fake_space),
                                        (8 * KILOBYTE));
                    scratch_space = 0;
                    sect_size = 8 * KILOBYTE;
                }
                //Real PNOR
                else
                {
                    pnordd = new PnorDD(*m);

                    if(!getTestSection(scratch_space, sect_size))
                    {
                        TRACFCOMP(g_trac_pnor,
                                  "PnorDdTest::test_readwrite_modes> Skipped due to not finding test section in PNOR" );
                        continue;
                    }
                }

                // Find the nearest erase-block (4K) boundary
                uint64_t l_boundary = (scratch_space+4096)
                  - (scratch_space%4096);
                uint64_t l_address = 0;

                //make sure we don't go past the end of the section
                if(l_boundary+0x4 > scratch_space+sect_size)
                {
                    TS_FAIL("PnorDdTest::test_crossblock_modes: Test Case went beyond allocated space in test section.");
                    TRACFCOMP(g_trac_pnor,
                              "PnorDdTest::test_crossblock_modes: Test Case went beyond allocated space in test section.l_boundary=0x%X, scratch_space=0x%X, sect_size=0x%X",
                              l_boundary, scratch_space, sect_size);
                    TRACFCOMP(g_trac_pnor,
                              "PnorDdTest::test_crossblock_modes: sect_size=0x%X",
                              sect_size);
                   break;
                }

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
        if( fake_space )
        {
            delete fake_space;
        }

        TRACFCOMP(g_trac_pnor, "PnorDdTest::test_crossblock_modes> %d/%d fails", fails, total );
    }


    /**
     * @brief PNOR DD Force Fails testcase
     */
/****************************************************************************/
/* NOTE:  TEST DISABLED!!!  remove "_" before test name to re-enable        */
/****************************************************************************/
    void _test_forceFails(void)
    {
        errlHndl_t l_err = NULL;
        uint64_t fails = 0;
        uint64_t total = 0;
        PnorDD* pnordd = new PnorDD();
        uint32_t l_poll = 0;
        PnorDD::SfcCmdReg_t sfc_cmd;

        do{
            TRACFCOMP(g_trac_pnor, "PnorDdTest::test_forceFails> starting - expect to see errors");

            /*******************************/
            /*  Send in an invalid OP Code */
            /*******************************/
            sfc_cmd.opcode = PnorDD::SFC_OP_INVALID;
            sfc_cmd.length = 0;

            mutex_lock(pnordd->iv_mutex_ptr);
            l_err = pnordd->writeRegSfc(PnorDD::SFC_CMD_SPACE,
                                        PnorDD::SFC_REG_CMD,
                                        sfc_cmd.data32);
            total++;
            if (l_err)
            {
                TS_FAIL("PnorDdTest::test_forceFails> Get Chip Id cmd failed! Error committed.");
                fails++;

                // Unlock mutex for Error Log to be commited
                mutex_unlock(pnordd->iv_mutex_ptr);
                errlCommit(l_err,PNOR_COMP_ID);

                // Lock mutex for next operation
                mutex_lock(pnordd->iv_mutex_ptr);
            }

            // Poll for complete status without waiting
            l_err = pnordd->pollSfcOpComplete();
            mutex_unlock(pnordd->iv_mutex_ptr);

            total++;
            if ( l_err == NULL )
            {
                TS_FAIL("PnorDdTest::test_forceFails> Failed to create illegal opcode error!");
                fails++;
            }
            else
            {
                // error correctly created - delete it
                delete l_err;
            }

            /*******************************************************/
            /* Issue a cmd but poll for completion without waiting */
            /*******************************************************/
            //Issue Get Chip ID command
            sfc_cmd.opcode = PnorDD::SFC_OP_CHIPID;
            sfc_cmd.length = 0;

            mutex_lock(pnordd->iv_mutex_ptr);
            l_err = pnordd->writeRegSfc(PnorDD::SFC_CMD_SPACE,
                                        PnorDD::SFC_REG_CMD,
                                        sfc_cmd.data32);

            total++;
            if (l_err)
            {
                TS_FAIL("PnorDdTest::test_forceFails> Get Chip Id cmd failed! Error committed.");
                fails++;

                // Unlock mutex for Error Log to be commited
                mutex_unlock(pnordd->iv_mutex_ptr);
                errlCommit(l_err,PNOR_COMP_ID);

                // Lock mutex for next operation
                mutex_lock(pnordd->iv_mutex_ptr);
            }

            // Poll for complete status without waiting
            l_err = pnordd->pollSfcOpComplete(l_poll);

            total++;
            if ( l_err == NULL )
            {
                TS_FAIL("PnorDdTest::test_forceFails> pollSfcOpCompletel(l_poll=0) Failed to create an error!");
                fails++;
            }
            else
            {
                // error correctly created - delete it
                delete l_err;
            }

            /*******************************************************/
            /* Cleanup: poll to make sure last operation completes */
            /*         before continuing                           */
            /*******************************************************/
            l_err = pnordd->pollSfcOpComplete();
            mutex_unlock(pnordd->iv_mutex_ptr);

            total++;
            if (l_err)
            {
                TS_FAIL("PnorDdTest::test_forceFails> Cleanup polling failed! Error committed.");
                errlCommit(l_err,PNOR_COMP_ID);
                fails++;
            }


        }while(0);

        if( pnordd )
        {
            delete pnordd;
        }

        TRACFCOMP(g_trac_pnor, "PnorDdTest::test_forceFails> %d/%d fails", fails, total );

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
