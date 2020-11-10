/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expaccess/test/expscomtest.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
#ifndef __EXPSCOMTEST_H
#define __EXPSCOMTEST_H

/**
 *  @file expscomtest.H
 *
 *  @brief Test case for EXPSCOM code
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/userif.H>
#include <expscom/expscom_reasoncodes.H>
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <fapi2_hwp_executor.H>
#include <fapi2/hw_access.H>
#include <lib/shared/exp_consts.H>
#include "exptest_utils.H"
#include "../expscom_trace.H"


using namespace TARGETING;
using namespace ERRORLOG;

// Address and data to read/write
struct testExpscomAddrData
{
    uint32_t addr;
    uint64_t data;
};

// Test table values
const testExpscomAddrData g_expscomAddrTable[] =
{
        {0x501C,     0x00000000DEADBEEF}, // UART scratch register
        {0x209004,   0x00000000C0DEDEAD}, // PVT_CTRL - TM_SCRATCH register
        {0x8010002,  0xDEADC0DEC0DEBEEF}  // PSCOM_ERROR_MASK register
};

const uint32_t g_expscomAddrTableSz =
                    sizeof(g_expscomAddrTable)/sizeof(testExpscomAddrData);


const ScomSwitches forceI2CScom = {.useFsiScom = 0, .useXscom = 0,
                                   .useInbandScom = 0, .useSbeScom = 0,
                                   .useI2cScom = 1};

const ScomSwitches forceMMIOScom = {.useFsiScom = 0, .useXscom = 0,
                                   .useInbandScom = 1, .useSbeScom = 0,
                                   .useI2cScom = 0};

const ScomSwitches forceSBEScom = {.useFsiScom = 0, .useXscom = 0,
                                   .useInbandScom = 0, .useSbeScom = 1,
                                   .useI2cScom = 0};

#define FAIL_TEST_RC(TARGET, STRING) \
l_fails++; \
TS_FAIL(STRING , \
        l_testEntry.data, \
        l_testEntry.addr, \
        get_huid(TARGET)); \
l_err = fapi2::rcToErrl(l_rc); \
errlCommit(l_err, CXXTEST_COMP_ID);

#define FAIL_TEST_ERRL(TARGET, STRING) \
l_fails++; \
TS_FAIL(STRING , \
        l_testEntry.data, \
        l_testEntry.addr, \
        get_huid(TARGET)); \
errlCommit(l_err, CXXTEST_COMP_ID);

class expscomTest: public CxxTest::TestSuite
{
private:
    fapi2::ReturnCode put_scom(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                               const uint64_t i_address,
                               const fapi2::buffer<uint64_t> i_data)
    {
      return fapi2::putScom(i_target,i_address,i_data);
    }

    fapi2::ReturnCode get_scom(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                               const uint64_t i_address,
                               fapi2::buffer<uint64_t>& o_data)
    {
      return fapi2::getScom(i_target,i_address,o_data);
    }

    fapi2::ReturnCode put_scom(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                               const uint64_t i_address,
                               const fapi2::buffer<uint64_t> i_data)
    {
        return fapi2::putScom(i_target,i_address,i_data);
    }

    fapi2::ReturnCode get_scom(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                               const uint64_t i_address,
                               fapi2::buffer<uint64_t>& o_data)
    {
        return fapi2::getScom(i_target,i_address,o_data);
    }

    // This is used for tests that need to not run operations at the same time
    HB_MUTEX_SERIALIZE_TEST_LOCK_ATTR iv_serializeTestMutex;

public:

    /**
    * @brief EXPSCOM test I2C Path of FAPI HWP interfaces
    *        Write value and read back to verify i2c scoms to OCMBs
    */
    void testExpscomI2c(void)
    {
// Only MMIO supported at runtime
#ifndef __HOSTBOOT_RUNTIME
        TRACFCOMP( g_trac_expscom, ">> Enter  testExpscomI2c");
        // Keep trace of pass/fails
        uint32_t l_tests = 0;
        uint32_t l_fails = 0;
        errlHndl_t l_err = nullptr;

        // Fapi interfaces will be used in these tests so this variable
        // will be used to hold error from fapi calls
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
        fapi2::buffer<uint64_t> l_scom_buffer;

        do{
            if (!iv_serializeTestMutex)
            {
                TS_FAIL("iv_serializedTestMutex is not setup");
                break;
            }

            // Get the system's OCMB chips, we will use these as test targets
            TargetHandleList l_explorerList;
            getAllChips( l_explorerList,
                          TYPE_OCMB_CHIP,
                          true ); // true: return functional OCMBs

            if(l_explorerList.size() == 0 )
            {
                TRACFCOMP( g_trac_expscom, "No OCMB targets found, skipping testExpscomI2c");
                break;
            }

            // Get the system's MEM_PORT units, we will use these as test targets
            TargetHandleList l_memportList;
            getAllChiplets( l_memportList,
                            TYPE_MEM_PORT,
                            true ); // true: return functional OCMBs

            if(l_explorerList.size() != l_memportList.size() )
            {
                TS_FAIL( "Wrong number of MEM_PORTs (%d) compared to OCMB_CHIPs (%d)", l_memportList.size(), l_explorerList.size() );
                break;
            }

            // We will use the first and last targets for these scom tests
            auto l_firstExpChip = l_explorerList.front();
            auto l_lastExpChip  = l_explorerList.back();
            auto l_firstMemPort = l_memportList.front();
            auto l_lastMemPort  = l_memportList.back();

            // Cast the TARGETING::Targets into fapi2::Targets
            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_firstExpChip_fapi(l_firstExpChip);
            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_lastExpChip_fapi(l_lastExpChip);
            fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> l_firstMemPort_fapi(l_firstMemPort);
            fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> l_lastMemPort_fapi(l_lastMemPort);

            // Save away original scom switch info so we can restore it at the end of the test
            auto first_ocmb_info =
                l_firstExpChip->getAttr<ATTR_SCOM_SWITCHES>();
            auto last_ocmb_info  =
                l_lastExpChip->getAttr<ATTR_SCOM_SWITCHES>();

            // Inband operations can't be run at the same time
            // atomic section >>
            mutex_lock(iv_serializeTestMutex);

            // The goal of these tests is to make sure I2C scom to OCMB is
            // working so force scom to go over I2C path for these targets
            l_firstExpChip->setAttr<ATTR_SCOM_SWITCHES>(forceI2CScom);
            l_lastExpChip->setAttr<ATTR_SCOM_SWITCHES>(forceI2CScom);

            // Loop through table for first and last OCMB targets
            for( uint32_t l_num=0; l_num < g_expscomAddrTableSz; l_num++)
            {
                // Read the test entry info from the global table at the top of this file
                testExpscomAddrData l_testEntry = g_expscomAddrTable[l_num];

                if(l_testEntry.addr & mss::exp::i2c::IBM_SCOM_INDICATOR)
                {
                    // If this is an IBM address then we expect 64 bits of data
                    l_scom_buffer.insert<0,64,0,uint64_t>(l_testEntry.data);
                }
                else
                {
                    // Otherwise we know this is a native OCMB address and it is only 32 bits
                    l_scom_buffer.insert<32,32,0,uint32_t>(l_testEntry.data);
                }

                FAPI_INVOKE_HWP(l_err, put_scom,
                                l_firstExpChip_fapi,
                                l_testEntry.addr,
                                l_scom_buffer );
                l_tests++;
                if(l_err)
                {
                    FAIL_TEST_ERRL(l_firstExpChip,
                                "testExpscomI2c>> Failed putScom writing 0x%016lx to 0x%08x on target w/ huid 0x%08x");

                }

                // putScom to last OCMB over i2c
                FAPI_INVOKE_HWP(l_err, put_scom,
                                l_lastExpChip_fapi,
                                l_testEntry.addr,
                                l_scom_buffer );
                l_tests++;
                if(l_err)
                {
                    FAIL_TEST_ERRL(l_lastExpChip,
                              "testExpscomI2c>> Failed putScom writing 0x%016lx to 0x%08x on target w/ huid 0x%08x");
                }


                // Flush scom buffers so it doesnt mess up next test
                l_scom_buffer.flush<0>();

                // getScom to first OCMB over i2c
                FAPI_INVOKE_HWP(l_err, get_scom,
                                l_firstExpChip_fapi,
                                l_testEntry.addr,
                                l_scom_buffer );
                l_tests++;
                if(l_err)
                {
                    FAIL_TEST_ERRL(l_firstExpChip,
                                "testExpscomI2c>> Failed getScom reading 0x%016lx to 0x%08x on target w/ huid 0x%08x");
                }

                l_tests++;
                if(l_scom_buffer() != l_testEntry.data)
                {
                    l_fails++;
                    TS_FAIL("testExpscomI2c>> Expected 0x%016lx but got 0x%016lx on target w/ huid 0x%08x",
                            l_testEntry.data,
                            l_scom_buffer(),
                            get_huid(l_firstExpChip));
                }

                // Flush scom buffers so it doesnt mess up next test
                l_scom_buffer.flush<0>();

                // getScom to last OCMB over i2c
                FAPI_INVOKE_HWP(l_err, get_scom,
                                l_lastExpChip_fapi,
                                l_testEntry.addr,
                                l_scom_buffer );
                l_tests++;
                if(l_err)
                {
                    FAIL_TEST_ERRL(l_lastExpChip,
                                "testExpscomI2c>> Failed getScom reading 0x%016lx to 0x%08x on target w/ huid 0x%08x");
                }

                l_tests++;
                if(l_scom_buffer() != l_testEntry.data)
                {
                    l_fails++;
                    TS_FAIL("testExpscomI2c>> Expected 0x%016lx but got 0x%016lx on target w/ huid 0x%08x",
                            l_testEntry.data,
                            l_scom_buffer(),
                            get_huid(l_lastExpChip));
                }

                /// Repeat everything on the MEM_PORT targets

                // Read the test entry info from the global table at the top of this file
                l_testEntry = g_expscomAddrTable[l_num];

                if(l_testEntry.addr & mss::exp::i2c::IBM_SCOM_INDICATOR)
                {
                    // If this is an IBM address then we expect 64 bits of data
                    l_scom_buffer.insert<0,64,0,uint64_t>(l_testEntry.data);
                }
                else
                {
                    // Otherwise we know this is a native OCMB address and it is only 32 bits
                    l_scom_buffer.insert<32,32,0,uint32_t>(l_testEntry.data);
                }

                FAPI_INVOKE_HWP(l_err, put_scom,
                                l_firstMemPort_fapi,
                                l_testEntry.addr,
                                l_scom_buffer );
                l_tests++;
                if(l_err)
                {
                    FAIL_TEST_ERRL(l_firstMemPort,
                                "testExpscomI2c>> Failed putScom writing 0x%016lx to 0x%08x on target w/ huid 0x%08x");

                }

                // putScom to last MEM_PORT over i2c
                FAPI_INVOKE_HWP(l_err, put_scom,
                                l_lastMemPort_fapi,
                                l_testEntry.addr,
                                l_scom_buffer );
                l_tests++;
                if(l_err)
                {
                    FAIL_TEST_ERRL(l_lastMemPort,
                              "testExpscomI2c>> Failed putScom writing 0x%016lx to 0x%08x on target w/ huid 0x%08x");
                }


                // Flush scom buffers so it doesnt mess up next test
                l_scom_buffer.flush<0>();

                // getScom to first MEM_PORT over i2c
                FAPI_INVOKE_HWP(l_err, get_scom,
                                l_firstMemPort_fapi,
                                l_testEntry.addr,
                                l_scom_buffer );
                l_tests++;
                if(l_err)
                {
                    FAIL_TEST_ERRL(l_firstMemPort,
                                "testExpscomI2c>> Failed getScom reading 0x%016lx to 0x%08x on target w/ huid 0x%08x");
                }

                l_tests++;
                if(l_scom_buffer() != l_testEntry.data)
                {
                    l_fails++;
                    TS_FAIL("testExpscomI2c>> Expected 0x%016lx but got 0x%016lx on target w/ huid 0x%08x",
                            l_testEntry.data,
                            l_scom_buffer(),
                            get_huid(l_firstMemPort));
                }

                // Flush scom buffers so it doesnt mess up next test
                l_scom_buffer.flush<0>();

                // getScom to last MEM_PORT over i2c
                FAPI_INVOKE_HWP(l_err, get_scom,
                                l_lastMemPort_fapi,
                                l_testEntry.addr,
                                l_scom_buffer );
                l_tests++;
                if(l_err)
                {
                    FAIL_TEST_ERRL(l_lastMemPort,
                                "testExpscomI2c>> Failed getScom reading 0x%016lx to 0x%08x on target w/ huid 0x%08x");
                }

                l_tests++;
                if(l_scom_buffer() != l_testEntry.data)
                {
                    l_fails++;
                    TS_FAIL("testExpscomI2c>> Expected 0x%016lx but got 0x%016lx on target w/ huid 0x%08x",
                            l_testEntry.data,
                            l_scom_buffer(),
                            get_huid(l_lastMemPort));
                }
            }

            // Set ATTR_SCOM_SWITCHES back to their original values
            l_firstExpChip->setAttr<ATTR_SCOM_SWITCHES>(first_ocmb_info);
            l_lastExpChip->setAttr<ATTR_SCOM_SWITCHES>(last_ocmb_info);

            // << atomic section
            mutex_unlock(iv_serializeTestMutex);
        }while(0);
        TRACFCOMP( g_trac_expscom, "<< Exit  testExpscomI2c");
#endif
        return;
    }

    /**
     * @brief Test platform level interfaces over I2C
     */
    void testExpscomI2cPlatform(void)
    {
// Only mmio supported at runtime
#ifndef __HOSTBOOT_RUNTIME
        TRACFCOMP( g_trac_expscom, ">> Enter  testExpscomI2cPlatform");
        // Keep trace of pass/fails
        uint32_t l_tests = 0;
        uint32_t l_fails = 0;
        errlHndl_t l_err = nullptr;
        size_t l_scomSize = sizeof(uint64_t);

        // Fapi interfaces will be used in these tests so this variable
        // will be used to hold error from fapi calls
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
        fapi2::buffer<uint64_t> l_scom_buffer;

        // Get the system's OCMB chips, we will use these as test targets
        TargetHandleList l_explorerList;

        do{
            if (!iv_serializeTestMutex)
            {
                TS_FAIL("iv_serializedTestMutex is not setup");
                break;
            }
            getAllChips( l_explorerList,
                          TYPE_OCMB_CHIP,
                          true ); // true: return functional OCMBs


            if(l_explorerList.size() == 0 )
            {
                TRACFCOMP( g_trac_expscom, "No OCMB targets found, skipping testExpscomI2cPlatform");
                break;
            }

            // We will use the first and last targets for these scom tests
            auto l_firstExpChip = l_explorerList.front();
            auto l_lastExpChip  = l_explorerList.back();

            // Save away original scom switch info so we can restore it at the end of the test
            auto first_ocmb_info =
                l_firstExpChip->getAttr<ATTR_SCOM_SWITCHES>();
            auto last_ocmb_info  =
                l_lastExpChip->getAttr<ATTR_SCOM_SWITCHES>();

            // Inband operations can't be run at the same time
            // atomic section >>
            mutex_lock(iv_serializeTestMutex);

            // This goal of this tests is to make sure I2C scom to OCMB is working so force
            // scom to go over I2C path for these targets
            l_firstExpChip->setAttr<ATTR_SCOM_SWITCHES>(forceI2CScom);
            l_lastExpChip->setAttr<ATTR_SCOM_SWITCHES>(forceI2CScom);

            // Loop through table for first and last OCMB targets
            for( uint32_t l_num=0; l_num < g_expscomAddrTableSz; l_num++)
            {
                // Read the test entry info from the global table at the top of this file
                testExpscomAddrData l_testEntry = g_expscomAddrTable[l_num];

                if(l_testEntry.addr & mss::exp::i2c::IBM_SCOM_INDICATOR)
                {
                  // If this is an IBM address then we expect 64 bits of data
                  l_scom_buffer.insert<0,64,0,uint64_t>(l_testEntry.data);
                }
                else
                {
                  // Otherwise we know this is a native OCMB address and it is only 32 bits
                  l_scom_buffer.insert<32,32,0,uint32_t>(l_testEntry.data);
                }
                l_err = deviceWrite(l_firstExpChip,
                                &l_scom_buffer,
                                l_scomSize,
                                DEVICE_SCOM_ADDRESS( l_testEntry.addr));
                l_tests++;
                if(l_err)
                {
                  FAIL_TEST_ERRL(l_firstExpChip,
                            "testExpscomI2cPlatform>> Failed putScom writing 0x%016lx to 0x%08x on target w/ huid 0x%08x");

                }

                l_err = deviceWrite(l_lastExpChip,
                                  &l_scom_buffer,
                                  l_scomSize,
                                  DEVICE_SCOM_ADDRESS( l_testEntry.addr));
                l_tests++;
                if(l_err)
                {
                  FAIL_TEST_ERRL(l_firstExpChip,
                                "testExpscomI2cPlatform>> Failed putScom writing 0x%016lx to 0x%08x on target w/ huid 0x%08x");

                }
                // Flush scom buffers so it doesnt mess up next test
                l_scom_buffer.flush<0>();

                // getScom to first OCMB over i2c
                l_err = deviceRead(l_firstExpChip,
                                &l_scom_buffer(),
                                l_scomSize,
                                DEVICE_SCOM_ADDRESS( l_testEntry.addr));
                l_tests++;
                if(l_err)
                {
                  FAIL_TEST_ERRL(l_firstExpChip,
                            "testExpscomI2cPlatform>> Failed getScom reading 0x%016lx to 0x%08x on target w/ huid 0x%08x")
                }

                l_tests++;
                if(l_scom_buffer() != l_testEntry.data)
                {
                  l_fails++;
                  TS_FAIL("testExpscomI2cPlatform>> Expected 0x%016lx but got 0x%016lx on target w/ huid 0x%08x",
                        l_testEntry.data,
                        l_scom_buffer(),
                        get_huid(l_firstExpChip));
                }


                // Flush scom buffers so it doesnt mess up next test
                l_scom_buffer.flush<0>();

                // getScom to last OCMB over i2c
                l_err = deviceRead(l_lastExpChip,
                                 &l_scom_buffer(),
                                 l_scomSize,
                                 DEVICE_SCOM_ADDRESS( l_testEntry.addr));
                l_tests++;
                if(l_err)
                {
                  FAIL_TEST_ERRL(l_firstExpChip,
                                 "testExpscomI2cPlatform>> Failed getScom reading 0x%016lx to 0x%08x on target w/ huid 0x%08x")
                }

                l_tests++;
                if(l_scom_buffer() != l_testEntry.data)
                {
                  l_fails++;
                  TS_FAIL("testExpscomI2cPlatform>> Expected 0x%016lx but got 0x%016lx on target w/ huid 0x%08x",
                          l_testEntry.data,
                          l_scom_buffer(),
                          get_huid(l_firstExpChip));
                }
            }

            // Set ATTR_SCOM_SWITCHES back to their original values
            l_firstExpChip->setAttr<ATTR_SCOM_SWITCHES>(first_ocmb_info);
            l_lastExpChip->setAttr<ATTR_SCOM_SWITCHES>(last_ocmb_info);

            // << atomic section
            mutex_unlock(iv_serializeTestMutex);

        }while(0);

        TRACFCOMP( g_trac_expscom, "<< Exit  testExpscomI2cPlatform");
#endif
        return;
    }

    /**
     * @brief EXPSCOM test MMIO
     *        Write value and read back to verify MMIO scoms to OCMBs
     *        using fapi HWPs.
     */
    void testExpscomMmio(void)
    {
        TargetHandleList l_explorerList;
        uint32_t l_tests = 0;
        uint32_t l_fails = 0;
        errlHndl_t l_err = nullptr;
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
        fapi2::buffer<uint64_t> l_scom_buffer;

        TRACFCOMP(g_trac_expscom, ">> Enter  testExpscomMmio");

        do{
            if (!iv_serializeTestMutex)
            {
                TS_FAIL("iv_serializedTestMutex is not setup");
                break;
            }

            // Get the system's procs
            getAllChips( l_explorerList,
                         TYPE_OCMB_CHIP,
                         true ); // true: return functional OCMBs

            if(l_explorerList.size() == 0 )
            {
                TRACFCOMP(g_trac_expscom, "No OCMB targets found, skipping testExpscomMmio");
                break;
            }

            auto l_firstExpChip = l_explorerList.front();
            auto l_lastExpChip  = l_explorerList.back();

            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>
                                l_firstExpChip_fapi(l_firstExpChip);
            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>
                                l_lastExpChip_fapi(l_lastExpChip);

            auto first_ocmb_info =
                l_firstExpChip->getAttr<ATTR_SCOM_SWITCHES>();
            auto last_ocmb_info  =
                l_lastExpChip->getAttr<ATTR_SCOM_SWITCHES>();

            // Inband operations can't be run at the same time
            // atomic section >>
            mutex_lock(iv_serializeTestMutex);

            // Force use of MMIO
            l_firstExpChip->setAttr<ATTR_SCOM_SWITCHES>(forceMMIOScom);
            l_lastExpChip->setAttr<ATTR_SCOM_SWITCHES>(forceMMIOScom);

            // Loop through table for first and last OCMB, perform i2c write,
            // then read it back
            for( uint32_t l_num=0; l_num < g_expscomAddrTableSz; l_num++)
            {
                testExpscomAddrData l_testEntry = g_expscomAddrTable[l_num];
                if(l_testEntry.addr & mss::exp::i2c::IBM_SCOM_INDICATOR)
                {
                    l_scom_buffer.insert<0,64,0,uint64_t>(l_testEntry.data);
                }
                else
                {
                    l_scom_buffer.insert<32,32,0,uint32_t>(l_testEntry.data);
                }

                // putScom to first OCMB over mmio
                l_rc = put_scom(l_firstExpChip_fapi,
                                l_testEntry.addr,
                                l_scom_buffer);
                l_tests++;
                if(l_rc)
                {
                    l_fails++;
                    TS_FAIL("testExpscomMmio>> Failed putScom writing 0x%016lx to 0x%08x on target w/ huid 0x%08x",
                            l_testEntry.data,
                            l_testEntry.addr,
                            get_huid(l_firstExpChip));
                    l_err = fapi2::rcToErrl(l_rc);
                    errlCommit(l_err, CXXTEST_COMP_ID);
                }

                // putScom to last OCMB over mmio
                l_rc = put_scom(l_lastExpChip_fapi,
                                l_testEntry.addr,
                                l_scom_buffer);
                l_tests++;
                if(l_rc)
                {
                    l_fails++;
                    TS_FAIL("testExpscomMmio>> Failed putScom writing 0x%016lx to 0x%08x on target w/ huid 0x%08x",
                            l_testEntry.data,
                            l_testEntry.addr,
                            get_huid(l_lastExpChip));
                    l_err = fapi2::rcToErrl(l_rc);
                    errlCommit(l_err, CXXTEST_COMP_ID);
                }

                // Flush scom buffer so it doesnt mess up next test
                l_scom_buffer.flush<0>();

                // getScom to first OCMB over mmio
                l_rc = get_scom(l_firstExpChip_fapi,
                                l_testEntry.addr,
                                l_scom_buffer);
                l_tests++;
                if(l_rc)
                {
                    l_fails++;
                    TS_FAIL("testExpscomMmio>> Failed getScom reading 0x%016lx to 0x%08x on target w/ huid 0x%08x",
                            l_testEntry.data,
                            l_testEntry.addr,
                            get_huid(l_firstExpChip));
                    l_err = fapi2::rcToErrl(l_rc);
                    errlCommit(l_err, CXXTEST_COMP_ID);
                }

                l_tests++;
                if(l_scom_buffer() != l_testEntry.data)
                {
                   l_fails++;
                    TS_FAIL("testExpscomMmio>> Expected 0x%016lx but got 0x%016lx on target w/ huid 0x%08x",
                            l_testEntry.data,
                            l_scom_buffer(),
                            get_huid(l_firstExpChip));
                    l_err = fapi2::rcToErrl(l_rc);
                    errlCommit(l_err, CXXTEST_COMP_ID);
                }

                // Flush scom buffer so it doesnt mess up next test
                l_scom_buffer.flush<0>();

                // getScom to last OCMB over mmio
                l_rc = get_scom(l_lastExpChip_fapi,
                                l_testEntry.addr,
                                l_scom_buffer);
                l_tests++;
                if(l_rc)
                {
                    l_fails++;
                    TS_FAIL("testExpscomMmio>> Failed getScom reading 0x%016lx to 0x%08x on target w/ huid 0x%08x",
                            l_testEntry.data,
                            l_testEntry.addr,
                            get_huid(l_lastExpChip));
                    l_err = fapi2::rcToErrl(l_rc);
                    errlCommit(l_err, CXXTEST_COMP_ID);
                }

                l_tests++;
                if(l_scom_buffer() != l_testEntry.data)
                {
                    l_fails++;
                    TS_FAIL("testExpscomMmio>> Expected 0x%016lx but got 0x%016lx on target w/ huid 0x%08x",
                            l_testEntry.data,
                            l_scom_buffer(),
                            get_huid(l_lastExpChip));
                    l_err = fapi2::rcToErrl(l_rc);
                    errlCommit(l_err, CXXTEST_COMP_ID);
                }
            }
            // Set ATTR_SCOM_SWITCHES back to their original values
            l_firstExpChip->setAttr<ATTR_SCOM_SWITCHES>(first_ocmb_info);
            l_lastExpChip->setAttr<ATTR_SCOM_SWITCHES>(last_ocmb_info);

            // << atomic section
            mutex_unlock(iv_serializeTestMutex);
        }while(0);


        TRACFCOMP(g_trac_expscom, "<< Exit  testExpscomMmio");
        return;
    }

    /**
     * @brief EXPSCOM test MMIO
     *        Combine I2C and MMIO reads/writes to verify that we
     *        get consistent results using FAPI HWPs.
     */
    void testExpscomCombined(void)
    {
// Only MMIO scoms supported at runtime, i2c not supported
#ifndef __HOSTBOOT_RUNTIME
        TargetHandleList l_explorerList;
        uint32_t l_tests = 0;
        uint32_t l_fails = 0;
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
        fapi2::buffer<uint64_t> l_scom_buffer;

        TRACFCOMP(g_trac_expscom, ">> Enter  testExpscomCombined");

        do{
            if (!iv_serializeTestMutex)
            {
                TS_FAIL("iv_serializedTestMutex is not setup");
                break;
            }

            // Get the system's procs
            getAllChips( l_explorerList,
                         TYPE_OCMB_CHIP,
                         true ); // true: return functional OCMBs

            if(l_explorerList.size() == 0 )
            {
                TRACFCOMP(g_trac_expscom, "No OCMB targets found, skipping testExpscomCombined");
                break;
            }

            auto l_firstExpChip = l_explorerList.front();
            auto l_lastExpChip  = l_explorerList.back();

            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>
                                l_firstExpChip_fapi(l_firstExpChip);
            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>
                                l_lastExpChip_fapi(l_lastExpChip);

            auto first_ocmb_info =
                    l_firstExpChip->getAttr<ATTR_SCOM_SWITCHES>();
            auto last_ocmb_info  =
                    l_lastExpChip->getAttr<ATTR_SCOM_SWITCHES>();

            // Inband operations can't be run at the same time
            // atomic section >>
            mutex_lock(iv_serializeTestMutex);

            // Loop through table for first and last OCMB, perform i2c write,
            // then mmio read, and mmio write followed by i2c read.
            for( uint32_t l_num=0; l_num < g_expscomAddrTableSz; l_num++)
            {
                testExpscomAddrData l_testEntry = g_expscomAddrTable[l_num];

                if(l_testEntry.addr & mss::exp::i2c::IBM_SCOM_INDICATOR)
                {
                    l_scom_buffer.insert<0,64,0,uint64_t>(l_testEntry.data);
                }
                else
                {
                    l_scom_buffer.insert<32,32,0,uint32_t>(l_testEntry.data);
                }

                // ODD tests  : first target writes MMIO, last target writes I2C
                // EVEN tests : first target writes I2C, last target writes MMIO
                if(l_num % 2)
                {
                    l_firstExpChip->setAttr<ATTR_SCOM_SWITCHES>(forceMMIOScom);
                    l_lastExpChip->setAttr<ATTR_SCOM_SWITCHES>(forceI2CScom);
                }
                else
                {
                    l_firstExpChip->setAttr<ATTR_SCOM_SWITCHES>(forceI2CScom);
                    l_lastExpChip->setAttr<ATTR_SCOM_SWITCHES>(forceMMIOScom);
                }

                // putScom to first OCMB
                l_rc = put_scom(l_firstExpChip_fapi,
                                l_testEntry.addr,
                                l_scom_buffer);
                l_tests++;
                if(l_rc)
                {
                    l_fails++;
                    TS_FAIL("testExpscomCombined>> Failed putScom writing 0x%016lx to 0x%08x on target w/ huid 0x%08x",
                            l_testEntry.data,
                            l_testEntry.addr,
                            get_huid(l_firstExpChip));
                }

                // putScom to last OCMB
                l_rc = put_scom(l_lastExpChip_fapi,
                                l_testEntry.addr,
                                l_scom_buffer);
                l_tests++;
                if(l_rc)
                {
                    l_fails++;
                    TS_FAIL("testExpscomCombined>> Failed putScom writing 0x%016lx to 0x%08x on target w/ huid 0x%08x",
                            l_testEntry.data,
                            l_testEntry.addr,
                            get_huid(l_lastExpChip));
                }

                // Flush scom buffer so it doesnt mess up next test
                l_scom_buffer.flush<0>();

                // getScom to first OCMB
                l_rc = get_scom(l_firstExpChip_fapi,
                                l_testEntry.addr,
                                l_scom_buffer);
                l_tests++;
                if(l_rc)
                {
                    l_fails++;
                    TS_FAIL("testExpscomCombined>> Failed getScom reading 0x%016lx to 0x%08x on target w/ huid 0x%08x",
                            l_testEntry.data,
                            l_testEntry.addr,
                            get_huid(l_firstExpChip));
                }

                l_tests++;
                if(l_scom_buffer() != l_testEntry.data)
                {
                    l_fails++;
                    TS_FAIL("testExpscomCombined>> Expected 0x%016lx but got 0x%016lx on target w/ huid 0x%08x",
                            l_testEntry.data,
                            l_scom_buffer(),
                            get_huid(l_firstExpChip));
                }

                // ODD tests  : first target reads I2C, last target reads MMIO
                // EVEN tests : first target reads MMIO, last target reads I2C
                if(l_num % 2)
                {
                    l_firstExpChip->setAttr<ATTR_SCOM_SWITCHES>(forceI2CScom);
                    l_lastExpChip->setAttr<ATTR_SCOM_SWITCHES>(forceMMIOScom);
                }
                else
                {
                    l_firstExpChip->setAttr<ATTR_SCOM_SWITCHES>(forceMMIOScom);
                    l_lastExpChip->setAttr<ATTR_SCOM_SWITCHES>(forceI2CScom);
                }

                // Flush scom buffer so it doesnt mess up next test
                l_scom_buffer.flush<0>();

                // getScom to last OCMB
                l_rc = get_scom(l_lastExpChip_fapi,
                                l_testEntry.addr,
                                l_scom_buffer);
                l_tests++;
                if(l_rc)
                {
                    l_fails++;
                    TS_FAIL("testExpscomCombined>> Failed getScom reading 0x%016lx to 0x%08x on target w/ huid 0x%08x",
                            l_testEntry.data,
                            l_testEntry.addr,
                            get_huid(l_lastExpChip));
                }

                l_tests++;
                if(l_scom_buffer() != l_testEntry.data)
                {
                    l_fails++;
                    TS_FAIL("testExpscomCombined>> Expected 0x%016lx but got 0x%016lx on target w/ huid 0x%08x",
                            l_testEntry.data,
                            l_scom_buffer(),
                            get_huid(l_lastExpChip));
                }
            }

            // Set ATTR_SCOM_SWITCHES back to their original values
            l_firstExpChip->setAttr<ATTR_SCOM_SWITCHES>(first_ocmb_info);
            l_lastExpChip->setAttr<ATTR_SCOM_SWITCHES>(last_ocmb_info);

            // << atomic section
            mutex_unlock(iv_serializeTestMutex);
        }while(0);

        TRACFCOMP(g_trac_expscom, "<< Exit  testExpscomCombined");
#endif
        return;
    }

    /**
     * @brief EXPSCOM test SBE
     *        Combine I2C and MMIO writes to verify that we get consistent
     *        results using SBE get scom to the OCMBs
     */
    void testExpscomSbe(void)
    {
// Only MMIO scoms supported at runtime, i2c not supported
#ifndef __HOSTBOOT_RUNTIME
        TargetHandleList l_explorerList;
        uint32_t l_tests = 0;
        uint32_t l_fails = 0;
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
        fapi2::buffer<uint64_t> l_scom_buffer;

        TRACFCOMP(g_trac_expscom, ">> Enter  testExpscomSbe");

        do{
            if (!iv_serializeTestMutex)
            {
                TS_FAIL("iv_serializedTestMutex is not setup");
                break;
            }

            // Get the system's procs
            getAllChips( l_explorerList,
                         TYPE_OCMB_CHIP,
                         true ); // true: return functional OCMBs

            if(l_explorerList.size() == 0 )
            {
                TS_FAIL("No OCMB targets found, skipping testExpscomSbe");
                break;
            }

            auto l_firstExpChip = l_explorerList.front();
            auto l_lastExpChip  = l_explorerList.back();

            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>
                                l_firstExpChip_fapi(l_firstExpChip);
            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>
                                l_lastExpChip_fapi(l_lastExpChip);

            auto first_ocmb_info =
                    l_firstExpChip->getAttr<ATTR_SCOM_SWITCHES>();
            auto last_ocmb_info  =
                    l_lastExpChip->getAttr<ATTR_SCOM_SWITCHES>();

            // Inband operations can't be run at the same time
            // atomic section >>
            mutex_lock(iv_serializeTestMutex);

            // Loop through table for first and last OCMB, test writing
            // scoms with mmio and i2c and reading the value back with
            // sbe scoms
            for( uint32_t l_num=0; l_num < g_expscomAddrTableSz; l_num++)
            {
                testExpscomAddrData l_testEntry = g_expscomAddrTable[l_num];

                if(l_testEntry.addr & mss::exp::i2c::IBM_SCOM_INDICATOR)
                {
                    l_scom_buffer.insert<0,64,0,uint64_t>(l_testEntry.data);
                }
                else
                {
                    l_scom_buffer.insert<32,32,0,uint32_t>(l_testEntry.data);
                }

                // ODD tests  : first target writes MMIO, last target writes I2C
                // EVEN tests : first target writes I2C, last target writes MMIO
                if(l_num % 2)
                {
                    l_firstExpChip->setAttr<ATTR_SCOM_SWITCHES>(forceMMIOScom);
                    l_lastExpChip->setAttr<ATTR_SCOM_SWITCHES>(forceI2CScom);
                }
                else
                {
                    l_firstExpChip->setAttr<ATTR_SCOM_SWITCHES>(forceI2CScom);
                    l_lastExpChip->setAttr<ATTR_SCOM_SWITCHES>(forceMMIOScom);
                }

                // putScom to first OCMB
                l_rc = put_scom(l_firstExpChip_fapi,
                                l_testEntry.addr,
                                l_scom_buffer);
                l_tests++;
                if(l_rc)
                {
                    l_fails++;
                    TS_FAIL("testExpscomSbe>> Failed putScom writing 0x%016lx to 0x%08x on target w/ huid 0x%08x",
                            l_testEntry.data,
                            l_testEntry.addr,
                            get_huid(l_firstExpChip));
                }

                // putScom to last OCMB
                l_rc = put_scom(l_lastExpChip_fapi,
                                l_testEntry.addr,
                                l_scom_buffer);
                l_tests++;
                if(l_rc)
                {
                    l_fails++;
                    TS_FAIL("testExpscomSbe>> Failed putScom writing 0x%016lx to 0x%08x on target w/ huid 0x%08x",
                            l_testEntry.data,
                            l_testEntry.addr,
                            get_huid(l_lastExpChip));
                }

                // Always read the results back with SBE scoms
                l_firstExpChip->setAttr<ATTR_SCOM_SWITCHES>(forceSBEScom);
                l_lastExpChip->setAttr<ATTR_SCOM_SWITCHES>(forceSBEScom);


                // Flush scom buffer so it doesnt mess up next test
                l_scom_buffer.flush<0>();

                // getScom to first OCMB
                l_rc = get_scom(l_firstExpChip_fapi,
                                l_testEntry.addr,
                                l_scom_buffer);
                l_tests++;
                if(l_rc)
                {
                    l_fails++;
                    TS_FAIL("testExpscomSbe>> Failed getScom reading 0x%016lx to 0x%08x on target w/ huid 0x%08x",
                            l_testEntry.data,
                            l_testEntry.addr,
                            get_huid(l_firstExpChip));
                }

                l_tests++;
                if(l_scom_buffer() != l_testEntry.data)
                {
                    l_fails++;
                    TS_FAIL("testExpscomSbe>> Expected 0x%016lx but got 0x%016lx on target w/ huid 0x%08x",
                            l_testEntry.data,
                            l_scom_buffer(),
                            get_huid(l_firstExpChip));
                }

                // Flush scom buffer so it doesnt mess up next test
                l_scom_buffer.flush<0>();

                // getScom to last OCMB
                l_rc = get_scom(l_lastExpChip_fapi,
                                l_testEntry.addr,
                                l_scom_buffer);
                l_tests++;
                if(l_rc)
                {
                    l_fails++;
                    TS_FAIL("testExpscomSbe>> Failed getScom reading 0x%016lx to 0x%08x on target w/ huid 0x%08x",
                            l_testEntry.data,
                            l_testEntry.addr,
                            get_huid(l_lastExpChip));
                }

                l_tests++;
                if(l_scom_buffer() != l_testEntry.data)
                {
                    l_fails++;
                    TS_FAIL("testExpscomSbe>> Expected 0x%016lx but got 0x%016lx on target w/ huid 0x%08x",
                            l_testEntry.data,
                            l_scom_buffer(),
                            get_huid(l_lastExpChip));
                }
            }

            // Set ATTR_SCOM_SWITCHES back to their original values
            l_firstExpChip->setAttr<ATTR_SCOM_SWITCHES>(first_ocmb_info);
            l_lastExpChip->setAttr<ATTR_SCOM_SWITCHES>(last_ocmb_info);

            // << atomic section
            mutex_unlock(iv_serializeTestMutex);
        }while(0);

        TRACFCOMP(g_trac_expscom, "<< Exit  testExpscomCombined");
#endif
        return;
    }

    /**
     * @brief Constructor
     */
    expscomTest() : CxxTest::TestSuite()
    {
        // All modules are loaded by runtime,
        // so testcase loading of modules is not required
#ifndef __HOSTBOOT_RUNTIME
        errlHndl_t err = nullptr;

        err = exptest::loadModule(exptest::MSS_LIBRARY_NAME);
        if(err)
        {
            TS_FAIL("expscomTest() - Constuctor: failed to load MSS module");
            errlCommit( err, CXXTEST_COMP_ID );
        }
#endif
        iv_serializeTestMutex = exptest::getTestMutex();
    };


    /**
     * @brief Destructor
     */
    ~expscomTest()
    {
    };

};

#endif
