//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/i2c/test/i2ctest.H $
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

using namespace TARGETING;

bool isI2CAvailable( TARGETING::Target * i_target )
{
    bool avail = true;
    EepromAddrInfo0 eepromData;
    if( i_target->tryGetAttr<ATTR_EEPROM_ADDR_INFO0>( eepromData ) )
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
         * @brief I2C Read/Write Test
         *      This test will test a variety of reads/writes and lengths
         *      across slave devices.
         *
         *      TODO - Currently there is only 1 dummy I2C device that is
         *      accessible via Simics.  Once another is added the structure
         *      used to direct commands will be altered to use the new device
         *      and also be changed to not be destructive as they are currently.
         */
        void testI2CReadWrite ( void )
        {
            errlHndl_t err = NULL;
            int cmds = 0;
            int fails = 0;

            TRACFCOMP( g_trac_i2c,
                       "testI2CReadWrite - Start" );

            typedef enum
            {
                I2C_PROC_TARGET,
                I2C_CENTAUR_TARGET,
            } targetType_t;

            struct
            {
                uint64_t port;      // Master engine port
                uint64_t engine;    // Master engine
                uint64_t devAddr;   // Slave Device address
                uint64_t data;      // Data to write or compare to
                size_t   size;      // Number of Bytes to read/write
                bool     rnw;       // Read (true), Write (false)
                targetType_t type;  // Target Type
            } testData[] =
            {
                // Dummy I2C Device in Simics
                { 0x00, 0x00, 0x50, 0x1234BA9876543210,
                    8, false, I2C_PROC_TARGET }, // Write data
                { 0x00, 0x00, 0x50, 0x1234000000000000,
                    2, false, I2C_PROC_TARGET }, // Write addr for read
                { 0x00, 0x00, 0x50, 0xba98765432100000,
                    6, true, I2C_PROC_TARGET  }, // Read data back
                { 0x00, 0x00, 0x50, 0x1100556677880000,
                    6, false, I2C_PROC_TARGET },
                { 0x00, 0x00, 0x50, 0x1100000000000000,
                    2, false, I2C_PROC_TARGET },
                { 0x00, 0x00, 0x50, 0x5566778800000000,
                    4, true, I2C_PROC_TARGET  },

                // TODO - Once these commands are working with Simics, they
                // can be enabled.  No target date.
                // Real Centaur Devices
//                { 0x00, 0x00, 0x51, 0x1111000000000000,
//                    2, false, I2C_CENTAUR_TARGET }, // Write addr of 0x0000
//                { 0x00, 0x00, 0x51, 0x0000000000000000,
//                    8, true, I2C_CENTAUR_TARGET  }, // Read 8 bytes
//                { 0x00, 0x00, 0x53, 0x0000000000000000,
//                    2, false, I2C_CENTAUR_TARGET }, // Write addr of 0x0000
//                { 0x00, 0x00, 0x53, 0x0000000000000000,
//                    8, true, I2C_CENTAUR_TARGET  }, // Read 8 bytes
            };

            const uint32_t NUM_CMDS = sizeof(testData)/sizeof(testData[0]);

            //@TODO
            //@VBU workaround - Disable I2C test case on fake target
            //Test case use fake targets, which will fail when running
            //on VBU.  Need to fix this.
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

                    // Decide which target to use
                    switch( testData[i].type )
                    {
                        case I2C_PROC_TARGET:
                            if( NULL == procTarget )
                            {
                                TRACFCOMP( g_trac_i2c,
                                           ERR_MRK"Processor Target is NULL, go to next "
                                           "operation!" );
                                continue;
                            }

                            theTarget = procTarget;
                            break;

                        case I2C_CENTAUR_TARGET:
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
                               "testI2ReadWrite Operation - no i2c function" );


                        continue;
                    }

                    // check to see if the target is functional before we
                    // continue..
                    if
                        (!theTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
                    {

                        TRACFCOMP( g_trac_i2c,
                               "testI2ReadWrite Operation - target not functional" );

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
                        TS_FAIL( "testI2CReadWrite - fail on cmd %d out of %d",
                                  i, NUM_CMDS );
                        errlCommit( err,
                                    I2C_COMP_ID );
                        delete err;
                        fails++;
                        continue;
                    }

                    // compare data for the read
                    if( testData[i].rnw )
                    {
                        if( data != testData[i].data )
                        {
                            TRACFCOMP( g_trac_i2c,
                                       "testI2CReadWrite - cmd: %d/%d, Data read: %016llx, "
                                       "expected: %016llx",
                                       i, NUM_CMDS, data, testData[i].data );
                            TS_FAIL( "testI2CReadWrite - Failure comparing read data!" );
                            fails++;
                            continue;
                        }
                    }
                }
            } while( 0 );

            TRACFCOMP( g_trac_i2c,
                       "testI2CReadWrite - %d/%d fails",
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
