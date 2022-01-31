/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/eeprom/test/eepromddtest.H $                          */
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
#ifndef __EEPROMDDTEST_H
#define __EEPROMDDTEST_H

/**
 *  @file eepromddtest.H
 *
 *  @brief Test cases for the eeprom dd code
 */

#include <sys/time.h>
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/driverif.H>
#include <eeprom/eepromddreasoncodes.H>
#include <eeprom/eeprom_const.H>
#include <eeprom/eepromif.H>
#include <targeting/common/commontargeting.H>
#include <pnor/pnorif.H>
#include <ecc/vpd_ecc_api_wrapper.h>

#include <secureboot/service.H>

#include <p10_sbe_spi_cmd.H>
#include <p10_infrastruct_help.H>

#include <memory>

using namespace TARGETING;
using namespace EEPROM;

#define TS_DEBUG(args...)
//#define TS_DEBUG(args...) TS_INFO(args)

extern trace_desc_t* g_trac_eeprom;

class EEPROMTest: public CxxTest::TestSuite
{
    /* @brief Restore the EEPROM device driver VPD state attribute(s).
     */
    static void restoreMvpdState()
    {
        TargetHandleList procs;
        getAllChips(procs, TYPE_PROC, true);

        for (const auto proc : procs)
        {
            const uint8_t state = proc->getAttr<ATTR_SAVED_STATE_UINT8>();
            proc->setAttr<ATTR_EEPROM_VPD_ACCESSIBILITY>(static_cast<ATTR_EEPROM_VPD_ACCESSIBILITY_type>(state));
        }
    }

    /* @brief Preserve the state attribute(s) of the VPDs for the EEPROM device
     *        driver, and return an object that will restore them when it goes
     *        out of scope.
     */
    static auto saveMvpdState()
    {
        TargetHandleList procs;
        getAllChips(procs, TYPE_PROC, true);

        for (const auto proc : procs)
        {
            const uint8_t state = proc->getAttr<ATTR_EEPROM_VPD_ACCESSIBILITY>();
            proc->setAttr<ATTR_SAVED_STATE_UINT8>(state);
        }

        return hbstd::scope_exit(restoreMvpdState);
    }

    public:

        void testEEPROMBoundaryWrite ( void )
        {
            errlHndl_t err = nullptr;
            int fails = 0;
            int num_ops = 0;
            const uint8_t TestDataSize = 100;
            uint8_t testData[TestDataSize];

            TRACFCOMP( g_trac_eeprom,
                       "testEEPROMBoundaryWrite - Start" );

            // initialize some testData to write
            for (uint8_t i = 0; i < TestDataSize; ++i)
            {
                testData[i] = i;
            }

            // Get a processor Target
            TARGETING::TargetService& tS = TARGETING::targetService();
            TARGETING::Target* testTarget = NULL;
            tS.masterProcChipTargetHandle( testTarget );
            assert(testTarget != NULL);

            eeprom_addr_t procEepromAddr;
            procEepromAddr.eepromRole = VPD_PRIMARY;
            err = eepromReadAttributes(testTarget, procEepromAddr);
            if ( err )
            {
                fails = 1;
                TS_FAIL( "testEEPROMBoundaryWrite - failed to find VPD_PRIMARY information for processor %.8X",
                        TARGETING::get_huid(testTarget) );
                errlCommit( err, CXXTEST_COMP_ID );
            }


            // 0) test crossing page boundary
            // 1) test write to the last page boundary
            // 2) test write over last page boundary
            const uint8_t TEST_SPLIT_PAGE_BOUNDARY = 0;
            const uint8_t TEST_WRITE_TO_LAST_PAGE = 1;
            const uint8_t TEST_ONE_OVER_LAST_PAGE = 2;
            uint64_t testingOffsets[3];
            testingOffsets[TEST_SPLIT_PAGE_BOUNDARY] =
                                (procEepromAddr.devSize_KB * KILOBYTE) -
                                EEPROM_PAGE_SIZE - (TestDataSize/2);
            testingOffsets[TEST_WRITE_TO_LAST_PAGE] =
                                (procEepromAddr.devSize_KB * KILOBYTE) -
                                TestDataSize; // reach boundary
            testingOffsets[TEST_ONE_OVER_LAST_PAGE] =
                                ((procEepromAddr.devSize_KB * KILOBYTE) -
                                TestDataSize) + 1;  // go 1 over max

            uint8_t storedData[TestDataSize];
            for (uint8_t i = 0; i < 3; ++i)
            {
                uint64_t storedDataSize = TestDataSize;

                {
                const auto restore = saveMvpdState();

                num_ops++;
                // first read the bytes we are overwritting
                err = deviceOp( DeviceFW::READ,
                                        testTarget,
                                        storedData,
                                        storedDataSize,
                                        DEVICE_EEPROM_ADDRESS(
                                                      VPD_PRIMARY,
                                                      testingOffsets[i],
                                                      EEPROM::AUTOSELECT) );
                if ( err )
                {
                    if (TEST_ONE_OVER_LAST_PAGE == i)
                    {
                        TS_TRACE("testEEPROMBoundaryWrite: cannot read past boundary");
                        delete err;
                        err = nullptr;
                    }
                    else
                    {
                        TS_FAIL("testEEPROMBoundaryWrite: %d) failed reading %ld test data from offset 0x%.8X", i, storedDataSize, testingOffsets[i]);
                        fails++;
                        errlCommit( err, CXXTEST_COMP_ID );
                        continue;
                    }
                }
                else if (TEST_ONE_OVER_LAST_PAGE == i)
                {
                    TS_FAIL("testEEPROMBoundaryWrite: TEST_ONE_OVER_LAST_PAGE read should fail");
                    fails++;
                }
                } // saveMvpdState

                uint64_t testDataSize = TestDataSize;

                {
                const auto restore = saveMvpdState();

                // overwrite the data
                num_ops++;
                err = deviceOp( DeviceFW::WRITE,
                                testTarget,
                                testData,
                                testDataSize,
                                DEVICE_EEPROM_ADDRESS(
                                              VPD_PRIMARY,
                                              testingOffsets[i],
                                              EEPROM::AUTOSELECT) );
                if ( err )
                {
                    if (i == TEST_ONE_OVER_LAST_PAGE)
                    {
                        TS_INFO("testEEPROMBoundaryWrite: %d) write past boundary failed as expected", i);
                        delete err;
                        err = nullptr;
                    }
                    else
                    {
                        TS_FAIL("testEEPROMBoundaryWrite: %d) failed writing %ld test data from offset 0x%.8X", i, testDataSize, testingOffsets[i]);
                        fails++;
                        errlCommit( err, CXXTEST_COMP_ID );
                    }
                    continue;
                }
                else if (TEST_ONE_OVER_LAST_PAGE == i)
                {
                    TS_FAIL("testEEPROMBoundaryWrite: TEST_ONE_OVER_LAST_PAGE write should fail");
                    fails++;
                }
                } // saveMvpdState

                // read new updated data now
                uint8_t updatedData[TestDataSize];
                uint64_t updatedDataSize = TestDataSize;
                num_ops++;
                err = deviceOp( DeviceFW::READ,
                                testTarget,
                                &updatedData,
                                updatedDataSize,
                                DEVICE_EEPROM_ADDRESS(
                                              VPD_PRIMARY,
                                              testingOffsets[i],
                                              EEPROM::AUTOSELECT) );
                if (err)
                {
                    TS_FAIL("testEEPROMBoundaryWrite: %d) failed reading new %ld test data from offset 0x%.8X", i, updatedDataSize, testingOffsets[i]);
                    fails++;
                    errlCommit( err, CXXTEST_COMP_ID );
                }
                else
                {
                    // check data matches what was written
                    if ( memcmp(updatedData, testData, TestDataSize) )
                    {
                        TS_FAIL("testEEPROMBoundaryWrite: %d data mismatch found", i);
                        TRACFBIN( g_trac_test, "updatedData", updatedData, updatedDataSize );
                        TRACFBIN( g_trac_test, "writtenData", testData, testDataSize );
                        fails++;
                    }
                    else
                    {
                        TS_INFO("testEEPROMBoundaryWrite: %d write worked", i);
                    }
                }

                // put back original data
                num_ops++;
                err = deviceOp( DeviceFW::WRITE,
                                testTarget,
                                storedData,
                                storedDataSize,
                                DEVICE_EEPROM_ADDRESS(
                                              VPD_PRIMARY,
                                              testingOffsets[i],
                                              EEPROM::AUTOSELECT) );
                if ( err )
                {
                    TS_FAIL("testEEPROMBoundaryWrite: unable to restore original data for run %d", i);
                    errlCommit(err, CXXTEST_COMP_ID);
                    fails++;
                }
            }

            TRACFCOMP( g_trac_eeprom,
                       "testEEPROMBoundaryWrite - End: %d/%d fails",
                       fails, num_ops );
        }

