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

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <errl/errltypes.H>
#include <devicefw/driverif.H>
#include <i2c/i2creasoncodes.H>

extern trace_desc_t* g_trac_i2c;

using namespace TARGETING;

// Address and data to read/write
struct testI2CAddrData
{
    uint32_t addr;
    uint64_t data;
};

// Test table values
const testI2CAddrData g_i2cAddrTable[] =
{
        // Write data to be ORed with read value
        {0x13030007, 0x0000040000000000},
        {0x13010002, 0x00000C0000000000},
};

const uint32_t g_i2cmAddrTableSz =
                    sizeof(g_i2cAddrTable)/sizeof(testI2CAddrData);


class I2CTest: public CxxTest::TestSuite
{
public:

    /**
     * @brief I2C test #1
     *        Write value and read back to verify
     */
    void testI2C1(void)
    {
        errlHndl_t l_err = NULL;
        TS_TRACE( "I2C Test 1: its running!" );

        do
        {
            TARGETING::TargetService& targetService = TARGETING::targetService();
            TARGETING::Target* l_testTarget = NULL;
            targetService.masterProcChipTargetHandle( l_testTarget );

            if( NULL == l_testTarget )
            {
                TS_TRACE( "I2C Test - PROC test target is NULL!" );
                break;
            }

            size_t l_size = sizeof(uint64_t);
            testI2CAddrData l_testEntry = g_i2cAddrTable[0];

            // --------------------------------------------
            // NOTE: The following doesn't actually read
            // or write any data, it is strictly there to
            // prove that the interfaces are working.  The
            // real tests will be added at a later time.
            // --------------------------------------------

            // Perform I2C write
            uint64_t l_data = 0;

            l_err = deviceOp( DeviceFW::WRITE, 
                              l_testTarget,
                              &l_data,
                              l_size,
                              DEVICE_I2C_ADDRESS(l_testEntry.addr) );

            if( l_err )
            {
                break;
            }

            // Perform I2C read
            l_err = deviceOp( DeviceFW::READ,
                              l_testTarget,
                              &l_data,
                              l_size,
                              DEVICE_I2C_ADDRESS(l_testEntry.addr) );


        } while( 0 );

        if (l_err)
        {
            TS_FAIL("testI2C1 failed!  Error committed.");
                        errlCommit(l_err);
        }
        else
        {
            TS_TRACE("testI2C1 runs successfully!");
        }

        return;
    }
};

#endif
