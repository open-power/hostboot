/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2GetChipletNumTest.H $                 */
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
#include <commontargeting.H>
#include <cxxtest/TestSuite.H>
#include "fapi2TestUtils.H"


namespace fapi2
{

class Fapi2GetChipletNum : public CxxTest::TestSuite
{
    public:

    void testVerifyiPhbChipletNum()
    {
        uint8_t  l_chiplet_id = 0;
        uint8_t  l_exp_chiplet_id = 0;
        uint8_t  l_chip_unit = 0;

        FAPI_INF ("Start testVerifyiPhbChipletNum");
        do
        {
            // find all PHB units
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predPhb(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_PHB);

            TARGETING::TargetHandleList l_TargetList;
            TARGETING::targetService().getAssociated( l_TargetList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predPhb);

            if (l_TargetList.empty())
            {
                TS_FAIL("testVerifyiPhbChipletNum: empty l_TargetList");
                break;
            }

            // Iterate through all PHB chiplets
            for (auto & l_Target : l_TargetList)
            {
                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_PHB> fapi2_Target( l_Target);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyiPhbChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(l_Target), l_chiplet_id);

                l_chip_unit = l_Target->getAttr<TARGETING::ATTR_CHIP_UNIT>();

                // PEC-0 PBH-0 maps to pervasive id 0x0D
                if (l_chip_unit == 0)
                {
                    l_exp_chiplet_id = START_PEC_0_CHIPLET_NUM;
                }
                // PEC-1 PBH-0 maps to pervasive id 0x0E
                // PEC-1 PBH-1 maps to pervasive id 0x0E
                else if ((l_chip_unit >= 1) && (l_chip_unit <= 2))
                {
                    l_exp_chiplet_id = START_PEC_1_CHIPLET_NUM;
                }
                // PEC-2 PBH-0 maps to pervasive id 0x0F
                // PEC-2 PBH-1 maps to pervasive id 0x0F
                // PEC-2 PBH-2 maps to pervasive id 0x0F
                else if ((l_chip_unit >= 3) && (l_chip_unit <= 5))
                {
                    l_exp_chiplet_id = START_PEC_2_CHIPLET_NUM;
                }

                if (l_chiplet_id != l_exp_chiplet_id)
                {
                    TS_FAIL("testVerifyiPhbChipletNum: Mismatch - Expected: %.8X:, Found: %.8X",
                         l_exp_chiplet_id, l_chiplet_id);
                    break;
                }
            }
        } while(0);
        FAPI_INF("Complete testVerifyiPhbChipletNum");
    }