        /**
         * @brief EEPROM Read/Write Test
         *      This test will test a variety of reads/writes and lengths
         *      across slave devices.
         *
         * @Note - Tests are not run on real hardware.
         */
        void testEEPROMReadWrite ( void )
        {
            const auto restore = saveMvpdState();

            // Skipping EEPROM test altogether in VBU/VPO environment or in
            // Secure mode
            if( TARGETING::is_vpo() || SECUREBOOT::enabled() )
            {
                TS_INFO("testEEPROMReadWrite skipping EEPROM test altogether "
                        "in VBU/VPO environment or in Secure mode");
                return;
            }

            errlHndl_t err = NULL;
            int fails = 0;
            int num_ops = 0;

            TS_INFO("testEEPROMReadWrite - Start" );

            struct
            {
                uint64_t offset;    // Internal Slave Device Offset to access
                uint64_t chip;      // Which EEPROM chip hung off of the target to access
                uint64_t data;      // Data to write or compare to
                size_t   size;      // Number of bytes to read/write
                bool     cached;    // true for eeproms that are part of eecache
            } testData[] =

            {

                // GENERAL : Interesting boundary comments
                // In general the methodology was to bounce around
                // from PRIMARY to BACKUP and also to jump from low
                // to high ranges to exercise the logical and physical
                // aspects.  Using odd and even offsets to exercise
                // math logic handling in the underlying layers as well.
                //
                // Specify the offset, chip, data to write and size
                // Tests will SAVE off the original data READ
                // and RESTORE at the end of the test
                //
                // MVPD of processor - eeprom2 spi engine 2
                {0x0000, VPD_PRIMARY, 0xAABBCCDD00000000, 4, true},

                // SBE Backup of processor - eeprom1 spi engine 1
                {0x0009, SBE_BACKUP, 0x1122334455660000, 6, false},

                // SBE Primary of processor - eeprom0 spi engine 0
                {0x0801, SBE_PRIMARY, 0xaabb000000000000, 2, false},

                // SBE Primary of processor - eeprom0 spi engine 0
                {0x0000, SBE_PRIMARY, 0xaa00000000000000, 1, false},

                // SBE Backup of processor - eeprom1 spi engine 1
                // interesting boundary 0x07FF 2047
                { 0x07FF, SBE_BACKUP, 0x1122334455660000, 6, false},

                // SBE Primary of processor - eeprom0 spi engine 0
                // interesting boundary 0x0800 2048
                {0x0800, SBE_PRIMARY, 0xaabbcc0000000000, 3, false},

                // SBE Primary of processor - eeprom0 spi engine 0
                // interesting boundary 0x7F8
                {MAX_LENGTH_TRNS-8, SBE_PRIMARY, 0xaabbcc0000000000, 3, false},

                // SBE Backup of processor - eeprom1 spi engine 1
                // interesting boundary 0xF9
                {SEEPROM_PAGE_SIZE-7, SBE_BACKUP, 0x1122334455000000, 5, false},

                // SBE Backup of processor - eeprom1 spi engine 1
                // interesting boundary 0x0001
                {0x0001, SBE_BACKUP, 0x1122000000000000, 2, false},

                // SBE Backup of processor - eeprom1 spi engine 1
                // interesting boundary 0x2FD
                {SEEPROM_PAGE_SIZE*3-3, SBE_BACKUP, 0x1122334400000000, 7, false},

                // SBE Primary of processor - eeprom0 spi engine 0
                // interesting boundary 0x00FF 255
                {0x00FF, SBE_PRIMARY, 0xaabbccdd00000000, 4, false},

                // SBE Backup of processor - eeprom 1 spi engine 1
                // interesting boundary 0x6FB
                {SEEPROM_PAGE_SIZE*7-5, SBE_BACKUP, 0xbad5adcabf0b7000, 7, false},

                // SBE Primary of processor - eeprom0 spi engine 0
                // interesting boundary 0x0007
                {0x0007, SBE_PRIMARY, 0x1122334400000000, 4, false},

                // SBE Backup of processor - eeprom1 spi engine 1
                // interesting boundary 0x0100 256
                {0x0100, SBE_BACKUP, 0x1122330000000000, 3, false},

                // SBE Primary of processor - eeprom0 spi engine 0
                // interesting boundary at end 0x7FFF8
                {MAX_SBE_SEEPROM_SIZE-8, SBE_PRIMARY, 0x1122334455667788, 8, false},

                // SBE Backup of processor - eeprom1 spi engine 1
                // interesting boundary 0x0008
                {0x0008, SBE_BACKUP, 0x1122330000000000, 3, false},

                // SBE Primary of processor - eeprom0 spi engine 0
                // interesting boundary 0x0101 257
                {0x0101, SBE_PRIMARY, 0xaabbccddeeff0000, 6, false},

            };

            const uint32_t NUM_CMDS = sizeof(testData)/sizeof(testData[0]);

            do
            {
                // Get a processor Target
                TARGETING::TargetService& l_targetService = TARGETING::targetService();
                TARGETING::Target* testTarget = NULL;
                l_targetService.masterProcChipTargetHandle( testTarget );
                assert(testTarget != NULL);
                TargetHandleList fullList;
                fullList.push_back( testTarget );

                TARGETING::TargetService& tS = TARGETING::targetService();
                TARGETING::Target * sysTarget = NULL;

                // Get top level system target
                tS.getTopLevelTarget( sysTarget );
                assert( sysTarget != NULL );

                // Predicate for the Procs
                TARGETING::PredicateCTM predProc( TARGETING::CLASS_CHIP,
                                                  TARGETING::TYPE_PROC );

                // Predicate for the DIMMs
                TARGETING::PredicateCTM predDimm( TARGETING::CLASS_CARD,
                                                  TARGETING::TYPE_DIMM );

                // Expression to get both Procs and DIMMs.
                PredicatePostfixExpr query;
                query.push( &predProc ).push( &predDimm ).Or();
                tS.getAssociated( fullList,
                                  sysTarget,
                                  TARGETING::TargetService::CHILD,
                                  TARGETING::TargetService::ALL,
                                  &query );
                assert( 0 != fullList.size() );

                // Number of total operations
                num_ops = fullList.size() * NUM_CMDS;

                for( uint32_t j = 0; j < fullList.size(); j++ )
                {
                    // Skip this target if EEPROM isn't available. or if non functional
                    if( !fullList[j]->getAttr<TARGETING::ATTR_HWAS_STATE>()\
                        .functional)
                    {
                        continue;
                    }

                    for( uint32_t i = 0; i < NUM_CMDS; i++ )
                    {
                        uint64_t data;
                        uint64_t saved_data;

                        data = 0x0ull; // always clear the read buffer
                        // Stage 1 - READ the device at specified locale
                        err = deviceOp( DeviceFW::READ,
                                        fullList[j],
                                        &data,
                                        testData[i].size,
                                        DEVICE_EEPROM_ADDRESS(
                                                      testData[i].chip,
                                                      testData[i].offset,
                                                      EEPROM::AUTOSELECT));
                        if( err )
                        {
                            TS_FAIL( "testEEPROMReadWrite - Stage 1 fail on cmd=%d out of %d",
                                     i, NUM_CMDS );
                            errlCommit( err,
                                        EEPROM_COMP_ID );
                            delete err;
                            fails++;
                            continue;
                        }

                        // Always SAVE off for RESTORE
                        saved_data = data;
                        TS_INFO("testEEPROMReadWrite - Stage 1  PRIME READ of "
                                "original data 0x%016llx cmd=%d out of %d",
                                data, i, NUM_CMDS);

                        // Stage 2 - WRITE the test data
                        data = testData[i].data;
                        err = deviceOp( DeviceFW::WRITE,
                                        fullList[j],
                                        &data,
                                        testData[i].size,
                                        DEVICE_EEPROM_ADDRESS(
                                                      testData[i].chip,
                                                      testData[i].offset,
                                                      EEPROM::AUTOSELECT));

                        if( err )
                        {
                            TS_FAIL( "testEEPROMReadWrite - Stage 2 failed "
                                     "on cmd=%d out of %d",
                                     i, NUM_CMDS );
                            errlCommit( err,
                                        EEPROM_COMP_ID );
                            delete err;
                            fails++;
                            continue;
                        }
                        TS_INFO("testEEPROMReadWrite - Stage 2  WROTE test data "
                                "0x%016llx cmd=%d out of %d",
                                data, i, NUM_CMDS);

                        data = 0x0ull; // always clear READ buffer
                        // Stage 3 - READ the data we just WROTE
                        err = deviceOp( DeviceFW::READ,
                                        fullList[j],
                                        &data,
                                        testData[i].size,
                                        DEVICE_EEPROM_ADDRESS(
                                                      testData[i].chip,
                                                      testData[i].offset,
                                                      EEPROM::AUTOSELECT));


                        if(err)
                        {
                            TS_FAIL( "testEEPROMReadWrite - Stage 3 failed to READ the data we "
                                     "just WROTE on cmd=%d out of %d",
                                     i, NUM_CMDS );
                            errlCommit( err,
                                        EEPROM_COMP_ID );
                            delete err;
                            fails++;
                            continue;
                        }
                        TS_INFO("testEEPROMReadWrite - Stage 3 - READ test data we "
                                "just WROTE 0x%016llx cmd=%d out of %d",
                                data, i, NUM_CMDS);
                        if (data != testData[i].data)
                        {
                            // we fail instead of retry to aide in root cause analysis
                            TS_FAIL("testEEPROMReadWrite - Stage 3 failed VERIFICATION of WRITE "
                                    "of desired test data on cmd=%d out of %d",
                                    i, NUM_CMDS);
                            fails++;
                            continue;
                        }
                        else
                        {
                            TS_INFO("testEEPROMReadWrite - Stage 3 READ VERIFIED "
                                    "cmd=%d out of %d",
                                    i, NUM_CMDS);
                        }

                        // Run the following test if the VPD ECC algorithm are in place
                        testData[i].cached = g_vpd_ecc_api_present;

#if ( !(defined(CONFIG_SUPPORT_EEPROM_CACHING) && defined(CONFIG_SUPPORT_EEPROM_HWACCESS)) )
                        // Skip this test if we don't have two data sources
                        testData[i].cached = false;
#endif

                        // Stage 3b - READ the data we just WROTE via the direct paths
                        //            to ensure proper write-through
                        if( testData[i].cached )
                        {
                            // Read from CACHE
                            data = 0x0ull; // always clear READ buffer
                            err = deviceOp( DeviceFW::READ,
                                            fullList[j],
                                            &data,
                                            testData[i].size,
                                            DEVICE_EEPROM_ADDRESS(
                                                                  testData[i].chip,
                                                                  testData[i].offset,
                                                                  EEPROM::CACHE));


                            if(err)
                            {
                                TS_FAIL( "testEEPROMReadWrite - Stage 3b failed to READ the data via CACHE we "
                                         "just WROTE on cmd=%d out of %d",
                                         i, NUM_CMDS );
                                errlCommit( err,
                                            EEPROM_COMP_ID );
                                delete err;
                                fails++;
                                continue;
                            }
                            TS_INFO("testEEPROMReadWrite - Stage 3b - READ via CACHE test data we "
                                    "just WROTE 0x%016llx cmd=%d out of %d",
                                    data, i, NUM_CMDS);
                            if (data != testData[i].data)
                            {
                                // we fail instead of retry to aide in root cause analysis
                                TS_FAIL("testEEPROMReadWrite - Stage 3b failed VERIFICATION via CACHE of WRITE "
                                        "of desired test data on cmd=%d out of %d",
                                        i, NUM_CMDS);
                                fails++;
                                continue;
                            }
                            else
                            {
                                TS_INFO("testEEPROMReadWrite - Stage 3b READ via CACHE VERIFIED "
                                        "cmd=%d out of %d",
                                        i, NUM_CMDS);
                            }

                            // Read from HARDWARE
                            data = 0x0ull; // always clear READ buffer
                            err = deviceOp( DeviceFW::READ,
                                            fullList[j],
                                            &data,
                                            testData[i].size,
                                            DEVICE_EEPROM_ADDRESS(
                                                                  testData[i].chip,
                                                                  testData[i].offset,
                                                                  EEPROM::HARDWARE));


                            if(err)
                            {
                                TS_FAIL( "testEEPROMReadWrite - Stage 3b failed to READ the data via HARDWARE we "
                                         "just WROTE on cmd=%d out of %d",
                                         i, NUM_CMDS );
                                errlCommit( err,
                                            EEPROM_COMP_ID );
                                delete err;
                                fails++;
                                continue;
                            }
                            TS_INFO("testEEPROMReadWrite - Stage 3b - READ via HARDWARE test data we "
                                    "just WROTE 0x%016llx cmd=%d out of %d",
                                    data, i, NUM_CMDS);
                            if (data != testData[i].data)
                            {
                                // we fail instead of retry to aide in root cause analysis
                                TS_FAIL("testEEPROMReadWrite - Stage 3b failed VERIFICATION via HARDWARE of WRITE "
                                        "of desired test data on cmd=%d out of %d",
                                        i, NUM_CMDS);
                                fails++;
                                continue;
                            }
                            else
                            {
                                TS_INFO("testEEPROMReadWrite - Stage 3b READ via HARDWARE VERIFIED "
                                        "cmd=%d out of %d",
                                        i, NUM_CMDS);
                            }
                        }

                        // Stage 4 - RESTORE the original data
                        data = saved_data;
                        err = deviceOp( DeviceFW::WRITE,
                                        fullList[j],
                                        &data,
                                        testData[i].size,
                                        DEVICE_EEPROM_ADDRESS(
                                                      testData[i].chip,
                                                      testData[i].offset,
                                                      EEPROM::AUTOSELECT));
                        if(err)
                        {
                            TS_FAIL( "testEEPROMReadWrite - Stage 4 Restoration "
                                     "WRITE failed on cmd=%d out of %d",
                                     i, NUM_CMDS );
                            errlCommit( err,
                                        EEPROM_COMP_ID );
                            delete err;
                            fails++;
                            continue;
                        }
                        TS_INFO("testEEPROMReadWrite - Stage 4 WROTE original "
                                "data 0x%016llx for RESTORE cmd=%d out of %d",
                                data, i, NUM_CMDS);

                        // Stage 5 - READ and VERIFY the RESTORE data
                        data = 0x0ull; // always clear READ buffer
                        err = deviceOp( DeviceFW::READ,
                                        fullList[j],
                                        &data,
                                        testData[i].size,
                                        DEVICE_EEPROM_ADDRESS(
                                                      testData[i].chip,
                                                      testData[i].offset,
                                                      EEPROM::AUTOSELECT));

                        if(err)
                        {
                            TS_FAIL( "testEEPROMReadWrite - Stage 5 failed on READ "
                                     "of cmd=%d out of %d",
                                     i, NUM_CMDS );
                            errlCommit( err,
                                        EEPROM_COMP_ID );
                            delete err;
                            fails++;
                            continue;
                        }
                        TS_INFO("testEEPROMReadWrite Stage 5 RESTORE VERIFIED - "
                                "READ RESTORED data 0x%016llx which should MATCH "
                                "original saved_data 0x%016llx cmd=%d out of %d",
                                data, saved_data, i, NUM_CMDS);
                        if (data != saved_data)
                        {
                            // we fail instead of retry to aide in root cause analysis
                            TS_FAIL("testEEPROMReadWrite - Stage 5 failed "
                                    "to VERIFY RESTORED data "
                                    "cmd=%d out of %d", i, NUM_CMDS);
                            fails++;
                            continue;
                        }
                        else
                        {
                            TS_INFO("testEEPROMReadWrite - Stage 5 - Success "
                                    "READ/WRITE/RESTORE of desired data "
                                    "cmd=%d out of %d", i, NUM_CMDS);
                        }
                    }
                }

            } while( 0 );

            TS_INFO("testEEPROMReadWrite - End: fails=%d num_ops=%d", fails, num_ops );
        }


