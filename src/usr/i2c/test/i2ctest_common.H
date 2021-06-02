/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/test/i2ctest_common.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
#ifndef __I2CTEST_COMMON_H
#define __I2CTEST_COMMON_H

/**
 *  @file i2ctest_common.H
 *
 *  @brief Test cases for I2C code under HBI and HBRT
 */
#include <sys/time.h>

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/driverif.H>
#include <i2c/i2creasoncodes.H>
#include <i2c/i2cif.H>
#include <targeting/common/predicates/predicates.H>
#include <targeting/common/attributes.H>
#include <targeting/common/utilFilter.H>
#include <i2c/i2c.H>

extern trace_desc_t* g_trac_i2c;

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

using namespace TARGETING;


// Used to ignore comparing data on reads
#define I2C_TEST_IGNORE_DATA_COMPARE 0xFFFFFFFFFFFFFFFF

using I2C::HOST_ENGINE_D;
using I2C::HOST_ENGINE_E;

class I2CTestCommon: public CxxTest::TestSuite
{
    public:

        /**
         * @brief I2C Direct Test
         *      This test will test a variety of direct reads and writes
         *      with various lengths across slave devices.
         *
         *      Currently only Processor targets are supported in simics.
         *
         *      Add other targets to this testcase when their support is
         *      added.
         */
        void testI2CDirect ( void )
        {
            errlHndl_t err = NULL;
            int cmds = 0;
            int fails = 0;

            TRACFCOMP( g_trac_i2c,
                       "testI2CDirect - Start" );

            struct
            {
                uint64_t port;      // Master engine port
                uint64_t engine;    // Master engine
                uint64_t devAddr;   // Slave Device address

                uint64_t data;      // Data to write or compare to
                                    // if data = I2C_TEST_IGNORE_DATA_COMPARE
                                    //  than ignore data compare

                size_t   size;        // Number of Bytes to read/write
                bool     rnw;         // Read (true), Write (false)
                TARGETING::TYPE type; // Target Type
            } testData[] =
            {

                // PROCESSOR TESTS
                //  -- For DIMM SPD's, ONLY USE ENGINE 3

                // READ All 3 at address 0 for 8 bytes first
                // Ignore data compare as we're not sure what's
                //  been writted there

                { 0x01, HOST_ENGINE_E, 0xA0, I2C_TEST_IGNORE_DATA_COMPARE,
                     8, true, TARGETING::TYPE_PROC }, // Read

                { 0x0a, HOST_ENGINE_E, 0xA0, I2C_TEST_IGNORE_DATA_COMPARE,
                     8, true, TARGETING::TYPE_PROC }, // Read

                { 0x0b, HOST_ENGINE_E, 0xA0, I2C_TEST_IGNORE_DATA_COMPARE,
                     8, true, TARGETING::TYPE_PROC }, // Read data back

                { 0x01, HOST_ENGINE_E, 0xA0, I2C_TEST_IGNORE_DATA_COMPARE,
                     8, true, TARGETING::TYPE_PROC }, // Read

                { 0x01, HOST_ENGINE_E, 0xA0, I2C_TEST_IGNORE_DATA_COMPARE,
                     8, true, TARGETING::TYPE_PROC }, // Read

                { 0x01, HOST_ENGINE_E, 0xA0, I2C_TEST_IGNORE_DATA_COMPARE,
                     8, true, TARGETING::TYPE_PROC }, // Read data back

                // Read/Write SPD
                // Safe to write addresses past 2048

                { 0x01, HOST_ENGINE_E, 0xA0, 0x0810ababcdcdefef,
                     8, false, TARGETING::TYPE_PROC }, // Write data to 0x0810

                { 0x01, HOST_ENGINE_E, 0xA0, 0x0810000000000000,
                     2, false, TARGETING::TYPE_PROC }, // Write addr for read

                { 0x01, HOST_ENGINE_E, 0xA0, 0xababcdcdefef0000,
                     6, true, TARGETING::TYPE_PROC  }, // Read data back

                { 0x01, HOST_ENGINE_E, 0xA0, 0x0813000000000000,
                     2, false, TARGETING::TYPE_PROC }, // Write addr for read

                { 0x01, HOST_ENGINE_E, 0xA0, 0xcdefef0000000000,
                     3, true, TARGETING::TYPE_PROC  }, // Read data back

                { 0x01, HOST_ENGINE_E, 0xA0, 0x0825831200000000,
                     4, false, TARGETING::TYPE_PROC }, // Write data to 0x0825

                { 0x01, HOST_ENGINE_E, 0xA0, 0x0824000000000000,
                     2, false, TARGETING::TYPE_PROC }, // Write addr for read

                { 0x01, HOST_ENGINE_E, 0xA0, 0x0083120000000000,
                     3, true, TARGETING::TYPE_PROC  }, // Read data back

                /* TODO RTC 248506: Test other I2C engines than engine E

                { 0x00, HOST_ENGINE_D, 0xA0, 0x0810ababcdcdefef,
                     8, false, TARGETING::TYPE_PROC }, // Write data to 0x0810

                { 0x00, HOST_ENGINE_D, 0xA0, 0x0810000000000000,
                     2, false, TARGETING::TYPE_PROC }, // Write addr for read

                { 0x00, HOST_ENGINE_D, 0xA0, 0xababcdcdefef0000,
                     6, true, TARGETING::TYPE_PROC  }, // Read data back

                { 0x00, HOST_ENGINE_D, 0xA0, 0x0813000000000000,
                     2, false, TARGETING::TYPE_PROC }, // Write addr for read

                { 0x00, HOST_ENGINE_D, 0xA0, 0xcdefef0000000000,
                     3, true, TARGETING::TYPE_PROC  }, // Read data back

                { 0x00, HOST_ENGINE_D, 0xA0, 0x0825831200000000,
                     4, false, TARGETING::TYPE_PROC }, // Write data to 0x0825

                { 0x00, HOST_ENGINE_D, 0xA0, 0x0824000000000000,
                     2, false, TARGETING::TYPE_PROC }, // Write addr for read

                { 0x00, HOST_ENGINE_D, 0xA0, 0x0083120000000000,
                     3, true, TARGETING::TYPE_PROC  }, // Read data back

                */
            };

            const uint32_t NUM_CMDS = sizeof(testData)/sizeof(testData[0]);


            // Skipping I2C test altogether in VBU/VPO environment
            if( TARGETING::is_vpo() )
            {
                return;
            }

            do
            {
                // Get top level system target
                TARGETING::TargetService& tS = TARGETING::targetService();
                TARGETING::Target * sysTarget = NULL;
                TARGETING::Target * theTarget = NULL;
                tS.getTopLevelTarget( sysTarget );
                assert( sysTarget != NULL );

                // Get the Proc Target
                TARGETING::Target* procTarget = NULL;
                tS.masterProcChipTargetHandle( procTarget );

                for( uint32_t i = 0; i < NUM_CMDS; i++ )
                {

                    // Make sure size is less than or = to 8 bytes
                    //  to fit into data
                    uint64_t data;
                    if (testData[i].size > 8)
                    {
                        TRACFCOMP( g_trac_i2c,
                                   "testI2CDirect Size (%d) is greater than"
                                   " 8 bytes. Skipping test %d",
                                   testData[i].size, i );
                        continue;
                    }

                    // if a read, initialize data, else, set data to write
                    if( testData[i].rnw )
                    {
                        data = 0x0ull;
                    }
                    else
                    {
                        data = testData[i].data;
                    }

                    // Decide which target to use
                    switch( testData[i].type )
                    {
                        case TARGETING::TYPE_PROC:
                            if( NULL == procTarget )
                            {
                                TRACFCOMP( g_trac_i2c,
                                           ERR_MRK"Processor Target is NULL, go to next "
                                           "operation!" );
                                continue;
                            }

                            theTarget = procTarget;
                            break;

                        default:
                            TS_FAIL( "testI2CDirect - Invalid Chip type "
                                     "specificed in testData!" );
                            fails++;
                            continue;
                            break;
                    };

                    // Check to see if the target is functional before we
                    // continue..
                    if
                        (!theTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
                    {

                        TRACFCOMP( g_trac_i2c,
                            "testI2CDirect - target not functional");

                        continue;
                    }

                    // do the operation
                    cmds++;
                    err = deviceOp( (testData[i].rnw ? DeviceFW::READ : DeviceFW::WRITE),
                                    theTarget,
                                    &data,
                                    testData[i].size,
                                    DEVICE_I2C_ADDRESS( testData[i].port,
                                                        testData[i].engine,
                                                        testData[i].devAddr,
                                                        0xFF,
                                                        nullptr) );

                    if( err )
                    {
                        TS_FAIL( "testI2CDirect - fail on cmd %d out of %d",
                                  i + 1, NUM_CMDS );
                        errlCommit( err,
                                    I2C_COMP_ID );
                        fails++;
                        continue;
                    }

                    // If a write op, wait 5ms for EEPROM to write data
                    // to its internal memory
                    if (testData[i].rnw == false)
                    {
                        nanosleep(0,5 * NS_PER_MSEC);   // 5 msec
                    }

                    // compare data for the read, but ignore case where
                    //  data = I2C_TEST_IGNORE_DATA_COMPARE
                    if( ( testData[i].rnw ) &&
                        ( testData[i].data != I2C_TEST_IGNORE_DATA_COMPARE ))
                    {
                        if( data != testData[i].data )
                        {
                            TRACFCOMP( g_trac_i2c,
                                       "testI2CDirect - cmd: %d/%d, Data read:"
                                       " %016llx, expected: %016llx",
                                       i + 1, NUM_CMDS, data, testData[i].data );
                            TS_FAIL( "testI2CDirect - Failure comparing read data!" );
                            fails++;
                            continue;
                        }
                    }
                }
            } while( 0 );

            TRACFCOMP( g_trac_i2c,
                       "testI2CDirect - End: %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief I2C Offset
         *      This test will use the I2C interface where an offset for
         *      the device is provided before the reads or write.
         *
         *      Currently only Processor targets are supported in simics.
         *
         *      Add other targets to this testcase when their support is
         *      added.
         */
        void testI2COffset ( void )
        {
            errlHndl_t err = NULL;
            int cmds = 0;
            int fails = 0;
            uint64_t original_data = 0;
            uint64_t data = 0;

            TRACFCOMP( g_trac_i2c,
                       "testI2COffset - Start" );

            struct
            {
                uint64_t port;         // Master engine port
                uint64_t engine;       // Master engine
                uint64_t devAddr;      // Slave Device address
                uint16_t offset;       // Slave Device offset - 2 bytes
                uint64_t data;         // Data to write
                size_t   size;         // Number of Bytes to read/write
                TARGETING::TYPE type;  // Target Type
            } testData[] =
            {

                // PROCESSOR TESTS

                // Read/Write DIMM SPD
                { 0x01, HOST_ENGINE_E, 0xA0, 0x0820,
                  0xFEFEDADA57579191, 8, TARGETING::TYPE_PROC },

                // Read/Write DIMM SPD
                { 0x0a, HOST_ENGINE_E, 0xA0, 0x0820,
                  0x5ABC310000000000, 3, TARGETING::TYPE_PROC },
            };

            const uint32_t NUM_CMDS = sizeof(testData)/sizeof(testData[0]);


            // Skipping I2C test altogether in VBU/VPO environment
            if( TARGETING::is_vpo() )
            {
                return;
            }

            do
            {

                // Get top level system target
                TARGETING::TargetService& tS = TARGETING::targetService();
                TARGETING::Target * sysTarget = NULL;
                TARGETING::Target * theTarget = NULL;
                tS.getTopLevelTarget( sysTarget );
                assert( sysTarget != NULL );

                // Get the Proc Target
                TARGETING::Target* procTarget = NULL;
                tS.masterProcChipTargetHandle( procTarget );

                for ( uint32_t i = 0; i < NUM_CMDS; i++ )
                {
                    TRACUCOMP( g_trac_i2c,"testI2COffset: Outer Loop i= "
                               "%d, NUM_CMDS = %d", i, NUM_CMDS);

                    // Make sure size is less than or = to 8 bytes
                    //  to fit into data
                    if (testData[i].size > 8)
                    {
                        TRACFCOMP( g_trac_i2c,
                                   "testI2COffset: Size (%d) is greater than"
                                   " 8 bytes. Skipping test %d",
                                   testData[i].size, i + 1 );
                        continue;
                    }

                    // Decide which target to use
                    switch( testData[i].type )
                    {
                        case TARGETING::TYPE_PROC:
                            if( NULL == procTarget )
                            {
                                TRACFCOMP( g_trac_i2c,
                                           ERR_MRK"Processor Target is NULL, "
                                           "go to next operation!" );
                                continue;
                            }

                            theTarget = procTarget;
                            break;

                        default:
                            TS_FAIL( "testI2COffset - Invalid Chip type "
                                     "specificed in testData!" );
                            fails++;
                            continue;
                            break;
                    };


                    // Check to see if the target is functional before we
                    // continue..
                    if
                        (!theTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
                    {

                        TRACFCOMP( g_trac_i2c,
                            "testI2COffset - target not functional");

                        continue;
                    }


                    // For Each Set of Data, 5 operations:
                    // 1) Read Original Data and Save It
                    // 2) Write New Data
                    // 3) Read New Data and Compare
                    // 4) Write Back Original Data
                    // 5) Read Back Original Data and Compare

                    // Before starting, clear original data buffer
                    original_data = 0x0ull;

                    for (uint8_t j = 1; j <= 5; j++)
                    {

                        // Clear data variable
                        data = 0x0ull;

                        // For Loop 2: set data to new data
                        if ( j == 2 )
                            data = testData[i].data;

                        // For Loop 4: set data to original_data
                        if ( j == 4 )
                            data = original_data;

                        // increment cmd op counter
                        cmds++;

                        err = deviceOp(
                                (j%2) ? DeviceFW::READ : DeviceFW::WRITE,
                                theTarget,
                                &data,
                                testData[i].size,
                                DEVICE_I2C_ADDRESS_OFFSET(
                                                    testData[i].port,
                                                    testData[i].engine,
                                                    testData[i].devAddr,
                                                    sizeof(testData[i].offset),
                                                    reinterpret_cast<uint8_t*>(
                                                    &(testData[i].offset)),
                                                    0xFF,
                                                    nullptr));

                        if( err )
                        {
                            TS_FAIL( "testI2COffset - OP %d FAILED "
                                     "- cmd %d out of %d",
                                     j, i + 1, NUM_CMDS );
                            errlCommit( err,
                                        I2C_COMP_ID );
                            fails++;
                            continue;
                        }


                        // If a write op, wait 5ms for EEPROM to write data
                        // to its internal memory
                        if ( (j%2) == 0 )
                        {
                            nanosleep(0,5 * NS_PER_MSEC);   // 5 msec
                        }

                        // Handle loop-specific results

                        // For Loop 1: save original data
                        if ( j == 1 )
                        {
                            original_data = data;

                            // Always trace original data - just in case
                            TRACFCOMP(g_trac_i2c,"testI2COffset: "
                                      "original_data=0x%x", original_data);
                        }


                        // For Loop 3: compare new data
                        if ( j == 3 )
                        {

                            TRACUCOMP( g_trac_i2c,"testI2COffset: "
                               "New Data Compare: "
                               "written=0x%016llx, read_back=0x%016llx",
                               testData[i].data, data);

                            if( data != testData[i].data )
                            {
                                TRACFCOMP(g_trac_i2c,"testI2COffset: New "
                                    "Data Compare Fail: wrote=%016llx, "
                                    "read back=%016llx. cmd: %d/%d (%d)",
                                    testData[i].data, data, i + 1, NUM_CMDS, j);
                                TS_FAIL( "testI2COffset - Failure comparing "
                                         "new data!" );
                                fails++;

                                // Don't break - try to write back original data
                                continue;
                            }

                        }

                        // For Loop 5: compare writing-back original data
                        if ( j == 5 )
                        {
                            TRACUCOMP( g_trac_i2c,"testI2COffset: "
                               "Original Data Compare: "
                               "original=0x%016llx, read_back=0x%016llx",
                               original_data, data);

                            if( data != original_data )
                            {
                                TRACFCOMP(g_trac_i2c,"testI2COffset: New "
                                    "Data Compare Fail: original=%016llx, "
                                    "read back=%016llx. cmd: %d/%d (%d)",
                                    original_data, data, i + 1, NUM_CMDS, j);
                                TS_FAIL( "testI2COffset - Failure comparing "
                                         "original data!" );
                                fails++;

                                // Break: stop testing if we can't write back
                                // original data successfully
                                break;
                            }
                        }

                    }  // end of 'j' loop: 5 ops per testData[i]

                }  // end of 'i' loop: unique testData[i] sets

            } while( 0 );

            TRACFCOMP( g_trac_i2c,
                       "testI2COffset - End: %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief I2C Invalid Target test
         *      This test will pass in the Master Sentinel chip in as a target
         *      to be sure that an error is returned, and that the error returned
         *      is the correct error.
         */
        void testI2CInvalidTarget ( void )
        {
            errlHndl_t err = NULL;
            int fails = 0;
            const int NUM_CMDS = 1;

            TRACFCOMP( g_trac_i2c,
                       "testI2CInvalidTarget - Start" );

            // Set processor chip to the master
            TARGETING::Target* testTarget = MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
            uint64_t data = 0x0ull;
            size_t size = sizeof(uint64_t);

            err = deviceOp( DeviceFW::READ,
                            testTarget,
                            &data,
                            size,
                            DEVICE_I2C_ADDRESS( 0x0,
                                                0x0,
                                                0x50,
                                                0xFF,
                                                nullptr) );

            if( !err )
            {
                TS_FAIL( "testI2CInvalidTarget - Failure to return error "
                         "using Master Sentinel Chip!" );
                fails++;
            }
            else
            {
                delete err;
                err = NULL;
            }

            TRACFCOMP( g_trac_i2c,
                       "testI2CInvalidTarget - End: %d/%d fails",
                       fails, NUM_CMDS );
        }

        /**
         * @brief I2C Invalid Operation Test
         *      This test will pass in an invalid Operation type.  It
         *      is expected that an error log is to be returned.
         */
        void testI2CInvalidOperation ( void )
        {
            errlHndl_t err = NULL;
            int64_t fails = 0, num_ops = 0;
            uint64_t data = 0x0ull;
            size_t dataSize = 8;

            TRACFCOMP( g_trac_i2c,
                       "testI2CInvalidOperation - Start" );

            do
            {
                // Get a processor Target
                TARGETING::TargetService& tS = TARGETING::targetService();
                TARGETING::Target* testTarget = NULL;
                tS.masterProcChipTargetHandle( testTarget );
                assert(testTarget != NULL);


                // check to see if the target is functional before we
                // continue..
                if
                    (!testTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
                {
                    TRACFCOMP( g_trac_i2c,
                               "testI2CInvalidOperation - not functional" );


                    continue;
                }

                num_ops++;
                err = deviceOp( DeviceFW::LAST_OP_TYPE,
                                testTarget,
                                &data,
                                dataSize,
                                DEVICE_I2C_ADDRESS( 0x1,
                                                    0x3,
                                                    0xA0,
                                                    0xFF,
                                                    nullptr) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testI2CInvalidOperation - Error should've "
                             "resulted in Operation type of LAST_OP_TYPE!" );
                }
                else
                {
                    delete err;
                    err = NULL;
                }
            } while( 0 );
            TRACFCOMP( g_trac_i2c,
                       "testI2CInvalidOperation - End: %d/%d fails",
                       fails, num_ops );
        }


};

#endif
