/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/test/eepromddtest.H $                             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
#include "i2ctest.H"
#include "../eepromdd.H"

extern trace_desc_t* g_trac_eeprom;

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

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

            uint8_t* testBuffer = NULL;
            uint8_t* testBuffer_read = NULL;


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
                // Write:
                { 0x0000, VPD_PRIMARY, 0xfedcba9876543210, 8, false },
                // Read:
                { 0x0000, VPD_PRIMARY, 0xfedcba9876543210, 8, true  },

                // SBE Primary of processor - chip 2
                // Write:
                { 0x0100, SBE_PRIMARY, 0xaabb000000000000, 2, false },
                // Read:
                { 0x0100, SBE_PRIMARY, 0xaabb000000000000, 2, true  },

                // SBE Backup of processor - chip 3
                // Write:
                { 0x00F0, SBE_BACKUP, 0x1122334400000000, 4, false },
                // Read:
                { 0x00F0, SBE_BACKUP, 0x1122334400000000, 4, true  },
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
                    if( !isI2CAvailable( fullList[j] ) ||
                        !fullList[j]->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
                    {
                        continue;
                    }

                    for( uint32_t i = 0; i < NUM_CMDS; i++ )
                    {
                        uint64_t data;

                        // if a read, initialize data, else, set data to write
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

                // Test EEPROM Write of large size
                // @todo RTC:69113 - will clean this up:
                //  1) Make its own testcase function
                //  2) Will use a larger data set: Plan on using 4K header of
                //  test_signed_container and putting it into un-used area of
                //  SBE_BACKUP
                //  3) Will restore original data just in case
                uint64_t testBufLen = 0xF1;
                testBuffer = static_cast<uint8_t*>(malloc(testBufLen));
                memset(testBuffer, 0xFE, testBufLen);

                // Randomize the Data a bit
                for (uint64_t i = 0;
                       i < ((testBufLen / 8) + 1);
                     i++)
                    testBuffer[i*8] = i;

                for (uint64_t k = 0; k < 8; k++)
                    testBuffer[k] = k;

                // do the Write operation
                err = deviceOp( DeviceFW::WRITE,
                                fullList[0],
                                testBuffer,
                                testBufLen,
                                DEVICE_EEPROM_ADDRESS(SBE_BACKUP,0x0));
                if( err )
                {
                    TS_FAIL( "testEEPROMReadWrite - FAIL on large Data Write");
                    errlCommit( err,
                                EEPROM_COMP_ID );
                    delete err;
                    break;
                }

                // Read Back and Compare
                testBuffer_read = static_cast<uint8_t*>(malloc( testBufLen ));

                // clear read buffer
                memset (testBuffer_read, 0, testBufLen);

                // do the Read operation
                err = deviceOp( DeviceFW::READ,
                                fullList[0],
                                testBuffer_read,
                                testBufLen,
                                DEVICE_EEPROM_ADDRESS(SBE_BACKUP,0x0));


                if( err )
                {
                    TS_FAIL( "testEEPROMReadWrite - FAIL on large Data Read");
                    errlCommit( err,
                                EEPROM_COMP_ID );
                    delete err;
                    break;
                }


                // Compare the data
                if ( memcmp( testBuffer, testBuffer_read, testBufLen) )
                {
                    TS_FAIL( "testEEPROMReadWrite - MISCOMPARE on large Data");
                    break;
                }
                else
                {
                    TRACUCOMP( g_trac_eeprom, "testEEPROMReadWrite - large "
                                              "Data R/W Successful");
                }

            } while( 0 );

            // Clean up malloc'ed buffers
            if ( testBuffer != NULL)
            {
                free(testBuffer);
            }

            if ( testBuffer_read != NULL)
            {
                free(testBuffer_read);
            }


            TRACFCOMP( g_trac_eeprom,
                       "testEEPROMReadWrite - %d/%d fails",
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

            do
            {
                // Get a processor Target
                TARGETING::TargetService& tS = TARGETING::targetService();
                TARGETING::Target* testTarget = NULL;
                tS.masterProcChipTargetHandle( testTarget );
                assert(testTarget != NULL);

                // Skip this target if EEPROM isn't available or target is non
                // functional
                if( !isI2CAvailable( testTarget )  ||
                    !testTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
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
                    TS_FAIL( "Error should've resulted in Operation type of LAST_OP_TYPE!" );
                }
                else
                {
                    delete err;
                    err = NULL;
                }
            } while( 0 );
            TRACFCOMP( g_trac_eeprom,
                       "testEEPROMInvalidOperation - %d/%d fails",
                       fails, num_ops );
        }

        /**
         * @brief EEPROM Invalid Chip Test
         *      This test will pass in an invalid chip identifier which should
         *      result in an error being returned back from
         */
        void testEEPROMInvalidChip ( void )
        {
            errlHndl_t err = NULL;
            int64_t fails = 0, num_ops = 0;
            uint64_t data = 0x0ull;
            size_t dataSize = 8;


            do
            {
                // Get a processor Target
                TARGETING::TargetService& tS = TARGETING::targetService();
                TARGETING::Target* testTarget = NULL;
                tS.masterProcChipTargetHandle( testTarget );
                assert(testTarget != NULL);

                // Skip this target if EEPROM isn't available. or target is non
                // functional
                if( !isI2CAvailable( testTarget )  ||
                    !testTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
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
                    TS_FAIL( "Error should've resulted in using EEPROM chip %d!",
                             LAST_CHIP_TYPE );
                }
                else
                {
                    delete err;
                    err = NULL;
                }
            } while( 0 );

            TRACFCOMP( g_trac_eeprom,
                       "testEEPROMInvalidChip - %d/%d fails",
                       fails, num_ops );
        }

};

#endif