        /**
         * @brief EEPROM Read/Write Large Test
         *      This test will read and write arbitrary bytes of data to SBE Backup and
         *      will attempt to restore the original data at the end of the test.
         *
         * @Note - Tests are not run on real hardware.
         *
         */
        void testEEPROMReadWriteLarge ( void )
        {
            const auto restore = saveMvpdState();

            // Skipping EEPROM test altogether in VBU/VPO environment or in
            // Secure mode
            if( TARGETING::is_vpo() || SECUREBOOT::enabled() )
            {
                TS_INFO("testEEPROMReadWriteLarge skipping EEPROM test altogether "
                        "in VBU/VPO environment or in Secure mode");
                return;
            }

            int fails = 0;
            int num_ops = 0;
            errlHndl_t err = NULL;
            int cmds = 0;

            size_t  testBufLen = 4096; // mixes up the offset handling
            uint8_t testBuffer[testBufLen];
            uint8_t new_data[testBufLen];
            uint8_t original_data[testBufLen];

            // Use small offset to force more complicated page-boundary testing
            uint8_t offset = 0x11;
            constexpr size_t MAX_BIN_TRACE = 0x200;


            TS_INFO("testEEPROMReadWriteLarge - Start" );

            do
            {
                // Get a processor Target
                TARGETING::TargetService& l_targetService =
                                          TARGETING::targetService();
                TARGETING::Target* testTarget = NULL;
                l_targetService.masterProcChipTargetHandle( testTarget );
                assert(testTarget != NULL);
                TargetHandleList fullList;
                fullList.push_back( testTarget );

                // 5 operations per target (details below)
                const uint32_t NUM_CMDS = 5;

                // Number of total operations
                num_ops = fullList.size() * NUM_CMDS;


                /************************************************************/
                /* Using PNOR to return the extended image to use as new_data */
                /**************************************************************/
                // Jumping 32K into extended image for more dense data
                static const uint64_t HEADER_OFFSET = 0x8000;
                PNOR::SectionInfo_t pnorSectionInfo;

                err = PNOR::getSectionInfo(PNOR::HB_EXT_CODE,
                                           pnorSectionInfo);

                if ( err ||
                     (pnorSectionInfo.size < HEADER_OFFSET + testBufLen + offset)
                   )
                {
                    TS_FAIL("testEEPROMReadWriteLarge: PNOR::getSectionInfo failed or size too small: pnorSize=0x%X HEADER_OFFSET=0x%X testBufLen=0x%X offset=0x%X",
                        pnorSectionInfo.size, HEADER_OFFSET, testBufLen, offset);
                    errlCommit(err, EEPROM_COMP_ID);
                    delete err;
                    fails++;
                    break;
                }


                void* tmp_ptr = reinterpret_cast<void*>(pnorSectionInfo.vaddr +
                                                         HEADER_OFFSET);

                if (tmp_ptr == NULL)
                {
                    TS_FAIL("testEEPROMReadWriteLarge: Couldn't get tmp_ptr for new data");
                    errlCommit(err, EEPROM_COMP_ID);
                    delete err;
                    fails++;
                    break;

                }

                //  Valid Buffer, so memcpy seed data
                memcpy( new_data, tmp_ptr, testBufLen );

                /************************************************************/
                /* Loop through targets and perform operations              */
                /************************************************************/

                for( uint32_t i = 0; i < fullList.size(); i++ )
                {
                    // Skip this target if EEPROM isn't available
                    // or if non functional
                    if( !fullList[i]->getAttr<TARGETING::ATTR_HWAS_STATE>()\
                        .functional)
                    {
                        continue;
                    }


                    // Before starting, clear original data buffer
                    memset(original_data, 0x0, testBufLen);
                    for (uint8_t j = 1; j <= NUM_CMDS; j++)
                    {
                        // Details: 5 operations per target
                        // 1) Read Original Data and Save It
                        // 2) Write New Data
                        // 3) Read New Data and Compare
                        // 4) Write Back Original Data
                        // 5) Read Back Original Data and Compare

                        // Clear data buffer before reads
                        if ( (j == 1) || (j == 3) || (j == 5) )
                        {
                            memset(testBuffer, 0x0, testBufLen);
                        }

                        // For Loop 2: set data to new data
                        if ( j == 2 )
                        {
                            memcpy(testBuffer, new_data, testBufLen);
                        }

                        // For Loop 4: set data to original_data
                        if ( j == 4 )
                        {
                            memcpy(testBuffer, original_data, testBufLen);
                        }

                        // increment cmd op counter
                        cmds++;

                        // do the Operation
                        err = deviceOp(
                                (j%2) ? DeviceFW::READ : DeviceFW::WRITE,
                                fullList[0],
                                testBuffer,
                                testBufLen,
                                DEVICE_EEPROM_ADDRESS(SBE_BACKUP,
                                                      offset,
                                                      EEPROM::AUTOSELECT));

                        if( err )
                        {
                            TS_FAIL( "testEEPROMReadWriteLarge = OP %d FAILED "
                                     "- cmd %d out of %d",
                                     j, i, NUM_CMDS );
                            errlCommit( err,
                                        EEPROM_COMP_ID );
                            delete err;
                            fails++;
                            continue;
                        }


                        // Handle loop-specific results

                        // For Loop 1: save original data
                        if ( j == 1 )
                        {
                            memcpy(original_data, testBuffer, testBufLen);

                            TS_DEBUG("testEEPROMReadWriteLarge"
                                      " saving original data i=%d, j=%d",
                                      i, j);
                        }

                        // For Loop 3: compare new data
                        if ( j == 3 )
                        {
                            // Compare the data
                            if ( memcmp(testBuffer, new_data, testBufLen) )
                            {
                                TS_INFO("testEEPROMReadWriteLarge MISCOMPARE"
                                        " of new data len=0x%X", testBufLen);

                                TRACFBIN( g_trac_eeprom, "testBuffer=",
                                          testBuffer, std::min(testBufLen, MAX_BIN_TRACE));
                                TRACFBIN( g_trac_eeprom, "new_data=",
                                          new_data, std::min(testBufLen, MAX_BIN_TRACE));
                                TS_FAIL( "testEEPROMReadWriteLarge - MISCOMPARE"
                                         " on writing new data");
                                fails++;

                                // Don't break - try to write back original data
                                continue;
                            }
                            else
                            {
                                TS_DEBUG(
                                          "testEEPROMReadWriteLarge New "
                                          "Data R/W Successful i=%d,j=%d",
                                          i, j);
                            }
                        }


                        // For Loop 5: compare writing-back original data
                        if ( j == 5 )
                        {
                            // Compare the data
                            if ( memcmp(testBuffer, original_data, testBufLen) )
                            {
                                TS_INFO("testEEPROMReadWriteLarge MISCOMPARE"
                                        " of original data len=0x%X",
                                        testBufLen);

                                TRACFBIN( g_trac_eeprom, "testBuffer=",
                                          testBuffer, std::min(testBufLen, MAX_BIN_TRACE));
                                TRACFBIN( g_trac_eeprom, "orig_data=",
                                          original_data, std::min(testBufLen, MAX_BIN_TRACE));

                                TS_FAIL( "testEEPROMReadWriteLarge - MISCOMPARE"
                                         " on writing back original data");
                                fails++;

                                break;
                            }
                            else
                            {
                                TS_DEBUG(
                                          "testEEPROMReadWriteLarge: Original "
                                          "Data R/W Successful i=%d,j=%d",
                                          i, j);
                            }
                        }

                    }  // end of 'j' loop: 5 ops per target

                }  // end of 'i' loop: target loop

            } while( 0 );

            TS_INFO("testEEPROMReadWriteLarge - End: %d/%d fails", fails,
                    num_ops );
        }

