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
 *  @brief Test case for I2C code
 */
#include <sys/time.h>

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <errl/errltypes.H>
#include <devicefw/driverif.H>
#include <i2c/i2creasoncodes.H>

extern trace_desc_t* g_trac_i2c;

using namespace TARGETING;

// Address and data to read/write
struct testI2CParms
{
    uint64_t port;
    uint64_t engine;
    uint64_t addr;
    uint64_t devAddr;
    uint64_t data;
    size_t   size;
};

// Test table values
const testI2CParms g_i2cWriteCmdTable[] =
{
    { 0x00, 0x00, 0x1234, 0x50, 0xFEDCBA9876543210, 8 },
    { 0x00, 0x00, 0x1234, 0x50, 0xFEDCBA9876543210, 8 },
};

const uint32_t g_i2cWriteCmdTableSz =
sizeof(g_i2cWriteCmdTable)/sizeof(testI2CParms);


class I2CTest: public CxxTest::TestSuite
{
    public:

        /**
         * @brief I2C test #1
         *        Write value and read back to verify
         *        Currently only 1 operation
         */
        void testI2C1(void)
        {
            errlHndl_t err = NULL;

            TS_TRACE( "I2C Test 1: its running!" );

            do
            {
                TARGETING::TargetService& l_targetService = TARGETING::targetService();
                TARGETING::Target* testTarget = NULL;
                l_targetService.masterProcChipTargetHandle( testTarget );
                assert(testTarget != NULL);

                testI2CParms testEntry = g_i2cWriteCmdTable[0];

                // Perform I2C write
                uint64_t data = testEntry.data;
                TS_TRACE( "I2C - calling from Write" );
                err = deviceOp( DeviceFW::WRITE,
                                testTarget,
                                &data,
                                testEntry.size,
                                DEVICE_I2C_ADDRESS( testEntry.addr,
                                                    testEntry.port,
                                                    testEntry.engine,
                                                    testEntry.devAddr ) );

                TS_TRACE( "I2C - returned from Write" );
                if( err )
                {
                    break;
                }

                // Perform I2C read
                err = deviceOp( DeviceFW::READ,
                                testTarget,
                                &data,
                                testEntry.size,
                                DEVICE_I2C_ADDRESS( testEntry.addr,
                                                    testEntry.port,
                                                    testEntry.engine,
                                                    testEntry.devAddr ) );

                if( err )
                {
                    break;
                }

                // check the data read
                if( testEntry.data != data )
                {
                    TS_FAIL( "testI2C1 failed! - Data read does not match what was written!" );
                    TS_TRACE( "testI2C1 - Data Written: %016llx, Data Read: %016llx",
                              testEntry.data, data );

                }
            } while( 0 );

            if ( err )
            {
                TS_FAIL( "testI2C1 failed!  Error committed." );
                errlCommit( err );
            }
            else
            {
                TS_TRACE( "testI2C1 runs successfully!" );
            }

            return;
        }
};

#endif
