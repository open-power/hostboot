/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/test/i2ctest.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2022                        */
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
 *  @brief Test cases for I2C code running during IPL
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

#include <arch/magic.H>

extern trace_desc_t* g_trac_i2c;

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

using namespace TARGETING;


// Used to ignore comparing data on reads
#define I2C_TEST_IGNORE_DATA_COMPARE 0xFFFFFFFFFFFFFFFF

using I2C::HOST_ENGINE_D;
using I2C::HOST_ENGINE_E;

class I2CTestIPL : public CxxTest::TestSuite
{
    public:

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

        void testI2cForceReset(void)
        {
            TRACFCOMP(g_trac_i2c, ENTER_MRK"testI2cForceReset enter");

            errlHndl_t err = nullptr;

            do
            {
                //TODO: RTC 297301
                if (MAGIC_IS_BONITO())
                {
                    TRACFCOMP( g_trac_i2c, "Skipping testI2cForceReset for Bonito, "
                               "device reads returns 0. Requires more investigation");
                    break;
                }
                I2C::misc_args_t io_args;

                uint64_t data = 0x0;

                // Get the Proc Target
                TARGETING::TargetService& tS = TARGETING::targetService();
                TARGETING::Target* procTarget = nullptr;
                tS.masterProcChipTargetHandle( procTarget );
                assert( procTarget != nullptr );

                // reset the target and then try a read
                if(procTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
                {
                    TRACFCOMP( g_trac_i2c, "testI2cForceReset- functional good path");
                    // p/e/devvAddr 1/e/0xA0 routes to Dimm for P10 standalone and Bonito
                    io_args.port = 0x1;
                    io_args.engine = HOST_ENGINE_E;
                    io_args.devAddr = 0xA0;
                    io_args.switches.useHostI2C = 1;
                    //get engine lock attr for engine 0
                    //prevents sbe update test fails

                    size_t data_size = 8;

                    uint8_t offset = 0;
                    err = deviceOp( DeviceFW::READ,
                                    procTarget,
                                    &data,
                                    data_size,
                                    DEVICE_I2C_ADDRESS_OFFSET( io_args.port,
                                                               io_args.engine,
                                                               io_args.devAddr,
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

                    TRACFCOMP( g_trac_i2c, "testI2cForceReset: data after first read is 0x%016llX", data );

                    mutex_t * engineLock = nullptr;
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
                                    DEVICE_I2C_ADDRESS( io_args.port,
                                                        io_args.engine,
                                                        io_args.devAddr,
                                                        I2C_MUX::NOT_APPLICABLE,
                                                        nullptr) );
                }

                if(err)
                {
                    TS_FAIL("testI2cForceReset failed err detected");
                    errlCommit( err,I2C_COMP_ID );
                    break;
                }

                TRACFCOMP( g_trac_i2c, "testI2cForceReset: data after second read is 0x%016llX", data );

                if(data == 0)
                {
                    //there should be some data
                    TS_FAIL("testI2cForceReset failed data read is 0");
                    break;
                }

            }while(0);

            TRACFCOMP(g_trac_i2c, EXIT_MRK"testI2cForceReset exit");
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

            std::list<I2C::DeviceInfo_t> l_deviceInfo;

            // Loop through every chip
            TARGETING::TargetHandleList allchips;
            TARGETING::getAllChips( allchips, TARGETING::TYPE_NA );
            for( auto &tgt : allchips )
            {
                getDeviceInfo( tgt, l_deviceInfo);
            }

            decltype(l_deviceInfo)::const_iterator devInfo_iter;
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