        /**
         * @brief EEPROM Invalid Operation Test
         *      This test will pass in an invalid Operation type.  It
         *      is expected that an error log is to be returned.
         */
        void testEEPROMInvalidOperation ( void )
        {
            const auto restore = saveMvpdState();

            errlHndl_t err = NULL;
            int64_t fails = 0, num_ops = 0;
            uint64_t data = 0x0ull;
            size_t dataSize = 8;

            TS_INFO("testEEPROMInvalidOperation - Start" );

            do
            {
                // Get a processor Target
                TARGETING::TargetService& tS = TARGETING::targetService();
                TARGETING::Target* testTarget = NULL;
                tS.masterProcChipTargetHandle( testTarget );
                assert(testTarget != NULL);

                // Skip this target if target is non-functional
                if(!testTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().\
                                                   functional)
                {
                    continue;
                }

                num_ops++;
                err = deviceOp( DeviceFW::LAST_OP_TYPE,
                                testTarget,
                                &data,
                                dataSize,
                                DEVICE_EEPROM_ADDRESS( 0x0,
                                                       0x0 ,
                                                       EEPROM::AUTOSELECT) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testEEPROMInvalidOperation - Error should've "
                             " resulted in Operation type of LAST_OP_TYPE!" );
                }
                else
                {
                    TS_DEBUG( "testEEPROMInvalidOperation - "
                              "Error log returned as expected. RC=0x%X",
                              err->reasonCode() );
                    delete err;
                    err = NULL;
                }
            } while( 0 );
            TS_INFO("testEEPROMInvalidOperation - End: %d/%d fails",
                    fails, num_ops );
        }


        /**
         * @brief EEPROM Overflow Test
         *      This test will pass in a target which does not have an
         *      EEPROM attribute associated with it.  It is expected that
         *      an error log is to be returned.
         */
        void testEEPROMOverflow ( void )
        {
            const auto restore = saveMvpdState();

            errlHndl_t err = NULL;
            int64_t fails = 0, num_ops = 0;
            uint64_t data = 0x0ull;
            size_t dataSize = 0;
            uint64_t offset = 0x0ull;

            TS_INFO("testEEPROMOverflow - Start" );

            do
            {
                // Get a processor Target
                TARGETING::TargetService& tS = TARGETING::targetService();
                TARGETING::Target* testTarget = NULL;
                tS.masterProcChipTargetHandle( testTarget );
                assert(testTarget != NULL);

                // Skip this target if target is non-functional
                if(!testTarget->getAttr<TARGETING::ATTR_HWAS_STATE>()
                                                   .functional)
                {
                    continue;
                }

                // Set max length and offset
                dataSize = 0xFFFFFFFFFFFFFFFF;
                offset = 0xFFFFFFFFFFFFFFFF;
                num_ops++;
                err = deviceOp( DeviceFW::WRITE,
                                testTarget,
                                &data,
                                dataSize,
                                DEVICE_EEPROM_ADDRESS( 0x0,
                                                       offset,
                                                       EEPROM::AUTOSELECT) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testEEPROMOverflow - Error should've "
                             "resulted from overflow offset and length: "
                             "offset=0x%X, length = 0x%x",
                             offset, dataSize);
                }
                else
                {
                    TS_DEBUG( "testEEPROMOverflow - "
                              "Error log returned as expectede. RC=0x%X",
                              err->reasonCode() );
                    delete err;
                    err = NULL;
                }
            } while( 0 );

            TS_INFO("testEEPROMOverflow - End: %d/%d fails",
                    fails, num_ops );
        }


        /**
         * @brief EEPROM Invalid Chip Test
         *      This test will pass in an invalid chip identifier which should
         *      result in an error being returned.
         */
        void testEEPROMInvalidChip ( void )
        {
            const auto restore = saveMvpdState();

            errlHndl_t err = NULL;
            int64_t fails = 0, num_ops = 0;
            uint64_t data = 0x0ull;
            size_t dataSize = 8;

            TS_INFO("testEEPROMInvalidChip - Start" );

            do
            {

                // Get a processor Target
                TARGETING::TargetService& tS = TARGETING::targetService();
                TARGETING::Target* testTarget = NULL;
                tS.masterProcChipTargetHandle( testTarget );
                assert(testTarget != NULL);

                // Skip this target if target is non-functional
                if(!testTarget->getAttr<TARGETING::ATTR_HWAS_STATE>()
                                                   .functional)
                {
                    continue;
                }

                num_ops++;
                err = deviceOp( DeviceFW::WRITE,
                                testTarget,
                                &data,
                                dataSize,
                                DEVICE_EEPROM_ADDRESS( LAST_CHIP_TYPE,
                                                       0x0,
                                                       EEPROM::AUTOSELECT) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testEEPROMInvalidChip - Error should've "
                             "resulted in using EEPROM chip %d!",
                             LAST_CHIP_TYPE );
                }
                else
                {
                    TS_DEBUG( "testEEPROMInvalidChip - "
                              "Error log returned as expected. RC=0x%x ",
                              err->reasonCode() );
                    delete err;
                    err = NULL;
                }

            } while( 0 );

            TS_INFO("testEEPROMInvalidChip - End: %d/%d fails",
                    fails, num_ops );
        }

        /**
         * @brief Verify we retrieve all of the EEPROMs we can think of
         */
        void test_getEEPROMs( void )
        {
            const auto restore = saveMvpdState();

            TS_INFO( ENTER_MRK"test_getEEPROMs" );
            std::list<EEPROM::EepromInfo_t> info;
            getEEPROMs( info );
            for( std::list<EEPROM::EepromInfo_t>::iterator eep = info.begin();
                 eep != info.end();
                 ++eep )
            {
                if ( eep->accessMethod ==
                     EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C )
                {
                    TS_INFO("Found I2C EEPROM: Master=%.8X, Eng=%d, Port=%d, "
                       "Freq=%d, Addr=%.2X, Dev=%d, Targ=%.8X",
                       TARGETING::get_huid(eep->eepromAccess.i2cInfo.i2cMaster),
                       eep->eepromAccess.i2cInfo.engine,
                       eep->eepromAccess.i2cInfo.port,
                       eep->eepromAccess.i2cInfo.busFreq,
                       eep->eepromAccess.i2cInfo.devAddr,
                       eep->deviceRole, TARGETING::get_huid(eep->assocTarg) );
                }
                else
                {
                    TS_INFO("Found SPI EEPROM: Master=%.8X, Eng=%d, "
                       "Role=%d, Targ=%.8X",
                       TARGETING::get_huid(eep->eepromAccess.spiInfo.spiMaster),
                       eep->eepromAccess.spiInfo.engine,
                       eep->deviceRole, TARGETING::get_huid(eep->assocTarg) );


                }
            }
            TS_INFO( EXIT_MRK"test_getEEPROMs" );
        }

    static Target* getProcessorWithTwoGoodVpds()
    {
        TargetHandleList procs;
        getAllChips(procs, TYPE_PROC, true);

        for (const auto proc : procs)
        {
            if (proc->getAttr<ATTR_EEPROM_VPD_ACCESSIBILITY>() == EEPROM_VPD_ACCESSIBILITY_NONE_DISABLED)
            {
                return proc;
            }
        }

        return nullptr;
    }

    static bool writeToVpd(Target* const i_target,
                           const EEPROM_ROLE i_role,
                           uint64_t i_data,
                           EEPROM_SOURCE i_source = EEPROM::HARDWARE)
    {
        uint64_t data_size = sizeof(i_data);

        errlHndl_t errl = deviceOp(DeviceFW::WRITE,
                                   i_target,
                                   &i_data,
                                   data_size,
                                   DEVICE_EEPROM_ADDRESS(i_role,
                                                         0,
                                                         i_source));

        bool success = true;
        if (errl)
        {
            errlCommit(errl, CXXTEST_COMP_ID);
            success = false;
        }

        return success;
    }

    static bool readFromVpdCompare(Target* const i_target,
                                   const EEPROM_ROLE i_role,
                                   uint64_t i_data,
                                   const EEPROM_SOURCE i_source = EEPROM::HARDWARE)
    {
        uint64_t data = 0;
        uint64_t data_size = sizeof(i_data);
        errlHndl_t errl = deviceOp(DeviceFW::READ,
                                   i_target,
                                   &data,
                                   data_size,
                                   DEVICE_EEPROM_ADDRESS(i_role,
                                                         0,
                                                         i_source));

        bool success = true;
        if (errl)
        {
            errlCommit(errl, CXXTEST_COMP_ID);
            success = false;
        }
        else if (i_data != 0 && data != i_data)
        {
            TS_INFO("readFromVpdCompareHw: Read 0x%lx, expected 0x%lx", data, i_data);
            success = false;
        }

        return success;
    }

    void setVpdAccessibility(Target* const i_proc, const uint64_t i_accessibility)
    {
        i_proc->setAttr<ATTR_EEPROM_VPD_ACCESSIBILITY>(static_cast<ATTR_EEPROM_VPD_ACCESSIBILITY_type>(i_accessibility));
    }

