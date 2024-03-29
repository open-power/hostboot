/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2HwpTest.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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

#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <fapi2.H>
#include <hwpf_fapi2_reasoncodes.H>
#include <fapi2TestUtils.H>
#include <p10_sample_procedure.H>
#include <plat_hwp_invoker.H>

using namespace fapi2;

class Fapi2HwpTest : public CxxTest::TestSuite
{
public:
//******************************************************************************
// test_fapi2Hwp
//******************************************************************************
void test_fapi2Hwp()
{
    int numTests = 0;
    int numFails = 0;
    errlHndl_t l_errl = nullptr;

    do
    {
        GENERATE_TEST_TARGETS(test_fapi2GetChildren)

        // scratch value to use in following tests
        int scratchWriteValue = 5;

        #define HWP_TEST_COMMON_MACRO(PROCEDURE_NAME, FAPI2_TARGET)                             \
        /*Get/Set Attr for all of the targets*/                                                 \
        numTests++;                                                                             \
        FAPI_INVOKE_HWP(l_errl, PROCEDURE_NAME, FAPI2_TARGET, scratchWriteValue);               \
        if(l_errl != nullptr)                                                                   \
        {                                                                                       \
            delete l_errl;                                                                      \
            l_errl = nullptr;                                                                   \
            numFails++;                                                                         \
            TS_FAIL("Error occured in " #PROCEDURE_NAME "!!");                                  \
        }                                                                                       \

        #define HWP_TEST_MODEL_SPECIFIC_MACRO(PROCEDURE_NAME, FAPI2_TARGET, TEST_TARGET)        \
        if (isHwValid(l_proc, TEST_TARGET))                                                     \
        {                                                                                       \
            HWP_TEST_COMMON_MACRO(PROCEDURE_NAME, FAPI2_TARGET)                                 \
        }                                                                                       \

        // Common for all P10 Models
        HWP_TEST_COMMON_MACRO(p10_sample_procedure_proc, fapi2_procTarget)
        HWP_TEST_COMMON_MACRO(p10_sample_procedure_eq, fapi2_eqTarget)
        HWP_TEST_COMMON_MACRO(p10_sample_procedure_core, fapi2_coreTarget)
        HWP_TEST_COMMON_MACRO(p10_sample_procedure_pec, fapi2_pecTarget)
        HWP_TEST_COMMON_MACRO(p10_sample_procedure_phb, fapi2_phbTarget)
        HWP_TEST_COMMON_MACRO(p10_sample_procedure_perv, fapi2_pervTarget)
        HWP_TEST_MODEL_SPECIFIC_MACRO(p10_sample_procedure_mc, fapi2_mcTarget, MY_MC)
        HWP_TEST_MODEL_SPECIFIC_MACRO(p10_sample_procedure_mi, fapi2_miTarget, MY_MI)
        HWP_TEST_MODEL_SPECIFIC_MACRO(p10_sample_procedure_omi, fapi2_omiTarget, MY_OMI)
        HWP_TEST_MODEL_SPECIFIC_MACRO(p10_sample_procedure_omic, fapi2_omic0Target, MY_OMIC0)
        HWP_TEST_MODEL_SPECIFIC_MACRO(p10_sample_procedure_omic, fapi2_omic1Target, MY_OMIC1)
        HWP_TEST_MODEL_SPECIFIC_MACRO(p10_sample_procedure_mcc, fapi2_mccTarget, MY_MCC)
        HWP_TEST_MODEL_SPECIFIC_MACRO(p10_sample_procedure_ocmb, fapi2_ocmbTarget, MY_OCMB)
        HWP_TEST_MODEL_SPECIFIC_MACRO(p10_sample_procedure_mem_port, fapi2_memportTarget, MY_MEM_PORT)

    }while(0);
    FAPI_INF("test_fapiHWP:: Test Complete. %d/%d fails",  numFails,numTests);
}

};
