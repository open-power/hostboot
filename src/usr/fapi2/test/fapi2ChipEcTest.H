/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2ChipEcTest.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

//--------------------------------------------------------------------------
/// @file  fapi2ChipEcTest.H
///
/// @brief Validate the chip/ec function support
//--------------------------------------------------------------------------

namespace fapi2
{

class Fapi2ChipEcTest : public CxxTest::TestSuite
{

  public:

    // Simple test to validate ATTR_CHIP_EC_FEATURE_TEST1
    void  test_fapi2ChipEc_1()
    {
        fapi2::ReturnCode l_rc;


        FAPI_INF("fapi2ChipEc_1 Test starting ... ");

        TARGETING::TargetHandleList l_chipList;
        TARGETING::getAllChips(l_chipList, TARGETING::TYPE_PROC, false);

        fapi2::Target<TARGET_TYPE_PROC_CHIP> l_fapi2_procTarget(
                                                              l_chipList[0]);

        ATTR_CHIP_EC_FEATURE_TEST1_Type l_valChipEcTest1 = 0;

        FAPI_TRY(FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_TEST1,
                               l_fapi2_procTarget, l_valChipEcTest1));
        // Returns if a chip contains the TEST1 feature. True if either:
        //  Centaur EC 1.0
        //  Cumulus EC greater than 3.0
        if(l_valChipEcTest1)
        {
            TS_FAIL("Fail: this proc is not cumulus and/or greater then DD3.0");
        }
        else
        {
            FAPI_INF("Pass: This proc is not cumulus and/or not greater then DD3.0");
        }

        fapi_try_exit:
        if(fapi2::current_err)
        {
            TS_FAIL("FAPI_TRY of attribute read failed! rc=0x%.8X",(uint32_t)fapi2::current_err);
        }
        return;

    }

    // Simple test to validate ATTR_CHIP_EC_FEATURE_TEST2
    void  test_fapi2ChipEc_2()
    {
        fapi2::ReturnCode l_rc;

        FAPI_INF("fapi2ChipEc_2 Test starting ... ");

        TARGETING::TargetHandleList l_chipList;
        TARGETING::getAllChips(l_chipList, TARGETING::TYPE_PROC, false);

        fapi2::Target<TARGET_TYPE_PROC_CHIP> l_fapi2_procTarget(
                                                              l_chipList[0]);

        ATTR_CHIP_EC_FEATURE_TEST2_Type l_valChipEcTest2 = 0;

        FAPI_TRY(FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_TEST2,
                               l_fapi2_procTarget, l_valChipEcTest2));

        // Tests if a chip contains the TEST2 feature.
        // True if: Nimbus EC less than 2.0
        if(TARGETING::MODEL_NIMBUS !=
                l_chipList[0]->getAttr<TARGETING::ATTR_MODEL>())
        {
            FAPI_INF("Pass: This proc is not Nimbus so does not have TEST2 feature");
        }
        else if(l_valChipEcTest2)
        {
            if(l_chipList[0]->getAttr<TARGETING::ATTR_EC>() < 0x20)
            {
                FAPI_INF("Pass: This Nimbus proc has TEST2 enabled and < DD2.0");
            }
            else
            {
                TS_FAIL("Fail: This Nimbus proc has TEST2 enabled but >= DD2.0");
            }
        }
        else
        {
            if(l_chipList[0]->getAttr<TARGETING::ATTR_EC>() >= 0x20)
            {
                FAPI_INF("Pass: This Nimbus proc has TEST2 disabled and >= DD2.0");
            }
            else
            {
                TS_FAIL("Fail: This Nimbus proc has TEST2 disabled but < DD 2.0");
            }
        }

        fapi_try_exit:
        if(fapi2::current_err)
        {
            TS_FAIL("FAPI_TRY of attribute read failed! rc=0x%.8X",(uint32_t)fapi2::current_err);
        }
        return;

    } // end main testcase driver

}; // end class

} // end namespace fapi2
