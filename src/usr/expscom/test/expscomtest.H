/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expscom/test/expscomtest.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2019                        */
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

extern trace_desc_t* g_trac_expscom;

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
        {0x501C,     0x00000000DEADBEEF},
        {0x209004,   0x00000000C0DEDEAD},
        {0x8010002,  0xDEADC0DEC0DEBEEF}
};
const uint32_t g_expscomAddrTableSz =
                    sizeof(g_expscomAddrTable)/sizeof(testExpscomAddrData);


const ScomSwitches forceI2CScom = {.useFsiScom = 0, .useXscom = 0,
                                   .useInbandScom = 0, .useSbeScom = 0,
                                   .useI2cScom = 1};

const ScomSwitches forceMMIOScom = {.useFsiScom = 0, .useXscom = 0,
                                   .useInbandScom = 1, .useSbeScom = 0,
                                   .useI2cScom = 0};

#define FAIL_TEST_RC(TARGET, STRING) \
l_fails++; \
TS_FAIL(STRING , \
        l_testEntry.data, \
        l_testEntry.addr, \
        get_huid(TARGET)); \
l_err = fapi2::rcToErrl(l_rc); \
errlCommit(l_err, 0x10);

#define FAIL_TEST_ERRL(TARGET, STRING) \
l_fails++; \
TS_FAIL(STRING , \
        l_testEntry.data, \
        l_testEntry.addr, \
        get_huid(TARGET)); \
errlCommit(l_err, 0x10);

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

