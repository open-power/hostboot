/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sio/test/sioddtest.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
#ifndef __SIODDTEST_H
#define __SIODDTEST_H

/**
 *  @file sioddtest.H
 *
 *  @brief Test case for SuperIO Driver
*/
#include <devicefw/driverif.H>
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/userif.H>
#include <sys/time.h>
#include <list>
#include <targeting/common/attributes.H>
#include <sio/sio.H>
#include "../siodd.H"

const uint8_t CTLREG_04 = 0x04;
const uint32_t SPIC_BASE_ADDR_AHB = 0x1E630000;
class SioDDTest : public CxxTest::TestSuite
{
  public:
    /**
     * @brief Test SIO access
     *        Use a SIO scratch register to verify reads and writes
     */
    void test_SIO(void)
    {
        errlHndl_t l_err = NULL;
        size_t l_len = sizeof(uint8_t);
        mutex_t l_lock = Singleton<SioDD>::instance().iv_sio_mutex;
        mutex_lock(&l_lock);
        // Read SIO to BMC scratch reg 1,2 and save off values
        uint8_t scratch1 = 0;
        l_err = deviceOp( DeviceFW::READ,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(scratch1),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::SUART1, SIO::SIO_SCRATCH_REG1));
        if( l_err )
        {
            TS_FAIL("SioDDTest::test_SIO> read from SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }
        uint8_t scratch2 = 0;
        l_err = deviceOp( DeviceFW::READ,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(scratch2),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::SUART1, SIO::SIO_SCRATCH_REG2));
        if( l_err )
        {
            TS_FAIL("SioDDTest::test_SIO> read from SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }

        // Write test patterns into registers
        uint8_t testdata = 0xA5;
        l_err = deviceOp( DeviceFW::WRITE,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(testdata),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::SUART1, SIO::SIO_SCRATCH_REG1));
        if( l_err )
        {
            TS_FAIL("SioDDTest::test_SIO> write to SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }
        testdata = 0x12;
        l_err = deviceOp( DeviceFW::WRITE,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(testdata),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::SUART1, SIO::SIO_SCRATCH_REG2));
        if( l_err )
        {
            TS_FAIL("SioDDTest::test_SIO> write to SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }

        // Read the data back and compare to expected results
        l_err = deviceOp( DeviceFW::READ,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(testdata),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::SUART1, SIO::SIO_SCRATCH_REG1));
        if( l_err )
        {
            TS_FAIL("SioDDTest::test_SIO> read from SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }
        if( testdata != 0xA5 )
        {
            TS_FAIL("SioDDTest::test_SIO> Data mismatch on SIO 0x21\
                    : Exp=0xA5, Act=%.2X", testdata);
        }
        l_err = deviceOp( DeviceFW::READ,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(testdata),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::SUART1, SIO::SIO_SCRATCH_REG2));
        if( l_err )
        {
            TS_FAIL("SioDDTest::test_SIO> read from SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }
        if( testdata != 0x12 )
        {
            TS_FAIL("SioDDTest::test_SIO> Data mismatch on SIO 0x22 :/\
                    Exp=0x12, Act=%.2X", testdata);
        }

        // Restore the original data
        l_err = deviceOp( DeviceFW::WRITE,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(scratch1),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::SUART1, SIO::SIO_SCRATCH_REG1));
        if( l_err )
        {
            TS_FAIL("SioDDTest::test_SIO> write to SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }
        l_err = deviceOp( DeviceFW::WRITE,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(scratch2),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::SUART1, SIO::SIO_SCRATCH_REG2));
        if( l_err )
        {
            TS_FAIL("SioDDTest::test_SIO> write to SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }
        mutex_unlock(&l_lock);
    }

    /**
     * @brief Concurrency test for SIO registers using devices Key Board
     * Controller and MailBox
     */
    void test_concurrency()
    {
        mutex_t l_lock = Singleton<SioDD>::instance().iv_sio_mutex;
        mutex_lock(&l_lock);
        errlHndl_t l_err = NULL;
        uint8_t l_data;
        size_t l_len = sizeof(l_data);
        //Enable additional SIO test devices 5 and E
        l_data = SIO::ENABLE_DEVICE;
        l_err = deviceOp( DeviceFW::WRITE,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(l_data),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::KBC, 0x30));
        if( l_err )
        {
            TS_FAIL("SioDDTest::SIO_concurrency> write to SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }

        l_err = deviceOp( DeviceFW::WRITE,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(l_data),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::MB, 0x30));
        if( l_err )
        {
            TS_FAIL("SioDDTest::SIO_concurrency> write to SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }

        //Read current values from devices
        //KBC
        uint8_t kbc_base_add_msb = 0;
        l_err = deviceOp( DeviceFW::READ,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(kbc_base_add_msb),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::KBC, 0x60));
        if( l_err )
        {
            TS_FAIL("SioDDTest::SIO_concurrency> read from SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }

        //MB
        uint8_t mb_base_add_msb = 0;
        l_err = deviceOp( DeviceFW::READ,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(mb_base_add_msb),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::MB, 0x60));
        if( l_err )
        {
            TS_FAIL("SioDDTest::SIO_concurrency> read from SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }

        //Write new values to registers 0x60
        //KBC
        uint8_t testdata1 = 0xAA;
        l_err = deviceOp( DeviceFW::WRITE,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(testdata1),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::KBC, 0x60));
        if( l_err )
        {
            TS_FAIL("SioDDTest::SIO_concurrency> write to SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }

        //MB
        uint8_t testdata2 = 0x05;
        l_err = deviceOp( DeviceFW::WRITE,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(testdata2),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::MB, 0x60));
        if( l_err )
        {
            TS_FAIL("SioDDTest::SIO_concurrency> write to SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }

        //Read and compare
        uint8_t testdata;
        l_err = deviceOp( DeviceFW::READ,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(testdata),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::KBC, 0x60));
        if( l_err )
        {
            TS_FAIL("SioDDTest::SIO_concurrency> read from SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }
        if( testdata != 0xAA )
        {
            TS_FAIL("SioDDTest::SIO_concurreny> Data mismatch on SIO device KBC\
                    reg 0x60 : Exp=0xAA, Act=%.2X", testdata);
        }

        l_err = deviceOp( DeviceFW::READ,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(testdata),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::MB, 0x60));
        if( l_err )
        {
            TS_FAIL("SioDDTest::SIO_concurrency> read from SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }
        if( testdata != 0x05 )
        {
            TS_FAIL("SioDDTest::SIO_concurreny> Data mismatch on SIO device MB\
                    reg 0x60 : Exp=0x05, Act=%.2X", testdata);
        }

        //Write original data back
        l_err = deviceOp( DeviceFW::WRITE,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(kbc_base_add_msb),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::KBC, 0x60));
        if( l_err )
        {
            TS_FAIL("SioDDTest::SIO_concurrency> write to SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }

        //MB
        l_err = deviceOp( DeviceFW::WRITE,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(mb_base_add_msb),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::MB, 0x60));
        if( l_err )
        {
            TS_FAIL("SioDDTest::SIO_concurrency> write to SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }
        mutex_unlock(&l_lock);
    }

    /** @brief test simultaneous accesses to same logical device
     */
    void test_same_dev()
    {
        uint8_t l_data;
        errlHndl_t l_err = NULL;
        size_t l_len = sizeof(l_data);
        mutex_t l_lock = Singleton<SioDD>::instance().iv_sio_mutex;
        mutex_lock(&l_lock);

        //enable device Key Board Controller
        l_data = SIO::ENABLE_DEVICE;
        l_err = deviceOp( DeviceFW::WRITE,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(l_data),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::KBC, 0x30));
        if( l_err )
        {
            TS_FAIL("SioDDTest::test_same_dev> write to SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }
        //Read value at key board controller, reg 0x60
        uint8_t current_data = 0;
        l_err = deviceOp( DeviceFW::READ,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(current_data),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::KBC, 0x60));
        if( l_err )
        {
            TS_FAIL("SioDDTest::test_same_dev> read from SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }
        //Write new test value to key board controller, reg 0x60
        uint8_t test_data = 0x10;
        l_err = deviceOp( DeviceFW::WRITE,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(test_data),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::KBC, 0x60));
        if( l_err )
        {
            TS_FAIL("SioDDTest::test_same_dev> write to SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }
        //Read and compare
        l_err = deviceOp( DeviceFW::READ,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(test_data),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::KBC, 0x60));
        if( l_err )
        {
            TS_FAIL("SioDDTest::test_same_dev> read from SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }
        if(test_data != 0x10)
        {
            TS_FAIL("SioDDTest::test_same_dev> Data mismatch on SIO KBC, 0x60\
                    : Exp=0x10, Act=%.2X", test_data);
        }
        //Write back original data
        l_err = deviceOp( DeviceFW::WRITE,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(current_data),
                          l_len,
                          DEVICE_SIO_ADDRESS(SIO::KBC, 0x60));
        if( l_err )
        {
            TS_FAIL("SioDDTest::test_same_dev> write to SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }
        mutex_unlock(&l_lock);
    }

    /**
     * @brief AHB_SIO access
     *      Read and write data to the SPI Control register
     */
    void test_AHB_SIO( void )
    {
        errlHndl_t l_err = NULL;
        uint32_t l_lpc_addr;
        size_t l_len = sizeof(uint32_t);
        mutex_t l_lock = Singleton<SioDD>::instance().iv_sio_mutex;
        mutex_lock(&l_lock);

        uint32_t first = 0;
        l_lpc_addr = CTLREG_04 | SPIC_BASE_ADDR_AHB;
        l_err = deviceOp( DeviceFW::READ,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(first),
                          l_len,
                          DEVICE_AHB_SIO_ADDRESS(l_lpc_addr));
        if( l_err )
        {
            TS_FAIL("SioDDTest::test_AHB_SIO> read from AHB_SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }
        uint32_t data1 = 0x12345678;
        l_err = deviceOp( DeviceFW::WRITE,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(data1),
                          l_len,
                          DEVICE_AHB_SIO_ADDRESS(l_lpc_addr));
        if( l_err )
        {
            TS_FAIL("SioDDTest::test_AHB_SIO> write to AHB_SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }
        l_err = deviceOp( DeviceFW::READ,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(data1),
                          l_len,
                          DEVICE_AHB_SIO_ADDRESS(l_lpc_addr));
        if( l_err )
        {
            TS_FAIL("SioDDTest::test_AHB_SIO> read from AHB_SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }
        if( data1 != 0x12345678 )
        {
            TS_FAIL("SioDDTest::test_SPIC> Unexpected result of %.8X\
                    (exp 0x12345678)",data1);
        }
        //put back the original
        l_err = deviceOp( DeviceFW::WRITE,
                          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                          &(first),
                          l_len,
                          DEVICE_AHB_SIO_ADDRESS(l_lpc_addr));
        if( l_err )
        {
            TS_FAIL("SioDDTest::test_AHB_SIO> write to AHB_SIO failed");
            errlCommit(l_err,SIO_COMP_ID);
        }
        mutex_unlock(&l_lock);
    }
};
#endif
