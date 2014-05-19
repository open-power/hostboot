/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/test/i2ctest.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#include "../i2c.H"

extern trace_desc_t* g_trac_i2c;

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

using namespace TARGETING;


// Used to ignore comparing data on reads
#define I2C_TEST_IGNORE_DATA_COMPARE 0xFFFFFFFFFFFFFFFF


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
                //  -- For Processor SEEPROM's, ONLY USE ENGINE 0

                // READ All 3 at address 0 for 8 bytes first
                // Ignore data compare as we're not sure what's
                //  been writted there

                // Read SBE Primary:  Murano-0, port-0
                { 0x00, 0x00, 0xAC, I2C_TEST_IGNORE_DATA_COMPARE,
                     8, true, TARGETING::TYPE_PROC }, // Read

                // Read SBE Backup:  Murano-0, port-0
                { 0x00, 0x00, 0xAE, I2C_TEST_IGNORE_DATA_COMPARE,
                     8, true, TARGETING::TYPE_PROC }, // Read

                // Read From MVPD: Murano-0, port 1
                { 0x01, 0x00, 0xA4, I2C_TEST_IGNORE_DATA_COMPARE,
                     8, true, TARGETING::TYPE_PROC }, // Read data back


                // Read/Write SBE Primary:  Murano-0, port-0
                // Safe to write to first 0x300: 0x0-0x2FF

                { 0x00, 0x00, 0xAC, 0x0020ababcdcdefef,
                     8, false, TARGETING::TYPE_PROC }, // Write data to 0x0020

                { 0x00, 0x00, 0xAC, 0x0020000000000000,
                     2, false, TARGETING::TYPE_PROC }, // Write addr for read

                { 0x00, 0x00, 0xAc, 0xababcdcdefef0000,
                     6, true, TARGETING::TYPE_PROC  }, // Read data back

                { 0x00, 0x00, 0xAC, 0x0023000000000000,
                     2, false, TARGETING::TYPE_PROC }, // Write addr for read

                { 0x00, 0x00, 0xAC, 0xcdefef0000000000,
                     3, true, TARGETING::TYPE_PROC  }, // Read data back

                { 0x00, 0x00, 0xAC, 0x0025831200000000,
                     4, false, TARGETING::TYPE_PROC }, // Write data to 0x0025

                { 0x00, 0x00, 0xAC, 0x0024000000000000,
                     2, false, TARGETING::TYPE_PROC }, // Write addr for read

                { 0x00, 0x00, 0xAC, 0xef83120000000000,
                     3, true, TARGETING::TYPE_PROC  }, // Read data back



                // Read/Write SBE Backup:  Murano-0, port-0
                // Safe to write to first 0x300: 0x0-0x2FF

                { 0x00, 0x00, 0xAE, 0x0030ababcdcdefef,
                     8, false, TARGETING::TYPE_PROC }, // Write data to 0x0030

                { 0x00, 0x00, 0xAE, 0x0030000000000000,
                     2, false, TARGETING::TYPE_PROC }, // Write addr for read

                { 0x00, 0x00, 0xAE, 0xababcdcdefef0000,
                     6, true, TARGETING::TYPE_PROC  }, // Read data back

                { 0x00, 0x00, 0xAE, 0x0033000000000000,
                     2, false, TARGETING::TYPE_PROC }, // Write addr for read

                { 0x00, 0x00, 0xAE, 0xcdefef0000000000,
                     3, true, TARGETING::TYPE_PROC  }, // Read data back

                { 0x00, 0x00, 0xAE, 0x0035971200000000,
                     4, false, TARGETING::TYPE_PROC }, // Write data to 0x0035

                { 0x00, 0x00, 0xAE, 0x0034000000000000,
                     2, false, TARGETING::TYPE_PROC }, // Write addr for read

                { 0x00, 0x00, 0xAE, 0xef97120000000000,
                     3, true, TARGETING::TYPE_PROC  }, // Read data back


                // MEMBUF TESTS
                // Use the following commands when Centaur devices are
                // supported in simics.  No target date.
                // Real Centaur Devices
