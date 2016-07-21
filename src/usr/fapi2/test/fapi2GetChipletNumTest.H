/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2GetChipletNumTest.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

    void testVerifyMcbistChipletNum()
    {
        uint8_t  l_chiplet_id = 0;
        uint8_t  l_exp_chiplet_id = 0;
        uint8_t  chipUnit = 0;

        FAPI_INF ("Start testVerifyMcbistChipletNum");
        do
        {
            // find the unit
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predMcbist(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_MCBIST);

            TARGETING::TargetHandleList pMcbistList;
            TARGETING::targetService().getAssociated( pMcbistList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predMcbist);

            if (pMcbistList.empty())
            {
                TS_FAIL("testVerifyMcbistChipletNum: empty pMcbistList");
                break;
            }

            // Iterate through present procs
            for (TARGETING::TargetHandleList::const_iterator
                 l_mcbistIter = pMcbistList.begin();
                 l_mcbistIter != pMcbistList.end();
                 ++l_mcbistIter)
            {

                TARGETING::Target * pTarTarget = *l_mcbistIter;

                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_MCBIST> fapi2_Target( pTarTarget);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyMcbistChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(pTarTarget), l_chiplet_id);

                chipUnit = pTarTarget->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                l_exp_chiplet_id = chipUnit + START_MCBIST_CHIPLET_NUM;

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
            // find the unit
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predMcs(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_MCS);

            TARGETING::TargetHandleList pMcsList;
            TARGETING::targetService().getAssociated( pMcsList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predMcs);

            if (pMcsList.empty())
            {
                TS_FAIL("testVerifyMcsChipletNum: empty pMcsList");
                break;
            }

            // Iterate through present procs
            for (TARGETING::TargetHandleList::const_iterator
                 l_mcsIter = pMcsList.begin();
                 l_mcsIter != pMcsList.end();
                 ++l_mcsIter)
            {
                TARGETING::Target * pTarTarget = *l_mcsIter;

                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_MCS> fapi2_Target(pTarTarget);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyMcsChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(pTarTarget),
                    l_chiplet_id);

                ReturnCode l_rc;
                fapi2::ATTR_CHIP_UNIT_POS_Type chipPos = 0;
                l_rc = FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                            pTarTarget,chipPos);
                if( l_rc )
                {
                    TS_FAIL("testVerifyMcsChipletNum: Error getting fapi::ATTR_CHIP_UNIT_POS");
                    break;
                }

                l_exp_chiplet_id = (chipPos/2) + START_MCBIST_CHIPLET_NUM;

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
        uint8_t  chipUnit = 0;

        FAPI_INF("Start testVerifyMcaChipletNum");
        do
        {
            // find the unit
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predMca(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_MCA);

            TARGETING::TargetHandleList pMcaistList;
            TARGETING::targetService().getAssociated( pMcaistList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predMca);

            if (pMcaistList.empty())
            {
                TS_FAIL("testVerifyMcaChipletNum: empty pMcbistList");
                break;
            }

            // Iterate through present procs
            for (TARGETING::TargetHandleList::const_iterator
                 l_mcaistIter = pMcaistList.begin();
                 l_mcaistIter != pMcaistList.end();
                 ++l_mcaistIter)
            {

                TARGETING::Target * pTarTarget = *l_mcaistIter;

                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_MCBIST> fapi2_Target( pTarTarget);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyMcaChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(pTarTarget), l_chiplet_id);

                chipUnit = pTarTarget->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                l_exp_chiplet_id = chipUnit / 4 + START_MCBIST_CHIPLET_NUM;

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
        uint8_t  chipUnit = 0;

        FAPI_INF("Start testVerifyObusChipletNum");
        do
        {
            // find the unit
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predObus(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_OBUS);

            TARGETING::TargetHandleList pObusList;
            TARGETING::targetService().getAssociated( pObusList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predObus);

            if (pObusList.empty())
            {
                TS_FAIL("testVerifyObusChipletNum: empty pObusList");
                break;
            }

            // Iterate through present procs
            for (TARGETING::TargetHandleList::const_iterator
                 l_obusIter = pObusList.begin();
                 l_obusIter != pObusList.end();
                 ++l_obusIter)
            {
                TARGETING::Target * pTarTarget = *l_obusIter;

                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_OBUS> fapi2_Target( pTarTarget);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyObusChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(pTarTarget),
                    l_chiplet_id);

                ReturnCode l_rc;
                fapi2::ATTR_CHIP_UNIT_POS_Type chipPos = 0;
                l_rc = FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                            pTarTarget,chipPos);
                if( l_rc )
                {
                    TS_FAIL("testVerifyObusChipletNum: Error getting fapi::ATTR_CHIP_UNIT_POS");
                    break;
                }

                // Nimbus has two obuses 0 & 3
                chipUnit = pTarTarget->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                l_exp_chiplet_id = chipUnit + START_OBUS_CHIPLET_NUM;

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
            // find the unit
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predXbus(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_XBUS);

            TARGETING::TargetHandleList pXbusList;
            TARGETING::targetService().getAssociated( pXbusList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predXbus);

            if (pXbusList.empty())
            {
                TS_FAIL("testVerifyXbusChipletNum: empty pXbusList");
                break;
            }

            // Iterate through present procs
            for (TARGETING::TargetHandleList::const_iterator
                 l_xbusIter = pXbusList.begin();
                 l_xbusIter != pXbusList.end();
                 ++l_xbusIter)
            {
                TARGETING::Target * pTarTarget = *l_xbusIter;

                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_XBUS> fapi2_Target( pTarTarget);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyXbusChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(pTarTarget),
                    l_chiplet_id);

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
        uint8_t  chipUnit = 0;

        FAPI_INF("Start testVerifyPervChipletNum");
        do
        {
            // find the unit
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predPerv(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_PERV);

            TARGETING::TargetHandleList pPervList;
            TARGETING::targetService().getAssociated( pPervList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predPerv );

            if (pPervList.empty())
            {
                TS_FAIL("testVerifyPervChipletNum: empty pPervList");
                break;
            }

            // Iterate through present procs
            for (TARGETING::TargetHandleList::const_iterator
                 l_pervIter = pPervList.begin();
                 l_pervIter != pPervList.end();
                 ++l_pervIter)
            {
                TARGETING::Target * pTarTarget = *l_pervIter;

                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_PERV> fapi2_Target( pTarTarget);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyPervChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(pTarTarget),
                    l_chiplet_id);

                chipUnit = pTarTarget->getAttr<TARGETING::ATTR_CHIP_UNIT>();

                if (l_chiplet_id != chipUnit)
                {
                    TS_FAIL("testVerifyPervChipletNum: Mismatch - Expected: %.8X:, Found: %.8X",
                         chipUnit, l_chiplet_id);
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
        uint8_t  chipUnit = 0;

        FAPI_INF("Start testVerifyEQChipletNum");
        do
        {
            // find the unit
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predEq(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_EQ);

            TARGETING::TargetHandleList pEqList;
            TARGETING::targetService().getAssociated( pEqList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predEq );

            if (pEqList.empty())
            {
                TS_FAIL("testVerifyEQChipletNum: empty pEqList");
                break;
            }

            // Iterate through present procs
            for (TARGETING::TargetHandleList::const_iterator
                 l_eqIter = pEqList.begin();
                 l_eqIter != pEqList.end();
                 ++l_eqIter)
            {
                TARGETING::Target * pTarTarget = *l_eqIter;

                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_EQ> fapi2_Target( pTarTarget);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyEQChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(pTarTarget),
                    l_chiplet_id);

                chipUnit = pTarTarget->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                l_exp_chiplet_id = chipUnit + START_EQ_CHIPLET_NUM;

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
            // find the unit
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predEx(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_EX);

            TARGETING::TargetHandleList pExList;
            TARGETING::targetService().getAssociated( pExList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predEx );

            if (pExList.empty())
            {
                TS_FAIL("testVerifyEXChipletNum: empty pExList");
                break;
            }

            // Iterate through present procs
            for (TARGETING::TargetHandleList::const_iterator
                 l_exIter = pExList.begin();
                 l_exIter != pExList.end();
                 ++l_exIter)
            {
                TARGETING::Target * pTarTarget = *l_exIter;

                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_EX> fapi2_Target( pTarTarget);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyEXChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(pTarTarget),
                    l_chiplet_id);

                ReturnCode l_rc;
                fapi2::ATTR_CHIP_UNIT_POS_Type chipPos = 0;
                l_rc = FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                            pTarTarget,chipPos);
                if( l_rc )
                {
                    TS_FAIL("testVerifyEXChipletNum: Error getting fapi::ATTR_CHIP_UNIT_POS");
                    break;
                }

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
        uint8_t  chipUnit = 0;

        do
        {
            // find the unit
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predCore(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_CORE);

            TARGETING::TargetHandleList pCoreList;
            TARGETING::targetService().getAssociated( pCoreList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predCore );

            if (pCoreList.empty())
            {
                TS_FAIL("testVerifyCoreChipletNum: empty pCoreList");
                break;
            }

            // Iterate through present cores
            for (TARGETING::TargetHandleList::const_iterator
                 l_coreIter = pCoreList.begin();
                 l_coreIter != pCoreList.end();
                 ++l_coreIter)
            {
                TARGETING::Target * pTarTarget = *l_coreIter;

                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_CORE> fapi2_Target( pTarTarget);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyCoreChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(pTarTarget),
                    l_chiplet_id);

                chipUnit = pTarTarget->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                l_exp_chiplet_id = chipUnit + START_CORE_CHIPLET_NUM;

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

        } while(0);
        FAPI_DBG("test_fapi2ChipletNum Test Complete.");
    } // end test_fapi2ChipletNum()

}; // end class

}// end namespace fapi2

