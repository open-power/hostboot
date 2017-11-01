/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2PllBucketTest.H $                     */
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
#ifndef __PLL_BUCKET_TEST_H__
#define __PLL_BUCKET_TEST_H__

/**
 *  @file fapi2PllBucketTest.H
 *
 *  @brief Test case for WOF access code
 */

#include <stdio.h>
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <fapi2.H>
#include <devicefw/userif.H>
#include <utilFilter.H>

using   namespace   TARGETING;

class PllBucketTest: public CxxTest::TestSuite
{
public:

    /**
      * @brief Test OB[0,1,2,3]_PLL_BUCKET access attribute
      *
      */
    void testPllBucket (void)
    {
        FAPI_INF("testPllBucket: ENTER");

        fapi2::ReturnCode l_rc;

        TARGETING::TargetHandleList l_chipList;
        TARGETING::getAllChips(l_chipList, TARGETING::TYPE_PROC);
        TARGETING::Target * l_target = NULL;

        for (uint8_t i = 0; i < l_chipList.size(); i++)
        {
            if(TARGETING::MODEL_NIMBUS ==
                l_chipList[i]->getAttr<TARGETING::ATTR_MODEL>())
            {
                uint8_t l_bucket[4] = {255, 255, 255, 255};
                l_target = l_chipList[i];
                fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                    fapi2_procTarget(l_target);

                //Perform test on OB0
                FAPI_DBG("test OB0_PLL_BUCKET  on chip HUID: %.8X",
                    TARGETING::get_huid(l_target));

                FAPI_ATTR_GET(fapi2::ATTR_OB0_PLL_BUCKET,
                          l_target,
                          l_bucket[0]);
                if(l_bucket[0] == 255)
                {
                    TS_FAIL("testPllBucket: OB0_PLL_BUCKET failed, got: %d",
                        l_bucket[0]);
                }

                //Perform test on OB1
                FAPI_DBG("test OB1_PLL_BUCKET  on chip HUID: %.8X",
                    TARGETING::get_huid(l_target));

                FAPI_ATTR_GET(fapi2::ATTR_OB1_PLL_BUCKET,
                          l_target,
                          l_bucket[1]);
                if(l_bucket[1] == 255)
                {
                    TS_FAIL("testPllBucket: OB1_PLL_BUCKET failed, got: %d",
                        l_bucket[1]);
                }

                //Perform test on OB2
                FAPI_DBG("test OB2_PLL_BUCKET on chip HUID: %.8X",
                    TARGETING::get_huid(l_target));

                FAPI_ATTR_GET(fapi2::ATTR_OB2_PLL_BUCKET,
                          l_target,
                          l_bucket[2]);
                if(l_bucket[2] == 255)
                {
                    TS_FAIL("testPllBucket: OB2_PLL_BUCKET failed, got: %d",
                        l_bucket[2]);
                }

                //Perform test on OB3
                FAPI_DBG("test OB3_PLL_BUCKET on chip HUID: %.8X",
                    TARGETING::get_huid(l_target));

                FAPI_ATTR_GET(fapi2::ATTR_OB3_PLL_BUCKET,
                          l_target,
                          l_bucket[3]);
                if(l_bucket[3] == 255)
                {
                    TS_FAIL("testPllBucket: OB3_PLL_BUCKET failed, got: %d",
                        l_bucket[3]);
                }
            }
        }
        FAPI_INF("testPllBucket: EXIT.");

    } // testPllBucket

};

#endif
