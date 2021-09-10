/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mdsaccess/test/mdsI2cScomTest.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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

#ifndef MDS_I2C_SCOM_TEST_H
#define MDS_I2C_SCOM_TEST_H

/**
 *  @file mdsI2cScomTest.H
 *
 *  @brief Test case for MDS I2C SCOM
*/

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <cxxtest/TestSuite.H>   // CxxTest::TestSuite
#include "../mdsAccessTrace.H"   // g_trac_mdsaccess
#include <mdsaccess/mdsaccess_reasoncodes.H> // MDS access ReasonCodes/ModuleIds
#include <targeting/common/utilFilter.H>      // getAllAsics
#include <targeting/common/commontargeting.H> // targetService, TYPE_PROC, TYPE_MDS_CTLR
#include <devicefw/userif.H>                  // deviceFW::DEVICE_SCOM_ADDRESS
#include <devicefw/driverif.H>                // deviceFW::DEVICE_I2CSCOM_ADDRESS
#include <devicefw/driverif_common.H>         // deviceFW::READ, deviceFW::WRITE

using namespace TARGETING;
using namespace DeviceFW;

extern trace_desc_t* g_trac_mdsaccess;

class MdsI2cScomTest: public CxxTest::TestSuite
{
public:

    /**
     * @brief Constructor
     */
    MdsI2cScomTest()
    : iv_buflen(sizeof(uint64_t)),
      iv_buffer(malloc(iv_buflen)),
      iv_scomAddress(0xABCDEF12),
      iv_mdsTarget(nullptr)
    {
        // Don't need a functional MDS_CTLR target for this test suite
        TARGETING::TargetHandleList mdsTargetList;
        TARGETING::getAllAsics(mdsTargetList,
                               TARGETING::TYPE_MDS_CTLR,
                               false );
        if(mdsTargetList.size())
        {
            iv_mdsTarget = mdsTargetList[0];
        }

        // Create a reference to the iv_buffer for easy manipulation
        uint64_t &l_dataBuffer = (*reinterpret_cast<uint64_t *>(iv_buffer));
        l_dataBuffer = 0xAABB;
    } // MdsI2cScomTest

    /**
     * @brief Destructor
     */
    ~MdsI2cScomTest()
    {
        if (iv_buffer)
        {
            free(iv_buffer);
            iv_buffer = nullptr;
        }
    } // ~MdsI2cScomTest