public:

    /**
    * @brief EXPSCOM test I2C Path
    *        Write value and read back to verify i2c scoms to OCMBs
    */
    void testExpscomI2c(void)
    {
        TRACFCOMP( g_trac_expscom, ">> Enter  testExpscomI2c");
        // Keep trace of pass/fails
        uint32_t l_tests = 0;
        uint32_t l_fails = 0;
        errlHndl_t l_err = nullptr;

        // Fapi interfaces will be used in these tests so this variable
        // will be used to hold error from fapi calls
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
        fapi2::buffer<uint64_t> l_scom_buffer;
        TargetHandleList l_explorerList;

        do{
// Causing a data storage exception in c_str...
#ifdef CONFIG_AXONE_BRING_UP
TRACFCOMP( g_trac_expscom,"skipping testExpscomI2c");
break;
#endif
            // Get the system's OCMB chips, we will use these as test targets
            getAllChips( l_explorerList,
                          TYPE_OCMB_CHIP,
                          true ); // true: return functional OCMBs

            if(l_explorerList.size() == 0 )
            {
                TRACFCOMP( g_trac_expscom, "No OCMB targets found, skipping testExpscomI2c");
                break;
            }


            // We will use the first and last targets for these scom tests
            auto l_firstExpChip = l_explorerList.front();
            auto l_lastExpChip  = l_explorerList.back();

            // Cast the TARGETING::Targets into fapi2::Targets
            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_firstExpChip_fapi(l_firstExpChip);
            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_lastExpChip_fapi(l_lastExpChip);

            // Save away original scom switch info so we can restore it at the end of the test
            auto first_ocmb_info = l_firstExpChip->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();
            auto last_ocmb_info  = l_lastExpChip->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();

            // This goal of this tests is to make sure I2C scom to OCMB is working so force
            // scom to go over I2C path for these targets
            l_firstExpChip->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(forceI2CScom);
            l_lastExpChip->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(forceI2CScom);

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
                                "testExpscomI2c>> Failed putScom writing 0x%.16X to 0x%.8X on target w/ huid 0x%.8X");

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
                              "testExpscomI2c>> Failed putScom writing 0x%.16X to 0x%.8X on target w/ huid 0x%.8X");
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
                                "testExpscomI2c>> Failed getScom reading 0x%.16X to 0x%.8X on target w/ huid 0x%.8X")
                }

                l_tests++;
                if(l_scom_buffer() != l_testEntry.data)
                {
                    l_fails++;
                    TS_FAIL("testExpscomI2c>> Expected 0x%.16X but got 0x%.16X on target w/ huid 0x%.8X",
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
                                "testExpscomI2c>> Failed getScom reading 0x%.16X to 0x%.8X on target w/ huid 0x%.8X")
                }

                l_tests++;
                if(l_scom_buffer() != l_testEntry.data)
                {
                    l_fails++;
                    TS_FAIL("testExpscomI2c>> Expected 0x%.16X but got 0x%.16X on target w/ huid 0x%.8X",
                            l_testEntry.data,
                            l_scom_buffer(),
                            get_huid(l_lastExpChip));
                }
            }

            // Set ATTR_SCOM_SWITCHES back to their original values
            l_firstExpChip->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(first_ocmb_info);
            l_lastExpChip->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(last_ocmb_info);
        }while(0);

        TRACFCOMP( g_trac_expscom, "<< Exit  testExpscomI2c");
        return;
    }

    void testExpscomI2cPlatform(void)
    {

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
// Causing a data storage exception in c_str...
#ifdef CONFIG_AXONE_BRING_UP
TRACFCOMP( g_trac_expscom,"skipping testExpscomI2cPlatformPlatform");
break;
#endif

            getAllChips( l_explorerList,
                          TYPE_OCMB_CHIP,
                          true ); // true: return functional OCMBs


            if(l_explorerList.size() == 0 )
            {
                TRACFCOMP( g_trac_expscom, "No OCMB targets found, skipping testExpscomI2cPlatformPlatform");
                break;
            }

            // We will use the first and last targets for these scom tests
            auto l_firstExpChip = l_explorerList.front();
            auto l_lastExpChip  = l_explorerList.back();

            // Save away original scom switch info so we can restore it at the end of the test
            auto first_ocmb_info = l_firstExpChip->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();
            auto last_ocmb_info  = l_lastExpChip->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();

            // This goal of this tests is to make sure I2C scom to OCMB is working so force
            // scom to go over I2C path for these targets
            l_firstExpChip->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(forceI2CScom);
            l_lastExpChip->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(forceI2CScom);

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
                                "testExpscomI2cPlatform>> Failed putScom writing 0x%.16X to 0x%.8X on target w/ huid 0x%.8X");

                  }

                  l_err = deviceWrite(l_lastExpChip,
                                      &l_scom_buffer,
                                      l_scomSize,
                                      DEVICE_SCOM_ADDRESS( l_testEntry.addr));
                  l_tests++;
                  if(l_err)
                  {
                      FAIL_TEST_ERRL(l_firstExpChip,
                                    "testExpscomI2cPlatform>> Failed putScom writing 0x%.16X to 0x%.8X on target w/ huid 0x%.8X");

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
                                "testExpscomI2cPlatform>> Failed getScom reading 0x%.16X to 0x%.8X on target w/ huid 0x%.8X")
                  }

                  l_tests++;
                  if(l_scom_buffer() != l_testEntry.data)
                  {
                      l_fails++;
                      TS_FAIL("testExpscomI2cPlatform>> Expected 0x%.16X but got 0x%.16X on target w/ huid 0x%.8X",
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
                                     "testExpscomI2cPlatform>> Failed getScom reading 0x%.16X to 0x%.8X on target w/ huid 0x%.8X")
                  }

                  l_tests++;
                  if(l_scom_buffer() != l_testEntry.data)
                  {
                      l_fails++;
                      TS_FAIL("testExpscomI2cPlatform>> Expected 0x%.16X but got 0x%.16X on target w/ huid 0x%.8X",
                              l_testEntry.data,
                              l_scom_buffer(),
                              get_huid(l_firstExpChip));
                  }
            }

            // Set ATTR_SCOM_SWITCHES back to their original values
            l_firstExpChip->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(first_ocmb_info);
            l_lastExpChip->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(last_ocmb_info);
        }while(0);

        TRACFCOMP( g_trac_expscom, "<< Exit  testExpscomI2cPlatform");
        return;
    }

