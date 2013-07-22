/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/test/i2ctest.H $                                  */
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
#include <targeting/common/predicates/predicates.H>
#include <targeting/common/attributes.H>

extern trace_desc_t* g_trac_i2c;

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

using namespace TARGETING;


// Used to ignore comparing data on reads
#define I2C_TEST_IGNORE_DATA_COMPARE 0xFFFFFFFFFFFFFFFF

// @todo RTC:72715: Re-visit the use of this function when we have full
// Attribute support
bool isI2CAvailable( TARGETING::Target * i_target )
{
    bool avail = true;

    // Rudimentary Check - Every I2C Master has VPD Primary Attribute
    EepromVpdPrimaryInfo eepromData;
    if( i_target->tryGetAttr<ATTR_EEPROM_VPD_PRIMARY_INFO>( eepromData ) )
    {

        if( ( 0x80 == eepromData.port ) &&
            ( 0x80 == eepromData.devAddr ) &&
            ( 0x80 == eepromData.engine ) )
        {
            // Default values, thus, not present
            avail = false;
        }
    }
    else
    {
        // Didn't find attribute, thus, not present
        avail = false;
    }

    return avail;
}

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
                // Safe to write to first 1K: 0x-0x400

                { 0x00, 0x00, 0xAC, 0x0000ababcdcdefef,
                     8, false, TARGETING::TYPE_PROC }, // Write data to 0x0000

                { 0x00, 0x00, 0xAC, 0x0000000000000000,
                     2, false, TARGETING::TYPE_PROC }, // Write addr for read

                { 0x00, 0x00, 0xAc, 0xababcdcdefef0000,
                     6, true, TARGETING::TYPE_PROC  }, // Read data back

                { 0x00, 0x00, 0xAC, 0x0003000000000000,
                     2, false, TARGETING::TYPE_PROC }, // Write addr for read

                { 0x00, 0x00, 0xAC, 0xcdefef0000000000,
                     3, true, TARGETING::TYPE_PROC  }, // Read data back

                { 0x00, 0x00, 0xAC, 0x0005ee1200000000,
                     4, false, TARGETING::TYPE_PROC }, // Write data to 0x0005

                { 0x00, 0x00, 0xAC, 0x0005000000000000,
                     2, false, TARGETING::TYPE_PROC }, // Write addr for read

                { 0x00, 0x00, 0xAC, 0xee12000000000000,
                     2, true, TARGETING::TYPE_PROC  }, // Read data back



                // Read/Write SBE Backup:  Murano-0, port-0
                // Safe to write to first 1K: 0x-0x400

                { 0x00, 0x00, 0xAE, 0x0000ababcdcdefef,
                     8, false, TARGETING::TYPE_PROC }, // Write data to 0x0000

                { 0x00, 0x00, 0xAE, 0x0000000000000000,
                     2, false, TARGETING::TYPE_PROC }, // Write addr for read

                { 0x00, 0x00, 0xAE, 0xababcdcdefef0000,
                     6, true, TARGETING::TYPE_PROC  }, // Read data back

                { 0x00, 0x00, 0xAE, 0x0003000000000000,
                     2, false, TARGETING::TYPE_PROC }, // Write addr for read

                { 0x00, 0x00, 0xAE, 0xcdefef0000000000,
                     3, true, TARGETING::TYPE_PROC  }, // Read data back

                { 0x00, 0x00, 0xAE, 0x0005ee1200000000,
                     4, false, TARGETING::TYPE_PROC }, // Write data to 0x0005

                { 0x00, 0x00, 0xAE, 0x0005000000000000,
                     2, false, TARGETING::TYPE_PROC }, // Write addr for read

                { 0x00, 0x00, 0xAE, 0xee12000000000000,
                     2, true, TARGETING::TYPE_PROC  }, // Read data back


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
                            TS_FAIL( "Invalid Chip type specificed in testData!" );
                            fails++;
                            continue;
                            break;
                    };

                    // Check to see if I2C function is there
                    if( !isI2CAvailable( theTarget ) )
                    {
                        TRACFCOMP( g_trac_i2c,
                               "testI2CDirect Operation - no i2c function" );
                        continue;
                    }

                    // check to see if the target is functional before we
                    // continue..
                    if
                        (!theTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
                    {

                        TRACFCOMP( g_trac_i2c,
                            "testI2CDirect Operation - target not functional");

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
                       "testI2CDirect - %d/%d fails",
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
                // Safe to write to first 1K: 0x-0x400
                { 0x00, 0x00, 0xAE, 0x0123,
                  0xFEFEDADA57579191, 8, TARGETING::TYPE_PROC },

                // Read/Write SBE Primary:  Murano-0, port-0
                // Safe to write to first 1K: 0x-0x400
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
                            TS_FAIL( "Invalid Chip type specificed in testData!" );
                            fails++;
                            continue;
                            break;
                    };


                    // Check to see if I2C function is there
                    if( !isI2CAvailable( theTarget ) )
                    {
                        TRACFCOMP( g_trac_i2c,
                               "testI2COfset Operation - no i2c function" );
                        continue;
                    }

                    // check to see if the target is functional before we
                    // continue..
                    if
                        (!theTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
                    {

                        TRACFCOMP( g_trac_i2c,
                            "testI2COffset Operation - target not functional");

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
                                TS_FAIL( "testI2COffset - Failure comparing new data!" );
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
                                TS_FAIL( "testI2COffset - Failure comparing original data!" );
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
                       "testI2COffset - %d/%d fails",
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
                TS_FAIL( "Failure to return error using Master Sentinel Chip!" );
                fails++;
            }
            else
            {
                delete err;
                err = NULL;
            }

            TRACFCOMP( g_trac_i2c,
                       "testI2CInvalidTarget - %d/%d fails",
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

            do
            {
                // Get a processor Target
                TARGETING::TargetService& tS = TARGETING::targetService();
                TARGETING::Target* testTarget = NULL;
                tS.masterProcChipTargetHandle( testTarget );
                assert(testTarget != NULL);

                // Check to see if I2C function is there
                if( !isI2CAvailable( testTarget ) )
                {
                    TRACFCOMP( g_trac_i2c,
                               "testI2CInvalid Operation - no i2c function" );


                    continue;
                }

                // check to see if the target is functional before we
                // continue..
                if
                    (!testTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
                {
                    TRACFCOMP( g_trac_i2c,
                               "testI2CInvalide Operation - not functional" );


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
                    TS_FAIL( "Error should've resulted in Operation type of LAST_OP_TYPE!" );
                }
                else
                {
                    delete err;
                    err = NULL;
                }
            } while( 0 );
            TRACFCOMP( g_trac_i2c,
                       "testI2CInvalidOperation - %d/%d fails",
                       fails, num_ops );
        }

};

#endif