#define VPDASSERT(X) if (!(X)) { TS_FAIL(FUNC ": %s failed, expected success on line %d", #X, __LINE__); }
#define VPDASSERTFAIL(X) if (X) { TS_FAIL(FUNC ": %s succeeded, expected failure on line %d", #X, __LINE__); }

    void test_redundantVpdAccess()
    {
        #define FUNC "test_redundantVpdAccess"

        TS_INFO( ENTER_MRK"test_redundantVpdAccess" );

        const auto restore = saveMvpdState();

        do
        {

        Target* const proc = getProcessorWithTwoGoodVpds();

        if (!proc)
        {
            TS_FAIL("Can't find a processor with both good VPDs");
            break;
        }

        const uint64_t testdata_primary = 0xabcd1234, testdata_backup = 0xffeeffee;

        // Simple sanity check (for SPI buses etc.)
        VPDASSERT(writeToVpd(proc, VPD_PRIMARY, testdata_primary, HARDWARE));
        VPDASSERT(writeToVpd(proc, VPD_BACKUP, testdata_backup, HARDWARE));

        VPDASSERT(readFromVpdCompare(proc, VPD_PRIMARY, testdata_primary, HARDWARE));
        VPDASSERT(readFromVpdCompare(proc, VPD_BACKUP, testdata_backup, HARDWARE));

        // The primary VPD is good, so make sure we read from that
        VPDASSERT(readFromVpdCompare(proc, VPD_AUTO, testdata_primary));

        // Write the test data to cache, make sure it gets written to both
        // EEPROMs as well
        VPDASSERT(writeToVpd(proc, VPD_AUTO, testdata_primary, AUTOSELECT));
        VPDASSERT(readFromVpdCompare(proc, VPD_AUTO, testdata_primary, CACHE));
        VPDASSERT(readFromVpdCompare(proc, VPD_PRIMARY, testdata_primary, CACHE));
        VPDASSERT(readFromVpdCompare(proc, VPD_BACKUP, testdata_primary, CACHE));
        VPDASSERT(readFromVpdCompare(proc, VPD_AUTO, testdata_primary, HARDWARE));
        VPDASSERT(readFromVpdCompare(proc, VPD_PRIMARY, testdata_primary, HARDWARE));
        VPDASSERT(readFromVpdCompare(proc, VPD_BACKUP, testdata_primary, HARDWARE));

        // Make back and primary inaccessible and make sure we fail on reads
        // from hardware
        setVpdAccessibility(proc, (EEPROM_VPD_ACCESSIBILITY_PRIMARY_DISABLED
                                   | EEPROM_VPD_ACCESSIBILITY_SECONDARY_DISABLED));
        VPDASSERT(readFromVpdCompare(proc, VPD_AUTO, 0, CACHE));
        VPDASSERT(readFromVpdCompare(proc, VPD_PRIMARY, 0, CACHE));
        VPDASSERT(readFromVpdCompare(proc, VPD_BACKUP, 0, CACHE));
        VPDASSERTFAIL(readFromVpdCompare(proc, VPD_AUTO, 0, HARDWARE));
        VPDASSERTFAIL(readFromVpdCompare(proc, VPD_PRIMARY, 0, HARDWARE));
        VPDASSERTFAIL(readFromVpdCompare(proc, VPD_BACKUP, 0, HARDWARE));

        // Make the primary VPD inaccessible and ensure the data only gets
        // written to the backup one through EECACHE
        setVpdAccessibility(proc, EEPROM_VPD_ACCESSIBILITY_PRIMARY_DISABLED);
        VPDASSERT(writeToVpd(proc, VPD_AUTO, testdata_backup, AUTOSELECT));
        setVpdAccessibility(proc, EEPROM_VPD_ACCESSIBILITY_NONE_DISABLED);
        VPDASSERT(readFromVpdCompare(proc, VPD_AUTO, testdata_backup, CACHE));
        VPDASSERT(readFromVpdCompare(proc, VPD_PRIMARY, testdata_backup, CACHE));
        VPDASSERT(readFromVpdCompare(proc, VPD_BACKUP, testdata_backup, CACHE));
        VPDASSERT(readFromVpdCompare(proc, VPD_AUTO, testdata_primary, HARDWARE));
        VPDASSERT(readFromVpdCompare(proc, VPD_PRIMARY, testdata_primary, HARDWARE));
        VPDASSERT(readFromVpdCompare(proc, VPD_BACKUP, testdata_backup, HARDWARE));

        // Make the backup VPD inaccessible and ensure the data only gets
        // written to the primary one through EECACHE
        setVpdAccessibility(proc, EEPROM_VPD_ACCESSIBILITY_SECONDARY_DISABLED);
        VPDASSERT(writeToVpd(proc, VPD_AUTO, testdata_primary, AUTOSELECT));
        setVpdAccessibility(proc, EEPROM_VPD_ACCESSIBILITY_NONE_DISABLED);
        VPDASSERT(readFromVpdCompare(proc, VPD_AUTO, testdata_primary, CACHE));
        VPDASSERT(readFromVpdCompare(proc, VPD_PRIMARY, testdata_primary, CACHE));
        VPDASSERT(readFromVpdCompare(proc, VPD_BACKUP, testdata_primary, CACHE));
        VPDASSERT(readFromVpdCompare(proc, VPD_AUTO, testdata_primary, HARDWARE));
        VPDASSERT(readFromVpdCompare(proc, VPD_PRIMARY, testdata_primary, HARDWARE));
        VPDASSERT(readFromVpdCompare(proc, VPD_BACKUP, testdata_backup, HARDWARE));

        // Make the primary inaccessible and make sure we read from the backup
        setVpdAccessibility(proc, EEPROM_VPD_ACCESSIBILITY_PRIMARY_DISABLED);
        VPDASSERT(readFromVpdCompare(proc, VPD_AUTO, testdata_backup));

        // Make the secondary inaccessible and make sure we read from the primary
        setVpdAccessibility(proc, EEPROM_VPD_ACCESSIBILITY_SECONDARY_DISABLED);
        VPDASSERT(readFromVpdCompare(proc, VPD_AUTO, testdata_primary));

        // Disable everything and make sure everything fails
        setVpdAccessibility(proc, (EEPROM_VPD_ACCESSIBILITY_CACHE_DISABLED
                                   | EEPROM_VPD_ACCESSIBILITY_PRIMARY_DISABLED
                                   | EEPROM_VPD_ACCESSIBILITY_SECONDARY_DISABLED));

        VPDASSERTFAIL(writeToVpd(proc, VPD_AUTO, testdata_primary, CACHE));
        VPDASSERTFAIL(writeToVpd(proc, VPD_PRIMARY, testdata_primary, CACHE));
        VPDASSERTFAIL(writeToVpd(proc, VPD_BACKUP, testdata_primary, CACHE));
        VPDASSERTFAIL(writeToVpd(proc, VPD_AUTO, testdata_primary, HARDWARE));
        VPDASSERTFAIL(writeToVpd(proc, VPD_PRIMARY, testdata_primary, HARDWARE));
        VPDASSERTFAIL(writeToVpd(proc, VPD_BACKUP, testdata_backup, HARDWARE));

        VPDASSERTFAIL(readFromVpdCompare(proc, VPD_AUTO, testdata_primary, CACHE));
        VPDASSERTFAIL(readFromVpdCompare(proc, VPD_PRIMARY, testdata_primary, CACHE));
        VPDASSERTFAIL(readFromVpdCompare(proc, VPD_BACKUP, testdata_primary, CACHE));
        VPDASSERTFAIL(readFromVpdCompare(proc, VPD_AUTO, testdata_primary, HARDWARE));
        VPDASSERTFAIL(readFromVpdCompare(proc, VPD_PRIMARY, testdata_primary, HARDWARE));
        VPDASSERTFAIL(readFromVpdCompare(proc, VPD_BACKUP, testdata_backup, HARDWARE));

        } while(false);

        TS_INFO( EXIT_MRK"test_redundantVpdAccess" );
    }

    /* @brief This test simulates a situation where there is different data in
     *        the primary and backup MVPD SEEPROMs. We call
     *        reloadMvpdEecacheFromNextSource to discard the data in the EECACHE
     *        (which has come from the primary SEEPROM), and then reload it
     *        (from the secondary SEEPROM).
     */
    void test_reloadMvpdEecacheFromNextSource()
    {
        #undef FUNC
        #define FUNC "test_reloadMvpdEecacheFromNextSource"

        TS_INFO(ENTER_MRK"test_reloadMvpdEecacheFromNextSource");

        const auto restore = saveMvpdState();

        do
        {

        Target* const proc = getProcessorWithTwoGoodVpds();

        if (!proc)
        {
            TS_FAIL("test_reloadMvpdEecacheFromNextSource: Can't find a processor with both good VPDs");
            break;
        }

        const uint64_t testdata1 = 0x1111111111111111;
        const uint64_t testdata2 = 0x2222222222222222;

        // Write to the primary cache, then write different data to the backup
        VPDASSERT(writeToVpd(proc, VPD_PRIMARY, testdata1, CACHE));
        VPDASSERT(writeToVpd(proc, VPD_BACKUP, testdata2, HARDWARE));

        // Verify that the primary hw + cache have been written
        VPDASSERT(readFromVpdCompare(proc, VPD_AUTO, testdata1, AUTOSELECT));
        VPDASSERT(readFromVpdCompare(proc, VPD_PRIMARY, testdata1, CACHE));
        VPDASSERT(readFromVpdCompare(proc, VPD_PRIMARY, testdata1, HARDWARE));

        // Verify that the backup data is different
        VPDASSERT(readFromVpdCompare(proc, VPD_BACKUP, testdata2, HARDWARE));

        // Discard what's in cache (i.e. the primary EEPROM's data) and reload
        // from the next source (i.e. the backup EEPROM). This should succeed.
        errlHndl_t errl = reloadMvpdEecacheFromNextSource(proc);

        if (errl)
        {
            TS_FAIL("test_reloadMvpdEecacheFromNextSource: failed with error %x", errl->plid());
            errlCommit(errl, CXXTEST_COMP_ID);
            break;
        }

        // Now all the reads should give us back what was in the backup SEEPROM
        VPDASSERT(readFromVpdCompare(proc, VPD_AUTO, testdata2, AUTOSELECT));
        VPDASSERT(readFromVpdCompare(proc, VPD_PRIMARY, testdata2, CACHE));
        VPDASSERT(readFromVpdCompare(proc, VPD_BACKUP, testdata2, HARDWARE));

        // This should fail since there are only two hardware MVPD sources
        errl = reloadMvpdEecacheFromNextSource(proc);

        if (!errl)
        {
            TS_FAIL("test_disableNextMpvdSource: expected second disable to fail");
            break;
        }

        errlCommit(errl, CXXTEST_COMP_ID);

        } while (0);

        TS_INFO( EXIT_MRK"test_reloadMvpdEecacheFromNextSource" );
    }
};

#endif
