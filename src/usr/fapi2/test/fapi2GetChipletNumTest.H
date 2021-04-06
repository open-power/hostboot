/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2GetChipletNumTest.H $                 */
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

                // PEC-0 PHB-0 maps to pervasive id 0x08
                // PEC-0 PHB-1 maps to pervasive id 0x08
                // PEC-0 PHB-2 maps to pervasive id 0x08
                if ((l_chip_unit >= 0) && (l_chip_unit <= 2))
                {
                    l_exp_chiplet_id = START_PEC_0_CHIPLET_NUM;
                }
                // PEC-1 PHB-0 maps to pervasive id 0x09
                // PEC-1 PHB-1 maps to pervasive id 0x09
                // PEC-1 PHB-2 maps to pervasive id 0x09
                else if ((l_chip_unit >= 3) && (l_chip_unit <= 5))
                {
                    l_exp_chiplet_id = START_PEC_1_CHIPLET_NUM;
                }

                if (l_chiplet_id != l_exp_chiplet_id)
                {
                    TS_FAIL("testVerifyiPhbChipletNum: Mismatch HUID %.8X - Expected: %.8X:, Found: %.8X",
                            TARGETING::get_huid(l_Target),
                            l_exp_chiplet_id, l_chiplet_id);
                }
            }
        } while(0);
        FAPI_INF("Complete testVerifyiPhbChipletNum");
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
                    TS_FAIL("testVerifyPecChipletNum: Mismatch HUID %.8X - Expected: %.8X:, Found: %.8X",
                            TARGETING::get_huid(l_Target),
                            l_exp_chiplet_id, l_chiplet_id);
                }
            }
        } while(0);
        FAPI_INF("Complete testVerifyPecChipletNum");
    }

    void testVerifyMcChipletNum()
    {
        uint8_t  l_chiplet_id = 0;
        uint8_t  l_exp_chiplet_id = 0;
        uint8_t  l_chip_unit = 0;

        FAPI_INF("Start testVerifyMcChipletNum");

        do
        {
            // find all MC units
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predMc(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_MC);

            TARGETING::Target* l_pMasterProcChip = nullptr;
            TARGETING::targetService().masterProcChipTargetHandle(l_pMasterProcChip);

            TARGETING::TargetHandleList l_TargetList;
            TARGETING::targetService().getAssociated( l_TargetList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predMc);

            if (l_TargetList.empty())
            {
                TS_FAIL("testVerifyMcChipletNum: empty l_TargetList");
                break;
            }

            // Iterate through all MC chiplets
            for (auto & l_Target : l_TargetList)
            {
                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_MC> fapi2_Target( l_Target);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyMcChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(l_Target), l_chiplet_id);

                // MC 0,1,2,3 maps to pervasive ids 0x07,0x08,0x09,0x0A
                l_chip_unit = l_Target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                l_exp_chiplet_id = l_chip_unit + START_MC_CHIPLET_NUM;

                if (l_chiplet_id != l_exp_chiplet_id)
                {
                    TS_FAIL("testVerifyMcChipletNum: Mismatch HUID %.8X - Expected: %.8X:, Found: %.8X",
                            TARGETING::get_huid(l_Target),
                            l_exp_chiplet_id, l_chiplet_id);
                }
            }

        } while(0);

        FAPI_INF("Complete testVerifyMcChipletNum");
    }

    void testVerifyMiChipletNum()
    {
        uint8_t  l_chiplet_id = 0;
        uint8_t  l_exp_chiplet_id = 0;
        uint8_t  l_chip_unit = 0;

        FAPI_INF("Start testVerifyMiChipletNum");

        do
        {
            // find all MI units
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predMi(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_MI);

            TARGETING::Target* l_pMasterProcChip = nullptr;
            TARGETING::targetService().masterProcChipTargetHandle(l_pMasterProcChip);

            TARGETING::TargetHandleList l_TargetList;
            TARGETING::targetService().getAssociated( l_TargetList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predMi);

            if (l_TargetList.empty())
            {
                TS_FAIL("testVerifyMiChipletNum: empty l_TargetList");
                break;
            }

            // Iterate through all MI chiplets
            for (auto & l_Target : l_TargetList)
            {
                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_MI> fapi2_Target( l_Target);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyMiChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(l_Target), l_chiplet_id);

                // MI 0,1,...  maps to pervasive id 0x0C,0x0D,...
                l_chip_unit = l_Target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                l_exp_chiplet_id = l_chip_unit + START_MI_CHIPLET_NUM;

                if (l_chiplet_id != l_exp_chiplet_id)
                {
                    TS_FAIL("testVerifyMiChipletNum: Mismatch HUID %.8X - Expected: %.8X:, Found: %.8X",
                            TARGETING::get_huid(l_Target),
                            l_exp_chiplet_id, l_chiplet_id);
                }
            }


        } while(0);

        FAPI_INF("Complete testVerifyMiChipletNum");
    }

    void testVerifyMccChipletNum()
    {
        uint8_t  l_chiplet_id = 0;
        uint8_t  l_exp_chiplet_id = 0;
        uint8_t  l_chip_unit = 0;

        FAPI_INF("Start testVerifyMccChipletNum");

        do
        {
            // find all MCC units
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predMcc(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_MCC);

            TARGETING::Target* l_pMasterProcChip = nullptr;
            TARGETING::targetService().masterProcChipTargetHandle(l_pMasterProcChip);

            TARGETING::TargetHandleList l_TargetList;
            TARGETING::targetService().getAssociated( l_TargetList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predMcc);

            if (l_TargetList.empty())
            {
                TS_FAIL("testVerifyMccChipletNum: empty l_TargetList");
                break;
            }

            // Iterate through all MCC chiplets
            for (auto & l_Target : l_TargetList)
            {
                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_MCC> fapi2_Target( l_Target);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyMccChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(l_Target), l_chiplet_id);

                // MCC 0..3, 4..7 maps to pervasive ids 0x07, 0x08
                l_chip_unit = l_Target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                l_exp_chiplet_id = l_chip_unit / PERV_MCC_CHILDREN + START_MCC_CHIPLET_NUM;

                if (l_chiplet_id != l_exp_chiplet_id)
                {
                    TS_FAIL("testVerifyMccChipletNum: Mismatch HUID %.8X - Expected: %.8X:, Found: %.8X",
                            TARGETING::get_huid(l_Target),
                            l_exp_chiplet_id, l_chiplet_id);
                }
            }
        } while(0);

        FAPI_INF("Complete testVerifyMccChipletNum");

    }

    void testVerifyOmiChipletNum()
    {
        uint8_t  l_chiplet_id = 0;
        uint8_t  l_exp_chiplet_id = 0;
        uint8_t  l_chip_unit = 0;

        FAPI_INF("Start testVerifyOmiChipletNum");

        do
        {
            // find all OMI units
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predOmi(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_OMI);

            TARGETING::Target* l_pMasterProcChip = nullptr;
            TARGETING::targetService().masterProcChipTargetHandle(l_pMasterProcChip);

            TARGETING::TargetHandleList l_TargetList;
            TARGETING::targetService().getAssociated( l_TargetList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predOmi);

            if (l_TargetList.empty())
            {
                TS_FAIL("testVerifyOmiChipletNum: empty l_TargetList");
                break;
            }

            // Iterate through all OMI chiplets
            for (auto & l_Target : l_TargetList)
            {
                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_OMI> fapi2_Target( l_Target);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyOmiChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(l_Target), l_chiplet_id);

                // OMI 0..4, 5..8 etc. maps to pervasive ids 0x0C, 0x0D, etc.
                l_chip_unit = l_Target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                l_exp_chiplet_id = l_chip_unit / PERV_OMI_CHILDREN + START_OMI_CHIPLET_NUM;

                if (l_chiplet_id != l_exp_chiplet_id)
                {
                    TS_FAIL("testVerifyOmiChipletNum: Mismatch HUID %.8X - Expected: %.8X:, Found: %.8X",
                            TARGETING::get_huid(l_Target),
                            l_exp_chiplet_id, l_chiplet_id);
                }
            }
        } while(0);

        FAPI_INF("Complete testVerifyOmiChipletNum");

    }

    void testVerifyOmicChipletNum()
    {
        uint8_t  l_chiplet_id = 0;
        uint8_t  l_exp_chiplet_id = 0;
        uint8_t  l_chip_unit = 0;

        FAPI_INF("Start testVerifyOmicChipletNum");

        do
        {
            // find all OMIC units
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            TARGETING::PredicateCTM predOmic(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_OMIC);

            TARGETING::Target* l_pMasterProcChip = nullptr;
            TARGETING::targetService().masterProcChipTargetHandle(l_pMasterProcChip);

            TARGETING::TargetHandleList l_TargetList;
            TARGETING::targetService().getAssociated( l_TargetList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predOmic);

            if (l_TargetList.empty())
            {
                TS_FAIL("testVerifyOmicChipletNum: empty l_TargetList");
                break;
            }

            // Iterate through all OMI chiplets
            for (auto & l_Target : l_TargetList)
            {
                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_OMIC> fapi2_Target( l_Target);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyOmicChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(l_Target), l_chiplet_id);

                // OMI 0..5, 6..11 maps to pervasive ids 0x07, 0x08
                l_chip_unit = l_Target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                l_exp_chiplet_id = l_chip_unit / PERV_OMIC_CHILDREN + START_OMIC_CHIPLET_NUM;

                if (l_chiplet_id != l_exp_chiplet_id)
                {
                    TS_FAIL("testVerifyOmicChipletNum: Mismatch HUID %.8X - Expected: %.8X:, Found: %.8X",
                            TARGETING::get_huid(l_Target),
                            l_exp_chiplet_id, l_chiplet_id);
                }
            }
        } while(0);

        FAPI_INF("Complete testVerifyOmicChipletNum");

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
                    TS_FAIL("testVerifyEQChipletNum: Mismatch HUID %.8X - Expected: %.8X:, Found: %.8X",
                            TARGETING::get_huid(l_Target),
                            l_exp_chiplet_id, l_chiplet_id);
                }
            }
        } while(0);
        FAPI_INF("Complete testVerifyEQChipletNum");
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

                // Processor Cores 0..31 map to pervasive ids 0x20..0x27
                l_chip_unit = l_Target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                l_exp_chiplet_id = l_chip_unit / 4 + START_CORE_CHIPLET_NUM;

                if (l_chiplet_id != l_exp_chiplet_id)
                {
                    TS_FAIL("testVerifyCoreChipletNum: Mismatch HUID %.8X - Expected: %.8X:, Found: %.8X",
                            TARGETING::get_huid(l_Target),
                            l_exp_chiplet_id, l_chiplet_id);
                }
            }
        } while(0);
        FAPI_INF("Complete testVerifyCoreChipletNum");
    }

    void testVerifySmpgroupChipletNum()
    {
        FAPI_INF("Start testVerifySmpgroupChipletNum");

        do
        {
            TARGETING::TargetHandleList smpgroups;
            getAllChiplets(smpgroups, TARGETING::TYPE_SMPGROUP, false);

            if (smpgroups.empty())
            {
                TS_FAIL("testVerifySmpgroupChipletNum: empty smpgroups");
                break;
            }

            for (const auto smpgroup : smpgroups)
            {
                Target<fapi2::TARGET_TYPE_IOLINK> iolink(smpgroup);

                const auto iolink_chiplet_id = iolink.getChipletNumber();

                FAPI_DBG("testVerifySmpgroupChipletNum HUID: 0x%08x, chiplet ID: 0x%08x",
                         TARGETING::get_huid(smpgroup),
                         iolink_chiplet_id);

                // SMPGROUP's chiplet number must match parent IOHS's chiplet number

                const auto parent_iohs = getImmediateParentByAffinity(smpgroup);

                Target<fapi2::TARGET_TYPE_IOHS> fapi_iohs(parent_iohs);

                const auto iohs_chiplet_id = fapi_iohs.getChipletNumber();

                if (iohs_chiplet_id != iolink_chiplet_id)
                {
                    TS_FAIL("testVerifySmpgroupChipletNum: SMPGROUP 0x%08x's chiplet number (0x%x) does not match parent IOHS's (0x%08x) chiplet number (0x%x)",
                            TARGETING::get_huid(smpgroup),
                            iolink_chiplet_id,
                            TARGETING::get_huid(parent_iohs),
                            iohs_chiplet_id);
                }

                // SMPGROUP's parent IOHS's chip unit must be the SMPGROUP's chip unit divided by 2

                const auto smpgroup_chip_unit = smpgroup->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                const auto iohs_chip_unit = parent_iohs->getAttr<TARGETING::ATTR_CHIP_UNIT>();

                if (smpgroup_chip_unit / 2 != iohs_chip_unit)
                {
                    TS_FAIL("SMPGROUP 0x%08x's chip unit (0x%x) divided by 2 should be parent IOHS's (0x%08x) chip unit (0x%x)",
                            TARGETING::get_huid(smpgroup),
                            smpgroup_chip_unit,
                            TARGETING::get_huid(parent_iohs),
                            iohs_chip_unit);
                }
            }
        } while(0);
        FAPI_INF("Complete testVerifySmpgroupChipletNum");
    }

    void testVerifyIohsChipletNum()
    {
        FAPI_INF("Start testVerifyIohsChipletNum");

        uint8_t  l_chiplet_id = 0;
        uint8_t  l_exp_chiplet_id = 0;
        uint8_t  l_chip_unit = 0;

        do
        {
            // find all cpu IOHSs
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            assert(pSys, "toplevel target must not be null");
            TARGETING::PredicateCTM predIohs(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_IOHS);

            TARGETING::TargetHandleList l_TargetList;
            TARGETING::targetService().getAssociated( l_TargetList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predIohs );

            if (l_TargetList.empty())
            {
                TS_FAIL("testVerifyIohsChipletNum: empty l_TargetList");
                break;
            }

            // Iterate through all iohss
            for (auto & l_Target : l_TargetList)
            {
                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_IOHS> fapi2_Target( l_Target);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyIohsChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(l_Target),
                    l_chiplet_id);

                // Processor Iohs 0..8 map to pervasive ids 0x18..0x1F
                l_chip_unit = l_Target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                l_exp_chiplet_id = l_chip_unit + START_IOHS_CHIPLET_NUM;

                if (l_chiplet_id != l_exp_chiplet_id)
                {
                    TS_FAIL("testVerifyIohsChipletNum: Mismatch HUID %.8X - Expected: %.8X:, Found: %.8X",
                            TARGETING::get_huid(l_Target),
                            l_exp_chiplet_id, l_chiplet_id);
                }
            }
        } while(0);
        FAPI_INF("Complete testVerifyIohsChipletNum");
    }

    void testVerifyPauChipletNum()
    {
        FAPI_INF("Start testVerifyPauChipletNum");

        uint8_t  l_chiplet_id = 0;
        uint8_t  l_exp_chiplet_id = 0;
        uint8_t  l_chip_unit = 0;

        do
        {
            // find all cpu PAUs
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            assert(pSys, "toplevel target must not be null");
            TARGETING::PredicateCTM predPau(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_PAU);

            TARGETING::TargetHandleList l_TargetList;
            TARGETING::targetService().getAssociated( l_TargetList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predPau );

            if (l_TargetList.empty())
            {
                TS_FAIL("testVerifyPauChipletNum: empty l_TargetList");
                break;
            }

            // Iterate through all paus
            for (auto & l_Target : l_TargetList)
            {
                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_PAU> fapi2_Target( l_Target);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyPauChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(l_Target),
                    l_chiplet_id);

                // Processor Pau 0-1, 2-3 etc. map to pervasive ids 0x10, 0x11 ...
                // (despite the fact that 1 and 2 don't exist yet)
                l_chip_unit = l_Target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                l_exp_chiplet_id = l_chip_unit / 2 + START_PAU_CHIPLET_NUM;

                if (l_chiplet_id != l_exp_chiplet_id)
                {
                    TS_FAIL("testVerifyPauChipletNum: Mismatch HUID %.8X - Expected: %.8X:, Found: %.8X",
                            TARGETING::get_huid(l_Target),
                            l_exp_chiplet_id, l_chiplet_id);
                }
            }
        } while(0);
        FAPI_INF("Complete testVerifyCoreChipletNum");
    }

    void testVerifyPaucChipletNum()
    {
        FAPI_INF("Start testVerifyPaucChipletNum");

        uint8_t  l_chiplet_id = 0;
        uint8_t  l_exp_chiplet_id = 0;
        uint8_t  l_chip_unit = 0;

        do
        {
            // find all cpu PAUCs
            TARGETING::Target * pSys;
            TARGETING::targetService().getTopLevelTarget(pSys);
            assert(pSys, "toplevel target must not be null");
            TARGETING::PredicateCTM predPauc(TARGETING::CLASS_UNIT,
                    TARGETING::TYPE_PAUC);

            TARGETING::TargetHandleList l_TargetList;
            TARGETING::targetService().getAssociated( l_TargetList, pSys,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &predPauc );

            if (l_TargetList.empty())
            {
                TS_FAIL("testVerifyPaucChipletNum: empty l_TargetList");
                break;
            }

            // Iterate through all paucs
            for (auto & l_Target : l_TargetList)
            {
                // map Targeting Type to fapi2 Type
                Target<fapi2::TARGET_TYPE_PAUC> fapi2_Target( l_Target);
                l_chiplet_id = fapi2_Target.getChipletNumber();

                FAPI_DBG("testVerifyPaucChipletNum HUID: %.8X, ChipletId: %.8X",
                    TARGETING::get_huid(l_Target),
                    l_chiplet_id);

                // Processor Pauc 0..8 map to pervasive ids 0x18..0x1F
                l_chip_unit = l_Target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                l_exp_chiplet_id = l_chip_unit + START_PAUC_CHIPLET_NUM;

                if (l_chiplet_id != l_exp_chiplet_id)
                {
                    TS_FAIL("testVerifyPaucChipletNum: Mismatch HUID %.8X - Expected: %.8X:, Found: %.8X",
                            TARGETING::get_huid(l_Target),
                            l_exp_chiplet_id, l_chiplet_id);
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

            testVerifyCoreChipletNum();

            testVerifyMcChipletNum();

            testVerifyMiChipletNum();

            testVerifyPecChipletNum();

            testVerifyiPhbChipletNum();

            testVerifyMccChipletNum();

            testVerifyOmiChipletNum();

            testVerifyOmicChipletNum();

            testVerifyIohsChipletNum();

            testVerifyPauChipletNum();

            testVerifyPaucChipletNum();

        } while(0);
        FAPI_DBG("test_fapi2ChipletNum Test Complete.");
    } // end test_fapi2ChipletNum()

}; // end class

}// end namespace fapi2