// TODO RTC: 189447 Enable MMIO tests when MMIO drivers avail
     /**
     * @brief EXPSCOM test MMIO
     *        Write value and read back to verify MMIO scoms to OCMBs
     */
//     void testExpscomMmio(void)
//     {
//         TargetHandleList l_explorerList;
//         uint32_t l_tests = 0;
//         uint32_t l_fails = 0;
//         errlHndl_t l_err = nullptr;
//         fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
//         fapi2::buffer<uint64_t> l_scom_buffer;
//
//         // Get the system's procs
//         getAllChips( l_explorerList,
//                      TYPE_OCMB_CHIP,
//                      true ); // true: return functional OCMBs
//
//         auto l_firstExpChip = l_explorerList.front();
//         auto l_lastExpChip  = l_explorerList.back();
//
//         fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_firstExpChip_fapi(l_firstExpChip);
//         fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_lastExpChip_fapi(l_lastExpChip);
//
//         auto first_ocmb_info = l_firstExpChip->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();
//         auto last_ocmb_info  = l_lastExpChip->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();
//
//
//         // Loop through table for first and last OCMB, perform i2c write, then
//         // mmio read, and mmio write followed by i2c read.
//         for( uint32_t l_num=0; l_num < g_expscomAddrTableSz; l_num++)
//         {
//               testExpscomAddrData l_testEntry = g_expscomAddrTable[l_num];
//               if(l_testEntry.addr & mss::exp::i2c::IBM_SCOM_INDICATOR)
//               {
//                   l_scom_buffer.insert<0,64,0,uint64_t>(l_testEntry.data);
//               }
//               else
//               {
//                   l_scom_buffer.insert<0,32,0,uint32_t>(l_testEntry.data);
//               }
//
//              // putScom to first OCMB over mmio
//              l_rc = put_scom(l_firstExpChip_fapi,
//                                    l_testEntry.addr,
//                                    l_scom_buffer);
//              l_tests++;
//              if(l_rc)
//              {
//                 l_fails++;
//                 TS_FAIL("testExpscomMmio>> Failed putScom writing 0x%.16X to 0x%.8X on target w/ huid 0x%.8X",
//                         l_testEntry.data,
//                         l_testEntry.addr,
//                         get_huid(l_firstExpChip));
//                 l_err = fapi2::rcToErrl(l_rc);
//                 errlCommit(l_err, 0x10);
//              }
//
//              // putScom to last OCMB over mmio
//              l_rc = put_scom(l_lastExpChip_fapi,
//                                    l_testEntry.addr,
//                                    l_scom_buffer);
//              l_tests++;
//              if(l_rc)
//              {
//                 l_fails++;
//                 TS_FAIL("testExpscomMmio>> Failed putScom writing 0x%.16X to 0x%.8X on target w/ huid 0x%.8X",
//                         l_testEntry.data,
//                         l_testEntry.addr,
//                         get_huid(l_lastExpChip));
//                 l_err = fapi2::rcToErrl(l_rc);
//                 errlCommit(l_err, 0x10);
//              }
//
//              // Flush scom buffer so it doesnt mess up next test
//              l_scom_buffer.flush<0>();
//
//
//              // getScom to first OCMB over mmio
//              l_rc = get_scom(l_firstExpChip_fapi,
//                                    l_testEntry.addr,
//                                    l_scom_buffer);
//              l_tests++;
//              if(l_rc)
//              {
//                 l_fails++;
//                 TS_FAIL("testExpscomMmio>> Failed getScom reading 0x%.16X to 0x%.8X on target w/ huid 0x%.8X",
//                         l_testEntry.data,
//                         l_testEntry.addr,
//                         get_huid(l_firstExpChip));
//                 l_err = fapi2::rcToErrl(l_rc);
//                 errlCommit(l_err, 0x10);
//              }
//
//              l_tests++;
//              if(l_scom_buffer() != l_testEntry.data)
//              {
//                l_fails++;
//                 TS_FAIL("testExpscomMmio>> Expected 0x%.16X but got 0x%.16X on target w/ huid 0x%.8X",
//                         l_testEntry.data,
//                         l_scom_buffer(),
//                         get_huid(l_firstExpChip));
//                 l_err = fapi2::rcToErrl(l_rc);
//                 errlCommit(l_err, 0x10);
//              }
//
//              // Flush scom buffer so it doesnt mess up next test
//              l_scom_buffer.flush<0>();
//
//              // getScom to last OCMB over mmio
//              l_rc = get_scom(l_lastExpChip_fapi,
//                                    l_testEntry.addr,
//                                    l_scom_buffer);
//              l_tests++;
//              if(l_rc)
//              {
//                 l_fails++;
//                 TS_FAIL("testExpscomMmio>> Failed getScom reading 0x%.16X to 0x%.8X on target w/ huid 0x%.8X",
//                         l_testEntry.data,
//                         l_testEntry.addr,
//                         get_huid(l_lastExpChip));
//                 l_err = fapi2::rcToErrl(l_rc);
//                 errlCommit(l_err, 0x10);
//              }
//
//              l_tests++;
//              if(l_scom_buffer() != l_testEntry.data)
//              {
//                l_fails++;
//                 TS_FAIL("testExpscomMmio>> Expected 0x%.16X but got 0x%.16X on target w/ huid 0x%.8X",
//                         l_testEntry.data,
//                         l_scom_buffer(),
//                         get_huid(l_lastExpChip));
//                 l_err = fapi2::rcToErrl(l_rc);
//                 errlCommit(l_err, 0x10);
//              }
//         }
//         // Set ATTR_SCOM_SWITCHES back to their original values
//         l_firstExpChip->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(first_ocmb_info);
//         l_lastExpChip->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(last_ocmb_info);
//         return;
//   }

      /**
    * @brief EXPSCOM test MMIO
    *        Write value and read back to verify MMIO
    */
