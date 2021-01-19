/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2GetTargetTest.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
#include <fapi2/target.H>
#include <error_scope.H>

using namespace fapi2;

class Fapi2GetTargetTest : public CxxTest::TestSuite
{
  public:
    //******************************************************************************
    // test_fapi2GetTarget
    //******************************************************************************
    void test_fapi2GetTarget()
    {
        uint8_t    l_chipletNum = 0;
        uint32_t   l_huid = 0;

        do
        {
            // Get FC target of FAPI_POS (2)
            fapi2::Target<fapi2::TARGET_TYPE_FC> l_fapiFC =
              fapi2::getTarget<fapi2::TARGET_TYPE_FC>(2);

            // Verify the chiplet number
            l_chipletNum = l_fapiFC.getChipletNumber();
            FAPI_INF("test_fapi2GetTarget FC Fapi-pos: 2, Chiplet Num: %.8x",
                     l_chipletNum);
            if (l_chipletNum != 0x21)
            {
                TS_FAIL("test_fapi2GetTarget: FC Wrong Chiplet Number!");
                break;
            }

            // Verify HUID of FC
            TARGETING::Target* l_targFC = l_fapiFC.get();
            l_huid = TARGETING::get_huid(l_targFC);
            FAPI_INF("test_fapi2GetTarget FC HUID: %.8x", l_huid);
            if (l_huid != 0x00530002)
            {
                TS_FAIL("getTarget: FC HUID is Wrong");
                break;
            }
        }while(0);
    }


    //******************************************************************************
    // test_fapi2GetTarget_1
    //******************************************************************************
    void test_fapi2GetTarget_1()
    {
        // get the 0'th instance of the proc target
        uint8_t instance = 0;

        fapi2::TargetType type = fapi2::TARGET_TYPE_PROC_CHIP;

        fapi2::Target<TARGET_TYPE_ALL>* l_target =
          fapi2::getTarget<fapi2::TARGET_TYPE_ALL>(type,instance);

        TARGETING::Target * l_targTarg = l_target->get();

        // verify the instance number
        // verify the type

        TARGETING::ATTR_FAPI_POS_type pos =
          l_targTarg->getAttr<TARGETING::ATTR_FAPI_POS>();

        if( pos != instance )
        {
            TS_FAIL("position of proc did not match [%d!=%d]",
                    instance, pos);
        }

        TARGETING::ATTR_TYPE_type Ttype =
          l_targTarg->getAttr<TARGETING::ATTR_TYPE>();

        if( Ttype != TARGETING::TYPE_PROC )
        {
            TS_FAIL("Target type was not TYPE_PROC - we got 0x%x", Ttype);
        }

        //get the 3rd FC chiplet
        instance = 3;

        type = fapi2::TARGET_TYPE_FC;

        l_target = fapi2::getTarget<fapi2::TARGET_TYPE_ALL>(type,instance);

        l_targTarg = l_target->get();

        // verify the instance number
        // verify the type

        pos = l_targTarg->getAttr<TARGETING::ATTR_FAPI_POS>();

        if( pos != instance )
        {
            TS_FAIL("position of FC chiplet did not match [%d!=%d]",
                    instance, pos);
        }

        Ttype = l_targTarg->getAttr<TARGETING::ATTR_TYPE>();

        if( Ttype != TARGETING::TYPE_FC )
        {
            TS_FAIL("Target type was not TYPE_FC - we got 0x%x", Ttype);
        }
    }
};
