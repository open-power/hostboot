/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/xscom/test/xscomtest.H $                              */
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
#ifndef __XCOMTEST_H
#define __XCOMTEST_H

/**
 *  @file xscomtest.H
 *
 *  @brief Test case for XSCOM code
*/

#include <sys/mmio.h>
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/userif.H>
#include <devicefw/driverif.H>
#include <xscom/xscomreasoncodes.H>
#include <xscom.H>
#include <xscom/piberror.H>
extern trace_desc_t* g_trac_xscom;

// Forward declare these XSCOM methods because they are not declared in the
// xscom header file (xscom.H) but only in the C file (xscom.C).
namespace XSCOM
{
errlHndl_t xScomDoOp(DeviceFW::OperationType i_opType,
                     uint64_t* i_virtAddr,
                     uint64_t i_xscomAddr,
                     void* io_buffer,
                     size_t& io_buflen,
                     HMER &io_hmer);

errlHndl_t getTargetVirtualAddress(TARGETING::Target* i_target,
                                           uint64_t*& o_virtAddr);

void resetScomEngine(TARGETING::Target* i_target,
                              uint64_t* i_virtAddr,
                        const uint64_t  i_mXSComStatus);
};


using namespace TARGETING;

// Address and data to read/write
struct testXscomAddrData
{
    uint32_t addr;
    uint64_t data;
};

// Test table values
const testXscomAddrData g_xscomAddrTable[] =
{
        // Write data to be ORed with read value
        // Use ECP.EC.PC.SCR0 and ECP.EC.PC.SCR1
        // Scom registers for testing
        {0x20028486, 0x0000040000000000},
        {0x20028487, 0xC000000000000000},
};
const uint32_t g_xscomAddrTableSz =
                    sizeof(g_xscomAddrTable)/sizeof(testXscomAddrData);


// Test table values read through multicast op
const testXscomAddrData g_xscomMultiReadTable[] =
{
        // Scratch reg 3
        //   Multicast OR op
        {0x41010a89, 0x1234000000000000},
        // Group0 Xstop Mask regs, TPEQPCC.EPS.FIR.GXSTOP0_MASK_REG
        //   ChipletID 0x10 0x20
        //   Multicast BITWISE op
        {0x50040014, 0x0000800080000000},
};
const uint32_t g_xscomMultiReadTableSz =
                sizeof(g_xscomMultiReadTable)/sizeof(testXscomAddrData);


class XscomTest: public CxxTest::TestSuite
{
public:

    /**
     * @brief XSCOM test #1
     *        Write value and read back to verify
     */
    void testXscom1(void)
    {

        TARGETING::TargetService& l_targetService = TARGETING::targetService();
        TARGETING::Target* l_testTarget = NULL;
        l_targetService.masterProcChipTargetHandle( l_testTarget );
        assert(l_testTarget != NULL);

        size_t l_size = sizeof(uint64_t);

        TS_INFO("testScom1 Start");

        // Loop thru table
        errlHndl_t l_err = NULL;
        for( uint32_t l_num=0; l_num < g_xscomAddrTableSz; l_num++)
        {
             testXscomAddrData l_testEntry = g_xscomAddrTable[l_num];

             // Perform XSComOM read
             uint64_t l_readData = 0;
             uint64_t l_writeData = 0;
             uint64_t l_savedData = 0;
             l_err = deviceRead(l_testTarget,
                                &l_readData,
                                l_size,
                                DEVICE_SCOM_ADDRESS(l_testEntry.addr));
             if (l_err)
             {
                 TS_FAIL("testXscom1: XSCom read: deviceRead() fails! Error committed.");
                 break;
             }
             else
             {
                 TS_TRACE("testXscom1: XSCom read, Address 0x%.8X, Data %llx",
                                                      l_testEntry.addr,
                                                      (long long unsigned)l_readData);
             }

             // Perform an XSCom write
             l_savedData = l_readData;
             l_writeData = (l_readData | l_testEntry.data);
             l_err = deviceWrite(l_testTarget,
                                 &l_writeData,
                                 l_size,
                                 DeviceFW::SCOM,
                                 l_testEntry.addr);

             if (l_err)
             {
                 TS_FAIL("testXscom1: XSCom write: deviceWrite() fails!");
                 break;
             }
             else
             {
                 TS_TRACE("testXscom1: XSCom write, Address 0x%.8X, Data %llx",
                         l_testEntry.addr,
                         (long long unsigned)l_writeData);
             }

             // Read back
             l_readData = 0;
             l_err = deviceRead(l_testTarget,
                                &l_readData,
                                l_size,
                                DEVICE_SCOM_ADDRESS(l_testEntry.addr));
             if (l_err)
             {
                 TS_FAIL("testXscom1: XSCom read back: deviceRead() fails!");
                 break;
             }

             if( l_readData != l_writeData )
             {
                 TS_FAIL("testXscom1: XSCom read back doesn't match write!");
                 /*@
                  * @errortype
                  * @moduleid     XSCOM::XSCOM_TEST_XSCOM1
                  * @reasoncode   XSCOM::XSCOM_DATA_UNMATCHED
                  * @userdata1    Write value
                  * @userdata2    Read back value
                  * @devdesc      Read back value doesn't match write
                  */
                 l_err = new ERRORLOG::ErrlEntry(
                         ERRORLOG::ERRL_SEV_INFORMATIONAL,
                         XSCOM::XSCOM_TEST_XSCOM1,
                         XSCOM::XSCOM_DATA_UNMATCHED,
                         l_writeData,
                         l_readData);
                 break;
             }

             // Write back original value
             l_err = deviceWrite(l_testTarget,
                      &l_savedData,
                      l_size,
                      DeviceFW::SCOM,
                      l_testEntry.addr);

              if (l_err)
              {
                  TS_FAIL("testXscom1: XSCom write back original fails!");
                  break;
              }
        }

        if (l_err)
        {
            TS_FAIL("testXscom1 failed!  Error committed.");
            errlCommit(l_err,XSCOM_COMP_ID);
        }
        else
        {
            TS_INFO("testXscom1 runs successfully!");
        }
        return;
  }


