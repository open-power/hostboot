/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/common/test/hwasCalloutTest.H $                  */
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
/**
*  @file hwasCalloutTest.H
*
*  @brief Test cases for Callout functions
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <errl/errlreasoncodes.H>
#include <hwas/common/hwasCommon.H>
#include <hwas/common/hwasCallout.H>

using namespace TARGETING;

class hwasCalloutTest: public CxxTest::TestSuite
{
    public:
        /**
        * @brief calls processCallout() with different Callout Types to ensure there are no
        *        errors along with corresponding Platform specific functions that handle
        *        each type
        */
        void test_processCallout ( void ) {
            TS_INFO(ENTER_MRK"test_processCallout - Start");

            //Create error log with random data
            uint64_t l_userData1 = 0x1;
            uint64_t l_userData2 = 0x2;
            //Set severity to be used in HW_CALLOUT and CLOCK_CALLOUT cases
            errlHndl_t l_err = hwasError(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                         ERRORLOG::ERRL_RT_TEST_MOD_ID,
                                         ERRORLOG::ERRL_TEST_REASON_CODE,
                                         l_userData1,
                                         l_userData2);
            errlHndl_t l_originalErr = l_err;

            uint64_t l_size = sizeof(callout_ud) + 2*sizeof(TARGET_IS_SENTINEL);
            uint8_t l_buffer[l_size] = {0};

            //Create pointer to callout data
            uint8_t* l_pData = reinterpret_cast<uint8_t*>(&l_buffer);
            callout_ud_t *l_calloutData = reinterpret_cast<callout_ud_t*>(l_pData);

            //Add TARGET_IS_SENTINEL token following callout data
            uint8_t* l_pData2 = reinterpret_cast<uint8_t*>(l_calloutData + 1);
            memcpy(l_pData2, &TARGET_IS_SENTINEL, sizeof(TARGET_IS_SENTINEL));
            //BUS_CALLOUT case requires two Targets - Add token twice
            l_pData2 += sizeof(TARGET_IS_SENTINEL);
            memcpy(l_pData2, &TARGET_IS_SENTINEL, sizeof(TARGET_IS_SENTINEL));

            //Set callout Data
            l_calloutData->priority = SRCI_PRIORITY_NONE;
            l_calloutData->deconfigState = NO_DECONFIG;
            l_calloutData->gardErrorType = GARD_Void;

            //BUS_CALLOUT
            l_calloutData->type = BUS_CALLOUT;
            TS_INFO("test_processCallout - BUS_CALLOUT case");
            processCallout(l_err, l_pData, l_size, false);
            if(l_err != l_originalErr) {
                TS_FAIL("test_processCallout - processCallout() with callout type BUS_CALLOUT "
                        "should not change l_err");
                errlCommit( l_err, CXXTEST_COMP_ID );
                l_err = l_originalErr;
            }

            //PART_CALLOUT
            l_calloutData->type = PART_CALLOUT;
            //reset pointer
            l_pData = reinterpret_cast<uint8_t*>(&l_buffer);
            TS_INFO("test_processCallout - PART_CALLOUT case");
            processCallout(l_err, l_pData, l_size, false);
            if(l_err != l_originalErr) {
                TS_FAIL("test_processCallout - processCallout() with callout type PART_CALLOUT "
                        "should not change l_err");
                errlCommit( l_err, CXXTEST_COMP_ID );
                l_err = l_originalErr;
            }

            //I2C_DEVICE_CALLOUT
            l_calloutData->type = I2C_DEVICE_CALLOUT;
            //reset pointer
            l_pData = reinterpret_cast<uint8_t*>(&l_buffer);
            TS_INFO("test_processCallout - I2C_DEVICE_CALLOUT case");
            processCallout(l_err, l_pData, l_size, false);
            if(l_err != l_originalErr) {
                TS_FAIL("test_processCallout - processCallout() with callout type I2C_DEVICE_CALLOUT "
                        "should not change l_err");
                errlCommit( l_err, CXXTEST_COMP_ID );
                l_err = l_originalErr;
            }

            // Unsupported Type
            l_calloutData->type = SENSOR_CALLOUT;
            //reset pointer
            l_pData = reinterpret_cast<uint8_t*>(&l_buffer);
            TS_INFO("test_processCallout - Unsupported type");
            processCallout(l_err, l_pData, l_size, false);
            if(l_err != l_originalErr) {
                TS_FAIL("test_processCallout - processCallout() with Unsupported callout type "
                        "should not change l_err");
                errlCommit( l_err, CXXTEST_COMP_ID );
                l_err = l_originalErr;
            }

            //HW_CALLOUT
            l_calloutData->type = HW_CALLOUT;
            //reset pointer
            l_pData = reinterpret_cast<uint8_t*>(&l_buffer);
            TS_INFO("test_processCallout - HW_CALLOUT case");
            processCallout(l_err, l_pData, l_size, false);
            if (l_err != l_originalErr) {
                TS_FAIL("test_processCallout - processCallout() with callout type HW_CALLOUT "
                        "should not change l_err");
                errlCommit( l_err, CXXTEST_COMP_ID );
                l_err = l_originalErr;
            }

            //CLOCK_CALLOUT
            l_calloutData->type = CLOCK_CALLOUT;
            l_calloutData->clockType = TODCLK_TYPE;
            l_calloutData->clkDeconfigState = NO_DECONFIG;
            l_calloutData->clkGardErrorType = GARD_Void;

            //reset pointer
            l_pData = reinterpret_cast<uint8_t*>(&l_buffer);
            TS_INFO("test_processCallout - CLOCK_CALLOUT case");
            processCallout(l_err, l_pData, l_size, false);

            if (l_err != l_originalErr) {
                TS_FAIL("test_processCallout - processCallout() with callout type CLOCK_CALLOUT "
                        "should not change l_err");
                errlCommit( l_err, CXXTEST_COMP_ID );
                l_err = l_originalErr;

            }

            delete l_err;
            l_err = nullptr;

            TS_INFO(EXIT_MRK"test_processCallout - End");
        }

};