    void testVerifyObusBrickChipletNum()
    {
        uint8_t  l_chiplet_id = 0;
        uint8_t  l_exp_chiplet_id = 0;
        uint8_t  l_chip_unit = 0;

        FAPI_INF ("Start testVerifyObusBrickChipletNum");
        do
        {
            // find the all OBUS Brick units
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predObusBrick(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_OBUS_BRICK);

            TARGETING::TargetHandleList l_TargetList;
            TARGETING::targetService().getAssociated( l_TargetList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predObusBrick);

            if (l_TargetList.empty())
            {
                TS_FAIL("testVerifyObusBrickChipletNum: empty l_TargetList");
                break;
            }

            // Iterate through all OBUS BRICK chiplets
            for (auto & l_Target : l_TargetList)
            {
                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_OBUS_BRICK> fapi2_Target( l_Target);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyObusBrickChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(l_Target), l_chiplet_id);

                //OBUS Brick's chiplet id should be same as its parent
                auto l_parent = static_cast<TARGETING::Target*>
                        (fapi2_Target.getParent<TARGET_TYPE_OBUS>());
                l_chip_unit = l_parent->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                l_exp_chiplet_id = l_chip_unit + START_OBUS_BRICK_CHIPLET_NUM;

                if (l_chiplet_id != l_exp_chiplet_id)
                {
                    TS_FAIL("testVerifyObusBrickChipletNum: Mismatch - Expected: %.8X:, Found: %.8X",
                         l_exp_chiplet_id, l_chiplet_id);
                    break;
                }
            }
        } while(0);
        FAPI_INF("Complete testVerifyObusBrickChipletNum");
    }

    void testVerifyPecChipletNum()
    {
        uint8_t  l_chiplet_id = 0;
        uint8_t  l_exp_chiplet_id = 0;
        uint8_t  l_chip_unit = 0;

        FAPI_INF ("Start testVerifyPecChipletNum");
        do
        {
            // find all PEC units
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predPec(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_PEC);

            TARGETING::TargetHandleList l_TargetList;
            TARGETING::targetService().getAssociated( l_TargetList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predPec);

            if (l_TargetList.empty())
            {
                TS_FAIL("testVerifyPecChipletNum: empty l_TargetList");
                break;
            }

            // Iterate through all PEC chiplets
            for (auto & l_Target : l_TargetList)
            {
                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_PEC> fapi2_Target( l_Target);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyPecChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(l_Target), l_chiplet_id);

                // PEC 0,1,2 maps to pervasive ids 0x0D, 0x0E, 0x0F
                l_chip_unit = l_Target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                l_exp_chiplet_id = l_chip_unit + START_PEC_0_CHIPLET_NUM;

                if (l_chiplet_id != l_exp_chiplet_id)
                {
                    TS_FAIL("testVerifyPecChipletNum: Mismatch - Expected: %.8X:, Found: %.8X",
                         l_exp_chiplet_id, l_chiplet_id);
                    break;
                }
            }
        } while(0);
        FAPI_INF("Complete testVerifyPecChipletNum");
    }

    void testVerifyCappChipletNum()
    {
        uint8_t  l_chiplet_id = 0;
        uint8_t  l_exp_chiplet_id = 0;
        uint8_t  l_chip_unit = 0;

        FAPI_INF ("Start testVerifyCappChipletNum");
        do
        {
            // find all CAPP units
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predCapp(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_CAPP);

            TARGETING::TargetHandleList l_TargetList;
            TARGETING::targetService().getAssociated( l_TargetList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predCapp);

            if (l_TargetList.empty())
            {
                TS_FAIL("testVerifyCappChipletNum: empty l_TargetList");
                break;
            }

            // Iterate through all CAPP chiplets
            for (auto & l_Target : l_TargetList)
            {
                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_CAPP> fapi2_Target( l_Target);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyCappChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(l_Target), l_chiplet_id);

                // CAPP 0,1 maps to pervasive ids 0x02, 0x04
                l_chip_unit = l_Target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                if (l_chip_unit == 0 )
                {
                    l_exp_chiplet_id = START_CAPP_CHIPLET_NUM;
                }
                else
                {
                    l_exp_chiplet_id = START_CAPP_CHIPLET_NUM + 2;
                }

                if (l_chiplet_id != l_exp_chiplet_id)
                {
                    TS_FAIL("testVerifyCappChipletNum: Mismatch - Expected: %.8X:, Found: %.8X",
                         l_exp_chiplet_id, l_chiplet_id);
                    break;
                }
            }
        } while(0);
        FAPI_INF("Complete testVerifyCappChipletNum");
    }

    void testVerifyMcbistChipletNum()
    {
        uint8_t  l_chiplet_id = 0;
        uint8_t  l_exp_chiplet_id = 0;
        uint8_t  l_chip_unit = 0;

        FAPI_INF ("Start testVerifyMcbistChipletNum");
        do
        {
            // find all MCBIST units
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predMcbist(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_MCBIST);

            TARGETING::TargetHandleList l_TargetList;
            TARGETING::targetService().getAssociated( l_TargetList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predMcbist);

            if (l_TargetList.empty())
            {
                TS_FAIL("testVerifyMcbistChipletNum: empty l_TargetList");
                break;
            }

            // Iterate through all MCBIST chiplets
            for (auto & l_Target : l_TargetList)
            {
                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_MCBIST> fapi2_Target( l_Target);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyMcbistChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(l_Target), l_chiplet_id);

                // MCBIST 0,1 maps to pervasive ids 0x07, 0x08
                l_chip_unit = l_Target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                l_exp_chiplet_id = l_chip_unit + START_MCBIST_CHIPLET_NUM;

                if (l_chiplet_id != l_exp_chiplet_id)
                {
                    TS_FAIL("testVerifyMcbistChipletNum: Mismatch - Expected: %.8X:, Found: %.8X",
                         l_exp_chiplet_id, l_chiplet_id);
                    break;
                }
            }
        } while(0);
        FAPI_INF("Complete testVerifyMcbistChipletNum");
    }

    void testVerifyMcsChipletNum()
    {
        uint8_t  l_chiplet_id = 0;
        uint8_t  l_exp_chiplet_id = 0;

        FAPI_INF("Start testVerifyMcsChipletNum");
        do
        {
            // find all MCS units
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predMcs(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_MCS);

            TARGETING::TargetHandleList l_TargetList;
            TARGETING::targetService().getAssociated( l_TargetList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predMcs);

            if (l_TargetList.empty())
            {
                TS_FAIL("testVerifyMcsChipletNum: empty l_TargetList");
                break;
            }

            // Iterate through all MCS chiplets
            for (auto & l_Target : l_TargetList)
            {
                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_MCS> fapi2_Target(l_Target);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyMcsChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(l_Target),
                    l_chiplet_id);

                ReturnCode l_rc;
                fapi2::ATTR_CHIP_UNIT_POS_Type l_chipPos = 0;
                l_rc = FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                            l_Target, l_chipPos);
                if( l_rc )
                {
                    TS_FAIL("testVerifyMcsChipletNum: Error getting fapi::ATTR_CHIP_UNIT_POS");
                    break;
                }

                // MCS 0..1, 2..3 maps to pervasive ids 0x07, 0x08
                l_exp_chiplet_id = (l_chipPos/2) + START_MCBIST_CHIPLET_NUM;

                if (l_chiplet_id != l_exp_chiplet_id)
                {
                    TS_FAIL("testVerifyMcsChipletNum: Mismatch - Expected: %.8X:, Found: %.8X",
                         l_exp_chiplet_id, l_chiplet_id);
                    break;
                }
            }
        } while(0);
        FAPI_INF("Complete testVerifyMcsChipletNum");
    }

    void testVerifyMcaChipletNum()
    {
        uint8_t  l_chiplet_id = 0;
        uint8_t  l_exp_chiplet_id = 0;
        uint8_t  l_chip_unit = 0;

        FAPI_INF("Start testVerifyMcaChipletNum");
        do
        {
            // find all MCA units
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predMca(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_MCA);

            TARGETING::TargetHandleList l_TargetList;
            TARGETING::targetService().getAssociated( l_TargetList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predMca);

            if (l_TargetList.empty())
            {
                TS_FAIL("testVerifyMcaChipletNum: empty pMcbistList");
                break;
            }

            // Iterate through all MCA chiplets
            for (auto & l_Target : l_TargetList)
            {
                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_MCBIST> fapi2_Target( l_Target);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyMcaChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(l_Target), l_chiplet_id);

                // MCA 0..3, 4..7 maps to pervasive ids 0x07, 0x08
                l_chip_unit = l_Target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                l_exp_chiplet_id = l_chip_unit / 4 + START_MCBIST_CHIPLET_NUM;

                if (l_chiplet_id != l_exp_chiplet_id)
                {
                    TS_FAIL("testVerifyMcaChipletNum: Mismatch - Expected: %.8X:, Found: %.8X",
                         l_exp_chiplet_id, l_chiplet_id);
                    break;
                }
            }
        } while(0);
        FAPI_INF("Complete testVerifyMcaChipletNum");
    }

    void testVerifyObusChipletNum()
    {
        uint8_t  l_chiplet_id = 0;
        uint8_t  l_exp_chiplet_id = 0;
        uint8_t  l_chip_unit = 0;

        FAPI_INF("Start testVerifyObusChipletNum");
        do
        {
            // find all OBUS units
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predObus(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_OBUS);

            TARGETING::TargetHandleList l_TargetList;
            TARGETING::targetService().getAssociated( l_TargetList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predObus);

            if (l_TargetList.empty())
            {
                TS_FAIL("testVerifyObusChipletNum: empty l_TargetList");
                break;
            }

            // Iterate through all OBUS chiplets
            for (auto & l_Target : l_TargetList)
            {
                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_OBUS> fapi2_Target( l_Target);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyObusChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(l_Target),
                    l_chiplet_id);

                ReturnCode l_rc;
                fapi2::ATTR_CHIP_UNIT_POS_Type l_chipPos = 0;
                l_rc = FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                            l_Target, l_chipPos);
                if( l_rc )
                {
                    TS_FAIL("testVerifyObusChipletNum: Error getting fapi::ATTR_CHIP_UNIT_POS");
                    break;
                }

                // OBUS 0,3 maps to pervasive ids 0x09, 0x0C
                l_chip_unit = l_Target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                l_exp_chiplet_id = l_chip_unit + START_OBUS_CHIPLET_NUM;

                if (l_chiplet_id != l_exp_chiplet_id)
                {
                    TS_FAIL("testVerifyObusChipletNum: Mismatch - Expected: %.8X:, Found: %.8X",
                         l_exp_chiplet_id, l_chiplet_id);
                    break;
                }
            }
        } while(0);
        FAPI_INF("Complete testVerifyObusChipletNum");
    }

    void testVerifyXbusChipletNum()
    {
        uint8_t  l_chiplet_id = 0;

        FAPI_INF("Start testVerifyXbusChipletNum");
        do
        {
            // find all XBUS units
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predXbus(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_XBUS);

            TARGETING::TargetHandleList l_TargetList;
            TARGETING::targetService().getAssociated( l_TargetList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predXbus);

            if (l_TargetList.empty())
            {
                TS_FAIL("testVerifyXbusChipletNum: empty l_TargetList");
                break;
            }

            // Iterate through all XBUS chiplets
            for (auto & l_Target : l_TargetList)
            {
                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_XBUS> fapi2_Target( l_Target);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyXbusChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(l_Target),
                    l_chiplet_id);

                // XBUS 0,1 maps to pervasive id 0x06
                if (l_chiplet_id != START_XBUS_CHIPLET_NUM)
                {
                    TS_FAIL("testVerifyXbusChipletNum: Mismatch - Expected: %.8X:, Found: %.8X",
                         START_XBUS_CHIPLET_NUM, l_chiplet_id);
                    break;
                }
            }
        } while(0);
        FAPI_INF("Complete testVerifyXbusChipletNum");
    }
    void testVerifyPervChipletNum()
    {
        uint8_t  l_chiplet_id = 0;
        uint8_t  l_chip_unit = 0;

        FAPI_INF("Start testVerifyPervChipletNum");
        do
        {
            // find all PERV units
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predPerv(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_PERV);

            TARGETING::TargetHandleList l_TargetList;
            TARGETING::targetService().getAssociated( l_TargetList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predPerv );

            if (l_TargetList.empty())
            {
                TS_FAIL("testVerifyPervChipletNum: empty l_TargetList");
                break;
            }

            // Iterate through all PERV chiplets
            for (auto & l_Target : l_TargetList)
            {
                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_PERV> fapi2_Target( l_Target);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyPervChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(l_Target),
                    l_chiplet_id);

                // PERV units and chiplet ids are same
                l_chip_unit = l_Target->getAttr<TARGETING::ATTR_CHIP_UNIT>();

                if (l_chiplet_id != l_chip_unit)
                {
                    TS_FAIL("testVerifyPervChipletNum: Mismatch - Expected: %.8X:, Found: %.8X",
                         l_chip_unit, l_chiplet_id);
                    break;
                }
            }
        } while(0);
        FAPI_INF("Complete testVerifyPervChipletNum");
    }

    void testVerifyEQChipletNum()
    {
        uint8_t  l_chiplet_id = 0;
        uint8_t  l_exp_chiplet_id = 0;
        uint8_t  l_chip_unit = 0;

        FAPI_INF("Start testVerifyEQChipletNum");
        do
        {
            // find all EQ units`
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predEq(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_EQ);

            TARGETING::TargetHandleList l_TargetList;
            TARGETING::targetService().getAssociated( l_TargetList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predEq );

            if (l_TargetList.empty())
            {
                TS_FAIL("testVerifyEQChipletNum: empty l_TargetList");
                break;
            }

            // Iterate through all EQ chiplets
            for (auto & l_Target : l_TargetList)
            {
                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_EQ> fapi2_Target( l_Target);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyEQChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(l_Target),
                    l_chiplet_id);

                // EQ 0..5 maps to pervasive ids 0x10..0x15
                l_chip_unit = l_Target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                l_exp_chiplet_id = l_chip_unit + START_EQ_CHIPLET_NUM;

                if (l_chiplet_id != l_exp_chiplet_id)
                {
                    TS_FAIL("testVerifyEQChipletNum: Mismatch - Expected: %.8X:, Found: %.8X",
                         l_exp_chiplet_id, l_chiplet_id);
                    break;
                }
            }
        } while(0);
        FAPI_INF("Complete testVerifyEQChipletNum");
    }

    void testVerifyEXChipletNum()
    {
        uint8_t  l_chiplet_id = 0;
        uint8_t  l_exp_chiplet_id = 0;

        FAPI_INF("Start testVerifyEXChipletNum");
        do
        {
            // find all EX units
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predEx(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_EX);

            TARGETING::TargetHandleList l_TargetList;
            TARGETING::targetService().getAssociated( l_TargetList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predEx );

            if (l_TargetList.empty())
            {
                TS_FAIL("testVerifyEXChipletNum: empty l_TargetList");
                break;
            }

            // Iterate through all EXs
            for (auto & l_Target : l_TargetList)
            {
                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_EX> fapi2_Target( l_Target);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyEXChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(l_Target),
                    l_chiplet_id);

                ReturnCode l_rc;
                fapi2::ATTR_CHIP_UNIT_POS_Type chipPos = 0;
                l_rc = FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                            l_Target,chipPos);
                if( l_rc )
                {
                    TS_FAIL("testVerifyEXChipletNum: Error getting fapi::ATTR_CHIP_UNIT_POS");
                    break;
                }

                // EXs maps to pervasive id of their parents 0x10..0x15
                l_exp_chiplet_id = (chipPos/2) + START_EQ_CHIPLET_NUM;

                if (l_chiplet_id != l_exp_chiplet_id)
                {
                    TS_FAIL("testVerifyEXChipletNum: Mismatch - Expected: %.8X:, Found: %.8X",
                         l_exp_chiplet_id, l_chiplet_id);
                    break;
                }
            }
        } while(0);
        FAPI_INF("Complete testVerifyEXChipletNum");
    }

    void testVerifyCoreChipletNum()
    {
        FAPI_INF("Start testVerifyCoreChipletNum");

        uint8_t  l_chiplet_id = 0;
        uint8_t  l_exp_chiplet_id = 0;
        uint8_t  l_chip_unit = 0;

        do
        {
            // find all cpu COREs
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predCore(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_CORE);

            TARGETING::TargetHandleList l_TargetList;
            TARGETING::targetService().getAssociated( l_TargetList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predCore );

            if (l_TargetList.empty())
            {
                TS_FAIL("testVerifyCoreChipletNum: empty l_TargetList");
                break;
            }

            // Iterate through all cores
            for (auto & l_Target : l_TargetList)
            {
                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_CORE> fapi2_Target( l_Target);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyCoreChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(l_Target),
                    l_chiplet_id);

                // Processor Core 0..23 maps to pervasive ids 0x20..0x37
                l_chip_unit = l_Target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                l_exp_chiplet_id = l_chip_unit + START_CORE_CHIPLET_NUM;

                if (l_chiplet_id != l_exp_chiplet_id)
                {
                    TS_FAIL("testVerifyCoreChipletNum: Mismatch - Expected: %.8X:, Found: %.8X",
                         l_exp_chiplet_id, l_chiplet_id);
                    break;
                }
            }
        } while(0);
        FAPI_INF("Complete testVerifyCoreChipletNum");
    }

    //**************************************************************************
    // test_fapi2GetChipletNum
    //**************************************************************************
    void test_fapi2ChipletNum()
    {

        FAPI_DBG("Enter test_fapi2GetChipletNum");
        do
        {

            testVerifyEQChipletNum();

            testVerifyEXChipletNum();

            testVerifyCoreChipletNum();

            testVerifyPervChipletNum();

            testVerifyXbusChipletNum();

            testVerifyObusChipletNum();

            testVerifyMcbistChipletNum();

            testVerifyMcsChipletNum();

            testVerifyMcaChipletNum();

            testVerifyCappChipletNum();

            testVerifyObusBrickChipletNum();

            testVerifyPecChipletNum();

            testVerifyiPhbChipletNum();

        } while(0);
        FAPI_DBG("test_fapi2ChipletNum Test Complete.");
    } // end test_fapi2ChipletNum()

}; // end class

}// end namespace fapi2