    /**
     * @brief XSCOM test #2
     *        Write value and read back to verify
     */
    void testXscom2(void)
    {

        TARGETING::TargetService& l_targetService = TARGETING::targetService();
        TARGETING::Target* l_testTarget = NULL;
        l_targetService.masterProcChipTargetHandle( l_testTarget );
        assert(l_testTarget != NULL);

        size_t l_size = sizeof(uint64_t);

        uint64_t l_readData = 0;
        uint64_t l_writeData[g_xscomAddrTableSz];
        uint64_t l_savedData[g_xscomAddrTableSz];

        // Loop thru table to do initial write
        errlHndl_t l_err = NULL;

        TS_INFO("testScom2 Start");

        for( uint32_t l_num=0; l_num < g_xscomAddrTableSz; l_num++)
        {
            testXscomAddrData l_testEntry = g_xscomAddrTable[l_num];

            // Perform XSComOM read
            l_err = deviceRead(l_testTarget,
                               &l_readData,
                               l_size,
                               DEVICE_SCOM_ADDRESS(l_testEntry.addr));
            if (l_err)
            {
                TS_FAIL("testXscom2: XSCom read: deviceRead() fails! Error committed.");
                break;
            }
            else
            {
                TS_TRACE("testXscom2: XSCom read, Address 0x%.8X, Data %llx",
                         l_testEntry.addr,
                         (long long unsigned)l_readData);
            }

            // Perform an XSCom write
            l_savedData[l_num] = l_readData;
            l_writeData[l_num] = (l_readData | l_testEntry.data);
            l_err = deviceWrite(l_testTarget,
                                &l_writeData[l_num],
                                l_size,
                                DeviceFW::SCOM,
                                l_testEntry.addr);

            if (l_err)
            {
                TS_FAIL("testXscom2: XSCom write: deviceWrite() fails!");
                break;
            }
            else
            {
                TS_INFO("testXscom2: XSCom write, Address 0x%.8X, Data %llx",
                         l_testEntry.addr,
                         (long long unsigned)l_writeData);
            }
        }

        // Loop through table to do the read and verify
        for( uint32_t l_num=0; l_num < g_xscomAddrTableSz; l_num++)
        {
            testXscomAddrData l_testEntry = g_xscomAddrTable[l_num];

            // Read back
            l_readData = 0;
            l_err = deviceRead(l_testTarget,
                               &l_readData,
                               l_size,
                               DEVICE_SCOM_ADDRESS(l_testEntry.addr));
            if (l_err)
            {
                TS_FAIL("testXscom2: XSCom read back: deviceRead() fails!");
                break;
            }

            if( l_readData != l_writeData[l_num] )
            {
                TS_FAIL("testXscom2: XSCom read back doesn't match write!");
                /*@
                 * @errortype
                 * @moduleid     XSCOM::XSCOM_TEST_XSCOM2
                 * @reasoncode   XSCOM::XSCOM_DATA_UNMATCHED
                 * @userdata1    Write value
                 * @userdata2    Read back value
                 * @devdesc      Read back value doesn't match write
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                                XSCOM::XSCOM_TEST_XSCOM1,
                                                XSCOM::XSCOM_DATA_UNMATCHED,
                                                l_writeData[l_num],
                                                l_readData);
                break;
            }

            // Write back original value
            l_err = deviceWrite(l_testTarget,
                                &l_savedData[l_num],
                                l_size,
                                DeviceFW::SCOM,
                                l_testEntry.addr);

            if (l_err)
            {
                TS_FAIL("testXscom2: XSCom write back original fails!");
                break;
            }
        }

        if (l_err)
        {
            TS_FAIL("testXscom2 failed!  Error committed.");
            errlCommit(l_err,XSCOM_COMP_ID);
        }
        else
        {
            TS_INFO("testXscom2 runs successfully!");
        }
        return;
    }


    //TODO: RTC34591 - Add testcase that talks to the non master proc.

    /**
     * @brief XSCOM test #3
     *        read to an invalid address to force error path
     */
    void testXscom3(void)
    {

        TARGETING::TargetService& l_targetService = TARGETING::targetService();
        TARGETING::Target* l_testTarget = NULL;
        l_targetService.masterProcChipTargetHandle( l_testTarget );
        assert(l_testTarget != NULL);
        errlHndl_t l_err = NULL;

        TS_INFO("testXscom3 Start");

        size_t l_size = sizeof(uint64_t);


        // Perform XSComOM read
        uint64_t l_readData = 0;
        l_err = deviceRead(l_testTarget,
                           &l_readData,
                           l_size,
                           DEVICE_SCOM_ADDRESS(0x01001111));
        if (l_err)
        {

            TS_INFO("testXscom3: XSCom read fails as expected: invalid addr");
            errlCommit(l_err,XSCOM_COMP_ID);
            TS_INFO("testXscom3 runs successfully!");
        }
        else
        {
            TS_FAIL("testXscom3: XSCom read did not fail with bad address");
        }


        return;
    }


    /**
     * @brief XSCOM test #4
     *        read to an invalid address to force error path, then set the HMER
     *        xscom status to PIB_TIMEOUT to force the timeout path in the
     *        resetScomEngine method.
     */
    void testXscom4(void)
    {
        TARGETING::TargetService& l_targetService = TARGETING::targetService();
        TARGETING::Target* l_testTarget(nullptr);
        l_targetService.masterProcChipTargetHandle( l_testTarget );
        assert(l_testTarget != nullptr);
        errlHndl_t l_err(nullptr);

        TS_INFO("testScom4 Start");

        XSCOM::HMER l_hmer;
        uint64_t *l_virtAddr(nullptr);
        uint64_t l_xscomAddr(0x01001111);
        uint64_t l_readData(0);
        uint64_t l_readDataSize(sizeof(l_readData));

        l_err = XSCOM::getTargetVirtualAddress(l_testTarget, l_virtAddr);
        assert(l_err == nullptr, "testXscom4: ERROR: Unexpected fail with call to XSCOM::getTargetVirtualAddress");

        // Pin this thread to current CPU
        task_affinity_pin();

        // Lock other XSCom in this same thread from running
        mutex_t* l_XSComMutex = mmio_xscom_mutex();
        mutex_lock(l_XSComMutex);

        l_err = XSCOM::xScomDoOp(DeviceFW::READ, l_virtAddr, l_xscomAddr, &l_readData,
                          l_readDataSize, l_hmer);

        assert(l_hmer.mXSComStatus == PIB::PIB_INVALID_ADDRESS, "testXscom4: ERROR: Unexpected HMER status");

        if (l_err)
        {
            bool l_failAsExpected(true);

            if (l_err->reasonCode() != XSCOM::XSCOM_STATUS_ERR)
            {
                TS_FAIL("testXscom4(negative test): XSCom read failed with unexpected reason "
                        "code (0x%.4X), was expecting reason code XSCOM::XSCOM_STATUS_ERR (0x%.4X)",
                        l_err->reasonCode(),
                        XSCOM::XSCOM_STATUS_ERR);
                l_failAsExpected = false;
            }

            if (l_err->moduleId() != XSCOM::XSCOM_DO_OP)
            {
                TS_FAIL("testXscom4(negative test): XSCom read failed with unexpected module "
                        "ID (0x%.2X), was expecting module ID XSCOM::XSCOM_DO_OP (0x%.2X)",
                        l_err->moduleId(),
                        XSCOM::XSCOM_DO_OP);
                l_failAsExpected = false;
            }

            if (l_failAsExpected)
            {
                TS_INFO("testXscom4(negative test): XSCom read *successfully* failed as expected: invalid addr");
                // This is an expected failure, no need to log it.
                delete l_err;
                l_err = nullptr;

            }
            else
            {
                TS_INFO("testXscom4(negative test): WARNING: XSCom read had an unexpected failure");
                errlCommit(l_err, XSCOM_COMP_ID);
            }
        }
        else
        {
            TS_FAIL("testXscom4(negative test): XSCom read did not fail with bad address");
        }

        /// Regardless if fail was on an unexpected failure or not, still want to
        /// reset the SCOM engine.
        // Spoof the timeout error ... set the HMER status to a timeout error.
        // This is the only way I know how to test a timeout error. Unfortunately,
        // to confirm the test worked, is to visually inspect the trace output
        // for a statement such as, "XSCOM caused a time out error".
        // Reset the scomEngine with timeout error
        l_hmer.mXSComStatus = PIB::PIB_TIMEOUT;
        XSCOM::resetScomEngine(l_testTarget, l_virtAddr, l_hmer.mXSComStatus);

        // Unlock
        mutex_unlock(l_XSComMutex);

        // Done, un-pin
        task_affinity_unpin();
        TS_INFO("testScom4 End");
    }; // void testXscom4(void)

};

#endif