//                { 0x00, 0x00, 0x51, 0x1111000000000000,
//                    2, false, TARGETING::TYPE_MEMBUF }, // Write addr 0x0000
//                { 0x00, 0x00, 0x51, 0x0000000000000000,
//                    8, true, TARGETING::TYPE_MEMBUF  }, // Read 8 bytes
//                { 0x00, 0x00, 0x53, 0x0000000000000000,
//                    2, false, TARGETING::TYPE_MEMBUF }, // Write addr 0x0000
//                { 0x00, 0x00, 0x53, 0x0000000000000000,
//                    8, true, TARGETING::TYPE_MEMBUF  }, // Read 8 bytes
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

                // Get a Centaur Target
                TargetHandleList centList;
                TARGETING::PredicateCTM predCent( TARGETING::CLASS_CHIP,
                                                  TARGETING::TYPE_MEMBUF );
                tS.getAssociated( centList,
                                  sysTarget,
                                  TARGETING::TargetService::CHILD,
                                  TARGETING::TargetService::ALL,
                                  &predCent );

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

                        case TARGETING::TYPE_MEMBUF:
                            if( ( 0 == centList.size() ) ||
                                ( NULL == centList[0] ) )
                            {
                                TRACFCOMP( g_trac_i2c,
                                           ERR_MRK"Centaur List has %d entries.  Either "
                                           "empty or first target is NULL!",
                                           centList.size() );
                                continue;
                            }

                            theTarget = centList[0];
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
                                                        testData[i].devAddr ) );

                    if( err )
                    {
                        TS_FAIL( "testI2CDirect - fail on cmd %d out of %d",
                                  i, NUM_CMDS );
                        errlCommit( err,
                                    I2C_COMP_ID );
                        delete err;
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
                                       i, NUM_CMDS, data, testData[i].data );
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

                // Read/Write SBE Backup:  Murano-0, port-0
                // Safe to write to first 0x300: 0x0-0x2FF
                { 0x00, 0x00, 0xAE, 0x0123,
                  0xFEFEDADA57579191, 8, TARGETING::TYPE_PROC },

                // Read/Write SBE Primary:  Murano-0, port-0
                // Safe to write to first 0x300: 0x0-0x2FF
                { 0x00, 0x00, 0xAC, 0x02FC,
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

                // Get a Centaur Target
                TargetHandleList centList;
                TARGETING::PredicateCTM predCent( TARGETING::CLASS_CHIP,
                                                  TARGETING::TYPE_MEMBUF );
                tS.getAssociated( centList,
                                  sysTarget,
                                  TARGETING::TargetService::CHILD,
                                  TARGETING::TargetService::ALL,
                                  &predCent );

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
                                   testData[i].size, i );
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

                        case TARGETING::TYPE_MEMBUF:
                            if( ( 0 == centList.size() ) ||
                                ( NULL == centList[0] ) )
                            {
                                TRACFCOMP( g_trac_i2c,
                                           ERR_MRK"Centaur List has %d entries."
                                           "  Either empty or first target is "
                                           "NULL!",
                                           centList.size() );
                                continue;
                            }

                            theTarget = centList[0];
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
                                                    &(testData[i].offset))));

                        if( err )
                        {
                            TS_FAIL( "testI2COffset - OP %d FAILED "
                                     "- cmd %d out of %d",
                                     j, i, NUM_CMDS );
                            errlCommit( err,
                                        I2C_COMP_ID );
                            delete err;
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
                                    testData[i].data, data, i, NUM_CMDS, j);
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
                                    original_data, data, i, NUM_CMDS, j);
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
        void testI2CSetupMasters ( void )
        {
            errlHndl_t err = NULL;
            int fails = 0;
            const int NUM_CMDS = 1;

            TRACFCOMP( g_trac_i2c,
                       "testI2CSetupMasters - Start" );

            err = I2C::i2cSetupMasters();

            if( err )
            {
                TS_FAIL( "testI2CSetupMasters - Error returned from "
                         "i2cSetupMasters()");
                fails++;
                delete err;
            }

            TRACFCOMP( g_trac_i2c,
                       "testI2CSetupMasters - End: %d/%d fails",
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
            /* Test i2cSetBusVariables() with different i_modes */
            /****************************************************/
            struct
            {
                I2C::i2c_bus_setting_mode_t i_mode;
                uint64_t o_bus_speed;
            } testData[] =
            {
                // 1MHz
                { I2C::SET_I2C_BUS_1MHZ, 1000 },

                // 400KHz
                { I2C::SET_I2C_BUS_400KHZ, 400 },

                // READ_I2C_BUS_ATTRIBUTES should default to 1MHz
                { I2C::READ_I2C_BUS_ATTRIBUTES, 1000 },
            };

            uint32_t NUM_CMDS = sizeof(testData)/sizeof(testData[0]);

            for ( uint32_t i = 0; i < NUM_CMDS; i++ )
            {
                cmds++;

                err = I2C::i2cSetBusVariables(procTarget,
                                              testData[i].i_mode,
                                              io_args);

                if( err )
                {
                    TS_FAIL( "testI2cSetBusVariables - Error returned from "
                             "i2cSetBusVariables: i_mode=0x%d, i=%d",
                             testData[i].i_mode, i);
                    fails++;
                    delete err;
                }
                else if ( io_args.bus_speed != testData[i].o_bus_speed )
                {
                    TS_FAIL( "testI2cSetBusVariables - i2cSetBusVariables "
                             "returned bad data: i_mode=0x%d, i=%d "
                             "o_bus_speed=%d, io_args.bus_speed=%d",
                             testData[i].i_mode, i,
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
                  31, 800, 6250 },

                // NEST_FREQ_MHz=2000, bus_speed=400KHz
                { 2000, 400,
                  77, 2000, 2500 },

                // NEST_FREQ_MHz=2400, bus_speed=1MHz
                { 2400, 1000,
                  37, 800, 6250 },

                // NEST_FREQ_MHz=2400, bus_speed=400KHz
                { 2400, 400,
                  93, 2000, 2500 },
            };

            NUM_CMDS = sizeof(testData_2)/sizeof(testData_2[0]);

            uint16_t l_brd = 0;
            uint64_t l_pi =0;
            uint64_t l_tc=0;

            for ( uint32_t i = 0; i < NUM_CMDS; i++ )
            {
                I2C::g_I2C_NEST_FREQ_MHZ = testData_2[i].i_nest_freq_mhz;

                cmds++;
                l_brd = I2C::i2cGetBitRateDivisor(testData_2[i].i_bus_speed);
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
                       "testI2CSetBusVariables - End: %d/%d fails",
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
                                                0x50 ) );

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
                                DEVICE_I2C_ADDRESS( 0x0,
                                                    0x0,
                                                    0x50 ) );

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
