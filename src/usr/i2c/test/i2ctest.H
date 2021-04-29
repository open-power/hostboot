/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/test/i2ctest.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
#ifndef __I2CTEST_H
#define __I2CTEST_H

/**
 *  @file i2ctest.H
 *
 *  @brief Test cases for I2C code
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
#include <secureboot/service.H>

extern trace_desc_t* g_trac_i2c;

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

using namespace TARGETING;


// Used to ignore comparing data on reads
#define I2C_TEST_IGNORE_DATA_COMPARE 0xFFFFFFFFFFFFFFFF

using I2C::HOST_ENGINE_D;
using I2C::HOST_ENGINE_E;

class I2CTest: public CxxTest::TestSuite
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
         * @brief Call I2C Setup Masters Function
         *      This function is part of the shutdown path and is
         *      needed by PHYP to ensure that the I2C masters are
         *      setup correctly on the system.
         */
        void testI2CSetupActiveMasters ( void )
        {
            errlHndl_t err = NULL;
            int fails = 0;
            const int NUM_CMDS = 1;

            TRACFCOMP( g_trac_i2c,
                       "testI2CSetupActiveMasters - Start" );

            err = I2C::i2cSetupActiveMasters(I2C::I2C_PROC_ALL);

            if( err )
            {
                TS_FAIL( "testI2CSetupActiveMasters - Error returned from "
                         "i2cSetupActiveMasters(I2C_PROC_ALL)");
                fails++;
                delete err;
            }

            TRACFCOMP( g_trac_i2c,
                       "testI2CSetupActiveMasters - End: %d/%d fails",
                       fails, NUM_CMDS );
        }


        /**
         * @brief Call I2C Set Bus Variables and related functions
         *
         *      Test that i2cSetBusVariables() and the functions it uses
         *      are returning expected values.
         */
        void testI2cSetBusVariables ( void )
        {
            errlHndl_t err = NULL;
            int fails = 0;
            int cmds = 0;
            I2C::misc_args_t io_args;

            TRACFCOMP( g_trac_i2c,
                       "testI2cSetBusVariables - Start" );

            // Get top level system target
            TARGETING::TargetService& tS = TARGETING::targetService();
            TARGETING::Target * sysTarget = NULL;
            tS.getTopLevelTarget( sysTarget );
            assert( sysTarget != NULL );

            // Get the Proc Target
            TARGETING::Target* procTarget = NULL;
            tS.masterProcChipTargetHandle( procTarget );

            /****************************************************/
            /* Test i2cSetBusVariables() with different i_speed */
            /****************************************************/
            struct
            {
                uint64_t i_speed;
                uint64_t o_bus_speed;
            } testData[] =
            {
                // 1MHz
                { I2C_BUS_SPEED_1MHZ, 1000 },

                // 400KHz
                { I2C_BUS_SPEED_400KHZ, 400 },

                // I2C_BUS_SPEED_FROM_MRW (==0) should default to 400kHz
                // with a processor target using Host I2C
                { I2C_BUS_SPEED_FROM_MRW, 400 },
            };

            uint32_t NUM_CMDS = sizeof(testData)/sizeof(testData[0]);

            // set Processor Target to Host I2C mode and default engine/port
            io_args.switches.useHostI2C = 1;
            io_args.switches.useFsiI2C = 0;
            io_args.engine = HOST_ENGINE_E;
            io_args.port = 1;

            for ( uint32_t i = 0; i < NUM_CMDS; i++ )
            {
                cmds++;

                err = I2C::i2cSetBusVariables(procTarget,
                                              testData[i].i_speed,
                                              io_args);

                if( err )
                {
                    TS_FAIL( "testI2cSetBusVariables - Error returned from "
                             "i2cSetBusVariables: i_speed=%d, i=%d",
                             testData[i].i_speed, i);
                    fails++;
                    delete err;
                }
                else if ( io_args.bus_speed != testData[i].o_bus_speed )
                {
                    TS_FAIL( "testI2cSetBusVariables - i2cSetBusVariables "
                             "returned bad data: i_speed=%d, i=%d "
                             "o_bus_speed=%d, io_args.bus_speed=%d",
                             testData[i].i_speed, i,
                             testData[i].o_bus_speed, io_args.bus_speed);
                    fails++;
                }
            }

            /****************************************************/
            /* Test functions that set other variables          */
            /****************************************************/
            struct
            {
                uint64_t i_nest_freq_mhz;
                uint64_t i_bus_speed;
                uint16_t o_bit_rate_divisor;
                uint64_t o_polling_interval_ns;
                uint64_t o_timeout_count;
            } testData_2[] =
            {
                // Most likely settings

                // NEST_FREQ_MHz=2000, bus_speed=1MHz
                { 2000, 1000,
                  499, 800, 25000 },

                // NEST_FREQ_MHz=2000, bus_speed=400KHz
                { 2000, 400,
                  1249, 2000, 10000 },

                // NEST_FREQ_MHz=2400, bus_speed=1MHz
                { 2400, 1000,
                  599, 800, 25000 },

                // NEST_FREQ_MHz=2400, bus_speed=400KHz
                { 2400, 400,
                  1499, 2000, 10000 },
            };

            NUM_CMDS = sizeof(testData_2)/sizeof(testData_2[0]);

            uint16_t l_brd = 0;
            uint64_t l_pi =0;
            uint64_t l_tc=0;

            for ( uint32_t i = 0; i < NUM_CMDS; i++ )
            {
                I2C::g_I2C_NEST_FREQ_MHZ = testData_2[i].i_nest_freq_mhz;

                cmds++;
                l_brd = I2C::i2cGetBitRateDivisor(
                                             testData_2[i].i_bus_speed,
                                             testData_2[i].i_nest_freq_mhz);
                l_pi = I2C::i2cGetPollingInterval(testData_2[i].i_bus_speed);
                l_tc = I2C_TIMEOUT_COUNT(l_pi);

                if ((l_brd != testData_2[i].o_bit_rate_divisor ) ||
                    (l_pi != testData_2[i].o_polling_interval_ns ) ||
                    (l_tc != testData_2[i].o_timeout_count )
                   )
                {
                    TS_FAIL( "testI2cSetBusVariables - Bad Calculations i=%d "
                             "nest_freq_mhz=%d, bus_speed=%d, "
                             "l_brd=%d, testData_2[i].o_bit_rate_divisor=%d, "
                             "l_pi=%d, testData_2[i].o_polling_interval_ns=%d, "
                             "l_tc=%d, testData_2[i].o_timeout_count=%d",
                             i, testData_2[i].i_nest_freq_mhz,
                             testData_2[i].i_bus_speed,
                             l_brd, testData_2[i].o_bit_rate_divisor,
                             l_pi, testData_2[i].o_polling_interval_ns,
                             l_tc, testData_2[i].o_timeout_count );
                    fails++;
                }
            }

            // reset global variable
            I2C::g_I2C_NEST_FREQ_MHZ = I2C::i2cGetNestFreq();

            TRACFCOMP( g_trac_i2c,
                       "testI2cSetBusVariables - End: %d/%d fails",
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

        void testI2cForceReset(void)
        {


            errlHndl_t err = NULL;

            do
            {
                I2C::misc_args_t io_args;

                uint64_t data = 0x0;

                // Get the Proc Target
                TARGETING::TargetService& tS = TARGETING::targetService();
                TARGETING::Target* procTarget = NULL;
                tS.masterProcChipTargetHandle( procTarget );
                assert( procTarget != NULL );

                // reset the target and then try a read
                if(procTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
                {
                    TRACFCOMP( g_trac_i2c,
                               " testI2cForceReset- functional good path" );
                    io_args.engine = HOST_ENGINE_E;
                    io_args.port = 0x1;
                    io_args.switches.useHostI2C = 1;
                    //get engine lock attr for engine 0
                    //prevents sbe update test fails


                    size_t data_size = 8;

                    uint8_t offset = 0;
                    err = deviceOp( DeviceFW::READ,
                                    procTarget,
                                    &data,
                                    data_size,
                                    DEVICE_I2C_ADDRESS_OFFSET( 0x01, HOST_ENGINE_E, 0xA0,
                                                               sizeof(offset),
                                                               &offset,
                                                               I2C_MUX::NOT_APPLICABLE,
                                                               nullptr) );

                    if(err)
                    {
                        TS_FAIL("testI2cForceReset: I2C read failed");
                        errlCommit( err,I2C_COMP_ID );
                        break;
                    }

                    mutex_t * engineLock = NULL;
                    engineLock =
                    procTarget->getHbMutexAttr<TARGETING::ATTR_I2C_ENGINE_MUTEX_0>();

                    recursive_mutex_lock( engineLock );

                    //force reset
                    err = I2C::i2cReset(procTarget,
                                        io_args,
                                        I2C::FORCE_UNLOCK_RESET);

                    recursive_mutex_unlock( engineLock );

                    //if there was an error for a reason commit it
                    if(err)
                    {
                        TS_FAIL("I2C reset failed");
                        errlCommit( err,I2C_COMP_ID );
                        break;
                    }
                    else
                    {
                        TS_INFO("i2cReset succeeded");
                    }

                    nanosleep( 0, 100);

                    data = 0;
                    err = deviceOp( DeviceFW::READ,
                                    procTarget,
                                    &data,
                                    data_size,
                                    DEVICE_I2C_ADDRESS( 0x01,
                                                        HOST_ENGINE_E,
                                                        0xA0,
                                                        I2C_MUX::NOT_APPLICABLE,
                                                        nullptr) );
                }

                if(err)
                {
                    TS_FAIL("testI2cForceReset failed err detected");
                    errlCommit( err,I2C_COMP_ID );
                    break;
                }

                if(data == 0)
                {
                    //there should be some data
                    TS_FAIL("testI2cForceReset failed data read is 0");
                    break;
                }


            }while(0);


        }

        /**
         * @brief Verify we retrieve all of the EEPROMs we can think of
         */
        void test_getMasterInfo( void )
        {
            std::list<I2C::MasterInfo_t> info;
            TARGETING::TargetHandleList allchips;
            TARGETING::getAllChips( allchips, TARGETING::TYPE_NA );
            for( TARGETING::TargetHandleList::iterator tgt = allchips.begin();
                 tgt != allchips.end();
                 ++tgt )
            {
                getMasterInfo( *tgt, info );
                for( std::list<I2C::MasterInfo_t>::iterator i2cm = info.begin();
                     i2cm != info.end();
                     ++i2cm )
                {
                    TRACFCOMP( g_trac_i2c, "Found I2C Master: Master=%.8X :: Scom=%.8X, Eng=%d, Freq=%d", TARGETING::get_huid(*tgt), i2cm->scomAddr, i2cm->engine, i2cm->freq );
                }
            }
        }

        void test_getDeviceInfo( void )
        {
            TRACFCOMP(g_trac_i2c, ENTER_MRK"test_getDeviceInfo");

            std::vector<I2C::DeviceInfo_t> l_deviceInfo;

            // Loop through every chip
            TARGETING::TargetHandleList allchips;
            TARGETING::getAllChips( allchips, TARGETING::TYPE_NA );
            for( auto &tgt : allchips )
            {
                getDeviceInfo( tgt, l_deviceInfo);
            }

            std::vector<I2C::DeviceInfo_t>::const_iterator devInfo_iter;
            for(devInfo_iter = l_deviceInfo.begin();
                devInfo_iter != l_deviceInfo.end();
                devInfo_iter++)
            {
                TRACFCOMP(g_trac_i2c, "Found Device Info: Engine=%d, Port=%d",
                          devInfo_iter->engine,
                          devInfo_iter->masterPort);
                TRACFCOMP(g_trac_i2c, "Type=%.2X, addr=%X, slavePort=%d",
                          devInfo_iter->deviceType,
                          devInfo_iter->addr,
                          devInfo_iter->slavePort);
                TRACFCOMP(g_trac_i2c, "busFreqKhz=%d, purpose=%X",
                          devInfo_iter->busFreqKhz,
                          devInfo_iter->devicePurpose)
            }

            TRACFCOMP(g_trac_i2c, EXIT_MRK"test_getDeviceInfo");
        }

        void test_secureInfo( void )
        {
#ifdef CONFIG_SECUREBOOT
        do
        {
        TS_INFO("test_secureInfo Start SECUREBOOT::enabled()=%d", SECUREBOOT::enabled());
        if (SECUREBOOT::enabled()) // executing in secure mode
        {
            errlHndl_t l_err = nullptr;
            uint64_t l_regValue = 0; // security switch
            l_err = SECUREBOOT::getSecuritySwitch(l_regValue,
                        TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL);
            if (l_err)
            {
                TS_FAIL("test_secureInfo Unable to retrieve the security switch, so unable to continue checks");
                errlCommit(l_err, CXXTEST_COMP_ID );
                break;
            }

            if (!(l_regValue & static_cast<uint64_t>(SECUREBOOT::ProcSecurity::SULBit)))
            {
                TS_FAIL("test_secureInfo SULBit (SEEPROM Update Lock) should have been set in host_secureboot_lockdown");
                break;
            }
            else
            {
                TS_INFO("test_secureInfo SULBit (SEEPROM Update Lock) properly set");
            }

            if (!(l_regValue & static_cast<uint64_t>(SECUREBOOT::ProcSecurity::SabBit)))
            {
                TS_FAIL("test_secureInfo SabBit (Secure Access Bit) should have been set before reaching RUNTIME");
                break;
            }
            else
            {
                TS_INFO("test_secureInfo SabBit (Secure Access Bit) properly set");
            }

            if (!(l_regValue & static_cast<uint64_t>(SECUREBOOT::ProcSecurity::SOLBit)))
            {
                TS_INFO("test_secureInfo SOLBit (Secure OCMB Lock) should have been set in host_secure_rng");
                break;
            }
            else
            {
                TS_INFO("test_secureInfo SOLBit (Secure OCMB Lock) properly set");
            }
        } // end executing in Secure Mode
        } while(0);

        TS_INFO("test_secureInfo Exit");
#endif
        }

        /**
         * @brief Verify the functions that create the userdata values
         */
        void test_setI2CUserData( void )
        {

            int64_t fails = 0, num_ops = 0;

            TRACFCOMP( g_trac_i2c,
                       "test_setI2CUserData - Start" );


            // Test userdata_1
            uint64_t userdata_1 = 0x0;
            uint64_t userdata_1_result = 0xABCDEFABFFFFFFFF;

            I2C::status_reg_t status_reg;
            status_reg.value = 0xABCDEFAB55555555;

            userdata_1 = I2C::I2C_SET_USER_DATA_1 (
                             status_reg,
                             MASTER_PROCESSOR_CHIP_TARGET_SENTINEL);

            num_ops++;
            if ( userdata_1 != userdata_1_result )
            {
                TS_FAIL( "testI2CUserData - Fail in generating userdata)1: "
                         "0x%X - should be 0x%X",
                         userdata_1, userdata_1_result );
                fails++;
            }

            // Test userdata_2
            uint64_t userdata_2 = 0x0;
            uint64_t userdata_2_result = 0x34679A5D1234FEDC;

            I2C::misc_args_t args;
            args.engine = 0x34;
            args.port = 0x67;
            args.devAddr = 0x1234123412349A5D;
            args.bus_speed = 0xFFFFFFFFFFFF1234;
            args.bit_rate_divisor = 0xFEDC;

            userdata_2 = I2C::I2C_SET_USER_DATA_2 ( args );

            num_ops++;
            if ( userdata_2 != userdata_2_result )
            {
                TS_FAIL( "testI2CUserData - Fail in generating userdata_2: "
                         "0x%X - should be 0x%X",
                         userdata_2, userdata_2_result );
                fails++;
            }

           TRACFCOMP( g_trac_i2c,
                       "testI2CUserData - End: %d/%d fails",
                       fails, num_ops );

        }


};

#endif
