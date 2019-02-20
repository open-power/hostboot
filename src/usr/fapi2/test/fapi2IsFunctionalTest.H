/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2IsFunctionalTest.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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

#include <fapi2.H>
#include <commontargeting.H>
#include <cxxtest/TestSuite.H>
#include "fapi2TestUtils.H"


namespace fapi2
{

class Fapi2IsFunctional : public CxxTest::TestSuite
{

    public:
    //**************************************************************************
    // test_fapi2IsFunctional
    //**************************************************************************
    void test_fapi2IsFunctional()
    {

        TARGETING::HwasState currentState;
        bool functional;
        int numTests = 0;
        int numFails = 0;
        FAPI_DBG("Enter test_fapi2IsFunctional");
        do
        {
            GENERATE_TEST_TARGETS(test_fapi2GetChildren)

            #define IS_FUNCTIONAL_TEST_MACRO(TARGETING_TARGET, FAPI2_TARGET)                \
                if(TARGETING_TARGET != nullptr)                                             \
                {                                                                           \
                    numTests++;                                                             \
                    /* get the HWAS_STATE of the current target */                          \
                    currentState = TARGETING_TARGET->getAttr<TARGETING::ATTR_HWAS_STATE>(); \
                    functional = FAPI2_TARGET.isFunctional();                               \
                    if(currentState.functional != functional)                               \
                    {                                                                       \
                        TS_FAIL("The functional state is incorrect. huid: 0x%x - "          \
                        "Functional State (Expected/Actual): (%d/%d)",                      \
                                TARGETING::get_huid(TARGETING_TARGET),                      \
                                currentState.functional,                                    \
                                functional);                                                \
                                numFails++;                                                 \
                    }                                                                       \
                }                                                                           \

            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_EQ], fapi2_eqTarget)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_EX], fapi2_exTarget)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_CORE], fapi2_coreTarget)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_MCS], fapi2_mcsTarget)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_MCBIST], fapi2_mcbistTarget)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_MCA], fapi2_mcaTarget)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_PEC], fapi2_pecTarget)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_PHB], fapi2_phbTarget)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_XBUS], fapi2_xbusTarget)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_OBUS], fapi2_obusTarget)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_OBUS_BRICK], fapi2_oBrickTarget)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_PPE], fapi2_ppeTarget)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_PERV], fapi2_pervTarget)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_SBE], fapi2_sbeTarget)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_CAPP], fapi2_cappTarget)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_MC], fapi2_mcTarget)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_MI], fapi2_miTarget)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_DMI], fapi2_dmiTarget)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_OMI], fapi2_omiTarget)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_OMIC0], fapi2_omic0Target)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_OMIC2], fapi2_omic2Target)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_MCC], fapi2_mccTarget)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_PROC], fapi2_procTarget)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_OCMB], fapi2_ocmbTarget)
            IS_FUNCTIONAL_TEST_MACRO(targeting_targets[MY_MEM_PORT], fapi2_memportTarget)


        } while(0);
        FAPI_INF("test_fapi2IsFunctional Test Complete. %d/%d fails",
                  numFails,
                  numTests);
    } // end test_fapi2IsFunctional()

}; // end class

}// end namespace fapi2

