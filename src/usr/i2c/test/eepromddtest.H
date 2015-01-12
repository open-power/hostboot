/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/test/eepromddtest.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
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
#ifndef __EEPROMTEST_H
#define __EEPROMTEST_H

/**
 *  @file eepromtest.H
 *
 *  @brief Test cases for the eeprom dd code
 */

#include <sys/time.h>
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/driverif.H>
#include <i2c/eepromddreasoncodes.H>
#include <targeting/common/commontargeting.H>
#include <pnor/pnorif.H>
#include "i2ctest.H"
#include "../eepromdd.H"

extern trace_desc_t* g_trac_eeprom;

// NOTE: TRACUCOMP defined/controlled in i2ctest.H

using namespace TARGETING;
using namespace EEPROM;


class EEPROMTest: public CxxTest::TestSuite
{
    public:

        /**
         * @brief EEPROM Read/Write Test
         *      This test will test a variety of reads/writes and lengths
         *      across slave devices.
         */
        void testEEPROMReadWrite ( void )
        {
            errlHndl_t err = NULL;
            int fails = 0;
            int num_ops = 0;

            TRACFCOMP( g_trac_eeprom,
                       "testEEPROMReadWrite - Start" );

            struct
            {
                uint64_t offset;    // Internal Slave Device Offset to access
                uint64_t chip;      // Which EEPROM chip hung off of the target to access
                uint64_t data;      // Data to write or compare to
                size_t   size;      // Number of bytes to read/write
                bool     rnw;       // Read (true), Write (false)
            } testData[] =

            {
                // MVPD of processor - chip 0
                // Read - Only
                { 0x0000, VPD_PRIMARY, 0x000f17ba00000000, 4, true  },

                // SBE Primary of processor - chip 2
                // Write: over 128-byte page boundary:
                { 0x017F, SBE_PRIMARY, 0xaabb000000000000, 2, false },
                // Read:
                { 0x017F, SBE_PRIMARY, 0xaabb000000000000, 2, true  },

                // SBE Backup of processor - chip 3
                // Write: over 256-byte page boundary:
                { 0x01FD, SBE_BACKUP, 0x1122334400000000, 4, false },
                // Read:
                { 0x01FD, SBE_BACKUP, 0x1122334400000000, 4, true  },

                // SBE Backup of processor - chip 3
                // Write: inside 128 page boundary:
                { 0x005B, SBE_BACKUP, 0xbad5adcabf0b7000, 7, false },
                // Read:
                { 0x005B, SBE_BACKUP, 0xbad5adcabf0b7000, 7, true  },

            };

            const uint32_t NUM_CMDS = sizeof(testData)/sizeof(testData[0]);

            // Skipping EEPROM test altogether in VBU/VPO environment
            if( TARGETING::is_vpo() )
            {
                return;
            }

            do
            {
                // Get a processor Target
                TARGETING::TargetService& l_targetService = TARGETING::targetService();
                TARGETING::Target* testTarget = NULL;
                l_targetService.masterProcChipTargetHandle( testTarget );
                assert(testTarget != NULL);
                TargetHandleList fullList;
                fullList.push_back( testTarget );

                // Uncomment the following code when other I2C devices
                // are supported
//                TARGETING::TargetService& tS = TARGETING::targetService();
//                TARGETING::Target * sysTarget = NULL;

//                // Get top level system target
//                tS.getTopLevelTarget( sysTarget );
//                assert( sysTarget != NULL );

//                // Predicate for the Procs
//                TARGETING::PredicateCTM predProc( TARGETING::CLASS_CHIP,
//                                                  TARGETING::TYPE_PROC );

//                // Predicate for the DIMMs
//                TARGETING::PredicateCTM predDimm( TARGETING::CLASS_CARD,
//                                                  TARGETING::TYPE_DIMM );

//                // Expression to get both Procs and DIMMs.
//                PredicatePostfixExpr query;
//                query.push( &predProc ).push( &predDimm ).Or();
//                tS.getAssociated( fullList,
//                                  sysTarget,
//                                  TARGETING::TargetService::CHILD,
//                                  TARGETING::TargetService::ALL,
//                                  &query );
//                assert( 0 != fullList.size() );

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

                        // if a read, clear data; else, set data to write
                        if( testData[i].rnw )
                        {
                            data = 0x0ull;
                        }
                        else
                        {
                            data = testData[i].data;
                        }

                        // do the operation
                        err = deviceOp( (testData[i].rnw ? DeviceFW::READ : DeviceFW::WRITE),
                                        fullList[j],
                                        &data,
                                        testData[i].size,
                                        DEVICE_EEPROM_ADDRESS(
                                                      testData[i].chip,
                                                      testData[i].offset));

                        if( err )
                        {
                            TS_FAIL( "testEEPROMReadWrite - fail on cmd %d out of %d",
                                     i, NUM_CMDS );
                            errlCommit( err,
                                        EEPROM_COMP_ID );
                            delete err;
                            fails++;
                            continue;
                        }

                        // compare data for the read
                        if( testData[i].rnw )
                        {
                            if( data != testData[i].data )
                            {
                                TRACFCOMP( g_trac_eeprom,
                                           "testEEPROMReadWrite - cmd: %d/%d, Data read: %016llx, "
                                           "expected: %016llx",
                                           i, NUM_CMDS, data, testData[i].data );
                                TS_FAIL( "testEEPROMReadWrite - Failure comparing read data!" );
                                fails++;
                                continue;
                            }
                        }
                    }
                }

            } while( 0 );

            TRACFCOMP( g_trac_eeprom,
                       "testEEPROMReadWrite - End: %d/%d fails",
                       fails, num_ops );
        }


        /**
         * @brief EEPROM Read/Write Large Test
         *      This test will read and write 603 bytes of data to SBE Backup
         *      VPD.  It will attempt to restore the original data at
         *      the end of the test.
         *
         *      Note: 1st 768 bytes of SBE EEPROM data is currently blank, so
         *            this test will read and write below that address space
         */
        void testEEPROMReadWriteLarge ( void )
        {
            errlHndl_t err = NULL;
            int fails = 0;
            int num_ops = 0;
            int cmds = 0;

            // Create 603-byte buffers
            size_t  testBufLen = 603;
            uint8_t testBuffer[testBufLen];
            uint8_t new_data[testBufLen];
            uint8_t original_data[testBufLen];

            // Use small offset to force more complicated page-boundary testing
            uint8_t offset = 0x11;


            TRACFCOMP( g_trac_eeprom,
                       "testEEPROMReadWriteLarge - Start" );

            // Skipping EEPROM test altogether in VBU/VPO environment
            if( TARGETING::is_vpo() )
            {
                return;
            }

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
                     (pnorSectionInfo.size < HEADER_OFFSET + testBufLen)
                   )
                {
                    TS_FAIL("testEEPROMReadWriteLarge: PNOR::getSectionInfo failed or size too small: pnorSize=0x%X, HEADER_OFFSET=0x%X, testBufLen = 0x%X", pnorSectionInfo.size, HEADER_OFFSET, testBufLen);
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

                //  Valid Buffer, so memcpy the first 603 bytes
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
                                                      offset));

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

                            TRACUCOMP(g_trac_eeprom,"testEEPROMReadWriteLarge:"
                                      " saving original data. i=%d, j=%d",
                                      i, j);
                        }

                        // For Loop 3: compare new data
                        if ( j == 3 )
                        {
                            // Compare the data
                            if ( memcmp(testBuffer, new_data, testBufLen) )
                            {
                                TRACFCOMP(g_trac_eeprom,
                                          "testEEPROMReadWriteLarge: MISCOMPARE"
                                          " of new data, len=0x%X", testBufLen);

                                TRACFBIN( g_trac_eeprom, "testBuffer=",
                                          testBuffer, testBufLen);
                                TRACFBIN( g_trac_eeprom, "new_data=",
                                          new_data, testBufLen);
                                TS_FAIL( "testEEPROMReadWriteLarge - MISCOMPARE"
                                         " on writing new data");
                                fails++;

                                // Don't break - try to write back original data
                                continue;
                            }
                            else
                            {
                                TRACUCOMP(g_trac_eeprom,
                                          "testEEPROMReadWriteLarge: New "
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
                                TRACFCOMP(g_trac_eeprom,
                                          "testEEPROMReadWriteLarge: MISCOMPARE"
                                          " of original data, len=0x%X",
                                          testBufLen);

                                TRACFBIN( g_trac_eeprom, "testBuffer=",
                                          testBuffer, testBufLen);
                                TRACFBIN( g_trac_eeprom, "orig_data=",
                                          original_data, testBufLen);

                                TS_FAIL( "testEEPROMReadWriteLarge - MISCOMPARE"
                                         " on writing back original data");
                                fails++;

                                break;
                            }
                            else
                            {
                                TRACUCOMP(g_trac_eeprom,
                                          "testEEPROMReadWriteLarge: Original "
                                          "Data R/W Successful i=%d,j=%d",
                                          i, j);
                            }
                        }

                    }  // end of 'j' loop: 5 ops per target

                }  // end of 'i' loop: target loop

            } while( 0 );

            TRACFCOMP( g_trac_eeprom,
                       "testEEPROMReadWriteLarge - End: %d/%d fails",
                       fails, num_ops );
        }

        /**
         * @brief EEPROM Invalid Operation Test
         *      This test will pass in an invalid Operation type.  It
         *      is expected that an error log is to be returned.
         */
        void testEEPROMInvalidOperation ( void )
        {
            errlHndl_t err = NULL;
            int64_t fails = 0, num_ops = 0;
            uint64_t data = 0x0ull;
            size_t dataSize = 8;

            TRACFCOMP( g_trac_eeprom,
                       "testEEPROMInvalidOperation - Start" );

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
                                                       0x0 ) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testEEPROMInvalidOperation - Error should've "
                             " resulted in Operation type of LAST_OP_TYPE!" );
                }
                else
                {
                    TRACUCOMP(g_trac_eeprom, "testEEPROMInvalidOperation - "
                              "Error log returned as expected. RC=0x%X",
                              err->reasonCode() );
                    delete err;
                    err = NULL;
                }
            } while( 0 );
            TRACFCOMP( g_trac_eeprom,
                       "testEEPROMInvalidOperation - End: %d/%d fails",
                       fails, num_ops );
        }


        /**
         * @brief EEPROM Overflow Test
         *      This test will pass in a target which does not have an
         *      EEPROM attribute associated with it.  It is expected that i
         *      an error log is to be returned.
         */
        void testEEPROMOverflow ( void )
        {
            errlHndl_t err = NULL;
            int64_t fails = 0, num_ops = 0;
            uint64_t data = 0x0ull;
            size_t dataSize = 0;
            uint64_t offset = 0x0ull;

            TRACFCOMP( g_trac_eeprom,
                       "testEEPROMOverflow - Start" );

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
                                                       offset ) );

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
                    TRACUCOMP(g_trac_eeprom, "testEEPROMOverflow - "
                              "Error log returned as expectede. RC=0x%X",
                              err->reasonCode() );
                    delete err;
                    err = NULL;
                }
            } while( 0 );

            TRACFCOMP( g_trac_eeprom,
                       "testEEPROMOverflow - End: %d/%d fails",
                       fails, num_ops );
        }


        /**
         * @brief EEPROM Invalid Chip Test
         *      This test will pass in an invalid chip identifier which should
         *      result in an error being returned.
         */
        void testEEPROMInvalidChip ( void )
        {
            errlHndl_t err = NULL;
            int64_t fails = 0, num_ops = 0;
            uint64_t data = 0x0ull;
            size_t dataSize = 8;

            TRACFCOMP( g_trac_eeprom,
                       "testEEPROMInvalidChip - Start" );

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
                                                       0x0 ) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testEEPROMInvalidChip - Error should've "
                             "resulted in using EEPROM chip %d!",
                             LAST_CHIP_TYPE );
                }
                else
                {
                    TRACUCOMP(g_trac_eeprom, "testEEPROMInvalidChip - "
                              "Error log returned as expected. RC=0x%x ",
                              err->reasonCode() );
                    delete err;
                    err = NULL;
                }

            } while( 0 );

            TRACFCOMP( g_trac_eeprom,
                       "testEEPROMInvalidChip - End: %d/%d fails",
                       fails, num_ops );
        }

        /**
         * @brief Verify we retrieve all of the EEPROMs we can think of
         */
        void test_getEEPROMs( void )
        {
            std::list<EEPROM::EepromInfo_t> info;
            getEEPROMs( info );
            for( std::list<EEPROM::EepromInfo_t>::iterator eep = info.begin();
                 eep != info.end();
                 ++eep )
            {
                TRACFCOMP( g_trac_eeprom, "Found EEPROM: Master=%.8X, Eng=%d, Port=%d, Freq=%d, Addr=%.2X, Dev=%d, Targ=%.8X", TARGETING::get_huid(eep->i2cMaster), eep->engine, eep->port, eep->busFreq, eep->devAddr, eep->device, eep->assocTarg );
            }
        }

};

#endif
