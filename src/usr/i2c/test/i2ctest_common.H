/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/test/i2ctest_common.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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
#include <eeprom/eeprom_const.H>
#include <arch/magic.H>

extern trace_desc_t* g_trac_i2c;

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

using namespace TARGETING;


// Used to ignore comparing data on reads
#define I2C_TEST_COMMON_IGNORE_DATA_COMPARE 0x0ull

using I2C::HOST_ENGINE_D;
using I2C::HOST_ENGINE_E;

// define operator==() to gather all targets with ATTR_EEPROM_VPD_PRIMARY_INFO
namespace TARGETING{

    bool operator==(const ATTR_EEPROM_VPD_PRIMARY_INFO_type&, ATTR_EEPROM_VPD_PRIMARY_INFO_type) { return true; }

}

class I2CTestCommon: public CxxTest::TestSuite
{

    private:

        TargetHandleList g_targsWithEepromInfo;
        TargetService& tS = TARGETING::targetService();

    public:

        I2CTestCommon(){
            // Get top level system target
            TargetHandle_t sysTarget = TARGETING::UTIL::assertGetToplevelTarget();

            // get all targs that have EEPROM_VPD_PRIMARY_INFO attribute
            ATTR_EEPROM_VPD_PRIMARY_INFO_type any = {};
            PredicateAttrVal<TARGETING::ATTR_EEPROM_VPD_PRIMARY_INFO> l_hasEepromInfo(any);

            PredicateIsFunctional l_isFunc;
            PredicatePostfixExpr l_checkExprFuncWithEepromInfo;
            l_checkExprFuncWithEepromInfo.push(&l_hasEepromInfo)
                                         .push(&l_isFunc)
                                         .And();

            tS.getAssociated(g_targsWithEepromInfo,
                             sysTarget,
                             TargetService::CHILD, TargetService::ALL,
                             &l_checkExprFuncWithEepromInfo);
        }