    /**
     * @brief The starting point of the tests.  Calls all tests
     */
    void testMdsI2cScom(void)
    {
        if (!iv_mdsTarget)
        {
            TRACFCOMP( g_trac_mdsaccess,
                      INFO_MRK"testMdsI2cScom::No functional/valid MDS_CTRL target found. "
                               "Not running tests." );
            return;
        }

        // Test that the MDS I2C SCOM calls will validate the inputs correctly
        // This is a negative test, testing for failures not SCOM call passes.
        validateInputsNegativeTest();
    }

private: // private methods that actually do the testing
    /**
     * @brief Test the validity of the input parameters to the read/write SCOM calls
     */
    void validateInputsNegativeTest(void)
    {
        TRACFCOMP( g_trac_mdsaccess, ENTER_MRK"Running test validateInputsNegativeTest");

        errlHndl_t l_err(nullptr);

        // Test DD (Device Driver Interface) with a NULL buffer
        void* l_buffer(nullptr);
        l_err = DeviceFW::deviceOp( DeviceFW::READ,
                                    iv_mdsTarget,
                                    l_buffer,
                                    iv_buflen,
                                    DEVICE_I2CSCOM_ADDRESS(iv_scomAddress) );
        if (l_err && (l_err->reasonCode() != MDS_ACCESS::RC_INVALID_DATA_BUFFER) )
        {
            TS_FAIL("validateInputsNegativeTest: DD Test failed to return the "
                    "correct reason code:  received = 0x%0.4X, but expected = "
                    "MDS_ACCESS::RC_INVALID_DATA_BUFFER(0x%0.4X)",
                     l_err->reasonCode(), MDS_ACCESS::RC_INVALID_DATA_BUFFER);
        }
        else if (!l_err)
        {
            TS_FAIL("validateInputsNegativeTest: DD Test failed to produce an "
                    "error log when given a nullptr buffer");
        }

        // It is safe to delete a nullptr
        delete l_err; l_err = nullptr;

        // Test UI (User Interface) with a NULL buffer
        l_buffer = nullptr;
        l_err = DeviceFW::deviceRead( iv_mdsTarget,
                                      l_buffer,
                                      iv_buflen,
                                      DEVICE_SCOM_ADDRESS(iv_scomAddress) );
        if (l_err && (l_err->reasonCode() != MDS_ACCESS::RC_INVALID_DATA_BUFFER) )
        {
            TS_FAIL("validateInputsNegativeTest: UI Test failed to return the "
                    "correct reason code: received = 0x%0.4X, but expected = "
                    "MDS_ACCESS::RC_INVALID_DATA_BUFFER(0x%0.4X)",
                     l_err->reasonCode(), MDS_ACCESS::RC_INVALID_DATA_BUFFER);
        }
            else if (!l_err)
        {
            TS_FAIL("validateInputsNegativeTest: UI Test failed to produce an "
                    "error log when given a nullptr buffer");
        }
        // It is safe to delete a nullptr
        delete l_err; l_err = nullptr;



        // Test DD interface with an incorrect buffer length
        size_t l_buflen(sizeof(uint32_t));
        l_err = DeviceFW::deviceOp( DeviceFW::WRITE,
                                    iv_mdsTarget,
                                    iv_buffer,
                                    l_buflen,
                                    DEVICE_I2CSCOM_ADDRESS(iv_scomAddress) );
        if (l_err && (l_err->reasonCode() != MDS_ACCESS::RC_INVALID_BUFFER_LENGTH) )
        {
            TS_FAIL("validateInputsNegativeTest: DD Test failed to return the "
                    "correct reason code: received = 0x%0.4X, but expected = "
                    "MDS_ACCESS::RC_INVALID_BUFFER_LENGTH(0x%0.4X)",
                     l_err->reasonCode(), MDS_ACCESS::RC_INVALID_BUFFER_LENGTH);
        }
        else if (!l_err)
        {
            TS_FAIL("validateInputsNegativeTest: DD Test failed to produce an "
                    "error log when given an incorrect buffer length of %d", l_buflen);
        }
        // It is safe to delete a nullptr
        delete l_err; l_err = nullptr;

        // Test UI with an incorrect buffer length
        l_buflen = sizeof(uint32_t);
        l_err = DeviceFW::deviceWrite( iv_mdsTarget,
                                       iv_buffer,
                                       l_buflen,
                                       DEVICE_SCOM_ADDRESS(iv_scomAddress) );
        if (l_err && (l_err->reasonCode() != MDS_ACCESS::RC_INVALID_BUFFER_LENGTH) )
        {
            TS_FAIL("validateInputsNegativeTest: UI Test failed to return the "
                    "correct reason code: received = 0x%0.4X, but expected = "
                    "MDS_ACCESS::RC_INVALID_BUFFER_LENGTH(0x%0.4X)",
                     l_err->reasonCode(), MDS_ACCESS::RC_INVALID_BUFFER_LENGTH);
        }
        else if (!l_err)
        {
            TS_FAIL("validateInputsNegativeTest: UI Test failed to produce an "
                    "error log when given an incorrect buffer length of %d", l_buflen);
        }
        // It is safe to delete a nullptr
        delete l_err; l_err = nullptr;



        // Test DD with a bad SCOM address
        uint64_t l_scomAddress(0x7BCDEF12ABCDEF12);
        l_err = DeviceFW::deviceOp( DeviceFW::WRITE,
                                    iv_mdsTarget,
                                    iv_buffer,
                                    iv_buflen,
                                    DEVICE_I2CSCOM_ADDRESS(l_scomAddress) );
        if (l_err && (l_err->reasonCode() != MDS_ACCESS::RC_INVALID_SCOM_ADDRESS) )
        {
            TS_FAIL("validateInputsNegativeTest: DD Test failed to return the "
                    "correct reason code: received = 0x%0.4X, but expected = "
                    "MDS_ACCESS::RC_INVALID_SCOM_ADDRESS(0x%0.4X)",
                     l_err->reasonCode(), MDS_ACCESS::RC_INVALID_SCOM_ADDRESS);
        }
        else if (!l_err)
        {
            TS_FAIL("validateInputsNegativeTest: DD Test failed to produce an "
                    "error log when given a bad SCOM address = 0X%lX", l_scomAddress);
        }
        // It is safe to delete a nullptr
        delete l_err; l_err = nullptr;

        // Test UI with a bad SCOM address
        l_scomAddress = 0x7BCDEF12ABCDEF12;
        l_err = DeviceFW::deviceWrite( iv_mdsTarget,
                                       iv_buffer,
                                       iv_buflen,
                                       DEVICE_SCOM_ADDRESS(l_scomAddress) );
        if (l_err && (l_err->reasonCode() != MDS_ACCESS::RC_INVALID_SCOM_ADDRESS) )
        {
            TS_FAIL("validateInputsNegativeTest: UI Test failed to return the "
                    "correct reason code: received = 0x%0.4X, but expected = "
                    "MDS_ACCESS::RC_INVALID_SCOM_ADDRESS(0x%0.4X)",
                     l_err->reasonCode(), MDS_ACCESS::RC_INVALID_SCOM_ADDRESS);
        }
        else if (!l_err)
        {
            TS_FAIL("validateInputsNegativeTest: UI Test failed to produce an "
                    "error log when given a bad SCOM address = 0X%lX", l_scomAddress);
        }
        // It is safe to delete a nullptr
        delete l_err; l_err = nullptr;

        TRACFCOMP( g_trac_mdsaccess, EXIT_MRK"Running test validateInputsNegativeTest");

    } // void validateInputsNegativeTest(void)

private:  // private data members
    size_t         iv_buflen;
    void*          iv_buffer;
    uint64_t       iv_scomAddress;
    TargetHandle_t iv_mdsTarget;
};

#endif