//   void testExpscomCombined(void)
//   {
//         TargetHandleList l_explorerList;
//         uint32_t l_tests = 0;
//         uint32_t l_fails = 0;
//         fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
//         fapi2::buffer<uint64_t> l_scom_buffer;
//
//         // Get the system's procs
//         getAllChips( l_explorerList,
//                      TYPE_OCMB_CHIP,
//                      true ); // true: return functional OCMBs
//
//         auto l_firstExpChip = l_explorerList.front();
//         auto l_lastExpChip  = l_explorerList.back();
//
//         fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_firstExpChip_fapi(l_firstExpChip);
//         fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_lastExpChip_fapi(l_lastExpChip);
//
//        auto first_ocmb_info = l_firstExpChip->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();
//         auto last_ocmb_info  = l_lastExpChip->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();
//
//         // Loop through table for first and last OCMB
//         for( uint32_t l_num=0; l_num < g_expscomAddrTableSz; l_num++)
//         {
//              testExpscomAddrData l_testEntry = g_expscomAddrTable[l_num];
//
//               if(l_testEntry.addr & mss::exp::i2c::IBM_SCOM_INDICATOR)
//               {
//                   l_scom_buffer.insert<0,64,0,uint64_t>(l_testEntry.data);
//               }
//               else
//               {
//                   l_scom_buffer.insert<0,32,0,uint32_t>(l_testEntry.data);
//               }
//
//             // ODD tests  : first target writes MMIO, last target writes I2C
//             // EVEN tests : first target writes I2C, last target writes MMIO
//             if(l_num % 2)
//             {
//                 l_firstExpChip->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(forceMMIOScom);
//                 l_lastExpChip->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(forceI2CScom);
//             }
//             else
//             {
//                 l_firstExpChip->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(forceI2CScom);
//                 l_lastExpChip->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(forceMMIOScom);
//             }
//
//              // putScom to first OCMB over mmio
//              l_rc = put_scom(l_firstExpChip_fapi,
//                                    l_testEntry.addr,
//                                    l_scom_buffer);
//              l_tests++;
//              if(l_rc)
//              {
//                 l_fails++;
//                 TS_FAIL("testExpscomMmio>> Failed putScom writing 0x%.16X to 0x%.8X on target w/ huid 0x%.8X",
//                         l_testEntry.data,
//                         l_testEntry.addr,
//                         get_huid(l_firstExpChip));
//              }
//
//              // putScom to last OCMB over mmio
//              l_rc = put_scom(l_lastExpChip_fapi,
//                                    l_testEntry.addr,
//                                    l_scom_buffer);
//              l_tests++;
//              if(l_rc)
//              {
//                 l_fails++;
//                 TS_FAIL("testExpscomMmio>> Failed putScom writing 0x%.16X to 0x%.8X on target w/ huid 0x%.8X",
//                         l_testEntry.data,
//                         l_testEntry.addr,
//                         get_huid(l_lastExpChip));
//              }
//
//              // Flush scom buffer so it doesnt mess up next test
//              l_scom_buffer.flush<0>();
//
//              // getScom to first OCMB over mmio
//              l_rc = get_scom(l_firstExpChip_fapi,
//                                    l_testEntry.addr,
//                                    l_scom_buffer);
//              l_tests++;
//              if(l_rc)
//              {
//                 l_fails++;
//                 TS_FAIL("testExpscomMmio>> Failed getScom reading 0x%.16X to 0x%.8X on target w/ huid 0x%.8X",
//                         l_testEntry.data,
//                         l_testEntry.addr,
//                         get_huid(l_firstExpChip));
//              }
//
//              l_tests++;
//              if(l_scom_buffer() != l_testEntry.data)
//              {
//                l_fails++;
//                 TS_FAIL("testExpscomMmio>> Expected 0x%.16X but got 0x%.16X on target w/ huid 0x%.8X",
//                         l_testEntry.data,
//                         l_scom_buffer(),
//                         get_huid(l_firstExpChip));
//              }
//
//             // ODD tests  : first target reads I2C, last target reads MMIO
//             // EVEN tests : first target reads MMIO, last target reads I2C
//             if(l_num % 2)
//             {
//                 l_firstExpChip->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(forceI2CScom);
//                 l_lastExpChip->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(forceMMIOScom);
//             }
//             else
//             {
//                 l_firstExpChip->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(forceMMIOScom);
//                 l_lastExpChip->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(forceI2CScom);
//             }
//
//              // Flush scom buffer so it doesnt mess up next test
//              l_scom_buffer.flush<0>();
//
//              // getScom to last OCMB over mmio
//              l_rc = get_scom(l_lastExpChip_fapi,
//                                    l_testEntry.addr,
//                                    l_scom_buffer);
//              l_tests++;
//              if(l_rc)
//              {
//                 l_fails++;
//                 TS_FAIL("testExpscomMmio>> Failed getScom reading 0x%.16X to 0x%.8X on target w/ huid 0x%.8X",
//                         l_testEntry.data,
//                         l_testEntry.addr,
//                         get_huid(l_lastExpChip));
//              }
//
//              l_tests++;
//              if(l_scom_buffer() != l_testEntry.data)
//              {
//                l_fails++;
//                 TS_FAIL("testExpscomMmio>> Expected 0x%.16X but got 0x%.16X on target w/ huid 0x%.8X",
//                         l_testEntry.data,
//                         l_scom_buffer(),
//                         get_huid(l_lastExpChip));
//              }
//         }
//         // Set ATTR_SCOM_SWITCHES back to their original values
//         l_firstExpChip->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(first_ocmb_info);
//         l_lastExpChip->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(last_ocmb_info);
//         return;
//   }


};

#endif