        /**
         * @brief I2C Direct Test for ONE_BYTE_ADDR EEPROMS
         *      This test will test a variety of direct reads and writes
         *      with various lengths across slave devices with 1 byte addresses.
         *
         *      Currently only Processor targets are supported in simics.
         *
         */
        void testI2CDirect_ONE_BYTE_ADDR ( void )
        {
            errlHndl_t err = nullptr;
            int cmds = 0;
            int fails = 0;
            uint64_t original_data = 0;
            uint64_t data = 0;

            TRACFCOMP( g_trac_i2c, "testI2CDirect_ONE_BYTE_ADDR - Start");

            const uint64_t dataMask = 0x00FFFFFFFFFFFFFF;
            struct testData_t
            {
                ATTR_EEPROM_VPD_PRIMARY_INFO_type eeprom_info;

                uint64_t addrAndData;   // Data to write or compare to, which also includes
                                        // the addr to read/write to in the MSBs

                size_t writeSize;       // Number of Bytes to write

                uint64_t expectedData;  // Expected Data to see after preforming test read
                size_t readSize;        // Number of Bytes to read, must be less than 7
                                        // (can only write 7 bytes of data since we need 1 for
                                        // addressing)

                TargetHandle_t i2cMasterTarg; // ptr to i2c Master target
                TargetHandle_t testTarget;    // target ptr getting the Eeprom Info from.
                                              // used for debug info for test case fails
            };

            std::vector<testData_t> testData;

            // create a test for each eeprom i2c master
            for (auto l_targ : g_targsWithEepromInfo)
            {
                ATTR_EEPROM_VPD_PRIMARY_INFO_type eeprom_info =
                    l_targ->getAttr<ATTR_EEPROM_VPD_PRIMARY_INFO>();

                auto i2cMasterTarg = tS.toTarget(eeprom_info.i2cMasterPath);
                if (i2cMasterTarg->getAttr<ATTR_TYPE>() != TARGETING::TYPE_PROC)
                {
                    TRACFCOMP( g_trac_i2c,
                               "testI2CDirect_ONE_BYTE_ADDR: HUID 0x%08X has i2c master 0x%08X, "
                               "which is not of TYPE_PROC, skip running tests on this master",
                               get_huid(l_targ), get_huid(i2cMasterTarg));
                    continue;
                }
                else if (!i2cMasterTarg->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
                {
                    TRACFCOMP( g_trac_i2c,
                               "testI2CDirect_ONE_BYTE_ADDR - HUID 0x%08X has i2c master 0x%08X "
                               "which is not functional, skip running tests on this master",
                               get_huid(l_targ), get_huid(i2cMasterTarg));
                    continue;
                }

                if(eeprom_info.byteAddrOffset == EEPROM::ONE_BYTE_ADDR ||
                   eeprom_info.byteAddrOffset == EEPROM::ONE_BYTE_ADDR_PAGESELECT)
                {
                    testData.push_back({eeprom_info,
                                0x40C0FFEE00000000, // at addr 0x40 write 0xC0FFEE
                                4, // write 4 bytes
                                0xC0FFEE0000000000, // expect to see 0xC0FFEE at addr 0x40
                                3, // read only 3 bytes
                                i2cMasterTarg,
                                l_targ });

                    testData.push_back({eeprom_info,
                                0x82DEADBEEF000000, // at addr 0x82 write 0xDEADBEEF
                                5, // write 5 bytes
                                0xDEADBEEF00000000, // expect to see 0xDEADBEEF at addr 0x82
                                4, // read only 4 bytes
                                i2cMasterTarg,
                                l_targ });
                }
            }

            const uint32_t NUM_CMDS = testData.size();

            // Skipping I2C test altogether in VBU/VPO environment
            if( TARGETING::is_vpo() )
            {
                return;
            }

            do
            {
                for( uint32_t i = 0; i < NUM_CMDS; i++ )
                {
                    // Make sure size is less than or = to 8 bytes
                    // to fit into data
                    if (testData[i].writeSize > 8)
                    {
                        TRACFCOMP( g_trac_i2c,
                                   "testI2CDirect_ONE_BYTE_ADDR Size (%d) is greater than "
                                   "8 bytes. Skipping test %d",
                                   testData[i].writeSize, i );
                        continue;
                    }
                    if (testData[i].readSize > 7)
                    {
                        TRACFCOMP( g_trac_i2c,
                                   "testI2CDirect_ONE_BYTE_ADDR Size (%d) is greater than "
                                   "7 bytes. Skipping test %d",
                                   testData[i].readSize, i );
                        continue;
                    }

                    // For Each Set of Data, 6 operations:
                    // 0) Write Addr to Read from
                    // 1) Read Original Data and Save It
                    // 2) Write Test Data
                    //    - after write of data, re-write the addr
                    //      for the following read
                    // 3) Read Test Data and Compare
                    // 4) Write Back Original Data
                    //    - after write of data, re-write the addr
                    //      for the following read
                    // 5) Read Back Original Data and Compare

                    // Before starting, clear original data buffer
                    original_data = 0x0ull;
                    size_t dataSize = 0;

                    for (uint8_t j = 0; j <= 5; j++)
                    {
                        // Clear data variable
                        data = 0;
                        // For Loop 0: Write addr to read from on next loop
                        if ( j == 0 )
                        {
                            // only write the addr
                            data = testData[i].addrAndData & (~dataMask);
                            dataSize = 1;
                            TRACFCOMP( g_trac_i2c,
                                       "Writting eeprom addr: 0x%016llX",
                                       data);
                        }
                        // For Loop 1, 5: Read orig data in EEPROM
                        if ( j == 1 || j == 5)
                        {
                            data = 0; // data filled in on read
                            // read back 1 byte less since writes use 1 byte
                            // for adressing, not actually writing data to the
                            // EEPROM
                            dataSize = testData[i].writeSize - 1;
                            TRACFCOMP( g_trac_i2c,"Reading orig data from eeprom");
                        }

                        // For Loop 2: Write test data to EEPROM
                        if ( j == 2 )
                        {
                            // write both addr with test data
                            data = testData[i].addrAndData;
                            dataSize = testData[i].writeSize;
                            TRACFCOMP( g_trac_i2c,
                                       "Writting test data and addr: 0x%016llX",
                                       data);
                        }

                        // For Loop 3: Read back test data
                        if ( j == 3 )
                        {
                            data = 0; // data filled in on read
                            dataSize = testData[i].readSize;
                            TRACFCOMP( g_trac_i2c,"Reading back test data");
                        }

                        // For Loop 4: Write back orig data
                        if ( j == 4 )
                        {
                            // get just the addr and add in the orig data in the lower 7 bytes
                            data = (testData[i].addrAndData & (~dataMask)) + (original_data >> 8);
                            dataSize = testData[i].writeSize;
                            TRACFCOMP( g_trac_i2c,
                                       "Writting back orig data with addr: 0x%016llX",
                                       data);
                        }

                        // increment cmd op counter
                        cmds++;

                        err = deviceOp( (j%2) ? DeviceFW::READ : DeviceFW::WRITE,
                                    testData[i].i2cMasterTarg,
                                    &data,
                                    dataSize,
                                    DEVICE_I2C_ADDRESS( testData[i].eeprom_info.port,
                                                        testData[i].eeprom_info.engine,
                                                        testData[i].eeprom_info.devAddr,
                                                        testData[i].eeprom_info.i2cMuxBusSelector,
                                                        &(testData[i].eeprom_info.i2cMuxPath)));
                        if( err )
                        {
                            TS_FAIL( "testI2CDirect_ONE_BYTE_ADDR - OP %d FAILED "
                                     "- cmd %d out of %d",
                                     j, i + 1, NUM_CMDS );

                            TRACFCOMP( g_trac_i2c,
                                       "testI2CDirect_ONE_BYTE_ADDR - failing cmd: %s, "
                                       "data 0x%016llX, target HUID 0x%08X for i2cMaster 0x%08X, "
                                       "p/e/devAddr = 0x%X/0x%X/0x%X",
                                       (j%2) ? "READ" : "WRITE",
                                       testData[i].addrAndData,
                                       get_huid(testData[i].testTarget),
                                       get_huid(testData[i].i2cMasterTarg),
                                       testData[i].eeprom_info.port,
                                       testData[i].eeprom_info.engine,
                                       testData[i].eeprom_info.devAddr);

                            errlCommit( err, I2C_COMP_ID );
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

                            TRACFCOMP(g_trac_i2c,"testI2CDirect_ONE_BYTE_ADDR: "
                                      "original_data=0x%016llX", original_data);
                        }

                        // For Loops 2, 4: Re-Write the addr to read from
                        if ( j == 2 || j == 4)
                        {
                            // need to re-write the test addr to read back the test data

                            // only write the addr
                            data = testData[i].addrAndData & (~dataMask);
                            dataSize = 1;
                            TRACFCOMP( g_trac_i2c,
                                       "Writting eeprom addr: 0x%016llX",
                                       data);

                            // increment cmd op counter
                            cmds++;

                            err = deviceOp(DeviceFW::WRITE,
                                        testData[i].i2cMasterTarg,
                                        &data,
                                        dataSize,
                                        DEVICE_I2C_ADDRESS( testData[i].eeprom_info.port,
                                                            testData[i].eeprom_info.engine,
                                                            testData[i].eeprom_info.devAddr,
                                                            testData[i].eeprom_info.i2cMuxBusSelector,
                                                            &(testData[i].eeprom_info.i2cMuxPath)));

                            if( err )
                            {


                                TRACFCOMP( g_trac_i2c,
                                           "testI2CDirect_ONE_BYTE_ADDR - failing cmd: WRITE, "
                                           "data 0x%016llX, target HUID 0x%08X for i2cMaster 0x%08X, "
                                           "p/e/devAddr = 0x%X/0x%X/0x%X",
                                           testData[i].addrAndData,
                                           get_huid(testData[i].testTarget),
                                           get_huid(testData[i].i2cMasterTarg),
                                           testData[i].eeprom_info.port,
                                           testData[i].eeprom_info.engine,
                                           testData[i].eeprom_info.devAddr);

                                TS_FAIL( "testI2CDirect_ONE_BYTE_ADDR - OP %d FAILED "
                                         "- cmd %d out of %d, Re-Write test addr",
                                         j, i + 1, NUM_CMDS );
                                errlCommit( err, I2C_COMP_ID );
                                fails++;
                                continue;
                            }
                            nanosleep(0,5 * NS_PER_MSEC);   // 5 msec

                        }

                        // For Loop 3: compare new data
                        if ( j == 3 )
                        {
                            TRACUCOMP( g_trac_i2c,
                                       "testI2CDirect_ONE_BYTE_ADDR: New Data Compare: "
                                       "written=0x%016llX, read_back=0x%016llX",
                                       testData[i].expectedData, data);

                            if( data != testData[i].expectedData )
                            {

                                TRACFCOMP(g_trac_i2c,
                                          "testI2CDirect_ONE_BYTE_ADDR: New Data Compare Fail: "
                                          "wrote=0x%016llx, read back=0x%016llX. cmd: %d/%d (%d)",
                                          testData[i].expectedData, data, i + 1, NUM_CMDS, j);

                                TRACFCOMP( g_trac_i2c,
                                           "testI2CDirect_ONE_BYTE_ADDR - failing cmd: %s, data "
                                           "0x%016llX, target HUID 0x%08X for i2cMaster 0x%08X, "
                                           "p/e/devAddr = 0x%X/0x%X/0x%X",
                                           (j%2) ? "READ" : "WRITE",
                                           testData[i].addrAndData,
                                           get_huid(testData[i].testTarget),
                                           get_huid(testData[i].i2cMasterTarg),
                                           testData[i].eeprom_info.port,
                                           testData[i].eeprom_info.engine,
                                           testData[i].eeprom_info.devAddr);
                                TS_FAIL( "testI2CDirect_ONE_BYTE_ADDR - Failure comparing new data!" );
                                fails++;

                                // Don't break - try to write back original data
                                continue;
                            }

                        }

                        // For Loop 5: compare writing-back original data
                        if ( j == 5 )
                        {
                            TRACUCOMP( g_trac_i2c,
                                       "testI2CDirect_ONE_BYTE_ADDR: Original Data Compare: "
                                       "original=0x%016llX, read_back=0x%016llX",
                                       original_data, data);

                            if( data != original_data )
                            {
                                TRACFCOMP(g_trac_i2c,
                                          "testI2CDirect_ONE_BYTE_ADDR: Original Data Compare Fail: "
                                          "original=0x%016llX, read back=0x%016llX. cmd: %d/%d (%d)",
                                          original_data, data, i + 1, NUM_CMDS, j);
                                TS_FAIL( "testI2CDirect_ONE_BYTE_ADDR - Failure comparing original data!");

                                TRACFCOMP( g_trac_i2c,
                                           "testI2CDirect_ONE_BYTE_ADDR - failing cmd: %s, data "
                                           "0x%016llX, target HUID 0x%08X for i2cMaster 0x%08X, "
                                           "p/e/devAddr = 0x%X/0x%X/0x%X",
                                           (j%2) ? "READ" : "WRITE",
                                           testData[i].addrAndData,
                                           get_huid(testData[i].testTarget),
                                           get_huid(testData[i].i2cMasterTarg),
                                           testData[i].eeprom_info.port,
                                           testData[i].eeprom_info.engine,
                                           testData[i].eeprom_info.devAddr);

                                fails++;

                                // Break: stop testing if we can't write back
                                // original data successfully
                                break;
                            }
                        }

                    }  // end of 'j' loop

                }
            } while( 0 );

            TRACFCOMP( g_trac_i2c,
                       "testI2CDirect_ONE_BYTE_ADDR - End: %d/%d fails",
                       fails, cmds );
        }

        /**
         * @brief I2C Direct Test for TWO_BYTE_ADDR EEPROMS
         *      This test will test a variety of direct reads and writes
         *      with various lengths across slave devices with 2 byte addresses.
         *
         *      Currently only Processor targets are supported in simics.
         *
         */
        void testI2CDirect_TWO_BYTE_ADDR ( void )
        {
            errlHndl_t err = nullptr;
            int cmds = 0;
            int fails = 0;
            uint64_t data = 0;

            TRACFCOMP( g_trac_i2c, "testI2CDirect_TWO_BYTE_ADDR - Start" );

            struct testData_t
            {
                ATTR_EEPROM_VPD_PRIMARY_INFO_type eeprom_info;

                uint64_t data;      // Data to write or compare to, which also includes
                                    // the addr to read/write to in the MSBs
                                    // if data = I2C_TEST_COMMON_IGNORE_DATA_COMPARE
                                    // than ignore data compare
                size_t   size;      // Number of Bytes to read/write
                DeviceFW::OperationType rnw;  // READ/WRITE
                TargetHandle_t i2cMasterTarg; // ptr to i2c Master target
                TargetHandle_t testTarget;    // target ptr getting the Eeprom Info from.
                                              // used for debug info for test case fails
            };

            std::vector<testData_t> testData;

            for (auto l_targ : g_targsWithEepromInfo)
            {
                ATTR_EEPROM_VPD_PRIMARY_INFO_type eeprom_info =
                    l_targ->getAttr<ATTR_EEPROM_VPD_PRIMARY_INFO>();

                auto i2cMasterTarg = tS.toTarget(eeprom_info.i2cMasterPath);
                if (i2cMasterTarg->getAttr<ATTR_TYPE>() != TARGETING::TYPE_PROC)
                {

                    TRACFCOMP( g_trac_i2c,
                               "testI2CDirect_TWO_BYTE_ADDR: HUID 0x%08X has i2c master 0x%08X, "
                               "which is not of TYPE_PROC, skip running tests on this master",
                               get_huid(l_targ), get_huid(i2cMasterTarg));
                    continue;
                }
                else if (!i2cMasterTarg->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
                {
                    TRACFCOMP( g_trac_i2c,
                               "testI2CDirect_TWO_BYTE_ADDR - HUID 0x%08X has i2c master 0x%08X "
                               "which is not functional, skip running tests on this master",
                               get_huid(l_targ), get_huid(i2cMasterTarg));
                    continue;
                }

                if (eeprom_info.byteAddrOffset == EEPROM::TWO_BYTE_ADDR)
                {
                    // read only tests
                    testData.push_back({eeprom_info,
                                        I2C_TEST_COMMON_IGNORE_DATA_COMPARE,
                                        8,
                                        DeviceFW::READ,
                                        i2cMasterTarg,
                                        l_targ });

                    //write->read->verify tests

                    // write data to an addr and read it back
                    // write 0xababcdcdefef to addr 0x0810
                    testData.push_back({eeprom_info,
                                        0x0810ababcdcdefef,
                                        8,
                                        DeviceFW::WRITE,
                                        i2cMasterTarg,
                                        l_targ });
                    // write which addr to read from (0x0810)
                    testData.push_back({eeprom_info,
                                        0x0810000000000000,
                                        2,
                                        DeviceFW::WRITE,
                                        i2cMasterTarg,
                                        l_targ });
                    // read from 0x0810
                    testData.push_back({eeprom_info,
                                        0xababcdcdefef0000,
                                        6,
                                        DeviceFW::READ,
                                        i2cMasterTarg,
                                        l_targ });

                    // move addr 3 bytes forward from before and read data again
                    // write which addr to read from (0x0813)
                    testData.push_back({eeprom_info,
                                        0x0813000000000000,
                                        2,
                                        DeviceFW::WRITE,
                                        i2cMasterTarg,
                                        l_targ });
                    // read from 0x0813
                    testData.push_back({eeprom_info,
                                        0xcdefef0000000000,
                                        3,
                                        DeviceFW::READ,
                                        i2cMasterTarg,
                                        l_targ });

                    // write data to an addr, and read the data back starting
                    // 1 byte before the data written.
                    // write 0x831200000000 to addr 0x0825
                    testData.push_back({eeprom_info,
                                        0x0825831200000000,
                                        8,
                                        DeviceFW::WRITE,
                                        i2cMasterTarg,
                                        l_targ });
                    // write which addr to read from (0x0x0824)
                    testData.push_back({eeprom_info,
                                        0x0824000000000000,
                                        2,
                                        DeviceFW::WRITE,
                                        i2cMasterTarg,
                                        l_targ });
                    // read from 0x0810
                    testData.push_back({eeprom_info,
                                        0x0083120000000000,
                                        3,
                                        DeviceFW::READ,
                                        i2cMasterTarg,
                                        l_targ });
                }
            } //for each l_targsWithEepromInfo

            const uint32_t NUM_CMDS = testData.size();

            // Skipping I2C test altogether in VBU/VPO environment
            if( TARGETING::is_vpo() )
            {
                return;
            }

            do
            {
                for( uint32_t i = 0; i < NUM_CMDS; i++ )
                {
                    // Make sure size is less than or = to 8 bytes
                    // to fit into data
                    if (testData[i].size > 8)
                    {
                        TRACFCOMP( g_trac_i2c,
                                   "testI2CDirect_TWO_BYTE_ADDR Size (%d) is greater than "
                                   "8 bytes. Skipping test %d",
                                   testData[i].size, i );
                        continue;
                    }

                    // do the operation
                    data = testData[i].data;
                    cmds++;
                    err = deviceOp( testData[i].rnw,
                                    testData[i].i2cMasterTarg,
                                    &data,
                                    testData[i].size,
                                    DEVICE_I2C_ADDRESS( testData[i].eeprom_info.port,
                                                        testData[i].eeprom_info.engine,
                                                        testData[i].eeprom_info.devAddr,
                                                        testData[i].eeprom_info.i2cMuxBusSelector,
                                                        &(testData[i].eeprom_info.i2cMuxPath)));

                    if( err )
                    {
                        TRACFCOMP( g_trac_i2c,
                                   "testI2CDirect_TWO_BYTE_ADDR - failing cmd: %s, data "
                                   "0x%016llX, target HUID 0x%08X for i2cMaster 0x%08X, "
                                   "p/e/devAddr = 0x%X/0x%X/0x%X",
                                   testData[i].rnw == DeviceFW::READ ? "READ" : "WRITE",
                                   testData[i].data,
                                   get_huid(testData[i].testTarget),
                                   get_huid(testData[i].i2cMasterTarg),
                                   testData[i].eeprom_info.port,
                                   testData[i].eeprom_info.engine,
                                   testData[i].eeprom_info.devAddr );

                        TS_FAIL( "testI2CDirect_TWO_BYTE_ADDR - fail on cmd %d out of %d",
                                 i + 1, NUM_CMDS );
                        errlCommit( err, I2C_COMP_ID );
                        fails++;
                        continue;
                    }

                    // If a write op, wait 5ms for EEPROM to write data
                    // to its internal memory
                    if (testData[i].rnw == DeviceFW::WRITE)
                    {
                        nanosleep(0,5 * NS_PER_MSEC);   // 5 msec
                    }

                    // compare data for the read, but ignore case where
                    // data = I2C_TEST_COMMON_IGNORE_DATA_COMPARE
                    if( ( testData[i].rnw == DeviceFW::READ) &&
                        ( testData[i].data != I2C_TEST_COMMON_IGNORE_DATA_COMPARE ))
                    {
                        if( data != testData[i].data )
                        {

                            TRACFCOMP( g_trac_i2c,
                                       "testI2CDirect_TWO_BYTE_ADDR - cmd: %d/%d, Data read: "
                                       "0x%016llX, expected: 0x%016llX",
                                       i + 1, NUM_CMDS, data, testData[i].data );
                            TRACFCOMP( g_trac_i2c,
                                       "testI2CDirect_TWO_BYTE_ADDR - failing cmd: %s, data "
                                       "0x%016llX, target HUID 0x%08X for i2cMaster 0x%08X, "
                                       "p/e/devAddr = 0x%X/0x%X/0x%X",
                                       testData[i].rnw == DeviceFW::READ ? "READ" : "WRITE",
                                       testData[i].data,
                                       get_huid(testData[i].testTarget),
                                       get_huid(testData[i].i2cMasterTarg),
                                       testData[i].eeprom_info.port,
                                       testData[i].eeprom_info.engine,
                                       testData[i].eeprom_info.devAddr );
                            TS_FAIL("testI2CDirect_TWO_BYTE_ADDR - Failure comparing read data!");
                            fails++;
                            continue;
                        }
                    }
                }
            } while( 0 );

            TRACFCOMP( g_trac_i2c,
                       "testI2CDirect_TWO_BYTE_ADDR - End: %d/%d fails",
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
            errlHndl_t err = nullptr;
            int cmds = 0;
            int fails = 0;
            uint64_t original_data = 0;
            uint64_t data = 0;

            TRACFCOMP( g_trac_i2c, "testI2COffset - Start" );

            struct testData_t
            {
                ATTR_EEPROM_VPD_PRIMARY_INFO_type eeprom_info;

                uint64_t data;      // Data to write or compare to
                                    // if data = I2C_TEST_COMMON_IGNORE_DATA_COMPARE
                                    // than ignore data compare

                size_t   size;      // Number of Bytes to read/write
                uint16_t offset;    // Slave Device offset. Set MSB for 1 byte addressing targets
                size_t offsetSize;  // size in bytes for the offset above.
                                    // Used for 1 vs 2 byte addressing
                TargetHandle_t i2cMasterTarg; // ptr to i2c Master target
                TargetHandle_t testTarget;    // target ptr getting the Eeprom Info from.
                                              // used for debug info for test case fails
            };

            std::vector<testData_t> testData;

            // create a test for reading each i2c master and port of the targets
            for (auto l_targ : g_targsWithEepromInfo)
            {
                ATTR_EEPROM_VPD_PRIMARY_INFO_type eeprom_info =
                    l_targ->getAttr<ATTR_EEPROM_VPD_PRIMARY_INFO>();

                auto i2cMasterTarg = tS.toTarget(eeprom_info.i2cMasterPath);
                if (i2cMasterTarg->getAttr<ATTR_TYPE>() != TARGETING::TYPE_PROC)
                {

                    TRACFCOMP( g_trac_i2c,
                               "testI2COffset: HUID 0x%08X has i2c master 0x%08X "
                               "which is not of TYPE_PROC, skip running tests on this master",
                               get_huid(l_targ), get_huid(i2cMasterTarg));
                    continue;
                }
                else if (!i2cMasterTarg->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
                {
                    TRACFCOMP( g_trac_i2c,
                               "testI2COffset - HUID 0x%08X has i2c master 0x%08X "
                               "which is not functional, skip running tests on this master",
                               get_huid(l_targ), get_huid(i2cMasterTarg));
                    continue;
                }


                if(eeprom_info.byteAddrOffset == EEPROM::TWO_BYTE_ADDR )
                {
                    testData.push_back({eeprom_info,
                                        0xFEFEDADA57579191,
                                        8,
                                        0x0820,
                                        2,
                                        i2cMasterTarg,
                                        l_targ });

                    testData.push_back({eeprom_info,
                                        0x5ABC310000000000,
                                        3,
                                        0x0820,
                                        2,
                                        i2cMasterTarg,
                                        l_targ });
                }
                else if(eeprom_info.byteAddrOffset == EEPROM::ONE_BYTE_ADDR ||
                        eeprom_info.byteAddrOffset == EEPROM::ONE_BYTE_ADDR_PAGESELECT)
                {
                    testData.push_back({eeprom_info,
                                        0xFEFEDADA57579191,
                                        8,
                                        0x8200,
                                        1,
                                        i2cMasterTarg,
                                        l_targ });

                    testData.push_back({eeprom_info,
                                        0x5ABC310000000000,
                                        3,
                                        0x8200,
                                        1,
                                        i2cMasterTarg,
                                        l_targ });
                }
            }

            const uint32_t NUM_CMDS = testData.size();


            // Skipping I2C test altogether in VBU/VPO environment
            if( TARGETING::is_vpo() )
            {
                return;
            }

            do
            {
                for ( uint32_t i = 0; i < NUM_CMDS; i++ )
                {
                    TRACUCOMP( g_trac_i2c,"testI2COffset: Outer Loop i= "
                               "%d, NUM_CMDS = %d", i, NUM_CMDS);

                    // Make sure size is less than or = to 8 bytes
                    //  to fit into data
                    if (testData[i].size > 8)
                    {
                        TRACFCOMP( g_trac_i2c,
                                   "testI2COffset: Size (%d) is greater than "
                                   "8 bytes. Skipping test %d",
                                   testData[i].size, i + 1 );
                        continue;
                    }

                    TRACUCOMP( g_trac_i2c,
                               "testI2COffset - Preforming test: data 0x%016llX, "
                               "target HUID 0x%08X for i2cMaster 0x%08X, p/e/devAddr "
                               "= 0x%X/0x%X/0x%X, offset 0x%016llX",
                               testData[i].data,
                               get_huid(testData[i].testTarget),
                               get_huid(testData[i].i2cMasterTarg),
                               testData[i].eeprom_info.port,
                               testData[i].eeprom_info.engine,
                               testData[i].eeprom_info.devAddr,
                               testData[i].offset );

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
                                testData[i].i2cMasterTarg,
                                &data,
                                testData[i].size,
                                DEVICE_I2C_ADDRESS_OFFSET(
                                                    testData[i].eeprom_info.port,
                                                    testData[i].eeprom_info.engine,
                                                    testData[i].eeprom_info.devAddr,
                                                    testData[i].offsetSize,
                                                    reinterpret_cast<uint8_t*>(
                                                        &(testData[i].offset)),
                                                    testData[i].eeprom_info.i2cMuxBusSelector,
                                                    &(testData[i].eeprom_info.i2cMuxPath)));

                        if( err )
                        {
                            TS_FAIL( "testI2COffset - OP %d FAILED "
                                     "- cmd %d out of %d",
                                     j, i + 1, NUM_CMDS );

                            TRACFCOMP( g_trac_i2c,
                                       "testI2COffset - failing cmd: %s, data 0x%016llX, "
                                       "target HUID 0x%08X for i2cMaster 0x%08X, p/e/devAddr "
                                       "= 0x%X/0x%X/0x%X, offset 0x%016llX",
                                       (j%2) ? "READ" : "WRITE",
                                       testData[i].data,
                                       get_huid(testData[i].testTarget),
                                       get_huid(testData[i].i2cMasterTarg),
                                       testData[i].eeprom_info.port,
                                       testData[i].eeprom_info.engine,
                                       testData[i].eeprom_info.devAddr,
                                       testData[i].offset );

                            errlCommit( err, I2C_COMP_ID );
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

                            TRACFCOMP(g_trac_i2c,"testI2COffset: "
                                      "original_data=0x%016llX", original_data);
                        }

                        // For Loop 3: compare new data
                        if ( j == 3 )
                        {
                            TRACUCOMP( g_trac_i2c,
                                       "testI2COffset: New Data Compare: "
                                       "written=0x%016llX, read_back=0x%016llX",
                                       testData[i].data, data);

                            if( data != testData[i].data )
                            {
                                TRACFCOMP(g_trac_i2c,
                                          "testI2COffset: New Data Compare Fail: wrote=%016llX, "
                                          "read back=%016llX. cmd: %d/%d (%d)",
                                          testData[i].data, data, i + 1, NUM_CMDS, j);

                                TRACFCOMP( g_trac_i2c,
                                           "testI2COffset - failing cmd: %s, data 0x%016llX, "
                                           "target HUID 0x%08X for i2cMaster 0x%08X, p/e/devAddr "
                                           "= 0x%X/0x%X/0x%X, offset 0x%016llX",
                                           (j%2) ? "READ" : "WRITE",
                                           testData[i].data,
                                           get_huid(testData[i].testTarget),
                                           get_huid(testData[i].i2cMasterTarg),
                                           testData[i].eeprom_info.port,
                                           testData[i].eeprom_info.engine,
                                           testData[i].eeprom_info.devAddr,
                                           testData[i].offset );

                                TS_FAIL("testI2COffset - Failure comparing new data!");
                                fails++;

                                // Don't break - try to write back original data
                                continue;
                            }

                        }

                        // For Loop 5: compare writing-back original data
                        if ( j == 5 )
                        {
                            TRACFCOMP( g_trac_i2c,
                                       "testI2COffset: Original Data Compare: "
                                       "original=0x%016llX, read_back=0x%016llX",
                                       original_data, data);

                            if( data != original_data )
                            {
                                TRACFCOMP(g_trac_i2c,
                                          "testI2COffset: New " "Data Compare Fail: "
                                          "original=0x%016llX, read back=0x%016llX. "
                                          "cmd: %d/%d (%d)",
                                          original_data, data, i + 1, NUM_CMDS, j);

                                TRACFCOMP( g_trac_i2c,
                                           "testI2COffset - failing cmd: %s, data 0x%016llX, "
                                           "target HUID 0x%08X for i2cMaster 0x%08X, p/e/devAddr "
                                           "= 0x%X/0x%X/0x%X, offset 0x%016llX",
                                           (j%2) ? "READ" : "WRITE",
                                           testData[i].data,
                                           get_huid(testData[i].testTarget),
                                           get_huid(testData[i].i2cMasterTarg),
                                           testData[i].eeprom_info.port,
                                           testData[i].eeprom_info.engine,
                                           testData[i].eeprom_info.devAddr,
                                           testData[i].offset );

                                TS_FAIL("testI2COffset - Failure comparing original data!");
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
            errlHndl_t err = nullptr;
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
                err = nullptr;
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
            errlHndl_t err = nullptr;
            int64_t fails = 0, num_ops = 0;
            uint64_t data = 0x0ull;
            size_t dataSize = 8;

            TRACFCOMP( g_trac_i2c,
                       "testI2CInvalidOperation - Start" );

            do
            {
                // Get a processor Target
                TARGETING::TargetService& tS = TARGETING::targetService();
                TARGETING::Target* testTarget = nullptr;
                tS.masterProcChipTargetHandle( testTarget );
                assert(testTarget != nullptr);


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

                if( nullptr == err )
                {
                    fails++;
                    TS_FAIL( "testI2CInvalidOperation - Error should've "
                             "resulted in Operation type of LAST_OP_TYPE!" );
                }
                else
                {
                    delete err;
                    err = nullptr;
                }
            } while( 0 );
            TRACFCOMP( g_trac_i2c,
                       "testI2CInvalidOperation - End: %d/%d fails",
                       fails, num_ops );
        }


};

#endif
