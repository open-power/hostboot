/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2ToStringTest.H $                      */
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


using namespace fapi2;


class Fapi2ToStringTest : public CxxTest::TestSuite
{
public:
//******************************************************************************
// test_fapi2ToString
//******************************************************************************
void test_fapi2ToString()
{
    int numTests = 0;
    int numFails = 0;
    do
    {
        TARGETING::Target* l_pMasterProcChip = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(l_pMasterProcChip);

        assert(l_pMasterProcChip != NULL);
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                            fapi2_procTarget(l_pMasterProcChip);

        TARGETING::ATTR_FAPI_NAME_type  tmpScomStr = {0};
        fapi2::toString(fapi2_procTarget, tmpScomStr, sizeof(tmpScomStr));
        numTests++;
        if (tmpScomStr[0] == '\0')
        {
            numFails++;
            TS_FAIL("toString failed to return data for processor chip !!");
        }
        else
        {
            numTests++;
            if (strcmp(tmpScomStr, "pu:k0:n0:s0:p00"))
            {
                numFails++;
                TS_FAIL("toString returned wrong processor chip string!!");
            }

            char smallName[5];
            fapi2::toString(fapi2_procTarget, smallName, sizeof(smallName));
            numTests++;
            if (memcmp(smallName, tmpScomStr, sizeof(smallName)-1))
            {
                numFails++;
                TS_FAIL("toString failed to fill in 5 character processor chip!!");
            }
        }
    } while(0);
    FAPI_INF("test_fapi2ToString Test Complete. %d/%d fails",  numFails , numTests);
}

void test_fapi2ToStringAll()
{
    FAPI_INF("test_fapi2ToStringAll>");
    int numTests = 0;
    int numFails = 0;

    do {
        TARGETING::Target* l_pMasterProcChip = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(l_pMasterProcChip);
        TARGETING::ATTR_MODEL_type procModel =
          l_pMasterProcChip->getAttr<TARGETING::ATTR_MODEL>();

        GENERATE_TEST_TARGETS(test_fapi2GetChildren);
        TARGETING::ATTR_FAPI_NAME_type fapiName = {0};

#define STRING_TEST(_targ) \
        fapi2::toString(_targ, fapiName, sizeof(fapiName));\
        FAPI_INF("_targ=%s",fapiName);

        STRING_TEST(fapi2_procTarget);
        STRING_TEST(fapi2_eqTarget);
        STRING_TEST(fapi2_exTarget);
        STRING_TEST(fapi2_coreTarget);
        STRING_TEST(fapi2_pecTarget);
        STRING_TEST(fapi2_phbTarget);
        STRING_TEST(fapi2_xbusTarget);
        STRING_TEST(fapi2_obusTarget);
        STRING_TEST(fapi2_oBrickTarget);
        STRING_TEST(fapi2_ppeTarget);
        STRING_TEST(fapi2_pervTarget);
        STRING_TEST(fapi2_sbeTarget);
        STRING_TEST(fapi2_cappTarget);

        if( procModel == TARGETING::MODEL_NIMBUS )
        {
            STRING_TEST(fapi2_mcsTarget);
            STRING_TEST(fapi2_mcaTarget);
            STRING_TEST(fapi2_mcbistTarget);
        }

        if( procModel == TARGETING::MODEL_CUMULUS )
        {
            STRING_TEST(fapi2_mcTarget);
            STRING_TEST(fapi2_miTarget);
            STRING_TEST(fapi2_dmiTarget);
        }

        if( procModel == TARGETING::MODEL_AXONE )
        {
            STRING_TEST(fapi2_mcTarget);
            STRING_TEST(fapi2_miTarget);
            STRING_TEST(fapi2_omiTarget);
            STRING_TEST(fapi2_omic0Target);
            STRING_TEST(fapi2_omic2Target);
            STRING_TEST(fapi2_mccTarget);
            STRING_TEST(fapi2_ocmbTarget);
            STRING_TEST(fapi2_memportTarget);
        }
    } while(0);

    FAPI_INF("test_fapi2ToStringAll:: Test Complete. %d/%d fails",  numFails , numTests);

}


};

